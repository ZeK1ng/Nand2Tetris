#include "JackTokenizer.h"

#define pb push_back

/** Opens the input file and gets ready to tokenize it
*/
JackTokenizer::JackTokenizer(string filename){
    inp_stream.open(filename.c_str());
    assert(inp_stream.is_open());
    currTokenIndex = 0;
    string line;
    while(getline(inp_stream,line)){
        line=trim(line);
        if(line.size() == 0 )continue;
        if(line[0]=='/')continue;
        if(line[0]=='*')continue;
        if(line.size()>2){
            if(line[1]=='*')continue;
        }
        int ind = line.find("//");
        if(ind !=std::string::npos){
            line =line.substr(0,ind);
        }
        fileData.push_back(line);
    }
    inp_stream.close();
    for(int i=0;i<fileData.size(); i++){
        if(fileData[i][0]=='/' && fileData[i][1]=='/'){
            fileData.erase(fileData.begin()+i);
        }
    }
    // for(auto st : fileData){
    //     cout<<st<<endl;
    // }
    setupSets();
    tokenize();
    currToken =tokens[0]; 
}
/**
* Destructor 
*/
JackTokenizer::~JackTokenizer(){
}
/**
 * Returns true if there are tokens left
*/
bool JackTokenizer::hasMoreTokens(){
    return currTokenIndex<tokens.size();
}

/**
* sets the current token to the next token if there are any
*/
void JackTokenizer::advance(){
    if( hasMoreTokens()){
        currToken=tokens[++currTokenIndex];
    }
}
/**
 * Gets the next token from the input and makes it the current token.
 * 
*/
string JackTokenizer::getNextToken(){
    if(hasMoreTokens())
    return tokens[currTokenIndex+1];
}
/**
 * return the type of the token
 * [Keyword,Symbol,identifier,int_const,string_const]
*/
string JackTokenizer::tokenType(){
    if(keyword_set.find(currToken) != keyword_set.end()){
        return "keyword";
    }
    if(symbol_set.find(currToken) != symbol_set.end()){
        return "symbol";
    }
    if(isdigit(currToken[0])){
        return "integerConstant";
    }
    if(currToken[0]=='"'){
        return "stringConstant";
    }
    return "identifier";
}
string JackTokenizer:: getTokenType(string tok){
    if(keyword_set.find(tok) != keyword_set.end()){
        return "keyword";
    }
    if(symbol_set.find(tok) != symbol_set.end()){
        return "symbol";
    }
    if(isdigit(tok[0])){
        return "integerConstant";
    }
    if(tok[0]=='"'){
        return "stringConstant";
    }
    return "identifier";
}
/**
 * return the keyWord which is the current token
 * should be called if tokentype is keyword 
*/
string JackTokenizer::keyWord(){
    if(tokenType() == "keyword"){
        return currToken;
    }
    return "";
}
string JackTokenizer::getKeyWord(string tok){
    if(getTokenType(tok) == "keyword"){
        return tok;
    }
    return "";
}
/**
 * Returns the character which is the current token.Should ne called when tokenType is a Symbol
*/
char JackTokenizer::symbol(){
    if(tokenType() == "symbol"){
        return currToken[0];
    }
}
char JackTokenizer::getSymbol(string tok){
      if(getTokenType(tok) == "symbol"){
        return tok[0];
    }
    
}
/**    
 * Identifire = a sequence of letters digits and underscore('_') not starting with a digit 
 * Returns the identifier which is the current Token;
*/
string JackTokenizer::identifier(){
    if(getTokenType(currToken) == "identifier"){
        return currToken;
    }
}

string JackTokenizer::get_identifier(string tok){
    if(getTokenType(tok) == "identifier"){
        return tok;
    }
}

/**
 * Returns the integer Value of the current token.Should be called when tokenType() is INT_CONST
*/
int JackTokenizer::intVal(){
 if(getTokenType(currToken) == "integerConstant"){
        return stoi(currToken);
    }
}

