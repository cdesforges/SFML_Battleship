cmake_minimum_required(VERSION 3.27)
project(06_Lab_Battleship)

set(CMAKE_CXX_STANDARD 17)

add_executable(06_Lab_Battleship main.cpp
        Battleship.cpp
        Battleship.h
        Enums.h
        Board.cpp
        Board.h
        Ship.cpp
        Ship.h
        "Graphic Assets/Square.cpp"
        "Graphic Assets/Square.h"
        Coordinates.cpp
        Coordinates.h
        "Graphic Assets/Animation.cpp"
        "Graphic Assets/Animation.h"
        "Graphic Assets/HitAnimation.cpp"
        "Graphic Assets/HitAnimation.h"
        "Graphic Assets/Menu.h"
        "Graphic Assets/Menu.cpp"
        ComPlayer.cpp
        ComPlayer.h
        Rand.h
        Rand.cpp
        "Game States/StateManager.cpp"
        "Game States/StateManager.h"
        "Game States/State.cpp"
        "Game States/State.h"
        "Game States/MainMenuState.cpp"
        "Game States/MainMenuState.h"
        "Game States/MainGameState.cpp"
        "Game States/MainGameState.h"
        "Graphic Assets/Button.cpp"
        "Graphic Assets/Button.h"
        "Game States/PlaceShipsState.cpp"
        "Game States/PlaceShipsState.h"
        "Graphic Assets/ShipPalette.cpp"
        "Graphic Assets/ShipPalette.h"
        "ComAI.cpp"
        "ComAI.h"
        Player.cpp
        Player.h
        TextureManager.cpp
        TextureManager.h
        "Attack States/AttackState.cpp"
        "Attack States/AttackState.h"
        "Attack States/AttackStateManager.cpp"
        "Attack States/AttackStateManager.h"
        "Attack States/SearchState.cpp"
        "Attack States/SearchState.h"
        HitResult.h
        "Attack States/RandomAttackState.cpp"
        "Attack States/RandomAttackState.h"
        "Attack States/DestroyState.cpp"
        "Attack States/DestroyState.h"
        Direction.h
        "Game States/EndGameState.cpp"
        "Game States/EndGameState.h"
)

target_link_libraries(06_Lab_Battleship sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
