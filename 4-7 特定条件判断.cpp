#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(65001);//UTF-8
    int m ,k,count= 0;
E_O_1:
    cout<<"请输入m（1，10000）和k（1，5）的值： ";
    cin>>m>>k;
    if (!(((1 < m)&&(m < 10000))&&((1 < k)&&(k < 5))))
    {
        cout<<"输入有误，请注意吗m和k的范围"<<endl;
        goto E_O_1;
    }
    else{
        if (m % 19 == 0){
           for(;m;m /= 10){
              if(m % 10 == 3) count++;  
           }
           if (k == count) cout<<"YES";
           else cout<<"NO";     
        }else cout<<"NO";
        
    }
    return 0;                                                                                             
}
