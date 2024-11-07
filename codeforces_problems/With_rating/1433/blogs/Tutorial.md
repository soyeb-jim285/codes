# Tutorial

I'm really sorry about issues with problems E and F. Can't say anything more because I don't want to justify my mistakes.

[1433A - Boring Apartments](../problems/A._Boring_Apartments.md "Codeforces Round 677 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1433A - Boring Apartments](../problems/A._Boring_Apartments.md "Codeforces Round 677 (Div. 3)")

This problem has a lot of solutions. You could even hard code all possible tests to solve it. But this problem has O(1) solution. Let the digit of x be dig. Then our character pressed each digit before dig exactly 10 times (1+2+3+4). And the amount of times he pressed the digit dig depends on the length of x. Let len be the length of x, then the amount of times he pressed the digit dig is 1+2+…+len=len(len+1)2. So the final answer is 10⋅(dig−1)+len(len+1)2.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		string x;
		cin >> x;
		int dig = x[0] - '0' - 1;
		int len = x.size();
		cout << dig * 10 + len * (len + 1) / 2 << endl;
	}
	
	return 0;
}
```
[1433B - Yet Another Bookshelf](../problems/B._Yet_Another_Bookshelf.md "Codeforces Round 677 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1433B - Yet Another Bookshelf](../problems/B._Yet_Another_Bookshelf.md "Codeforces Round 677 (Div. 3)")

We can notice that the answer is the number of zeros between the leftmost occurrence of 1 and the rightmost occurrence of 1. Why is it true? Let's take the leftmost maximum by inclusion segment of 1 and just shift it right. We can see that using this algorithm we will do exactly described amount of moves and there is no way improve the answer.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		while (a.back() == 0) a.pop_back();
		reverse(a.begin(), a.end());
		while (a.back() == 0) a.pop_back();
		cout << count(a.begin(), a.end(), 0) << endl;
	}
	
	return 0;
}
```
[1433C - Dominant Piranha](../problems/C._Dominant_Piranha.md "Codeforces Round 677 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1433C - Dominant Piranha](../problems/C._Dominant_Piranha.md "Codeforces Round 677 (Div. 3)")

If all the piranhas have the same size then the answer is -1. Otherwise, there are at least two different sizes of piranhas and the answer always exists. Claim that the answer is such a piranha with the maximum size that one of the adjacent piranhas has the size less than a maximum.

Why is it true and why the answer always exists? First, if the piranha with the maximum size eats some other piranha, it becomes the only maximum in the array and can eat all other piranhas. Why is there always such a pair of piranhas? Let's change our array a bit: replace every maximum with 1 and every non-maximum with 0. There is always some 01-pair or 10-pair in such array because we have at least two different elements.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int mx = 0;
		for (auto &it : a) {
			cin >> it;
			mx = max(mx, it);
		}
		int idx = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] != mx) continue;
			if (i > 0 && a[i - 1] != mx) idx = i + 1;
			if (i < n - 1 && a[i + 1] != mx) idx = i + 1;
		}
		cout << idx << endl;
	}
	
	return 0;
}
```
[1433D - Districts Connection](../problems/D._Districts_Connection.md "Codeforces Round 677 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1433D - Districts Connection](../problems/D._Districts_Connection.md "Codeforces Round 677 (Div. 3)")

If all districts belong to the same gang then the answer is NO. Otherwise, the answer is always YES (yeah, as in the previous problem). How to construct it? Let's choose the first "root" as the district 1 and connect all such districts i that a1≠ai to the district 1. So, all disconnected districts that remain are under control of the gang a1. Let's find any district i that ai≠a1 and just connect all remaining districts of the gang a1 to this district. This district always exists because we have at least two different gangs and it is connected to the remaining structure because its gang is not a1. So, all conditions are satisfied.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<pair<int, int>> res;
		int idx = -1;
		for (int i = 1; i < n; ++i) {
			if (a[i] != a[0]) {
				idx = i;
				res.push_back({1, i + 1});
			}
		}
		if (idx == -1) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 1; i < n; ++i) {
			if (a[i] == a[0]) {
				res.push_back({idx + 1, i + 1});
			}
		}
		cout << "YES" << endl;
		for (auto [x, y] : res) cout << x << " " << y << endl;
	}
	
	return 0;
}
```
[1433E - Two Round Dances](../problems/E._Two_Round_Dances.md "Codeforces Round 677 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1433E - Two Round Dances](../problems/E._Two_Round_Dances.md "Codeforces Round 677 (Div. 3)")

Firstly, we need to choose the set of n2 people to be in the first round dance (the other half is going to the second one). The number of ways to do that is (nn2). Then we need to set some order of people in both round dances, but we don't want to forget about rotation (because rotation can lead us to counting the same ways several times). So, the number of ways to arrange people inside one round dance is (n2−1)!. This is true because we just "fixed" who will be the first in the round dance, and place others in every possible order. So, we need to multiply our initial answer by this value twice because we have two round dances. And, finally, we have to divide our answer by 2 because we counted "ordered" pairs (i.e. we distinguish pairs of kind (x,y) and (y,x) but we don't have to do that). So, the final answer is (nn2)⋅(n2−1)!⋅(n2−1)! divided by 2. This formula can be reduced to n!n22⋅2.

You could also find the sequence of answers in OEIS (and this can be really useful skill sometimes).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 21;

