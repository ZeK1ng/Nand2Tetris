//translating : 
//translating : push constant 3030
@3030
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop pointer 0
@SP
M=M-1
@SP
A=M
D=M
@3
M=D
//translating : push constant 3040
@3040
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop pointer 1
@SP
M=M-1
@SP
A=M
D=M
@4
M=D
//translating : push constant 32
@32
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop this 2
@2
D=A
@THIS
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : push constant 46
@46
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop that 6
@6
D=A
@THAT
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : push pointer 0
@3
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push pointer 1
@4
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : add
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
AM=M+1
//translating : push this 2
@THIS
D=M
@2
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : sub
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
AM=M+1
//translating : push that 6
@THAT
D=M
@6
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : add
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
AM=M+1
