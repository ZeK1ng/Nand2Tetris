//translating : 
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
