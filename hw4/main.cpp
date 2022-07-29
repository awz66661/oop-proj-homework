#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;


int main() 
{ 
	//TODO
	vector<Student_info> stu;
	Student_info record;
	while(record.read_info(cin)){
		stu.push_back(record);
	}
	for(vector<Student_info>::iterator it = stu.begin();it != stu.end();it++){
		it->compute_grade();
	}
	sort(stu.begin(),stu.end(),compare);
	for(vector<Student_info>::iterator it = stu.begin();it != stu.end();it++){
		it->show_grade();
	}
	return 0; 
}
