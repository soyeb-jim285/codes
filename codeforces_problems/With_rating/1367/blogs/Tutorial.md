# Tutorial

All problems were developed by me [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz") and [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly").

[1367A - Short Substrings](../problems/A._Short_Substrings.md "Codeforces Round 650 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1367A - Short Substrings](../problems/A._Short_Substrings.md "Codeforces Round 650 (Div. 3)")

Note that the first two characters of a match the first two characters of b. The third character of the string b again matches the second character of a (since it is the first character in the second substring, which contains the second and the third character of a). The fourth character b matches with the third character of a.

It is easy to notice that such a pattern continues further. That is, the string a consists of the first character b and all characters at even positions in b.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {
		string b;
		cin >> b;

		string a = b.substr(0, 2);

		for (int i = 3; i < b.size(); i += 2) {
			a += b[i];
		}

		cout << a << endl;
	}

	return 0;
}

```
[1367B - Even Array](../problems/B._Even_Array.md "Codeforces Round 650 (Div. 3)")

Авторы: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly")

 **Editorial**
### [1367B - Even Array](../problems/B._Even_Array.md "Codeforces Round 650 (Div. 3)")

We split all the positions in which the parity of the index does not match with the parity of the element into two arrays. If there is an odd number in the even index, add this index to the e array. Otherwise, if there is an even number in the odd index, add this index to the o array. Note that if the sizes of the o and e arrays are not equal, then there is no answer. Otherwise, the array a can be made good by doing exactly |o| operations by simply swapping all the elements in the o and e arrays.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 != i % 2) {
            if (i % 2 == 0) {
                a++;
            } else {
                b++;
            }
        }
    }
    if (a != b) {
        cout << -1 << endl;
    } else {
        cout << a << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
```
[1367C - Social Distance](../problems/C._Social_Distance.md "Codeforces Round 650 (Div. 3)")

Авторы: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly")

 **Editorial**
### [1367C - Social Distance](../problems/C._Social_Distance.md "Codeforces Round 650 (Div. 3)")

Let's split a given string into blocks of consecutive zeros. Then in each such block, you can independently put the maximum number of people who fit in it. But there are three cases to consider. 

* If the current block is not the first and not the last, then there are ones at the border and this means that the first k tables of the current block and the last k are prohibited. Therefore, remove these zeroes from the string.
* If the current block is the first, then the one is at the end and you need to delete the last k zeros.
* If the current block is the last, then in the beginning there is one and you need to delete the first k zeros.

 Also, as a separate case, you need to consider — a string consisting only of zeros. Then there is exactly one block from which you do not need to remove zeros.Now all the tables in each block are free, then in each block we can put ⌊number of zerosk⌋. Sum these values over all blocks.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int res = 0;

		for (int i = 0; i < n;) {
			int j = i + 1;

			for (; j < n && s[j] != '1'; j++);

			int left = s[i] == '1' ? k : 0;
			int right = j < n && s[j] == '1' ? k : 0;
			int len = j - i;

			if (left == k) {
				len--;
			}

			len -= left + right;

			if (len > 0) {
				res += (len + k) / (k + 1);
			}

			i = j;
		}

		cout << res << endl;
	}

	return 0;
}
```
[1367D - Task On The Board](../problems/D._Task_On_The_Board.md "Codeforces Round 650 (Div. 3)") Автор: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1367D - Task On The Board](../problems/D._Task_On_The_Board.md "Codeforces Round 650 (Div. 3)")

We will construct the string t, starting with the largest letters. Note that if bi=0, then the i-th letter of the string t is maximal, so we know that the i-th letter affect all bj≠0. While the string t is not completely constructed, we will do the following: 

* Find all i such that bi=0 and the i-th character of string t is not placed;
* Put on all these positions i in the string t the maximum letter not used in the string t (there should be a sufficient number of letters in the string s);
* Subtract |i−j| from all bj≠0.
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int q;
    cin >> q;
    forn(qq, q) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        vector<int> b(n);
        forn(i, n)
            cin >> b[i];
        vector<vector<int>> groups;
        while (true) {
            vector<int> pos;
            forn(i, n)
                if (b[i] == 0)
                    pos.push_back(i);
            if (pos.empty())
                break;
            groups.push_back(pos);
            forn(i, n)
                if (b[i] == 0)
                    b[i] = INT_MAX;
                else
                    for (int pp: pos)
                        b[i] -= abs(i - pp);
        }
        map<char, int> cnts;
        forn(i, s.size())
            cnts[s[i]]++;
        auto j = cnts.rbegin();
        string t(n, '?');
        for (auto g: groups) {
            while (j->second < g.size())
                j++;
            for (int pp: g)
                t[pp] = j->first;
            j++;
        }
        cout << t << endl;
    }
}

```
[1367E - Necklace Assembly](../problems/E._Necklace_Assembly.md "Codeforces Round 650 (Div. 3)")

