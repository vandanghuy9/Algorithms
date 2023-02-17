#include<bits/stdc++.h>

using namespace std;

// Competitve Progaming 3 / 74
// int row[8], TC, a, b, lineCounter; // ok to use global variables

// bool place(int r, int c) {
//     for (int prev = 0; prev < c; prev++) // check previously placed queens
//         if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
//             return false; // share same row or same diagonal -> infeasible
//         return true; 
// }


// void backtrack(int c) {
//     if (c == 8 && row[b] == a) { // candidate sol, (a, b) has 1 queen
//         printf("%2d %d", ++lineCounter, row[0] + 1);
//     for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
//     printf("\n"); }
//     for (int r = 0; r < 8; r++) // try all possible row
//         if (place(r, c)) { // if can place a queen at this col and row
//             row[c] = r; backtrack(c + 1); // put this queen here and recurse
//         } 
//     }

// int main() {
//     scanf("%d", &TC);
//     while (TC--) {
//         scanf("%d %d", &a, &b); a--; b--; // switch to 0-based indexing
//         memset(row, 0, sizeof row); lineCounter = 0;
//         printf("SOLN COLUMN\n");
//         printf(" # 1 2 3 4 5 6 7 8\n\n");
//         backtrack(0); // generate all possible 8! candidate solutions
//         if (TC) printf("\n");
//     }
//     return 0;
// } // return 0;

int n, dem;
int a[20];

void GhiNhan(){
    dem++;
    cout << dem << ") ";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

bool UCVh(int j, int k){
    for(int i = 1; i < k; i++){
        if((j == a[i]) || (fabs(j - a[i]) == k - i)) return false;
    }
    return true;
}

void TRY(int k){
    for(int j = 1; j <= n; j++){
        if(UCVh(j ,k)){
            a[k] = j;
            if(k == n) GhiNhan();
            else TRY(k + 1);
        }
    }
}

int main(){
    cout << "Nhap kich thuoc ban co: ";
    cin >> n;
    dem = 0;
    TRY(1);
    if(dem == 0) cout << "Khong co cach xep!\n";
    return 0;
}