# Tutorial_(en)

Tutorial is loading... **Code**
```cpp
#include <bits/stdc++.h>
#define N 510
using namespace std;

char a[N][N];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s", a[i] + 1);
	}
	
	int ans = 0;
	for (int i = 2; i < n; i++){
		for (int j = 2; j < n; j++){
			if (a[i][j] == 'X' && a[i - 1][j - 1] == 'X' && a[i - 1][j + 1] == 'X'
				&& a[i + 1][j - 1] == 'X' && a[i + 1][j + 1] == 'X'){
				ans ++;	
			}
		}
	}
	printf("%dn", ans);
	return 0;
} 
```
 Tutorial is loading... **Code**
```cpp
#include <bits/stdc++.h>
#define N 300010
#define PII pair<int, int> 
using namespace std;

typedef long long LL;

int n, m, a[N], c[N], t, d;
LL ans = 0;

priority_queue<PII, vector<PII>, greater<PII> > Q;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		Q.push(make_pair(c[i], i));
	}
	
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &t, &d);
		if (d <= a[t]){
			a[t] -= d;
			printf("%lldn", 1LL * d * c[t]);
		} else {
			bool flag = false;
			LL ans = 1LL * a[t] * c[t];
			d -= a[t];
			a[t] = 0;
			while (!Q.empty()){
				while (!Q.empty() && a[Q.top().second] == 0) Q.pop();
				if (Q.empty()) break;
				PII now = Q.top();
				if (d <= a[now.second]){
					a[now.second] -= d;
					ans += 1LL * d * now.first;
					flag = true;
					printf("%lldn", ans);
					break;
				} else {
					ans += 1LL * a[now.second] * now.first;
					d -= a[now.second];
					a[now.second] = 0;
					Q.pop();
				}
			}
			
			if (!flag){
				puts("0");
			}
		}
	}
}
```
 Tutorial is loading... **Code**
```cpp
#include <bits/stdc++.h>
#define N 300010
using namespace std;

typedef long long LL;

int n, a[N];
LL ans = 0;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n / 2; i++){
		ans += 1LL * (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
	}
	printf("%lldn", ans);
	return 0;
}
```
 Tutorial is loading... **Code**
```cpp
#include <bits/stdc++.h>
#define N 300010
using namespace std;

typedef long long LL;

priority_queue<int, vector<int>, greater<int> > Q;
vector<int> e[N];
vector<int> seq;
bool vis[N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	vis[1] = true;
	Q.push(1);
	while (!Q.empty()){
		int now = Q.top();
		Q.pop();
		seq.push_back(now);
		for (auto p : e[now]){
			if (!vis[p]){
				Q.push(p);
				vis[p] = true;
			}
		}
	}
	
	for (auto p : seq){
		printf("%d ", p);
	}
	puts("");
	return 0;
}
```
 Tutorial is loading... **Code**
```cpp
#include <bits/stdc++.h>
#define N 100010
using namespace std;

typedef long long LL;

struct Event{
	int d, w, t;
	
	bool operator < (const Event &e) const {
		return w > e.w || (w == e.w && d > e.d);
	}
};

vector<Event> e[N];
Event a[N];
map<Event, int> cur;
int n, m, k;

LL f[2][N], ans = 0x3f3f3f3f3f3f3f3fLL;

void insert(Event x){
	if (cur.count(x)){
		cur[x] ++;
	} else {
		cur[x] = 1;
	}
}

void erase(Event x){
	cur[x] --;
	if (cur[x] == 0){
		cur.erase(x);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++){
		int s, t, d, w;
		scanf("%d%d%d%d", &s, &t, &d, &w);
		e[s].push_back((Event){d, w, 1});
		e[t + 1].push_back((Event){d, w, -1});
	}
	
	for (int i = 1; i <= n; i++){
		for (auto p : e[i]){
			if (p.t == 1){
				insert(p);
			} else {
				erase(p);
			}
		}
		
		if (cur.size()){
			a[i] = (*cur.begin()).first;
		} else {
			a[i] = (Event){i, 0, 0};
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0][1] = 0;
	for (int j = 0; j <= m; j++){
		memset(f[(j ^ 1) & 1], 0x3f, sizeof(f[(j ^ 1) & 1]));
		for (int i = 1; i <= n; i++){
			f[(j ^ 1) & 1][i + 1] = min(f[(j ^ 1) & 1][i + 1], f[j & 1][i]);
			f[j & 1][a[i].d + 1] = min(f[j & 1][a[i].d + 1], f[j & 1][i] + a[i].w);
		}
		ans = min(ans, f[j & 1][n + 1]);
	}
	printf("%lldn", ans);
	return 0;
}
```
 Tutorial is loading... **Code**
