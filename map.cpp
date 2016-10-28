#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, string> ms = {
    {"hello", "world"},
    {"see", "you"},
    {"bye bye", "beautiful"}
    };
    
    for(auto s : ms){
        cout<<s.first<<":"<<s.second<<endl;
    }
    
    for(auto p = ms.begin(); p != ms.end(); ++p){
        cout<<p->first<<":"<<p->second<<endl;
    }
    
    return 0;
}
