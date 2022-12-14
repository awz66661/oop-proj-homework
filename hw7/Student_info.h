#ifndef GUARD_Student_info
#define GUARD_Student_info

#include "Vec.h"
#include <string>
#include <istream>
#include <iostream>
#include "Core.h"
#include "Grad.h"

class Student_info{
    //TODO
public:
    Student_info():cp(0){}
    Student_info(std::istream& is):cp(0){read(is);}
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info(){delete cp;}

    std::istream& read(std::istream&);

    std::string name() const{
        if(cp) return cp->name();
        else throw std::runtime_error("uninitialized Student");
    }

    double grade() const{
        if(cp) return cp->grade();
        else throw std::runtime_error("uninitialized Student");
    }

    static bool compare_grade(const Student_info& s1, const Student_info& s2){
        return s1.grade() < s2.grade();
    }

    // bool compare_grade(const Student_info& x,const Student_info& y){
    //     return x.cp->grade() < y.cp->grade();
    // }
private:
    Core* cp;
};


#endif
