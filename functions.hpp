//
//  functions.hpp
//  TicTacToe
//
//  Created by Abdulrahman Hanifa on 29/07/2024.
//

#ifndef functions_hpp
#define functions_hpp

void print(const std::string* layout);
int takeInput(int& turn, int * usedSlot, char currentPlayer);
void updateLayout(std::string* layout, int newSlot, char& currentPlayer);
void victoryCheck(std::string* layout, int turn, bool& victory, int& winner); // checks for the 8 conditions of victory in TicTacToe if the minimum rounds required for a victory are played
void victoryUpdate(bool& victory, int& winner, std::string slot);
void message(bool victory, int winner); // assings a player as 'winner'
void reset(std::string layout[], int& turn, int* usedSlot, char& currentPlayer, bool& victory, int& winner, char& again); // resets the game after it ends

#endif /* functions_hpp */
