#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1'00'000;
const string X = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string Y =  "What are you doing while sending \"";
const string Z = "\"? Are you busy? Will you send \"";
const string U = "\"?";

ll s(string st){
    return (ll)(st.size());
}

ll len[N+1];
map<pair<int,ll>,char> wyn;

char rek(int krok, ll zost){
    if(wyn.find({krok,zost})!=wyn.end()){
        return wyn[{krok,zost}];
    }
    //cout<<"##"<<krok<<" "<<zost<<" -> ";
    if(krok==0){
      //  cout<<"1"<<endl;
        return X[zost-1];

    }else if(zost<=s(Y)){
        //cout<<"2"<<endl;
        return Y[zost-1];

    }else if(len[krok-1]==-1 || zost<=s(Y)+len[krok-1]){
        //cout<<"3"<<endl;
        return rek(krok-1,zost-s(Y));

    }else if(zost<=s(Y)+len[krok-1]+s(Z)){
        //cout<<"4"<<endl;
        return Z[zost-s(Y)-len[krok-1]-1];

    }else if(zost<=s(Y)+len[krok-1]+s(Z)+len[krok-1]){
        //cout<<"5"<<endl;
        return rek(krok-1,zost-s(Y)-len[krok-1]-s(Z));

    }else{
        //cout<<"6"<<endl;
        return U[zost-s(Y)-len[krok-1]-s(Z)-len[krok-1]-1];
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    len[0] = s(X);
    for(int i=1;i<=N;++i){
        if(len[i-1]==-1){len[i]=-1;continue;}
        len[i] = s(Y)+len[i-1]+s(Z)+len[i-1]+s(U);
        if(len[i]<0 || len[i]>1'000'000'000'000'000'000){
            len[i]=-1;
        }
    }

    int q=0;
    cin>>q;
    while(q--){
        int n=0;
        ll k=0LL;
        cin>>n>>k;
        if(len[n]<k && len[n]!=-1){
            cout<<".";
        }else{
            cout<<rek(n,k);
        }
    }

}