v
string a="baninn";
string b="kanin";
int mem[100][100];
string sub[100];
int m,n;
int lcs(int i, int j){
    if (j == -1 || i == -1) return 0;
    if (mem[i][j] != -1) return mem[i][j];
    int res = 0;
    if (a[i] == b[j]) 
    {
        res = max(res,1+lcs(i-1,j-1)); 
    }
    else{
        res = max(res,lcs(i,j-1));
        res = max(res,lcs(i-1,j));
    }
    mem[i][j] = res;
    return res;
}
int main(){
    memset(mem,-1,sizeof(mem));
    m = 6;
    n = 5;
    int k= lcs(m-1,n-1);
    cout << k << endl;
    int i,j,count;
    stack<char> S;
    for (i=m-1,j=n-1,count=1;count<=k;){
        if (a[i] == b[j] && mem[i][j] == 1+mem[i-1][j-1]){
            S.push(a[i]);
            count ++;
            i--;
            j--;
        }
        else if (mem[i][j] == mem[i-1][j]) {
            i--;
        }
        else if (mem[i][j] == mem[i][j-1]){
            j--;
        }
    }

    while(!S.empty()){
        cout << S.top();
        S.pop();
    }
    return 0;
}