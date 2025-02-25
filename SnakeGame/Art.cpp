#include "Art.h"

std::vector<std::string> Art::text_win = {
    " _ _ _ _     ",
    "| | | |_|___ ",
    "| | | | |   |",
    "|_____|_|_|_|"
};

std::vector<std::string> Art::text_gameOver = {
    " _____                     _____                ",
    "|   __| ___  _____  ___   |     | _ _  ___  ___ ",
    "|  |  || .'||     || -_|  |  |  || | || -_||  _|",
    "|_____||__,||_|_|_||___|  |_____| \\_/ |___||_|  "
};

std::vector<std::string> Art::text_cheating = {
    " _____ _           _           ",
    "|     | |_ ___ ___| |_ ___ ___ ",
    "|   --|   | -_| .'|  _| -_|  _|",
    "|_____|_|_|___|__,|_| |___|_|  "
};

const std::vector<std::string>& Art::GetWinText() {
    return text_win;
}

const std::vector<std::string>& Art::GetGameOverText() {
    return text_gameOver;
}

const std::vector<std::string>& Art::GetCheatingText() {
    return text_cheating;
}

void Art::PrintText(const std::vector<std::string>& text) {
    for (const auto& line : text) {
        std::cout << line << std::endl;
    }
}