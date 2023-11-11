#include <iostream>
#include <windows.h>
using namespace std;
void Fun(int number);
int main(){
    SetConsoleOutputCP(65001);//UTF-8
    //定义变量
    int number;
    cout<<"输入数字（输入的数字属于[2,10000])：";
Point_1:
    cin>>number;
    if (!(number <= 10000 && number >= 2)) {
        cout<<"输入有误"<<endl<<"请重输（输入的数字属于[2,10000])：";
        goto Point_1;
    }
    Fun(number);
    return 0;
}
void Fun(int number){
    #define XLength (number/2)+2
    int XArray[XLength] = {0};//因数表
    int XPin = 0;
    for(int i = 2;i <= (number/2);i++){
        if (number % i == 0){
            XArray[XPin] = i;
            XPin++;
        }
    }
    #define Length (number+1)//质数表
    int PrimeNumber[Length] = {0};
    int ArrPin = 0;
    for (int Pin = 2; Pin <= number; Pin++){
        int flag = 1;
        for(int i = 2;i < Pin; i++){
            if (Pin % i == 0){
                flag --;
                break;
            }
        }
        if (flag == 1) {
            PrimeNumber[ArrPin] = Pin;
            ArrPin++;
        }
    }
    int NewArray[XLength+2]={0};
    int Helper_1 = 0,Helper_2 = 0;
    for(int i = 2;i <= XLength;i++){
        for(int j = Helper_1;j <= XLength;j++ ){
            if(PrimeNumber[j] == i) {
                NewArray[i]++;
                Helper_1 = j;
                break;
            }else if(PrimeNumber[j] > i) break;
        }
            
         for(int j = Helper_2;j <= XLength;j++ ){
            if(XArray[j] == i) {
                NewArray[i]++;
                Helper_2 = j;
                break;
            }else if(XArray[j] > i) break;
         }
    }
    int Line = 0;
    for(int i = 2;i <= XLength;i++){
        if (NewArray[i-1] == 2 && Line == 0) {cout<<i-1;Line++;}
        else if (NewArray[i-1] == 2 && Line != 0)cout<<","<<i-1;
    }
}
// void Function(int number){
// }
//检查质数（1~10000）
// int PrimeNumber(int StartNumber,int EndNumber){
//     #define Length (EndNumber - StartNumber +1);
//     int PrimeNumber[Length];
//     int ArrPin = 0;
//     for (int Pin = StartNumber; Pin <= EndNumber; Pin++){
//         int flag = 1;
//         for(int i = 2;i < Pin; i++){
//             if (Pin % i == 0){
//                 flag --;
//                 break;
//             }
//         }
//         if (flag == 1) {
//             PrimeNumber[ArrPin] = Pin;
//             ArrPin++;
//         }
//     }
// }