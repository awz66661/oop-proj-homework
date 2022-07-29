#include <vector>
#include <algorithm>
#include<stdexcept>
#include"median.h"
using namespace std;


//TODO


double median(std::vector<double> vec)
{
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double average(std::vector<double>& vec)
{
    double sum = 0.0;
    for (vector<double>:: iterator it = vec.begin(); it < vec.end(); it++) {
        sum += *it;
    }
    return sum/vec.size();
}


