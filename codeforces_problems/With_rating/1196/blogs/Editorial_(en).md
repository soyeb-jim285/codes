# Editorial_(en)

[1196A - Three Piles of Candies](../problems/A._Three_Piles_of_Candies.md "Codeforces Round 575 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1196A - Three Piles of Candies](../problems/A._Three_Piles_of_Candies.md "Codeforces Round 575 (Div. 3)")

The answer is always $\lfloor\frac{a + b + c}{2}\rfloor$. Let's understand why it is so. Let $a \le b \le c$. Then let Bob take the pile with $a$ candies and Alice take the pile with $b$ candies. Then because of $b \le a + c$ we can see that Bob's pile always can reach size of Alice's pile (and remaining candies can be divided between them fairly except one candy if $a + b + c$ is odd).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << endl;
	}
	
	return 0;
}
```
[1196B - Odd Sum Segments](../problems/B._Odd_Sum_Segments.md "Codeforces Round 575 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1196B - Odd Sum Segments](../problems/B._Odd_Sum_Segments.md "Codeforces Round 575 (Div. 3)")

Firstly, let $cnt$ be the number of odd elements in the array. Note that even elements are don't matter at all because they cannot change the parity of the sum.

If $cnt < k$ then it is obviously impossible to split the given array into $k$ subsegments with odd sum. And if $cnt \% 2 \ne k \% 2$ then it is impossible to split the array into $k$ subsegments with odd sum also because at least one of $k$ segments will have even number of odd elements (so will have odd sum).

In other cases the answer is always "YES" and you can print $k-1$ leftmost positions of odd elements and $n$ as right borders of segments (it means that when you find one odd element, you end one segment). Because $cnt \% 2 = k \% 2$ now, the last segment will have odd number of odd elements so it will have odd sum also.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int cntodd = 0;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			cntodd += a[j] % 2;
		}
		if (cntodd < k || cntodd % 2 != k % 2) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int j = 0; j < n; ++j) {
			if (k == 1) break;
			if (a[j] % 2 == 1) {
				cout << j + 1 << " ";
				--k;
			}
		}
		cout << n << endl;
	}
	return 0;
}
```
[1196C - Robot Breakout](../problems/C._Robot_Breakout.md "Codeforces Round 575 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1196C - Robot Breakout](../problems/C._Robot_Breakout.md "Codeforces Round 575 (Div. 3)")

In fact, we have some restrictions on $OX$ axis and $OY$ axis (for example, if some robot stays at the position $x$ and cannot move to the left, then the answer point should have $X \ge x$).

So we can take the minimum among all $y$-coordinates of robots that cannot go up and save it into $maxy$, maximum among all $y$-coordinates of robots that cannot go down and save it into $miny$, minimum among all $x$-coordinates of robots that cannot go right and save it into $maxx$ and maximum among all $x$-coordinates of robots that cannot go right and save it into $minx$. Initially $minx = miny = -\infty, maxx = maxy = +\infty$.

So these restrictions are describe some rectangle (possibly incorrect, with $minx > maxx$ or $miny > maxy$). Let $(minx, miny)$ be the bottom-left point of this rectangle and $(maxx, maxy)$ be the top-right point of this rectangle.

In case if this rectangle have $minx > maxx$ or $miny > maxy$, the answer is "NO". Otherwise this rectangle describes all integer points which can be reachable all robots and you can print any of them.

 **Solution**
```cpp
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXC = 1e5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int mnx = -MAXC, mxx = MAXC;
        int mny = -MAXC, mxy = MAXC;
        while (n--) {
            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if (!f1) mnx = max(mnx, x);
            if (!f2) mxy = min(mxy, y);
            if (!f3) mxx = min(mxx, x);
            if (!f4) mny = max(mny, y);
        }
        if (mnx <= mxx && mny <= mxy)
            cout << "1 " << mnx << " " << mny << "n";
        else
            cout << "0n";
    }

    return 0;
}
```
[1196D1 - RGB Substring (easy version)](../problems/D1._RGB_Substring_(easy_version).md "Codeforces Round 575 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1196D1 - RGB Substring (easy version)](../problems/D1._RGB_Substring_(easy_version).md "Codeforces Round 575 (Div. 3)")

You can just implement what is written in the problem statement and solve this problem this way.

Let's iterate over all starting positions of the substring $i$ from $0$ to $n-k+1$ and over all possible offsets of the string $t$ = "RGB" $offset$ from $0$ to $2$ inclusive. Then let's iterate over all position of the current substring $pos$ from $0$ to $k-1$ and carry the variable $cur$ which denotes the answer for the current starting position and the current offset. And if $s_{i + pos} \ne t_{(offset + pos) \% 3}$ then let's increase $cur$ by $1$. After iterating over all positions $pos$ let's update the answer with the value of $cur$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	const string t = "RGB";

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 1e9;
		for (int j = 0; j < n - k + 1; ++j) {
			for (int offset = 0; offset < 3; ++offset) {
				int cur = 0;
				for (int pos = 0; pos < k; ++pos) {
					if (s[j + pos] != t[(pos + offset) % 3]) {
						++cur;
					}
				}
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1196D2 - RGB Substring (hard version)](../problems/D2._RGB_Substring_(hard_version).md "Codeforces Round 575 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1196D2 - RGB Substring (hard version)](../problems/D2._RGB_Substring_(hard_version).md "Codeforces Round 575 (Div. 3)")

In this problem you should make the same as in the previous one but faster. Let's consider three offsets of string "RGB": "RGB", "GBR" and "BRG". Let's copy the current offset of the string so that it will has the length $n$ (possibly, without some trailing characters) and save it in the string $t$.

Then let's compare the string $s$ with this offset of length $n$ and build an array $diff$ of length $n$ where $diff_i = 1$ if $s_i \ne t_i$. Then let's iterate over all possible continuous subsegments of this array $diff$ and maintain the variable $cur$ denoting the current answer.

Firstly, for the current position $i$ let's add $diff_i$ to $cur$. Then if the current position $i$ is greater than or equal to $k-1$ ($0$-indexed) let's decrease $cur$ by $diff_{i-k}$. So now we have the continuous subsegment of the array $diff$ of length no more than $k$. Then if the current position $i$ is greater than or equal to $k$ ($0$-indexed again) (the current subsegment has the length $k$) then let's update the answer with $cur$. Then let's do the same with two remaining offsets.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	const string t = "RGB";

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 1e9;
		for (int offset = 0; offset < 3; ++offset) {
			vector<int> res(n);
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				res[j] = (s[j] != t[(j + offset) % 3]);
				cur += res[j];
				if (j >= k) cur -= res[j - k];
				if (j >= k - 1) ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1196E - Connected Component on a Chessboard](../problems/E._Connected_Component_on_a_Chessboard.md "Codeforces Round 575 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1196E - Connected Component on a Chessboard](../problems/E._Connected_Component_on_a_Chessboard.md "Codeforces Round 575 (Div. 3)")

I'll consider the case when $b \ge w$, the other case is symmetric and the answer I construct is the same but shifted by $1$ to the right.

Consider the given field as a matrix where $x$ is the number of row and $y$ is the number of column. Firstly, let's build the line of length $2w-1$ from the cell $(2, 2)$ to the cell $(2, 2w)$. Then $b$ will decrease by $w-1$ and $w$ will (formally) become $0$.

Then we have two black cells to the left and to the right ($(2, 1)$ and $(2, 2w+1)$) and $w-1$ black cells to the up (all cells ($1, 2w+2*i$) for all $i$ from $0$ to $w-1$) and $w-1$ black cells to the down (all cells ($3, 2w+2*i$) for all $i$ from $0$ to $w-1$). Let's add the required number of cells to the answer.

If even after adding all these cells $b$ still be greater than $0$ then the answer is "NO" (maybe there will be a proof why it is so but you can read it already from other participants). Otherwise the answer is "YES" and we constructed the required component.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int b, w;
		cin >> b >> w;
		vector<pair<int, int>> res;
		bool need = b < w;
		if (need) swap(w, b);
		int x = 2, y = 2;
		while (w > 0) {
			if ((x + y) % 2 == 1) {
				res.push_back({x, y});
				--b;
			} else {
				res.push_back({x, y});
				--w;
			}
			++y;
		}
		int cx = 1, cy = 2;
		while (b > 0 && cy <= y) {
			res.push_back({cx, cy});
			--b;
			cy += 2;
		}
		cx = 3, cy = 2;
		while (b > 0 && cy <= y) {
			res.push_back({cx, cy});
			--b;
			cy += 2;
		}
		if (b > 0) {
			res.push_back({2, 1});
			--b;
		}
		if (b > 0) {
			res.push_back({2, y});
			--b;
		}
		if (b > 0) {
			cout << "NO" << endl;
		} else {
			assert(w == 0);
			cout << "YES" << endl;
			for (auto it : res) cout << it.first << " " << it.second + need << endl;
		}
	}
	
	return 0;
}
```
[1196F - K-th Path](../problems/F._K-th_Path.md "Codeforces Round 575 (Div. 3)")

 **Tutorial**
### [1196F - K-th Path](../problems/F._K-th_Path.md "Codeforces Round 575 (Div. 3)")

The main observation is that you don't need more than $min(k, m)$ smallest by weight edges (among all edges with the maximum weights you can choose any). Maybe there will be a proof later, but now I ask other participant to write it.

So you sort the initial edges and after that you can construct a graph consisting of no more than $2min(k, m)$ vertices and no more than $min(m, k)$ edges. You just can build the new graph consisting only on these vertices and edges and run Floyd-Warshall algorithm to find the matrix of shortest paths. Then sort all shorted distances and print the $k$-th element of this sorted array.

Time complexity: $O(m \log m + k^3)$.

I know that there are other approaches that can solve this problem with greater $k$, but to make this problem easily this solution is enough.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e18;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<pair<int, pair<int, int>>> e;
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		--x, --y;
		e.push_back(make_pair(w, make_pair(x, y)));
	}
	sort(e.begin(), e.end());
	
	vector<int> vert;
	for (int i = 0; i < min(m, k); ++i) {
		vert.push_back(e[i].second.first);
		vert.push_back(e[i].second.second);
	}
	sort(vert.begin(), vert.end());
	vert.resize(unique(vert.begin(), vert.end()) - vert.begin());
	int cntv = vert.size();
	vector<vector<long long>> dist(cntv, vector<long long>(cntv, INF64));
	for (int i = 0; i < cntv; ++i) dist[i][i] = 0;
	
	for (int i = 0; i < min(m, k); ++i) {
		int x = lower_bound(vert.begin(), vert.end(), e[i].second.first) - vert.begin();
		int y = lower_bound(vert.begin(), vert.end(), e[i].second.second) - vert.begin();
		dist[x][y] = dist[y][x] = min(dist[x][y], (long long)e[i].first);
	}
	
	for (int z = 0; z < cntv; ++z) {
		for (int x = 0; x < cntv; ++x) {
			for (int y = 0; y < cntv; ++y) {
				dist[x][y] = min(dist[x][y], dist[x][z] + dist[z][y]);
			}
		}
	}
	
	vector<long long> res;
	for (int i = 0; i < cntv; ++i) {
		for (int j = 0; j < i; ++j) {
			res.push_back(dist[i][j]);
		}
	}
	
	sort(res.begin(), res.end());
	cout << res[k - 1] << endl;
	
	return 0;
}
```
