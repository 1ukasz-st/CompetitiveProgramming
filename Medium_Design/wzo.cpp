#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q=0;
    cin>>q;
    while(q--){
        int n=0,m=0;
        cin>>n>>m;
        vector<pair<int,int>> seg(n);
        for(auto &[l,r] : seg){
            cin>>l>>r;
        }
        auto comp = [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        };
        sort(seg.begin(),seg.end());
        set<pair<int, int>, decltype(comp)> curr(comp);
        int c1=0,cm=0,ans=0;
        for(int i=0;i<n;++i){
            while(curr.size() && curr.begin()->second < seg[i].first){
                c1 -= curr.begin()->first==1;
                cm -= curr.begin()->second==m;
                curr.erase(curr.begin());
            }
            curr.insert(seg[i]);
            c1 += seg[i].first==1;
            cm += seg[i].second==m;
            ans = max(ans,(int)(curr.size())-min(c1,cm));
        }
        cout<<ans<<endl;
    }

    return 0;
}