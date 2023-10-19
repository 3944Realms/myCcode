#include <stdio.h>
#include <windows.h>
#include <math.h>

int main(){    
    SetConsoleOutputCP(65001);//UTF-8
    double delt,a,b,c; //初始化变量a,b,c(方程的参数)和delt（方程的根判定式）
    printf("请输入该一元二次方程标准式的参数a,b,c的值（注意：请以空格分开输入）\n\a");
    scanf("%lf %lf %lf",&a,&b,&c);
    delt = pow(b,2) - 4*a*c ;//运算delt（方程的根判定式）
    Sleep(2000);
    printf("\n该一元二次方程为：(%lfX^2) + (%lfX) + (%lf) = 0\n\a",a,b,c);
    Sleep(2000);
    printf("\n该方程的判别式结果为：%lf\n",delt);
    Sleep(2000);
    //虚根情况
    if (delt < 0){
        printf("\n该方程的判别式delt < 0\n");
        Sleep(1000);
        double root_real,root_imag,imag;
        imag = pow(-delt,0.5);//中间量
        root_real = (-b)/(2*a);
        root_imag = imag/(2*a);
        Sleep(2000);
        printf("\n这个一元二次方程的虚根: \nroot_1 = %lf + %lfi\nroot_2 = %lf - %lfi\n",root_real,root_imag,root_real,root_imag);
    }
    //两实根情况
    else if (delt > 0){
        printf("\n该方程的判别式delt > 0\n");
        Sleep(1000);
        double root_1,root_2;
        root_1 = (-b - pow(delt,0.5)) / (2*a);
        root_2 = (-b + pow(delt,0.5)) / (2*a);
        Sleep(5000);
        printf("\n这个一元二次方程的实数根: \nroot_1 = %lf\nroot_2 = %lf\n",root_1,root_2);
    }
    //delt = 0情况
    else{
        printf("\n该方程的判别式delt = 0\n");
        Sleep(1000);
        double root = (-b) / (2*a);
        printf("\n这个一元二次方程的实数根: \nroot = %lf\n",root);
    }
    Sleep(5000);
    printf("\n程序运行结束\n\a");
    return 0;
    
    
}
