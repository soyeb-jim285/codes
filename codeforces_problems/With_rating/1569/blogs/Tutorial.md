# Tutorial

[1569A - Balanced Substring](../problems/A._Balanced_Substring.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1569A - Balanced Substring](../problems/A._Balanced_Substring.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Any non-empty balanced string contains at least one letter 'a' and at least one letter 'b'. That implies that there's an 'a' adjacent to a 'b' somewhere in that string. Both strings "ab" and "ba" are balanced. Thus, any balanced string contains a balanced substring of length $2$. So the solution is to check all $n-1$ pairs of adjacent letters. If there exists a pair of different ones, print it.

Overall complexity: $O(n)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = input()
	for i in range(n - 1):
		if s[i] != s[i + 1]:
			print(i + 1, i + 2)
			break
	else:
		print(-1, -1)
```
[1569B - Chess Tournament](../problems/B._Chess_Tournament.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1569B - Chess Tournament](../problems/B._Chess_Tournament.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Since the chess players of the first type should not lose a single game, each game between two chess players of the first type should end in a draw (so that none of them gets defeated). And a game between a chess player of the first type and the second type should end either with a victory of the first or a draw. Therefore, for convenience, we will say that all games with a chess player of the first type end in a draw.

Now there are only games between chess players of the second type left. If there are only $1$ or $2$ such players, then there is no answer. Otherwise, we can choose the following method: the $i$-th chess player of the second type wins against the $i+1$-th chess player of the second type, and the last one wins against the first; all remaining games are drawn.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> id;
    for (int i = 0; i < n; ++i) if (s[i] == '2')
      id.push_back(i);
    int k = id.size();
    if (k == 1 || k == 2) {
      cout << "NOn";
      continue;
    }
    vector<string> t(n, string(n, '='));
    for (int i = 0; i < n; ++i) t[i][i] = 'X';
    for (int i = 0; i < k; ++i) {
      int x = id[i], y = id[(i + 1) % k];
      t[x][y] = '+';
      t[y][x] = '-';
    }
    cout << "YESn";
    for (int i = 0; i < n; ++i) cout << t[i] << 'n';
  }
}
```
[1569C - Jury Meeting](../problems/C._Jury_Meeting.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1569C - Jury Meeting](../problems/C._Jury_Meeting.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Note that if there are at least two members with the maximum value of $a_i$, then any permutation is nice.

Now let's consider the case when there is only one maximum. Let's find out when the permutation is nice. Let $x$ be the index of the jury member with the maximum number of tasks. Then, during the $a_x$-th discussion round, they will be the only one who will tell their task, because the other members of the jury have already told all their tasks. So during the $(a_x-1)$-th discussion round, there should be a jury member who tells a task after the $x$-th jury member.

Let $k$ be the number of elements in the array $a$ equal to $a_x-1$. Then, if at least one of these $k$ jury members goes after the jury member $x$ in the permutation, then the permutation is nice. Using this, we will count the number of bad permutations. Let's fix the elements in the permutation that are not equal to $a_x$ or $a_x-1$, there are $n-k-1$ of them, then the number of ways is $ A_n^{n-k-1} = \frac{n!}{(k+1)!}$. It remains to place $k+1$ elements so that the maximum is in the last position among them, there are $k!$ such ways. The total number of bad permutations is $\frac{n!k!}{(k+1)!}=\frac{n!}{k + 1}$. So the answer is $n! - \frac{n!}{k + 1}$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mx = *max_element(a.begin(), a.end());
    int cmx = count(a.begin(), a.end(), mx);
    int k = count(a.begin(), a.end(), mx - 1);
    int ans = 1, sub = 1;
    for (long long i = 1; i <= n; ++i) {
      ans = ans * i % MOD;
      if (i != k + 1) sub = sub * i % MOD;
    }
    if (cmx == 1) ans = (ans - sub + MOD) % MOD;
    cout << ans << 'n';
  }
}
```
[1569D - Inconvenient Pairs](../problems/D._Inconvenient_Pairs.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, m, k;
vector<int> x, y;
vector<pt> ps;

inline bool read() {
	if(!(cin >> n >> m >> k))
		return false;
	x.resize(n);
	fore (i, 0, n)
		cin >> x[i];
	y.resize(m);
	fore (i, 0, m)
		cin >> y[i];
	ps.resize(k);
	fore (i, 0, k)
		cin >> ps[i].x >> ps[i].y;
	
	return true;
}

inline void solve() {
	li ans = 0;
	
	fore (_i, 0, 2) {
		vector<int> cntY(m, 0);
		sort(all(ps));
		
		vector<pt> bord(k);
		
		int u = 0;
		while (u < k) {
			int v = u;
			while (v < k && ps[v].x == ps[u].x)
				v++;
			
			fore (i, u, v) {
				int r = int(lower_bound(all(y), ps[i].y) - y.begin());
				int l = r;
				if (y[l] > ps[i].y)
					l--;
				assert(y[l] <= ps[i].y && ps[i].y <= y[r]);
				
				bord[i] = {l, r};
			}
			
			fore (i, u, v) if (bord[i].x < bord[i].y)
				ans += cntY[bord[i].x];
			
			fore (i, u, v) if (bord[i].x < bord[i].y)
				cntY[bord[i].x]++;
			
			u = v;
		}
		
		
		fore (i, 0, k)
			swap(ps[i].x, ps[i].y);
		swap(x, y);
		swap(n, m);
	}
	
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
```
[1569E - Playoff Restoration](../problems/E._Playoff_Restoration.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1569E - Playoff Restoration](../problems/E._Playoff_Restoration.md "Educational Codeforces Round 113 (Rated for Div. 2)")

