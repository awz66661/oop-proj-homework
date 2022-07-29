#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"

using namespace std;
//成绩=0.2*期中+0.4*期末+0.4*(0.6*平均作业+0.4*中值作业
//TODO
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double grade(double midterm, double final, std::vector<double>& hw) {
    return 0.2 * midterm + 0.4 * final + 0.4 * (0.6 * average(hw) + 0.4 * median(hw));
}

double grade(Student_info& s) {
    return 0.2 * s.midterm + 0.4 * s.final + 0.4 * (0.6 * average(s.homework) + 0.4 * median(s.homework));
}

bool fgrade(Student_info& s)//if the grade of the student is not pass,it will show true
{
    if (grade(s) < 60) {
        return true;
    }
    return false;
}
