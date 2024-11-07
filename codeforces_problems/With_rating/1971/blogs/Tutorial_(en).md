# Tutorial_(en)

Thank you for participating!

[1971A - My First Sorting Problem](../problems/A._My_First_Sorting_Problem.md "Codeforces Round 944 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1971A - My First Sorting Problem](../problems/A._My_First_Sorting_Problem.md "Codeforces Round 944 (Div. 4)")

You can use, for example, an if-statement or some inbuilt min and max function available in most languages (like Python or C++).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int x, y;
	cin >> x >> y;
	cout << min(x, y) << ' ' << max(x, y) << 'n';	
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}

```
[1971B - Different String](../problems/B._Different_String.md "Codeforces Round 944 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1971B - Different String](../problems/B._Different_String.md "Codeforces Round 944 (Div. 4)")

Since the string is length at most 10, we can try all swaps of two characters of the string. This is O(|s|2) per test case, which is fast enough. If none of them create a different string, then all characters in the original string are the same, so the answer is NO.

Bonus: Actually, it's enough to try all swaps with the first character, solving the problem in O(|s|). Why?

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 1; i < (int)(s.length()); i++) {
		if (s[i] != s[0]) {swap(s[i], s[0]); ok = true; break;}
	}	
	if (!ok) {
		cout << "NOn"; return;
	}
	cout << "YESn";
	cout << s << 'n';
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}

```
[1971C - Clock and Strings](../problems/C._Clock_and_Strings.md "Codeforces Round 944 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1971C - Clock and Strings](../problems/C._Clock_and_Strings.md "Codeforces Round 944 (Div. 4)")

There are many ways to implement the solution, but many involve a lot of casework. Below is the shortest solution we know of.

Walk around the clock in the order 1, 2, …, 12. If we pass by two red strings or two blue strings in a row, the strings don't intersect; otherwise, they do.

This is because if we don't have two red or blue in a row, then the red and blue strings alternate, so there must be an intersection.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	for (int i = 1; i <= 12; i++) {
		if (i == a || i == b) {s += "a";}
		if (i == c || i == d) {s += "b";}
	}
	cout << (s == "abab" || s == "baba" ? "YESn" : "NOn");
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}