```cpp
#include <bits/stdc++.h>
#define N 210
using namespace std;
typedef long long LL;

const LL p = 998244353;
const LL g = 3;

int k;
LL n, m, b[N];

struct Matrix{
	int n;
	LL mat[N][N];
	
	Matrix(){
		n = 0;
		memset(mat, 0, sizeof(mat));
	}
	
	Matrix(int _n, LL diag){
		n = _n;
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= n; i++){
			mat[i][i] = diag;
		}
	}
	
	Matrix(const Matrix &c){
		n = c.n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				mat[i][j] = c.mat[i][j];
			}
		}
	}
	
	Matrix operator * (const Matrix &a) const {
		Matrix ans = Matrix(n, 0);
		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					ans.mat[i][j] += mat[i][k] * a.mat[k][j];
					ans.mat[i][j] %= (p - 1);
				}
			}
		}
		return ans;
	}
	
	Matrix mat_pow(LL t){
		Matrix base = Matrix(*this), ans = Matrix(n, 1);
		while (t){
			if (t & 1){
				ans = ans * base;
			}
			base = base * base;
			t >>= 1;
		}
		return ans;
	}

};

namespace GCD{
	LL gcd(LL a, LL b){
		if (!b) return a;
		return gcd(b, a % b);
	}
	
	LL ex_gcd(LL a, LL b, LL &x, LL &y){
		if (!b){
			x = 1; y = 0;
			return a;
		}
		
		LL q = ex_gcd(b, a % b, y, x);
		y -= a / b * x;
		return q;
	}
}

namespace BSGS{
	LL qpow(LL a, LL b, LL p){
		LL ans = 1, base = a;
		while (b){
			if (b & 1){
				(ans *= base) %= p;
			}
			(base *= base) %= p;
			b >>= 1;
		}
		return ans;
	}
	
	LL inv(LL x, LL p){
		return qpow(x, p - 2, p);
	}
	
	map<LL, LL> tab;
	LL bsgs(LL a, LL b, LL p){
		LL u = (LL) sqrt(p) + 1;
		LL now = 1, step;
		for (LL i = 0; i < u; i++){
			LL tmp = b * inv(now, p) % p;
			if (!tab.count(tmp)){
				tab[tmp] = i;
			}
			(now *= a) %= p;
		}
		step = now;
		now = 1;
		for (LL i = 0; i < p; i += u){
			if (tab.count(now)){
				return i + tab[now];
			}
			(now *= step) %= p;
		}
		throw;
		return -1;
	}
}

namespace SOL{
	LL solve(LL a, LL b, LL c){
		if (c == 0) return 0;
		LL q = GCD::gcd(a, b);
		if (c % q){
			return -1;
		}
		a /= q, b /= q, c /= q;
		LL ans, _;
		GCD::ex_gcd(a, b, ans, _);
		(ans *= c) %= b;
		while (ans < 0) ans += b;
		return ans;
	}
}

int main(){
	scanf("%d", &k);
	for (int i = 1; i <= k; i++){
		scanf("%d", &b[i]);
		b[i] %= (p - 1);
	}
	
	scanf("%lld%lld", &n, &m);
	
	Matrix A = Matrix(k, 0);
	for (int i = 1; i <= k; i++){
		A.mat[1][i] = b[i];
	}
	
	for (int i = 2; i <= k; i++){
		A.mat[i][i - 1] = 1;
	}
	
	A = A.mat_pow(n - k);
	
	LL ans = SOL::solve(A.mat[1][1], p - 1, BSGS::bsgs(g, m, p));
	if (ans >= 0){
		printf("%lldn", BSGS::qpow(g, ans, p));
	} else {
		puts("-1");
	}
	return 0;
}
```