There are exactly $2^k-1$ games in the tournament, each game has only two possible outcomes. So it's possible to bruteforce all $2^k-1$ possible ways the tournament could go if $k$ is not large. In fact, this solution is fast enough when $k < 5$, so if we somehow can handle the case $k = 5$, we will have a working solution.

To handle $k = 5$, let's divide the teams into two groups: teams from $1$ to $16$ and teams from $17$ to $32$. There will be exactly $15$ matches in each group, and the winners of these two groups will play in the finals. The number of possible ways the games in a group can go is just $2^{15}$, so let's try to bruteforce all possible results in each group and somehow "merge" them into the results of the whole tournament.

The main idea is to rewrite $h$ as $(h_1 + h_2) \bmod 998244353$, where $h_1 = (\sum \limits_{i=1}^{16} i \cdot A^{p_i}) \bmod 998244353$, and $h_2 = (\sum \limits_{i=17}^{32} i \cdot A^{p_i}) \bmod 998244353$, find all possible values for $h_1$ and $h_2$, and choose a pair of values that yields exactly the given value of $h$.

We will handle two separate cases: the winner of the first group wins the whole tournament, or the winner of the second group wins the whole tournament. Suppose we are handling the first case (the second is symmetrical). By choosing the results of matches in the first group, we determine the places of the teams from the first group in the whole tournament: the winner of the first group gets place $1$, the team eliminated in the last match of the first group gets place $3$, and so on. It means that by choosing one of the $2^{15}$ possible results in the first group, we can calculate $h_1$. Let's bruteforce these $2^{15}$ combinations of results in the first group and store them in some data structure that allows to check whether some value of $h_1$ is achievable (in the model solution, it's a std::map which maps reachable values of $h_1$ to combinations of results that yield these values). Then, by choosing the results of matches in the second group, we can calculate $h_2$; so the remaining part of the solution is to bruteforce all $2^{15}$ possible results in the second group, calculate $h_2$ for them, and check that $h_1$ such that $(h_1 + h_2) \bmod 998244353 = h$ can be achieved by choosing the results in the first group. Don't forget to also handle the case when the team which wins in the first group loses in the finals (it is almost the same, but the winner in the first group gets place $2$ and the winner in the second group gets place $1$).

