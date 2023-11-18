#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
class TransmitNumber{
private:
    int z;
    void CorrectLetter(int vaule){
        char letterlist[6]={'a','b','c','d','e','f'};
        if (vaule >= 0&& vaule < 10) std::cout<<vaule;
        else if (vaule <= 15 &&vaule >= 10) std::cout<<letterlist[vaule - 10];
        else MessageBox(NULL,TEXT("程序类函数内部错误：值超出阈值"),TEXT("错误"),MB_OK | MB_ICONERROR);
    }
public:
    void transale(int number){
        printf("其八进制为%o，十六进制为%x",number,number); 
    }
    void Scale_n(int number,bool mode){//mode = 1 八进制 |mode = 0 十六进制
        if(mode == true){
            if (number/8 >= 8) Scale_n(number/8,1);
            else std::cout<<number/8;
            z = number % 8 ;
            std::cout<<z;
        }
        else{
           if(number/16 >= 16) Scale_n(number/16,0);
           else CorrectLetter(number/16);
           z = number % 16;
           CorrectLetter(z);
        }
    }   

};
int main(){
    int number;
    TransmitNumber A1;
    std::cout<<"请输入一个数：";
    std::cin>>number;
    A1.transale(number);
    std::cout<<std::endl<<"八进制为";
    A1.Scale_n(number,true);
    std::cout<<std::endl<<"十六进制为";
    A1.Scale_n(number,false);
    return 0;
}
/*
n进制
函数1（数x）：
数x % n = m | if m => 10 -> 'm' is replace by letter.(char)
数x / n = z | 函数1（z） 
*/