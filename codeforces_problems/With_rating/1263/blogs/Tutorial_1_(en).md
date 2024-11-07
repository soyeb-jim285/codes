# Tutorial_1_(en)

[1263A - Sweet Problem](../problems/A._Sweet_Problem.md "Codeforces Round 603 (Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1263A - Sweet Problem](../problems/A._Sweet_Problem.md "Codeforces Round 603 (Div. 2)")

Sort the values of r, g, b such that r≥g≥b. Now consider two cases.

If r≥g+b, then Tanya can take g candies from piles r and g, and then — b candies from piles r and b. After that there may be a bunch of candies left in the pile r that Tanya won't be able to eat, so the answer is g+b.

Otherwise, we need to achieve the equality of the piles r, g, b. First, we make equal r and g by eating r−g from the piles r and b (this can always be done since r<g+b). Then we make equal the piles g, b by eating g−b from the piles r and g. After that, r=g=b, and we can get three different cases.

* r=g=b=0 — nothing needs to be done, Tanya has already eaten all the sweets;
* r=g=b=1 — you can take candy from any of two piles so in the end there will always be one candy left;
* r=g=b≥2 — we reduce all the piles by 2, taking, for example, a candy from piles r and g, g and b, r and b. With such actions, Tanya eventually reaches the two previous cases, since the sizes of the piles are reduced by 2.

Since with this strategy we always have 0 or 1 candy at the end, Tanya will be able to eat candies for ⌊r+g+b2⌋ days.

 **Solution (MikeMirzayanov)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {   
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] <= a[0] + a[1])
            cout << (a[0] + a[1] + a[2]) / 2 << endl;
        else
            cout << a[0] + a[1] << endl;
    }
}
```
[1263B - PIN Codes](../problems/B._PIN_Codes.md "Codeforces Round 603 (Div. 2)")

Idea: [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1263B - PIN Codes](../problems/B._PIN_Codes.md "Codeforces Round 603 (Div. 2)")

Group all the numbers into groups of equals PIN-Codes. Note that the size of each such group does not exceed 10. Therefore, in each PIN-Code we need to change no more than 1 digits. If the group consists of 1 element, then we do nothing, otherwise, we take all the PIN-codes except one from this group and change exactly one digit in them so that the new PIN-code becomes unique.

 **Solution (Stepavly)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<char> calced(n);
	vector<string> a(n);
	set<string> have;
	int res = 0;

	for (string &pin : a) {
		cin >> pin;
		have.insert(pin);
	}

	for (int i = 0; i < n; i++) {
		if (calced[i]) {
			continue;
		}

		vector<int> sameIds;

		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				sameIds.push_back(j);
				calced[j] = 1;
				res++;

				for (int k = 0; k < 4 && a[i] == a[j]; k++) {
					for (char c = '0'; c <= '9'; c++) {
						string t = a[j];
						t[k] = c;

						if (!have.count(t)) {
							have.insert(t);
							a[j] = t;
							break;
						}
					}
				}
			}
		}
	}

	cout << res << "n";

	for (string& s : a) {
		cout << s << "n";
	}
}

int main() {
	int test;
	cin >> test;

	while (test--) {
		solve();
	}
}
```
[1263C - Everyone is a Winner!](../problems/C._Everyone_is_a_Winner!.md "Codeforces Round 603 (Div. 2)")

