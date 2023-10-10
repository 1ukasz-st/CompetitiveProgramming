#include<bits/stdc++.h>

using namespace std;

int sg(int x){
    return (x>0 ? 1 : int(x/(x-1)));
}

int main(){

    int t=0;
    cin>>t;
    while(t--){
        int xa=0,xb=0,xc=0,ya=0,yb=0,yc=0;
        cin>>xa>>ya;
        cin>>xb>>yb;
        cin>>xc>>yc;
        int dxb = xb-xa, dyb = yb-ya;
        int dxc = xc-xa, dyc = yc-ya;
        int ans=0;  
        if(sg(dxb)==sg(dxc)){
            ans+=min(abs(dxb),abs(dxc));
        }
        if(sg(dyb)==sg(dyc)){
            ans+=min(abs(dyb),abs(dyc));
        }
        cout<<ans+1<<endl;
    }

    return 0;
}