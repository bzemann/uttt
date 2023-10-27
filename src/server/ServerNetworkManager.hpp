//
// Created by basil zemann on 30.10.2023.
//

#ifndef UTTT_SERVERNETWORKMANAGER_HPP
#define UTTT_SERVERNETWORKMANAGER_HPP

#include "../common/common.hpp"
#include "../common/message.hpp"

#include <random>
#include <functional>
#include <thread>
#include <unordered_map>

#include <sockpp/tcp_socket.h>
#include <sockpp/tcp_acceptor.h>
#include <sockpp/tcp_connector.h>

struct ServerNetworkManager {
    private:
        sockpp::tcp_acceptor _acc;
        std::unordered_map<std::string, sockpp::tcp_socket> _address_to_socket;
    public:
        void connect();
        void listener_loop();



};

#endif //UTTT_SERVERNETWORKMANAGER_HPP
