#include "binary_string.h"
#include <iostream>

BinaryString::BinaryString() : StringBase() {}

BinaryString::BinaryString(const char* cString) {
    if (isBinary(cString)) {
        data = new char[strlen(cString) + 1];
        strcpy_s(data, strlen(cString) + 1, cString);
    }
    else {
        clear(); 
    }
}

BinaryString::BinaryString(const BinaryString& other) : StringBase(other) {}

BinaryString& BinaryString::operator=(const BinaryString& other) {
    if (this != &other) {
        StringBase::operator=(other);
    }
    return *this;
}

BinaryString::~BinaryString() {}

void BinaryString::changeSign() {
    
    if (data[0] == '0') {
        data[0] = '1';
    }
    else if (data[0] == '1') {
        data[0] = '0';
    }
}

BinaryString BinaryString::operator+(const BinaryString& other) const {
    BinaryString result;
    result.data = new char[length() + other.length() + 1];
    strcpy_s(result.data, length() + other.length() + 1, data);
    strcat_s(result.data, length() + other.length() + 1, other.data);
    return result;
}

BinaryString& BinaryString::operator+=(const BinaryString& other) {
    char* temp = new char[length() + other.length() + 1];
    strcpy_s(temp, length() + other.length() + 1, data);
    strcat_s(temp, length() + other.length() + 1, other.data);
    delete[] data;
    data = temp;
    return *this;
}

bool BinaryString::operator==(const BinaryString& other) const {
    return StringBase::operator==(other);
}

bool BinaryString::operator!=(const BinaryString& other) const {
    return StringBase::operator!=(other);
}

bool BinaryString::isBinary(const char* cString) const {
   
    for (size_t i = 0; i < strlen(cString); ++i) {
        if (cString[i] != '0' && cString[i] != '1') {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const BinaryString& binaryStr) {
    os << binaryStr.data;
    return os;
}
