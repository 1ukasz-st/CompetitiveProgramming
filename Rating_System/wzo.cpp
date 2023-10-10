#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5;

ll T[N+3],sp[N+3];

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0,l=0,best_l=0;
        ll curr_sum=0LL,min_sum=1e18,k=1e18;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>T[i];
            sp[i] = sp[i-1]+T[i];
            if(curr_sum+T[i] < T[i]){
                curr_sum += T[i];
            }else{
                curr_sum = T[i];
                l = i;
            }
            if(curr_sum <= min_sum){
                best_l = l;
                min_sum=curr_sum;
            }
        }
        cout<<sp[best_l-1]<<endl;
    }


    return 0;
}