#ifndef GUARD_Student_info
#define GUARD_Student_info

// TODO
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <vector>
#include "median.h"
#include "grade.h"
#include "Student_info.h"
using namespace std;

class Student_info{
	// TODO
public:
	istream & read_info(istream & in);
	void compute_grade();
	string get_name();
	void show_grade();
private:
	string m_name;
	double m_median_test;
	double m_final_test;
	vector<double> m_homework;
	double m_grade;
};

// TODO
bool compare(Student_info &x, Student_info &y);

#endif
