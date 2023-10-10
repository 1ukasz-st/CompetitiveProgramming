#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

inline constexpr int p10(int p){
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

inline constexpr int getpref(int x, int d){
    int len = int(log10(x))+1;
    int zeros = 10-len;
    if(d+1<=zeros){
        return 0;
    }
    d -= zeros-1;
    d = len-d;
    return int(x/p10(d));
}

inline constexpr int getds(int x, int l, int r){
    return getpref(x,r) - (getpref(x,l-1)*p10(r-l+1));
}

int dig=1;
int vals = p10(dig);
vector<vector<int>> bucket(vals,vector<int>(0));

void radix(vector<int> *v){
    for(int pos=0;pos<=9;pos+=dig){
        while(v->size()){
            bucket[getds(v->back(),9-pos-dig+1,9-pos)].push_back(v->back());
            v->pop_back();
        }
        for(int val=0;val<vals;++val){
            while(bucket[val].size()){
                v->push_back(bucket[val].back());
                bucket[val].pop_back();
            }
        }
        if(9-pos+1 < dig){
            dig = 9-pos+1;
            vals = p10(dig);
        }
    }
    vals = p10(dig);
}