# Tutorial

[1535A - Fair Playoff](../problems/A._Fair_Playoff.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1535A - Fair Playoff](../problems/A._Fair_Playoff.md "Educational Codeforces Round 110 (Rated for Div. 2)")

It is easier to determine the case when the players with the maximum skills will not meet in the finals. It means that they met in the semifinals, and in the other semifinals, both players are weaker.

It's easy to check this case with the following formula: min(s1,s2)>max(s3,s4) or max(s1,s2)<min(s3,s4).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> s(4);
    for (int& x : s) cin >> x;
    if (min(s[0], s[1]) > max(s[2], s[3]) || max(s[0], s[1]) < min(s[2], s[3]))
      cout << "NOn";
    else
      cout << "YESn";
  }
}

```
[1535B - Array Reodering](../problems/B._Array_Reodering.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1535B - Array Reodering](../problems/B._Array_Reodering.md "Educational Codeforces Round 110 (Rated for Div. 2)")

If the value of $a_i$ is even, then $\gcd(a_i, 2a_j)$ at least $2$, regardless of the value of $a_j$. Therefore, we can put all the even values before the odd ones (it does not matter in what order). Now it remains to arrange the odd values. In fact, their order is not important, because $\gcd(a_i, 2a_j) = \gcd(a_i, a_j)$ (for odd $a_i$ and $a_j$). This means that each pair will be considered exactly $1$ time, regardless of the order of the odd elements.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end(), [](int x, int y) {
      return x % 2 < y % 2;
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans += __gcd(a[i], a[j] * 2) > 1;
      }
    }
    cout << ans << endl;
  }
}

```
[1535C - Unstable String](../problems/C._Unstable_String.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1535C - Unstable String](../problems/C._Unstable_String.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Let's find a simple condition when the string is not beautiful. A string is not beautiful if there are two characters 0 (or two characters 1) at an odd distance, or 0 and 1 at an even distance (because in this case, the string cannot be made unstable).

Iterate over the right border of the substring $r$. Let $l$ be the maximum index such that the substring $s[l, r]$ is not beautiful (or $0$ if the substring $s[1, r]$ is beautiful). Then we have to add $r - l$ to the answer (since any substring of a beautiful string is also beautiful).

Denote $lst_{c, p}$ as the last occurrence of $c$ ($0$ or $1$) at the position of parity $p$.

Let $s_r = 0$, $p$ is the parity of $r$, then $l = \max(lst_{0, p \oplus 1}, lst_{1, p})$, i. e. find the nearest character that breaks a beautiful substring (0 at an odd distance or 1 at an even distance)

The case for $s_r = 1$ is similar. If $s_r = ?$, then we can choose what this character will be. Obviously, we need to choose the option with the smaller value of $l$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<vector<int>> lst(2, vector<int>(2, -1));
    long long ans = 0;
    for (int i = 0; i < int(s.size()); ++i) {
      int j = i - 1;
      int p = i & 1;
      if (s[i] != '1') j = min(j, max(lst[0][p ^ 1], lst[1][p]));
      if (s[i] != '0') j = min(j, max(lst[0][p], lst[1][p ^ 1]));
      ans += i - j;
      if (s[i] != '?') lst[s[i] - '0'][p] = i;
    }
    cout << ans << 'n';
  }
}

