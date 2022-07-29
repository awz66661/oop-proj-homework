#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	vector<string> S_p;
	vector<int> size_s;
	string x;
	int m, k;
	cin >> m;//输入字符串的个数
	cin >> k;//参数
	while (cin >> x) {
		S_p.push_back(x);
		size_s.push_back(x.size());
		if (S_p.size() == m) {
			break;
		}
	}
	sort(size_s.begin(), size_s.end());
	size_s.erase(unique(size_s.begin(), size_s.end()));//此处删除vector中的相同元素借用了网上的方法
	int index = -1;
	if(k>0){
		index = size_s[k - 1];
	}
	for (vector<string>::iterator it = S_p.begin(); it < S_p.end(); it++) {
		if (it->size() == index && index != -1 && size_s.size() > k) {
			cout << *it << endl;
		}
	}
}