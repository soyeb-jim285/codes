# Tutorial_(en)

[1875A - Jellyfish and Undertale](https://codeforces.com/contest/1875/problem/A "Codeforces Round 901 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------

 **Tutorial**We can use one tool each time the timer reaches to 1, then the answer will be ∑ni=1min(a−1,xi)+b. This can prove to be optimal. Because for each tool, if we use it when the timer is c, its contribution to the answer is min(xi,a−c). We can't use the tool when the timer is less than or equal to 0 because the bomb will explode before that, so c=1 is the optimal.

Time complexity: O(n) per test case.

Memory complexity: O(1) per test case.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n = 0, a = 0, b = 0;
long long ans = 0;

inline void solve(){
	scanf("%d %d %d", &a, &b, &n);
	ans = b;
	for(int i = 0, x = 0 ; i < n ; i ++){
		scanf("%d", &x);
		ans += min(a - 1, x);
	}
	printf("%lldn", ans);
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}

```
[1874A - Jellyfish and Game](../problems/A._Jellyfish_and_Game.md "Codeforces Round 901 (Div. 1)")
------------------------------------------------------------------------------------------------------------

 **Tutorial**Let us define min(a) to be the minimum value of a in the current round, max(a) to be the maximum value of a in the current round, min(b) to be the minimum value of b in the current round, max(b) to be the maximum value of b in the current round, MIN to be the minimum value of all the apples, MAX to be the maximum value of all the apples.

By greedy and induction, we would come to the following conclusion:

 * If Jellyfish is the one operating this round: If min(a)<max(b), she will swap this two apples, otherwise she will do nothing.
* If Gellyfish is the one operating this round: If max(a)>min(b), he will swap this two apples, otherwise she will do nothing.

We consider who MAX and MIN will belong to after the first round.

In the first round:

 * If max(a)<max(b), MAX=max(b). And because min(a)<max(b), Jellyfish will swap this two apples. So MAX belongs to Jellyfish.
* If max(a)>max(b), MAX=max(a). If min(a)=max(a), then min(a)>max(b), Jellyfish will do nothing. Otherwise Jellyfish won't swap the apple with value MAX. In conclusion MAX belongs to Jellyfish

We can also show that MIN belongs to Gellyfish, and the proof is symmetric with the above.

So in the second round, min(b)=MIN,max(a)=MAX, We have MIN<MAX. So Gellyfish will swap this two apples, in the third round, min(a)=MIN,max(b)=MAX, Jellyfish will swap this two apples.

So after the first round, the game will go two rounds at a time, with two people swapping two apples with the minimum value and the maximum value back and forth.

So we only need to know the answer for k=1 and k=2.

Time complexity: O(n+m) per test case.

Memory complexity: O(n+m) per test case.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;
int n = 0, m = 0, k = 0, x = 0, y = 0, a[N] = {}, b[N] = {};

inline void solve(){
	scanf("%d %d %d", &n, &m, &k); k --;
	for(int i = 0 ; i < n ; i ++) scanf("%d", &a[i]);
	for(int i = 0 ; i < m ; i ++) scanf("%d", &b[i]);
	x = y = 0;
	for(int i = 1 ; i < n ; i ++) if(a[i] < a[x]) x = i;
	for(int i = 1 ; i < m ; i ++) if(b[i] > b[y]) y = i;
	if(b[y] > a[x]) swap(a[x], b[y]);
	if(k & 1){
		x = 0, y = 0;
		for(int i = 1 ; i < n ; i ++) if(a[i] > a[x]) x = i;
		for(int i = 1 ; i < m ; i ++) if(b[i] < b[y]) y = i;
		swap(a[x], b[y]);
	}
	long long ans = 0;
	for(int i = 0 ; i < n ; i ++) ans += a[i];
	printf("%lldn", ans);
	
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}

```
[1875C - Jellyfish and Green Apple](https://codeforces.com/contest/1875/problem/C "Codeforces Round 901 (Div. 2)")
-------------------------------------------------------------------------------------------------------------------

 **Tutorial**Firstly, if n≥m, we can make the problem transform n<m by giving each person an apple at a time until there are not enough apples.

We can calculate the mass of apples that each person ends up with as nm.

Since it's cut in half every time, if mgcd(n,m) is not an integral power of 2, there's no solution.

Since the number of apple pieces is added to exactly 1 for each cut, So we just need to minimize the final number of apple pieces.

As the problem is transformed, nm is less than 1, and mgcd(n,m) is an integral power of 2. So we can uniquely find a set of positive integers S satisfying nm=∑i∈S12i. And this method can be proven to be optimal, if we find another multiset T satisfying S≠T, for every element x that appears twice or more, We can make the answer better by removing two x at a time from T and adding one x−1 to T. By repeating this process, eventually T will become S.

We can use std::__builtin_popcount() to get |S|, the answer is m×|S|−n.

Time complexity: O(logm) per test case.

Memory complexity: O(1) per test case.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n = 0, m = 0;

inline void solve(){
	scanf("%d %d", &n, &m); n %= m;
	int a = n / __gcd(n, m), b = m / __gcd(n, m);
	if(__builtin_popcount(b) > 1) printf("-1n");
	else printf("%lldn", 1ll * __builtin_popcount(a) * m - n);
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}

```
[1875D - Jellyfish and Mex](https://codeforces.com/contest/1875/problem/D "Codeforces Round 901 (Div. 2)")
-----------------------------------------------------------------------------------------------------------

 **Tutorial**We only care about the operation before MEX(a) reaches 0, because after that, m will never change.

**Lemma.** Before MEX(a) reaches 0, we will choose a positive integer x at a time that satisfies x<MEX(a), and delete all x from a, the MEX(a) will become x.

**Proof.** Because if x>MEX(a), we can place this operation after the MEX(a) becomes 0, if we don't delete all of x, MEX(a) won't change, we can also put this operation later.

So before MEX(a) reaches 0, the x we delete is non-increasing.

It means we can solve this problem by dynamic programming. Let dpi represents when MEX(a)=i, and we haven't delete any x satisfying x<i,the minimum value of m.

Let ci represents the number of times i appears in a, the transition is: ∀j<i,dpj←dpi+i×(cj−1)+j.

Time complexity: O(n2) per test case.

Memory complexity: O(n) per test case.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 5000 + 5, Inf = 0x3f3f3f3f3f3f3f3f;
ll n = 0, m = 0, a[N] = {}, dp[N] = {};

inline void init(){
	for(ll i = 0 ; i <= n ; i ++) a[i] = 0, dp[i] = Inf;
	n = m = 0;
}

inline void solve(){
	scanf("%lld", &n);
	for(ll i = 1, x = 0 ; i <= n ; i ++){
		scanf("%lld", &x);
		if(x < n) a[x] ++;
	}
	while(a[m]) m ++;
	dp[m] = 0;
	for(ll i = m ; i >= 1 ; i --) for(ll j = 0 ; j < i ; j ++) dp[j] = min(dp[j], dp[i] + i * a[j]);
	printf("%lldn", dp[0] - m);
}

ll T = 0;

int main(){
	memset(dp, 0x3f, sizeof(dp));
	scanf("%lld", &T);
	for(ll i = 0 ; i < T ; i ++) init(), solve();
	return 0;
}

```
[1874B - Jellyfish and Math](../problems/B._Jellyfish_and_Math.md "Codeforces Round 901 (Div. 1)")
------------------------------------------------------------------------------------------------------------

 **Tutorial**First of all, since and,or,xor are all bitwise operations, each bit is independent of the other.

We define ai as the i-th bit of a, bi as the i-th bit of b, ci as the i-th bit of c, di as the i-th bit of d, mi as the i-th bit of m, xi as the i-th bit of x, yi as the i-th bit of y. (in binary)

**Lemma.** For all i≠j, if (ai,bi,mi)=(aj,bj,mj) and (ci,di)≠(cj,dj), the goal cannot be achieved.

**Proof.** Because after every operation we will have (xi,yi)=(xj,yj), so we can't achieve he goal.

Since (ai,bi,mi) has only 23=8 cases, and (ci,di) has only 22=4 cases, and there are some (0/1,0/1,0/1) that do not appear in {(ai,bi,mi) | 0≤i≤logmax(a,b,c,d,m)}, so there are only (4+1)8<4×105 cases in this problem. We can use BFS(breadth-first search) for preprocessing.

Time complexity: O(58) for preprocessing and O(logmax(a,b,c,d,m)) per test case.

Memory complexity: O(58) for preprocessing and O(1) per test case.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int S = 4e5 + 5, Inf = 0x3f3f3f3f;
int pw5[10] = {}, dp[S] = {};
queue<int> Q;

inline void checkmin(int &x, int y){
	if(y < x) x = y;
}

inline int w(int mask, int i){
	return (mask / pw5[i]) % 5;
}

inline int f(int a, int b, int m){
	return (a << 2) | (b << 1) | m;
}

inline int g(int c, int d){
	return (c << 1) | d;
}

inline int work(int mask, int opt){
	int ret = 0;
	for(int a = 0 ; a < 2 ; a ++) for(int b = 0 ; b < 2 ; b ++) for(int m = 0 ; m < 2 ; m ++){
		int x = w(mask, f(a, b, m)), c = x >> 1, d = x & 1;
		if(opt == 1) c = c & d;
		else if(opt == 2) c = c | d;
		else if(opt == 3) d = c ^ d;
		else d = m ^ d;
		ret += pw5[f(a, b, m)] * g(c, d);
	}
	return ret;
}

inline void init(){
	pw5[0] = 1;
	for(int i = 1 ; i <= 8 ; i ++) pw5[i] = pw5[i - 1] * 5;
	memset(dp, 0x3f, sizeof(dp));
	int mask = 0;
	for(int a = 0 ; a < 2 ; a ++) for(int b = 0 ; b < 2 ; b ++) for(int m = 0 ; m < 2 ; m ++) mask += pw5[f(a, b, m)] * g(a, b);
	dp[mask] = 0, Q.push(mask);
	while(Q.size()){
		int s = Q.front(); Q.pop();
		for(int opt = 0 ; opt < 4 ; opt ++){
			int t = work(s, opt);
			if(dp[t] == Inf) dp[t] = dp[s] + 1, Q.push(t);
		}
	}
	for(int mask = 0 ; mask < pw5[8] ; mask ++) for(int i = 0 ; i < 8 ; i ++) if(w(mask, i) == 4){
		for(int x = 1 ; x <= 4 ; x ++) checkmin(dp[mask], dp[mask - x * pw5[i]]);
		break;
	}
}

inline void solve(){
	int A = 0, B = 0, C = 0, D = 0, M = 0, mask = pw5[8] - 1;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &M);
	for(int i = 0 ; i < 30 ; i ++){
		int a = (A >> i) & 1, b = (B >> i) & 1, c = (C >> i) & 1, d = (D >> i) & 1, m = (M >> i) & 1;
		if(w(mask, f(a, b, m)) == 4) mask -= (4 - g(c, d)) * pw5[f(a, b, m)];
		else if(w(mask, f(a, b, m)) != g(c, d)){
			printf("-1n");
			return;
		}
	}
	printf("%dn", (dp[mask] < Inf) ? dp[mask] : -1);
}

int T = 0;

int main(){
	init();
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}

```
[1874C - Jellyfish and EVA](../problems/C._Jellyfish_and_EVA.md "Codeforces Round 901 (Div. 1)")
-----------------------------------------------------------------------------------------------------------

 **Tutorial**Let's solve this problem by dynamic programming, Let fu represents the max probability of reaching city n starting from city u.

The problem is how to transition. for city u, we assume that there are d roads from city u, the i-th road from city u is to city vi.

Let's sort v by using fv as the keyword, with v with the larger fv coming first.

Let's define an array a of d elements equals to [fv1,fv2,…,fvd], according to the definition, a is non-increasing.

That is, next we want to find an optimal solution such that the probability of going to city vi is pi, maximizing the value of ∑di=1ai×pi.

**Tips:** the sum of pi may not be 1, because it is possible to stay at city u when d is even.

For two choices of p, p1 and p2, Sometimes we can't which is better, for example:

p1=[0.6,0.2,0.2],p2=[0.5,0.5,0]

when a=[1.0,0.2,0.2], p1 is better than p2. But when a=[1.0,0.8,0], p2 is better than p1.

**Tips.** In fact, when d=3, p has only one choice [13,13,13], the above is just a hypothetical to illustrate the problem.

So when can we say, p1 is always not worse than p2?

**Lemma.** If there are two arrays p1 and p2, satisfying ∀i≤d,∑ij=1p1j≥∑ij=1p2j, p1 is always not worse than p2.

**Proof.** Let's consider ad+1 as 0 and define a′i=ai−ai+1, p′1i=∑ij=1p1j and p′2i=∑ij=1p2j, then ∑di=1ai×p1i=∑di=1a′i×p′1i,∑di=1ai×p2i=∑di=1a′i×p′2i, Because a is non-increasing, so a′i≥0, and we have ∀i≤d,p1i≥p2i, so ∑di=1ai×p1i≥∑di=1ai×p2i.

Now the problem is, there is whether an array p not worse than any other arrays for for all d.

For d=1, p=[1.0] satisfies the condition.

For d=2, p=[0.5,0] satisfies the condition.

What about d>2 ? After they choose the roads for the first time, The size of the problem will become d−2.

For example, when d=4, Let's assume Jellyfish choose v1 for the first time, then there will be 4 situations:

 1. When Asuka chooses v1 they will go to v1.
2. When Asuka chooses v2, the problem changes into the subproblem with [v3,v4].
3. When Asuka chooses v3, the problem changes into the subproblem with [v2,v4].
4. When Asuka chooses v4, the problem changes into the subproblem with [v2,v3].

By calculating, p=[0.25,0.25,0.125,0], it also satisfies the condition.

Let's define gk as the best array p when d=k, g′k as the the probabilities of going to cities except the city Jellyfish choose for the first time. By recursion, we can get g′k from gk−2. After that, we insert 1k into g′k, keeping it non-increasing, we will get gk.

By calculating, we will find 1k is always the first element in gk. So when k>2, we have the following transition:

 * gk,1=1k
* ∀1<i≤k,gk,i=gk−2,i−2×i−2k+gk−2,i−1×k−ik

In the above we consider gk,x as 0 for all x=0 or x>k.

Because gk−2 satisfies the condition, by greedy and induction we can show that gk satisfies the condition.

Time complexity: O(max(n)2) for preprocessing and O(mlogn) per test case.

Memory complexity: O(max(n)2) for preprocessing and O(m) per test case.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 5000 + 5;
int n = 5000, m = 0;
vector<vector<int> > G(N), Gx(N);
long double f[N] = {}, g[N][N] = {};

inline bool cmp(int u, int v){
	return f[u] > f[v];
}

inline void work(int u){
	if(u == n){
		f[u] = 1.00;
		return;
	}
	sort(G[u].begin(), G[u].end(), cmp);
	int k = G[u].size();
	for(int i = 0 ; i < k ; i ++){
		int v = G[u][i];
		f[u] += f[v] * g[k][i + 1];
	}
}

inline void init(){
	for(int u = 1 ; u <= n ; u ++){
		f[u] = 0.00;
		G[u].clear(), Gx[u].clear();
	}
	n = m = 0;
}

inline void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1, u = 0, v = 0 ; i <= m ; i ++){
		scanf("%d %d", &u, &v);
		if(u != n){
			G[u].push_back(v);
			Gx[v].push_back(u);
		}
	}
	for(int u = n ; u >= 1 ; u --) work(u);
	printf("%.12Lfn", f[1]);
}

int T = 0;

int main(){
	for(int i = 1 ; i <= n ; i += 2) for(int j = 1 ; j <= i ; j ++) g[i][j] = 1.00 / i;
	for(int i = 2 ; i <= n ; i += 2){
		g[i][1] = 1.00;
		for(int j = 1 ; j <= i ; j ++) g[i][j] /= i;
		if(i + 2 <= n) for(int j = 1 ; j <= i ; j ++) g[i + 2][j + 1] += g[i][j] * (i - j + 1), g[i + 2][j + 2] += g[i][j] * j;
	}
	scanf("%d", &T);
	for(int i = 1 ; i <= T ; i ++) init(), solve();
	return 0;
}

```
[1874D - Jellyfish and Miku](../problems/D._Jellyfish_and_Miku.md "Codeforces Round 901 (Div. 1)")
------------------------------------------------------------------------------------------------------------

 **Tutorial**Let's assume that a is given. We can use dynamic programming to solve the problem.

Let's define fi as the expected number of days Jellyfish needs to reach city i from city 0.

We will have:

 * f0=0,f1=1
* ∀i>1,fi=fi−1+1+ai−1ai−1+ai×(fi−fi−2)

Let's make it better:

 * fi=fi−1+1+ai−1ai×(fi−1−fi−2+1)

What does this inspire us to do? Let's define gi=fi−fi−1, then we will get:

 * g1=1
* ∀i>1,gi=1+ai−1ai×(gi−1+1)

By induction, we will find gi=1+2×∑i−1j=1ajai. According to the definition, fn=∑ni=1gn=n+2×∑ni=1∑i−1j=1ajai.

Then we can use dynamic programming to solve the problem itself.

Let's define si=∑ij=1aj, then fn=n+2×∑ni=1si−1ai.

Let's define dpi,x as the minimum value of ∑ni=1si−1ai when si=x.

We transit by enumerating the values of ai+1, The transition is: dpi+1,x+y←dpi,x+xy.

But the time complexity is O(nm2), how can it becomes faster?

Let's take a closer look at ∑ni=1∑i−1j=1ajai. If there exists i<n satisfying ai>ai+1. We can swap ai and ai+1, the answer will be better! so a is a non-decreasing array, which means ai≤mn−i+1.

Because ∑ni=1ni is O(nlogn), so if we only enumerate the possible values of ai the time complexity will be O(m2logm).

Time complexity: O(m2logm)

Memory complexity: O(nm)

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 3000 + 5;
const long double Inf = 1e18;
int n = 0, m = 0;
long double dp[N][N] = {};

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i <= n ; i ++) for(int x = 0 ; x <= m ; x ++) dp[i][x] = Inf;
	dp[0][0] = 0.00;
	for(int i = 1 ; i <= n ; i ++) for(int x = 0 ; x <= m ; x ++) for(int y = 1 ; x + y * (n - i + 1) <= m ; y ++) dp[i][x + y] = min(dp[i][x + y], dp[i - 1][x] + 1.00 * x / y);
	printf("%.12Lf", 2 * dp[n][m] + n);
	return 0;
}

