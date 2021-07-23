#include <bits/stdc++.h>
#include <unistd.h>
#include <dirent.h>
#include "Tokenizer.h"
using namespace std;

#define pb push_back
#define printVec(vec) for(int i=0; i< vec.size(); i++) cout<<vec[i]<<" ";
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
void handleLabel(string label){
    cout<<"("<<label<<")"<<endl;
}
void handleGoTo(string dest){
    cout<<"@"<<dest<<endl;
    cout<<"0;JMP"<<endl;
}
void handleIfGoTo(string dest){
    get_val();
    cout<<"@"<<dest<<endl;
    cout<<"D;JNE"<<endl;
}
void pushSegOfCallingFunc(string seg){
    cout<<"@"<<seg<<endl<<"D=M\n"<<"@SP\n"<<"A=M\n"<<"M=D"<<endl;
    incrSP();
}
void handleCall(string funcName, string nArgs){
    //push return val
    cout<<"@RETURN_ADDRES"<<lblCounter<<endl;
    cout<<"D=A\n";
    cout<<"@SP\n"<<"A=M"<<endl<<"M=D"<<endl;
    incrSP();
    //push LCL
    pushSegOfCallingFunc("LCL");
    //push arg
    pushSegOfCallingFunc("ARG");
    //push this
    pushSegOfCallingFunc("THIS");
    //pushing that
    pushSegOfCallingFunc("THAT");
    //position ARG
    cout<<"@"<<nArgs<<endl;
    cout<<"D=A\n"<<"@SP\n"<<"D=M-D"<<endl;
    cout<<"@5\n"<<"D=D-A\n"<<"@ARG\n"<<"M=D"<<endl;
    //position LCL
    cout << "@SP" << endl << "D=M" << endl << "@LCL" << endl << "M=D" << endl;
    // transfer contorl to called function
    cout<<"@"<<funcName<<endl;
    cout<<"0;JMP"<<endl;
    cout<<"(RETURN_ADDRES"<<lblCounter<<")"<<endl;
    lblCounter++;
}
void handleFunction(string funcName, string nVars){
    int varCount = stoi(nVars);
    cout<<"("<<funcName<<")"<<endl;
    for(int i=0; i< varCount; i++){
        push("0");
    }
}
void handleReturn(){
    //store LCL in endFrame varibale
    cout<<"@LCL"<<endl<<"D=M"<<endl<<"@endFrame\n"<<"M=D"<<endl;
    //retAdrr = *(endFrame - 5
    cout<<"@5"<<endl<<"D=A\n"<<"@endFrame\n"<<"A=M-D\n"<<"D=M\n";
    cout<<"@RET_VAl"<<endl<<"M=D"<<endl;
    //reposition the retval for the caller *arg=pop();
    get_val();
    cout<<"@ARG\n"<<"A=M\n"<<"M=D\n";
    //reposition sp for the caller
    cout<<"@ARG\n"<<"D=M+1\n"<<"@SP\n"<< "M=D" << endl;
    //restorre That of the caller
    cout<<"@endFrame\n"<<"A=M-1\n"<<"D=M\n";
    cout<<"@THAT"<<endl<<"M=D"<< endl;
    //restore THIS of the caller
    cout<<"@2\n"<<"D=A\n"<<"@endFrame\n"<<"A=M-D"<<endl<<"D=M"<<endl;
    cout<<"@THIS\n"<<"M=D"<< endl;
    //restore ARG of the caller
    cout<< "@3" << endl << "D=A" << endl ;
    cout<< "@endFrame\n" << "A=M-D" << endl << "D=M" << endl ;
    cout<< "@ARG" << endl << "M=D" << endl;
    //restore LCL of the caller
    cout<<"@4\n"<<"D=A"<<endl;
    cout<<"@endFrame\n"<< "A=M-D"<<endl<<"D=M"<< endl;
    cout<< "@LCL"<<endl<<"M=D"<<endl;
    //jump tp return-addres
    cout<<"@RET_VAl"<<endl<< "A=M" << endl << "0;JMP" << endl;
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
    if(instr[0] == "label"){
        handleLabel(instr[1]);
    }
    if(instr[0] == "goto"){
        handleGoTo(instr[1]);
    }
    if(instr[0] =="if-goto"){
        handleIfGoTo(instr[1]);
    }
    if(instr[0] == "function"){
        handleFunction(instr[1],instr[2]);
    }
    if(instr[0] == "return"){
        handleReturn();
    }
    if(instr[0] == "call"){
        handleCall(instr[1],instr[2]);
    }

}
void initVm(){
    cout << "@256" << endl;
    cout << "D=A" << endl;
    cout << "@SP" << endl;
    cout << "M=D" << endl;

    handleCall("Sys.init", "0");
}
int handler(string inp_file){
    ifstream inp_stream(inp_file.c_str());
    
    if(!inp_stream.is_open()) {
        cout<<"Can`t open give file"<<endl;
        return EXIT_FAILURE;
    }

    string line;
    while(getline(inp_stream,line)){
        if(line.length()==0)continue;
        if(line[0]==' ') continue;
        if(line[0]=='/')continue;


        string resL = "";
        for(int i= 0 ;i <line.size(); i++){
            if(line[i] != 13 && line[i] != '\n'){
                resL += line[i];
            }
        }
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
    inp_stream.close();
    return 0 ;
}


int main(int argc , char *argv[]){
    setupSet();
    string inp_file;
    string out_file;
    string given_inp = argv[1];
    if(given_inp[0]!='/'){
        string newInp = "/"+given_inp;
        given_inp=newInp;
    }
    
    if(given_inp.find(".vm")!= string::npos){
        inp_file=given_inp;
        out_file = inp_file.substr(0,inp_file.size()-2) + "asm";
        freopen(out_file.c_str(),"w+",stdout);
        handler(inp_file);
    }else{
        char p [PATH_MAX];
        ssize_t rv = readlink( "/proc/self/exe", p, PATH_MAX );
        if(rv == -1 ){
            return EXIT_FAILURE;
        }
        string fullPath = p ;
        size_t lastInd= fullPath.find_last_of("/\\");
        string path_F = fullPath.substr(0,lastInd);
        path_F +=given_inp;
        int numVmFiles = 0;
        Tokenizer tk;
        tk.set(given_inp,"/\\");
        string token;
        vector<string> name_vec;
        while((token = tk.next()) != ""){
            name_vec.pb(token);
        }
        string out_file_name = name_vec[name_vec.size()-1]+".asm";
         if(path_F[path_F.length()-1] =='/'){
               out_file=path_F+out_file_name;
        }else{
            out_file=path_F+"/"+out_file_name;
        }
        cout<<path_F<<endl;
        DIR * dir; 
        struct dirent * ent;
        string currFile;
        if((dir = opendir(path_F.c_str()))!=NULL){
            while((ent = readdir(dir))!=NULL ){
                currFile = ent->d_name;            
                if(currFile.length() >2){
                    if(currFile.substr(currFile.length()-3) ==".vm"){
                        
                        numVmFiles++;
                    }
                }
            }
            closedir(dir);
        }
        freopen(out_file.c_str(),"w+",stdout);

        if(numVmFiles>1){
            initVm();
        }

        DIR * o_dir; 
        struct dirent * o_ent;
        if((o_dir=opendir(path_F.c_str()))!=NULL ){
            while((o_ent=readdir(o_dir)) !=NULL){
                currFile=o_ent->d_name;
                 if(currFile.length() >3){
                    if(currFile.substr(currFile.length()-3) ==".vm"){
                        if(path_F[path_F.length()-1] =='/'){
                            inp_file=path_F+currFile;
                        }else{
                            inp_file=path_F+"/"+currFile;
                        }
                        filename = currFile;
                        handler(inp_file);
                    }
                }
            }
            closedir(o_dir);
        }
    }

    fclose(stdout);
    return 0;
}