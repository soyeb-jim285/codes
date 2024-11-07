# Tutorial_(en)


> It has been a wild ride the final 24 hours in the preparation of this contest! And we really hope you liked the problemset we gave today!

[1737A - Ela Sorting Books](../problems/A._Ela_Sorting_Books.md "Dytechlab Cup 2022")
------------------------------------------------------------------------------------------------

Author: [low_](https://codeforces.com/profile/low_ "Master low_")

 **Tutorial**
### [1737A - Ela Sorting Books](../problems/A._Ela_Sorting_Books.md "Dytechlab Cup 2022")

We'll iterate through compartments from $1$ to $K$. we'll try to put 1 'a' book in it, so the MEX in that compartment will not be 'a'. If any compartment can't be filled by 'a' because we ran out of 'a', the MEX of that compartment will have to be 'a'.

The same logic applies to 'b', 'c', 'd', ..., where for each compartment from $1$, if the MEX of that compartment hasn't been determined, we'll fill the corresponding letter there.

We'll stop when reaching the end of the alphabet, or we've reached the ($\frac{N}{K}$)-th letter in the alphabet (because the first compartment is already full).

 **Solution snippet ( low_ C++)**
```cpp
...
void execute(int test_number)
{
  cin>>n>>k>>str;
  vector <int> count_char(26, 0);
  for (char c: str) count_char[c - 'a']++;
  string ans = "";
  for (int i = 0; i < min(25, n/k); i++) {
    while (k - ans.size() > count_char[i]) {
      ans.push_back(i + 'a');
    }
  }

  char c = 'a' + min(n / k, 25);
  while (k > ans.size()) {
    ans += c;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "n";
}
...
```
[1737B - Ela's Fitness and the Luxury Number](../problems/B._Ela's_Fitness_and_the_Luxury_Number.md "Dytechlab Cup 2022")
------------------------------------------------------------------------------------------------------------------

Author: [low_](https://codeforces.com/profile/low_ "Master low_")

 **Tutorial**
### [1737B - Ela's Fitness and the Luxury Number](../problems/B._Ela's_Fitness_and_the_Luxury_Number.md "Dytechlab Cup 2022")

We shift the perspective to see the pattern from $\lfloor \sqrt{x} \rfloor$, instead of $x$, to see what kind of patterns are needed so $x$ can be luxurious.

Note that: ${(a + 1)}^2 - 1 = a * (a + 2)$.

Therefore, every half-closed segment $[a^2, (a + 1) ^ 2)$ contains exactly $3$ luxurious number: $a^2$, $a * (a + 1)$ and $a * (a + 2)$.

Also note that, since large numbers can cause inaccuracies in floating point computation, we should use binary search to find the floor-value of a square root, instead of using the sqrt function in any language.

![](images/b551043a51e5073888d3d3f84ae0def1ccb1d916.png)

 **Solution snippet (low_, C++)**
```cpp
...
ll l, r;

ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

// main solution goes here:
void execute(int test_number)
{
  cin >> l >> r;
  ll sql = bs_sqrt(l), sqr = bs_sqrt(r);
  ll ans;
  if (sql == sqr) {
    ans = 0;
    for (int i = 0; i < 3; i++) {
      if (l <= sql * (sql + i) && sql * (sql + i) <= r) ans++;
    }
  } else {
    ans = (sqr - sql - 1) * 3;
    for (int i = 0; i < 3; i++) {
      if (l <= sql * (sql + i) && sql * (sql + i) <= r) ans++;
      if (l <= sqr * (sqr + i) && sqr * (sqr + i) <= r) ans++;
    }
  }
  cout << ans << "n";
}
...
```
[1737C - Ela and Crickets](../problems/C._Ela_and_Crickets.md "Dytechlab Cup 2022")
-----------------------------------------------------------------------------------------------

Author: [low_](https://codeforces.com/profile/low_ "Master low_")

 **Tutorial**
### [1737C - Ela and Crickets](../problems/C._Ela_and_Crickets.md "Dytechlab Cup 2022")

The initial configuration will have one central piece and 2 non-central pieces. The central piece is the one on the square that shares the edges with both of the 2 other squares.

As the crickets are standing next to each other, we can prove that each of them can only jump into another square with the same color of the square it's standing on. Assuming that the central piece are on the dark square, we consider 3 cases: 

1. The central piece initially lies on the corner of the board (restrict the moves of the crickets): can only move pieces to squares on the edges they cover.
2. The target square is dark: we can prove that there is always a way to line up 2 pieces on the same-colored squares with the target square diagonally.
3. The target square is light: we can see that the only piece on the white square can only move 2 squares horizontally/vertically, not diagonally in any way, so if the target square x-coordinates has the same oddity as the original square x-coordinate of the light, then it's possible. Otherwise, it's not.

For the case of 2 lights, and 1 dark, use the same reasoning.

Complexity: $O(1)$

 **Solution snippet (low_, C++)**
```cpp
...
int n;
int x[3], y[3];
int u, v;

pii centralSquare() {
  int a = (x[0] == x[1]) ? x[0] : x[2];
  int b = (y[0] == y[1]) ? y[0] : y[2];
  return {a, b};
}
// main solution goes here:
void execute(int test_number)
{
  cin>>n;
  for (int i=0; i<3; i++) cin>>x[i]>>y[i];
  cin>>u>>v;

  int cx = centralSquare().first, cy = centralSquare().second;

  if ((cx == 1 || cx == n) && (cy == 1 || cy == n)) { // "corner" case, literally
    // the crickets can only reach coordinates within the edges that already contains at least 2 crickets,
    // which contains the centralSquare of the L
    cout << ((u == cx || v == cy) ? "YESn" : "NOn");
  } else {
    if ((cx + cy) % 2 == (u + v) % 2) {
      cout << (cx % 2 == u % 2 ? "YESn" : "NOn"); 
    } else { // can be prove to always reach, since we have ways to align 2 crickets in the same diagonal as target
      cout << "YESn"; 
    }
  }
}
...
```
[1737D - Ela and the Wiring Wizard](../problems/D._Ela_and_the_Wiring_Wizard.md "Dytechlab Cup 2022")
--------------------------------------------------------------------------------------------------------

Author: [low_](https://codeforces.com/profile/low_ "Master low_")

 **Tutorial**
### [1737D - Ela and the Wiring Wizard](../problems/D._Ela_and_the_Wiring_Wizard.md "Dytechlab Cup 2022")

Note that you can turn $(u, v)$ edge into a self loop $(u, u)$ in a single operation.

We can prove that it is always better to make an edge directly connect $1$ and $n$. Denote the index of that edge as $i$, and $\text{dist}[u][v]$ as the shortest path from $u$ to $v$ on the unweighted version of the input graph. There are two cases: 

* Connect $u_i$ to $1$ and $v_i$ to $n$ (and vice-versa) directly. The cost is $\text{dist}[u_i][1] + \text{dist}[v_i][n] + 1$ multiplied by $w_i$.
* Connect $1$, $n$ and $u_i$ through an intermediate vertex $x$. Then we will follow the shortest path from $u_i$ to $x$, connect $v_i$ to $x$, then create a self loop $(x, x)$. After that one of the edges will follow the path from $x$ to $1$, the other one will go from $x$ to $n$, and we are able to create an edge $(1, n)$ with weight $w$. The similar procedure is used to connect $1$, $n$ and $v_i$. The cost of the transformation is $\text{dist}[1][x] + \text{dist}[x][n] + \text{dist}[u_i][x] + 2$ multiplied by $w_i$.

We may use BFS or Floyd algorithm in order to calculate $\text{dist}[u][v]$. The final complexity is $O(n^3)$.

 ![](images/2ac13384224c9790093bb3d06e9e6f2c8ac3965d.png)  **Solution (magnified, C++)**
```cpp
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 507;

ll f[N][N];

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int a = 0; a < t; ++a) {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f[i][j] = 1e18;
      }
      f[i][i] = 0;
    }

    vector<tuple<int, int, int> > ed;

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      ed.pb(make_tuple(u - 1, v - 1, w));
      f[u - 1][v - 1] = 1;
      f[v - 1][u - 1] = 1;
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
      }
    }

    ll ans = 1e18;
    for (auto x : ed) {
      int u = get<0>(x);
      int v = get<1>(x);
      int w = get<2>(x);

//      per(ans, u, v, w);

      ans = min(ans, (ll) w * (f[0][u] + f[n - 1][v] + 1));
      ans = min(ans, (ll) w * (f[0][v] + f[n - 1][u] + 1));

  //    per(ans, u, v, w);

      for (int i = 0; i < n; ++i) {
        ans = min(ans, (ll) w * (f[v][i] + 1 + f[i][0] + f[i][n-1] + 1));
        ans = min(ans, (ll) w * (f[u][i] + 1 + f[i][0] + f[i][n-1] + 1));
      }

    }

    cout << ans << 'n';

  }
}
```
[1737E - Ela Goes Hiking](../problems/E._Ela_Goes_Hiking.md "Dytechlab Cup 2022")
----------------------------------------------------------------------------------------------

Author: [ngfam_kongu](https://codeforces.com/profile/ngfam_kongu "Master ngfam_kongu")

 **Tutorial**
### [1737E - Ela Goes Hiking](../problems/E._Ela_Goes_Hiking.md "Dytechlab Cup 2022")

The first ant will die if there are more than $1$ ants since it doesn't have any way to eat other ants (initially no ants have a weight less than it, and no ants are on the left of it).

Call $f(i)$ the probability for the $i$-th ants to be the last one standing in the ants from $1$ to $2i - 1$. $i$ will be the last one standing between them if $i$ is walking to the left and there are $\frac{i-1}{2}$ consecutive ants standing right to the left of it walking to the right. In other words: $i$ will survive if every ant from $\lfloor \frac{i + 2}{2} \rfloor$-th to $(i - 1)$-th ant all walking to the right and $i$ itself walking to the left.

Therefore: $f(i) = \frac{1}{2^{\frac{i+1}{2}}}$.

Except for when $i = n$, that's when whichever direction the $n$-th ant is walking to, it will eventually change direction into walking left: $f(n) = \frac{1}{2^{\frac{n-1}{2}}}$.

Note that $f(i)$ won't take into account ants from $2i$ to $n$.

$g(i)$ will be the probability for the $i$-th ants to be the last one standing in the ants from $1$ to $n$. This holds 2 conditions accountable:

- $i$ can survive for ants between $1$ and $2i - 1$, which only dependent on how ants from $\frac{i-1}{2}$ to $i$ is moving. We already calculated that using $f(i)$ - Ant from $2i$, $2i - 1$ ... $n$ cannot survive, which only dependent on how ants from $i+1$ to $n$ is moving, we can calculate this using $1 - g(2i) - g(2i + 1) - .. - g(n)$.

$g(i)$ = $f(i) * (1 - g(2i) - g(2i + 1) - .. - g(n))$

The answer for each $x$ is $g(x)$

 **Solution snippet (low_, C++)**
```cpp
...
// data preprocessing: (e.g.: divisor generating, prime sieve)
ll POW2[mn];
void preprocess()
{
  POW2[0] = 1;
  for (int i = 1; i < mn; i++) POW2[i] = POW2[i &mdash; 1] * 2 % mod;
}
 
// global variables:
ll n;
 
ll POW(ll u, ll v) {
  if (v == 0) return 1;
  ll mid = POW(u, v / 2);
  mid = (mid * mid) % mod;
  return (v & 1) ? (mid * u % mod) : mid;
}
// main solution goes here:
void execute(int test_number)
{
  cin>>n;
 
  if (n == 1) {
    cout << "1n";
    return;
  }
  vector <ll> ans(n + 1, 0), sufsum(n + 1, 0);
  sufsum[n] = ans[n] = POW(POW2[(n &mdash; 1) / 2], mod &mdash; 2);
  for (int i = n &mdash; 1; i > 1; i--) {
    ans[i] = POW(POW2[(i + 1) / 2], mod &mdash; 2);
    if (2 * i <= n) ans[i] = ans[i] * (1 &mdash; sufsum[i * 2] + mod) % mod;
    sufsum[i] = (sufsum[i + 1] + ans[i]) % mod;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << "n";
 
}
...
```
[1737F - Ela and Prime GCD](../problems/F._Ela_and_Prime_GCD.md "Dytechlab Cup 2022")
------------------------------------------------------------------------------------------------

Author: [blobugh](https://codeforces.com/profile/blobugh "Master blobugh")

 **Tutorial**Observation: Assume that x is composite number and divisor of n. Among all the multiples of x, the number of the divisor of n must be less than or equal to m/2.

First, factorize n. Assume that w is divisor of n. If w is in the form of a^4, a^3b^2, or a^2b^2c^2, it can be proved that there is no answer. Otherwise, there can be two cases.

If the possible maximum exponent of prime factor is 2, place the divisors like this: 1 a^2b^2 b a^2b b^2 ab a^2 ab^2 a / 1 a^2 a. And expand the sequence as follows:

 1. Repeat the current sequence twice — 1 a^2b^2 b a^2b b^2 ab a^2 ab^2 a 1 a^2b^2 b a^2b b^2 ab a^2 ab^2 a / 1 a^2 a 1 a^2 a.
2. Multiply the odd-indexed elements of first half and the even-indexed elements of second half by the new prime factor. Index 1 is exception — 1 a^2b^2 bc a^2b b^2c ab a^2c ab^2 ac c a^2b^2c b a^2bc b^2 abc a^2 ab^2c a / 1 a^2 ab b a^2b a.
3. If more prime factor exists, jump to "Otherwise".

Otherwise, place the divisors like this: 1 a^3 a a^2 / 1 a. Now the exponents of other prime factors are all 1, and we can expand the sequence as follows: 

 1. Repeat the current sequence twice — 1 a^3 a a^2 1 a^3 a a^2 / 1 a 1 a.
2. Multiply the even-indexed elements of first half and the odd-indexed elements of second half by the new prime factor — 1 a^3b a a^2b b a^3 ab a^2 / 1 ab b a. 3-1. If the maximum exponent is 3, swap a and b — 1 a^3b b a^2b a a^3 ab a^2 3-2. Otherwise, swap b and ab — 1 b ab a.

Like this, we can expand the sequence

 **Solution (C++)**
```cpp
#import<bits/stdc++.h>
#define endl 'n'
using namespace std;

int m, t, b[18], check[18], cnt[5];
vector<int>v;
vector<vector<int>>a;

void initialize(int m)
{
	fill(b, b + m + 1, 0);
	fill(check, check + m + 1, 0);
	fill(cnt, cnt + 5, 0);
	v.clear();
	a.clear();
}
void insert1(int p1, int c1)
{
	v[p1] = c1;
	a.push_back(v);
}
void insert2(int p1, int p2, int c1, int c2)
{
	v[p1] = c1;
	v[p2] = c2;
	a.push_back(v);
}

void f1(int x)
{
	int n = a.size();
	for(int i = 0; i < n; i++)a.push_back(a[i]);
	for(int i = 0; i < n; i += 2)
	{
		a[i + 1][x] = 1;
		a[i + n][x] = 1;
	}
	swap(a[n / 2], a[n]);
}
void f2(int x)
{
	int n = a.size();
	for(int i = 0; i < n; i++)a.push_back(a[i]);
	for(int i = 1; i < n; i += 2)
	{
		a[i + 1][x] = 1;
		a[i + n][x] = 1;
	}
	a[n][x] = 1;
}
void f3(int x)
{
	int n = a.size();
	for(int i = 0; i < n; i++)a.push_back(a[i]);
	for(int i = 0; i < n; i += 2)
	{
		a[i + 1][x] = 1;
		a[i + n][x] = 1;
	}
	swap(a[n], a[2 * n &mdash; 1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(cin >> t; t--;)
	{
		cin >> m;
		for(int i = 1; i <= m; i++)
		{
			cin >> b[i];
			cnt[min(b[i], 4)]++;
		}
		if(cnt[4] || cnt[3] >= 2 || cnt[3] && cnt[2] || cnt[2] >= 3)
		{
			cout << -1 << endl;
			initialize(m);
			continue;
		}
		
		for(int i = 1; i <= m; i++)v.push_back(0);
		a.push_back(v);
		
		if(cnt[2])
		{
			int p1 = -1, p2 = -1;
			for(int i = 1; i <= m; i++)
			{
				if(b[i] == 2)
				{
					if(~p1)p2 = i - 1;
					else p1 = i - 1;
				}
			}
			if(~p2)
			{
				insert2(p1, p2, 2, 2);
				insert2(p1, p2, 0, 1);
				insert2(p1, p2, 2, 1);
				insert2(p1, p2, 0, 2);
				insert2(p1, p2, 1, 1);
				insert2(p1, p2, 2, 0);
				insert2(p1, p2, 1, 2);
				insert2(p1, p2, 1, 0);
				check[p1 + 1] = check[p2 + 1] = 1;
			}
			else
			{
				insert1(p1, 2);
				insert1(p1, 1);
				check[p1 + 1] = 1;
			}
			for(int i = 1; i <= m; i++)
			{
				if(check[i])continue;
				if(a.size() % 2)f2(i - 1);
				else f3(i - 1);
			}
		}
		else
		{
			if(cnt[3])
			{
				int p = 0;
				for(int i = 1; i <= m; i++)
				{
					if(b[i] == 3)p = i - 1;
				}
				insert1(p, 3);
				insert1(p, 1);
				insert1(p, 2);
				check[p + 1] = 1;
			}
			else
			{
				insert1(0, 1);
				check[1] = 1;
			}
			for(int i = 1; i <= m; i++)
			{
				if(!check[i])f1(i - 1);
			}
		}
		
		for(auto &v: a)
		{
			if(*max_element(v.begin(), v.end()))
			{
				for(auto &p: v)cout << p << ' ';
				cout << endl;
			}
		}
		initialize(m);
	}
}
```
[1737G - Ela Takes Dancing Class](../problems/G._Ela_Takes_Dancing_Class.md "Dytechlab Cup 2022")
------------------------------------------------------------------------------------------------------

Author: [magnified](https://codeforces.com/profile/magnified "Master magnified")

 **Tutorial**
### [1737G - Ela Takes Dancing Class](../problems/G._Ela_Takes_Dancing_Class.md "Dytechlab Cup 2022")

Note that the immovable dancers don't change their positions during transformations.

Let's pretend that all immovable dancers disappeared. We denote an arrangement as "good" if the dancer in the first step jump over any other dancers (the new placement of the first dancer is greater than the position of any other dancers).

Denote $C$ as the number of dancers in the arrangement. A "good" dancer arrangement retains some properties:

* After $C$ operations, the relative coordinates of dancers are untouched, and the absolute coordinates of dancers are increased by $(C - 1 + d)$. Proof: by intuition. Dancer $1$'s position is increased by $C - 1 + d$ since it goes over $C - 1$ dancers and jumps to the following $d$-th space. Dancer $2$ must jump across dancer $1$ (there aren't enough empty spaces between them), and its position will be increased by the same amount. The description is the same for others.
* After $i$ operations ($i < C$), the absolute coordinates of the leftmost $i$ dancers increased by $C - 1 + d$.

 Let's go through all dancers and maintain the observed "good" arrangement. At the $i$-th iteration (index from $0$), we will attempt to merge the observed arrangement with the $i$-th dancer:* Repeatedly increase the current arrangement by several $C - 1 + d$ until dancer $1$ can go over dancer $i$.
* Increase the coordinate of all the arranged dancers that lie after dancer $i$ by $1$.
* Push the dancer into the maintained arrangement.

Let's binary search each query. We can safely remove all immovable dancers and the remaining dancers that haven't been observed, and appropriately adjust the query segment. In order to maintain the "good" arrangement, we may use any balanced binary search tree (treap for example).

The final complexity is $O((n + q) \log^2 n)$.

 **Solution (C++)**[175061586](https://codeforces.com/contest/1737/submission/175061586 "Submission 175061586 by magnified")

