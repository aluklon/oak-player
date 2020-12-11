set(_NAME oakplayer)

set(_SOURCES
    player.cpp
    common/event_loop_libev.cpp
)

add_library(${_NAME} ${_SOURCES})

target_link_libraries(${_NAME}
    ev
)

target_include_directories(${_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
