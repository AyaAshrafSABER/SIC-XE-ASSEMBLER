#ifndef DIRECTIVETABLE_H_INCLUDED
#define DIRECTIVETABLE_H_INCLUDED

#include <vector>
#include <string>
#include <algorithm>

class DirectiveTable {
public:
    static DirectiveTable *getInstance();

    bool contains(std::string directive);

private:
    static DirectiveTable *instance;
    std::vector<std::string> dirTable;

    DirectiveTable();

    void initDirTable();
};

#endif // DIRECTIVETABLE_H_INCLUDED
