#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> options({{1,1,1},{2,2,2},{1,1,2},{1,2,2}});

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        int x=-1,y=-1,z=-1;
        for(vector<int> opt : options){
            int a = opt[0], b = opt[1], c = opt[2];
            if(((n-a-b-c)%3)!=0 || n-a-b-c < 0){
                continue;
            }
            if(a+b+c==n){
                if(a==b || b==c || c==a){
                    continue;
                }
            }
            int sum = (n-a-b-c)/3, p=0,q=0,r=0;
            if(a!=b && b!=c && c!=a){
                p=0;
                q=0;
                r=sum-p-q;
            }else if(a==b && b!=c){
                p=0;
                q=1;
                r=sum-p-q;
            }else if(b==c && a!=b){
                q=0;
                r=1;
                p=sum-q-r;
            }else if(a==b && b==c){
                p=0;
                q=1;
                r=sum-p-q;
            }else if(a==c && c!=b){
                p=0;
                r=1;
                q=sum-p-r;
            }
            int x0=3*p + a;
            int y0=3*q + b;
            int z0=3*r + c;
        //    cout<<a<<b<<c<<" "<<p<<q<<r<<" "<<x0<<" "<<y0<<" "<<z0<<" "<<x0+y0+z0<<endl;
            if(x0!=y0 && y0!=z0 && z0!=x0 && x0>0 && y0>0 && z0>0 && (x0%3 != 0) && (y0%3 != 0) && (z0%3 != 0)){
                if(x0+y0+z0 == n){
                    x=x0;
                    y=y0;
                    z=z0;
                    break;
                }
            }
        }
        if(x==-1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<x<<" "<<y<<" "<<z<<endl;
    }


    return 0;
}