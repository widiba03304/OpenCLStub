cmake_minimum_required(VERSION 3.5)

add_subdirectory(
    third_party/abseil-cpp
)

add_library(
    OpenCLStub

    STATIC
    
    src/opencl_stub.cc
)

add_executable(
    absl_test 
    
    test/test.cc
)

target_include_directories(
    OpenCLStub

    PRIVATE

    "include"
)

target_include_directories(
    absl_test

    PRIVATE

    "include"
)

target_link_libraries(
    OpenCLStub

    ${CMAKE_DL_LIBS}
    absl::status
)

target_link_libraries(
    absl_test

    OpenCLStub
    absl::status
)