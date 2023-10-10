#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        ll c=0,t=0;
        int n=0;
        cin>>c>>t>>n;
        vector<ll> foo(n);
        for(ll &x : foo){
            cin>>x;
        }
        ll res=0LL;
        while(foo.size()){
            res += t-1;
            t = min(c,foo.back()+1);
            foo.pop_back();
            t--;
            ++res;
        }
        res += t;
        cout<<res<<endl;
    }

    return 0;
}