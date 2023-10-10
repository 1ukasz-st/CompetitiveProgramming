#include<bits/stdc++.h>

using namespace std;

vector<int> res;

void rec(int k, int target_k, int sum, int target_sum){
    if(k==target_k){
      /*  for(int x : res){
            cout<<x<<" ";
        }cout<<endl; */
        return;
    }
    if(k==target_k-1){
        res.push_back(target_sum-sum);
        rec(k+1,target_k,target_sum,target_sum);
        res.pop_back();
        return;
    }
    for(int curr=0;curr<=target_sum-sum;++curr){
        res.push_back(curr);
        rec(k+1,target_k,sum+curr,target_sum);
        res.pop_back();
    }
}

int main(){

    rec(0,20,0,10);


    return 0;
}