```
[1874E - Jellyfish and Hack](../problems/E._Jellyfish_and_Hack.md "Codeforces Round 901 (Div. 1)")
------------------------------------------------------------------------------------------------------------

 **Tutorial**Firstly, if lim>n(n+1)2, the answer will be 0. So we only need to solve the problem which satisfies lim≤n(n+1)2.

We can use dynamic programming to solve the problem:

Let's define dpi,a means the number of the permutations P of [1,2,…,i], satisfying fun(P)=a.

Since only relative rankings are useful, we have the following transition:

 * dp0,0=1
* ∀i>0,dpi,a=∑ij=1(i−1j−1)∑a−ib=0dpj−1,b×dpi−j,a−b−i

The time complexity is O(n6), because a≤i(i+1)2, how can it becomes faster?

FFT (Fast Fourier Transform) might come to mind first. If we use FFT instead of enumerating t, The time complexity will become O(n4logn). This is not enough because n is large and 109+7 is not a modulus suitable for NTT (Number-theoretic Transform).

**Tips.** Also, if you use divide and conquer and FFT, The time complexity will be O(n3poly(logn)), but because FFT have a big constant factor, this still can't pass the problem.

But we can do something similar to what the FFT does. We define Fi=∑n(n+1)2a=1dpi,a×xa, then we will have the following transition:

 * F0=1
* Fi=xi×∑ij=1(i−1j−1)Fj−1×Fi−j

For all 1≤i≤n, The degree of Fi won't exceed n(n+1)2. So if we have n(n+1)2+1 points on Fn, We can get Fn by in time complexity O(n4) using Lagrange Interpolation. The only thing we need to do is the dot product of the functions, so the time complexity of the transition is also O(n4).

Time complexity: O(n4)

Memory complexity: O(n3)

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 200 + 5, Mod = 1e9 + 7;

inline ll power(ll x, ll y){
	ll ret = 1;
	while(y){
		if(y & 1) ret = ret * x % Mod;
		x = x * x % Mod, y >>= 1;
	}
	return ret;
}

ll n = 0, k = 0, lim = 0;
ll C[N][N] = {}, pw[N * N][N] = {}, iv[N * N] = {}, ifac[N * N] = {}, dp[N][N * N] = {};
ll a[N * N] = {}, b[N * N] = {}, ans = 0;

int main(){
	scanf("%lld %lld", &n, &k); lim = n * (n + 1) / 2;
	for(ll i = 0 ; i <= n ; i ++){
		C[i][0] = 1;
		for(ll j = 1 ; j <= i ; j ++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	}
	ifac[0] = 1;
	for(ll x = 0 ; x <= lim ; x ++){
		pw[x][0] = 1;
		if(x) iv[x] = power(x, Mod - 2), ifac[x] = ifac[x - 1] * iv[x] % Mod;
		for(ll i = 1 ; i <= n ; i ++) pw[x][i] = pw[x][i - 1] * x % Mod;
	}
	for(ll x = 0 ; x <= lim ; x ++) dp[0][x] = 1;
	for(ll i = 1 ; i <= n ; i ++){
		for(ll j = 0 ; j < i ; j ++) for(ll x = 0 ; x <= lim ; x ++) dp[i][x] = (dp[i][x] + dp[j][x] * dp[i - 1 - j][x] % Mod * C[i - 1][j]) % Mod;
		for(ll x = 0 ; x <= lim ; x ++) dp[i][x] = dp[i][x] * pw[x][i] % Mod;
	}
	a[0] = 1;
	for(ll i = 0 ; i <= lim ; i ++){
		for(ll x = lim ; x >= 1 ; x --) a[x] = (a[x - 1] + a[x] * (Mod - i)) % Mod;
		a[0] = a[0] * (Mod - i) % Mod;
	}
	for(ll i = 1 ; i <= lim ; i ++) if(dp[n][i]){
		ll w = dp[n][i] * ifac[i] % Mod * ifac[lim - i] % Mod;
		if((lim - i) & 1) w = Mod - w;
		b[0] = a[0] * (Mod - iv[i]) % Mod;
		for(ll x = 1 ; x <= lim ; x ++) b[x] = (a[x] - b[x - 1] + Mod) * (Mod - iv[i]) % Mod;
		for(ll x = k ; x <= lim ; x ++) ans = (ans + b[x] * w) % Mod;
	}
	printf("%lldn", ans);
	return 0;
}

```
[1874F - Jellyfish and OEIS](../problems/F._Jellyfish_and_OEIS.md "Codeforces Round 901 (Div. 1)")
------------------------------------------------------------------------------------------------------------

 **Tutorial**Let's call a section [l,r] bad if [pl,pl+1,…,pr−1,pr] is a permutation of [l,l+1,…,r−1,r] and l≤r≤ml.

