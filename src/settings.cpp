
#include "settings.h"
#include <iostream>
#include <fstream>

const std::string SETTINGS_FILE = "settings.txt";

Settings loadSettings() {
    Settings settings;
    std::ifstream file(SETTINGS_FILE);
    if (file.is_open()) {
        file >> settings.fieldSize;
        file.ignore();
        std::getline(file, settings.player1);
        std::getline(file, settings.player2);
    } else {
        std::cout << "Unable to open settings file. Using default settings." << std::endl;
    }
    file.close();
    return settings;
}

void saveSettings(const Settings& settings) {
    std::ofstream file(SETTINGS_FILE);
    if (file.is_open()) {
        file << settings.fieldSize << std::endl;
        file << settings.player1 << std::endl;
        file << settings.player2 << std::endl;
    } else {
        std::cout << "Unable to open settings file for saving." << std::endl;
    }
    file.close();
}

void settingsMenu(Settings& settings) {
    std::cout << "=== Settings ===" << std::endl;
    std::cout << "1. Set field size (minimum 3x3)" << std::endl;
    std::cout << "2. Set Player 1 name" << std::endl;
    std::cout << "3. Set Player 2 name" << std::endl;
    std::cout << "0. Return to main menu" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter field size (minimum 3): ";
            std::cin >> settings.fieldSize;
            if (settings.fieldSize < 3)
                settings.fieldSize = 3;
            break;
        case 2:
            std::cout << "Enter Player 1 name: ";
            std::cin.ignore();
            std::getline(std::cin, settings.player1);
            break;
        case 3:
            std::cout << "Enter Player 2 name: ";
            std::cin.ignore();
            std::getline(std::cin, settings.player2);
            break;
        case 0:
            return;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }

    saveSettings(settings);
    std::cout << "Settings saved!" << std::endl;
}
