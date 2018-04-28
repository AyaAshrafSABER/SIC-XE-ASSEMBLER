#ifndef OPERATIONTABLE_H_INCLUDED
#define OPERATIONTABLE_H_INCLUDED

#include "OperationInfomation.h"
#include <string>
#include <map>
using namespace std;

class OperationTable{
public:
    static OperationTable *getInstance();
    /**
    check if the given operation in the opTable or not.
    **/
    bool contains(std::string operation);
    /**
    return all information about this operation after checking that is true operation word.
    **/
    /*/*
    ha5od el operation upper case :D --------------->
    */
    OperationInformation getInfo(std::string operation);
    void test();
    OperationTable();
private:
    void toUpper(string*);
    /**
    private constractor to intialize  singleton.
    **/

    /**
    private object to constract static table.
    **/
    static OperationTable *instance;
    /**
    using map as a datastucture to constract operation table the operation is the key and Operation
    information is a class hold all information of the instruction avalible format and opcode and availabilty
    to find label with it or not.
    **/
    std::map<std::string,OperationInformation> opTable;
    /**
    call this method in the constractor to constrct opTable.
    */
    void initOpTable();

};

#endif // OPERATIONTABLE_H_INCLUDED
