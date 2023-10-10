#include<bits/stdc++.h>

using namespace std;

const int maxBucketSize = 100000;

vector<vector<int>> bucket_val(maxBucketSize,vector<int>(0));
vector<vector<int>> bucket_ori(maxBucketSize,vector<int>(0));

inline constexpr int p10(int p){ // returns 10^p
    switch(p){
        case 0:
            return 1;
        case 1:
            return 10;
        case 2:
            return 100;
        case 3:
            return 1000;
        case 4:
            return 10000;
        case 5:
            return 100000;
        case 6:
            return 1000000;
        case 7:
            return 10000000;
        case 8:
            return 100000000;
        case 9:
            return 1000000000;
    }

}

inline constexpr int numDigits(int x)
{
    if (x >= 10000) {
        if (x >= 10000000) {
            if (x >= 100000000) {
                if (x >= 1000000000)
                    return 10;
                return 9;
            }
            return 8;
        }
        if (x >= 100000) {
            if (x >= 1000000)
                return 7;
            return 6;
        }
        return 5;
    }
    if (x >= 100) {
        if (x >= 1000)
            return 4;
        return 3;
    }
    if (x >= 10)
        return 2;
    return 1;
}


inline void radix(vector<int> *v){
    int bucketSizeLog = 3;
    int maxDigits = 0;              // max digits in numbers from the input
    for(int i=0;i<v->size();++i){
        int xv = (*v)[i];
        maxDigits = max(maxDigits,numDigits(xv));
    }
    bucketSizeLog = min(5,maxDigits-1);
    int vals = p10(bucketSizeLog-1);
    vector<int> res(v->begin(),v->end());
    for(int pos=0;pos<maxDigits;pos+=bucketSizeLog){
        int ind=v->size() - 1;
        while(v->size()){ 
            int what = v->back();
            int where = what%vals;
            bucket_val[where].push_back(what);
            bucket_ori[where].push_back(res.back());
            v->pop_back();
            res.pop_back();
        }
        for(int val=0;val<vals;++val){
            while(bucket_val[val].size()){
                int curr = bucket_val[val].back();
                curr = (curr - (curr%vals)) / vals;
                if(pos+bucketSizeLog>=maxDigits){
                    v->push_back(bucket_ori[val].back());
                }else{
                    res.push_back(bucket_ori[val].back());
                    v->push_back(curr);
                }
                bucket_val[val].pop_back();
                bucket_ori[val].pop_back();
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=0;
    cin>>n;
    vector<int> foo(n);
    for(int &x :foo){
        cin>>x;
    }
    radix(&foo);
    for(int x : foo){
        cout<<x<<" ";
    }
}