#include<bits/stdc++.h>

using namespace std;

const int L = 'z';

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q=0;
    cin>>q;
    while(q--){
        int n=0,k=0;
        cin>>n>>k;
        string s="";
        cin>>s;
        vector<int> wyst(L+1);
        for(char c : s){
            ++wyst[c];
        }
        int m=0;
        for(int i='a';i<='z';++i){
            if(wyst[i]&1){
                ++m;
            }
        }
        if(k==0){
            if(m<=1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        else if(k>=m && (k-m)%2 == 0){
            cout<<"YES"<<endl;
        }else if(k>=m-1 && (k-(m-1))%2 == 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}