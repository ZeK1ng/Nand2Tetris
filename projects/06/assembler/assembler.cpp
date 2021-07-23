/*
	!!!TOKENIZER class is not written by me and I am just using it!!!
*/
#include <bits/stdc++.h>
#include "Tokenizer.h"
using namespace std;
#define pb push_back
#define ll long long

map<string,pair<char,bitset<6> > > c_instructMap;
map<string, bitset<3> > dest_map;
map<string, bitset<3> > jump_map;
map<string,int> symbol_map;

void constructCMap(){
	c_instructMap["0"]= make_pair('0',bitset<6> (string("101010")) );
	c_instructMap["1"]= make_pair('0',bitset<6> (string("111111")) );
	c_instructMap["-1"]= make_pair('0',bitset<6> (string("111010")) );
	c_instructMap["D"]= make_pair('0',bitset<6> (string("001100")) );
	c_instructMap["A"]= make_pair('0',bitset<6> (string("110000")) );
	c_instructMap["!D"]= make_pair('0',bitset<6> (string("001101")) );
	c_instructMap["!A"]= make_pair('0',bitset<6> (string("110001")) );
	c_instructMap["-D"]= make_pair('0',bitset<6> (string("001111")) );
	c_instructMap["-A"]= make_pair('0',bitset<6> (string("110011")) );
	c_instructMap["D+1"]= make_pair('0',bitset<6> (string("011111")) );
	c_instructMap["A+1"]= make_pair('0',bitset<6> (string("110111")) );
	c_instructMap["D-1"]= make_pair('0',bitset<6> (string("001110")) );
	c_instructMap["A-1"]= make_pair('0',bitset<6> (string("110010")) );
	c_instructMap["D+A"]= make_pair('0',bitset<6> (string("000010")) );
	c_instructMap["D-A"]= make_pair('0',bitset<6> (string("010011")) );
	c_instructMap["A-D"]= make_pair('0',bitset<6> (string("000111")) );
	c_instructMap["D&A"]= make_pair('0',bitset<6> (string("000000")) );
	c_instructMap["D|A"]= make_pair('0',bitset<6> (string("010101")) );
	c_instructMap["M"]= make_pair('1',bitset<6> (string("110000")) );
	c_instructMap["!M"]= make_pair('1',bitset<6> (string("110001")) );
	c_instructMap["-M"]= make_pair('1',bitset<6> (string("110011")) );
	c_instructMap["M+1"]= make_pair('1',bitset<6> (string("110111")) );
	c_instructMap["M-1"]= make_pair('1',bitset<6> (string("110010")) );
	c_instructMap["D+M"]= make_pair('1',bitset<6> (string("000010")) );
	c_instructMap["D-M"]= make_pair('1',bitset<6> (string("010011")) );
	c_instructMap["M-D"]= make_pair('1',bitset<6> (string("000111")) );
	c_instructMap["D|M"]= make_pair('1',bitset<6> (string("010101")) );
	c_instructMap["D&M"]= make_pair('1',bitset<6> (string("000000")) );

}

void constructDestMap(){
	dest_map["null"]=bitset<3> (string("000"));
	dest_map["M"]=bitset<3>(string("001"));
	dest_map["D"]=bitset<3>(string("010"));
	dest_map["MD"]=bitset<3>(string("011"));
	dest_map["A"]=bitset<3>(string("100"));
	dest_map["AM"]=bitset<3>(string("101"));
	dest_map["AD"]=bitset<3>(string("110"));
	dest_map["AMD"]=bitset<3>(string("111"));
}
void constructJumpMap(){
	jump_map["null"]=bitset<3> (string("000"));
	jump_map["JGT"]=bitset<3> (string("001"));
	jump_map["JEQ"]=bitset<3> (string("010"));
	jump_map["JGE"]=bitset<3> (string("011"));
	jump_map["JLT"]=bitset<3> (string("100"));
	jump_map["JNE"]=bitset<3> (string("101"));
	jump_map["JLE"]=bitset<3> (string("110"));
	jump_map["JMP"]=bitset<3> (string("111"));
}
void constructSymbolMap(){
	symbol_map["R0"]=0;
	symbol_map["R1"]=1;
	symbol_map["R2"]=2;
	symbol_map["R3"]=3;
	symbol_map["R4"]=4;
	symbol_map["R5"]=5;
	symbol_map["R6"]=6;
	symbol_map["R7"]=7;
	symbol_map["R8"]=8;
	symbol_map["R9"]=9;
	symbol_map["R10"]=10;
	symbol_map["R11"]=11;
	symbol_map["R12"]=12;
	symbol_map["R13"]=13;
	symbol_map["R14"]=14;
	symbol_map["R15"]=15;
	symbol_map["SCREEN"]=16384;
	symbol_map["KBD"]=24576;
	symbol_map["SP"]=0;
	symbol_map["LCL"]=1;
	symbol_map["ARG"]=2;
	symbol_map["THIS"]=3;
	symbol_map["THAT"]=4;

	
}

