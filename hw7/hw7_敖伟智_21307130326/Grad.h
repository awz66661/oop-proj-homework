#ifndef GUARD_GRAD
#define GUARD_GRAD

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"
#include "Core.h"

class Grad: public Core{
    //TODO
public:
    Grad():thesis(0){};
    Grad(std::istream& is){this->read(is);}
    double grade() const;
    std::istream& read(std::istream&);
private:
    double thesis;
protected:
    Grad* clone() const {return new Grad(*this);}
};

#endif
