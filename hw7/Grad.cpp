#include "Grad.h"
#include "grade.h"

using namespace std;
//TODO
std::istream& Grad::read(std::istream& in){
    read_common(in);
    in>>thesis;
    read_hw(in,homework);
    return in;
}

double Grad::grade() const{
    return min(Core::grade(),thesis);
}