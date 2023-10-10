#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<int> a(n);
        for(int &x : a){
            cin>>x;
        }
        sort(a.begin(),a.end());
        int last=a.size()-1;
        while(last>0){
            if(a[last-1]==a.back()){
                --last;
            }else{
                break;
            }
        }
        if(last==0){
            cout<<"-1\n";
            continue;
        }
        bool bad = false;
        for(int i=0;i<last;++i){
            if(a[i]%a.back() == 0){
                bad = true;
                break;
            }
        }
        if(bad){
            cout<<"-1\n";
        }else{
            cout<<last<<" "<<a.size()-last<<"\n";
            for(int i=0;i<last;++i){
                cout<<a[i]<<" ";
            }cout<<"\n";
            for(int i=last;i<a.size();++i){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}