//translating : push constant 7
@7
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : push constant 8
@8
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : add
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
AM=M+1
//translating : gt
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D-M
@ISTRUE
D;JGT
@0
D=A
@SP
A=M
M=D
@SP
AM=M+1
@DONECHECK
0;JMP
(ISTRUE)
@SP
A=M
M=-1
@SP
AM=M+1
(DONECHECK)
