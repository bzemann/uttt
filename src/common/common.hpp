//
// Created by basil zemann on 27.10.2023.
//

#ifndef PROJECT_COMMON_HPP
#define PROJECT_COMMON_HPP

#include <iostream>
#include <optional>
#include <array>

enum class PlayerSymbol {
    Cross,
    Circle
};

enum class InnerBoardState {
    Free,
    Occupied,
    Drawn
};

struct Tile {
    std::optional<PlayerSymbol> state;
};

struct InnerBoard {
    InnerBoardState state;
    std::array<Tile, 9> tiles;
};

struct OuterBoard {
    std::array<InnerBoard, 9> inners;
};

struct GameState {
    OuterBoard board;
    PlayerSymbol current_player;
};

enum class GameEndType {
    Win,
    Forfeit,
    Draw
};

#endif //PROJECT_COMMON_HPP
