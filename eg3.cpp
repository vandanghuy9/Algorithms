#include<iostream>

using namespace std;
const int MAX = 1e3;
int Nmax;
int n, k;
int x[11];
int Bool[MAX] = { 0 };
int A[MAX];
int S[8] = {1000, 100, 100, -100, 10, 10, 2};
int dem;
int demm;

void xuat() {
    int res = 0;
    for (int i = 1; i <= k; i++) {
        //cout << x[A[i]] << " ";
        res += S[i-1] * x[A[i]];
        //cout << S[i-1] << " ";
        //cout << res << " ";

    }
    //demm++;
    //cout << res <<" "; //<< endl;
    if (res == Nmax) {
         dem++;
        // cout << dem;
        for (int i = 1; i <= k; i++) {
         cout << x[A[i]] << " ";
         }
         cout << res << endl;
        //cout << res;
    }
       
}
 
void Try(int tg) {
    for (int i = 1; i <= k; i++) {
        if (!Bool[i]) {
            A[tg] = i; 
            Bool[i] = 1;
            if (tg == k)
                xuat();
            else
                Try(tg + 1);
            Bool[i] = 0;
        }
    }
}



void printArray(int x[], int k){
	for (int i = 1; i <= k; ++i) Bool[i] = 0;
    Try(1);
}
void dequy(int h, int k, int n){
	for (int i = x[h-1] + 1; i <= n - (k-h); i++){
		x[h] = i;
		if (h == k) printArray(x, k);
		else {
			dequy(h+1, k, n);
		}
	}
}
int main(){
    cin >> Nmax;
    Nmax = Nmax + 62;
    n = 9; k = 7;
	//cin >> n >> k;
	x[0] = 0;
    dem = 0;
    dequy(1, k, n);
    cout << dem;
    return 0;
}