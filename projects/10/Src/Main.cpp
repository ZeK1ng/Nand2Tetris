#include "JackTokenizer.h"
#include "CompilationEngine.h"
#include <unistd.h>
#include <dirent.h>

void tokenizeTester(string input_file_name){
    JackTokenizer jt(input_file_name);
    vector<string> tokens = jt.getTokens();
    size_t found = input_file_name.find_last_of("/\\");
    string output_file_directory_path= input_file_name.substr(0,found);
    string output_file_name =input_file_name.substr(found+1);
    output_file_name = output_file_name.substr(0,output_file_name.length()-5);
    output_file_name+="JT.xml";
    string output_file_full_path = output_file_directory_path+"/"+output_file_name;
    freopen(output_file_full_path.c_str(),"w+",stdout);
    cout<<"<tokens>\n";
    for(auto tok : tokens){
        if(tok =="")continue;
        string type = jt.getTokenType(tok);
        if(type == "stringConstant"){
            tok = jt.getStringVal(tok);
        }
        if(tok == ">"){
            tok = "&gt;";
        }else if (tok == "<"){
            tok = "&lt;";
        }else if (tok == "\""){
            tok = "&quot;";
        }else if (tok == "&"){
            tok = "&amp;";
        }
        string output= "";
        output += "<" + type + "> ";
        output +=tok;
        output+=" </"+type +">\n"; 
        cout<<output;
    }
    cout<<"</tokens>\n";

}

void handleFile(string input_file_name){
    JackTokenizer jt(input_file_name);
    vector<string> tokens = jt.getTokens();
    for(int i = 0; i < tokens.size() ;i++){
        string x = tokens[i];
        if(x[0]='\0' || x.size() == 0 || x[0] == NULL || x[0]== ' ' || x == " " || x == "\n" || x == "\t" || x == "\t\t" || x == "" || x[0]==' '){
            tokens.erase(tokens.begin()+i);
              i--;
        }
    }
    size_t found = input_file_name.find_last_of("/\\");
    string output_file_directory_path= input_file_name.substr(0,found);
    string output_file_name =input_file_name.substr(found+1);
    output_file_name = output_file_name.substr(0,output_file_name.length()-5);
    output_file_name+="My.xml";
    string output_file_full_path = output_file_directory_path+"/"+output_file_name;
    CompilationEngine cmpe( &jt,output_file_full_path);  
    cmpe.startCompiling();
} 

void handleDir(string input_path){
    DIR * dir;
    struct dirent * ent;
    string currFile;
    if((dir=opendir(input_path.c_str()))!=NULL){
        while((ent=readdir(dir))!=NULL){
            currFile=ent->d_name;
            if(currFile.length()>2 && currFile.substr(currFile.length()-5) == ".jack"){
                string full_file_path = "";
                if(input_path[input_path.length()-1] == '/'){
                        full_file_path=input_path+currFile;
                }else{
                     full_file_path=input_path+"/"+currFile;
                }
                // tokenizeTester(full_file_path);
                handleFile(full_file_path);
            }
        }
        closedir(dir);
    }
}

int main(int argc , char *argv[]){
    string input_path = argv[1];
    if(input_path.find(".") != string::npos){
        // tokenizeTester(input_path);
        handleFile(input_path);

    }else {
        handleDir(input_path);
    }
    fclose(stdout);
    return 0;
}

