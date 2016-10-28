#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(){
        vector<string> vs;
        string fooline;
        while(getline(cin, fooline)){
                istringstream is(fooline);
                string s;
                while(is >> s){
                        cout <<s<<endl;
                }
        }
        
        return 0;
}
