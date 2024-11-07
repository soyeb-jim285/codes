# Tutorial

[1697A - Parkway Walk](../problems/A._Parkway_Walk.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1697A - Parkway Walk](../problems/A._Parkway_Walk.md "Educational Codeforces Round 130 (Rated for Div. 2)")

If you have at least $sum(a_i)$ units of energy, then the answer is $0$, because you can just walk to the end. Otherwise, the answer is $sum(a_i) - m$, because you can just sit on the first bench and then just go.

Time complexity: $O(n)$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", H"r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << max(0, sum - m) << endl;
    }
    
    return 0;
}
```
[1697B - Promo](../problems/B._Promo.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1697B - Promo](../problems/B._Promo.md "Educational Codeforces Round 130 (Rated for Div. 2)")

First of all, there is an answer with exactly x items bought. Suppose items worth p1≤p2≤⋯≤pm (x<m) were purchased. Then by removing p1 from this set, the sum of y the cheapest items in the set will change by py+1−p1≥0, which means the answer will not decrease.

The second fact that is necessary to solve the problem  — x of the most expensive items should be chosen. Otherwise, one can remove the minimum price item from the set and add an item with a higher price (it can always be found), which means the answer will not decrease.

Using these two facts, it is enough to sort the array and use prefix sums.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long> p(n), s(n + 1);
  for (auto& x : p) cin >> x;
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) s[i + 1] = s[i] + p[i];
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << s[n - x + y] - s[n - x] << 'n';
  }
} 
```
[1697C - awoo's Favorite Problem](../problems/C._awoo's_Favorite_Problem.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1697C - awoo's Favorite Problem](../problems/C._awoo's_Favorite_Problem.md "Educational Codeforces Round 130 (Rated for Div. 2)")

First, check that the counts of all letters are the same in both strings.

Then consider the following restatement of the moves. The letters 'b' in the string $s$ are stationary. Letters 'a' and 'c', however, move around the string. The move of the first type moves a letter 'a' to the right. The move of the second type moves a letter 'c' to the left.

Notice that letters 'a' and 'c' can never swap with each other. Thus, if you remove all letters 'b' from both strings, the remaining strings should be the same.

Again, since letters 'a' and 'c' can never swap with each other, you can deduce where each of these letters should end up after the swaps. The first letter '{a}' in $s$ should be on the position of the first letter 'a' in $t$ and so on.

After that, we recall that 'a's can only move to the right and 'c's can only move to the left. Thus, we check that the $i$-th occurrence of 'a' in $s$ is to the left or equal to the $i$-th occurrences of 'a' in $t$ and vice versa for 'c's.

Finally, we can see that this is a sufficient condition. Easy to show by construction: you can just fix the positions one after another left to right.

Overall complexity: $O(n)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = input()
	t = input()
	if s.count('b') != t.count('b'):
		print("NO")
		continue
	j = 0
	for i in range(n):
		if s[i] == 'b':
			continue
		while t[j] == 'b':
			j += 1
		if s[i] != t[j] or (s[i] == 'a' and i > j) or (s[i] == 'c' and i < j):
			print("NO")
			break
		j += 1
	else:
		print("YES")
