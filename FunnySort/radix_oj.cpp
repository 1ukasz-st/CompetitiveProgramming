#include<bits/stdc++.h>

using namespace std;

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

const int maxBucketSize = 1000000;

// number of digits in a positive integer - slightly modified function from https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
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

// returns the first d digits of a number (in out imagination, we convert numbers like 456 to 00...0456 so they have the same length - maxDigits )
inline constexpr int getpref(int x, int d, int maxDigits){
    int len = numDigits(x);
    int zeros = maxDigits-len;
    if(d+1<=zeros){
        return 0;
    }
    d -= zeros-1;
    d = len-d;
    return int(x/p10(d));
}

inline constexpr int getds(int x, int l, int r, int maxDigits){ // returns digits on positions [l...r] from a number, following the same logic as getpref
    return getpref(x,r,maxDigits) - (getpref(x,l-1,maxDigits)*p10(r-l+1));
}

vector<vector<int>> bucket(maxBucketSize,vector<int>(0));

inline void radix(vector<int> *v){
    int bucketSizeLog = 6;
    int maxDigits = 0; // max digits in numbers from the input
    for(int i=0;i<v->size();++i){
        int xv = (*v)[i];
        maxDigits = max(maxDigits,numDigits(xv));
    }
    int vals = p10(bucketSizeLog);
    for(int pos=0;pos<maxDigits;pos+=bucketSizeLog){
        while(v->size()){ 
            bucket[getds(v->back(),maxDigits-pos-bucketSizeLog,maxDigits-1-pos,maxDigits)].push_back(v->back());
            v->pop_back();
        }
        for(int val=0;val<vals;++val){
            while(bucket[val].size()){
                v->push_back(bucket[val].back());
                bucket[val].pop_back();
            }
        }
        if(maxDigits-pos < bucketSizeLog){
            bucketSizeLog = maxDigits-pos;
            vals = p10(bucketSizeLog);
        }
    }
    vals = p10(bucketSize);
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