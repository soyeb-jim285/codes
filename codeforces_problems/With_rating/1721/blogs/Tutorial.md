# Tutorial

[1721A - Image](../problems/A._Image.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1721A - Image](../problems/A._Image.md "Educational Codeforces Round 134 (Rated for Div. 2)")

There are some solutions based on case analysis, but in my opinion, the most elegant one is the following:

Let's pick a color with the maximum possible number of pixels and repaint all other pixels into it. We will try to pick all pixels of some other color and repaint them in one operation, and we can ignore the constraint that we can repaint no more than 2 pixels, since we will never need to repaint 3 or 4 pixels in one operation. So, the number of operations is just the number of colors other than the one we chosen, or just d−1, where d is the number of different colors in the image. To calculate this, we can use a set or an array of size 26, where we mark which colors are present.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        s1 += s2;
        cout << set<char>(s1.begin(), s1.end()).size() - 1 << endl;
    }
}
```
[1721B - Deadly Laser](../problems/B._Deadly_Laser.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1721B - Deadly Laser](../problems/B._Deadly_Laser.md "Educational Codeforces Round 134 (Rated for Div. 2)")

First, let's determine if it's possible to reach the end at all. If the laser's field doesn't span until any wall, then it's surely possible — just stick to the wall yourself.

If it touches at most one wall, it's still possible. If it's the bottom wall or the left wall, then take the path close to the top and the right wall. Vice versa, if it's the top wall or the right wall, then take the path close to the bottom and the left wall.

What if both of these paths are locked? That means that the laser touches at least two walls at the same time: the top one and the left one, or the bottom one and the right one. Turns out, it's completely impossible to reach the end in either of these two cases. Just draw a picture and see for yourself.

Thus, we can always take at least one of the path sticking to the walls. The distance from the start to the end is |n−1|+|m−1|, and both of these paths are exactly this long. So the answer is always either -1 or n+m−2.

To check if the laser touches a wall with its field, you can either use a formula or check every cell adjacent to a wall.

Overall complexity: O(1) or O(n+m) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n, m, sx, sy, d = map(int, input().split())
	if min(sx - 1, m - sy) <= d and min(n - sx, sy - 1) <= d:
	    print(-1)
	else:
	    print(n + m - 2)
```
[1721C - Min-Max Array Transformation](../problems/C._Min-Max_Array_Transformation.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1721C - Min-Max Array Transformation](../problems/C._Min-Max_Array_Transformation.md "Educational Codeforces Round 134 (Rated for Div. 2)")

For the start, let's note that ai≤bi for each i. Otherwise, there is no way to get b from a.

Firstly, let's calculate dmini for each i. Since all di≥0 then bj is always greater or equal than ai you get it from. So, the minimum di would come from lowest bj that still ≥ai. Since b is sorted, we can find such bj with lower_bound in O(logn).

Let's prove that we can build such d that transforms ai to bj we found earlier. Let's just make dk=bk−ak for k∈[1..j)∪(i..n]; dk=bk+1−ak for k∈[j..i) and di=bj−ai. It's easy to see that all di are non-negative, so such d is valid.

Now, let's calculate dmaxi. Suppose, we transform ai to bj for some j≥i. It's not hard to prove that the "proving" array d may be constructed in the similar way: dk=bk−ak for k∈[1..i)∪(j..n]; dk=bk−1−ak for k∈(i..j] and di=bj−ai.

In order to build such array d, you need bk−1≥ak for each i∈(i..j]. In other words, if there is some position l such that l>i and bl−1<al you can't choose j such that j≥l. It means that we can iterate i in descending order and just keep track of leftmost l≥i with bl−1<al. Then, dmaxi is equal to b[l−1]−a[i] (or b[n]−a[i] if there are no such l).

The resulting complexity is O(nlogn) because of the first part. But it can be optimized to O(n) if we use two pointers instead of lower_bound.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        val b = readLine()!!.split(' ').map { it.toInt() }

        val indices = (0 until n).sortedBy { a[it] }
        val mn = Array(n) { 0 }
        val mx = Array(n) { 0 }

        var lst = n
        for (i in n - 1 downTo 0) {
            val pos = indices[i]
            mn[pos] = lowerBound(b, a[pos])
            mx[pos] = lst - 1;
            if (i == mn[pos])
                lst = i

            mn[pos] = b[mn[pos]] - a[pos]
            mx[pos] = b[mx[pos]] - a[pos]
        }
        println(mn.joinToString(" "))
        println(mx.joinToString(" "))
    }
}

