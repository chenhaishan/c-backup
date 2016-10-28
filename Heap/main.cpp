#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    cout<<"start"<<endl;
    vector<int> vs;
    //vs.resize(100);
    for(int i = 0; i < 10; ++i){
        vs.push_back(i);
    }
    auto itr = vs.begin();
    while(itr != vs.end()){
        cout<<*itr<<endl;
        ++itr;
    }

    return 0;
}
