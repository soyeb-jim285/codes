# Tutorial

[1913A - Rating Increase](../problems/A._Rating_Increase.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1913A - Rating Increase](../problems/A._Rating_Increase.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Since the length of the string is pretty small, it's possible to iterate over all possible cuts of ab into a and b. First, you have to check if b has a leading zero. If it doesn't, compare integer representations of a and b. In order to get an integer from a string, you can use stoi(s) for C++ or int(s) for Python.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    ab = input()
    for i in range(1, len(ab)):
        if ab[i] != '0' and int(ab[:i]) < int(ab[i:]):
            print(ab[:i], ab[i:])
            break
    else:
        print(-1)
```
[1913B - Swap and Delete](../problems/B._Swap_and_Delete.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1913B - Swap and Delete](../problems/B._Swap_and_Delete.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Let's count the number of 0-s and 1-s in s as cnt0 and cnt1 correspondingly. Since t consists of characters from s then t will contain no more than cnt0 zeros and cnt1 ones.

Let's build t greedily, since we always compare t with prefix of s. Suppose the length of t is at least one, it means that t1 must be different from s1, so if s1 = 0 we must set t1 = 1. So let's check that we have at least one 1 (or cnt1>0), take 1 and place it at t1. Case s1 = 1 is the same.

After placing t1 we can analogically try to place t2 and so on until we run out of necessary digits or build the whole string of length |s|.

We've built the longest possible string t in O(|s|) time, so the answer is |s|−|t|.

 **Solution (adedalic)**
```cpp
for _ in range(int(input())):
    s = input()
    cnt = [0, 0]
    for i in range(len(s)):
        cnt[int(s[i])] += 1
    for i in range(len(s) + 1):
        if (i == len(s) or cnt[1 - int(s[i])] == 0):
            print(len(s) - i)
            break
        cnt[1 - int(s[i])] -= 1
```
[1913C - Game with Multiset](../problems/C._Game_with_Multiset.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Idea: [Ferume](https://codeforces.com/profile/Ferume "Master Ferume"), preparation: [Ferume](https://codeforces.com/profile/Ferume "Master Ferume")

 **Tutorial**
### [1913C - Game with Multiset](../problems/C._Game_with_Multiset.md "Educational Codeforces Round 160 (Rated for Div. 2)")

We are given a classic knapsack problem. There are items with certain weights and a total weight that we want to achieve. If the weights were arbitrary, we would need dynamic programming to solve it. However, this variation of the knapsack problem can be solved greedily. What makes it special? If we arrange the weights in non-decreasing order, each subsequent weight is divisible by the previous one.

Then the following greedy approach works. Arrange the items by weight, from smallest to largest. Let's say we want to achieve sum s, and the weights of the items are x1,x2,…. Let the weights be distinct, and the number of items with weight xi be cnti.

If s is not divisible by x1, the answer is NO. Otherwise, we look at the remainder of s divided by x2. If it is not equal to 0, our only hope to make it 0 is to take items with weight x1. All other items are divisible by x2, so they will not help. We take exactly smodx2x1 items. If there are less than that, the answer is NO.

Subtract this from s — now the remainder is 0. Now the claim is: there is no point in taking additional items with weight x1 in a quantity not divisible by x2x1. If we do that, we will break the remainder again. Thus, we can pack x2x1 items with weight x1 into groups of weight x2 and add the number of these groups to cnt2. Then recursively solve the same problem, but for the new value of s and weights 2,3,….

When we run out of distinct weights, we have to check that there are enough items of the largest weight to collect the entire weight s.

This can be written by iterating through the weight values from smallest to largest. For each weight, we can maintain the count in an array. Then the first type of query works in O(1), and the second type of query works in 30 iterations.

 **Solution (awoo)**
```cpp
from sys import stdin, stdout

LOG = 30
cnt = [0 for i in range(LOG)]
ans = []
for _ in range(int(stdin.readline())):
    t, v = map(int, stdin.readline().split())
    if t == 1:
        cnt[v] += 1
    else:
        nw = 0
        for i in range(LOG):
            r = (v % (2 << i)) // (1 << i)
            if r > nw + cnt[i]:
                ans.append(0)
                break
            v -= r
            nw = (nw + cnt[i] - r) // 2
        else:
            ans.append(nw >= (v >> 30))
stdout.write('n'.join(["YES" if x else "NO" for x in ans]))
```
[1913D - Array Collapse](../problems/D._Array_Collapse.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms"), preparation: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1913D - Array Collapse](../problems/D._Array_Collapse.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Let's rephrase the problem a bit. Instead of counting the number of arrays, let's count the number of subsequences of elements that can remain at the end.

One of the classic methods for counting subsequences is dynamic programming of the following kind: dpi is the number of subsequences such that the last taken element is at position i. Counting exactly this is that simple. It happens that element i cannot be the last overall because it is impossible to remove everything after it. Thus, let's say it a little differently: the number of good subsequences on a prefix of length i. Now we are not concerned with what comes after i — after the prefix.

If we learned to calculate such dp, we could get the answer from it. We just need to understand when we can remove all elements after a fixed one. It is easy to see that it is enough for all these elements to be smaller than the fixed one. Then they can be removed one by one from left to right. If there is at least one larger element, then the maximum of such elements cannot be removed.

Therefore, the answer is equal to the sum of dp for all i such that ai is the largest element on a suffix of length n−i+1.

How to calculate such dp?

Let's look at the nearest element to the left that is larger than ai. Let its position be j. Then any subsequence that ended with an element between j and i can have the element i appended to it. It is only necessary to remove the elements standing before i. This can also be done one by one.

Can j be removed as well? It can, but it's not that simple. Only the element that is the nearest larger one to the left for aj or someone else even more to the left can do this. Let f[i] be the position of the nearest larger element to the left. Then the element i can also extend subsequences ending in a[f[i]],a[f[f[i]]],a[f[f[f[i]]]],….

If there are no larger elements to the left of the element — the element is the maximum on the prefix — then 1 is added to its dp value. This is a subsequence consisting of only this element.

The position of the nearest larger element to the left can be found using a monotonic stack: keep a stack of elements; while the element at the top is smaller, remove it; then add the current one to the stack.

Counting the dp currently works in O(n2) in the worst case. How to optimize this? The first type of transitions is optimized by prefix sums, as it is simply the sum of dp on a segment. For the second type of transitions, you can maintain the sum of dp on a chain of jumps to the nearest larger element: dpsumi=dpsumf[i]+dpi. Now, both transitions can be done in O(1).

Overall complexity: O(n) for each testcase.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int normalize(long long x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> nextMin(n);
        vector <int> dpSum(n + 2);
        vector <int> dpNext(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        stack <int> stMin;
        nextMin[n - 1] = n;
        dpSum[n] = 1;
        for (int pos = n - 1; pos >= 0; --pos) {
            while(!stMin.empty() && a[stMin.top()] > a[pos])
                stMin.pop();
            nextMin[pos] = stMin.empty() ? n : stMin.top();
            stMin.push(pos);
            
            int nxtPos = nextMin[pos];
            int dpPos = normalize(dpSum[pos + 1] - dpSum[nxtPos + 1]);
            if (nxtPos != n) {
                dpPos = normalize(dpPos + dpNext[nxtPos]);
                dpNext[pos] = normalize(dpSum[nxtPos] - dpSum[nxtPos + 1] + dpNext[nxtPos]);
            }
            dpSum[pos] = normalize(dpPos + dpSum[pos + 1]);
            
            //cout << pos << ' ' << nxtPos << ' ' << dpPos << endl;
        }
        
        int res = 0;
        int mn = a[0];
        for(int i = 0; i < n; ++i) {
            mn = min(mn, a[i]);
            if (a[i] == mn) {
                res = normalize(res + dpSum[i] - dpSum[i + 1]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
```
[1913E - Matrix Problem](../problems/E._Matrix_Problem.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Idea: [Ferume](https://codeforces.com/profile/Ferume "Master Ferume"), preparation: [Ferume](https://codeforces.com/profile/Ferume "Master Ferume")

 **Tutorial**
### [1913E - Matrix Problem](../problems/E._Matrix_Problem.md "Educational Codeforces Round 160 (Rated for Div. 2)")

There are many ways to solve this problem (even if all of them are based on minimum cost flows), but in my opinion, the most elegant one is the following one.

Let us build another matrix b of size n×m that meets the following requirements:

* the sum in the i-th row of the matrix b is Ai;
* the sum in the j-th column of the matrix b is Bj;
* the number of cells (i,j) such that ai,j=bi,j=1 is the maximum possible.

It's quite easy to see that this matrix b is the one which we need to transform the matrix a into: the first two conditions are literally from the problem statement, and the third condition ensures that the number of 1's we change into 0's is as small as possible (and since we know the number of 1's in the matrix a, and we know that the number of 1's in the matrix b should be exactly ∑Ai, this also minimizes the number of times we change a 0 into a 1). So, the third condition minimizes the number of operations we have to perform.

How can we build b? Let's model it with a flow network (with costs). We will need a source (let's call it S), a sink (let's call it T), a vertex for every row (let's call it Ri for the i-th row), and a vertex for every column (let's call it Cj for the j-th column).

To model that we want the i-th row to have the sum Ai, let's add a directed edge from S to Ri with capacity of Ai and cost of 0. Some solutions will also need to make sure that this directed edge has a lower constraint on the flow equal to Ai, but we will show later why it's unnecessary in our method. Similarly, to model that the j-th column should have sum Bj, add a directed edge from Cj to T with capacity Ai and cost 0.

To model that we can choose either 0 or 1 for the cell (i,j), add a directed edge from Ri to Cj with capacity 1. The value in the corresponding cell of the matrix b will be equal to the flow along that edge. The cost of this edge should reflect that we want to have as many cells such that ai,j=bi,j=1. To ensure that, let's make its cost 0 if ai,j=1, or 1 if ai,j=0. That way, the cost of the flow increases by 1 each time we put a 1 in a cell where ai,j=0 — and since the number of 1's in the matrix b is fixed, this means that we put a 0 in a cell where ai,j=1; so, the number of cells (i,j) such that ai,j=bi,j=1 gets reduced.

Now our network is ready. In order to make sure that all edges connecting S with Ri and Cj with T are saturated, we have to find the minimum cost maximum flow in it. Since the network has no negative cycles, the number of vertices is O(n+m), the number of edges is O(nm), and the maximum flow in the network is also O(nm), any reasonable MCMF algorithm can be used.

After running MCMF, let's check that the amount of the flow we pushed is equal both to ∑Ai and to sumBj. If that's not the case, then it is impossible to construct the matrix b, so the answer is −1. Otherwise, to calculate the number of operations we have to perform, we can either restore the matrix b from the flow we got and calculate the number of cells such that ai,j≠bi,j, or derive a formula which can calculate the number of operations directly from the number of 1's in a, number of 1's in b and the cost of the flow. The model solution does the latter.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 111;

struct edge
{
    int y, c, w, f;
    edge() {};
    edge(int y, int c, int w, int f) : y(y), c(c), w(w), f(f) {};
};

vector<edge> e;
vector<int> g[N];

int rem(int x)
{
    return e[x].c - e[x].f;
}

void add_edge(int x, int y, int c, int w)
{
    g[x].push_back(e.size());
    e.push_back(edge(y, c, w, 0));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, -w, 0));
}

int n, m, s, t, v;

pair<int, long long> MCMF()
{
    int flow = 0;
    long long cost = 0;
    while(true)
    {
        vector<long long> d(v, (long long)(1e18));
        vector<int> p(v, -1);
        vector<int> pe(v, -1);
        queue<int> q;
        vector<bool> inq(v);
        q.push(s);
        inq[s] = true;
        d[s] = 0;
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            inq[k] = false;
            for(auto ei : g[k])
            {
                if(rem(ei) == 0) continue;
                int to = e[ei].y;
                int w = e[ei].w;
                if(d[to] > d[k] + w)
                {
                    d[to] = d[k] + w;
                    p[to] = k;
                    pe[to] = ei;
                    if(!inq[to])
                    {
                        inq[to] = true;
                        q.push(to);
                    }
                }
            }
        }
        if(p[t] == -1) break;
        flow++;
        cost += d[t];
        int cur = t;
        while(cur != s)
        {
            e[pe[cur]].f++;
            e[pe[cur] ^ 1].f--;
            cur = p[cur];
        }
    }
    return make_pair(flow, cost);
}

