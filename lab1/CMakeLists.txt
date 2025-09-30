cmake_minimum_required(VERSION 3.26)
set(PROJ lab1)
set(CMAKE_BUILD_TYPE Debug)
project(${PROJ})
add_executable(${PROJ}
    lab1.cpp
    HoldEmDeck.cpp
    PinochleDeck.cpp
    Game.cpp
    PinochleGame.cpp
    HoldEmGame.cpp
    suits.cpp
)
set_target_properties(${PROJ} PROPERTIES
    CXX_STANDARD 17
    COMPILE_OPTIONS -Wall
    COMPILE_DEFINITIONS TEMPLATE_HEADERS_INCLUDE_SOURCE
)
