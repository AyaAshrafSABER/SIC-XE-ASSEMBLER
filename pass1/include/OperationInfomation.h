#ifndef OPERATIONINFOMATION_H_INCLUDED
#define OPERATIONINFOMATION_H_INCLUDED

#include <vector>

/**
 * A class containing some information about the instruction.
 */
class OperationInformation {
public:
    /**
     * The opCode of the instruction.
     */
    unsigned char opCode;
    /**
     * An int representing the existence of label in
     * the instruction. -1 can't find 0 optional 1 must be found.
     */
    int label;
    /**
     * The supported formats of the instruction. 1 ,2,3,4
     */
    std::vector<int> supportedFormats;

};


#endif // OPERATIONINFOMATION_H_INCLUDED
