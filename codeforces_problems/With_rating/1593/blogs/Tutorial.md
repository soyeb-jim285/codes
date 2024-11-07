# Tutorial

[1593A - Elections](../problems/A._Elections.md "Codeforces Round 748 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1593A - Elections](../problems/A._Elections.md "Codeforces Round 748 (Div. 3)")

Let's solve the problem for the first candidate. To win the election, he needs to get at least $1$ more votes than every other candidate. Therefore, the first candidate needs to get at least $\max(b, c) + 1$ votes. If $a$ is already greater than this value, then you don't need to add any votes, otherwise, you need to add $\max(b, c) + 1 - a$ votes. So the answer for the first candidate is $\max(0, \max(b,c) + 1 - a)$.

Similarly, the answer for the second candidate is $\max(0, \max(a, c) + 1 - b)$, and, for the third one, the answer is $\max(0, \max(a, b) + 1 - c)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int solveSingle(int best, int other1, int other2)
{
	return max(0, max(other1, other2) + 1 - best);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		cout << solveSingle(a, b, c) << ' ' << solveSingle(b, a, c) << ' ' << solveSingle(c, a, b) << 'n';
	}

	return 0;
}

```
[1593B - Make it Divisible by 25](../problems/B._Make_it_Divisible_by_25.md "Codeforces Round 748 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1593B - Make it Divisible by 25](../problems/B._Make_it_Divisible_by_25.md "Codeforces Round 748 (Div. 3)")

A number is divisible by $25$ if and only if its last two digits represent one of the following strings: "00", "25", "50", "75".

Let's solve for each string the following subtask: what is the minimum number of characters to be deleted so that the string becomes a suffix of the number. Then, choosing the minimum of the answers for all subtasks, we solve the whole problem.

Let's solve the subtask for a string "X Y" where 'X' and 'Y' are digits. We can do it using the following algorithm: let's delete the last digit of the number until it is equal to 'Y', then the second to last digit of the number until it is equal to 'X'. If it is not possible, then this subtask has no solution (i.e. its result will not affect the answer).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const string subseqs[] = { "00", "25", "50", "75" };

const int INF = 100;

int solve(string& s, string& t)
{
	int sptr = s.length() - 1;

	int ans = 0;
	while (sptr >= 0 && s[sptr] != t[1])
	{
		sptr--;
		ans++;
	}

	if (sptr < 0) return INF;

	sptr--;

	while (sptr >= 0 && s[sptr] != t[0])
	{
		sptr--;
		ans++;
	}

	return sptr < 0 ? INF : ans;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string n;
		cin >> n;
		
		int ans = INF;
		for (auto e : subseqs)
			ans = min(ans, solve(n, e));

		cout << ans << 'n';
	}

	return 0;
}

```
[1593C - Save More Mice](../problems/C._Save_More_Mice.md "Codeforces Round 748 (Div. 3)")

Idea: ITMO student team

 **Tutorial**
### [1593C - Save More Mice](../problems/C._Save_More_Mice.md "Codeforces Round 748 (Div. 3)")

Let's solve the problem using a linear search. Let $m$ be the number of mice we are trying to save. Then it is more efficient to save $m$ mice such that they are the closest ones to the hole. Let $r_i$ be the distance from the $i$-th mouse to the hole ($r_i = n - x_i$). Denote $R := \sum\limits_{i = 1}^m r_i$. Let's prove that these mice will be saved if and only if $R < n$.

The necessary condition. Suppose we can save the mice and $R \ge n$. Since only one mouse can be moved in one second, the following will happen: $m - 1$ of mice will already be saved and one mouse will have to be saved. When it's been $q$ seconds, then the distance from the cat to the hole will be equal to $n - q$, and the distance from the mouse to the hole will be equal to $R - q$ (since all other mice are already in the hole, their distances to the hole are equal to $0$, so the sum of the distances from all mice to the hole at the current time is exactly equal to the distance to the hole from one remaining mouse). Since $R - q \ge n - q$, the distance from the mouse to the hole is greater than or equal to the distance from the cat to the hole. But this cannot be, because both the mice and the cat move only to the right, and all mice met by the cat are eaten. So, $R < n$.

