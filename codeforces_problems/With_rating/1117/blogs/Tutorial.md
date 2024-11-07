# Tutorial

[1117A - Best Subsegment](../problems/A._Best_Subsegment.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int mx = -1, lenMx = 0;
	
	int curEl = -1, curLen = 0;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		
		if(curEl != a)
			curEl = a, curLen = 0;
		curLen++;
		
		if(mx < curEl)
			mx = curEl, lenMx = 0;
		if(mx == curEl)
			lenMx = max(lenMx, curLen);
	}
	cout << lenMx << endl;
	return 0;
}
```
[1117B - Emotes](../problems/B._Emotes.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	
	cout << m / (k + 1) * 1ll * (a[0] * 1ll * k + a[1]) + m % (k + 1) * 1ll * a[0] << endl;
	
	return 0;
}
```
[1117C - Magic Ship](../problems/C._Magic_Ship.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int N = 100009;

pair<int, int> st, fi;
int n;
string s;

string mv = "UDLR";
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

pair<int, int> d[N];

int main(){
	cin >> st.x >> st.y >> fi.x >> fi.y;
	cin >> n >> s;		

	for(int i = 0; i < n; ++i){
		int id = -1;
		for(int j = 0; j < 4; ++j)
			if(mv[j] == s[i])
				id = j;
		assert(id != -1);
		d[i + 1] = make_pair(d[i].x + dx[id], d[i].y + dy[id]);
	}

	long long l = 0, r = 1e18;
	while(r - l > 1){
		long long mid = (l + r) / 2;
		long long cnt = mid / n, rem = mid % n;
		long long x = st.x + d[rem].x + cnt *  1LL * d[n].x;
		long long y = st.y + d[rem].y + cnt *  1LL * d[n].y;
		long long dist = abs(x - fi.x) + abs(y - fi.y);
		if(dist <= mid)
			r = mid;
		else
			l = mid;	
	} 

	if(r > 5e17) r = -1;
	cout << r << endl;

	return 0;
}
```
[1117D - Magic Gems](../problems/D._Magic_Gems.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Reziba)**
```cpp
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define bolt ios::sync_with_stdio(0)
#define light cin.tie(0);cout.tie(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define MAXN 1000003
typedef long long ll;
using namespace std;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll inv_euclid(ll a, ll m = MOD){ll m0 = m;ll y = 0, x = 1;if (m == 1)return 0;while (a > 1){ll q = a / m;ll t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}

ll bin[103][103];

void mult_mat(ll m, ll ans[][100], ll bin[][100]){
    ll mult[m][m];
    forr(i,0,m){
        forr(j,0,m){
            mult[i][j]=0;
            forr(k,0,m){
                mult[i][j]+=ans[i][k]*bin[k][j];
                if(mult[i][j]>=MOD){
                    mult[i][j]%=MOD;
                }
            }
        }
    }
    forr(i,0,m){
        forr(j,0,m){
            ans[i][j]=mult[i][j];
        }
    }
}

void pow_mat(ll n, ll fin[][100], ll m){
    ll ans[m][100];
    ll b[m][100];
    forr(i,0,m){
        forr(j,0,m){
            ans[i][j]=bin[i][j];
            b[i][j]=bin[i][j];
        }
    }
    n--;
    while(n>0){
        if(n%2==1){
            mult_mat(m,ans,b);
            n--;
        }else{
            n=n/2;
            mult_mat(m,b,b);
        }
    }
    forr(i,0,m){
        forr(j,0,m){
            fin[i][j]=ans[i][j];
        }
    }
}

int main(){
    bolt;
    ll n,m;
    cin>>n>>m;
    bin[0][0]=1;
    bin[0][m-1]=1;
    for(ll i=1;i<m;i++){
        bin[i][i-1]=1;
    }
    if(n<m){
        cout<<1<<"n";
    }else{
        ll fin[m+1][100];
        pow_mat(n-m+1,fin,m);
        ll ans=0;
        forr(i,0,m){
            ans+=fin[0][i];
            if(ans>=MOD){
                ans-=MOD;
            }
        }
        cout<<ans<<"n";
    }
}
```
[1117E - Decypher the String](../problems/E._Decypher_the_String.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string t;
	cin >> t;
	int n = t.size();
	string s1(n, 'a'), s2(n, 'a'), s3(n, 'a');
	for(int i = 0; i < n; i++)
	{
		s1[i] = char('a' + (i % 26));
		s2[i] = char('a' + ((i / 26) % 26));
		s3[i] = char('a' + ((i / 26 / 26) % 26));
	}
	cout << "? " << s1 << endl;
	string t1;
	cin >> t1;
	cout << "? " << s2 << endl;
	string t2;
	cin >> t2;
	cout << "? " << s3 << endl;
	string t3;
	cin >> t3;
	vector<int> p(n);
	for(int i = 0; i < n; i++)
		p[i] = (t1[i] - 'a') + (t2[i] - 'a') * 26 + (t3[i] - 'a') * 26 * 26;
	string s(n, 'a');
	for(int i = 0; i < n; i++)
		s[p[i]] = t[i];
	cout << "! " << s << endl;
	return 0;
}
```
[1117F - Crisp String](../problems/F._Crisp_String.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 100 * 1000 + 13;
const int P = 17;

int n, p;
string s;
int A[P][P];
vector<int> pos[P];
int pr[P][N];
bitset<(1 << P)> legal, cur, dp;
int cnt[P];

int main() {
	scanf("%d%d", &n, &p);
	char buf[N];
	scanf("%s", buf);
	s = buf;
	forn(i, p) forn(j, p)
		scanf("%d", &A[i][j]);
	
	forn(i, n){
		pos[s[i] - 'a'].push_back(i);
		forn(j, p)
			pr[j][i + 1] = pr[j][i] + (s[i] == 'a' + j);
	}
	
	legal.reset();
	legal.flip();
	
	int fl = (1 << p) - 1;
	forn(c, p) forn(d, c + 1){
		if (A[c][d]) continue;
		cur.reset();
		cur.flip();
		int i = 0, j = 0;
		while (i < pos[c].size() && j < pos[d].size()){
			if (c == d && i == j){
				++j;
				continue;
			}
			int mask = 0;
			if (pos[c][i] < pos[d][j]){
				forn(e, p) if ((pr[e][pos[d][j]] - pr[e][pos[c][i] + 1]) != 0)
					mask |= (1 << e);
				++i;
			}
			else{
				forn(e, p) if ((pr[e][pos[c][i]] - pr[e][pos[d][j] + 1]) != 0)
					mask |= (1 << e);
				++j;
			}
			if ((mask >> c) & 1) continue;
			if ((mask >> d) & 1) continue;
			cur[mask ^ fl] = 0;
		}
		for (int mask = fl; mask > 0; --mask){
			if (cur[mask]) continue;
			forn(e, p) if (c != e && d != e && ((mask >> e) & 1))
				cur[mask ^ (1 << e)] = 0;
		}
		legal &= cur;
	}
	
	dp[fl] = 1;
	for (int mask = fl; mask > 0; --mask){
		if (!dp[mask]) continue;
		forn(i, p) if ((mask >> i) & 1){
			int nmask = mask ^ (1 << i);
			if (dp[nmask]) continue;
			dp[nmask] = legal[nmask];
		}
	}
	
	forn(i, n)
		++cnt[s[i] - 'a'];
	
	int ans = n;
	forn(mask, 1 << p) if (dp[mask]){
		int cur = 0;
		forn(i, p) if ((mask >> i) & 1)
			cur += cnt[i];
		ans = min(ans, cur);
	}
	
	printf("%dn", ans);
	
	return 0;
}
```
[1117G - Recursive Queries](../problems/G._Recursive_Queries.md "Educational Codeforces Round 60 (Rated for Div. 2)")

 **Tutorial**
### [1117G - Recursive Queries](../problems/G._Recursive_Queries.md "Educational Codeforces Round 60 (Rated for Div. 2)")

Let's denote $fl(l, r) = (m_{l,r} - l) + fl(l, m_{l,r} - 1) + fl(m_{l,r} + 1, r)$ and, analogically, $fr(l, r) = (r - m_{l,r}) + fr(l, m_{l,r} - 1) + fr(m_{l,r} + 1, r)$. Then, we can note that $f(l, r) = (r - l + 1) + fl(l, r) + fr(l, r)$. So we can switch to calculating $fl$ (and $fr$).

Let's $lf[i]$ be the closest from the left to $i$ element such that $a[lf[i]] > a[i]$. 

To calculate $fl(l, r)$ we will look from the other side: we will look at it as the sum of lengths of segments induced by each element from $[l, r]$. Each element $a_i$ ($l \le i \le r)$ will add to $fl(l, r)$ value equal to $\min(i - lf[i] - 1, i - l)$, or a piecewise linear function if we look at $l$ as a variable. And $fl(l, r)$ is a value of a sum of linear functions induced by $a[i]$ in a point $x = l$.

To process it efficiently we can one by one add induced linear functions to the corresponding subsegments using BIT or Segment Tree and if we've added functions induced by $a[k]$ we can calculate answer for all queries which looks like $(l_i, k)$.

To calculate $fr(l, r)$ we can just reverse array and all queries.

Result time complexity is $O((n + q) \log{n})$. Note, that it's still works quite slow, so you should use fast data structures like BIT of iterative segment tree.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

int n, q;
vector<int> a;
vector< pair<pt, int> > qs;

inline bool read() {
	if(!(cin >> n >> q))
		return false;
	a.resize(n);
	qs.resize(q);
	
	fore(i, 0, n)
		cin >> a[i];
	fore(i, 0, q) {
		cin >> qs[i].x.x;
		qs[i].x.x--;
	}
	fore(i, 0, q) {
		cin >> qs[i].x.y;
		qs[i].x.y--;
		qs[i].y = i;
	}
	return true;
}

bool cmp(const pair<pt, int> &a, const pair<pt, int> &b) {
	if(a.x.y != b.x.y)
		return a.x.y < b.x.y;
	if(a.x.x != b.x.x)
		return a.x.x < b.x.x;
	return a.y < b.y;
}

typedef pair<li, li> func;
func operator +=(func &a, const func &b) {
	a.x += b.x, a.y += b.y;
	return a;
}

vector<func> t;
void add(int l, int r, const func &f) {
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l & 1) t[l++] += f;
		if(r & 1) t[--r] += f;
	}
}
func sum(int pos) {
	func ans(0, 0);
	for(pos += n; pos > 0; pos >>= 1)
		ans += t[pos];
	return ans;
}

inline void solve() {
	vector<li> ans(q, 0);
	fore(i, 0, q)
		ans[i] = qs[i].x.y - qs[i].x.x + 1;
	fore(_, 0, 2) {
		vector<int> st;
		vector<int> lf(n, -1);
		fore(i, 0, n) {
			while(!st.empty() && a[st.back()] < a[i])
				st.pop_back();
			if(!st.empty())
				lf[i] = st.back();
			st.push_back(i);
		}
		
		sort(qs.begin(), qs.end(), cmp);
		t.assign(2 * n, {0, 0});
		
		int uk = 0;
		fore(i, 0, n) {
			add(0, lf[i] + 1, {0, i - lf[i] - 1});
			add(lf[i] + 1, i, {-1, i});
			
			while(uk < q && qs[uk].x.y == i) {
				auto f = sum(qs[uk].x.x);
				ans[qs[uk].y] += f.x * qs[uk].x.x + f.y;
				uk++;
			}
		}
		
		reverse(a.begin(), a.end());
		for(auto &p : qs) {
			p.x.x = n - 1 - p.x.x;
			p.x.y = n - 1 - p.x.y;
			swap(p.x.x, p.x.y);
		}
	}
	for(auto v : ans)
		cout << v << ' ';
	cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
