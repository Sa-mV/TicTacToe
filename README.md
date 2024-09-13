# TicTacToe

This is a text-based TicTacToe built using c++. The program uses a string to print, store, and update the game layout. The game is ran by 8 helper functions to take input from the user, validate it, update the game status, and then declare the result of each match. Two do-while loops are utilized to allow for repetition.

##### Functions descriptions:

- `print`: Displays the current layout of the game by looping through an array of strings, containing both the 9 slots and the borders (visuals).
- `takeInput`: Takes input from the current player (X or O) while validating the following:
	- The new slot exits (1-9).
	- The new slot is not already occupied.
	- The input is a number.
- `updateLayout`: Changes a slot to X or O based on user input and player's turn.
- `victoryCheck`: Checks for the 8 conditions of victory. The minimum number of turns must have been played before execution. If one of the conditions are valid it calls `victoryUpdate`.
- `victoryUpdate`: Changes the current status of the game (ends it) and assigns a winner.
- `message`: displays the results of the game
- `reset`: resets the layout of the game and other variables to their initial state.

### Learning Outcomes:

This project helped me enforce the following concepts:
- Organize the code by using separate compilation and a function for each task.
- Passing different data types to functions (arrays, pointers, pass by reference vs value).

### Program in Action:

![Image of a game state](./images/image-of-a-game-state)

### How to Install and Run:
##### For  Mac Users:

- Download and run the executable file "TicTacToe-download". Alternatively, clone the entire repository by following these steps:

- **Open the terminal**
- **Clone the Repository:**
	Using SSH:
	`git clone git@github.com:Sa-mV/TicTacToe.git`
	or using the web URL:
	`git clone https://github.com/Sa-mV/TicTacToe.git`
- **Navigate to the Project Directory:**
	`cd TicTacToe`
- **Navigate to the directory with `main.cpp`:**
	`cd ./TicTacToe`
- **Compile the Program:**
	`clang++ -o TicTacToe -I../ main.cpp ../functions.cpp
	Equivalent to 
	`<compiler> -o <nameOfFile> -I../ main.cpp ../functions.cpp`
- **Run the program:**
	`./TicTacToe`

##### For Windows Users:

- **Open Command Prompt or PowerShell**
- **Clone the Repository:**
	`git clone git@github.com:Sa-mV/TicTacToe.git`
- **Navigate to the Project Directory:**
	`cd TicTacToe`
- **Navigate to the directory with `main.cpp`:**
	`cd ./TicTacToe`
- **Compile the Program:**
	- Using Visual Studio (`cl`):
	    - Open the "Developer Command Prompt for Visual Studio" (found in the Start menu with your Visual Studio installation).
	    - Compile using:
		    `cl /EHsc -I.. main.cpp ..\functions.cpp /Fe:TicTacToe.exe`
	- You can use any other compiler of your choice
- **Run the Program:**
    - In Command Prompt, execute the program by typing:
        `TicTacToe.exe`
