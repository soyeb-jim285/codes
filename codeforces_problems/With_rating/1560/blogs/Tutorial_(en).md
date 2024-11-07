# Tutorial_(en)

Ideas: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

[1560A - Dislike of Threes](../problems/A._Dislike_of_Threes.md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560A - Dislike of Threes](../problems/A._Dislike_of_Threes.md "Codeforces Round 739 (Div. 3)")

The solution is simple: let's create an integer variable (initially set to $0$) that will contain the number of considered liked integers. Let's iterate over all positive integers starting with $1$. Let's increase the variable only when the considered number is liked. If the variable is equal to $k$, let's stop the iteration and output the last considered number.

Since the answer for $k = 1000$ is $x = 1666$, the count of considered numbers is at most $1666$ so the solution will work on the specified limitations fast enough.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		for (int i = 1; ; i++)
		{
			if (i % 3 == 0 || i % 10 == 3)
				continue;
			if (--k == 0)
			{
				cout << i << 'n';
				break;
			}
		}
	}
}
```
[1560B - Who's Opposite?](../problems/B._Who's_Opposite_.md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560B - Who's Opposite?](../problems/B._Who's_Opposite_.md "Codeforces Round 739 (Div. 3)")

The person with the number $a$ looks at the person with the number $b$ so the count of people standing to the left of $a$ between $a$ and $b$ is equal to the count of people standing to the right of $a$ between $a$ and $b$. Therefore, both counts are equal to $\frac{n - 2}{2}$, hence $n$ must be a solution of the equation $\frac{n - 2}{2} = |a - b| - 1$. The only solution of the equation is $n = 2 \cdot |a - b|$.

Let's check that in the circle of $n$ people can occur the numbers $a$, $b$ and $c$, i. e. let's check that $1 \le a, b, c \le n$. If it's false, there's no solution (output $-1$).

Since the person with the number $d$ looks at the person with the number $c$, the condition $\frac{n - 2}{2} = |c - d| - 1$ must be met. Let's solve the equation for $d$. There are two solutions:

* $d_1 = c + \frac{n}{2}$;
* $d_2 = c - \frac{n}{2}$.

We can output any of $d_i$ such that $1 \le d_i \le n$. It's easy to prove that exactly one of the solutions meets the condition.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		ll n = 2 * abs(a - b);
		if (a > n || b > n || c > n)
			cout << -1 << 'n';
		else
		{
			ll d = n / 2 + c;
			while (d > n) d -= n;
			cout << d << 'n';
		}
	}
	return 0;
}

```
[1560C - Infinity Table](../problems/C._Infinity_Table.md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560C - Infinity Table](../problems/C._Infinity_Table.md "Codeforces Round 739 (Div. 3)")

Let's call a set of cells being filled from the topmost row to the leftmost column a layer. E. g. the $1$-st layer consists of the single number $1$, the $2$-nd layer consists of the numbers $2$, $3$ and $4$, the $3$-rd layer consists of the numbers $5$, $6$, $7$, $8$ and $9$, etc.

The number of cells in layers forms an arithmetic progression. The first layer consists of $a_1 = 1$ cells, the $i$-th layer consists of $a_i = a_{i-1} + 2$ cells. The minimum number in the $i$-th layer $x_i$ is equal to the sum of sizes of all layers from the $1$-st to the $(i - 1)$-th plus $1$.

Suppose that $k$ belongs to the $i$-th layer. Consider the value of $m = k - x_i + 1$. Polycarp fills exactly $i$ cells on the $i$-th layer before he starts filling the cells from the right to the left (i. e. while he goes down). Therefore, if $m \le i$, the number $k$ belongs to the $m$-th row and the $i$-th column. Otherwise, the number belongs to the $i$-th row and the $(i - (m - i))$-th column.

Consider a way to find the coordinates of a given number $k$. Let's iterate by the layer number $i$ to which given the number belongs calculating the values of $a_i$ and $x_i$ (going to the next layer, let's calculate the next layer parameters as follows: $x_{i + 1} := x_i + a_i$; $a_{i + 1} := a_i + 2$). The iteration must be stopped if the layer number $i$ is such that $x_i \le k < x_{i + 1}$. Using the values of $i$ and $x_i$, we can calculate the given number's coordinates in the described way in $O(1)$. The total time of calculating the coodrinates for one given $k$ is $O(i_k)$ where $i_k$ is the number of the layer to which the given $k$ belongs.

