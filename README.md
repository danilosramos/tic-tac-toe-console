# ❌⭕ Tic-Tac-Toe Console Game

> A classic implementation of the Tic-Tac-Toe game built with **C++**, featuring a Human vs. Computer mode and robust input validation.

![C++](https://img.shields.io/badge/Language-C++11-00599C?style=for-the-badge&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Windows%20|%20Linux-lightgrey?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

## 📖 About the Project

This project is a console-based adaptation of the popular **Tic-Tac-Toe** game. It was developed to practice game logic implementation, array manipulation, and random number generation in C++.

The game allows a user to play against the computer (AI). Unlike basic implementations, this project focuses on **User Experience (UX)** by preventing crashes through input validation (e.g., handling non-numeric inputs) and ensuring fair play logic.

## 🚀 Key Features

* **🤖 Human vs. Computer:** Play against an AI opponent that makes moves automatically.
* **🛡️ Robust Input Validation:** Uses `std::cin.fail()` and `std::numeric_limits` to handle invalid inputs (like letters or symbols) without crashing the game loop.
* **🎲 Random AI Logic:** The computer utilizes `srand(time(0))` to generate unpredictable moves, ensuring each game is different.
* **📊 Win/Tie Detection:** Accurately checks all 8 winning conditions (rows, columns, diagonals) and detects tie games when the board is full.

## 🛠️ Technologies Used

* **Language:** C++ (Standard C++11 or higher)
* **Libraries:**
    * `<iostream>`: Standard Input/Output.
    * `<ctime>` & `<cstdlib>`: For random number generation (`rand`, `srand`).
    * `<limits>`: For clearing input buffers during validation.

## ⚙️ How to Run

### Prerequisites
You need a C++ compiler installed (like **g++** or **clang**).

### Compilation
Open your terminal in the project folder and run:

```bash
g++ tic-tac-toe-console.cpp -o tictactoe
```

Execution

On Linux/macOS:
```bash
./tictactoe
```

On Linux/macOS:
```bash
tictactoe.exe
```

## 🧩 Code Structure
### The game logic is divided into clear, modular functions:

* drawBoard(): Renders the 3x3 grid layout to the console.

* playerMove(): Handles user input and verifies if the chosen spot is valid/empty.

* computerMove(): Generates a random valid move for the AI.

* checkWinner(): Iterates through winning patterns to determine the result.

* checkTie(): Checks if the board is full with no winner.
