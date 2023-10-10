#include<bits/stdc++.h>
#define cf cout.flush()

using namespace std;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int q=0;
    cin>>q;
    while(q--){
        int n=0,k=0;
        cin>>n>>k;
        vector<int> h(n),f(n),c(n),sp(n);
        int ans=0;
        for(int &x : f){
            cin>>x;
            if(x<=k){
                ans=1;
            }
        }
        sp[0] = f[0];
        for(int i=1;i<n;++i){
            sp[i] = sp[i-1]+f[i];
        }
        for(int &x : h){
            cin>>x;
        }
        auto sum = [sp,f](int l, int r){
            if(l==r){
                return f[l];
            }
            if(l==0){
                return sp[r];
            }
            return sp[r]-sp[l-1];
        };
        c[n-1] = 1;
        for(int i=n-2;i>=0;--i){
            c[i] = (h[i]%h[i+1] == 0 ? c[i+1]+1 : 1);
        }
        int l=0,r=n;
        while(l<=r){
            int mid = (l+r)/2;
            bool good = false;
            for(int i=0;i<n;++i){
                if(c[i]>=mid && sum(i,i+mid-1) <= k){
                    good=true;
                }
            }
            if(good){
                ans = max(ans,mid);
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout<<ans<<endl;       
    }

    return 0;
}