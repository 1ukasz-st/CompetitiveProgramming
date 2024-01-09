#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (2e5)+3;

void print_arr(int a[], int n){
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }cout<<endl;
}

int main(){

    int n;
    cin>>n;
    vector<int> a(n-1);
    for(int &x : a){
        cin>>x;
    }
    int l = __lg(n);
    //cout<<endl<<l<<endl;
    vector<int*> arr_bit(l+1);
    vector<int*> arr_bit_inv(l+1);
    vector<int> res(n);
    for(int bit=0;bit<=l;++bit){
        arr_bit[bit] = (int*)calloc(n,sizeof(int)); // fuck c++
        arr_bit_inv[bit] = (int*)calloc(n,sizeof(int)); // fuck c++
        int pos = 1<<bit;
        int cnt1 = 0;
        for(int i=0;i<n;++i){
            cnt1 += i&pos;
        }
        arr_bit[bit][n-1] = (a.back()&pos)>0;
        arr_bit_inv[bit][n-1] = !(arr_bit[bit][n-1]);
        int c11=0,c12=0;
        for(int i=n-2;i>=0;--i){
            arr_bit[bit][i] = arr_bit[bit][i+1]^((a[i]&pos)>0);
            arr_bit_inv[bit][i] = !(arr_bit[bit][i]);
            c11+=arr_bit[bit][i];
            c12+=arr_bit_inv[bit][i];
        }
        if(c11==cnt1){
           // print_arr(arr_bit[bit],n);
            for(int i=0;i<n;++i){
                res[i]+=pos*arr_bit[bit][i];
            }
        }else{
          //  print_arr(arr_bit_inv[bit],n);
            for(int i=0;i<n;++i){
                res[i]+=pos*arr_bit_inv[bit][i];
            }
        }
    } 
    for(int x : res){
        cout<<x<<" ";
    }
    for(int bit=0;bit<l;++bit){
        free(arr_bit[bit]);  // fuck c++ 
        free(arr_bit_inv[bit]); // fuck c++
    }
    return 0;
}