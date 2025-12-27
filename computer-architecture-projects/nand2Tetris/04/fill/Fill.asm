// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

//VAR FOR KEYBOARD
@KBD
D = A
@addr2
M = D

//VAR FOR SCREEN HEIGHT
@R0
D = M
@n
M = D

(INIT)
//VAR FOR SCREEN
@SCREEN
D = A
@addr1
M = D

@i
M = 0

(LOOP)
@i
D = M
@n
D = D - M
@INIT
D;JGT

(CHECKING)
@addr2
A = M
D = M
@WHITE
D;JEQ

@addr1
A = M
M = -1
@FINAL_LOOP
0;JMP

(WHITE)
@addr1
A = M
M = 0

(FINAL_LOOP)
@i
M = M + 1
@addr1
M = M + 1
@LOOP
0;JMP


