int get_sum(const vector<int>& v)
{
    int sum = 0;
    for(auto x : v) sum += x;
    return sum;
}

int main()
{
    cin >> n >> m;
    s = n + m;
    t = n + m + 1;
    v = n + m + 2;
    int sum_matrix = 0;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            sum_matrix += x;
            if(x == 1)
                add_edge(i, j + n, 1, 0);
            else
                add_edge(i, j + n, 1, 1);
        }
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        add_edge(s, i, A[i], 0);
    }
    for(int i = 0; i < m; i++) 
    {
        cin >> B[i];
        add_edge(i + n, t, B[i], 0);
    }
    
    auto res = MCMF();
    if(res.first != get_sum(A) || res.first != get_sum(B))
        cout << -1 << endl;
    else
        cout << sum_matrix - res.first + res.second * 2 << endl;
}
```
[1913F - Palindromic Problem](../problems/F._Palindromic_Problem.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Idea: [Ferume](https://codeforces.com/profile/Ferume "Master Ferume"), preparation: [Ferume](https://codeforces.com/profile/Ferume "Master Ferume")

 **Tutorial**
### [1913F - Palindromic Problem](../problems/F._Palindromic_Problem.md "Educational Codeforces Round 160 (Rated for Div. 2)")

Let's recall the algorithm for counting the number of palindromes in a string. For each position, we can calculate the longest odd and even palindromes with centers at that position (the right one for even). Then sum up all the values.

If we forget about the complexity, we can consider the following algorithm for solving the full problem. Iterate over the index of the change and the new letter. Make the change, count the number of palindromes, and update the answer. In case of equality, choose the lexicographically minimal change.

Let's keep the first step and optimize the rest. It won't be possible to count the number of palindromes from scratch for every change, so let's try to calculate how much their number will change from the original. It's also not feasible to compare all strings lexicographically naively, so we have to come up with a faster way to compare.

Let's fix the change position i. Which of the longest palindromes change? If for some center j, the longest palindrome included i, then we definitely know its new length. Due to the change at i, the longest palindrome will stop at i. If the longest palindrome did not reach i, it will not change. And only if it stopped at i, it can become longer, and we don't know by how much yet. But for each center j and the parity of the palindrome, there are only positions to the left and to the right where it stops. So, in total, we will need to make O(n) such checks.

How to take into account the palindromes that become shorter? We need to calculate the sum of the differences for all palindromes that include i. For an odd palindrome, this change looks like this: […,0,−1,−2,−3,−4,−3,−2,−1,0,…], where −4 is the center of the palindrome, and the values show the difference in the number of palindromes for each position of the string. For an even palindrome: […,0,−1,−2,−3,−3,−2,−1,0,…]. To calculate the sum at each position, we can pre-calculate a difference array based on these values.

The difference array usually implies first-order changes: write +x at l, write −x at r+1, then collect the prefix sum to get […,0,x,x,…,x,0,…]. But we can also record second-order changes. For the odd construction, we will write as follows. Let the length of the palindrome be len, and the center be i. Then: 

* dt[i−len+1]+=1;
* dt[i+1]−=2;
* dt[i+len+1]+=1.

Then iterate from left to right, maintaining two variables. The current change and the current value. At each i, add dt[i] to the change, add the change to the value, and save the value to some array.

For the even case, it is built similarly. It is easy to see that such changes can be made at the same time. Basically the same as the regular difference array.

Now, in each position, the total decrease in the length of the palindromes passing through that position is recorded. The answer will decrease by almost this amount. The only difference is the odd-length palindromes with a center at this position. They will not change at all, and we accidentally subtracted them. Thus, let's save the longest odd palindrome for each position in advance and add it back.

Let's learn how to calculate the longest palindromes for each center. Yes, there is the Manacher's algorithm for a static string. We can use it for counting at the very beginning, but it's not really necessary. Instead, let's learn to count palindromes using suffix structures. In particular, with a suffix array.

It is known that with an additional sparse table, we can query the longest common prefix of two suffixes in O(1) with pre-calculation in O(nlogn). Let's build a suffix array on the string s+#+rev(s)+$. Then we can query the LCP of both suffixes and reverse prefixes. Then the longest odd palindrome with center at i is LCP(s[i..n], rev(s[1..i])). The even one is LCP(s[i..n], rev(s[1..i−1])).

So, we can count the palindromes at the very beginning with O(nlogn) pre-calculation and O(n) extra calculations.

The following task remains. For each position, the centers of the palindromes that reach it are known. For each such center, we need to be able to recalculate how much longer the palindrome will become after changing the letter at that position.

Obviously, even the new letter may still not match the letter on the other side. If it does match, we would like to know how many letters further match the opposite ones in the original string. And we already have a tool for this. It's still a simple LCP query on the suffix to the right of the right letter and the reverse prefix to the left of the left letter.

Now we have everything necessary to recalculate the number of palindromes.

If the new count is greater than the current maximum, we will simply update the answer. If it is equal, we need to check the lexicographic order. The following check works: 

* if one change increased the original letter, and the other decreased it, then the second one will definitely produce a smaller string;
* if both changes decreased it, then the more left one will produce a smaller string; if both are in the same position, the smaller letter will produce a smaller string;
* if both changes increased it, then the more right one will produce a smaller string; if both are in the same position, the smaller letter will produce a smaller string.

All these checks can be performed in O(1).

Overall complexity: O(nlogn+n⋅|AL|).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

struct sparse_table {
    vector<vector<int>> st;
    vector<int> pw;
    
    sparse_table() {}
    
    sparse_table(const vector<int> &a) {
        int n = a.size();
        int logn = 32 - __builtin_clz(n);
        st.resize(logn, vector<int>(n));
        forn(i, n)
            st[0][i] = a[i];
        for (int j = 1; j < logn; ++j) forn(i, n) {
            st[j][i] = st[j - 1][i];
            if (i + (1 << (j - 1)) < n)
                st[j][i] = min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
        }
        pw.resize(n + 1);
        pw[0] = pw[1] = 0;
        for (int i = 2; i <= n; ++i)
            pw[i] = pw[i >> 1] + 1;
    }
    
    int get(int l, int r) {
        if (l >= r) return 1e9;
        int len = pw[r - l];
        return min(st[len][l], st[len][r - (1 << len)]);
    }
};

struct suffix_array {
    vector<int> c, pos;
    vector<pair<pair<int, int>, int>> p, nw;
    vector<int> cnt;
    int n;
    
    void radix_sort(int max_al) {
        cnt.assign(max_al, 0);
        forn(i, n) ++cnt[p[i].x.y];
        for (int i = 1; i < max_al; ++i) cnt[i] += cnt[i - 1];
        nw.resize(n);
        forn(i, n) nw[--cnt[p[i].x.y]] = p[i];
        cnt.assign(max_al, 0);
        forn(i, n) ++cnt[nw[i].x.x];
        for (int i = 1; i < max_al; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) p[--cnt[nw[i].x.x]] = nw[i];
    }
    
    vector<int> lcp;
    sparse_table st;
    
    int get_lcp(int l, int r) {
        l = c[l], r = c[r];
        if (l > r) swap(l, r);
        return st.get(l, r);
    }
    
    suffix_array(const string &s) {
        n = s.size();
        c = vector<int>(s.begin(), s.end());
        int max_al = *max_element(c.begin(), c.end()) + 1;
        p.resize(n);
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0, j = k; i < n; ++i, j = (j + 1 == n ? 0 : j + 1))
                p[i] = make_pair(make_pair(c[i], c[j]), i);
            radix_sort(max_al);
            c[p[0].y] = 0;
            for (int i = 1; i < n; ++i) c[p[i].y] = c[p[i - 1].y] + (p[i].x != p[i - 1].x);
            max_al = c[p.back().y] + 1;
        }
        lcp.resize(n);
        int l = 0;
        forn(i, n) {
            l = max(0, l - 1);
            if (c[i] == n - 1)
                continue;
            while (i + l < n && p[c[i] + 1].y + l < n && s[i + l] == s[p[c[i] + 1].y + l])
                ++l;
            lcp[c[i]] = l;
        }
        pos.resize(n);
        forn(i, n)
            pos[i] = p[i].y;
        st = sparse_table(lcp);
    }
};

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    auto sa = suffix_array(s + "#" + t + "$");
    vector<vector<int>> ev0(n), ev1(n);
    long long base = 0;
    vector<long long> dt(n + 2);
    vector<int> d1(n);
    forn(i, n){
        int len0 = sa.get_lcp(i, 2 * n - i + 1);
        base += len0;
        dt[i - len0] += 1;
        dt[i] -= 1;
        dt[i + 1] -= 1;
        dt[i + len0 + 1] += 1;
        if (i - len0 - 1 >= 0 && i + len0 < n){
            ev0[i - len0 - 1].push_back(i);
            ev0[i + len0].push_back(i);
        }
        int len1 = sa.get_lcp(i, 2 * n - i);
        d1[i] = len1;
        dt[i - len1 + 1] += 1;
        dt[i + 1] -= 2;
        dt[i + len1 + 1] += 1;
        base += len1;
        if (i - len1 >= 0 && i + len1 < n){
            ev1[i - len1].push_back(i);
            ev1[i + len1].push_back(i);
        }
    }
    vector<long long> dx(n + 1);
    long long curt = 0, val = 0;
    forn(i, n){
        curt += dt[i];
        val += curt;
        dx[i] = val;
    }
    long long ans = base;
    int pos = -1, nc = -1;
    bool gr = false;
    forn(i, n) forn(c, 26) if (c != s[i] - 'a'){
        long long cur = base;
        for (int j : ev0[i]){
            if (j <= i && c == s[2 * j - i - 1] - 'a')
                cur += 1 + sa.get_lcp(i + 1, 2 * n - (2 * j - i - 2));
            else if (j > i && c == s[2 * j - i - 1] - 'a')
                cur += 1 + sa.get_lcp(2 * j - i, 2 * n - (i - 1));
        }
        for (int j : ev1[i]){
            if (c != s[2 * j - i] - 'a') continue;
            if (j < i)
                cur += 1 + sa.get_lcp(i + 1, 2 * n - (2 * j - i - 1));
            else
                cur += 1 + sa.get_lcp(2 * j - i + 1, 2 * n - (i - 1));
        }
        cur += d1[i];
        cur -= dx[i];
        bool upd = false;
        if (cur > ans){
            upd = true;
        }
        else if (cur == ans){
            if (c < s[i] - 'a'){
                if (pos == -1 || gr)
                    upd = true;
            }
            else{
                if (pos < i && gr)
                    upd = true;
            }
        }
        if (upd){
            ans = cur;
            pos = i;
            nc = c;
            gr = c > s[i] - 'a';
        }
    }
    cout << ans << endl;
    if (pos != -1) s[pos] = nc + 'a';
    cout << s << endl;
    return 0;
}
```
