
#include "settings.h"
#include "history.h"
#include "game.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void mainMenu() {
    Settings settings = loadSettings();
    while (true) {
        std::cout << "=== Tic-Tac-Toe ===" << std::endl;
        std::cout << "1. Start New Game" << std::endl;
        std::cout << "2. Settings" << std::endl;
        std::cout << "3. Game History" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Who will play first?" << std::endl;
            std::cout << "1. " << settings.player1 << std::endl;
            std::cout << "2. " << settings.player2 << std::endl;
            int firstPlayerChoice;
            std::cin >> firstPlayerChoice;

            std::string currentPlayer = (firstPlayerChoice == 1) ? settings.player1 : settings.player2;
            char currentSymbol = 'X';
            std::string opponent = (firstPlayerChoice == 1) ? settings.player2 : settings.player1;
            char opponentSymbol = 'O';

            std::vector<std::vector<char>> board(settings.fieldSize, std::vector<char>(settings.fieldSize, '.'));

            while (true) {
                displayBoard(board);
                int row, col;
                std::cout << currentPlayer << "'s turn (" << currentSymbol << "). Enter row and column (0-based): ";
                std::cin >> row >> col;

                if (row >= 0 && row < settings.fieldSize && col >= 0 && col < settings.fieldSize && board[row][col] == '.') {
                    board[row][col] = currentSymbol;

                    if (isWin(board, currentSymbol)) {
                        displayBoard(board);
                        std::cout << currentPlayer << " wins!" << std::endl;
                        saveGameResult(settings.player1, settings.player2, settings.fieldSize, currentPlayer);
                        afterGameMenu(settings);
                        break;
                    }

                    if (isBoardFull(board)) {
                        displayBoard(board);
                        std::cout << "It's a draw!" << std::endl;
                        saveGameResult(settings.player1, settings.player2, settings.fieldSize, "Draw");
                        afterGameMenu(settings); 
                        break;
                    }

                    std::swap(currentPlayer, opponent);
                    std::swap(currentSymbol, opponentSymbol);
                } else {
                    std::cout << "Invalid move, try again." << std::endl;
                    std::cout << "Zanovo." << std::endl;
                }
            }
            break;
        }
        case 2:
            settingsMenu(settings);
            break;
        case 3:
            showHistory();
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            return;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }

        std::cout << std::endl;
    }
}

int main() {
    mainMenu();
    return 0;
}
