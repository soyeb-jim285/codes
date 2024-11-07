# Tutorial

[1941A - Rudolf and the Ticket](../problems/A._Rudolf_and_the_Ticket.md "Codeforces Round 933 (Div. 3)")

Author: [daha.002](https://codeforces.com/profile/daha.002 "Newbie daha.002")

 **Tutorial**
### [1941A - Rudolf and the Ticket](../problems/A._Rudolf_and_the_Ticket.md "Codeforces Round 933 (Div. 3)")

For each test case, we calculate all elements bi from the first array. Then we iterate through the elements cj in the second array and in a loop, we calculate each sum bi+cj. If this sum is less than or equal to k, we add 1 to the answer.

 **Solution**
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int ans = 0;
		vector<int> v1(n);
		for (int i = 0; i < n; i++) {
			cin >> v1[i];
		}
		int o;
		for (int j = 0; j < m; j++) {
			cin >> o;
			for (int i = 0; i < n; i++) {
				if ((o + v1[i]) <= k) ans++;
			}
		}
		cout << ans << "n";
	}
	return 0;
}
```
 **Rate the problem*** Didn't solve 


[*12*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*120*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*227*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")
[1941B - Rudolf and 121](../problems/B._Rudolf_and_121.md "Codeforces Round 933 (Div. 3)")

Author: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1941B - Rudolf and 121](../problems/B._Rudolf_and_121.md "Codeforces Round 933 (Div. 3)")

Let's consider the minimum i such that ai>0. Making this element zero is only possible by choosing the (i+1)-th element for the operation (applying the operation to a more leftward element is either impossible or will make some elements less than zero). We will apply operations in this way until we reach the end of the array. If there are non-zero elements left after applying the operations, the answer is "NO".

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    for i in range(n - 2):
        if a[i] < 0:
            print('NO')
            return
        op = a[i]
        a[i] -= op
        a[i + 1] -= 2 * op
        a[i + 2] -= op
    if a[-1] != 0 or a[-2] != 0:
        print('NO')
    else:
        print('YES')
    

for _ in range(int(input())):
    solve()
```
 **Rate the problem*** Didn't solve 

 
