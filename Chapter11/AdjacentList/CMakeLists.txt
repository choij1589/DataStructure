cmake_minimum_required(VERSION 3.21)
project(AdjacentList)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdjacentList main.cpp Node.h AdjListGraph.h CircularQueue.h SrchALGraph.h TopoSortGraph.h ArrayStack.h)
