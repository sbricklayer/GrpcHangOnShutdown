
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

project (DLL3 LANGUAGES CXX)
include(GenerateExportHeader)

set(SOURCES
	GrpcClient2.cpp
)
set(HEADERS
	GrpcClient2.h
 )

add_library(DLL3 SHARED ${PROTO_FILES} ${SOURCES} ${HEADERS})
generate_export_header(DLL3)

target_include_directories(DLL3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DLL3 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(DLL3
	PRIVATE        
		protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

install(TARGETS DLL3 DESTINATION "bin/InfiniteBlock")
