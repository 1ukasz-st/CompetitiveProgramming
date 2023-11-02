#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void chk(vector<ll> v){
    ll range = v.back()-v[0];
    ll sum=0LL;
    set<ll> sv;
    for(ll x : v){
        sum+=x;
        sv.insert(x);
    }
    if(range*range != sum || sv.size()!=v.size()){
        cout<<"BAD BAD BAD"<<endl;
    }
}

int main(){

    int q;
    cin>>q;
    vector<pair<ll,int>> zap;
    vector<vector<ll>> ans(q);
    for(int i=0;i<q;++i){
        ll x=0;
        cin>>x;
        zap.push_back({x,i});
    }
    sort(zap.begin(),zap.end());

    auto floor_div = [](ll a, ll b){
        return ll(a/b);
    };
    auto ceil_div = [](ll a, ll b){
        return ll((a+b-1)/b);
    };
    auto sum_range = [](ll a, ll b){
        return (b*(b+1) - (a-1)*a)/2;
    };
    auto is_avg_good = [sum_range](ll l, ll s, ll n, ll avg, vector<ll> &res){ // 1 - too big, -1 - too small, 0 - ok
        ll len = min(avg-1,s-1-avg);
        ll available_elements = len*2 + 1;
        if(available_elements < n-2){
            if(avg-1 < s-1-avg){
                return 1;
            }else{
                return -1;
            }
        }
        ll sum = sum_range(avg-len,avg+len) - (n&1 ? 0 : avg);
        ll total = 0+sum+s + n*l;
        if(total == s*s){
            res.push_back(l+0);
            for(ll i=avg-len;i<=avg+len;++i){
                if(i!=avg || n&1){
                    res.push_back(l+i);
                }
            }
            res.push_back(l+s);
            return 0;
        }else if(total < s*s){
            ll max_to_add = s-1 - (avg+len);
            if(total+max_to_add >= s*s){
                res.push_back(l+0);
                for(int i=avg-len;i<avg+len;++i){
                    if(i!=avg || n&1){
                        res.push_back(l+i);
                    }
                }
                res.push_back(l+avg+len + s*s-total);
                res.push_back(l+s);
                return 0;
            }else{
                return -1;
            }
        }else{ //total > s*s{
            int max_to_substract = (avg-len) - 1;
            if(total-max_to_substract <= s*s){
                res.push_back(l+0);
                res.push_back(l+avg-len - (total-s*s));
                for(ll i=avg-len+1;i<=avg+len;++i){
                    if(i!=avg || n&1){
                        res.push_back(l+i);
                    }
                }
                res.push_back(l+s);
                return 0;
            }else{
                return 1;
            }
        }
    };

    ll s=2;
    for(auto [n,zap_ind] : zap){
        //cout<<"zapytanie: n="<<n<<endl;
        if(n==2){
            ans[zap_ind] = {1,3};
            continue;
        }
        while(true){
            ll min_l = 1, max_l = ll( (s*s - s)/n );
            //cout<<"  s*s = "<<s*s<<endl;
            //cout<<"  l nal do ["<<min_l<<","<<max_l<<"]"<<endl;
            if(max_l<min_l){
                ++s;
                continue;
            }
            while(min_l <= max_l){
                ll l = (min_l + max_l)/2;
                ll avg = floor_div(s*s - s - n*l, n-2);
                vector<ll> res;
                ll a = is_avg_good(l,s,n,avg,res);
                //cout<<"    (pod) l: "<<l<<" avg: "<<avg<<"|"<<a<<endl;
                if(a==-1){
                    min_l = l+1;
                }else if(a==1){
                    max_l = l-1;
                }else{
                    ans[zap_ind] = res;
                    break;
                }
            }
            if(ans[zap_ind].size()){
                break;
            }
            min_l = 1; max_l = ll( (s*s - s)/n );
            while(min_l <= max_l){
                ll l = (min_l + max_l)/2;
                ll avg = ceil_div(s*s - s - n*l, n-2);
                vector<ll> res;
                ll a = is_avg_good(l,s,n,avg,res);
                //cout<<"    (suf) l: "<<l<<" avg: "<<avg<<"|"<<a<<endl;
                if(a==-1){
                    min_l = l+1;
                }else if(a==1){
                    max_l = l-1;
                }else{
                    ans[zap_ind] = res;
                    break;
                }
            }
            if(ans[zap_ind].size()){
                break;
            }
            ++s;
        }
    }

    for(vector<ll> v : ans){
        //chk(v);
        for(ll x : v){
            cout<<x<<" ";
        }cout<<endl;
    }

    return 0;
}