#include<bits/stdc++.h>


using namespace std;


int main(){

    int t=0;
    cin>>t;
    while(t--){
        int n=0,k=0;
        cin>>n>>k;
        vector<int> arr(n);
        vector<vector<int>> moc(n+1,vector<int>(n+1,0)),dp(n+1,vector<int>(k+1,1e9));
        for(int &x : arr){
            cin>>x;
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                moc[i][j] = moc[i][j-1]+abs(arr[j-1]-arr[j]);
            }
        }
        //cout<<"XD"<<endl;
        for(int i=0;i<n;++i){
            dp[i][1] = moc[0][i];
            //cout<<"i: "<<i<<endl;
            for(int c=2;c<=k && c<=i+1;c++){
                //cout<<"c: "<<c<<endl;
                dp[i][c] = dp[i-1][c] + abs(arr[i]-arr[i-1]);
                for(int j=0;j<i;++j){
                    //cout<<"j: "<<j<<endl;
                    //cout<<i<<","<<c<<","<<j<<endl;
                    dp[i][c] = min(dp[i][c],dp[j][c-1]+moc[j+1][i]);
                }
            }
        }
        /*for(int i=0;i<n;++i){
            cout<<i<<" -> ";
            for(int j=1;j<=k;++j){
                cout<<j<<","<<dp[i][j]<<" ";
            }cout<<endl;
        }*/
        cout<<dp[n-1][k]<<endl;
    }   


    return 0;
}