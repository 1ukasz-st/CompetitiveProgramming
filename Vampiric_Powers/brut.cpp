#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int N = (2e5)+3;

struct node {
    int curr=0;
    node * ls[2] = {NULL,NULL};
};

inline void nowe_slowo(node *root, int p) {
    node *ten = root;
    for (int i=31;i>=0;i--) {
        bool flag = (p&(1<<i));
        if (ten->ls[flag] == NULL)
            ten->ls[flag] = new node;
        ten = ten->ls[flag];
    }
    ten->curr = p;
}

inline int query(node * root, int p) {
    node *ten = root;
    for (int i=31;i>=0;--i) {
		bool flag = (p&(1<<i));
        if (ten->ls[1-flag] != NULL){
            ten=ten->ls[1-flag];
		}
        else if (ten->ls[flag] != NULL){
            ten=ten->ls[flag];
		}
    }
    return p^(ten->curr);
}

int n,T[2*N+3];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    int t=0;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;++i){
            cin>>T[i];
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int x=0;
            for(int j=i;j<n;++j){
                x^=T[j];
                ans = max(ans,x);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}