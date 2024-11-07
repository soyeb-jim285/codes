# Tutorial

Ideas: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1551A - Polycarp and Coins](../problems/A._Polycarp_and_Coins.md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551A - Polycarp and Coins](../problems/A._Polycarp_and_Coins.md "Codeforces Round 734 (Div. 3)")

Let's initialize variables $c_1$ and $c_2$ by the same value of $\lfloor{\frac{n}{3}}\rfloor$. Then we need to gather additionally the remainder of dividing $n$ by $3$.

If the remainder is equal to $0$, we don't need to gather anything else because the variables $c_1$ and $c_2$ have been already set to the correct answer: $|c_1 - c_2| = 0$ because $c_1 = c_2$ and no absolute value can be less than $0$. Otherwise, $|c_1 - c_2| \neq 0$ because $c_1 = c_2$ and $n = c_1 + 2 \times c_2 = 3 \times c_1$ in this case, but that's impossible if $n$ isn't divisible by 3.

If the remainder is equal to $1$, then we need to gather additionally $1$ burle using one coin of $1$ burle so let's increase $c_1$ by $1$. In this case, $c_1 = c_2 + 1$, hence $|c_1 - c_2| = 1$, this value cannot be less than $1$, as it was proved above.

If the remainder is equal to $2$, then we need to gather additionally $2$ burles using one coin of $2$ burles so let's increase $c_2$ by $1$. In this case, $c_2 = c_1 + 1$, hence $|c_1 - c_2| = 1$, this value cannot be less than $1$.

There are no other remainders of dividing by $3$ so these cases cover the whole solution.

 **Solution**
```cpp
for i in range(0, int(input())):
    n = int(input())
    c1 = n // 3;
    c2 = c1;
    if n % 3 == 1:
        c1 += 1
    elif n % 3 == 2:
        c2 += 1
    print(c1, c2)
```
[1551B1 - Wonderful Coloring - 1](../problems/B1._Wonderful_Coloring_-_1.md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551B1 - Wonderful Coloring - 1](../problems/B1._Wonderful_Coloring_-_1.md "Codeforces Round 734 (Div. 3)")

Let's calculate the number of letters which occur exactly once in the string and letters that occur more than once — $c_1$ and $c_2$, respectively.

If a letter occurs more than once, one of its occurrences may be painted in red and another one may be painted in green. We cannot paint all other occurrences because there will be two equal letters painted in one color, but this is unacceptable by the statement. So there are no more than $c_2$ occurrences of letters that occur more than once to be painted in red. Let's select $c_2$ such occurrences and paint them. We need to paint additionally the letters which occur exactly once by meeting the same conditions as we meet painting the whole string.

There's no way to paint these letters and not meet the first two conditions. So we must select the maximal count of the letters so that we will be able to paint some set of remaining letters in green so that the number of red letters will be equal to the number of green letters. This number is equal to $\lfloor \frac{c_1}{2} \rfloor$.

So the final answer is equal to $c_2 + \lfloor \frac{c_1}{2} \rfloor$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int L = 26;
int cnt[L];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for (auto c : s) cnt[c - 'a']++;
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < L; i++)
			if (cnt[i] == 1)
				cnt1++;
			else if (cnt[i] > 0)
				cnt2++;
		cout << (cnt2 + cnt1 / 2) << endl;
	}
	return 0;
}

