#include <iostream>
#include <stdio.h>
#define N 20
//ֻ�ܴ���������
class Marxial{
public:
/*
1.��һ������д�ڵ�һ�е��м�
2.��һ�����֣���д����һ�����ֵ����Ϸ���
    a.����������ڵ�һ�У�����һ������д�����һ�У�����Ϊ�����ֵ���һ��
    b.��������������һ�У�����һ������д�ڵ�һ�У�����Ϊ�����ֵ���һ��
    c.��������������Ͻǣ����߸����ֵ����Ϸ��������֣�����һ������д�ڸ����ֵ��·�
*/
    void MagicBox(int n,int a[N - 1][N - 1]){
        int LinePin,ListPin;
        if (n % 2 == 1) LinePin =  0,ListPin = n/2;
        else LinePin = 0,ListPin = 0;
        a[LinePin][ListPin] = 1;
        for (int num = 2; num <= (n)*(n);num++){
            LinePin -= 1;
            ListPin += 1;
            if(LinePin == -1 && ListPin == n){//c.���������Ͻ�
                LinePin += 2;ListPin -= 1;
            }
            else if (ListPin == n && LinePin == 0) ListPin = 0;
            else if (LinePin == -1) LinePin = n - 1;//a.����������ڵ�һ�У�����һ������д�����һ�У�����Ϊ�����ֵ���һ��  
            else if (ListPin == n ) ListPin = 0;//b.��������������һ�У�����һ������д�ڵ�һ�У�����Ϊ�����ֵ���һ��
            if (a[LinePin][ListPin] == 0){
                a[LinePin][ListPin] = num;
            }
            else {
                LinePin += 2;
                ListPin -= 1;
                a[LinePin][ListPin] = num;//���߸����ֵ����Ϸ��������֣�����һ������д�ڸ����ֵ��·�
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