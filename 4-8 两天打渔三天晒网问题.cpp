#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
int year_NDay(int year);//自定义函数，求出某年的总天数
int year_day(int year,int month,int day);//自定义函数，求出某年具体一天距离这年的1.1的天数
int main(){
    //控制台默认使用GBK编码，需要转UTF-8编码
    SetConsoleOutputCP(65001);
    int month,year,day;
BACK:
    int day_1,sum = 0;
    cout<<"请依次输入年份 月份 日份（以空格间隔开）：";
    scanf("%d %d %d",&year,&month,&day);
MainCheckPoint_year:
    if (year < 1990){
        printf("\n\a[ERROR] 年份输入错误，请输入大于等于1990年的年份\n年份:");
        scanf("%d",&year);
        goto MainCheckPoint_year;
    }
    day_1 = year_day(year,month,day);
    sum += day_1;
    for (int year_1 = year - 1;year_1 >= 1990;year_1 --){
        sum += year_NDay(year);
    }
    Sleep(500);
    printf("\n[INFO] 距1990.1.1日过去了%d天",sum);
    cout<<endl;
    Sleep(500);
    int leftday = sum % 5 ;//不难发现5天一周期，只需判断总天数处于余数
    if ((leftday > 0)&&(leftday <= 3)) printf("\n[INFO] 打渔");
    else printf("\n[INFO] 晒网");
    printf("\n");
    cout<<"\n[SYSTEM] 继续,如退出请Ctrl+C\a";
    printf("\n");
    goto BACK;
    return 0;
}
int year_day(int year,int month,int day){
    int goneday,TOF;
    int Month_Day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    //这里的序列号= 月份 
    ((year % 400 == 0) && (year % 4 == 0 ||year % 400 != 0))? Month_Day[1] = 29 :Month_Day[1] = 28 ;
    //判断是平年还是闰年
Checkpoint_1:
    if ((month > 0 && month < 13) ){
        printf("\n[INFO] 月份输入无误\n");
        Sleep(500);
    }
    else{
        printf("\n[ERROR] 月份输入错误，请重输入\n月份：");
        scanf("%d",&month);
        Sleep(500);
        goto Checkpoint_1;
    }
Checkpoint_2:
    if (day < 32 && day > 0){
        printf("\n[INFO] 日份输入无误\n");
        Sleep(500);
    }
    else{
        printf("\n\a[ERROR] 日份输入错误，请重输入\n日份：");
        scanf("%d",&day);
        Sleep(500);
        goto Checkpoint_2;
    }    
    if ((year % 400 == 0) && (year % 4 == 0 ||year % 400 != 0)){
        printf("\n[INFO] 该年（%d）是闰年\n",year);
        TOF = 1; // 闰/平 判断变量 = 1 ——》闰
        Sleep(500);
    }
    else{
        printf("\n[INFO] 该年（%d）是平年\n",year);
        TOF = 0;// 闰/平 判断变量 = 0 ——》平
        Sleep(500);
    }
Checkpoint_3:
    if(month == 1 ||month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12){
            if (day < 32 && day > 0){
            printf("\n[INFO] 对应月份日份输入无误\n");
            Sleep(500);
        }
        else{
            printf("\n\a[ERROR] 对应月份日份输入错误，请重输入\n日份：");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }    
    }
    else if (month == 2 && TOF == 1){
        if (day < 30 && day > 0){
            printf("\n[INFO] 对应月份日份输入无误\n");
        }
        else{
            printf("\n\a[ERROR] 对应月份日份输入错误，请重输入\n日份：");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }    
    }
    else if(month == 2 && TOF == 0){
        if (day < 29 && day > 0){
            printf("\n[INFO] 对应月份日份输入无误\n");
            Sleep(500);
        }
        else{
            printf("\n\a[ERROR] 对应月份日份输入错误，请重输入\n日份：");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }  
    }
    else{
        if (day < 31 && day > 0){
            printf("\n[INFO] 对应月份日份输入无误");
            Sleep(500);
        }
        else{
            printf("\n\a[ERROR] 对应月份日份输入错误，请重输入\n日份：");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }         
    }
    goneday = day;
    for(int i = month ;i > 0;i--){
        goneday += Month_Day[i-1];
    } 
    return goneday; 
}
int year_NDay(int year){
    if ((year % 400 == 0) && (year % 4 == 0 ||year % 400 != 0)) return 366;//如果是闰年
    else return 365;//如果是平年
}
