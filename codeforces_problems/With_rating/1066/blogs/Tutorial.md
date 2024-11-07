# Tutorial

[1066A - Vova and Train](../problems/A._Vova_and_Train.md "Codeforces Round 515 (Div. 3)")

 **Tutorial**
### [1066A - Vova and Train](../problems/A._Vova_and_Train.md "Codeforces Round 515 (Div. 3)")

What is the number of lanterns Vova will see from $1$ to $L$? This number is $\lfloor\frac{L}{v}\rfloor$. Now we have to subtract the number of lanters in range $[l; r]$ from this number. This number equals to $\lfloor\frac{r}{v}\rfloor - \lfloor\frac{l - 1}{v}\rfloor$. So the answer is $\lfloor\frac{L}{v}\rfloor$ - $\lfloor\frac{r}{v}\rfloor$ + $\lfloor\frac{l - 1}{v}\rfloor$.

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
	
	for (int i = 0; i < t; ++i) {	
		int L, v, l, r;
		cin >> L >> v >> l >> r;
		cout << L / v - r / v + (l - 1) / v << endl;
	}
	
	return 0;
}
```
[1066B - Heaters](../problems/B._Heaters.md "Codeforces Round 515 (Div. 3)")

 **Tutorial**
### [1066B - Heaters](../problems/B._Heaters.md "Codeforces Round 515 (Div. 3)")

Let's solve this problem greedily. Let $last$ be the last position from the left covered by at least one heater. Initially, $last$ equals -1. While $last < n - 1$, lets repeat the following process: firstly, we have to find the rightmost heater in range $(max(-1, last - r + 1); last + r]$. It can be done in time $O(n)$ because of given constrains or in $O(1)$ using precalculated prefix values for each $i$ in range $[0; n - 1]$. If there is no such heater then the answer is -1, otherwise let's set $last := pos + r - 1$, increase the answer by $1$ and repeat the process if $last < n - 1$.

There is another one solution to this problem. Assume that the initial answer equals to the total number of heaters. Let's calculate an array $cnt$ of length $n$, where $cnt_i$ means the number of heaters covering the $i$-th element. It can be done in $O(n^2)$. This array will mean that we are switch all the heaters on and we know for each element the number of heaters covers this element. Now if for at least $i \in [0, n - 1]$ holds $cnt_i = 0$ then the answer is -1. Otherwise let's switch useless heaters off. Let's iterate over all heaters from left to right. Let the current heater have position $i$. We need to check if it is useless or not. Let's iterate in range $[max(0, i - r + 1), min(n - 1, i + r - 1)]$ and check if there is at least one element $j$ in this segment such that $cnt_j = 1$. If there is then the current heater is not useless and we cannot switch it off. Otherwise we can decrease the answer by $1$, switch this heater off (decrease $cnt_j$ for all $j$ in range $[max(0, i - r + 1), min(n - 1, i + r - 1)]$) and continue the process.

 **Solution 1**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	int last = -1;
	while (last < n - 1) {
		int pos = -1;
		for (int i = n - 1; i > max(-1, last - r + 1); --i) {
			if (a[i] == 1 && i - r <= last) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			cout << -1 << "n";
			return 0;
		}
		++ans;
		last = pos + r - 1;
	}
	
	cout << ans << "n";
	
	return 0;
}
```
 **Solution 2**
```cpp
#include <vector>
#include <iostream>

#define forn(i,n) for (int i=0; i<int(n); i++)

using namespace std;

const int N = 2e5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, r; cin >> n >> r;
	vector<int> a(n);
	vector<int> cnt(n);
	int ans = 0;
	forn(i, n)
        {
            cin >> a[i];
            if (a[i])ans++;
            if (a[i])
                for (int j = max(0, i - r + 1); j < min(n, i + r); ++j)
                    cnt[j]++;
        }
    forn(i, n)
        if (!cnt[i])
        {
            cout << -1;
            return 0;
        }
    forn(i, n)
    {
        bool fl = true;
        if (a[i])
            for (int j = max(0, i - r + 1); j < min(n, i + r); ++j)
                if (cnt[j] == 1)
                {
                    fl = false;
                    break;
                }
        if (fl && a[i])
        {
            ans--;
            for (int j = max(0, i - r + 1); j < min(n, i + r); ++j)
                cnt[j]--;
        }
    }
    cout << ans;

}
```
[1066C - Books Queries](../problems/C._Books_Queries.md "Codeforces Round 515 (Div. 3)")

 **Tutorial**
### [1066C - Books Queries](../problems/C._Books_Queries.md "Codeforces Round 515 (Div. 3)")

Let imagine our shelf as an infinite array. Let's carry the rightmost free position from the left of our shelf (let it be $l$ and initially it equals to $0$) and the leftmost free position from the right of our shelf (let it be $r$ and initially it equals to $0$). Also let's carry the array $pos$ of length $2 \cdot 10^5$ where $pos_i$ will be equal to the position in our imaginary array of the book with a number $i$.

