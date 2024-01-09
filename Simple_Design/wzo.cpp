#include<bits/stdc++.h>

using namespace std;


int main(){

    int q=0;
    cin>>q;
    while(q--){
        int x=0,k=0;
        cin>>x>>k;
        for(int y=x;y<=x+20;++y){
            int s=0;
            int y2=y;
            while(y2>=1){
                s += (y2%10);
                y2/=10;
            }
            if(s%k==0){
                cout<<y<<endl;
                break;
            }
        }
    }


    return 0;
}