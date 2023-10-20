#include <stdio.h>
#include <windows.h>
int main(){
    //控制台默认使用GBK编码，需要转UTF-8编码
    SetConsoleOutputCP(65001);
    int month,year,day,goneday,TOF;
    int Month_Day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    //这里的序列号= 月份 
    printf("请依次输入年份 月份 日份（以空格间隔开）：");
    scanf("%d %d %d",&year,&month,&day);
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
        printf("\n[ERROR] 日份输入错误，请重输入\n日份：");
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
            printf("\n[ERROR] 对应月份日份输入错误，请重输入\n日份：");
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
            printf("\n[ERROR] 对应月份日份输入错误，请重输入\n日份：");
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
            printf("\n[ERROR] 对应月份日份输入错误，请重输入\n日份：");
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
            printf("\n[ERROR] 对应月份日份输入错误，请重输入\n日份：");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }         
    }


    printf("\n[INFO] %d.%d的天数为%d",year,month,Month_Day[month]);
    goneday = day;
    for(int i = month ;i > 0;i--){
        goneday = goneday + Month_Day[i-1];
    } 
    Sleep(500);
    printf("\n\n[INFO] %d.%d.%d这是该年的第%d天",year,month,day,goneday);
    return 0; 
}
