#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int a[1000];
int mem[1000];
bool comp[1000];

int findIndex(int i){
    int a = 1;
    int b = 1;
    int k;
    while (k < i){
        int tmp = b;

    }

}
/*
max_sum(i) = max(max_sum(i-1) + ai , ai);
*/
int max_sum(int i){
    if (i == 1) return a[i];
    if (comp[i] ) return mem[i];
    int res = max(a[i],a[i]+max_sum(i-1));
    
}
int main(){
    for (int i=0;i<1000;i++){
        comp[i] = false;
    }


}