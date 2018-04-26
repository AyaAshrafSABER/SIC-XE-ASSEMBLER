#include "SymbolTable.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

    void SymbolTable::addSymbol(string symbolName, int symbolAddress, bool symbolType) {
        toUpper(symbolName);
        symbol_info symbolInfo;
        symbolInfo.address = symbolAddress;
        symbolInfo.type = symbolType;
        int symbolLen = symbolLength(symbolName);
        symbolInfo.length = symbolLen;
        symbol_table[symbolName] = symbolInfo;
    }

    int SymbolTable::symbolLength(string symbolName) {
        return symbolName.length();
    }

    bool SymbolTable::containSymbol(string symbolName) {
         toUpper(symbolName);
         return (symbol_table.find(symbolName) != symbol_table.end());
    }

    int SymbolTable::getSymbolAddress(string symbolName) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(symbolName);
        if (symbol_table_iterator != symbol_table.end()) {
            return symbol_table_iterator->second.address;
        }
        return -1;
    }
    int SymbolTable::getSymbolLength(string symbolName) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(symbolName);
        if (symbol_table_iterator != symbol_table.end()) {
           return symbol_table_iterator->second.length;
        }
        return -1;
    }
    bool SymbolTable::getSymbolType(string symbolName) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(symbolName);
        return symbol_table_iterator->second.type;
    }

    void SymbolTable::modifySymbol(string symbolName, int symbolAddress, bool symbolType) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(symbolName);
        if (symbol_table_iterator != symbol_table.end()) {
            symbol_table_iterator->second.address = symbolAddress;
            symbol_table_iterator->second.type = symbolType;
        }
    }
    string SymbolTable::toUpper(string symbolName) {
        transform(symbolName.begin(), symbolName.end(), symbolName.begin(), ::toupper);
    }

