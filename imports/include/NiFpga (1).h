// this is an exported header file, to prevent ambiguous inclusion problems
// with pragma once, use macro guards
#ifndef __niriodispatch_nifpga_h__
#define __niriodispatch_nifpga_h__

#include <nibuild/platform.h>
#include <niapal/quarks/platform.h>
#include <niriodispatch/NiFpgaTypes.h>

// You might be thinking: I can add C++11 declarations to this header file!
//
// Think again.
//
// This header file is exported to client groups and your extra crafty
// auto variable variadic template function that resolved to a constexpr
// is going to break the build for somebody.
//
// Please think again.
// - Signed: client groups

// Declaration of types must match the C API's NiFpga.h
// e.g. //NI-RIO/chi/trunk/16.0/source/fpgainterfacecapi/NiFpga.h

kNICPPHeader

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_Open(const char*     bitfile,
                                      const char*     signature,
                                      const char*     resource,
                                      uint32_t        attribute,
                                      NiFpga_Session* session)
kNIExportPost;

/// Opens a "Single Resource Session"
///
/// The new "single resource session" is a child of an already-opened parent
/// session and has access to just one resource (control/indicator/FIFO)
///
/// The child session must be closed before the parent session because the
/// child will re-use much of the parent's metadata.
///
/// @param parentSession the session to open a child from
/// @param parentIndex the index in the parent session to add to the child session
/// @param globalIndex the global index to add the resource at the parentIndex to in the child session
/// @param childSession the returned child session.  Caller must close this session before the parent session is closed.
kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_OpenResource(NiFpga_Session  parentSession,
                                              uint32_t        parentIndex,
                                              uint32_t        globalIndex,
                                              NiFpga_Session* childSession)
kNIExportPost;

/// Adds resources to a session
/// This is how dynamic mode works.  LabVIEW FPGA calls GetResourceIndex on every
/// string that shows up on the diagram and uses that index when calling into
/// NiFpgaLv entrypoints.
/// When a session is opened, LV FPGA calls add resources, this call internally
/// calls GetResourceIndex on every resource and associates that index with the resource
/// allowing future calls to just use the index.
kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_AddResources(NiFpga_Session session,
                                              const char**   resourceNames,
                                              uint32_t*      resourceValues,
                                              uint32_t*      externalRegisters,
                                              size_t         numberOfResources)
kNIExportPost;

/// Gets an index for a given resourceName.
/// If a resource already has an index, it will just re-give out the same index
/// and increment a refcount.
/// If a resource doesn't have an index, it will create an index for it.
/// For every call of GetResourceIndex, you should call ReleaseResourceIndex
/// when you are done with the index.
kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_GetResourceIndex(const char* resourceName,
                                                  uint32_t* resourceIndex)
kNIExportPost;

/// Releases resource indexes given out by GetResourceIndex
kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ReleaseResourceIndex(const char* resourceName)
kNIExportPost;

/// Get's the name of a resource at the given index.
/// The char* is valid as long as the index is valid.
/// If ReleaseResourceIndex is called on the index such that the refcount
/// would go to 0, the string will be deallocated.
kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_GetResourceName(uint32_t resourceIndex,
                                                 const char** resourceName)
kNIExportPost;

/// Returns all the indexes used by the session.
/// @param session the session to use
/// @param indexes, a list of indexes to fill, if NULL, will instead attempt to set sizeNeeded
/// @param size the size of indexes
/// @param sizeNeeded, the number of indexes filled
kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_GetSessionIndexes(NiFpga_Session session,
                                                   uint32_t* indexes,
                                                   size_t size,
                                                   size_t* sizeNeeded)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_Close(NiFpga_Session session,
                                       uint32_t       attribute)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_Run(NiFpga_Session session,
                                     uint32_t       attribute)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_Abort(NiFpga_Session session)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_Reset(NiFpga_Session session)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_Download(NiFpga_Session session)
kNIExportPost;

#define NIFPGA_FOR_EACH_SCALAR(generator) \
   generator(Bool, NiFpga_Bool) \
   generator(I8,        int8_t) \
   generator(U8,       uint8_t) \
   generator(I16,      int16_t) \
   generator(U16,     uint16_t) \
   generator(I32,      int32_t) \
   generator(U32,     uint32_t) \
   generator(I64,      int64_t) \
   generator(U64,     uint64_t) \
   generator(Sgl,        float) \
   generator(Dbl,       double)

#define NIFPGA_DECLARE_READ(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_Read##name( \
                                               NiFpga_Session session, \
                                               uint32_t       indicator, \
                                               type*          value) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_READ)

