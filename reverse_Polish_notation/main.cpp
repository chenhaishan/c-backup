#include "Stack_List.h"
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
typedef int OPODER;
/*
void deloperator(string &s){
	for(string::iterator i = s.begin(); i != s.end(); ++i){
		if(!isspace(*i) && !isdigit(*i) && *i != '.')
			*i = ' ';
	}
}
*/
int main(int argc, char **argv)
{
	map<char, OPODER> opoder;
	opoder['+'] = 0;
	opoder['-'] = 0;
	opoder['*'] = 2;
	opoder['/'] = 2;
	opoder['('] = 9;
	opoder[')'] = 9;
	string exp;
	string re_polish;
	cout<<"input expression:"<<endl;
	getline(cin, exp);
	Stack<char> op;
	/*
	list<double> num;
	string snum(exp);
	deloperator(snum);
	istringstream isnum(snum);
	double tmp;
	while(isnum >> tmp){
		num.push_back(tmp);
	}
	*/
	
	for(auto i = exp.begin(); i != exp.end(); ++i){
		if(*i != '.' && !isspace(*i) && !isdigit(*i)){
			if(op.empty() || *i == '('){//如果遇到'('一律入栈，只有读取到')'才能弹出
				op.push(*i);
			}
			else if(*i == ')'){//遇到')'将'('与')'之间的所有操作符弹出。
				while(op.top() != '('){
					re_polish.push_back(op.pop());
					re_polish.push_back(' ');
				}
				op.pop();//最后还要弹出'('
			}
			/***如果读取的操作符优先级高于栈底的操作符，
			 * 或者栈顶操作符为'(',则入栈***/
			else if(op.top() == '(' || opoder[op.top()] < opoder[*i]){
				op.push(*i);
			}
			/***否则，一直弹出到有小于该操作符优先级的栈内操作符为止
			 * 并且，如果遇到'('也要停止，但不弹出'('***/
			else if(opoder[op.top()] >= opoder[*i]){
				while(opoder[op.top()] >= opoder[*i] && op.top() != '('){
					re_polish.push_back(op.pop());
					re_polish.push_back(' ');
				}
				op.push(*i);//最后将该操作符入栈
			}
		}
		else if(*i == '.' || isdigit(*i)){//如果是数字
			re_polish.push_back(*i);
			++i;
			while(*i == '.' || isdigit(*i)){
				re_polish.push_back(*i);
				++i;
			}
			re_polish.push_back(' ');
			--i;
				
		}
	}
	/***如果栈内还有操作符，则依次弹出***/
	while(!op.empty()){
		re_polish.push_back(op.pop());
	}
	cout<<re_polish<<endl;
	
	Stack<double> result;
	for(string::const_iterator itr = re_polish.begin(); itr != re_polish.end();
	++itr){
		string snum;
		while(isspace(*itr))++itr;
		while(isdigit(*itr) || *itr == '.' ){
			snum.push_back(*itr);
			++itr;
		}
		if(!snum.empty())
			result.push(stod(snum));
		if(isspace(*itr))continue;
		double l, r;
		switch(*itr){
		case '+':
			r = result.pop();
			l = result.pop();
			result.push(l+r);
			break;
		case '-':
			r = result.pop();
			l = result.pop();
			result.push(l-r);
			break;
		case '*':
			r = result.pop();
			l = result.pop();
			result.push(l*r);
			break;
		case '/':
			r = result.pop();
			l = result.pop();
			result.push(l/r);
			break;
		default:
			break;
			
		}
	}
	cout<<result.top()<<endl;
	return 0;
}
