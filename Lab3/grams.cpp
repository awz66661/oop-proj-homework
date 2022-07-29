#include "grams.h"
#include "util.h"
#include <iostream>
#include <regex>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

// define some global variables
vector<string> words;                       // all words, sort by appearance order
vector<pair<string, int>> freq;             // frequency of coocurrence of each word
// for simplicity, each row of the co-occurrence matrix represents the word by lexicographical order
// thus, we'd use a map to store the index of the word which is `word_index`
map<string, int> word_index;                // mapping the word to the index in the co-occurrence matrix
map<int, string> index_word;                // mapping the index to the word in the co-occurrence matrix
vector<vector<int>> coocur_matrix;          // co-ocurrence martix, each row is a n-gram
vector<vector<double>> normalized_matrix;   // normalized co-ocurrence martix
// You can add more global variables here if you need.
// Notice that if you add more global variables, you should declare them in the `grams.h` using `extern`

/**
 * @brief read the input file and record all words in the file. 
 *  Store the words in the vector `words` according to the appearance order.
 * 
 * @param filename  file name of the input file
 * @param words     vector to store the words
 * @return size_t   the size of the `words` vector
 */
size_t record_words(const string& filename, vector<string>& words) {
    ifstream file(filename);
    if (!file.good()) {
        cerr << "Error: cannot open file " << filename << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        split_string(line, words);
    }
    file.close();
    return words.size();
}

/**
 * @brief go through the vector `words` and record the frequency of each word.
 * e.g.:
 *  words = ["a", "a", "b", "c", "d", "e", "e"]
 *  freq = [("a", 2), ("b", 1), ("c", 1), ("d", 1), ("e", 2)]
 * 
 * @param words     vector of words
 * @param freq      vector to store the frequency of each word
 * @return size_t   the size of the `freq` vector
 */
size_t record_freq(const vector<string>& words, vector<pair<string, int>>& freq) {
    // hint: you may find the `map` data structure useful
    // TODO: impelement this function.
    /* Your code here */
    map<string,int> count_map;
    for(vector<string>::const_iterator it = words.begin();it < words.end(); it++){
        count_map[*it] += 1;
    }
    freq = vector<pair<string,int>>(count_map.begin(),count_map.end());
    return freq.size();
}

/**
 * @brief Compare Function for freq
 */
bool mycompare(pair<string,int> i,pair<string,int> j){
    if(i.second>j.second || (i.second == j.second && i.first < j.first)){
        return true;
    }
    else{
        return false;
    }
}


/**
 * @brief Filter out the 3000 most frequent words.
 * !!Notice that if a word is not in the 3000 most frequent words, it should be replaced by `<unk>`.
 * 
 * @param freq      vector of words and their frequency
 * @param words     original vector of words. You should change the vector `words` to keep the 3000 most frequent words.
 */
void filter_words(vector<pair<string, int>>& freq, vector<string>& words) {
    // hint: you can use function `sort` to sort the vector `freq` by modify the compare function.
    // if you want to write a compare function more gracefully, you can try to use `lambda expression`(It's a new feature in C++11.).
    // TODO: implement this function.
    /* Your code here */
    sort(freq.begin(),freq.end(),mycompare);
    set<string> most_3000_words;
    int i = 0;
    for(vector<pair<string,int>>::iterator it = freq.begin();i<3000;it++,i++){
        most_3000_words.insert(it->first);
    }
    for(vector<string>::iterator it = words.begin(); it < words.end(); it++){
        if(most_3000_words.find(*it) == most_3000_words.end()){
            *it = "<unk>";
        }
    }
    return;
}

/**
 * @brief Use `words` vector to construct a word index map. 
 * The key is the word and the value is the position of the word in the alphabetical order.
 * e.g. :
 * words: ["I", "like", "to", "eat", "apple"]
 * word_index: {"I": 0, "apple": 1, "eat": 2, "like": 3, "to": 4}
 * 
 * @param words         vector of words
 * @param word_index    map to store the word index
 * @return size_t       the size of the `word_index` map
 */
size_t set_word_index(const vector<string>& words, map<string, int>& word_index) {
    // TODO: implement this function
    /* Your code here */
    set<string> temp_sort;
    for(vector<string>::const_iterator it = words.begin();it < words.end(); it++){
        temp_sort.insert(*it);
    }
    int index = 0;
    for(set<string>::iterator it = temp_sort.begin();it != temp_sort.end();it++,index++){
        word_index[*it] = index;
    }
    return word_index.size();
}

