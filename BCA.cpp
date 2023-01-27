#include <iostream>
#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;
int n,m,A[100][100],load[100],res,con;
// n: course num
// m: teacher num
int c[100][100];
bool visited[100];
vector<int,int> conflictCourse;
int f=0;
void Try (int k){
    for (int i=2;i<n;i++){
        if (visited[i] == 0){
            x[k] = i;
            visited[i] = 1;
            f += c[x[k-1]][x[k]];
        }
    }
} 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}