[*122*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*326*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*49*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*138*](https://codeforces.com/data/like?action=like "I like this")
[1941C - Rudolf and the Ugly String](../problems/C._Rudolf_and_the_Ugly_String.md "Codeforces Round 933 (Div. 3)")

Author: [Mordvin13](https://codeforces.com/profile/Mordvin13 "Newbie Mordvin13")

 **Tutorial**
### [1941C - Rudolf and the Ugly String](../problems/C._Rudolf_and_the_Ugly_String.md "Codeforces Round 933 (Div. 3)")

To solve this problem, you need to find all occurrences of the substrings "pie", "map", "mapie" in the string s and remove the middle character in each of them. This way, you will remove the minimum number of characters to ensure that the string does not contain the substrings "pie" and "map".

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long t;
    cin>>t;
    for(long long c=0;c<t;c++){
	long long n;
	cin >> n;
	string s;
	cin >> s;
	vector<long long> va;                 
	for (string sul : {"mapie", "pie", "map"}) {
		for (size_t pos = 0; (pos = s.find(sul, pos)) != string::npos;) {
			s[pos + sul.length() / 2] = '?';
			va.push_back(pos + sul.length() / 2);
		}
	}
	cout << va.size() << endl;
    }
	return 0;
}

```
 **Rate the problem*** Didn't solve 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*285*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*90*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*61*](https://codeforces.com/data/like?action=like "I like this")
[1941D - Rudolf and the Ball Game](../problems/D._Rudolf_and_the_Ball_Game.md "Codeforces Round 933 (Div. 3)")

Author: [Alexey_Parsh](https://codeforces.com/profile/Alexey_Parsh "Expert Alexey_Parsh")

 **Tutorial**
### [1941D - Rudolf and the Ball Game](../problems/D._Rudolf_and_the_Ball_Game.md "Codeforces Round 933 (Div. 3)")

Let's introduce a set of unique elements q, initially containing a single element x — the index of the first player who started the game. For each i from 1 to m, we will update q in such a way as to maintain the set of players who could have the ball after the i-th throw. For each element qj of the set q, we will remove qj from q, and also: 

* if ci="0" or ci="?", add to q the element ((qj+ri−1) mod n+1) — the index of the player who will receive the ball in case of a clockwise throw;
* if ci="1" or ci="?", add to q the element ((qj−ri−1+n) mod n+1) — the index of the player who will receive the ball in case of a counterclockwise throw. The term n before the mod operation is necessary to obtain a positive argument of this operation. Otherwise, in some programming languages, the mod function will return a negative result, which does not correspond to the semantics of the problem.

 The operation u mod v denotes the remainder of the division of u by v. It should be noted that it is not needed to store duplicates in q — one index of the thrower is sufficient for the correct calculation of the players who could have received their throw.After the m-th iteration of the described cyclic process, the set q will contain the desired indices of all players who could have the ball at the end of the game.

At each iteration of the loop, the power of q does not exceed n, and a total of exactly m iterations will be performed. Thus, the asymptotic complexity of the algorithm is of the order O(n∗m).

 **Solution**
```cpp
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, m, a; cin >> n >> m >> a;
        set <int> q[2];
        int ix = 0;
        q[ix].insert(a);
        while (m--) {
            int x; char ch; cin >> x >> ch;
            while (!q[ix].empty()) {
                int u = *(q[ix].begin());
                q[ix].erase(u);
                if (ch == '?' || ch == '0') {
                    q[ix ^ 1].insert((u + x - 1) % n + 1);
                }
                if (ch == '?' || ch == '1') {
                    q[ix ^ 1].insert((u - x - 1 + n) % n + 1);
                }
            }
            ix ^= 1;
        }
        cout << q[ix].size() << 'n';
        for (auto& x : q[ix]) {
            cout << x << ' ';
        }
        cout << 'n';
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*61*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*363*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*34*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*34*](https://codeforces.com/data/like?action=like "I like this")
[1941E - Rudolf and k Bridges](../problems/E._Rudolf_and_k_Bridges.md "Codeforces Round 933 (Div. 3)")

Author: [t0rtik](https://codeforces.com/profile/t0rtik "Expert t0rtik")

 **Tutorial**
### [1941E - Rudolf and k Bridges](../problems/E._Rudolf_and_k_Bridges.md "Codeforces Round 933 (Div. 3)")

First, for each string separately, we will calculate the minimum total cost of supports and write it to an array. This can be done, for example, using dynamic programming as follows. We will go through the string and maintain the last d+1 minimum total costs in a multiset. Then the answer for the current position will be the sum of the cost of the support at this position and the minimum element from the multiset. When moving to the next element of the string, it is important to remember to update the multiset.

After that, from the array of minimum total costs, we choose a segment of length k with the minimum sum, which will be the answer.

The algorithm's asymptotic complexity is of the order O(n⋅m⋅logd).

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int t = 1;
    cin >> t;
    while (t--) {
        int N, M, K, D;
        cin >> N >> M >> K >> D;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) {
            vector<long long> dp(M, 1e9);
            vector<int> v(M);
            multiset<long long> mst = {1};
            dp[0] = 1;
            cin >> v[0];
            for (int j = 1; j < M - 1; j++) {
                cin >> v[j];
                dp[j] = *mst.begin() + v[j] + 1;
                if (j - D - 1 >= 0)
                    mst.erase(mst.find((dp[j - D - 1])));
                mst.insert(dp[j]);
            }
            cin >> v.back();
            dp.back() = 1 + *mst.begin();
            a[i] = dp.back();
        }

        long long cur = 0;
        for (int i = 0; i < K; i++)
            cur += a[i];

        long long mn = cur;

        for (int i = K; i < N; i++) {
            cur += a[i] - a[i - K];
            mn = min(cur, mn);
        }
        cout << mn << endl;
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*97*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*331*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*76*](https://codeforces.com/data/like?action=like "I like this")
[1941F - Rudolf and Imbalance](../problems/F._Rudolf_and_Imbalance.md "Codeforces Round 933 (Div. 3)")

Author: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1941F - Rudolf and Imbalance](../problems/F._Rudolf_and_Imbalance.md "Codeforces Round 933 (Div. 3)")

Let's consider the differences ai−ai−1. Since we can only insert one problem, we can reduce the difference in difficulty in only one place. If we insert a problem not between the tasks whose difference in difficulty is maximum (denote them as ap and ap+1), then the imbalance will not change. The best way to insert a problem in this way is to choose the middle between these tasks, so the larger of the differences di+fj−ap and ap+1−di−fj will be minimal.

We also cannot forget about the other tasks. Let's find the second maximum among the values ai−ai−1. Since we insert a problem in another place, this difference will not decrease, and therefore the answer cannot be less than it.

To understand what answer we can achieve, let's sort the functions and iterate through all the models. For the model di, using binary search, we will find the maximum index l such that di+fl≤⌊ap+ap+12⌋. For inserting with the selected model, the best fit will be either a problem of difficulty di+fl or a problem of difficulty di+fl+1 (if l<k) since it is the closest problems to the middle. We will check both options and update the answer.

 **Solution**
```cpp
def solve():
    n, m, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    d = [int(x) for x in input().split()]
    f = [int(x) for x in input().split()]
    d.sort()
    f.sort()

    m1, m2 = 0, 0
    ind = -1
    for i in range(1, n):
        e = a[i] - a[i - 1]
        m2 = max(m2, e)
        if m2 > m1:
            m1, m2 = m2, m1
            ind = i - 1

    ans = m1

    target = (a[ind] + a[ind + 1]) // 2
    for model in d:
        l, r = 0, k - 1
        while r - l > 1:
            mid = (r + l) // 2
            if model + f[mid] <= target:
                l = mid
            else:
                r = mid
        ans = min(ans, max(m2, abs(model + f[l] - a[ind]), abs(model + f[l] - a[ind + 1])))
        ans = min(ans, max(m2, abs(model + f[r] - a[ind]), abs(model + f[r] - a[ind + 1])))
    print(ans)


for _ in range(int(input())):
    solve()

```
 **Rate the problem*** Didn't solve 

 
[*50*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*185*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*37*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")
[1941G - Rudolf and Subway](../problems/G._Rudolf_and_Subway.md "Codeforces Round 933 (Div. 3)")

Author: [natalina](https://codeforces.com/profile/natalina "Expert natalina")

 **Tutorial**
### [1941G - Rudolf and Subway](../problems/G._Rudolf_and_Subway.md "Codeforces Round 933 (Div. 3)")

Let's construct a bipartite graph, where one part is the vertices of the original graph, i.e., subway stations, and the other part is the subway lines. We add an edge between a station vertex and a line vertex if in the original subway graph, the station is incident to an edge of the corresponding subway line. In the new graph, we find the shortest path between the vertices corresponding to the departure and destination stations (for example, using breadth-first search). The answer to the problem will be the shortest path, divided in half.

 **Solution**
```cpp
#include<bits/stdc++.h>

using LL = long long;
using ld = long double;

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);


    int _ = 0, __ = 1;
    cin >> __;

    for (int _ = 0; _ < __; ++_) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n + 1);
        map<int, int> clrs;
        int idx = n + 1;
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({v, c});
            g[v].push_back({u, c});
            if (!clrs.count(c)) {
                clrs[c] = idx;
                idx++;
            }
        }
        int s, t;
        cin >> s >> t;
        
        if (s == t) 
        {
            cout << 0 << endl;
            continue;
        }

        vector<set<int>> bg(n + clrs.size() + 3);

        for (int i = 1; i <= n; ++i) {
            for(auto &[to, c] : g[i])
            {
                int clr_v = clrs[c];
                bg[i].insert(clr_v);
                bg[clr_v].insert(i);

                bg[to].insert(clr_v);
                bg[clr_v].insert(to);
            }
        }

        vector<int> used(bg.size());
        vector<int> d(bg.size(), -1);
        auto bfs = [&](int v)
        {
            queue<int> q;
            q.push(v);
            used[v] = 1;
            d[v] = 0;
            while (!q.empty())
            {
                auto from = q.front();
                q.pop();
                for (auto& to : bg[from])
                {
                    if (!used[to])
                    {
                        q.push(to);
                        used[to] = 1;
                        d[to] = d[from] + 1;
                    }
                }
            }
        };
        bfs(s);
        if (d[t] > 0) cout << d[t] / 2 << endl;
        else cout << -1 << endl;


    }

    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*86*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*183*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
