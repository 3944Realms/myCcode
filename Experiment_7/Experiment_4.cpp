#include <iostream>
#include <stdio.h>
#define N 20
//只能处理奇数次
class Marxial{
public:
/*
1.第一个数字写在第一行的中间
2.下一个数字，都写在上一个数字的右上方：
    a.如果该数字在第一行，则下一个数字写在最后一行，列数为该数字的右一列
    b.如果该数字在最后一列，则下一个数字写在第一列，行数为该数字的上一行
    c.如果该数字在右上角，或者该数字的右上方已有数字，则下一个数字写在该数字的下方
*/
    void MagicBox(int n,int a[N - 1][N - 1]){
        int LinePin,ListPin;
        if (n % 2 == 1) LinePin =  0,ListPin = n/2;
        else LinePin = 0,ListPin = 0;
        a[LinePin][ListPin] = 1;
        for (int num = 2; num <= (n)*(n);num++){
            LinePin -= 1;
            ListPin += 1;
            if(LinePin == -1 && ListPin == n){//c.数字在右上角
                LinePin += 2;ListPin -= 1;
            }
            else if (ListPin == n && LinePin == 0) ListPin = 0;
            else if (LinePin == -1) LinePin = n - 1;//a.如果该数字在第一行，则下一个数字写在最后一行，列数为该数字的右一列  
            else if (ListPin == n ) ListPin = 0;//b.如果该数字在最后一列，则下一个数字写在第一列，行数为该数字的上一行
            if (a[LinePin][ListPin] == 0){
                a[LinePin][ListPin] = num;
            }
            else {
                LinePin += 2;
                ListPin -= 1;
                a[LinePin][ListPin] = num;//或者该数字的右上方已有数字，则下一个数字写在该数字的下方
            } 
        }
    }
    void show(int n,int a[N - 1][N - 1]){
        for (int i = 0;i <= n - 1;i++){
           for(int j = 0; j <= n - 1;j++){
                printf("%5d",a[i][j]);
           }
           std::cout<<"\n\n"; 
        }
    }
};

int main(){
    int n;
    Marxial obj;
    std::cin>>n;
    int MagBox[N - 1][N - 1] = {0};
    obj.MagicBox(n,MagBox);
    obj.show(n,MagBox);
    return  0;
}
/*
     0   1   2   3   4   5   6  list

0    0   0   0   0   0   0   0

1    0   0   0   0   0   0   0

2    0   0   0   0   0   0   0

3    0   0   0   0   0   0   0

4    0   0   0   0   0   0   0

5    0   0   0   0   0   0   0

6    0   0   0   0   0   0   0

line
*/