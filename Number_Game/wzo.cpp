#include<bits/stdc++.h>

using namespace std;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        vector<int> t(n);
        for(int &x : t){
            cin>>x;
        }
        sort(t.begin(),t.end());
        int ans=0;
        for(int k=1;k<=n;++k){
            int l=0,r=n-1,m=k; // l-> ostatni dostepny, r -> najwiekszy dostepny, m -> ile co najwyzej mozna wziac teraz
            while(l<=r && m > 0){
                while(t[r] > m && l <= r-1){
                    --r;
                }
                if(t[r] <= m){
                    --r;
                    ++l;
                    --m;
                }else{
                    break;
                }
            }
            if(m==0){
                ans = k;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
