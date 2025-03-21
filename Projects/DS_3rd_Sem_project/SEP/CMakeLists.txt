cmake_minimum_required(VERSION 3.28)
project(SEP)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Add source files
file(GLOB SOURCES src/*.cpp)

# Create the executable
add_executable(SEP ${SOURCES}
        include/DataRetriever.h
        include/Date.h
        include/OutlierAnalysis.h
        include/StatsAnalysis.h
        include/TrendAnalysis.h
        src/main.cpp
        src/MinHeap.cpp
        "src/MaxHeap .cpp"
        "include/MaxHeap .h"
        include/MinHeap.h)
