#include <bits/stdc++.h>
#include "Tokenizer.h"
using namespace std;

#define pb push_back
#define printVec(vec) for(int i=0; i< vec.size(); i++) cout<<vec[i];
#define is_arith 1
#define is_push 2
#define is_pop 3
set<string> arith_commands;
set<string> primitive_segs;
int lblCounter = 0;
string filename;
void setupSet(){
    arith_commands.insert("add");
    arith_commands.insert("sub");
    arith_commands.insert("neg");
    arith_commands.insert("and");
    arith_commands.insert("not");
    arith_commands.insert("eq");
    arith_commands.insert("gt");
    arith_commands.insert("lt");
    arith_commands.insert("or");
    primitive_segs.insert("that");
    primitive_segs.insert("this");
    primitive_segs.insert("local");
    primitive_segs.insert("argument");
    


}
void incrSP(){
    cout<<"@SP\n"<<"AM=M+1"<<endl;
}
void decrSP(){
    cout<<"@SP\n"<<"AM=M-1"<<endl;
}
void get_val(){
    cout<<"@SP\n"<<"AM=M-1\n"<<"D=M"<<endl;
}
void push(string str){
    cout<<"@"<<str<<endl;
    cout<<"D=A\n"<<"@SP\n"<<"A=M\n"<<"M=D\n"<<"@SP\n"<<"AM=M+1"<<endl;
}


void branch(string cond){
    cout << "@SP\n" << "A=M-1\n" << "D=M\n" << "A=A-1\n";
    cout<<"D=M-D\n";
    if(cond == "eq"){
        //if equals jump tp eqTrue , else right 0
        cout<<"@B_TRUE"<<lblCounter<<endl<<"D;JEQ"<<endl;
    }
    if(cond =="gt"){
        cout<<"@B_TRUE"<<lblCounter<<endl<<"D;JGT"<<endl;
    }
    if(cond == "lt"){
        cout<<"@B_TRUE"<<lblCounter<<endl<<"D;JLT"<<endl;
    }

    cout<<"D=0\n"<<"@B_DONE"<<lblCounter<<endl<<"0;JMP"<<endl;
    cout<<"(B_TRUE"<<lblCounter<<")"<<endl<<"D=-1"<<endl;
    cout<<"(B_DONE"<<lblCounter<<")"<<endl;
    cout<<"@SP\n"<<"A=M-1\n"<<"A=A-1\n"<<"M=D\n";
    cout<<"@SP\n"<<"M=M-1"<<endl;
    lblCounter++;
}
    


void manageArithmetic(string cmd){
    if(cmd == "sub"){
        get_val();
        decrSP();
        cout<<"M=M-D"<<endl;
        incrSP();
    }

    if(cmd=="add"){
        get_val();
        decrSP();
        cout<<"M=D+M"<<endl;
        incrSP();
    }
    if(cmd == "neg"){
        decrSP();
        cout<<"M=-M"<<endl;
        incrSP();
    }
    if(cmd == "and"){
        get_val();
        decrSP();
        cout<<"M=D&M"<<endl;
        incrSP();
    }
    if(cmd == "not"){
        decrSP();
        cout<<"M=!M"<<endl;
        incrSP();
    }
    if(cmd == "or"){
        get_val();
        decrSP();
        cout<<"M=D|M"<<endl;
        incrSP();
    }
    if(cmd == "gt"){
        branch("gt");
    }
    if(cmd == "lt"){
        branch("lt");
    }
    if(cmd == "eq"){
        branch("eq");
    }
}