```
[1551B2 - Wonderful Coloring - 2](../problems/B2._Wonderful_Coloring_-_2.md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551B2 - Wonderful Coloring - 2](../problems/B2._Wonderful_Coloring_-_2.md "Codeforces Round 734 (Div. 3)")

Since we must use exactly $k$ colors, each element that occurs in the sequence may have no more than $k$ painted occurrences. Let's select for each element $x$ $min(k, cnt_x)$ its occurrences where $cnt_x$ is the number of all its occurrences in the sequence.

Let $b_1, b_2, \dots, b_m$ be a sequence of all elements that occur in the sequence $a$, but in the sequence $b$ they will occur only once. Let's create a $1$-indexed array $p$ in which we will add sequentially indices of the selected occurrences of $b_1$ in the sequence $a$, then the selected occurrences of $b_2$, and so on till $b_m$. Currently, $p$ is a set of occurrences, which wonderful coloring is a wonderful coloring of the whole sequence $a$ because if we want to paint an occurrence outside $p$, we can do it only by selecting an occurrence of the same element in $p$ which we will not paint so that no more than $k$ occurrences will be painted.

We must use exactly $k$ colors and paint for each color an equal number of occurrences, hence if we want to paint all occurrences from $p$, we must remove from it the minimum number of occurrences so that the size of the array $p$ will be divided by $k$ (i. e. remove the number of occurrences equal to the remainder of dividing the size of $p$ by $k$). We can remove any occurrences, for example, let's delete it from the suffix of $p$. Currently, we can paint all occurrences from $p$ using the following rule: the occurrence $p_i$ we must paint in the color with a number $((i - 1) \% k) + 1$ where $\%$ takes the remainder of dividing the left operand by the right operand. So all occurrences from $p$ will be painted and all $k$ colors will be used. Since all occurrences of one element belong to one subsegment of $p$ and their number isn't greater than $k$, they will be painted in different colors.

It may be so that the array $p$ before painting will be empty. In this case, the wonderful coloring of $a$ doesn't contain any painted element.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200 * 1000 + 13;

int ans[MAX_N];
map<int, vector<int>> indices;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		indices.clear();
		memset(ans, 0, n * sizeof(ans[0]));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (indices[x].size() < k)
				indices[x].push_back(i);
		}
		int m = 0;
		for (auto e : indices) m += e.second.size();
		m -= m % k;
		int color = 0;
		for (auto e : indices)
			for (auto i : e.second)
			{
				ans[i] = ++color;
				color %= k;
				if (--m == 0) goto _output;
			}
	_output:
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << 'n';
	}

	return 0;
}

```
[1551C - Interesting Story](../problems/C._Interesting_Story.md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551C - Interesting Story](../problems/C._Interesting_Story.md "Codeforces Round 734 (Div. 3)")

Let $f(s, c)$ be the number of the occurrences of the letter $c$ in the word $s$ minus the number of the occurrences of all other letters in total. Since for each two words $s_1$ and $s_2$ the number of the occurrences of a letter in the word $s_1 + s_2$ is the sum of the numbers of its occurrences in $s_1$ and $s_2$, the equality $f(s_1 + s_2, c) = f(s_1, c) + f(s_2, c)$ is true ($s_1 + s_2$ means the concatenation of $s_1$ and $s_2$).

Consider a sequence of words $s_1, s_2, \ldots, s_n$. A story consisting of words $s_{i_1}, s_{i_2}, \ldots, s_{i_m}$ is interesting if and only if there's a letter $c$ such that $f(s_{i_1} + s_{i_2} + \ldots + s_{i_m}, c) > 0$ — it exactly means that there's a letter which occurs more times than all other in total. So we are interested in searching for a letter $c$ such that exists a positive integer $m$ — a maximal number of words $s_{i_1}, s_{i_2}, \ldots, s_{i_m}$ such that $\sum\limits_{j = 1}^{m} f(s_{i_j}, c) = f(s_{i_1} + s_{i_2} + \ldots + s_{i_m}, c) > 0$.

Suppose we have a set of words that form an interesting story and where $c$ is the letter having more occurrences than all other letters in total. Suppose we can add to it one of few words. We had better add a word $s$ such that $f(s, c)$ is maximal to be able to add more words in the future.

So the problem has the following solution: for each letter $c$ of the Latin alphabet and for each word $s_i$ let's calculate $f(s, c)$. Then let's iterate over all letters $c$, take a sequence $f(s_1, c), f(s_2, c), \ldots, f(s_n, c)$ and sort it in descending order. Let's initialize an interesting story by a set of a single word corresponding to the first element of the sequence. If there's no word $s$ such that $f(s, c) \le 0$, then there's no non-empty interesting story containing some words of the given set. Otherwise, let's take the next elements of the sequence sequentially until the sum of $f(s, c)$ over all taken words $s$ is greater than zero. Let's select a letter such that the corresponding taken set is maximal over all letters. Finally, we should print the set's size.

