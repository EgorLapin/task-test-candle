cmake_minimum_required(VERSION 3.14)
project(testproj CXX)

# Найти GTest
find_package(GTest REQUIRED)

# Включить заголовочные файлы GTest
include_directories(${GTEST_INCLUDE_DIRS})

# Исполняемый файл тестов
add_executable(${PROJECT_NAME} main.cpp candle.cpp)

# Прилинковать библиотеки GTest
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main pthread)

# Стандарт C++
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)