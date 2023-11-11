#include <iostream>
#include <stdio.h>
using namespace std;
void Transform_int_to_char(int int_number){
    if (int_number < 0) {
        int_number *= -1;
        cout<<"-";
    }
    if (int_number > 0 && int_number < 10) {
        char value = int_number + '0'; 
        printf("%c",value);
    }
    else if (int_number >=10){
        Transform_int_to_char(int_number/10);//迭代
        char value = int_number%10 + '0';//达到最小规模后返回时的操作
        printf("%c",value);//达到最小规模后返回时的操作
    }   
}
int main (){
    int number;
    cin>>number;
    if (number ==0 ){//if 输入 == 0 -->直接输出‘0’
        cout<<"0";
        return 0;
    }
    Transform_int_to_char(number);
    return 0;
}