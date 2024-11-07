# Tutorial

[1015A - Points in Segments](../problems/A._Points_in_Segments.md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015A - Points in Segments](../problems/A._Points_in_Segments.md "Codeforces Round 501 (Div. 3)")

In this problem all you need is to check for each point from $1$ to $m$ if it cannot belongs to any segment. It can be done in $O(n \cdot m)$ by two nested loops or in $O(n + m)$ by easy prefix sums calculation. Both solutions are below.

 **Solution (Vovuh, O(n + m))**
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
	vector<int> cnt(m + 2);
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		++cnt[l];
		--cnt[r + 1];
	}
	for (int i = 1; i <= m; ++i)
		cnt[i] += cnt[i - 1];
	
	vector<int> ans;
	for (int i = 1; i <= m; ++i) {
		if (cnt[i] == 0)
			ans.push_back(i);
	}
	
	cout << ans.size() << endl;
	for (auto it : ans) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
 **Solution (Vovuh, O(n * m))**
```cpp
n, m = map(int, input().split())
seg = [list(map(int, input().split())) for i in range(n)]
def bad(x):
	for i in range(n):
		if (seg[i][0] <= x and x <= seg[i][1]): return False
	return True
ans = list(filter(bad, [i for i in range(1, m + 1)]))
print(len(ans))
print(' '.join([str(x) for x in ans]))
```
[1015B - Obtaining the String](../problems/B._Obtaining_the_String.md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015B - Obtaining the String](../problems/B._Obtaining_the_String.md "Codeforces Round 501 (Div. 3)")

This problem can be solved using the next greedy approach: let's iterate over all $i$ from $1$ to $n$. If $s_i = t_i$, go further. Otherwise let's find any position $j > i$ such that $s_j = t_i$ and move the character from the position $j$ to the position $i$. If there is no such position in $s$, the answer is "-1".

Upper bound on time complexity (and the size of the answer) of this solution is $O(n^2)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s, t;
	cin >> n >> s >> t;
	
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) continue;
		int pos = -1;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == t[i]) {
			        pos = j;
			        break;
			}
		}
		if (pos == -1) {
			cout << -1 << endl;
			return 0;
		}
		for (int j = pos - 1; j >= i; --j) {
			swap(s[j], s[j + 1]);
			ans.push_back(j);
		}
	}
	
	assert(s == t);
	
	cout << ans.size() << endl;
	for (auto it : ans) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}
```
[1015C - Songs Compression](../problems/C._Songs_Compression.md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015C - Songs Compression](../problems/C._Songs_Compression.md "Codeforces Round 501 (Div. 3)")

If we will no compress songs, the sum of the sizes will be equal $\sum\limits_{i = 1}^{n} a_i$. Let it be $sum$. Now, if we will compress the $j$-th song, how do $sum$ will change? It will decrease by $a_j - b_j$. This suggests that the optimal way to compress the songs is the compress it in non-increasing order of $a_j - b_j$. Let's create the array $d$ of size $n$, where $d_j = a_j - b_j$. Let's sort it in non-increasing order, and then iterate over all $j$ from $1$ to $n$. If at the current step $sum \le m$, we print $j - 1$ and terminate the program. Otherwise we set $sum := sum - d_j$. After all we have to check again if $sum \le m$ then print $n$ otherwise print "-1".

Time complexity is $O(n \log n)$ because of sorting.

 **Solution (Vovuh)**
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
	vector<pair<int, int>> a(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
	}
	
	sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b) { return a.first - a.second > b.first - b.second; });
	
	for (int i = 0; i < n; ++i) {
		if (sum <= m) {
			cout << i << endl;
			return 0;
		}
		sum -= a[i].first - a[i].second;
	}
	
	if (sum <= m)
		cout << n << endl;
	else
		cout << -1 << endl;
	
	return 0;
}
```
[1015D - Walking Between Houses](../problems/D._Walking_Between_Houses.md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015D - Walking Between Houses](../problems/D._Walking_Between_Houses.md "Codeforces Round 501 (Div. 3)")

The solution for this problem is very simple: at first, if $k > s$ or $k \cdot (n - 1) < s$ the answer is "NO". Otherwise let's do the following thing $k$ times: let $dist$ be $min(n - 1, s - k + 1)$ (we have to greedily decrease the remaining distance but we also should remember about the number of moves which we need to perform). We have to walk to any possible house which is located at distance $dist$ from the current house (also don't forget to subtract $dist$ from $s$).

