#include <stdio.h>
#include <iostream>
#include <windows.h>
int year_day(int year,int month,int day);
int main(){
    int xyear,xmonth,xday;
    std::cout<<"[System] ������������� �·� �շݣ��Կո���������";
    std::cin>>xyear>>xmonth>>xday;
    std::cout<<"\n[System] ����������ĵ�"<<year_day(xyear,xmonth,xday)<<"��";
    MessageBox(NULL,TEXT("�������н���"),TEXT("����"),MB_OK | MB_ICONSTOP);
    return 0;
}
int year_day(int year,int month,int day){
    int goneday,TOF;
    int Month_Day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    //��������к�= �·� 
    ((year % 400 == 0) && (year % 4 == 0 ||year % 400 != 0))? Month_Day[1] = 29 :Month_Day[1] = 28 ;//��Ŀ�����
    //�ж���ƽ�껹������
Checkpoint_1:
    if ((month > 0 && month < 13) ){
        printf("\n[INFO] �·���������\n");
        Sleep(500);
    }
    else{
        printf("\n[ERROR] �·����������������\n�·ݣ�");
        scanf("%d",&month);
        Sleep(500);
        goto Checkpoint_1;
    }
Checkpoint_2:
    if (day < 32 && day > 0){
        printf("\n[INFO] �շ���������\n");
        Sleep(500);
    }
    else{
        printf("\n\a[ERROR] �շ����������������\n�շݣ�");
        scanf("%d",&day);
        Sleep(500);
        goto Checkpoint_2;
    }    
    if ((year % 400 == 0) && (year % 4 == 0 ||year % 400 != 0)){
        printf("\n[INFO] ���꣨%d��������\n",year);
        TOF = 1; // ��/ƽ �жϱ��� = 1 ��������
        Sleep(500);
    }
    else{
        printf("\n[INFO] ���꣨%d����ƽ��\n",year);
        TOF = 0;// ��/ƽ �жϱ��� = 0 ������ƽ
        Sleep(500);
    }
Checkpoint_3:
    if(month == 1 ||month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12){
            if (day < 32 && day > 0){
            printf("\n[INFO] ��Ӧ�·��շ���������\n");
            Sleep(500);
        }
        else{
            printf("\n\a[ERROR] ��Ӧ�·��շ����������������\n�շݣ�");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }    
    }
    else if (month == 2 && TOF == 1){
        if (day < 30 && day > 0){
            printf("\n[INFO] ��Ӧ�·��շ���������\n");
        }
        else{
            printf("\n\a[ERROR] ��Ӧ�·��շ����������������\n�շݣ�");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }    
    }
    else if(month == 2 && TOF == 0){
        if (day < 29 && day > 0){
            printf("\n[INFO] ��Ӧ�·��շ���������\n");
            Sleep(500);
        }
        else{
            printf("\n\a[ERROR] ��Ӧ�·��շ����������������\n�շݣ�");
            scanf("%d",&day);
            Sleep(500);
            goto Checkpoint_3;
        }  
    }
    else{
        if (day < 31 && day > 0){
            printf("\n[INFO] ��Ӧ�·��շ���������");
            Sleep(500);
        }
        else{
            printf("\n\a[ERROR] ��Ӧ�·��շ����������������\n�շݣ�");
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