Let's put the first book to the position $0$. Also let's save that $pos_{id}$ (where $id$ is the number of the first book) equals to $0$. How will change $l$ and $r$? $l$ will become $-1$ and $r$ will become $1$. Now let's process queries one by one. If now we have the query of type $1$ with a book with a number $id$, then let's set $pos_{id} := l$ and set $l := l - 1$. The query of type $2$ can be processed similarly. Now what about queries of type $3$? The answer to this query equals to $min(|pos_{id} - l|, |pos_{id} - r|) - 1$, where $|v|$ is the absolute value of $v$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int M = 200 * 1000 + 11;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	
	vector<int> pos(M);
	int curl = 0;
	int curr = 0;
	
	for (int i = 0; i < q; ++i) {
		string type;
		int id;
		cin >> type >> id;
		if (i == 0) {
			pos[id] = curl;
			--curl;
			++curr;
		} else {
			if (type == "L") {
				pos[id] = curl;
				--curl;
			} else if (type == "R") {
				pos[id] = curr;
				++curr;
			} else {
				cout << min(abs(pos[id] - curl), abs(pos[id] - curr)) - 1 << "n";
			}
		}
	}
	
	return 0;
}
```
[1066D - Boxes Packing](../problems/D._Boxes_Packing.md "Codeforces Round 515 (Div. 3)")

 **Tutorial**
### [1066D - Boxes Packing](../problems/D._Boxes_Packing.md "Codeforces Round 515 (Div. 3)")

The first solution is some kind of a straight-forward understanding the problem. Let's do binary search on the answer. So our problem is to find the smallest $x$ such that the suffix of the array $a$ starting from the position $x$ can be packed in boxes. It is easy to see that if we can do it for some $x$ then we always can do it for $x+1$. And to find the answer for the fixed $x$ we have to simulate the process described in the problem statement starting from the position $x$. Okay, this is $O(n \log n)$ solution.

The second solution is more interesting than the first one. The approach is to reverse the initial array, simulate the process from the first position of reversed array and then all the objects we can pack are in the best answer and there is no better answer at all.

Why it works?

Let's take a look on the last box in the best answer if we will go from left to right in the initial array. Let objects in this box be $a_{lst_1}, a_{lst_2}, \dots, a_{lst_x}$. What do we see? $\sum\limits_{i = 1}^{x}a_{lst_i} \le k$. So all these objects are fit in the last box (obviously). Now if we will iterate over objects from right to left, these objects will fit also! It means that we cannot do worse by such a transform (reversing) at least for the last box.

But what will happen if we can put some of the previous objects in this box? Well, it will not make worse for this box, but what about next boxes (previous boxes in straight notation)? Let objects in the penultimate box be $a_{prev_1}, a_{prev_2}, \dots, a_{prev_y}}$. What do we see? These objects are fit in this box (obviously again). What will happen if we will put in the last box one or more objects of this box? Then the left border of objects which we will put in it will not increase because we decrease the number of object in this box. So we can see that for previous boxes this condition is also satisfied.

So we can solve the problem with this approach. Time complexity of this solution is $O(n)$.

 **Solution 1**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int ar[MAX];
int n, m, k;

int find(int pos){
    int ans = n - pos + 1;
    int used = 0;
    while(used < m && pos <= n){
        int t = k;
        while(pos <= n && ar[pos] <= t){
            t -= ar[pos++];
        }
        used++;
    }
    return pos == n + 1 ? ans : 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int ans = 0;
    int l = 1, r = n;
    while(l <= r){
        int x = (l + r) >> 1;
        if(find(x)){
            ans = max(ans, n - x + 1);
            r = x - 1;
        }else{
            l = x + 1;
        }
    }
    cout << ans << endl;
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	reverse(a.begin(), a.end());
	int rem = 0;
	for (int i = 0; i < n; ++i) {
		if (rem - a[i] < 0) {
			if (m == 0) {
				cout << i << endl;
				return 0;
			} else {
				--m;
				rem = k - a[i];
			}
		} else {
			rem -= a[i];
		}
	}
	
	cout << n << endl;
	
	return 0;
}
```
[1066E - Binary Numbers AND Sum](../problems/E._Binary_Numbers_AND_Sum.md "Codeforces Round 515 (Div. 3)")

 **Tutorial**
### [1066E - Binary Numbers AND Sum](../problems/E._Binary_Numbers_AND_Sum.md "Codeforces Round 515 (Div. 3)")