```
[1697D - Guess The String](../problems/D._Guess_The_String.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1697D - Guess The String](../problems/D._Guess_The_String.md "Educational Codeforces Round 130 (Rated for Div. 2)")

There are several ways to solve this problem. The model solution does it as follows:

Restore the characters of $s$ from left to right. The first character is restored by query ? 1 1. For each of the next characters, let's ask if this character is new (by querying ? 2 1 i and comparing the result with the number of different characters on the segment $[1, i-1]$). If it's new, ask ? 1 i to obtain the $i$-th character (there will be at most $26$ such queries).

Otherwise, we can find the previous occurrence of the $i$-th character with binary search. Let $f(x,y)$ be the number of different characters from position $x$ to position $y$. If we want to find the previous occurrence of the $i$-th character, we need to find the last index $j$ such that $f(j,i) = f(j,i-1)$. Since the value $f(j,i) - f(j,i-1)$ does not decrease when we increase $j$, we can find the last $j$ such that $f(j,i) - f(j,i-1) = 0$, with binary search.

Unfortunately, the number of queries of type $2$ will be too large if we just use binary search over the whole segment $[1,i-1]$. To decrease the number of queries, we can use the fact that the value of $j$ we are interested in is the last occurrence of some character we already met; there are at most $26$ such values, and binary search among them will need only $5$ iterations.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

char ask_character(int i)
{
    cout << "? 1 " << i << endl;
    cout.flush();
    string s;
    cin >> s;
    return s[0];
}

int ask_cnt(int l, int r)
{
    cout << "? 2 " << l << " " << r << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main()
{
    int n;
    cin >> n;
    string s = "";
    vector<vector<int>> cnt(n + 1);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            s.push_back(ask_character(1));
            cnt[0] = {1};
        }
        else
        {
             int cur = ask_cnt(1, i + 1);
             if(cur > cnt[i - 1][0])
                s.push_back(ask_character(i + 1));
             else
             {
                map<char, int> last;
                for(int j = 0; j < s.size(); j++)
                    last[s[j]] = j;
                vector<int> lasts;
                for(auto x : last) lasts.push_back(x.second);
                sort(lasts.begin(), lasts.end());
                int l = 0;
                int r = lasts.size();
                // there is always an occurrence in [lasts[l], i)
                // there is no occurrence in [lasts[r], i)
                while(r - l > 1)
                {
                    int m = (l + r) / 2;
                    int c = ask_cnt(lasts[m] + 1, i + 1);
                    if (c == cnt[i - 1][lasts[m]])
                        l = m;
                    else
                        r = m;
                }   
                s.push_back(s[lasts[l]]);                                                
             }
             cnt[i].resize(i + 1);
             set<char> q;
             for(int j = i; j >= 0; j--)
             {
                q.insert(s[j]);
                cnt[i][j] = q.size();
             }
        }
    }
    cout << "! " << s << endl;
    cout.flush();
    return 0;
}
```
[1697E - Coloring](../problems/E._Coloring.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1697E - Coloring](../problems/E._Coloring.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Let's call a point $i$ isolated if its color does not match the color of any other point. If a point is not isolated, then it has the same color as the points with minimum distance to it (and only these points should have this color).

Let's build a directed graph where the arc $i \rightarrow j$ means that the point $j$ is one of the closest to the point $i$ (i. e. $d(i, j) = \min\limits_{k = 1, k \ne i}^{n} d(i,k)$). If there is a path from the vertex $i$ to the vertex $j$, it means that if the vertex $i$ is not isolated, the vertex $j$ should have the same color as vertex $i$.

Suppose the set of vertices reachable from $i$ (including $i$ itself) is $S(i)$. Finding $S(i)$ is easy — just run DFS from the vertex $i$. Let's analyze two cases:

* there exists a pair of vertices $(j, k)$ such that $j \in S(i)$, $k \in S(i)$, and there is no arc from $j$ to $k$;
* for every pair of vertices $(j, k)$ such that $j \in S(i)$ and $k \in S(i)$, there is an arc $j \rightarrow k$.

Why do we need to analyze these two cases? In the first case, the vertex $i$ must be isolated, because painting it and some other vertex into the same color means that every vertex from $S(i)$ will have this color, and it will break the condition in the statement. In the second case, the vertex $i$ may be isolated, or it may have the same color as all vertices in $S(i)$ — and if it is isolated, then the whole set $S(i)$ should consist of isolated vertices.

Let's find all such set of vertices that meet the second case. Each vertex will belong to at most one of these sets; if it doesn't belong to any, it must be isolated, otherwise either the whole its set consists of isolated vertices, or the whole set has the same color. So, for each set, we either use $1$ color or $|S(i)|$ colors. This allows us to implement a knapsack-like dynamic programming: let $dp_{i,j}$ be the number of ways to paint $i$ first sets into $j$ colors, such that the colors are not ordered. After running this dynamic programming, we can get the answer by simple combinatorics: iterate on the number of colors we use in these sets in total, multiply the dynamic programming for it by the (ordered) number of ways to choose these colors from $n$, and then by the number of ways to choose the colors for points that must be isolated.

This dynamic programming can even be implemented a bit easier if we treat every vertex that must be isolated as a set of size $1$, and this is the way it's written in the model solution.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 143;
const int K = 5;
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
    while(y > 0)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int fact[N];
int rfact[N];

int A(int n, int k)
{
    return mul(fact[n], rfact[n - k]);
}

int n;

vector<int> g[N];
int x[N];
int y[N];
int dist[N][N];
int color[N];
int dp[N][N];

int cc = 0;
set<int> pts;
vector<int> compsize;

void dfs1(int i)
{
    //cerr << i << endl;
    if(pts.count(i) == 1) return;
    pts.insert(i);
    for(auto v : g[i])
    {
        dfs1(v);
    }
}

void dfs2(int i, int c)
{
    if(color[i] == c) return;
    color[i] = c;
    for(auto v : g[i])
        dfs2(v, c);
}

int main()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(i, fact[i - 1]);
    for(int i = 0; i < N; i++)
        rfact[i] = binpow(fact[i], MOD - 2);


    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);    
    }
    for(int i = 0; i < n; i++)
    {
        dist[i][i] = int(1e9);
        for(int j = 0; j < n; j++)
            if(i != j)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
    for(int i = 0; i < n; i++)
    {
        int d = *min_element(dist[i], dist[i] + n);
        for(int j = 0; j < n; j++)
            if(dist[i][j] == d) g[i].push_back(j);    
    }

    for(int i = 0; i < n; i++)
    {
        if(color[i] != 0) continue;
        cc++;
        pts.clear();
        dfs1(i);
        //cerr << "!" << endl; 
        int d = *min_element(dist[i], dist[i] + n);                      
        set<int> pts2 = pts;
        bool bad = false;
        for(auto x : pts)
            for(auto y : pts2)
                if(x != y && dist[x][y] != d)
                    bad = true;
        if(bad)           
        {
            color[i] = cc;
            compsize.push_back(1);
        }
        else
        {
            dfs2(i, cc);
            compsize.push_back(pts.size());
        }
    }            

    dp[0][0] = 1;
    int m = compsize.size();
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] == 0) continue;
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
            if(compsize[i] != 1)
            {
                dp[i + 1][j + compsize[i]] = add(dp[i + 1][j + compsize[i]], dp[i][j]);
            }
        }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = add(ans, mul(dp[m][i], A(n, i)));
    cout << ans << endl;
}
```
[1697F - Too Many Constraints](../problems/F._Too_Many_Constraints.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1697F - Too Many Constraints](../problems/F._Too_Many_Constraints.md "Educational Codeforces Round 130 (Rated for Div. 2)")

Imagine there were no constraints of the second or the third types. Then it would be possible to solve the problem with some greedy algorithm. Unfortunately, when both these constraints are present, it's not immediately clear how to adapt the greedy.

Dynamic programming is probably also out of question, because you can't maintain all possible cuts between equal values on each prefix.

Thus, let's try to make a graph problem out of this. Who knows, maybe a flow or something else could work.

Create $k$ nodes for each position. Let the $x$-th of them on the $i$-th position represent the condition of kind "is $a_i$ equal to $x$?". Then all constraints can be described as edges on this graph. Binary variables, restrictive edges. Surely, this is 2-SAT.

Connect the pairs of values that satisfy each constraint. Add the edges between the adjacent positions to enforce the restriction on the non-decreasing order. Prohibit each position to be assigned to multiple values. Force each position to be assigned at least one value. Huh, it's not that easy. That's where the 2-SAT idea fails. We want the conditions of form $(a_i = 1 \vee a_i = 2 \vee \dots \vee a_i = k)$. But that is not allowed, since 2-SAT has to have two variables in a clause.

That's where the main idea of the problem comes up. Instead of making our nodes $(i, x)$ represent $a_i = x$, let's make them $a_i \ge x$ and try building the graph again.

If $a_i = x$, then all nodes $(i, y)$ for $y \le x$ will be true, and the rest will be false. So if $(i, x)$ is false, then $(i, x + 1)$ is false. That will enforce the validity of the nodes themselves.

First, the order. If $(i, x)$ is true, then $(i + 1, x)$ is true.

The first type of constraints. $a_i \neq x$ is basically the same as ($a_i < x$ or $a_i > x$). For our conditions, it's rather ((not $a_i \ge x$) or $a_i \ge x + 1$).

The second type of constraints. $a_i + a_j \le x$. Let $a_i$ be greater than or equal to some $y$. Then, for this constraint to hold, $a_j$ should be no greater than $x - y$. Thus, if $(a_i \ge y)$ is true, then $(a_j \ge x - y + 1)$ should be false. Same for $i$ and $j$ swapped.

The third type of constraints is similar. $a_i + a_j \ge x$. Let $a_i$ be less than or equal to some $y$. Then, for this constraint to hold, $a_j$ should be greater than or equal to $x - y$. Thus, if $(a_i \ge y + 1)$ is false, then $(a_j \ge x - y)$ should be true. Same for $i$ and $j$ swapped.

And that's it. Solve the 2-SAT and restore the answer. I can advise making not $k$ but actually $k + 2$ nodes for $a_i \ge 0, 1, \dots, k+1$ and force the values to be between $1$ and $k$. That will simplify the checks while adding the constraints.

Overall complexity: $O((n+m)k)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct constraint{
	int tp, i, j, x;
};

vector<vector<int>> g, tg;
vector<char> used;
vector<int> clr, ord;

void ts(int v){
	used[v] = true;
	for (int u : g[v]) if (!used[u])
		ts(u);
	ord.push_back(v);
}

void dfs(int v, int k){
	clr[v] = k;
	for (int u : tg[v]) if (clr[u] == -1)
		dfs(u, k);
}

void either(int x, int y){
	g[x ^ 1].push_back(y);
	g[y ^ 1].push_back(x);
	tg[y].push_back(x ^ 1);
	tg[x].push_back(y ^ 1);
}

void implies(int x, int y){
	either(x ^ 1, y);
}

void must(int x){
	either(x, x);
}

int main() {
	int t;
	scanf("%d", &t);
	forn(_, t){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<constraint> c(m);
		forn(i, m){
			scanf("%d%d", &c[i].tp, &c[i].i);
			if (c[i].tp != 1) scanf("%d", &c[i].j);
			scanf("%d", &c[i].x);
			--c[i].i, --c[i].j;
		}
		int vts = n * (k + 2);
		g.assign(2 * vts, vector<int>());
		tg.assign(2 * vts, vector<int>());
		forn(i, n){
			forn(j, (k + 2) - 1)
				implies(2 * (i * (k + 2) + j + 1) + 1, 2 * (i * (k + 2) + j) + 1);
			must(2 * (i * (k + 2) + 1) + 1);
			must(2 * (i * (k + 2) + k + 1));
		}
		forn(i, n - 1) forn(j, k + 2){
			implies(2 * (i * (k + 2) + j) + 1, 2 * ((i + 1) * (k + 2) + j) + 1);
		}
		forn(i, m){
			if (c[i].tp == 1)
				either(2 * (c[i].i * (k + 2) + c[i].x + 1) + 1, 2 * (c[i].i * (k + 2) + c[i].x));
			else if (c[i].tp == 2){
				for (int a = max(1, c[i].x - k); a <= min(k, c[i].x - 1); ++a){
					implies(2 * (c[i].i * (k + 2) + a) + 1, 2 * (c[i].j * (k + 2) + (c[i].x - a) + 1));
					implies(2 * (c[i].j * (k + 2) + a) + 1, 2 * (c[i].i * (k + 2) + (c[i].x - a) + 1));
				}
			}
			else{
				for (int a = max(1, c[i].x - k); a <= min(k, c[i].x - 1); ++a){
					implies(2 * (c[i].i * (k + 2) + a + 1), 2 * (c[i].j * (k + 2) + (c[i].x - a)) + 1);
					implies(2 * (c[i].j * (k + 2) + a + 1), 2 * (c[i].i * (k + 2) + (c[i].x - a)) + 1);
				}
			}
		}
		used.assign(2 * vts, 0);
		ord.clear();
		forn(i, used.size()) if (!used[i]) ts(i);
		reverse(ord.begin(), ord.end());
		clr.assign(2 * vts, -1);
		int cc = 0;
		for (int v : ord) if (clr[v] == -1){
			dfs(v, cc);
			++cc;
		}
		vector<int> vals(vts);
		bool ans = true;
		forn(i, vts){
			if (clr[2 * i] == clr[2 * i + 1]){
				ans = false;
				break;
			}
			vals[i] = (clr[2 * i] < clr[2 * i + 1]);
		}
		if (!ans){
			puts("-1");
			continue;
		}
		forn(i, n){
			int lst = 0;
			forn(j, k + 2) if (vals[i * (k + 2) + j])
				lst = j;
			printf("%d ", lst);
		}
		puts("");
	}
	return 0;
}

```
