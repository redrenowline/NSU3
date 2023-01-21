# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project ("EvoTest")


find_package(Qt6 COMPONENTS Widgets REQUIRED)


# Включите подпроекты.
add_subdirectory ("Life")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
