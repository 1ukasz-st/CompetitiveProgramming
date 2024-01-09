#include<bits/stdc++.h>

using namespace std;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        vector<int> t(n);
        vector<vector<pair<int,int>>> wyst(101);
        int ilew1=0;
        for(int i=0;i<n;++i){
            cin>>t[i];
            wyst[t[i]].push_back({t[i],i});
        }
        for(int i=0;i<=100;++i){
            if(wyst[i].size() > 1){
                ilew1++;
            }
         }
        if(ilew1<2){
            cout<<"-1"<<endl;
            continue;
        }
        vector<int> res(n);
        vector<pair<int,int>> typy = {{1,2},{1,3}};
        for(vector<pair<int,int>> v : wyst){
            if(v.empty()){continue;}
            if(typy.empty() || v.size()<2){
                for(auto [val,ind] : v){
                    res[ind]=1;
                }
            }else{
                for(int i=0;i<v.size();++i){
                    res[v[i].second] = typy.back().first;
                }
                res[v.back().second] = typy.back().second;
                typy.pop_back();        
            }    
        }
        for(int x : res){
            cout<<x<<" ";
        }cout<<endl;
    }

    return 0;
}