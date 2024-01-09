#ifndef BINARY_STRING_H
#define BINARY_STRING_H

#include "string_base.h"
#include <iostream>

class BinaryString : public StringBase {
public:
    BinaryString();
    BinaryString(const char* cString);
    BinaryString(const BinaryString& other);
    BinaryString& operator=(const BinaryString& other);
    ~BinaryString();

    
    void changeSign();

    
    BinaryString operator+(const BinaryString& other) const;
    BinaryString& operator+=(const BinaryString& other);

    
    bool operator==(const BinaryString& other) const;
    bool operator!=(const BinaryString& other) const;

    friend std::ostream& operator<<(std::ostream& os, const BinaryString& binaryStr);

private:
    
    bool isBinary(const char* cString) const;
};

#endif 
