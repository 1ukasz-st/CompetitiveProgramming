#include<bits/stdc++.h>


using namespace std;

struct node{
    int ls[10],cnt=0;
    node(){
        for(int i=0;i<=9;++i){
            ls[i]=-1;
        }
    }
};

int tree_size=0;
vector<node> tree;

void add_element(string el){
    int curr=0,ind=0;
    while(ind<el.size()){
        bool found=false;
        int d = el[ind]-'0';
        int nxt = tree[curr].ls[d];
        if(nxt==-1){
            ++tree_size;
            tree[curr].ls[d] = tree_size;
            node added;
            tree.push_back(added);
            curr = tree_size;
        }else{
            curr = nxt;
        }
        if(ind+1==el.size()){
            tree[curr].cnt+=1;
        }
        ++ind;
    }
}

inline void dfs(int v, int c, vector<int> &el, vector<int> &res){
    if(v!=0)    el.push_back(c);
    if(tree[v].cnt>0){
        int p=pow(10,int(el.size()-1)),num=0;
        for(int i=0;i<el.size();++i){
            num += el[i]*p;
            p/=10;
        }
        el.pop_back();
        for(int i=0;i<tree[v].cnt;++i){
            res.push_back(num);
        }
        return;
    }
    for(int i=0;i<=9;++i){
        int x = tree[v].ls[i];
        if(x==-1){continue;}
        dfs(x,i,el,res);
    }
    if(v!=0)    el.pop_back();
}

vector<int> weird_sort(vector<int> v){
    tree_size=0;
    for(int x : v){
        string xs="";
        while(x>=1){
            xs=char('0'+(x%10))+xs;
            x/=10;
        }
        while(xs.size()<7){
            xs = "0"+xs;
        }
        add_element(xs);
    }
    vector<int> res,el;
    dfs(0,0,el,res);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=0;
    cin>>n;
    vector<int> foo(n);
    node start;
    tree.push_back(start);
    for(int &x :foo){
        cin>>x;
    }
    vector<int> bar = weird_sort(foo);
    for(int x : bar){
        cout<<x<<" ";
    }
}