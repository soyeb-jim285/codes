# Tutorial

[1256A - Payment Without Change](../problems/A._Payment_Without_Change.md "Codeforces Round 598 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1256A - Payment Without Change](../problems/A._Payment_Without_Change.md "Codeforces Round 598 (Div. 3)")

Firstly, we obviously need to take at least $S \% n$ coins of value $1$. If we cannot do it, the answer it NO. Otherwise we always can obtain the required sum $S$ if $a \cdot n + b \ge S$.

 **Solution**
```cpp
#include <iostream>

using namespace std;

int main() {
	int q;
	cin >> q;

	for (int qr = 0; qr < q; ++qr) {
		int a, b, n, s;
		cin >> a >> b >> n >> s;

		if (s % n <= b && 1ll * a * n + b >= s) {
			cout << "YESn";
		}
		else {
			cout << "NOn";
		}
	}
}
```
[1256B - Minimize the Permutation](../problems/B._Minimize_the_Permutation.md "Codeforces Round 598 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1256B - Minimize the Permutation](../problems/B._Minimize_the_Permutation.md "Codeforces Round 598 (Div. 3)")

The following greedy solution works: let's take the minimum element and move it to the leftmost position we can. With this algorithm, all forbidden operations are form the prefix of operations: ($1, 2$), $(2, 3)$, ..., and so on. So we can carry the position of the leftmost operation we can perform $pos$. Initially, it is $1$. We repeat the algorithm until $pos \ge n$. Let's find the position of the minimum element among elements $a_{pos}, a_{pos + 1}, \dots, a_{n}$. Let this position be $nxt$. If $nxt = pos$ then let's increase $pos$ and continue the algorithm. Otherwise, we need to move the element from the position $nxt$ to the position $pos$ and then set $pos := nxt$.

Time complexity: $O(n^2)$.

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
		vector<int> a(n);
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			--a[j];
		}
		int pos = 0;
		while (pos < n) {
			int nxt = min_element(a.begin() + pos, a.end()) - a.begin();
			int el = a[nxt];
			a.erase(a.begin() + nxt);
			a.insert(a.begin() + pos, el);
			if (pos == nxt) pos = nxt + 1;
			else pos = nxt;
		}
		for (auto it : a) cout << it + 1 << " ";
		cout << endl;
	}
	
	return 0;
}
```
[1256C - Platforms Jumping](../problems/C._Platforms_Jumping.md "Codeforces Round 598 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1256C - Platforms Jumping](../problems/C._Platforms_Jumping.md "Codeforces Round 598 (Div. 3)")

This problem has a very easy idea but requires terrible implementation. Firstly, let's place all platforms as rightmost as we can. Thus, we will have the array, in which the first $n - \sum\limits_{i=1}^{m} c_i$ elements are zeros and other elements are $1$, $2$, ..., $m$.

Now, let's start the algorithm. Firstly, we need to jump to the position $d$ or less. If we could jump to the position $d$ then we don't need to jump to some position to the left from $d$. But if we cannot do it, let's take the leftmost platform to the right from the position $d$ and move it in such a way that its left border will be at the position $d$. Now we can jump to the position $d$ and then jump by $1$ right to reach the position $d + c_1 - 1$. Let's repeat the same algorithm and continue jumping.

If after some move we can jump to the position at least $n+1$ then we are done.

Time complexity: $O(n^2)$ but I'm sure it can be implemented in $O(n \log n)$ or $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> c(m);
	for (int i = 0; i < m; ++i) {
		cin >> c[i];
	}
	
	vector<int> ans(n + 2);
	for (int i = m - 1, pos = n; i >= 0; --i) {
		for (int len = 0; len < c[i]; ++len) {
			ans[pos - len] = i + 1;
		}
		pos -= c[i];
	}
	
	int now = 0;
	while (true) {
		while (now + 1 < n + 1 && ans[now + 1] > 0) ++now;
		if (now + d >= n + 1) break;
		if (ans[now + d] == 0) {
			int lpos = -1;
			for (int i = now + d; i < n + 2; ++i) {
				if (ans[i] != 0) {
					lpos = i;
					break;
				}
			}
			if (lpos == -1) {
				cout << "NO" << endl;
				return 0;
			}
			int rpos = -1;
			for (int i = lpos; i < n + 2; ++i) {
				if (ans[i] == ans[lpos]) rpos = i;
			}
			while (ans[now + d] == 0) {
				swap(ans[lpos - 1], ans[rpos]);
				--lpos, --rpos;
			}
		}
		now += d;
	}
	
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1256D - Binary String Minimizing](../problems/D._Binary_String_Minimizing.md "Codeforces Round 598 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1256D - Binary String Minimizing](../problems/D._Binary_String_Minimizing.md "Codeforces Round 598 (Div. 3)")

This problem has a very standard solution: let's take the leftmost zero, place it as left as possible, and solve the problem without this zero and all operations we spent.

But we should do it fast. Let's go from left to right and carry the number of ones on the prefix $cnt$. If we meet $1$, let's just increase $cnt$ and continue the algorithm. It is obvious that if we meet $0$ we need to make exactly $cnt$ swaps to place it before all ones. If we can do it, let's just add $0$ to the answer, decrease $k$ by $cnt$ and continue. Otherwise, this zero will be between some of these $cnt$ ones and we can place it naively. In this case, the suffix of the string will not change. If after all operations we didn't meet the case above, let's add all ones to the suffix of the resulting string.

Time complexity: $O(n)$.

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
	while (q--) {
		int n;
		long long k;
		string s;
		cin >> n >> k >> s;
		string res;
		int cnt = 0;
		bool printed = false;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (cnt <= k) {
					res += '0';
					k -= cnt;
				} else {
					res += string(cnt - k, '1');
					res += '0';
					res += string(k, '1');
					res += s.substr(i + 1);
					cout << res << endl;
					printed = true;
					break;
				}
			} else {
				++cnt;
			}
		}
	
		if (!printed) {
			res += string(cnt, '1');
			cout << res << endl;
		}
	}
	
	return 0;
}
```
[1256E - Yet Another Division Into Teams](../problems/E._Yet_Another_Division_Into_Teams.md "Codeforces Round 598 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1256E - Yet Another Division Into Teams](../problems/E._Yet_Another_Division_Into_Teams.md "Codeforces Round 598 (Div. 3)")

Let's sort all students by their programming skills but save the initial indices to restore the answer.

Now we can understand that we don't need to compose the team of size greater than $5$ because in this case we can split it into more teams with fewer participants and obtain the same or even less answer.

Now we can do the standard dynamic programming $dp_{i}$ — the minimum total diversity of the division if we divided the first $i$ students (in sorted order). Initially, $dp_{0} = 0$, all other values of $dp$ are $+\infty$. Because of the fact above, we can do only three transitions ($0$-indexed):

* $dp_{i + 3} = min(dp_{i + 3}, dp_{i} + a_{i + 2} - a_{i})$;
* $dp_{i + 4} = min(dp_{i + 4}, dp_{i} + a_{i + 3} - a_{i})$;
* $dp_{i + 5} = min(dp_{i + 5}, dp_{i} + a_{i + 4} - a_{i})$.

The answer is $dp_{n}$ and we can restore it by standard carrying parent values (as a parent of the state we can use, for example, the number of participants in the team).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pt;

#define x first
#define y second
#define mp make_pair

const int N = 200043;
const int INF = int(1e9) + 43;

int n;
int dp[N];
int p[N];
pt a[N];
int t[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
    	a[i].y = i;
    	scanf("%d", &a[i].x);
    }
    sort(a, a + n);
    for(int i = 1; i <= n; i++)
    {
    	dp[i] = INF;
    	p[i] = -1;
    }
    for(int i = 0; i < n; i++)
    	for(int j = 3; j <= 5 && i + j <= n; j++)
    	{
    		int diff = a[i + j - 1].x - a[i].x;
    		if(dp[i + j] > dp[i] + diff)
    		{
    			p[i + j] = i;
    			dp[i + j] = dp[i] + diff;
    		}
    	}
    int cur = n;
    int cnt = 0;
    while(cur != 0)
    {
    	for(int i = cur - 1; i >= p[cur]; i--)
    		t[a[i].y] = cnt;
    	cnt++;
    	cur = p[cur]; 
    }
    printf("%d %dn", dp[n], cnt);
    for(int i = 0; i < n; i++)
    {
    	if(i) printf(" ");
    	printf("%d", t[i] + 1); 
    }
    puts("");
    return 0;
}
```
[1256F - Equalizing Two Strings](../problems/F._Equalizing_Two_Strings.md "Codeforces Round 598 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1256F - Equalizing Two Strings](../problems/F._Equalizing_Two_Strings.md "Codeforces Round 598 (Div. 3)")

The necessary condition to make strings equal is that the number of occurrences of each character should be the same in both strings. Let's show that if some character appears more than once, we always can make strings equal. How? Let's sort the first string by swapping adjacent characters (and it does not matter what do we do in the second string). Then let's sort the second string also by swapping adjacent characters but choose the pair of adjacent equal characters in the first string (it always exists because the first string is already sorted).

Otherwise, all characters in both strings are distinct and they lengths are at most $26$. Then the answer is YES if the parity of the number of inversions (the number inversions in the array $a$ is the number of such pairs of indices $i, j$ that $i < j$ but $a_i > a_j$) are the same. It can be proven in the following way: every swap of two adjacent elements changes the parity of the number of inversions.

Time complexity: $O(max(n, AL^2))$.

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
		string s, t;
		cin >> n >> s >> t;
		vector<int> cnts(26), cntt(26);
		for (int j = 0; j < n; ++j) {
			++cnts[s[j] - 'a'];
			++cntt[t[j] - 'a'];
		}
		bool ok = true;
		bool good = false;
		for (int j = 0; j < 26; ++j) {
			ok &= cnts[j] == cntt[j];
			good |= cnts[j] > 1;
		}
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		if (good) {
			cout << "YES" << endl;
			continue;
		}
		int invs = 0, invt = 0;
		for (int l = 0; l < n; ++l) {
			for (int r = 0; r < l; ++r) {
				invs += s[l] > s[r];
				invt += t[l] > t[r];
			}
		}
		ok &= (invs & 1) == (invt & 1);
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
