#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Q;

const int N = (5e3)+3;
 
ll F[N+3];
 
ll pw(ll base, ll power){
    ll res=1LL;
    while(power>=1){
        if(power&1){
            res=(res*base)%Q;
            --power;
        }
        base=(base*base)%Q;
        power>>=1;
    }
    return res;
}
 
ll newt(ll n, ll k){
    if(n<0){
        return 0LL;
    }
    return (F[n]*pw((F[k]*F[n-k])%Q,Q-2))%Q;
}

int main(){

    ll n=0LL;
    cin>>n;
    cin>>Q;

    F[0]=1LL;
    for(int i=1;i<=N;++i){
        F[i] = (F[i-1]*ll(i))%Q;
    }

    int cl=(n+1)/2;
    ll ans=0LL;
    for(int x=0;x<cl;++x){
        ll blockers = x+1 - (n&1);
        ll L = max(0,x-1);
        for(ll l = 0;l<=L;++l){
            ll curr = newt(L,l);
            curr = (curr * F[n-x-1 + l - 1])%Q;
            curr = (curr * blockers)%Q;
            ans = (ans+curr)%Q;
        }
    }
    ans = (ans*n)%Q;
    cout<<ans;



    return 0;
}