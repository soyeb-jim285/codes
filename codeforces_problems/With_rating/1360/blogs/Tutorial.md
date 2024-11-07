# Tutorial

All problems were invented by [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and developed by me, [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), and [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz").

[1360A - Minimal Square](../problems/A._Minimal_Square.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360A - Minimal Square](../problems/A._Minimal_Square.md "Codeforces Round 644 (Div. 3)")

Obviously that both rectangles should completely touch by one of the sides. Otherwise, you can move them closer to each other so that the total height or total width decreases, and the other dimension does not change. Thus, there are only two options: 

* The rectangles touch by width, we get the side of the square equal to $\max(2b, a)$,
* The rectangles touch by height, we get the side of the square equal to $\max(2a, b)$.

 Thus, the minimum side of the square is equal to the minimum of these two options. Then the answer is $(\min(\max(2b, a), \max(2a, b)))^2$. **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int solve(int a, int b) {
    int side = min(max(a * 2, b), max(a, b * 2));
    return side * side;
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    forn(tt, t) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}

```
[1360B - Honest Coach](../problems/B._Honest_Coach.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360B - Honest Coach](../problems/B._Honest_Coach.md "Codeforces Round 644 (Div. 3)")

Let's found two athletes with numbers $a$ and $b$ (the strength of $a$ is not greater than the strength of $b$), which have the minimal modulus of the difference of their strength. Obviously, we cannot get an answer less than this. Let's show how to get the partition with exactly this answer.

Sort all athletes by strength. Our two athletes will stand in neighboring positions (otherwise, we can decrease the answer). Let the first team contains all athletes who stand on positions not further than $a$, and the second team contains other athletes. We got a partition, in which the athlete with number $a$ has the maximal strength in the first team, and the athlete with number $b$ has the minimal strength in the second team.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;

	for (int tt = 0; tt < test; tt++) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (int &x : a) {
			cin >> x;
		}

		sort(a.begin(), a.end());

		int result = a[n - 1] - a[0];

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				result = min(result, a[j] - a[i]);
			}
		}

		cout << result << endl;
	}

	return 0;
}
```
[1360C - Similar Pairs](../problems/C._Similar_Pairs.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360C - Similar Pairs](../problems/C._Similar_Pairs.md "Codeforces Round 644 (Div. 3)")

Let $e$ — be the number of even numbers in the array, and $o$ — be the number of odd numbers in the array. Note that if the parities of $e$ and of $o$ do not equal, then the answer does not exist. Otherwise, we consider two cases: 

* $e$ and $o$ — are even numbers. Then all numbers can be combined into pairs of equal parity.
* $e$ and $o$ — are odd numbers. Then you need to check whether there are two numbers in the array such that the modulus of their difference is $1$. If there are two such numbers, then combine them into one pair. $e$ and $o$ will decrease by $1$ and become even, then the solution exists as shown in the previous case.
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
    int a = 0, b = 0;
    for (int &e : v) {
        cin >> e;
        if (e % 2 == 0) {
            a++;
        } else {
            b++;
        }
    }
    if (a % 2 != b % 2) {
        cout << "NOn";
    } else {
        if (a % 2 == 0) {
            cout << "YESn";
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (v[i] % 2 != v[j] % 2 && abs(v[i] - v[j]) == 1) {
                        cout << "YESn";
                        return;
                    }
                }
            }
            cout << "NOn";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1360D - Buying Shovels](../problems/D._Buying_Shovels.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360D - Buying Shovels](../problems/D._Buying_Shovels.md "Codeforces Round 644 (Div. 3)")

If Polycarp buys $a$ packages of $b$ shovels and gets exactly $n$ shovels in total, then $a \cdot b = n$, that is, $a$ and $b$ are divisors of $n$. Then the problem reduces to the following, you need to find the maximum divisor of the number $n$ not greater than $k$. To do this, iterate over all the numbers $x$ from $1$ to $\sqrt n$ inclusive and check whether $n$ is divisible by $x$. If so, then $x$ and $\frac{n}{x}$ — are both divisors of $n$ and you can use them to try to improve the answer.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;

	for (int tt = 0; tt < test; tt++) {
		int n, k;
		cin >> n >> k;

		int ans = n;

		for (int j = 1; j * j <= n; j++) {
			if (n % j == 0) {
				if (j <= k) {
					ans = min(ans, n / j);
				}

				if (n / j <= k) {
					ans = min(ans, j);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
```
[1360E - Polygon](../problems/E._Polygon.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360E - Polygon](../problems/E._Polygon.md "Codeforces Round 644 (Div. 3)")

Let's see how the matrix looks like after some sequence of shoots: 

* The matrix consists of 0, or
* There is at least one 1 at position ($n, i$) or ($i, n$), and any 1 not at position ($n, j$) or ($j, n$) must have 1 below or right.

If the second condition is violated, then the 1 in the corresponding cell would continue its flight. Thus, it is necessary and sufficient to verify that the matrix satisfies the condition above.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool a[50][50];

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }

    bool ans = true;
    for (int i = n - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        if (a[i][j] && !a[i + 1][j] && !a[i][j + 1]) {
          ans = false;
        }
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}
```
[1360F - Spy-string](../problems/F._Spy-string.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360F - Spy-string](../problems/F._Spy-string.md "Codeforces Round 644 (Div. 3)")

Consider all strings that differ from the first one in no more than one position (this is either the first string or the first string with one character changed). We will go through all such strings and see if they can be the answer. To do this, go through all the strings and calculate the number of positions where they differ.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string ans = v[0];
    for (int j = 0; j < m; j++) {
        char save = ans[j];
        for (char d = 'a'; d <= 'z'; d++) {
            ans[j] = d;
            bool flag = true;
            for (int z = 0; z < n; z++) {
                int cntErrors = 0;
                for (int c = 0; c < m; c++) {
                    if (v[z][c] != ans[c]) {
                        cntErrors++;
                    }
                }
                if (cntErrors > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << ans << endl;
                return;
            }
        }
        ans[j] = save;
    }
    cout << "-1" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1360G - A/B Matrix](../problems/G._A_B_Matrix.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360G - A/B Matrix](../problems/G._A_B_Matrix.md "Codeforces Round 644 (Div. 3)")

Let's see how the desired matrix looks like. Since each row should have exactly $a$ ones, and each column should have exactly $b$ ones, the number of ones in all rows $a \cdot n$ should be equal to the number of ones in all columns $b \cdot m$. Thus, the desired matrix exists iff $a \cdot n = b \cdot m$ or $\frac{n}{m} = \frac{b}{a}$.

Let's show how to construct the desired matrix if it exists. Let's find any number $0<d<m$ such that $(d \cdot n) \% m = 0$, where $a \% b$ — is the remainder of dividing $a$ by $b$. In the first row of the desired matrix, we put the ones at the positions $[1, a]$, and in the $i$-th row we put the ones, as in the $i-1$ row, but cyclically shifted by $d$ to the right.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int test;
  cin >> test;

  for (int tt = 0; tt < test; tt++) {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    if (h * a != w * b) {
      cout << "NO" << endl;
      continue;
    }

    vector<vector<int>> result(h, vector<int>(w, 0));

    int shift = 0;

    for (shift = 1; shift < w; shift++) {
      if (shift * h % w == 0) {
        break;
      }
    }

    for (int i = 0, dx = 0; i < h; i++, dx += shift) {
      for (int j = 0; j < a; j++) {
        result[i][(j + dx) % w] = 1;
      }
    }

    cout << "YES" << endl;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << result[i][j];
      }

      cout << endl;
    }
  }

  return 0;
}
```
[1360H - Binary Median](../problems/H._Binary_Median.md "Codeforces Round 644 (Div. 3)")

 **Editorial**
### [1360H - Binary Median](../problems/H._Binary_Median.md "Codeforces Round 644 (Div. 3)")

If we did not delete the strings, then the median would be equal to the binary notation of $2^{(m-1)}$. After deleting $n$ strings, the median cannot change (numerically) by more than $2 \cdot n$. 

Let's start with the median $2^{(m-1)}$ and each time decrease it by one if there are fewer not deleted smaller numbers than not deleted large numbers. Similarly, you need to increase the median by one, otherwise. The algorithm stops when the result is the median of the current set. All these steps will run at most $200$ times.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

void solve() {
	ll m, n;
	cin >> n >> m;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			v[i] *= 2;
			v[i] += c - '0';
		}
	}
	ll need = ((1ll << m) - n - 1) / 2 + 1;
	ll cur = (1ll << (m - 1)) - 1;
	while (true) {
		ll left = cur + 1;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			flag |= v[i] == cur;
			if (v[i] <= cur) {
				left--;
			}
		}
		if (left == need && !flag) {
			string s;
			for (int i = 0; i < m; i++) {
				s += (char)(cur % 2 + '0');
				cur /= 2;
			}
			reverse(s.begin(), s.end());
			cout << s << endl;
			return;
		} else if (left < need) {
			cur++;
		} else {
			cur--;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
```
