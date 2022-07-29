#include <iostream>
#include <ios>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"
#include "median.h"
using namespace std;

// void test_show_grade(vector<Student_info>& students){
// 	for (std::vector<Student_info>::size_type i = 0; i != students.size(); i++){
// 		cout<<students[i].name<<endl;
// 		cout<<students[i].homework.size()<<endl;
// 		for(vector<double>::iterator it=students[i].homework.begin();it<students[i].homework.end();it++){
// 			cout<<*it<<" ";
// 		}
// 		cout<<endl;
// 	}

// }

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	while (read(cin, record)) {
		maxlen = max(record.name.size(), maxlen);
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);
	//test_show_grade(students);
	for (std::vector<Student_info>::size_type i = 0; i != students.size(); i++) {
		double final_grade = grade(students[i]);
		if(final_grade < 60.0){
				cout << students[i].name
				<< string(maxlen + 1 - students[i].name.size(), ' ');
			try {
				streamsize prec = cout.precision(3);
				cout << "Your final grade is " << setprecision(3)
				<< final_grade
				<< setprecision(prec) << endl;
			}
			catch (domain_error e) {
				cout << e.what();
			}
		}
	
	}
	return 0;
}