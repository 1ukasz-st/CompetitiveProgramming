#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        vector<int> t(n);
        vector<vector<int>> dp(n,vector<int>(2));
        for(int &x : t){
            cin>>x;
        }
        dp[n-1][0] = (t[n-1]==0 ? 0 : 1);
        dp[n-1][1] = 1;
        for(int i=n-2;i>=0;--i){
            dp[i][1] = min(dp[i+1][0],dp[i+1][1])+1;
            int jump = i+t[i]+1;
            if(jump == n){
                dp[i][0] = 0;
            }else if(jump <= n-1){
                dp[i][0] = min(dp[jump][0],dp[jump][1]);
            }else{
                dp[i][0] = n-i;
            }
        }
        cout<<min(dp[0][0],dp[0][1])<<endl;
    }
}