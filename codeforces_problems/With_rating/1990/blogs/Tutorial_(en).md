# Tutorial_(en)

Thank you for participation and we hope you enjoy this round :)

Additionally, we sincerely invite you to join the unofficial round of TheForces Community tomorrow. Compete alongside many high-rated participants and earn your own rating in a our own rating system([TheForces Rating System](https://codeforces.com/https://theforces.netlify.app/ratings))!

For more details, pls read <https://codeforces.com/blog/entry/131733>.

#### [A — Submission Bait](../problems/A._Submission_Bait.md)

 **hint1**For Alice, what if choosing the maximum value doesn't work?

 **hint2**Consider parity.

 **solution 1**Case 1: When all values appear an even number of times, Alice will lose. This is because no matter which number Alice chooses, Bob can mimic Alice's move.

Case 2: When at least one value appears an odd number of times, Alice will win. Alice only needs to choose the maximum value that appears an odd number of times, which will force Bob into Case 1.

Time complexity: O(n).

 **solution 2**Sort the array a in non-increasing order. We can observe that any state can be represented as a prefix of the array a. Consider dynamic programming: let dpi denote whether the first player is guaranteed to win when the state is a1...i (dpi=1 indicates a guaranteed win for the first player). We have the following formula:

 * dp1=1;
* dpi=∼(dpi−1 & dpid1−1 & dpid2−1…), where idj satisfies aidj≠aidj+1 and idj<i.

Time complexity: O(n2).

 **code(solution 1)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 55;

int n;
int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        ++q[x];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (q[i] % 2 == 1)
        {
            cout << "YESn";
            return;
        }
    }
    cout << "NOn";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}

```
#### [B — Array Craft](../problems/B._Array_Craft.md)

 **hint1**Starting from a trival construction.

 **hint2**Utilize the condition x>y.

 **solution**First, we consider making presumx>presumj for all x<i≤n, and similarly for y. We can think of a trivial construction: a[r,…,l]=[1,…,1],a[1,…...,r−1]=[−1,…,−1] and a[l+1,…,n]=[−1,…,−1].

The construction doesn't works when presumx<0, but we are close to the correct solution. Next, we will make a little adjustment: a[r,…,l]=[1,…,1],a[1,…...,r−1]=[…,1,−1] and a[l+1,…,n]=[−1,1,…].

It is not hard to see presumx≥presumj for all x<i≤n, and for 1≤i≤y, max(presumi)−min(presumi)≤1. Thus, we get presumx≥2+presumy−1≥2+min(presumi)≥1+max(presumi). The same applies to the suffix sum as well. Therefore, this construction is valid.

Time complexity: O(n).

 **Bonus**Solve the problem when x≤y.

 **code**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,x,y;
    cin >> n >> x >> y;
    x--; y--;
    vector<int> a(n,1);
    int e;
    e=-1;
    for(int i=x+1;i<n;i++){
      a[i]=e;
      e*=-1;
    }
    e=-1;
    for(int i=y-1;i>=0;i--){
      a[i]=e;
      e*=-1;
    }
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << a[i];
    }cout << "n";
  }
  return 0;
}


```
#### [C — Mad MAD Sum](../problems/C._Mad_MAD_Sum.md)

 **hint1**After one operation, the array becomes non-decreasing.

 **hint2**Consider a1=a2=…=an, the operation seems to have shifted the array right.

 **hint3**When does the "right shift" parttern happen?

 **solution**Read hints first.

Let's consider only non-decreasing arrays. Observe a continuous segments a[l...r]=x(l<r,x>0), after one operation, we get a[l+1,min(r+1,n)]=x holds. We can conclude that if, for all non-zero contiguous segments in the array (except the last one), their lengths are all greater than 1, then the array follows the "right shift" parttern. Let's say this kind of array "good".

The last problem is when will the array become "good". Let's assume we get the array b after one operation on array a, we get bi<bi+1<bi+2. We can infer that bi=ai,bi+1=ai+1 and there is at least aj=ai+1(j≤i), which shows that a is not non-decreasing. In other words, after two operations, we can always get a "good" array. Then the calculating is trival.

