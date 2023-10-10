#include<bits/stdc++.h>


using namespace std;


vector<string> radix(vector<int> v){
    vector<string> words;
    for(int x : v){
        string xs="";
        while(x>=1){
            xs=char('0'+(x%10))+xs;
            x/=10;
        }
        while(xs.size()<12){
            xs = "0"+xs;
        }
        words.push_back(xs);
    }
    vector<string> res = words;
    vector<vector<string>> count(10,vector<string>(0));
    for(int pos=11;pos>=0;--pos){
        while(res.size()){
            count[res.back()[pos]-'0'].push_back(res.back());
            res.pop_back();
        }
        for(int val=0;val<=9;++val){
            while(count[val].size()){
                res.push_back(count[val].back());
                count[val].pop_back();
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=0;
    cin>>n;
    vector<int> foo(n);
    for(int &x :foo){
        cin>>x;
    }
    vector<string> res = radix(foo);
    for(string s : res){
        int pos=0;
        if(s!="000000000000"){
            while(s[pos]=='0'){
                ++pos;
            }
        }else{
            putchar('0');
            putchar(' ');
            continue;
        }
        for(int i=pos;i<s.size();++i){
            putchar(s[i]);
        }putchar(' ');
    }
}