The solution consists of two phases: the calculation of all $f(s, c)$ (works in $O(L \times \sum\limits_{i = 1}^{n} |s_i|)$ where $L$ is the alphabet's size, $|s|$ is the lengths of a string $s$) and building a maximal interesting story for each letter $c$ (sorting and a greedy algorithm — $O(L \times n \times \log n)$).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2 * 100 * 1000 + 13;
const int L = 26;

vector<int> balance[L];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < L; i++)
			balance[i].clear();
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			int initBalance = -(int)s.length();
			for (int j = 0; j < L; j++)
				balance[j].push_back(initBalance);
			for (auto c : s)
				balance[c - 'a'].back() += 2;
		}
		int bestCount = 0;
		int bestLetter = 0;
		for (int i = 0; i < L; i++)
		{
			auto& b = balance[i];
			sort(b.begin(), b.end());
			reverse(b.begin(), b.end());
			if (b[0] <= 0) continue;
			int sumBalance = b[0];
			int j = 1;
			for (; j < n && sumBalance > 0; j++)
				sumBalance += b[j];
			if (sumBalance <= 0) j--;
			if (j > bestCount)
			{
				bestCount = j;
				bestLetter = i;
			}
		}

		cout << bestCount << endl;
	}
	return 0;
}
```
[1551D1 - Domino (easy version)](../problems/D1._Domino_(easy_version).md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551D1 - Domino (easy version)](../problems/D1._Domino_(easy_version).md "Codeforces Round 734 (Div. 3)")

See the tutorial for problem D2.

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
		int n, m, kh;
		cin >> n >> m >> kh;
		int kv = n * m / 2 - kh;
		if (n & 1)
		{
			kh -= m / 2;
			if (kh < 0)
			{
				cout << "NOn";
				continue;
			}
		}
		else if (m & 1)
		{
			kv -= n / 2;
			if (kv < 0)
			{
				cout << "NOn";
				continue;
			}
		}
		if ((kh & 1) || (kv & 1))
		{
			cout << "NOn";
			continue;
		}
		cout << "YESn";
	}
	return 0;
}

```
[1551D2 - Domino (hard version)](../problems/D2._Domino_(hard_version).md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551D2 - Domino (hard version)](../problems/D2._Domino_(hard_version).md "Codeforces Round 734 (Div. 3)")

Suppose $n$ and $m$ are even. A necessary and sufficient condition of existence of the answer is that $k$ is even.

Let's prove the sufficient condition. If the count of the horizontal dominoes is even, then we can combine them and vertical dominoes to blocks of size $2 \times 2$ (the number of the vertical dominoes is even, too, if $k$ is even). If $n$ and $m$ are even, we can fill the table with these blocks. The description of the locations of the dominoes may be printed as follows: consider the table is a chessboard where a cell is a block of two dominoes. Consider the leftmost topmost cell of the board is black. If a cell of the board is black, let's mark one of the dominoes of the block with the letter "a" and the other one with the letter "b". If a cell of the board is white, let's mark one of the dominoes of the block with the letter "c" and the other one with the letter "d". There will be no situation that some two cells of the table are marked with one letter but belong to different dominoes.

Let's prove the necessary condition. The number of cells in a column ($n$) is even, so the number of cells that belong to vertical dominoes is even because cells of each vertical domino may be either belong to the column or not belong at the same time. So the number of cells that belong to horizontal dominoes is even. Let's cross out all cells that belong to vertical dominoes and let's find the leftmost column having cells that haven't been crossed out. It's the leftmost column with such cells so the pairwise cells of the non-crossed out cells belong to the column to the right of the found one. The number of such cells in the right column is equal to the number of found cells so it's even and the number of found horizontal dominoes is even, too. Let's cross out the found cells and the pairwise cells. The number of non-crossed out cells in the right column will be even. The number of crossed-out horizontal dominoes will be even, too. Let's repeat this procedure until all the dominoes will be crossed out. In every step, we have crossed out the even number of horizontal dominoes, hence the total count of horizontal dominoes is even.