The technique I've described here (instead of bruteforcing all possible variants, split the thing we try to bruteforce into two parts, bruteforce them separatedly, and then try to "merge" the parts) is called meet-in-the-middle and can be used to solve a large variety of problems.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
 	x += y;
 	while(x >= MOD) x -= MOD;
 	while(x < 0) x += MOD;
 	return x;
}

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
 	int z = 1;
 	while(y)
 	{
 	 	if(y & 1) z = mul(z, x);
 	 	x = mul(x, x);
 	 	y >>= 1;
 	}
 	return z;
}

vector<int> evaluate(int n, int choice_mask)
{
 	int cur_place = n / 2 + 1;
 	int cur_bit = n - 2;
 	vector<int> p(n);
 	vector<int> c(n);
 	for(int i = 0; i < n; i++)
 		c[i] = i;
 	while(c.size() != 1)
 	{
 		vector<int> nc;
 	 	for(int i = 0; i < c.size(); i += 2)
 	 	{
 	 	 	if(choice_mask & (1 << cur_bit))
 	 	 	{
 	 	 		p[c[i]] = cur_place;
 	 	 		nc.push_back(c[i + 1]);
 	 	 	}
 	 	 	else
 	 	 	{
 	 	 		p[c[i + 1]] = cur_place;
 	 	 		nc.push_back(c[i]);
 	 	 	}
 	 	 	cur_bit--;
 	 	}
 	 	c = nc;
 	 	cur_place /= 2;
  		cur_place++;
	}
	p[c[0]] = 1;
	return p;
}

vector<int> adjust(int n, vector<int> p, bool winning)
{
	for(int i = 0; i < n; i++)
	{
		if(p[i] == 1)
		{
		 	if(!winning) p[i]++;	
		}
		else
		 	p[i] = p[i] * 2 - 1;
	}
	return p;
}	

int get_hash(int n, vector<int> p, int A, bool partial = false, bool winning = false, int shift = 0)
{
	if(partial)
		p = adjust(n, p, winning);
 	int res = 0;
 	for(int i = 0; i < n; i++)
 		res = add(res, mul(add(i + 1, shift), binpow(A, p[i])));
 	return res;
}

int main()
{
 	int k, A, h;
 	cin >> k >> A >> h;
 	if(k <= 4)
 	{
 		for(int i = 0; i < (1 << ((1 << k) - 1)); i++)
 		{             
 			vector<int> p = evaluate(1 << k, i);
 			if(get_hash(1 << k, p, A) == h)
 			{
 		 		for(auto x : p) cout << x << " ";
 		 		cout << endl;
 		 		return 0;
 			}
 		}
 	}
 	else
 	{
 		int mask_left = -1;
 		int mask_right = -1;
 		bool left_win = false;
 		for(int c = 0; c < 2; c++)
 		{
 		 	map<int, int> left_map;
 		 	for(int i = 0; i < (1 << 16); i++)
 		 	{
 		 	 	vector<int> p = evaluate(16, i);
 		 	 	int left_hash = get_hash(16, p, A, true, c == 0, 0);
 		 	 	left_map[left_hash] = i;	
 		 	}
 		 	for(int i = 0; i < (1 << 16); i++)
 		 	{
 		 	 	vector<int> p = evaluate(16, i);
 		 	 	int right_hash = get_hash(16, p, A, true, c == 1, 16);
 		 	 	int left_hash = add(h, MOD - right_hash);
 		 	 	if(left_map.count(left_hash))
 		 	 	{
 		 	 	 	mask_left = left_map[left_hash];
 		 	 	 	mask_right = i;
 		 	 	 	left_win = (c == 0);
 		 	 	}
 		 	}
 	 	}
 	 	if(mask_left != -1)
 		{
 	 		vector<int> ans_left = evaluate(16, mask_left);
 	 		vector<int> ans_right = evaluate(16, mask_right);
 	 		ans_left = adjust(16, ans_left, left_win);
 	 		ans_right = adjust(16, ans_right, !left_win);
 	 		for(auto x : ans_left)
 	 			cout << x << " ";
 	   		for(auto x : ans_right)
 	   			cout << x << " ";
 	   		return 0;
 		}        
 	}
 	cout << -1 << endl;
 	return 0;
}