int JackTokenizer::getIntVal(string tok){
    if(getTokenType(tok) == "integerConstant"){
        return stoi(tok);
    }
}
/**
 * Returns the string value of the current Token, without double qotes.
 * Should be called only when TokenyType is STRING_CONST
*/
string JackTokenizer::stringVal(){
  if(getTokenType(currToken) == "stringConstant" ){
        return currToken.substr(1,currToken.length()-2);
    }
}
string JackTokenizer::getStringVal(string tok){
    if(getTokenType(tok) == "stringConstant" ){
        return tok.substr(1,tok.length()-2);
    }
}
/**
 * Returns the current Token
*/
string JackTokenizer::getCurrToken(){
    return currToken;
}
vector<string> JackTokenizer::getTokens(){
    return tokens;
}
/*Private Functions*/
void JackTokenizer::setupSets(){
    keyword_set.insert("class");
    keyword_set.insert("constructor");
    keyword_set.insert("function");
    keyword_set.insert("method");
    keyword_set.insert("field");
    keyword_set.insert("static");
    keyword_set.insert("var");
    keyword_set.insert("int");
    keyword_set.insert("char");
    keyword_set.insert("boolean");
    keyword_set.insert("void");
    keyword_set.insert("true");
    keyword_set.insert("false");
    keyword_set.insert("null");
    keyword_set.insert("this");
    keyword_set.insert("let");
    keyword_set.insert("do");
    keyword_set.insert("if");
    keyword_set.insert("else");
    keyword_set.insert("while");
    keyword_set.insert("return");
    symbol_set.insert("{");
    symbol_set.insert("}");
    symbol_set.insert("(");
    symbol_set.insert(")");
    symbol_set.insert("[");
    symbol_set.insert("]");
    symbol_set.insert(";");
    symbol_set.insert(",");
    symbol_set.insert(".");
    symbol_set.insert("+");
    symbol_set.insert("-");
    symbol_set.insert("*");
    symbol_set.insert("/");
    symbol_set.insert("&");
    symbol_set.insert("|");
    symbol_set.insert("<");
    symbol_set.insert(">");
    symbol_set.insert("=");
    symbol_set.insert("~");
}

string JackTokenizer::trim(string &s){
    auto start = s.begin();
	while (start != s.end() && std::isspace(*start)) {
		start++;
	}

	auto end = s.end();
	do {
		end--;
	} while (std::distance(start, end) > 0 && std::isspace(*end));

	return std::string(start, end + 1);
}
void JackTokenizer::tokenize(){
    for(auto line : fileData){
        if(line.find("\"") ==std::string::npos ){
            istringstream ss(line);
            while(ss){
                string token;
                ss>>token;
                token=trim(token);
                if(token.size()) preTokens.pb(token);
            }
        }else{
            int ind = line.find("\"");
            while(line[ind] != ' ')ind--;
            string word="";
            for(int i =0; i< ind; i++){
                char x=line[i];
                if(x == ' '){
                    preTokens.pb(word);
                    word = "";
                }else{
                    word+= x;
                }
            }
            preTokens.pb(word);
            line=line.substr(ind+1);
            int ind1 = line.find("\"");
            preTokens.pb(line.substr(0,ind1));
            int ind2 = line.find("\"",ind1+1,1);
            preTokens.pb(line.substr(ind1,ind2-ind1+1));
            preTokens.pb(line.substr(ind2+1));

        }
       
    }


    // cout<<"------PRINTING PRE  TOKENS---- "<<endl;
    // for(auto tok : preTokens){
    //     cout<<tok<<endl;
    // }

    for(auto tok : preTokens){
        tok = trim(tok);
        if(keyword_set.count(tok)){
            tokens.pb(tok);
        }else if(symbol_set.count(tok)){
            tokens.pb(tok);
        }else
        if(tok[0]=='"'){
            tokens.pb(tok);
        }else{
            string toPush = "";
            for (auto x : tok){
                if(x == '{' || x == '}' ||  x == '(' || x == ')'|| x == '[' || x == ']'  || x =='.' || x==',' || x == ';'
                || x== '-' || x== '+' || x== '*' || x == '/' || x=='&' || x == '|' || x=='<' || x=='>' || x=='=' || x=='~' ){
                    tokens.pb(toPush);
                    string symb = "";
                    symb+=x;
                    tokens.pb(symb);
                    toPush = "";
                }else{
                    toPush+=x;
                }
            }
            tokens.pb(toPush);
        }

    }
    for(int i =0; i< tokens.size(); i++){
        if(tokens[i][0] == '\040' || tokens[i][0]=='\0'  || tokens[i][0]==' '|| tokens[i].length() == 0 || tokens[i] == " " ||tokens[i] == "" ||tokens[i] == "\n" || tokens[i] == "\t"){
            tokens.erase(tokens.begin()+i);
            i--;
        }
    }
   
    // cout<<"-------Printing FINAL TOKENS------"<<endl;
    // for(auto tok: tokens){
    //     cout<<tok<<endl;
    // }
}