Sufficient condition. Suppose $R < n$. If $R = 0$, then all the mice are already in the hole, i.e. they are saved. Suppose $R > 0$. Let's move any mouse, then the cat. Suppose the cat ate at least one of the mice. This mouse is definitely not the one that was moved. Then the distance from it to the eaten mouse was equal to $1$, i.e. the distance from it to the hole was equal to the distance from the eaten mouse to the hole plus $1$. The distance from the moved mouse to the hole was at least $1$. So, $R \ge r_s + r_m$, where $r_s = n - 1$ is the distance from the eaten mouse to the hole, $r_m \ge 1$ is the distance from the moved mouse to the hole. So, $R \ge n - 1 + 1 = n$, but it's false. Therefore, none of the mice will be eaten on the first move. Then the distance from the cat to the hole will be equal to $n - 1$, the total distance from the mice to the hole will be equal to $R - 1$. $R - 1 < n - 1$, i.e. now we have to solve a similar problem for smaller $R$ and $n$. So $R$ will be gradually decreased to $0$, while no mouse will be eaten. So, if $R < n$, all the mice will be saved.

Thus, to solve the problem, we need to find the maximum $m$ such that the sum of the distances from the $m$ nearest mice to the hole is less than $n$.

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
		int n, k;
		cin >> n >> k;

		vector<int> x(k);
		for (int i = 0; i < k; i++) cin >> x[i];
		sort(x.rbegin(), x.rend());

		int cnt = 0;
		long long sum = 0;

		while (cnt < x.size() && sum + n - x[cnt] < n)
		{
			sum += n - x[cnt++];
		}

		cout << cnt << 'n';
	}

	return 0;
}

```
[1593D1 - All are Same](../problems/D1._All_are_Same.md "Codeforces Round 748 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1593D1 - All are Same](../problems/D1._All_are_Same.md "Codeforces Round 748 (Div. 3)")

$k$ can be arbitrarily large if and only if all numbers in the array are the same. In this case, we can choose any number $k$ and subtract it from all the numbers, for example, exactly once.

Suppose we fix some $k$. Let $q_i$ be the number of subtractions of the number $k$ from the number $a_i$. In this case, all numbers will be equal if and only if, for any two numbers $a_i$ and $a_j$ from the array, $a_i - k \cdot q_i = a_j - k\cdot q_j$. Let $q_{i_0}$ be the minimum of $q_i$. Then all numbers in the array become the same if for each index $i$ we subtract from $a_i$ $k$ not $q_i$, but $q_i - q_{i_0}$ times. Then we will never subtract $k$ from the element $a_{i_0}$. This means that there is always an element in the array from which we can never subtract $k$. This element is the minimum on the array. Then from $a_i$ we will subtract $k$ exactly $\frac{a_i - a_{i_0}}{k}$ times.

Thus, with the current $k$, it is possible to make all elements equal if and only if for all elements $a_i$ the value $a_i - a_{i_0}$ (where $a_{i_0}$ is the minimum on the array) is divisible by $k$. So, the maximum $k$ is the greatest common divisor of all values of $a_i - a_{i_0}$, $i = \overline{1, n}$.

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
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		bool inf = true;
		int minval = a[0];

		for (int i = 1; i < n; i++)
		{
			if (a[i] != a[0])
			{
				inf = false;
				break;
			}
			minval = min(minval, a[i]);
		}

		if (inf)
		{
			cout << "-1n";
			continue;
		}

		sort(a.begin(), a.end());

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = gcd(ans, a[i] - minval);
		cout << ans << 'n';
	}

	return 0;
}

```
[1593D2 - Half of Same](../problems/D2._Half_of_Same.md "Codeforces Round 748 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1593D2 - Half of Same](../problems/D2._Half_of_Same.md "Codeforces Round 748 (Div. 3)")

$k$ can be arbitrarily large if and only if at least half of the numbers in the array are the same. In this case, we can choose any number $k$ and subtract it from all numbers, for example, exactly once.

Let's iterate over the element $a_{i_0}$, it will be the minimum among the numbers that we want to make the same. Let's calculate the number of numbers in the array that are equal to this element. If this number is at least $\frac{n}{2}$, then the answer is -1. Otherwise, we will iterate over numbers $a_i$ which are strictly greater than the selected minimum, and, for each number, we will iterate over the divisors of the number $a_i - a_{i_0}$. For each of the found divisors, let's calculate the number of $a_i$ for which this divisor was found. Among all such divisors for which the sum of the found number and the number of numbers equal to $a_{i_0}$ is greater than or equal to $\frac{n}{2}$, we will choose the maximum one. The greatest found divisor will be the desired $k$. This solution works in $O(n^2\times\sqrt{A})$ (where $A$ is the absolute value of the maximum on the array).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

set<int> divs(int n) {  
    set<int> d;
    for (int dd = 1; dd * dd <= n; dd++)
        if (n % dd == 0) {
            d.insert(n / dd);
            d.insert(dd);
        }
    return d;
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        int k = -1;

        forn(i, n) {
            int minv = a[i];
            int same = 0;
            vector<int> d;
            forn(j, n) {
                if (a[j] == minv)
                    same++;
                else if (a[j] > minv)
                    d.push_back(a[j] - minv);
            }
            if (same >= n / 2) {
                k = INT_MAX;
                continue;
            }
            map<int,int> div_counts;
            for (int di: d)
                for (int dd: divs(di))
                    div_counts[dd]++;
            for (auto p: div_counts)
                if (p.second >= n / 2 - same)
                    k = max(k, p.first);
        }

        cout << (k == INT_MAX ? -1 : k) << endl;
    }
}

