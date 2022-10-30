# CMakeList.txt: проект CMake для CMakeProject1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
enable_testing()

# Добавьте источник в исполняемый файл этого проекта.
add_executable (BigInt "BigInt.h" "BigInt.cpp" "main.cpp")
target_link_libraries(BigInt gtest gtest_main)

include(GoogleTest)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