Time complexity: O(n).

 **code**
```cpp
  
#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N];

bool c[N];
void doit()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[a[i]])
            maxu = max(maxu, a[i]);
        c[a[i]] = true;
        a[i] = maxu;
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    doit();
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    doit();

    for (int i = 1; i <= n; ++i)
        ans += (n - i + 1) * 1LL * a[i];
    cout << ans << "n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}


```
 **fun fact**The title "Mad MAD Sum" is not only a pun on the words Mad and MAD (Maximum Appearing Duplicate), but also implies the solution to the problem :)

#### [D Grid Puzzle](../problems/D._Grid_Puzzle.md)

 **hint1**Obviously, when ai is large enough, we will definitely use operation 2 on the i-th row. What is its specific value?

 **hint2**It is 5(try to prove it). Now we can only consider ai≤4 cases.

 **hint3**From left to right, consider a greedy solution or a DP solution.

 **solution**Read hints first.

For ai≥5, we will definitely use operation 2 on the i-th row because at least three 2×2 subgrid are needed to cover it, which is not better then do three times operation 2 in the i−1,i and i+1 row.

Now we can only consider ai≤4 cases. Let's consider from left to right.

In the left most row, there are 3 cases:

 * there is no black cells Do nothing;
* there is ≤2 black cells. We can put one 2×2 subgrid greedily;
* there is >2 black cells. We just use one time operation 2 in this row(try to prove it).

We can summarize that for the i-th row, there are only three situations where it is affected by the i−1-th row:

 * it is not affected;
* the cells in the third and fourth columns have been colored white;
* the cells in the first and second columns have been colored white.

We can greedily process this process from left to right, or use DP.

Time complexity: O(n).

 **code(greedy)**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MODD 998244353

long long int bigmod(long long int a,long long int b){
    long long int ans=1,powa=a;
    while(b>0){
        if(b%2==1){
            ans*=powa;
            ans%=MOD;
        }
        powa=powa*powa;
        powa%=MOD;
        b/=2;
    }
    return ans;
}

void func(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bool b1=0,b2=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if((!b1)&&(!b2)){
            if(arr[i]==0) continue;
            ans++;
            if(arr[i]<=2) b1=1;
        }
        else if(b1){
            b1=0;
            if(arr[i]<=2) continue;
            ans++;
            if(arr[i]<=4) b2=1;
        }
        else{
            b2=0;
            if(arr[i]==0) continue;
            ans++;
            if(arr[i]<=4) b1=1;
        }
    }
    cout << ans << 'n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        func();
    }
}
//i added the bigmod func to my code cause yes
```
 **code(DP)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N];

int dp[N];
void minh(int& x, int y)
{
    x = min(x, y);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int minu[2] = {N, N};
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (a[i] == 0)
            minh(dp[i], dp[i - 1]);
        if (a[i] <= 2)
            minh(dp[i], i + minu[1 - i % 2]);

        if (a[i] <= 2)
            minh(minu[i % 2], dp[i - 1] - i);
        else if (a[i] > 4)
            minu[0] = minu[1] = N;
    }

    cout << dp[n] << "n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}


```
#### [E Catch the Mole](../problems/E2._Catch_the_Mole(Hard_Version).md)

 **hint1**Consider querying a subtree. If the jury returns 0, we can delete the entire subtree.

 **hint2**We can query any leaf node. If the jury returns 1, we are done; otherwise, the mole will move up.

 **hint3**Consider querying a subtree. If the jury returns 1, we can "drive" it out of this subtree using the method in hint2.

 **hint4**Combime the idea in hint 1 and 3.

 **solution1**Read hints first.

For easy version, we can pick a vertex v such that maxdepv−depv+1=50:

 1. if the jury returns 0, we can delete the entire subtree;
2. otherwise, make queries until it is out and answer fav(a special case is v=1); ﻿
3. if there is no such vertex, then make 100 queries and answer the root node 1.

