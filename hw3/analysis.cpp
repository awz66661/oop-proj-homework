#include <iterator>
#include "analysis.h"
#include "student_info.h"
#include "algorithm.h"
#include "grade.h"

using std::vector;
using std::back_inserter;
using MySpace::median;
using MySpace::average;
using MySpace::transform;
using MySpace::remove_copy;

double median_analysis(const vector<Student_info> & students)
{
    //TODO
    vector<double> grades;
    for(vector<Student_info>::const_iterator it = students.begin();it < students.end();it++){
        double y = grade(it->midterm,it->final,it->homework);
        grades.push_back(y);
    }
    return median(grades);


}

double average_analysis(const vector<Student_info> & students)
{
    //TODO
    vector<double> grades;
    for(vector<Student_info>::const_iterator it = students.begin();it < students.end();it++){
        double y = grade(it->midterm,it->final,average(it->homework));
        grades.push_back(y);
    }
    return median(grades);
}

double optimistic_median_analysis(const vector<Student_info> & students)
{
    //TODO
    vector<double> grades;
    for(vector<Student_info>::const_iterator it = students.begin();it < students.end();it++){
        double y = grade(it->midterm,it->final,optimistic_median(*it));
        grades.push_back(y);
    }
    return median(grades);
}
