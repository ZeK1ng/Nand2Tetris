@256
D=A
@SP
M=D
@RETURN_ADDRES0
D=A
@SP
A=M
M=D
@SP
AM=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
AM=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
AM=M+1
@0
D=A
@SP
D=M-D
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.init
0;JMP
(RETURN_ADDRES0)
//translating : 
//translating : function Class2.set 0
(Class2.set)
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
//translating : pop static 0
@Class2.vm.0
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
//translating : pop static 1
@Class2.vm.1
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
//translating : push constant 0
@0
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : return
@LCL
D=M
@endFrame
M=D
@5
D=A
@endFrame
A=M-D
D=M
@RET_VAl
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@endFrame
A=M-1
D=M
@THAT
M=D
@2
D=A
@endFrame
A=M-D
D=M
@THIS
M=D
@3
D=A
@endFrame
A=M-D
D=M
@ARG
M=D
@4
D=A
@endFrame
A=M-D
D=M
@LCL
M=D
@RET_VAl
A=M
0;JMP
//translating : 
//translating : function Class2.get 0
(Class2.get)
//translating : push static 0
@Class2.vm.0
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push static 1
@Class2.vm.1
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
//translating : return
@LCL
D=M
@endFrame
M=D
@5
D=A
@endFrame
A=M-D
D=M
@RET_VAl
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@endFrame
A=M-1
D=M
@THAT
M=D
@2
D=A
@endFrame
A=M-D
D=M
@THIS
M=D
@3
D=A
@endFrame
A=M-D
D=M
@ARG
M=D
@4
D=A
@endFrame
A=M-D
D=M
@LCL
M=D
@RET_VAl
A=M
0;JMP
//translating : 
//translating : function Sys.init 0
(Sys.init)
//translating : push constant 6
@6
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
//translating : call Class1.set 2
@RETURN_ADDRES1
D=A
@SP
A=M
M=D
@SP
AM=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
AM=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
AM=M+1
@2
D=A
@SP
D=M-D
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class1.set
0;JMP
(RETURN_ADDRES1)
//translating : pop temp 0 // Dumps the return value
@5
D=A
@0
D=D+A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : push constant 23
@23
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : push constant 15
@15
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : call Class2.set 2
@RETURN_ADDRES2
D=A
@SP
A=M
M=D
@SP
AM=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
AM=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
AM=M+1
@2
D=A
@SP
D=M-D
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class2.set
0;JMP
(RETURN_ADDRES2)
//translating : pop temp 0 // Dumps the return value
@5
D=A
@0
D=D+A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
//translating : call Class1.get 0
@RETURN_ADDRES3
D=A
@SP
A=M
M=D
@SP
AM=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
AM=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
AM=M+1
@0
D=A
@SP
D=M-D
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class1.get
0;JMP
(RETURN_ADDRES3)
//translating : call Class2.get 0
@RETURN_ADDRES4
D=A
@SP
A=M
M=D
@SP
AM=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
AM=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
AM=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
AM=M+1
@0
D=A
@SP
D=M-D
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class2.get
0;JMP
(RETURN_ADDRES4)
//translating : label WHILE
(WHILE)
//translating : goto WHILE
@WHILE
0;JMP
//translating : 
//translating : function Class1.set 0
(Class1.set)
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
//translating : pop static 0
@Class1.vm.0
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
//translating : pop static 1
@Class1.vm.1
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
//translating : push constant 0
@0
D=A
@SP
A=M
M=D
@SP
AM=M+1
//translating : return
@LCL
D=M
@endFrame
M=D
@5
D=A
@endFrame
A=M-D
D=M
@RET_VAl
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@endFrame
A=M-1
D=M
@THAT
M=D
@2
D=A
@endFrame
A=M-D
D=M
@THIS
M=D
@3
D=A
@endFrame
A=M-D
D=M
@ARG
M=D
@4
D=A
@endFrame
A=M-D
D=M
@LCL
M=D
@RET_VAl
A=M
0;JMP
//translating : 
//translating : function Class1.get 0
(Class1.get)
//translating : push static 0
@Class1.vm.0
D=M
@SP
A=M
M=D
@SP
M=M+1
//translating : push static 1
@Class1.vm.1
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
//translating : return
@LCL
D=M
@endFrame
M=D
@5
D=A
@endFrame
A=M-D
D=M
@RET_VAl
M=D
@SP
AM=M-1
D=M
@ARG
A=M
M=D
@ARG
D=M+1
@SP
M=D
@endFrame
A=M-1
D=M
@THAT
M=D
@2
D=A
@endFrame
A=M-D
D=M
@THIS
M=D
@3
D=A
@endFrame
A=M-D
D=M
@ARG
M=D
@4
D=A
@endFrame
A=M-D
D=M
@LCL
M=D
@RET_VAl
A=M
0;JMP
