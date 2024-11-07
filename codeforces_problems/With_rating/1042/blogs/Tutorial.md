# Tutorial

[1042A - Benches](../problems/A._Benches.md "Codeforces Round 510 (Div. 2)")

 **Tutorial**
### [1042A - Benches](../problems/A._Benches.md "Codeforces Round 510 (Div. 2)")

The maximum value of $k$ should be determined in the following way: let's find the maximum number of people already sitting on the same bench (i. e. the maximum value in the array $a$). Let this number be $t$. Then if all additional $m$ people will seat on this bench, we will get the maximum value of $k$, so the answer is $t + m$.

To determine the minimum value of $k$ let's perform $m$ operations. During each operation we put a new person on the bench currently having minimum number of people occupying it. The answer is the maximum number of people on the bench after we perform this operation for each of $m$ newcomers.

 **Solution**
```cpp
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

const int N = 100 + 13;

int n, m;
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans2 = *max_element(a, a + n) + m;
    for (int it = 0; it < m; it++) {
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (pos == -1 || a[i] < a[pos]) {
                pos = i;
            }
        }
        assert(pos != -1);
        a[pos]++;
    }
    int ans1 = *max_element(a, a + n);
    cout << ans1 << ' ' << ans2 << endl;
}
```
[1042B - Vitamins](../problems/B._Vitamins.md "Codeforces Round 510 (Div. 2)")

 **Tutorial**
### [1042B - Vitamins](../problems/B._Vitamins.md "Codeforces Round 510 (Div. 2)")

Let's calculate the minimum cost of the juice containing only the vitamin "A", only the vitamin "B" and only the vitamin "C". Also let's calculate the minimum cost of the juice containing all three vitamins.

If there is at least one juice containing only the vitamin "A", at least one juice containing only the vitamin "B" and at least one juice containing only the vitamin "C", let's update the answer with the sum of the corresponding minimum costs.

If there is at least one juice containing all three vitamins, let's update the answer with its cost.

Only one case remains — when Petya has to buy two juices. Let's iterate over all pairs of juices using nested loops. Let the index of the first juice we iterate be $a$, the index of the second juice be $b$. We have to check that the strings $s_a$ and $s_b$ contain all three letters "A", "B", "C" (i.e. these juices contain all the vitamins). If they do, let's update the answer with the value $c_a + c_b$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
map<string, int> was;

inline void read() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		string s;
		cin >> c >> s;
		sort(s.begin(), s.end());
		if (was.count(s) == 0) {
			was[s] = c;
		} else {
			was[s] = min(was[s], c);
		}
	}
}

inline int getC(string a, string b) {
 	if (!was.count(a) || !was.count(b)) {
 		return INF;
 	}
 	return was[a] + was[b];
}

inline void solve() {
	int ans = INF;
	if (was.count("A") && was.count("B") && was.count("C")) {
		ans = was["A"] + was["B"] + was["C"];
	}
    if (was.count("ABC")) {
    	ans = min(ans, was["ABC"]);
    }
    ans = min(ans, getC("AB", "C"));
    ans = min(ans, getC("A", "BC"));
    ans = min(ans, getC("AC", "B"));
    ans = min(ans, getC("AB", "BC"));
    ans = min(ans, getC("AC", "BC"));
    ans = min(ans, getC("AC", "AB"));
    if (ans == INF) {
    	ans = -1;
    }
    cout << ans << endl;
}

