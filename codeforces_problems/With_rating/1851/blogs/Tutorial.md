# Tutorial

[1851A - Escalator Conversations](../problems/A._Escalator_Conversations.md "Codeforces Round 888 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1851A - Escalator Conversations](../problems/A._Escalator_Conversations.md "Codeforces Round 888 (Div. 3)")

For each person in the array h, we will check the conditions. First, the height should not be the same as Vlad's height, then their difference should be divisible by k, and finally, the difference between the extreme steps should not exceed the difference in height. If these requirements are met, there will be steps where Vlad can talk to a person with that height.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n,m,k,H; cin >> n >> m >> k >> H;
    int ans = 0;
    forn(i, n) {
        int x; cin >> x;
        ans += (H != x) && abs(H - x) % k == 0 && abs(H-x) <= (m-1) * k;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1851B - Parity Sort](../problems/B._Parity_Sort.md "Codeforces Round 888 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1851B - Parity Sort](../problems/B._Parity_Sort.md "Codeforces Round 888 (Div. 3)")

Let's copy array a to array b. Then sort array b. Let's check that for each 1≤i≤n it is satisfied that (aimod2)=(bimod2), where mod is the operation of taking the remainder from division. In other words, we need to check that in the sorted array b, the element at the i-th position has the same parity as the element at the i-th position in the unsorted array a.

This is true because any array can be sorted using at most n2 operations, in which any two elements are swapped. Consequently, if the parity of the elements in the sorted array is preserved, then the even and odd subsequences of the elements can be sorted separately, and the answer is YES. If the parity of the elements is not preserved after sorting, the answer is NO.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        if((a[i] % 2) != (b[i] % 2)) return false;
    }
    return true;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << (solve() ? "YES" : "NO") << "n";
    }
    return 0;
}
```
[1851C - Tiles Comeback](../problems/C._Tiles_Comeback.md "Codeforces Round 888 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1851C - Tiles Comeback](../problems/C._Tiles_Comeback.md "Codeforces Round 888 (Div. 3)")

Since the path must start in the first tile and end in the last tile, it is enough to construct a path consisting of 1 or 2 blocks of length k to solve the problem.

If c1=cn, then we need to check that there are k−2 tiles of colour c0 between the first and the last tile. If this condition is satisfied, then the tiles that are found together with the first and the last tile form the path p, and the answer is — YES. Otherwise — the answer is NO.

If c1≠cn we can solve the problem by the method of two pointers: let's move from the two ends of the array c to the middle, counting the number of tiles of colour c1 on the left and tiles of colour cn on the right. If the pointers meet no later than k tiles of the desired colours are found on both sides, the answer is — YES, otherwise — NO.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;

bool solve(){
    int n, k;
    cin >> n >> k;
    vector<int>c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    int left = 0, right = 0, i = 0, j = n - 1;
    int k_left = k, k_right = k;

    if (c[0] == c[n - 1]){
        k_left = k / 2;
        k_right = k - k_left;
    }
    for(; i < n && left < k_left; i++){
        if(c[i] == c[0]) left++;
    }
    for(; j >= 0 && right < k_right; j--){
        if(c[j] == c[n - 1]) right++;
    }
    return (i - 1) < (j + 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << (solve() ? "YES" : "NO") << "n";
    }

}
```
[1851D - Prefix Permutation Sums](../problems/D._Prefix_Permutation_Sums.md "Codeforces Round 888 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), prepared: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1851D - Prefix Permutation Sums](../problems/D._Prefix_Permutation_Sums.md "Codeforces Round 888 (Div. 3)")

To begin with, let's learn how to reconstruct an array from its prefix sum array. This can be done by calculating the differences between adjacent elements.

If the element n∗(n+1)2 is missing from the array, we will add it and check if the array corresponds to some permutation.

Otherwise, there is a missing element in the middle or at the beginning of the array.

Let's count the occurrences of each difference between adjacent elements. Obviously, we should have one extra number and 2 missing numbers.

If the count of differences occurring at least 2 times is at least 2, the answer is NO.

The answer is also NO if any difference occurs at least 3 times.

Otherwise, we check that exactly 2 distinct numbers are missing, and their sum is equal to the only duplicate.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

ll n;

bool isPermutation(vector<ll> a) {
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 0 || a[i] > n) {
            return false;
        }
    }
    set<ll> s(a.begin(), a.end());
    return s.size() == n;
}

vector<ll> prefSumToArray(vector<ll> p) {
    vector<ll> res(n);
    res[0] = p[0];
    for (int i = 1; i < n; ++i) {
        res[i] = p[i] - p[i - 1];
    }
    return res;
}

