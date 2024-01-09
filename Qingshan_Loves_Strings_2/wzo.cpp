#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void add01(string &s, int where){
    if(where==-1){
        s = "01"+s;
        return;
    }
    string temp=s.substr(0, where + 1);
    temp+="01";
    temp+=s.substr(where + 1, s.length() - (where + 1));
    s = temp;
}

int isBad(string s, int &pos){
    for(int i=0;i<s.size();++i){
        if(s[i]==s[s.size()-1-i]){
            pos=i;
            return 1;
        }
    }
    return 0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--){
        int n=0;
        cin>>n;
        string s="";
        cin>>s;
        if(count(s.begin(),s.end(),'0')!=count(s.begin(),s.end(),'1')){
            cout<<"-1\n";
            continue;
        }
        vector<int> ans;
        int pos;
        while(isBad(s,pos)){
            if(s[pos]=='0'){
                int pos2 = s.size()-pos-1;
                ans.push_back(pos2+1);
                add01(s,pos2);
            }else{
                ans.push_back(pos);
                add01(s,pos-1);
            }
        }       
        cout<<ans.size()<<"\n";
        for(int x : ans){
            cout<<x<<" ";
        }cout<<"\n";
    }

    return 0;
}