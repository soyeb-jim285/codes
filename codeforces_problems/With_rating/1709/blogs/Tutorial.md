# Tutorial

[1709A - Three Doors](../problems/A._Three_Doors.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1709A - Three Doors](../problems/A._Three_Doors.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Note that we never have a choice in what door should we open. First, we open the door with the same number as the key in our hand. Then, the door with the same number as the key behind the first opened door. Finally, the door with the same number as the key behind the second opened door.

If any of the first and second opened doors didn't have a key behind it, then it's impossible. Otherwise, we open every door.

Let a1,a2,a3 be the keys behind the corresponding doors. Then we should check if a[x] is not zero and a[a[x]] is not zero.

Overall complexity: O(1) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	x = int(input())
	a = [0] + [int(x) for x in input().split()]
	print("YES" if a[x] != 0 and a[a[x]] != 0 else "NO")
```
[1709B - Also Try Minecraft](../problems/B._Also_Try_Minecraft.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1709B - Also Try Minecraft](../problems/B._Also_Try_Minecraft.md "Educational Codeforces Round 132 (Rated for Div. 2)")

So, the first idea that is coming into mind is prefix sums. Let's define two values li=max(0,ai−ai+1) and ri=max(0,ai+1−ai). The value li means the amount of fall damage when we are going to the right from the column i to the column i+1, and ri means the amount of fall damage when we are going to the left from the column i+1 to the column i. Then let's build prefix sums on these two arrays. Now let pli be the sum of all li on a prefix [0;i) (i. e. pl0=0), and pri be the sum of all ri on a prefix [0;i). Then if s<t in a query, the answer is plt−1−pls−1, otherwise (if s>t) the answer is prs−1−prt−1.

Time complexity: O(n).

 **Solution (vovuh)**
```cpp
n, m = map(int, input().split())
a = list(map(int, input().split()))
l = [0] + [max(0, a[i] - a[i + 1]) for i in range(n - 1)]
r = [0] + [max(0, a[i] - a[i - 1]) for i in range(1, n)]
for i in range(n - 1):
    l[i + 1] += l[i]
    r[i + 1] += r[i]
for _ in range(m):
    s, t = map(int, input().split())
    if s < t:
        print(l[t - 1] - l[s - 1])
    else:
        print(r[s - 1] - r[t - 1])
```
[1709C - Recover an RBS](../problems/C._Recover_an_RBS.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1709C - Recover an RBS](../problems/C._Recover_an_RBS.md "Educational Codeforces Round 132 (Rated for Div. 2)")

There are many different approaches to this problem, but I think the model solution has the most elegant one.

First of all, let's construct an RBS from the given string (it always exists, so it is always possible). By calculating the number of opening brackets, closing brackets and questions in the given string, we can compute the number of question marks that should be replaced with opening brackets (it is easy since exactly half of the characters in each RBS are opening brackets). Then, let's form the RBS greedily: replace the first several question marks with opening brackets, and all remaining ones with closed brackets.

Okay, then what about finding a second RBS? Recall that a bracket sequence is an RBS when for each of its positions, the number of closing brackets before it is not greater than the number of opening brackets before it (and these two values should be equal at the end of the sequence, but it is less important now). Consider the segment between the last question mark replaced with an opening bracket, and the first question mark replaced by the closing bracket. If we try to change the order of characters corresponding to question marks, the balance on this segment will decrease at least by 2 (since at least one opening bracket to the left of it will become a closing bracket). Is there a way to affect only this segment, and change the balance on it only by 2? Yes — just swap the endpoints of this segment (i. e. the last opening bracket that was a question mark and the first closing bracket that was also a question mark). If it yields an RBS, then the answer is NO. Otherwise, the answer is YES since any other permutation of characters that were replacing question marks will also decrease the balance on this segment by at least 2.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  auto check = [](const string& s) {
    int bal = 0;
    for (char c : s) {
      if (c == '(') ++bal;
      if (c == ')') --bal;
      if (bal < 0) return false;
    }
    return bal == 0;
  };
  
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> pos;
    int op = s.size() / 2, cl = s.size() / 2;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '?') pos.push_back(i);
      if (s[i] == '(') --op;
      if (s[i] == ')') --cl;
    }
    for (int i = 0; i < pos.size(); ++i) {
      if (i < op) s[pos[i]] = '(';
      else s[pos[i]] = ')';
    }
    bool ok = true;
    if (op > 0 && cl > 0) {
      swap(s[pos[op - 1]], s[pos[op]]);
      if (check(s)) ok = false;
    }
    cout << (ok ? "YESn" : "NOn");
  }
} 
```
[1709D - Rorororobot](../problems/D._Rorororobot.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1709D - Rorororobot](../problems/D._Rorororobot.md "Educational Codeforces Round 132 (Rated for Div. 2)")

What if there were no blocked cells? Then the movement is easy. From cell (x,y) we can go to cells (x+k,y), (x,y+k), (x−k,y) or (x,y−k). Thus, we can visit all cells that have the same remainder modulo k over both dimensions. The answer would be "YES" if xsmodk=xfmodk and ysmodk=yfmodk.

Let's choose the following path from start to finish. Let xs be less or equal to xf. If that isn't the case, swap the cells. First, move up until the row is the same, then move to the side until the column is the same.

What stops us from doing the same on a grid with blocked cells? The first part of the part can remain the same — we can always move up from the cell. Only cells below the start cell can be blocked. The second part is trickier. If there is a column with too many blocked cells between the start and the finish column, then we won't be able to pass through it.

Let's adjust the path for that. Move up as high as possible — to the highest cell with the same remainder modulo k in this column. Then move to the finish column and go down to the finish cell.

If there still exists a column with too many blocked cells, then the answer is "NO". No matter what we do, we won't be able to go around that column. Otherwise, the answer is "YES".

Thus, the solution is to check for remainders, then find the largest number of blocked cells between the query columns and compare it to the highest row with the same remainder modulo k as the start or the finish. You can use any RMQ data structure you want.

Overall complexity: O(nlogn+q) with sparse table for RMQ, for example.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(m);
	forn(i, m) scanf("%d", &a[i]);
	
	int l = 0;
	while ((1 << l) <= m) ++l;
	vector<vector<int>> st(l, vector<int>(m));
	forn(i, m) st[0][i] = a[i];
	for (int j = 1; j < l; ++j) forn(i, m){
		st[j][i] = st[j - 1][i];
		if (i + (1 << (j - 1)) < m)
			st[j][i] = max(st[j][i], st[j - 1][i + (1 << (j - 1))]);
	}
	vector<int> pw(m + 1, 0);
	for (int i = 2; i <= m; ++i) pw[i] = pw[i / 2] + 1;
	auto get = [&](int l, int r){
		if (l > r) swap(l, r);
		++r;
		int len = pw[r - l];
		return max(st[len][l], st[len][r - (1 << len)]);
	};
	
	int q;
	scanf("%d", &q);
	forn(_, q){
		int xs, ys, xf, yf, k;
		scanf("%d%d%d%d%d", &xs, &ys, &xf, &yf, &k);
		--xs, --ys, --xf, --yf;
		if (ys % k != yf % k || xs % k != xf % k){
			puts("NO");
			continue;
		}
		int mx = (n - xs - 1) / k * k + xs;
		puts(get(ys, yf) <= mx ? "YES" : "NO");
	}
	return 0;
}
```
[1709E - XOR Tree](../problems/E._XOR_Tree.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1709E - XOR Tree](../problems/E._XOR_Tree.md "Educational Codeforces Round 132 (Rated for Div. 2)")

To begin with, we note that there are no restrictions on the values that can be written on the vertices, so we can use numbers of the form 230+x for the x-th replacement. Then, if we replaced the value of a vertex, then no path passing through this vertex has weight 0.

Let's root the tree at the vertex number 1. We can use a greedy approach: consider some vertex v such that it is the LCA for two vertices x and y, the path between which has XOR equal to 0. Among such vertices v, pick one with the maximum distance from the root. We need to change at least one vertex on the path (x,y). It turns out that changing the vertex v is always no worse than changing any other vertex u on this path, because all the remaining bad paths that pass through the vertex u also pass through the vertex v (that's why we have chosen the deepest LCA). This means that in order to solve the problem, it is necessary to quickly find the deepest LCA of some bad path.

For the convenience of solving the problem, let's denote the XOR on the path (x,y) as bx⊕by⊕aLCA(x,y), where bv is XOR on the path from the root to the vertex v. For all vertices v, let's maintain a set of values bx, such that x belongs to the subtree of v. Let's use the small-to-large method to obtain such sets. Also, during the union of sets, we can check if there is a bad path in this subtree, i. e. if two values in the sets we merge have the same XOR as the value written on the current vertex (because that's when the XOR on path is 0). If such a path exists, then we have to change the value of the vertex v and mark that the vertices of this subtree cannot be the ends of a bad path anymore — that means we just clear the set instead of pulling it up the tree.

This solution works in O(nlog2n).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 13;

int n;
int a[N], b[N];
vector<int> g[N];
set<int> vals[N];

void init(int v, int p) {
  b[v] = a[v];
  if (p != -1) b[v] ^= b[p];
  for (int u : g[v]) if (u != p)
    init(u, v);
}

int ans;

void calc(int v, int p) {
  bool bad = false;
  vals[v].insert(b[v]);
  for (int u : g[v]) if (u != p) {
    calc(u, v);
    if (vals[v].size() < vals[u].size()) vals[v].swap(vals[u]);
    for (int x : vals[u]) bad |= vals[v].count(x ^ a[v]);
    for (int x : vals[u]) vals[v].insert(x);
    vals[u].clear();
  }
  if (bad) {
    ans += 1;
    vals[v].clear();
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  init(0, -1);
  calc(0, -1);
  cout << ans << 'n';
} 
```
[1709F - Multiset of Strings](../problems/F._Multiset_of_Strings.md "Educational Codeforces Round 132 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1709F - Multiset of Strings](../problems/F._Multiset_of_Strings.md "Educational Codeforces Round 132 (Rated for Div. 2)")

First of all, let's visualize the problem in a different way. We have to set some constraints on the number of strings which have some kind of prefix. Let's think about a data structure that would allow us to understand it better. One of the most common data structures to store strings which works with their prefixes and maintains the number of strings with some prefix is a trie; so, we can reformulate this problem using tries.

Now the problem is the following one: we have a binary trie of depth n; the leaves of this trie may store strings, and for each vertex except for the root, we can set a constraint on the number of strings stored in the subtree; what is the number of ways to choose these constraints so that the maximum number of strings (possibly with copies) the trie can store is exactly f? To handle it, we can use dynamic programming of the form dpv,i — the number of ways to choose the constraints for the vertex v and its subtree so that the maximum number of strings which can be stored in the subtree is exactly i. When calculating dpv,i, we can iterate on the constraint for the vertex v (let it be a), and the maximum number of strings in the subtrees of v1 and v2 (let these be b and c), and make updates of the form "add dpv1,b⋅dpv2,c to the value of dpv,min(a,b+c)". This dynamic programming will work in O(2nk2) or O(2nk3) depending on the implementation, which is too slow.

However, we can use the following optimizations to improve the complexity of the solution:

* all vertices on the same depth can be treated as equivalent, so we can actually calculate this dynamic programming not for O(2n) vertices, but just for O(n);
* when handling transitions from some node's children to that node, let's split these transitions into two steps. The first step is iterating on the number of strings which fit into the subtrees of the children; the second step is iterating on the constraint for the subtree of the node. The first step is actually a convolution: if we don't consider the constraint for the node itself, then the transitions would be something like "add dpv1,b⋅dpv2,c to the value of dpv,b+c)"; so it can be improved to O(klogk) with FFT. The second step can be improved to O(k) as well, if we iterate on the minimum between the constraint for the node and the total number of strings which can be stored in the children, and maintain the sum on suffix for the values of dynamic programming.

Overall, these optimizations lead to a solution with complexity O(nklogk).

