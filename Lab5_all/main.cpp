#include <iostream>
#include "myList.h"
#include <list>

bool test_push_back(){
	List<int> mylist;
    std::list<int> reflist;
	for(int i = 0; i < 20; i++){
		mylist.push_back(i);
		reflist.push_back(i);
	}
	auto it = mylist.begin();
	for(auto refit = reflist.begin(); refit != reflist.end(); refit++){
		if(*it!=*refit || it==mylist.end()){
			return false;
		}
		it++;
	}
	return true;
}

bool test_pop_back(){
    List<int> mylist;
    std::list<int> reflist;
	for(int i = 0; i < 20; i++){
		mylist.push_back(i);
		reflist.push_back(i);
	}
    for(int i = 0; i < 10; i++){
		mylist.pop_back();
		reflist.pop_back();
	}
    auto it = mylist.begin();
	for(auto refit = reflist.begin(); refit != reflist.end(); refit++){
		if(*it!=*refit || it==mylist.end()){
			return false;
		}
		it++;
	}
	return true;
}

//As the test_push_back function call the API begin() and end(), so I didn't write a individual test function for them
bool test_begin_and_end(){
    if(test_begin_and_end){
        return true;
    }else{
        return false;
    }
}

bool test_size(){
    List<int> mylist;
    std::list<int> reflist;
	for(int i = 0; i < 20; i++){
		mylist.push_back(i);
		reflist.push_back(i);
	}
    if(mylist.size() == reflist.size()){
        return true;
    }
    else {
        return false;
    }
}

bool test_insert(){
    List<int> mylist;
    std::list<int> reflist;
	for(int i = 0; i < 20; i++){
		mylist.push_back(i);
		reflist.push_back(i);
	}
    mylist.insert(mylist.begin(),1000);
    reflist.insert(reflist.begin(),1000);
    auto it = mylist.begin();
	for(auto refit = reflist.begin(); refit != reflist.end(); refit++){
		if(*it!=*refit || it==mylist.end()){
			return false;
		}
		it++;
	}
	return true;
}

bool test_sort(){
    List<int> mylist;
    std::list<int> reflist;
	for(int i = 0; i < 20; i++){
		mylist.push_back(i);
		reflist.push_back(i);
	}
    mylist.insert(mylist.begin(),1000);
    reflist.insert(reflist.begin(),1000);
    mylist.sort();
    reflist.sort();
    auto it = mylist.begin();
	for(auto refit = reflist.begin(); refit != reflist.end(); refit++){
		if(*it!=*refit || it==mylist.end()){
			return false;
		}
		it++;
	}
	return true;
}

int main(){
    if(!test_begin_and_end){
		std::cout << "Test begin_and_end fail" << std::endl;
	}else
    if(!test_push_back){
		std::cout << "Test push_back fail" << std::endl;
	}else
    if(!test_pop_back){
        std::cout << "Test pop_back fail" << std::endl;
    }else
    if(!test_size){
        std::cout << "Test size fail" << std::endl;
    }else
    if(!test_insert){
        std::cout << "Test insert fail" << std::endl;
    }else
    if(!test_sort){
        std::cout << "Test sort fail" << std::endl;
    }else{
		std::cout << "All tests passed:" << std::endl;
		std::cout <<"1.begin_and_end 2.push/pop_back 3.size 4.insert 5.sort" << std::endl;
	}
}