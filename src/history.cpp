
#include "history.h"
#include <iostream>
#include <fstream>

const std::string HISTORY_FILE = "history.txt";

void showHistory() {
    std::ifstream file(HISTORY_FILE);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "Game history is empty." << std::endl;
    }
    file.close();
}

void saveGameResult(const std::string& player1, const std::string& player2, int fieldSize, const std::string& winner) {
    std::ofstream file(HISTORY_FILE, std::ios::app);
    if (file.is_open()) {
        file << player1 << " vs " << player2 << " | Field: " << fieldSize << "x" << fieldSize << " | Winner: " << winner << std::endl;
    } else {
        std::cout << "Unable to open history file for saving game result." << std::endl;
    }
    file.close();
}
