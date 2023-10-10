#include<bits/stdc++.h>

using namespace std;

int main(){

    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<int> arr(n),cnt(101);
        for(int &x : arr){
            cin>>x;
            ++cnt[x];
        }
        bool flag=true;
        for(int x=100;x>=0;--x){
            while(cnt[x]--){
                for(int y=x-1;y>=0;--y){
                    if(cnt[y]==0){
                        flag=false;
                        break;
                    }
                    --cnt[y];
                }
                if(!flag){
                    break;
                }
            }
        }
        cout<<(flag ? "YES" : "NO")<<endl;
    }

    return 0;
}