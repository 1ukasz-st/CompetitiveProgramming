#include<bits/stdc++.h>

using namespace std;

const int N = (2e5)+3, NINF = -1000000000;

int maxd[N+3],marked[N+3];
vector<int> ls[N+3];

void dfs_depth(int v, int last){
    maxd[v] = marked[v] ? 0 : NINF;
    for(size_t i=0;i<ls[v].size();++i){
        if(ls[v][i]==last){
            iter_swap(ls[v].begin(), ls[v].begin()+i);
        }
    }
    for(size_t i=1;i<ls[v].size();++i){
        int u = ls[v][i];
        if(u!=last){
            dfs_depth(u,v);
            maxd[v] = max(maxd[v],maxd[u]+1);
        }
    }
}

void dfs_calc(int v, int gora, int &ans){
    int f = max(maxd[v],gora);
    if(f>=0){
        ans = min(ans,f);
    }
    int m = (int)(ls[v].size());
    int *maxpref = (int*)calloc(m,sizeof(int)), *maxsuf = (int*)calloc(m+1,sizeof(int));
    maxpref[0]=NINF;maxsuf[m]=NINF;
    for(int i=1;i<m;++i){
        maxpref[i] = max(maxpref[i-1],maxd[ls[v][i]]);
    }
    for(int i=m-1;i>=1;--i){
        maxsuf[i] = max(maxsuf[i+1],maxd[ls[v][i]]);
    }
    for(int i=1;i<m;++i){
        int lewo = maxpref[i-1], prawo = maxsuf[i+1], ten = marked[v] ? 0 : NINF;
        int nast = max({lewo+1,prawo+1,gora,ten})+1;
        if(nast<0){
            nast = NINF;
        }
        dfs_calc(ls[v][i],nast,ans);
    }
    free(maxpref);
    free(maxsuf);
}

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0,k=0;
        cin>>n>>k;
        for(int i=1;i<=n;++i){
            ls[i].clear();
            marked[i]=0;
            maxd[i]=0;
        }
        for(int i=0;i<k;++i){
            int a=0;
            cin>>a;
            marked[a]=1;
        }
        ls[1].push_back(1);
        for(int i=1;i<n;++i){
            int a=0,b=0;
            cin>>a>>b;
            ls[a].push_back(b);
            ls[b].push_back(a);
        }
        dfs_depth(1,1);
        int ans = -NINF, start = marked[1] ? 0 : NINF;
        dfs_calc(1,start,ans);
        cout<<ans<<endl;
    }


    return 0;
}