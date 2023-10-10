#include<bits/stdc++.h>

using namespace std;

bitset<1<<20> dp;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int q=0;
    cin>>q;
    while(q--){
        dp &= 0;
        int w=0,f=0,n=0,sum=0;
        cin>>w>>f>>n;
        if(w>f){
            swap(w,f);
        }
        vector<int> s(n);
        for(int &si : s){
            cin>>si;
            sum += si;
        }
        dp[0]=1;
        for(int si : s){
            for(int total=sum-si;total>=0;--total){
                dp[total+si] = dp[total+si] || dp[total];
            }
        }
        int ans=1e9;
        for(int sa=0;sa<=sum;++sa){
            if(dp[sa] == 1){
                int t1 = (sa+w-1)/w, t2 = (sum-sa+f-1)/f;
                ans = min(ans,max(t1,t2));
            }
           // cout<<i<<" "<<dp[i]<<endl;
        }  //cout<<endl;      
        cout<<ans<<endl;
    }

    return 0;
}