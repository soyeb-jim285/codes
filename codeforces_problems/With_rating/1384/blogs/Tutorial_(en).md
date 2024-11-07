# Tutorial_(en)

We (the setters) hope you liked the problems. Here is the editorial:

 Tutorial is loading... **C++ solution**
```cpp
#include <iostream>

#define endl 'n'

using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s(200, 'a');
    cout << s << endl;

    for (int i = 0; i < n; ++i)
    {
        int u;
        cin >> u;
        s[u] = s[u] == 'a' ? 'b' : 'a';
        cout << s << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}
```
 **Python solution**
```cpp
import sys
input = sys.stdin.readline

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
    
        mx = max(a)
        ans = [ 'a' * (mx + 1) ] * (n + 1)
    
        for i, x in enumerate(a):
            who = 'a' if ans[i][x] == 'b' else 'b'
            ans[i + 1] = ans[i][:x] + who + ans[i][x + 1:]
    
        print('n'.join(ans))    

main()
```
Problem idea: [dcordb](https://codeforces.com/profile/dcordb "Expert dcordb")

Solution idea: [dcordb](https://codeforces.com/profile/dcordb "Expert dcordb") and [Devil](https://codeforces.com/profile/Devil "Master Devil")

 Tutorial is loading... **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		int n, k, l;
		cin >> n >> k >> l;
		vector<int> d(n+2, -k);
		for (int i = 1; i <= n; ++i)
			cin >> d[i];

		set<tuple<int, int, bool>> mark;
		function<bool(int, int, bool)> go = [&](int pos, int tide, bool down)
		{
			if (pos > n) return true;
			
			if (mark.find({ pos, tide, down }) != mark.end())
				return false;

			mark.insert({ pos, tide, down });

			tide += down ? -1 : +1;
			if (tide == 0) down = false;
			if (tide == k) down = true;

			if (d[pos] + tide <= l && go(pos, tide, down))
				return true;
			if (d[pos + 1] + tide <= l && go(pos + 1, tide, down))
				return true;
			return false;
		};

		if (go(0, 0, false)) cout << "Yesn";
		else cout << "Non";
	}

	return 0;
}
```
Problem idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

Solution idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

 Tutorial is loading... **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		int n, k, l;
		cin >> n >> k >> l;
		vector<int> d(n+1), safe = { 0 };
		for (int i = 1; i <= n; ++i)
		{
			cin >> d[i];
			if (d[i] + k <= l)
				safe.push_back(i);
		}

		safe.push_back(n+1);
		bool ok = true;
		for (size_t i = 1; i < safe.size() && ok; ++i)
		{
			int tide = k; bool down = true;
			for (int j = safe[i-1] + 1; j < safe[i]; ++j)
			{
				tide += down ? -1 : +1;

				if (down) tide -= max(0, d[j] + tide - l);
				if (tide < 0 || d[j] + tide > l) { ok = false; break; }

				if (tide == 0) down = false;
			}
		}

		if (ok) cout << "Yesn";
		else cout << "Non";
	}

	return 0;
}
```
Problem idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

Solution idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

 
### [1383A - String Transformation 1](https://codeforces.com/contest/1383/problem/A "Codeforces Round 659 (Div. 1)")

First of all, if there exists some $i$ such that $A_i > B_i$ there isn't a solution.

Otherwise, create a graph where every character is a node, and put a directed edge between node $u$ and node $v$ if character $u$ must be transformed into character $v$ (ie. from $A_i$ to $B_i$ for all $i$). We must select a list with minimum number of operations such that if there is an edge from node $u$ to node $v$, then it must exist a subsequence of the operations in the list that transforms $u$ into $v$.

Each weakly connected component $C$ can be solved independently and the answer for each component is $|C| - 1$. So total answer is $|ALP| - k$ where $k$ is the number of weakly connected components in the graph.

Proof:

Each weakly connected component $C$ requires at least $|C| - 1$ operations (because they are connected). Since there are no cycles in the graph a topological order exists. Find one and select each pair of consecutive nodes in this order as the list of operations.

