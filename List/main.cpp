#include <iostream>
#include "List.h"

using namespace std;

int main(){
	List<int> LI;
	for(int i = 0; i< 3; ++i){
		LI.push_back(i);
	}
	
	for(List<int>::const_iterator i = LI.begin(); i != LI.end(); ++i){
		cout<<*i<<endl;
	}
	cout<<"const List<int> LI1"<<endl;
	const List<int> LI1(LI);
	for(auto i = LI1.begin(); i != LI1.end(); ++i){
		cout <<i.operator *()<<endl;
	}
        cout<<"#####################test1####################"<<endl;
        const List<int>::iterator citr(LI.begin());

        cout<<*citr<<endl;

        *citr +=1;
        cout<<*citr<<endl;

        //citr = LI.end();
        cout<<"#####################test2####################"<<endl;
        const List<int> LI2(LI);
        auto li2ptr = LI2.begin();
        while(li2ptr++ != LI2.end())
            cout<<*li2ptr<<endl;
        cout<<"#####################test3####################"<<endl;
        List<int>::const_iterator constitr = LI.begin();
        LI.insert(constitr, 9);
        for(List<int>::const_iterator i = LI.begin(); i != LI.end(); ++i){
                cout<<*i<<endl;
        }
        return 0;

}
