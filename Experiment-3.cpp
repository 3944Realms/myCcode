#include <iostream>
#include <windows.h>
using namespace std;
int main(){
    //UTF-8
    int i;
    SetConsoleOutputCP(65001);
    cout<<" 输入n： ";
    cin>>i;
    for (int n = 1;n <= i; n++){//控制每行
        for(int space = i - n;space != 0; space--) cout<<" ";
        for(int sign = 2*n - 1;sign != 0; sign--) cout<<"*";
        cout<<endl;//换行符
    }
    return 0;
}
/*
      *      1 6 1
     ***     2 5 3
    *****    3 4 5
   *******   4 3 7
  *********  5 2 9
 *********** 6 1 11
*************7 0 13
   .......   ......
 序列号n  总行数N  空格数： N - n  星号数：2*n - 1        

*/