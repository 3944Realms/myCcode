#include <stdio.h>
#include <windows.h>
#define PrefectPoint 14150
int menu(int GamePoint , int RemainedBullet ,int GOON_1);
int main(){
    //UTF-8
    SetConsoleOutputCP(65001);
    //设变量
    int GamePoint ,RemainedBullet;
    //假设你得了1415分，剩余弹药10
    GamePoint = 1415;
    RemainedBullet = 10;
    int GOON_1 = 1;
    do {
        GOON_1 = menu(GamePoint ,RemainedBullet,GOON_1);//void函数里的值并不会返回
    } while (GOON_1);
    return 0;
}
int menu(int GamePoint , int RemainedBullet,int GOON_1){
    int Choose;
    GOON_1 = GOON_1;
    float GameAccuracy = ((float)GamePoint/PrefectPoint)*100;
    printf("\n");
    printf("\
    ***********************************************\n\
    *              打飞机游戏<V1.0>               *\n\
    *-------------------------------------------==*\n\
    *  1.开始游戏      2.游戏道具     3.设置      *\n\
    *  4.我的记录      5.关于作者     6.退出      *\n\
    *-------------------------------------------==*\n\
    ***********************************************\n\
    *              >上一个游戏记录<               *\n\
    *-------------------------------------------==*\n\
    *                                             *\n\
    *    得分：%d | 剩余弹药：%d |命中率：%3.1f%% *\n\
    *                                             *\n\
    ***********************************************\n\
                     请选择（1-6） "\
    ,GamePoint,RemainedBullet,GameAccuracy); //换行
    printf("\n输入：");
    scanf("%d",&Choose);
    Sleep(500);
    switch (Choose) {
        case 1 : printf("\n我还不会，以后再写awa\nqwp");Sleep(500);GOON_1 = 1;break;
        case 2 : printf("\n* 空气X10");Sleep(1000);GOON_1 = 1;break;
        case 3 : printf("\n设置？我游戏逻辑还不会写，怎么可能会有设置qwp");Sleep(1000);GOON_1 = 1;break;
        case 4 : printf("\n其实上一游戏记录是骗你的，你根本没有记录awa");Sleep(1000);GOON_1 = 1;break;
        case 5 : printf("\n作者：");Sleep(400);printf("R3944Realms");Sleep(400);GOON_1 = 1;break;
        case 6 : printf("\n已退出");GOON_1 = 0;break;
        default : printf("。。。\n");Sleep(500);printf("【灵魂拷问】你按要求输入了吗？？？\n\a");Sleep(500);printf("【灵魂拷问】你按要求输入了吗？？？\n\a");Sleep(500);printf("【灵魂拷问】你按要求输入了吗？？？\n\a");GOON_1 = 1;break;
    }
    return GOON_1;
}