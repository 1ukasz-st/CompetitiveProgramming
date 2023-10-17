#include<bits/stdc++.h>


using namespace std;

const int N = (2e5)+3;

int n,l,r,curr_max=-1,T[N+3],end_pref[N+3],end_suf[N+3];

int main(){

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>T[i];
    }
    T[0]=-1e9;
    for(int i=1;i<=n;++i){
        end_suf[i] = (T[i]<T[i-1] ? end_suf[i-1] : i);
    }
    T[n+1]=-1e9;
    for(int i=n;i>=1;--i){
        end_pref[i] = (T[i]<T[i+1] ? end_pref[i+1] : i);
    }

    l=1;
    r=n;
    int ruch=0;
    for(int k=0;k<=n;++k){ 
        int tl = T[l], tr = T[r];
        if(max(tl,tr) <= curr_max){
            break;
        }
        bool wygramy = false;
        if(T[l]==T[r]){
            // Chcemy wiedziec, czy obecnie grajacy gracz przegra w tej pozycji
            // bierzemy lewego {
                int r2 = min(end_pref[l],r-1 + (l==r));
                if((r2-l+1)&1){
                    wygramy = true;
                }
            // }  koniec przypadku   

            // bierzemy prawego {
                int l2 = max(end_suf[r],l+1 - (l==r));
                if((r-l2+1)&1){
                    wygramy = true;
                }
            // }  koniec przypadku   
            if(!wygramy){
                if(ruch==0){
                    cout<<"Bob";
                    return 0;
                }else{
                    cout<<"Alice";
                    return 0;
                }
            }
            break;
        }
        if(tl > tr && tl > curr_max){ // patrzymy czy wygramy jesli usuniemy lewego (usuniecie prawego w tej sytuacji powoduje zwykłą grę dalej)
            int r2 = min(end_pref[l],r-1);
            if((r2-l+1)&1){
                wygramy = true;
            }else if(tr <= curr_max){
                if(ruch==0){
                    cout<<"Bob";
                    return 0;
                }else{
                    cout<<"Alice";
                    return 0;
                }
            }
        }
        else if(tr > curr_max){ // patrzymy czy wygramy jesli usuniemy prawego (usuniecie lewego w tej sytuacji powoduje zwykłą grę dalej)
            int l2 = max(end_suf[r],l+1);
            if((r-l2+1)&1){
                wygramy = true;
            }else if(tl <= curr_max){
                if(ruch==0){
                    cout<<"Bob";
                    return 0;
                }else{
                    cout<<"Alice";
                    return 0;
                }
            }
        }
        if(wygramy){
            if(ruch==0){
                cout<<"Alice";
                return 0;
            }else{
                cout<<"Bob";
                return 0;
            }
        }
        if(tl<tr && tl > curr_max){
            curr_max = max(curr_max,tl);
            ++l;
        }else{
            curr_max = max(curr_max,tr);
            --r;
        }
        ruch = (ruch+1)%2;
    }
    if(ruch==0){
        cout<<"Alice";
        return 0;
    }else{
        cout<<"Bob";
        return 0;
    }
    return 0;
}
