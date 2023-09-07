#ifndef STRING_H
#define STRING_H

#include <iostream>

using std::cin;
using std::ios_base;

class String {
    char* pData;
    size_t len;
public:
    String(const char* p = "");
    size_t size() const { return len; }
    const char* c_str() const { return pData; }
    String(char ch);
    String(const String& s1);

    virtual ~String() {
        delete[] pData;
    }

    String& operator=(const String& rhs_s);
    String operator+(const String& rhs_s) const;
    String operator+(char rhs_c) const { return *this + String(rhs_c); }


    char& operator[](unsigned int indx);
    const char& operator[](unsigned int indx) const;
};

std::ostream& operator<<(std::ostream& os, const String& s0);
std::istream& operator>>(std::istream& is, String& s0);
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif // SAVE_H
