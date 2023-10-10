#include<bits/stdc++.h>

using namespace std;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0,curr=0,last=0;
        cin>>n;
        vector<int> c(n),partsum(n),ans(n);
        for(int &x : c){
            cin>>x;
        }
                       // -cost, ind
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;++i){
            pq.push({-c[i],i});
        }
        cin>>curr;
        int last_ind=-1;
        while(pq.size() && curr > 0){
            auto [ci, ind] = pq.top();
            ci *= -1; 
            pq.pop();
            if(ind < last_ind){continue;}
            int p=0;
            if(ci==last && last_ind!=-1){
                p = partsum[last_ind];
            }else{
                p = curr / (ci - last);
            }
            if(last_ind!=-1){
                p = min(p,partsum[last_ind]);
                partsum[last_ind] -= p;
            }
            partsum[ind] += p;
            curr -= p*(ci - last);
            last = ci;
            last_ind = ind;
        }
        ans[n-1]=partsum[n-1];
        for(int i=n-2;i>=0;--i){
            ans[i] = ans[i+1] + partsum[i];
        }
        for(int i : ans){
            cout<<i<<" ";
        }cout<<endl;      
    }

    return 0;
}