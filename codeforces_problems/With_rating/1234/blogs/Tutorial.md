# Tutorial

Suddenly, all problems expect A and D were invented by me. The author of A and D is [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

[1234A - Equalize Prices Again](../problems/A._Equalize_Prices_Again.md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234A - Equalize Prices Again](../problems/A._Equalize_Prices_Again.md "Codeforces Round 590 (Div. 3)")

In this problem, we need to find the minimum possible $price$ such that $price \cdot n \ge sum$, where $sum$ is the sum of all $a_i$. $price$ equals to $\lceil \frac{sum}{n} \rceil$, where $\lceil \frac{x}{y} \rceil$ is $x$ divided by $y$ rounded up.

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
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			sum += x;
		}
		cout << (sum + n - 1) / n << endl;
	}
	
	return 0;
}

```
[1234B1 - Social Network (easy version)](../problems/B1._Social_Network_(easy_version).md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234B1 - Social Network (easy version)](../problems/B1._Social_Network_(easy_version).md "Codeforces Round 590 (Div. 3)")

The solution to this problem is just the implementation of what is written in the problem statement. Let's carry the array $q$ which shows the current smartphone screen. When we receive the new message from the friend with ID $id_i$, let's do the following sequence of moves:

1. Firstly, let's try to find him on the screen. If he is found, just do nothing and continue.
2. Otherwise, let's check if the current number of conversations is $k$. If it is so then let's remove the last conversation.
3. Now the number of conversations is less than $k$ and the current friend is not shown on the screen. Let's insert him into the first position.

After processing all $n$ messages the answer is just the array $q$.

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
	vector<int> ids;
	for (int i = 0; i < n; ++i) {
		int id;
		cin >> id;
		if (find(ids.begin(), ids.end(), id) == ids.end()) {
			if (int(ids.size()) >= k) ids.pop_back();
			ids.insert(ids.begin(), id);
		}
	}
	
	cout << ids.size() << endl;
	for (auto it : ids) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
[1234B2 - Social Network (hard version)](../problems/B2._Social_Network_(hard_version).md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234B2 - Social Network (hard version)](../problems/B2._Social_Network_(hard_version).md "Codeforces Round 590 (Div. 3)")

The idea of this solution is the same as in the easy version, but now we need to do the same sequence of moves faster. We can notice that the smartphone screen works as a queue, so let store it as a queue! When the new message appears, we have to check if the friend with this ID is in the queue already, but we need to check it somehow fast. Let's use some logarithmic structure that stores the same information as the queue but in other order to find, add and remove elements fast. In C++ this structure is std::set.

So let's check if the current friend is in the queue, and if no, let's check if the size of the queue is $k$. If it is so then let's remove the first element of the queue from it and the same element from the set also. Then add the current friend to the queue and to the set. After processing all messages, the reversed queue (the queue from tail to head) is the answer to the problem.

Time complexity: $O(n \log{k})$.

And don't forget that std::unordered_map and other standard hashmaps can work in linear time in the worst case, so you need to redefine the hash function to use them. You can read more about this issue here: <https://codeforces.com/blog/entry/62393>.

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
	
	queue<int> q;
	set<int> vals;
	for (int i = 0; i < n; ++i) {
		int id;
		cin >> id;
		if (!vals.count(id)) {
			if (int(q.size()) >= k) {
				int cur = q.front();
				q.pop();
				vals.erase(cur);
			}
			vals.insert(id);
			q.push(id);
		}
	}
	
	vector<int> res;
	while (!q.empty()) {
		res.push_back(q.front());
		q.pop();
	}
	reverse(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto it : res) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
[1234C - Pipes](../problems/C._Pipes.md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234C - Pipes](../problems/C._Pipes.md "Codeforces Round 590 (Div. 3)")

Let's see how the water can flow when it meets the pipe of type $1$ or $2$ and in the other case. When the water meets the pipe of type $1$ or $2$ we cannot do anything but let it flow to the right of the current cell. Otherwise (if the current pipe is curved) then there are two cases: if the pipe on the same position but in the other row is not curved then the answer is "NO" because the water has to change the row but we cannot turn the next pipe to allow it to move to the right or to the left. So, the current pipe is curved and the pipe on the same position in the other row is also curved, let's change the row and move to the right (it is obvious that we never need to move to the left).

So, the answer (and the sequence of pipes) is uniquely defined by types of pipes. If after iterating over all $n$ positions we didn't meet the case of "NO" and the current row is second, then the answer is "YES".

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
		string s[2];
		cin >> n >> s[0] >> s[1];
		int row = 0;
		int pos = 0;
		for (pos = 0; pos < n; ++pos) {
			if (s[row][pos] >= '3') {
				if (s[row ^ 1][pos] < '3') {
					break;
				} else {
					row ^= 1;
				}
			}
		}
		if (pos == n && row == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
```
[1234D - Distinct Characters Queries](../problems/D._Distinct_Characters_Queries.md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234D - Distinct Characters Queries](../problems/D._Distinct_Characters_Queries.md "Codeforces Round 590 (Div. 3)")

