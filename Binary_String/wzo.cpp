#include<bits/stdc++.h>

using namespace std;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        string s="";
        cin>>s;
        n = (int)(s.size());
        int *t = (int*)calloc(n+1,sizeof(int)); // just for some fun. There's no reason to do this in C++
        int *sp0 = (int*)calloc(n+1,sizeof(int));
        int *sp1 = (int*)calloc(n+1,sizeof(int));
        for(int i=1;i<=n;++i){
            t[i] = s[i-1]-'0';
            sp0[i] = sp0[i-1] + (t[i]==0);
            sp1[i] = sp1[i-1] + t[i];
        }
        int ss1=0,ans=1000000000;
        if(sp0[n]==0 || sp1[n]==0){
            cout<<"0\n";
            goto next_test;     // Alignment: Chaotic Evil 
        }
        for(int r=n;r>=1;--r){
            int l = sp0[r] - ss1 + 1;
            if(l>=1 && l <= r){
                
                ans = min(ans,sp0[r] - sp0[l-1]);
            }
            ss1+=t[r];
        }
        cout<<ans<<endl;

        next_test:
        free(t);

        free(sp0);
        free(sp1);
    }

    return 0;
}