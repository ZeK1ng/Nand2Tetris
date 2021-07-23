// The game of life world consists of 2D grid 16x32, the grid is mapped in memory:
// RAM[100] == grid(0, 0)
// RAM[132] == grid(1, 0)
// RAM[611] == grid(16, 31)
//
// RAM[99] contains number of generations to iterate over the Game of life world (aka grid)
//
// Iteration rules:
// For a space that is 'populated':
// * Each cell with one or no neighbors dies, as if by solitude.
// * Each cell with four or more neighbors dies, as if by overpopulation.
// * Each cell with two or three neighbors survives.
//
// For a space that is 'empty' or 'unpopulated'
// * Each cell with three neighbors becomes populated.
//
// initial values are set by test. The are only two values allowed:
// 1 -- the cell is populated
// 0 -- the cell is empty

// your code here

//MaxGenerations
@99
D=M
@generations
M=D


// Get the world
@100
D=A
@world
M=D
//get the size;
@512
D=A
@worldSize
M=D


@640
D=A
@copy_world
M=D

@generations
M=M+1
@DISPLAY
0;JMP

(MAIN)
    @generations
    D=M
    @ENDMAIN
    D;JEQ
    @COPYWORLD
    0;JMP
    (COPYING_OVER)
        @640
        D=A
        @copy_world
        M=D
        @COMPUTE_NEXT_GEN
        0;JMP
    (NEXT_GEN_DONE)
    
    @DISPLAY
    0;JMP
    (DISPLAY_DONE)
    @generations
    M=M-1
    @MAIN
    0;JMP
(COMPUTE_NEXT_GEN)
    @copy_world
    D=M
    @currInd
    M=D
    
    @512// worldSizd
    D=A
    @worldSizeHolder
    M=D
    (LOOP)
    
        @worldSizeHolder
        D=M
        @NEXT_GEN_DONE
        D;JEQ
      
        @mezoblebi
        M=0
         
    (CHECKLEFT)
      
        @currInd
        D=M
        @31
        D=D&A
        @CHECKRIGHT
        D;JEQ

        @currInd
        D=M
        @mezobelisIndexi
        M=D-1
       

        @640
        D=A
        @mezobelisIndexi
        D=D-M
        @CHECKRIGHT
        D;JGT

        @mezobelisIndexi
        A=M
        D=M
        @CHECKRIGHT
        D;JEQ

        @mezoblebi
        M=M+1
 
    (CHECKRIGHT)
        
        @currInd
        D=M
        @31
        D=D&A
        @31
        D=D-A
        @CHECKDOWN
        D;JEQ
       

      
        @currInd
        D=M
        @mezobelisIndexi
        M=D+1
       



        @mezobelisIndexi
        A=M
        D=M
        @CHECKDOWN
        D;JEQ   
       
        @mezoblebi
        M=M+1
       

    (CHECKDOWN)
        @currInd
        D=M
        @mezobelisIndexi
        M=D
        @32
        D=A
        @mezobelisIndexi
        M=M+D
        
        D=M
        @1120
        D=D-A
        @CHECKDOWNLEFT
        D;JGT

        
    
        @mezobelisIndexi
        A=M
        D=M
        @CHECKDOWNLEFT
        D;JEQ

        @mezoblebi
        M=M+1
       
    
    (CHECKDOWNLEFT)
       
        @currInd
        D=M
        @31
        D=D&A
        @CHECKDOWNRIGHT
        D;JEQ

        @currInd
        D=M
        @mezobelisIndexi
        M=D
        @31
        D=A
        @mezobelisIndexi
        M=M+D
        D=M
        @1120
        D=D-A
        @CHECKDOWNRIGHT
        D;JGT

       

        @mezobelisIndexi
        A=M
        D=M
        @CHECKDOWNRIGHT
        D;JEQ
       

        @mezoblebi
        M=M+1
       

(CHECKDOWNRIGHT)

    @currInd
    D=M
    @31
    D=D&A
    @31
    D=D-A
    @CHECKUP
    D;JEQ

    @currInd
    D=M
    @mezobelisIndexi
    M=D
    @33
    D=A
    @mezobelisIndexi
    M=M+D
    D=M
    @1120
    D=D-A
    @CHECKUP
    D;JGT
    
 

    @mezobelisIndexi
    A=M
    D=M
    @CHECKUP
    D;JEQ
    

    @mezoblebi
    M=M+1
    



(CHECKUP)
    
    @currInd
    D=M
    @mezobelisIndexi
    M=D
    @32
    D=A
    @mezobelisIndexi
    M=M-D

    @640
    D=A
    @mezobelisIndexi
    D=D-M
    @CHECKUPRIGHT
    D;JGT 

   
    @mezobelisIndexi
    A=M
    D=M
    @CHECKUPRIGHT
    D;JEQ

    @mezoblebi
    M=M+1
    

