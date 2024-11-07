# Tutorial

I'm so thankful to all testers, especially to [Gassa](https://codeforces.com/profile/Gassa "Grandmaster Gassa") and [Rox](https://codeforces.com/profile/Rox "Candidate Master Rox") for their invaluable help!

[1409A - Yet Another Two Integers Problem](../problems/A._Yet_Another_Two_Integers_Problem.md "Codeforces Round 667 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1409A - Yet Another Two Integers Problem](../problems/A._Yet_Another_Two_Integers_Problem.md "Codeforces Round 667 (Div. 3)")

We can add or subtract $10$ until the difference between $a$ and $b$ becomes less than $10$. And if it is not $0$ after all such moves, we need one additional move.

Let $d = |a - b|$ is the absolute difference between $a$ and $b$. The final answer is $\left\lfloor\frac{d}{10}\right\rfloor$ plus one if $d \mod 10 > 0$. This formula can be represented as $d$ divided by $10$ rounded up, in other words $\left\lfloor\frac{d+9}{10}\right\rfloor$.

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
		int a, b;
		cin >> a >> b;
		cout << (abs(a - b) + 9) / 10 << endl;
	}
	
	return 0;
}
```
[1409B - Minimum Product](../problems/B._Minimum_Product.md "Codeforces Round 667 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1409B - Minimum Product](../problems/B._Minimum_Product.md "Codeforces Round 667 (Div. 3)")

The only fact required to solve the problem: if we start decreasing the number, we are better to end decreasing it and only then decrease the other number. So, we can just consider two cases: when we decrease $a$ first, and $b$ after that and vice versa, and just take the minimum product of these two results. The rest is just implementation.

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
		int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		long long ans = 1e18;
		for (int i = 0; i < 2; ++i) {
			int da = min(n, a - x);
			int db = min(n - da, b - y);
			ans = min(ans, (a - da) * 1ll * (b - db));
			swap(a, b);
			swap(x, y);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1409C - Yet Another Array Restoration](../problems/C._Yet_Another_Array_Restoration.md "Codeforces Round 667 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1409C - Yet Another Array Restoration](../problems/C._Yet_Another_Array_Restoration.md "Codeforces Round 667 (Div. 3)")

The only fact required to solve this problem is just to notice that the answer array is just an arithmetic progression. After that, we can fix the first element $start$, fix the difference $d$, construct the array $[start, start + d, start + 2d, \dots, start + d \cdot (n-1)]$, check if $x$ and $y$ are in this array and, if yes, update the answer with $start + d \cdot (n-1)$. This is $O(n^3)$ solution.

There are faster solutions, though. Other author's solution is $O(n \sqrt{y})$ but I didn't want to make this problem harder, so I allowed $O(n^3)$ solutions.

It is obvious that the difference of the progression is some divisor of $y-x$. Let it be $d$. Let's add some elements starting from $y$ "to the left" ($y, y-d, y-2d$ and so on) and stop if we reach $n$ elements or the next element is less than $1$. If we didn't find $x$ among these elements, just skip this difference, it is useless for us. Otherwise, if we have less than $n$ elements, let's add $y+d, y+2d, y+3d$ and so on until we get $n$ elements. And then update the answer with the maximum element of the array.

There is also a solution in $O(n + \sqrt{y})$ with some greedy observations :)

 **Solution (Gassa)**
```cpp
// Author: Ivan Kazmenko (gassa@mail.ru)
module solution;
import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.string;

