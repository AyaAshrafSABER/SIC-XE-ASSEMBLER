#ifndef LITTABLE_H
#define LITTABLE_H

#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LitTable
{

    public:
        void addLiteral(string, int);
        int assignAddress(int);
        int getLength(string);
        string getValue(string);

   private:
        int litLength(string);
        //info about the literals
        struct literal_info {
            int address;
            int length;
            string value;
        };
        //map that stores the literals
        map<string, literal_info> literal_table;
        //iterator for map iteration
        map<string, literal_info>::iterator literal_table_iterator;
        bool contain(string);
        string litValue(string, int);
        int getIncrValue (string);
        string getAscii(char);
        string convertCharToString(char [], int);
        string convertToHexa(int);
        unordered_map<char ,string> hashtable;
        int getAddress(string);
        int convertToBin(int);

};

#endif // LITTABLE_H