Suppose $n$ is odd, hence $m$ is even. In this case, every column contains an odd number of cells, whereas the number of cells that belong to vertical dominoes is even. So the number of cells that belong to horizontal dominoes is odd. Consider the leftmost column and find a cell of it that belongs to a horizontal domino (it must be found because the number of such cells is odd so it isn't equal to $0$). Let's find the pairwise cell and cross out both cells. Currently, the two columns will have an even number of non-crossed-out cells. Let's repeat the procedure until all columns will have even non-crossed-out cells. We will cross out $m$ cells and $\frac{m}{2}$ dominoes. So the necessary condition is that the number of horizontal dominoes ($k$) is at least $\frac{m}{2}$.

Let's extend the necessary condition with the following condition: the value of $k - \frac{m}{2}$ is even. Consider the table that we've become after the previous procedure where each column has exactly one crossed-out cell. Let's start the procedure we've done in the case of even both $n$ and $m$. The procedure can be started on our table because each column of the table has an even number of non-crossed-out cells. As a result of the procedure, we will cross out an even count of horizontal dominoes, so the value of $k - \frac{m}{2}$ is even.

Let's build an answer if the conditions $k \ge \frac{m}{2}$ and $k - \frac{m}{2}$ is even are met. Let's place in the topmost row $\frac{m}{2}$ horizontal dominoes and mark their cells as follows: the first domino will be marked with "x", the second one — with "y", the third one — with "x", and so on. As the result, the region of $n - 1$ rows and $m$ columns will be unfilled. Both values are even, and the value of $k - \frac{m}{2}$ is even, too. So let's fill the region as if it's a separate table having even numbers of rows and columns. As it was proved above, it's possible to do. The set of letters used for the region and set of the letters used for the topmost row don't have common elements, so there will be no cells that are marked with one letter but belong to different dominoes.

The case of odd $m$ (hence, $n$ is even) is similar to the previous one — let's transpose the table (it will have $m$ rows and $n$ columns), swap the values of $k$ and $\frac{nm}{2} - k$, solve the case above and transpose the table back to have $n$ rows and $m$ columns.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

char field[128][128];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, kh;
		cin >> n >> m >> kh;
		int kv = n * m / 2 - kh;
		if (n & 1)
		{
			kh -= m / 2;
			if (kh < 0)
			{
				cout << "NOn";
				continue;
			}

			for (int i = 0; i < m / 2; i++)
				field[n - 1][i * 2] = field[n - 1][i * 2 + 1] = ((i & 1) ? 'x' : 'y');
		}
		else if (m & 1)
		{
			kv -= n / 2;
			if (kv < 0)
			{
				cout << "NOn";
				continue;
			}

			for (int i = 0; i < n / 2; i++)
				field[i * 2][m - 1] = field[i * 2 + 1][m - 1] = ((i & 1) ? 'x' : 'y');
		}
		if ((kh & 1) || (kv & 1))
		{
			cout << "NOn";
			continue;
		}
		for(int i = 0; i < n / 2; i++)
			for (int j = 0; j < m / 2; j++)
			{
				if (kh)
				{
					kh -= 2;
					field[2 * i][2 * j] = field[2 * i][2 * j + 1] = (((i + j) & 1) ? 'a' : 'b');
					field[2 * i + 1][2 * j] = field[2 * i + 1][2 * j + 1] = (((i + j) & 1) ? 'c' : 'd');
				}
				else
				{
					field[2 * i][2 * j] = field[2 * i + 1][2 * j] = (((i + j) & 1) ? 'a' : 'b');
					field[2 * i][2 * j + 1] = field[2 * i + 1][2 * j + 1] = (((i + j) & 1) ? 'c' : 'd');
				}
			}

		cout << "YESn";
		for (int i = 0; i < n; i++)
		{
			field[i][m] = 0;
			cout << field[i] << 'n';
		}
	}
	return 0;
}

