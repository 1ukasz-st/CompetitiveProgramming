#include<bits/stdc++.h>


using namespace std;


int main(){

    int t=0;
    cin>>t;
    while(t--){
        int  n=0,k=0,x=0;
        cin>>n>>k>>x;
        vector<pair<bool,vector<int>>> dp(n+1,{0,vector<int>()});
        dp[0]={1,{}};
        for(int i=1;i<=n;++i){
            for(int j=1;j<=k && j<=i;++j){
                if(j!=x && dp[i-j].first == 1){
                    dp[i] = dp[i-j];
                    dp[i].second.push_back(j);
                    break;
                }
            }
        }
        if(dp[n].first==1){
            cout<<"YES\n"<<dp[n].second.size()<<"\n";
            for(int x : dp[n].second){
                cout<<x<<" ";
            }
        }else{
            cout<<"NO";
        }
        cout<<"\n";        
    }


    return 0;
}