```
[1569F - Palindromic Hamiltonian Path](../problems/F._Palindromic_Hamiltonian_Path.md "Educational Codeforces Round 113 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

vector<vector<char>> g;
map<long long, bool> dp;

void brute(int n, vector<int> &p){
	int x = find(p.begin(), p.end(), -1) - p.begin();
	if (x == int(p.size())){
		vector<vector<char>> dp2(1 << n, vector<char>(n));
		vector<int> pos1(n), pos2(n);
		forn(i, p.size()){
			pos1[p[i]] = pos2[p[i]];
			pos2[p[i]] = i;
		}
		forn(i, n) if (g[pos1[i]][pos2[i]]) dp2[1 << i][i] = true;
		forn(mask, 1 << n) forn(i, n) if (dp2[mask][i]){
			forn(j, n) if (!((mask >> j) & 1)){
				dp2[mask | (1 << j)][j] |= (g[pos1[i]][pos1[j]] && g[pos2[i]][pos2[j]]);
				dp2[mask | (1 << j)][j] |= (g[pos1[i]][pos2[j]] && g[pos2[i]][pos1[j]]);
			}
		}
		forn(i, n) if (dp2[(1 << n) - 1][i]){
			long long num = 0;
			for (int x : p) num = num * 6 + x;
			dp[num] = true;
			break;
		}
		return;
	}
	for (int y = x + 1; y < int(p.size()); ++y) if (p[y] == -1){
		p[x] = p[y] = n;
		brute(n + 1, p);
		p[x] = p[y] = -1;
	}
}

bool dfs(vector<int> p){
	vector<int> used(int(p.size()), -1);
	int cnt = 0;
	forn(i, p.size()) if (used[p[i]] == -1)
		used[p[i]] = cnt++;
	long long num = 0;
	for (int& x : p){
		x = used[x];
		num = num * 6 + x;
	}
	if (dp.count(num)) return dp[num];
	bool res = false;
	vector<int> cur(cnt);
	forn(i, p.size()) ++cur[p[i]];
	forn(i, p.size()) if (cur[p[i]] > 2){
		int x = p[i];
		for (int j = i + 1; j < int(p.size()); ++j) if (p[j] == p[i]){
			p[i] = p[j] = cnt;
			if (dfs(p)){
				res = true;
				break;
			}
			p[i] = p[j] = x;
		}
		break;
	}
	return dp[num] = res;
}

void brute2(int n, vector<int> &p){
	int x = find(p.begin(), p.end(), -1) - p.begin();
	if (x == int(p.size())){
		dfs(p);
		return;
	}
	forn(i, n + 1){
		for (int y = x + 1; y < int(p.size()); ++y) if (p[y] == -1){
			p[x] = p[y] = i;
			brute2(max(n, i + 1), p);
			p[x] = p[y] = -1;
		}
	}
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	g.resize(n, vector<char>(n));
	forn(_, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v][u] = g[u][v] = 1;
	}
	vector<int> cur(n, -1);
	brute(0, cur);
	brute2(0, cur);
	vector<long long> fact(k + 1);
	fact[0] = 1;
	for (int i = 1; i <= k; ++i) fact[i] = fact[i - 1] * i;
	long long ans = 0;
	for (auto it : dp) if (it.second){
		long long num = it.first;
		long long mx = 1;
		while (num){
			mx = max(mx, num % 6 + 1);
			num /= 6;
		}
		if (mx <= k){
			ans += fact[k] / fact[k - mx];
		}
	}
	printf("%lldn", ans);
	return 0;
}

```
