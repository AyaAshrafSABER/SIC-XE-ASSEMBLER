#include "LitTable.h"
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <bitset>

using namespace std;

    void LitTable::addLiteral(string litName, int type) {
        literal_info litInfo;
        litInfo.address = -1;
        litInfo.value = litValue(litName, type);
        int literalLength = litLength(litName);
        litInfo.length = literalLength;
        literal_table[litName] = litInfo;
    }

    int LitTable::assignAddress(int startAddress) {
        literal_table_iterator = literal_table.begin();
         for (literal_table_iterator; literal_table_iterator!=literal_table.end(); ++literal_table_iterator) {
            if (literal_table_iterator->second.address != -1) {
                string name = literal_table_iterator->first;
                int incValue = getIncrValue(name);
                startAddress += incValue;
                literal_table_iterator->second.address = startAddress;
            }
         }
         return startAddress;
    }

    int LitTable::litLength(string litName) {
        string value = getValue(litName);
        return ceil(value.length()/2);
    }

    string LitTable::litValue(string litName, int type) {
        string value;
        if (type == 6) {
            string str;
            if (litName.at(2) == '-') {
                str = litName.append(litName, 3, litName.length() - 1);
                int decimalValue = atoi(str.c_str()) + 1;
                litName = convertToHexa(convertToBin(decimalValue));
            }
        } else {
            for (int i = 2; i < litName.length() - 1; i++) {
                value.append(getAscii(litName.at(i)));
            }
        }
        return value;
    }

    int LitTable::getLength(string litName) {
        literal_table_iterator = literal_table.find(litName);
        if (literal_table_iterator != literal_table.end()) {
           return literal_table_iterator->second.length;
        }
        return -1;
    }

    string LitTable::getValue(string litName) {
        literal_table_iterator = literal_table.find(litName);
        if (literal_table_iterator != literal_table.end()) {
           return literal_table_iterator->second.value;
        }
        return "";
    }

    int LitTable::getAddress(string litName) {
        literal_table_iterator = literal_table.find(litName);
        if (literal_table_iterator != literal_table.end()) {
            return literal_table_iterator->second.address;
        }
        return -1;
    }

    int LitTable::getIncrValue (string litName) {
        string value = getValue(litName);
        return ceil(value.length()/2);
    }

    string LitTable:: getAscii(char x){
        hashtable.emplace('0', "30");
        hashtable.emplace('1', "31");
        hashtable.emplace('2', "32");
        hashtable.emplace('3', "33");
        hashtable.emplace('4', "34");
        hashtable.emplace('5', "35");
        hashtable.emplace('6', "36");
        hashtable.emplace('7', "37");
        hashtable.emplace('8', "38");
        hashtable.emplace('9', "39");

        hashtable.emplace('A', "41");
        hashtable.emplace('B', "42");
        hashtable.emplace('C', "43");
        hashtable.emplace('D', "44");
        hashtable.emplace('E', "45");
        hashtable.emplace('F', "46");
        hashtable.emplace('G', "47");
        hashtable.emplace('H', "48");
        hashtable.emplace('I', "49");
        hashtable.emplace('J', "4A");
        hashtable.emplace('K', "4B");
        hashtable.emplace('L', "4C");
        hashtable.emplace('M', "4D");
        hashtable.emplace('N', "4E");
        hashtable.emplace('O', "4F");
        hashtable.emplace('P', "50");
        hashtable.emplace('Q', "51");
        hashtable.emplace('R', "52");
        hashtable.emplace('S', "53");
        hashtable.emplace('T', "54");
        hashtable.emplace('U', "55");
        hashtable.emplace('V', "56");
        hashtable.emplace('W', "57");
        hashtable.emplace('X', "58");
        hashtable.emplace('Y', "59");
        hashtable.emplace('Z', "5A");

        hashtable.emplace('a', "61");
        hashtable.emplace('b', "62");
        hashtable.emplace('c', "63");
        hashtable.emplace('d', "64");
        hashtable.emplace('e', "65");
        hashtable.emplace('f', "66");
        hashtable.emplace('g', "67");
        hashtable.emplace('h', "68");
        hashtable.emplace('i', "69");
        hashtable.emplace('j', "6A");
        hashtable.emplace('k', "6B");
        hashtable.emplace('l', "6C");
        hashtable.emplace('m', "6D");
        hashtable.emplace('n', "6E");
        hashtable.emplace('o', "6F");
        hashtable.emplace('p', "70");
        hashtable.emplace('q', "71");
        hashtable.emplace('r', "72");
        hashtable.emplace('s', "73");
        hashtable.emplace('t', "74");
        hashtable.emplace('u', "75");
        hashtable.emplace('v', "76");
        hashtable.emplace('w', "77");
        hashtable.emplace('x', "78");
        hashtable.emplace('y', "79");
        hashtable.emplace('z', "7A");
        string result = hashtable[x];
        return result;
    }

    string LitTable::convertToHexa(int decimalNumber) {
        char hexaNumber[15];
        int hexaLength = 0;
        while (decimalNumber != 0) {
          int modNumber = decimalNumber % 16;
          if (modNumber < 10) {
             modNumber = modNumber + 48;
          } else {
            modNumber = modNumber + 55;
          }
            hexaNumber[hexaLength] = modNumber;
             decimalNumber /= 16;
             hexaLength++;
        }
        string result = convertCharToString(hexaNumber, hexaLength);

         return result;
    }

    string LitTable::convertCharToString(char hexaNumber[], int hexaLength) {
        char newChar[hexaLength];
        int counter = 0;
        for (int i = hexaLength - 1; i >= 0; i--) {
            newChar[counter++] = hexaNumber[i];
        }
        newChar[counter] = '\0';
        string result(newChar);
        return result;
    }

    bool LitTable::contain(string litName){
        return (literal_table.find(litName) != literal_table.end());
    }

    int LitTable::convertToBin(int value) {
        string str = bitset<16>(value).to_string();
        int i;
        char s[17];
        for (i = 0; i < str.length(); i++) {
            if(str.at(i) == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        s[i] = '\0';
        char* temp = &(s[0]);
        value = strtol(temp, NULL, 2);
        return value;
    }