void main ()
{
	auto tests = readln.strip.to !(int);
	foreach (test; 0..tests)
	{
		int n, x, y;
		readf !(" %s %s %s") (n, x, y);
		auto answer = int.max.repeat (n).array;
		foreach (start; 1..51)
		{
			foreach (d; 1..51)
			{
				auto a = iota (start, start + d * n, d).array;
				if (a.canFind (x) && a.canFind (y))
				{
					if (answer.back > a.back)
					{
						answer = a;
					}
				}
			}
		}
		writefln !("%(%s %)") (answer);
	}
}
```
 **Solution (vovuh)**
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
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> ans;
		for (int d = 1; d <= y - x; ++d) {
			if ((y - x) % d != 0) continue;
			vector<int> res;
			bool foundx = false;
			int cur = y;
			int need = n;
			while (cur >= 1 && need > 0) {
				res.push_back(cur);
				foundx |= cur == x;
				--need;
				cur -= d;
			}
			cur = y;
			while (need > 0) {
				cur += d;
				res.push_back(cur);
				--need;
			}
			sort(res.begin(), res.end());
			if (need == 0 && foundx) {
				if (ans.empty() || ans.back() > res.back()) {
					ans = res;
				}
			}
		}
		assert(!ans.empty());
		for (auto it : ans) cout << it << " ";
		cout << endl;
		
	}
	
	return 0;
}
```
 **Solution (Rox)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    while (tcs--) {
        int n, x, y;
        cin >> n >> x >> y;
        int diff = y - x;
        for (int delta = 1; delta <= diff; ++delta) {
            if (diff % delta) continue;
            if (diff / delta + 1 > n) continue;
            int k = min((y - 1) / delta, n - 1);
            int a0 = y - k * delta;
            for (int i = 0; i < n; ++i) {
                cout << (a0 + i * delta) << ' ';
            }
            cout << endl;
            break;
        }
    }
}
```
[1409D - Decrease the Sum of Digits](../problems/D._Decrease_the_Sum_of_Digits.md "Codeforces Round 667 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1409D - Decrease the Sum of Digits](../problems/D._Decrease_the_Sum_of_Digits.md "Codeforces Round 667 (Div. 3)")

Firstly, let's check if the initial $n$ fits the conditions. If it is, print $0$ and continue. Otherwise, let's solve the problem greedily. At first, let's try to set the last digit to zero. Let $dig = n \mod 10$. We need exactly $(10 - dig) \mod 10$ moves to do that. Let's add this number to $n$ and to the answer and check if the current $n$ fits the conditions. If it isn't, let's try to set the previous last digit to zero. Let $dig = \left\lfloor\frac{n}{10}\right\rfloor \mod 10$. Then we need $((10 - dig) \mod 10) \cdot 10$ moves to do that. Let's add this number to $n$ and to the answer and check if the current $n$ fits the conditions. If it isn't, repeat the same with the third digit and so on. This cycle can do no more than $18$ iterations. And we can fing the sum of digits of $n$ in at most $18$ iterations too (decimal logarithm of $n$).

So, the total time complexity is $O(\log_{10}^2{(n)})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int sum(long long n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		long long n;
		int s;
		cin >> n >> s;
		long long ans = 0;
		if (sum(n) <= s) {
			cout << 0 << endl;
			continue;
		}
		long long pw = 1;
		for (int i = 0; i < 18; ++i) {
			int digit = (n / pw) % 10;
			long long add = pw * ((10 - digit) % 10);
			n += add;
			ans += add;
			if (sum(n) <= s) {
				break;
			}
			pw *= 10;
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1409E - Two Platforms](../problems/E._Two_Platforms.md "Codeforces Round 667 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1409E - Two Platforms](../problems/E._Two_Platforms.md "Codeforces Round 667 (Div. 3)")

Firstly, we obviously don't need $y$-coordinates at all because we can place both platforms at $y=-\infty$. Let's sort all $x$-coordinates in non-decreasing order.

Calculate for each point $i$ two values $l_i$ and $r_i$, where $l_i$ is the number of points to the left from the point $i$ (including $i$) that are not further than $k$ from the $i$-th point (i.e. the number of such points $j$ that $|x_i - x_j| \le k$). And $r_i$ is the number of points to the right from the point $i$ (including $i$) that are not further than $k$ from the $i$-th point. Both these parts can be done in $O(n)$ using two pointers.

Then let's build suffix maximum array on $r$ and prefix maximum array on $l$. For $l$, just iterate over all $i$ from $2$ to $n$ and do $l_i := max(l_i, l_{i-1})$. For $r$, just iterate over all $i$ from $n-1$ to $1$ and do $r_i := max(r_i, r_{i + 1})$.

The question is: what? What did we do? We did the following thing: the answer always can be represented as two non-intersecting segments of length $k$ such that at least one endpoint of each segment is some input point (except the case $n=1$). Now, let's fix this border between segments. Iterate over all $i$ from $1$ to $n-1$ and update the answer with $max(l_{i}, r_{i + 1})$. So we took some segment that starts at some point to the left from $i$ (including $i$) and goes to the left and took some segment that starts further than $i+1$ (including $i+1$) and goes to the right. With this model, we considered all optimal answers that can exist.

Time complexity: $O(n \log{n})$.

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
		int n, k;
		cin >> n >> k;
		vector<int> x(n), y(n);
		for (auto &it : x) cin >> it;
		for (auto &it : y) cin >> it;
		sort(x.begin(), x.end());
		int j = n - 1;
		vector<int> l(n), r(n);
		for (int i = n - 1; i >= 0; --i) {
			while (x[j] - x[i] > k) --j;
			r[i] = j - i + 1;
			if (i + 1 < n) r[i] = max(r[i], r[i + 1]);
		}
		j = 0;
		for (int i = 0; i < n; ++i) {
			while (x[i] - x[j] > k) ++j;
			l[i] = i - j + 1;
			if (i > 0) l[i] = max(l[i], l[i - 1]);
		}
		int ans = 1;
		for (int i = 0; i < n - 1; ++i) {
			ans = max(ans, r[i + 1] + l[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
```
[1409F - Subsequences of Length Two](../problems/F._Subsequences_of_Length_Two.md "Codeforces Round 667 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1409F - Subsequences of Length Two](../problems/F._Subsequences_of_Length_Two.md "Codeforces Round 667 (Div. 3)")

I'm almost sure this problem can be solved faster and with greater constraints but this version is fine for the last problem.

Consider both strings $0$-indexed and let's do the dynamic programming $dp_{i, j, cnt_0}$. It means the maximum number of occurrences of $t$ if we considered first $i$ characters of $s$, did $j$ moves and the number of characters $t_0$ is $cnt_0$. The answer to the problem is $\max\limits_{ck=0}^{k} \max\limits_{cnt_0=0}^{n} dp_{n, ck, cnt_0}$. Initially all states are $-\infty$ and $dp_{0, 0, 0}$ is $0$. What about transitions? There are essentially three types of them: don't change the current character, change the current character to $t_0$ and change the current character to $t_1$.

Let's create three additional variables to make our life easier (if that were true...). $e_0$ is $1$ if $s_i = t_0$ and $0$ otherwise, $e_1$ is $1$ if $s_i = t_1$ and $0$ otherwise and $e_{01}$ is $1$ if $t_0 = t_1$ and $0$ otherwise. Now let's make and describe our transitions:

* Don't change the $i$-th character:$dp_{i + 1, ck, cnt_0 + e_0} = max(dp_{i + 1, ck, cnt_0 + e_0}, dp_{i, ck, cnt_0} + (e_1~ ?~ cnt_0 : 0))$.

The expression $x~ ?~ y : z$ is just ternary if statement: if $x$ is true, return $y$, otherwise return $z$. So, the number of characters $t_0$ increases if $s_i$ equals $t_0$ and the answer increases if the $i$-th character equals $t_1$ (because we added all occurrences that end in the $i$-th character).
* Change the $i$-th character to $t_0$ (possible only when $ck < k$):$dp_{i + 1, ck + 1, cnt_0 + 1} = max(dp_{i + 1, ck + 1, cnt_0 + 1}, dp_{i, ck, cnt_0} + (e_{01}~ ?~ cnt_0 : 0))$.

The number of characters $t_0$ always increases and the answer increases if $t_0$ equals $t_1$ by the same reason as in the previous transition.
* Change the $i$-th character to $t_1$ (possible only when $ck < k$):$dp_{i + 1, ck + 1, cnt_0 + e_{01}} = max(dp_{i + 1, ck + 1, cnt_0 + e_{01}}, dp_{i, ck, cnt_0} + cnt_0)$.

The number of characters $t_0$ increases only if $t_0 = t_1$ and the answer always increases.

Note that we always increase the number of moves in the second and the third transitions even when $s_i$ equals $t_0$ or $t_1$ because this case is handled in the first transition, so we don't care.

Time complexity: $O(n^3)$.

There are also some greedy approaches which work in $O(n^4)$ with pretty small constant and can be optimized even further.

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
	
	int n, k;
	string s, t;
	cin >> n >> k >> s >> t;
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -INF)));
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int ck = 0; ck <= k; ++ck) {
			for (int cnt0 = 0; cnt0 <= n; ++cnt0) {
				if (dp[i][ck][cnt0] == -INF) continue;
				int e0 = s[i] == t[0];
				int e1 = s[i] == t[1];
				int e01 = t[0] == t[1];
				
				dp[i + 1][ck][cnt0 + e0] = max(dp[i + 1][ck][cnt0 + e0], dp[i][ck][cnt0] + (e1 ? cnt0 : 0));
				
				if (ck < k) {
					dp[i + 1][ck + 1][cnt0 + 1] = max(dp[i + 1][ck + 1][cnt0 + 1], dp[i][ck][cnt0] + (e01 ? cnt0 : 0));
					dp[i + 1][ck + 1][cnt0 + e01] = max(dp[i + 1][ck + 1][cnt0 + e01], dp[i][ck][cnt0] + cnt0);
				}
			}
		}
	}
	
	int ans = 0;
	for (int ck = 0; ck <= k; ++ck) {
		for (int cnt0 = 0; cnt0 <= n; ++cnt0) {
			ans = max(ans, dp[n][ck][cnt0]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **Solution (Gassa, greedy, O(n^4))**
```cpp
// Author: Ivan Kazmenko (gassa@mail.ru)
module solution;
import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.string;

void main ()
{
	int n, k;
	while (readf !(" %s %s") (n, k) > 0)
	{
		readln;
		auto s0 = readln.strip;
		auto t = readln.strip;
		auto s = s0.dup;
		int res = 0;
		foreach (b0; 0..k + 1)
		{
			auto e0 = k - b0;
loop_x0:
			foreach (x0; 0..b0 + 1)
			{
loop_y0:
				foreach (y0; 0..e0 + 1)
				{
					int b = b0;
					int e = e0;
					int x = x0;
					int y = y0;
					s[] = s0[];
					for (int i = 0; i < n && b; i++)
					{
						if (s[i] == t[0])
						{
						}
						else if (s[i] != t[1])
						{
							s[i] = t[0];
							b -= 1;
						}
						else if (x > 0)
						{
							s[i] = t[0];
							x -= 1;
							b -= 1;
						}
					}

					for (int j = n - 1; j >= 0 && e; j--)
					{
						if (s[j] == t[1])
						{
						}
						else if (s[j] != t[0])
						{
							s[j] = t[1];
							e -= 1;
						}
						else if (y > 0)
						{
							s[j] = t[1];
							y -= 1;
							e -= 1;
						}
					}

					int cur = 0;
					int add = 0;
					for (int i = 0; i < n; i++)
					{
						if (s[i] == t[1])
						{
							cur += add;
						}
						if (s[i] == t[0])
						{
							add += 1;
						}
					}
					res = max (res, cur);

					if (x > 0)
					{
						break loop_x0;
					}
					if (y > 0)
					{
						break loop_y0;
					}
				}
			}
		}

		writeln (res);
	}
}
```
