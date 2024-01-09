#include "string_base.h"
#include <iostream>

StringBase::StringBase() : data(nullptr) {}

StringBase::StringBase(const char* cString) {
    data = new char[strlen(cString) + 1];
    strcpy_s(data, strlen(cString) + 1, cString);
}

StringBase::StringBase(const StringBase& other) {
    data = new char[strlen(other.data) + 1];
    strcpy_s(data, strlen(other.data) + 1, other.data);
}

StringBase& StringBase::operator=(const StringBase& other) {
    if (this != &other) {
        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy_s(data, strlen(other.data) + 1, other.data);
    }
    return *this;
}

StringBase::~StringBase() {
    delete[] data;
}

size_t StringBase::length() const {
    return data ? strlen(data) : 0;
}

void StringBase::clear() {
    delete[] data;
    data = nullptr;
}

StringBase StringBase::operator+(const StringBase& other) const {
    StringBase result;
    result.data = new char[length() + other.length() + 1];
    strcpy_s(result.data, length() + other.length() + 1, data);
    strcat_s(result.data, length() + other.length() + 1, other.data);
    return result;
}

StringBase& StringBase::operator+=(const StringBase& other) {
    char* temp = new char[length() + other.length() + 1];
    strcpy_s(temp, length() + other.length() + 1, data);
    strcat_s(temp, length() + other.length() + 1, other.data);
    delete[] data;
    data = temp;
    return *this;
}

bool StringBase::operator==(const StringBase& other) const {
    return strcmp(data, other.data) == 0;
}

bool StringBase::operator!=(const StringBase& other) const {
    return !(*this == other);
}