This costs about 200 queries, which can not pass hard version. But we can optimize it.

The bottleneck is the step 2, when we drive away this mole once, we need to immediately check if it is still in the subtree v, which can be optimized. In fact, we can drive the mole 50 times and then perform a binary search on the chain from v to the root node.

Number of queries: O(2sqrt(n)+log(n))

 **solution2**Query any leaf 70 times, then delete all nodes x such that maxdepv−depv+1<=70. Then the tree can be split into ≤70 chains. Do binary search for these chains.

 **bonus**Solve the problem in 100 queries.

 **code(hard version)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())

using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using f128=__float128;

using pii=pair<int,int>;
using pll=pair<ll,ll>;

template<typename T> using vc=vector<T>;
template<typename T> using vvc=vc<vc<T>>;
template<typename T> using vvvc=vc<vvc<T>>;

using vi=vc<int>;
using vll=vc<ll>;
using vvi=vc<vi>;
using vvll=vc<vll>;

#define vv(type,name,n,...) 
    vector<vector<type>> name(n,vector<type>(__VA_ARGS__))
#define vvv(type,name,n,m,...) 
    vector<vector<vector<type>>> name(n,vector<vector<type>>(m,vector<type>(__VA_ARGS__)))

template<typename T> using min_heap=priority_queue<T,vector<T>,greater<T>>;
template<typename T> using max_heap=priority_queue<T>;

// https://trap.jp/post/1224/
#define rep1(n) for(ll i=0; i<(ll)(n); ++i)
#define rep2(i,n) for(ll i=0; i<(ll)(n); ++i)
#define rep3(i,a,b) for(ll i=(ll)(a); i<(ll)(b); ++i)
#define rep4(i,a,b,c) for(ll i=(ll)(a); i<(ll)(b); i+=(c))
#define cut4(a,b,c,d,e,...) e
#define rep(...) cut4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define per1(n) for(ll i=((ll)n)-1; i>=0; --i)
#define per2(i,n) for(ll i=((ll)n)-1; i>=0; --i)
#define per3(i,a,b) for(ll i=((ll)a)-1; i>=(ll)(b); --i)
#define per4(i,a,b,c) for(ll i=((ll)a)-1; i>=(ll)(b); i-=(c))
#define per(...) cut4(__VA_ARGS__,per4,per3,per2,per1)(__VA_ARGS__)
#define rep_subset(i,s) for(ll i=(s); i>=0; i=(i==0?-1:(i-1)&(s)))

template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}

template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

template<typename T, typename S> constexpr bool chmin(T &a, const S b){if(a>b) return a=b,true; return false;}
template<typename T, typename S> constexpr bool chmax(T &a, const S b){if(a<b) return a=b,true; return false;}

template<typename T, typename S> istream& operator >> (istream& i, pair<T,S> &p){return i >> p.first >> p.second;}
template<typename T, typename S> ostream& operator << (ostream& o, const pair<T,S> &p){return o << p.first << ' ' << p.second;}

#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

template<typename T> void print(vector<T> x){for(auto i: x) cout << i << ' ';cout << "n";}
template<typename T> void print(set<T> x){for(auto i: x) cout << i << ' ';cout << "n";}
template<typename T> void print(unordered_set<T> x){for(auto i: x) cout << i << ' ';cout << "n";}
template<typename T> void print(T && x) {cout << x << "n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

template<typename T> istream& operator >> (istream& i, vector<T> &vec){for(auto &x: vec) i >> x; return i;}

vvi read_graph(int n, int m, int base=1){
    vvi adj(n);
    for(int i=0,u,v; i<m; ++i){
        cin >> u >> v,u-=base,v-=base;
        adj[u].pb(v),adj[v].pb(u);
    }
    return adj;
}

vvi read_tree(int n, int base=1){return read_graph(n,n-1,base);}

template<typename T, typename S> pair<T,S> operator + (const pair<T,S> &a, const pair<T,S> &b){return {a.first+b.first,a.second+b.second};}

template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;

template<typename T> vector<T> operator += (vector<T> &a, int val){for(auto &i: a) i+=val; return a;}

template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}

