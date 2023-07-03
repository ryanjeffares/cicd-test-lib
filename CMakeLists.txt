cmake_minimum_required(VERSION 3.23)
project(cicd-test-lib)

include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.3.2
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(Catch2)

add_library(cicd-test-lib src/lib.cpp)
add_executable(tests tests/tests.cpp src/lib.cpp)

set_property(TARGET cicd-test-lib PROPERTY CXX_STANDARD 23)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(cicd-test-lib PRIVATE CICD-TEST-LIB_DEBUG)
endif()

target_compile_options(cicd-test-lib PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_link_libraries(cicd-test-lib PRIVATE fmt::fmt)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