fun lowerBound(a: List<Int>, v: Int): Int {
    var l = -1; var r = a.size
    while (r - l > 1) {
        val m = (l + r) / 2
        if (a[m] < v)
            l = m
        else
            r = m
    }
    return r
}
```
[1721D - Maximum AND](../problems/D._Maximum_AND.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1721D - Maximum AND](../problems/D._Maximum_AND.md "Educational Codeforces Round 134 (Rated for Div. 2)")

We will build the answer greedily, from the highest significant bit to the lowest one. Let's analyze how to check if the answer can have the highest bit equal to 1. It means that every value in c should have its highest bit equal to 1, so for every i, exactly one of the numbers {ai,bi} should have this bit equal to 1. For both of the given arrays, we can calculate how many elements have which value of this bit, and then the number of elements with 1 in this bit in the array a should be equal to the number of elements with 0 in the array b (and the same for elements with 0 in a and elements with 1 in b). If these values are equal, it means that the elements of a and b can be matched in such a way that in every pair, the XOR of them has 1 in this bit. If it is so, then the highest bit of the answer is 1, otherwise it is 0.

Okay, then let's proceed to the next bit. Should we just do the same to check if this bit can be equal to 1 in the answer? Unfortunately, that's not enough. Let's look at the case: a=[3,0], b=[2,1]. We can get the value 1 in the 0-th bit or in the 1-st bit, but not in both simultaneously. So, for the next bit, we need to make sure that not only we can get 1 in the result, but we can also do this without transforming some of the 1-s to 0-s in the higher bits. If it is impossible, it doesn't matter if we can get 1 in the current bit since it will be suboptimal, so we have to use an ordering that gets 0 in this bit.

In general case, it means that we have to solve the following subproblem: check if we can obtain 1 in several bits of the answer; let these bits be {x1,x2,…,xk} (x1 to xk−1 are the bits that we have already checked; xk is the new bit we are trying to check). Let mask be the number that has 1 in every bit xi and 0 in every other bit. The elements should be matched in such a way that (ai&mask)⊕(bi&mask)=mask. If we group all numbers from a and from b according to the value of ai&mask (or bi&mask), then for every group of elements from a, there is a corresponding group in b such that we can match the elements from the first group only with the elements from the second group. So, if for every such group, its size in a is equal to the size of the corresponding group in b, then we can set all bits from {x1,x2,…,xk} to 1 simultaneously.

Some implementation notes: if the number of bits we need to check is big, the number of groups can become too large to handle all of them (since it is 2k). So, to store the number of elements in each group, we should use some associative data structure, like, for example, std::map in C++. If you use a map, splitting elements into groups will be done in O(nlogn), so in total, you will get complexity of O(nlognlogA), where A is the maximum possible value in the input.

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
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    
    auto check = [&](int ans) {
      map<int, int> cnt;
      for (int x : a) ++cnt[x & ans];
      for (int x : b) --cnt[~x & ans];
      bool ok = true;
      for (auto it : cnt) ok &= it.second == 0;
      return ok;
    };
    
    int ans = 0;
    for (int bit = 29; bit >= 0; --bit) 
      if (check(ans | (1 << bit)))
        ans |= 1 << bit;
    
    cout << ans << 'n';
  }
}
```
[1721E - Prefix Function Queries](../problems/E._Prefix_Function_Queries.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1721E - Prefix Function Queries](../problems/E._Prefix_Function_Queries.md "Educational Codeforces Round 134 (Rated for Div. 2)")

What's the issue with calculating the prefix function on the string s and then appending the string t with an extra |t| recalculations? Calculating prefix function is linear anyway. Well, it's linear, but it's also amortized. So while it will make O(n) operations for a string in total, it can take up to O(n) on every particular letter. These particular letters can appear in string t, making the algorithm work in O(q⋅(|s|+|t|)).

Let's analyze the classic way to calculate the prefix function. To append a character to the string and calculate the new value of the prefix function, you have to do the following: 

