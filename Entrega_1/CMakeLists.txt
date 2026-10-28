cmake_minimum_required(VERSION 3.10)

project(Entrega1_Corte3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(underground_system OBJECT
    "1396 Design Underground System.cpp"
)

add_library(atm_machine OBJECT
    "3709 Design an ATM Machine.cpp"
)

add_library(auction_system OBJECT
    "3815 Design Auction System - LeetCode.cpp"
)


add_subdirectory("Clock in C++ on Exercism")
add_subdirectory("Meetup in C++ on Exercism")
