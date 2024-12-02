cmake_minimum_required(VERSION 3.28)
project(likou)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SKELETON_SOURCES "skeleton/*.cpp")
file(GLOB SOLVER_SOURCES "solver/**/*.cpp")

add_executable(likou ${SKELETON_SOURCES} ${SOLVER_SOURCES} solver/dfs/77.cpp solver/dfs/79.cpp solver/dfs/51.cpp solver/bfs/934.cpp)