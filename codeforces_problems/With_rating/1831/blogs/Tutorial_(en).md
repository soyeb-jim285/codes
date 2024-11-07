# Tutorial_(en)

[1831A — Twin Permutations](../problems/A._Twin_Permutations.md)
--------------------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Candidate Master Gheal") 

 **Hints****Hint 1**If ai+bi≤ai+1+bi+1, then ai+bi can be equal to ai+1+bi+1.

 **Hint 2**Building on the idea from the first hint, can we build a permutation b such that a1+b1=a2+b2=…=an+bn?

 **Solution**Since ai+bi≤ai+1+bi+1, then ai+bi can be equal to ai+1+bi+1. 

Therefore, any permutation b which satisfies a1+b1=a2+b2=…=an+bn is a valid answer.

If bi=n+1−ai, then:

 1. b is a permutation;
2. a1+b1=a2+b2=…=an+bn=n+1

Consequently, b=[n+1−a1,n+1−a2,…,n+1−ai,…,n+1−an] is a valid answer.

Time complexity per test case : O(N)

 **Code (Gheal, C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
void tc(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        cout<<n+1-x<<' ';
    }
    cout<<'n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t; cin>>t; while(t--)
        tc();
    return 0;
}


```
 **Rate Problem**Good problem 


[*399*](https://codeforces.com/data/like?action=like "I like this")





Ok problem 

 
[*105*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*12*](https://codeforces.com/data/like?action=like "I like this")



[1831B — Array Merging](../problems/B._Array_merging.md)
----------------------------------------------------------------------

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte")

 **Hints****Hint 1**When we merge two arrays a and b, we can force the resulting array to have [al1,al1+1,…,ar1,bl2,bl2+1,…,br1] as a subarray, for some 1≤l1≤r1≤n and 1≤l2≤r2≤n.

 **Hint 2**If al1=bl1, then we can achieve a contiguous sequence of (r1−l1+1)+(r2−l2+1) equal elements in the resulting array.

 **Solution**Let maxa(x) be the length of the longest subarray from a containing only elements equal to x. If x doesn't appear in a, then maxa(x)=0.

Similarly, let maxb(x) be the length of the longest subarray from b containing only elements equal to x. If x doesn't appear in b, then maxb(x)=0.

maxa and maxb can be computed in O(N) by scanning the array while updating current maximal subarray.

When merging two arrays, it is possible to force a particular subarray [al1,al1+1,…,ar1] to be adjacent to another particular subarray [bl2,bl2+1,…,br2] in the merged array.

 **Proof**We can construct the merged array as follows: 

 [a1,a2,…,al1−1]+[b1,b2,…,bl2−1]+[al1,al1+1,…,ar1,bl2,bl2+1,…,br2]+[…]If al1=bl2, then the merged array will have a subarray consisting of (r1−l1+1)+(r2−l2+1) equal elements.

Therefore, the answer is equal to: 

 max2⋅ni=1(maxa(i)+maxb(i))Time complexity per testcase: O(N).

 **Code (tibinyte, C++)**
```cpp
#include <bits/stdc++.h>

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
        vector<int> b(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        vector<int> fa(n + n + 1);
        vector<int> fb(n + n + 1);
        int p = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] != a[i - 1])
            {
                fa[a[i - 1]] = max(fa[a[i - 1]], i - p);
                p = i;
            }
        }
        fa[a[n]] = max(fa[a[n]], n - p + 1);

        p = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (b[i] != b[i - 1])
            {
                fb[b[i - 1]] = max(fb[b[i - 1]], i - p);
                p = i;
            }
        }
        fb[b[n]] = max(fb[b[n]], n - p + 1);

        int ans = 0;
        for (int i = 1; i <= n + n; ++i)
        {
            ans = max(ans, fa[i] + fb[i]);
        }

        cout << ans << 'n';
    }
}

```
 **Rate problem**Good problem 

 
[*584*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*101*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*87*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*53*](https://codeforces.com/data/like?action=like "I like this")



[1830A — Copil Copac Draws Trees](https://codeforces.com/contest/1830/problem/A)
--------------------------------------------------------------------------------

Author: [alecs](https://codeforces.com/profile/alecs "Candidate Master alecs")

 **Hints****Hint 1**What is the answer if n=3?

 **Hint 2**The previous case can be generalised to find the answer for any tree.

 **Solution**This problem can be solved via dynamic programming. From here on out, step 1 from the statement will be called a "scan".

Let dp[i] be the number of scans needed to activate node i, and id[i] be the index (in the order from the input) of the edge which activated node i.

Intially, since only 1 is active, dp[1]=1 and id[1]=0.

We will perform a dfs traversal starting from node 1. When we process an edge (u,v), one of the following two cases can happen:

 1. If index((u,v))≥id[u], we can visit v in the same scan as u:

 dp[v]=dp[u], id[v]=index((u,v)) 1. If index((u,v))<id[u], v will be visited in the next scan after dp[u]:

 dp[v]=dp[u]+1, id[v]=index((u,v))The answer is maxni=1(dp[i]).

Time complexity per test case: O(n)

 **Code (Gheal, C++)**
```cpp
  
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 2e5+5;
int dp[NMAX], id[NMAX];
vector<pair<int,int>> edg[NMAX];
void dfs(int u){
    for(auto it : edg[u]){
        if(dp[it.first] == 0){
            dp[it.first] = dp[u] + (it.second <= id[u]);
            id[it.first] = it.second;
            dfs(it.first);
        }
    }
}
void tc(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) dp[i] = id[i] = 0, edg[i].clear();
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        edg[u].push_back({v,i});
        edg[v].push_back({u,i});
    }
    dp[1] = 1;
    dfs(1);
    int ans = 0;
    for(int i=1; i<=n; i++) ans=max(ans,dp[i]);
    cout<<ans<<'n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
        tc();
    return 0;
}

