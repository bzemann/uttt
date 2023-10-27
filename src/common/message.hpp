//
// Created by basil zemann on 27.10.2023.
//

#ifndef PROJECT_MESSAGE_HPP
#define PROJECT_MESSAGE_HPP

#include "common.hpp"

using u8 = std::uint8_t;

enum class MessageType {
    Client,
    Server
};

struct Message {
    MessageType message_type;
    GameState full_state;

    explicit Message(MessageType message_type,
                     GameState full_state):
            message_type(message_type),
            full_state(full_state) {}
};

enum ClientMessageType {
    ConnectionClientRequest,
    GameRestartClientRequest,
    TryChooseInnerBoardClientRequest,
    TryMoveClientRequest,
    ForfeitClientMessage,
    // DisconnectClientMessage,
    // Message if a player clicks on the x on the window
};

struct ClientMessage: Message {
    ClientMessageType client_message_type;

    explicit ClientMessage(ClientMessageType client_message_type,
                           GameState full_state):
            Message(MessageType::Client, full_state),
            client_message_type(client_message_type) {}
};

struct ConnectionClientRequest: ClientMessage {
    std::string username;

    explicit ConnectionClientRequest(std::string username,
                                     GameState full_state):
            ClientMessage(ClientMessageType::ConnectionClientRequest, full_state),
            username(std::move(username)) {}
};

struct TryChooseInnerBoardClientRequest: ClientMessage {
    std::array<u8 , 2> position;

    explicit TryChooseInnerBoardClientRequest(std::array<u8, 2> position,
                                              GameState full_state):
            ClientMessage(ClientMessageType::TryChooseInnerBoardClientRequest, full_state),
            position(position) {}
};

struct TryMoveClientRequest: ClientMessage {
    std::array<u8, 2> position;

    explicit TryMoveClientRequest(std::array<u8, 2> position,
                                  GameState full_state):
            ClientMessage(ClientMessageType::TryMoveClientRequest, full_state),
            position(position) {}
};

enum ServerMessageType {
    ConnectionServerResponse,
    GameStartServerMessage,
    ChooseInnerBoardServerMessage,
    TryChooseInnerBoardServerResponse,
    NewTurnServerMessage,
    TryMoveServerResponse,
    GameEndingServerMessage,
};

struct ServerMessage: Message {
    ServerMessageType server_message_type;

    explicit ServerMessage(ServerMessageType server_message_type,
                           GameState full_state):
            Message(MessageType::Server, full_state),
            server_message_type(server_message_type) {}
};

struct ConnectionServerResponse: ServerMessage {
    bool success;
    std::string username;
    PlayerSymbol symbol;

    explicit ConnectionServerResponse(GameState full_state,
                                      bool success,
                                      std::string username,
                                      PlayerSymbol symbol):
            ServerMessage(ServerMessageType::ConnectionServerResponse, full_state),
            success(success),
            username(std::move(username)),
            symbol(symbol) {}
};

struct TryChooseInnerBoardServerResponse: ServerMessage {
    bool success;
    std::array<u8, 2> position;

    explicit TryChooseInnerBoardServerResponse(GameState full_state,
                                               bool success,
                                               std::array<u8, 2> position):
            ServerMessage(ServerMessageType::TryChooseInnerBoardServerResponse, full_state),
            success(success),
            position(position) {}
};

struct NewTurnServerMessage: ServerMessage {
    PlayerSymbol symbol;
    std::array<u8, 2> inner_board_position;

    explicit NewTurnServerMessage(GameState full_state,
                                  PlayerSymbol symbol,
                                  std::array<u8, 2> inner_board_position):
            ServerMessage(ServerMessageType::NewTurnServerMessage, full_state),
            symbol(symbol),
            inner_board_position(inner_board_position) {}
};

struct TryMoveServerResponse: ServerMessage {
    bool success;
    std::array<u8, 2> position;

    explicit TryMoveServerResponse(GameState full_state,
                                   bool success,
                                   std::array<u8, 2> position):
            ServerMessage(ServerMessageType::TryMoveServerResponse, full_state),
            success(success),
            position(position) {}
};

struct GameEndingServerMessage: ServerMessage {
    GameEndType end_type;
    PlayerSymbol symbol;

    explicit GameEndingServerMessage(GameState full_state,
                                     PlayerSymbol symbol,
                                     GameEndType end_type):
            ServerMessage(ServerMessageType::GameEndingServerMessage, full_state),
            end_type(end_type),
            symbol(symbol) {}
};

#endif //PROJECT_MESSAGE_HPP
