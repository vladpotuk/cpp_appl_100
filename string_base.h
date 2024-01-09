#ifndef STRING_BASE_H
#define STRING_BASE_H

#include <cstring>

class StringBase {
public:
    StringBase();
    StringBase(const char* cString);
    StringBase(const StringBase& other);
    StringBase& operator=(const StringBase& other);
    virtual ~StringBase();

    size_t length() const;
    void clear();

    
    virtual StringBase operator+(const StringBase& other) const;
    StringBase& operator+=(const StringBase& other);

    
    bool operator==(const StringBase& other) const;
    bool operator!=(const StringBase& other) const;

protected:
    char* data;
};

#endif 
