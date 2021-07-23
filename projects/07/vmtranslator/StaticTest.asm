//translating : 
//translating : push constant 111
@111
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : push constant 333
@333
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : push constant 888
@888
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop static 8
@StaticTest.8
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : pop static 3
@StaticTest.3
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : pop static 1
@StaticTest.1
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : push static 3
@StaticTest.3
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push static 1
@StaticTest.1
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
//translating : push static 8
@StaticTest.8
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