Let's represent the value of $x_i$ as $x_i = f(i)$: $x_i = 1 + \sum\limits_{j = 1}^{i - 1} a_j = 1 + \sum\limits_{j = 1}^{i - 1} (2j - 1) = 1 + \frac{1 + 2(i - 1) - 1}{2} \cdot (i - 1) = 1 + (i - 1)^2$. $1 + (i_k - 1)^2 = x_{i_k} \le k < x_{i_k + 1} = 1 + i_k^2$, hence $i_k \approx \sqrt(k)$. Therefore, the coordinates of one number $k$ may be calculated in $O(\sqrt{k})$. At the same time, as it follows from the formulas, the layer number $i_k$ can be calculated as follows: $i_k = \lceil \sqrt{k} \rceil$ (the square root of $k$ rounded up). To avoid accuracy problems, you can calculate the value using a loop.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		int a = 1;
		int x = 1;
		int i = 1;

		while (k >= x + a)
		{
			x += a;
			a += 2;
			i += 1;
		}

		int m = k - x + 1;
		if (m <= i)
			cout << m << ' ' << i << 'n';
		else
			cout << i << ' ' << (i - (m - i)) << 'n';
	}
}


```
[1560D - Make a Power of Two](../problems/D._Make_a_Power_of_Two.md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560D - Make a Power of Two](../problems/D._Make_a_Power_of_Two.md "Codeforces Round 739 (Div. 3)")

Suppose we must turn $n$ into some specific number $x$. In this case, we can use the following greedy algorithm. Consider the string forms — $s_n$ and $s_x$ — of the numbers $n$ and $x$, respectively. Let's make a pointer $p_n$ pointing at the first character of the string $s_n$ and a pointer $p_x$ pointing at the first character of the string $s_x$. Let's initialize a variable $taken = 0$ in which we will store a number of selected characters. Until any of the pointers points at the place that is out of the corresponding string, let's do the following procedure: if the characters to which the pointers point are equal, we will take the character (increase $taken$ by $1$) and move both pointers $1$ character to the right, otherwise, the only action we must perform is to move $s_n$ $1$ character to the right. The variable $taken$ will contain after the whole process the length of the longest subsequence of $s_n$ equal to a prefix of $s_x$, i. e. the maximum number of original characters of $s_n$ that we will not erase. We must add to the resulting string all remaining characters of $s_x$ to turn it into $s_x$. Therefore, we must erase $|s_n| - taken$ digits and add $|s_x| - taken$ digits so the answer for this subproblem is $ans(n, x) = |s_n| + |s_x| - 2 \cdot taken$ where $|s|$ means the length of a string $s$.

Suppose we have a set $X$ of powers of two such that it's enough to consider to get the problem's answer. The problem can be solved as follows: for each $x \in X$ let's calculate the answer for the subproblem described above and select the value of $\min\limits_{x \in X} ans(n,x)$ as the answer.

What set of powers of two we can take? Suppose the number $n$ consists of no more than $9$ digits. The answer for each $n$ consisting of $d$ digits doesn't exceed $d + 1$, hence we can get this value by turning the number into $1$ in $d + 1$ move adding $1$ to the right of the number, and erasing all other $d$ digits. Suppose there's a number $x$ such that $ans(n, x) \le d$. So it consists of no more than $2 \cdot d$ digits — this value can be reached as follows: we must not erase any digit and add $d$ digits. Therefore, if $d \le 9$, each number $x$ such that $ans(n, x) \le d$ consists of no more than $18$ digits, hence $x < 10^{18}$.

Suppose $n$ consists of more than $9$ digits. Then $n = 10^9$ because $n \le 10^9$ according to the input format. The answer for the number doesn't exceed $9$ — we can get this answer if we erase all $0$ from the number to turn it into $1$. Suppose there's a number $x$ such that $ans(n, x) \le 8$. This number can consist of no more than $18$ digits ($10$ digits of $n$ plus $8$ digits), hence $x < 10^{18}$.

Therefore, it's enough to consider all powers of two that are less than $10^{18}$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll P2LIM = (ll)2e18;

int solve(string s, string t)
{
	int tp = 0;
	int sp = 0;
	int taken = 0;

	while (sp < s.length() && tp < t.length())
	{
		if(s[sp] == t[tp])
		{
			taken++;
			tp++;
		}
		sp++;
	}

	return (int)s.length() - taken + (int)t.length() - taken;
}

vector<string> ts;

int main()
{
	for (ll p2 = 1; p2 <= P2LIM; p2 *= 2)
		ts.push_back(to_string(p2));

	int t;
	cin >> t;

	while (t--)
	{
		string n;
		cin >> n;

		int ans = n.length() + 1;
		for (auto p2 : ts)
			ans = min(ans, solve(n, p2));
		cout << ans << 'n';
	}

	return 0;
}

```
[1560E - Polycarp and String Transformation](../problems/E._Polycarp_and_String_Transformation.md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560E - Polycarp and String Transformation](../problems/E._Polycarp_and_String_Transformation.md "Codeforces Round 739 (Div. 3)")

