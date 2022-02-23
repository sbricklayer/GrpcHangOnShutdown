
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

project (MyDLL LANGUAGES CXX)
include(GenerateExportHeader)

set(SOURCES
	ExampleServiceAccessor.cpp
)
set(HEADERS
	ExampleServiceAccessor.h
 )

add_library(MyDLL SHARED ${PROTO_FILES} ${SOURCES} ${HEADERS})
generate_export_header(MyDLL)

target_include_directories(MyDLL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(MyDLL PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(MyDLL
	PRIVATE        
		protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

install(TARGETS MyDLL DESTINATION "bin")
