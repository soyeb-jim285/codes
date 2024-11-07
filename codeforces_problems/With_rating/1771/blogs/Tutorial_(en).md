# Tutorial_(en)

We apologize for the delay in editorial of the tasks.

[A. Hossam and Combinatorics](../problems/A._Hossam_and_Combinatorics.md)

Idea: [_HossamYehia_](https://codeforces.com/profile/_HossamYehia_ "Expert _HossamYehia_")

 **Tutorial**
### [1771A - Hossam and Combinatorics](../problems/A._Hossam_and_Combinatorics.md "Codeforces Round 837 (Div. 2)")

Firstly, let's find max1≤p,q≤n|ap−aq|=max(a)−min(a)

if it's equal to zero, then any pair is valid, so answer if n⋅(n−1)

Otherwise, let's calculate count_min and count_max. Answer is 2⋅count_min⋅count_max

 **Solution(_HossamYehia_)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0 ; i < n ; ++i)
            scanf("%d", a + i);
    
        sort(a, a + n);
    
        if(a[0] == a[n - 1]){
            printf("%lldn", (1LL * n * (n - 1LL)));
            continue;
        }
    
        int mn = 0, mx = n - 1;
    
        while(a[0] == a[mn])
            ++mn;
    
        while(a[n - 1] == a[mx])
            --mx;
    
        long long l = mn;
        long long r = n - mx - 1;
    
    
        printf("%lldn", 2LL * l * r);
    }
}

```
[B. Hossam and Friends](../problems/B._Hossam_and_Friends.md)

Idea: [_HossamYehia_](https://codeforces.com/profile/_HossamYehia_ "Expert _HossamYehia_")

 **Tutorial**
### [1771B - Hossam and Friends](../problems/B._Hossam_and_Friends.md "Codeforces Round 837 (Div. 2)")

Just ai<bi in non-friends pairs. Let's calculate ri= minimum non-friend for all people. So, we can't start subsegment in ai and finish it righter ri.

Let's process people from right to left and calculate the rightmost positions there subsegment can end. Initially, R=n−1. Then we go to ai just do R=min(R,ri) and add R−i+1 to answer.

 **Solution(_HossamYehia_)**
```cpp
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5;

int n, m;
int mn[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1 ; i <= n ; ++i)
            mn[i] = n;
    
        for(int i = 0 ; i < m ; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            
            if(x > y)
                swap(x, y);
                
            mn[x] = min(mn[x], y - 1);
        }
    
        for(int i = n - 1 ; i ; --i)
            mn[i] = min(mn[i], mn[i + 1]);
    
        ll ans = n;
        for(int i = 0 ; i < n ; ++i)
            ans += (mn[i] - i);
    
        printf("%lldn", ans);
    }
}