Let's call a section [l,r] primitive if it's a bad section and there are no section [l′,r′] satisfying [l′,r′] is also a bad section and [l,r] covers [l′,r′].

**Lemma.** For all primitive sections, none two of them intersect.

**Proof.** If [l1,r1] is a bad section, [l2,r2] is a bad section and l1<l2<r1<r2, the section [l2,r1] will also be a bad section, but both [l1,r1] and [l2,r2] covers [l2,r1], so [l1,r1] and [l2,r2] can't be primitive at the same time.

Let's use the principle of inclusion-exclusion and dynamic programming to solve the problem.

Let's define f(l,r) as the number of pl,pl+1,…,pr−1,pr which is a primitive section. By the principle of inclusion-exclusion, we count the ways to fix k primitive sections in range [l,r], and arrange the rest arbitrarily.

Then we can define g1/2(l,r,x) as the number of ways to fix k (k is odd/even) primitive sections in range [l,r], and the number of the positions which doesn't cover by any primitive section is x.

Finally we define g(l,r,x)=g2(l,r,x)−g1(l,r,x), We will have the following transition:

 * ∀l≤r≤ml,f(l,r)=∑r−l+1x=0g(l,r,x)×x!+f(l,r)
* g(l,r,x)=g(l,r−1,x−1)−∑rmid=lg(l,mid−1,x)×f(mid,r)