/**
 * @brief Set up the coocur matrix object. 
 * Each row of the coocur matrix represents the word by lexicographical order. 
 * The value of each element in the co-occurrence matrix is the number of times that two words appear together.
 * e.g. :
 * consider n as 3,
 * words: ["<unk>", "I", "like", "to", "eat", "apple", "<unk>"]
 * coocur_matrix:   (sorted by lexicographical order. Thus, these rows represent the words ["<unk>", "I", "apple", "eat", "like", "to"])
 * coocur_matrix[1][4] == 1 represents that if consider "I" as center word, the number of times that "I" and "like" appear together is 1.
 * [0, 1, 1, 0, 0, 0]
 * [1, 0, 0, 0, 1, 0]
 * [1, 0, 0, 1, 0, 0]
 * [0, 0, 1, 0, 0, 1]
 * [0, 1, 0, 0, 0, 1]
 * [0, 0, 0, 1, 1, 0]
 * 
 * @param words             vector of words
 * @param word_index        map of word index
 * @param coocur_matrix     vector of vector to store the co-occurrence matrix
 * @param n                 hyper-parameter of n-gram
 */
void set_coocur_matrix(const vector<string>& words, const map<string, int>& word_index, vector<vector<int>>& coocur_matrix, int n) {
    int size = words.size();
    coocur_matrix = vector<vector<int>>(word_index.size(), vector<int>(word_index.size(), 0));
    for (int left = 0, right = n, center = (n + 1) / 2; right <= size; left++, right++, center++) {
        if (center % 100 == 0) {
            cout << setprecision(5) << (double)center/size << '\r';     // This is to show the progress of building the co-occurrence matrix.
        }
        // If you want, you can do the similar thing to print the progress of other parts.
        // TODO: impelement this function. Store the co-occurrence matrix in the `coocur_matrix` vector.
        /* Your code here */
        for(int index = left;index < right;index++){
            if(index != center){
                string i_word = words[center];
                int i = (*word_index.find(i_word)).second;
                string j_word = words[index];
                int j = (*word_index.find(j_word)).second;
                coocur_matrix[i][j]++;
            }
        }
    }
    return;
}

/**
 * @brief normalize the co-occurrence matrix by column.
 * e.g.:
 * co-occurrence matrix:
 * [0, 2, 1, 0, 0, 0]
 * [2, 0, 0, 0, 1, 0]
 * [1, 0, 0, 1, 0, 0]
 * [0, 0, 1, 0, 0, 1]
 * [0, 1, 0, 0, 0, 1]
 * [0, 0, 0, 1, 1, 0]
 * normalized matrix:
 * [0, 2/3, 0.5, 0, 0, 0]
 * [2/3, 0, 0, 0, 0.5, 0]
 * [1/3, 0, 0, 0.5, 0, 0]
 * [0, 0, 0.5, 0, 0, 0.5]
 * [0, 1/3, 0, 0, 0, 0.5]
 * [0, 0, 0, 0.5, 0.5, 0]
 * 
 * @param coocur_matrix         co-occurrence martix
 * @param normalized_matrix     normalized co-occurrence martix
 */
void normalize_matrix(const vector<vector<int>>& coocur_matrix, vector<vector<double>>& normalized_matrix) {
    // TODO: implement this function
    /* Your code here */
    normalized_matrix = vector<vector<double>>(word_index.size(), vector<double>(word_index.size(), 0.0));
    for(size_t index_j = 0;index_j < coocur_matrix.size();index_j++){
        double sum = 0;
        for(size_t index_i = 0;index_i < coocur_matrix.size();index_i++){
            sum += coocur_matrix[index_i][index_j];
        }
        for(size_t index_i = 0;index_i < coocur_matrix.size();index_i++){
            normalized_matrix[index_i][index_j] = coocur_matrix[index_i][index_j]/sum;
        }
    }
}

/**
 * @brief save the normalized co-occurrence matrix to a file. The first line should be the words which each row represents.
 * each number is separated by a space.
 * e.g.:
 * a b c d
 * 0.2 0 0.6 0.2
 * 0 0.5 0.5 0
 * 0.6666666666666666 0.3333333333333333 0 0
 * 0 0 0 1
 * 
 * @param filename      file name of the output file
 * @param matrix        normalized co-occurrence martix
 * @param word_index    map of word to index
 */
void save_matrix(const string& filename, const vector<vector<double>>& matrix, const map<string, int>& word_index) {
    // TODO: save the normalized_matrix to file `result.txt`. Notice that the first row should be the words.
    /* Your code here */
    ofstream ofs(filename);
    set<string> temp;
    for(map<string,int>::const_iterator it = word_index.begin();it != word_index.end();it++){
        temp.insert(it->first);
    }
    for(set<string>::iterator it = temp.begin();it !=temp.end();it++){
        ofs << *it << ' ';
    }
    ofs << endl;
    for(vector<vector<double>>::const_iterator it = matrix.begin();it != matrix.end();it++){
        for(vector<double>::const_iterator it1 = it->begin();it1 < it->end();it1++){
            ofs << *it1 <<' ';
        }
        ofs << endl;
    }
    if(!ofs.good()){
        cerr << "Error: cannot open file " << filename << endl;
        exit(1);
    }
}