#define NIFPGA_DECLARE_WRITE(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_Write##name( \
                                                NiFpga_Session session, \
                                                uint32_t       control, \
                                                type           value) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_WRITE)

#define NIFPGA_DECLARE_READ_ARRAY(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_ReadArray##name( \
                                                    NiFpga_Session session, \
                                                    uint32_t       indicator, \
                                                    type*          values, \
                                                    size_t         size) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_READ_ARRAY)

#define NIFPGA_DECLARE_WRITE_ARRAY(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_WriteArray##name( \
                                                     NiFpga_Session session, \
                                                     uint32_t       control, \
                                                     const type*    values, \
                                                     size_t         size) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_WRITE_ARRAY)

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ReserveIrqContext(NiFpga_Session session,
                                                   NiFpga_IrqContext* context)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_UnreserveIrqContext(NiFpga_Session    session,
                                                     NiFpga_IrqContext context)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_WaitOnIrqs(NiFpga_Session    session,
                                            NiFpga_IrqContext context,
                                            uint32_t          irqs,
                                            uint32_t          timeout,
                                            uint32_t*         irqsAsserted,
                                            NiFpga_Bool*      timedOut)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_AcknowledgeIrqs(NiFpga_Session session,
                                                 uint32_t       irqs)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ConfigureFifo(NiFpga_Session session,
                                               uint32_t       fifo,
                                               size_t         depth)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ConfigureFifo2(NiFpga_Session session,
                                                uint32_t       fifo,
                                                size_t         requestedDepth,
                                                size_t*        actualDepth)
kNIExportPost;

typedef enum
{
   /**
    * Type: U32
    * Specifies the number of bytes in a single element of the FIFO. Other
    * FIFO Buffer related properties are specified in number of elements, so
    * this property can be used to convert that number to a number of bytes.
    *
    * This property is only Getable and cannot be Set.
    */
   NiFpga_FifoProperty_BytesPerElement = 1,
   /**
    * Type: U32
    * Specifies the smallest discreet allocation unit that the HostBufferSize
    * will be coerced too. By default, this value will be set to the most
    * optimized setting for your hardware and system. This usually defaults to
    * the system's page size. The only valid values for this property are
    * powers of 2.
    */
   NiFpga_FifoProperty_HostBufferAllocationGranularity = 2,
   /**
    * Type: U64
    * The number of elements in the host memory part of the DMA FIFO. This size
    * will be coerced to be a multiple of the HostBufferAllocationGranularity.
    * By default this value will be 16KB or 2 times the size of the FPGA Block
    * RAM part of the FIFO if thats larger.
    */
   NiFpga_FifoProperty_HostBufferSize = 3,
   /**
    * Type: U64
    * Specifies the number of elements mirrored at the end of the host memory
    * part of the DMA FIFO. By mirrored, we mean that the memory is mapped in
    * such a way that these elements point to the same physical memory as the
    * elements at the beginning of the host memory part of the DMA FIFO.
    *
    * The HostBufferMirrorSize can be set from 0 to the HostBufferSize.  If set
    * to a value larger than HostBufferSize it will be coerced to match it.
    * HostBufferMirrorSize requires the HostBufferSize to be a multiple of the
    * page size on POSIX systems and the system Allocation Granularity on
    * Windows Systems.  In 32bit processes, HostBufferMirrorSize will default
    * to 0.  In 64bit processes, HostBufferMirrorSize will default to the max
    * possible value and coerce down to the set HostBufferSize.  The space
    * used for the HostBufferMirrorSize does not come out of the HostBufferSize.
    * It is allocated separately from virtual memory and is backed by the same
    * physical memory as the HostBuffer.
    *
    * Setting up memory like this improves use with the AcquireFifoElements API.
    * When using AcquireFifoElements, you can hit the end of the buffer and
    * recieve less elements than you attempted to acquire. This requires a
    * second AcquireFifoElements call to get the remaining elements.
    * Mirroring Elements avoids that second call.
    *
    * Example:
    * Behavior without Mirrored Elements:
    * This is a Target to Host FIFO of 10 elements:
    *   0-1-2-3-4-5-6-7-8-9
    *   ^
    *   Current FIFO pointer here.
    *
    * 1. Acquire, use and Release 7 elements.
    *   0-1-2-3-4-5-6-7-8-9
    *                 ^
    *                 Current FIFO pointer here.
    * 2. The device writes to those 7 elements, filling up the FIFO.
    * 3. Attempt to acquire 7 elements, get back 3 because we can only give a
    *    pointer to 3 elements.
    *
    * Behavior with Mirrored Elements:
    * If instead we had mirrored 4 elements, it would act like this.
    *   0-1-2-3-4-5-6-7-8-9{0-1-2-3}
    *   ^                   ^mirrored elements
    *   Current FIFO pointer here.
    * 1. Acquire, use and Release 7 elements.
    *   0-1-2-3-4-5-6-7-8-9{0-1-2-3}
    *                 ^     ^mirrored elements
    *                 Current FIFO pointer here.
    * 2. The device writes to those 7 elements, filling up the FIFO.
    * 3. Acquire, use and Release 7 elements. No problems are encountered
    *    because the driver gives back a pointer to the 7 elements requested.
    */
   NiFpga_FifoProperty_HostBufferMirrorSize = 4,
   /**
    * Type: I32
    * Specifies the type of memory used in the host memory part of the DMA FIFO.
    * See NiFpga_HostBufferType for the valid values of this property.
    * This property defaults to NiFpga_HostBufferType_AllocatedByRIO.
    */
   NiFpga_FifoProperty_HostBufferType = 5,
   /**
    * Type: Ptr
    * Specifies a pointer to the start of the host memory part of the DMA FIFO.
    * Can only be set if the HostBufferType is set to
    * NiFpga_HostBufferType_AllocatedByUser.
    *
    * Note, if the buffer is user supplied, the buffer will be pagelocked
    * by the driver. When the user has finished with the buffer, the user must
    * do one of the following before deallocating the buffer:
    * 1. Call NiFpga_Close on the NiFpga_Session
    * 2. Set the buffer type to NiFpga_HostBufferType_AllocatedByRIO and call
    *    NiFpga_CommitFifoConfiguration.
    * 3. Set the NiFpga_FifoProperty_HostBuffer to a different buffer.
    * 4. End the process.
    */
   NiFpga_FifoProperty_HostBuffer= 6,
   /**
    * Type: I32
    * Specifies the flow control behavior of the DMA FIFO.
    * This property defaults to NiFpga_FifoFlowControl_Enabled, which means
    * that FIFOs operate in a "first in first out" manner and no data is lost.
    * See NiFpga_FifoFlowControl for specifics on the behaviors.
    * Warning, changing the behavior of a FIFO can make it work in a non-"first
    * in first out" manner and data may be lost.
    */
   NiFpga_FifoProperty_FlowControl = 7,

   /**
    * Type: U64
    * Specifies how many elements that are currently acquired in the fifo
    */
   NiFpga_FifoProperty_ElementsCurrentlyAcquired = 8,
   /**
    * Type: I32
    * The NUMA node the FIFO should be allocated on.
    */
   NiFpga_FifoProperty_PreferredNumaNode = 9,
   /**
    * Type: U32
    * The number of zero copy regions that can be acquired at once.
    */
   NiFpga_FifoProperty_NumberOfZeroCopyRegions = 10
} NiFpga_FifoProperty;