```
[C. Hossam and Trainees](../problems/C._Hossam_and_Trainees.md)

Idea: [_HossamYehia_](https://codeforces.com/profile/_HossamYehia_ "Expert _HossamYehia_")

 **Tutorial**
### [1771C - Hossam and Trainees](../problems/C._Hossam_and_Trainees.md "Codeforces Round 837 (Div. 2)")

If exists x≥2 such that ai divides x and aj divides x then exists prime number p such that ai and aj divides p. We can choose p= any prime divisor of x.

So, let's factorize all numbers and check, if two of them divides one prime number. We can use default factorization, and it will be O(n⋅√A). It's too long, so just calculate prime numbers ≤√A and check if ai divides this numbers. It will be O(n⋅√AlogA) - fast enouth.

 **Solution(_HossamYehia_)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2 * N + 5;

bool vis[N], ans;

void Sieve(){
    memset(vis, true, sizeof(vis));
    
    vis[0] = vis[1] = false;
    for(int i = 4 ; i < N ; i += 2)
        vis[i] = false;
    for(int i = 3 ; i < N / i ; i += 2){
        if(!vis[i])continue;
        for(int j = i * i ; j < N ; j += i + i)
            vis[j] = false;
    }
}

int in[N], vid;
vector<int> primes;

void Gen(){
    for(int i = 2 ; i < N ; ++i)
        if(vis[i])
            primes.emplace_back(i);
}

set<int> st;

void check(int x){
    if(in[x] == vid){
        ans = true;
        return;
    }

    in[x] = vid;
}

void fact(int x){

    if(x < N && vis[x] == true){
        check(x);
        return;
    }

    int idx = 0, sz = primes.size();

    while(x > 1 && idx < sz && x / primes[idx] >= primes[idx]){

        if(x % primes[idx] == 0){
            check(primes[idx]);
            while(x % primes[idx] == 0)x /= primes[idx];
        }

        ++idx;
    }

    if(x > 1){
        if(x < N)
            return check(x), void();

        if(st.find(x) != st.end()){
            ans = true;
            return;
        }

        st.emplace(x);
    }
}

void pre(){
    ++vid;
    st.clear();
}

int main(){
    Sieve();
    Gen();

    int t;
    scanf("%d", &t);
    while(t--){
        pre();
        
        int n;
        scanf("%d", &n);
        
        ans = false;
        
        while(n--){
            int x;
            scanf("%d", &x);
            fact(x);
        }
        
        puts(ans ? "YES" : "NO");
    }
    
}
```
[D. Hossam and (sub-)palindromic tree](../problems/D._Hossam_and_(sub-)palindromic_tree.md)

