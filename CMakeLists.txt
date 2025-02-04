cmake_minimum_required(VERSION 3.15)
project(Vector3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector3
        main.cpp
        Vec3.cpp
        Transform.cpp
        Utils.cpp
        Tests.cpp
)
