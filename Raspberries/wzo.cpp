#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q=0;
    cin>>q;
    while(q--){
        int n=0,k=0;
        cin>>n>>k;
        vector<int> t(n);
        for(int &x : t){
            cin>>x;
        }
        int ans=1e9;
        if(k==4){
            int countEven=0;
            for(int x : t){
                if(x%4==0){
                    countEven+=2;
                }
                if(x%2==0){
                    ++countEven;
                }
                int nxt = int((x+k-1)/k)*k;
                ans = min(ans,nxt-x);
            }
            ans = min(ans,max(0,2-countEven));
        }else{
            for(int x : t){
                int nxt = int((x+k-1)/k)*k;
                //cout<<x<<" -> "<<nxt<<endl;
                ans = min(ans,nxt-x);
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}