Idea: [4qqqq](https://codeforces.com/profile/4qqqq "Candidate Master 4qqqq")

 **Tutorial**
### [1771D - Hossam and (sub-)palindromic tree](../problems/D._Hossam_and_(sub-)palindromic_tree.md "Codeforces Round 837 (Div. 2)")

Let's use dynamic programming method. Let dpv,u as length of the longest maximal sub-palindrome on the path between vertexes v and u. Then the answer to the problem is max1≤v,u≤ndpv,u.

Define gov,u (v≠u) vertex x such that it is on way between v and u and distance between v and x is 1. If v=u, then we put gov,u equal to v.

So, there are three cases:

1. The answer for (v,u) equals to the answer for (gov,u,u);
2. The answer for (v,u) equals to the answer for (v,gou,v);
3. If sv=su, then the answer for (v,u) equals to the answer for (gov,u,gou,v)+2. In this case we took best sub-palindrome strictly inside the path v,u and added to it two same symbols in v and u.

Formally , the transitions in dynamics will look like this:

dpv,u:=max(dpv,gou,v,dpgov,u,u,dpgov,u,gou,v+2⋅(sv=su)).

Dynamic's base: dpv,v:=1, dpv,w:=1+(sv=sw), for v,w, such that distance between them equals to one.

In order to calculate the values in dp, you need to iterate through pairs of vertices in ascending order of the distance between the vertices in the pair (note that this can be done by counting sort).

The question remains: how to calculate the array go? Let's iterate all vertexes and let the current vertex is v. Let v be the root of the tree. Consider all sons of this vertex. Let current son is x. Then for all u from subtree of x the value of gov,u will be number of x.

Thus, time and memory complexity of this solution is O(n2).

 **Solution(4qqqq)**
```cpp
#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<vector<int>> &go, vector<vector<pair<int, int>>> &kek, int s, int t = -1, int p = -1, int len = 0){
    if(len == 1)
        t = v;

    if(len > 1)
        go[s][v] = t;

    kek[len].push_back({s, v});

    for(int u : g[v])
        if(u != p)
            dfs(u, g, go, kek, s, t, v, len + 1);
}

void Solve(){
    int n; cin >> n;
    string a; cin >> a;

    vector<vector<int>> g(n);
    vector<vector<int>> go(n, vector<int>(n));
    vector<vector<pair<int, int>>> kek(n);
    vector<vector<int>> dp(n, vector<int>(n));

    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }

    for(int v = 0; v < n; v++)
        dfs(v, g, go, kek, v);

    for(int len = 0; len < n; len++){
        for(auto p : kek[len]){
            int v = p.first;
            int u = p.second;

            if(len == 0){
                dp[v][u] = 1;
            }else if(len == 1){
                dp[v][u] = 1 + (a[v] == a[u]);
            }else{
                int x = dp[v][go[u][v]];
                int y = dp[go[v][u]][u];
                int z = dp[go[v][u]][go[u][v]] + ((a[v] == a[u]) << 1);
                dp[v][u] = max({x, y, z});
            }
        }
    }

    int ans = 0;

    for(int v = 0; v < n; v++)
        for(int u = 0; u < n; u++)
            ans = max(ans, dp[v][u]);

    cout << ans << 'n';
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    cin >> test;
 
    for(int i = 1; i <= test; i++)
        Solve();
}
```
[E. Hossam and a Letter](../problems/E._Hossam_and_a_Letter.md)

Idea: [_HossamYehia_](https://codeforces.com/profile/_HossamYehia_ "Expert _HossamYehia_")

 **Tutorial**
### [1771E - Hossam and a Letter](../problems/E._Hossam_and_a_Letter.md "Codeforces Round 837 (Div. 2)")

Let's preprocess the following data for each cell.

1. first medium cell above current cell. 2. first medium cell below current cell. 3. first bad cell above current cell. 4. first bad cell below current cell.

Then we will try to solve the problem for each row (i), and 2 columns (j, k).

Now we have a horizontal line in row (i), and we can calculate the length of vertical line by the following.

There is two cases:

In case of the horizontal line contains one letter 'm'.

For each column (j, k): get first cell above it the don't contain ('#' or 'm') and first cell below it the don't contain ('#' or 'm').

In case of the horizontal line doesn't contain any letter 'm'.

We will try to get the 4 cells as it contains letter 'm', but in this case we will 4 trials.

for each cell from the 4 cells, we allow to have only one letter 'm' in that line.

After getting above cells and below cells for each line. the starting cell will be the maximum between the two above cells, and the ending cell will be the minimum between the two below cells.

Then we need to check that starting cell is above the current row (i) to avoid making letter n instead of H

And check that ending cell is below the current row (i) to avoid making letter u instead of H.

Since n, m has the same maximum limit 400.

Thus, time complexity of this solution is O(n3).

 **Solution(_HossamYehia_)**
```cpp
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const int N = 4e2 + 5;

int n, m;
char a[N][N];

int upM[N][N];
int upB[N][N];

int downM[N][N];
int downB[N][N];

int _get(int I, int j, int incI, char ch){
    int i = I + incI;

    while(i >= 0 && i < n){
        if(a[i][j] == '#')
            break;

        if(a[i][j] == ch)
            break;

        i += incI;
    }

    return i;
}

int _getCount(int i, int j){
    if(a[i][j] == 'm')
        return 1;

    return (a[i][j] == '.' ? 0 : 10);
}

/**

1  2    4  8
UL DL   UR DR

*/


int getU(int i, int j, int bt){
    if(!bt)
        return max(upM[i][j], upB[i][j]) + 1;

    int cur = upM[i][j];

    if(cur == -1 || a[cur][j] == '#')
        return cur + 1;

    cur = upM[cur][j];

    return cur + 1;
}


int getD(int i, int j, int bt){
    if(!bt)
        return min(downM[i][j], downB[i][j]) &mdash; 1;

    int cur = downM[i][j];

    if(cur == n || a[cur][j] == '#')
        return cur - 1;

    cur = downM[cur][j];

    return cur - 1;
}


int solve(int i, int l, int r, int msk){
    int upL = getU(i, l, (msk & 1));
    int downL = getD(i, l, (msk & 2));


    int upR = getU(i, r, (msk & 4));
    int downR = getD(i, r, (msk & 8));


    int up = max(upL, upR);
    int down = min(downL, downR);

    if(up < i && down > i)
        return  2 * (down - up + 1) + (r - l - 1);
    
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; ++i)
        scanf("%s", a + i);

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(a[i][j] == '#')
                continue;

            upM[i][j] = _get(i, j, -1, 'm');
            upB[i][j] = _get(i, j, -1, '#');

            downM[i][j] = _get(i, j, 1, 'm');
            downB[i][j] = _get(i, j, 1, '#');
        }
    }

    int mx = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j + 2 < m ; ++j){

            int cnt = _getCount(i, j) + _getCount(i, j + 1);
            for(int k = j + 2 ; k < m ; ++k){
                if((cnt += _getCount(i, k)) > 1)
                    break;

                mx = max(mx, solve(i, j, k, 0));

                if(cnt == 1)
                    continue;

                mx = max(mx, solve(i, j, k, 1));
                mx = max(mx, solve(i, j, k, 2));
                mx = max(mx, solve(i, j, k, 4));
                mx = max(mx, solve(i, j, k, 8));
            }

        }
    }

    printf("%dn", mx);
}
```
[F. Hossam and Range Minimum Query](../problems/F._Hossam_and_Range_Minimum_Query.md)

Idea: [4qqqq](https://codeforces.com/profile/4qqqq "Candidate Master 4qqqq")

 **Tutorial**
### [1771F - Hossam and Range Minimum Query](../problems/F._Hossam_and_Range_Minimum_Query.md "Codeforces Round 837 (Div. 2)")

Note that we were asked to solve the problem in online mode. If this were not the case, then the Mo Algorithm could be used.

How to solve this task in online mode? Consider two ways.

The first way is as follows. Let's build a persistent bitwise trie T on a given array, where the i-th version of the trie will store numbers x such that x occurs on the subsegment a[1…i] an odd number of times.

This can be done as follows. Let T0 be an empty trie, and Ti will be obtained as follows: first we assign Ti=Ti−1; then, if ai occurs in Ti−1, then we will erase the number ai from Ti, otherwise we will insert it there.

Suppose we need to get answer on the query [l,r]. Note that if x is included in Tr, but is not included in Tl−1 (or is included in Tl−1, but is not included in Tr), then this means that the number x on the segment a[l…r] occurs an odd number of times. Otherwise, the number x occurs an even number of times (recall that 0 is an even number). Thus, we need to find a minimum number x such that it occurs either in Tl−1 or in Tr, but not in both at once. If there is no such number, then you need to output 0.

Let's go down Tl−1 and Tr in parallel on the same prefix of the number. If Tl−1 and Tr are equal, then the same numbers are contained there, and then the answer is 0. Next, we will assume that the answer is not 0. The left subtree of the vertex is the son to whom the transition along the edge of 0 is going, and the right subtree is the vertex to which the transition along the edge of 1 is going. Let us now stand at the vertices v and u, respectively. If the left subtrees of v and u are equal, it means that the same numbers are contained there, so there is no point in going there, so we go along the right edge. Otherwise, the left subtree of v contains at least one number that is not in the left subtree of u (or vice versa), so we will go down the left edge. The number in which we ended up will be the answer.

Note that in order to compare two subtrees for equality, you need to use the hashing technique of root trees. Then we can compare the two subtree for O(1).

Thus, we get the asymptotics O((n+q)logmax(a)). If we compress the numbers of the sequence a in advance, then we can get the asymptotics of O((n+q)logn).

Let's consider the second way. Let's compress the numbers in the sequence a in advance. Let prefij=0 if the prefix i contains the number aj an even number of times, and prefij=1 if the prefix i contains the number aj an odd number of times.

Then, in order to get an answer to the query [l…r], we need to take the "bitwise exclusive OR" arrays prefl−1 and prefr and find in it the minimum j such that prefij=1. The number j will be the answer.

Obviously, now this solution need much time and memory.

In order to optimize the amount of memory consumed, we will use bitsets. However, even in this case, we consume memory of the order of o(h2/64), which is still a lot. So let's not remember about all prefi, but only some. For example, let's get some constant k and remeber only about pref0,prefk,pref2k,\dataprefpk.

Then, when we need to answer the next query [l…r], we will find the right block on which we store almost all the numbers we are looking for, and then we will insert/erase for O(k) missing numbers.

If you select k∼√n, then this solution will fit in memory. However, if you use std::bitset<> in C++, then most likely this solution will still receive the verdict Time Limit. Therefore, to solve this problem, you need to write your own fast bitset.

The asymptotics of such a solution would be O(n(n+q)/64). However, due to a well-chosen k and a self-written bitset, the constant in this solution will be very small and under given constraints, such a solution can work even faster than the first one.

 **Solution(4qqqq, trie)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int p1 = 31;
const int p2 = 53;

unsigned long long pow1[32];
unsigned long long pow2[32];

struct Node{
    unsigned long long hsh = 0;
    Node *l = 0, *r = 0;
    bool was = false;
};

const int max_memory = 13e7;

int pos_memory = 0;
char memory[max_memory];
 
void* operator new(size_t n) {
    char *res = memory + pos_memory;
    pos_memory += n;
    assert(pos_memory <= max_memory);
    return (void*) res;
}
 
void operator delete(void *){}

Node * upd(Node *v, unsigned long long x, int i = 18){
    if(i == -1){
        Node *u = new Node();

        if(!v || v && !v->was){
            u->hsh = ((int(1e9) + 345) ^ x) * (3 * x + 654);
            u->was = true;
        }

        return u;
    }

    if(x & (1 << i)){
        Node *res = new Node();
        res->l = (v ? v->l : 0);
        res->r = upd((v ? v->r : 0), x, i - 1);
        unsigned long long a = (res->l ? res->l->hsh * pow1[i + 1] : 0);
        unsigned long long b = (res->r ? res->r->hsh * pow2[i + 1] : 0);
        res->hsh = a + b;
        return res;
    }else{
        Node *res = new Node();
        res->l = upd((v ? v->l : 0), x, i - 1);
        res->r = (v ? v->r : 0);
        unsigned long long a = (res->l ? res->l->hsh * pow1[i + 1] : 0);
        unsigned long long b = (res->r ? res->r->hsh * pow2[i + 1] : 0);
        res->hsh = a + b;
        return res;
    }
}

int get(Node *l, Node *r, int i = 18, int now = 0){
    if((l ? l->hsh : 0) == (r ? r->hsh : 0))
        return -1;

    if(i == -1)
        return now;

    if((l && l->l ? l->l->hsh : 0) == (r && r->l ? r->l->hsh : 0))
        return get((l ? l->r : 0), (r ? r->r : 0), i - 1, now + (1 << i));

    return get((l ? l->l : 0), (r ? r->l : 0), i - 1, now);
}

void Solve(){
    pow1[0] = 1;
    pow2[0] = 1;

    for(int i = 1; i <= 31; i++){
        pow1[i] = p1 * pow1[i - 1];
        pow2[i] = p2 * pow2[i - 1];
    }

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> mp(n + 1);

    {
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());
        map<int, int> kek;
        int now = 0;

        for(int i = 0; i < n; i++){
            if(a[i].first != (i ? a[i - 1].first : -1))
                now++;

            kek[a[i].first] = now;
        }

        sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y){ return x.second < y.second; });

        for(int i = 0; i < n; i++){
            int x = kek[a[i].first];
            mp[x] = a[i].first;
            a[i].first = x;
        }
    }

    vector<Node *> t(n + 1);

    t[0] = new Node();

    for(int i = 1; i <= n; i++){
        int x = a[i - 1].first;
        t[i] = upd(t[i - 1], x);
    }

    int q; cin >> q;
    
    int last = 0;

    while(q--){
        int a, b;
        cin >> a >> b;

        int l = (last ^ a);
        int r = (last ^ b);

        int kek = get(t[l - 1], t[r]);
        int ans = (kek != -1 ? mp[kek] : 0);
        cout << ans << 'n';
        last = ans;
    }
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
}
```
 **Solution(Aleks5d, bitset)**
```cpp
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unroll-all-loops")
#pragma GCC optimize("O3")
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
//#define _FORTIFY_SOURCE 0 
#pragma GCC optimize("no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native") 

