#include<bits/stdc++.h>

using namespace std;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0,k=0;
        cin>>n>>k;
        k %= m;
        vector<int> t(m);
        map<int,int> cnt;
        for(int i=0;i<n;++i){
            int x=0;
            cin>>x;
            t[i]=x;
            cnt[i-(t[i]-1)]++;
        }
        for(int rot=1;rot<n;++i){
            int c = rot;
            int juz=0;
            while(true){
                int ilef = cnt[-c];
                if(ilef==0){
                    break;
                }
                else{
                    c += c;
                }
            }
            if()

        }

    }

    return 0;
}