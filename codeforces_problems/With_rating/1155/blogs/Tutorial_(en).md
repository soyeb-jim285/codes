# Tutorial_(en)

[1155A - Reverse a Substring](../problems/A._Reverse_a_Substring.md "Educational Codeforces Round 63 (Rated for Div. 2)")

 **Tutorial**
### [1155A - Reverse a Substring](../problems/A._Reverse_a_Substring.md "Educational Codeforces Round 63 (Rated for Div. 2)")

If the answer is "YES" then we always can reverse a substring of length $2$. So we need to check only pairs of adjacent characters in $s$. If there is no such pair of characters $s_i > s_{i + 1}$ for all $i$ from $1$ to $n-1$ then the answer is "NO".

Why is it so? Consider the substring $s[l; r] = s_l s_{l+1} \dots s_r$ we have to reverse. It is obvious that $s_l > s_r$, otherwise it is pointless to reverse this substring. Then consider two cases: $s_l \le s_{l+1}$ then $s_{l+1} > s_r$ (by transitivity) and then we can go to a smaller substring ($s[l + 1; r]$); otherwise $s_l > s_{l + 1}$ and it means that we can take the substring $s[l; l + 1]$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s;
	cin >> n >> s;
	
	for (int i = 1; i < int(s.size()); ++i) {
		if (s[i] < s[i - 1]) {
			cout << "YES" << endl;
			cout << i << " " << i + 1 << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;

	return 0;
}
```
[1155B - Game with Telephone Numbers](../problems/B._Game_with_Telephone_Numbers.md "Educational Codeforces Round 63 (Rated for Div. 2)")

 **Tutorial**
### [1155B - Game with Telephone Numbers](../problems/B._Game_with_Telephone_Numbers.md "Educational Codeforces Round 63 (Rated for Div. 2)")

Let's understand how players should act. 

Vasya needs to delete the first digit that is not equal to 88, because the first digit of telephone number should be 88, and the first digit not equal to 88 is preventing it.

Petya needs to delete the first digit equal to 88, for the same reasons.

So, all that we need to do is delete first n−112n−112 digits not equal to 88 (if they exist), and first n−112n−112 digits equal to 88 (again if they exist). It's enough to stop when there is either no 88's left or no non-88's because the latter moves won't change the result of the game anyway. Finally, if first digit of resulting string is 88, then Vasya wins, otherwise Petya.

Overall complexity: O(n)O(n).

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
    cin >> n >> s;
    int cnt1 = (n - 11) / 2;
    int cnt2 = cnt1;
    string res = "";
    for(int i = 0; i < n; ++i){
        if(s[i] == '8'){
            if(cnt1 > 0) --cnt1;
            else res += s[i];
        }
        else{
            if(cnt2 > 0) --cnt2;
            else res += s[i];
        }
    }
    
    if(res[0] == '8') cout << "YESn";
    else cout << "NOn";
	return 0;
}
```
[1155C - Alarm Clocks Everywhere](../problems/C._Alarm_Clocks_Everywhere.md "Educational Codeforces Round 63 (Rated for Div. 2)")

 **Tutorial**
### [1155C - Alarm Clocks Everywhere](../problems/C._Alarm_Clocks_Everywhere.md "Educational Codeforces Round 63 (Rated for Div. 2)")

It is obvious that we can always take x1 as y. But we don't know which value of p we can take. Let di be xi+1−xi for all i from 1 to n−1. The value of p should be divisor of each value of di. The maximum possible divisor of each di is g=gcd(d1,d2,…,dn−1) (greatest common divisor). And then it is obvious that the value of p should be the divisor of g. So we have to find any divisor of g among all values pj. If there is no such value then the answer is "NO".

Time complexity: O(nlogn).

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<long long> x(n), p(m);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
	}
	
	long long g = x[1] - x[0];
	for (int i = 2; i < n; ++i) {
		g = __gcd(g, x[i] - x[i - 1]);
	}
	
	for (int i = 0; i < m; ++i) {
		if (g % p[i] == 0) {
			cout << "YES" << endl;
			cout << x[0] << " " << i + 1 << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}
```
[1155D - Beautiful Array](../problems/D._Beautiful_Array.md "Educational Codeforces Round 63 (Rated for Div. 2)")

 **Tutorial**
### [1155D - Beautiful Array](../problems/D._Beautiful_Array.md "Educational Codeforces Round 63 (Rated for Div. 2)")

The first intuitive guess one's probably made is multiplying the segment of maximum sum for positive $x$. That thing is correct. Unfortunately, there is no similar strategy for non-positive $x$, simple greedy won't work there.

Thus, dynamic programming is our new friend. Let's introduce the following state: $dp[pos][state_{max}][state_{mul}]$, where $pos$ is the length of the currently processed prefix, $state_{max}$ is the state of maximum sum segment ($0$ is not reached, it'll appear later, $1$ is open, current elements are added to it, $2$ is passed, the segment appeared earlier) and $state_{mul}$ is the state of segment multiplied by $x$ with the same values. This $dp$ will store the maximum segment sum we can achieve.

The only base state is $dp[0][0][0] = 0$ — the prefix of length $0$ is processed and both segments are not open yet. The rest of values in $dp$ are $-\infty$.

There are two main transitions. At any moment we can change the state of each segment to the next one without moving to the next position. From state $0$ (not reached) we can go to state $1$ (opened) and from state $1$ we can go to state $2$ (passed). Note that this easily covers the case where optimal segment is empty. We can also move to the next position updating the value of $dp$ with correspondance to the current states of segments.

The answer will be stored in $dp[n][2][2]$ — the state where all the array is processed and both segments are closed.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

typedef long long li;

const int N = 300 * 1000 + 13;
const li INF64 = 1e18;

int n, x;
int a[N];

li dp[N][3][3];

int main() {
	scanf("%d%d", &n, &x);
	forn(i, n) scanf("%d", &a[i]);
	
	forn(i, n + 1) forn(j, 3) forn(k, 3)
		dp[i][j][k] = -INF64;
	
	dp[0][0][0] = 0;
	forn(i, n + 1) forn(j, 3) forn(k, 3){
		if (k < 2)
			dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
		if (j < 2)
			dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
		if (i < n)
			dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * li(k == 1 ? x : 1));
	}
	
	printf("%lldn", dp[n][2][2]);
}
```
[1155E - Guess the Root](../problems/E._Guess_the_Root.md "Educational Codeforces Round 63 (Rated for Div. 2)")

 **Tutorial**
### [1155E - Guess the Root](../problems/E._Guess_the_Root.md "Educational Codeforces Round 63 (Rated for Div. 2)")

Since $10^6 + 3$ is a prime and degree $k$ of the polynomial is small enough, we can get this polynomial in our hands asking $k + 1$ queries in different points. Knowing values $f(x_i)$ for $x_1, x_2, \dots, x_{k + 1}$, we can interpolate $f$ by various ways. 

For example, we can construct a system of linear equations thinking of $a_i$ as variables. In other words, we know, that $a_0 \cdot x_i^0 + a_1 \cdot x_i^1 + \dots + a_k \cdot x_i^k = f(x_i)$ for $i = 1 \dots (k+1)$, also we know $x_i^l$ and $f(x_i)$. So we can solve this system using Gaussian elimination in $O(k^3)$.

Now, knowing the polynomial $f(x)$ we can locally brute force all possible candidates for $x_0$, since there is only $10^6 + 3$ such candidates, and print the one we found.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int MOD = 1000 * 1000 + 3;

int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int binPow(int a, int k) {
	int ans = 1;
	while(k > 0) {
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}
int inv(int a) {
	return binPow(a, MOD - 2);
}

int k = 10;
vector<int> f;

int main() {
	f.resize(k + 1);
	fore(i, 0, sz(f)) {
		cout << "? " << i << endl;
		cout.flush();
		cin >> f[i];
	}
	
	vector< vector<int> > mat(sz(f), vector<int>(sz(f) + 1));
	fore(i, 0, sz(mat)) {
		mat[i][0] = 1;
		mat[i][sz(f)] = f[i];
		
		fore(j, 1, sz(mat[i]) - 1)
			mat[i][j] = mul(mat[i][j - 1], i);
	}
	
	/*
	fore(i, 0, sz(mat)) {
		fore(j, 0, sz(mat[i]))
			cerr << mat[i][j] << " ";
		cerr << endl;
	}
	*/
	
	fore(j, 0, sz(mat)) {
		int nid = -1;
		fore(i, j, sz(mat)) {
			if(mat[i][j] != 0) {
				nid = i;
				break;
			}
		}
		if(nid == -1)
			continue;
		
		swap(mat[j], mat[nid]);
		fore(i, 0, sz(mat)) {
			if(i == j) continue;
			int cf = mul(mat[i][j], inv(mat[j][j]));
			
			fore(cj, j, sz(mat[i]))
				mat[i][cj] = norm(mat[i][cj] - mul(cf, mat[j][cj]));
		}
	}
	
	vector<int> a(sz(f), 0);
	fore(i, 0, sz(a)) {
		if(mat[i][i] == 0)
			continue;
		a[i] = mul(mat[i][sz(a)], inv(mat[i][i]));
	}
	
	fore(x0, 0, MOD) {
		int val = 0;
		for(int i = sz(a) - 1; i >= 0; i--)
			val = norm(mul(val, x0) + a[i]);
			
		if(val == 0) {
			cout << "! " << x0 << endl;
			return 0;
		}
	}
	
	cout << "! -1" << endl;
	return 0;
}
```
[1155F - Delivery Oligopoly](../problems/F._Delivery_Oligopoly.md "Educational Codeforces Round 63 (Rated for Div. 2)")

 **Tutorial**
### [1155F - Delivery Oligopoly](../problems/F._Delivery_Oligopoly.md "Educational Codeforces Round 63 (Rated for Div. 2)")

Let's use dynamic programming to solve this problem. We will start with a single biconnected component consisting of vertex $0$, and connect other vertices to it. So, the state of our dynamic programming will be a $mask$ of vertices that are in the same biconnected component with $0$.

How can we extend a biconnected component in such a way that some other vertices are added into it, but it is still biconnected? We will add a path (possibly cyclic) that starts in some vertex $x$ belonging to the $mask$, goes through some vertices not belonging to the $mask$, and ends in some vertex $y$ belonging to the $mask$ (possibly $x = y$). If for every triple ($x$, $y$, $addmask$) we precalculate some path that starts in $x$, goes through vertices from $addmask$ and ends in $y$ (and $addmask$ does not contain neither $x$ nor $y$), then we can solve the problem in $O(3^n n^2)$: there will be $2^n$ states, for every state we will iterate on two vertices $x$ and $y$ belonging to the $mask$, and the number of possible pairs of non-intersecting masks $mask$ and $addmask$ is $O(3^n)$.

The only thing that's left is precalculating the paths for triples ($x$, $y$, $addmask$). That can be done with auxiliary dynamic programming $dp_2[x][y][addmask]$ which will denote whether such a path exists. For every edge $(u, v)$ of the original graph, $dp_2[u][v][0]$ is true, and we can go from $dp_2[x][y][addmask]$ to some state $dp_2[x][z][addmask']$, where $addmask'$ will contain all vertices from $addmask$ and vertex $y$ (and we should ensure that there is an edge $(y, z)$ in the graph and the $addmask$ didn't contain vertex $y$ earlier). We should also somehow be able to restore the paths from this dp, and we also should be careful not to choose the same edge twice (for example, if we start a path by edge $(x, y)$, we should not use the same edge to return to $x$) — both these things can be done, for example, by storing next-to-last vertex in the path. 

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 14;
const int INF = int(1e9);

int dp[1 << N];
int par[1 << N];
int last[1 << N];
pair<int, int> last_pair[1 << N];
int dp2[N][N][1 << N];
int lastv[N][N][1 << N];
vector<int> bits[1 << N];

int n;
int m;
vector<int> g[N];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < (1 << n); i++)
		dp[i] = INF;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int z = 0; z < (1 << n); z++)
				dp2[i][j][z] = INF;
	for(int i = 0; i < n; i++)
		for(auto x : g[i])
		{
			dp2[i][x][0] = 1;
			lastv[i][x][0] = i;
		}
	for(int mask = 0; mask < (1 << n); mask++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				if((mask & (1 << i)) || (mask & (1 << j)) || (i == j) || (dp2[i][j][mask] == INF))
					continue;
				for(auto z : g[j])
				{
					if(mask & (1 << z)) continue;
					if(z == lastv[i][j][mask]) continue;
					int nmask = mask ^ (1 << j);
					if(dp2[i][z][nmask] == INF)
					{
						dp2[i][z][nmask] = 1;
						lastv[i][z][nmask] = j;
					}
				}
			}
	for(int mask = 0; mask < (1 << n); mask++)
		for(int j = 0; j < n; j++)
			if(mask & (1 << j))
				bits[mask].push_back(j);
	dp[1] = 0;
	for(int mask = 0; mask < (1 << n); mask++)
		for(int addmask = mask; addmask; addmask = (addmask - 1) & mask)
		{
			int lastmask = mask ^ addmask;
			int cnt = __builtin_popcount(addmask) + 1;
			if(dp[lastmask] + cnt >= dp[mask])
				continue;
			bool f = false;
			for(auto x : bits[lastmask])
			{
				for(auto y : bits[lastmask])
				{
					if(dp2[x][y][addmask] == 1)
					{
						dp[mask] = dp[lastmask] + cnt;
						last_pair[mask] = make_pair(x, y);
						last[mask] = addmask;
					}
					if(f) break;
				}
				if(f) break;
			}
		}
	if(dp[(1 << n) - 1] == INF)
		cout << -1 << endl;
	else
	{
		cout << dp[(1 << n) - 1] << endl;
		int cur = (1 << n) - 1;
		while(cur != 1)
		{
			int lst = last[cur];
			int x = last_pair[cur].first;
			int y = last_pair[cur].second;
			cur ^= lst;
			while(lst)
			{
				int ny = lastv[x][y][lst];
				cout << y + 1 << " " << ny + 1 << endl;
				lst ^= (1 << ny);
				y = ny;
			}
			cout << x + 1 << " " << y + 1 << endl;
		}
	}
}
```