#include<bits/stdc++.h>
#include <x86intrin.h>

using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using pdd = std::pair<dd, dd>;
using pld = std::pair<ldd, ldd>;

namespace fast {
    template<typename T>
    T gcd(T a, T b) {
        return gcd(a, b);
    }

    template<>
    unsigned int gcd<unsigned int>(unsigned int u, unsigned int v) {
        int shift;
        if (u == 0)
            return v;
        if (v == 0)
            return u;
        shift = __builtin_ctz(u | v);
        u >>= __builtin_ctz(u);
        do {
            unsigned int m;
            v >>= __builtin_ctz(v);
            v -= u;
            m = (int)v >> 31;
            u += v & m;
            v = (v + m) ^ m;
        } while (v != 0);
        return u << shift;
    }

    template<>
    unsigned long long gcd<unsigned long long>(unsigned long long u, unsigned long long v) {
        int shift;
        if (u == 0)
            return v;
        if (v == 0)
            return u;
        shift = __builtin_ctzll(u | v);
        u >>= __builtin_ctzll(u);
        do {
            unsigned long long m;
            v >>= __builtin_ctzll(v);
            v -= u;
            m = (long long)v >> 63;
            u += v & m;
            v = (v + m) ^ m;
        } while (v != 0);
        return u << shift;
    }
}
 
