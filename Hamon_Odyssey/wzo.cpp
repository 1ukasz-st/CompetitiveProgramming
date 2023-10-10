#include<bits/stdc++.h>

using namespace std;

int main(){

    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        int a = INT_MAX;
        vector<int> arr(n),sand(n+1);
        for(int &x : arr){
            cin>>x;
            a &= x;
        }
        if(a!=0){
            cout<<1<<endl;
            continue;
        }
        sand[n-1] = arr[n-1];
        for(int i=n-2;i>=0;--i){
            sand[i] = sand[i+1]&arr[i];
        }
        int ans=0,curr=arr[0];
        for(int i=0;i<n;++i){
            curr &= arr[i];
            if(curr == 0 && sand[i+1] == 0){
                curr = INT_MAX;
                ++ans;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}