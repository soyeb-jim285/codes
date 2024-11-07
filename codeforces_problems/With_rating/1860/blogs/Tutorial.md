# Tutorial

[1860A - Not a Substring](../problems/A._Not_a_Substring.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1860A - Not a Substring](../problems/A._Not_a_Substring.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Let's consider the following two cases: 

* the string s contains two consecutive equal characters, for example, ")(((" or "())". In this case, we can choose a string t of the form "()()()", since it does not contain a substring of two equal characters, therefore s is not a substring of t;
* in the string s, all adjacent characters are different, i.e., it is alternating. In this case, we can choose a string t of the form "((()))", since here the length of the longest alternating substring is 2. The only alternating substring it contains is "()", which is a part of every regular bracket sequence.

Thus, it is sufficient to consider the answer among only two candidates — "()()()" and "((()))" of length 2n.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
	string s;
	cin >> s;
	int n = s.size();
	string a, b;
	for (int i = 0; i < 2 * n; ++i) {
	  a += "()"[i & 1];
	  b += ")("[i < n];
	}
	if (a.find(s) == string::npos) {
	  cout << "YESn" << a << 'n';
	} else if (b.find(s) == string::npos) {
	  cout << "YESn" << b << 'n';
	} else {
	  cout << "NOn";
	}
  }
}
```
[1860B - Fancy Coins](../problems/B._Fancy_Coins.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1860B - Fancy Coins](../problems/B._Fancy_Coins.md "Educational Codeforces Round 153 (Rated for Div. 2)")

There are two ways to approach this problem: a mathematical way and an algorithmic way.

Approach 1

Let's start by looking at the possible ways to represent m burles with our coins. For example, we could try to use as many coins of value k as possible: then, the number of coins of value k will be ⌊mk⌋, and the number of coins of value 1 will be mmodk.

Now suppose it's not optimal to use that many coins of value k; what if it's better to use more coins of value 1 and fewer coins of value k? Well, we can still start with using ⌊mk⌋ coins of value k and mmodk coins of value 1, and then try to replace one coin of value k with k coins of value 1 several times (maybe zero).

How many times should we do this, and when should we stop to get an optimal solution? Well, firstly, let's make sure that we have already taken as many regular coins as possible. Then, if we have at least k leftover coins of value 1 which are regular (not fancy), and we have taken at least one fancy coin of value k, it's better to replace that coin. It's easy to see that there's no need for any replacements if that's not the case: if we don't have k regular coins which are currently unused, then at least one of the replacement coins will be fancy; and if the coin of value k we want to replace is not fancy, why replacing it at all?

So, we could write a while-loop that keeps track how many coins of which types we have taken, and replaces one fancy coin of value k with k regular coins of value 1 until it's impossible. Unfortunately, this is too slow. But instead of running this loop, we can calculate the number of times we make that replacement in O(1): it is the minimum of the number of regular coins of value 1 we aren't using, divided by k, and the number of fancy coins of value k we are using.

So, the outline of the solution is the following:

* start by taking as many coins of value k as possible, and calculate how many coins of which value we have taken;
* calculate how many regular and fancy coins of both types we have taken;
* calculate how many "replacements" (discard one fancy coin of value k, add k regular coins of value 1) we can make.

Approach 2

The second approach also starts with analyzing how many coins of value 1 and how many coins of value k we can take. The minimum number of coins of value k we can take is 0, and the maximum number of such coins is ⌊mk⌋.

Let f(x) denote the number of fancy coins we use, if we take exactly x coins of value k. This function can easily be calculated because we know how many coins of both types we take, if x is fixed. We need to find the minimum of this function on [0,⌊mk⌋].

How does f(x+1)−f(x) behave? The meaning of going from f(x) to f(x+1) is just replacing k coins of value 1 with one coin of value k. When we increase x, obviously, we should try to discard fancy coins of value 1 first, then regular coins of value 1 (and the number of fancy coins we will discard will never increase when we increase x). Similarly, we should try to take regular coins of value k first, then fancy ones (and the number of fancy coins we take will never decrease when we increase x). So, the value of f(x+1)−f(x) does not decrease when x increases.

All of this means that the minimum value of f(x) can be found using ternary search.

 **Solution 1 (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int m, k, a1, ak;
		cin >> m >> k >> a1 >> ak;
		int taken_k = m / k;
		int taken_1 = m % k;
		int taken_fancy_1 = max(0, taken_1 - a1);
		int left_regular_1 = max(0, a1 - taken_1);
		int taken_fancy_k = max(0, taken_k - ak);
		int to_replace = min(left_regular_1 / k, taken_fancy_k);
		int ans = taken_fancy_1 + taken_fancy_k - to_replace;
		cout << ans << endl;
	}
}
```
 **Solution 2 (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int m, k, a1, ak;
		cin >> m >> k >> a1 >> ak;
		// function which calculates the number of fancy coins taken
		// if we take exactly x coins of value k
		auto f = [m, k, a1, ak](int x)
		{
			int taken_1 = m - k * x;
			return max(0, taken_1 - a1) + max(0, x - ak);
		};
		
		int lf = 0;
		int rg = m / k;
		while(rg - lf > 2)
		{
			int mid = (lf + rg) / 2;
			if(f(mid) < f(mid + 1))
				rg = mid + 1;
			else
				lf = mid;
		}
		int ans = 1e9;
		for(int i = lf; i <= rg; i++) ans = min(ans, f(i));
		cout << ans << endl;
	}
}
```
[1860C - Game on Permutation](../problems/C._Game_on_Permutation.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1860C - Game on Permutation](../problems/C._Game_on_Permutation.md "Educational Codeforces Round 153 (Rated for Div. 2)")

For each position i, let's determine its status: whether this position is winning or losing for the player who moved the chip into that position. Since a player can only move a chip into a position with smaller index, we can determine the statuses of positions in the order from 1 to n. You can treat it as dynamic programming.

If there is no such j that j<i and pj<pi, then this position is a losing one, because the other player cannot make a move, which means they win (and the player who placed the chip in that position loses). Otherwise, the other player can make a move. And we already know whether the player wins if they place a chip for all previous positions. If there exists a position j where a move can be made and j is a winning position, then i is a losing one (because our opponent will move there). Otherwise, i is a winning position. Thus, we have a solution with a time complexity of O(n2), for each position i, we need to iterate through all possible transitions j.

However, we can notice that we are only interested in two simple properties to determine the status of each position: whether a move can be made from the current position, and whether a move can be made into a winning position. The first property can be easily checked if we maintain the minimum element up to the current position i, let's call it mn. And for the second property, it is sufficient to maintain the minimum element among winning positions, let's call it mnWin. Then, position i is winning if mn<pi and mnWin>pi. Thus, the time complexity of the solution is O(n).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    int mn = n + 1, mnWin = n + 1;
    while (n--) {
      int x;
      cin >> x;
      if (mn < x && x < mnWin) {
      	ans += 1;
      	mnWin = x;
      }
      mn = min(mn, x);
    }
    cout << ans << 'n';
  }
}
```
[1860D - Balanced String](../problems/D._Balanced_String.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1860D - Balanced String](../problems/D._Balanced_String.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Let's calculate the following dynamic programming: $dp_{i, cnt0, cnt01}$ — the minimum number of changes in string $s$ if we consider only $i$ first characters of it, the number of characters 0 on that prefix is $cnt0$, and the number of subsequences 01 on that prefix is equal to $cnt01$.

The transitions are pretty simple. Let's look at the transitions according to the character we are trying to place at the next position: 

* if it is 0, then there is transition from the state $(i, cnt0, cnt01)$ to the state $(i + 1, cnt0 + 1, cnt01)$ and the value of $dp$ depends on $s_i$ (the value stays the same if $s_i=0$, and increases by $1$ otherwise);
* if it is 1, then there is transition from the state $(i, cnt0, cnt01)$ to the state $(i + 1, cnt0, cnt01 + cnt0)$, and the value of $dp$ depends on $s_i$ (the value stays the same if $s_i=1$ and increases by $1$ otherwise).

So, this dynamic programming works in $O(n^4)$.

It remains us to get the answer to the problem from that dynamic programming. It is stored in $dp_{n, cnt0, need}$, where $cnt0$ is equal to the number of characters 0 in the string $s$, and $need=\frac{cnt0 \cdot cnt1}{2}$ (because the number of subsequences 01 should be equal to the number of subsequences 10). But our dynamic programming stores the number of changes in the string, and the problems asks for the minimum number of swaps. However, we can easily get it from the $dp$ value. Since the amounts of zeroes and ones are fixed in the string, then the number of changes from 0 to 1 equals to the number of changes from 1 to 0 and we can pair them up. So, the answer to the problem is the half of the $dp$ value.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
using li = long long;
 
const int N = 111;
 
int n;
string s;
int dp[2][N][N * N];
 
int main() {
  cin >> s;
  n = s.size();
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i + 1; ++j) {
      for (int cnt = 0; cnt <= j * (i + 1 - j); ++cnt) {
        dp[1][j][cnt] = n;   
      }
    }
    for (int j = 0; j <= i; ++j) {
      for (int cnt = 0; cnt <= j * (i - j); ++cnt) {
        dp[1][j + 1][cnt] = min(dp[1][j + 1][cnt], dp[0][j][cnt] + (s[i] != '0'));
        dp[1][j][cnt + j] = min(dp[1][j][cnt + j], dp[0][j][cnt] + (s[i] != '1'));
      }
    } 
    swap(dp[0], dp[1]);
  }
  int cnt0 = count(s.begin(), s.end(), '0');
  cout << dp[0][cnt0][cnt0 * (n - cnt0) / 2] / 2 << 'n';
}
```
[1860E - Fast Travel Text Editor](../problems/E._Fast_Travel_Text_Editor.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1860E - Fast Travel Text Editor](../problems/E._Fast_Travel_Text_Editor.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Let's start with the easiest slow solution.

We can basically treat the problem as a graph one. There are n−1 vertices and the operations represent edges: from i to i+1, from i+1 to i and from i to j if si=sj and si+1=sj+1.

Then, for a query, we can run any algorithm that finds the shortest path. For example, BFS. That will be n2 per query in the worst case, because the third type of actions produces a lot of edges.

Let's try to optimize the third action. If you look at the edges between all positions linked by the third action, they just form cliques. So the distance between every pair of vertices should be equal to 1. Instead of having a lot of edges, we can add a dummy vertex that simulates this behavior. For example, add a directed edge from each vertex in the clique to the dummy vertex of weight 1 and a directed edge back of weight 0. Now, you can travel from one vertex to another in the clique in 1, but only use O(n) edges in total.

Thus, the BFS for each query will be linear. Well, a couple of things are wrong with that statement... First, not a regular BFS, of course, but a 0-1 BFS now, since there are edges of weight 0. Second, there are also some dummy vertices. How many of them? Each clique is induced by all positions that have the same letters to the left and to the right of them. So, there are |A|2 options, where |A|=26, and n+|A|2 vertices in total.

To optimize further, let's investigate the structure of the path. There are trivial paths: they just go left or right without using the third action. We can initialize the answer with them.

Otherwise, a path uses the jump to the dummy node at least once. Let that node be s. So, the path looks like f→s, then s→t. Let's use the fact that there are not that many candidates for s. We can iterate over s and update the answer with each of them. If the optimal path goes through any of them, we will find it.

And calculating f→s or s→t is way easier. First, f→s is the same as s→f in a transposed graph (all edges are reversed). Second, we can calculate the shortest path from s to all vertices with a single 0-1 BFS.

Thus, we get a solution in O(|A|2⋅(n+|A|2+q)). We can either run |A|2 BFS's before reading the queries and save the results, using O(|A|2⋅n) memory. Alternatively, we can read the queries, then run each BFS and update the answer with its results immediately for O(n+|A|2) memory. The second option will generally also be faster by a constant factor, since there are fewer cache misses.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
const int INF = 1e9;
const int AL = 26;
 
struct query{
	int f, t, ans;
};
 
struct edge{
	int u, w;
};
 
int main() {
	cin.tie(0);
	iostream::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	
	int m;
	cin >> m;
	vector<query> a(m);
	forn(i, m){
		cin >> a[i].f >> a[i].t;
		--a[i].f, --a[i].t;
		a[i].ans = abs(a[i].f - a[i].t);
	}
	
	int k = n - 1 + AL * AL;
	vector<vector<edge>> g(k);
	forn(i, n - 1){
		int j = n - 1 + (s[i] - 'a') * AL + (s[i + 1] - 'a');
		g[i].push_back({j, 0});
		g[j].push_back({i, 1});
		if (i > 0){
			g[i].push_back({i - 1, 1});
			g[i - 1].push_back({i, 1});
		}
	}
	
	for (int st = n - 1; st < k; ++st){
		vector<int> d(k, INF);
		d[st] = 0;
		deque<int> q;
		q.push_back(st);
		while (!q.empty()){
			int v = q.front();
			q.pop_front();
			for (auto it : g[v]){
				if (d[it.u] <= d[v] + it.w) continue;
				d[it.u] = d[v] + it.w;
				if (it.w == 0) q.push_front(it.u);
				else q.push_back(it.u);
			}
		}
		forn(i, m){
			a[i].ans = min(a[i].ans, d[a[i].f] + d[a[i].t] - 1);
		}
	}
	
	forn(i, m) cout << a[i].ans << 'n';
	return 0;
}
```
[1860F - Evaluate RBS](../problems/F._Evaluate_RBS.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1860F - Evaluate RBS](../problems/F._Evaluate_RBS.md "Educational Codeforces Round 153 (Rated for Div. 2)")

