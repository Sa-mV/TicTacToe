//
//  functions.cpp
//  TicTacToe
//
//  Created by Abdulrahman Hanifa on 29/07/2024.
//

#include<iostream>
#include<string>
#include "functions.hpp"

void print(const std::string* layout) {
    
    for (int i = 0; i < 19; i++) {
        std::cout << layout[i];
    }
}

int takeInput(int& turn, int * usedSlot, char currentPlayer) {
    
    char inputSlot;
    int currentPlayerInt;
    
    if (currentPlayer == 'X')
        currentPlayerInt = 1;
    else
        currentPlayerInt = 2;
    
    std::cout << "Player " << currentPlayerInt << ", enter a slot number: ";
    std::cin >> inputSlot;
    
    while (inputSlot < 49 || inputSlot > 57 || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid slot. Try again: ";
        std::cin >> inputSlot;
    }
    
    int newSlot = inputSlot - '0';
    
    for (int i = 0; i < turn; i++) {
        while (newSlot == usedSlot[i]) {
            std::cout << "Slot is already used. Try again: ";
            std::cin >> newSlot;
        }
    }
    usedSlot[turn] = newSlot;
    turn++;
    
    return newSlot;
}

void updateLayout(std::string* layout, int newSlot, char& currentPlayer) {
    
    newSlot = newSlot*2 -1;
    
    if (currentPlayer == 'X') {
        layout[newSlot] = "X";
        currentPlayer = 'O';
    } else {
        layout[newSlot] = "O";
        currentPlayer = 'X';
    }
}

void victoryCheck(std::string* layout, int turn, bool& victory, int& winner) {
    
    if (turn > 3) { // check if the
        if (layout[1]  == layout[3]  && layout[3]  == layout[5])
            victoryUpdate(victory, winner, layout[1]);
        else if (layout[7]  == layout[9]  && layout[9]  == layout[11])
            victoryUpdate(victory, winner, layout[7]);
        else if (layout[13] == layout[15] && layout[15] == layout[17])
            victoryUpdate(victory, winner, layout[13]);
        else if (layout[1]  == layout[7]  && layout[7]  == layout[13])
            victoryUpdate(victory, winner, layout[1]);
        else if (layout[3]  == layout[9]  && layout[9]  == layout[15])
            victoryUpdate(victory, winner, layout[3]);
        else if (layout[5]  == layout[11] && layout[11] == layout[17])
            victoryUpdate(victory, winner, layout[5]);
        else if (layout[1]  == layout[9]  && layout[9]  == layout[17])
            victoryUpdate(victory, winner, layout[1]);
        else if (layout[5]  == layout[9]  && layout[9]  == layout[13])
            victoryUpdate(victory, winner, layout[5]);
        }
}

void victoryUpdate(bool& victory, int& winner, std::string slot) {
    victory = true;
    if (slot == "X") {
        winner = 1;
    } else {
        winner = 2;
    }
}

void message(bool victory, int winner) {
    std::cout << "The game has ended. ";
    
    if (victory) {
        std::cout << "The winner is player " << winner << std::endl;
    } else {
        std::cout << "It is a tie" << std::endl;
    }
}

void reset(std::string layout[], int& turn, int* usedSlot, char& currentPlayer, bool& victory, int& winner, char& again) {
    
    std::string tempLayout[19] = {
        "**********************\n*   ",
        "1",
        "  *   ",
        "2",
        "  *   ",
        "3",
        "  *\n*      *      *      *\n**********************\n*   ",
        "4",
        "  *   ",
        "5",
        "  *   ",
        "6",
        "  *\n*      *      *      *\n**********************\n*   ",
        "7",
        "  *   ",
        "8",
        "  *   ",
        "9",
        "  *\n*      *      *      *\n**********************\n\n"
    };
    
    for (int i = 0; i < 19; i++)
        layout[i] = tempLayout[i];
    
    turn = 0;
    
    for (int i = 0; i < 9; i++) {
        usedSlot[i] = -1;
    }
    currentPlayer = 'X';
    victory = false;
    winner = -1;
    again = 'n';
}
