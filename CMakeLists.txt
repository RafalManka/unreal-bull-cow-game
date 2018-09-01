cmake_minimum_required(VERSION 3.12)
project(BullCowGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(BullCowGame)

add_executable(BullCowGame
        BullCowGame/main.cpp BullCowGame/FBullCowGame.cpp BullCowGame/FBullCowGame.h)
