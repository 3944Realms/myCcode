#include <iostream>
#include <math.h>
#include <windows.h>
int Sum(int value);
int main(){
    //控制台默认使用GBK编码，需要转UTF-8编码
    SetConsoleOutputCP(65001);
    int n;
    double sum;
    std::cout<<"输入：";
    std::cin>>n;
    sum = Sum(n);
    std::cout<<"输出：";
    std::cout<<sum;
    return 0;
}
int Sum(int value){
    int sum;
    for (int i = 1; i <= value ;i++){
        sum += pow(-1,(double)(i-1)) * ((double)((2*i - 1)*(2*i + 1)) / pow((double)i*2,2.0));
    }
    return sum;
}