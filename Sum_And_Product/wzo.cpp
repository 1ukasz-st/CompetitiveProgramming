#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin>>t;
    while (t--) {
        int n=0,q=0;
        map<ll,ll> cnt;
        cin>>n;
        for(int i=0;i<n;++i){
            ll x=0LL;
            cin>>x;
            ++cnt[x];
        }
        cin>>q;
        while(q--){
            ll x=0LL,y=0LL;
            cin>>x>>y;
            ll d = x*x - 4*y;
            if(d<0){
                cout<<"0 ";
                continue;
            }
            ll sd = ll(sqrt(d));
            if(sd*sd != d){
                cout<<"0 ";
                continue;
            }
            ll aj1 = ll((x + sd)/2);
            ll ai1 = x - aj1;
            ll aj2 = ll((x - sd)/2);
            ll ai2 = x - aj2;
            ll a = 0LL, b = 0LL;
            if(aj1 != ai1){
                a += cnt[aj1]*cnt[ai1];
            }
            else{
                a += (cnt[aj1]*(cnt[aj1]-1LL))/2LL;
            }
            if(aj2 != ai2){
                b += cnt[aj2]*cnt[ai2];
            }
            else{
                b += (cnt[aj2]*(cnt[aj2]-1LL))/2LL;
            }
            if(min(aj1,ai1) != min(aj2,ai2) || max(aj1,ai1) != max(aj2,ai2)){
                cout<<a+b<<" ";
            }else{
                cout<<a<<" ";
            }
        }cout<<"\n";
    }

    return 0;
}
