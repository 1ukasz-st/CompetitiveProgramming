#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        vector<ll> t(n);
        vector<vector<ll>> dp(n+1,vector<ll>(2));
        for(ll &x : t){
            cin>>x;
        }
        ll ans=0LL;
        for(int i=n-1;i>=0;--i){
            if((i+1)&1){
                dp[i][0] = max({t[i],0LL,dp[i+1][1]+t[i],dp[i+1][0]+t[i]});
                dp[i][1] = max({0LL,dp[i+1][1],dp[i+1][0]});
            }else{
                dp[i][0] = max({0LL,dp[i+1][0],dp[i+1][1]});
                dp[i][1] = max({t[i],0LL,dp[i+1][0]+t[i],dp[i+1][1]+t[i]});
            }
            ans = max(ans,dp[i][0]);
        }
        cout<<ans<<endl;
    }

    return 0;
}