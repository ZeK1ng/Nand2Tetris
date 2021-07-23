//translating : 
//translating : push constant 0    
@0
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : pop local 0         // initializes sum = 0
@0
D=A
@LCL
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
//translating : label LOOP_START
(LOOP_START)
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
//translating : push local 0
@LCL
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
//translating : add
@SP
AM=M-1
D=M
@SP
AM=M-1
M=D+M
@SP
AM=M+1
//translating : pop local 0	        // sum = sum + counter
@0
D=A
@LCL
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
//translating : pop argument 0      // counter--
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
//translating : if-goto LOOP_START  // If counter > 0, goto LOOP_START
@SP
AM=M-1
D=M
@LOOP_START
D;JGT
//translating : push local 0
@LCL
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