typedef enum
{
   /**
    * Specifies that the DMA Buffer will be allocated by the NI-RIO driver
    * according to the options specified in the other FIFO properties.
    */
   NiFpga_HostBufferType_AllocatedByRIO = 1,
   /**
    * Specifies that the user has allocated the FIFO to the options specified
    * in the other FIFO properties. After setting this property, the user
    * should set NiFpga_FifoProperty_HostBuffer to their specified buffer.
    */
   NiFpga_HostBufferType_AllocatedByUser = 2
} NiFpga_HostBufferType;

typedef enum
{
   /**
    * When this option is specified, the FPGA will fully control data transfer
    * without any action from the host. FIFOs will no longer act in a first
    * in first out manner. It is up to the user to synchronize with the FPGA
    * and ensure coherent data.
    *
    * For Target To Host FIFOs, data will being transferring on StartFifo.
    * For Host To Target FIFOs, data will begin transferring when the entire
    * host part of the DMA FIFO has been written once. This is intended to
    * prevent the FPGA from reading garbage data from an uninitialized buffer
    * on the host.
    */
   NiFpga_FifoFlowControl_Disabled = 1,
   /**
    * This is the default options for FIFOs. When this option is specified,
    * FIFOs act with First In First Out behavior and no data is ever lost.
    * Data will stop transferring if the host memory part of the FIFO becomes
    * full rather than overwriting it.
    */
   NiFpga_FifoFlowControl_Enabled = 2
} NiFpga_FifoFlowControl;

#define NIFPGA_FOR_EACH_FIFO_PROPERTY_TYPE(generator) \
   generator(I32,  int32_t) \
   generator(U32, uint32_t) \
   generator(I64,  int64_t) \
   generator(U64, uint64_t) \
   generator(Ptr,    void*)

