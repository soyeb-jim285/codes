# Tutorial

[1899A — Game with Integers](../problems/A._Game_with_Integers.md)

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), development: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX").

 **Editorial**Consider the remainder from dividing n by 3 before the first move. If it is equal to 1 or 2, then Vanya can make the number n divisible by 3 after the first move, i.e. he wins. Let the remainder be 0, then Vanya must change the number after which it will not be divisible by 3. Then Vova can do the same operation as Vanya and make it divisible by 3 again. This will go on indefinitely, so Vova wins.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    if (n % 3) {
        cout << "Firstn";
    } else {
        cout << "Secondn";
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1899B — 250 Thousand Tons of TNT](../problems/B._250_Thousand_Tons_of_TNT.md)

Idea: [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv"), development: [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv").

 **Editorial**Solution #1:

Since k is a divisor of n, there are O(3√n) such k. We can enumerate all k, calculate a given value in O(n), and take the maximum of them. Total complexity — O(n⋅3√n).

Solution #2:

Without using the fact that k is a divisor of n, we can simply loop over k and then calculate the values using prefix sums, and at the end check that there are exactly k elements in each segment. Such a solution works in O(n1+n2+n3+⋯+nn)=O(nlogn).

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define all(x) x.begin(), x.end()
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = -1;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            ll mx = -1e18, mn = 1e18;
            for (int i = 0; i < n; i += d) {
                ll sm = 0;
                for (int j = i; j < i + d; ++j) {
                    sm += a[j];
                }
                mx = max(mx, sm);
                mn = min(mn, sm);
            }
            ans = max(ans, mx - mn);
        }
    }
    cout << ans << 'n';
}
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}
```
[1899C — Yarik and Array](../problems/C._Yarik_and_Array.md)

Idea: [meowcneil](https://codeforces.com/profile/meowcneil "Grandmaster meowcneil"), development: [meowcneil](https://codeforces.com/profile/meowcneil "Grandmaster meowcneil").

 **Editorial**There are "bad" positions in the array, i.e., those on which two numbers of the same parity are next to each other. Note that all matching segments cannot contain such positions, in other words, we need to solve the problem of finding a sub segment with maximal sum on some number of non-intersecting sub segments of the array, the boundaries of which are between two neighboring elements of the same parity.

The problem of finding a sub segment with maximal sum can be solved using the classical algorithm with keeping minimal prefix sum on the prefix. The problem can be solved in a single pass over the array by simply dropping the keeped values when we are in a bad position.

Total complexity — O(n).

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = a[0];
    int mn = min(0, a[0]), sum = a[0];
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] % 2) == abs(a[i - 1] % 2)) {
            mn = 0;
            sum = 0;
        }
        sum += a[i];
        ans = max(ans, sum - mn);
        mn = min(mn, sum);
    }
    cout << ans << endl;
}
 
int main() {
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
```
[1899D — Yarik and Musical Notes](../problems/D._Yarik_and_Musical_Notes.md)

Idea: [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv"), development: [molney](https://codeforces.com/profile/molney "Master molney").

 **Editorial**The problem requires to count the number of pairs of indices (i,j) (i<j) such that (2a)(2b)=(2b)(2a), where a=bi,b=bj. Obviously, when a=b this equality is satisfied. Let a≠b, then rewrite the equality: (2a)(2b)=(2b)(2a)⇔2(a⋅2b)=2(b⋅2a)⇔a⋅2b=b⋅2a⇔ab=2a2b. Obviously, a and b must differ by powers of two, otherwise the equality cannot be satisfied, since the ratio of powers of two is on the right. Without loss of generality, suppose that b=a⋅2k (k>0), then the equation takes the form aa⋅2k=2a2a⋅2k⇔12k=12(2k−1)a⇔2k=2(2k−1)a. If k=1, then a=1, b=2. If k>1, then 2k−1>k, and so the equality cannot be satisfied.

Thus, the only possible cases where the equality is satisfied are if bi=bj or bi=1,bj=2 (and vice versa). The number of such pairs can be counted for O(nlogn).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	ll ans = 0;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		ans += cnt[a[i]];
		if (a[i] == 1) ans += cnt[2];
		else if (a[i] == 2) ans += cnt[1];
		cnt[a[i]]++;
	}
	cout << ans << "n";
}
 
signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}
```
[1899E — Queue Sort](../problems/E._Queue_Sort.md)

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), development: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya").

 **Editorial**Consider the position of the first minimum in the array, let it be equal to k. All elements standing on positions smaller than k are strictly greater, so we must apply operations to them, because otherwise the array will not be sorted. Suppose we have applied operations to all such elements, they have taken some positions after k (since they are strictly greater than the minimum), i.e. now the minimum element that moved from position k is at the beginning of the array. If we apply the operation to it, it will return to its current position, since it is less than or equal to all elements of the array, i.e. the array will not change.

Thus, after the array has its minimum at the beginning, it is useless to apply operations, and all the operations applied before that will move the element from the beginning of the array to some position after the position of the first minimum.

Then, if the part of the array after the position k is not sorted, the answer is −1, because it is impossible to change the order of elements in it. Otherwise, the answer is equal to the number of elements standing before the first minimum, since the operation must be applied to them and they will be in the right place in the right part. Total complexity — O(n).

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    fm = 0
    for i in range(n):
        if a[i] < a[fm]:
            fm = i
    for i in range(fm + 1, n):
        if a[i] < a[i - 1]:
            print(-1)
            return
    print(fm)
 
 
for _ in range(int(input())):
    solve()
```
[1899F — Alex's whims](../problems/F._Alex's_whims.md)

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), development: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv").

 **Editorial**This problem can be solved in several similar ways, one of them is given below. First, it is most convenient to take a bamboo — vertices from 1 to n connected in order. Then, we will maintain the following construction. At each moment of time, vertices 1 and 2 will be connected by an edge, from vertex 2 there will be at most two branches, which are sequentially connected vertices (bamboo). Thus, at any given time there will be at most three leaves in the tree, one of which is vertex 1.

We will maintain vertices from two branches in two arrays. Then, let the current number from the query be d. If the distance from any of the leaves to vertex 1 is d, we don't need to perform the operation. Otherwise, let's do the operation so that the distance from a leaf from, for example, the first branch to vertex 1 is equal to d. If the current distance is greater than d, then we remove the extra vertices to the end of the second branch, and otherwise we add the necessary ones from the end of the second branch. Thus, after each operation, the distance from vertex 1 to some of the sheets will be equal to d.

Transformations can be done by completely moving vertices, then the total complexity — O(nq).

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> b1, b2;
		for (int i = 0; i < n; ++i) {
			b1.push_back(i);
		}
		b2.push_back(1);
		for (int i = 1; i < n; ++i) {
			cout << i << ' ' << i + 1 << endl;
		}
		int q;
		cin >> q;
		while (q--) {
			int d;
			cin >> d;
			d++;
			if (b1.size() == d) {
				cout << "-1 -1 -1n";
			} else if (b1.size() < d) {
				d = d - b1.size();
				vector<int> qq(b2.end() - d, b2.end());
				int u = b2[b2.size() - d];
				int v1 = b2[b2.size() - d - 1];
				int v2 = b1.back();
				cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << 'n';
				for (int i = 0; i < d; ++i) b2.pop_back();
				for (auto i : qq) b1.push_back(i);
			} else {
				d = b1.size() - d;
				vector<int> qq(b1.end() - d, b1.end());
				int u = b1[b1.size() - d];
				int v1 = b1[b1.size() - d - 1];
				int v2 = b2.back();
				cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << 'n';
				for (int i = 0; i < d; ++i) b1.pop_back();
				for (auto i : qq) b2.push_back(i);
			}
		}
	}
}
```
[1899G — Unusual Entertainment](../problems/G._Unusual_Entertainment.md)

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), development: [Sokol080808](https://codeforces.com/profile/Sokol080808 "Master Sokol080808").

 **Editorial**Let's start the depth-first search from vertex 1 and write out the entry and exit times for each vertex. Then, the fact that vertex b is a descendant of vertex a is equivalent to the fact that tin[a]≤tin[b]≤tout[b]≤tout[b]≤tout[a], where tin and tout — entry and exit times, respectively. Then, let us create an array a, where ai=tin[pi], then the problem is reduced to checking that on the segment c l through r in array a there is at least one number belonging to the segment [tin[x];tout[x]]. This can be done, for example, using Merge Sort Tree, then the total complexity will be O(nlogn+qlog2n).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
struct SegmentTree {
    int n;
    vector<vector<int>> tree;
 
    void build(vector<int> &a, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = {a[l]};
            return;
        }
 
        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        merge(all(tree[2 * x + 1]), all(tree[2 * x + 2]), back_inserter(tree[x]));
    }
 
    SegmentTree(vector<int>& a) : n(a.size()) {
        int SIZE = 1 << (__lg(n) + bool(__builtin_popcount(n) - 1));
        tree.resize(2 * SIZE - 1);
        build(a, 0, 0, n);
    }
 
    int count(int lq, int rq, int mn, int mx, int x, int l, int r) {
        if (rq <= l || r <= lq) return 0;
        if (lq <= l && r <= rq) return lower_bound(all(tree[x]), mx) - lower_bound(all(tree[x]), mn);
 
        int m = (l + r) / 2;
        int a = count(lq, rq, mn, mx, 2 * x + 1, l, m);
        int b = count(lq, rq, mn, mx, 2 * x + 2, m, r);
        return a + b;
    }
 
    int count(int lq, int rq, int mn, int mx) {
        return count(lq, rq, mn, mx, 0, 0, n);
    }
};
 
vector<vector<int>> g;
 
vector<int> tin, tout;
int timer;
void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = timer;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    
    g.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    timer = 0;
    tin.resize(n);
    tout.resize(n);
    dfs(0, -1);
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = tin[p[i] - 1];
    SegmentTree ST(a);
 
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; x--;
        if (ST.count(l, r, tin[x], tout[x])) {
            cout << "YESn";
        } else {
            cout << "NOn";
        }
    }
}
 
int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
        if(tests > 0) cout << "n";
    }
    return 0;
}
```