namespace someUsefull {
    template<typename T1, typename T2>
    inline void checkMin(T1& a, T2 b) {
        if (a > b)
            a = b;
    }
 
    template<typename T1, typename T2>
    inline void checkMax(T1& a, T2 b) {
        if (a < b)
            a = b;
    }

    template<typename T1, typename T2>
    inline bool checkMinRes(T1& a, T2 b) {
        if (a > b) {
            a = b;
            return true;
        }
        return false;
    }

    template<typename T1, typename T2>
    inline bool checkMaxRes(T1& a, T2 b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }
}
 
namespace operators {
    template<typename T1, typename T2>
    std::istream& operator>>(std::istream& in, std::pair<T1, T2>& x) {
        in >> x.first >> x.second;
        return in;
    }
 
    template<typename T1, typename T2>
    std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> x) {
        out << x.first << " " << x.second;
        return out;
    }
 
    template<typename T1>
    std::istream& operator>>(std::istream& in, std::vector<T1>& x) {
        for (auto& i : x) in >> i;
        return in;
    }
 
    template<typename T1>
    std::ostream& operator<<(std::ostream& out, std::vector<T1>& x) {
        for (auto& i : x) out << i << " ";
        return out;
    }
}
 
//name spaces
using namespace std;
using namespace operators;
using namespace someUsefull;
//end of name spaces
 
