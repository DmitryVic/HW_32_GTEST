

# Включаем GoogleTest (или другую библиотеку тестирования)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Для Windows: запретить переопределение настройки компилятора/линкера родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл для тестов
add_executable(Gtest
    test_my_class.cpp
)

# Линкуем тесты с нашей библиотекой и GTest
target_link_libraries(Gtest
    PRIVATE
        HW_32
        GTest::gtest_main
        GTest::gmock_main
)

# Добавляем тест в CTest
include(GoogleTest)
gtest_discover_tests(Gtest)