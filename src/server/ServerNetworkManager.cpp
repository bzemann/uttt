//
// Created by basil zemann on 30.10.2023.
//
#include "ServerNetworkManager.hpp"

std::random_device rd;
std::mt19937 gen37(rd());

PlayerSymbol choose_player_symbol(){
    std::uniform_int_distribution<> distr(0, 1);
    int r_var = distr(gen37);

    if(r_var == 0){
        return PlayerSymbol::Cross;
    }
    else {
        return PlayerSymbol::Circle;
    }
}


void ServerNetworkManager::connect() {

}

void ServerNetworkManager::listener_loop() {

}