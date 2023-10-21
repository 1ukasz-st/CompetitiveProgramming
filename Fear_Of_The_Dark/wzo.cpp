#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 0.0000001;

typedef struct{
    ld x=0.0,y=0.0;
} point;

ld sqdist(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); 
}

bool in(point p, point mid, ld rad){
    return rad * rad - sqdist(p, mid) > EPS;
}

bool circles_intersect(point mid1, point mid2, ld rad){
    return 4.0*rad*rad - sqdist(mid1,mid2) > EPS;
}

int main(){


    point O;
    O.x=0;
    O.y=0;

    int q;
    cin>>q;
    while(q--){
        point P,A,B;
        int px=0,py=0,ax=0,ay=0,bx=0,by=0;
        cin>>px>>py;
        cin>>ax>>ay;
        cin>>bx>>by;
        P.x=px; P.y=py;
        A.x=ax; A.y=ay;
        B.x=bx; B.y=by;
        ld l=0.0,r=5000.0,ans=5000.0;
        while(r-l > EPS){
            ld w = (l+r)*0.5;
            bool pa = in(P,A,w), pb = in(P,B,w);
            bool oa = in(O,A,w), ob = in(O,B,w);
            bool inter = circles_intersect(A,B,w);
            //cout<<w<<" "<<pa<<","<<pb<<" "<<oa<<","<<ob<<" "<<int(inter)<<endl;
            if(pa && oa){
                ans = min(ans,w);
                r = w-EPS;
                continue;
            }
            if(pb && ob){
                ans = min(ans,w);
                r = w-EPS;
                continue;
            }
            if(((pa && ob) || (pb && oa)) && inter){
                ans = min(ans,w);
                r = w-EPS;
                continue;
            }
            l = w+EPS;            
        }
        cout<<fixed<<setprecision(7)<<ans<<endl;       
    }


    return 0;
}