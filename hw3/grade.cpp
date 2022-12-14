#include <vector>
#include <stdexcept>
#include <iterator>
#include "grade.h"
#include "algorithm.h"

using std::back_inserter;
using std::vector;
using std::domain_error;
using MySpace::remove_copy;
using MySpace::median;
using MySpace::transform;
using MySpace::average;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double> & hw)
{
	if(hw.size()==0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info & s){
	return grade(s.midterm,s.final,s.homework);
}

//grade_aux
double grade_aux(const Student_info & s)
{
    //TODO
	try{
		return grade(s);
	}catch (domain_error){
		return grade(s.midterm,s.final,0);
	}
}

//average_grade
double average_grade(const Student_info & s)
{
    //TODO
	return average(s.homework);
}

//optimistic_median
double optimistic_median(const Student_info & s)
{
    //TODO
	vector<double> x = s.homework;
	vector<double> x_without_0;
	remove_copy(x.begin(),x.end(),back_inserter(x_without_0),0.0);
	return median(x_without_0);
}

