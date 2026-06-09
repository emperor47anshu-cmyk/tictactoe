# Tic-Tac-Toe

Hi this is my first project,
started learning to code a month ago,am currently learning cs50X course by Havard.
I am here to gain some real life exposure. I made this project with my understanding of gamelogic and algorithms.

## Features

**Player vs PLayer (PvP):** You can play with your most imp asset in life(frnds) locally on the same screen and have FUN.

**Player vs Computer (PvC):** You can sharpen your skills against AI.

**Three Difficulty Levels (PvC):**
 - Easy: The computer makes completely random moves. Great for casual game.
- Medium: The computer mixes random moves with its brain to give you a fair fight.(Highly Recommended)
- Hard(Unbeatable) Powered by **Minimax algorithm** . The Ai explores all possible moves to minimize your WIN.
 
  **THE best you can hope for is DRAW.**
## About The computer/AI(Minimax)

For the "Hard" difficulty in PvC mode i have implemented the minimax algorithm. Everytime it's computer's turn it stimulates all possible futer moves untill the end of the game(win,lose Or draw). It stores those possible outcomes and choose the moves which maximize it's own position while minimizing the player's position.


## how to run

```bash
git clone https://github.com/emperor47anshu-cmyk/TicTacToe

cd tictactoe

clang tictactoe.c -o tictactoe -lncurses

./tictactoe



