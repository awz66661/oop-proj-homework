#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

int main(){
    string x;
    int k;//The rank of the number of the string
    vector<string>name;
    set<int>size_s;
    while(cin>>x){
        name.push_back(x);
        size_s.insert(x.size());
    }
    if(k > 1 && size_s.size() > k){
        for(vector<string>::iterator it = name.begin();it<name.end();it++){
            cout <<*it<<endl;
        }
    }
    return 0;
}