The proof of the fact that we can always walk to the house at distance $dist$ is very simple: one of the possible answers (which is obtained by the algorithm above) will looks like several moves of distance $n-1$, (possibly) one move of random distance less than $n-1$ and several moves of distance $1$. The first part of the answer can be obtained if we are stay near the leftmost or the rightmost house, second and third parts always can be obtained because distances we will walk in every of such moves is less than $n-1$.

Time complexity is $O(k)$.

 **Solution (BledDest)**
```cpp
def step(cur, x):
    if(cur - x > 0):
        return cur - x
    else:
        return cur + x



n, k, s = map(int, input().split())
cur = 1

if(k > s or k * (n - 1) < s):
    print('NO')
else:
    print('YES')
    while(k > 0):
        l = min(n - 1, s - (k - 1))
        cur = step(cur, l)
        print(cur, end = ' ')
        s -= l
        k -= 1
```
[1015E1 - Stars Drawing (Easy Edition)](../problems/E1._Stars_Drawing_(Easy_Edition).md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015E1 - Stars Drawing (Easy Edition)](../problems/E1._Stars_Drawing_(Easy_Edition).md "Codeforces Round 501 (Div. 3)")

Since we are almost unlimited in the number of stars in the answer, the following solution will works. We iterate over all possible stars centers and try to extend rays of the current star as large as possible. It can be done by the simple iterating and checking in $O(n)$. If the size of the current star is non-zero, let's add it to the answer. It is obvious that the number of stars in such answer will not exceed $n \cdot m$. Then let's try to draw all these stars on the empty grid. Drawing of each star is also can be done in $O(n)$. If after drawing our grid equals to the input grid, the answer is "YES" and our set of stars is the correct answer. Otherwise the answer is "NO".

Time complexity: $O(n^3)$.

 **Solution (MikeMirzayanov, O(n^3))**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int dx[] = {1, 0, -1,  0};
const int dy[] = {0, 1,  0, -1};
const int N = 1001;

int n, m;
vector<string> f;
int d[N][N][4];
int r[N][N], a[N][N], b[N][N];

int getd(int i, int j, int k) {
    int dxk = dx[k];
    int dyk = dy[k];
    int result = 0;
    while (i >= 0 && i < n && j >= 0 && j < m && f[i][j] == '*')
        result++, i += dxk, j += dyk;
    return result;
}

