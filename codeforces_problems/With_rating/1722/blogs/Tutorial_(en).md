# Tutorial_(en)

Thanks for participating!

[1722A - Spell Check](../problems/A._Spell_Check.md "Codeforces Round 817 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1722A - Spell Check](../problems/A._Spell_Check.md "Codeforces Round 817 (Div. 4)")

Check if the string has length 5 and if it has the characters T,i,m,u,r. The complexity is O(n). 

You can also sort the string, and check if it is Timur when sorted (which is Timru).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    string name = "Timur";
    sort(name.begin(), name.end());

    int n;
    cin >> n;
    forn(i, n) {
        int m;
        cin >> m;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << (s == name ? "YES" : "NO") << endl;
    }
}
```
[1722B - Colourblindness](../problems/B._Colourblindness.md "Codeforces Round 817 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1722B - Colourblindness](../problems/B._Colourblindness.md "Codeforces Round 817 (Div. 4)")

Here are two solutions.

Solution 1. Iterate through the string character by character. If si=R, then ti=R; otherwise, if si=G or B, then ti=G or B. If the statement is false for any i, the answer is NO. Otherwise it is YES.

Solution 2. Replace all B with G, since they are the same anyway. Then just check if the two strings are equal.

In either case the complexity is O(n) per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			if (t[i] != 'R') {cout << "NOn"; return;}
		}
		else {
			if (t[i] == 'R') {cout << "NOn"; return;}
		}
	}
	cout << "YESn";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1722C - Word Game](../problems/C._Word_Game.md "Codeforces Round 817 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1722C - Word Game](../problems/C._Word_Game.md "Codeforces Round 817 (Div. 4)")

You need to implement what is written in the statement. To quickly check if a word is written by another guy, you should store some map<string, int> or Python dictionary, and increment every time you see a new string in the input. Then, you should iterate through each guy, find the number of times their word appears, and update their score. 

The complexity is O(nlogn) per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	map<string, int> mp;
	string a[3][n];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			mp[a[i][j]]++;
		}
	}
	for (int i = 0; i < 3; i++) {
		int tot = 0;
		for (int j = 0; j < n; j++) {
			if (mp[a[i][j]] == 1) {tot += 3;}
			else if (mp[a[i][j]] == 2) {tot++;}
		}
		cout << tot << ' ';
	}
	cout << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1722D - Line](../problems/D._Line.md "Codeforces Round 817 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1722D - Line](../problems/D._Line.md "Codeforces Round 817 (Div. 4)")

For each person, let's calculate how much the value will change if they turn around. For example, in the line LRRLL, if the $i$-th person turns around, then the value of the line will change by $+4$, $-2$, $0$, $-2$, $-4$, respectively. (For instance, if the second person turns around, they see $3$ people before and $1$ person after, so the value of the line changes by $-2$ if they turn around.)

Now note that if a person turns around, it doesn't affect anyone else's value. So the solution is a greedy one: let's sort the array of values in increasing order. Afterwards, we should go from the left to the right, and see if the value will increase if this person turns around; if it does, we should add it to the current total and continue.

The time complexity of this solution is $\mathcal{O}(n \log n)$ per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long tot = 0;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			v.push_back((n - 1 - i) - i);
			tot += i;
		}
		else {
			v.push_back(i - (n - 1 - i));
			tot += n - 1 - i;
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {tot += v[i];}
		cout << tot << ' ';
	}
	cout << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1722E - Counting Rectangles](../problems/E._Counting_Rectangles.md "Codeforces Round 817 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1722E - Counting Rectangles](../problems/E._Counting_Rectangles.md "Codeforces Round 817 (Div. 4)")

Consider the 2D array with $a[x][y]=0$ for all $x,y$. Increase $a[h][w]$ by $h \times w$ if there is an $h \times w$ rectangle in the input.

Now for each query, we need to find the sum of all $a[x][y]$ in a rectangle with lower-left corner at $a[h_s+1][w_s+1]$ and upper-right corner at $a[h_b-1][w_b-1]$. This is the standard problem that can be solved with 2D prefix sums.

The time complexity is $\mathcal{O}(n+q+\max(h_b)\max(w_b))$ per testcase.

You can read about [2D prefix sums](https://codeforces.com/https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums) if you haven't heard of them before.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

long long a[1005][1005];
long long pref[1005][1005];

void solve()
{
    long long n, q;
    cin >> n >> q;
    for(int i = 0; i <= 1001; i++)
    {
        for(int j = 0; j <= 1001; j++)
        {
            a[i][j] = pref[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        long long h, w;
        cin >> h >> w;
        a[h][w]+=h*w;
    }
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 1; j <= 1000; j++)
        {
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
        }
    }
    for(int i = 0; i < q; i++)
    {
        long long hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << pref[hb-1][wb-1]-pref[hb-1][ws]-pref[hs][wb-1]+pref[hs][ws] << endl;
    }
}
 
int main() {
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
```
[1722F - L-shapes](../problems/F._L-shapes.md "Codeforces Round 817 (Div. 4)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1722F - L-shapes](../problems/F._L-shapes.md "Codeforces Round 817 (Div. 4)")

The problem is mainly a tricky implementation problem. Let's denote the elbow of an L-shape as the square in the middle (the one that is side-adjacent to two other squares). Every elbow is part of exactly one L-shape, and every L-shape has exactly one elbow.

Iterate through the grid and count the number of side-adjacent neighbors they have. If there is a cell with more than 2, or if there is a cell with exactly two neighbors on opposite sides, then the answer is NO. Otherwise, if there are exactly 2 neighbors, this cell is an elbow. Mark all three cells of this L-shape with a unique number (say, mark the first one you find with $1$, the second with $2$, and so on.) If you ever remark a cell that already has a number, then two elbows are adjacent, and you can output NO.

After all elbows are marked, check if all shaded cells have a number. If some don't, then they are not part of an L-shape, so you can output NO.

Finally, we should check that L-shapes don't share edge or corner. Just check, for each number, if it is only diagonally adjacent to other numbers equal to it or unshaded cells. If it is diagonally adjacent to other unequal numbers, then the answer is NO, because two L-shapes share an edge or corner then.

Otherwise the answer is YES.

There are many other solutions, all of which are various ways to check the conditions. The complexity is $\mathcal{O}(mn)$ per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

const int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};