```
[1535D - Playoff Tournament](../problems/D._Playoff_Tournament.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1535D - Playoff Tournament](../problems/D._Playoff_Tournament.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Denote $cnt_i$ as the number of teams that can be winners in the $i$-th game. The answer to the problem is $cnt_{2^k-1}$.

If the $i$-th game is played between the winners of games $x$ and $y$ ($x < y$), then: 

* $cnt_i = cnt_x$ if $s_i = 0$;
* $cnt_i = cnt_y$ if $s_i = 1$;
* $cnt_i = cnt_x + cnt_y$ if $s_i = ?$.

So we can calculate all values of $cnt$ for the initial string.

Note that the result of no more than $k$ other games depends on the result of any game. So, if we change $s_p$, it will change no more than $k$ values of $cnt$, and we can recalculate all of them.

For convenience, you can renumerate the games so that the playoff looks like a segment tree, i. e. the final has the number $0$, the semifinals have numbers $1$ and $2$, etc.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  
  int k;
  cin >> k;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  
  int n = 1 << k;
  vector<int> cnt(2 * n, 1);
  
  auto upd = [&](int i) {
    return cnt[i] = (s[i] != '0' ? cnt[i * 2 + 1] : 0) + (s[i] != '1' ? cnt[i * 2 + 2] : 0);
  };
  
  for (int i = n - 2; i >= 0; i--) {
    upd(i);
  }
  
  int q;
  cin >> q;
  while (q--) {
    int p;
    char c;
    cin >> p >> c;
    p = n - p - 1;
    s[p] = c;
    while (p) {
      upd(p);
      p = (p - 1) / 2;
    }
    cout << upd(0) << 'n';
  }
}

```
[1535E - Gold Transfer](../problems/E._Gold_Transfer.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1535E - Gold Transfer](../problems/E._Gold_Transfer.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Note, that $c_i > c_{p_i}$ for each vertex $i$. So if we consider a path from some vertex $v$ to $0$, the closer you are to $0$, the cheaper the cost. In other words, it's always optimal to choose the highest vertex on the path with $a_i > 0$.

Suppose we can find such vertex $u$ for a given $v$. How many times we will repeat this search operation? If we need to buy $w$ tons and $u$ has $a_u$ tons, then it's optimal to buy $mn = \min(w, a_u)$ tons in $u$. After we buy $mn$ tons, either $w$ becomes $0$ or $a_u$ becomes $0$.

Since for each vertex $u$, $a_u$ can become equal to zero at most once, and since after $w$ is zero we stop buying, then there will be $O(q)$ searches in total. The next question is how to find $u$ efficiently for a given $v$?

Consider the path from $0$ to some vertex $v$. Since we prefer to buy from higher vertices, all empty vertices on this path will form some prefix of it (possibly, empty prefix). So we can make some sort of binary search to find the first non-empty vertex $u$. But instead of binary search we will use binary lifting technique.

If we know for each $k$ ($0 \le k < 20$) which vertex $p[k][v]$ on the path from $v$ to $0$ on distance $2^k$ from $v$ then we can efficiently jump up the path. Let's firstly jump at distance $2^{19}$: if $a[p[19][v]] = 0$ then we jump too high — let's not jump. But if $a[p[19][v]] > 0$ then we can safely jump (or $v = p[19][v]$). Now we know that we don't need a second $2^{19}$ jump, so we try $2^{18}$ jump and so on.

In other words, using binary lifting we can find the highest vertex $u$ with $a_u > 0$ in $O(\log(q))$ steps. Also, we can calculate array $p[k][v]$ for vertex $v$ right after we add vertex $v$ to the tree, since $p[0][v] = p_i$ and $p[k][v] = p[k - 1][p[k - 1][v]]$.

The resulting complexity is $O(q \log(q))$.

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

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	out << "[";
	fore(i, 0, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);

const int LOG = 20;

int q;
vector<int> a, c;
vector<int> p[LOG];

int main() {
	cin >> q;
	a.resize(q + 1);
	c.resize(q + 1);
	
	fore (lg, 0, LOG)
		p[lg].resize(q + 1);

	fore (lg, 0, LOG)
		p[lg][0] = 0;
	cin >> a[0] >> c[0];
	
	fore (id, 1, q + 1) {
		int tp; cin >> tp;
		if (tp == 1) {
			int pr; cin >> pr;
			cin >> a[id] >> c[id];
			
			p[0][id] = pr;
			fore (lg, 1, LOG)
				p[lg][id] = p[lg - 1][p[lg - 1][id]];
		} 
		else {
			int v, w;
			cin >> v >> w;
			
			int ansR = 0;
			li ansS = 0;
			
			while (w > 0 && a[v] > 0) {
				int u = v;
				for (int lg = LOG - 1; lg >= 0; lg--) {
					if (a[p[lg][u]] > 0)
						u = p[lg][u];
				}
				int mn = min(a[u], w);
				a[u] -= mn;
				w -= mn;
				
				ansR += mn;
				ansS += mn * 1ll * c[u];
			}
			cout << ansR << " " << ansS << endl;
		}
	}
		
	return 0;
}

```
[1535F - String Distance](../problems/F._String_Distance.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1535F - String Distance](../problems/F._String_Distance.md "Educational Codeforces Round 110 (Rated for Div. 2)")

Disclaimer: the model solution is very complicated compared to most participants' solutions. Feel free to discuss your approaches in the comments!

First of all, it's easy to determine when two strings cannot be made equal using these operations: it's when their multisets of characters differ. So, we divide the strings into different equivalence classes, and for any pair of strings from different classes, the answer is $1337$. For any pair of strings from the same class, the answer is either $1$ or $2$, since $2$ operations are always enough to make the strings from the same equivalence class equal (we just sort both of them). Okay, now, for each class, we have to calculate the number of pairs of strings with the distance equal to $1$.

Okay, suppose you have two strings $s_1$ and $s_2$, and you want to make them equal using one operation. Suppose that $s_1 < s_2$ lexicographically. Since applying an operation can't result in getting a lexicographically larger string, we should apply the operation on the string $s_2$, not $s_1$. 

Suppose we choose a substring $[l, r]$ of the string $s_2$ and sort it. All characters to the left of position $l$ and to the right of position $r$ are untouched, and all characters in $[l, r]$ are ordered in non-descending order; so, in order to transform $s_2$ into $s_1$, we should choose a subsegment $[l, r]$ such that all characters outside this segment are the same in both strings, and the substring $[l, r]$ of $s_1$ is sorted. So, the best way to choose a subsegment $[l, r]$ is to compute the longest common prefix of $s_1$ and $s_2$, the longest common suffix of $s_1$ and $s_2$, and try sorting everything in the middle in $s_2$. 

This gives us a solution in $O(n^2)$: for a pair of strings, we can check that one of them can be transformed into the other in $O(1)$. To do so, we need to build some data structure allowing to query longest common prefixes/suffixes in $O(1)$ (a trie with $O(1)$ LCA or precalculating LCP and building a sparse table of them can do the trick); furthermore, we want to be able to check if some subsegment of some string is sorted in $O(1)$ (but precalculating them is quite easy). So, we have a solution that works if the strings are long (in the model solution, this approach is used on classes having not more than $12000$ strings).

The second approach can be used on classes having many strings. If the number of strings is big, it means that they are short, so we can do the following thing: for each string, iterate on the subsegment we will sort and check if the resulting string exists. The model solution uses some very complicated data structures to implement this, but I believe that it's quite easy to get this approach working using string hashes.

The only dangerous thing in the second solution you have to consider is that choosing different substrings to sort may result in getting the same resulting string. One good way to deal with this is to ignore some substrings if sorting them doesn't change the leftmost or the rightmost character in the substring; for example, if we sort the substring acb in the string zacb, the character in the beginning of this substring is unchanged, so we can get the same result by sorting cb. So, we consider sorting the substring only if it changes both the first and the last characters of the substring.

Okay, so we have two approaches: one works well with a small number of long strings, and the other works well with a big number of short strings. We can choose which of them to run depending on the size of the equivalence class we are considering, and this idea gives us a working solution.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>   
using namespace std;

const int LN = 20;
const int K = 12000;

int pw2[1 << LN];

vector<int> sorted_segments(const string& s)
{
 	int n = int(s.size()) - 1;
 	vector<int> res(n);
 	for(int i = 0; i < n; i++)
 		if(s[i] <= s[i + 1])
 			res[i] = 0;
 		else
 			res[i] = 1;
 	return res;
}

vector<int> prefix_sum(const vector<int>& s)
{
 	int n = s.size();
 	vector<int> p(n + 1);
 	for(int i = 0; i < n; i++)
 		p[i + 1] = p[i] + s[i];
 	return p;
}

int naiveLCP(const string& s, const string& t)
{
 	int ans = 0;
 	int n = s.size();
 	int m = t.size();
 	while(ans < n && ans < m && s[ans] == t[ans])
 		ans++;
 	return ans;
}

vector<vector<int>> build_table(const vector<int>& a)
{
	int n = a.size();
	vector<vector<int>> table(LN, vector<int>(n));
	for(int i = 0; i < n; i++)
		table[0][i] = a[i];
	for(int i = 1; i < LN; i++)
		for(int j = 0; j < n; j++)
			if(j + (1 << (i - 1)) < n)
				table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			else
				table[i][j] = table[i - 1][j];
	return table; 	
}

struct LCP
{
 	vector<int> idx;
 	vector<vector<int>> table;

 	int query_inner(int x, int y)
 	{
 	 	if(x > y) swap(x, y);
 	 	int len = y - x;
 	 	int d = pw2[len];
 	 	return min(table[d][x], table[d][y - (1 << d)]);
 	}

 	int query(int x, int y)
 	{
 	 	return query_inner(idx[x], idx[y]);
 	}

 	LCP() {};
 	LCP(vector<string> s) 
 	{
 		int n = s.size();
		vector<pair<string, int>> t;
		for(int i = 0; i < n; i++)
		{
		 	t.push_back(make_pair(s[i], i));
	   	}
	   	sort(t.begin(), t.end());
	   	idx.resize(n);
	   	for(int i = 0; i < n; i++)
	   	{
	   		idx[t[i].second] = i;
	   	}
	   	vector<int> LCPs;
	   	for(int i = 0; i < n - 1; i++)
	   		LCPs.push_back(naiveLCP(t[i].first, t[i + 1].first));
	   	table = build_table(LCPs);		
 	};
};

const int T = int(2e7);

map<char, int> nxt[T];
int cur = 1;
int root = 0;
int cnt[T];

void clear_trie()
{
 	root = cur++;
}

int go(int x, char c)
{
 	if(!nxt[x].count(c))
 		nxt[x][c] = cur++;
 	return nxt[x][c];
}

void add(int v, const string& s, int l, int r, int n, bool sw, const vector<int>& ps)
{
	if(sw && l + r < n - 1 && ps[n - r - 1] == ps[l])
	{
		cnt[v]++;
	}
	if(sw)
	{
		if(l + r < n - 1)
			add(go(v, s[n - r - 1]), s, l, r + 1, n, sw, ps);
 	}
 	else
 	{
 		add(go(v, '$'), s, l, r, n, true, ps);
 		if(l < n - 1)
 			add(go(v, s[l]), s, l + 1, r, n, sw, ps);
 	}
}

int calc(int v, const string& s, int l, int r, int n, bool sw, const vector<vector<int>>& good)
{
	int ans = 0;
	if(sw && l + r < n - 1 && good[l][r])
	{
		ans = cnt[v];
	}
	if(sw)
	{
		if(l + r < n)
			ans += calc(go(v, s[n - r - 1]), s, l, r + 1, n, sw, good);
	}
	else
	{
	 	ans += calc(go(v, '$'), s, l, r, n, true, good);
	 	if(l < n)
	 		ans += calc(go(v, s[l]), s, l + 1, r, n, sw, good);	
	}
	return ans;
}

long long solve_short(vector<string> s, int n)
{
	long long ans = 0;
 	clear_trie();
 	sort(s.begin(), s.end());
 	for(int i = 0; i < n; i++)
 	{
 	 	string cur = s[i];
 	 	int len = cur.size();
 	 	vector<vector<int>> good(len + 1, vector<int>(len + 1));
 	 	for(int l = 0; l < len; l++)
 	 	{
 	 	 	set<char> q;
 	 	 	for(int r = l; r < len; r++)
 	 	 	{
 	 	 	 	q.insert(cur[r]);
 	 	 	 	if(cur[l] != *q.begin() && cur[r] != *q.rbegin())
 	 	 	 	{
 	 	 	 		good[l][len - r - 1] = 1;
 	 	 	 	}
 	 	 	}
 	 	}
 	 	vector<int> p = prefix_sum(sorted_segments(cur));
 	 	add(root, cur, 0, 0, len, false, p);
 	 	ans += calc(root, cur, 0, 0, len, false, good);
 	}
 	ans = n * 1ll * (n - 1) - ans;
 	return ans;
}

long long solve_long(vector<string> s, int n)
{                     
	int len = s[0].size();
 	sort(s.begin(), s.end());
 	vector<string> t = s;
 	for(int i = 0; i < n; i++)
 		reverse(t[i].begin(), t[i].end());
 	LCP ls(s);
 	LCP lt(t);
 	long long ans = 0;
 	for(int i = 0; i < n; i++)
 	{
 	 	vector<int> aux = prefix_sum(sorted_segments(s[i]));
 	 	for(int j = i + 1; j < n; j++)
 	 	{
 	 	 	int lf = ls.query(i, j);
 	 	 	int rg = lt.query(i, j);
 	 	 	if(aux[len - rg - 1] - aux[lf] == 0)
 	 	 		ans++;
 	 	 	else
 	 	 		ans += 2;
 	 	}
	}
	return ans;
}

long long solve_class(vector<string> s, int n)
{                       
	if(n <= K)
		return solve_long(s, n);
	else
		return solve_short(s, n); 	
}

vector<int> get_class(string s)
{
	vector<int> c(26);
	for(auto x : s) c[x - 'a']++;
	return c;
}

int main()
{
	pw2[1] = 0;
	for(int i = 2; i < (1 << LN); i++)
		pw2[i] = pw2[i >> 1] + 1;
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++)   
		cin >> s[i];         
	long long ans = 0;
	map<vector<int>, vector<string>> classes;
	for(int i = 0; i < n; i++)
		classes[get_class(s[i])].push_back(s[i]);
	int cnt = 0;
	for(auto x : classes)
	{                       
	 	ans += solve_class(x.second, x.second.size());
	 	ans += cnt * 1337ll * x.second.size();
	 	cnt += x.second.size();
	}
	cout << ans << endl;
}

```
