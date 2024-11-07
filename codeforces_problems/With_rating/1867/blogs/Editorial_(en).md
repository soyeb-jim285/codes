# Editorial_(en)

Hello everyone! We're very sorry for the delay >_< 

We hope you enjoyed the tasks! Sorry for too tight limits in C so that Java solutions don't pass (actually one of our authors nickname used to be "java." :D), we'll hopefully do a better job next time! Feel free to leave your feedback in the comments.

[1867A — green_gold_dog, array and permutation](../problems/A._green_gold_dog,_array_and_permutation.md)

Author: [green_gold_dog](https://codeforces.com/profile/green_gold_dog "Grandmaster green_gold_dog")

 **Tutorial**Let's subtract n from the minimum number, subtract n−1 from the second minimum, n−2 from the third …, and subtract 1 from the maximum. Then the number of distinct elements will be n. Obviously, it is impossible to achieve a better result.

Let's prove that the number of distinct elements will be equal to n. Suppose ci=cj, then without loss of generality, let's say that bi>bj, then ai≤aj, which means ci=ai−bi < aj−bj=cj. Contradiction.

Time Complexity: O(nlogn) per test case.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		arr[i].first = x;
		arr[i].second = i;
	}
	vector<ll> ans(n);
	sort(arr.begin(), arr.end());
	reverse(arr.begin(),arr.end());
	for (ll i = 0; i < n; i++) {
		ans[arr[i].second] = i + 1;
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
```
[1867B — XOR Palindromes](../problems/B._XOR_Palindromes.md)

Author: [ace5](https://codeforces.com/profile/ace5 "International Master ace5")

 **Tutorial**Firstly, a string is a palindrome if and only if for any i (1≤i≤n) si=sn−i+1 (because when reversed, si becomes sn−i+1).

We can divide the characters into pairs, where each pair consists of si and sn−i+1. If si=sn−i+1, then we need to have li=ln−i+1 in order to obtain equal elements after XOR. Therefore, either li=ln−i+1=0 (with 0 ones) or li=ln−i+1=1 (with 2 ones). If si≠sn−i+1, then li≠ln−i+1 must hold (1 one in any case). Additionally, if n is odd, then ln/2+1 can be either 0 or 1 (with 0 or 1 ones).

We can iterate over the number of pairs where li=ln−i+1 will have two ones, as well as whether there will be a one in the center or not. This way, we can obtain all possible numbers of ones in l, i.e., all good i.

Time Complexity: O(n) per test case.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t(n+1,'0');
        int ans = 0;
        int max_1 = 0;
        int max_2 = 0;
        for(int i = 0;i <= n/2-1;++i)
        {
            if(s[i] == s[n-i-1])
                max_2++;
            else
                ans++;
        }
        if(n%2 == 1)
            max_1++;
        for(int j = 0;j <= max_2;++j)
        {
            for(int k = 0;k <= max_1;++k)
            {
                t[ans + j*2 + k] = '1';
            }
        }
        cout << t << "n";
    }
}
```
[1867C-Salyg1n and the MEX Game](../problems/C._Salyg1n_and_the_MEX_Game.md)

Author: [salyg1n](https://codeforces.com/profile/salyg1n "Master salyg1n")

 **Tutorial**The correct strategy for Alice is to add the number MEX(S) to the set S on the first move, and add the last removed number on the remaining moves.

Let m = MEX(S∪MEX(S)), at the start of the game. In other words, m is equal to the second MEX of the set S. m≥1.

Notice that after the first move, MEX(S)=m, and no matter what Bob removes, we will return that number to the set, so the result of the game will always be equal to m.

Let's prove that with Bob's optimal play, we cannot achieve a result greater than m.

Notice that the MEX of a set is the largest number k such that all numbers from 0 to k−1 inclusive are present in the set.

Let pi be the number of numbers from 0 to i−1 inclusive that appear in the set S. Then MEX(S) is equal to the maximum i such that pi=i.

If Bob removes the number y during his turn, he decreases all values pi where i>y by 1. So, if y=min(S), Bob decreases all non-zero values pi by 1.

Alice can increase some values pi by 1 during her turn. Therefore, after Alice's first move, MEX(S) will no longer increase if Bob keeps removing the minimum, because no non-zero values of pi will increase (Bob decreases them by 1, and Alice increases them by at most 1).

It is obvious that in order to maximize MEX(S) after the first move, Alice needs to add the number MEX(S) to the set S.

We have proven that R≤m and provided a strategy that achieves a result of m.

Time Complexity: O(n) per test case.

 **Solution**
```cpp
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int mex = -1;
	for (int i = 0; i < n; ++i) {
		if (i == 0 && s[i] != 0) {
			mex = 0;
			break;
		}
		if (i > 0 && s[i] != s[i - 1] + 1) {
			mex = s[i - 1] + 1;
			break;
		}
	}
	if (mex == -1)
		mex = s[n - 1] + 1;
	cout << mex << endl;
	int y;
	cin >> y;
	while (y != -1) {
		cout << y << endl;
		cin >> y;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
```
[1867D-Cyclic Operations](../problems/D._Cyclic_Operations.md)

Author: [ace5](https://codeforces.com/profile/ace5 "International Master ace5")

 **Tutorial**If k=1, then we can change bi to i, so the answer is YES only if bi=i, otherwise the answer is NO.

Otherwise, let's build an undirected graph with n vertices and edges (i,bi). Any component of this graph will look like a cycle (possibly of size 1) to each vertex of which a tree is attached (possibly empty).

 **Proof**Let's assume that there are x vertices in a component, then there are also x edges in it (since each vertex has exactly one outgoing edge). We can construct a depth-first search (DFS) tree for this component, which will have x−1 edges. Now, when we add the remaining edge (u,v), a cycle is formed in the component (formed by the edge (u,v) and the path between u and v in the DFS tree). Each vertex will have a tree attached to it, because before adding the edge, we had a tree.

Now it is claimed that if the cycle in each component has a size exactly k, then the answer is YES, otherwise NO.

 **Proof**Let's first consider the situation where the size of the cycle in some component is not k. Let the cycle contain vertices v1,v2,⋯,vx in that order. Now let's look at the last operation in which one of the li was equal to some element from the cycle. If the size of the cycle is less than k, then in the last operation there will be at least one vertex not from the cycle, which means that at least one vertex from the cycle will be replaced by a number that is not the next vertex in the cycle, which is incorrect because each vertex from the cycle should be replaced by the next vertex after it. If the size of the cycle is greater than k, then we will have a vertex from the cycle that will be replaced by a vertex that is not the next vertex in the cycle (otherwise we would have used all the vertices of the cycle, and there are more than k of them). Therefore, in any case, there is no valid last operation with vertices from the cycle, so the answer is NO.

If the size of the cycle in a component is equal to k, then we can apply the following algorithm:

While there is at least one vertex v in the component that is a leaf, we will perform the operation with l=[v,bv,bbv,⋯] (all elements are distinct because we will enter the cycle and it has a size of k). After this operation, we will have av=bv, and we can remove vertex v (it had only 1 outgoing edge).

When only the cycle remains, we can apply the operation for the vertices in the cycle, preserving the order, and then for all vertices in the component, we will have av=bv. By doing this for all components, we will get a=b, which is what we wanted, so the answer is YES.

Time Complexity: O(n) per test case.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int b[n];
        int vis[n];
        for(int j = 0;j < n;++j)
        {
            cin >> b[j];
            vis[j] = 0;
        }
        if(k == 1)
        {
            int no = 0;
            for(int j = 0;j < n;++j)
            {
                if(b[j] != j+1)
                {
                    no = 1;
                }
            }
            cout << (no ? "NOn" : "YESn");
            continue;
        }
        int num[n];
        int no = 0;
        int tgr = 1;
        for(int j = 0;j < n;++j)
        {
            if(!vis[j])
            {
                int ind = j;
                int cnum = 0;
                while(!vis[ind])
                {
                    vis[ind] = tgr;
                    num[ind] = cnum++;
                    ind = b[ind]-1;
                }
                if(vis[ind] != tgr)
                {
                    tgr++;
                    continue;
                }
                if(cnum-num[ind] != k)
                {
                    no = 1;
                    break;
                }
                tgr++;
            }
        }
        cout << (no ? "NOn" : "YESn");
    }
}
```
[1867E1-Salyg1n and Array (simple version)](../problems/E1._Salyg1n_and_Array_(simple_version).md)

Author: [salyg1n](https://codeforces.com/profile/salyg1n "Master salyg1n")

 **Tutorial**Let's make queries to subarrays starting at positions 1, k+1, 2k+1, … m⋅k+1, as long as these queries are valid, meaning their right boundary does not exceed n. Let's save the XOR of all the answers to these queries. We will call these queries primary.

Now, we will shift the last subarray of the query one unit to the right and make a new query, as long as the right boundary does not exceed n. We will call these queries secondary. It is claimed that the XOR of the entire array will be equal to the XOR of all the queries. Let's prove this.

Let i be the position at which the first secondary query starts. Notice that after this query, the subarray [$i$; i+k−2] will turn into the subarray [i+1; i+k−1] and reverse. After the next query, the same thing will happen, the subarray will shift one unit to the right and reverse. Therefore, the prefixes of length k−1 of each secondary query will be the same, up to the reversal, which does not affect the XOR. Since the number of secondary queries is equal to nmodk, which is an even number, the XOR of these prefixes will not affect the XOR of all the secondary queries, which will therefore be equal to the XOR of the elements [$a_{i + k — 1}$; $a_n$], that is, all the elements that we did not consider in the primary queries.

The number of primary queries is equal to ⌊nk⌋≤k≤50, since n≤k2≤2500.

The number of secondary queries is equal to nmodk<k<=50, since k2≤2500.

The total number of queries does not exceed 100.

 **Solution**
```cpp
#include <iostream>

using namespace std;

int ask(int i) {
	cout << "? " << i << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int res = 0;
	int i;
	for (i = 1; i + k - 1 <= n; i += k)
	    res ^= ask(i);
	for (; i <= n; ++i)
	    res ^= ask(i - k + 1);
	cout << "! " << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
```
[1867E2-Salyg1n and Array (hard version)](../problems/E2._Salyg1n_and_Array_(hard_version).md)

Author: [salyg1n](https://codeforces.com/profile/salyg1n "Master salyg1n")

 **Tutorial**Let's make queries to subarrays starting at positions 1, k+1, 2k+1, … m⋅k+1, such that the size of the uncovered part is greater than 2⋅k and not greater than 3⋅k. In other words, 2⋅k<n−(m+1)⋅k≤3⋅k. Let's keep the XOR of all the answers to these queries. We will call these queries primary.

Let the size of the remaining (uncovered) part be x (2⋅k<x≤3⋅k). Let's learn how to solve the problem for an array of size x in three queries.

If x=3⋅k, simply make queries to positions 1, k+1, 2⋅k+1.

Otherwise, let y=x−k. Note that y is even, since x and k are even.

Make queries at positions 1, 1+y2, 1+y.

Note that after this query, the subarray [$1$; k−y2] will turn into the subarray [y/2+1; k] and reverse. After the next query, the same thing will happen, the subarray will shift one unit to the right and reverse. Therefore, the prefixes of length k−y2 for each query are the same, up to the reversal, which does not affect the XOR. Since the number of queries in the second group is 3, which is an odd number, the XOR of these prefixes will be taken into account exactly once in the XOR of all the queries, which will therefore be equal to the XOR of the elements.

The number of primary queries does not exceed ⌊nk⌋≤k≤50, since n≤k2≤2500.

The total number of queries does not exceed 53.

 **Solution**
```cpp
#include <iostream>

using namespace std;

int ask(int i) {
	cout << "? " << i << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int res = 0;
	int i;
	for (i = 1; n - i + 1 >= 2 * k; i += k)
		res ^= ask(i);
	if (n - i + 1 == k) {
		res ^= ask(i);
		cout << "! " << res << endl;
		return;
	}
	int y = (n - i + 1 - k) / 2;
	res ^= ask(i);
	res ^= ask(i + y);
	res ^= ask(i + 2 * y);
	cout << "! " << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
```
[1867F-Most Different Tree](../problems/F._Most_Different_Tree.md)

Author: [green_gold_dog](https://codeforces.com/profile/green_gold_dog "Grandmaster green_gold_dog")

 **Tutorial**Here we say that the answer for tree G′ is the number of subtrees in P(G′) that have an isomorphic subtree in P(G).

Let's find a tree T of minimum size that has no isomorphic tree in P(G). Let the size of tree T be x. Then take a chain of size n−x, and let the root of T be the kid of the last vertex on the chain. We say that this is the tree G′ we were looking for (with the root of G′ being the first vertex of the chain). The number of matching subtrees will be at most x−1, since all subtrees of the vertices on the chain and the subtree T itself will not have isomorphic trees in P(G), because T lies entirely in them, and T has no isomorphic tree in P(G). Therefore, the answer is not greater than n−(n−x)−1=x−1.

Let's prove why the answer cannot be less than x−1: suppose there exists a tree G∗ for which the answer is less than x−1. Let's find a subtree of minimum size whose size is at least x (it always exists, since we can take the entire tree for example). In this subtree, there are at least x−1 other subtrees, whose sizes are less than x (because in the previous step we chose a subtree of minimum size not less than x). And since all trees of size less than x have isomorphic trees in P(G) (by definition T is the tree of minimum size that has no isomorphic tree in P(G) and its size is x), the number of matching subtrees in tree G∗ is at least x−1, which is a contradiction.

Therefore in our case the answer is x−1.

Now let's solve the second part of the problem — finding T. To do this, let's first find all trees of size 1, then of size 2, then 3, 4 and so on until we find a tree that has no isomorphic subtree in P(G). One can see that if we generate all trees of size up to 15 we will definitely find T there. Within each size, let's number the trees in the order in which we've generated them. To find all trees of size x if we are given all trees of size x−1 and smaller, let's say that the sizes of the children of the root of the tree we generate must not decrease, and if the sizes are the same, their positions in the order must not decrease. Then, we can iterate over the first child, then among the smaller and suitable ones, the second child, then the third, and so on until the total size of the tree becomes exactly x. This way, we will enumerate all trees of size x in complexity of their total number (since we will not consider any tree twice and will not consider any extra trees). Let's do this until we find a tree that is not in P(G).

Hashes can be used to compare trees for isomorphism. For more details, read the [blog post](https://codeforces.com/blog/entry/113465)

Time Complexity: O(nlogn).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXSZ = 15;

void rec(int ns, int last, vector<int>& now, vector<vector<int>>& aint, vector<int>& col, vector<int>& sz, int& ss, int sns) {
    if (ss < 0) {
        return;
    }
	if (ns == 0) {
		col.back()++;
		aint.push_back(now);
		ss -= sns;
		return;
	}
	for (int i = min(last, col[ns] - 1); i >= 0; i--) {
		now.push_back(i);
		rec(ns - sz[i], i, now, aint, col, sz, ss, sns);
		now.pop_back();
	}
}

void dfs(int v, int p, vector<vector<int>>& arr, vector<int>& num, map<vector<int>, int>& m, vector<int>& sz) {
	vector<int> now;
	sz[v] = 1;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, num, m, sz);
			sz[v] += sz[i];
			if (sz[v] <= MAXSZ) {
			    now.push_back(num[i]);
			}
		}
	}
	if (sz[v] > MAXSZ) {
		num[v] = -1;
		return;
	}
	stable_sort(now.begin(), now.end());
	reverse(now.begin(), now.end());
	num[v] = m[now] - 1;
}

void dfs2(int x, int p, vector<vector<int>>& aint, vector<int>& ans) {
	if (p >= 0) {
		ans.push_back(p);
	}
	int now = ans.size();
	for (auto i : aint[x]) {
		dfs2(i, now, aint, ans);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> aint(1);
	vector<vector<int>> arr(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	map<vector<int>, int> m;
	vector<int> col(1, 0), sz(1, 1);
	col.push_back(1);
	for (int i = 2; i <= MAXSZ; i++) {
		vector<int> now;
		col.push_back(col.back());
		int ss = n;
		rec(i - 1, aint.size() - 1, now, aint, col, sz, ss, i);
		while (sz.size() < col.back()) {
			sz.push_back(i);
		}
		if (ss < 0) {
		    break;
		}
	}
	for (int i = 0; i < col.back(); i++) {
		m[aint[i]] = i + 1;
	}
	vector<int> num(n), szi(n, 1);
	dfs(0, 0, arr, num, m, szi);
	set<int> s;
	for (int i = 0; i < col.back(); i++) {
		s.insert(i);
	}
	for (auto i : num) {
		s.erase(i);
	}
	int x = *s.begin();
	vector<int> ans;
	if (sz[x] > n) {
		for (int i = 0; i < n; i++) {
			for (auto j : arr[i]) {
				if (i < j) {
					cout << i + 1 << ' ' << j + 1 << 'n';
				}
			}
		}
		return;
	}
	for (int i = 0; i < n - sz[x] - 1; i++) {
		ans.push_back(i);
	}
	dfs2(x, n - sz[x] - 1, aint, ans);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << ' ' << i + 2 << 'n';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}

```