void solve() {
	int n, m;
	cin >> n >> m;
	char g[n][m];
	int id[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			id[i][j] = 0;
		}
	}
	int curr = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '*') {
				vector<pair<int, int>> adjh, adjv;
				if (i > 0 && g[i - 1][j] == '*') {
					adjh.emplace_back(i - 1, j);
				}
				if (i < n - 1 && g[i + 1][j] == '*') {
					adjh.emplace_back(i + 1, j);
				}
				if (j > 0 && g[i][j - 1] == '*') {
					adjv.emplace_back(i, j - 1);
				}
				if (j < m - 1 && g[i][j + 1] == '*') {
					adjv.emplace_back(i, j + 1);
				}
				if (adjh.size() == 1 && adjv.size() == 1) {
					if (id[i][j] == 0) {id[i][j] = curr;}
					else {cout << "NOn"; return;}
					if (id[adjh[0].first][adjh[0].second] == 0) {id[adjh[0].first][adjh[0].second] = curr;}
					else {cout << "NOn"; return;}
					if (id[adjv[0].first][adjv[0].second] == 0) {id[adjv[0].first][adjv[0].second] = curr;}
					else {cout << "NOn"; return;}
					curr++;
				}
				else if (adjh.size() > 1 || adjv.size() > 1) {
					cout << "NOn"; return;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '*') {
				if (id[i][j] == 0) {cout << "NOn"; return;}
				else {
					for (int x = 0; x < 3; x++) {
						for (int y = 0; y < 3; y++) {
							if (0 <= i + dx[x] && i + dx[x] < n) {
								if (0 <= j + dy[y] && j + dy[y] < m) {
									if (id[i + dx[x]][j + dy[y]] != id[i][j] && id[i + dx[x]][j + dy[y]] != 0) {
										cout << "NOn"; return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "YESn";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1722G - Even-Odd XOR](../problems/G._Even-Odd_XOR.md "Codeforces Round 817 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1722G - Even-Odd XOR](../problems/G._Even-Odd_XOR.md "Codeforces Round 817 (Div. 4)")

There are a lot of solutions to this problem. Here I will describe one of them.

First, we observe that having the XOR of even indexed numbers and odd indexed numbers equal is equivalent to having the XOR of all the elements equal to 0. Let's note with $a$ the XOR of all odd indexed numbers and $b$ the xor of all even indexed numbers. Notice that the XOR of all the array equals $0$ if and only if a = b.

So how do we generate such an array with XOR of all elements $0$? Our first instinct might be to arbitrarily generate the first $n-1$ numbers, then set the last element as the XOR of the first $n-1$, ensuring that the total XOR is $0$. However, we might have problems with the condition that all elements must be distinct. Let's arbitrarily set the first $n-2$ so that they don't have the highest bit($2^30$) set, and then the $n-1$-th number can be just $2^30$. The last number can be the XOR of the first $n-2$ XOR the $n-1$-th number; you will be sure that the last number has not occurred in the first $n-2$ elements because they don't have the highest bit set while the last number must have the highest bit set. But how do we know that the $n-1$-th number and the $n$-th number will not be equal? This occurs only if the total XOR of the first $n-2$ numbers equals $0$. To fix this, we can just choose a different arbitrary number in one of the $n-2$ spots.

For example, my solution checks if the XOR of the numbers $0, 1, 2 ..., n-4, n-3$ is $0$. If it is not $0$, great! We can use the simple solution without any changes. However, if the XOR is $0$ I use the numbers $1, 2, 3, ...., n-3, n-2$ in their place. These two sequences have different XORs, so it ensures that one of them always works.

 **Alternate Tutorial Sketch**Output the integers from 1 to n−3, then 229, 230, and the XOR of those n−1 numbers. Why does it work?

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int case1 = 0;
    int case2 = 0;
    for(int i = 0; i < n-2; i++)
    {
        case1^=i;
        case2^=(i+1);
    }
    long long addLast = ((long long)1<<31)-1;
    if(case1 != 0)
    {
        for(int i = 0; i < n-2; i++)
        {
            cout << i << " ";
        }
        case1^=addLast;
        cout << addLast << " " << case1 << endl;
    }
    else
    {
        for(int i = 1; i <= n-2; i++)
        {
            cout << i << " ";
        }
        case2^=addLast;
        cout << addLast << " " << case2 << endl;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
```
