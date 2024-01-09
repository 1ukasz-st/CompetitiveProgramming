#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        ll k=0LL;
        cin>>n>>k;
        vector<ll> t(n);
        for(int i=0;i<n;++i){
            ll x=0LL;
            cin>>x;
            x = (k-(x%k))%k;
            t[i] = x;
        }
        sort(t.begin(),t.end());
        int start=0;
        while(start<n && t[start]==0){++start;}
        if(start>=n){
            cout<<0<<endl;
            continue;
        }
        ll maxC=1,val=t[start],currC=1,currVal=t[start];
        for(int i=start+1;i<n;++i){
            if(t[i]!=t[i-1]){
                if(currC > maxC){
                    maxC = currC;
                    val = currVal;
                }else if(currC==maxC){
                    val = max(val,currVal);
                }
                currVal=t[i];
                currC=1;
            }else{
                ++currC;
            }
        }
        if(currC > maxC){
            maxC = currC;
            val = currVal;
        }else if(currC==maxC){
            val = max(val,currVal);
        }
        cout<<k*(maxC-1LL) + val + 1<<endl;
    }


    return 0;
}