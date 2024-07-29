//
//  main.cpp
//  TicTacToe
//
//  Created by Abdulrahman Hanifa on 27/07/2024.
//

#include<iostream>
#include<string>
#include"functions.hpp"

int main() {
    
    std::string layout[19] = {
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
    int turn = 0;
    int usedSlot[9];
    char currentPlayer = 'X';
    bool victory = false;
    int winner;
    char again;
    
    std::cout << "Welcome to TicTacToe. Player 1 is X, plyaer 2 is O. Begin..." << std::endl << std::endl;

    do {
        do {
            print(layout);
            updateLayout(layout, takeInput(turn, usedSlot, currentPlayer), currentPlayer);
            victoryCheck(layout, turn, victory, winner);
        } while (victory == false && turn != 9);
        
        print(layout);
        message(victory, winner);
        reset(layout, turn, usedSlot, currentPlayer, victory, winner, again);
        
        std::cout << "\nWould you like to play again (y/n): ";
        std::cin >> again;
        std::cout << "\n";
        
        
    } while (again == 'y');
    
    std::cout << "Thank you for playing! Game ended." << std::endl;
    
    return 0;
}
