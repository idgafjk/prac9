
add_library(tictactoe
    settings.cpp
    history.cpp
    game.cpp
)

target_include_directories(tictactoe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
