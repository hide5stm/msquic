/*++

    Copyright (c) Microsoft Corporation.
    Licensed under the MIT License.

Abstract:

    External definition of C99 inline functions.
    See "Clang" / "Language Compatibility" / "C99 inline functions"
    ( https://clang.llvm.org/compatibility.html#inline .)
    It seems that C99 standard requires that every inline function defined
    in a header have a corresponding non-inline definition in a C source file.
    Observed behavior is that Clang is enforcing this, but not MSVC.
    Until an alternative solution is found, this file is required for Clang.

--*/

#include "precomp.h"

QUIC_CID_QUIC_LIST_ENTRY*
QuicCidNewDestination(
    _In_ uint8_t Length,
    _In_reads_(Length)
        const uint8_t* const Data
    );

QUIC_CID_HASH_ENTRY*
QuicCidNewSource(
    _In_ QUIC_CONNECTION* Connection,
    _In_ uint8_t Length,
    _In_reads_(Length)
        const uint8_t* const Data
    );

QUIC_CID_HASH_ENTRY*
QuicCidNewRandomSource(
    _In_ QUIC_CONNECTION* Connection,
    _In_ uint8_t ServerID,
    _In_ uint8_t PartitionID,
    _In_ uint8_t PrefixLength,
    _In_reads_opt_(PrefixLength)
        const uint8_t* Prefix,
    _In_ uint8_t Length
    );

QUIC_CID_QUIC_LIST_ENTRY*
QuicCidNewRandomDestination(
    );