Let's store for each letter all positions in which it appears in some data structure. We need such a data structure that can add, remove and find the next element greater than or equal to our element, fast enough. Suddenly, this data structure is std::set again (in C++).

When we meet the first type query, let's just modify two elements of corresponding sets (one remove, one add). When we meet the second type query, let's iterate over all letters. If the current letter is in the segment $[l; r]$ then the first element greater than or equal to $l$ in the corresponding set should exist and be less than or equal to $r$. If it is so, let's increase the answer by one. After iterating over all letters just print the answer.

Time complexity: $O(n \log{n} AL)$, when $AL$ is the size of the alphabet.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	vector<set<int>> poss(26);
	for (int i = 0; i < int(s.size()); ++i) {
		poss[s[i] - 'a'].insert(i);
	}
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			--pos;
			poss[s[pos] - 'a'].erase(pos);
			s[pos] = c;
			poss[s[pos] - 'a'].insert(pos);
		} else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			int cnt = 0;
			for (int c = 0; c < 26; ++c) {
				auto it = poss[c].lower_bound(l);
				if (it != poss[c].end() && *it <= r) ++cnt;
			}
			cout << cnt << endl;
		}
	}
	
	return 0;
}
```
[1234E - Special Permutations](../problems/E._Special_Permutations.md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234E - Special Permutations](../problems/E._Special_Permutations.md "Codeforces Round 590 (Div. 3)")

Let's calculate the answer for the first permutation $p_1(n)$ naively in $O(m)$. Then let's recalculate the answer somehow and then maybe prove that it works in linear time.

Which summands will change when we try to recalculate the function $f(p_i(n))$ using $f(p_1(n))$? First of all, let's notice that each pair of adjacent elements of $x$ is the segment on the permutation. To calculate $f(p_i(n))$ fast, let's firstly notice that all segments that cover the element $i$ (but $i$ is not their endpoint) will change their length by minus one after placing $i$ at the first position (because $i$ will be removed from all such segments).

This part can be calculated in $O(n + m)$. Let's use the standard trick with prefix sums and segments. Let $cnt$ be the array of length $n$. For each pair of adjacent elements $x_j$ and $x_{j+1}$ for all $j$ from $1$ to $m-1$ let's do the following sequence of moves: if $|x_j - x_{j + 1}| < 2$ then there are no points that covered by this segment not being its endpoints, so let's just skip this segment. Otherwise let's increase the value of $cnt[min(x_j, x_{j+1}) + 1]$ by one and decrease the value of $cnt[max(x_j, x_{j + 1})]$ by one. After this, let's build prefix sums on this array (make $cnt[i + 1] := cnt[i + 1] + cnt[i]$ for all $i$ from $1$ to $n-1$). And now $cnt_i$ equals to the number of segments covering the element $i$.

The second part that will change is such segments that $i$ is their endpoint. Let's store the array of arrays $adj$ of length $n$ and $adj[i]$ will store all elements adjacent to $i$ in the array $x$ for all $i$ from $1$ to $n$. But one important thing: we don't need to consider such pairs $x_j$ and $x_{j + 1}$ that $x_j = x_{j + 1}$ (it broke my solution somehow so this part is important).

Knowing these two parts we can easily calculate $f(p_i(n))$ using $f(p_1(n))$. Firstly, let's initialize the result as $res = f(p_1(n)) - cnt[i]$. Then we need to recalculate lengths of such segments that $i$ is their endpoint. Let's iterate over all elements $j$ in $adj[i]$, set $res := res - |j - i|$ (remove the old segment) and set $res := res + j$ (add the length of the segment from $j$ to $1$) and increase $res$ by one if $j < i$ (it means that $i$ and $j$ change their relative order and the length of the segment from $j$ to $i$ increases by one).

Now we can see that after iterating over all $i$ from $1$ to $n$ we make at most $O(n + m)$ moves because each pair of adjacent elements in $x$ was considered at most twice.

Total complexity: $O(n + m)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		--a[i];
	}
	
	vector<long long> res(n);
	for (int j = 0; j < m - 1; ++j) {
		res[0] += abs(a[j] - a[j + 1]);
	}
	
	vector<int> cnt(n);
	vector<vector<int>> adj(n);
	for (int i = 0; i < m - 1; ++i) {
		int l = a[i], r = a[i + 1];
		if (l != r) {
			adj[l].push_back(r);
			adj[r].push_back(l);
		}
		if (l > r) swap(l, r);
		if (r - l < 2) continue;
		++cnt[l + 1];
		--cnt[r];
	}
	for (int i = 0; i < n - 1; ++i) {
		cnt[i + 1] += cnt[i];
	}
	
	for (int i = 1; i < n; ++i) {
		res[i] = res[0] - cnt[i];
		for (auto j : adj[i]) {
			res[i] -= abs(i - j);
			res[i] += j + (j < i);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1234F - Yet Another Substring Reverse](../problems/F._Yet_Another_Substring_Reverse.md "Codeforces Round 590 (Div. 3)")

 **Tutorial**
### [1234F - Yet Another Substring Reverse](../problems/F._Yet_Another_Substring_Reverse.md "Codeforces Round 590 (Div. 3)")

First of all, I wanted to offer you one little challenge: I found a solution that I can't break (and I don't sure if it can be broken) and I will be so happy if anyone will give me countertest which will break it. You can see its code below.

Let's notice that we can reduce our problem to the following: find two substrings of the given string that letters in them do not intersect and the total length of these substrings is the maximum possible. Why can we make such a reduction? It is so because our answer consists of at most two non-intersecting parts: one fixed substring and at most one substring that we appended to the first one. We can always append any other substring to the first one by one reverse operation (just look at some examples to understand it).

Let's iterate over all possible substrings of length at most $AL$ (where $AL$ is the size of the alphabet) which contain distinct letters. We can do it in $O(n AL)$. Let the current substring containing distinct letters be $s[i; j]$. Let's create the bitmask corresponding to this substring: the bit $pos$ is $1$ if the $pos$-th letter of the alphabet is presented in the substring and $0$ otherwise (letters are $0$-indexed).

Store all these masks somewhere. Notice that our current problem can be reduced to the following: we have the set of masks and we need to find a pair of masks that they do not intersect and their total number of ones in them is the maximum possible. This reduction is less obvious than the previous one but you also can understand it considering some examples.

So how to solve this problem? We can do it with easy bitmasks dynamic programming! Let $dp_{mask}$ be the maximum number of ones in some mask that is presented in the given string and it is the submask of $mask$. How to calculate this dynamic programming? First of all, all values $dp_{mask}$ for all masks presented in the string are equal to the number of ones in corresponding masks. Let's iterate over all masks from $0$ to $2^{AL} - 1$. Let the current mask be $mask$. Then let's try to update the answer for this mask with the answer for one of its submasks. It is obvious that because of dynamic programming we need to remove at most one bit from our mask to cover all possible submasks that can update our answer. So let's iterate over all bits in $mask$, let the current bit be $pos$. If this bit is zero then just skip it. Otherwise update $dp_{mask} := max(dp_{mask}, dp_{mask \hat{} 2^{pos}})$, where $\hat{}$ is the xor operation.

After calculating this dynamic programming we can finally calculate the answer. Let's iterate over all masks presented in the string, let the current mask be $mask$. We can update the answer with the number of ones in $mask$ plus $dp_{mask \hat{} (2^{AL} - 1)}$ ($mask \hat{} (2^{AL} - 1)$ is the completion of $mask$).

Total complexity: $O(n AL + AL 2^{AL})$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	
	vector<int> dp(1 << 20);
	for (int i = 0; i < int(s.size()); ++i) {
		vector<bool> used(20);
		int mask = 0;
		for (int j = 0; i + j < int(s.size()); ++j) {
			if (used[s[i + j] - 'a']) break;
			used[s[i + j] - 'a'] = true;
			mask |= 1 << (s[i + j] - 'a');
			dp[mask] = __builtin_popcount(mask);
		}
	}
	
	for (int mask = 0; mask < (1 << 20); ++mask) {
		for (int pos = 0; pos < 20; ++pos) {
			if ((mask >> pos) & 1) {
				dp[mask] = max(dp[mask], dp[mask ^ (1 << pos)]);
			}
		}
	}
	
	int ans = 0;
	for (int mask = 0; mask < (1 << 20); ++mask) {
		if (dp[mask] == __builtin_popcount(mask)) {
			int comp = ~mask & ((1 << 20) - 1);
			ans = max(ans, dp[mask] + dp[comp]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
 **WA?**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int tt = clock();
	
	string s;
	cin >> s;
	
	vector<int> dp(1 << 20);
	vector<int> masks;
	for (int i = 0; i < int(s.size()); ++i) {
		vector<bool> used(20);
		int mask = 0;
		for (int j = 0; i + j < int(s.size()); ++j) {
			if (used[s[i + j] - 'a']) break;
			used[s[i + j] - 'a'] = true;
			mask |= 1 << (s[i + j] - 'a');
			masks.push_back(mask);
		}
	}
	sort(masks.begin(), masks.end());
	masks.resize(unique(masks.begin(), masks.end()) - masks.begin());
	sort(masks.begin(), masks.end(), [](int x, int y){
		return __builtin_popcount(x) > __builtin_popcount(y);
	});
	
	int ans = __builtin_popcount(masks[0]);
	for (int i = 0; i < int(masks.size()); ++i) {
		if (clock() - tt > 1900) {
			break;
		}
		for (int j = i + 1; j < int(masks.size()); ++j) {
			if (!(masks[i] & masks[j])) {
				ans = max(ans, __builtin_popcount(masks[i]) + __builtin_popcount(masks[j]));
				break;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
