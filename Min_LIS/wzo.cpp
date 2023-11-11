#include<bits/stdc++.h>

using namespace std;

const int M = 1<<19;

int D[M*2];



void add(int v, int val){
	v+=M;
    D[v] = val;
	while(v>=1){
		v/=2;
        D[v] = max(D[2*v],D[2*v+1]);
	} 
}

int maxp(int v, int p_b, int k_b, int p_p, int k_p){
	if(p_b>k_p || k_b<p_p) return 0;
	if(p_b>=p_p && k_b<=k_p){
		return D[v];
	}
	int srodek=(p_b+k_b)/2;	
	return max(maxp(2*v, p_b, srodek, p_p, k_p),maxp(2*v+1, srodek+1, k_b, p_p, k_p));
}

void conv(){
	
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q=0;
    cin>>q;

    while(q--){

        vector<int> t,t2;
        map<int,int> con,decon;

        int n=0,m=0;
        cin>>n>>m;

        for(int i=0;i<=n+m;++i){
            add(i,0);
        }

        vector<int> b(m);
        for(int i =0 ;i<n;i++){
            int a=0;
            cin>>a;
            t.push_back(a);
            t2.push_back(a);
        }
        for(int &x : b){
            cin>>x;
            t2.push_back(x);
        }  
              
        sort(t2.begin(),t2.end());

        int k = 0;
        con[t2[0]]=k;
        decon[k] = t2[0];
        for(int i = 1;i<int(t2.size());i++){
            if(t2[i]>t2[i-1]){
                k += 1;
            }
            con[t2[i]]=k;
            decon[k] = t2[i];
        }
        for(int i =0 ;i<int(t.size());i++){
            t[i]=con[t[i]];
        }

        int lis = 0;

        vector<int> najl(n);
        vector<int> poc;
        
        for(int i = int(t.size()-1);i>=0;i--){
            najl[i] = maxp(1,0,M-1,t[i]+1,M-1)+1;
            lis = max(lis,najl[i]);
            add(t[i],najl[i]);
        }

        for(int i=0;i<n;++i){
            if(najl[i]==lis){
                poc.push_back(i);
            }
        }
        vector<vector<int>> przed(n+1);

        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());

        int j=0;
        //cout<<"!"<<poc.size()<<"!"<<endl;
        for(int x : b){
           // cout<<"#"<<x<<" -> ";
            while(j<poc.size() && t[poc[j]] > con[x]){
               ++j;
              // cout<<j<<",";
               if(j==poc.size()){
                break;
               }
            }//cout<<" | "<<j<<endl;
            if(j==poc.size()){
                przed.back().push_back(x);
            }else{
                przed[poc[j]].push_back(x);
            }
           //cout<<"NEXT"<<endl;
        }
        for(int i=0;i<n;++i){
            for(int x : przed[i]){
                cout<<x<<" ";
            }
            cout<<decon[t[i]]<<" ";
        }
        for(int x : przed.back()){
            cout<<x<<" ";
        }
        cout<<endl;
    }
	
	return 0;
	
}