#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <algorithm>
#include <iostream>
#include <map>


using namespace std;

class SymbolTable
{
    public:
        SymbolTable();
        /*add symbol [name, address, type]
        return error if exists
        */
        void addSymbol(string*, int, bool);
        //edit symbol address, type
        void modifySymbol(string*, int, bool);
        //check if symbol exists
        bool containSymbol(string*);

        int getSymbolAddress(string*);
        bool getSymbolType(string*);
        int getSymbolLength(string*);

    private:
        int symbolLength(string);
        void toUpper(string*);
        //info about the symbol
        struct symbol_info {
            int address;
            bool type;
            int length;
        };
        //map that stores the symbols
        map<string, symbol_info> symbol_table;
        //iterator for map iteration
        map<string, symbol_info>::iterator symbol_table_iterator;
};

#endif // SYMBOLTABLE_H
