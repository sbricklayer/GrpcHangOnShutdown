project (InfiniteBlockExample LANGUAGES CXX)

set(SOURCES
  main.cpp
)

set(HEADERS

)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})
add_executable(InfiniteBlockExample ${SOURCES} ${HEADERS})

target_link_libraries(InfiniteBlockExample
    PUBLIC
        MyDLL
)

install(TARGETS InfiniteBlockExample DESTINATION "bin")
