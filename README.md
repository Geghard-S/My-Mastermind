Welcome to My Mastermind
Task
Write a program called mastermind; it will be an implementation of the famous game.

Description
Mastermind is a game composed of 8 pieces of different colors. A secret code is then composed of 4 distinct pieces.

Installation
you must create a Makefile, and the ouput is the command itself It will contain rule all/clean/fclean (re => fclean + all)

You can use:

printf(3) write(2) read(2) rand() (/ srand()) time() atoi() You can NOT use: Any functions/syscalls which does not appear in the previous list Yes, it includes exit Consider writing a README.md to describe your project and how it works.

Your mastermind needs to handle the sequence Ctrl + d. It's End Of File. It's consider as a normal execution.

read() is a syscall difficult to apprehend, you will have time to deal more with it in a later project. In this project, you should read 1 character by 1 (use read(0, &c, 1)) and add them one by one to a buffer until you encounter a newline.

Usage
The player has 10 attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7' '8'.

If the player finds the code, he wins, and the game stops. A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

The Core Team
Made at Qwasar Silicon Valley Qwasar Silicon Valley Logo