Автор: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1367E - Necklace Assembly](../problems/E._Necklace_Assembly.md "Codeforces Round 650 (Div. 3)")

Let's iterate over the m — length of the k-beautiful necklace. For each position i, make an edge to the position p[i]=(i+k)modm, where amodb — is the remainder of dividing a by b. What is a cyclic shift by k in this construction? A bead located at position i will go along the edge to position p[i]. Consider all the cycles of a graph constructed on p. You may notice that if only equal letters are found in each cycle, then with a cyclic shift by k the graph and the string will remain unchanged. Thus, in order to check whether it is possible to make a k-beautiful necklace of length m, you need to make a graph p, find the cycles in it and check whether it is possible to distribute the letters from the string s in cycles such that each cycle have equal letters. The last part of the solution can be done with simple greedy.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;

	while (test--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> cnt(26);

		for (char c : s) {
			cnt[c - 'a']++;
		}

		for (int len = n; len >= 1; len--) {
			vector<bool> used(len);
			vector<int> cycles;

			for (int i = 0; i < len; i++) {
				if (used[i]) {
					continue;
				}

				int j = (i + k) % len;
				used[i] = true;
				cycles.push_back(0);
				cycles.back()++;

				while (!used[j]) {
					cycles.back()++;
					used[j] = true;
					j = (j + k) % len;
				}
			}

			vector<int> cur_cnt(cnt);

			sort(cycles.begin(), cycles.end());
			sort(cur_cnt.begin(), cur_cnt.end());

			bool can_fill = true;

			while (!cycles.empty()) {
				if (cur_cnt.back() < cycles.back()) {
					can_fill = false;
					break;
				} else {
					cur_cnt.back() -= cycles.back();
					cycles.pop_back();
					sort(cur_cnt.begin(), cur_cnt.end());
				}
			}

			if (can_fill) {
				cout << len << endl;
				break;
			}
		}
	}
}
```
[1367F2 - Flying Sort (Hard Version)](../problems/F2._Flying_Sort_(Hard_Version).md "Codeforces Round 650 (Div. 3)")

Автор: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly") [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1367F2 - Flying Sort (Hard Version)](../problems/F2._Flying_Sort_(Hard_Version).md "Codeforces Round 650 (Div. 3)")

Let's replace each number ai with the number of unique numbers less than ai.

For example, the array a=[3,7,1,2,1,3] will be replaced by [2,3,0,1,0,2].

Note that the values of the numbers themselves were not important to us, only the order between them was important.

Let's sort such an array. Let's see what maximum length of the segment from the array a is already sorted (it forms a subsequence). This segment can be left in place, and all other numbers can be moved either to the beginning or to the end. That is, the task came down to finding the maximum sorted subsequence in the array.

This problem can be solved with the help of simple dynamic programming. Let dp[i] —- be the maximum length of a subsequence ending in position i. To calculate it, we will find the closest past position, which also has the value a[i] and the position with value a[i]−1 (lower numbers cannot be used, since a[i]−1 must stand between them). Any of these positions can be extended, so we take the maximum out of them and add 1. It is necessary to separately consider the first numbers in the subsequence and the last, since the first should include their suffix, and the last should have their prefix.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[i] = {v[i], i};
    }
    sort(a.begin(), a.end());
    vector<int> p(n);
    int j = 0;
    unordered_multiset<int> next;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i].first != a[i - 1].first) {
            j++;
        }
        p[a[i].second] = j;
        next.insert(j);
    }
    unordered_map<int, int> d;
    vector<int> dp1(n), dp2(n), dp3(n), cnt(n);
    for (int i = 0; i < n; i++) {
        if (next.count(p[i])) {
            next.erase(next.find(p[i]));
        }
        if (d.count(p[i] - 1)) {
            if (!d.count(p[i])) {
                dp2[i] = max(dp2[i], dp1[d[p[i] - 1]] + 1);
                if (!next.count(p[i] - 1)) {
                    dp2[i] = max(dp2[i], dp2[d[p[i] - 1]] + 1);
                }
            }
            if (!next.count(p[i] - 1)) {
                dp3[i] = max(dp3[i], dp2[d[p[i] - 1]] + 1);
            }
            dp3[i] = max(dp3[i], dp1[d[p[i] - 1]] + 1);
        }
        if (d.count(p[i])) {
            dp3[i] = max(dp3[i], dp3[d[p[i]]] + 1);
            dp2[i] = max(dp2[i], dp2[d[p[i]]] + 1);
            dp1[i] = dp1[d[p[i]]] + 1;
        } else {
            dp1[i] = 1;
        }
        dp2[i] = max(dp2[i], dp1[i]);
        dp3[i] = max(dp3[i], dp2[i]);
        d[p[i]] = i;
    }
    cout << n - *max_element(dp3.begin(), dp3.end()) << "n";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}


```
