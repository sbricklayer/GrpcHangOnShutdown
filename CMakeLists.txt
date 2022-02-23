cmake_minimum_required(VERSION 3.13)
project(grpc-cpp-test LANGUAGES CXX)
find_package(Threads)

set(LIBGRPC_DIR "c:/temp/grpc")

set (protobuf_DIR "${LIBGRPC_DIR}/cmake")
find_package(protobuf CONFIG REQUIRED)

set (absl_DIR "${LIBGRPC_DIR}/lib/cmake/absl")

set (gRPC_DIR "${LIBGRPC_DIR}/lib/cmake/grpc")
find_package(gRPC CONFIG REQUIRED)

add_subdirectory(MyDLL)
add_subdirectory(InfiniteBlockExample)
