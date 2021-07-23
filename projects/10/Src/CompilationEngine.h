#ifndef _COMPILATIONENGINE_H
#define _COMPILATIONENGINE_H
#include <bits/stdc++.h>
#include "JackTokenizer.h"
using namespace std;

class CompilationEngine{
    public:
        /**
         * Constructor
         * Takes the path to the file
        */
        CompilationEngine(JackTokenizer *jat,string given_file_path);  
        /**
         * Destructor
        */
        ~CompilationEngine();
        /**
         * Compiles a complete class
        */
        /**
         * Starts the translation  process;
        */
        void startCompiling();

        void compileClass();
        /**
         * Compiles a static or field declaration
        */
        void compileClassVarDec();
        /**
         * Compiles a complete method, function or constructor
        */
        void compileSubroutine();
        /**
         * Compiles a (possibly empty) parameter list, not including the enclosing "()"
        */
        void compileParameterList();

        /**
         * Compiles a var declaration
        */
        void compileVarDec();    
        /**
         * Compiles a sequence of statements not including the enclosing"{}"
        */
        void compileStatemenets();    
        /**
         * COmpiles a do statement
        */
        void compileDo();
        /**
         * Compiles a let statement
        */
        void compileLet();
        /**
         *  Compiles a while statement 
        */
        void compileWhile();
        /**
         * Compiles a return statement
        */
        void compileReturn();
        /**
         * Compile if statement, posibly with a trailing else clause.
        */
        void compileIf();
        /**
         * Compiles expression
        */
        void compileExpression();

        /**
         * Compiles a term. THis routine is  Faced witha sligth difficulty
         * when trying to decide between some of the alternative parsing rules.
         * Specifically, if the current tokken is an identifier,  the routine must distinguish 
         *                                              between a variable, array entry and a subroutine call
         * A single look ahead token , which may be one of '[', '('  or '.' suffices to distinguish between three possibilites.
         * Any other token is not part of this term and should not be advanced over.
         * 
        */
        void compileTerm();

        /**
         * Compiles a (possibly empty) comma separated list of expressions.
        */
        void compileExpressionList();



        void  compileSubroutineCall();

    private:
        set<string> stmSet;
        set<string> keywordSet;
        set<string> symbol_set;
        JackTokenizer *jt;
        string output_file_path;
        string buildOutToken(string type , string token,int tabSize );
        void advanceTokenizer();
        void printToken(string type,string token,int tabSize);
        void setupSets();
        string printToken(string token , int tabNum);
};
#endif
