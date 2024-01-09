#include<bits/stdc++.h>

using namespace std;

int find(int v, vector<int> &F){
    if(F[v]!=v){
        F[v] = find(F[v],F);
    }
    return F[v];
}

void polacz(int u, int v, vector<int> &F){
    u = find(u,F);
    v = find(v,F);
    F[u] = v;
}

int solve(int n, int k, string s){
    vector<int> F(n);
    vector<vector<int>> S(n);
    for(int i=0;i<n;++i){
        F[i]=i;
    }
    for(int i=0;i<k;++i){
        for(int j=i;j<n;j+=k){
            polacz(j,i,F);
            if(n-1-j > j) polacz(n-1-j,j,F);
        }
    }
    for(int i=0;i<n;++i){
        S[find(i,F)].push_back(s[i]);
    }
    int ans=0;
    for(vector<int> g : S){
        if(g.empty())continue;
        vector<int> cnt(30);
        for(int c : g) cnt[c-'a']++;
        int r = (int)g.size();
        int m = *max_element(cnt.begin(),cnt.end());
        ans += r-m;
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q=0;
    cin>>q;
    while(q--){
        int n=0,k=0;
        cin>>n>>k;
        string s="";
        cin>>s;
        cout<<solve(n,k,s)<<"\n";
    }



}