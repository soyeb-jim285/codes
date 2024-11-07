# Tutorial_(en)

[A — Constructive Problems](../problems/A._Constructive_Problems.md)
==========================================================================

Author: [valeriu](https://codeforces.com/profile/valeriu "Grandmaster valeriu")

 **Solution**We can observe an invariant given by the problem is that every time we apply adjacent aid on any state of the matrix, the sets of rows that have at least one rebuilt city, respectively the sets of columns that appear that have at least one rebuilt city remain constant. Therefore, if we want to have a full matrix as consequence of applying adjacent aid multiple times, both of these sets must contain all rows/columns. As such, the answer is bounded by max(n,m).

We can tighten this bound by finding an example which always satisfies the statement. If we take, without loss of generality, n≤m, the following initial setting will satisfy the statement: (1,1),(2,2),(3,3),...,(n,n),(n,n+1),(n,n+2),..(n,m)

 **Author's Note**I have proposed this div2A at 3 contests and after 1 year of waiting I finally was able to propose it (mainly because theoretically, this was supposed to be my round :)). 

As the title suggests, this problem is inspired by one day trying to solve some constructive problem that required to draw some weird grid with some properties. And, as I was drawing multiple grids to try out multiple strategies, I was wondering how to draw these grids more optimally, as actually having to count for every matrix the height/width was pretty annoying, and I could just eyeball it by drawing it next to another drawn (but filled out) grid. As such, I needed an already drawn grid "below" the current one and another "to the left".

 **Code (valeriu)**
```cpp
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

using ll = long long;
using ld = long double;

//#define int ll
#define sz(x) ((int)(x).size())

using pii = pair<int,int>;
using tii = tuple<int,int,int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;
int n, k, m, q;
vector<int> g[nmax];
int v[nmax];

static void testcase() {
  cin >> n >> m;
  cout << max(n, m) << 'n';
  return;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}



/**
      Anul asta se da centroid.
-- Surse oficiale
*/
```
 **Rate Problem**Good problem 


[*326*](https://codeforces.com/data/like?action=like "I like this")





Ok problem 

 
[*101*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*81*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")



[B — Beginner's Zelda](../problems/B._Begginer's_Zelda.md)
=====================================================================

Author: [valeriu](https://codeforces.com/profile/valeriu "Grandmaster valeriu")

 **Solution**We can prove by induction that on any tree with K leaves, the answer is [K+12], where with [x] we denote the greatest integer smaller than x. This can be proven by induction, we will give an overview of what a proof would look like:

 * For two leaves, the answer is clearly 1.
* For three leaves, the answer is clearly 2.
* For more than four leaves, it is always the case that we can find two leaves for which the node that will be created as a result of applying an operation on these two will have degree greater than 1 (i.e. it will not be a leaf)

The third argument holds because in a tree with four leaves, we have either at least two nodes with degree at least 3 (and as such we can choose two leaves which contain these two nodes on their chain), or a node with degree at least 4. Furthermore, it reduces the number of leaves in the tree by 2.

 **Code (valeriu)**
```cpp
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cstring>
#include <numeric>
#define all(x) (x).begin(),(x).end()
using namespace std;

using ll = long long;
using ld = long double;

//#define int ll
#define sz(x) ((int)(x).size())

using pii = pair<int,int>;
using tii = tuple<int,int,int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;
int n, k, m, q;
int freq[nmax];

static void testcase() {
  cin >> n;
  for (int i = 1, a, b; i < n; i++) {
    cin >> a >> b;
    freq[a]++;
    freq[b]++;
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++)
    cnt += (freq[i] == 1),
    freq[i] = 0;
  cout << (cnt + 1) / 2 << 'n';
  return;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}



/**
      Anul asta se da centroid.
-- Surse oficiale
*/
```
 **Rate Problem**Good problem 

 
[*441*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*58*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*70*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*71*](https://codeforces.com/data/like?action=like "I like this")



[C — Largest Subsequence](../problems/C._Largest_Subsequence.md)
========================================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte")

 **Solution**We can notice that this operation will ultimately reverse the lexicographically largest subset of the initial string. 

Thus, we can easily check if the string is sortable, and for finding the number of operations we will subtract the length of the largest prefix of equal values of the subset from its length.

This solution works in O(n) time.

 **Code (tibinyte)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        string s;
        cin >> n >> s;
        s = '$' + s;
        vector<int> subset;
        for (int i = 1; i <= n; ++i)
        {
            while (!subset.empty() && s[subset.back()] < s[i])
            {
                subset.pop_back();
            }
            subset.push_back(i);
        }
        int ans = 0;
        int m = (int)subset.size() - 1;
        while (ans <= m && s[subset[ans]] == s[subset[0]])
        {
            ans++;
        }
        ans = m - ans + 1;

        for (int i = 0; i <= m; ++i)
        {
            if (i < m - i)
            {
                swap(s[subset[i]], s[subset[m - i]]);
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (s[i] < s[i - 1])
            {
                ans = -1;
                break;
            }
        }
        cout << ans << 'n';
    }
}
```
 **Rate Problem**Good problem 

 
[*492*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*68*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*104*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*77*](https://codeforces.com/data/like?action=like "I like this")



[D — Cyclic MEX](../problems/D._Cyclic_MEX.md)
===============================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte")

 **Solution**Let's analyze how the values of each prefix mex changes upon performing a cyclic shift to the left: 

 * The first prefix mex is popped.
* Each prefix mex with a value less than p1 doesn't change.
* Each prefix mex with a value greater than p1 becomes p1.
* n is appended to the back.

Let's keep our prefix mexes compressed ( meaning that we keep the value and its frequency instead of keeping multiple same values ). After that, we can simulate the above process naively with a deque, because the potential will decrease by the number of performed operations. 

This solution works in O(n) time.

 **Code (tibinyte)**
```cpp
#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		deque<pair<int, int>> dq;
		vector<int> f(n + 1);
		int mex = 0;
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			f[a[i]]++;
			while (f[mex])
			{
				mex++;
			}
			dq.push_back({mex, 1});
			sum += mex;
		}
		int ans = sum;
		for (int i = 1; i < n; ++i)
		{
			pair<int, int> me = {a[i], 0};
			sum -= dq.front().first;
			dq.front().second--;
			if (dq.front().second == 0)
			{
				dq.pop_front();
			}
			while (!dq.empty() && dq.back().first >= a[i])
			{
				sum -= dq.back().first * dq.back().second;
				me.second += dq.back().second;
				dq.pop_back();
			}
			dq.push_back(me);
			sum = sum + me.first * me.second;
			dq.push_back({n, 1});
			sum += n;
			ans = max(ans, sum);
		}
		cout << ans << 'n';
	}
}
```
 **Rate Problem**Good problem 

 
[*423*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*51*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*113*](https://codeforces.com/data/like?action=like "I like this")



[E — One-X](../problems/E._One-X.md)
===========================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte")

 **Solution**Let's try to solve a slightly easier problem first: changing the coefficient of the label to be the msb of the label.

We can note that at each depth, every label will have the same number of digits ( in base 2 ), thus the same msb. And we can notice that for each depth there are at most 2 different interval lengths. Combining the former with the latter, we can solve this case in O(log(N)) time complexity, since the maximum depth is bounded by log(N).

We can find an easy generalization to this: for the k-th most significant bit of each label to be 1, we have to go right from a node whose depth is k−1. Thus the above solution can be extended to find the contribution of the k-th most significant bit of each label.

Doing this for all bits gives us a time complexity of O(log2(N)) which is sufficient to pass the given constraints.

 **Code (tibinyte)**
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
struct Mint
{
    int val;
    Mint(long long x = 0)
    {
        val = x % mod;
    }
    Mint operator+(Mint oth)
    {
        return val + oth.val;
    }
    Mint operator-(Mint oth)
    {
        return val - oth.val + mod;
    }
    Mint operator*(Mint oth)
    {
        return val * oth.val;
    }
};
Mint powmod(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 1)
    {
        return powmod(a, b - 1) * a;
    }
    Mint P = powmod(a, b / 2);
    return P * P;
}
map<int, vector<vector<tuple<int, int, int>>>> memo;
vector<vector<tuple<int, int, int>>> find_ranges(int lg) // log^2
{
    if (memo.find(lg) != memo.end())
    {
        return memo[lg];
    }
    if (lg == 1)
    {
        return {{{1, 1, 1}}};
    }
    vector<vector<tuple<int, int, int>>> l = find_ranges((lg + 1) / 2);
    vector<vector<tuple<int, int, int>>> r = find_ranges(lg / 2);
    vector<vector<tuple<int, int, int>>> ans(max(l.size(), r.size()) + 1);
    Mint x = (powmod(2, (lg + 1) / 2) - 1) * (powmod(2, lg / 2) - 1);
    ans[0].push_back({lg, 1, x.val});
     for (int i = 0; i < (int)l.size(); ++i)
    {
        for (auto j : l[i])
        {
            ans[i + 1].push_back(j);
        }
    }
    for (int i = 0; i < (int)r.size(); ++i)
    {
        for (auto j : r[i])
        {
            bool ok = false;
            for (auto &[size, cnt, ways] : ans[i + 1])
            {
                if (size == get<0>(j))
                {
                    ok = true;
                    cnt += get<1>(j);
                }
            }
            if (!ok)
            {
                ans[i + 1].push_back(j);
            }
        }
    }
    return memo[lg] = ans;
}
Mint count(int lg, int coef)
{
    vector<vector<tuple<int, int, int>>> adam = find_ranges(lg);
    Mint ans = 0;
    Mint pow_2 = 1;
    for (int i = 0; i < (int)adam.size(); ++i)
    {
        for (auto [size, cnt, ways] : adam[i])
        {
            ans = ans + pow_2 * coef * cnt * ways;
        }
        pow_2 = pow_2 * 2;
    }
    return ans;
}
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<vector<tuple<int, int, int>>> adam = find_ranges(n);
        Mint ans = count(n, 1);
        for (int i = 1; i < (int)adam.size(); ++i)
        {
            for (auto [size, cnt, ways] : adam[i - 1])
            {
                int lsize = (size + 1) / 2;
                int rsize = size / 2;
                if (rsize)
                {
                    ans = ans + count(rsize, cnt);
                }
            }
        }
        cout << ans.val << 'n';
        memo.clear();
    }
}
```
 **Rate Problem**Good problem 

 
[*56*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*46*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")



[F — Field Should Not Be Empty](../problems/F._Field_Should_Not_Be_Empty.md)
==============================================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte")

 **Solution**The key observation to this problem is that most swaps are useless. In fact, we can find that only 2n swaps can increase our initial cost:

 * The first type of meaningful swaps is (i,pi)
* For each 1<i<n, consider k and l such that pk=max(p1,p2,...,pi−1) and pl=min(pi+1,pi+2,...,pn). The second type is (k,l).

The reason why this is true is because the first type of swap can create a new good index ( since every good index must be a fixed point ) and the second type of swap can fix an already good index. It's obvious that if a swap does neither of the above, it can't increase our current cost.

Calculating f(p) after each swap can be done with a segment tree. Consider adding one on the ranges (min(i,pi),max(i,pi)). Now an index is good if and only if its value is 1, which is also the minimum value an index can have. Thus our segment tree has to find the number of minimums while performing range additions which can be easily maintained by lazy propagation.

This solution works in O(nlog(n)) time complexity.

 **Code (tibinyte)**
```cpp
#include <bits/stdc++.h>
using namespace std;
struct aint
{
    vector<pair<int, int>> a;
    vector<int> lazy;
    void resize(int n)
    {
        a = vector<pair<int, int>>(4 * n);
        lazy = vector<int>(4 * n);
    }
    void init(int node, int left, int right)
    {
        a[node].second = (right - left + 1);
        if (left != right)
        {
            int mid = (left + right) / 2;
            init(2 * node, left, mid);
            init(2 * node + 1, mid + 1, right);
        }
    }
    void prop(int node, int left, int right)
    {
        a[node].first += lazy[node];
        if (left != right)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    pair<int, int> merge(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return pair<int, int>{a.first, a.second + b.second};
        }
        return min(a, b);
    }
    void update(int node, int left, int right, int st, int dr, int val)
    {
        prop(node, left, right);
        if (right < st || left > dr)
        {
            return;
        }
        if (st <= left && dr >= right)
        {
            lazy[node] += val;
            prop(node, left, right);
            return;
        }
        int mid = (left + right) / 2;
        update(2 * node, left, mid, st, dr, val);
        update(2 * node + 1, mid + 1, right, st, dr, val);
        a[node] = merge(a[2 * node], a[2 * node + 1]);
    }
};
struct bit
{
    vector<int> a;
    void resize(int n)
    {
        a = vector<int>(n + 1);
    }
    void update(int pos, int val)
    {
        int n = (int)a.size() - 1;
        for (int i = pos; i <= n; i += i & (-i))
        {
            a[i] += val;
        }
    }
    int query(int pos)
    {
        int ans = 0;
        for (int i = pos; i; i -= i & (-i))
        {
            ans += a[i];
        }
        return ans;
    }
    int query(int st, int dr)
    {
        return query(dr) - query(st - 1);
    }
};
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        bool sortat = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] != i)
            {
                sortat = false;
            }
        }
        if (sortat)
        {
            cout << n - 2 << 'n';
            continue;
        }
        vector<pair<int, int>> qui(n + 1);
        stack<int> s;
        bit tree;
        tree.resize(n);
        for (int i = 1; i <= n; ++i)
        {
            while (!s.empty() && a[s.top()] < a[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                qui[i].first = s.top();
            }
            if (tree.query(a[i], n) > 1)
            {
                qui[i].first = 0;
            }
            tree.update(a[i], 1);
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        tree.resize(n);
        for (int i = n; i >= 1; --i)
        {
            while (!s.empty() && a[s.top()] > a[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                qui[i].second = s.top();
            }
            if (tree.query(1, a[i]) > 1)
            {
                qui[i].second = 0;
            }
            tree.update(a[i], 1);
            s.push(i);
        }
        aint lesgo;
        lesgo.resize(n);
        lesgo.init(1, 1, n);
        function<void(int, int)> upd = [&](int ind, int sign)
        {
            lesgo.update(1, 1, n, min(ind, a[ind]), max(ind, a[ind]), sign);
        };
        function<int()> count = [&]()
        {
            if (lesgo.a[1].first == 1)
            {
                return lesgo.a[1].second;
            }
            return 0;
        };
        function<void(int, int)> mySwap = [&](int i, int j)
        {
            upd(i, -1);
            upd(j, -1);
            swap(a[i], a[j]);
            upd(i, 1);
            upd(j, 1);
        };
        for (int i = 1; i <= n; ++i)
        {
            upd(i, 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (qui[i].first && qui[i].second)
            {
                mySwap(qui[i].first, qui[i].second);
                ans = max(ans, count());
                mySwap(qui[i].first, qui[i].second);
            }
        }
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            pos[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            int qui1 = i;
            int qui2 = pos[i];
            mySwap(qui1, qui2);
            ans = max(ans, count());
            mySwap(qui1, qui2);
        }
        cout << ans << 'n';
    }
}
```
 **Rate Problem**Good problem 

 
[*41*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*63*](https://codeforces.com/data/like?action=like "I like this")