```
[1551E - Fixed Points](../problems/E._Fixed_Points.md "Codeforces Round 734 (Div. 3)")

 **Tutorial**
### [1551E - Fixed Points](../problems/E._Fixed_Points.md "Codeforces Round 734 (Div. 3)")

Let's use the concept of dynamic programming. Let's create an array $dp$ ($0$-indexed) with size of $(n + 1) \times (n + 1)$. $dp[i][j]$ will contain the maximal number of the elements equal to their indices if we have considered the first $i$ elements of the sequence $a$ and have not deleted $j$ elements.

Let's fill the array with zeroes, then we will increase the elements of the array for different $i$ and $j$. Let's start the $for$-loop with parameter $i$ from $0$ to $n - 1$ and the internal one with parameter $j$ from $0$ to $i$. Consider an element $a_{i + 1}$. We can delete or not delete it.

If we delete this element, the number of the elements equal to their indices will not be increased and the number of the non-deleted element will not be increased, too. It means that the answer for $dp[i + 1][j]$ may be updated with $dp[i][j]$. Since we are interested in a maximum answer, we rewrite $dp[i + 1][j]$ only if $dp[i][j]$ is greater than $dp[i + 1][j]$.

Suppose we don't delete this element. We haven't deleted previously $j$ elements so $a_{i + 1}$ will have the index $(j + 1)$ and there will be $j + 1$ non-deleted elements if we consider $i + 1$ elements so we must update $dp[i + 1][j + 1]$. If $a_{i + 1} = j + 1$ (i. e. an element equal to its index is found), let's update $dp[i + 1][j + 1]$ with $dp[i][j] + 1$. Otherwise, we should update it with $dp[i][j]$. Remember that update may be done only if we rewrite the less value with the greater value.

Let's build the answer as follows. We need to minimize the number of deleted elements (maximize the number of non-deleted elements) so that the number of the elements equal to their indices is at least $k$. Consider only the elements of $dp$ having the first index $i = n$. Let's start a $for$-loop in the descending order of $j$. If $dp[n][j] \ge k$, $j$ is the maximum number of elements that we will not delete, so the answer is $n - j$. If we will not find $j$ such that $dp[n][j] \ge k$, there's no desired sequence of moves so the answer is $-1$.

The algorithm works in $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 6000;

int dp[MAX_N][MAX_N];
int a[MAX_N];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= i; j++)
				dp[i][j] = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
			{
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + ((a[i + 1] == j + 1) ? 1 : 0));
			}
		int ans = -1;
		for(int i = n; i >= 0; i--)
			if (dp[n][i] >= k)
			{
				ans = n - i;
				break;
			}
		cout << ans << 'n';
	}
	return 0;
}

```
[1551F - Equidistant Vertices](../problems/F._Equidistant_Vertices.md "Codeforces Round 734 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 128;

typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll add(ll x, ll y) { return (x + y) % mod; }
ll mul(ll x, ll y) { return x * y % mod; }

vector<int> g[MAX_N];
bool used[MAX_N];
int cnt[MAX_N];
ll dp[MAX_N][MAX_N];

ll rundp(int m, int k)
{
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= k; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j <= k; j++)
		{
			dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], cnt[i]));
		}
	return dp[m][k];
}

void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	if (k == 2)
	{
		cout << n * (n - 1LL) / 2 % mod << 'n';
		return;
	}
	ll ans = 0;
	for (int center = 0; center < n; center++)
	{
		memset(used, 0, n);
		used[center] = true;

		vector<pair<int, int>> layer;
		int m = g[center].size();
		for (int i = 0; i < m; i++)
		{
			int y = g[center][i];
			layer.emplace_back(y, i);
			cnt[i] = 1;
			used[y] = true;
		}
		while (!layer.empty())
		{
			ans = add(ans, rundp(m, k));
			vector<pair<int, int>> newlayer;
			for (auto p : layer)
			{
				cnt[p.second]--;
				for (auto y : g[p.first])
					if (!used[y])
					{
						newlayer.emplace_back(y, p.second);
						used[y] = true;
						cnt[p.second]++;
					}
			}
			layer = newlayer;
		}
	}
	cout << ans << 'n';
}

int main()
{
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

```