To solve this problem let's take a look which powers of $2$ in $a$ will be affected by powers of $2$ in $b$. Firstly, let's reverse numbers. Let's carry the current power of $2$ (let it be $pw$), the current sum of powers of $2$ in $a$ from the position $0$ to the current position inclusive (let it be $res$) and the answer is $ans$. Initially, $pw = 1$, $res = 0$ and $ans = 0$. Let's iterate over all bits of $b$ from $0$ to $m - 1$. Let the current bit in $b$ have the number $i$. Firstly, if $i < n$ and $a_i = 1$ then set $res := res + pw$ (in other words, we add to the sum of powers of $2$ in $a$ the current power of $2$). If $b_i = 1$ then this bit will add to the answer all the powers of $2$ in $a$ from $0$ to $i$ inclusive (in other words, $res$), so if it is, then set $ans := ans + res$. And after all we can set $pw := pw + pw$ and go on to $i+1$. And don't forget to take all values modulo $998244353$ to avoid overflow.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	int pw = 1;
	int res = 0;
	int ans = 0;
	
	for (int i = 0; i < m; ++i) {
		if (i < n && s[n - i - 1] == '1') {
			res = add(res, pw);
		}
		if (t[m - i - 1] == '1') {
			ans = add(ans, res);
		}
		pw = add(pw, pw);
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1066F - Yet another 2D Walking](../problems/F._Yet_another_2D_Walking.md "Codeforces Round 515 (Div. 3)")

 **Tutorial**
### [1066F - Yet another 2D Walking](../problems/F._Yet_another_2D_Walking.md "Codeforces Round 515 (Div. 3)")

The main idea is that we don't need more than $2$ border points on each level. So if we consider than the point $p = (x_p, y_p)$ is less than point $q = (x_q, y_q)$ when $p_x < q_x$ or $p_x = q_x$ and $p_y > q_y$ then let's distribute all the points by their levels using std::map or something like it, sort points on each level by the comparator above and remain the first one and the last one on each level. Also let's add the fictive level $0$ with the point $(0, 0)$. It is always true to remain at most $2$ points and can be easily proved but this fact is very intuitive I think. Now let's do dynamic programming on the points. $dp_{i, j}$ means that now we are at the level $i$ and stay in the first point (if $j = 0$) or in the last point (if $j = 1$) and we are already visit all the points on the level $i$. The value of this dynamic programming is the minimum possible total distance to reach this state. Initially, $dp_{0, 0} = dp_{0, 1} = 0$, other values are equal to $\infty$. Let's calculate this dynamic programming in order of increasing levels. Let $p_{lvl, 0}$ be the first key point at the level $lvl$ and $p_{lvl, 1}$ be the last key point at the level $lvl$. Now if we are at the level $lvl$ and the previous level is $plvl$, these $4$ transitions are sufficient to calculate states of dynamic programming on the current level: 

1. $dp_{lvl, 0} = min(dp_{lvl, 0}, dp_{plvl, 0} + dist(p_{plvl, 0}, p_{lvl, 1}) + dist(p_{lvl, 1}, p_{lvl, 0})$;
2. $dp_{lvl, 0} = min(dp_{lvl, 0}, dp_{plvl, 1} + dist(p_{plvl, 1}, p_{lvl, 1}) + dist(p_{lvl, 1}, p_{lvl, 0})$;
3. $dp_{lvl, 1} = min(dp_{lvl, 1}, dp_{plvl, 0} + dist(p_{plvl, 0}, p_{lvl, 0}) + dist(p_{lvl, 0}, p_{lvl, 1})$;
4. $dp_{lvl, 1} = min(dp_{lvl, 1}, dp_{plvl, 1} + dist(p_{plvl, 1}, p_{lvl, 0}) + dist(p_{lvl, 0}, p_{lvl, 1})$.

There $dist(p, q)$ means the distance between points $p$ and $q$.

Let last level we have be $lst$. After calculating this dynamic programming the answer is $min(dp_{lst, 0}, dp_{lst, 1})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e18;

long long dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	map<int, vector<pair<int, int>>> pts;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pts[max(x, y)].push_back(make_pair(x, y));
	}
	pts[0].push_back(make_pair(0, 0));
	
	for (auto &it : pts) {
		sort(it.second.begin(), it.second.end(), [&](pair<int, int> a, pair<int, int> &b) {
			if (a.first == b.first)
				return a.second > b.second;
			return a.first < b.first;
		});
	}
	
	vector<vector<long long>> dp(int(pts.size()) + 1, vector<long long>(2, INF64));
	dp[0][0] = dp[0][1] = 0;
	
	int lvl = 0;
	int prv = 0;
	for (auto &it : pts) {
		++lvl;
		
		pair<int, int> curl = it.second[0];
		pair<int, int> curr = it.second.back();
		
		pair<int, int> prvl = pts[prv][0];
		pair<int, int> prvr = pts[prv].back();
		
		dp[lvl][0] = min(dp[lvl][0], dp[lvl - 1][0] + dist(prvl, curr) + dist(curl, curr));
		dp[lvl][0] = min(dp[lvl][0], dp[lvl - 1][1] + dist(prvr, curr) + dist(curl, curr));
		dp[lvl][1] = min(dp[lvl][1], dp[lvl - 1][0] + dist(prvl, curl) + dist(curl, curr));
		dp[lvl][1] = min(dp[lvl][1], dp[lvl - 1][1] + dist(prvr, curl) + dist(curl, curr));
		
		prv = it.first;
	}
	
	cout << min(dp[lvl][0], dp[lvl][1]) << endl;
	
	return 0;
}
```