int main() {
    cin >> n >> m;
    f = vector<string>(n);
    forn(i, n)
        cin >> f[i];
    
    memset(d, -1, sizeof(d));
    int result = 0;
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < m; j++)
            if (f[i][j] == '*') {
                bool around = true;
                forn(k, 4)
                    around = around && (f[i + dx[k]][j + dy[k]] == '*');
                if (around) {
                    r[i][j] = INT_MAX;
                    forn(k, 4)
                        r[i][j] = min(r[i][j], getd(i, j, k) - 1);
                    result++;
                    a[i][j - r[i][j]] = max(a[i][j - r[i][j]], 2 * r[i][j] + 1);
                    b[i - r[i][j]][j] = max(b[i - r[i][j]][j], 2 * r[i][j] + 1);
                }
            }

    vector<string> g(n, string(m, '.'));
    forn(i, n) {
        int v = 0;
        forn(j, m) {
            v = max(v - 1, a[i][j]);
            if (v > 0)
                g[i][j] = '*';
        }
    }
    forn(j, m) {
        int v = 0;
        forn(i, n) {
            v = max(v - 1, b[i][j]);
            if (v > 0)
                g[i][j] = '*';
        }
    }
    
    if (f == g) {
        cout << result << endl;
        forn(i, n)
            forn(j, m)
                if (r[i][j] > 0)
                    cout << i + 1 << " " << j + 1 << " " << r[i][j] << endl;
    } else
        cout << -1 << endl;
}
```
[1015E2 - Stars Drawing (Hard Edition)](../problems/E2._Stars_Drawing_(Hard_Edition).md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015E2 - Stars Drawing (Hard Edition)](../problems/E2._Stars_Drawing_(Hard_Edition).md "Codeforces Round 501 (Div. 3)")

I am sorry that some $O(n^3)$ solutions pass tests in this problem also. I was supposed to increase constraints or decrease time limit.

The general idea of this problem is the same as in the previous problem. But now we should do all what we were doing earlier faster. The solution is divided by two parts.

The first part. Let's calculate four matrices of size $n \times m$ — $up$, $down$, $left$ and $right$. $up_{i, j}$ will denote the distance to the nearest dot character to the top from the current position. The same, $down_{i, j}$ will denote the distance to the nearest dot character to the bottom from the current position, $left_{i, j}$ — to the left and $right_{i, j}$ — to the right. We can calculate all these matrices in $O(n^2)$ using easy dynamic programming. If we will iterate over all possible $i$ from $1$ to $n$ and $j$ from $1$ to $m$, we can easy see the next: if the current character is dot, then $up_{i, j} = left_{i, j} = 0$. Otherwise if $i > 1$ then $up_{i, j} = up_{i - 1, j}$, and if $j > 1$ then $left_{i, j} = left_{i, j - 1}$. Rest two matrices can be calculated the as well as these two matrices but we should iterate over all $i$ from $n$ to $1$ and $j$ from $m$ to $1$. So, this part of the solution works in $O(n^2)$.

After calculating all these matrices the maximum possible length of rays of the star with center in position $(i, j)$ is $min(up_{i, j}, down_{i, j}, left_{i, j}, right_{i, j}) - 1$.

The second part is to draw all stars in $O(n^2)$. Let's calculate another two matrices of size $n \times m$ — $h$ and $v$. Let's iterate over all stars in our answer. Let the center of the current star is $(i, j)$ and its size is $s$. Let's increase $h_{i, j - s}$ by one and decrease $h_{i, j + s + 1}$ by one (if $j + s + 1 \le m$). The same with the matrix $v$. Increase $v_{i - s, j}$ and decrease $v_{i + s + 1, j}$ (if $i + s + 1 \le n$). Then let's iterate over all possible $i$ from $1$ to $n$ and $j$ from $1$ to $m$. If $i > 1$ then set $v_{i, j} := v_{i, j} + v_{i - 1, j}$ and if $j > 1$ set $h_{i, j} := h_{i, j} + h_{i, j - 1}$.

How to know that the character at the position $(i, j)$ is asterisk character or dot character? If either $h_{i, j}$ or $v_{i, j}$ greater than zero, then the character at the position $(i, j)$ in our matrix will be the asterisk character. Otherwise it is the dot character. This part works also in $O(n^2)$.

Time complexity of the solution: $O(n^2)$.

 **Solution (Vovuh, O(n^2))**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> s;

vector<string> draw(const vector<pair<pair<int, int>, int>> &r) {
	vector<string> f(n, string(m, '.'));
	vector<vector<int>> h(n, vector<int>(m));
	vector<vector<int>> v(n, vector<int>(m));
	for (auto it : r) {
		int x = it.first.first;
		int y = it.first.second;
		int len = it.second;
		++v[x - len][y];
		if (x + len + 1 < n)
			--v[x + len + 1][y];
		++h[x][y - len];
		if (y + len + 1 < m)
			--h[x][y + len + 1];	
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) v[i][j] += v[i - 1][j];
			if (j > 0) h[i][j] += h[i][j - 1];
			if (v[i][j] > 0 || h[i][j] > 0)
				f[i][j] = '*';
		}
	}
	return f;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	s = vector<string>(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	
	vector<vector<int>> l(n, vector<int>(m));
	vector<vector<int>> r(n, vector<int>(m));
	vector<vector<int>> u(n, vector<int>(m));
	vector<vector<int>> d(n, vector<int>(m));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) {
				if (s[i][j] != '.')
					u[i][j] = u[i - 1][j] + 1;
			} else {
				u[i][j] = s[i][j] != '.';
			}
			if (j > 0) {
				if (s[i][j] != '.')
					l[i][j] = l[i][j - 1] + 1;
			} else {
				l[i][j] = s[i][j] != '.';
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i < n - 1) {
				if (s[i][j] != '.')
					d[i][j] = d[i + 1][j] + 1;
			} else {
				d[i][j] = s[i][j] != '.';
			}
			if (j < m - 1) {
				if (s[i][j] != '.')
					r[i][j] = r[i][j + 1] + 1;
			} else {
				r[i][j] = s[i][j] != '.';
			}
		}
	}
	
	vector<pair<pair<int, int>, int>> ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '*') {
				int len = min(min(u[i][j], l[i][j]), min(d[i][j], r[i][j])) - 1;
				if (len != 0) {
					ans.push_back(make_pair(make_pair(i, j), len));
				}
			}
		}
	}
	
	if (draw(ans) != s) {
		cout << -1 << endl;
	} else {
		cout << ans.size() << endl;
		for (auto it : ans) {
			cout << it.first.first + 1 << " " << it.first.second + 1 << " " << it.second << endl; 
		}
	}
	
	return 0;
}
```
[1015F - Bracket Substring](../problems/F._Bracket_Substring.md "Codeforces Round 501 (Div. 3)")

 **Tutorial**