Suppose it's given a string $t$ for which the answer exists. Consider the last non-empty value of $s$. Only $1$ letter occurs in the value and the letter is the last removed letter. At the same time, the value of $s$ is a suffix of $t$ so the last character of $t$ is the last removed letter. Consider the second-last non-empty value of $s$. It contains exactly $2$ distinct letters so that one of them is the last removed letter and the other is the second-last removed letter. The concatenation of the second-last and the last values of $s$ is a suffix of $t$ consisting only of the letters. Therefore, the letter which occurrence is the last of the occurrences of all letters except the last removed one is the second-last removed letter. Considering so other values, we are proving that the order of removing the letters is the order the last occurrences of the letters occur in the string $t$.

Suppose $k$ is the number of the step in which some letter was removed, $c_k$ is the number of occurrences of the letter in the initial value of $s$. The letter occurs in exactly $k$ different values of $s$. In each of them, the letter occurs exactly $c_k$ times. So the letter occurs in $t$ exactly $d_k = k \cdot c_k$ times. Therefore, using the number of the step ($k$) in which the letter was removed and the number of the letter's occurrences in $t$ ($d_k$), let's calculate the number of the letter's occurrences in the string $s$: $c_k = \frac{d_k}{k}$. If $d_k$ isn't completely divisible by $k$, there's no solution.

The sum of all $c_k$ of all letters occurring in $t$ is the length of the initial value of $s$. Since the initial value is a prefix of $t$, the possible answer is the prefix of $t$ having the length equal to the sum of all $c_k$.

Before outputting the prefix, check that you can get from the supposed value of the string $s$ the string $t$. Checking it, you may use the algorithm from the statement. If the resulting string is equal to $t$, the answer is correct and must be outputted, otherwise, there's no solution.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int cntsrc[26]; // don't forget to memset it but not cnt
int* cnt = cntsrc - 'a'; // so cnt['a'] = cntsrc[0] and so on

pair<string, string> decrypt(string s)
{
	string order;
	reverse(s.begin(), s.end());
	for (auto c : s)
	{
		if (!cnt[c])
			order.push_back(c);
		cnt[c]++;
	}

	int m = order.length();
	int originalLength = 0;
	for (int i = 0; i < m; i++)
		originalLength += cnt[order[i]] / (m - i);

	reverse(order.begin(), order.end());
	return { string(s.rbegin(), s.rbegin() + originalLength), order };
}

string encrypt(pair<string, string> p)
{
	string result = p.first;

	for (auto c : p.second)
	{
		string temp;
		for (auto d : p.first)
			if (d != c)
			{
				temp.push_back(d);
				result.push_back(d);
			}
		p.first = temp;
	}

	return result;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		memset(cntsrc, 0, sizeof(cntsrc));
		string s;
		cin >> s;

		auto ans = decrypt(s);
		auto check = encrypt(ans);

		if (check == s)
			cout << ans.first << ' ' << ans.second << 'n';
		else
			cout << "-1n";
	}

	return 0;
}

