#include "GroupTable.h"
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void GroupTable::addGroup(string groupName, int groupAddress, int groupNumber) {
    toUpper(groupName);
    group_info groupInfo;
    groupInfo.address = groupAddress;
    groupInfo.number = groupNumber;
    group_table[groupName] = groupInfo;
}

int GroupTable::getGropLength(string groupName) {
    toUpper(groupName);
    group_table_iterator = group_table.find(groupName);
    if (group_table_iterator != group_table.end()) {
        group_table_iterator->second.length;
    }
    return -1;
}

int GroupTable::getGroupAddress(string groupName) {
    toUpper(groupName);
    group_table_iterator = group_table.find(groupName);
    if (group_table_iterator != group_table.end()) {
        group_table_iterator->second.address;
    }
    return -1;
}

void GroupTable::modifyGroup(string groupName, int groupAddress, int groupLength) {
    toUpper(groupName);
    group_table_iterator = group_table.find(groupName);
    if (group_table_iterator != group_table.end()) {
        group_table_iterator->second.address = groupAddress;
        group_table_iterator->second.length = groupLength;
    }
}

bool GroupTable::containGroup(string groupName) {
    toUpper(groupName);
    return (group_table.find(groupName) != group_table.end());
}
string GroupTable::toUpper(string groupName) {
    transform(groupName.begin(), groupName.end(), groupName.begin(), ::toupper);
}
