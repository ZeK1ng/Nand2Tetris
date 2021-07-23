#include "CompilationEngine.h"
/**
 * Constructor
 * Takes the path to the file
*/
CompilationEngine::CompilationEngine(JackTokenizer *jat,string given_file_path){
    jt = jat;
    output_file_path = given_file_path;
    setupSets();
    // while(jt->hasMoreTokens()){
    //     cout<<jt->getCurrToken()<<endl;
    //     advanceTokenizer();
    // }
    freopen(output_file_path.c_str(),"w+",stdout);
    
}   
/**
 * Destructor
*/
CompilationEngine:: ~CompilationEngine(){
}

/**
 * Starts the translation proccess
*/
void CompilationEngine::startCompiling(){
    compileClass();
    // while(jt->hasMoreTokens()){
    //     cout<<jt->getCurrToken()<<endl;
    //     advanceTokenizer();
    // }
}


/**
 * Compiles a complete class
*/
void CompilationEngine::compileClass(){
    cout<<"<class>"<<endl;
    assert(jt->getCurrToken() == "class");
    cout<<buildOutToken(jt->tokenType() , jt->getCurrToken(),1);  
    advanceTokenizer();
    assert(jt->tokenType() == "identifier");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),1);
    advanceTokenizer();
    assert(jt->getCurrToken() == "{");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),1);
    advanceTokenizer();
    while((keywordSet.find(jt->keyWord()) != keywordSet.end())){
        string kw = jt->keyWord();
        if( kw == "constructor" || kw == "method" || kw ==  "void" || kw == "function"){
            compileSubroutine();
        }
        if(kw == "static" || kw == "field"){
            compileClassVarDec();
        }
    }
    assert(jt->getCurrToken() == "}");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),1);
    cout<<"</class>"<<endl;
}
/**
 * Compiles a static or field declaration
*/
void CompilationEngine::compileClassVarDec(){
    cout<<"<classVarDec>\n";
    cout<<buildOutToken("keyword",jt->keyWord(),2);
    advanceTokenizer();

    while(jt->getCurrToken() != ";"){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),2);
        advanceTokenizer();
    }
    cout<<buildOutToken("symbol",jt->getCurrToken(),2);
    advanceTokenizer();
    cout<<"</classVarDec>\n";
}
/**
 * Compiles a complete method, function or constructor
*/
void CompilationEngine::compileSubroutine(){
    cout<<"<subroutineDec>" <<endl;
    while(jt->getCurrToken() != "("){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),2);
        advanceTokenizer();
    }
    printToken(jt->tokenType(),jt->getCurrToken(),2);
    advanceTokenizer();
    compileParameterList();
    assert(jt->getCurrToken()== ")");
    printToken(jt->tokenType(),jt->getCurrToken(), 2);
    advanceTokenizer();
    if(jt->getCurrToken() == "{"){
        cout<<"<subroutineBody>"<<endl;
        printToken(jt->tokenType(),jt->getCurrToken(),3);
        advanceTokenizer();
        while(jt->keyWord() == "var"){
            compileVarDec();
        }
        if(stmSet.find(jt->keyWord())!= stmSet.end()){
            compileStatemenets();
        }
        assert(jt->getCurrToken() == "}");
        printToken(jt->tokenType(),jt->getCurrToken(),3);
        advanceTokenizer();
        cout<<"</subroutineBody>"<<endl;
    }
    cout<<"</subroutineDec>"<<endl;
}
/**
 * Compiles a (possibly empty) parameter list, not including the enclosing "()"
*/
void CompilationEngine::compileParameterList(){
    cout<<"<parameterList>"<<endl;
    while(jt->getCurrToken() != ")"){
        if(jt->tokenType() == "identifier"){
            printToken(jt->tokenType(),jt->getCurrToken(),3);
        }else if(jt->tokenType() == "keyword"){
            printToken(jt->tokenType(),jt->getCurrToken(),3);
        }else if (jt->tokenType() == "symbol"){
            printToken(jt->tokenType(),jt->getCurrToken(),3);
        }
        advanceTokenizer();
    }

    cout<<"</parameterList>"<<endl;
}
/**
 * Compiles a var declaration
*/
void CompilationEngine::compileVarDec(){
    cout<<"<varDec>"<<endl;
    while(jt->getCurrToken() != ";"){
        if(jt->tokenType() == "identifier"){
            printToken(jt->tokenType(),jt->getCurrToken(),4);
        }else if(jt->tokenType() == "keyword"){
            printToken(jt->tokenType(),jt->getCurrToken(),4);
        }else if (jt->tokenType() == "symbol"){
            printToken(jt->tokenType(),jt->getCurrToken(),4);
        }
        advanceTokenizer();
    }
    printToken("symbol",jt->getCurrToken(),4);
    advanceTokenizer();
    cout<<"</varDec>"<<endl;
}
/**
 * Compiles a sequence of statements not including the enclosing"{}"
*/
void CompilationEngine::compileStatemenets(){
    cout<<"<statements>"<<endl;
    while(stmSet.find(jt->keyWord())!= stmSet.end()){
        if(jt->getCurrToken() == "if"){
            compileIf();
        }else if(jt->getCurrToken() == "while"){
            compileWhile();
        }else if(jt->getCurrToken() == "do"){
            compileDo();
        }else if(jt->getCurrToken() == "return"){
            compileReturn();
        }else if(jt->getCurrToken() == "let"){
            compileLet();
        }
    }
    cout<<"</statements>"<<endl;

}  
/**
 * COmpiles a do statement
*/
void CompilationEngine::compileDo(){
    cout<<"<doStatement>"<<endl;
    printToken(jt->tokenType(), jt->getCurrToken(), 5);
    advanceTokenizer();
    printToken(jt->tokenType(), jt->getCurrToken(), 5);
    advanceTokenizer();
    compileSubroutineCall();
    assert(jt->getCurrToken() == ";");
    printToken(jt->tokenType(),jt->getCurrToken(),0);
    advanceTokenizer();
    cout<<"</doStatement>"<<endl;

}
/**
 * Compiles a let statement
*/
void CompilationEngine::compileLet(){
    cout<<printToken("<letStatement>",4);
    while(jt->getCurrToken() != "="){
        if(jt->getCurrToken() == "["){
            printToken(jt->tokenType(), jt->getCurrToken(), 5);
            advanceTokenizer();
            compileExpression();
            assert(jt->getCurrToken() == "]");
            printToken(jt->tokenType(), jt->getCurrToken(), 5);
            advanceTokenizer();
        }else{
            printToken(jt->tokenType(), jt->getCurrToken(), 5);
            advanceTokenizer();            
        }
    }
    printToken(jt->tokenType(), jt->getCurrToken(), 5);
    advanceTokenizer();
    compileExpression();
    assert(jt->symbol() == ';');
    printToken(jt->tokenType(), jt->getCurrToken(), 5);
    advanceTokenizer();
    cout<<printToken("</letStatement>",4);
}
/**
 *  Compiles a while statement 
*/
void CompilationEngine::compileWhile(){
    cout<<printToken("<whileStatement>",3);
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    assert(jt->getCurrToken() == "(");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    compileExpression();
    assert(jt->getCurrToken() == ")");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    assert(jt->getCurrToken() == "{");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    compileStatemenets();
    assert(jt->getCurrToken() == "}");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();

    cout<<printToken("</whileStatement>",3);
}
/**
 * Compiles a return statement
*/
void CompilationEngine::compileReturn(){
    cout<<"<returnStatement>"<<endl;
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    if(jt->getCurrToken() != ";"){
        compileExpression();
    }
    assert(jt->getCurrToken() == ";");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    cout<<"</returnStatement>"<<endl;
}
/**
 * Compile if statement, posibly with a trailing else clause.
*/
void CompilationEngine::compileIf(){
    cout<<"<ifStatement>"<<endl;
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    assert(jt->getCurrToken() == "(");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    compileExpression();
    assert(jt->getCurrToken() == ")");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    assert(jt->getCurrToken() == "{");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    compileStatemenets();
    assert(jt->getCurrToken() == "}");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
    advanceTokenizer();
    if(jt->getCurrToken() == "else"){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
        advanceTokenizer();
        assert(jt->getCurrToken() == "{");
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
        advanceTokenizer();
        compileStatemenets();
        assert(jt->getCurrToken() == "}");
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 4);
        advanceTokenizer();
    }
    cout<<"</ifStatement>"<<endl;   
}
/**
 * Compiles expression
*/
void CompilationEngine::compileExpression(){
    cout<<printToken("<expression>",5);
    compileTerm();
    while(symbol_set.find(jt->getCurrToken()) != symbol_set.end()){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 6);
        advanceTokenizer();   
        compileTerm();
    }
    cout<<printToken("</expression>",5);
}
/**
 * Compiles a term. THis routine is  Faced witha sligth difficulty
 * when trying to decide between some of the alternative parsing rules.
 * Specifically, if the current tokken is an identifier,  the routine must distinguish 
 *                                              between a variable, array entry and a subroutine call
 * A single look ahead token , which may be one of '[', '('  or '.' suffices to distinguish between three possibilites.
 * Any other token is not part of this term and should not be advanced over.
 * 
*/
void CompilationEngine::compileTerm(){
    cout<<printToken("<term>",6);
    if(jt->tokenType() == "integerConstant" || jt->tokenType() == "stringConstant"|| jt->tokenType() == "keyword"){
        if(jt->tokenType() == "stringConstant"){
            cout<<buildOutToken(jt->tokenType(),jt->stringVal(),7);
            advanceTokenizer();
        }else{
            cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
            advanceTokenizer();
        }
    }else if( jt->getCurrToken() == "~" || jt->getCurrToken() == "-"){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        compileTerm();
    }else if(jt->getCurrToken() == "("){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        compileExpression();
        assert(jt->getCurrToken() == ")");
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
    }else if(jt->tokenType() == "identifier"){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        if(jt->getCurrToken() == "["){
            cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
            advanceTokenizer();
            compileExpression();
            assert(jt->getCurrToken() == "]");
            cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
            advanceTokenizer();  
        }else if(jt->getCurrToken() == "(" || jt->getCurrToken() == "."){
            compileSubroutineCall();
        }
    }
    cout<<printToken("</term>",5);

}
void CompilationEngine::compileSubroutineCall(){
    if(jt->getCurrToken() == "("){
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        compileExpressionList();
    }else {
        // prints .t
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        //prints (
        cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
        advanceTokenizer();
        compileExpressionList();
    }
    assert(jt->getCurrToken() == ")");
    cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(),7);
    advanceTokenizer();
}
/**
 * Compiles a (possibly empty) comma separated list of expressions.
*/
void CompilationEngine::compileExpressionList(){
    cout<<printToken("<expressionList>",6);
    while(jt->getCurrToken() != ")"){
        compileExpression();
        if(jt->getCurrToken() == ","){
            cout<<buildOutToken(jt->tokenType(),jt->getCurrToken(), 6);
            advanceTokenizer();
        }
    }
    cout<<printToken("</expressionList>",6);
}


