set(_NAME oakplayer)

set(_SOURCES
    player.cpp
    common/event_loop_libev.cpp
    common/http/http_client_libcurl.cpp
)

find_package(Threads REQUIRED)

add_library(${_NAME} ${_SOURCES})

target_link_libraries(${_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    ev
)

target_include_directories(${_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
