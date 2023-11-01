#include <iostream>
#include <windows.h>
#define MAX(a,b) ((a >= b)? a : b)//宏定义无需给参数声明类型
#define MIN(a,b) ((a >= b)? b : a)
using namespace std;
int main(){
    SetConsoleOutputCP(65001);//UTF-8
    int x, y ,max ,min;
    cout<<"请输入要求最大公约数和最小公倍数的两个值：";
    cin>>x>>y;
    //求x,y之间的最大公约数
    //方法一，辗转相除法
    max = MAX(x,y);
    min = MIN(x,y);
    int value_1,value_2;
    while(max % min != 0){
        value_1 = max,value_2 = min;
        min = value_1 % value_2;
        max = value_2;
    }
    //
    cout<<"这两个数的最大公约数为"<<min<<endl;
    cout<<"这两个数的最小公倍数为"<<(x*y)/min;
    return 1;
}
