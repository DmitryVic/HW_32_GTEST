
# Собираем библиотеку из кода src
add_library(HW_32 STATIC main.cpp my_class.h)

add_executable(HW_32_app main.cpp)

# Задаем одинаковые имя выходного файла
set_target_properties(HW_32_app PROPERTIES OUTPUT_NAME "HW_32")

# Делаем заголовки доступными при подключении
target_include_directories(HW_32 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