```
[1593E - Gardener and Tree](../problems/E._Gardener_and_Tree.md "Codeforces Round 748 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1593E - Gardener and Tree](../problems/E._Gardener_and_Tree.md "Codeforces Round 748 (Div. 3)")

Let's create two arrays of length $n$. The element of the array $layer$ will contain the operation number at which the vertex which is the index of the array will be deleted. The $rem$ array will contain the number of neighbors of a given vertex at a certain time. This array must be initialized with the number of neighbors in the original tree.

Initially, we will suppose that the gardener performs an infinite number of operations, and we will simply calculate for each vertex the number of the operation on which it will be deleted. Let's create a queue $q$, which will store the order of deleting vertices. The queue will contain only those vertices whose neighbors, except, maybe, one, have been removed (i.e. $rem[v] \le 1$). Let's add all leaves of the original tree to it, for each of them let's store the value $1$ in the array $layer$ (because all original leaves will be removed during the first operation).

Next, we will take sequentially one vertex from the queue and update the data about its neighbors. Consider the neighbors. Since we are deleting the current vertex, we need to update $rem$ of its neighbors. If the neighbor's $rem$ is equal to $1$, then it's already in the queue and it doesn't need to be considered right now. Otherwise, we will decrease the neighbor's $rem$ by $1$. If it becomes equal to $1$, then the neighbor must be added to the queue. The number of the operation during which the neighbor will be deleted is equal to the number of the operation during which the current vertex will be deleted plus $1$.

After we calculate the numbers of operations for all vertices, we need to select among them those that will not be deleted during operations with numbers $1, 2, \dots, k$. Thus, the answer is the number of vertices $v$ such that $layer[v] > k$.

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
		int n, k;
		cin >> n >> k;

		vector<vector<int>> g(n, vector<int>());
		vector<int> rem(n, 0);
		vector<int> layer(n, 0);

		for (int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
			rem[x]++;
			rem[y]++;
		}

		queue<int> q;
		for (int i = 0; i < n; i++)
			if (rem[i] == 1)
			{
				q.push(i);
				layer[i] = 1;
			}

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int v : g[u])
			{
				if (rem[v] != 1)
				{
					rem[v]--;
					if (rem[v] == 1)
					{
						layer[v] = layer[u] + 1;
						q.push(v);
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
			if (layer[i] > k)
				ans++;

		cout << ans << 'n';
	}

	return 0;
}


```
[1593F - Red-Black Number](../problems/F._Red-Black_Number.md "Codeforces Round 748 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1593F - Red-Black Number](../problems/F._Red-Black_Number.md "Codeforces Round 748 (Div. 3)")

The number $x$ is divisible by the number $y$ if and only if $x \equiv 0$ modulo $y$.

To solve this problem, let's use the concept of dynamic programming. There will be four states: the number of considered digits of the number $x$, the number of such considered digits that we have colored red, the remainder from dividing the red number by $A$ and the black one by $B$. The value corresponding to the state will be described by three parameters: the possibility of a situation described by the states, the color of the last digit, and the parent state. Let's assume that the number that contains $0$ digits is equal to $0$.

Initially, let's mark the state in which $0$ digits are considered, of which $0$ are red digits, and both remainders are equal to $0$, as possible. Next, let's iterate over all states in the following order: first by the number of considered digits, then by the number of considered red digits, then by the remainder of the division by $A$ and by $B$. From the current state, if it is possible (i.e. the corresponding mark is set), you can make two transitions to new states. At the first transition, we paint the last digit in red, at the second one in black. We need also to store the current state in the new states as the previous one.

A solution exists if and only if some state in which exactly $n$ digits are considered, of which at least $1$ and at most $n - 1$ red digits, and the remainders are equal to $0$, is marked as possible. Let's find such a state. Using the stored information about the color of the last digit and the previous state, we can restore the colors of all digits of the number $x$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 64;

bool dp[MAX_N][MAX_N][MAX_N][MAX_N]; // (taken, red, mod A, mod B) -> may be
pair<bool, int> sert[MAX_N][MAX_N][MAX_N][MAX_N]; // the same -> (true (red) | false(black), prev red/black)

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, a, b;
		string x;
		cin >> n >> a >> b >> x;

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k < a; k++)
					for (int l = 0; l < b; l++)
						dp[i][j][k][l] = false;

		dp[0][0][0][0] = true;

		for(int taken = 0; taken < n; taken++)
			for(int red = 0; red <= taken; red++)
				for(int remA = 0; remA < a; remA++)
					for(int remB = 0; remB < b; remB++)
						if (dp[taken][red][remA][remB])
						{
							// red transition
							dp[taken + 1][red + 1][(remA * 10 + (x[taken] - '0')) % a][remB] = true;
							sert[taken + 1][red + 1][(remA * 10 + (x[taken] - '0')) % a][remB] = { true, remA };

							// black transition
							dp[taken + 1][red][remA][(remB * 10 + (x[taken] - '0')) % b] = true;
							sert[taken + 1][red][remA][(remB * 10 + (x[taken] - '0')) % b] = { false, remB };
						}

		int bestRed = 0;

		for (int red = 1; red < n; red++)
			if (dp[n][red][0][0] && abs(red - (n - red)) < abs(bestRed - (n - bestRed)))
				bestRed = red;

		if (bestRed == 0)
		{
			cout << "-1n";
		}
		else
		{
			int taken = n;
			int red = bestRed;
			int remA = 0;
			int remB = 0;
			string ans = "";
			
			while (taken > 0)
			{
				auto way = sert[taken][red][remA][remB];
				if (way.first)
				{
					red--;
					remA = way.second;
					ans.push_back('R');
				}
				else
				{
					remB = way.second;
					ans.push_back('B');
				}
				taken--;
			}

			reverse(ans.begin(), ans.end());
			cout << ans << 'n';
		}
	}

	return 0;
}

