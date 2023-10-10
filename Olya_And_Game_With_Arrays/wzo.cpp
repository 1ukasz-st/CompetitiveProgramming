#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int t = 0;
    cin>>t;
    while (t--) {
        int k = 0;
        cin >> k;
        vector<pair<ll, ll>> t(k, {1 + 1e9, 1 + 1e9});
        int smallest_max = 0;
        for (int i = 0; i < k; ++i) {
            int n = 0;
            cin >> n;
            for (int j = 0; j < n; ++j) {
                ll x = 0LL;
                cin >> x;
                if (x < t[i].first) {
                    t[i].second = t[i].first;
                    t[i].first = x;
                } else if (x < t[i].second) {
                    t[i].second = x;
                }
            }
            if (t[i].second < t[smallest_max].second) {
                smallest_max = i;
            }
        } // Correct placement of the closing brace for the inner for loop

        if (k == 1) {
            cout << t[smallest_max].first << endl;
            continue;
        }
        swap(t[smallest_max], t[0]);
        sort(t.begin() + 1, t.end());
        reverse(t.begin() + 1, t.end());
       /* for (auto [mi, ma] : t) {
            cout << mi << "," << ma << " ";
        } */
        ll ans = t[0].first;
        for (int i = 1; i < t.size(); ++i) {
            if (t[i].second == 1 + 1e9) {
                ans += t[i].first;
                continue;
            }
            ll ans2 = ans + t[i].second;
            if (t[i].first < t[0].first) {
                ans2 -= t[0].first;
                ans2 += t[i].first;
            }
            if (ans2 > ans) {
                t[0].first = min(t[0].first, t[i].first);
                ans = ans2;
            } else {
                ans = ans + t[i].first;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