1. take the longest proper prefix of a string before appending the letter, which is also a suffix;
2. if the letter right after it is the same as the new one, then the new value is length of it plus one;
3. if it's empty, then the new value is 0;
4. otherwise, take its longest proper prefix and return to step 2.

Basically, from having the value of the prefix function of the string and the new letter, you can determine the new value of the prefix function.

If |t| was always equal to 1, then you would only want to try all options for the next letter after a string.

That should remind you of a structure known as prefix function automaton. Its states are the values of the prefix function, and the transitions are appending a letter to a string with a certain value of the prefix function.

So you can append a letter in O(1) if you have an automaton built on the string s. However, you can't just append more letters after one — you don't have the automaton built this far.

You can follow two paths.

The first one is to jump with a regular way of calculating the prefix function until you reach the state of the automaton which exists.

The second one is to continue building the automaton onto the string t, calculating the prefix function along the way. Appending a layer to the automaton takes O(AL) non-amortized. After you calculated everything you needed, pop the states back to the original.

Overall complexity: O(|s|⋅AL+q⋅|t|) or O(|s|⋅AL+q⋅|t|⋅AL).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 26;

vector<int> prefix_function(const string &s){
	int n = s.size();
	vector<int> p(n);
	for (int i = 1; i < n; ++i){
		int k = p[i - 1];
		while (k > 0 && s[i] != s[k])
			k = p[k - 1];
		k += (s[i] == s[k]);
		p[i] = k;
	}
	return p;
}

