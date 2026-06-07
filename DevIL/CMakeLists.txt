cmake_minimum_required(VERSION 2.6)

if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()

project(ImageLib)

if(MSVC)
	set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
# include our custom modules
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(src-IL)
add_subdirectory(src-ILU)
add_subdirectory(src-ILUT)
option(IL_TESTS "build DevIL tests" ON)
if (IL_TESTS)
    ENABLE_TESTING()
    Add_Subdirectory(test)
endif()