//defines
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define NO {cout << "NO"; return;}
#define YES {cout << "YES"; return;}
 
//end of defines
//#undef HOME
//debug defines
#ifdef HOME
    #define debug(x) cerr << #x << " " << (x) << endl;
    #define debug_v(x) {cerr << #x << " "; for (auto ioi : x) cerr << ioi << " "; cerr << endl;}
    #define debug_vp(x) {cerr << #x << " "; for (auto ioi : x) cerr << '[' << ioi.ff << " " << ioi.ss << ']'; cerr << endl;}
    #define debug_v_v(x) {cerr << #x << "/*n"; for (auto ioi : x) { for (auto ioi2 : ioi) cerr << ioi2 << " "; cerr << 'n';} cerr << "*/" << #x << endl;}
    int jjj;
    #define wait() cin >> jjj;
    #define PO cerr << "POMELO" << endl;
    #define OL cerr << "OLIVA" << endl;
    #define gen_clock(x) cerr << "Clock " << #x << " created" << endl; ll x = clock(); 
    #define check_clock(x) cerr << "Time spent in " << #x << ": " << clock() - x << endl; x = clock();
    #define reset_clock(x) x = clock();
    #define say(x) cerr << x << endl;
#else
    #define debug(x) 0;
    #define debug_v(x) 0;
    #define debug_vp(x) 0;
    #define debug_v_v(x) 0;
    #define wait() 0;
    #define PO 0;
    #define OL 0;
    #define gen_clock(x) 0;
    #define check_clock(x) 0;
    #define reset_clock(x) 0;
    #define say(x) 0;