(CHECKUPRIGHT)

    @currInd
    D=M
    @31
    D=D&A
    @31
    D=D-A
    @CHECKUPLEFT
    D;JEQ
    @currInd
    D=M
    @mezobelisIndexi
    M=D
    @31
    D=A
    @mezobelisIndexi
    M=M-D

    @640
    D=A
    @mezobelisIndexi
    D=D-M
    @CHECKUPLEFT
    D;JGT
    @mezobelisIndexi
    A=M
    D=M
    @CHECKUPLEFT
    D;JEQ

 

    @mezoblebi
    M=M+1
  

(CHECKUPLEFT)
    @currInd
    D=M
    @31
    D=D&A
    @CHECKSTATUS
    D;JEQ
    @currInd
    D=M
    @mezobelisIndexi
    M=D
    @33
    D=A
    @mezobelisIndexi
    M=M-D

    @640
    D=A
    @mezobelisIndexi
    D=D-M
    @CHECKSTATUS
    D;JGT
    @mezobelisIndexi
    A=M
    D=M
    @CHECKSTATUS
    D;JEQ

   
    @mezoblebi
    M=M+1
   
(CHECKSTATUS)
    @mezoblebi
    D=M
    @14
    M=D
    @currInd
    D=M
    @13
    M=D
    //if currInd is dead
    @mezoblebi
    D=M
    @0
    M=D
    @currInd
    A=M
    D=M
    @ISDEAD
    D;JEQ
    //if it is alive and it has >=4 mezobeli , than kill
    @mezoblebi
    D=M
    @4
    D=D-A
    @KILL
    D;JGE
    //if it is alive and it has 1 or 0 mezobeli , than kill
    //if mezoblebi <4 and mezoblebs-1 <= 0 than kill
    @mezoblebi
    D=M
    @1
    D=D-A
    @KILL
    D;JLE
    // if it has 2 or 3 mezobeli than start next loop
    @START_NEXT_LOOP
    0;JMP
(ISDEAD)
    //if mezoblebi ==3 then revive
    @mezoblebi
    D=M
    @3
    D=D-A
    @REVIVE
    D;JEQ

    @START_NEXT_LOOP
    0;JMP

(START_NEXT_LOOP)
    @currInd
    M=M+1
    @worldSizeHolder
    M=M-1
    @LOOP
    0;JMP

(KILL)
    @currInd
    D=M
    @640
    D=D-A
    @100
    D=D+A
    A=D
    M=0
   
    @START_NEXT_LOOP
    0;JMP
(REVIVE)
  
    @currInd
    D=M
    @640
    D=D-A
    @100
    D=D+A
    A=D
    M=1
   
    @START_NEXT_LOOP
    0;JMP




(COPYWORLD)
    @world
    D=M
    @currInd // world address holder
    M=D 
    @worldSize
    D=M
    @worldSizeHolder
    M=D

    (LOOP_WORLD)
//if went through all 512points, break
    @worldSizeHolder
    D=M
    @COPYING_OVER
    D;JEQ
    // VALUE = WOLRD[currInd]
    @currInd 
    A=M
    D=M
    @value 
    M=D     
    // copy World index = value
    
    D=M
    @copy_world
    A=M
    M=D

    @copy_world
    M=M+1
    @currInd 
    M = M+1 
    @worldSizeHolder
    M=M-1

    @LOOP_WORLD
    0;JMP
(END_LOOP_WORLD)
    @COPYING_OVER
    0;JMP
(DISPLAY)

    @SCREEN
    D=A
    @screenHolder
    M=D

    @world
    D=M
    @tipi
    M=D
    
    @512
    D=A
    @size
    M=D

    (CIKLI)
        @size
        D=M
        @DISPLAY_DONE
        D;JEQ

        @tipi
        A=M
        D=M
        @tipisState
        M=D
        @0
        D=A
        @tipisState
        D=D-M
        @flag
        M=D

        @16
        D=A
        @ciklera
        M=D
        @screenHolder
        D=M
        @tempScreenInd
        M=D
        (KUBIKIS_LOOP)
            @ciklera
            D=M
            @KAPUT_KUBIKI
            D;JEQ
            @flag
            D=M
            @tempScreenInd
            A=M
            M=D
            @32
            D=A
            @tempScreenInd
            M=M+D
            @ciklera
            M=M-1
            @KUBIKIS_LOOP
            0;JMP

        (KAPUT_KUBIKI)
        @screenHolder
        M=M+1
        D=M
        @SCREEN
        D=D-A
        @31
        D=D&A
        @NEXTROW
        D;JEQ

        @next_cikl
        0;JMP

        (NEXTROW)
        @480
        D=A
        @screenHolder
        M=M+D

        (next_cikl)
        @tipi
        M=M+1
        @size
        M=M-1
        @CIKLI
        0;JMP


(ENDMAIN)
    @ENDMAIN
    0;JMP