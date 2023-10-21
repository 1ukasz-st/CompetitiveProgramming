#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (1e6)+3, L = 'z'-'a';

int res[N+3],wyst_suf[N+3][L+3];

ll length(int n, int k){
    ll a = ((ll(n)*ll(n+1))/2);
    ll b = ((ll(n-k-1) * ll(n-k)))/2;
    return a-b;
}

int main(){

    int q=0;
    cin>>q;
    while(q--){
        string s="";
        cin>>s;
        ll pos=0;
        cin>>pos;
        int n = (int)s.size();
        int l=0,r=n,k=1000000000;
        while(l<=r){
            int mid = (l+r)/2;
            if(length(n,mid) >= pos){
                k=min(k,mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        for(int c=0;c<=L;++c){
            wyst_suf[n][c] = 1000000000;
        }
        for(int i=n-1;i>=0;--i){
            for(int c=0;c<=L;++c){
                wyst_suf[i][c] = wyst_suf[i+1][c];
                if(s[i]==char(c+'a')){
                    wyst_suf[i][c] = i;
                }
            }
        }
        int ind=0,k_curr=k,res_ind=1;
        while(ind<n && res_ind <= n-k){
            for(int c=0;c<=L;++c){
                int nearest = wyst_suf[ind][c];
                int must_remove = nearest-ind;
                if(must_remove<=k_curr){
                    res[res_ind] = c;
                    ind = nearest+1;
                    k_curr -= must_remove;
                    ++res_ind;
                    break;
                }
            }
        }
        int ptr = length(n,k-1);
        int mv=0;
        while(ptr+mv < pos){
            ++mv;
        }
        cout<<char(res[mv]+'a');
        for(int i=0;i<=n;++i){
            res[i]='`';
        }
    }

    return 0;
}