#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

//#include<atcoder/all>
//using namespace atcoder;

//using mint=modint998244353;
//using mint=modint1000000007;

struct Tree{
    int n;
    vector<vector<int>> adj,anc;
    vector<int> par,tl,tr,dep,ord,siz,ch,head;
    Tree(int _n=0){
        n=_n;
        adj.resize(n);
    }
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void init(){
        par.resize(n),tl.resize(n),tr.resize(n),dep.resize(n),anc.resize(n),siz.resize(n),ch.resize(n),head.resize(n);
        int cur=-1,m=0;
        while((1<<m)<=n) m++;
        for(int i=0; i<n; ++i) anc[i].resize(m),ch[i]=-1;
        auto dfs1=[&](auto &self, int u, int fa) -> void{
            par[u]=fa;
            siz[u]=1;
            for(int v: adj[u]) if(v!=fa) self(self,v,u),siz[u]+=siz[v];
            for(int v: adj[u]) if(v!=fa&&(ch[u]==-1||siz[v]>siz[ch[u]])) ch[u]=v;
        };
        auto dfs2=[&](auto &self, int u, int fa) -> void{
            ord.push_back(u);
            tl[u]=++cur;
            anc[u][0]=fa;
            if(fa==-1) dep[u]=0;
            else dep[u]=dep[fa]+1;
            for(int i=1; i<m; ++i){
                if(anc[u][i-1]==-1) anc[u][i]=-1;
                else anc[u][i]=anc[anc[u][i-1]][i-1];
            }
            if(ch[u]!=-1) self(self,ch[u],u);
            for(int v: adj[u]) if(v!=fa&&v!=ch[u]) self(self,v,u);
            tr[u]=cur;
        };
        dfs1(dfs1,0,-1);
        dfs2(dfs2,0,-1);
        head[0]=0;
        for(int u: ord){
            for(int v: adj[u]) if(v!=par[u]){
                if(v==ch[u]) head[v]=head[u];
                else head[v]=v;
            }
        }
    }
    bool is_anc(int u, int v){return tl[u]<=tl[v]&&tr[u]>=tr[v];}
    int get_anc(int u, int x){
        for(int i=anc[0].size()-1; i>=0; --i) if(u!=-1&&(x>>i&1)) u=anc[u][i];
        return u;
    }
    int lca(int u, int v){
        if(is_anc(u,v)) return u;
        for(int i=anc[0].size()-1; i>=0; --i) if(anc[u][i]!=-1&&!is_anc(anc[u][i],v)) u=anc[u][i];
        return par[u];
    }
};