Idea: [unreal.eugene](https://codeforces.com/profile/unreal.eugene "Candidate Master unreal.eugene")

 **Tutorial**
### [1263C - Everyone is a Winner!](../problems/C._Everyone_is_a_Winner!.md "Codeforces Round 603 (Div. 2)")

There are two approaches to solving this problem.

Mathematical Solution

Note that the answer will always contain the numbers 0≤x<⌊√n⌋. You can verify this by solving the equation ⌊nk⌋=x, equivalent to the inequality x≤nk<x+1, for integer values ​​of k. The solution to this double inequality is the interval k∈(nx+1;nx], whose length is nx2+x. For x<⌊√n⌋ nx2+x>1, and on an interval of length greater than 1 there is always a whole solution k=⌊nx⌋, so all integers 0≤x<⌊√n⌋ belong to the answer.

Note that we no longer need to iterate over the values ​​of k>⌊√n⌋, because these numbers always correspond to the values ​​0≤x<⌊√n⌋. Thus, it is possible, as in a naive solution, to iterate over all the values ​​of k upto ⌊√n⌋ and add x=⌊nk⌋ to the answer. It remains only to carefully handle the case k=⌊√n⌋.

Total complexity of the solution: O(√nlogn) or O(√n)

Algorithmic Solution

In the problem, it could be assumed that there are not so many numbers in the answer (after all, they still need to be printed, which takes the majority of the program execution time). Obviously, n always belongs to the answer. Note that as k increases, the value of x=⌊nk⌋ decreases. Thus, using a binary search, you can find the smallest value of k′ such that nk′<x. Value x′=nk′ will be the previous one for x in the answer.

Total complexity of the solution: O(√nlogn)

 **Solution (unreal.eugene)**
```cpp
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mkp make_pair
#define pb push_back
#define sqr(s) ((s) * (s))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

#ifdef EUGENE
	mt19937 rng(1337);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	int s = (int)sqrtl(n);
	for (int i = 0; i <= s; i++)
		ans.pb(i);
	for (int i = 1; i <= s; i++)
		ans.pb(n / i);
	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());
	cout << sz(ans) << endl;
	for (int &x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	#ifdef EUGENE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "r", stdout);
	#endif

	int t;
	cin >> t;
	while (t--)
		solve();
}
```
[1263D - Secret Passwords](../problems/D._Secret_Passwords.md "Codeforces Round 603 (Div. 2)")

Idea: [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1263D - Secret Passwords](../problems/D._Secret_Passwords.md "Codeforces Round 603 (Div. 2)")

This problem can be solved in many ways (DSU, bipartite graph, std::set and so on). A solution using a bipartite graph will be described here.

Consider a bipartite graph with 26 vertices corresponding to each letter of the Latin alphabet in the first set and n vertices corresponding to each password in the second set. Connect each password and the letters that are part of this password with an edge. From the definition of equivalence of passwords, it is easy to understand that the answer to the problem is the number of connected components in this bipartite graph.

Total complexity: O(n).

 **Solution (Stepavly)**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 100;

vector<int> g[N];
char used[N];

void addEdge(int v, int u) {
	g[v].push_back(u);
	g[u].push_back(v);
}

void dfs(int v) {
	used[v] = 1;

	for (int to : g[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (char c : s) {
			addEdge(i, n + c - 'a');
		}
	}

	int res = 0;

	for (int i = n; i < n + 26; i++) {
		if (!g[i].empty() && !used[i]) {
			dfs(i);
			res++;
		}
	}

	cout << res;

	return 0;
}
```
[1263E - Editor](../problems/E._Editor.md "Codeforces Round 603 (Div. 2)")

Idea: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Tutorial**
### [1263E - Editor](../problems/E._Editor.md "Codeforces Round 603 (Div. 2)")

To respond to requests, you need two stacks. The first stack will contain all the brackets at the positions left than the cursor position, and the second one all the remaining ones.

Also, for each closing bracket in the first stack, we will maintain the maximum depth of the correct bracket sequence (CBS) ending with this bracket. Similarly, in the second stack, we will maintain the maximum depth of CBS that starting in this bracket. Since the brackets are added to the stack at the end and one at a time, you can easily recalculate this value.

Even in the left stack, you need to maintain the number of opening brackets that do not have a pair of closing brackets, and in the right stack the number of closing brackets that do not have a pair of opening brackets.

If the previous two values are equal, then the current line is CBS. Otherwise, there is either one non-closed bracket or one bracket that does not have an opening one.

The answer to the problem, after each query, will be a maximum of three values - the maximum depth in the left stack, the maximum depth in the right stack and the number of non-closed brackets (the number of non-opened brackets in the right stack does not need to be taken into account, since if the line is CBS, then it is the number of open brackets in the left).

Total complexity is O(n).

 **Solution (Supermagzzz)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

struct MyStack {
    int cnt = 0;
    int allOpens = 0;
    stack<int> s;
    stack<int> minValue;
    stack<int> maxValue;

    void push(int x) {
        s.push(x);
        cnt += x;
        if (x == 1) {
            allOpens += 1;
        }
        minValue.push((minValue.size() ? min(minValue.top(), cnt) : cnt));
        maxValue.push((maxValue.size() ? max(maxValue.top(), cnt) : cnt));
    }

    void pop() {
        if (s.size() == 0) {
            return;
        }
        cnt -= s.top();
        if (s.top() == 1) {
            allOpens -= 1;
        }
        s.pop();
        minValue.pop();
        maxValue.pop();
    }

    int top() {
        return s.top();
    }

    bool isCorrect() {
        return (minValue.size() == 0 || minValue.top() >= 0);
    }

    int depth() {
        return (maxValue.size() ? maxValue.top() : 0);
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    MyStack left, right;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        right.push(0);
    }
    left.push(0);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (pos != 0) {
                pos--;
                right.push(-left.top());
                left.pop();
            }
        } else if (s[i] == 'R') {
            pos++;
            left.push(-right.top());
            right.pop();
        } else if (s[i] == '(') {
            left.pop();
            left.push(1);
        } else if (s[i] == ')') {
            left.pop();
            left.push(-1);
        } else {
            left.pop();
            left.push(0);
        }
        if (left.isCorrect() && right.isCorrect() && left.cnt == right.cnt) {
            cout << max({left.depth(), right.depth(), left.cnt}) << " ";
        } else {
            cout << "-1 ";
        }
    }
}           	
```
[1263F - Economic Difficulties](../problems/F._Economic_Difficulties.md "Codeforces Round 603 (Div. 2)")

Idea: [AdvancerMan](https://codeforces.com/profile/AdvancerMan "Candidate Master AdvancerMan")

 **Tutorial**
### [1263F - Economic Difficulties](../problems/F._Economic_Difficulties.md "Codeforces Round 603 (Div. 2)")

We assume that the leaves of the trees are numbered in the same way as the devices to which these leaves are connected.

Let's calculate costl,r (l≤r) for each tree (let's call them upperCostl,r and lowerCostl,r) — the maximum number of edges that can be removed so that on the segment [l,r] exists a path from each leaf to the root of the opposite tree. Let's calculate costl,r for some fixed l. Let's call 'bamboo' the connected set of ancestors of the node v such that each node has at most 1 child, and the node v itself is in this set. Obviously, costl,l is the maximum length of l's 'bamboo'.

Suppose we have already calculated costl,r−1. Let's calculate costl,r−1. Obviously, we can remove all edges counted in costl,r−1. We can also remove the resulting 'bamboo' of the leaf r (because we do not need to have paths from the leaves [l,r] to the root in the tree, for which we are calculating cost). Let's prove that we cannot remove more edges. For each tree exists a depth-first search from the node 1, that visits leaves in order of connection to devices, so for each node v the set of leaf indices in its subtree is a segment. If there is r in the segment for the node v, then the r-th leaf is in the subtree of the node v.

Let's have a look at the nodes whose subtree does not contain leaf r. If in their subtree there are nodes not from the segment [l,r], then we cannot remove edge to the parent of this node, because we don't want to lose the path to the root for the nodes out of the segment [l,r] (we are calculating the answer only for the segment [l,r]). So in the v's subtree leaves are only from the segment [l,r]. Leaves from the segment [l,r−1] were calculated in costl,r−1. Then the segment for the v's nodes is [i,r],l≤i. So we can remove the edge from each such node to its parent. And the set of these nodes is a 'bamboo' from the leaf r because we have already removed all 'bamboos' on [l,r−1] segment.

So to calculate costl,r it is enough to know costl,r−1 and the maximum length of r's 'bamboo'. This can be calculated in O(n(a+b)) time complexity.

Let's calculate dpi — the answer for the i-th prefix. Let's take a look at the answer: some suffix of leaves has a path to the root in only one tree, and the rest of prefix has a maximum answer (if not, then we take the maximum answer for the prefix, which will improve the answer). Then we get the formula dpi=max0≤j<i(dpj+max(upperCostj,i−1,lowerCostj,i−1)) (and dp0=0), which can be calculated in the O(n2) time complexity. Then the answer is dpn.

Challenge: Can you solve this problem with linear time complexity (for example, O(n+a+b))?

 **Solution (Rox)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

vector<vector<int>> precalc(int n, vector<int> p, vector<int> id) {
    vector<vector<int>> res(n, vector<int>(n));

    for (int l = 0; l < n; l++) {
        vector<int> deg(sz(p));
        for (int i = 1; i < sz(p); i++)
            deg[p[i]]++;

        int val = 0;
        for (int r = l; r < n; r++) {
            int v = id[r];
            while (v != 0 && deg[v] == 0) {
                deg[p[v]]--;
                v = p[v];
                val++;
            }
            res[l][r] = val;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> p(2);
    vector<vector<int>> id(2);
    for (int i = 0; i < 2; i++) {
        int vn;
        cin >> vn;
        p[i].resize(vn);
        for (int v = 1; v < vn; v++) {
            cin >> p[i][v];
            p[i][v]--;
        }
        id[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> id[i][j];
            id[i][j]--;
        }
    }

    vector<vector<vector<int>>> cost(2);
    for (int i = 0; i < 2; i++)
        cost[i] = precalc(n, p[i], id[i]);

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[j] = max(dp[j], dp[i] + max(
                cost[0][i][j - 1],
                cost[1][i][j - 1]
            ));
        }
    }

    cout << dp[n] << endl;
}
```
