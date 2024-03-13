#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (1e5)+3;

int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    cin>>t;
    vector<vector<int>> mults(M+1);
    vector<ll> cnt(M+1),res(M+1);    
    vector<int> inArr(M+1);
    while(t--){
        int n=0,m=0;
        cin>>n;
        vector<int> t(n),t2;
        for(int &x : t){
            cin>>x;
            m = max(m,x);
            ++inArr[x];
        }
        t2=t;
        sort(t2.begin(),t2.end());

        for(int i=1;i<=m;++i){
            for(int j=i;j<=m;j+=i){
                for(int k=0;k<inArr[j];++k){
                    mults[i].push_back(j);
                }
            }
        }

        for(int i=1;i<=m;++i){
            int cm = mults[i].size();
            int left=0,ub=0;
            for(int j=0;j<cm;++j){
                int curr = mults[i][j];
                while(t2[ub]<curr){
                    ++ub;
                }
                ++ub;
                ++left;
                if(left>=2){
                    cnt[i]+=ll(left-1)*ll(n-ub);
                }
            }
        }
        ll ans=0LL;
        for(int i=m;i>=1;--i){
            res[i] = cnt[i];
            for(int j=2*i;j<=m;j+=i){
                res[i] -= res[j];
            }
            ans += res[i]*ll(i);
        }

        cout<<ans<<"\n";

        for(int i=1;i<=m;++i){
            mults[i].clear();
            cnt[i] = 0;
            res[i] = 0;
            inArr[i] = 0;
        }

    }



    return 0;
}