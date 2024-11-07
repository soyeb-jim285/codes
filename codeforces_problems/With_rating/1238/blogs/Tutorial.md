# Tutorial

[1238A - Prime Subtraction](../problems/A._Prime_Subtraction.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1238A - Prime Subtraction](../problems/A._Prime_Subtraction.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Let's denote the difference between $x$ and $y$ as $z$ ($z = x - y$). Then, if $z$ has a prime divisor $p$, we can subtract $p$ from $x$ $\frac{z}{p}$ times.

The only positive integer that doesn't have any prime divisors is $1$. So, the answer is NO if and only if $x - y = 1$.

 **Solution (BledDest)**
```cpp
t = int(input())

for i in range(t):
	x, y = map(int, input().split())
	if(x - y > 1):
		print('YES')
	else:
		print('NO')
```
[1238B - Kill `Em All](../problems/B._Kill_`Em_All.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1238B - Kill `Em All](../problems/B._Kill_`Em_All.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Notice the following fact: it's never optimal to fire a missile at such a position that there are monsters to the right of it. That suggests the next solution: sort the positions, leave only the unique ones and process to shoot at the rightmost alive monster until every monster is dead. Position of some monster after s shots are made is the original position minus r⋅s, because the monster could only be pushed to the left.

Overall complexity: O(nlogn).

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int N = 100 * 1000 + 13;

int n, r;
int a[N];

void solve() {
	scanf("%d%d", &n, &r);
	forn(i, n) scanf("%d", &a[i]);
	
	sort(a, a + n);
	n = unique(a, a + n) - a;
	
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) 
		ans += (a[i] - ans * r > 0);

	printf("%dn", ans);
}

int main() {
	int q;
	scanf("%d", &q);
	forn(i, q) solve();
}
```
[1238C - Standard Free2play](../problems/C._Standard_Free2play.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1238C - Standard Free2play](../problems/C._Standard_Free2play.md "Educational Codeforces Round 74 (Rated for Div. 2)")

You are given the input data in compressed format, let's decompress it in binary string, where the ii-th character is 0 if the ii-th platform is hidden and 1 otherwise. For, example, the third query is 101110011.

Let's look how our string changes: if we had ...01... then after pulling the lever it becomes ...10... and if we had ...111... then we'd get ...100... (The underlined index is the platform we are currently on). So it looks like we are standing on 1 and move it to the left until it clashes with the next one. So we can determine that we should look only at subsegments on 1-s.

Now we can note, that the "good" string should have all subsegments of ones with even length except two cases: the subsegment that starts from hh should have odd length and subsegment, which ends in 11 can have any length.

Now we can say, that the answer is equal to number of subsegments which doesn't match the pattern of the "good string", since we can fix each subsegment with one crystal. And we can prove that it's optimal since the only way to fix two subsegments with one crystal is to merge them but it does not help.

Finally, we can understand that we have no need in decompressing the input and can determine subsegments of ones straightforwardly.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

const int INF = int(1e9);

int h, n;
vector<int> p;

inline bool read() {
	if(!(cin >> h >> n))
		return false;
	p.resize(n);
	fore(i, 0, n)
		cin >> p[i];
	return true;
}

inline void solve() {
	int ans = 0;
	
	int lf = 0;
	fore(i, 0, n) {
		if (i > 0 && p[i - 1] > p[i] + 1) {
			if (lf > 0)
				ans += (i - lf) & 1;
			else
				ans += 1 - ((i - lf) & 1);
			lf = i;
		}
	}
	if (p[n - 1] > 1) {
		if (lf != 0)
			ans += (n - lf) & 1;
		else
			ans += 1 - ((n - lf) & 1);
	}
	
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	while(tc--) {
		read();
		solve();
	}
	return 0;
}
```
[1238D - AB-string](../problems/D._AB-string.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1238D - AB-string](../problems/D._AB-string.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Instead of counting the number of good substrings, let's count the number of bad substrings $cntBad$, then number of good substrings is equal to $\frac{n(n+1)}{2} - cntBad$.

Let's call a character $t_i$ in string $t_1t_2 \dots t_k$ is bad if there is no such palindrome $t_lt_{l+1} \dots t_r$ that $l \le i \le r$. Any character in substring $t_2t_3 \dots t_{k-1}$ is good. It can be proven as follows. If $t_i = t_{i+1}$ or $t_i = t_{i-1}$ then $t_i$ belong to a palindrome of length 2. If $t_i \neq t_{i+1}$ and $t_i \neq t_{i-1}$ then $t_i$ belong to a palindrome $t_{i-1} \dots t_{i+1}$.

So only characters $t_1$ and $t_k$ can be bad. But at the same time character $t_1$ is bad if there is no character $t_i$ such that $i > 1$ and $t_i = t_1$. It is true because substring $t_1t_2 \dots t_i$ is palindrome (index $i$ is minimum index such that $t_i = t_1$).

So, there are only 4 patterns of bad strings: 

1. $ABB \dots BB$;
2. $BAA \dots AA$;
3. $AA \dots AAB$;
4. $BB \dots BBA$;

All that remains is to count the number of substrings of this kind.

 **Solution (Roms)**
```cpp
n = int(input())
s = input()
res = n * (n - 1) // 2

for x in range(2):
	cur = 1
	for i in range(1, n):
		if s[i] == s[i - 1]:
			cur += 1
		else:
			res -= cur - x
			cur = 1
	s = s[::-1]

print(res) 
```
[1238E - Keyboard Purchase](../problems/E._Keyboard_Purchase.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1238E - Keyboard Purchase](../problems/E._Keyboard_Purchase.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Let's solve this problem by subset dynamic programming.

Let's denote $cnt_{x, y}$ as the number of adjacent characters ($s_i$ and $s_{i+1}$) in $s$ such that $s_i = x, s_{i+1} = y$ or $s_i = y, s_{i+1} = x$.

Let's $dp_{msk}$ be some intermediate result (further it will be explained what kind of intermediate result) if we already added letters corresponding to subset $msk$ to the keyboard (and we don't care about the order of these letters).

Now let's consider how to recalculate values of this dynamic programming using some $dp_{msk}$. Let's iterate over a new letter $x$ on keyboard (and we know the position of this letter on the keyboard: it's equal to the number of elements in $msk$). After adding this new letter, we want to calculate what it added to the $dp_{msk \cup x}$. Let consider some letter $y \neq x$ and calculate how much time will be spent on moving $x \rightarrow y$ and $y \rightarrow x$. There are two cases. If letter $y$ is already on current keyboard, then we should add to answer $cnt_{x, y} (pos_x - pos_y)$, and $cnt_{x, y} (pos_y - pos_x)$ otherwise (where $pox_a$ is the position of character $a$ on the keyboard). But we don't know the position of the letter $y$. Let's fix it as follows. We will add the contribution of some letter when it will be added to the keyboard. So, when we added letter $x$, we should add the value $\sum\limits_{y \in msk} (cnt_{x, y} pos_x) - \sum\limits_{y \notin msk} (cnt_{x, y} pos_x)$.

So, the total complexity is $O(a^2 2^a + n)$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void upd(int &a, int b){
	a = min(a, b);
}

const int N = 20;
const int M = (1 << N) + 55;
const int INF = int(1e9) + 100;

int a, n;
string s;
int cnt[N][N];
int d[M][N];
int dp[M];
int cntBit[M];
int minBit[M];

int main() {	
	cin >> n >> a >> s;
	
	int B = (1 << a) - 1;
	for(int i = 1; i < s.size(); ++i){
		++cnt[s[i] - 'a'][s[i - 1] - 'a'];
		++cnt[s[i - 1] - 'a'][s[i] - 'a'];
	}
	for(int i = 0; i < M; ++i)
		dp[i] = INF;
	dp[0] = 0;
	for(int msk = 1; msk < M; ++msk){
		cntBit[msk] = 1 + cntBit[msk & (msk - 1)];
		for(int i = 0; i < N; ++i) if((msk >> i) & 1){
			minBit[msk] = i;
			break;
		}
	}
	for(int msk = 1; msk < M; ++msk)
		for(int i = 0; i < a; ++i){
			int b = minBit[msk];
			d[msk][i] = d[msk ^ (1 << b)][i] + cnt[i][b];		
		}

	for(int msk = 0; msk < (1 << a); ++msk){
		for(int i = 0; i < a; ++i){
			if((msk >> i) & 1) continue;
			//i -> x
			int pos = cntBit[msk];
			int nmsk = msk | (1 << i);
			upd(dp[nmsk], dp[msk] + pos * (d[msk][i] - d[B ^ nmsk][i]));
		}
	}	

	cout << dp[B] << endl;
	return 0;
} 

```
[1238F - The Maximum Subtree](../problems/F._The_Maximum_Subtree.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1238F - The Maximum Subtree](../problems/F._The_Maximum_Subtree.md "Educational Codeforces Round 74 (Rated for Div. 2)")

At first let's understand which trees are good. For this, let's consider some vertex $v$ (we denote its segment as $[l_v, r_v]$) which is not a leaf. Also let's consider some adjacent vertex $u$ (we denote its segment as $[l_u, r_u]$) which also is not leaf. It is claimed that segment $[l_v, r_v]$ can't be inside segment $[l_u, r_u]$ (it's means $l_u \le l_v \le r_v \le r_u$) and vice versa. It's true because if segment $[l_v, r_v]$ is inside the segment $[l_u, r_u]$ then some vertex $t$ adjacent with $v$ also will be adjacent with $u$. So any non-leaf vertex can be adjacent with at most 2 non-leaf vertexes. Therefore good tree is a path with a leafs adjacent to this path.

So all the have to do it's find the such subtree of maximum size. We can do it by subtree dynamic programming.

At first, let chose the root of the tree — some not leaf vertex. 

Let $dp_{v, 0}$ be the answer for the subtree with root in $v$ and dp_{v, 1} be the answer for the subtree with root in $v$ if we already took $v$ and its parent to the answer.

It can be calculated as follows: 

* $dp_{v, 0} = \max\limits_{to} dp_{to, 0}$;
* $dp_{v, 0} = \max(dp_{v, 0}, deg_v + 1 + firstMax + secondMax)$, there $firstMax$ is a first maximum of all $dp_{to, 1}$, and $secondMax$ is a second maximum, and $deg_v$ is a degree of vertex $v$;
* $dp_{v, 1} = deg_v - 1 + \max\limits_{to} dp_{to, 1}$.
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n;
vector <int> g[N];
int d[N];
int dp[N][2];

void dfs(int v, int p){
	vector <int> d1;
	dp[v][1] = d[v] - 1;
	for(auto to : g[v]){
		if(to == p) continue;
		dfs(to, v);
		dp[v][0] = max(dp[v][0], dp[to][0]);
		if(g[to].size() > 1){
			d1.push_back(dp[to][1]);
			dp[v][1] = max(dp[v][1], d[v] + dp[to][1] - 1);	
		}
	}

	sort(d1.rbegin(), d1.rend());
	int x = d[v] + 1;
	for(int i = 0; i < 2; ++i)
		if(i < d1.size())
			x += d1[i];
    dp[v][0] = max(dp[v][0], x);
}

int main() {	
    int q;
    scanf("%d", &q);
    for(int qc = 0; qc < q; ++qc){
    	scanf("%d", &n);
    	for(int i = 0; i < n; ++i){
    	    g[i].clear();
    	    d[i] = 0;
    	    dp[i][0] = dp[i][1] = 0;
    	}
    	for(int i = 0; i < n - 1; ++i){
    		int u, v;
    		scanf("%d %d", &u, &v);
    		--u, --v;
    		g[u].push_back(v), g[v].push_back(u);
    	}
    
        if(n <= 2){
            printf("%dn", n);
            continue;
        }
        
    	for(int v = 0; v < n; ++v){
    		//d[v] = 1;
    		//for(auto to : g[v])	
    		//	d[v] += g[to].size() == 1;
    		d[v] = g[v].size();
    	}
        
        int r = -1;
        for(int v = 0; v < n; ++v)
            if(g[v].size() != 1)
                r = v;
                
    	dfs(r, r);
    	printf("%dn", dp[r][0]);
    }
	return 0;
}                             	

```
[1238G - Adilbek and the Watering System](../problems/G._Adilbek_and_the_Watering_System.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1238G - Adilbek and the Watering System](../problems/G._Adilbek_and_the_Watering_System.md "Educational Codeforces Round 74 (Rated for Div. 2)")

Despite the fact that statement sounds like some dp or flow, the actual solution is pretty greedy.

Let's iterate over all minutes Adilbek has to water at and maintain the cheapest $C$ liters he can obtain to this minute. Let this be some structure which stores data in form (price for 1 liter, total volume Adilbek can buy for this price). Pairs will be sorted by the price of a liter. The most convenient structure for that might be a C++ map, for example.

When moving to the next minute, pop the cheapest liter out of this structure and add it to the answer.

If that minute some friend comes, then push his water to the structure: if the total updated volume in the structure is greater than $C$, then pop the most expensive left-overs out of it so that the structure holds no more than $C$ liters total. That prevents out solution to fill the watering system over its capacity.

The main idea for why this greedy strategy works is that it's never optimal to take not the cheapest liter because a liter of that price or cheaper will still be available in the future minutes.

Note that between each pairs of adjacent coming friends basically nothing happens. Thus you can find the time between them and pop that number of cheapest liters right away instead of iterating minute by minute.

Overall complexity: $O(n \log n)$ per query.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef long long li;
typedef pair<int, int> pt;

const int N = 500 * 1000 + 13;

int n, m, c, c0;
pair<int, pt> a[N];

li solve() {
	scanf("%d%d%d%d", &n, &m, &c, &c0);
	forn(i, n) scanf("%d%d%d", &a[i].x, &a[i].y.x, &a[i].y.y);
	a[n++] = mp(m, mp(0, 0));
	sort(a, a + n);

	int sum = c0;
	map<int, int> q;
	q[0] = c0;
	
	li ans = 0;
	forn(i, n) {
		int x = a[i].x;
		int cnt = a[i].y.x;
		int cost = a[i].y.y;
	
		int dist = x - (i ? a[i - 1].x : 0);
		while (!q.empty() && dist > 0) {
			int can = min(q.begin()->y, dist);
			ans += q.begin()->x * 1ll * can;
			sum -= can;
			dist -= can;
			q.begin()->y -= can;
			if (q.begin()->y == 0) q.erase(q.begin());
		}
		
		if (dist > 0) 
			return -1;
		
		int add = min(c - sum, cnt);
		sum += add;
		
		while (add < cnt && !q.empty() && q.rbegin()->x > cost) {
			if (cnt - add >= q.rbegin()->y) {
				add += q.rbegin()->y;
				q.erase(--q.end());
			} else {
				q.rbegin()->y -= cnt - add;
				add = cnt;
			}
		}
		
		q[cost] += add;
	}
	
	return ans;
}

int main() {
	int q;
	scanf("%d", &q);
	forn(i, q) printf("%lldn", solve());
}
```
