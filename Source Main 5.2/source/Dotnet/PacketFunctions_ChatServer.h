﻿// <copyright file="PacketFunctions.h" company="MUnique">
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
// </copyright>

//------------------------------------------------------------------------------
// <auto-generated>
//     This source code was auto-generated by an XSL transformation.
//     Do not change this file. Instead, change the XML data which contains
//     the packet definitions and re-run the transformation (publish/rebuild the
//     managed library project).
// </auto-generated>
//------------------------------------------------------------------------------

#pragma once

#include "stdafx.h"
#include "PacketFunctions_Custom.h"
#include <coreclr_delegates.h>

/// <summary>
/// Extension methods to start writing messages of this namespace on a <see cref="Connection"/>.
/// </summary>
class PacketFunctions_ChatServer : public PacketFunctions_ChatServer_Custom
{
public:

    /// <summary>
    /// Sends a Authenticate to this connection.
    /// </summary>
    /// <param name="roomId">The room id.</param>
    /// <param name="token">A token (integer number), formatted as string and "encrypted" with the 3-byte XOR key (FC CF AB).</param>
    /// <param name="tokenByteLength">The length of <paramref name="token"/> in bytes.
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client after it connected to the server, to authenticate itself.
    /// Causes reaction on server side: The server will check the token. If it's correct, the client gets added to the requested chat room.
    /// </remarks>
    void SendAuthenticate(uint16_t roomId, const BYTE* token, uint32_t tokenByteLength);

    /// <summary>
    /// Sends a ChatRoomClientJoined to this connection.
    /// </summary>
    /// <param name="clientIndex">The client index.</param>
    /// <param name="name">The name.</param>
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after another chat client joined the chat room.
    /// Causes reaction on client side: The client will add the client in its list (if over 2 clients are connected to the same room), or show its name in the title bar.
    /// </remarks>
    void SendChatRoomClientJoined(BYTE clientIndex, const wchar_t* name);

    /// <summary>
    /// Sends a LeaveChatRoom to this connection.
    /// </summary>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client when it leaves the chat room, before the connection closes.
    /// Causes reaction on server side: The server will remove the client from the chat room, notifying the remaining clients.
    /// </remarks>
    void SendLeaveChatRoom();

    /// <summary>
    /// Sends a ChatRoomClientLeft to this connection.
    /// </summary>
    /// <param name="clientIndex">The client index.</param>
    /// <param name="name">The name.</param>
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after a chat client left the chat room.
    /// Causes reaction on client side: The client will remove the client from its list, or mark its name in the title bar as offline.
    /// </remarks>
    void SendChatRoomClientLeft(BYTE clientIndex, const wchar_t* name);

    /// <summary>
    /// Sends a ChatMessage to this connection.
    /// </summary>
    /// <param name="senderIndex">The sender index.</param>
    /// <param name="messageLength">The message length.</param>
    /// <param name="message">The message. It's "encrypted" with the 3-byte XOR key (FC CF AB).</param>
    /// <param name="messageByteLength">The length of <paramref name="message"/> in bytes.
    /// <remarks>
    /// Is sent by the server when: This packet is sent by the server after another chat client sent a message to the current chat room.
    /// Causes reaction on client side: The client will show the message.
    /// </remarks>
    void SendChatMessage(BYTE senderIndex, BYTE messageLength, const BYTE* message, uint32_t messageByteLength);

    /// <summary>
    /// Sends a KeepAlive to this connection.
    /// </summary>
    /// <remarks>
    /// Is sent by the client when: This packet is sent by the client in a fixed interval.
    /// Causes reaction on server side: The server will keep the connection and chat room intact as long as the clients sends a message in a certain period of time.
    /// </remarks>
    void SendKeepAlive();
};