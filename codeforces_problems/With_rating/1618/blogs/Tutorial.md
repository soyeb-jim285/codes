# Tutorial

[1618A - Polycarp and Sums of Subsequences](../problems/A._Polycarp_and_Sums_of_Subsequences.md "Codeforces Round 760 (Div. 3)")

Idea: [Brovko](https://codeforces.com/profile/Brovko "International Master Brovko"), preparation: [Brovko](https://codeforces.com/profile/Brovko "International Master Brovko")

 **Tutorial**
### [1618A - Polycarp and Sums of Subsequences](../problems/A._Polycarp_and_Sums_of_Subsequences.md "Codeforces Round 760 (Div. 3)")

The order of elements in a doesn't matter. If there is at least one correct array a, then we can sort it and get the answer in which a1≤a2≤a3. Therefore, we can always find a sorted array. Suppose that a1≤a2≤a3. Then b1=a1, b2=a2, b7=a1+a2+a3. We can find a3 as b7−a1−a2.

 **Solution (Brovko)**
```cpp
#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        vector <int> b(7);

        for(int i = 0; i < 7; i++)
            cin >> b[i];

        cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[0] - b[1] << endl;
    }
}
```
[1618B - Missing Bigram](../problems/B._Missing_Bigram.md "Codeforces Round 760 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1618B - Missing Bigram](../problems/B._Missing_Bigram.md "Codeforces Round 760 (Div. 3)")

Consider a full sequence of bigrams for some word. The first bigram consists of letters 1 and 2 of the word. The second bigram consists of letters 2 and 3. The i-th bigram consists of letters i and i+1.

After one bigram is removed, there becomes two adjacent bigrams such that one consists of letters i and i+1 and the other consists of letters i+2 and i+3. Thus, we can find the position of the removed bigram by looking for a pair of adjacent bigrams such that the second letter of the first one differs from the first letter of the second one.

If there is no such pair, then the sequence of bigrams represents a valid word of length n−1. We can append it with any bigram that starts with the second letter of the last bigram to make it a valid word of length n.

If there exists such a pair, then all letters of the word can be recovered. We can find the position of the removed bigram, determine the letters it consisted of and insert it into the sequence.

After that, we have a full sequence of bigrams and we can restore the word from it.

Overall complexity: O(n) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = input().split()
	for i in range(n - 3):
		if s[i][1] != s[i + 1][0]:
			s.insert(i + 1, s[i][1] + s[i + 1][0])
			break
	else:
		s.append(s[-1][1] + 'a')
	print(s[0][0], end="")
	for i in range(n - 1):
		print(s[i][1], end="")
	print()
```
[1618C - Paint the Array](../problems/C._Paint_the_Array.md "Codeforces Round 760 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1618C - Paint the Array](../problems/C._Paint_the_Array.md "Codeforces Round 760 (Div. 3)")

What does it mean that no pair of adjacent elements should have the same color? It means that either all elements on odd positions are blue and all elements on even positions are red, or vice versa. So, we need to check these two cases.

Let's try to solve a case when we have to find a number d such that a1,a3,… are divisible by d, and a2,a4,… are not. What does it mean that d divides all of the numbers a1,a3,…? It means that d divides the gcd(a1,a3,…), where gcd represents the greatest common divisor. Let's calculate this gcd using Euclidean algorithm or some built-in functions in O(n+logA).

Okay, now we need to check all divisors of the gcd(a1,a3,…) and find if any of them does not divide a2,a4,…. So, we have to factorize gcd and generate all of its divisors... or do we? In fact, if gcd(a1,a3,…) divides any of the numbers a2,a4,…, then every divisor of gcd also divides that number. So, the only two numbers we have to check as canditates for the answer are gcd(a1,a3,…) and gcd(a2,a4,…).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> g(a.begin(), a.begin() + 2);
    for(int i = 0; i < n; i++)
    {
        g[i % 2] = __gcd(g[i % 2], a[i]);
    }  
    vector<bool> good(2, true);
    for(int i = 0; i < n; i++)
    {
        good[i % 2] = good[i % 2] && (a[i] % g[(i % 2) ^ 1] > 0);
    }   
    long long ans = 0;
    for(int i = 0; i < 2; i++)
        if(good[i])
            ans = max(ans, g[i ^ 1]);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        solve();
    }
}
```
[1618D - Array and Operations](../problems/D._Array_and_Operations.md "Codeforces Round 760 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1618D - Array and Operations](../problems/D._Array_and_Operations.md "Codeforces Round 760 (Div. 3)")

It's kinda obvious that we have to choose the k greatest elements of the array as the denominators in the operations: suppose we haven't chosen one of them, but have chosen a lesser element as a denominator; if we swap them, the total score won't decrease.

It is a bit harder to prove that the numerators of the fractions should be the next k greatest elements (the elements on positions from n−2k+1 to n−k in sorted order). It can be proved as follows: each fraction we will get in such a way rounds down to either 1 or to 0, and if we choose a lesser element as a numerator, we can decrease a fraction from 1 to 0, but we'll increase the sum of elements that remain in the array, so this is not optimal.

All that's left is to pair the numerators and denominators. A fraction with numerator equal to denominator rounds down to 1, any other fraction will round down to 0, so our goal is to minimize the number of fractions having the numerator equal to the denominator. It can be done by pairing the numbers into fractions in the following way: an−2k+1an−k+1, an−2k+2an−k+2, ..., an−kan (assuming a is sorted).

So, the solution of the problem is the following: sort the array a, then calculate n−2k∑i=1ai+k∑i=1⌊an−2k+ian−k+i⌋.

 **Solution (BledDest)**
```cpp
def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    a = sorted(a)
    cost = sum(a[0:n-2*k]) + sum(map(lambda x: a[x+n-2*k] // a[x+n-k], range(0, k)))
    print(cost)
    
t = int(input())
for i in range(t):
    solve()
```
[1618E - Singers' Tour](../problems/E._Singers'_Tour.md "Codeforces Round 760 (Div. 3)")

Idea: [shnirelman](https://codeforces.com/profile/shnirelman "Master shnirelman"), preparation: [shnirelman](https://codeforces.com/profile/shnirelman "Master shnirelman")

 **Tutorial**
### [1618E - Singers' Tour](../problems/E._Singers'_Tour.md "Codeforces Round 760 (Div. 3)")

First, bi=ai+2⋅ai−1+⋯+i⋅a1+(i+1)⋅an+…n⋅ai+1.

Consider the sum b1+b2+⋯+bn. If we substitute the formula of bi then for every i=1,2,…,n the coefficient at ai will be equal to n⋅(n+1)2, so we can find the sum S of all ai: S=a1+a2+⋯+an is equal to 2⋅(b1+b2+⋯+bn)n⋅(n+1). If the sum of bi isn't divisible by n⋅(n+1)2, then the answer is NO. 

Now let's consider the difference between two neighboring towns: bi−b(i+n−2)modn+1=ai−1+ai−2+⋯+aimodn+1−(n−1)⋅ai=S−ai−(n−1)⋅ai=S−n⋅ai, so ai=S−bi+b(i+n−2)modn+1n. If the value of ai we found isn't a positive integer, then the answer if NO. Otherwise, we can find a single value of ai for every i=1,2,…n. It's easy to see that these values are correct.

Overall complexity: O(n) per testcase. 

 **Solution (shnirelman)**
```cpp
#include <bits/stdc++.h>

using namespace std;
using li = long long;

const int N = 50013;

int b[N];
int a[N];

void solve() {
    
    int n;
    cin >> n;

    li sumb = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sumb += b[i];
    }

    li d = n * 1ll * (n + 1) / 2;

    if(sumb % d != 0) {
        cout << "NO" << endl;
        return;
    }

    li suma = sumb / d;

    for(int i = n - 1; i >= 0; i--) {
        li res = (b[i] - b[(i + 1) % n] + suma);
        if(res % n != 0 || res <= 0) {
            cout << "NO" << endl;
            return;
        }

        a[(i + 1) % n] = res / n;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}
```
[1618F - Reverse](../problems/F._Reverse.md "Codeforces Round 760 (Div. 3)")

Idea: [Lankin](https://codeforces.com/profile/Lankin "Expert Lankin"), preparation: [Lankin](https://codeforces.com/profile/Lankin "Expert Lankin")

 **Tutorial**
### [1618F - Reverse](../problems/F._Reverse.md "Codeforces Round 760 (Div. 3)")

There are two main approaches to this problem.

Approach 1. Let's analyze how the binary representation of x changes after the operation. If there are no zeroes at the end of it, appending 0 just reverses the binary representation; if there are any trailing zeroes, we remove them and reverse the binary representation. If we append 1, we just reverse the binary representation and add 1 at the beginning. No matter which action we choose on the first step, the resulting binary representation will have 1 at its beginning and 1 at its end, so no bits can be removed from it (no zero from the resulting binary representation can become leading). It means that every number we can obtain from x will have the following form: several ones (maybe none), then s, then several ones (again, maybe none), where s is one of the following four strings:

* the binary representation of x after appending 1 in the first operation;
* the binary representation of x after appending 0 in the first operation;
* one of the aforementioned representations, but reversed.

We can check that y meets one of these four templates, but since we only considered the case when we apply at least one operation, we also have to verify if x=y.

Approach 2. Run something like implicit BFS or DFS to generate all possible values you can obtain, pruning when the length of the binary representation we get becomes too large (say, greater than 100). Why does this work fast? As we have shown in our first approach, the numbers we can get from x have a very specific form, and if we limit their lengths to 100, we will consider only about 400 different numbers. Note that if you try this approach, you have to store the obtained numbers in some associative data structure (I use a set of strings in my solution).

 **Solution (awoo)**
```cpp
a, b = map(int, input().split())
s = bin(b)[2:]
t = bin(a)[2:]
if s == t:
    print("YES")
    exit(0)
for q in [t + '1', t.strip('0')]:
    for l in range(len(s) - len(q) + 1):
        r = len(s) - len(q) - l
        if '1' * l + q + '1' * r == s or '1' * l + q[::-1] + '1' * r == s:
            print("YES")
            exit(0)
print("NO")
```
 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

string go(string t)
{
    while(t.back() == '0') t.pop_back();
    reverse(t.begin(), t.end());
    return t;
}

string to_bin(long long x)
{
    if(x == 0)
        return "";
    else
    {
        string s = to_bin(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}

int main()
{
    long long x, y;
    cin >> x >> y;
    set<string> used;
    queue<string> q;
    q.push(to_bin(x));
    used.insert(to_bin(x));
    while(!q.empty())
    {
        string k = q.front();
        q.pop();
        if(k.size() > 100) continue;
        for(int i = 0; i < 2; i++)
        {
            string k2 = go(k + string(1, char('0' + i)));
            if(!used.count(k2))
            {
                used.insert(k2);
                q.push(k2);
            }
        }
    }
    if(used.count(to_bin(y)))
        cout << "YESn";
    else
        cout << "NOn";
}
```
[1618G - Trader Problem](../problems/G._Trader_Problem.md "Codeforces Round 760 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1618G - Trader Problem](../problems/G._Trader_Problem.md "Codeforces Round 760 (Div. 3)")

Suppose we have fixed the value of k, so we can trade an item with price i for an item with price j if j∈[0,i+k]. We can see that it's never optimal to trade an item with higher price for an item with lower price, and we could just simulate the trading process as follows: try to find an item owned by Polycarp and a more expensive item owned by the other character which can be traded, repeat until we cannot find any suitable pair.

Unfortunately, it is too slow. Instead, let's try to analyze: for a given value of k, how to verify that an item of price x can be traded for an item of price y (maybe not right away, but with intermediate trades)?

You can build a graph of n+m vertices representing items, where two vertices representing items with prices x and y are connected by an edge if and only if |x−y|≤k. Then, the edges of the graph represent possible trades, and the paths in the graph represent sequences of trades. So, one item can be traded for another item (possibly with intermediate trades) if the vertices representing the items belong to the same component.

For a fixed value of k, we can build this graph, find all of its components, calculate the number of Monocarp's items in each component and add this number of most expensive vertices from the component to the answer. There are two problems though.

The first one is that the graph may have up to O((n+m)2) edges. But if we sort all items according to their prices, we are only interested in edges between vertices which represent adjacent items in sorted order, so the size of the graph is decreased to O(n+m).

Another problem is that there are multiple queries for different values of k. To handle it, we can sort the values of k in ascending order and go in sorted order while maintaining the graph for the current value of k. A data structure like DSU or a method like small-to-large merging can be helpful to update the components as they merge.

The last trick: to quickly recalculate the number of items Monocarp has in a component and the sum of most expensive several items, you can build two prefix sum arrays — one over the array storing the costs of the items, and another one over the array which stores values 1 or 0 depending on who owns the respective item (the items should still be considered in sorted order). Since each component is a segment of costs of items, prefix sums allow us to calculate the required values in O(1).

By the way, knowing that each component is a segment, we can get rid of the graph and the structure that stores it altogether and just maintain a set of segments of items representing the components.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 400 * 1000 + 13;

int n, m, k;
int a[N], b[N];
int q[N];

int p[N];
multiset<int> wst[N], bst[N];
long long sum;

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (wst[a].size() + bst[a].size() < wst[b].size() + bst[b].size()) swap(a, b);
	for (auto it : wst[b])
		wst[a].insert(it);
	for (auto it : bst[b])
		bst[a].insert(it);
	wst[b].clear();
	bst[b].clear();
	while (!bst[a].empty() && !wst[a].empty() && *bst[a].begin() < *wst[a].rbegin()){
		sum -= *bst[a].begin();
		sum += *wst[a].rbegin();
		bst[a].insert(*wst[a].rbegin());
		wst[a].insert(*bst[a].begin());
		bst[a].erase(bst[a].begin());
		wst[a].erase(--wst[a].end());
	}
	p[b] = a;
}

long long ans[N];

struct event{
	int x, t, i;
};

int main() {
	scanf("%d%d%d", &n, &m, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m)
		scanf("%d", &b[i]);
	forn(i, k)
		scanf("%d", &q[i]);
	vector<pair<int, int>> tot;
	forn(i, n) tot.push_back({a[i], 1});
	forn(i, m) tot.push_back({b[i], 0});
	sort(tot.begin(), tot.end());
	sum = accumulate(a, a + n, 0ll);
	forn(i, n + m){
		p[i] = i;
		wst[i].clear();
		bst[i].clear();
		if (tot[i].second) bst[i].insert(tot[i].first);
		else wst[i].insert(tot[i].first);
	}
	vector<event> ev;
	forn(i, n + m - 1) ev.push_back({tot[i + 1].first - tot[i].first, 0, i});
	forn(i, k) ev.push_back({q[i], 1, i});
	sort(ev.begin(), ev.end(), [](const event &a, const event &b){
		if (a.x != b.x) return a.x < b.x;
		return a.t < b.t;
	});
	for (auto it : ev){
		if (it.t == 0)
			unite(it.i, it.i + 1);
		else
			ans[it.i] = sum;
	}
	forn(i, k) printf("%lldn", ans[i]);
}
```
 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

long long get(const vector<int>& pcnt, const vector<long long>& psum, pair<int, int> seg)
{
    int L = seg.first;
    int R = seg.second;
    int cnt = pcnt[R] - pcnt[L];
    return psum[R] - psum[R - cnt];
}

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    vector<int> pcnt = {0};
    vector<long long> psum = {0ll};
    vector<pair<int, int>> order;
    for(int i = 0; i < n; i++) order.push_back(make_pair(a[i], 1));
    for(int i = 0; i < m; i++) order.push_back(make_pair(b[i], 0));
    sort(order.begin(), order.end());
    int z = n + m;
    for(int i = 0; i < z; i++)
    {
        pcnt.push_back(pcnt.back() + order[i].second);
        psum.push_back(psum.back() + order[i].first);
    }
    long long cur = 0;
    for(int i = 0; i < n; i++)
        cur += a[i];
    set<pair<int, int>> segs;
    for(int i = 0; i < z; i++)
        segs.insert(make_pair(i, i + 1));
    map<int, vector<int>> events;
    for(int i = 0; i < z - 1; i++)
        events[order[i + 1].first - order[i].first].push_back(i);
    vector<pair<int, long long>> ans = {{0, cur}};
    for(auto x : events)
    {
        int cost = x.first;
        vector<int> changes = x.second;
        for(auto i : changes)
        {
            auto itr = segs.upper_bound(make_pair(i, int(1e9)));
            auto itl = prev(itr);
            pair<int, int> pl = *itl;
            pair<int, int> pr = *itr;
            cur -= get(pcnt, psum, pl);
            cur -= get(pcnt, psum, pr);
            pair<int, int> p = make_pair(pl.first, pr.second);
            cur += get(pcnt, psum, p);
            segs.erase(pl);
            segs.erase(pr);
            segs.insert(p);
        }
        ans.push_back(make_pair(cost, cur));
    }              
    for(int i = 0; i < q; i++)
    {
        int k;
        scanf("%d", &k);
        int pos = upper_bound(ans.begin(), ans.end(), make_pair(k + 1, -1ll)) - ans.begin() - 1;
        printf("%lldn", ans[pos].second);
    }
}
```
