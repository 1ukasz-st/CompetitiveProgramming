#include<bits/stdc++.h>

using namespace std;


int main(){
    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        vector<int> foo(n),wpr(n);
        set<int> els;
        for(int &x : foo){
            cin>>x;
        }
        for(int i=0;i<n;++i){
            els.insert(foo[i]);
            wpr[i]=els.size();
        }
        els.clear();
        long long ans=0LL;
        for(int i=n-1;i>=0;--i){
            int x=foo[i];
            if(els.find(x)==els.end()){
                ans += wpr[i];
                els.insert(x);
            }
        }
        cout<<ans<<endl;
    }
}