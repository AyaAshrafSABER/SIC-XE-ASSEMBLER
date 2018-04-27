//
// Created by Carnival Stores on 4/27/2018.
//

#include "inOutFile.h"
#include <iostream>
#include "fstream"
#include <vector>

using namespace std;

vector<string> inOutFile::readFile(string fileName) {
    string line;
    ifstream file(fileName);
    std::vector<std::string> fileContent;

    while( std::getline( file, line ) ) {
        fileContent.push_back( line );
    }
    return fileContent;
}

void inOutFile::writeFile(vector<string> fileContent, string fileName) {
    std::size_t line_count = fileContent.size();
    std::ofstream out(fileName);
    for( std::size_t i = 0; i < line_count; ++i ) {
        out <<fileContent[i] << std::endl;
    }
    out.close();
}
