# CMakeList.txt: проект CMake для EvoTest; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)


# Добавьте источник в исполняемый файл этого проекта.
add_executable (Life "Core.cpp" "Core.h"  "Cells.h" "Field.h" "Field.cpp" "Source.cpp" "FieldLoader.h" "FieldLoader.cpp" "EvoGUI.h" "EvoGUI.cpp" "MenuGUI.h" "MenuGUI.cpp" "Strategy.cpp" "Strategy.h" "MainGUI.h" "MainGUI.cpp" "FieldSaver.h" "FieldSaver.cpp")