int main () {
    read();
    solve();
}
```
[1042C - Array Product](../problems/C._Array_Product.md "Codeforces Round 510 (Div. 2)")

 **Tutorial**
### [1042C - Array Product](../problems/C._Array_Product.md "Codeforces Round 510 (Div. 2)")

There are several cases in the problem. Let the number of zeroes in the array be $cntZero$ and the number of negative elements be $cntNeg$. Also let $maxNeg$ be the position of the maximum negative element in the array, or $-1$ if there are no negative elements in the array.

Let the answer part be the product of all the numbers which will be in the answer and the removed part be the product of all the numbers which will be removed by the second type operation.

The first case is the following: $cntZero = 0$ and $cntNeg = 0$. Then the answer part is the product of all the numbers in the array. The removed part is empty.

The second case is the following: $cntNeg$ is odd. Then the answer part is the product of all the numbers in the array except all zeroes and $a_{maxNeg}$. The removed part is the product of all zeroes and $a_{maxNeg}$.

And the third case is the following: $cntNeg$ is even. Then the answer part is the product of all the numbers in the array except all zeroes. The removed part is the product of all zeroes in the array (be careful in case $cntNeg = 0$ and $cntZero = n$).

Be careful with printing the answer because my first solution printed $n$ operations instead of $n-1$ operations in case $cntZero = n$ or $cntZero = n-1$ and $cntNeg = 1$.

And the funniest part of this problem is the checker. The first thing I thought was "Well, I want to write a fair checker on this problem". I did exactly that. What do we need? Split all the numbers in the array into two parts? Okay, let's write DSU to do that. What's next? Multiply $2 \cdot 10^5$ numbers from $1$ to $10^9$? Okay, let's use FFT and Divide and Conquer! And the last part is the comparing two numbers of length about $2 \cdot 10^6$. So writing this checker was pretty easy problem. But the coordinator didn't like that and I replaced it with very easy checker which uses some ideas from the solution. :( 

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	int cntneg = 0;
	int cntzero = 0;
	vector<int> used(n);
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			used[i] = 1;
			++cntzero;
		}
		if (a[i] < 0) {
			++cntneg;
			if (pos == -1 || abs(a[pos]) > abs(a[i]))
				pos = i;
		}
	}
	if (cntneg & 1)
		used[pos] = 1;
		
	if (cntzero == n || (cntzero == n - 1 && cntneg == 1)) {
		for (int i = 0; i < n - 1; ++i)
			printf("1 %d %dn", i + 1, i + 2);
		return 0;
	}
	
	int lst = -1;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			if (lst != -1) printf("1 %d %dn", lst + 1, i + 1);
			lst = i;
		}
	}
	if (lst != -1) printf("2 %dn", lst + 1);
	
	lst = -1;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			if (lst != -1) printf("1 %d %dn", lst + 1, i + 1);
			lst = i;
		}
	}
	
	return 0;
}
```
[1042D - Petya and Array](../problems/D._Petya_and_Array.md "Codeforces Round 510 (Div. 2)")

 **Tutorial**
### [1042D - Petya and Array](../problems/D._Petya_and_Array.md "Codeforces Round 510 (Div. 2)")

Let's reformulate the problem. Now the problem is to calculate the difference between the prefix sums to the right border and to the left border instead of the sum on the segment.

Let $pref[i] = \sum\limits_{j=1}^{i} a[j]$, a $pref[0] = 0$.

Then the answer to the problem is $\sum\limits_{L=1}^{n}\sum\limits_{R=L}^{n} pref[R] - pref[L - 1] < t$. 

It's easy to see that the answer for the fixed $L$ is $\sum\limits_{R=L}^{n} pref[R] < t + pref[L - 1]$. We can calculate this formula using some data structure which allows us to get the number of elements less than given and set the value at some position. For example, segment tree or BIT (Fenwick tree).

 **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n;
long long T;
int a[N];
int f[N];

void upd(int x){
	for (int i = x; i < N; i |= i + 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i];
	return res;
}