void ahcorz(){
    int lft=150;
    auto query=[&](int u){
        assert(lft>0);
        cout << "? " << u+1 << endl;
        lft--;
        int res; cin >> res; return res;
    };
    int n; cin >> n;
    Tree tree(n);
    rep(n-1){
        int u,v; cin >> u >> v; u--,v--;
        tree.add_edge(u,v);
    }
    tree.init();
    vi vis(n);
    auto fill_vis=[&](auto &self, int u){
        if(vis[u]) return;
        vis[u]=1;
        for(int v: tree.adj[u]) if(v!=tree.par[u]) self(self,v);
    };
    vi ord(n); iota(all(ord),0);
    sort(all(ord),[&](int i, int j){return tree.dep[i]<tree.dep[j];});
    per(n){
        int u=ord[i];
        if(vis[u]) continue;
        int v=u;
        rep(_,(lft-1)/2-1){
            if(v==0) break;
            v=tree.par[v];
        }
        if(!query(v)){
            fill_vis(fill_vis,v);
            continue;
        }
        int x=tree.ord.back();
        int m=tree.dep[u]-tree.dep[v]+1;
        rep(_,m){
            if(query(x)){
                cout << "! " << x+1 << endl;
                return;
            }
            if(!query(v)){
                int y=tree.par[v];
                if(y!=-1) y=tree.par[y];
                if(y==-1) y=0;
                cout << "! " << y+1 << endl;
                return;
            }
        }
        cout << "! 1" << endl;
        return;
    }
    assert(0);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(20);
    int t=1;
    cin >> t;
    while(t--) ahcorz();
}
```
#### [F Polygonal Segments](../problems/F._Polygonal_Segments.md)

 **solution1**Consider using a segment tree to solve this problem. We need to merge the information of two intervals. First, we take the maximum value of the answers in the two intervals, and then calculate the polygon segment spanning the two intervals.

We notice that a local maximal polygon segment [l,r] must satisfy min(al−1,ar+1)>=2(al+...+ar)(or l=1,r=n). 

Define the suffix [i,r] of the interval [l,r] as a **special suffix** if and only if ai+…+ar ≤2⋅ai. The same principle applies to special prefixes. 

We can observe that there are at most O(log(maxa)) special suffixes, because the sum of one special suffix is at least twice the sum of the previous special suffix. Therefore, we can merge the special suffixes of the left interval and the special prefixes of the right interval (using the two-pointer algorithm) to obtain the answer spanning the two intervals.

Number of queries: O(nlog2(n))

 **solution2**Consider the following process:

 
```cpp
query(l,r)
    if r-l+1<3 return -1
    mxp=getmaxpos(l,r)
    if 2*a[mxp]<getsum(l,r) return r-l+1
    else return max(query(l,mxp-1),query(mxp+1,r))
```
This looks O(n2) when a=[1,2,1,4,1,2,1,8,1,2,1,4,1,2,1,16,...]. However, if we store all the ranges which are already calculated, it becomes O(nlogn).

Why? Let's call a range [l,r] "key range" when sum(a[l...r])<=2min(a[l−1],a[r+1]). We can see:

1.There're only O(nlogn) different key ranges;

2.We only visit at most 2 ranges which are not key range in each query.

Assume we have changed ap. We need to clear all the answer of key ranges which pass through p. We can use [interval tree](https://codeforces.com/https://en.wikipedia.org/wiki/Interval_tree) to achieve it.

 **code(solution 1)**
```cpp
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
typedef double db; 
typedef long long ll;
typedef unsigned long long ull;
const int N=1000010;
const int LOGN=28;
const ll  TMD=0;
const ll  INF=2147483647;
int T,n,q;
ll  a[N];

//---------------------------------------------------------- 

struct INFO
{
	int ans,l,r;
	ll  sum;
	vector<int> lpos,rpos;
	vector<ll>  lsum,rsum;
};

struct nod
{
	INFO info;
	nod  *lc,*rc;
};

struct Segtree
{
	nod *root;
	
	Segtree() 
	{
		build(&root,1,n);
	}
	
	void newnod(nod **p,int l,int r)
	{
		*p=new nod;
		(*p)->info.l=l;
		(*p)->info.r=r;
		(*p)->info.sum=(*p)->info.ans=0;
		(*p)->lc=(*p)->rc=NULL;
	}
	