void solve() {
    cin >> n;
    vector<ll> a(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        cin >> a[i];
    }
    ll x = n * (n + 1) / 2;
    if (a.back() != x) {
        a.push_back(x);
        vector<ll> b = prefSumToArray(a);
        if (isPermutation(b)) {
            cout << "YESn";
        } else {
            cout << "NOn";
        }
        return;
    }
    map<ll, int> cnt;
    cnt[a[0]]++;
    for (int i = 1; i < n - 1; ++i) {
        cnt[a[i] - a[i - 1]]++;
    }
    vector<int> cntGt1;
    for (auto p: cnt) {
        if (p.second > 1) {
            cntGt1.push_back(p.first);
        }
    }
    if (cntGt1.size() > 1) {
        cout << "NOn";
        return;
    }
    if (cntGt1.size() == 1) {
        int x1 = cntGt1[0];
        if (cnt[x1] > 2) {
            cout << "NOn";
            return;
        }
    }
    vector<int> cnt0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            cnt0.push_back(i);
        }
    }
    if (cnt0.size() != 2) {
        cout << "NOn";
        return;
    }
    cout << "YESn";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}
```
[1851E - Nastya and Potions](../problems/E._Nastya_and_Potions.md "Codeforces Round 888 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1851E - Nastya and Potions](../problems/E._Nastya_and_Potions.md "Codeforces Round 888 (Div. 3)")

To begin with, let's note that potions of types $p1, p2, \dots, p_k$ are essentially free, so we can replace their costs with $0$.

Let $ans[i]$ be the answer for the $i$-th potion. Each potion can be obtained in one of two ways: by buying it or by mixing it from other potions. For mixing, we obtain all the required potions at the minimum cost. That is, if there is a way to mix a potion of type $i$, then the answer for it is either $c_i$ or the sum of answers for all $e_i$. Since the graph in the problem does not have cycles, this can be done by a simple depth-first search.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> dp;
vector<bool> used;
vector<vector<int>> sl;

int get(int v){
    if(used[v]){
        return dp[v];
    }
    used[v] = true;
    int s = 0;
    for(int u: sl[v]){
        s += get(u);
    }
    if(!sl[v].empty()) dp[v] = min(dp[v], s);
    return dp[v];
}

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    dp.resize(n);
    used.assign(n, false);
    sl.assign(n, vector<int>(0));
    for(int &e: dp) cin >> e;
    for(int i = 0; i < k; ++i){
        int e;
        cin >> e;
        dp[--e] = 0;
    }
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        sl[i].resize(m);
        for(int &e: sl[i]){
            cin >> e;
            --e;
        }
    }
    for(int i = 0; i < n; ++i){
        get(i);
    }
    for(int e: dp) cout << e << " ";
}

bool multi = true;

signed main() {
    int t = 1;
    if(multi) cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "n";
    }
    return 0;
}
```
[1851F - Lisa and the Martians](../problems/F._Lisa_and_the_Martians.md "Codeforces Round 888 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), prepared: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1851F - Lisa and the Martians](../problems/F._Lisa_and_the_Martians.md "Codeforces Round 888 (Div. 3)")

Solution 1. Let's use the data structure called a bitwise trie. Fix some $a_i$, where all $a_j$ for $j < i$ have already been added to the trie. We will iterate over the bits in $a_i$ from the $(k - 1)$-th bit to the $0$-th bit. Since $2^t > 2^{t - 1} + 2^{t - 2} + \ldots + 2 + 1$, if there exists $a_j$ with the same bit at the corresponding position in $a_i$, we will go into that branch of the trie and append $1 - b$ to the corresponding bit $x$. Otherwise, our path is uniquely determined. When we reach a leaf, the bits on the path will correspond to the optimal number $a_j$ for $a_i$. The complexity of this solution is $O(n k)$.

Solution 2. Sort $a_1, a_2, \ldots, a_n$ in non-decreasing order. We will prove that the answer is some pair of adjacent numbers. Let the answer be numbers $a_i, a_j$ ($j - i > 1$). If $a_i = a_j$, then $a_i = a_{i + 1}$. Otherwise, they have a common prefix of bits, after which there is a differing bit. That is, at some position $t$, $a_i$ has a $0$ and $a_j$ has a $1$. Since $j - i > 1$, $a_{i + 1}$ can have either $0$ or $1$ at this position, but in the first case it is more advantageous to choose $a_i, a_{i + 1}$ as the answer, and in the second case it is more advantageous to choose $a_{i + 1}, a_j$ as the answer. The complexity of this solution is $O(n \log n)$.

Solution 3 (secret). The problem can be easily reduced to finding a pair of numbers with the minimum $\oplus$. If you don't know about the bitwise trie and the sorting trick, such a problem can be solved using AVX instructions. The complexity of this solution is $O(\frac{n^2}{2 \cdot 8})$.

 **Solution**
```cpp
#include <bits/stdc++.h>
#define all(arr) arr.begin(), arr.end()

using namespace std;

const int MAXN = 200200;
const int MAXK = 30;
const int MAXMEM = MAXN * MAXK;

mt19937 rng(07062006);

struct node {
	node *chi[2] {nullptr};
	int sz = 0, id = -1;
};

int n, k;
int arr[MAXN];
node *mem = new node[MAXMEM];
node *root, *mpos;

void add_num(node* &v, int val, int i, int id) {
	if (v == nullptr) *(v = mpos++) = node();
	v->sz++;
	if (i == -1) {
		v->id = id;
		return;
	}
	add_num(v->chi[val >> i & 1], val, i - 1, id);
}

int down(node *v, int val, int i, int &x, int &jans) {
	if (i == -1) {
		jans = v->id;
		return 0;
	}
	int b = val >> i & 1;
	if (v->chi[b])
		return down(v->chi[b], val, i - 1, x ^= ((1 ^ b) << i), jans) | (1 << i);
	return down(v->chi[b ^ 1], val, i - 1, x ^= ((rng() & 1) << i), jans);
}

void build() {
	root = nullptr;
	mpos = mem;
	add_num(root, *arr, k - 1, 0);
}

tuple<int, int, int> solve() {
	int ians = 0, jans = 1, xans = 0;
	for (int i = 1; i < n; ++i) {
		int x = 0, j = -1;
		int cur = down(root, arr[i], k - 1, x, j);
		if (cur > ((arr[ians] ^ xans) & (arr[jans] ^ xans)))
			ians = j, jans = i, xans = x;
		add_num(root, arr[i], k - 1, i);
	}
	return {ians, jans, xans};
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		build();
		auto [ians, jans, xans] = solve();
		cout << ++ians << ' ' << ++jans << ' ' << xans << endl;
	}
}
```
[1851G - Vlad and the Mountains](../problems/G._Vlad_and_the_Mountains.md "Codeforces Round 888 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1851G - Vlad and the Mountains](../problems/G._Vlad_and_the_Mountains.md "Codeforces Round 888 (Div. 3)")

Let's consider the change in energy when traveling from $i \rightarrow j \rightarrow k$, $h_i - h_j + h_j - h_k = h_i - h_k$, it can be seen that this is the difference between the heights of the first and last mountains on the path. In other words, from vertex $a$, it is possible to reach any vertex for which there is a path that does not pass through vertices with a height greater than $h_a+e$.

Therefore, for each query, it is necessary to construct a component from vertex $a$, in which all vertices with a height not greater than $h_a + e$ are included, and check if vertex $b$ lies within it. To do this efficiently, let's sort the queries by $h_a + e$, and the edges of the graph by $\max(h_u, h_v)$, and maintain a disjoint set data structure (DSU).

Before each query, add all edges that have not been added yet and their $\max(h_u, h_v)$ is not greater than $h_a+e$ for that specific query. After this, it remains to only check if vertices $a$ and $b$ belong to the same connected component.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

struct dsu{
    vector<int> p, lvl;

    dsu(int n){
        p.resize(n);
        lvl.assign(n, 0);
        iota(all(p), 0);
    }

    int get(int i){
        if(i == p[i]) return i;
        return p[i] = get(p[i]);
    }

    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a == b){
            return false;
        }
        if(lvl[a] < lvl[b])swap(a, b);
        p[b] = a;
        if(lvl[a] == lvl[b]){
            ++lvl[a];
        }
        return true;
    }

    bool reachable(int a, int b){
        return get(a) == get(b);
    }
};

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> h(n);
    for(auto &e: h) cin >> e.x;
    for(int i = 0; i < n; ++i){
        h[i].y = i;
    }
    dsu graph(n);
    vector<vector<int>> sl(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        if(h[u].x > h[v].x) sl[u].emplace_back(v);
        else sl[v].emplace_back(u);
    }
    int q;
    cin >> q;
    vector<pair<pair<int, int>, pair<int, int>>> req(q);
    for(auto &e: req){
        cin >> e.y.x >> e.y.y >> e.x.x;
        --e.y.x, --e.y.y;
        e.x.x += h[e.y.x].x;
    }
    for(int i = 0; i < q; ++i){
        req[i].x.y = i;
    }

    sort(all(h));
    sort(all(req));
    vector<bool> ans(q);
    int j = 0;
    for(auto e: req){
        while (j < n && h[j].x <= e.x.x) {
            for(int u: sl[h[j].y]){
                graph.unite(h[j].y, u);
            }
            ++j;
        }
        ans[e.x.y] = graph.reachable(e.y.x, e.y.y);
    }
    for(bool e: ans) cout << (e? "YES": "NO") << "n";
}

bool multi = true;

signed main() {
    int t = 1;
    if(multi) cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        if(i < t) cout << "n";
    }
    return 0;
}
```
