# Tutorial

[1311A - Add Odd or Subtract Even](../problems/A._Add_Odd_or_Subtract_Even.md "Codeforces Round 624 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1311A - Add Odd or Subtract Even](../problems/A._Add_Odd_or_Subtract_Even.md "Codeforces Round 624 (Div. 3)")

If a=b then the answer is 0. Otherwise, if a>b and a−b is even or a<b and b−a is odd then the answer is 1. Otherwise the answer is 2 (you can always make 1-case in one move).

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
		if (a == b) cout << 0 << endl;
		else cout << 1 + int((a < b) ^ ((b - a) & 1)) << endl;
	}
	
	return 0;
}
```
[1311B - WeirdSort](../problems/B._WeirdSort.md "Codeforces Round 624 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1311B - WeirdSort](../problems/B._WeirdSort.md "Codeforces Round 624 (Div. 3)")

The simple simulation works here: while there is at least one inversion (such a pair of indices i and i+1 that a[i]>a[i+1]) we can fix, let's fix it (we can fix this inversion if i∈p). If there are inversions but we cannot fix any of them, the answer is "NO". Otherwise, the answer is "YES".

There is also a O(nlogn) solution: it is obvious that we have some segments in which we can change the order of elements as we want. And it is also obvious that we cannot move elements between these "allowed" segments. So, each of them is independent of each other. We can just find all these segments of indices using two pointers and sort them independently. Then we just need to check if the array becomes sorted.

Time complexity is O(n2) or O(nlogn).

 **Solution (n^2)**
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> p(n);
		for (int i = 0; i < m; ++i) {
			int pos;
			cin >> pos;
			p[pos - 1] = 1;
		}
		while (true) {
			bool ok = false;
			for (int i = 0; i < n; ++i) {
				if (p[i] && a[i] > a[i + 1]) {
					ok = true;
					swap(a[i], a[i + 1]);
				}
			}
			if (!ok) break;
		}
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			ok &= a[i] <= a[i + 1];
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
```
 **Solution (n log n)**
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> p(n);
		for (int i = 0; i < m; ++i) {
			int pos;
			cin >> pos;
			p[pos - 1] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if (p[i] == 0) continue;
			int j = i;
			while (j < n && p[j]) ++j;
			sort(a.begin() + i, a.begin() + j + 1);
			i = j;
		}
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			ok &= a[i] <= a[i + 1];
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}

```
[1311C - Perform the Combo](../problems/C._Perform_the_Combo.md "Codeforces Round 624 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1311C - Perform the Combo](../problems/C._Perform_the_Combo.md "Codeforces Round 624 (Div. 3)")

We can consider all tries independently. During the i-th try we press first pi buttons, so it makes +1 on the prefix of length pi. So the i-th character of the string will be pressed (the number of pi≥i plus 1) times. We can use sorting and some kind of binary search to find this number for each character but we also can build suffix sums to find all required numbers. We can build suffix sums using the following code:


```cpp
  
vector<int> cnt(n);  
for (int i = 0; i < m; ++i) {  
    ++cnt[p[i]];  
}  
for (int i = n - 1; i > 0; --i) {  
    cnt[i - 1] += cnt[i];  
}  

```
So as you can see, the i-th element of p will add 1 in each position from 1 to pi. So we got what we need. After that we can calculate the answer for each character in the following way:


```cpp
  
vector<int> ans(26);  
for (int i = 0; i < n; ++i) {  
    ans[s[i] - 'a'] += cnt[i] + 1;  
}  

