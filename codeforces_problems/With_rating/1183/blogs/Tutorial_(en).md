# Tutorial_(en)

[1183A - Nearest Interesting Number](../problems/A._Nearest_Interesting_Number.md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1183A - Nearest Interesting Number](../problems/A._Nearest_Interesting_Number.md "Codeforces Round 570 (Div. 3)")

Even if we will iterate over all possible numbers starting from a and check if sum of digits of the current number is divisible by 4, we will find the answer very fast. The maximum possible number of iterations is no more than 5.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int sum(int a) {
    int result = 0;
    while (a > 0) {
        result += a % 10;
        a /= 10;
    }
    return result;
}

int main() {
    int a;
    cin >> a;
    while (sum(a) % 4 != 0) {
        a++;
    }
    cout << a << endl;
}

```
[1183B - Equalize Prices](../problems/B._Equalize_Prices.md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1183B - Equalize Prices](../problems/B._Equalize_Prices.md "Codeforces Round 570 (Div. 3)")

It is very intuitive that the maximum price we can obtain is min+k where min is the minimum value in the array. For this price we should check that we can change prices of all products to it. It can be done very easily: we can just check if each segment [ai−k;ai+k] covers the point min+k. But this is not necessary because if we can change the price of the maximum to this value (min+k) then we can change each price in the segment [min;max] to this value. So we just need to check that min+k≥max−k and if it is then print min+k otherwise print -1.

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
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
		}
		int mn = *min_element(a.begin(), a.end());
		int mx = *max_element(a.begin(), a.end());
		if (mx - mn > 2 * k) cout << -1 << endl;
		else cout << mn + k << endl;
	}
	
	return 0;
}
```
[1183C - Computer Game](../problems/C._Computer_Game.md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh") and [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1183C - Computer Game](../problems/C._Computer_Game.md "Codeforces Round 570 (Div. 3)")

Firstly, about the problem description. Vova really needs to complete the game i. e. play all $n$ turns. Exactly $n$ turns. Among all possible ways to do it he need choose one where the number of turns when he just plays (this is the first type turn!) is maximum possible.

Suppose the answer is $n$. Then the charge of the battery after $n$ turns will be $c = k - na$. If this value is greater than $0$ then the answer is $n$. Otherwise we need to replace some turns when Vova just plays with turns when Vova plays and charges. The charge of the battery will increase by $diff = a - b$ avfter one replacement. We have to obtain $c > 0$ with some replacements. The number of turns to do it is equals to $turns = \lceil\frac{-c + 1}{diff}\rceil$, where $\lceil\frac{x}{y}\rceil$ is $x$ divided by $y$ rounded up. If $turns > n$ then the answer is -1. Otherwise the answer is $n - turns$.

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
		long long k, n, a, b;
		cin >> k >> n >> a >> b;
		k -= n * a;
		if (k > 0) {
			cout << n << endl;
		} else {
			k = -k;
			++k;
			long long diff = a - b;
			long long turns = (k + diff - 1) / diff;
			if (turns > n) {
				cout << -1 << 'n';
			} else {
				cout << n - turns << 'n';
			}
		}
	}
	
	return 0;
}
```
[1183D - Candy Box (easy version)](../problems/D._Candy_Box_(easy_version).md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1183D - Candy Box (easy version)](../problems/D._Candy_Box_(easy_version).md "Codeforces Round 570 (Div. 3)")

Let's calculate the array $cnt$ where $cnt_i$ is the number of candies of the $i$-th type. Let's sort it in non-ascending order.

Obviously, now we can take $cnt_1$ because this is the maximum number of candies of some type in the array. Let $lst$ be the last number of candies we take. Initially it equals $cnt_1$ (and the answer $ans$ is initially the same number). Then let's iterate over all values of $cnt$ in order from left to right. If the current number $cnt_i$ is greater than or equal to the last taken number of candies $lst$ then we cannot take more candies than $lst - 1$ (because we iterating over values of $cnt$ in non-ascending order), so let's increase answer by $lst - 1$ and set $lst := lst - 1$. Otherwise $cnt_i < lst$ and we can take all candies of this type, increase the answer by $cnt_i$ and set $lst := cnt_i$.

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
	for (int t = 0; t < q; ++t) {
		int n;
		cin >> n;
		vector<int> cnt(n + 1);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++cnt[x];
		}
		sort(cnt.rbegin(), cnt.rend());
		int ans = cnt[0];
		int lst = cnt[0];
		for (int i = 1; i <= n; ++i) {
			if (lst == 0) break;
			if (cnt[i] >= lst) {
				ans += lst - 1;
				lst -= 1;
			} else {
				ans += cnt[i];
				lst = cnt[i];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1183E - Subsequences (easy version)](../problems/E._Subsequences_(easy_version).md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1183E - Subsequences (easy version)](../problems/E._Subsequences_(easy_version).md "Codeforces Round 570 (Div. 3)")

The topic of this problem is BFS. Let strings be the vertices of the graph and there is a directed edge from string $s$ to string $t$ if and only if we can obtain $t$ from $s$ by removing exactly one character.

In this interpretation we have to find first $k$ visited vertices if we start our BFS from the initial string. And then the answer will be just $nk$ minus the sum of length of visited strings. The last thing to mention: instead of standard queue of integers we need to maintain the queue of strings and instead of array of visited vertices we have to maintain the set of visited strings. Don't forget to stop BFS when you obtain exactly $k$ strings.

If the number of distinct subsequences is less than $k$ then the answer is -1.

 **Solution**
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
	string s;
	cin >> s;
	
	int ans = 0;
	queue<string> q;
	set<string> st;
	q.push(s);
	st.insert(s);
	while (!q.empty() && int(st.size()) < k) {
		string v = q.front();
		q.pop();
		for (int i = 0; i < int(v.size()); ++i) {
			string nv = v;
			nv.erase(i, 1);
			if (!st.count(nv) && int(st.size()) + 1 <= k) {
				q.push(nv);
				st.insert(nv);
				ans += n - nv.size();
			}
		}
	}
	
	if (int(st.size()) < k) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
```
[1183F - Topforces Strikes Back](../problems/F._Topforces_Strikes_Back.md "Codeforces Round 570 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1183F - Topforces Strikes Back](../problems/F._Topforces_Strikes_Back.md "Codeforces Round 570 (Div. 3)")

I know about some solutions that are trying to iterate over almost all possible triples, but I have a better and more interesting one. Possibly, it was already mentioned in comments, but I need to explain it.

Let's solve the problem greedily. Let's sort the initial array. The first number we would like to choose is the maximum element. Then we need to pop out some maximum elements that are divisors of the maximum. Then there are two cases: the array becomes empty, or we have some maximum number that does not divide the chosen number. Let's take it and repeat the same procedure again, but now we have to find the number that does not divide neither the first taken number nor the second taken number.

So we have at most three numbers after this procedure. Let's update the answer with their sum. This solution is almost correct. Almost! What have we forgotten? Let's imagine that the maximum element is divisible by $2$, $3$ and $5$ and there are three following numbers in the array: maximum divided by $2$, by $3$ and by $5$. Then their sum is greater than the maximum (and may be greater than the answer we have!) because $\frac{1}{2} + \frac{1}{3} + \frac{1}{5} > 1$. So if these conditions are satisfied, let's update the answer with the sum of these three numbers.

It can be shown that this is the only possible triple that can break our solution. The triple $2, 3, 4$ does not match because the maximum divided by $4$ divides the maximum divided by $2$. The triple $2, 3, 6$ is bad for the same reason. And the triple $2, 3, 7$ has sum less than the maximum element.

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
		int n;
		cin >> n;
		set<int> st;
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			st.insert(x);
		}
		
		int ans = 0;
		int mx = *st.rbegin();
		if (mx % 2 == 0 && mx % 3 == 0 && mx % 5 == 0) {
			if (st.count(mx / 2) && st.count(mx / 3) && st.count(mx / 5)) {
				ans = max(ans, mx / 2 + mx / 3 + mx / 5);
			}
		}
		
		vector<int> res;
		while (!st.empty() && int(res.size()) < 3) {
			int x = *st.rbegin();
			st.erase(prev(st.end()));
			bool ok = true;
			for (auto it : res) ok &= (it % x != 0);
			if (ok) res.push_back(x);
		}
		
		ans = max(ans, accumulate(res.begin(), res.end(), 0));
		
		cout << ans << endl;
	}
	
	return 0;
}
```
[1183G - Candy Box (hard version)](../problems/G._Candy_Box_(hard_version).md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1183G - Candy Box (hard version)](../problems/G._Candy_Box_(hard_version).md "Codeforces Round 570 (Div. 3)")

First of all, to maximize the number of candies in the gift, we can use the following greedy algorithm: let's iterate on the number of candies of some type we take from $n$ to $1$ backwards. For fixed $i$, let's try to find any suitable type of candies. A type is suitable if there are at least $i$ candies of this type in the box. If there exists at least one such type that wasn't used previously, let's pick any such type and take exactly $i$ candies of this type (and decrease $i$). It does not matter which type we pick if we only want to maximize the number of candies we take.

Okay, let's now modify this solution to maximize the number of candies having $f_i = 1$. We initially could pick any type that has at least $i$ candies, but now we should choose a type depending on the number of candies with $f_i = 1$ in this type. For example, if we have two types having $x_1$ and $x_2$ candies with $f_i = 1$ respectively, and we want to pick $i_1$ candies from one type and $i_2$ candies from another type, and $x_1 > x_2$ and $i_1 > i_2$, it's better to pick $i_1$ candies of the first type and $i_2$ candies of the second type. In this case we have $min(x_1, i_1) + min(x_2, i_2)$ candies with $f_i = 1$, in the other case it's $min(x_2, i_1) + min(x_1, i_2)$. And if $x_1 > x_2$ and $i_1 > i_2$, then $min(x_1, i_1) + min(x_2, i_2) \ge min(x_2, i_1) + min(x_1, i_2)$. So, when we want to pick a type of candies such that we will take exactly $i$ candies of this type, it's optimal to choose a type that wasn't used yet, contains at least $i$ candies, and has maximum possible number of candies with $f_i = 1$. This best type can be maintained with a multiset or a set of pairs.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	vector<int> cnt(n);
	vector<int> cnt_good(n);
	for(int i = 0; i < n; i++)
	{
		int a, f;
		scanf("%d %d", &a, &f);
		--a;
		cnt[a]++;
		if(f) cnt_good[a]++;
	}
	vector<vector<int> > types(n + 1);
	for(int i = 0; i < n; i++)
		types[cnt[i]].push_back(cnt_good[i]);
	int ans1 = 0;
	int ans2 = 0;
	multiset<int> cur;
	for(int i = n; i > 0; i--)
	{
		for(auto x : types[i]) cur.insert(x);
		if(!cur.empty())
		{
			int z = *cur.rbegin();
			ans1 += i;
			ans2 += min(i, z);
			cur.erase(cur.find(z));
		}
	}
	printf("%d %dn", ans1, ans2);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve();
}
```
[1183H - Subsequences (hard version)](../problems/H._Subsequences_(hard_version).md "Codeforces Round 570 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1183H - Subsequences (hard version)](../problems/H._Subsequences_(hard_version).md "Codeforces Round 570 (Div. 3)")

Firstly, let's calculate the following auxiliary matrix: $lst_{i, j}$ means the maximum position $pos$ that is less than or equal to $i$, and the character $s_{pos} = j$ (in order from $0$ to $25$, 'a' = $0$, 'b' = $1$, and so on). It can be calculated naively or with some easy dynamic programming (initially all $lst_{i, j}$ are $-1$ and then for each $i$ from $1$ to $n-1$ all values $lst_{i, j}$ are equal to $lst_{i - 1, j}$ except $lst_{i, s_i}$ which is $i$).

After calculating this matrix we can solve the problem by the following dynamic programming: let $dp_{i, j}$ be the number of subsequences of length $j$ that ends exactly in the position $i$. Initially all values are zeros except $dp_{i, 1} = 1$ for each $i$ from $0$ to $n-1$.

How do we perform transitionss? Let's iterate over all lengths $j$ from $2$ to $n$, then let's iterate over all positions $i$ from $1$ to $n-1$ in a nested loop, and for the current state $dp_{i, j}$ we can calculate it as $\sum\limits_{c=0}^{25}dp_{lst_{i - 1, c}},{j - 1}$. If $lst_{i - 1, c} = -1$ then we don't need to add this state of the dynamic programming to the current state. Don't forget to take the minimum with $10^{12}$ after each transition!

This transition means that we take all subsequences that end with each possible character of the alphabet and try to add the current character to each of them. You can understand that there are no overlapping subsequences in this dynamic programming.

After that let's iterate over all possible lengths $j$ from $n$ to $1$ and calculate the number of subsequences of the current length $j$. It equals to $cnt = \sum\limits_{c=0}^{25}dp_{lst_{n - 1, c}, j}$. The same, if $lst_{n - 1, c} = -1$ then we don't need to add this state of the dynamic programming to $cnt$. Don't forget to take the minimum with $10^{12}$! If $cnt \ge k$ then let's add $k(n - len)$ to the answer and break the cycle. Otherwise let's add $cnt(n - len)$ to the answer and decrease $k$ by $cnt$.

If after all iterations $k$ is greater than zero then let's try to add the empty string to the answer (we didn't take it into account earlier). Increase the answer by $n$ and decrease $k$ by one. If after this $k$ is still greater than zero then the answer is -1, otherwise the answer is the calculated sum.

Time complexity: $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e12;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	long long k;
	cin >> n >> k;
	--k; // the whole string costs nothing
	string s;
	cin >> s;
	
	vector<vector<int>> lst(n, vector<int>(26, -1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (i > 0) lst[i][j] = lst[i - 1][j];
		}
		lst[i][s[i] - 'a'] = i;
	}
	
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
	for (int i = 0; i < n; ++i) {
		dp[i][1] = 1;
	}
	
	for (int len = 2; len < n; ++len) {
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 26; ++j) {
				if (lst[i - 1][j] != -1) {
					dp[i][len] = min(INF64, dp[i][len] + dp[lst[i - 1][j]][len - 1]);
				}
			}
		}
	}
	
	long long ans = 0;
	for (int len = n - 1; len >= 1; --len) {
		long long cnt = 0;
		for (int j = 0; j < 26; ++j) {
			if (lst[n - 1][j] != -1) {
				cnt += dp[lst[n - 1][j]][len];
			}
		}
		if (cnt >= k) {
			ans += k * (n - len);
			k = 0;
			break;
		} else {
			ans += cnt * (n - len);
			k -= cnt;
		}
	}
	
	if (k == 1) {
		ans += n;
		--k;
	}
	
	if (k > 0) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
```
