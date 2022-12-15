# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-src"
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-build"
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/WORK/university2/1-0/NSU3/1-0/build-Lab1-Desktop_x86_windows_msvc2019_pe_64bit-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