/*Private functions*/

string CompilationEngine::buildOutToken(string type , string token,int tabSize ){
    string tabs = "";
    // for(int i = 0; i< tabSize ; i ++){
    //     tabs+="\t";
    // }
    if(token == ">" ) {
        token = "&gt;";
    }else if(token == "<"){
        token = "&lt;";
    }else if (token == "&"){
        token = "&amp;";
    }
    string res =  tabs+"<"+type + "> " + token + " </" + type + ">\n";
    return res;
}
string CompilationEngine :: printToken(string token , int tabNum){
    string tabs = "";
 
    string res = tabs + token +"\n";
    return res;
}
void CompilationEngine::advanceTokenizer(){
    if(jt->hasMoreTokens()) {
        jt->advance();
    }
}
void CompilationEngine::printToken(string type,string token,int tabSize){
    cout<<buildOutToken(type , token,tabSize);  

}
void CompilationEngine::setupSets(){
    stmSet.insert("if");
    stmSet.insert("while");
    stmSet.insert("let");
    stmSet.insert("do");
    stmSet.insert("else");
    stmSet.insert("return");
    keywordSet.insert("static");
    keywordSet.insert("field");
    keywordSet.insert("constructor");
    keywordSet.insert("function");
    keywordSet.insert("method");
    keywordSet.insert("void");
    symbol_set.insert("+");
    symbol_set.insert("-");
    symbol_set.insert("*");
    symbol_set.insert("/");
    symbol_set.insert("&");
    symbol_set.insert("|");
    symbol_set.insert("<");
    symbol_set.insert(">");
    symbol_set.insert("=");
}