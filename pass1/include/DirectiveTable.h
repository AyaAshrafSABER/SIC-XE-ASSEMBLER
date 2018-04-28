#ifndef DIRECTIVETABLE_H_INCLUDED
#define DIRECTIVETABLE_H_INCLUDED

#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class DirectiveTable {
public:
    static DirectiveTable *getInstance();

    bool contains(std::string directive);
    DirectiveTable();
private:
    string toUpper(string*);
    static DirectiveTable *instance;
    std::vector<std::string> dirTable;



    void initDirTable();
};

#endif // DIRECTIVETABLE_H_INCLUDED