Think of this as a geometry problem. If that's a revelation for you, don't worry, you'll start seeing it with more experience.

We have some points (a,b), are asked to choose a vector (x,y) and sort the points by a dot product of (a,b) and (x,y). What exactly is a dot product? Well, A⋅B=|A|⋅|B|⋅cosα. Obviously, (a,b) will always be the same length no matter what (x,y) we choose. At the same time, the length of (x,y) will also be the same for a fixed (x,y). So, a dot product only depends on an angle between (x,y) and (a,b). Thus, the vector (x,y) can always be a unit one.

Imagine iterating over all vectors (x,y) in the increasing order of their angle. Consider a pair of different points (a1,b1) and (a2,b2). When does one go before the other in the order? We can compare their angles to (x,y). So, if we keep rotating (x,y), the order of two points will be changing when their angles to (x,y) are the same. That happens exactly twice, and both events correspond to the opposite vectors. Both of them lie on the line perpendicular to the one (a1,b1) and (a2,b2) are on.

Now imagine that rotating (x,y) idea as an actual algorithm. We'd want to iterate over all (x,y) while maintaining the order of points. When we encounter (x,y) on a line where two points swap, we swap. For each (x,y) we check if current order of points produces an RBS.

For points with the same dot product (so when (x,y) is on a line where these swap), we arrange them in such an order that the opening bracket goes first, then the closing bracket. That must be pretty obvious from any RBS intuition.