#endif // HOME

const int SIZE = 200000;
const int block = 64;
const int _size = (SIZE + 63) / 64;

struct bs {
    ull arr[_size];

    bs() {
        for (int i = 0; i < _size; ++i) arr[i] = 0;
    }

    bs& operator^=(bs &other) {
        #pragma GCC ivdep
        for (int i = 0; i < _size; ++i)
            arr[i] ^= other.arr[i];
        return *this;
    }

    int _Find_first_in_xor(bs& other) {
        ull t;
        for (int i = 0; i < _size; ++i) {
            if (t = arr[i] ^ other.arr[i]) {
                return (i << 6) + __builtin_ctzll(t);
            }
        }
        return SIZE;
    }

    int _Find_first() {
        for (int i = 0; i < _size; ++i) {
            if (arr[i]) {
                return (i << 6) + __builtin_ctzll(arr[i]);
            }
        }
        return SIZE;
    }

    void flip(int id) {
        ull &x = arr[id >> 6];
        id &= 63;
        x ^= ((ull)1 << id);
    }

    int size() {
        return SIZE;
    }

};


ostream& operator<<(ostream &os, bs &x) {
    for (int i = 0; i < _size; ++i) {
        os << x.arr[i] << " ";
    }
    return os;
}

void solve(int test) {
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    vector<int> to(n);
    {
        map<int, int> have;
        for (int i : arr) have[i] = 0;
        int cnt = 0;
        for (auto &i : have) {
            i.ss = cnt;
            to[cnt] = i.ff;
            cnt++;
        }
        for (int &i: arr) i = have[i];
    }

    vector<vector<int>> blocks;
    for (int i = 0; i < n; i += block) {
        blocks.push_back({});
        for (int j = 0; i + j < n && j < block; ++j) {
            blocks.back().push_back(arr[i + j]);
        }
    }

    vector<bs> blocks_bs(blocks.size());
    for (int i = 0; i < blocks.size(); ++i) {
        for (int j : blocks[i]) {
            blocks_bs[i].flip(j);
        }
    }
    for (int i = 1; i < blocks.size(); ++i) {
        blocks_bs[i] ^= blocks_bs[i - 1];
    }

    int q;
    cin >> q;
    bs have;
    int last = 0;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        int l = (last ^ a);
        int r = (last ^ b);

        // cin >> l >> r;
        --l;
        --r;
        int lb = l / block;
        int rb = r / block;
        if (rb - lb <= 1) {
            int L = l;
            while (l <= r) {
                have.flip(arr[l]);
                ++l;
            }
            int id = have._Find_first();

            int ans = (id == have.size() ? 0 : to[id]);
            last = ans;
            cout << ans << 'n';
            l = L;
            while (l <= r) {
                have.flip(arr[l]);
                ++l;
            }
        } else {
            int L = (lb + 1) * block;
            int old_l = l;
            int R = (rb + 1) * block;
            checkMin(R, n);
            int old_r = r;
            ++r;
            while (r < R) {
                blocks_bs[rb].flip(arr[r]);
                ++r;
            }
                        while (l < L) {
                blocks_bs[lb].flip(arr[l]);
                ++l;
            }
            int id = blocks_bs[rb]._Find_first_in_xor(blocks_bs[lb]);
            int ans = (id == have.size() ? 0 : to[id]);
            last = ans;
            cout << ans << 'n';
            r = old_r;
            ++r;
            while (r < R) {
                blocks_bs[rb].flip(arr[r]);
                ++r;
            }
            l = old_l;
            while (l < L) {
                blocks_bs[lb].flip(arr[l]);
                ++l;
            }
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
 
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
        //cout << 'n';
        //PO;
    }
    return 0;
}
/*
*/
```
