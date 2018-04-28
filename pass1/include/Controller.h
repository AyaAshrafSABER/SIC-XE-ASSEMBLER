#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include <inOutFile.h>
#include <LitTable.h>

class Controller
{
    public:
        static const int TYPE_ERRONEOUS_LINE = -1;
        static const int TYPE_COMMENT_ONLY = 1;
        static const int TYPE_WITH_LABEL = 2;
        static const int TYPE_WITH_LABEL_WITHOUT_OPERAND = 3;
        static const int TYPE_WITHOUT_LABEL = 4;
        static const int TYPE_WITHOUT_LABEL_AND_OPERAND = 5;

        static const int TYPE_IMMEDITAE_WORD = 0; //A
        static const int TYPE_IMMEDITAE_SYMBOL = 1; //R
        static const int TYPE_INDIRECT_WORD = 2;   //A
        static const int TYPE_INDIRECT_SYMBOL = 3; //R
        static const int TYPE_SYMBOL_OPERAND = 4;  //R
        static const int TYPE_HEXA_LITERAL = 5;  //A
        static const int TYPE_WORD_LITERAL = 6;  //A
        static const int TYPE_BYTE_LITERAL = 7;  //A
        static const int TYPE_HEXA_OPERAND = 8;  //A
        static const int TYPE_BYTE_OPERAND = 9; //A
        static const int TYPE_INDEXED_SYMBOL = 10; //R
        static const int TYPE_WORD_OPERAND = 11; //A
        static const int TYPE_REGISTER_TO_REGISTER = 12; //R
        static const int TYPE_LOCCTR = 13;//R
        static const int TYPE_EXPRESSION = 14;//R
        int locctr;
        Controller();
        void start();

    private:
        string getSymbol(string);
        bool baseFound = false;
        bool endBaseFound = false;
        LitTable litTab
};

#endif // CONTROLLER_H
