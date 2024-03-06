#include<bits/stdc++.h>

using namespace std;

int main(){

    int t=0;
    cin>>t;
    while(t--){
        int n=0,k=0;
        cin>>n>>k;
        vector<int> in(n+1);
        vector<vector<int>> G(n+1);
        for(int r=0;r<k;++r){
            int a=0,last=0;
            for(int i=0;i<n;++i){
                cin>>a;
                if(i>1){
                    G[last].push_back(a);
                    ++in[a];
                }
                last = a;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;++i){
            cout<<i<<" | ";
            for(int j : G[i]){
                cout<<j<<" ";
            }cout<<endl;
            if(in[i]==0)
            q.push(i);
        }
        vector<int> res;
        while(q.size()){
            int v = q.front();
            q.pop();
            res.push_back(v);
            for(int u : G[v]){
                --in[u];
                if(in[u]==0){
                    q.push(u);
                }
            }
        }
        cout<<((int)(res.size())==n ? "YES" : "NO") << endl;
       
    }
    


    return 0;
}