#define NIFPGA_DECLARE_GET_FIFO_PROPERTY(name, type) \
kNIExportPre \
NiFpga_Status kNICCall NiFpgaDll_GetFifoProperty##name(NiFpga_Session session, \
                                                       uint32_t       fifo, \
                                                       uint32_t       propertyId, \
                                                       type*          value) \
kNIExportPost;

NIFPGA_FOR_EACH_FIFO_PROPERTY_TYPE(NIFPGA_DECLARE_GET_FIFO_PROPERTY);

#define NIFPGA_DECLARE_SET_FIFO_PROPERTY(name, type) \
kNIExportPre \
NiFpga_Status kNICCall NiFpgaDll_SetFifoProperty##name(NiFpga_Session session, \
                                                       uint32_t       fifo, \
                                                       uint32_t       propertyId, \
                                                       type           value) \
kNIExportPost;

NIFPGA_FOR_EACH_FIFO_PROPERTY_TYPE(NIFPGA_DECLARE_SET_FIFO_PROPERTY);

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_CommitFifoConfiguration(NiFpga_Session session,
                                                         uint32_t       fifo)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_StartFifo(NiFpga_Session session,
                                           uint32_t       fifo)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_StopFifo(NiFpga_Session session,
                                          uint32_t       fifo)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_UnreserveFifo(NiFpga_Session session,
                                               uint32_t       fifo)
kNIExportPost;

#define NIFPGA_DECLARE_READ_FIFO(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_ReadFifo##name( \
                                                    NiFpga_Session session, \
                                                    uint32_t       fifo, \
                                                    type*          data, \
                                                    size_t         count, \
                                                    uint32_t       timeout, \
                                                    size_t*        remaining) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_READ_FIFO)

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ReadFifoComposite(
                                                 NiFpga_Session session,
                                                 uint32_t       fifo,
                                                 void*          data,
                                                 uint32_t       bytesPerElement,
                                                 size_t         count,
                                                 uint32_t       timeout,
                                                 size_t*        remaining)
kNIExportPost;

#define NIFPGA_DECLARE_WRITE_FIFO(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_WriteFifo##name( \
                                                    NiFpga_Session session, \
                                                    uint32_t       fifo, \
                                                    const type*    data, \
                                                    size_t         count, \
                                                    uint32_t       timeout, \
                                                    size_t*        remaining) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_WRITE_FIFO)

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_WriteFifoComposite(
                                                 NiFpga_Session session,
                                                 uint32_t       fifo,
                                                 const void*    data,
                                                 uint32_t       bytesPerElement,
                                                 size_t         count,
                                                 uint32_t       timeout,
                                                 size_t*        remaining)
kNIExportPost;

#define NIFPGA_DECLARE_ACQUIRE_FIFO_READ_ELEMENTS(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_AcquireFifoReadElements##name( \
                                          NiFpga_Session session, \
                                          uint32_t       fifo, \
                                          type**         elements, \
                                          size_t         elementsRequested, \
                                          uint32_t       timeout, \
                                          size_t*        elementsAcquired, \
                                          size_t*        elementsRemaining) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_ACQUIRE_FIFO_READ_ELEMENTS)

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_AcquireFifoReadElementsComposite(
                                       NiFpga_Session session,
                                       uint32_t       fifo,
                                       void**         elements,
                                       uint32_t       elementSizeBytes,
                                       size_t         elementsRequested,
                                       uint32_t       timeout,
                                       size_t*        elementsAcquired,
                                       size_t*        elementsRemaining)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_AcquireFifoReadRegion(
                                       NiFpga_Session session,
                                       uint32_t       fifo,
                                       void**         region,
                                       void**         elements,
                                       bool           isSigned,
                                       uint32_t       elementSizeBytes,
                                       size_t         elementsRequested,
                                       uint32_t       timeout,
                                       size_t*        elementsAcquired,
                                       size_t*        elementsRemaining)
kNIExportPost;

#define NIFPGA_DECLARE_ACQUIRE_FIFO_WRITE_ELEMENTS(name, type) \
   kNIExportPre \
   NiFpga_Status kNICCall NiFpgaDll_AcquireFifoWriteElements##name( \
                                          NiFpga_Session session, \
                                          uint32_t       fifo, \
                                          type**         elements, \
                                          size_t         elementsRequested, \
                                          uint32_t       timeout, \
                                          size_t*        elementsAcquired, \
                                          size_t*        elementsRemaining) \
   kNIExportPost;