Obviously, we don't care about all (x,y) (also there are infinitely many of them). We only care about ones where something happens. Now, that algorithm is called a radial sweepline. Very commonly not the prettiest thing to code, but I'll share some implementation details that help with this one. I'll also call vectors (x,y) events from now on sometimes.

First, generate all interesting (x,y), arrange them by their angle and save what happens for each of them. Get rid of pairs with non-positive x or y. Now, arranging by angle can be done with just a cross product. Also, with that, you don't even have to normalize the vectors. You can use a map from points to events with a comparator using cross product (and no additional tie-breaks).

Second, instead of swapping pairs one by one on each angle (which might turn very annoying very fast), let's process them all in bulk. When there are multiple pairs of points swapping on the same angle, extract all of them from the current order, sort them on their own and insert them back.

Notice that it doesn't produce exactly the same outcome. It rearranges the points as if all points with equal dot product are free among each other until the next event. However, if we turn (x,y) just a bit further, they will get in their true places. But our algorithm will just skip to the next event without fixing the order.

It's actually quite easy to fix the issue. Along with sorting points that swap on the current event, take also points that had to be swapped on the previous event. Sort them all together. That won't increase the complexity (however, will increase the constant factor), but will fix the order of the previous event points.

The sorting is best done with an inverse permutation of the order. For each point, remember its current place in the order. Now, we can find where each point is, and we can easily update the inverse permutation after the rearrangement. Since every pair of point appears at most O(1) times, the total size of arrays to sort is O(n2).

