#include<bits/stdc++.h>

using namespace std;


int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0,m=0;
        cin>>n>>m;
        vector<int> a(n);
        set<pair<int,int>> b;
        a[0]=1;
        for(int i=1;i<n;++i){
            cin>>a[i];
        }
        for(int i=0;i<n;++i){
            int x=0;
            cin>>x;
            b.insert({x,i});
        }
        sort(a.begin(),a.end());
       /* for(auto [v,i] : b){
            cout<<"#"<<v<<","<<i<<"#"<<endl;
        }*/
        int ok=0;
        for(int i=0;i<n;++i){
            auto search = b.upper_bound({a[i],1000000000});
            if(search!=b.end()){
                //cout<<a[i]<<","<<(*search).first<<endl;
                b.erase(search);
                ++ok;
            }
        }
        cout<<n-ok<<endl;
        
    }


    return 0;
}