long long f[N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	f[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * i;
	}
	
	long long ans = f[n] / f[n / 2] / f[n / 2];
	ans = ans * f[n / 2 - 1];
	ans = ans * f[n / 2 - 1];
	ans /= 2;
	
	cout << ans << endl;
	
	return 0;
}

```
[1433F - Zero Remainder Sum](../problems/F._Zero_Remainder_Sum_.md "Codeforces Round 677 (Div. 3)") 

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1433F - Zero Remainder Sum](../problems/F._Zero_Remainder_Sum_.md "Codeforces Round 677 (Div. 3)")

This is pretty standard dynamic programming problem. Let dp[x][y][cnt][rem] be the maximum possible sum we can obtain if we are at the element ax,y right now, we took cnt elements in the row x and our current remainder is rem.

Initially, all states are −∞ except dp[0][0][0][0]=0.

Transitions are standard because this is a knapsack problem: we either take the element if cnt<⌊m2⌋ or don't take it. If the element ax,y is not the last element of the row, then transitions look like that:

* dp[x][y+1][cnt][rem]=max(dp[x][y+1][cnt][rem],dp[x][y][cnt][rem]) — we don't take the current element.
* dp[x][y+1][cnt+1][(rem+ax,y)%k]=max(dp[x][y+1][cnt+1][(rem+ax,y)%k],dp[x][y][cnt][rem]+ax,y) — we take the current element (this transition is only possible if cnt<⌊m2⌋).

The transitions from the last element of the row are almost the same, but the next element is ax+1,0 and the new value of cnt is always zero.

The answer is max(0,dp[n][0][0][0]).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 75;
const int INF = 1e9;

int a[N][N];
int dp[N][N][N][N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	forn(i, n) forn(j, m) {
		cin >> a[i][j];
	}
	
	forn(i, N) forn(j, N) forn(cnt, N) forn(rem, N) dp[i][j][cnt][rem] = -INF;
	dp[0][0][0][0] = 0;
	forn(i, n) forn(j, m) forn(cnt, m / 2 + 1) forn(rem, k) {
		if (dp[i][j][cnt][rem] == -INF) continue;
		int ni = (j == m - 1 ? i + 1 : i);
		int nj = (j == m - 1 ? 0 : j + 1);
		if (i != ni) {
			dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
		} else {
			dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
		}
		if (cnt + 1 <= m / 2) {
			int nrem = (rem + a[i][j]) % k;
			if (i != ni) {
				dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + a[i][j]);
			} else {
				dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + a[i][j]);
			}
		}
	}
	
	cout << max(0, dp[n][0][0][0]) << endl;
	
	return 0;
}
```
[1433G - Reducing Delivery Cost](../problems/G._Reducing_Delivery_Cost.md "Codeforces Round 677 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1433G - Reducing Delivery Cost](../problems/G._Reducing_Delivery_Cost.md "Codeforces Round 677 (Div. 3)")

If we would naively solve the problem, we would just try to replace each edge's cost with zero and run Dijkstra algorithm n times to get the cheapest paths. But this is too slow.

Let's try to replace each edge's cost with zero anyway but use some precalculations to improve the speed of the solution. Let's firstly run Dijkstra n times to calculate all cheapest pairwise paths. Then, let's fix which edge we "remove" (x,y).

There are three cases for the path (a,b): this edge was not on the cheapest path before removing and is not on the cheapest path after removing. Then the cost of this path is d(a,b). The second case is when this edge was not on the cheapest path before removing but it is on the cheapest path after removing. Then the cost of this path is min(d(a,x)+d(y,b),d(a,y)+d(x,b)). So we are just going from a to x using the cheapest path, then going through the zero edge and then going from y to b using the cheapest path also (or vice versa, from a to y and from x to b). And the third case is when this edge was already on the cheapest path between a and b but this case is essentially the same as the second one.

So, if we fix the edge (x,y), then the answer for this edge is k∑i=1min(d(ai,bi),d(ai,x)+d(y,bi),d(ai,y)+d(x,bi)). Taking the minimum over all edges, we will get the answer.

The precalculating part works in O(nmlogn) and the second part works in O(km).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> d;
vector<vector<pair<int, int>>> g;

void dijkstra(int s, vector<int> &d) {
	d = vector<int>(n, INF);
	d[s] = 0;
	set<pair<int, int>> st;
	st.insert({d[s], s});
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto [to, w] : g[v]) {
			if (d[to] > d[v] + w) {
				auto it = st.find({d[to], to});
				if (it != st.end()) st.erase(it);
				d[to] = d[v] + w;
				st.insert({d[to], to});
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int m, k;
	cin >> n >> m >> k;
	g = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	
	vector<pair<int, int>> r(k);
	for (auto &[a, b] : r) {
		cin >> a >> b;
		--a, --b;
	}
	
	d = vector<vector<int>>(n);
	for (int v = 0; v < n; ++v) {
		dijkstra(v, d[v]);
	}
	
	int ans = INF;
	for (int v = 0; v < n; ++v) {
		for (auto [to, w] : g[v]) {
			int cur = 0;
			for (auto [a, b] : r) {
				cur += min({d[a][b], d[a][v] + d[to][b], d[a][to] + d[v][b]});
			}
			ans = min(ans, cur);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
