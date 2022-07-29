#include "Student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;

//TODO
std::istream & Student_info::read_info(istream & in){
	in >> m_name >> m_median_test >> m_final_test;
	if(in){
		m_homework.clear();
		double x;
		while(in >> x){
			m_homework.push_back(x);
		}
		in.clear();
	}
	return in;
}

void Student_info::compute_grade(){
	m_grade = grade(m_median_test,m_final_test,m_homework);
}

string Student_info::get_name(){
	return m_name;
}


bool compare(Student_info &x, Student_info &y){
	return x.get_name() < y.get_name();
}

void Student_info::show_grade(){
	cout << m_name <<"'s final grade is "<<m_grade<<endl;
}