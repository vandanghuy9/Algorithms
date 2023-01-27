#include <windows.h>
#include <stdio.h>
#include <iterator>
#include <map>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stringfwd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int x = 2;int y = 3;int t1=0,t2=0,t3=0;
HANDLE S1, S2;
void T1();
void T2();
void T3();
int main(){
     HANDLE h1, h2,h3;
     DWORD ThreadId;

//     S1 = CreateSemaphore( NULL,0,1, NULL);
//     S2 = CreateSemaphore( NULL,0,1, NULL);
    h1 = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)T1, NULL, 0, &ThreadId);
    h2 = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)T2, NULL, 0, &ThreadId);
    WaitForSingleObject(h2, INFINITE);
    WaitForSingleObject(h1, INFINITE);
    // getch();
     return 0;
}
void T1(){
     while(1)
     {
          // t1 = x+y;
          // int t4 = t1*t2;
          // int kq = t4 * t3;
          // printf("%d ",kq);
     		//printf("T1");

          // WaitForSingleObject(S1, INFINITE);
          x = y + 1;     
          // ReleaseSemaphore(S2, 1, NULL);
          printf("%d ",x);

          //if(x<y||x>=y+5)
          //if(x-y==4)
          	//printf("%5d",x-y);
     }
}
void T2(){
     while(1)
     {
     	//printf("T2");

     	y = 2; 
          // ReleaseSemaphore(S1, 1, NULL);
          // WaitForSingleObject(S2, INFINITE);
           y = y * 2;

     //    ReleaseSemaphore(S1, 1, NULL);
     	//WaitForSingleObject(S1, INFINITE);
		//printf("Y++"); 
     }
}

void T3(){
     while (1){
          t3 =x/y;
     }
}