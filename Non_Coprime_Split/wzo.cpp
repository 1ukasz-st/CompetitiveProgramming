#include<bits/stdc++.h>


using namespace std;


int main(){

    int q=0;
    cin>>q;
    while(q--){
        int l=0,r=0;
        cin>>l>>r;
        if(r-l+1 >= 4){
            int f4 = int((l+3)/4) * 4;
            cout<<f4/2<<" "<<f4/2<<endl;
            continue;
        }
        for(int x=l;x<=r;++x){
            int xtemp = x;
            for(int k=2;k*k<=xtemp;k++){
                if(xtemp % k == 0){
                    int l = xtemp/k;
                    int p = (l-1)*k, q = k;
                    if(min(p,q)>0){
                        cout<<p<<" "<<q<<endl;
                        goto next_test;
                    }
                }
            }
        }
        cout<<-1<<endl;

        next_test:continue;
    }
}