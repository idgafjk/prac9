
#ifndef GAME_H
#define GAME_H

#include "settings.h"
#include <vector>

void displayBoard(const std::vector<std::vector<char>>& board);
bool isWin(const std::vector<std::vector<char>>& board, char symbol);
bool isBoardFull(const std::vector<std::vector<char>>& board);
void afterGameMenu(Settings& settings);

#endif