```
Time complexity: O(nlogn) or O(n).

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
		int n, m;
		string s;
		cin >> n >> m >> s;
		vector<int> pref(n);
		for (int i = 0; i < m; ++i) {
			int p;
			cin >> p;
			++pref[p - 1];
		}
		for (int i = n - 1; i > 0; --i) {
			pref[i - 1] += pref[i];
		}
		vector<int> ans(26);
		for (int i = 0; i < n; ++i) {
			ans[s[i] - 'a'] += pref[i];
			++ans[s[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
```
[1311D - Three Integers](../problems/D._Three_Integers.md "Codeforces Round 624 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1311D - Three Integers](../problems/D._Three_Integers.md "Codeforces Round 624 (Div. 3)")

Let's iterate over all possible values of $A$ from $1$ to $2a$. It is obvious that $A$ cannot be bigger than $2a$, else we can just move $a$ to $1$. Then let's iterate over all possible multiples of $A$ from $1$ to $2b$. Let this number be $B$. Then we can find $C$ as the nearest number to $c$ that is divisible by $B$ (we can check two nearest numbers to be sure). These numbers are $C = \lfloor\frac{c}{B}\rfloor \cdot B$ and $C = \lfloor\frac{c}{B}\rfloor \cdot B + B$. Then we can update the answer with the found triple. Note that the only condition you need to check is that $B \le C$.

Time complexity: $O(n \log n)$ because of the sum of the harmonic series.

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
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 1e9;
		int A = -1, B = -1, C = -1;
		for (int cA = 1; cA <= 2 * a; ++cA) {
			for (int cB = cA; cB <= 2 * b; cB += cA) {
				for (int i = 0; i < 2; ++i) {
					int cC = cB * (c / cB) + i * cB;
					int res = abs(cA - a) + abs(cB - b) + abs(cC - c);
					if (ans > res) {
						ans = res;
						A = cA;
						B = cB;
						C = cC;
					}
				}
			}
		}
		cout << ans << endl << A << " " << B << " " << C << endl;
	}
	
	return 0;
}
```
[1311E - Construct the Binary Tree](../problems/E._Construct_the_Binary_Tree.md "Codeforces Round 624 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1311E - Construct the Binary Tree](../problems/E._Construct_the_Binary_Tree.md "Codeforces Round 624 (Div. 3)")

This problem has an easy constructive solution. We can find lower and upper bounds on the value of $d$ for the given $n$. If the given $d$ does not belong to this segment, then the answer is "NO". Otherwise, the answer is "YES" for any $d$ in this segment.

How to construct it? Let's start from the chain. The answer for the chain is the upper bound of $d$ and it is $\frac{n(n-1)}{2}$. Then let's try to decrease the answer by $1$ in one move. Let's take some leaf $v$ (the vertex without children) with the smallest depth that is not bad and try to move it up. The definition of badness will be below. To do this, let's find such vertex $p$ that its depth is less than the depth of $v$ by $2$ and it has less than $2$ children. If we found such vertex $p$ then let's make $v$ the child of $p$ and decrease the answer by one.

If we didn't find such vertex $p$, I claim that the vertex $v$ has the minimum possible depth it can have and we should not consider it in the future. Let's mark this vertex as bad and continue our algorithm.

If at some moment we cannot find any not bad leaf $v$, then the answer is "NO". Otherwise, the answer is "YES".

Time complexity: $O(nd)$.

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
		int n, d;
		cin >> n >> d;
		int ld = 0, rd = n * (n - 1) / 2;
		for (int i = 1, cd = 0; i <= n; ++i) {
			if (!(i & (i - 1))) ++cd;
			ld += cd - 1;
		}
		if (!(ld <= d && d <= rd)) {
			cout << "NO" << endl;
			continue;
		}
	
		vector<int> par(n);
		iota(par.begin(), par.end(), -1);
		
		vector<int> cnt(n, 1);
		cnt[n - 1] = 0;
		
		vector<int> bad(n);
		
		vector<int> dep(n);
		iota(dep.begin(), dep.end(), 0);
		
		int cur = n * (n - 1) / 2;
		while (cur > d) {
			int v = -1;
			for (int i = 0; i < n; ++i) {
				if (!bad[i] && cnt[i] == 0 && (v == -1 || dep[v] > dep[i])) {
					v = i;
				}
			}
			assert(v != -1);
			int p = -1;
			for (int i = 0; i < n; ++i) {
				if (cnt[i] < 2 && dep[i] < dep[v] - 1 && (p == -1 || dep[p] < dep[i])) {
					p = i;
				}
			}
			if (p == -1) {
				bad[v] = 1;
				continue;
			}
			assert(dep[v] - dep[p] == 2);
			--cnt[par[v]];
			--dep[v];
			++cnt[p];
			par[v] = p;
			--cur;
		}
	
		cout << "YES" << endl;
		for (int i = 1; i < n; ++i) cout << par[i] + 1 << " ";
		cout << endl;
	}
		
	return 0;
}
```
[1311F - Moving Points](../problems/F._Moving_Points.md "Codeforces Round 624 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1311F - Moving Points](../problems/F._Moving_Points.md "Codeforces Round 624 (Div. 3)")

Let's understand when two points $i$ and $j$ coincide. Let $x_i < x_j$. Then they are coincide when $v_i > v_j$. Otherwise, these two points will never coincide and the distance between them will only increase.

So, we need to consider only the initial positions of points. Let's sort all points by $x_i$ and consider them one by one from left to right. Let the $i$-th point be the rightmost in the pair of points that we want to add to the answer.

We need to find the number of points $j$ such that $x_j < x_i$ and $v_j \le v_i$ and the sum of $x_j$ for such points as well. We can do this using two BITs (Fenwick trees) if we compress coordinates (all values $v$) and do some kind of "scanline" by values $x$. Let the number of such points be $cnt$ and the sum of coordinates of such points be $sum$. Then we can increase the answer by $x_i \cdot cnt - sum$ and add our current point to the Fenwick trees (add $1$ to the position $v_i$ in the first tree and $x_i$ to the position $v_i$ in the second tree). When we want to find the number of required points and the sum of its coordinates, we just need to find the sum on the prefix two times in Fenwick trees. Note that you can use any "online" logarithmic data structure you like in this solution (such as treap and segment tree).

There is also another solution that uses [pbds](https://codeforces.com/blog/entry/11080). Let's do the same thing, but there is one problem. Such data structure does not have "sum on prefix" function, so we have to replace it somehow. To do this, let's calculate only $x_i \cdot cnt$ part when we go from left to right. Then let's clear our structure, go among all points again but from right to left and calculate the same thing, but with the opposite sign (find the number of points $j$ such that $x_j > x_i$ and $v_j \ge v_i$). When we go from right to left, we need to decrease the answer by $x_i \cdot cnt$. It is some kind of "contribution to the sum" technique.

Time complexity: $O(n \log n)$.

 **Solution (Fenwick tree)**
```cpp
#include <bits/stdc++.h>

using namespace std;

long long get(vector<long long> &f, int pos) {
	long long res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

void upd(vector<long long> &f, int pos, int val) {
	for (; pos < int(f.size()); pos |= pos + 1) {
		f[pos] += val;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &pnt : p) cin >> pnt.first;
	for (auto &pnt : p) cin >> pnt.second;
	sort(p.begin(), p.end());
	
	vector<int> vs;
	for (auto &pnt : p) vs.push_back(pnt.second);
	sort(vs.begin(), vs.end());
	vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
	
	long long ans = 0;
	vector<long long> cnt(vs.size()), xs(vs.size());
	for (auto &pnt : p) {
		int pos = lower_bound(vs.begin(), vs.end(), pnt.second) - vs.begin();
		ans += get(cnt, pos) * 1ll * pnt.first - get(xs, pos);
		upd(cnt, pos, 1);
		upd(xs, pos, pnt.first);
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **Solution (pbds)**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &pnt : p) cin >> pnt.first;
	for (auto &pnt : p) cin >> pnt.second;
	sort(p.begin(), p.end());
	
	ordered_set s;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = s.order_of_key(make_pair(p[i].second + 1, -1));
		ans += cnt * 1ll * p[i].first;
		s.insert(make_pair(p[i].second, i));
	}
	s.clear();
	for (int i = n - 1; i >= 0; --i) {
		int cnt = int(s.size()) - s.order_of_key(make_pair(p[i].second - 1, n));
		ans -= cnt * 1ll * p[i].first;
		s.insert(make_pair(p[i].second, i));
	}
	
	cout << ans << endl;
	
	return 0;
}
```
