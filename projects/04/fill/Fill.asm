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

(INFLOOP)
    @SCREEN
    D = A 
    @scrAddr
    M=D
    @KBD  
    D= M

    @BLACK  
    D;JGT
    @WHITE
    D;JEQ

(BLACK)
    @R0
    M=-1
    @Fill
    0;JMP



(WHITE)
    @R0
    M=0
    @Fill
    0;JMP
(Fill)
    @R0
    D=M 
    @scrAddr
    A=M 
    M=D

    @scrAddr
    D=M+1
    @KBD
    D=A-D

    @scrAddr
    M=M+1
    A=M

    @Fill
    D;JGT

@INFLOOP    
0;JMP