### [1015F - Bracket Substring](../problems/F._Bracket_Substring.md "Codeforces Round 501 (Div. 3)")

At first, let's calculate the matrix $len$ of size $(n + 1) \times 2$. Let $len_{i, j}$ will denote the maximum length of the prefix of $s$ which equals to the suffix of the prefix of $s$ of length $i$ with the additional character '(' if $j = 0$ and ')' otherwise. In other words, $len_{i, j}$ is denote which maximum length of the prefix of $s$ we can reach if now we have the prefix of $s$ of length $i$ and want to add the character '(' if $j = 0$ and ')' otherwise, and only one possible move is to remove characters from the beginning of this prefix with an additional character. This matrix can be easily calculated in $O(n^3)$ without any dynamic programming. It can be also calculated in $O(n)$ using prefix-function and dynamic programming.

Now let's calculate the following dynamic programming $dp_{i, j, k, l}$. It means that now we have gained $i$ characters of the regular bracket sequence, the balance of this sequence is $j$, the last $k$ characters of the gained prefix is the prefix of $s$ of length $k$ and $l$ equals to $1$ if we obtain the full string $s$ at least once and $0$ otherwise. The stored value of the $dp_{i, j, k, l}$ is the number of ways to reach this state.

Initially, $dp_{0, 0, 0, 0} = 1$, all other values equal $0$.

The following recurrence works: try to add to the current prefix character '(' if the current balance is less than $n$, then we will move to the state $dp{i + 1, j + 1, len_{k, 0}, f~ |~ (len_{k, 0} = |s|)}$. $|s|$ is the length of $s$ and $|$ is OR operation (if at least one is true then the result is true). Let's add to the number of ways to reach the destination state the number of ways to reach the current state.

The same with the character ')'. Try to add to the current prefix character ')' if the current balance is greater than $0$, then we will move to the state $dp{i + 1, j - 1, len_{k, 1}, f~ |~ (len_{k, 1} = |s|)}$. Also add to the number of ways to reach the destination state the number of ways to reach the current state.

After calculating this dynamic programming, the answer is $\sum\limits_{i = 0}^{|s|} dp_{2n, 0, i, 1}$.

Time complexity is $O(n^3)$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 203;
const int MOD = 1e9 + 7;

int n, ssz;
string s;
int len[N][2];
int dp[N][N][N][2];

int calc(const string &t) {
	int tsz = t.size();
	for (int i = tsz; i > 0; --i) {
		if (s.substr(0, i) == t.substr(tsz - i, i))
			return i;
	}
	return 0;
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> s;
	ssz = s.size();
	
	if (s[0] == '(')
		len[0][0] = 1;
	else
		len[0][1] = 1;
	
	string pref;
	for (int i = 0; i < ssz; ++i) {
		pref += s[i];
		pref += '(';
		len[i + 1][0] = calc(pref);
		pref.pop_back();
		pref += ')';
		len[i + 1][1] = calc(pref);
		pref.pop_back();
	}
	
	dp[0][0][0][0] = 1;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int pos = 0; pos <= ssz; ++pos) {
				for (int f = 0; f < 2; ++f) {
					if (dp[i][j][pos][f] == 0) continue;
					if (j + 1 <= n)
						add(dp[i + 1][j + 1][len[pos][0]][f | (len[pos][0] == ssz)], dp[i][j][pos][f]);
					if (j > 0)
						add(dp[i + 1][j - 1][len[pos][1]][f | (len[pos][1] == ssz)], dp[i][j][pos][f]);
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= ssz; ++i)
		add(ans, dp[2 * n][0][i][1]);
		
	cout << ans << endl;
	
	return 0;
}
```
