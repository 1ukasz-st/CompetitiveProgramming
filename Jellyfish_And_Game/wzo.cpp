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
        int n=0,m=0,k=0;
        cin>>n>>m>>k;
        vector<ll> j(n),g(m);
        for(ll &x : j){
            cin>>x;
        }
        for(ll &x : g){
            cin>>x;
        }
        vector<ll> res(1001);
        for(int i=1;i<=min(1000,k);++i){
            if(i&1){
                auto minj = min_element(j.begin(),j.end()), maxg = max_element(g.begin(),g.end());
                if(*minj < *maxg){
                    iter_swap(minj, maxg);
                }
            }else{
                auto maxj = max_element(j.begin(),j.end()), ming = min_element(g.begin(),g.end());
                if(*ming < *maxj){
                    iter_swap(maxj, ming);
                }
            }
            for(ll x : j){
                res[i]+=x;
            }
        }
        if(k%1000 == 0){
            cout<<res.back()<<endl;
            continue;
        }
        cout<<res[k%1000]<<endl;
    }

    return 0;
}