**Tips.** In the transition of f(l,r), We add f(l,r) because f(l,r) contributes to g(l,r,0), but it should not contribute to f(l,r), This problem can be solved by ordering the transitions.

According to the definition, ∑nx=0g(1,n,x)×x! is the answer.

Time complexity: O(n4)

Memory complexity: O(n3)

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 200 + 5, Mod = 1e9 + 7;
ll n = 0, m[N] = {}, fac[N] = {}, f[N][N] = {}, g[N][N][N] = {};

int main(){
	scanf("%lld", &n);
	for(ll i = 1 ; i <= n ; i ++) scanf("%lld", &m[i]);
	if(m[1] == n){
		printf("0");
		return 0;
	}
	fac[0] = 1;
	for(ll i = 1 ; i <= n ; i ++) fac[i] = fac[i - 1] * i % Mod;
	for(ll i = 1 ; i <= n ; i ++) g[i][i - 1][0] = 1;
	for(ll l = n ; l >= 1 ; l --) for(ll r = l ; r <= n ; r ++){
		for(ll x = 1 ; x <= r - l + 1 ; x ++) g[l][r][x] = g[l][r - 1][x - 1];
		for(ll mid = l ; mid < r ; mid ++) if(r <= m[mid + 1]) for(ll x = 0 ; x <= mid - l + 1 ; x ++) g[l][r][x] = (g[l][r][x] + g[l][mid][x] * (Mod - f[mid + 1][r])) % Mod;
		for(ll x = 0 ; x <= r - l + 1 ; x ++) f[l][r] = (f[l][r] + g[l][r][x] * fac[x]) % Mod;
		if(r <= m[l]) g[l][r][0] = (g[l][r][0] + (Mod - f[l][r])) % Mod;
	}
	printf("%lld", f[1][n]);
	return 0;
}

