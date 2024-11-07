# Tutorial

[1739A - Immobile Knight](../problems/A._Immobile_Knight.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1739A - Immobile Knight](../problems/A._Immobile_Knight.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Let's consider some cases.

If at least one of $n$ or $m$ are $1$, then all cells are isolated. A knight can't move one in a perpendicular direction.

If at least one of $n$ or $m$ are at least $4$, then the knight always has at least one move. No matter where you place it, it can move two cells along the greater of the dimensions and move one in a perpendicular direction, because it's at least $2$.

Three cases are left. $(2, 2)$, $(2, 3)$ and $(3, 3)$. For all of these cases, the middle cell is isolated. That cell is $(\lfloor \frac n 2 \rfloor + 1, \lfloor \frac m 2 \rfloor + 1)$.

Since it doesn't matter which cell you print in the first two cases, you can always print $(\lfloor \frac n 2 \rfloor + 1, \lfloor \frac m 2 \rfloor + 1)$.

Overall complexity: $O(1)$ per testcase.

Alternatively, you can check every possible cell. Iterate over a cell and check all eight possible knight moves from it. If none are inside the board, the cell is isolated.

Overall complexity: $O(nm)$ per testcase.

 **Solution 1 (awoo)**
```cpp
for _ in range(int(input())):
	n, m = map(int, input().split())
	print(n // 2 + 1, m // 2 + 1)
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	forn(_, t){
		int n, m;
		scanf("%d%d", &n, &m);
		int svx = 1, svy = 1;
		for (int x = 1; x <= n; ++x){
			for (int y = 1; y <= m; ++y){
				bool ok = true;
				for (int dx : {-2, -1, 1, 2}){
					for (int dy : {-2, -1, 1, 2}){
						if (abs(dx * dy) != 2) continue;
						if (1 <= x + dx && x + dx <= n && 1 <= y + dy && y + dy <= m)
							ok = false;
					}
				}
				if (ok){
					svx = x;
					svy = y;
				}
			}
		}
		printf("%d %dn", svx, svy);
	}
}
```
[1739B - Array Recovery](../problems/B._Array_Recovery.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1739B - Array Recovery](../problems/B._Array_Recovery.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Note that $a_i = a_{i-1} + d_i$ or $a_i= a_{i-1} - d_i$. Since there is no upper bound for the values of $a_i$, the case where $a_i = a_{i-1} + d_i$ for all $i$ always exists. It remains to check if there are other ways. To do this, it is enough to check whether there is such a position $pos$ that: 

* $pos > 1$;
* $d_{pos} \ne 0$;
* the change $a_{pos} = a_{pos-1} + d_{pos}$ to $a_{pos} = a_{pos-1} - d_{pos}$ doesn't result in a negative value of $a_{pos}$.

The reason for $d_{pos} \ne 0$ is that for $d_{pos} = 0$ no matter the plus or minus we choose, the array $a$ doesn't change. If you could change at least one sign to minus, that would be another answer.

 **Solution (Neon)**
```cpp
for _ in range(int(input())):
	n = int(input())
	ans = [0]
	for x in map(int, input().split()):
		if x != 0 and ans[-1] - x >= 0:
			print(-1)
			break
		else:
			ans.append(ans[-1] + x)
	else:
		print(*ans[1:])
```
[1739C - Card Game](../problems/C._Card_Game.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1739C - Card Game](../problems/C._Card_Game.md "Educational Codeforces Round 136 (Rated for Div. 2)")

The example tests suggest that there is only one possible distribution with a draw. Let's find out why it is so. We will use a process similar to induction/recursion to distribute the cards between the two players so that the game ends in a draw:

* suppose Alex receives the card $n$. Then he wins since he can play it immediately. So, for the game to result in a draw, Boris must receive the card $n$.
* suppose Boris receives the card $n-1$. Then he wins since he also has the card $n$, he can use it to answer any first move of Alex, and then win the game by playing $n-1$. So, for the game to result in a draw, Alex must receive the card $n-1$.
* suppose Boris receives the card $n-2$. Then he wins since he also has the card $n$: if Alex plays the card $n-1$, Boris responds with $n$ and then plays $n-2$; if Alex plays some other card, Boris responds with $n-2$ and the plays $n$. So, for the game to result in a draw, Alex must receive the card $n-2$.
* and so on.

In fact, if Alex receives the card $n-1$ and Boris receives the card $n$, Alex must play the card $n-1$ or something equivalent to it on the first move, and Boris must respond with the card $n$, so we can consider the game without these two cards with the roles swapped.

So, if we consider the distribution of cards as a string with characters A and B, where A denotes the card belonging to Alex, and B denotes the card belonging to Boris, and the $i$-th character of the string represents the card $n-i+1$, the only possible distribution for the draw is BAABBAAB... But there's more to this string representation of the distribution of cards: the first character that is different from this pattern denotes the winner; if the first different character is A in the draw distribution and B in the distribution we consider, the winner is Boris; otherwise, the winner is Alex.

This may lead us to the following ways to count the number of possible distributions which win/lose for Alex:

* we can use dynamic programming of the form $dp_{x,y,t}$, where $x$ is the number of characters A we used, $y$ is the number of characters B we used, and $t$ is $0$, $1$ or $2$ depending on whether our string coincides with the draw string ($t = 0$), differs from it in a way that Alex wins ($t = 1$), or differs from it in a way that Boris wins ($t = 2$); the actual value of $dp_{x,y,t}$ must be the number of ways to reach this state of dynamic programming. The answer then is stored in the states of the form $dp_{\frac{n}{2},\frac{n}{2},t}$.
* or we can use combinatorics: let's iterate on the length of the prefix that is common in the draw string and in the string representing the distribution of cards, and then count the number of ways to distribute the remaining characters with a binomial coefficient. To calculate the binomial coefficients, we can use one of the following methods: Pascal's triangle, precalculating factorials and modular inverses to then, or calculating factorials with big integers in Java or Python.
 **Solution 1 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

long long dp[65][65][3];

void solve(int n)
{
    memset(dp, 0, sizeof dp);
    int k = n / 2;
    dp[0][0][2] = 1;
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= k; j++)
            for(int t = 0; t <= 2; t++)
            {
                int turn = (i + j) % 4;
                if (turn == 0 || turn == 3)
                {
                    if(i < k) dp[i + 1][j][t == 2 ? 0 : t] += dp[i][j][t];
                    if(j < k) dp[i][j + 1][t] += dp[i][j][t];
                }
                else
                {
                    if(i < k) dp[i + 1][j][t] += dp[i][j][t];
                    if(j < k) dp[i][j + 1][t == 2 ? 1 : t] += dp[i][j][t];
                }
            }
    for(int i = 0; i < 3; i++)
        cout << dp[k][k][i] % 998244353 << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        solve(n);
    }
}
```
 **Solution 2 (BledDest)**
```cpp
def fact(n):
    return 1 if n == 0 else n * fact(n - 1)

