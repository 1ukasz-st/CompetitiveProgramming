#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    vector<vector<vector<ll>>> cntb(1000001,vector<vector<ll>>(7,vector<ll>(7,0LL)));
    for(ll aa=1LL;aa<=1000000LL;++aa){
        ll minc=1LL;
        ll maxc=9LL;
        for(ll cc=1LL;cc<=6LL;++cc){
            ll roz = max(0LL,minc-aa);
            ll ileb=9LL;
            for(ll bb=1LL;bb<=6LL;++bb){
                if(int(log10(10*roz - 1)) <= bb){
                    cnt[aa][cc][bb] = ileb;
                } 
                ileb*=10LL;
                ileb+=9LL;
            }
            minc*=10LL;
            maxc*=10LL;
            maxc+=9LL;
        }
    }

    int t=0;
    cin>>q;
    while(t--){
        int a=0,b=0,c=0;
        ll k=0LL;
        cin>>a>>b>>b>>k;
        if(c-b>=2){
            cout<<"-1"<<endl;
            continue;
        }
        string A="";
        ll kc=1LL;
        for(int i=0;i<a;++i){
            for(int d=int(i>0);d<9;++d){
                
                kc +=  
            }
        }
    }

}