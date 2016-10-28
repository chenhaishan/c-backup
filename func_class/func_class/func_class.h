#ifndef FUNC_CLASS_H
#define FUNC_CLASS_H

template<typename T>
T max(const T &l, const T &r){
	return l>r?l:r;
}

class A{
private:
	int i;
	int j;
public:
	A(const int &first, const int &second)
	:i(first), j(second){}
	int findmax(){
		return max<int>(i,j);
	}
	
};


#endif