```
 **Code (alecs, C++)**
```cpp
#include <bits/stdc++.h>

const int NMAX = 3e5 + 5, INF = 1e9;

int n, f[NMAX], d[NMAX];
std :: vector < std :: pair < int, int > > G[NMAX];

void DFS(int node, int t) {
    f[node] = true;

    for (int i = 0; i < G[node].size(); ++ i) {
        int u = G[node][i].first, c = G[node][i].second;

        if (f[u] == false) {
            d[u] = (c < t) + d[node];
            DFS(u, c);
        }
    }

    return;
}

int main() {
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(nullptr);
    
    int tc;
    
    std :: cin >> tc;
    
    while (tc --) {
        std :: cin >> n;
    
        for (int i = 1, u, v; i < n; ++ i) {
            std :: cin >> u >> v;
    
            G[u].push_back({v, i});
            G[v].push_back({u, i});
        }
        
        for (int i = 1; i <= n; ++ i)
            f[i] = false;
    
        d[1] = 0;
        DFS(1, n);
    
        int Max = 0;
    
        for (int i = 1; i <= n; ++ i)
            Max = std :: max(Max, d[i]);
    
        std :: cout << Max << "n";
        
        for (int i = 1; i <= n; ++ i)
            G[i].clear();
    }

    return 0;
}
```
 **Rate problem**Good problem 

 
[*760*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*41*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*42*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*72*](https://codeforces.com/data/like?action=like "I like this")



[1830B — The BOSS Can Count Pairs](https://codeforces.com/contest/1830/problem/B)
---------------------------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Candidate Master Gheal")

 **Hints****Hint 1**Since bi≤n and bj≤n, bi+bj=ai⋅aj≤2⋅n.

 **Hint 2**Since ai⋅aj≤2⋅n, then min(ai,aj)≤√2⋅n.

 **Solution**Since bi≤n and bj≤n, bi+bj=ai⋅aj≤2⋅n. Therefore, min(ai,aj)≤√2⋅n.

Let lim=√2⋅n and fr[ai][bi] be the number of pairs (ai,bi) from the input such that ai≤lim. 

A pair (i,j) is *good* if it satisfies ai⋅aj=bi+bj.

Firstly, we'll count the number of good pairs (i,j) such that ai=aj. Since min(ai,aj)≤lim, we can see that ai=aj≤lim.

This sum can be written as:

 ∑ni=1fr[ai][ai⋅ai−bi]−∑limi=1fr[i][i⋅i2]2The remaining good pairs will have ai≠aj, and instead of counting the pairs which have i<j, we can count the pairs which have ai>aj.

Since aj=min(ai,aj), we can say that aj≤lim.

Substituting aj for j, this second sum can be written as:

 ∑ni=1∑min(ai−1,2⋅nai)j=1fr[j][ai⋅j−bi]Since we've already established that j≤lim=√2⋅n, calculating this sum takes O(n√n) time.

**Be especially careful when calculating these sums, as ai⋅ai−bi and ai⋅j−bi can end up being either negative or greater than n.**

Time complexity per testcase: O(n√n)

 **Code (Gheal, C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll NMAX=2e5+5,SQRMAX=635,MOD=1e9+7;

int fr[SQRMAX][NMAX];
ll a[NMAX],b[NMAX];
void tc(){
    ll n,ans=0;
    cin>>n;
    ll lim=sqrt(n*2);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(a[i]<=lim)
            fr[a[i]][b[i]]++;
    }
    for(ll i=0;i<n;i++){
        if(a[i]<=lim){
            if(a[i]*a[i]-b[i]>=1 && a[i]*a[i]-b[i]<=n)
                ans+=fr[a[i]][a[i]*a[i]-b[i]];
        }
    }
    for(ll i=2;i<=lim;i+=2)
        ans-=fr[i][i*i/2];
    ans/=2;

    for(ll i=0;i<n;i++){
        for(ll j=1;j<=lim && j<a[i] && j*a[i]<=2*n;j++){
            if(j*a[i]-b[i]>=1 && j*a[i]-b[i]<=n)
                ans+=fr[j][j*a[i]-b[i]];
        }
    }
    for(ll i=0;i<n;i++){
        if(a[i]<=lim)
            fr[a[i]][b[i]]=0;
    }
    cout<<ans<<'n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        tc();
    return 0;
}

```
 **Code (Vladithur, Python)**
```cpp
  
for _ in range(int(input())):
    n = int(input())
    
    ta = list(map(int, input().split()))
    tb = list(map(int, input().split()))
    
    a = [(x, y) for x, y in zip(ta, tb)]
    a.sort()
    
    cnt = [0] * (2 * n + 1)
    pr = 0
    ans = 0
    
    for i in range(n):
        if pr != a[i][0]:
            pr = a[i][0]
            
            if pr * pr > 2 * n:
                break
                
            cnt = [0] * (2 * n + 1)
            for j in range(i + 1, n):
                t = a[i][0] * a[j][0] - a[j][1]
                if t >= 0 and t <= 2 * n:
                    cnt[t] += 1
        
        ans += cnt[a[i][1]]
        
        if i + 1 < n:
            t = a[i][0] * a[i + 1][0] - a[i + 1][1]
            if t >= 0 and t <= 2 * n:
                cnt[t] -= 1
    
    print(ans)

```
 **Rate problem**Good problem 

 
