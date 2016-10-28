#include <iostream>
using namespace std;

void func(int row, int (*A)[3]){
    for(int i = 0;i<row;++i){
        for(int j=0;j<sizeof(A[0])/sizeof(A[0][0]);++j){
            cout<<A[i][j]<<",";
        }
        cout<<endl;
    }
}

void func(int r, int l, int *A){
    for(int i = 0; i<r; ++i){
        for(int j = 0; j<l; ++j){
            cout<<*(A+i*l+j)<<",";
        }
        cout<<endl;
    }
}

int main()
{
    int a[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };
    cout<<"sizeof(int)"<<sizeof(int)<<endl;
    cout<<"sizeof(int*)"<<sizeof(int*)<<endl;
    cout<<"sizeof(a)"<<sizeof(a)<<endl;
    cout<<"sizeof(a[0])"<<sizeof(a[0])<<endl;
    func(sizeof(a)/sizeof(a[0]), a);
    func(sizeof(a)/sizeof(a[0]), sizeof(a[0])/sizeof(a[0][0]), (int *)a);
    return 0;
}
