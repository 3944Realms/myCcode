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
        else MessageBox(NULL,TEXT("�����ຯ���ڲ�����ֵ������ֵ"),TEXT("����"),MB_OK | MB_ICONERROR);
    }
public:
    void transale(int number){
        printf("��˽���Ϊ%o��ʮ������Ϊ%x",number,number); 
    }
    void Scale_n(int number,bool mode){//mode = 1 �˽��� |mode = 0 ʮ������
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
    std::cout<<"������һ������";
    std::cin>>number;
    A1.transale(number);
    std::cout<<std::endl<<"�˽���Ϊ";
    A1.Scale_n(number,true);
    std::cout<<std::endl<<"ʮ������Ϊ";
    A1.Scale_n(number,false);
    return 0;
}
/*
n����
����1����x����
��x % n = m | if m => 10 -> 'm' is replace by letter.(char)
��x / n = z | ����1��z�� 
*/