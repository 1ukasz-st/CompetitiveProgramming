#include<bits/stdc++.h>

using namespace std;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=0;
    cin>>t;
    while(t--){
        int n=0,m=0,q=0;
        cin>>n>>m;
        vector<pair<int,int>> seg(m);
        for(auto &[a,b] : seg){
            cin>>a>>b;
            --a;
            --b;
        }
        cin>>q;
        vector<int> que(q);
        for(int &x : que){
            cin>>x;
            --x;
        }
        int l=0,r=q-1,ans=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            vector<int> sp(n),arr(n);
            for(int i=0;i<=mid;++i){
                arr[que[i]]=1;
            }
            sp[0]=arr[0];
            for(int i=1;i<n;++i){
                sp[i] = sp[i-1]+arr[i];
            }
            auto sum = [sp,arr](int l, int r){
                return sp[r]-sp[l]+arr[l];
            };
            int cnt=0;
            for(auto [l,r] : seg){
                if(sum(l,r) > (r-l+1)-sum(l,r)){
                    ++cnt;
                }
            }
            if(cnt>=1){
                ans=min(ans,mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout<<(ans==1e9 ? -1 : ans+1)<<"\n";
    }

    return 0;
}