set(_NAME oakplayer)

set(_SOURCES
    player.cpp
)

add_library(${_NAME} ${_SOURCES})

target_include_directories(${_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
