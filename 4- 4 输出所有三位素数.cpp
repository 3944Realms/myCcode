#include <iostream>
using namespace std;
int main(){
    int i,n,flag = 1,count = 0;//flag 是判断符
    for (i = 100;i < 1000; i++){
        for(n = 2; n <= (i/2);n++){
            if (i % n == 0){
                flag = 1;
                break;
            }
            else {
                flag = 0;
            }
          
        }
            if (flag == 0){
            count ++;
            cout<<i<<" ";
            if (count % 10 == 0) cout<<endl;//每十个一换行
            flag = 1;
            }

    }
    return 0;
}
// 897 448.5 -> 448  2~448
