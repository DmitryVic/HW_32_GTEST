cmake_minimum_required(VERSION 3.14)
project(HW_31 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Опция: собирать ли тесты (по умолчанию ON)
option(BUILD_TESTING "Build tests" ON)

# Подключаем подкаталоги
add_subdirectory(HW_32) 

if(BUILD_TESTING)
    enable_testing()            # включает поддержку ctest
    add_subdirectory(Gtest)     # тесты
endif()