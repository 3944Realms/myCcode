#include <iostream>
#include <windows.h>
using namespace std;
int Fun(int num);
int main(){
    //UTF-8
    SetConsoleOutputCP(65001);
    int number;
    cout<<"请输入任意数位数:";
    cin>>number;
    int output = Fun(number);//抽取的函数
    if (output == 0) {
        cout<<"输入数位上没有偶数"<<endl;
        return 0;
        }
    cout<<"输出结果为："<<output;
    return 0;
}
int Fun(int num){
    int value,newnumber = 0;
    while (num){
        if ((num % 10) % 2 == 0){//筛选
            value = num % 10;
            newnumber *= 10;
            newnumber += value;
        } 
        num /= 10; //去位
    }
    return newnumber;
}