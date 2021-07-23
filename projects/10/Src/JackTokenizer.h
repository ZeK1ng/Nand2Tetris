#ifndef JACKTOKENIZER_H
#define JACKTOKENIZER_H

#include <bits/stdc++.h>
using namespace std;

class JackTokenizer
{
    public:
        /**
         * Opens the input file and gets ready to tokenize it
        */
        JackTokenizer(string filename);
        /**
         * Destructor , will close the opened file stream
        */
        ~JackTokenizer();
        /**
         * Returns true if there are tokens left
        */
        bool hasMoreTokens();
        /**
         * sets the current token to the next token if there are any
        */
        void advance();
        /**
         * Gets the next token from the input and makes it the current token.
         * 
        */
        string getNextToken();
        /**
         * return the type of the token
         * [Keyword,Symbol,identifier,int_const,string_const]
        */
        string tokenType();
        /**
         * return the keyWord which is the current token
         * should be called if tokentype is keyword 
        */
        string keyWord();
        /**
         * Returns the character which is the current token.Should ne called when tokenType is a Symbol
        */
        char symbol();
        /**
         * Returns the identifier which is the current Token;
         * Identifire = a sequence of letters digits and underscore('_') not starting with a digit 
        */
        string identifier();
        /**
         * Returns the integer Value of the current token.Should be called when tokenType() is INT_CONST
        */
        int intVal();
        /**
         * Returns the string value of the current Token, without double qotes.
         * Should be called only when TokenyType is STRING_CONST
        */
        string stringVal();
        /**
         * Returns the current Token
        */
        string getCurrToken();

        /**
         * Returns generated tokens
        */
        vector<string> getTokens();

        string getTokenType(string tok);
        char getSymbol(string tok);
        string getKeyWord(string tok);
        string getStringVal(string tok);
        int getIntVal(string tok);
        string get_identifier(string tok);
        


    private:
        vector<string> fileData;
        vector<string> tokens;
        vector<string> preTokens;
        set<string> keyword_set;
        set<string> symbol_set;
        string currToken;
        ifstream inp_stream;
        void setupSets();
        void tokenize();
        string trim(string &s);
        int currTokenIndex;
};

#endif