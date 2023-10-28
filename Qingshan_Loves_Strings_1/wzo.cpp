#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_good(string s){
    for(int i=1;i<s.size();++i){
        if(s[i]==s[i-1]){
            return false;
        }
    }
    return true;
}

int main(){

    int q;
    cin>>q;
    while(q--){
        int n=0,m=0;
        cin>>n>>m;
        string s="",t="";
        cin>>s>>t;
        if(is_good(s)){
            cout<<"YES"<<endl;
            continue;
        }
        if(!is_good(t)){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(int i=1;i<s.size();++i){
            if(s[i]==s[i-1]){
                if(t[0]!=s[i-1] && t.back()!=s[i]){
                   // ok 
                }else{
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}