Time complexity: $O(|A| + |B| + |ALP|)$ per test case where $|ALP| = 20$ denotes size of alphabet

 **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int Alp = 20;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
	    int n;
		string a, b;
		cin >> n >> a >> b;

		bool bad = false;
		vector<vector<int>> adj(Alp);
		for (int i = 0; i < n; ++i)
			if (a[i] != b[i])
			{
				if (a[i] > b[i])
				{
					bad = true;
					cout << "-1n";
					break;
				}

				adj[a[i]-'a'].push_back(b[i]-'a');
				adj[b[i]-'a'].push_back(a[i]-'a');
			}

		if (bad) continue;

		vector<bool> mark(Alp);
		function<void(int)> dfs = [&](int u)
		{
			mark[u] = true;
			for (auto v : adj[u])
				if (!mark[v])
					dfs(v);
		};

		int ans = Alp;
		for (int i = 0; i < Alp; ++i)
			if (!mark[i])
				dfs(i), --ans;
		cout << ans << "n";
	}

	return 0;
}

```
Problem idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

Solution idea: [mnaeraxr](https://codeforces.com/profile/mnaeraxr "Grandmaster mnaeraxr") and [Devil](https://codeforces.com/profile/Devil "Master Devil")

 
### [1383B - GameGame](https://codeforces.com/contest/1383/problem/B "Codeforces Round 659 (Div. 1)")

Let $x$ be the number of ones and $y$ be the numbers of zeros in the most significant bit of the numbers:

* if $x$ is even, whatever decision players take, both will end with the same score in that bit, so go to the next bit (if it doesn't exist the game ends in a draw). Indeed, the parity of the result of both players will be the same, since $x$ is even.
* if $x$ is odd, one of the players ends with $0$ in this bit and the other with $1$, the player with $1$ in this bit wins the game because the well know inequality $2^k > \sum\limits_{i=0}^{k-1} 2^i$ for $k \ge 1$, so the game is equivalent to play on an array of $x$ ones and $y$ zeros. Lemma: The second player wins iff $x \bmod 4 = 3$ and $y \bmod 2 = 0$ otherwise the first player wins.

 Proof: We know that $x \bmod 2 = 1$ so $x \bmod 4$ can be $1$ or $3$ 


	+ if $x \bmod 4 = 1$ the first player can choose one $1$ and the remaining number of $1$ is a multiple of $4$, if the first player always repeats the last move of the second player (if $y \bmod 2 = 1$ and the second player takes the last $0$ both players start taking all the remaining ones), then both ends with the same number of ones which divided by $2$ is even and therefore the first player wins.
	+ if $x \bmod 4 = 3$
		- if $y \bmod 2 = 0$ the second player can repeat the last move of the first player always so the first ends with a even numbers of $1$ and therefore the second player wins.
		- if $y \bmod 2 = 1$ the first player takes one $0$ and the game now is exactly the previous case with the first player as the second player.

Time complexity: $O(n)$ per testcase

 **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		
		int x = 0;
		vector<int> a(n);
		for (auto &i : a)
		{
			cin >> i;
			x ^= i;
		}

		if (x == 0)
		{
			cout << "DRAWn";
			continue;
		}

		for (int k = 30; k >= 0; --k)
			if (x >> k & 1)
			{
				vector<int> f(2);
				for (auto &i : a) ++f[i >> k & 1];
				if (f[1] % 4 == 3 && f[0] % 2 == 0)
					cout << "LOSEn";
				else
					cout << "WINn";
				break;
			}
	}

	return 0;
}
```
 **Python solution**
```cpp
import sys
input = sys.stdin.readline

d = { 1: 'WIN', 0: 'LOSE', -1: 'DRAW' }

def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        a = map(int, input().split())

        f = [0] * 30

        for x in a:
            for b in range(30):
                if x >> b & 1:
                    f[b] += 1

        ans = -1
        for x in reversed(range(30)):
            if f[x] % 2 == 1:
                ans = 0 if f[x] % 4 == 3 and (n - f[x]) % 2 == 0 else 1
                break

        print(d[ans])

main()
```
Problem idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

