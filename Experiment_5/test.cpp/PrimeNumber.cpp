#include <iostream>
using namespace std;
int PrimeNumber(int StartNumber,int EndNumber){
    #define Length (EndNumber - StartNumber +1);
    int PrimeNumber[Length];
    int ArrPin = 0;
    for (int Pin = StartNumber; Pin <= EndNumber; Pin++){
        int flag = 1;
        for(int i = 2;i < Pin; i++){//[2,Pin)
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
    return ;
}
int main(){
    int primeNumber[] = PrimeNumber(2,10000);
    //待定
}