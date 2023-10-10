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
        ll n=0,m=0,ans=0;
        cin>>n>>m;
        ll g = __gcd(m,n);
        if(__builtin_popcount(m/g) != 1){
            if(n%m==0){
                cout<<0<<endl;
                continue;
            }
            cout<<-1<<endl;
            continue;
        }
        ll k = n%m;
        while(true){
            if(k==0){
                break;
            }
            ans += k;
            k = (2*k)%m;
        }
        cout<<ans<<endl;
    }

    return 0;
}