#include <iostream>
int main(){
    int Marxial[5][5] = {0};
    int LineMax[5],ListMin[5],count = 0;
    for (int i = 0 ; i <= 25 -1; i++) std::cin>>Marxial[0][i];
    for (int listORline = 0 ; listORline <= 4; listORline++){
        int max = Marxial[listORline][0];
        for(int line = 1; line <= 4; line++){//ÊäÈë
            if(max < Marxial[listORline][line]) max = Marxial[listORline][line];
        }
        LineMax[listORline] = max;
        int min = Marxial[0][listORline];
        for(int list = 1; list <= 4; list++){
            if(min > Marxial[list][listORline]) min = Marxial[list][listORline];
        }
        ListMin[listORline] = min;
    }
    for (int List = 0; List <= 4; List++){
        for(int Line = 0; Line <= 4; Line++){
            if(LineMax[Line] == ListMin[List]){ count++;std::cout<<Line + 1<<" "<<List + 1<<" "<<LineMax[Line]<<std::endl;}
        }
    }
    if (count == 0) std::cout<<"not found";
    return 0;
}
// int anPolt(int *array){

// }
/*
8     3    4    6    2
I     II   III  IV   V    list/line
11    3    5    6    9  i   11
12    4    7    8   10  ii  12
10    5    6    9   11  iii 10
 8    6    4    7    2  iv  8
15   10   11   20   25  v   25

I-i(max)[I-iv(min)] X -> I-ii(max)[I-iv(min)] X -> V-iii(max)[V-iv(min)] X -> I-iv(max)[I-iv(min)] ÊÇµÄ
*/