// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

// for i=0; i<R1;i++
//     R0+=R0

@R2
M=0

@R1
D=M

@END
D;JEQ

@R0
D=M

@END
D;JEQ
//n = r1
@R1
D=M
@n
M=D
//i = 1
@i
M=1
// result = R0
@R0
D=M
@result
M=D

(COMPUTE)
    @i
    D=M
    @n
    D=D-M
    @STOP
    D;JGE
    @R0
    D=M
    @result
    M=M+D
    @i
    M=M+1
    @COMPUTE
    0;JMP
(STOP)
    @result
    D=M
    @R2
    M=D

    
(END)
    @END
    0;JMP