/**
 * @brief restore the normalized co-occurrence matrix from file `filename`.
 * Assume that the file is in the same format as the one in `save_matrix` function.
 * e.g.:
 * 0.2 0 0.6 0.2
 * 0 0.5 0.5 0
 * 0.6666666666666666 0.3333333333333333 0 0
 * 0 0 0 1
 * 
 * @param filename    file name of the input file
 * @param matrix      normalized co-occurrence martix
 * @param index_word  map of index to word
 */
void restore_matrix(const string& filename, vector<vector<double>>& matrix, map<int, string>& index_word) {
    // hint: you can refer to the `set_word_index` function and `split_string` function.
    // TODO: restore the normalized_matrix from file `result.txt`.
    /* Your code here */
    ifstream ifs(filename);
    if(true){
        string x;
        getline(ifs,x);
        //x = x.substr(0,x.size()-1);
        vector<string> temp_word;
        split_string(x,temp_word);
        map<string,int> temp_word_index;
        set_word_index(temp_word,temp_word_index);
        matrix = vector<vector<double>>(temp_word.size(), vector<double>(temp_word.size(), 0.0));
        temp_word.clear();
        for(map<string,int>::iterator it = temp_word_index.begin();it != temp_word_index.end();it++){
            index_word[it->second] = it->first;
        }
        for(size_t index_i = 0;index_i < matrix.size();index_i++){
            getline(ifs,x);
            split_string(x,temp_word);
            for(size_t index_j = 0;index_j < matrix.size();index_j++){
                matrix[index_i][index_j] = stod(temp_word[index_j]);
            }
            temp_word.clear();
        }
    }
    return;
}

/**
 * @brief calculate the cosine similarity of word i and word j
 * you can calculate the cosine similarity by using the formula:
 * cosine_similarity = sum(matrix[i][k]*matrix[j][k]) / (sqrt(sum(matrix[i][k]^2)) * sqrt(sum(matrix[j][k]^2)))
 * if you can not understand the formula, please refer to the lab notes.
 * 
 * @param matrix    normalized co-occurrence martix
 * @param i         index of word i
 * @param j         index of word j
 * @return double   cosine similarity of word i and word j
 */
double similarity(const vector<vector<double>>& matrix, size_t i, size_t j) {
    // TODO: implement this function
    /* Your code here */
    double res;
    double molecular = 0;
    double denominator_part_1_before_sqrt = 0;
    double denominator_part_2_before_sqrt = 0;
    double denominator_part_1_after_sqrt = 0;
    double denominator_part_2_after_sqrt = 0;
    for(size_t siz = 0;siz<matrix.size();siz++){
        molecular += matrix[i][siz]*matrix[j][siz];
    }
    for(size_t siz = 0;siz<matrix.size();siz++){
        denominator_part_1_before_sqrt += pow(matrix[i][siz],2);
    }
    for(size_t siz = 0;siz<matrix.size();siz++){
        denominator_part_2_before_sqrt += pow(matrix[j][siz],2);
    }
    denominator_part_1_after_sqrt = sqrt(denominator_part_1_before_sqrt);
    denominator_part_2_after_sqrt = sqrt(denominator_part_2_before_sqrt);
    res = molecular/(denominator_part_1_after_sqrt*denominator_part_2_after_sqrt);
    return res == 0 ? 0 : res;
}

/**
 * @brief compare the pair
 * refered by sort
 * @param c1_c2
 */
bool mycompare1(pair<int,double> c1,pair<int,double> c2){
    return c1.second>c2.second;
}

/**
 * @brief find the 5 most similar words to the given word. If there are less than 5 words, then simply return all of them.
 * You should sort them by the similarity score in descending order.
 * If they have the same similarity score, then sort them by the alphabetical order.
 * 
 * @param word                  given word
 * @param matrix                normalized co-occurrence martix
 * @param index_word            map of index to word
 * @return vector<string>       vector of 5 most similar words
 */
vector<string> most_similar(const string& word, const vector<vector<double>>& matrix, const map<int, string>& index_word) {
    // TODO: implement this function. 
    /* Your code here */
    map<int,double> similarity_m;
    vector<pair<int,double>> sort_similarity;
    int i;
    int flag = 0;
    for(map<int,string>::const_iterator it = index_word.begin();it != index_word.end();it++){
        if(it->second == word){
            i = it->first;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cerr << "Error: cannot find word " << word << endl;
        return vector<string>();
    }
    for(size_t j = 0;j < matrix.size();j++){
        if(i != (int)j){
            similarity_m[j] = similarity(matrix,i,j);
        }
    }
    sort_similarity = vector<pair<int,double>>(similarity_m.begin(),similarity_m.end());
    sort(sort_similarity.begin(),sort_similarity.end(),mycompare1);
    vector<string> ret;
    int counter = 0;
    
    for(vector<pair<int,double>>::iterator it = sort_similarity.begin();it != sort_similarity.end(); it++){
        if(counter < 5){
            string word = (*index_word.find(it->first)).second;
            //string temp = to_string(it->second);
            ret.push_back(word);
            //ret.push_back(temp);
            counter++;
        }
    }
    return ret;
}