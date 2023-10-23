#include<bits/stdc++.h>

using namespace std;

const int L = 'z';
int ord[1000];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ord['0']=10;
    ord['1']=1;
    ord['2']=2;
    ord['3']=3;
    ord['4']=4;
    ord['5']=5;
    ord['6']=6;
    ord['7']=7;
    ord['8']=8;
    ord['9']=9;

    int q=0;
    cin>>q;
    while(q--){
        string s="";
        cin>>s;
        int ans=0;
        int ptr='1';
        for(int i=0;i<4;++i){
            ans += abs(ord[ptr]-ord[s[i]]);
            ptr = s[i];
            ++ans;
        }
        cout<<ans<<endl;
    }


    return 0;
}