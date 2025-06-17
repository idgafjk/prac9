
#include "game.h"
#include <iostream>

void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isWin(const std::vector<std::vector<char>>& board, char symbol) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < n; j++) {
            if (board[i][j] != symbol) rowWin = false;
            if (board[j][i] != symbol) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    bool diagWin1 = true, diagWin2 = true;
    for (int i = 0; i < n; i++) {
        if (board[i][i] != symbol) diagWin1 = false;
        if (board[i][n - i - 1] != symbol) diagWin2 = false;
    }
    return diagWin1 || diagWin2;
}

bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '.') return false;
        }
    }
    return true;
}

void afterGameMenu(Settings& settings) {
    while (true) {
        std::cout << "What would you like to do next?" << std::endl;
        std::cout << "1. Start a new game" << std::endl;
        std::cout << "2. Return to main menu" << std::endl;
        std::cout << "Your choice: ";
        
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
        case 2:
            return;  
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
}
