#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main(){

    int t=0;
    cin>>t;
    while(t--){
        ll n=0LL,k=0LL,g=0LL,q=0LL,nq=0LL,kg=0LL;
        cin>>n>>k>>g;
        if(k==0){
            cout<<0<<endl;
            continue;
        }
        kg=k*g;
        q = ((g+1LL)/2LL) - 1LL;
        if(q==0){
            cout<<0<<endl;
            continue;
        }
        nq = min(ll(kg/q),n);
        if((nq*q) % g != 0 && nq == n){
            nq--;
        }
        ll ile = (kg - q*nq) / g;
        ll r = kg - ile*g - q*nq;
        //cout<<"######"<<endl;
        //cout<<kg<<","<<q<<","<<nq<<","<<ile<<","<<r<<" ";
        if(r>q){
            cout<<q*nq - (g-r)<<endl;
        }else{
            cout<<q*nq + r<<endl;
        }
    }
    
    return 0;
}