	INFO merge_info(INFO x,INFO y)
	{
		INFO z;
		z.l=x.l;
		z.r=y.r;
		z.sum=x.sum+y.sum;
		z.ans=max(x.ans,y.ans);
		int px=(int)x.lpos.size()-1,py=0;
		ll  mx=0;
		//
		//return z;
		//
		//
		while(1) //two pointer
		{
			int len=0;
			ll  sum=0;
			if(px<0) 
			{
			    sum+=x.sum;
			    len+=(x.r-x.l+1);
			}
			else     
			{
			    sum+=x.lsum[px]-a[x.lpos[px]];
				len+=(x.r-x.lpos[px]);
			}
			if(py<y.rpos.size()) 
			{
			    sum+=y.rsum[py]-a[y.rpos[py]];
				len+=(y.rpos[py]-y.l);
			}
			else
			{
			    sum+=y.sum;
			    len+=(y.r-y.l+1);
			}
			if(sum>2*mx) z.ans=max(z.ans,len);
			if(px<0&&py>=y.rpos.size()) break;
			else if(px<0) mx=max(mx,a[y.rpos[py]]),py++;
			else if(py>=y.rpos.size()) mx=max(mx,a[x.lpos[px]]),px--;
			else if(a[x.lpos[px]]<a[y.rpos[py]]) mx=max(mx,a[x.lpos[px]]),px--;
			else mx=max(mx,a[y.rpos[py]]),py++;
		}
		//
		/*
		z.lpos.resize(1);
		z.rpos.resize(1);
		z.lsum.resize(1);
		z.rsum.resize(1);
		*/
		//
		if(z.ans<3) z.ans=-1;
		for(int i=0;i<x.lpos.size();i++)
		    if(2*a[x.lpos[i]]>=x.lsum[i]+y.sum) z.lpos.push_back(x.lpos[i]),z.lsum.push_back(x.lsum[i]+y.sum);
        for(int i=0;i<y.lpos.size();i++) 
		    z.lpos.push_back(y.lpos[i]),z.lsum.push_back(y.lsum[i]);
		for(int i=0;i<x.rpos.size();i++)
		    z.rpos.push_back(x.rpos[i]),z.rsum.push_back(x.rsum[i]);
        for(int i=0;i<y.rpos.size();i++) 
		    if(2*a[y.rpos[i]]>=y.rsum[i]+x.sum) z.rpos.push_back(y.rpos[i]),z.rsum.push_back(y.rsum[i]+x.sum);
		//
		return z;
	}
	
	void build(nod **p,int L,int R)
	{
		newnod(p,L,R);
		if(L==R)
		{
			(*p)->info.sum=a[L];
			(*p)->info.ans=-1;
			(*p)->info.lpos.push_back(L);
			(*p)->info.rpos.push_back(L);
			(*p)->info.lsum.push_back(a[L]);
			(*p)->info.rsum.push_back(a[L]);
			return ;
		}
		int M=(L+R)>>1;
		build(&(*p)->lc,L,M);
		build(&(*p)->rc,M+1,R);
		(*p)->info=merge_info((*p)->lc->info,(*p)->rc->info);
	}
	
	void modify(int pos,ll val)
	{
		_modify(root,pos,val);
	}
	
	void _modify(nod *p,int pos,ll val)
	{
		if(p->info.l==p->info.r)
		{
			p->info.sum=val;
			p->info.lpos[0]=pos;
			p->info.rpos[0]=pos;
			p->info.lsum[0]=val;
			p->info.rsum[0]=val;
			return ;
		}
		int M=(p->info.l+p->info.r)>>1;
		if(pos<=M) _modify(p->lc,pos,val);
		else       _modify(p->rc,pos,val);
		p->info=merge_info(p->lc->info,p->rc->info);
	}
	
	ll getans(int L,int R)
	{
		return _getans(root,L,R).ans;
	}
	
	INFO _getans(nod *p,int L,int R)
	{
		if(p->info.l==L&&p->info.r==R) return p->info;
		int M=(p->info.l+p->info.r)>>1;
		if(R<=M)     return _getans(p->lc,L,R);
		else if(L>M) return _getans(p->rc,L,R);
		else return merge_info(_getans(p->lc,L,M),_getans(p->rc,M+1,R));
	}
};

//---------------------------------------------------------- 


int main()
{
	//freopen("test.in","r",stdin);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
		Segtree TR;
		for(int i=1;i<=q;i++)
		{
			int t;
			scanf("%d",&t);
			if(t==1)
			{
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%I64dn",TR.getans(l,r));
			}
			else
			{
				int p;
				ll  x;
				scanf("%d%I64d",&p,&x);
				a[p]=x;
				TR.modify(p,x);
			}
		}
	}
	
	//fclose(stdin);
	return 0;
}

```
 **code(solution 2)**
```cpp
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

