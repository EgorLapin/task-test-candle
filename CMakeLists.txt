cmake_minimum_required(VERSION 3.14)
project(testproj CXX)

add_executable(${PROJECT_NAME} 
    main.cpp 
    candle.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)