```
[1560F1 - Nearest Beautiful Number (easy version)](../problems/F1._Nearest_Beautiful_Number_(easy_version).md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560F1 - Nearest Beautiful Number (easy version)](../problems/F1._Nearest_Beautiful_Number_(easy_version).md "Codeforces Round 739 (Div. 3)")

Suppose the number $n$ contains $m$ digits. The desired number $x$ isn't greater than the number consisting of $m$ digits $9$. This number is $1$-beautiful whereas any $1$-beautiful number is at the same time $k$-beautiful, so $x$ contains at most $m$ digits. At the same time, $x \ge n$ so $x$ contains at least $m$ digits. Therefore, the desired number contains exactly $m$ digits.

Suppose $k = 1$. There are exactly $9$ $k$-beautiful numbers containing exactly $m$ digits. To get the answer fast, it's possible to consider all these numbers.

Suppose $k = 2$. If $n$ is already $k$-beautiful, let's output it. Otherwise, let's initialize the answer by the value as if $k = 1$. Let's iterate two digits $a$ and $b$ such that $a < b$. Let's search for the answer by considering the strings consisting only of digits $a$ and $b$. Let's iterate a prefix of $n$ starting from the empty one so that the prefix will be the prefix of $x$. This prefix must contain only the digits $a$ and $b$. Consider the leftmost digit that doesn't belong to the prefix. Let's try to increase it. If the digit is less than $a$, a possible answer is a number such that it has the considered prefix and all other digits are equal to $a$. Let's update the answer by this number (i.e. if the found number is less than the best previously found answer, let's set the answer to the found number). If the considered digit is at least $a$ and is less than $b$, let's update the answer by the number such that it has the considered prefix, the digit $b$ follows the prefix, and all other digits are equal to $a$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

string solve1(string n)
{
	string res(n.length(), '9');
	for (char c = '8'; c >= '0'; c--)
	{
		string t(n.length(), c);
		if (t >= n)
			res = t;
	}

	return res;
}

string solve2(string n)
{
	string res = solve1(n);

	for(char a = '0'; a <= '9'; a++)
		for (char b = a + 1; b <= '9'; b++)
		{
			bool n_ok = true;
			for (int i = 0; i < n.length(); i++)
			{
				if (n[i] < b)
				{
					string t = n;
					if (t[i] < a) t[i] = a;
					else t[i] = b;
					for (int j = i + 1; j < n.length(); j++)
						t[j] = a;
					if (res > t)
						res = t;
				}

				if(n[i] != a && n[i] != b)
				{
					n_ok = false;
					break;
				}
			}

			if (n_ok) return n;
		}

	return res;
}

string solve()
{
	string n;
	int k;
	cin >> n >> k;

	if (k == 1) return solve1(n);
	else return solve2(n);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		cout << solve() << 'n';

	return 0;
}

```
[1560F2 - Nearest Beautiful Number (hard version)](../problems/F2._Nearest_Beautiful_Number_(hard_version).md "Codeforces Round 739 (Div. 3)")

 **Tutorial**
### [1560F2 - Nearest Beautiful Number (hard version)](../problems/F2._Nearest_Beautiful_Number_(hard_version).md "Codeforces Round 739 (Div. 3)")

Suppose the number $n$ contains $m$ digits and its decimal representation is $d_1d_2 \dots d_m$. The desired number $x$ isn't greater than the number consisting of $m$ digits $9$. This number is $1$-beautiful whereas any $1$-beautiful number is at the same time $k$-beautiful, so $x$ contains at most $m$ digits. At the same time, $x \ge n$ so $x$ contains at least $m$ digits. Therefore, the desired number contains exactly $m$ digits.

Since we search for the minimum $x$, we need to minimize first of all the first digit, only then the second digit, etc. Therefore, we need to find a prefix of the decimal representation of $n$ such that is a prefix of the decimal representation of $x$. Let's do it greedily.

Short solution, works in $O(m^2)$

Let's find the maximum prefix of $n$ such that contains no more than $k$ distinct numbers. Suppose the prefix has the length $p$. If $p = m$, then $n$ is already $k$-beautiful, let's output it. Otherwise, let's increase the prefix like a number by $1$, e.g. if $n = 1294$ and $p = 3$, then we increase $129$ by $1$, the resulting prefix is $130$. All other digits ($d_{p + 2}, d_{p + 3}, \dots, d_m$), let's set to zeroes (e.g. if $n = 1294$ and $p = 3$, then $n$ will be turned into $1300$). The answer for the old $n$ is the answer for the new $n$. To get the answer for the new $n$, let's start the described procedure once again preparing the new $n$.

Long solution, works in $O(mk)$

Let's find the maximum prefix of $n$ such that contains no more than $k$ distinct numbers. It's possible to do using a $map$ in which for each digit (the key) the number of its occurrences in the prefix is stored. For an empty prefix, the $map$ is empty. If we increase the prefix length by $1$, we need to check that $map$ contains no more than $k$ keys and add a new key with the value $1$ or increase the value of an existing key. If the length of the found prefix is equal to the length of the whole decimal representation, the given number is already $k$-beautiful so the answer is $n$.

