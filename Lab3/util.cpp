#include "util.h"
// You can include any std header file here.
#include <regex>

using namespace std;

/**
 * @brief split a string by the delimiter space aka ` ` and append the result to the back of the vector `ret`.
 * 
 * @param s the string to be splitted
 * @param ret result vector. In this lab, argument `ret` is a global variable 
 *            and is used to store the words according to the appearance order.
 */
void split_string(const string& s, vector<string>& ret) {
    // hint: you can use function `substr` to get a substring of the string `s`
    //       if you know what regular expression is, you can use `regex` to easily split the string `s`
    //       stringstream may be useful, too
    // TODO: implement this function
    /* Your code here */
        int count_delimiter = 0;
    vector<int> index_v;
    int index = 0;
    for (string::const_iterator it = s.begin(); it < s.end(); it++) {
        if (*it == ' ') {
            count_delimiter++;
            index_v.push_back(index);
        }
        index++;
    }
    if (count_delimiter == 0) {
        if(s != "")
        ret.push_back(s);
    }
    else {
        if(s.substr(0, index_v[0]) != ""){
            ret.push_back(s.substr(0, index_v[0]));
        }
        for (size_t i = 0; i < index_v.size() - 1; i++) {
            if(s.substr(index_v[i] + 1, index_v[i + 1] - index_v[i] - 1) != ""){
                ret.push_back(s.substr(index_v[i] + 1, index_v[i + 1] - index_v[i] - 1));
            }
        }
        if(s.substr(*index_v.rbegin() + 1, s.size() - *index_v.rbegin() - 1) != "")
        ret.push_back(s.substr(*index_v.rbegin() + 1, s.size() - *index_v.rbegin() - 1));
    }
    return;
}
