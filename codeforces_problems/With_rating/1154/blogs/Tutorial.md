# Tutorial

[1154A - Restoring Three Numbers](../problems/A._Restoring_Three_Numbers.md "Codeforces Round 552 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1154A - Restoring Three Numbers](../problems/A._Restoring_Three_Numbers.md "Codeforces Round 552 (Div. 3)")

Let $x_1 = a + b$, $x_2 = a + c$, $x_3 = b = c$ and $x_4 = a + b + c$. Then we can construct the following answer: $c = x_4 - x_1$, $b = x_4 - x_2$ and $a = x_4 - x_3$.

Because all numbers in the answer are positive, we can assume that the maximum element of $x$ is $a + b + c$. So let's sort the input array $x$ consisting of four elements and just print $x_4 - x_1, x_4 - x_2$ and $x_4 - x_3$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	vector<int> a(4);
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[3] - a[0] << " " << a[3] - a[1] << " " << a[3] - a[2] << endl;
	
	return 0;
}
```
[1154B - Make Them Equal](../problems/B._Make_Them_Equal.md "Codeforces Round 552 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1154B - Make Them Equal](../problems/B._Make_Them_Equal.md "Codeforces Round 552 (Div. 3)")

Let's leave only unique values of the given array in the array $b$ (i. e. construct an array $b$ that is actually array $a$ without duplicate element) and sort it in ascending order. Then let's consider the following cases: 

* If the length of $b$ is greater than $3$ then the answer is -1;
* if the length of $b$ is $3$ then there are two cases:
	+ if $b_3 - b_2 = b_2 - b_1$ then the answer is $b_2 - b_1$;
	+ otherwise the answer is -1;
* if the length of $b$ is $2$ then there are also two cases:
	+ if $b_2 - b_1$ is even then the answer is $\frac{b_2 - b_1}{2}$;
	+ otherwise the answer is $b_2 - b_1$;
* and if the length of $b$ is $1$ then the answer is $0$.
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
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	if (a.size() > 3) {
		cout << -1 << endl;
	} else {
		if (a.size() == 1) {
			cout << 0 << endl;
		} else if (a.size() == 2) {
			if ((a[1] - a[0]) % 2 == 0) {
				cout << (a[1] - a[0]) / 2 << endl;
			} else {
				cout << a[1] - a[0] << endl;
			}
		} else {
			if (a[1] - a[0] != a[2] - a[1]) {
				cout << -1 << endl;
			} else {
				cout << a[1] - a[0] << endl;
			}
		}
	}
	
	return 0;
}
```
[1154C - Gourmet Cat](../problems/C._Gourmet_Cat.md "Codeforces Round 552 (Div. 3)")