```
[1593G - Changing Brackets](../problems/G._Changing_Brackets.md "Codeforces Round 748 (Div. 3)")

Idea: [nastya_ka](https://codeforces.com/profile/nastya_ka "Specialist nastya_ka")

 **Tutorial**
### [1593G - Changing Brackets](../problems/G._Changing_Brackets.md "Codeforces Round 748 (Div. 3)")

Consider a substring $t = s[l \dots r]$. Let's call square brackets located in odd positions in the substring odd brackets, and square brackets located in even positions even brackets. Let $cnt_{odd}$ be the number of odd brackets, $cnt_{even}$ be the number of even brackets, $cnt_{all} = cnt_{odd} + cnt_{even}$ be the number of all square brackets. Let's prove that the string $t$ can be turned into a correct bracket sequence for $0$ burles if and only if $cnt_{odd} = cnt_{even}$.

Let's prove the necessary condition. Suppose the initial substring has been turned into a correct bracket sequence. Since we have paid $0$ burles, there's no bracket which form has been changed. Therefore, $cnt_{odd}$ for the new sequence is the same as $cnt_{odd}$ for the initial sequence, the similar situation happens with $cnt_{even}$.

Let's say that two square brackets form a pair if the left one is an opening bracket and the right one is a closing bracket and the substring between them is a correct bracket sequence. A pair can be formed only by one odd bracket and one even bracket because between them is placed an even number of brackets (since it's a correct bracket sequence) so the difference between their indices is odd. In a correct bracket sequence, each square bracket has a pairwise bracket. Therefore, a correct bracket sequence contains $\frac{cnt_{all}}{2}$ pairs of brackets so $cnt_{odd} = cnt_{even} = \frac{cnt_{all}}{2}$.

Let's prove the sufficient condition. Suppose the initial substring contains equal numbers of odd and even brackets. Let's prove by induction that the substring may be turned into a correct bracket sequence for $0$ burles.

Suppose $cnt_{odd} = cnt_{even} = 0$. So the initial substring contains only round brackets. Let's make the first $\frac{r - l + 1}{2}$ brackets opening and the other brackets closing. The resulting sequence is a correct bracket sequence whereas we haven't changed the form of any bracket so the cost is equal to $0$.

A correct bracket sequence has two important properties:

* after deleting its substring being a correct bracket sequence, the resulting string is a correct bracket sequence;
* after inserting at any place any correct bracket sequence, the resulting string is a correct bracket sequence.

These properties can be applied to an incorrect bracket sequence, too: after deleting a substring being a correct bracket subsequence from an incorrect bracket sequence or inserting a correct bracket sequence into an incorrect one, the resulting sequence is an incorrect bracket sequence.

Consider a substring $t$ such that $cnt_{odd} = cnt_{even} > 0$. Suppose we have proved before that each substring $t$ having $cnt_{odd} = cnt_{even}$ decreased by $1$ can be turned into a correct bracket sequence for $0$ burles. Let's find two square brackets such that one of them is odd and another one is even and there are no square brackets between them. There's an even number of round brackets between them that can be turned into a correct bracket sequence for $0$ burles. Let's make the left found bracket opening and the right one closing. Then the substring starting at the left found bracket and ending at the right found bracket is a correct bracket sequence. Let's remove it from $t$. The resulting string contains $cnt_{odd} - 1$ odd brackets and $cnt_{even} - 1$ even brackets so, by the assumption of induction, it can be turned into a correct bracket sequence for $0$ burles. Let's do it and then insert the removed string into its place. Since we insert a correct bracket sequence into a correct bracket sequence, the resulting string is a correct bracket sequence.

Actually, the operations of inserting and removing are not allowed, they have been used for clarity, the string can be turned into a correct bracket sequence without these operations as follows: let's turn the substring we have removed into a correct bracket sequence (as it was described above), then change the other brackets of the string the same way as it was done with the string that was the result after removing. The resulting string is a correct bracket sequence. Therefore, the illegal operations of inserting and removing are not necessary, all other operations cost $0$ burles so the substring $t$ can be turned into a correct bracket sequence for $0$ burles.

Therefore, to turn a substring into a correct bracket sequence, we need to get a sequence such that $cnt_{odd} = cnt_{even}$. Suppose, initiallly, $cnt_{odd} > cnt_{even}$. Let's pay $cnt_{odd} - cnt_{even}$ burles to replace $cnt_{odd} - cnt_{even}$ odd brackets with round brackets. If $cnt_{odd} < cnt_{even}$, let's replace $cnt_{even} - cnt_{odd}$ even brackets with round brackets. Anyway, we must pay $|cnt_{odd} - cnt_{even}|$ burles. We cannot pay less than this value because for a correct bracket sequence, $cnt_{odd} = cnt_{even}$. But there's no need to pay more than this value, because, if we turn the initial substring into a sequence with $cnt_{odd} = cnt_{even}$, we can turn it into a correct bracket sequence for free. Therfore, the answer for a given question is $|cnt_{odd} - cnt_{even}|$.

Since we must answer the queries fast, let's use a concept of prefix sums. If the given string $s$ contains $n$ brackets, let's create arrays $psumOdd$ and $psumEven$ with the length $n + 1$. $psumOdd[i]$ will contain the number of odd brackets on the prefix of the string $s$ with the length $i$, $psumEven[i]$ — the same value for even brackets. Let's initialize $psumOdd[0] = psumEven[0] = 0$ and then iterate $i$ from $1$ to $n$. Let's initialize $psumOdd[i] = psumOdd[i - 1]$ and $psumEven[i] = psumEven[i - 1]$. If the $i$-th bracket is round, then the current values are correct. Otherwise, let's find out what bracket is it. If $i$ is odd, the bracket is odd so we must increase $psumOdd[i]$ by $1$. If $i$ is even, the bracket is even so we must increase $psumEven[i]$ by $1$.

To get the answer for a current $l$ and $r$, let's calculate $cnt_{odd}$ and $cnt_{even}$. $cnt_{odd}$ is a number of odd brackets that belong to the prefix with the length $r$ but not to the prefix with the length $l - 1$ so $cnt_{odd} = psumOdd[r] - psumOdd[l - 1]$. Similarly, $cnt_{even} = psumEven[r] - psumEven[l - 1]$. The remaining thing is to output $|cnt_{odd} - cnt_{even}|$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1'000'000;

int psumOdd[MAX_N + 1];
int psumEven[MAX_N + 1];

void solve()
{
	string s;
	int q;
	cin >> s >> q;
	int n = s.length();

	psumOdd[0] = psumEven[0] = 0;
	for (int i = 0; i < n; i++)
	{
		psumOdd[i + 1] = psumOdd[i];
		psumEven[i + 1] = psumEven[i];

		if (s[i] == '[' || s[i] == ']')
		{
			if (i & 1)
				psumOdd[i + 1]++;
			else
				psumEven[i + 1]++;
		}
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		int odd = psumOdd[r] - psumOdd[l];
		int even = psumEven[r] - psumEven[l];
		cout << abs(odd - even) << 'n';
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

```