Solution idea: [Devil](https://codeforces.com/profile/Devil "Master Devil") and [dcordb](https://codeforces.com/profile/dcordb "Expert dcordb")

 Tutorial is loading... **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int Alp = 20;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
	    int len;
		string a, b;
		cin >> len >> a >> b;
		
		vector<int> adj(Alp);
		vector<vector<int>> G(Alp);
		for (int i = 0; i < len; ++i)
			if (a[i] != b[i])
			{
				adj[a[i]-'a'] |= 1 << (b[i]-'a');
				G[a[i]-'a'].push_back(b[i]-'a');
				G[b[i]-'a'].push_back(a[i]-'a');
			}

		vector<bool> mark(Alp);
		function<void(int)> dfs = [&](int u)
		{
			mark[u] = true;
			for (auto v : G[u])
				if (!mark[v])
					dfs(v);
		};

		int comp = 0;
		for (int i = 0; i < Alp; ++i)
			if (!mark[i])
				dfs(i), ++comp;

		int ans = 0;
		vector<bool> dp(1<<Alp);
		dp[0] = true;
		for (int mask = 0; mask < 1<<Alp; ++mask)
			if (dp[mask])
			{
				ans = max(ans, __builtin_popcount(mask));
				for (int u = 0; u < Alp; ++u)
					if ((~mask >> u & 1) && (adj[u] & mask) == 0)
						dp[mask | 1 << u] = true;
			}

		cout << 2*Alp - comp - ans << "n";
	}

	return 0;
}
```
Problem idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

Solution idea: [mnaeraxr](https://codeforces.com/profile/mnaeraxr "Grandmaster mnaeraxr")

 
### [1383D - Rearrange](https://codeforces.com/contest/1383/problem/D "Codeforces Round 659 (Div. 1)")

Let $A$ be a matrix of size $n \cdot m$ that is formed by a permutation of elements from $1$ to $n \cdot m$. Find the maximum element on each row and column (i.e. the spectrum)

Now we are going to build the answer adding numbers one by one in decreasing order. We start with an empty 2 dimensional matrix (both dimensions have length 0) and at the end of each iteration the following invariants will be maintained on the matrix:

1. All elements processed are inside of the matrix.
2. Each row and column is bitonic.
3. The horizontal/vertical spectrum of this matrix is a subset of the expected horizontal/vertical spectrum.

In addition we are keeping a queue with all positions in the matrix that doesn't contain any element yet. At the end of each iteration the following invariants will be maintained on the queue:

* Let $A$ be a position on the queue and $B$ a position that contains a value that belongs to the horizontal spectrum in the matrix such that $A$ and $B$ are in the same row, then all positions between $A$ and $B$ have already an element in the matrix or occur in the queue before $A$.
* Let $A$ be a position on the queue and $B$ a position that contains a value that belongs to the vertical spectrum in the matrix such that $A$ and $B$ are in the same column, then all positions between $A$ and $B$ have already an element in the matrix or occur in the queue before $A$.


```cpp
  
M := int[0][0]  
Queue := new Queue()  
// sides of the matrix  
x, y = 0, 0   
  
for num in n * m .. 1  
	if num belongs to the horizontal spectrum  
		// Add one row full of 0 in the bottom of the matrix  
		X += 1  
  
	if num belongs to the vertical spectrum  
		// Add one column full of 0 in the right of the matrix  
		Y += 1  
  
	if num belongs either to the horizontal or to the vertical spectrum:  
		// Put num in the bottom rightmost position of the matrix.  
		M[x][y] = num  
	else:  
		ax, ay = pop element from Queue  
		M[ax][ay] = num  
  
	if num belongs to the horizontal spectrum  
		// Add all positions in the last row (but the last one) to the Queue from right to left  
		for py in y - 1 .. 1  
			Queue.add(x, py)  
  
	if num belongs to the vertical spectrum:  
		// Add all positions in the last column (but the last one) to the Queue from bottom to top.  
		for px in X - 1 .. 1   
			Queue.add(px, y)  

```
In the end, invariants on the matrix guarantee that all elements are placed, each row and column consist in a bitonic sequence as required and the spectrums are equal to the expected spectrums.

Let's prove each invariant on the matrix is kept:

1. Clearly on each step a different element is placed on the matrix on an empty position, we should only show that the operation pop element from Queue doesn't fail with Queue empty. Say the current element is $t$, so the matrix is filled with elements larger than $t$. Now we know that in original matrix there were at least $n-x$ rows with maximums less than t and at least m-y columns with maximums less than $t$, so there could be at most $x \cdot y$ elements greater or equal than t but there are $x \cdot y+1$ already.
2. On each row and column the first element added is the maximum and then elements are added in each direction starting from it toward each edge, since elements are processed from largest to smallest then each row and column is bitonic.
3. The first element added on each row and column is the maximum, and we only add it if it is part of the expected spectrum.

Time complexity: $O(n \cdot m)$

 **C++ solution**
```cpp
#include <bits/stdc++.h>

