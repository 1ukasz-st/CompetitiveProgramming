#include<bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> a){
    vector<int> prev(n+2,n+1), dp(n+2,0);
    dp[n+1] = -1000000000;
    for(int i=1;i<=n;++i){
        dp[i] = max({dp[i-1],dp[prev[a[i-1]]]+i-prev[a[i-1]],i-prev[a[i-1]]+1 + dp[prev[a[i-1]]-1]});
        prev[a[i-1]] = i;
    }
    return dp[n];
}


int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        vector<int> a(n);
        for(int &x : a){
            cin>>x;
        }
        cout<<solve(n,a)<<"\n";
    }

    return 0;
}