uint8_t
QuicCidDecodeLength(
    _In_ uint8_t Length
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
void
QuicConnFatalError(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_STATUS Status,
    _In_opt_z_ const char* ErrorMsg
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
void
QuicConnRelease(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_CONNECTION_REF Ref
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
void
QuicConnAddRef(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_CONNECTION_REF Ref
    );

BOOLEAN
QuicConnIsClosed(
    _In_ const QUIC_CONNECTION * const Connection
    );

BOOLEAN
QuicConnIsServer(
    _In_ const QUIC_CONNECTION * const Connection
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
void
QuicConnTransportError(
    _In_ QUIC_CONNECTION* Connection,
    _In_ uint64_t ErrorCode
    );

_Success_(return != FALSE)
BOOLEAN
QuicFrameParseType(
    _In_ uint8_t Type,
    _Out_ QUIC_FRAME_TYPE* FrameType
    );

_Success_(return != FALSE)
BOOLEAN
QuicStreamFramePeekID(
    _In_ uint16_t BufferLength,
    _In_reads_bytes_(BufferLength)
        const uint8_t * const Buffer,
    _In_ uint16_t Offset,
    _Out_ uint64_t* StreamID
    );

_Success_(return != FALSE)
BOOLEAN
QuicStreamFrameSkip(
    _In_ QUIC_FRAME_TYPE FrameType,
    _In_ uint16_t BufferLength,
    _In_reads_bytes_(BufferLength)
        const uint8_t * const Buffer,
    _Inout_ uint16_t* Offset
    );

BOOLEAN
QuicIsVersionSupported(
    _In_ uint32_t Version // Network Byte Order
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
BOOLEAN
QuicIsTupleRssMode(
    void
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
void
QuicStreamAddRef(
    _In_ QUIC_STREAM* Stream,
    _In_ QUIC_STREAM_REF Ref
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
BOOLEAN
QuicStreamRelease(
    _In_ QUIC_STREAM* Stream,
    _In_ QUIC_STREAM_REF Ref
    );

QUIC_ENCRYPT_LEVEL
QuicKeyTypeToEncryptLevel(
    QUIC_PACKET_KEY_TYPE KeyType
    );

uint16_t
QuicKeyLength(
    QUIC_AEAD_TYPE Type
    );

QUIC_PACKET_KEY_TYPE
QuicPacketTypeToKeyType(
    uint8_t PacketType
    );

_When_(FirstByte < 0x80, _Post_equal_to_(sizeof(uint8_t)))
_When_(FirstByte >= 0x80 && FirstByte < 0x4000, _Post_equal_to_(sizeof(uint16_t)))
_When_(FirstByte >= 0x4000, _Post_equal_to_(sizeof(uint32_t)))
uint8_t
QuicVarPktNumDecodeLength(
    uint8_t FirstByte
    );

BOOLEAN
QuicIsVersionReserved(
    _In_ uint32_t Version // Either Byte Order
    );

QUIC_CONNECTION*
QuicCryptoGetConnection(
    _In_ QUIC_CRYPTO* Crypto
    );

BOOLEAN
QuicCryptoHasPendingCryptoFrame(
    _In_ QUIC_CRYPTO* Crypto
    );

void
QuicCryptoCombineIvAndPacketNumber(
    _In_reads_bytes_(QUIC_IV_LENGTH)
        const uint8_t* const IvIn,
    _In_reads_bytes_(sizeof(uint64_t))
        const uint8_t* const PacketNumber,
    _Out_writes_bytes_(QUIC_IV_LENGTH)
        uint8_t* IvOut
    );

QUIC_SUBRANGE*
QuicRangeGetSafe(
    _In_ const QUIC_RANGE * const Range,
    _In_ uint32_t Index
    );

uint32_t
QuicRangeSize(
    _In_ const QUIC_RANGE * const Range
    );

QUIC_SUBRANGE*
QuicRangeGet(
    _In_ const QUIC_RANGE * const Range,
    _In_ uint32_t Index
    );

uint64_t
QuicRangeGetHigh(
    _In_ const QUIC_SUBRANGE* const Sub
    );

uint8_t
QuicStreamFrameHeaderSize(
    _In_ const QUIC_STREAM_EX * const Frame
    );

uint64_t
QuicStreamGetInitialMaxDataFromTP(
    _In_ uint64_t StreamID,
    _In_ BOOLEAN IsServer,
    _In_ const QUIC_TRANSPORT_PARAMETERS* const TransportParams
    );

QUIC_CONNECTION*
QuicLossDetectionGetConnection(
    _In_ QUIC_LOSS_DETECTION* LossDetection
    );

uint8_t
QuicCidEncodeLength(
    _In_ uint8_t Length
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
void
QuicCongestionControlSetExemption(
    _In_ QUIC_CONGESTION_CONTROL* Cc,
    _In_ uint8_t NumPackets
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
BOOLEAN
QuicCongestionControlCanSend(
    _In_ QUIC_CONGESTION_CONTROL* Cc
    );

QUIC_CONNECTION*
QuicSendGetConnection(
    _In_ QUIC_SEND* Send
    );

uint8_t
QuicEncryptLevelToPacketType(
    QUIC_ENCRYPT_LEVEL Level
    );

QUIC_ENCRYPT_LEVEL
QuicPacketTypeToEncryptLevel(
    uint8_t PacketType
    );

uint8_t
QuicKeyTypeToPacketType(
    QUIC_PACKET_KEY_TYPE KeyType
    );

uint16_t
PacketSizeFromUdpPayloadSize(
    _In_ QUIC_ADDRESS_FAMILY Family,
    _In_ uint16_t UdpPayloadSize
    );

QUIC_PACKET_SPACE*
QuicAckTrackerGetPacketSpace(
    _In_ QUIC_ACK_TRACKER* Tracker
    );

QUIC_CONNECTION*
QuicCongestionControlGetConnection(
    _In_ QUIC_CONGESTION_CONTROL* Cc
    );

QUIC_CID_STR
QuicCidToStr(
    _In_ const QUIC_CID* const CID
    );

QUIC_CID_STR
QuicCidBufToStr(
    _In_reads_(Length)
        const uint8_t* const Data,
    _In_ uint8_t Length
    );

 char QuicHalfByteToStr(uint8_t b);

_IRQL_requires_max_(DISPATCH_LEVEL)
BOOLEAN
QuicSendBufferHasSpace(
    _Inout_ QUIC_SEND_BUFFER* SendBuffer
    );

uint64_t
QuicConnGetNextTimer(
    _In_ const QUIC_CONNECTION * const Connection
    );

QUIC_CONNECTION*
QuicStreamSetGetConnection(
    _In_ QUIC_STREAM_SET* StreamSet
    );

uint64_t
StreamIDToCount(
    _In_ uint64_t ID,
    _In_ uint8_t Type // STREAM_ID_FLAG_*
    );

uint64_t
StreamCountToID(
    _In_ uint64_t Count,
    _In_ uint8_t Type // STREAM_ID_FLAG_*
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
_Success_(return != 0)
uint16_t
QuicPacketEncodeLongHeaderV1(
    _In_ uint32_t Version, // Allows for version negotiation forcing
    _In_ QUIC_LONG_HEADER_TYPE_V1 PacketType,
    _In_ const QUIC_CID* const DestCid,
    _In_ const QUIC_CID* const SourceCid,
    _In_ uint16_t TokenLength,
    _In_reads_opt_(TokenLength)
        const uint8_t* const Token,
    _In_ uint32_t PacketNumber,   // Host Byte order
    _In_ uint16_t BufferLength,
    _Out_writes_bytes_(BufferLength)
        uint8_t* Buffer,
    _Out_ uint16_t* PayloadLengthOffset,
    _Out_ uint8_t* PacketNumberLength
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
_Success_(return != 0)
uint16_t
QuicPacketEncodeShortHeaderV1(
    _In_ const QUIC_CID* const DestCid,
    _In_ uint64_t PacketNumber,
    _In_ uint8_t PacketNumberLength,
    _In_ BOOLEAN SpinBit,
    _In_ BOOLEAN KeyPhase,
    _In_ uint16_t BufferLength,
    _Out_writes_bytes_opt_(BufferLength)
        uint8_t* Buffer
    );

QUIC_PACKET_KEY_TYPE
QuicEncryptLevelToKeyType(
    QUIC_ENCRYPT_LEVEL Level
    );

BOOLEAN
QuicIsTupleRssMode(
    void
    );

BOOLEAN
QuicVarIntDecode(
    _In_ uint16_t BufferLength,
    _In_reads_bytes_(BufferLength)
        const uint8_t * const Buffer,
    _Deref_in_range_(0, BufferLength)
    _Deref_out_range_(0, BufferLength)
        uint16_t* Offset,
    _Out_ QUIC_VAR_INT* Value
    );

uint8_t*
QuicVarIntEncode(
    _In_ QUIC_VAR_INT Value,
    _When_(Value < 0x40, _Out_writes_bytes_(sizeof(uint8_t)))
    _When_(Value >= 0x40 && Value < 0x4000, _Out_writes_bytes_(sizeof(uint16_t)))
    _When_(Value >= 0x4000 && Value < 0x40000000, _Out_writes_bytes_(sizeof(uint32_t)))
    _When_(Value >= 0x40000000, _Out_writes_bytes_(sizeof(uint64_t)))
        uint8_t* Buffer
    );

void
QuicPktNumEncode(
    _In_ uint64_t PacketNumber,
    _In_ uint8_t PacketNumberLength,
    _Out_writes_bytes_(PacketNumberLength)
        uint8_t* Buffer
    );

void
QuicPktNumDecode(
    _In_ uint8_t PacketNumberLength,
    _In_reads_bytes_(PacketNumberLength)
        const uint8_t* Buffer,
    _Out_ uint64_t* PacketNumber
    );

void
QuicConnLogOutFlowStats(
    _In_ const QUIC_CONNECTION* const Connection
    );

void
QuicOperLog(
    _In_ const void* Connection,
    _In_ QUIC_OPERATION* Oper
    );

void
QuicConnSilentlyAbort(
    _In_ QUIC_CONNECTION* Connection
    );

void
QuicPathIncrementAllowance(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_PATH* Path,
    _In_ uint32_t Amount
    );

void
QuicPathDecrementAllowance(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_PATH* Path,
    _In_ uint32_t Amount
    );

void
QuicPktNumDecode(
    _In_ uint8_t PacketNumberLength,
    _In_reads_bytes_(PacketNumberLength)
        const uint8_t* Buffer,
    _Out_ uint64_t* PacketNumber
    );

uint64_t
QuicPktNumDecompress(
    _In_ uint64_t ExpectedPacketNumber,
    _In_ uint64_t CompressedPacketNumber,
    _In_ uint8_t CompressedPacketNumberBytes
    );

uint8_t*
QuicVarIntEncode2Bytes(
    _In_ QUIC_VAR_INT Value,
    _Out_writes_bytes_(sizeof(uint16_t))
        uint8_t* Buffer
    );

int
QuicRangeSearch(
    _In_ const QUIC_RANGE* Range,
    _In_ const QUIC_RANGE_SEARCH_KEY* Key
    );

int
QuicRangeCompare(
    const QUIC_RANGE_SEARCH_KEY* Key,
    const QUIC_SUBRANGE* Sub
    );

uint8_t*
QuicVarIntEncode2Bytes(
    _In_ QUIC_VAR_INT Value,
    _Out_writes_bytes_(sizeof(uint16_t))
        uint8_t* Buffer
    );

uint64_t
QuicConnGetNextExpirationTime(
    _In_ const QUIC_CONNECTION * const Connection
    );

BOOLEAN
QuicPacketIsHandshake(
    _In_ const QUIC_HEADER_INVARIANT* Packet
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
BOOLEAN
QuicWorkerIsOverloaded(
    _In_ QUIC_WORKER* Worker
    );

BOOLEAN HasStreamControlFrames(uint32_t Flags);

BOOLEAN HasStreamDataFrames(uint32_t Flags);

BOOLEAN
QuicConnAddOutFlowBlockedReason(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_FLOW_BLOCK_REASON Reason
    );

BOOLEAN
QuicConnRemoveOutFlowBlockedReason(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_FLOW_BLOCK_REASON Reason
    );

BOOLEAN
QuicStreamAddOutFlowBlockedReason(
    _In_ QUIC_STREAM* Stream,
    _In_ QUIC_FLOW_BLOCK_REASON Reason
    );

BOOLEAN
QuicStreamRemoveOutFlowBlockedReason(
    _In_ QUIC_STREAM* Stream,
    _In_ QUIC_FLOW_BLOCK_REASON Reason
    );

void
QuicConnLogInFlowStats(
    _In_ const QUIC_CONNECTION* const Connection
    );

QUIC_STREAM_SEND_STATE
QuicStreamSendGetState(
    _In_ const QUIC_STREAM* Stream
    );

QUIC_STREAM_RECV_STATE
QuicStreamRecvGetState(
    _In_ const QUIC_STREAM* Stream
    );

BOOLEAN
QuicRetryTokenDecrypt(
    _In_ const QUIC_RECV_PACKET* const Packet,
    _In_reads_(sizeof(QUIC_RETRY_TOKEN_CONTENTS))
        const uint8_t* TokenBuffer,
    _Out_ QUIC_RETRY_TOKEN_CONTENTS* Token
    );

void
QuicConnLogStatistics(
    _In_ const QUIC_CONNECTION* const Connection
    );

BOOLEAN
QuicPacketBuilderAddFrame(
    _Inout_ QUIC_PACKET_BUILDER* Builder,
    _In_ uint8_t FrameType,
    _In_ BOOLEAN IsRetransmittable
    );

BOOLEAN
QuicPacketBuilderAddStreamFrame(
    _Inout_ QUIC_PACKET_BUILDER* Builder,
    _In_ QUIC_STREAM* Stream,
    _In_ uint8_t FrameType
    );

BOOLEAN
QuicAckTrackerHasPacketsToAck(
    _In_ const QUIC_ACK_TRACKER* Tracker
    );

BOOLEAN
QuicPacketBuilderHasAllowance(
    _In_ const QUIC_PACKET_BUILDER* Builder
    );

QUIC_CID_HASH_ENTRY*
QuicConnGetSourceCidFromSeq(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_VAR_INT SequenceNumber,
    _In_ BOOLEAN RemoveFromList,
    _Out_ BOOLEAN* IsLastCid
    );

QUIC_CID_HASH_ENTRY*
QuicConnGetSourceCidFromBuf(
    _In_ QUIC_CONNECTION* Connection,
    _In_ uint8_t CidLength,
    _In_reads_(CidLength)
        const uint8_t* CidBuffer
    );

QUIC_CID_QUIC_LIST_ENTRY*
QuicConnGetDestCidFromSeq(
    _In_ QUIC_CONNECTION* Connection,
    _In_ QUIC_VAR_INT SequenceNumber,
    _In_ BOOLEAN RemoveFromList
    );

uint8_t
QuicPacketTraceType(
    _In_ const QUIC_SENT_PACKET_METADATA* Metadata
    );

int64_t
QuicTimeEpochMs64(
    void
    );