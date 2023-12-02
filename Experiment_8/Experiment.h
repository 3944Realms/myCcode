class StringHandler{
private:
    
public:
    bool IsAvailable(int va_1,int va_2){
        if((va_1 < 2*va_2) || (va_1 <= 0) || (va_2 <= 0)) {
            std::cout<<"\n[错误]输入值不符合要求，存在非法输入,重输:";
            // MessageBox(NULL,TEXT("请重输"),TEXT("警告"),MB_ICONWARNING);
            return false;
        }else return true;
    }
    void str_gets(char str[]){
        int i = 0;
        char ch;
        while ((ch = getchar()) != 10){//输入
            str[i] = ch;
            i++;
        }
        str[i] = '\0';
    }
    void str_puts(char str[]){//输出
        int i = 0;
        while (str[i] != '\0'){
            // printf("%c",str[i]);
            putchar(str[i]);
            i++;
        }
    }
    int str_strlen(char str[]){//长度
        int i = 0;
        while (str[i] != '\0'){
            i++;
        }
        return i;
    }
    // char *str_strcat(char str1[],char str2[]){//拼接（会改变str1的值）
    //     int i = str_strlen(str1),j = 0;
    //     while (str2[j] != '\0'){
    //         str1[i] = str2[j];
    //         i++;j++;
    //     }
    //     str1[i + j - 1] = '\n';
    //     return str1;
    // }
    void str_strcat(char *str1,char *str2){
        int End_pos = str_strlen(str2) + str_strlen(str1) ;int Beg_pos = str_strlen(str1);
        for(int i = Beg_pos ; i < End_pos; i++ ){
            str1[i] = str2[i - Beg_pos];
        }
    }

    char *str_strcpy(char str1[],char str2[]){//复制（会改变str1的值）
        int i = 0;
        while(str2[i] != '\0'){
            str1[i] = str2[i];
            i++;
        }
        str1[i] = '\0';
        return str1;
    }
    short int str_strcmp(char str1[],char str2[]){//比较
        int len1 = str_strlen(str1);
        int len2 = str_strlen(str2);
        int t= len1 > len2?len1:len2;
        int i,k;
        for (i = 0;i < t;){
        k = str1[i] - str2[i];
            if (k) break;
            else i++;
        }
        if (k > 0) return 1;
        else if (k == 0) return 0;
        return -1; 
    }
    void FUN(short int Value){//将 -1，0，1 转化为文字语言 小，等，大
        if (Value > 0) std::cout<<"前者更大";
        else if(Value == 0) std::cout<<"两者相等";
        else std::cout<<"后者更大";
    }
};
class sort{
private:
void swap(int *a1,int *a2){
    int t = *a1;
    *a1 = *a2;
    *a2 = t;
}//
public:
	void qSortArray(int array[], int start, int last){
		int low = start;
		int high = last;
		int base = array[start];
		if (low < high){
			while (low < high){
				while (array[low] <= base && low < last){
					low++;//满足小于基准的条件，指针右移
				}
				while (array[high] >= base && high > start){
					high--;//满足大于基准的条件，指针左移
				}
				if (low < high){
					swap(&array[low], &array[high]);//交换两个不满足条件的元素
				}
				else{
					break;
				}
			}
			swap(&array[start], &array[high]);//插入基准元素
			qSortArray(array, start, high - 1);
			qSortArray(array, high + 1, last);
		}
	}
	void printall(int *arr,int start,int end){
		int *p = arr;
		for (int i = start ; i <= end ;i++,p++){
			std::cout<<*p<<" ";
		}
	}
	void inputElement(int *arr,int start,int end){
		int *p = arr;
		for (int i = start ; i <= end ;i++,p++){
			std::cin>>*p;
		}
	}
	int GetSum(int *arr,int start,int end){
		int sum = 0;
		int *p = arr;
		for (int i = start;i <= end;i++,p++){
			sum +=  *p;
		}
		return sum;
	}
};
