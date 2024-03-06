#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> joinLeft(vector<int> x, int el){
    vector<int> y({el});
    for(int a : x){
        y.push_back(a);
    }
    return y;
}

vector<int> joinRight(vector<int> x, int el){
    vector<int> y = x;
    y.push_back(el);
    return y;
}

vector<int> foo(ll x, int min){
    if(x==1){
        return {};
    }else if(x&1){
        return joinRight(foo(x-1,min+1),min);
    }else{
        return joinLeft(foo(x/2,min+1),min);
    }
}


int main(){


    int t=1;
    cin>>t;
    while(t--){
        ll X = 0LL;
        cin>>X;
        vector<int> res = foo(X,1);
        cout<<res.size()<<endl;
        for(int x : res){
            cout<<x<<" ";
        }cout<<endl;
    }
   

    return 0;
}