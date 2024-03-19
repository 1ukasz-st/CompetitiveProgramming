#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'
#define int long long
#define NO {puts("NO"); return;}
#define YES {puts("YES"); return;}

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e6 + 10, INF = 1e18; 

int n, m;
int a[N], b[N];
int fact[N], infact[N];

int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int qmi(int x, int y)
{
	int res = 1 % m;
	while(y)
	{
		if(y & 1) res = res * x % m;
		y >>= 1;
		x = x * x % m;
	}
	return res;
}

int C(int a, int b)
{
	return fact[a] * infact[b] % m * infact[a - b] % m;
}

void solve()
{
	int ans = 0;
	cin >> n >> m; 
	fact[0] = 1, infact[0] = 1;
	for(int i = 1; i <= n; i ++ ) 
	{
		fact[i] = fact[i - 1] * i % m;
		infact[i] = qmi(fact[i], m - 2);
	}
	int t = n / 2;
	int len = n - 2;
	for(int i = t; i <= n - 2; i ++ )
		for(int j = 0; j <= n - i - 2; j ++ )
			ans += (2 * t - i) % m * fact[i + j - 1] % m * C(n - i - 2, j) % m, ans %= m;
	if(1 ^ n & 1) ans += fact[n - 2] % m, ans %= m;
	cout << (ans * n) % m << endl;
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t = 1;
	while(t -- ) solve();
	return 0;
}