int main() {
	scanf("%d%lld", &n, &T);
	forn(i, n)
		scanf("%d", &a[i]);
	
	vector<long long> sums(1, 0ll);
	long long pr = 0;
	forn(i, n){
		pr += a[i];
		sums.push_back(pr);
	}
	
	sort(sums.begin(), sums.end());
	sums.resize(unique(sums.begin(), sums.end()) - sums.begin());
	
	long long ans = 0;
	pr = 0;
	upd(lower_bound(sums.begin(), sums.end(), 0ll) - sums.begin());
	
	forn(i, n){
		pr += a[i];
		
		int npos = upper_bound(sums.begin(), sums.end(), pr - T) - sums.begin();
		ans += (i + 1 - get(npos - 1));
		
		int k = lower_bound(sums.begin(), sums.end(), pr) - sums.begin();
		upd(k);
	}
	
	printf("%lldn", ans);
	return 0;
}
```
[1042E - Vasya and Magic Matrix](../problems/E._Vasya_and_Magic_Matrix.md "Codeforces Round 510 (Div. 2)")

 **Tutorial**
### [1042E - Vasya and Magic Matrix](../problems/E._Vasya_and_Magic_Matrix.md "Codeforces Round 510 (Div. 2)")

Let's iterate over all the elements of the matrix in order of increasing their values and calculate the expected value for these elements to solve the problem. Suppose that now we consider the element at intersection of the $R$-th row and the $C$-th column. Let the elements having value less than the value of the current element be $(r_1, c_1), (r_2, c_2), \dots , (r_k, c_k)$, where $r_i$ is the row of the $i$-th element and $c_i$ is the column of the $i$-th element.

Then the expected value for the current element can be calculated as follows: $\frac{\sum\limits_{i=1}^{k}{(ev_i + (R - r_i)^2 + (C - c_i)^2)}}{k}$, where $ev_i$ is the expected value of the $i$-th element. We can rewrite the formula to the following form using equivalent transforms: $\frac{\sum\limits_{i=1}^{k}{ ev_i }}{k} + R^2 + C^2 + \frac{\sum\limits_{i=1}^{k}{ {r_i}^2 }}{k} + \frac{\sum\limits_{i=1}^{k}{ {c_i}^2 }}{k} - 2\frac{\sum\limits_{i=1}^{k}{ Rr_i }}{k} -2\frac{\sum\limits_{i=1}^{k}{ Cc_i }}{k}$.

So we need to maintain five sums for the elements having value less than current element: sum of their values, sum of their row indices, sum of their column indices, sum of squares of their row indices and sum of squares of their column indices. We can maintain all these sums if we will iterate over all the elements continuously in order of increasing their values.

It is also necessary to note that we need to process all the elements having equal values at once and recalculate all the sums right after calculating the expected values for these elements.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 1009;

int mul(int a, int b){
	return int(a * 1LL * b % MOD);
}

void upd(int &a, int b){
	a += b;
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
}

int bp(int a, int n){
	int res = 1;
	for(; n > 0; n >>= 1){
		if(n & 1) res = mul(res, a);
		a = mul(a, a);
	}
	
	return res;
}

int inv(int a){
	int ia = bp(a, MOD - 2);
	assert(mul(a, ia) == 1);
	return ia;
}

int n, m;
int a[N][N];
int dp[N][N];
int si, sj;

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	scanf("%d %d", &si, &sj);
	--si, --sj;
	
	vector <pair<int, pair<int, int> > > v;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			v.push_back(make_pair(a[i][j], make_pair(i, j)));

	sort(v.begin(), v.end());
	int l = 0;
	int sumDP = 0, sumX = 0, sumY = 0, sumX2 = 0, sumY2 = 0;
	while(l < int(v.size())){
		int r = l;
		while(r < int(v.size()) && v[r].first == v[l].first) ++r;
		
		int il = -1;
		if(l != 0) il = inv(l);
		for(int i = l; i < r; ++i){
			int x = v[i].second.first, y = v[i].second.second;
			if(il == -1){
				dp[x][y] = 0;
				continue;
			}
			
			
			upd(dp[x][y], mul(sumDP, il));
			
			upd(dp[x][y], mul(x, x));
			upd(dp[x][y], mul(y, y));
			
			upd(dp[x][y], mul(sumX2, il));
			upd(dp[x][y], mul(sumY2, il));
			
			upd(dp[x][y], mul(mul(-x - x, sumX), il));
			upd(dp[x][y], mul(mul(-y - y, sumY), il));		
		}
		
		for(int i = l; i < r; ++i){
			int x = v[i].second.first, y = v[i].second.second;
			
			upd(sumDP, dp[x][y]);
			
			upd(sumX2, mul(x, x));
			upd(sumY2, mul(y, y));
			
			upd(sumX, x);
			upd(sumY, y);
		}
		
		l = r;
		
	}
	
	printf("%dn", dp[si][sj]);
	return 0;
}
```
[1042F - Leaf Sets](../problems/F._Leaf_Sets.md "Codeforces Round 510 (Div. 2)")

 **Tutorial**
### [1042F - Leaf Sets](../problems/F._Leaf_Sets.md "Codeforces Round 510 (Div. 2)")

Let's use the following technique, which is pretty common for tree problems. Let the root of the tree be some none-leaf vertex. Run dfs from the root and let the vertex yield all the resulting sets in the optimal answer for its subtree. For each vertex you iterate over its children and merge the yielded sets.

The first thing to notice is that you only need the deepest vertex from each set to check its mergeability. Let's call the distance between the vertex $v$ and the deepest vertex in some set $u$ in its subtree $d_u$. Now two sets $a$ and $b$ can be merged only if $d_a + d_b \le k$. Moreover, $d$ value of the resulting the set is $max(d_a, d_b)$.

