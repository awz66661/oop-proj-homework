#ifndef _STRING_H
#define _STRING_H

#include <algorithm>
#include <iostream>
#include "Vec.h"
#include <cstring>

//TODO
class Str{
    friend std::istream& operator>>(std::istream&,Str&);
public:
    typedef Vec<char>::size_type size_type;
    //The default constructor
    Str(){}
    //Create a object Str,it contain n copies of character c
    Str(size_type n,char c){}
    //Create a object Str,and initialize it with a string
    Str(const char*cp){
        std::copy(cp,cp+std::strlen(cp),std::back_inserter(data));
    }
    //Create a object str,and initialize it with the characters between iterators b and e
    template<class In>
    Str(In b,In e){
        std::copy(b,e,std::back_inserter(data));
    }
    //reload []
    char& operator[](size_type i){
        return data[i];
    }
    //reload const[]
    const char& operator[](size_type i) const {
        return data[i];
    }
    //size of data
    size_type size() const {
        return data.size();
    }
    //reload +=
    Str& operator +=(const Str& s){
        std::copy(s.data.begin(),s.data.end(),std::back_inserter(data));
        return *this;
    }
private:
    Vec<char> data;
};
std::ostream& operator<<(std::ostream&, const Str&);
Str operator +(const Str&, const Str&);


#endif