/**
 * Point-update Segment Tree
 * Source: kactl
 * Description: Iterative point-update segment tree, ranges are half-open i.e [L, R).
 *              f is any associative function.
 * Time: O(logn) update/query
 */

template<class T, T unit = T()>
struct SegTree {
	T f(T a, T b) {
        a[0] += b[0];
        if (a[1] < b[1]) a[1] = b[1], a[2] = b[2];
        return a;
    }
	vector<T> s; int n;
	SegTree(int _n = 0, T def = unit) : s(2*_n, def), n(_n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

#include <ext/pb_ds/assoc_container.hpp>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        map<ll, int> cache;

        struct Node {
            int L, R, M; // [L, R)
            set<array<int, 2>> by_l, by_r;
            void ins(int l, int r) {
                by_l.insert({l, r});
                by_r.insert({r, l});
            }
            void del(int l, int r) {
                by_l.erase({l, r});
                by_r.erase({r, l});
            }
        };
        vector<Node> ITree(4*n);
        auto build = [&] (const auto &self, int node, int l, int r) -> void {
            int mid = (l + r)/2;
            ITree[node].L = l;
            ITree[node].R = r;
            ITree[node].M = mid;
            if (l+1 == r) return;
            self(self, 2*node + 1, l, mid);
            self(self, 2*node + 2, mid, r);
        };
        build(build, 0, 0, n);
        auto insert = [&] (const auto &self, int node, int l, int r) -> void { // Insert interval [l, r) into the tree
            if (ITree[node].L+1 == ITree[node].R) {
                ITree[node].ins(l, r);
                return;
            }

            if (l >= ITree[node].M) self(self, 2*node+2, l, r);
            else if (r <= ITree[node].M) self(self, 2*node+1, l, r);
            else ITree[node].ins(l, r);
        };
        auto erase = [&] (const auto &self, int node, int x) -> void { // Delete all intervals covering point x
            if (x < ITree[node].M) {
                // Delete some prefix
                auto &st = ITree[node].by_l;
                while (!st.empty()) {
                    auto [l, r] = *begin(st);
                    if (l <= x) {
                        ITree[node].del(l, r);
                        ll id = 1ll*(n+1)*l + r;
                        cache.erase(id);
                    }
                    else break;
                }
            }
            else {
                // Delete some suffix
                auto &st = ITree[node].by_r;
                while (!st.empty()) {
                    auto [r, l] = *rbegin(st);
                    if (r > x) {
                        ITree[node].del(l, r);
                        ll id = 1ll*(n+1)*l + r;
                        cache.erase(id);
                    }
                    else break;
                }
            }

            if (ITree[node].L+1 == ITree[node].R) return;
            if (x < ITree[node].M) self(self, 2*node+1, x);
            else self(self, 2*node+2, x);
        };

        constexpr array<ll, 3> unit = {0, 0, -1};
        SegTree<array<ll, 3>, unit> seg(n);
        for (int i = 0; i < n; ++i) seg.update(i, array<ll, 3>{a[i], a[i], i});
        
        auto solve = [&] (const auto &self, int L, int R) -> int {
            if (R-L <= 2) return -1;
            ll id = 1ll*L*(n+1) + R;
            if (cache.find(id) != cache.end()) return cache[id];
            
            auto [sm, mx, pivot] = seg.query(L, R);

            insert(insert, 0, L, R);
            if (mx < sm - mx) {
                return cache[id] = R-L;
            }
            else {
                int ret = self(self, L, pivot);
                ret = max(ret, self(self, pivot+1, R));
                return cache[id] = ret;
            }
        };

        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int l, r; cin >> l >> r;
                cout << solve(solve, l-1, r) << 'n';
            }
            else {
                ll pos, val; cin >> pos >> val; --pos;

                erase(erase, 0, pos);
                if (pos) erase(erase, 0, pos-1);
                if (pos+1 < n) erase(erase, 0, pos+1);
                seg.update(pos, array<ll, 3>{val, val, pos});
            }
        }
    }
}
```
