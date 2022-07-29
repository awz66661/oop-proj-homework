#include "util.h"

#include <sstream>
using namespace std;

/**
 * @brief split single line string (Do not contain "\n") by delimiter to at most max_part
 * e.g "1,2,3,4" by "," at most 4 part => ["1","2","3","4"]
 *     "1,2,3,4" by "," at most 5 part => ["1","2","3","4"]
 *     "1,2,3,4" by "," at most 3 part => ["1","2","3,4"]
 * @param str any string
 * @param delim any char delimiter
 * @param max_part
 * @return vector<string> containing splitted string
 */
vector<string> split(const string& str, char delim, int max_part) {
    vector<string> res;
    // TODO: complete this function
    /* Your Code Here */
    int count_delim = 0;
    vector<int> index_v;
    int index = 0;
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == delim) {
            index_v.push_back(index);
            count_delim++;
        }
        index++;
    }
    if (count_delim == 0) {
        res.push_back(str);
    }else if (max_part > count_delim) {
        res.push_back(str.substr(0, index_v[0]));
        for (size_t i = 0; i < index_v.size() - 1; i++) {
            res.push_back(str.substr(index_v[i] + 1, index_v[i + 1] - index_v[i] - 1));
        }
        res.push_back(str.substr(*index_v.rbegin() + 1, index_v[str.size() - 1] - *index_v.rbegin() - 1));
    }
    else {
        res.push_back(str.substr(0, index_v[0]));
        for (size_t i = 0; i < max_part - 2; i++) {
            res.push_back(str.substr(index_v[i] + 1, index_v[i + 1] - index_v[i] - 1));
        }
        res.push_back(str.substr(index_v[max_part - 2] + 1, index_v[str.size() - 1] - index_v[max_part - 2] - 1));
    }
    return res;
}

/**
 * @brief output info string to os and mark it green
 *
 * @param os any output stream, usually cout
 * @param str any string
 * @return ostream& the original output stream
 */
ostream& output_info(ostream& os, const string& str) {
    os << "\033[32m" << str << "\033[0m";
    return os.flush();
}

/**
 * @brief output error string to os and mark it red
 *
 * @param os any output stream, usually cerr
 * @param str any string
 * @return ostream& the original output stream
 */
ostream& output_error(ostream& os, const string& str) {
    // TODO: complete this function
    /* Your Code Here */
    os << "\033[31m" << str << "\033[0m";
    return os.flush();
}