cmake_minimum_required(VERSION 3.21)
project(AdjacentMatrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdjacentMatrix main.cpp AdjMatGraph.h SrchAMGraph.h CircularQueue.h ConnectedComponentGraph.h TopoSortGraph.h)
