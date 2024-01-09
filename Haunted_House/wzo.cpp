#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        string s="";
        cin>>s;
        if(n==1){
            cout<<-(s[0]-'0')<<endl;
            continue;
        }
        vector<int> t(n);
        vector<ll> indeksy_zer;
        for(int i=0;i<n;++i){
            t[i] = s[i]-'0';
            if(t[i]==0){
                indeksy_zer.push_back(ll(i));
            }
        }
        if(indeksy_zer.empty()){
            for(int i=0;i<n;++i){
                cout<<"-1 ";
            }cout<<endl;
            continue;
        }
        vector<ll> sp(indeksy_zer.size());
        int m = indeksy_zer.size();
        sp[0] = indeksy_zer[0];
        for(int i=1;i<m;++i){
            sp[i] = sp[i-1] + indeksy_zer[i];
        }
        auto sum = [sp,indeksy_zer](int l, int r){
            return sp[r] - sp[l] + indeksy_zer[l];
        };
        /*cout<<"Zera: ";for(int x : indeksy_zer){
            cout<<x<<" ";
        }cout<<endl;
        cout<<"Sumy: ";for(int x : sp){
            cout<<x<<" ";
        }cout<<endl;*/
        int k=0;
        ll suma1=0;
        int indeks=indeksy_zer.size()-1;
        for(int ii=1;ii<n;++ii){
            int i = n-ii-1;
            if(t[i+1] == 1){
                ++k;
                suma1 += ll(i+1);
            }
            while(indeks >= 0 && indeksy_zer[indeks] > i){
                --indeks;
            }
            if(indeks==-1){
                if(k==0){
                    cout<<"0 ";
                }else{
                    cout<<"-1 ";
                }
                continue;
            }
            if(indeks+1 < k){
                cout<<"-1 ";
            }else{
                int indeks_lewy = indeks-k+1;
                ll suma0 = sum(indeks_lewy,indeks);
                cout<<suma1-suma0<<" ";
            }
        }
        if(int(indeksy_zer.size())==n){
            cout<<0<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}