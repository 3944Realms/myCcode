#include <math.h>
#include <stdio.h>
#include <windows.h>
//预加载定义
#define MAX(a,b) ( (a) >= (b) ? (a) : (b) )
#define MIN(a,b) ( (a) >= (b) ? (a) : (b) ) 
int main(){
//控制台默认使用GBK编码，需要转UTF-8编码
    SetConsoleOutputCP(65001);
//定义变量 三角形的三条边长度a,b,c
    double a ,b ,c;
    double min,max,mid;
plot_1:
    printf("请按空格分开输入三角形的三条边：");
    scanf("%lf %lf %lf",&a,&b,&c);
    Sleep(500);
    if ( a > 0 && b > 0 && c>0){ //防呆设计
        printf("\n[INFO] 输入的值符合要求\n");
    }
    else{
        printf("\n[ERROR] 输入的值不符合要求\n\a");
        goto plot_1;//纠错重输入
    }
    //程序体-判断并赋予最大 最小 中值 值
    if (MAX(a,b) == MAX(a,c)){
        max = a;
        min = MIN(b,c);
        mid = MAX(b,c);
    }
    else if (MAX(b,a) == MAX(b,c)){
        max = b;
        min = MIN(a,c);
        mid = MAX(a,c);
    }
    else if (MAX(c,a) == MAX(c,b)){
        max = c;
        min = MIN(a,b);
        mid = MAX(a,b);
    }
    else{ 
        printf("\n程序逻辑错误，请检查输入是否错误\a");
        return 0;
    }
    Sleep(500);
    //判断是否构成三角形
    if ( (min + max) > mid && (max - min) < mid ){
        printf("\n[INFO] Y该三边能够构成三角形\n\a");
    }
    else{
        printf("\n[INFO] N该三边不能够构成三角形\n\a");
    }

    return 0;
}


//已废弃部分代码

/*    switch (a >= b && b >= c){
        case 1: max = a; min = c; 
            break;

        default: 
            break;
    }
    switch (b > a && a > c)
    {
    case 1: max = b; min = c; 
        break;
    
    default:
        break;

    }
    switch ()
    {
    case 1:
        int max = a;min = b;
        break;
    
    default:
        break;
    }
*/