def choose(n, k):
    return fact(n) // fact(k) // fact(n - k)

def calc(n):
    if n == 2:
        return [1, 0, 1]
    else:
        a = calc(n - 2)
        return [choose(n - 1, n // 2) + a[1], choose(n - 2, n // 2) + a[0], 1]

t = int(input())
for i in range(t):
    mod = 998244353
    n = int(input())
    a = calc(n)
    a = list(map(lambda x: x % mod, a))
    print(*a)
```
[1739D - Reset K Edges](../problems/D._Reset_K_Edges.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1739D - Reset K Edges](../problems/D._Reset_K_Edges.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Start with the following. Let's look at the input format and consider what the operation actually does to it. Since it only changes the parent of some vertex, it modifies only one value in it. Moreover, it just assigns it to $1$. Thus, the goal is to assign at most $k$ values of parents to $1$ to minimize the resulting height of the tree.

In particular, that implies that we can freely rearrange the operations, since the assignments don't depend on each other.

One more conclusion. Imagine we have already built some answer. One by one, we moved some subtrees to be children of the root. It could happen that we first moved some subtree of a vertex $u$ and then applied the operation to an edge inside the subtree of $u$. Let's show that it's always possible to rearrange the operations in the answer to avoid that. Just apply the operations in order of decreasing the depth of the vertex $u$.

If we knew what height $h$ we want to get, we could have been making sure that cut subtree $u$ has height at most $h-1$ (since it gets increased by $1$ when glueing it to the root), then pretending that that subtree doesn't exist anymore.

Moreover, it's always required to cut subtrees with height at most $h-1$. If you cut a higher subtree, then the answer can't be smaller than $h+1$, since we rearranged the operation to not touch that subtree anymore.

Well, let's fix that height $h$ if we wanted that. Let's try the solve the opposite problem. How many operations will it require to make the tree height at most $h$? Obviously, the values for this problem are non-increasing — the greater we allow the height to be, the less operations it will require. Thus, we will be able to apply binary search to it to find the smallest height we can achieve with at most $k$ operations.

Now we want to be choosing the subtrees of height at most $h-1$ repeatedly and cutting them off until the height of the tree becomes at most $h$.

Let's think greedily. If the height of the tree is not at most $h$ yet, then there exists a vertex with the depth greater than $h$. Let's look at the deepest of them. That leaf has to be cut in some subtree. Otherwise, the tree won't become any less higher. What subtree is the best for it? What options do we have? That vertex itself and all its parents up until $h-1$ above. It's always optimal to cut the highest of them — the $(h-1)$-st parent, since it will remove at least all the vertices of any other cut and some other vertices along with them. It's also always possible to remove the $(h-1)$-st parent, since it will always have height exactly $h-1$. The vertex we are looking at is the deepest in the entire tree — there are no deeper vertices in the subtree of the $(h-1)$-st parent.

Thus, the strategy is to keep cutting the $(h-1)$-st parent of the deepest vertex until the tree becomes at most $h$ height.

Now about the implementation details.

First, we can process the vertices from the deepest upwards in their order in the original tree. The operation only removes some vertices but doesn't change the depth of the remaining ones. For example, you can do a bfs from the root to find the order.

Now the $(h-1)$-st parent. Let's find it for each vertex before starting the process. Run a dfs and maintain the stack of the ascendants. When going down the child, append it to the stack. What exiting, pop from the stack. Now you can just look at the $(h-1)$-st element from the top of the stack. To be able to do that, simulate the stack with a vector (C++) or a list (Python).

Finally, we would have to determine if the current vertex in the order is removed or not. For that, we could maintain a boolean array $\mathit{used}$ for the removed vertices. Once you apply the operation, run the dfs from the removed vertex and mark all the newly removed descendants of it in $\mathit{used}$. If you don't go into already marked vertices, there will be no more than $n$ calls of the dfs.

The number of cut vertices is the answer for the fixed height $h$.

Overall complexity: $O(n \log n)$ per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
vector<vector<int>> g;

vector<int> st;
vector<int> pd;

void init(int v, int d){
	st.push_back(v);
	if (int(st.size()) - d >= 0)
		pd[v] = st[st.size() - d];
	for (int u : g[v])
		init(u, d);
	st.pop_back();
}

vector<char> used;

void dfs(int v){
	used[v] = true;
	for (int u : g[v]) if (!used[u])
		dfs(u);
}

int get(int d){
	pd.assign(n, -1);
	init(0, d);
	
	vector<int> ord, h(n);
	queue<int> q;
	q.push(0);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		ord.push_back(v);
		for (int u : g[v]){
			q.push(u);
			h[u] = h[v] + 1;
		}
	}
	reverse(ord.begin(), ord.end());
	
	used.assign(n, 0);
	int res = 0;
	for (int v : ord) if (!used[v] && h[v] > d){
		++res;
		dfs(pd[v]);
	}
	
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int k;
		scanf("%d%d", &n, &k);
		g.assign(n, vector<int>());
		for (int i = 1; i < n; ++i){
			int p;
			scanf("%d", &p);
			--p;
			g[p].push_back(i);
		}
		int l = 1, r = n - 1;
		int ans = n;
		while (l <= r){
			int m = (l + r) / 2;
			if (get(m) <= k){
				ans = m;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		printf("%dn", ans);
	}
	return 0;
}
```
[1739E - Cleaning Robot](../problems/E._Cleaning_Robot.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1739E - Cleaning Robot](../problems/E._Cleaning_Robot.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Why did the author choose the width of the hallway to be only $2$? Well, in that case you can show that the robot will never move to the left while cleaning. That is not true on width $3$ already.

When does the robot break? Let the robot currently be in the cell $(j, i)$ ($0$-indexed) and the next column with a dirty cell be $\mathit{nxt}_i$ (possibly, $\mathit{nxt}_i = i$). The robot breaks only if both $(1 - j, \mathit{nxt}_i)$ and $(j, \mathit{nxt}_i)$ are dirty.

That helps us to do a dynamic programming solution. Since we can only care about $O(1)$ next columns, we would want to have some $dp[i][j]$ — the largest number of dirty cells we can leave to the robot if we processed the first $i$ columns of the hallway and are currently standing in the $j$-th row of the $i$-th column. Maybe with some additional states of the current or the next columns.

We want the dp to maintain the invariant that everything to the left of the $i$-th column is cleaned in such a way the robot can reach the cell $(j, i)$. We can choose when to fix the $i$-th column: either maintain it being correct prior to entering the state or handling it in the transition to the next one. I chose the former option. There probably exists a million different dps that work, I'll describe the one I did.

Let $dp[i][j][f]$ be the largest number of dirty cells that we can leave to the robot if: 

* we fixed which of the dirty cells in the first $i$ columns, inclusive, are cleaned by hand;
* the robot reaches the cell $(j, i)$ from the left;
* $f$ is true if the cell in the opposite row of the $i$-th column is dirty.

The transitions handle what to do with the dirty cells in the $(i+1)$-st column and where the robot goes based on that.

In particular, there are the following transitions: 

* if $f$ is true, then we have to clean the cell $(j, i + 1)$, and the robot will move into $(1 - j, i + 1)$ — otherwise the robot breaks from having two options;
* if $f$ is false, then let's say that the robot doesn't break immediately but moves into the next column in a unique way: it moves horizontally first, then possibly vertically;
	+ we can leave the next column as is, and the robot will move into $(j, i + 1)$ if the cell $(1 - j, i + 1)$ is clean, or $(1 - j, i + 1)$ if it's dirty;
	+ if $f$ is false, then we can clean the cell $(1 - j, i + 1)$, and the robot will move into $(j, i + 1)$.

Since we maintained the invariant that the $i$-th column is valid, we can update the answer from all four states in the last column.

Overall complexity: $O(n)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int INF = 1e9;

int main(){
	int n;
	cin >> n;
	vector<string> s(2);
	forn(i, 2) cin >> s[i];
	vector<array<array<int, 2>, 2>> dp(n + 1);
	forn(i, n + 1) forn(j, 2) forn(k, 2) dp[i][j][k] = -INF;
	dp[0][0][s[1][0] == '1'] = s[1][0] == '1';
	dp[0][0][0] = 0;
	forn(i, n - 1) forn(j, 2){
		int nxtj = s[j][i + 1] == '1';
		int nxtj1 = s[j ^ 1][i + 1] == '1';
		dp[i + 1][j ^ 1][0] = max(dp[i + 1][j ^ 1][0], dp[i][j][1] + nxtj1);
		dp[i + 1][j][nxtj1] = max(dp[i + 1][j][nxtj1], dp[i][j][0] + nxtj1 + nxtj);
		dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + nxtj);
	}
	cout << max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][1][0], dp[n - 1][1][1]}) << 'n';
}
```
[1739F - Keyboard Design](../problems/F._Keyboard_Design.md "Educational Codeforces Round 136 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1739F - Keyboard Design](../problems/F._Keyboard_Design.md "Educational Codeforces Round 136 (Rated for Div. 2)")

For each word, let's consider a graph on $12$ vertices where the $i$-th and the $j$-th vertices are connected by an edge iff the $i$-th character of the alphabet is adjacent to the $j$-th character of the alphabet in this string. Obviously, this graph is connected (except for the isolated vertices). If there is a vertex of degree $3$ or more in this graph, or if there is a cycle in this graph, it is impossible to design a keyboard to type the word easily: in the first case, the letter represented by that vertex must have at least three neighbors on the keyboard, but can have only at most two; in the second case, the keyboard must be cyclic (and it is not). So, the word can be typed easily only if the graph representing it consists of one path and several isolated vertices.

Let's write the letters along the path we constructed for the word in a single string. For example, for the word abacabacd, we get edges ab, ac and cd in the graph, so the letters along the path are either dcab or bacd (and, obviously, one can be obtained from the other by reversing the string). Let $f(s)$ and $f'(s)$ be the two strings we obtain from the word $s$ using this method. Now, we claim that the word $s$ can be typed easily if and only if one of these two strings ($f(s)$ and $f'(s)$) is a substring of the keyboard — this would mean that every pair of letters that should be on adjacent positions are actually on adjacent positions.

Okay, now we construct $f(s_i)$ and $f'(s_i)$ for each word, and our goal is to find the permutation of the first $12$ characters of Latin alphabet such that the sum of $c_i$ over all words having either $f(s_i)$ or $f'(s_i)$ as a substring is the maximum possible. There are two key observations that allow us to solve this problem:

* $f(s_i)$ and $f'(s_i)$ cannot be the substrings of the same keyboard (the proof is simple: if $f(s_i)$ is a substring, its first character must be before its second character; and if $f'(s_i)$ is a substring, its second-to-last character (which is the second character of $f(s_i)$) must be before its last character (which is the first character of $f(s_i)$);
* neither $f(s_i)$ nor $f'(s_i)$ can appear in the keyboard twice (it's obvious since the keyboard is a permutation).

So, we can reformulate the problem as follows: let $c_i$ be the cost of the string $f(s_i)$ and the cost of the string $f'(s_i)$ as well; find the permutation of the first $12$ characters of the Latin alphabet so that its cost (which is the sum of costs of its substrings) is the maximum possible. To solve this problem, we can store the strings in an Aho-Corasick automaton, and for every state of the automaton, precalculate the total cost of all string ending in this state (that is, the cost of this state and all states reachable from it via the suffix links). Then run a dynamic programming of the form $dp_{mask,v}$ — the maximum possible cost of a partial keyboard if we used a $mask$ of characters and the Aho-Corasick automaton is currently in the state $v$. This dynamic programming runs in $O(2^K \cdot K \cdot A)$, where $K$ is the size of the alphabet ($12$), and $A$ is the size of the automaton (up to $4000$).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 10043;
const int K = 12;

int tsz = 0;
int trie[N][K];
int aut[N][K];
int lnk[N];
int p[N];
int pchar[N];
int cost[N];
int ncost[N];

int newNode()
{
    lnk[tsz] = -1;
    ncost[tsz] = -1;
    cost[tsz] = 0;
    for(int i = 0; i < K; i++)
    {
        trie[tsz][i] = aut[tsz][i] = -1;
    }
    return tsz++;
}

int nxt(int x, int y)
{                                 
    if(trie[x][y] == -1) 
    {
        trie[x][y] = newNode();
        pchar[trie[x][y]] = y;
        p[trie[x][y]] = x;
    }
    return trie[x][y];
}

int go(int x, int y);

int get_lnk(int x)
{
    if(lnk[x] != -1) return lnk[x];
    int& d = lnk[x];
    if(x == 0 || p[x] == 0) return d = 0;
    return d = go(get_lnk(p[x]), pchar[x]);    
}

int go(int x, int y)
{
    if(aut[x][y] != -1) return aut[x][y];
    int& d = aut[x][y];
    if(trie[x][y] != -1) return d = trie[x][y];
    if(x == 0) return d = 0;
    return d = go(get_lnk(x), y);
}

void add(string s, int c)
{
    int cur = 0;
    for(auto x : s) cur = nxt(cur, x - 'a');
    cost[cur] += c;     
} 

int calc(int x)
{
    if(ncost[x] != -1) return ncost[x];
    ncost[x] = cost[x];
    int y = get_lnk(x);
    if(y != x) ncost[x] += calc(y);
    return ncost[x];
}

int main()
{
    int root = newNode();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> x >> s;
        map<char, set<char>> adj;
        for(int j = 0; j + 1 < s.size(); j++)
        {
            adj[s[j]].insert(s[j + 1]);
            adj[s[j + 1]].insert(s[j]);
        }
        bool bad = false;
        string res = "";
        char c;
        for(c = 'a'; c <= 'l'; c++)
        {
            if(!adj.count(c)) continue;
            if(adj[c].size() >= 3)
                bad = true;
            if(adj[c].size() == 1)
                break;
        }
        if(c == 'm' || bad) continue;
        res.push_back(c);
        while(adj[c].size() > 0)
        {
            char d = *adj[c].begin();
            adj[c].erase(d);
            adj[d].erase(c);
            c = d;
            res.push_back(c);  
        }
        bad |= adj.size() != res.size();
        map<char, int> pos;
        for(int i = 0; i < res.size(); i++)
            pos[res[i]] = i;
        for(int i = 0; i + 1 < s.size(); i++)
            bad |= abs(pos[s[i]] - pos[s[i + 1]]) > 1;
        if(bad) continue;
        add(res, x);
        reverse(res.begin(), res.end());
        add(res, x);
    }  
    int INF = 1e9;
    int K = 12;
    vector<vector<int>> dp(1 << K, vector<int>(tsz + 1, -INF));
    vector<vector<pair<int, int>>> pdp(1 << K, vector<pair<int, int>>(tsz + 1));
    dp[0][0] = 0;
    for(int i = 0; i < (1 << K); i++)
        for(int j = 0; j <= tsz; j++)
        {
            for(int z = 0; z < K; z++)
            {
                if(i & (1 << z)) continue;
                int nstate = go(j, z);
                int add = calc(nstate);
                int nmask = i | (1 << z);
                if(dp[nmask][nstate] < dp[i][j] + add)
                {
                    dp[nmask][nstate] = dp[i][j] + add;
                    pdp[nmask][nstate] = {z, j};
                }
            }
        }
    string ans = "";
    int curmask = (1 << K) - 1;
    int curstate = max_element(dp[curmask].begin(), dp[curmask].end()) - dp[curmask].begin();
    while(curmask != 0)
    {
        int cc = pdp[curmask][curstate].first;
        int ns = pdp[curmask][curstate].second;
        ans.push_back(char('a' + cc));
        curmask ^= (1 << cc);
        curstate = ns;
    }
    cout << ans << endl;
}
```
