cmake_minimum_required(VERSION 3.30)
project(lab8_files_dynamic_arrays C)

set(CMAKE_C_STANDARD 17)

include_directories(.)
include_directories(utils)

add_executable(lab8_files_dynamic_arrays
    utils/fileUtils.c
    utils/sortUtils.c
    cscd240Lab7.c
    lab7.c
    )

#Complete Re-Write Counter: 10