Finally, how to check for an RBS every time? We can't afford O(n), so we must maintain something. For a sequence to be an RBS, all prefix balances of brackets should be non-negative (since we are already guaranteed by the input that the final balance is 0). The idea is easy. Notice how the points that are swapped on each event actually represent some segments of the order. And all swaps are performed within these segments. Thus, the prefix balances are only updated for the positions of the swapping points. Basically, we can maintain the entire array of the prefix balances and the number of negative elements in it. On each event, recalculate its entire parts corresponding to the positions of the sorted points. If the number of negative elements becomes 0, then we found the answer.

Overall complexity: O(n2logn).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
const int INF = 1e9;
 
struct bracket{
	int a, b, c;
};
 
struct point{
	int x, y;
};
 
long long cross(const point &a, const point &b){
	return a.x * 1ll * b.y - a.y * 1ll * b.x;
}
 
long long dot(const point &a, const bracket &b){
	return a.x * 1ll * b.a + a.y * 1ll * b.b;
}
 
bool operator <(const point &a, const point &b){
	return cross(a, b) > 0;
}
 
int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<bracket> val;
		forn(i, 2 * n){
			int a, b;
			string c;
			cin >> a >> b >> c;
			val.push_back({a, b, c[0] == '(' ? 1 : -1});
		}
		map<point, vector<int>> opts;
		forn(i, 2 * n) forn(j, 2 * n){
			int dx = val[i].b - val[j].b;
			int dy = val[j].a - val[i].a;
			if (dx <= 0 || dy <= 0) continue;
			opts[{dx, dy}].push_back(i);
			opts[{dx, dy}].push_back(j);
		}
		opts[{1, INF}];
		vector<int> ord(2 * n), rord(2 * n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](int i, int j){
			long long di = dot({INF, 1}, val[i]);
			long long dj = dot({INF, 1}, val[j]);
			if (di != dj) return di < dj;
			return val[i].c > val[j].c;
		});
		forn(i, 2 * n) rord[ord[i]] = i;
		int neg = 0, cur = 0;
		vector<int> bal(1, 0);
		for (int i : ord){
			cur += val[i].c;
			bal.push_back(cur);
			neg += cur < 0;
		}
		bool ans = neg == 0;
		vector<int> prv;
		for (auto it : opts){
			vector<int> tot = prv;
			for (int x : it.second) tot.push_back(x);
			sort(tot.begin(), tot.end(), [&](int i, int j){
				return rord[i] < rord[j];
			});
			tot.resize(unique(tot.begin(), tot.end()) - tot.begin());
			for (int x : tot) neg -= bal[rord[x] + 1] < 0;
			vector<int> tmp = tot;
			sort(tot.begin(), tot.end(), [&](int i, int j){
				long long di = dot(it.first, val[i]);
				long long dj = dot(it.first, val[j]);
				if (di != dj) return di < dj;
				return val[i].c > val[j].c;
			});
			vector<int> nrord(tot.size());
			forn(i, tot.size()) nrord[i] = rord[tmp[i]];
			forn(i, tot.size()) rord[tot[i]] = nrord[i];
			for (int x : tot){
				bal[rord[x] + 1] = bal[rord[x]] + val[x].c;
				neg += bal[rord[x] + 1] < 0;
			}
			if (neg == 0){
				ans = true;
				break;
			}
			prv = it.second;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
```