Idea: [le.mur](https://codeforces.com/profile/le.mur "Unrated, le.mur")

 **Tutorial**
### [1154C - Gourmet Cat](../problems/C._Gourmet_Cat.md "Codeforces Round 552 (Div. 3)")

Let the number of rations of fish food be $a_1$, the number of rations of rabbit stew be $a_2$ and the number of rations of chicken stakes be $a_3$ (so we have an array $a$ consisting of $3$ elements).

Let $full$ be the maximum number of full weeks cat can eat if the starting day of the trip can be any day of the week. The value of $full$ is $min(\lfloor\frac{a_1}{3}\rfloor, \lfloor\frac{a_2}{2}\rfloor, \lfloor\frac{a_3}{2}\rfloor)$.

Let's subtract the value $3 \cdot full$ from $a_1$, and $2 \cdot full$ from $a_2$ and $a_3$. We can see that we cannot feed the cat at least one more full week. So the final answer is $7 \cdot full + add$, where $add < 7$.

Now it's time for some good implementation! Of course, you can try to analyze all cases and handle them using ifs or something similar, but I will try to suggest you a good enough way to implement the remaining part of the problem:

Let's create an array $idx$ of length $7$, where $idx_i$ means the type of the food cat eats during the $i$-th day of the week ($1$ for fish food, $2$ for rabbit stew and $3$ for chicken stake). It will be $idx = [1, 2, 3, 1, 3, 2, 1]$.

Now let's iterate over the day we will start our trip. Let it be $start$. For the current starting day let $cur$ be the number of rations cat has eaten already (initially it is zero), $day$ be the current day of the trip (initially it is $start$) and the array $b$ be the copy of the array $a$. Then let's do the following sequence of the operations, while $b_{idx_{day}}$ is greater than zero: decrease $b_{idx_{day}}$ by one, increase $cur$ by one and set $day := day \% 7 + 1$ (take it modulo $7$ and add one). After this cycle we can update the answer with the value of $7 \cdot full + cur$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	
	vector<int> idx({0, 1, 2, 0, 2, 1, 0});
	
	int full = min({a[0] / 3, a[1] / 2, a[2] / 2});
	a[0] -= full * 3;
	a[1] -= full * 2;
	a[2] -= full * 2;
	
	int ans = 0;
	for (int start = 0; start < 7; ++start) {
		int day = start;
		vector<int> b = a;
		int cur = 0;
		while (b[idx[day]] > 0) {
			--b[idx[day]];
			day = (day + 1) % 7;
			++cur;
		}
		ans = max(ans, full * 7 + cur);
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1154D - Walking Robot](../problems/D._Walking_Robot.md "Codeforces Round 552 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

int a, b, maxa;

void use_battery(int s)
{
	if(s == 1) a = min(a + 1, maxa);
	--b;	
}

void use_accum()
{
	--a;
}

int main()
{
	int ans = 0;
	int n;
	cin >> n >> b >> a;
	maxa = a;
	vector<int> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++)
	{
		if(a == 0 && b == 0)
			break;
		else if(a == 0)
			use_battery(s[i]);
		else if(b == 0)
			use_accum();
		else if(s[i] == 1 && a < maxa)
			use_battery(s[i]);
		else use_accum();
		ans++;
	}
	cout << ans << endl;
}
```
[1154E - Two Teams](../problems/E._Two_Teams.md "Codeforces Round 552 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort(a.rbegin(), a.rend());
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		q.push(a[i].second);
	}
	
	set<int> idx;
	for (int i = 0; i < n; ++i) {
		idx.insert(i);
	}
	string ans(n, '0');
	int who = 0;
	while (!idx.empty()) {
		while (!idx.count(q.front())) {
			q.pop();
		}
		int pos = q.front();
		q.pop();
		
		vector<int> add;
		auto it = idx.find(pos);
		for (int i = 0; i <= k; ++i) {
			add.push_back(*it);
			if (it == idx.begin()) break;
			--it;
		}
		it = next(idx.find(pos));
		for (int i = 0; i < k; ++i) {
			if (it == idx.end()) break;
			add.push_back(*it);
			++it;
		}
		for (auto it : add) {
			idx.erase(it);
			ans[it] = '1' + who;
		}
		who ^= 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1154F - Shovels Shop](../problems/F._Shovels_Shop.md "Codeforces Round 552 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1154F - Shovels Shop](../problems/F._Shovels_Shop.md "Codeforces Round 552 (Div. 3)")

First of all, since we are going to buy exactly $k$ shovels, we may discard $n - k$ most expensive shovels from the input and set $n = k$ (and solve the problem which requires us to buy all the shovels). Also, let's add an offer which allows us to buy $1$ shovel and get $0$ cheapest of them for free, to simulate that we can buy shovels without using offers.

Now we claim that if we sort all the shovels by their costs, it's optimal to divide the array of costs into some consecutive subarrays and buy each subarray using some offer. Why should the sets of shovels for all purchases be consecutive subarrays? Suppose it's not so: let's pick two purchases such that they are "mixed" in the array of costs, i. e. there exists at least one shovel $A$ bought in the first purchase such that there exists a shovel $B$ cheaper than it and a shovel $C$ more expensive than it, both bought in the second purchase. If shovel $A$ is for free, then we may "swap" shovels $A$ and $C$, otherwise we may swap shovels $A$ and $B$, and the answer won't become worse. So, we can do it until all purchases correspond to subsegments in the array of costs.

Then it's easy to see that we can make purchases in such a way that we always buy some amount of cheapest shovels. And now the problem can be solved by knapsack-like dynamic programming: let $dp_i$ be the minimum cost to buy exactly $i$ cheapest shovels. $dp_0$ is $0$, and for each offer $(x, y)$ we can update $dp_{i + x}$ by the value of $dp_i + sum(i + y + 1, i + x)$, where $sum(l, r)$ is the sum of costs of all shovels in the sorted order from shovel on position $l$ to shovel on position $r$, inclusive (these sums can be calculated in $O(1)$ using partial sums method).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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
	
	sort(a.begin(), a.end());
	a.resize(k);
	reverse(a.begin(), a.end());
	
	vector<int> offers(k + 1);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (x <= k) {
			offers[x] = max(offers[x], y);
		}
	}
	
	vector<int> pref(k + 1);
	for (int i = 0; i < k; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	
	vector<int> dp(k + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < k; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
		for (int j = 1; j <= k; ++j) {
			if (offers[j] == 0) continue;
			if (i + j > k) break;
			dp[i + j] = min(dp[i + j], dp[i] + pref[i + j - offers[j]] - pref[i]);
		}
	}
	
	cout << dp[k] << endl;
	
	return 0;
}
```
[1154G - Minimum Possible LCM](../problems/G._Minimum_Possible_LCM.md "Codeforces Round 552 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1154G - Minimum Possible LCM](../problems/G._Minimum_Possible_LCM.md "Codeforces Round 552 (Div. 3)")

I've heard about some very easy solutions with time complexity $O(a \log a)$, where $a$ is the maximum value of $a_i$, but I will describe my solution with time complexity $O(nd)$, where $d$ is the maximum number of divisors of $a_i$.

A very good upper-bound approximation of the number of divisors of $x$ is $\sqrt[3]{x}$ so my solution works in $O(n \sqrt[3]{a})$.

Firstly, let's talk about the idea. The main idea is the following: for each number from $1$ to $10^7$, we want to find two minimum numbers in the array which are divisible by this number. Then we can find the answer among all such divisors that have at least two multiples in the array.

Let's write a function $add(idx)$ which will try to add the number $a_{idx}$ to all its divisors. The easiest way to do it is iterate over all divisors in time $O(\sqrt{a_{idx}})$ and add it somehow. But it is too slow. Let's improve it somehow. How can we skip numbers that aren't divisors of $a_{idx}$? Let's build an Eratosthenes sieve (I highly recommended one with time complexity $O(n)$ because the sieve with time complexity $O(n \log \log n)$ is about twice slower on such constraints) which will maintain the minimum divisor for each number from $1$ to $10^7$ (the linear sieve builds this array automatically in its implementation). Then we can factorize the number in $O(\log a_{idx})$ and iterate over all its divisors using simple recursive function.

And the last thing I should notice — this solution can give TLE and require some constant optimizations. I recommended to use pair of integers (or arrays of size two) for each divisor and to add numbers using a few if-statements.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 10 * 1000 * 1000 + 11;

int n;
vector<int> a;

int mind[N];

pair<int, int> mins[N];
vector<pair<int, int>> divs;

void build_sieve() {
	vector<int> pr;
	mind[0] = mind[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (mind[i] == 0) {
			pr.push_back(i);
			mind[i] = i;
		}
		for (int j = 0; j < int(pr.size()) && pr[j] <= mind[i] && i * pr[j] < N; ++j) {
			mind[i * pr[j]] = pr[j];
		}
	}
}


void add_to_mins(int curd, int idx) {
    if(mins[curd].first == -1)
        mins[curd].first = idx;
    else if(mins[curd].second == -1)
        mins[curd].second = idx;
}

void rec(int pos, int curd, int idx) {
	if (pos == int(divs.size())) {
		add_to_mins(curd, idx);
		return;
	}
	int curm = 1;
	for (int i = 0; i <= divs[pos].second; ++i) {
		rec(pos + 1, curd * curm, idx);
		curm *= divs[pos].first;
	}
}

void add(int idx) {
	int value = a[idx];
	divs.clear();
	while (value > 1) {
		int d = mind[value];
		if (!divs.empty() && divs.back().first == d) {
			++divs.back().second;
		} else {
			divs.push_back(make_pair(d, 1));
		}
		value /= d;
	}
	rec(0, 1, idx);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < N; i++)
	    mins[i] = make_pair(-1, -1);
	build_sieve();
	
	vector<pair<int, int> > vals;
	for(int i = 0; i < n; i++)
	    vals.push_back(make_pair(a[i], i));
	sort(vals.begin(), vals.end());
	for (int i = 0; i < n; ++i) {
	    if(i > 1 && vals[i].first == vals[i - 2].first) continue;
		add(vals[i].second);
	}
	
	long long l = INF * 1ll * INF;
	int ansi = -1, ansj = -1;
	for (int i = 1; i < N; ++i) {
		pair<int, int> idxs = mins[i];
		if (idxs.second == -1) continue;
		long long curl = a[idxs.first] * 1ll * a[idxs.second] / i;
		if (l > curl) {
			l = curl;
			ansi = min(idxs.first, idxs.second);
			ansj = max(idxs.first, idxs.second);
		}
	}
	
	cout << ansi + 1 << " " << ansj + 1 << endl;
	
	return 0;
}
```
