// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

//var1 = R0
@R0
D = M
@var1
M = D

//var2 = R1
@R1
D = M
@var2
M = D

//tmp = 0
@tmp
M = 0

//@i = 1
@i
M = 1

(LOOP)
@i
D = M
@var2
D = D - M
@NEXT
D;JGT

//tmp = tmp + var1
@var1
D = M
@tmp
M = M + D
@i
M = M + 1
@LOOP
0;JMP

//R2 = temp
(NEXT)
@tmp
D = M
@R2
M = D

(END)
@END
0;JMP




























