#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    double sum;
    cin>>n;
    for (int i = 1; i <= n;i++){
        sum += pow(-1,(double)(i-1)) * ((double)((2*i - 1)*(2*i + 1)) / pow((double)i*2,2.0));
    }
    cout<<sum;
    return 0;
}