void pushPrimSeg(string dest,string val){
    if(dest=="local"){
        dest = "LCL";
    }else if(dest == "argument"){
        dest = "ARG";
    }else if(dest =="this"){
        dest = "THIS";
    }else if(dest =="that"){
        dest = "THAT";
    }
    cout<<"@"<<dest<<endl;
    cout<<"D=M\n";
    cout<<"@"<<val<<endl;
    cout<<"D=D+A\n"<<"A=D\n"<<"D=M\n";
    cout<<"@SP\n"<<"A=M\n"<<"M=D\n";
    cout<<"@SP\n"<<"M=M+1\n";
}
void pushTemp(string val){
   
    cout << "@5" <<endl;
    cout << "D=A\n";
    cout<<"@" << val << endl;
    cout << "A=D+A\n" << "D=M\n";
    cout << "@SP\n" << "A=M\n" << "M=D\n";
    incrSP();
}
void popPrim(string dest,string ind){
    if(dest=="local"){
        dest = "LCL";
    }else if(dest == "argument"){
        dest = "ARG";
    }else if(dest =="this"){
        dest = "THIS";
    }else if(dest =="that"){
        dest = "THAT";
    }
    cout<<"@"<<ind<<endl;
    cout<<"D=A"<<endl;
    cout<<"@"<<dest<<endl;
    cout<<"D=D+M"<<endl;
    cout<<"@R13"<<endl;
    cout<<"M=D"<<endl;
    cout<<"@SP\n"<<"M=M-1\n"<<"A=M\n"<<"D=M"<<endl;
    cout<<"@R13\n"<<"A=M\n"<<"M=D"<<endl;
}
void popTemp(string ind){
    cout<<"@5"<<endl;
    cout<<"D=A"<<endl;
    cout<<"@"<<ind<<endl;
    cout<<"D=D+A"<<endl;
    cout<<"@R13"<<endl;
    cout<<"M=D"<<endl;
    cout<<"@SP\n"<<"M=M-1\n"<<"A=M\n"<<"D=M"<<endl;
    cout<<"@R13\n"<<"A=M\n"<<"M=D"<<endl;
}
void pushPointer(string ind){
  if(ind == "0"){
    cout<<"@3"<<endl;
  }else{
    cout<<"@4"<<endl;
  }
  cout<<"D=M\n";
  cout<<"@SP"<<endl;
  cout<<"A=M\n";
  cout<<"M=D"<<endl;
  cout<<"@SP"<<endl;
  cout<<"M=M+1"<<endl;
}
void popPointer(string ind){
    cout<<"@SP"<<endl;
    cout<<"M=M-1"<<endl;
    cout<<"@SP"<<endl;
    cout<<"A=M"<<endl;
    cout<<"D=M"<<endl;
    if(ind == "0"){
        cout<<"@3"<<endl;
    }else{
        cout<<"@4"<<endl;
    }
    cout<<"M=D"<<endl;
}
void pushStatic(string val){
    cout<<"@"<<filename<<"."<<val<<endl;
    cout<<"D=M"<<endl;
    cout<<"@SP"<<endl;
    cout<<"A=M"<<endl;
    cout<<"M=D"<<endl;
    cout<<"@SP"<<endl;
    cout<<"M=M+1"<<endl;
}
void popStatic(string val){
    cout<<"@"<<filename<<"."<<val<<endl;
    cout<<"D=A"<<endl;
    cout<<"@R13"<<endl;
    cout<<"M=D"<<endl;
    cout<<"@SP"<<endl;
    cout<<"M=M-1"<<endl;
    cout<<"A=M"<<endl;
    cout<<"D=M"<<endl;
    cout<<"@R13"<<endl;
    cout<<"A=M"<<endl;
    cout<<"M=D"<<endl;
}
// this that, local , argument, 
void translateToAsm(vector<string> instr){
    if(arith_commands.find(instr[0])!=arith_commands.end()){
        manageArithmetic(instr[0]);
    }
    if(instr[0] == "push"){
        if(instr[1] == "constant") {
            push(instr[2]);
        }else if(primitive_segs.find(instr[1]) != primitive_segs.end()){
            pushPrimSeg(instr[1],instr[2]);
        }else if(instr[1] == "temp"){
            pushTemp(instr[2]);
        }else if(instr[1] == "pointer"){
            pushPointer(instr[2]);
        }else if(instr[1] == "static"){
            pushStatic(instr[2]);
        }
    }
    if(instr[0]=="pop"){
        if(instr[1]!="temp"&&instr[1]!="pointer"&&instr[1]!="static"){
            popPrim(instr[1],instr[2]);
        }else if(instr[1] == "temp"){
            popTemp(instr[2]);
        }else if(instr[1]=="pointer"){
            popPointer(instr[2]);
        }else if(instr[1] == "static"){
            popStatic(instr[2]);
        }
    }
}
int main(int argc , char *argv[]){
    setupSet();
    string inp_file = argv[1];
    ifstream inp_stream(argv[1]);
    if(!inp_stream.is_open()) {
        cout<<"Can`t open give file"<<endl;
        return 0;
    }
    string out_file = inp_file.substr(0,inp_file.size()-2)+"asm";
    filename=out_file.substr(0,out_file.size()-4);
    freopen(out_file.c_str(),"w+",stdout);
    string line;

    while(getline(inp_stream,line)){
        if(line.length()==0)continue;
        if(line[0]==' ') continue;
        if(line[0]=='/')continue;
        cout<<"//translating : "<<line<<endl;
        vector<string> instructions;
        Tokenizer tok; 
        tok.set(line," ");
        string token;
        while((token=tok.next())!=""){
           token.erase(token.find_last_not_of(" \n\r\t")+1);

            instructions.pb(token);
        }
        translateToAsm(instructions);
    }

    fclose(stdout);
    inp_stream.close();
    return 0;

}