NIFPGA_FOR_EACH_SCALAR(NIFPGA_DECLARE_ACQUIRE_FIFO_WRITE_ELEMENTS)

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_AcquireFifoWriteElementsComposite(
                                       NiFpga_Session session,
                                       uint32_t       fifo,
                                       void**         elements,
                                       uint32_t       elementSizeBytes,
                                       size_t         elementsRequested,
                                       uint32_t       timeout,
                                       size_t*        elementsAcquired,
                                       size_t*        elementsRemaining)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_AcquireFifoWriteRegion(
                                       NiFpga_Session session,
                                       uint32_t       fifo,
                                       void**         region,
                                       void**         elements,
                                       bool           isSigned,
                                       uint32_t       elementSizeBytes,
                                       size_t         elementsRequested,
                                       uint32_t       timeout,
                                       size_t*        elementsAcquired,
                                       size_t*        elementsRemaining)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ReleaseFifoElements(NiFpga_Session session,
                                                     uint32_t       fifo,
                                                     size_t         elements)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ReleaseFifoRegion(NiFpga_Session session,
                                                   uint32_t       fifo,
                                                   void*          region)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_GetPeerToPeerFifoEndpoint(NiFpga_Session session,
                                                           uint32_t       fifo,
                                                           uint32_t*      endpoint)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_MapP2PSinkFifo(const NiFpga_Session session,
                                                const uint32_t       fifo,
                                                size_t*              size,
                                                void**               virtualAddress)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_UnmapP2PSinkFifo(const NiFpga_Session session,
                                                  const uint32_t       fifo)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_GetBitfileContents(NiFpga_Session session,
                                                    const char**   contents)
kNIExportPost;


nNIAPALS100_kExportPre
NiFpga_Status nNIAPALS100_kCCall NiFpgaDll_GetBitfileSignature(NiFpga_Session session,
                                                               uint32_t* signature,
                                                               size_t*   signatureSize)
nNIAPALS100_kExportPost;


nNIAPALS100_kExportPre
NiFpga_Status nNIAPALS100_kCCall NiFpgaDll_GetBitfileWithoutBitstream(NiFpga_Session session,
                                                                      char* contents,
                                                                      uint32_t* contentsSize)
nNIAPALS100_kExportPost;


nNIAPALS100_kExportPre
NiFpga_Status nNIAPALS100_kCCall NiFpgaDll_FindRegisterPrivate(NiFpga_Session session,
                                                               const char* resourceName,
                                                               uint32_t  expectedResourceType,
                                                               uint32_t* resourceOffset)
nNIAPALS100_kExportPost;


nNIAPALS100_kExportPre
NiFpga_Status nNIAPALS100_kCCall NiFpgaDll_FindFifoPrivate(NiFpga_Session session,
                                                           const char* fifoName,
                                                           uint32_t  expectedResourceType,
                                                           uint32_t* resourceOffset)
nNIAPALS100_kExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_OpenHmb(const NiFpga_Session session,
                                         const char*          memoryName,
                                         size_t*              memorySize,
                                         void**               virtualAddress)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_CloseHmb(const NiFpga_Session session,
                                          const char*          memoryName)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_OpenLlbLvPrivate(const NiFpga_Session session,
                                                  const char*          memoryName,
                                                  size_t*              memorySizeToHost,
                                                  void**               virtualAddressToHost,
                                                  void**               objPtrToHost,
                                                  void (**releaseFuncToHost)(void *objPtr, const char* memoryName),
                                                  size_t*              memorySizeToFpga,
                                                  void**               virtualAddressToFpga,
                                                  void**               objPtrToFpga,
                                                  void (**releaseFuncToFpga)(void *objPtr, const char* memoryName))
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_OpenLlb(const NiFpga_Session session,
                                         const char*          memoryName,
                                         size_t*              memorySizeToHost,
                                         void**               virtualAddressToHost,
                                         size_t*              memorySizeToFpga,
                                         void**               virtualAddressToFpga)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_CloseLlb(const NiFpga_Session session,
                                          const char*          memoryName)
kNIExportPost;

kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_ClientFunctionCall(NiFpga_Session session,
                                                    uint32_t group,
                                                    uint32_t functionId,
                                                    const void* inBuffer,
                                                    size_t inBufferSize,
                                                    void* outBuffer,
                                                    size_t outBufferSize)
kNIExportPost;


kNIExportPre
NiFpga_Status kNICCall NiFpgaDll_GetFpgaViState(NiFpga_Session session,
                                                uint32_t* state)
kNIExportPost;

kNICPPTrailer

#endif // __niriodispatch_nifpga_h__