[*265*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*72*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*295*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*91*](https://codeforces.com/data/like?action=like "I like this")



[1830C — Hyperregular Bracket Strings](https://codeforces.com/contest/1830/problem/C)
-------------------------------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Candidate Master Gheal")

 **Hints****Hint 1**While not necessarily a hint, this problem cannot be solved without knowing that there are Cn=1n+1(2nn) Regular Bracket Strings of length 2⋅n.

 **Hint 2**What's the answer if q=1?

 **Hint 3**What's the answer if q=2 and the two intervals partially overlap?

 **Hint 4**Based on the previous hint, we can get rid of all partially overlapping intervals. The remaining intervals will have a tree-like structure.

 **Hint 5**Finding the tree is actually unnecessary and also very difficult. 

 **Hint 6**The brackets on the positions covered by the same **subset** of intervals must form an RBS.

 **Hint 7**Hashing. Xor hashing specifically.

 **Solution**First and foremost, the number of regular bracket strings of length 2⋅n is equal to Cn=1n+1(2nn).

Secondly, for a bracket string ¯s1s2…sk, let:

 f(si)={1,if si='('−1,if si=')'  


 Δi=∑ij=1f(sj)A bracket string ¯s1s2…sk is a regular bracket string if both of the following statements are true:

 1. Δk=0
2. Δi≥0,i=¯1,k

From now on we'll call a set of indices i1<i2<…<ik a *group* if ¯si1si2…sik must be an RBS.

There are two main cases to consider, both of which can be proven with the aforementioned conditions for a string to be an RBS:

 **Case 1: Included intervals**Let's consider two intervals [l1,r1] and [l2,r2] such that l1≤l2≤r2≤r1.

The two groups formed by these intervals are:

 * [l2,r2]
* [l1,l2−1]∪[r2+1,r1]
 **Case 2: Partially overlapping intervals**Let's consider two intervals [l1,r1] and [l2,r2] such that l1<l2≤r1<r2.

The three groups formed by these two intervals are:

 * [l1,l2−1]
* [l2,r1]
* [r1+1,r2]
By taking both of these cases into account, we can conclude that all indices ik covered by the same **subset** of intervals are part of the same group.

Finding the subset of intervals which cover a certain index i can be implemented using difference arrays and xor hashing.

 **How does xor hashing on difference arrays work?**Each interval [li,ri] will be assigned a random 64-bit value vi. 

The value of a subset of intervals i1,i2,…,ik is equal to vi1∧vi2∧…∧vik.

For each interval [li,ri], diff[li]∧=vi, diff[ri+1]∧=vi.

The value of the subset of intervals which cover position i is equal to diff[1]∧diff[2]∧…∧diff[i].

Time complexity: O(maxn⋅log(mod)) for precomputing every Cn, and O(k⋅log(k)) per test case.

 **Code (Gheal, C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int NMAX=3e5+5, MOD=998244353;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX);

ll fact[NMAX], invfact[NMAX], C[NMAX];

ll binPow(ll x, ll y){
    ll ans=1;
    for(;y ;y>>=1, x = x*x%MOD)
        if(y&1)
            ans = ans*x%MOD;
    return ans;
}
map<ll,ll> diff,freq;
void add_interval(ll l, ll r){
    ll Hash = rnd(gen);
    diff[l] ^= Hash, diff[r+1] ^= Hash;
}
void tc(){
    ll n,k;
    cin>>n>>k;
    diff.clear(), freq.clear();
    add_interval(1,n); /// the initial string must be an RBS

    for(ll i=0;i<k;i++){
        ll l,r;
        cin>>l>>r;
        add_interval(l,r);
    }
    ll Hash = diff[1];

    for(map<ll,ll> :: iterator it=next(diff.begin()); it!=diff.end(); it++){
        freq[Hash] += it->first - prev(it)->first;
        Hash ^= it->second;
    }

    ll ans=1;

    for(const auto& it : freq)
        ans=ans*C[it.second]%MOD;

    cout<<ans<<'n';
}

int main()
{
    fact[0] = invfact[0] = 1;
    for(ll i=1; i<NMAX; i++){
        fact[i] = fact[i-1] * i % MOD;
        invfact[i] = binPow(fact[i], MOD - 2);
    }

    for(ll i=0; i*2<NMAX; i++) C[i*2] = fact[i*2] * invfact[i] % MOD * invfact[i+1] % MOD;

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        tc();
    return 0;
}

```
 **Rate problem**Good problem 

 
[*226*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")



[1830D — Mex Tree](https://codeforces.com/contest/1830/problem/D)
-----------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Candidate Master Gheal")

 **Hints****Hint 1**Why is bipartite coloring not always optimal?

 **Hint 2**How good is a bipartite coloring actually?

 **Solution**Disclaimer: I ( [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte") ) wanted to cut O(n√n) memory because I thought that setting 1024 MB memory limit would spoil the solution. So only blame me for this.

We will do a complementary problem which is finding the minimum loss of a coloring. The initial cost is the maximum possible cost, n⋅(n+1).

If we analyze how good a bipartite coloring of the given tree is we can note that loss≤2⋅n

Now suppose the tree has a connected component of size k. We can note that in such a coloring loss≥k⋅(k+1)2

By the 2 claims above, we can note that in an optimal coloring, the maximum size k of a connected component respects k⋅(k+1)2≤2⋅n. Thus we can safely say k≤√4⋅n.

Now let dpi,j,color be the minimum loss if we color the subtree of i and the connected component of vertex i has size j. We can calculate this in a knapsack style by adding subtrees successively. The computation takes O(n⋅√n) if we use the 7-th trick from [this](https://codeforces.com/blog/entry/100910) blog.

Now we are only left to optimize memory, since now it's O(n⋅√n). We can directly apply [this](https://codeforces.com/blog/entry/113453) to get linear memory.

However, the bound of k≤√4⋅n is overestimated, for n=200000 it can be proven that the worst case for k is 258.

 **Proof Sketch**Assume have a connected component of size k we want it to be colored 0 across all optimal colorings. Then we can attach to each node some subtrees such that after flipping its whole subtree the total cost doesn't increase. We will assume all subtrees are leaves for simplicity. Doing such, we can get some inequalities about the number of leaves we need to attatch to each node. 

In a star tree, the number of leaves we should attatch to nodes has the smallest sum.

 **Code (tibinyte, C++)**
```cpp
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int lim = 893;
const int inf = 1e16;

struct dp_state
{
    vector<int> a;
    vector<int> b;
    void init()
    {
        a.resize(lim + 1, inf);
        b.resize(lim + 1, inf);
        a[1] = 1;
        b[1] = 2;
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
        vector<vector<int>> g(n + 1);
        vector<int> sz(n + 1);

        for (int i = 1; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        function<int(int, int)> shuffle_kids = [&](int node, int parent)
        {
            int sz = 1;
            pair<int, int> best;
            for (int i = 0; i < (int)g[node].size(); ++i)
            {
                if (g[node][i] != parent)
                {
                    int sz2 = shuffle_kids(g[node][i], node);

                    best = max(best, {sz2, i});

                    sz += sz2;
                }
            }
            if (!g[node].empty())
            {
                swap(g[node][0], g[node][best.second]);
            }
            return sz;
        };
        shuffle_kids(1, 0);

        vector<vector<int>> merged(2 * lim + 1, vector<int>(2, inf));

        function<dp_state(int, int)> dfs = [&](int node, int parent)
        {
            dp_state dp;
            sz[node] = 1;
            bool hasinit = false;
            for (auto i : g[node])
            {
                if (i != parent)
                {
                    dp_state qui = dfs(i, node);
                    if (!hasinit)
                    {
                        dp.init();
                        hasinit = true;
                    }
                    for (int j = 0; j <= min(sz[node], lim) + min(sz[i], lim); ++j)
                    {
                        merged[j][0] = merged[j][1] = inf;
                    }
                    for (int k = 1; k <= min(sz[node], lim); ++k)
                    {
                        for (int l = 1; l <= min(sz[i], lim); ++l)
                        {
                            merged[k][0] = min(merged[k][0], dp.a[k] + qui.b[l]);
                            merged[k][1] = min(merged[k][1], dp.b[k] + qui.a[l]);
                            merged[k + l][0] = min(merged[k + l][0], dp.a[k] + qui.a[l] + k * l);
                            merged[k + l][1] = min(merged[k + l][1], dp.b[k] + qui.b[l] + k * l * 2);
                        }
                    }
                    sz[node] += sz[i];
                    for (int k = 1; k <= min(sz[node], lim); ++k)
                    {
                        dp.a[k] = merged[k][0];
                        dp.b[k] = merged[k][1];
                    }
                }
            }
            if (!hasinit)
            {
                dp.init();
                hasinit = true;
            }
            return dp;
        };
        dp_state dp = dfs(1, 0);
        int ans = inf;
        for (int i = 1; i <= lim; ++i)
        {
            ans = min(ans, dp.a[i]);
            ans = min(ans, dp.b[i]);
        }
        cout << n * (n + 1) - ans << 'n';
    }
}
```
 **Rate problem**Good problem 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")



[1830E — Bully Sort](https://codeforces.com/contest/1830/problem/E)
-------------------------------------------------------------------

Author: [valeriu](https://codeforces.com/profile/valeriu "Candidate Master valeriu")

Thanks to [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn") for the solution!

 **Solution**First of all, we notice that if some element moves left, it will never move right. 

 **Proof**Proving this is not hard, imagine S to be the set of suffix minimas. Then if an element is in S we know that px≤x.

Since after every bully swap an element cannot disappear from S and after each bully swap, the 2 swapped elements can only get closer to their desired position, we conclude the proof.

Obviously, if an element moves right, it will never move left since it will continue to move right until it reaches its final position.

By the 2 claims above, we conclude that left and right movers are distinct.

Now suppose we swap indicies i and j and note that such swap kills 2⋅(j−i)−1 inversions and the left mover j moves j−i steps.

Now the magic is that if we let s be the sum over 2⋅(i−pi) for all left movers we have s−ans=inversions, thus our answer is just s−inversions.

Now to handle the data structure part, we just need to be able to calculate inversions while being able to perform point updates. There are many ways to do this, for example for using a fenwick tree and a bitwise trie/ordered_set in O(nlog2n). 

 **Code (tibinyte, fenwick tree + ordered_set C++)**
```cpp
  
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;

/*               .___                 __                 __           .__
  ____  ____   __| _/____     _______/  |______ ________/  |_  ______ |  |__   ___________   ____
_/ ___/  _  / __ |/ __    /  ___/   ____  \_  __    __/  ___/ |  |  _/ __ _  __ _/ __ 
  __(  <_> ) /_/   ___/   ___   |  |  / __ |  | /|  |  ___   |   Y    ___/|  | /  ___/
 ___  >____/____ |___  > /____  > |__| (____  /__|   |__| /____  > |___|  /___  >__|    ___  >
     /           /    /       /            /                 /       /     /            /
*/

struct bit
{
  int n;
  vector<ordered_set> lesgo;
  void resize(int _n)
  {
    n = _n;
    lesgo = vector<ordered_set>(n + 1);
  }
  void update(int pos, int val, int sign)
  {
    for (int i = pos; i <= n; i += i & (-i))
    {
      if (sign == -1)
      {
        lesgo[i].erase(val);
      }
      if (sign == 1)
      {
        lesgo[i].insert(val);
      }
    }
  }
  int query_smaller(int pos, int val)
  {
    int ans = 0;
    for (int i = pos; i; i -= i & (-i))
    {
      ans += lesgo[i].order_of_key(val);
    }
    return ans;
  }
  int query_greater(int pos, int val)
  {

    int ans = 0;
    for (int i = pos; i; i -= i & (-i))
    {
      int sz = lesgo[i].size();
      ans += sz - lesgo[i].order_of_key(val + 1);
    }
    return ans;
  }
  int query_smaller(int st, int dr, int val)
  {
    return query_smaller(dr, val) - query_smaller(st - 1, val);
  }
  int query_greater(int st, int dr, int val)
  {
    return query_greater(dr, val) - query_greater(st - 1, val);
  }
};

int32_t main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }
  bit lesgo;
  lesgo.resize(n);
  for (int i = 1; i <= n; ++i)
  {
    lesgo.update(i, a[i], 1);
  }

  ll inv = 0;

  for (int i = 1; i <= n; ++i)
  {
    inv += lesgo.query_greater(1, i, a[i]);
  }

  ll sum = 0;

  for (int i = 1; i <= n; ++i)
  {
    sum += max(a[i] - i, 0);
  }

  while (q--)
  {
    int x, y;
    cin >> x >> y;
    if (x != y)
    {
      lesgo.update(x, a[x], -1);
      lesgo.update(y, a[y], -1);
      sum -= max(a[x] - x, 0);
      sum -= max(a[y] - y, 0);
      if (x + 1 <= y - 1)
      {
        int lesgo1 = lesgo.query_smaller(x + 1, y - 1, a[x]);
        int lesgo2 = lesgo.query_greater(x + 1, y - 1, a[y]);
        inv += 2 * (y - x - 1 - lesgo1 - lesgo2);
      }

      if (a[x] > a[y])
      {
        inv--;
      }
      else
      {
        inv++;
      }

      swap(a[x], a[y]);
      sum += max(a[x] - x, 0);
      sum += max(a[y] - y, 0);
      lesgo.update(x, a[x], 1);
      lesgo.update(y, a[y], 1);
    }
    cout << sum + sum - inv << 'n';
  }
}

```
 **Code (tibinyte, sqrt decomposition, C++)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int st, int dr)
{
  uniform_int_distribution<int> dist(st, dr);
  return dist(rng);
}

typedef long long ll;

/*               .___                 __                 __           .__
  ____  ____   __| _/____     _______/  |______ ________/  |_  ______ |  |__   ___________   ____
_/ ___/  _  / __ |/ __    /  ___/   ____  \_  __    __/  ___/ |  |  _/ __ _  __ _/ __ 
  __(  <_> ) /_/   ___/   ___   |  |  / __ |  | /|  |  ___   |   Y    ___/|  | /  ___/
 ___  >____/____ |___  > /____  > |__| (____  /__|   |__| /____  > |___|  /___  >__|    ___  >
     /           /    /       /            /                 /       /     /            /
*/

struct decomp
{
  vector<int> a;
  vector<pair<int, int>> buckets;
  vector<int> sp;
  vector<int> spbucket;
  vector<int> wh;
  const int sz = 400;
  void resize(int n)
  {
    a = vector<int>(n + 1);
    sp = vector<int>(n + 1);
    wh = vector<int>(n + 1);
    for (int i = 1; i <= n; i += sz)
    {
      int st = i;
      int dr = min(n, st + sz - 1);
      for (int j = st; j <= dr; ++j)
      {
        wh[j] = (int)buckets.size();
      }
      buckets.push_back({st, dr});
      spbucket.push_back(0);
    }
  }
  void update(int pos, int x)
  {
    a[pos] += x;
    int qui = wh[pos];
    sp[buckets[qui].first] = a[buckets[qui].first];
    for (int i = buckets[qui].first + 1; i <= buckets[qui].second; ++i)
    {
      sp[i] = sp[i - 1] + a[i];
    }
    spbucket[0] = sp[buckets[0].second];
    for (int i = 1; i < (int)buckets.size(); ++i)
    {
      spbucket[i] = spbucket[i - 1] + sp[buckets[i].second];
    }
  }
  int query(int pos)
  {
    int qui = wh[pos];
    int ans = sp[pos];
    if (qui)
    {
      ans += spbucket[qui - 1];
    }
    return ans;
  }
};

struct geralt
{
  vector<int> a;
  vector<decomp> lesgo;
  vector<pair<int, int>> buckets;
  vector<int> wh;
  const int sz = 3000;
  void resize(int n)
  {
    a = vector<int>(n + 1);
    wh = vector<int>(n + 1);
    for (int i = 1; i <= n; i += sz)
    {
      int st = i;
      int dr = min(n, st + sz - 1);
      for (int j = st; j <= dr; ++j)
      {
        wh[j] = (int)buckets.size();
      }
      buckets.push_back({st, dr});
      lesgo.push_back({});
      lesgo.back().resize(n);
    }
  }
  void update(int pos, int val)
  {
    int qui = wh[pos];
    if (a[pos] != 0)
    {
      lesgo[qui].update(a[pos], -1);
    }
    a[pos] = val;
    lesgo[qui].update(a[pos], 1);
  }
  int query_brute(int st, int dr, int val)
  {
    int ans = 0;
    for (int i = st; i <= dr; ++i)
    {
      if (a[i] <= val)
      {
        ans++;
      }
    }
    return ans;
  }
  int query_smaller(int st, int dr, int val) // number of values <= val in st...dr
  {
    if (wh[st] == wh[dr])
    {
      return query_brute(st, dr, val);
    }
    int qui1 = wh[st], qui2 = wh[dr];
    int ans = query_brute(st, buckets[qui1].second, val) + query_brute(buckets[qui2].first, dr, val);
    qui1++;
    qui2--;
    for (int i = qui1; i <= qui2; ++i)
    {
      ans += lesgo[i].query(val);
    }
    return ans;
  }
  int query_greater(int st, int dr, int val) // number of values > val in st...dr
  {
    return (dr - st + 1) - query_smaller(st, dr, val);
  }
};

int32_t main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }

  geralt lesgo;
  lesgo.resize(n);

  ll inv = 0;

  for (int i = 1; i <= n; ++i)
  {
    lesgo.update(i, a[i]);
    inv += lesgo.query_greater(1, i, a[i]);
  }

  ll sum = 0;

  for (int i = 1; i <= n; ++i)
  {
    sum += max(a[i] - i, 0);
  }

  while (q--)
  {
    int x, y;
    cin >> x >> y;
    if (x != y)
    {
      sum -= max(a[x] - x, 0);
      sum -= max(a[y] - y, 0);
      if (x + 1 <= y - 1)
      {
        int lesgo1 = lesgo.query_smaller(x + 1, y - 1, a[x]);
        int lesgo2 = lesgo.query_greater(x + 1, y - 1, a[y]);
        inv += 2 * (y - x - 1 - lesgo1 - lesgo2);
      }

      if (a[x] > a[y])
      {
        inv--;
      }
      else
      {
        inv++;
      }

      swap(a[x], a[y]);
      sum += max(a[x] - x, 0);
      sum += max(a[y] - y, 0);
      lesgo.update(x, a[x]);
      lesgo.update(y, a[y]);
    }
    cout << sum + sum - inv << 'n';
  }
}

```
 **Code (errorgorn, divide and conquer, C++)**
```cpp
  
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define i4 tuple<int,int,int,int>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct FEN{ //we want to count the reverse
	int arr[500005];
	
	void update(int i,int k){
		i=500005-i;
		
		while (i<500005){
			arr[i]+=k;
			i+=i&-i;
		}
	}
	
	int query(int i){
		i=500005-i;
		
		int res=0;
		while (i){
			res+=arr[i];
			i-=i&-i;
		}
		return res;
	}
} fen;

int n,q;
int arr[500005];
long long ans[50005];

void dnc(int l,int r,vector<i4> upd,vector<i4> que){
	vector<i4> updl,updr;
	vector<i4> quel,quer;
	
	int m=l+r>>1;
	
	for (auto [a,b,c,d]:upd){
		if (c<=m) updl.pub({a,b,c,d});
		else updr.pub({a,b,c,d});
	}
	
	for (auto [a,b,c,d]:que){
		if (c<=m) quel.pub({a,b,c,d});
		else quer.pub({a,b,c,d});
	}
	
	int i=0;
	for (auto it:quer){
		while (i<sz(updl) && get<0>(updl[i])<get<0>(it)){
			fen.update(get<1>(updl[i]),get<3>(updl[i]));
			i++;
		}
		
		ans[get<2>(it)]+=fen.query(get<1>(it))*get<3>(it);
	}
	while (i){
		i--;
		fen.update(get<1>(updl[i]),-get<3>(updl[i]));
	}
	
	if (l!=m) dnc(l,m,updl,quel);
	if (m+1!=r) dnc(m+1,r,updr,quer);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	vector<i4> upd,que;
	
	rep(x,1,n+1) upd.pub({x,arr[x],-1,1});
	rep(x,1,n+1) que.pub({x,arr[x],0,-1});
	rep(x,1,n+1) ans[0]+=abs(x-arr[x]);
	
	rep(x,1,q+1){
		int a,b;
		cin>>a>>b;
		
		if (a==b) continue;
		if (arr[a]<arr[b]) ans[x]--;
		else ans[x]++;
		
		upd.pub({a,arr[a],x-1,-1});
		upd.pub({b,arr[b],x-1,-1});
		ans[x]-=abs(a-arr[a])+abs(b-arr[b]);
		
		swap(arr[a],arr[b]);
		
		upd.pub({a,arr[a],x,1});
		upd.pub({b,arr[b],x,1});
		ans[x]+=abs(a-arr[a])+abs(b-arr[b]);
		
		que.pub({b,arr[b],x,-2});
		que.pub({b,arr[a],x,2});
		que.pub({a,arr[b],x,2});
		que.pub({a,arr[a],x,-2});
		
	}
	
	sort(all(upd)),sort(all(que));
	
	dnc(-1,q,upd,que);
	
	rep(x,1,q+1) ans[x]+=ans[x-1];
	rep(x,1,q+1) cout<<ans[x]<<" "; cout<<endl;
}

```
 **Rate problem**Good problem 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*0*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")



[1830F — The Third Grace](https://codeforces.com/contest/1830/problem/F)
------------------------------------------------------------------------

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Newbie tibinyte")

Thanks to [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn") for the editorial!

 **Solution**Let dpi be the maximum sum of costs of activated points that are <i over all states that has point i activated.

When we transition from dpi to dpj, we need to add the cost contributed by point i. The number of ranges where point i is the largest coordinate within it are the ranges [l,r] which satisfy l≤i≤r<j. So we have dpj=maxi<j(dpi+pi⋅Si,j) where Si,j is the number of ranges [l,r] which satisfy l≤i≤r<j. Now, we note that Si,jz

With some work, we can get calculate this dp in O(n2). But this will be too slow, let's try to speed this up.

Let us define dpi,j=maxk≤i(dpk+pk⋅Sk,j). We have dpj−1,j=dpj. Our goal is to go from (implictly) storing dpi,i+1,dpi,i+2,…,dpi,n to dpi+1,i+2,dpi+1,i+3,…,dpi+1,n. As dpi+pi⋅Si,j looks like a linear function w.r.t. Si,j, we can try to use convex hull data structures to maintain it.

Let's figure out how Si+1,j relates to Si,j. We need to subtract the number of ranges with r=i and add the number of ranges with l=i+1 and r<j. This corresponds to Si,∗ and Si+1,∗ differing by amortized O(1) suffix increment updates. Also, note that Si,∗ is non-decreasing.

So we want to support the following data structure: Initially we have an arrays A and X that are both initially 0. Handle the following updates:

 * `1 m c` Ai←max(Ai,m⋅Xi+c) for all i
* `2 j k` Xi←Xi+k for all j≤i. It is guaranteed that X will always be non-decreasing.
* `3 i` find Ai

This can be maintained in a lichao tree in O(log2) time. In each lichao node, we need to store s,m,e, the start, middle and end indices and their corresponding X values Xs,Xm,Xe respectively. This way, we can support operations 1 and 3 already.

To support operation 2, note that in a lichao tree, you can use O(log2) time to push down all lines that covers a certain point (refer to [https://codeforces.com/blog/entry/86731)](https://codeforces.com/blog/entry/86731)). This way, all lines in the li chao tree are in [1,j) or 

Unable to parse markup [type=CF_MATHJAX]

, so you can do lazy updates on both the coordinates of the lines and the X values.The time complexity is O(nlog2).

There is another solution that works in O(mlog3) that we are unable to optimize further yet. Let us flip the array so that the condition is on the activated point with the smallest coordinate. Then we have dpj=maxi<j(dpi+pj⋅Si,j) where Si,j counts the number of ranges [l,r] such that i<l≤j≤r.

Now, we want to store the linear function dpi+x⋅Si,j in some sort of data structure so that we can evaluate the maximum value with x=pj. Unfortunately, the value of Si,j can change by suffix additions, similar to above.

But since Si,j is non-increasing here, that means the optimal i that maximizes dpi+x⋅Si,j decreases when x increases. That is, for l1≤r1<l2≤r2 and we have two data structures that can get the maximum fj(x)=dpi+x⋅Si,j for lj≤i≤rj respectively. We can combine these 2 data structures to make it for [l1,r1]∪[l2,r2] by binary searching the point X where for all x≤X, f1(x)≤f2(x) and for all X≤x,f1(x)≥f2(x). Since querying this data structure takes O(logn), it takes O(log2) time to combine two such data structures. If we use a segment tree, we only need to rebuild O(log3) different data structures (the rest can be handled using lazy tags), giving us a time complexity of O(log3). 

 **Code (errorgorn, C++)**
```cpp
  
//もう布団の中から出たくない
//布団の外は寒すぎるから
//布団の中から出たくない
//布団の中はあたたかすぎるから

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const ll INF=1e18;

struct line{
	ll m,c;
	
	line (ll _m,ll _c){
		m=_m,c=_c;
	}
	
	ll get(ll x){
		return m*x+c;
	}
};

struct node{
	int s,e,m;
	int vs=0,ve=0,vm=0;
	line val={0,-INF};
	int lazy=0;
	node *l,*r;
	
	node(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy==0) return;
		
		val.c-=val.m*lazy;
		vs+=lazy;
		ve+=lazy;
		vm+=lazy;
		
		if (s!=e){
			l->lazy+=lazy;
			r->lazy+=lazy;
		}
		lazy=0;
	}
	
	void update(int i){
		if (s==i) lazy++;
		else{
			if (val.c!=-INF){
				l->propo(),r->propo();
				l->update(val),r->update(val);
				val={0,-INF};
			}
			
			if (m<i) r->update(i);
			else l->update(i),r->update(m+1);
			
			l->propo(),r->propo();
			vs=l->vs,vm=l->ve,ve=r->ve;
		}
	}
	
	void update(line i){
		bool lo=i.get(vs)>val.get(vs);
		bool mi=i.get(vm)>val.get(vm);
		bool hi=i.get(ve)>val.get(ve);
		
		if (mi) swap(i,val);
		
		if (s==e || i.c==-INF || lo==hi) return;
		
		l->propo(),r->propo();
		if (lo!=mi) l->update(i);
		else r->update(i);
	}
	
	ii query(ll i){
		propo();
		
        if (s==e) return {val.get(vs),vs};
		else if (i<=m){
			auto temp=l->query(i);
			return {max(temp.fi,val.get(temp.se)),temp.se};
		}
		else{
			auto temp=r->query(i);
			return {max(temp.fi,val.get(temp.se)),temp.se};
		}
	}
} *root;

const int maxn = 1e6;
const int maxm = 1e6;

int n,m;
ii arr[maxn+1];
ii brr[maxm+1];

int ans[maxm+1];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[x].fi>>arr[x].se;
		rep(x,1,m+1){
            cin>>brr[x].se;
            brr[x].fi = x;
        }
    
		sort(arr+1,arr+n+1);
		
		root=new node(0,m+1);
		root->update({0,0});
		
		int curr=1;
		rep(x,0,m+2){
			while (curr<=n && arr[curr].fi==x) root->update(arr[curr++].se+1);
			auto temp=root->query(x);
			root->update({brr[x].se,temp.fi-brr[x].se*temp.se});
		}
		
		cout<<root->query(m+1).fi<<endl;
	}
}

```
 **Code (valeriu, C++)**
```cpp
  
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

using ll = long long;
using ld = long double;

//#define int ll
#define sz(x) ((int)(x).size())

using pii = pair<ll,ll>;
using tii = tuple<int,int,int>;

const int nmax = 5e5 + 5, qmax = 2e6 + 5;
const ll inf = 1e18 + 5; 

struct line {
  ll m = 0, b = -inf;
  ll operator()(const ll& x) const {
     return m * x + b;
  }
  bool operator ==(const line& x) const { return m == x.m && b == x.b; }
};

int M;

namespace AINT {
  struct Node {
    int vl = 0, vmid = 0, vr = 0;
    line val = line{0, -inf};
    Node() {;}
    void operator += (const int &x) { vl += x, vmid += x, vr += x; val.b -= val.m * x; }
  } aint[qmax * 4];
  int lazy[qmax * 4];
  
  void push(int node) {
    lazy[2 * node] += lazy[node];
    aint[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    aint[2 * node + 1] += lazy[node];
    lazy[node] = 0;
  }
  void pushline(line x, int node = 1, int cl = 0, int cr = M) {
    bool l = x(aint[node].vl) > aint[node].val(aint[node].vl), m = x(aint[node].vmid) > aint[node].val(aint[node].vmid), r = x(aint[node].vr) > aint[node].val(aint[node].vr);
    if(m) swap(x, aint[node].val);
    if(cl == cr || x == line() || l == r) return;
    
    int mid = cl + cr >> 1;
    push(node);
    if(m != l) pushline(x, 2 * node, cl, mid);
    else pushline(x, 2 * node + 1, mid + 1, cr);
    return;
  }
  void add(int l, int node = 1, int cl = 0, int cr = M) {
    if(cl >= l) {
      lazy[node]++;
      aint[node] += 1;
      return;
    }
    if(cr < l) return;
    int mid = cl + cr >> 1;
    
    push(node);
    
    pushline(aint[node].val, 2 * node, cl, mid);
    pushline(aint[node].val, 2 * node + 1, mid + 1, cr);
    aint[node].val = line{0, -inf};
    
    add(l, 2 * node, cl, mid);
    add(l, 2 * node + 1, mid + 1, cr);
    aint[node].vl = aint[2 * node].vl;
    aint[node].vmid = aint[2 * node].vr;
    aint[node].vr = aint[2 * node + 1].vr;
  }
  pii query(ll p, int node = 1, int cl = 0, int cr = M) {
    if(cl == cr) return pii{aint[node].val(aint[node].vl), aint[node].vl};
    int mid = cl + cr >> 1;
    push(node);
    auto [mxv, atrv] = p <= mid? query(p, 2 * node, cl, mid) : query(p, 2 * node + 1, mid + 1, cr);
    return pii{max(mxv, aint[node].val(atrv)), atrv};
  } 
  
  void init(int node = 1, int cl = 0, int cr = M) {
    aint[node] = Node();
    lazy[node] = 0;
    if(cl == cr) return;
    int mid = cl + cr >> 1;
    init(2 * node, cl, mid);
    init(2 * node + 1, mid + 1, cr);
    return;
  }
};

vector<int> atraddp[qmax];
ll val[qmax];

void testcase() {
  int n, m;
  cin >> n >> m;
  M = m + 2;
  for(int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    atraddp[l].emplace_back(r + 1);
  }
  for(int i = 1; i <= m; i++)
    cin >> val[i];
  
  AINT::init();
  AINT::pushline({0, 0});
  
  for(int i = 0; i < m + 2; i++) {
    for(auto x : atraddp[i])
      AINT::add(x);
    auto [a, b] = AINT::query(i);
    //cerr << a << ' ' << b << 'n';
    AINT::pushline({val[i], a - val[i] * b});
  }
  
  for(int i = 0; i < m + 2; i++)
    atraddp[i].clear();
  
  cout << AINT::query(m + 1).first << 'n';
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) testcase();
  
}

/**
      Anul asta se da centroid.
-- Surse oficiale
*/



```
 **Rate problem**Good problem 

 
[*31*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*1*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")



If there is anything wrong or unclear in this editorial, feel free to ping me or any of the other authors in the comments.

