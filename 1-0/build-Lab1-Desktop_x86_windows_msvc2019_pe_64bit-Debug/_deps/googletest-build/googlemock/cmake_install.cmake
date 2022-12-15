# Install script for directory: D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-src/googlemock

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Lab1")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-src/googlemock/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/lib/gmock.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/lib/gmock_main.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmockpdb_debug_postfix-NOTFOUND.pdb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock_mainpdb_debug_postfix-NOTFOUND.pdb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-build/googletest/generated/gmock.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-build/googletest/generated/gmock_main.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-build/googletest/cmake_install.cmake")

endif()

