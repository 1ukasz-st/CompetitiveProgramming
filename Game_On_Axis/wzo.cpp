#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int u, vector<vector<int>> &G, vector<bool> &reachableTo){
    if(reachableTo[u]){
        return;
    }
    reachableTo[u] = 1;
    for(int v : G[u]){
        dfs(v,G,reachableTo);
    }
}

int find(int v, vector<int> &F){
    if(F[v]!=v){
        F[v] = find(F[v],F);
    }
    return F[v];
}

void polacz(int u, int v, vector<int> &F, vector<bool> &cycle){
    u = find(u,F);
    v = find(v,F);
    if(u==v){
        cycle[u] = 1;
        cycle[v] = 1;
    }
   // cout<<"U"<<u<<","<<v<<endl;
    F[u] = v;
}

ll dfs_cnt(int u, vector<vector<int>> &G){
    ll sum=1LL;
    for(int v : G[u]){
        sum+=dfs_cnt(v,G);
    }
    return sum;
}

int main(){

    int q=1;
    cin>>q;
    while(q--){

        int n=0;
        cin>>n;
        vector<int> edge(n+1),F(n+1);
        vector<vector<int>> invEdge(n+1);
        map<int,int> in;
        vector<bool> reachableFrom(n+1),reachableTo(n+1),cycle(n+1);
        bool oneInCycle=false;
        for(int i=1;i<=n;++i){
            F[i] = i;
        }
        for(int i=1;i<=n;++i){
            cin>>edge[i];
            edge[i] = i+edge[i];
            if(edge[i] >= 1 && edge[i] <= n){
                polacz(i,edge[i],F,cycle);
                invEdge[edge[i]].push_back(i);
            }
        }
      /*  dfs(1,invEdge,reachableTo);
        ll cnt_reachable_from=0LL, cnt_reachable_to = -1LL;
        for(bool b : reachableTo){
            cnt_reachable_to += b;
        }*/
        ll cnt_reachable_from=0LL;

        int v=1;
        while(v>0 && v<=n){
            if(reachableFrom[v]){
                oneInCycle = true;
                break;
            }
            reachableFrom[v] = 1;
            ++cnt_reachable_from;
            v = edge[v];
        }
    

        ll ans=0LL;
        if(oneInCycle){
            ll bad = 0LL;
            for(int i=1;i<=n;++i){
                if(cycle[find(i,F)]){
                    ++bad;
                }
            }
            ans = cnt_reachable_from * (2*n+1 - bad);
        }else{
            ans = n*ll(2*n+1);
            ll bad = 0LL;
            for(int i=1;i<=n;++i){
                if(cycle[find(i,F)]){
                    ++bad;
                }
            }
            int v = 1, last = 1;
            while(v>=1 && v<=n){
                bad+=1LL;
                for(int u : invEdge[v]){
                    if(u != last){
                        int cnt = dfs_cnt(u,invEdge);
                        bad += cnt;
                    }
                }
                ans -= bad;
                last = v;
                v = edge[v];
            }
        }   
         cout<<ans<<endl;
    }
    return 0;
}