#define endl 'n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    vector<int> h(n * m + 1);
    vector<int> v(n * m + 1);

    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        for (int j = 0; j < m; ++j)
            a = max(a, mat[i][j]);
        h[a] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        int a = 0;
        for (int j = 0; j < n; ++j)
            a = max(a, mat[j][i]);
        v[a] = 1;
    }

    vector<vector<int>> fin(n, vector<int>(m));
    queue<pair<int, int>> q;

    int x = -1, y = -1;

    for (int u = n * m; u >= 1; --u)
    {
        x += h[u];
        y += v[u];

        if (h[u] || v[u])
        {
            fin[x][y] = u;
        }
        else
        {
            int qx, qy;
            tie(qx, qy) = q.front();
            q.pop();
            fin[qx][qy] = u;
        }

        if (h[u])
            for (int i = y - 1; i >= 0; --i)
                q.push({x, i});

        if (v[u])
            for (int i = x - 1; i >= 0; --i)
                q.push({i, y});
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << fin[i][j] << " n"[j + 1 == m];

    return 0;
}
```
Problem idea: [gilcu3](https://codeforces.com/profile/gilcu3 "Master gilcu3")

Solution idea: [gilcu3](https://codeforces.com/profile/gilcu3 "Master gilcu3") and [mnaeraxr](https://codeforces.com/profile/mnaeraxr "Grandmaster mnaeraxr")

 Tutorial is loading... **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);

	string s; cin >> s;
	int n = s.length();
	vector<int> dist(n);
	for (int i = 0; i < n; ++i)
		if (s[i] == '0') dist[i] = (i ? dist[i-1] : 0) + 1;

	vector<int> dp(n + 2), nxt(n+2, n);
	auto get = [&](int i) { return nxt[i] < n ? dp[nxt[i]] : 0; };

	for (int i = n-1; i >= 0; --i)
	{
		dp[i] = ((dist[i] <= dist.back()) + get(0) + get(dist[i] + 1)) % mod;
		nxt[dist[i]] = i;
	}

	int ans = n;
	if (nxt[0] < n)
		ans = ((long long)get(0) * (nxt[0] + 1)) % mod;
	cout << ans << "n";

	return 0;
}
```
Problem idea: [Devil](https://codeforces.com/profile/Devil "Master Devil")

Solution idea: [Devil](https://codeforces.com/profile/Devil "Master Devil") and [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 
### [1383F - Special Edges](https://codeforces.com/contest/1383/problem/F "Codeforces Round 659 (Div. 1)")

Finding maximum flow from $1$ to $n$ is equivalent to find the minimum cut from $1$ to $n$. Let's use the later interpretation to solve the problem.

Suppose there is a single special edge ($k = 1$), on each query there are two options, either this edge belong to the minimum cut or it doesn't. If the edge doesn't belong to the minimum cut, the value of the cut won't change even if we increase the capacity of each edge arbitrarily (let's say to $\infty$). On the other hand, if the edge belong to the cut, then the value of the cut will be equal to the capacity of the edge + the value of the cut if the capacity of the edge was $0$. With this in mind we can compute each query in O(1).

Let $MC_0$ be the value of the minimum cut if the capacity of the special edge is 0, and $MC_{\infty}$ be the value of the minimum cut if the capacity of the special edge is $\infty$. Then for each query $c_i$ the minimum cut will be equal to $min(MC_{\infty}, MC_0 + c_i)$.

We can generalize this ideas to multiple edges in the following way. For each subset of special edges, they either belong to the minimum cut, or they don't. If we fix a subset $S$ and say those are among the special edges the only ones that belong to the minimum cut, then the value of the cut will be equal to the sum of the values of the capacities of these edges plus the minimum cut in the graph were each of these edges has capacity 0 and other special edges has capacity $\infty$. In a similar way as we did for the case of $k=1$ we can pre-compute $2^k$ cuts, fixing $S$ as each possible set in $O(2^k \cdot max\\_flow(n, m))$, and then answer each query in $O(2^k)$. The overall complexity of this solution will be $O(2^k \cdot max\\_flow(n, m) + q \cdot 2^k)$. 

However the preprocessing can be done faster. If we have the maximum flow (and the residual network) for a mask, we can compute the maximum flow adding one new edge in $O(w * m)$, doing at most $w$ steps of augmentation as done by Ford-Fulkerson algorithm. To remove an edge we just store the residual network before augmenting, in such a way that we can undo the last change. The time complexity of the preprocessing will be $O(max\\_flow(n, m) + 2^k \cdot w \cdot m)$ and since we need to be able to undo the last operation spatial complexity will be $O(k \cdot m)$.

It was possible to solve the problem without the last trick, but it was not guaranteed that slow flows implementations would work in $O(2^k \cdot max\\_flow(n, m))$.

 **C++ solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

template<typename C, typename R = C>
struct dinic
{
	typedef C flow_type;
	typedef R result_type;

	static_assert(std::is_arithmetic<flow_type>::value, "flow_type must be arithmetic");
	static_assert(std::is_arithmetic<result_type>::value, "result_type must be arithmetic");

	static const flow_type oo = std::numeric_limits<flow_type>::max();

	struct edge
	{
		//int src; // not needed, can be deleted to save memory
		int dst;
		int rev;
		flow_type cap, flowp;

		edge(int src, int dst, int rev, flow_type cap, int flowp) :
			/*src(src),*/ dst(dst), rev(rev), cap(cap), flowp(flowp) {}
	};

	dinic(int n) : adj(n), que(n), level(n), edge_pos(n), flow_id(0) {}

	int add_edge(int src, int dst, flow_type cap, flow_type rcap = 0)
	{
		adj[src].emplace_back(src, dst, (int) adj[dst].size(), cap, flow_id++);
		if (src == dst) adj[src].back().rev++;
		adj[dst].emplace_back(dst, src,  (int) adj[src].size() - 1, rcap, flow_id++);
		return (int) adj[src].size() - 1 - (src == dst);
	}

	inline bool side_of_S(int u) { return level[u] == -1; }

	result_type max_flow(int source, int sink, vector<flow_type> &flow_e)
	{
		result_type flow = 0;
		while (true)
		{
			int front = 0, back = 0;
			std::fill(level.begin(), level.end(), -1);
			for (level[que[back++] = sink] = 0; front < back && level[source] == -1; ++front)
			{
				int u = que[front];
				for (const edge &e : adj[u])
					if (level[e.dst] == -1 && flow_e[rev(e).flowp] < rev(e).cap)
						level[que[back++] = e.dst] = 1 + level[u];
			}
			if (level[source] == -1)
				break;
			std::fill(edge_pos.begin(), edge_pos.end(), 0);
			std::function<flow_type(int, flow_type)> find_path = [&](int from, flow_type res)
			{
				if (from == sink)
					return res;
				for (int &ept = edge_pos[from]; ept < (int) adj[from].size(); ++ept)
				{
					edge &e = adj[from][ept];
					if (flow_e[e.flowp] == e.cap || level[e.dst] + 1 != level[from]) continue;
					flow_type push = find_path(e.dst, std::min(res, e.cap - flow_e[e.flowp]));
					if (push > 0)
					{
						flow_e[e.flowp] += push;
						flow_e[rev(e).flowp] -= push;
						if (flow_e[e.flowp] == e.cap)
							++ept;
						return push;
					}
				}
				return static_cast<flow_type>(0);
			};
			for (flow_type f; (f = find_path(source, oo)) > 0;)
				flow += f;
		}
		return flow;
	}

	result_type max_flow2(int source, int sink, vector<flow_type> &flow_e)
	{
		result_type flow = 0;
		std::function<flow_type(int, flow_type)> find_path = [&](int from, flow_type res)
		{
			level[from] = 1;
			if (from == sink)
				return res;
			for (int &ept = edge_pos[from]; ept < (int) adj[from].size(); ++ept)
			{
				edge &e = adj[from][ept];
				if (level[e.dst] == 1 || flow_e[e.flowp] == e.cap) continue;
				flow_type push = find_path(e.dst, std::min(res, e.cap - flow_e[e.flowp]));
				if (push > 0)
				{
					flow_e[e.flowp] += push;
					flow_e[rev(e).flowp] -= push;
					if (flow_e[e.flowp] == e.cap)
						++ept;
					return push;
				}
			}
			return static_cast<flow_type>(0);
		};
		
		for (bool ok = true; ok; )
		{
			int it = 0;
			std::fill(edge_pos.begin(), edge_pos.end(), 0);
			for (flow_type f; ; ++it)
			{
				std::fill(level.begin(), level.end(), -1);
				f = find_path(source, oo);
				if (f == 0)
				{
					if (it == 0) ok = false;
					break;
				}
				flow += f;
			}
		}
		return flow;
	}

	int flow_id;
private:
	std::vector<std::vector<edge>> adj;
	std::vector<int> que;
	std::vector<int> level;
	std::vector<int> edge_pos;

	inline edge& rev(const edge &e) { return adj[e.dst][e.rev]; }
};

const int inf = 25;

struct edge
{
	int u, v, w;
};

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void relabel(int n, vector<edge> &e, int k)
{
	shuffle(e.begin() + k, e.end(), rng);

	vector<vector<pair<int, int>>> adj(n);
	for (auto &i : e)
		adj[i.u].push_back({ i.v, &i-&e[0] });

	vector<edge> ne = e;
	vector<int> id(n, -1);
	id[0] = 0;
	id[n-1] = n-1;
	int sz = 1, esz = k;

	function<void(int)> dfs = [&](int u)
	{
		for (auto &v : adj[u])
		{
			if (v.second >= k)
			{
				ne[esz++] = e[v.second];
				v.second = -1;
			}
			if (id[v.first] == -1)
			{
				id[v.first] = sz++;
				dfs(v.first);
			}
		}
	};
	dfs(0);
	
	for (auto &u : adj)
		for (auto v : u)
			if (v.second >= k)
				ne[esz++] = e[v.second];
	
	for (int i = 0; i < n; ++i)
		if (id[i] == -1)
			id[i] = sz++;
			
	e = ne;
	for (auto &i : e)
	{
		i.u = id[i.u];
		i.v = id[i.v];
	}
}

struct masks
{
	int x, cost;
	vector<int> flow_e;
	
	bool operator<(const masks &o) const
	{
		return cost < o.cost;
	}
};

typedef std::chrono::_V2::system_clock::time_point timepoint;

timepoint get_time()
{
	return std::chrono::high_resolution_clock::now();
}

int get_elapsed(timepoint t)
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(get_time() - t).count();
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<edge> e(m);
	for (auto &i : e) cin >> i.u >> i.v >> i.w, --i.u, --i.v;

	vector<int> mask(1 << k, -1);
	
	relabel(n, e, k);
	dinic<int> d(n);
	for (int i = 0; i < m; ++i)
		d.add_edge(e[i].u, e[i].v, ((i < k) ? inf : e[i].w));

	vector<int> flow_e(d.flow_id);
	for (int i = 0; i < k; ++i)
		flow_e[2*i] = inf;

	mask[0] = d.max_flow(0, n-1, flow_e);
	
	priority_queue<masks> pq;
	pq.push({ 0, 0, flow_e });
	while (!pq.empty())
	{
		int x = pq.top().x;
		flow_e = pq.top().flow_e;
		pq.pop();
		
		for (int j = 0; j < k; ++j)
			if ((~x >> j & 1) && mask[x | 1 << j] == -1)
			{
				auto n_flow_e = flow_e;
				n_flow_e[2 * j] = 0;
				auto t = get_time();
				mask[x | 1 << j] = mask[x] + d.max_flow2(0, n-1, n_flow_e);
				pq.push({ x | 1 << j, get_elapsed(t), n_flow_e });
			}
	}

	vector<int> cut(1 << k), bit(1 << k);
	for (int i = 1; i < 1 << k; ++i)
		bit[i] = i & -i;

	const int U = (1 << k) - 1;
	while (q--)
	{
		for (int i = 0; i < k; ++i)
			cin >> cut[1 << i];

		int ans = mask[U];
		for (int i = 1; i < 1<<k; ++i)
		{
			cut[i] = cut[i ^ bit[i]] + cut[bit[i]];
			ans = min(ans, cut[i] + mask[U ^ i]);
		}
		cout << ans << "n";
	}

	return 0;
}
```
Problem idea: [mnaeraxr](https://codeforces.com/profile/mnaeraxr "Grandmaster mnaeraxr")

Solution idea: [mnaeraxr](https://codeforces.com/profile/mnaeraxr "Grandmaster mnaeraxr") and [Devil](https://codeforces.com/profile/Devil "Master Devil")

