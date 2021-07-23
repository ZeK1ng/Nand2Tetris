//translating : 
//translating : 
//translating : push argument 1
@ARG
D=M
@1
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : pop pointer 1           // that = argument[1]
@SP
M=M-1
@SP
A=M
D=M
@4
M=D
//translating : 
//translating : push constant 0
@0
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop that 0              // first element in the series = 0
@0
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
//translating : push constant 1
@1
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop that 1              // second element in the series = 1
@1
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
//translating : 
//translating : push argument 0
@ARG
D=M
@0
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push constant 2
@2
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : sub
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
AM=M+1
//translating : pop argument 0          // num_of_elements -= 2 (first 2 elements are set)
@0
D=A
@ARG
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
//translating : 
//translating : label MAIN_LOOP_START
(MAIN_LOOP_START)
//translating : 
//translating : push argument 0
@ARG
D=M
@0
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : if-goto COMPUTE_ELEMENT // if num_of_elements > 0, goto COMPUTE_ELEMENT
@SP
AM=M-1
D=M
@COMPUTE_ELEMENT
D;JGT
//translating : goto END_PROGRAM        // otherwise, goto END_PROGRAM
@END_PROGRAM
0;JMP
//translating : 
//translating : label COMPUTE_ELEMENT
(COMPUTE_ELEMENT)
//translating : 
//translating : push that 0
@THAT
D=M
@0
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push that 1
@THAT
D=M
@1
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
//translating : pop that 2              // that[2] = that[0] + that[1]
@2
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
//translating : 
//translating : push pointer 1
@4
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push constant 1
@1
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
//translating : pop pointer 1           // that += 1
@SP
M=M-1
@SP
A=M
D=M
@4
M=D
//translating : 
//translating : push argument 0
@ARG
D=M
@0
D=D+A
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push constant 1
@1
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : sub
@SP
AM=M-1
D=M
@SP
AM=M-1
M=M-D
@SP
AM=M+1
//translating : pop argument 0          // num_of_elements--
@0
D=A
@ARG
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
//translating : 
//translating : goto MAIN_LOOP_START
@MAIN_LOOP_START
0;JMP
//translating : 
//translating : label END_PROGRAM
(END_PROGRAM)