```
[1874G - Jellyfish and Inscryption](../problems/G._Jellyfish_and_Inscryption.md "Codeforces Round 901 (Div. 1)")
-------------------------------------------------------------------------------------------------------------------

 **Tutorial**For convenience, let's define k=max(a,b,x,y), use operation 1 for "You will get a card with a HP, and b damage", operation 2 for "If you have at least one card, choose one of your cards and increase its HP by x" and operation 3 for "If you have at least one card, choose one of your cards and increase its damage by y", operation 4 for "You will get a prop with w power", operation 5 for "You can choose at most one of your cards and multiply its damage by 109", "the i-th card" for the card we get from vertex i (It must be operation 1 on vertex i), "do operation 2/3/5 onto card i" for "When we do this operation 2/3/5, we will choose the card i and increase his HP or damage".

Let us consider the problem without the operation 5, what's the maximum possible answer. If you want to maximize the the sum of the power of your cards, the answer will not exceeding (100×200)2=4×108; If you you want to maximize the the sum of the power of your props, the answer will not exceeding 200×106=2×108. Because 4×108+2×108=6×108<109, so the operation n is the most important. Let's called the card we wil do the operation 5 onto it the "flash card". Let's use meet-in-the-middle, the problem is divided into two subproblems — the game before we get the flash card and the game after we get the flash card.

### 1. The game after we get the flash card

It's a easy problem, we can use dynamic programming to solve this problem.

Since the most important thing is the HP and damage of the flash card, so we define the following dynamic programming state:

 * dpb(u,a) means we are current at vertex u, the current HP of the flash card is a, the maximum damage of the flash card.
* dpc(u,a) means we are current at vertex u, the current HP of the flash card is a, the damage of the flash card is dpb(u,a), the maximum sum of the power of all the other cards and props.

Since a≤nk, the time complexity of the transition is O(m×n×k).

### 2. The game before we get the flash card

This is the key of the problem, and since it's much more difficult, we first consider the subproblems of this problem.

#### I. If the graph is a chain, and all the operation 2 and operation 3 is after the operation 1

**Lemma.** We will do all the operation 2 onto one of the cards, symmetrically we will also do all the operation 3 onto one of the cards.

**Proof.** We consider a sequence of operations, let's consider if we do all the operation 1 on the card with the max damage after doing all the operation 2, the answer won't be worse, we can do all the operation 1 onto this card instead, then we make a symmetrical adjustment, the answer won't be worse, and all the operation 2 is done onto one of the cards, all the operation 3 is done onto one of the cards.

#### II. If the graph is a chain

It's similar to the **subproblem I**. If we say **subproblem I** is like a "global max value", then **subproblem II** is like a "prefix max value".

Let's define pi means we will do the operation 2/3 on vertex i onto the pi-th card.

**Lemma1.** If there is a operation 2 on vertex i and a operation 2 on vertex j, if pi<j<i, we will have pj=pi.

**Proof.** Let's consider the final HP and damage of the cards after all the operations. Because we do the operation 2 on vertex i onto the pi-th card, for all i′<i, the damage of the i′-th card is not larger than the pi-th card. So for j, if we don't do the operation 2 on vertex j onto the pi-th card, we can do it onto the pi-th card instead, the answer won't be worse.

Symmetrically, **Lemma1** is also correct for operation 3.

Now we can use dynamic programming to solve the problem, we define the following dynamic programming state:

 * f(u,a,b) means we are current at vertex u, we will do the next several operation 3 onto a card with a HP after all the operations and we will do the next several operation 2 onto a card with b damage after all the operations, and this two cards are not the same.
* g(u,a,b) means we are current at vertex u, We will do the next several operation 2 and operation 3 onto a card currently having a HP and b damage.

The time complexity is O(m×n2×k2), but it's not enough.

**Lemma2.** If a card has a HP and b damage after all the operations and it's not the flash card, min(a,b)≤k.

**Proof.** If we use this card as the flash card instead of the last one, and do all the operations done onto the last flash card onto this card, the power of the flash card will be larger. So it won't exist in this half problem.

Now the time complexity becomes O(m×n×k2), it's still not enough.

**Lemma3.** Let's define A as the maximum HP of all the cards except the flash card after all the operations, B as the maximum damage of all the cards except the flash card after all the operations, min(A,B)≤k.

**Proof.** Let's assume that the i-th card has A HP after all the operations, the j-th card has B damage after all the operations and A>k,B>k. If i=j, it conflicts with **Lemma 2**; If i<j, because of the **Lemma 2**, the HP of the j-th card after all the operations won't exceed k, let's use A′ as the HP of the j-th card after all the operations, and B>k, so we have done some operation 3 onto the j-th card. But because A>k≥A′, if we do these operations onto the i-th card, the answer will be better; If i>j, it's symmetric with i<j.

But we can make the dynamic programming state better:

 * f(u,a,b) means we are current at vertex u, we will do the next several operation 3 onto a card with a HP after all the operations and we will do the next several operation 2 onto a card with b damage after all the operations, and this two cards are not the same.
* ga(u,a,a′) means we are current at vertex u, we will do the next several operation 3 onto a card with a HP after all the operations, we will do the next several operation 2 onto a card and totally increase a′ HP in the next several operations to reach it's HP after all the operations.
* gb(u,b,b′) it's symmetric with ga, just swap "HP" and "damage".

Let's define A as the maximum HP of all the cards except the flash card after all the operations, B as the maximum damage of all the cards except the flash card after all the operations. We will find the a,a′,b,b′ in f,ga,gb is O(k) because if A≤k, using ga we can get the right answer, if B≤k, using gb we can get the right answer.

the time complexity of the transition is O(m×k2).

The transition is very complex, you can see more details in my code : )

In my code, I use g(u) to make the transition better. When a′ or b′ reaches 0, we reaches the vertex u and there is a operation 1 on vertex u, I don't enumerate the value of the next a and b while transiting. I transit it to g(u) first, and enumerate the value of the next a and b together.

#### III. the problem itself

Since the path is a chain, and we use dynamic programming to solve the problem. There's no difference whether the graph is a chain.

Time complexity: O(m(nk+k2))

Memory complexity: O(n2k+nk2)

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200 + 5;
const ll lim = 1e9;

inline void checkmax(int &x, int y){
	if(y > x) x = y;
}

inline void checkmax(ll &x, ll y){
	if(y > x) x = y;
}

inline void checkmax(pair<int, int> &x, pair<int, int> y){
	if(y > x) x = y;
}

int n = 0, m = 0, k = 0, opt[N] = {}, a[N] = {}, b[N] = {}, w[N] = {};
int f[N][N][N] = {}, g[N] = {}, g_a[N][N][N] = {}, g_b[N][N][N] = {};
pair<int, int> dp[N][N * N] = {};
vector<vector<int> > G(N);

int main(){
	scanf("%d %d", &n, &m);
	for(int u = 1 ; u <= n ; u ++){
		scanf("%d", &opt[u]);
		if(opt[u] == 1) scanf("%d %d", &a[u], &b[u]);
		else if(opt[u] == 2) scanf("%d", &a[u]);
		else if(opt[u] == 3) scanf("%d", &b[u]);
		else if(opt[u] == 4) scanf("%d", &w[u]);
		k = max(k, max(a[u], b[u]));
	}
	for(int i = 1, u = 0, v = 0 ; i <= m ; i ++){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	memset(f, -1, sizeof(f));
	memset(g, -1, sizeof(g)), memset(g_a, -1, sizeof(g_a)), memset(g_b, -1, sizeof(g_b));
	memset(dp, -1, sizeof(dp));
	f[1][0][0] = 0;
	for(int u = 1 ; u <= n ; u ++){
		if(opt[u] == 1 && g[u] != -1){
			for(int x = a[u] ; x <= k ; x ++) checkmax(g_a[u][x][x - a[u]], g[u] + x * b[u]);
			for(int x = b[u] ; x <= k ; x ++) checkmax(g_b[u][x][x - b[u]], g[u] + x * a[u]);
			checkmax(dp[u][a[u]], make_pair(b[u], g[u]));
		}
		for(int v : G[u]){
			if(opt[v] == 1){
				for(int x = 0 ; x <= k ; x ++) for(int y = 0 ; y <= k ; y ++){
					if(f[u][x][y] != -1){
						checkmax(f[v][max(x, a[v])][max(y, b[v])], f[u][x][y] + a[v] * b[v]);
						checkmax(g[v], f[u][x][y]);
					}
					if(g_a[u][x][y] != -1){
						checkmax(g_a[v][max(x, a[v])][y], g_a[u][x][y] + a[v] * b[v]);
						if(!y){
							checkmax(g[v], g_a[u][x][y]);
							checkmax(f[v][x][b[v]], g_a[u][x][y] + a[v] * b[v]);
						}
					}
					if(g_b[u][x][y] != -1){
						checkmax(g_b[v][max(x, b[v])][y], g_b[u][x][y] + a[v] * b[v]);
						if(!y){
							checkmax(g[v], g_b[u][x][y]);
							checkmax(f[v][a[v]][x], g_b[u][x][y] + a[v] * b[v]);
						}
					}
				}
				for(int x = 0 ; x <= n * k ; x ++) if(dp[u][x] != make_pair(-1, -1)){
					int y = dp[u][x].first, z = dp[u][x].second;
					checkmax(dp[v][x], make_pair(y, z + a[v] * b[v]));
				}
			}
			else if(opt[v] == 2){
				for(int x = 0 ; x <= k ; x ++) for(int y = 0 ; y <= k ; y ++){
					if(f[u][x][y] != -1) checkmax(f[v][x][y], f[u][x][y] + a[v] * y);
					if(g_a[u][x][y] != -1 && y >= a[v]) checkmax(g_a[v][x][y - a[v]], g_a[u][x][y]);
					if(g_b[u][x][y] != -1) checkmax(g_b[v][x][y], g_b[u][x][y] + a[v] * x);
				}
				for(int x = 0 ; x <= n * k ; x ++) if(dp[u][x] != make_pair(-1, -1)){
					int y = dp[u][x].first, z = dp[u][x].second;
					checkmax(dp[v][x + a[v]], make_pair(y, z));
				}
			}
			else if(opt[v] == 3){
				for(int x = 0 ; x <= k ; x ++) for(int y = 0 ; y <= k ; y ++){
					if(f[u][x][y] != -1) checkmax(f[v][x][y], f[u][x][y] + x * b[v]);
					if(g_a[u][x][y] != -1) checkmax(g_a[v][x][y], g_a[u][x][y] + x * b[v]);
					if(g_b[u][x][y] != -1 && y >= b[v]) checkmax(g_b[v][x][y - b[v]], g_b[u][x][y]);
				}
				for(int x = 0 ; x <= n * k ; x ++) if(dp[u][x] != make_pair(-1, -1)){
					int y = dp[u][x].first, z = dp[u][x].second;
					checkmax(dp[v][x], make_pair(y + b[v], z));
				}
			}
			else{
				for(int x = 0 ; x <= k ; x ++) for(int y = 0 ; y <= k ; y ++){
					if(f[u][x][y] != -1) checkmax(f[v][x][y], f[u][x][y] + w[v]);
					if(g_a[u][x][y] != -1) checkmax(g_a[v][x][y], g_a[u][x][y] + w[v]);
					if(g_b[u][x][y] != -1) checkmax(g_b[v][x][y - b[v]], g_b[u][x][y] + w[v]);
				}
				for(int x = 0 ; x <= n * k ; x ++) if(dp[u][x] != make_pair(-1, -1)){
					int y = dp[u][x].first, z = dp[u][x].second;
					checkmax(dp[v][x], make_pair(y, z + w[v]));
				}
			}
		}
	}
	ll ans = f[n][0][0];
	for(int x = 0 ; x <= n * k ; x ++) if(dp[n][x] != make_pair(-1, -1)){
		int y = dp[n][x].first, z = dp[n][x].second;
		checkmax(ans, lim * x * y + z);
	}
	printf("%lld", ans);
	return 0;
}

```
