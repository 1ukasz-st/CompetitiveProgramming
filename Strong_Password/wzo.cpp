#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=0;
    cin>>t;
    while(t--){
        int m=0;
        string s="",a="",b="";
        cin>>s;
        cin>>m;
        cin>>a;
        cin>>b;
        vector<deque<int>> wyst(10);
        int i=0;
        for(char c : s){
            int d = c-'0';
            wyst[d].push_back(i);
            ++i;
        }
        int ost=-1;
        bool flag=false;
        for(int i=0;i<m;++i){
            int l=a[i]-'0', r=b[i]-'0';
            int cob=l;
            for(int d=l;d<=r;++d){
                if(wyst[d].empty()){
                    flag=true;
                    break;
                }
                if(wyst[d].front() > wyst[cob].front()){
                    cob = d;
                }
            }
            if(!flag){
                int foo = wyst[cob].front();
                for(int d=0;d<=9;++d){
                    while(wyst[d].size() && wyst[d].front() <= max(foo,ost)){
                        wyst[d].pop_front();
                    }
                }
                ost = foo;
            }
        }
        cout<<(flag ? "YES": "NO")<<endl;
    }

    return 0;
}