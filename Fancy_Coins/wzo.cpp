#include<bits/stdc++.h>

using namespace std;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int m=0,k=0,a1=0,ak=0;
        cin>>m>>k>>a1>>ak;
        if(m<k){
            cout<<max(0,m-a1)<<endl;
            continue;
        }
        m -= min(ak,int(m/k))*k;
        if(m<=0){
            cout<<0<<endl;
            continue;
        }
        if(a1 < m%k){
            m -= min(m%k,a1);
            cout<<m%k + int(m/k)<<endl;
            continue;
        }
        a1 -= m%k;
        m -= m%k;
        m -= int(a1/k)*k;
        if(m<=0){
            cout<<0<<endl;
            continue;
        }
        cout<<m%k + int(m/k)<<endl;
    }


    return 0;
}