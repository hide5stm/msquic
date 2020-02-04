/*++

    Copyright (c) Microsoft Corporation.
    Licensed under the MIT License.

Abstract:

    QUIC protocol versions.

--*/

#pragma once

//
// The QUIC version numbers, in network byte order.
//
#define QUIC_VERSION_VER_NEG    0x00000000      // Version for 'Version Negotiation'
#define QUIC_VERSION_1          0x01000000      // First official version
#define QUIC_VERSION_MS_1       0x0000cdab      // First Microsoft version (currently same as latest draft)
#define QUIC_VERSION_DRAFT_25   0x190000ff      // IETF draft 25

//
// The QUIC version numbers, in host byte order.
//
#define QUIC_VERSION_VER_NEG_H  0x00000000      // Version for 'Version Negotiation'
#define QUIC_VERSION_1_H        0x00000001      // First official version
#define QUIC_VERSION_1_MS_H     0xabcd0000      // First Microsoft version (-1412628480 in decimal)
#define QUIC_VERSION_DRAFT_25_H 0xff000019      // IETF draft 25

//
// Represents a reserved version value; used to force version negotation.
//
#define QUIC_VERSION_RESERVED       0x0a0a0a0a
#define QUIC_VERSION_RESERVED_MASK  0x0f0f0f0f

//
// The latest QUIC version number.
//
#define QUIC_VERSION_LATEST     QUIC_VERSION_DRAFT_25
#define QUIC_VERSION_LATEST_H   QUIC_VERSION_DRAFT_25_H

inline
BOOLEAN
QuicIsVersionSupported(
    _In_ uint32_t Version // Network Byte Order
    )
{
    switch (Version) {
    case QUIC_VERSION_VER_NEG:
    case QUIC_VERSION_DRAFT_25:
    case QUIC_VERSION_MS_1:
        return TRUE;
    default:
        return FALSE;
    }
}

inline
BOOLEAN
QuicIsVersionReserved(
    _In_ uint32_t Version // Either Byte Order
    )
{
    return (Version & QUIC_VERSION_RESERVED_MASK) == QUIC_VERSION_RESERVED;
}