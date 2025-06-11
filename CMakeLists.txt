
    cmake_minimum_required(VERSION 3.12)
    project(tetris)

    set(CMAKE_CXX_STANDARD 14)

    # Add your source files here
    set(SOURCE_FILES tetris.cpp)

    # raylib paths
    set(raylib_INCLUDE_DIR "D:/msys64/mingw64/include")
    set(raylib_LIBRARY "D:/msys64/mingw64/lib")

    # raylib
    find_package(raylib 5.0 QUIET)
    if (NOT raylib_FOUND)
        include(FetchContent)
        FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/master.tar.gz
        )
        FetchContent_GetProperties(raylib)
        if (NOT raylib_POPULATED)
            set(FETCHCONTENT_QUIET NO)
            FetchContent_Populate(raylib)
            set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
            add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        endif()
    endif()

    add_executable(tetris ${SOURCE_FILES})
    target_link_libraries(tetris raylib)
    