void testDestMap(){
 	map<string,bitset<3> > ::iterator it=dest_map.begin();
	 while(it!=dest_map.end()){
		cout<<"inst: "<<it->first<<" bits: "<<it->second<<endl;
		it++;
	}
}
void testSymbolMap(){
	map<string,int> ::iterator it = symbol_map.begin();
	while(it!=symbol_map.end()){
		cout<<"symb: "<<it->first<<" val: "<<it->second<<endl;
		it++;
	}
}

 bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
void cleanUp(string & str){
	while(str.find(" ")!=string::npos){
		str.erase(str.find(" "),1);
	}
	int index = str.find("/");
	if(index==string::npos)return;
	str.erase(str.begin()+index,str.end());
	
}	
void scanCodeLabel(char * argv[]){
	ifstream inp_file (argv[1]);
	if(!inp_file.is_open())cout<<"Can`t open file"<<endl;
	int pc =0;
	int counter =16;
	string line;
	while(getline(inp_file,line)){
		cleanUp(line);
		if(line.length()==0)continue;
		if(line[0]=='('){
			Tokenizer tok;
			tok.set(line," ()");
			string token;
			while((token=tok.next())!= ""){
				symbol_map[token]=pc;
			}
		}else{
			pc++;
		}
	}
	inp_file.close();
}
void scanCodeVariable(char * argv[]){
	ifstream inp_file (argv[1]);
	if(!inp_file.is_open())cout<<"Can`t open file"<<endl;
	int counter =16;
	string line;
	while(getline(inp_file,line)){
		cleanUp(line);
		if(line.length()==0)continue;
		if (line[0]=='@'){
			string s = line.substr(1,line.size()-1);
			if(!is_number(s) && symbol_map.count(s)==0){
				symbol_map[s]=counter++;
			}	
		}
	}
	inp_file.close();
}

int main(int argc,char* argv[]){
	constructCMap();
	constructDestMap();
	constructJumpMap();
	constructSymbolMap();
	scanCodeLabel(argv);
	scanCodeVariable(argv);
//	testSymbolMap();
	//test();
	
	ifstream inp_file (argv[1]);
	if(!inp_file.is_open()) cout<<"Can`t open file"<<endl;
	string infile = argv[1];
	string out_file = infile.substr(0,infile.size()-3)+"hack";
	freopen(out_file.c_str(),"w+",stdout);
	string inp;
	while(getline(inp_file,inp)){
		cleanUp(inp);
		if(inp.length()==0)continue;
		if(inp[0]=='(')continue;
		if(inp[0]=='@'){
			//cout<<inp<<endl;
			string val = inp.substr(1,inp.size()-1);
			if(symbol_map.count(val)>0){
				bitset<16>valbit (symbol_map[val]);
				cout<<valbit<<endl;
				continue;
			}
			bitset<16> valbit (stoi(val));
			cout<<valbit<<endl;
		}else{
   			std::vector<string> vec(3,"empty");

   			bool isDest=true;
   			bool isJump=true;
   			if(inp.find("=") == string::npos){
   				vec[0]="null";
   				isDest=false;
   			}
   			if(inp.find(";")==string::npos){
   				vec[2]="null";
   				isJump=false;
   			}
   			vector<string> tokens;
   			//cout<<vec[0]<<vec[1]<<vec[2]<<endl;
   			Tokenizer tok;
    		tok.set(inp," =;");
   			string token;
   			while((token = tok.next()) != ""){
   				tokens.pb(token);
   			}
   			if(tokens.size()==3){
   				for(int i=0; i<tokens.size();i++){
   					vec[i]=tokens[i];
   				}
   			}else if(!isDest){
   				for(int i =0; i<tokens.size(); i++){
   					vec[i+1]=tokens[i];
   				}
   			}else if(!isJump){
   				for(int i =0; i<tokens.size(); i++){
   					vec[i]=tokens[i];
   				}
   			}
   			// for(int i=0; i< vec.size(); i++){
   			// 	cout<<vec[i]<<endl;
   			// }
   			string res = "";
   			res+="111";
  			string dest = vec[0];
  			string comp = vec[1];
  			string jump = vec[2];
  			res+=c_instructMap[comp].first;
  			res+=c_instructMap[comp].second.to_string();
  			res+=dest_map[dest].to_string();
  			res+= jump_map[jump].to_string();
  		//	cout<<"c_instructMap[comp].first-"<<c_instructMap[comp].first<<"  c_instructMap[comp].second.to_string()"<<c_instructMap[comp].second.to_string()<<"  dest_map[dest].to_string()"<<dest_map[dest].to_string()<<"  jump_map[jump].to_string()"<<jump_map[jump].to_string()<<endl;
  			// if(res.size()>16){
  			// 	cout<<"COMMAND: "<<inp<<"   RESULT  "<<res<<endl;
  			// }
  			//cout<<"COMMAND"<<inp<<" ---"<<res<<endl;
  			cout<<res<<endl;
		}
	 }
	fclose(stdout);
	inp_file.close();
	return 0;
}