int main() {
	cin.tie(0);
	iostream::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	auto p = prefix_function(s);
	vector<vector<int>> A(n, vector<int>(AL));
	forn(i, n) forn(j, AL){
		if (i > 0 && j != s[i] - 'a')
			A[i][j] = A[p[i - 1]][j];
		else
			A[i][j] = i + (j == s[i] - 'a');
	}
	int q;
	cin >> q;
	vector<vector<int>> ans(q);
	forn(z, q){
		string t;
		cin >> t;
		int m = t.size();
		s += t;
		for (int i = n; i < n + m; ++i){
		    A.push_back(vector<int>(AL));
			forn(j, AL){
				if (j != s[i] - 'a')
					A[i][j] = A[p[i - 1]][j];
				else
					A[i][j] = i + (j == s[i] - 'a');
			}
			p.push_back(A[p[i - 1]][s[i] - 'a']);
			ans[z].push_back(p[i]);
		}
		forn(_, m){
			p.pop_back();
			s.pop_back();
			A.pop_back();
		}
	}
	for (auto &it : ans){
		for (int x : it)
			cout << x << ' ';
		cout << 'n';
	}
	return 0;
}
```
[1721F - Matching Reduction](../problems/F._Matching_Reduction.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1721F - Matching Reduction](../problems/F._Matching_Reduction.md "Educational Codeforces Round 134 (Rated for Div. 2)")

Let's start by finding the maximum matching in the given graph. Since the constraints are pretty big, you need something fast. The model solution converts the matching problem into a flow network and uses Dinic to find the matching in O(m1.5), but something like heavily optimized Kuhn's algorithm can also work.

Okay, then what about finding the minimum possible number of vertices to delete in order to reduce the maximum matching? We claim that it is always enough to remove one vertex, and the proof will also provide a way to quickly search for such vertices.

Let's recall that the size of the maximum matching is equal to the size of the minimum vertex cover (this only works in bipartite graphs). So, we will try to find a way to reduce the minimum vertex cover by 1, and it's actually pretty easy — just remove any vertex belonging to the vertex cover; it's obvious that it reduces the vertex cover by 1, and the maximum matching by 1 as well. So, we can find the minimum vertex cover in the graph using the standard algorithm to convert the MM into MVC (or, if you're using Dinic to find the maximum matching, you can represent the minimum vertex cover as the minimum cut problem), and for each query of type 1, just take a vertex from the vertex cover we found.

Now the only thing that's left is discussing how to maintain the structure of the maximum matching in the graph. In fact, it's quite easy:

* on the one hand, since we remove the vertices belonging to the minimum vertex cover, every edge (including the edges from the matching) will be incident to one of the vertices we will remove;
* on the other hand, due to the definition of the maximum matching, there is no vertex that is incident to two or more edges from the maximum matching;
* so, every vertex from the vertex cover has exactly one edge from the maximum matching that is incident to it, and when we remove a vertex, we can simply remove the corresponding edge from the maximum matching.

So, the only thing we need to do is to maintain which edge from the matching corresponds to which vertex from the minimum vertex cover, and it will allow us to maintain the structure of the maximum matching — and since these "pairs" don't change when we remove a vertex, it is enough to get this information right after we have constructed the maximum matching in the given graph; we won't need to rebuild it.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 400043;
const int INF = int(1e9);

struct edge
{
    int y, c, f;
    edge() {};
    edge(int y, int c, int f) : y(y), c(c), f(f) {};
};

vector<edge> e;
vector<int> g[N];
int S, T, V;
int d[N], lst[N];
int n1, n2, m, q;
map<pair<int, int>, int> es;

void add_edge(int x, int y, int c)
{
    g[x].push_back(e.size());
    e.push_back(edge(y, c, 0));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, 0));
}

int rem(int x)
{
    return e[x].c - e[x].f;
}

bool bfs()
{
    for (int i = 0; i < V; i++)
        d[i] = INF;
    d[S] = 0;
    queue<int> q;
    q.push(S);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto y : g[k])
        {
            if (rem(y) == 0)
                continue;
            int to = e[y].y;
            if (d[to] > d[k] + 1)
            {
                q.push(to);
                d[to] = d[k] + 1;
            }
        }
    }
    return d[T] < INF;
}

int dfs(int x, int mx)
{
    if (x == T || mx == 0)
        return mx;
    int sum = 0;
    for (; lst[x] < g[x].size(); lst[x]++)
    {
        int num = g[x][lst[x]];
        int r = rem(num);
        if (r == 0)
            continue;
        int to = e[num].y;
        if (d[to] != d[x] + 1)
            continue;
        int pushed = dfs(to, min(r, mx));
        if (pushed > 0)
        {
            e[num].f += pushed;
            e[num ^ 1].f -= pushed;
            sum += pushed;
            mx -= pushed;
            if (mx == 0)
                return sum;
        }
    }
    return sum;
}

int Dinic()
{
    int ans = 0;
    while (bfs())
    {
        for (int i = 0; i < V; i++)
            lst[i] = 0;
        int f = 0;
        do
        {
            f = dfs(S, INF);
            ans += f;
        } while (f > 0);
    }
    return ans;
}

int main()
{
    scanf("%d %d %d %d", &n1, &n2, &m, &q);
    S = n1 + n2;
    T = S + 1;
    V = T + 1;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        es[make_pair(x, y)] = i + 1;
        add_edge(x, n1 + y, 1);
    }
    for (int i = 0; i < n1; i++)
        add_edge(S, i, 1);
    for (int i = 0; i < n2; i++)
        add_edge(i + n1, T, 1);
    Dinic();
    bfs();
    vector<int> vertex_cover;
    map<int, int> index;
    set<int> matched;
    long long sum = 0;
    for (int i = 0; i < n1; i++)
        if (d[i] == INF)
        {
            vertex_cover.push_back(i + 1);
            for (auto ei : g[i])
                if (e[ei].f == 1)
                {
                    int idx = es[make_pair(i, e[ei].y - n1)];
                    index[i + 1] = idx;
                    sum += idx;
                    matched.insert(idx);
                }
        }
    for (int i = 0; i < n2; i++)
        if (d[i + n1] != INF)
        {
            vertex_cover.push_back(-(i + 1));
            for (auto ei : g[i + n1])
                if (e[ei].f == -1)
                {
                    int idx = es[make_pair(e[ei].y, i)];
                    index[-(i + 1)] = idx;
                    sum += idx;    
                    matched.insert(idx);
                }
        }
    for (int i = 0; i < q; i++)
    {
        int s;
        scanf("%d", &s);
        if (s == 1)
        {
            puts("1");
            int v = vertex_cover.back();
            vertex_cover.pop_back();
            printf("%dn", v);
            sum -= index[v];
            matched.erase(index[v]);
            printf("%lldn", sum);
        }
        else
        {
            printf("%dn", (int)matched.size());
            for(auto x : matched) printf("%d ", x);
            puts("");
        }   
        fflush(stdout);
    }
}
```
