#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using namespace std;


double grade(double midterm, double final, std::vector<double>& hw) {
    return 0.2 * midterm + 0.4 * final + 0.4 * median(hw);
}
//TODO

