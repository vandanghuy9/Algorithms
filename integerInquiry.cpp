/*
The input will consist of at most 100 lines of text,
each of which contains a single VeryLongInteger. Each
VeryLongInteger will be 100 or fewer characters in
length, and will only contain digits (no negative)
the final input line contain a single zero on a line by itself
The output is the sum of the VeryLongIntegers given in the Input
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    char inputString[201];
    int sum[201], length;
    while (gets(inputString))
    {
        if(!strcmp(inputString, "0")) break;
        length = strlen(inputString);
        for(int i = 0, j = length - 1; i < length; i++, j--){
            sum[i] += inputString[j] - '0';
        }
    }
    //Xu ly nho
    for(int i = 0; i < 200; i++){
        if(sum[i] >= 10){
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
    //in ket qua
    int i = 200;
    while(sum[i] == 0 && i >= 0) i--;
    if(i == -1) cout << "0";
    else{
        for(; i >= 0; i--) cout << sum[i];
    }
    return 0;
}