The time has come to reveal the merging process. We will heavily rely on a fact that the resulting $d$ doesn't change after merging. Let's merge the sets with the smallest $d$ to any other possible sets. 

Now we can deduce the small-to-large solution from it. Let the vertex yield the whole multiset of the depths of the resulting sets. Now take the child with the largest number of resulting sets and add all the values from the other children to its multiset. Then merge the maximum possible number of sets and yield the result. The size of set yielded by the root is the answer.

The complexity of this solution is $O(n \cdot log^2{n})$, which still can be too slow.

You can notice that if you have a pair of sets $a$ and $b$ such that $d_a \le d_b, d_a + d_b > k$, set $b$ will never affect the answer. If some set $c$ could later be merged with $b$, it can be with $a$ as well. Thus, you can erase set $b$ from the result and add $1$ to the answer. Then the vertex will always yield a single set. The solution mentioned above works in $O(n \log n)$ with this modification.

This can later be modified a bit to a $O(n)$ solution but that is totally unnecessary and works about the same time as $O(n \log n)$. It still takes most of the time to read the input.

 **Solution (O(n log n))**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(a) int((a).size())

const int N = 1000 * 1000 + 13;

int n, k;
vector<int> g[N];
int ans;

int dfs(int v, int p = -1){
	if (g[v].size() == 1)
		return 0;
	
	vector<int> cur;
	for (auto u : g[v]){
		if (u == p) continue;
		cur.push_back(dfs(u, v) + 1);
	}
	sort(cur.begin(), cur.end());
	
	while (sz(cur) >= 2){
		if (cur.back() + cur[sz(cur) - 2] <= k)
			break;
		++ans;
		cur.pop_back();
	}
	
	return cur.back();
}

int main(){
	scanf("%d%d", &n, &k);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	forn(i, n){
		if (sz(g[i]) > 1){
			dfs(i);
			break;
		}
	}
	
	printf("%dn", ans + 1);
	return 0;
}
```
 **Solution (Small to Large, O(n log^2 n))**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(a) int((a).size())

const int N = 1000 * 1000 + 13;

int n, k;
vector<int> g[N];
multiset<int> val[N];
int ans;

void dfs(int v, int d, int p){
	if (g[v].size() == 1){
		val[v].insert(d);
		return;
	}
	
	int bst = -1;
	for (auto u : g[v]){
		if (u == p) continue;
		dfs(u, d + 1, v);
		if (bst == -1 || sz(val[u]) > sz(val[bst]))
			bst = u;
	}
	swap(val[bst], val[v]);
	
	for (auto u : g[v]){
		if (u == p || u == bst) continue;
		for (auto it : val[u]){
			int dd = k + 2 * d - it;
			auto jt = val[v].upper_bound(dd);
			if (jt == val[v].begin()){
				val[v].insert(it);
			}
			else{
				--jt;
				int t = *jt;
				val[v].erase(jt);
				val[v].insert(max(it, t));
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	forn(i, n){
		if (sz(g[i]) > 1){
			dfs(i, 0, -1);
			printf("%dn", sz(val[i]));
			break;
		}
	}
	return 0;
}
```
 **Solution (O(n))**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(a) int((a).size())

const int N = 1000 * 1000 + 13;

int n, k;
vector<int> g[N];
int ans;

int dfs(int v, int p = -1){
	if (g[v].size() == 1)
		return 0;
	
	vector<int> cur;
	for (auto u : g[v]){
		if (u == p) continue;
		cur.push_back(dfs(u, v) + 1);
	}
	
	int pos = -1;
	forn(i, sz(cur)) {
		if (cur[i] * 2 <= k && (pos == -1 || cur[pos] < cur[i]))
			pos = i;
	}
	
	if (pos == -1) {
		ans += sz(cur) - 1;
		return *min_element(cur.begin(), cur.end());
	}
	
	int res = -1;
	forn(i, sz(cur)) {
		if (cur[pos] >= cur[i]) continue;
		if (cur[i] + cur[pos] <= k && (res == -1 || cur[i] < cur[res]))
			res = i;
	}
	
	forn(i, sz(cur))
		ans += (cur[i] > cur[pos]);
	if (res != -1)
		--ans;
	
	return (res == -1 ? cur[pos] : cur[res]);
}

int main(){
	scanf("%d%d", &n, &k);
	forn(i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	forn(i, n) {
		if (sz(g[i]) > 1) {
			dfs(i);
			break;
		}
	}
	
	printf("%dn", ans + 1);
	return 0;
}
```