```
[1971D - Binary Cut](../problems/D._Binary_Cut.md "Codeforces Round 944 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1971D - Binary Cut](../problems/D._Binary_Cut.md "Codeforces Round 944 (Div. 4)")

First, note that it's always optimal to divide the string into "blocks" of equal values; there is no use having two strings 111|11 when we can just have 11111 and use fewer pieces.

Now note that to sort the string, we need all blocks of 0 to come before all blocks of 1. The only way that two blocks can join is if we have a block of 0s before a block of 1s, and we can have at most one such block. That is, all strings look like: (blocks of 0s)0...1⏟≤1joined block of 0s and 1s(blocks of 1s)

So the answer is the number of blocks, but we should subtract 1 if a substring 01 exists (because then we can make the center block above). The time complexity is O(|s|).

For example, for the string 111000110, we can use three pieces: 111|00011|0→0|00011|111.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	string s;
	cin >> s;
	int res = 1;
	bool ex = false;
	for (int i = 0; i + 1 < (int)(s.size()); i++) {
		res += (s[i] != s[i + 1]);
		ex |= (s[i] == '0' && s[i + 1] == '1');
	}
	cout << res - ex << 'n';
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}

```
[1971E - Find the Car](../problems/E._Find_the_Car.md "Codeforces Round 944 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1971E - Find the Car](../problems/E._Find_the_Car.md "Codeforces Round 944 (Div. 4)")

For each query, we binary search to find the last sign we passed (since the array a is sorted). Say it is ar. Then, br minutes have passed. 

To find out how much time has passed since we left that sign, we know that the speed between sign r and r+1 is ar+1−arbr+1−brdistanceminute (by the usual formula for speed).

We have passed a distance c−ar since the last sign, so the total number of minutes since the last sign is br+1−brar+1−arminutedistance×c−ardistance=(c−ar)×br+1−brar+1−arminutes. Adding this to our br from before, we get the answer.

Be careful about using floating-point numbers, as they can behave strangely. Our solution below doesn't use them at all.

 **Solution**
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <cassert>
typedef long long  ll;
using namespace std;
 
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(k+1), b(k+1);
    a[0] = 0;
    b[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < q; i++)
    {
        long long c;
        cin >> c;
        int l = 0, r = k;
        while(l <= r)
        {
            int mid = l+r>>1;
            if(a[mid] > c)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        if(a[r] == c)
        {
            cout << b[r] << " ";
            continue;
        }
        long long ans = b[r] + (c-a[r])*(b[r+1]-b[r])/(a[r+1]-a[r]);
        cout << ans << " ";
    }
    cout << endl;
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
 
 
 

```
[1971F - Circle Perimeter](../problems/F._Circle_Perimeter.md "Codeforces Round 944 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1971F - Circle Perimeter](../problems/F._Circle_Perimeter.md "Codeforces Round 944 (Div. 4)")

There are many solutions to this problem, some of which involve binary search, but we will present a solution that doesn't use it. In fact, our solution is basically just brute force, but with some small observations that make it pass. See the implementation for more detail.

First, we can only count points (x,y) such that x≥0 and y>0; we can multiply by 4 at the end to get points in all four quadrants, by symmetry.

Let's store a variable height initially equal to r. It will tell us the maximum y-value to look at.

Iterate through all values of x from 0 to r. For each x, decrease height until the distance of (x,height) to the origin is <r+1. Then, brute force all values of y from height downwards until we hit a point whose distance to the origin is <r; at this point, we break and add the number of valid points to our total. 

Note that we essentially only look at points whose distance to the origin is between r and r+1; that is, we brute force over all valid points.

How many valid points are there? Well, we can roughly estimate the number of points as the area of the region, which is π(r2−(r−1)2)=2πr−π. This means we only visit O(r) points per test case, which is fast enough.

 **Solution**
```cpp
#include <iostream>
using namespace std;
 
void solve()
{
    long long r;
    cin >> r;
    long long height = r;
    long long ans = 0;
    for(long long i = 0; i <= r; i++)
    {
        while(i*i+height*height >= (r+1)*(r+1))
        {
            height--;
        }
        long long cop = height;
        while(i*i+cop*cop >= r*r && cop > 0)
        {
            cop--;
            ans++;
        }
    }
    cout << ans*4 << endl;
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
 
 
 

```
[1971G - XOUR](../problems/G._XOUR.md "Codeforces Round 944 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1971G - XOUR](../problems/G._XOUR.md "Codeforces Round 944 (Div. 4)")

Note that if ai XOR aj<4, then ai and aj must share all bits in their binary representation, except for the last 2 bits. This is because if they have a mismatch in any greater bit, their XOR will include this bit, making its value ≥22=4.

This means that we can group the numbers by removing the last two bits and putting equal numbers into the same group. In each group, we can order the numbers freely (since we can swap any two of them), so it's optimal to sort the numbers in each group. 

Thus we can just divide the numbers into groups and sort each, solving the problem in O(nlogn). There are several ways to implement this: for instead, you can use a map storing all the groups, and then sort the values in each group. The implementation we used maps each integer to a priority queue, which automatically will sort the numbers in each group.

 **Solution**
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
 
using namespace std;
 
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, priority_queue<int>> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]>>2].push(-a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cout << -mp[a[i]>>2].top() << " ";
        mp[a[i]>>2].pop();
    }
    cout << endl;
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1971H - ±1](../problems/H._±1.md "Codeforces Round 944 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1971H - ±1](../problems/H._±1.md "Codeforces Round 944 (Div. 4)")

The problem statement is somewhat reminiscent of [SAT](https://codeforces.com/https://en.wikipedia.org/wiki/Boolean_satisfiability_problem). Indeed, treating +1 as true and −1 as false, we have clauses of length 3, and we need at least 2 of the variables to be true.

We can reduce this to [2-SAT](https://codeforces.com/https://en.wikipedia.org/wiki/2-satisfiability) with the following observation: at least 2 of (x,y,z) are true ⟺ at least one of (x,y) is true, at least one of (y,z) is true, and at least one of (z,x) is true. That is, for each column of the grid, we make three 2-SAT clauses. Then we just run 2-SAT on these clauses, and output if there is a solution. The time complexity is O(n) per test case.

It might be time-consuming to code 2-SAT during the contest, so we recommend using some standard library (for example, our solution uses [AtCoder library](https://codeforces.com/https://github.com/atcoder/ac-library/blob/master/atcoder/twosat.hpp)).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
 
#include <algorithm>
#include <utility>
#include <vector>
 
namespace atcoder {
namespace internal {
 
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
 
// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}
 
    int num_vertices() { return _n; }
 
    void add_edge(int from, int to) { edges.push_back({from, {to}}); }
 
    // @return pair of (
# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
 
    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }
 
  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
 
}  // namespace internal
 
}  // namespace atcoder
 
#include <cassert>
#include <vector>
 
namespace atcoder {
 
// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}
 
    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }
 
  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
};
 
}  // namespace atcoder
 
 
using namespace std;
using namespace atcoder;
 
void solve() {
	int n;
	cin >> n;
	int b[3][n];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	two_sat ts(n);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 3; i++) {
			int nxt = (i + 1) % 3;
			ts.add_clause(abs(b[i][j]) - 1, b[i][j] > 0, abs(b[nxt][j]) - 1, b[nxt][j] > 0);
		}
	}
	cout << (ts.satisfiable() ? "YESn" : "NOn");
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}

```
