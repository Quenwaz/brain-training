cmake_minimum_required (VERSION 3.8)
project ("brain-training")

set(${PROJECT_NAME}_INCLUDE )
add_library(${PROJECT_NAME}_static INTERFACE)
target_include_directories(${PROJECT_NAME}_static INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/case)


include(CTest)
# find_package(GTest QUIET)
message(STATUS "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
if (NOT GTEST_FOUND)
    message("GoogleTest not found. Consider installing it on your system. Downloading it from source...")
    include(FetchContent)
    set(FETCHCONTENT_QUIET OFF)
    # 设置依赖目录
    get_filename_component(deps "../deps" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
    set(FETCHCONTENT_BASE_DIR ${deps})
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://gitee.com/mirrors/googletest.git
        GIT_TAG release-1.12.1
        GIT_SHALLOW true
    )
     
    set(BUILD_GMOCK OFF CACHE BOOL "")
    FetchContent_GetProperties(googletest)
    if(NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
        add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    endif()
endif()

add_subdirectory(tests)