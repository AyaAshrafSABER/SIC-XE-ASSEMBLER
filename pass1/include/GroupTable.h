#ifndef GROUPTABLE_H
#define GROUPTABLE_H
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class GroupTable
{
    public:
        GroupTable();
        void addGroup(string, int,int);
        void modifyGroup(string, int,int);
        int getGroupAddress(string);
        int getGropLength(string);
        bool containGroup(string);

    private:
        string toUpper(string);
        struct group_info {
            int number;
            int address;
            int length;
        };
        map<string, group_info> group_table;
        map<string, group_info>::iterator group_table_iterator;
};

#endif // GROUPTABLE_H
