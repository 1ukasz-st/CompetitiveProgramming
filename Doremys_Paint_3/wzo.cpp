#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int q;
    cin>>q;
    while(q--){

        int n=0;
        cin>>n;
        vector<int> a(n);
        for(int &x : a){
            cin>>x;
        }
        sort(a.begin(),a.end());
        set<int> xdd;
        for(int x : a){
            xdd.insert(x);
        }
        if(xdd.size()>2){
            cout<<"NO\n";
            continue;
        }
        if(xdd.size()==1){
            cout<<"YES\n";
            continue;
        }
        int x=a[0],y=a.back();
        int cx=1,cy=0;
        int ne=1,no=0;
        for(int i=1;i<n;++i){
            ne+=!(i&1);
            no+=(i&1);
            if(a[i]==x){
                ++cx;
            }else{
                ++cy;
            }
        }
        if((cx==ne && cy==no) || (cx==no && cy==ne)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}