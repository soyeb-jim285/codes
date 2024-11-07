# Tutorial

[1157A - Reachable Numbers](../problems/A._Reachable_Numbers.md "Codeforces Round 555 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1157A - Reachable Numbers](../problems/A._Reachable_Numbers.md "Codeforces Round 555 (Div. 3)")

The key fact in this problem is that the answer is not very large (in fact, it's not greater than $91$). Why is it so? Every $10$ times we apply function $f$ to our current number, it gets divided by $10$ (at least), and the number of such divisions is bounded as $O(\log n)$.

So we can just do the following: store all reachable numbers somewhere, and write a loop that adds current number $n$ to reachable numbers, and sets $n = f(n)$ (we should end this loop when $n$ already belongs to reachable numbers). The most convenient way to store reachable numbers is to use any data structure from your favourite programming language that implemenets a set, but, in fact, the constrains were so small that it was possible to store all reachable numbers in an array.

 **Solution**
```cpp
def f(x):
	x += 1
	while(x % 10 == 0):
		x //= 10
	return x

a = set()
n = int(input())

while(not(n in a)):
	a.add(n)
	n = f(n)

print(len(a))
```
[1157B - Long Number](../problems/B._Long_Number.md "Codeforces Round 555 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1157B - Long Number](../problems/B._Long_Number.md "Codeforces Round 555 (Div. 3)")

Let's find the first digit in $a$ that becomes strictly greater if we replace it (obviously, if there is no such digit, then the best solution is to leave $a$ unchanged). In the optimal solution we will replace this digit and maybe some digits after this. Why is it so? It is impossible to make any of the previous digits greater (since we found the first digit that can be replaced with a greater one). 

Then let's analyze all digits to the right of it. We should not replace any digit with a lower digit (because it is better not to replace it and all digits to the right of it at all), but there's nothing wrong with replacing any other digits.

So, the segment we need to replace begins with the first digit that can become greater after replacing (and includes this digit) and goes to the right until the first digit that becomes less after replacing (and this digit is excluded).

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

int f[10];
string s;

int main()
{
	int n;
	cin >> n;
	cin >> s;
	for(int i = 1; i <= 9; i++)
		cin >> f[i];
	vector<int> diff;
	for(int i = 0; i < n; i++)
		diff.push_back(f[s[i] - '0'] - (s[i] - '0'));
	for(int i = 0; i < n; i++)
		if(diff[i] > 0)
		{
			while(i < n && diff[i] >= 0)
			{
				s[i] = char(f[s[i] - '0'] + '0');
				i++;
			}
			break;
		}
	cout << s << endl;
}
```
[1157C1 - Increasing Subsequence (easy version)](../problems/C1._Increasing_Subsequence_(easy_version).md "Codeforces Round 555 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1157C1 - Increasing Subsequence (easy version)](../problems/C1._Increasing_Subsequence_(easy_version).md "Codeforces Round 555 (Div. 3)")

In this problem the following greedy solution works: let's maintain the last element of the increasing sequence we got and on each turn choose the minimum element greater than this last element among the leftmost and the rightmost. Such turns will maximize the answer. You can find details of implementation in the authors solution.

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
	
	string res;
	int l = 0, r = n - 1;
	int lst = 0;
	while (l <= r) {
		vector<pair<int, char>> cur;
		if (lst < a[l]) cur.push_back(make_pair(a[l], 'L'));
		if (lst < a[r]) cur.push_back(make_pair(a[r], 'R'));
		sort(cur.begin(), cur.end());
		if (int(cur.size()) == 2) {
			cur.pop_back();
		}
		if (int(cur.size()) == 1) {
			if (cur[0].second == 'L') {
				res += 'L';
				lst = a[l];
				++l;
			} else {
				res += 'R';
				lst = a[r];
				--r;
			}
		} else {
			break;
		}
	}
	
	cout << res.size() << endl << res << endl;
	
	return 0;
}
```
[1157C2 - Increasing Subsequence (hard version)](../problems/C2._Increasing_Subsequence_(hard_version).md "Codeforces Round 555 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1157C2 - Increasing Subsequence (hard version)](../problems/C2._Increasing_Subsequence_(hard_version).md "Codeforces Round 555 (Div. 3)")

The solution of the previous problem works for this problem also. Almost works. What if the leftmost element is equal the rightmost element? Which one should we choose? Let's analyze it. If we take the leftmost element then we will nevertake any other element from the right, and vice versa. So we can't meet this case more than once because after meeting it once we can take only leftmost elements or only rightmost elements. The only thing we should understand is which of these two cases is better (take the leftmost element or take the rightmost element). To do it we can just iterate from left to right and calculate the number of elements we can take if we will take the leftmost element each time. If we cannot take the current element then just stop the cycle. And do the same thing for the rightmost element and take the best case.

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
	
	string res;
	int l = 0, r = n - 1;
	int lst = 0;
	while (l <= r) {
		vector<pair<int, char>> cur;
		if (lst < a[l]) cur.push_back(make_pair(a[l], 'L'));
		if (lst < a[r]) cur.push_back(make_pair(a[r], 'R'));
		sort(cur.begin(), cur.end());
		if (int(cur.size()) == 2 && cur[0].first != cur[1].first) {
			cur.pop_back();
		}
		if (int(cur.size()) == 1) {
			if (cur[0].second == 'L') {
				res += 'L';
				lst = a[l];
				++l;
			} else {
				res += 'R';
				lst = a[r];
				--r;
			}
		} else if (int(cur.size()) == 2) {
			int cl = 1, cr = 1;
			while (l + cl <= r && a[l + cl] > a[l + cl - 1]) ++cl;
			while (r - cr >= l && a[r - cr] > a[r - cr + 1]) ++cr;
			if (cl > cr) {
				res += string(cl, 'L');
			} else {
				res += string(cr, 'R');
			}
			break;
		} else {
			break;
		}
	}
	
	cout << res.size() << endl << res << endl;
	
	return 0;
}
```
[1157D - N Problems During K Days](../problems/D._N_Problems_During_K_Days.md "Codeforces Round 555 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1157D - N Problems During K Days](../problems/D._N_Problems_During_K_Days.md "Codeforces Round 555 (Div. 3)")

I suppose there are some solutions without cases handling, but I'll describe my own, it handling approximately $5$ cases.

Firstly, let $nn = n - \frac{k(k+1)}{2}$. If $nn < 0$ then the answer is "NO" already. Otherwise let's construct the array $a$, where all $a_i$ are $\lfloor\frac{nn}{k}\rfloor$ (except rightmost $nn \% k$ values, they are $\lceil\frac{nn}{k}\rceil$). It is easy to see that the sum of this array is $nn$, it is sorted in non-decreasing order and the difference between the maximum and the minimum elements is not greater than $1$. Let's add $1$ to $a_1$, $2$ to $a_2$ and so on (this is what we subtract from $n$ at the beginning of the solution). Then if $nn \ne k - 1$ or $k = 1$ then this answer is correct. Otherwise we got some array of kind $1, 3, \dots, a_k$. How do we fix that? For $k=2$ or $k=3$ there is no answer for this case (you can try to prove it or try to find answers for cases $n=4, k=2$ and $n=8, k=3$). Otherwise $k > 3$ and we can subtract one from $a_2$ and add it to $a_k$ and this answer will be correct (this also can be proved with some easy formulas).

Time complexity: $O(k)$.

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
	if (n < k * 1ll * (k + 1) / 2) {
		cout << "NO" << endl;
		return 0;
	}
	
	int nn = n - k * (k + 1) / 2;
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		a[i] = i + 1 + (nn / k) + (i >= k - nn % k);
	}
	
	if (nn != k - 1) {
		cout << "YES" << endl;
		for (int i = 0; i < k; ++i) cout << a[i] << " ";
		cout << endl;
	} else {
		if (k > 3) {
			--a[1];
			++a[k - 1];
		}
		if (k == 2 || k == 3) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (int i = 0; i < k; ++i) cout << a[i] << " ";
			cout << endl;
		}
	}
	
	return 0;
}
```
[1157E - Minimum Array](../problems/E._Minimum_Array.md "Codeforces Round 555 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1157E - Minimum Array](../problems/E._Minimum_Array.md "Codeforces Round 555 (Div. 3)")

Let's maintain all elements of the array $b$ in a set that allows multiple copies of equal elements (std::multiset for C++). Then let's iterate from left to right over the array $a$ and try to minimize the current element in array $c$. This order will minimize the resulting array by lexicographical comparing definition. So for the $i$-th element $a_i$ let's find the minimum element greater than or equal to $n - a_i$ in the set because $n - a_i$ will give us remainder $0$, $n - a_i + 1$ will give us remainder $1$ and so on. If there is no greater or equal element in the set then let's take the minimum element of the set and take it as a pair for $a_i$ otherwise let's take this greater or equal element and remove it from the set.

Time complexity: $O(n \log n)$.

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
	multiset<int> b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		b.insert(x);
	}
	
	for (int i = 0; i < n; ++i) {
		auto it = b.lower_bound(n - a[i]);
		if (it == b.end()) it = b.begin();
		cout << (a[i] + *it) % n << " ";
		b.erase(it);
	}
	cout << endl;
	
	return 0;
}
```
[1157F - Maximum Balanced Circle](../problems/F._Maximum_Balanced_Circle.md "Codeforces Round 555 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1157F - Maximum Balanced Circle](../problems/F._Maximum_Balanced_Circle.md "Codeforces Round 555 (Div. 3)")

Let's realize what we need to construct the minimum balanced circle with heights from $l$ to $r$. We can represent it as $l, l + 1, \dots, r - 1, r, r - 1, \dots, l + 1$. As we can see, we need one occurrence of $l$ and $r$ and two occurrences of all other heights from $l + 1$ to $r - 1$. How can we find the maximum balanced circle using this information? We can find the maximum by inclusion segment of neighboring heights with at least two occurrences using the array of frequencies $cnt$, sorted array of unique heights $b$ and two pointers technique. For the current left border $l$ we should increase $r$ (initially it is $l + 1$ and it is an excluded border) while $b_r - b_{r - 1}=1$ and $cnt_{b_r} \ge 2$. Then for the current left and right borders we can try to extend the segment to the left if $b_l - b_{l - 1} = 1$ and to the right if $b_{r + 1} - b_r = 1$ and try to update the answer with the the current segment (and go to the next segment). There may be some corner cases like $n = 1$ or all $cnt$ are $1$, but you can avoid them if you will implement the solution carefully. There are almost no corner cases in my solution, you can see details of implementation in authors code.

Time complexity: $O(n \log n)$ or $O(n)$ (depends on sorting method).

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
	vector<int> cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	
	int l = 0, r = 0;
	int ans = cnt[a[0]];
	for (int i = 0; i < int(a.size()); ++i) {
		int j = i + 1;
		int sum = cnt[a[i]];
		while (a[j] - a[j - 1] == 1 && cnt[a[j]] > 1) {
			sum += cnt[a[j]];
			++j;
		}
		int cr = j - 1;
		if (j < n && a[j] - a[j - 1] == 1) {
			sum += cnt[a[j]];
			cr = j;
		}
		if (ans < sum) {
			ans = sum;
			l = i;
			r = cr;
		}
		i = j - 1;
	}
	
	cout << ans << endl;
	for (int c = 0; c < cnt[a[l]]; ++c) cout << a[l] << " ";
	for (int i = l + 1; i < r; ++i) {
		for (int c = 0; c < cnt[a[i]] - 1; ++c) cout << a[i] << " ";
	}
	for (int c = 0; l != r && c < cnt[a[r]]; ++c) cout << a[r] << " ";
	for (int i = r - 1; i > l; --i) cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
```
[1157G - Inverse of Rows and Columns](../problems/G._Inverse_of_Rows_and_Columns.md "Codeforces Round 555 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

[This](Announcement.md?#comment-508037) is the comment about the quadratic solution. Thank you so much for mentioning this fact, [STommydx](https://codeforces.com/profile/STommydx "Candidate Master STommydx")!

 **Tutorial**
### [1157G - Inverse of Rows and Columns](../problems/G._Inverse_of_Rows_and_Columns.md "Codeforces Round 555 (Div. 3)")

The first observation: if we have an answer where the first row is inverted, we can inverse all rows and columns, then the matrix will remain the same, and the first row is not inverted in the new answer. So we can suppose that the first row is never inverted. Note that this will be true only for slow solution.

The second observation: if we consider a sorted matrix, its first row either consists only of '0's, or has at least one '1' and then all other rows consist only of '1's. This observation can be extended to the following (one user wrote a comment about it and I pinned the link to it above) which can improve time complexity of the solution a lot: in the sorted matrix either the first row consists only of '0's, or the last row consists only of '1's (the corner case is $n = 1$, but for $n=1$ we can obtain both answers).

So what should we do with these observations? I will explain a slow solution, a faster solution can be obtained by mirroring one of cases of this one. Let's iterate over the number of '0's in the first row. Let it be $cnt$. Then the first $cnt$ elements of the first string should be '0's, and all others should be '1's. We can do it by inverting the columns with elements '1' among first $cnt$ elements of the first row and columns with elements '0' among remaining elements. So, it's case handling time!

The first case (when $cnt < m$) is pretty easy. We have to check if all rows from $2$ to $n$ that they consist only of '0's or only of '1's (and if some row consists of '0's then we should invert it). If it is true then we found the answer. Otherwise the first row consists only of '0's. So we have to find the "transitional" row (the row with some '0's on the prefix and '1's on the suffix or vice versa). If the number of such rows among all rows from $2$ to $n$ is greater than $1$ then this configuration is bad. If the number of such rows is $1$ then let $idx$ be the index of this row. Then we should inverse all rows above it consisting only of '1's and all rows consisting only of '0's below it. And we have to check if the current row is really transitional. We know that its sum is neither $0$ nor $m$ so there is at least one '1' and at least '0' in it. If the first element is '1' then let's inverse it. Then we just should check if this row is sorted, and if it is then we found the answer. And the last case is if there are no transitional rows in the matrix. Then we should invert all rows from $2$ to $n$ consisting only of '0's (or only of '1's, it does not matter).

So, we have a solution with time complexity $O(n^3)$. Each number of '0's in the first row is processed in $O(n^2)$ and there are $O(n)$ such numbers. But we can see that if we apply the last case (when the number of '0' is $m$) to the first row and then do the same, but with the last row consisting of $m$ '1', we can get a solution in $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;

void invRow(vector<vector<int>> &a, int idx) {
	for (int pos = 0; pos < m; ++pos) {
		a[idx][pos] ^= 1;
	}
}

void invCol(vector<vector<int>> &a, int idx) {
	for (int pos = 0; pos < n; ++pos) {
		a[pos][idx] ^= 1;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	for (int cnt0 = 0; cnt0 <= m; ++cnt0) {
		string r(n, '0');
		string c(m, '0');
		vector<vector<int>> b = a;
		for (int j = 0; j < m; ++j) {
			if ((j < cnt0 && b[0][j] == 1) || (j >= cnt0 && b[0][j] == 0)) {
				invCol(b, j);
				c[j] = '1';
			}
		}
		bool ok = true;
		if (cnt0 < m) {
			for (int i = 1; i < n; ++i) {
				int sum = accumulate(b[i].begin(), b[i].end(), 0);
				if (sum != 0 && sum != m) {
					ok = false;
				} else if (sum == 0) {
					invRow(b, i);
					r[i] = '1';
				}
			}
		} else {
			int idx = -1;
			for (int i = 1; i < n; ++i) {
				int sum = accumulate(b[i].begin(), b[i].end(), 0);
				if (sum != 0 && sum != m) {
					if (idx != -1) ok = false;
					else idx = i;
				}
			}
			if (idx == -1) {
				for (int i = 1; i < n; ++i) {
					int sum = accumulate(b[i].begin(), b[i].end(), 0);
					if (sum == 0) {
						invRow(b, i);
						r[i] = '1';
					}
				}
			} else {
				for (int i = 1; i < idx; ++i) {
					int sum = accumulate(b[i].begin(), b[i].end(), 0);
					if (sum == m) {
						invRow(b, i);
						r[i] = '1';
					}
				}
				if (b[idx][0] == 1) {
					invRow(b, idx);
					r[idx] = '1';
				}
				for (int j = 1; j < m; ++j) {
					if (b[idx][j] < b[idx][j - 1]) {
						ok = false;
					}
				}
				for (int i = idx + 1; i < n; ++i) {
					int sum = accumulate(b[i].begin(), b[i].end(), 0);
					if (sum == 0) {
						invRow(b, i);
						r[i] = '1';
					}
				}
			}
		}
		if (ok) {
			cout << "YES" << endl << r << endl << c << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}
```
