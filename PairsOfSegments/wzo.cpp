#include<bits/stdc++.h>

using namespace std;

bool in(pair<int,int> a, pair<int,int> b){
    return !(a.first > b.second || a.second < b.first);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(auto &[l,r] : arr){
            cin>>l>>r;
        }
        sort(arr.begin(),arr.end()/*,[](pair<int,int> a, pair<int,int> b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        }*/);
        vector<vector<int>> dp(n,vector<int>(2,0)); 
        dp[0][0]=1;
        dp[0][1]=1e9;
        for(int i=1;i<n;++i){
           dp[i][0]=i+1;
           if(in(arr[i],arr[i-1])){
                dp[i][1]=i-1;
           }else{
                dp[i][1]=1e9;
           }
           for(int j=i-1;j>0;--j){
                if(in(arr[i],arr[j]) && (!in(arr[j-1],arr[j]))){
                    dp[i][1] = min(dp[i][1],min(dp[j-1][0],dp[j-1][1])+i-j-1);
                }
                dp[i][0] = min(dp[i][0],dp[j][1]+i-j-1);
           }
           cout<<arr[i].first<<","<<arr[i].second<<" "<<dp[i][0]<<","<<dp[i][1]<<endl;
        }
        cout<<min(dp.back()[0],dp.back()[1])<<endl;
    }

    return 0;
}