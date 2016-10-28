#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> vs{"hello", "world", "!"};
	for_each(vs.begin(), vs.end(), [](const string &s){cout<<s<<endl;});
	return 0;
} 