Otherwise, the found prefix may not be a prefix of the desired number. Let's change the digits of the decimal representation of $n$ to turn it into the desired number $x$. Let's start the following procedure: suppose we consider a prefix with the length equal to $p$. First, let's find out, is it possible to increase the first element out of the prefix (i. e. $d_{p + 1}$). We need to do it because if we consider the length $p$, then the prefix with the length $p + 1$ cannot be unchanged so the element $d_{p + 1}$ must be changed whereas it cannot be decreased because, in this case, we will get the number which is less than $n$. If we can increase the element $d_{p + 1}$ so that the prefix with the length $p + 1$ has at most $k$ distinct digits, the only thing that is remained to do is to fill the remaining digits $d_{p + 2}, d_{p + 3}, \dots d_m$ somehow greedily and output the result. If we cannot increase the element $d_{p + 1}$, let's decrease the length of the considered prefix $p$ by $1$ updating the $map$ (let's decrease the value corresponding to the key $d_{p}$ by $1$, then, if it's equal to $0$, we remove the key $d_{p}$ from the $map$).

Consider, how and under what conditions we can change $d_{p + 1}$ and the following digits:

1. If $d_{p + 1} = 9$, it's impossible.
2. Suppose the considered prefix contains less than $k$ distinct digits (the number of the keys in the $map$ is less than $k$). In this case, we can replace the digit $d_{p + 1}$ with the value $d_{p + 1} + 1$ so the prefix with the length $p + 1$ will not contain more than $k$ distinct elements because the prefix with the length $p$ doesn't contain more than $k - 1$ distinct elements. If the prefix with the length $p + 1$ still contains less than $k$ distinct numbers, let's replace the remaining digits ($d_{p + 2}$, $d_{p + 3}$, etc) with $0$. Otherwise, we can replace them with the minimum digit that occurs in the prefix with the length $p + 1$ (it may be $0$).
3. Suppose the considered prefix contains exactly $k$ distinct digits. So let's find the minimum digit that occurs in the prefix with the length $p$ and is greater than $d_{p + 1}$. If such digit exists, let's replace $d_{p + 1}$ with it, and all following digits with the minimum digit that occurs in the prefix with the length $p + 1$. Otherwise, the element $d_{p + 1}$ cannot be increased.

The converted by the procedure $n$ is the answer.

 **Short solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

string solve()
{
	string n;
	int k;
	cin >> n >> k;

	while (true)
	{
		set<char> s;
		for (auto c : n) s.insert(c);
		if (s.size() <= k) return n;

		s.clear();
		int ptr = 0;
		for (; ; ptr++)
		{
			s.insert(n[ptr]);
			if (s.size() > k)
			{
				while (n[ptr] == '9')
					ptr--;
				n[ptr]++;
				for (int i = ptr + 1; i < n.size(); i++)
					n[i] = '0';
				break;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		cout << solve() << 'n';
	
	return 0;
}

```
 **Long solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

string solveFillingSuffix(string& n, char d, int from)
{
	for (int i = from; i < n.length(); i++)
		n[i] = d;
	return n;
}

void decAt(map<char, int>& d, char c)
{
	if (d.count(c))
	{
		d[c]--;
		if (d[c] == 0) d.erase(c);
	}
}

string solve()
{
	string n;
	int k;
	cin >> n >> k;

	map<char, int> d;
	int pref = 0;

	while (pref < n.length())
	{
		if (d.count(n[pref]))
		{
			d[n[pref++]]++;
			continue;
		}
		if (d.size() == k) break;
		d[n[pref++]]++;
	}

	if (pref == n.length())
		return n;

	while (true)
	{
		if (n[pref] == '9')
		{
			decAt(d, n[--pref]);
			continue;
		}

		if (d.size() < k)
		{
			d[++n[pref]]++;
			return solveFillingSuffix(n, d.size() < k ? '0' : d.begin()->first, pref + 1);
		}

		auto it = d.upper_bound(n[pref]);
		if (it == d.end())
		{
			decAt(d, n[--pref]);
			continue;
		}

		n[pref] = it->first;
		return solveFillingSuffix(n, d.begin()->first, pref + 1);
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		cout << solve() << 'n';
	
	return 0;
}

```
