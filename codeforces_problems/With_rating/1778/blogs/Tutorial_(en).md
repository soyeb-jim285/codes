# Tutorial_(en)

[1778A - Flip Flop Sum](../problems/A._Flip_Flop_Sum.md "Codeforces Round 848 (Div. 2)")

 **Tutorial**
### [1778A - Flip Flop Sum](../problems/A._Flip_Flop_Sum.md "Codeforces Round 848 (Div. 2)")

Let's say we've chosen index i. What will happen? 

1. If the values of ai and ai+1 have opposite signs, flipping them won't change the initial sum.
2. if ai = ai+1 = 1, flipping them will reduce the sum by 4.
3. if ai = ai+1 = −1, flipping them will increase the sum by 4.

So, for each i<n, we can check the values of ai and ai+1, and we can measure the effects on the sum based on the three cases stated above. Among the effects, take the one that maximizes the sum.

Time complexity: In each test case, O(n)

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int sz = 1e5 + 10;
int ara[sz];
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while(t--) {
        int n;
        scanf("%d", &n);
 
        int sum = 0;
 
        for(int i = 1; i <= n; i++) {
            scanf("%d", &ara[i]);
            sum += ara[i];
        }
 
        int ans = -1e9;
 
        for(int i = 1; i < n; i++) {
            if(ara[i] == ara[i+1]) {
                if(ara[i] == 1) ans = max(ans, sum-4);
                else ans = max(ans, sum+4);
            }
            else
                ans = max(ans, sum);
        }
 
        printf("%dn", ans);
    }
 
    return 0;
}
```
[1778B - The Forbidden Permutation](../problems/B._The_Forbidden_Permutation.md "Codeforces Round 848 (Div. 2)")

 **Tutorial**
### [1778B - The Forbidden Permutation](../problems/B._The_Forbidden_Permutation.md "Codeforces Round 848 (Div. 2)")

If the array a is good, the answer is obviously 0. Now, how can we optimally transform a not good array a to a good array? Let, we are on the index i (i<m) and x=ai, y=ai+1. If we observe carefully, we will find that there are basically two cases that will make the array a good:

1. Move x and y in the permutation p in such a way that pos(y) becomes greater than pos(x)+d. To do that, in the permutation p, we can swap x to the left and y to the right. The total number of swaps needed is =d−(pos(y)−pos(x))+1. We need to check if there is enough space to the left of pos(x) and to the right of pos(y) to perform the needed number of swaps.
2. Move x and y in the permutation p in such a way that pos(y) becomes smaller than pos(x). To do that, In the permutation p, we can simply swap y to the left until the condition is satisfied. The number of swaps needed is pos(y)−pos(x).

For each i<m, calculate the minimum number of swaps needed among these two cases. The minimum number of swaps among all i<m will be the desired answer.

Time complexity: In each test case, O(n)

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int sz = 1e5+10;
int p[sz], a[sz], pos[sz];
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while(t--) {
        int n, m, d;
        scanf("%d %d %d", &n, &m, &d);
 
        for(int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            pos[ p[i] ] = i;
        }
 
        for(int i = 1; i <= m; i++) {
            scanf("%d", &a[i]);
        }
 
        int ans = 1e9;
 
        for(int i = 1; i < m; i++) {
            if(pos[a[i+1]] <= pos[a[i]] || pos[a[i+1]]-pos[a[i]] > d) {
                ans = 0;
                break;
            }
 
            ans = min(ans, pos[a[i+1]] - pos[a[i]]);
 
            int dist = pos[a[i+1]]-pos[a[i]];
 
            int swapNeed = d-dist+1;
            int swapPossible = (pos[a[i]]-1) + (n - pos[a[i+1]]);
            if(swapPossible >= swapNeed) ans = min(ans, swapNeed);
        }
 
        printf("%dn", ans);
    }
 
    return 0;
}
```
[1778C - Flexible String](../problems/C._Flexible_String.md "Codeforces Round 848 (Div. 2)")

 **Tutorial**
### [1778C - Flexible String](../problems/C._Flexible_String.md "Codeforces Round 848 (Div. 2)")

If we can replace all the characters of the string a, we can transform the string a to the string b. So, replacing more characters is always beneficial. For a fixed string a and another fixed string b, if the answer is x1 for k1 and x2 for k2 (k1<k2), it can be shown that x1≤x2 always satisfies.

That is to say, we can safely consider the size of the set q to be the maximum limit min(k,u) where u is the number of unique characters in the string a. Now, we can generate all possible sets of characters having size min(k,u). Obviously, we won't take the characters that are not present in the string a because they have no effect on the answer. There are many ways to generate the sets, like backtracking, bitmasking, etc. If we can calculate the number of valid pairs (l,r) for each set efficiently, the rest task will be just taking the maximum of them.

To calculate the number of pairs for each set efficiently, we can observe the fact that if a[l,r]=b[l,r] is true, a[p,q]=b[p,q] satisfies for any l≤p≤q≤r. So, we will get c×(c+1)2 number of valid pairs from here where c=r−l+1. Now, we can start iterating from the beginning of the string a. We can say that ai matches bi if they are equal or ai exists in the currently generated set.

While iterating, when we are on the jth index, we need to find the rightmost index r such that a[j,r]=b[j,r] satisfies. Then we need to add the number of valid pairs in this range to the contribution of this set. After that, we need to set the value of j to r+1 and repeat the steps again. The rest of the tasks are trivial.

Time complexity: In each test case, O(n×(um)), where m=min(k,u)

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define EL 'n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
string a, b;
string char_list;
bool mark[26];
ll ans, k;
 
ll count_matching_pair()
{
    ll tot_pair = 0, match_count = 0;
 
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] == b[i] || mark[ a[i]-'a' ])
            match_count++;
        else {
            tot_pair += match_count*(match_count+1)/2;
            match_count = 0;
        }
    }
    tot_pair += match_count*(match_count+1)/2;
 
    return tot_pair;
}
 
void solve(ll pos, ll cnt)
{
    if(cnt > k) return;
 
    if(pos == char_list.size()) {
        if(cnt == k) ans = max(ans, count_matching_pair());
        return;
    }
 
    solve(pos+1, cnt);
 
    mark[ char_list[pos]-'a' ] = 1;
    solve(pos+1, cnt+1);
    mark[ char_list[pos]-'a' ] = 0;
}
 
int main()
{
    fastio;
    ll t;
    cin >> t;
 
    while(t--) {
        ll n; cin >> n >> k;
        cin >> a >> b;
 
        unordered_set <char> unq;
        for(auto &ch : a) unq.insert(ch);
 
        char_list.clear();
        for(auto &x : unq) char_list.pb(x);
 
        k = min(k, (ll)unq.size());
        memset(mark, 0, sizeof mark);
        ans = 0;
        solve(0, 0);
 
        cout << ans << EL;
    }
 
    return 0;
}
```
[1778D - Flexible String Revisit](../problems/D._Flexible_String_Revisit.md "Codeforces Round 848 (Div. 2)")

 **Tutorial**
### [1778D - Flexible String Revisit](../problems/D._Flexible_String_Revisit.md "Codeforces Round 848 (Div. 2)")

Let k be the number of indices where the characters between two strings are different and f(x) be the expected number of moves to make two strings equal given that the strings have x differences. We have to find the value of f(k).

For all x where 1≤x≤n−1,

 f(x)=xn⋅[1+f(x−1)]+n−xn⋅[1+f(x+1)]or,   f(x)=1+xn⋅f(x−1)+n−xn⋅f(x+1)Now, f(0)=0 and f(1)=1+n−1nf(2).

We can represent any f(i) in the form f(i)=ai+bi⋅f(i+1).

Let, a1=1 and b1=n−1n. So, we can write f(1)=a1+b1⋅f(2).

When 1<i<n, f(i)=1+in⋅f(i−1)+n−in⋅f(i+1). We can substitute the value of f(i−1) with ai−1+bi−1⋅f(i) and calculate the value of f(i). Thus we can get the value of ai and bi using the value of ai−1 and bi−1 by considering a1 and b1 as the base case.

We get, ai=n+i⋅ai−1n−i⋅bi−1 and bi=n−in−i⋅bi−1 for 2≤i≤n.

 **Calculation**Substituting f(i−1)=ai−1+bi−1⋅f(i),

 f(i)=1+in⋅[ai−1+bi−1⋅f(i)]+n−in⋅f(i+1)=1+in⋅ai−1+in⋅bi−1⋅f(i)+n−in⋅f(i+1)=1+in⋅ai−11−in⋅bi−1+n−in−i⋅bi−1f(i+1)=n+i⋅ai−1n−i⋅bi−1+n−in−i⋅bi−1f(i+1)=ai+bi⋅f(i+1)So, ai=n+i⋅ai−1n−i⋅bi−1 and bi=n−in−i⋅bi−1 for 2≤i≤n.

Similarly, f(n)=1+f(n−1).

We can represent any f(i) in the form f(i)=ci+di⋅f(i−1).

Let, cn=1 and dn=1. So, we can write f(n)=cn+dn⋅f(n−1).

When 1<i<n, f(i)=1+in⋅f(i−1)+n−in⋅f(i+1). We can substitute the value of f(i+1) with ci+1+di+1⋅f(i) and calculate the value of f(i). Thus we can get the value of ci and di using the value of ci+1 and di+1 by considering cn and dn as the base case.

We get, ci=n+(n−i)⋅ci+1n−(n−i)⋅di+1 and di=in−(n−i)⋅di+1.

 **Calculation**Substituting f(i+1)=ci+1+di+1⋅f(i),

 f(i)=1+in⋅f(i−1)+n−in⋅[ci+1+di+1⋅f(i)]=1+in⋅f(i−1)+n−in⋅ci+1+n−in⋅di+1⋅f(i)=1+n−in⋅ci+11−n−in⋅di+1+in−(n−i)⋅di+1f(i−1)=n+(n−i)⋅ci+1n−(n−i)⋅di+1+in−(n−i)⋅di+1f(i−1)=ci+di⋅f(i−1)So, ci=n+(n−i)⋅ci+1n−(n−i)⋅di+1 and di=in−(n−i)⋅di+1.

Now, f(i)=ci+di⋅f(i−1) and f(i−1)=ai−1+bi−1⋅f(i). By solving these two equations, we find that f(i)=ci+di⋅ai−11−di⋅bi−1.

Time Complexity: O(n⋅logm).

 **Alternative Solution**After some calculations, it can be shown that f(1)=2n−1. Now we know f(0)=0 and f(1)=2n−1.

From the relation between f(i), f(i−1) and f(i−2), we can write f(i)=n⋅f(i−1)−i⋅f(i−2)−nn−i+1.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define mod 998244353 
#define N 1000005
 
template<int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(ll p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<998244353> mint;
 
mint a[N], b[N], c[N], d[N];
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 
        string s1, s2;
        cin >> s1 >> s2;
 
        int diff = 0;
        for(int i = 0; i < n; i++){
            diff += s1[i]!=s2[i];
        }
 
        c[n] = 1, d[n] = 1, a[1] = 1, b[1] = ((mint) n-1)/n;
 
        for(int i = 2; i <= n; i++){
            a[i] = ((mint) n + a[i-1]*i)/((mint) n - b[i-1]*i);
            b[i] = ((mint) n-i)/((mint) n - b[i-1]*i);
        }
 
        for(int i = n-1; i >= 1; i--){
            c[i] = ((mint) n + c[i+1]*(n-i))/((mint) n - d[i+1]*(n-i));
            d[i] = (mint) i / ((mint) n - d[i+1]*(n-i));
        }
 
        mint ans = (c[diff]+d[diff]*a[diff-1])/((mint) 1 - d[diff]*b[diff-1]);
 
        cout << ans << endl;
    }
 
    return 0;
}

```
 **Alternative Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
template<int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(ll p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<998244353> mint;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    mint two = 2;
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 
        string a, b;
        cin >> a >> b;
 
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i]!=b[i]) cnt++;
        }
 
        vector<mint> dp(n+2);
        dp[0] = two.pow(n);
        dp[1] = dp[0]-1;
        dp[0] = 0;
 
        for(long long i = 2; i < n; i++){
            mint x = i-1;
            x /= n;
            dp[i] = (dp[i-1]-x*dp[i-2]-1)*n/(n-i+1);
        }
 
        dp[n] = dp[n-1]+1;
 
        cout << dp[cnt] << 'n';
    }
 
    return 0;
}

```
[1778E - The Tree Has Fallen!](../problems/E._The_Tree_Has_Fallen!.md "Codeforces Round 848 (Div. 2)")

 **Tutorial**
### [1778E - The Tree Has Fallen!](../problems/E._The_Tree_Has_Fallen!.md "Codeforces Round 848 (Div. 2)")

At first, we can think of another problem. Given an array. You need to find the maximum subset XOR. How can we solve it? We can solve this problem very efficiently using a technique called "XOR Basis". You can read about it from [here](https://codeforces.com/blog/entry/68953).

In problem E, at first, we can fix any node as the root of the tree. Let's call this rooted tree the base tree. After that, start an Euler tour from the root and assign discovery time du and finishing time fu to each node u. In each query, three types of cases can occur (node r and node v are from the query format): 

1. r=v. In this case, we need to calculate the maximum subset XOR of the whole tree.
2. Node v is not an ancestor of node r in the base tree. So, the subtree of node v will remain the same.
3. Node v is an ancestor of node r in the base tree. What will be the new subtree of node v in this case? This is a bit tricky. Let's denote such a node c that is a child of node v and an ancestor of node r in the base tree. Then the new subtree of node v will contain the whole tree except the subtree (in the base tree) of node c.

Let's say, inu is the XOR basis of all the values in node u's subtree (in the base tree). We can build inu by inserting the value au to inu and merging it with all of its children w's basis inw. Two basis can be merged in O(log2(d)) complexity, where d is their dimension. If we can build the basis inu for each node u, we are able to answer the case 1 and case 2. To answer case 2, we need to find the maximum subset XOR in the corresponding basis. To answer case 1, we need to do a similar thing in the basis inroot, where root is the root node of the base tree.

For case 3, let's say outu is the XOR basis of all the values of the base tree except the node u's subtree (in the base tree). Then the answer of the case 3 will be the maximum subset XOR in the basis outc. To build the basis outu for each node u, we can utilize the properties of the discovery time du and finishing time fu. Which nodes will be outside the subtree of node u? The nodes w that have either dw<du or dw>fu. To merge their basis easily, we can pre-calculate two basis arrays pre[] and suf[] where the basis prei includes all the values of the nodes w such that dw≤i and the basis sufi includes all the values of the nodes w such that dw≥i.

To find the node c in the case 3, we can perform a binary search on the children of node v. We can use the fact that the order of the discovery times follows the order of the children and a node c is only an ancestor of a node r iff dc≤dr && fc≥fr.

Time complexity: O(n×log2(d)), where d=max(ai) 

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define nn 'n'
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL);
 
const int sz = 2e5 + 10, d = 30;
vector <int> g[sz], Tree[sz];
int a[sz], discover_time[sz], finish_time[sz], nodeOf[sz], tim;
 
struct BASIS {
    int basis[d];
    int sz;
 
    void init() {
        for(int i = 0; i < d; i++) basis[i] = 0;
        sz = 0;
    }
 
    void insertVector(int mask) {
        for (int i = d-1; i >= 0; i--) {
            if (((mask>>i)&1) == 0) continue;
 
            if (!basis[i]) {
                basis[i] = mask;
                ++sz;
                return;
            }
            mask ^= basis[i];
        }
    }
 
    void mergeBasis(const BASIS &from) {
        for(int i = d-1; i >= 0; i--) {
            if(!from.basis[i])
                continue;
 
            insertVector(from.basis[i]);
        }
    }
 
    int findMax()  {
        int ret = 0;
        for(int i = d-1; i >= 0; i--) {
            if(!basis[i] || (ret>>i & 1))
                continue;
 
            ret ^= basis[i];
        }
        return ret;
    }
} in[sz], out, pre[sz], suf[sz];
 
void in_dfs(int u, int p)
{
    in[u].insertVector(a[u]);
    discover_time[u] = ++tim;
    nodeOf[tim] = u;
 
    for(auto &v : g[u]) {
        if(v == p)
            continue;
 
        Tree[u].pb(v);
        in_dfs(v, u);
 
        in[u].mergeBasis(in[v]);
    }
    finish_time[u] = tim;
}
 
inline bool in_subtree(int sub_root, int v)
{
    return discover_time[sub_root] <= discover_time[v]
            && finish_time[sub_root] >= finish_time[v];
}
 
int findChildOnPath(int sub_root, int v)
{
    int lo = 0, hi = (int)Tree[sub_root].size()-1;
 
    while(lo <= hi) {
        int mid = lo+hi>>1, node = Tree[sub_root][mid];
 
        if(finish_time[node] < discover_time[v])
            lo = mid + 1;
        else if(discover_time[node] > discover_time[v])
            hi= mid - 1;
        else
            return node;
    }
}
 
void init(int n) {
 
    for(int i = 0; i <= n+5; i++) {
        g[i].clear(), Tree[i].clear();
        in[i].init();
        pre[i].init(), suf[i].init();
    }
    tim = 0;
}
 
int main()
{
    fastio;
 
    int t;
    cin >> t;
 
    while(t--) {
        int n; cin >> n;
 
        init(n);
 
        for(int i = 1; i <= n; i++) cin >> a[i];
 
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }
 
        in_dfs(1, -1);
 
        for(int i = 1; i <= n; i++) {
            pre[i].insertVector(a[ nodeOf[i] ]);
            pre[i].mergeBasis(pre[i-1]);
        }
 
        for(int i = n; i >= 1; i--) {
            suf[i].insertVector(a[ nodeOf[i] ]);
            suf[i].mergeBasis(suf[i+1]);
        }
 
        int q; cin >> q;
 
        while(q--) {
            int root, v;
            cin >> root >> v;
 
            if(root == v) {
                cout << in[1].findMax() << nn;
            }
            else if(in_subtree(v, root)) {
                int child = findChildOnPath(v, root);
 
                out.init();
                out.mergeBasis(pre[discover_time[child]-1]);
                out.mergeBasis(suf[finish_time[child]+1]);
                cout << out.findMax() << nn;
            }
            else
                cout << in[v].findMax() << nn;
        }
    }
 
    return 0;
}
```
[1778F - Maximizing Root](../problems/F._Maximizing_Root.md "Codeforces Round 848 (Div. 2)")

 **Tutorial**
### [1778F - Maximizing Root](../problems/F._Maximizing_Root.md "Codeforces Round 848 (Div. 2)")

Let, xu be the value of node u and dp[u][d] be the minimum number of moves required to make the GCD of the subtree of u equal to a multiple of d.

Now, dp[u][d]=0 if the subtree GCD of node u is already a multiple of d and dp[u][d]=∞ if (xu⋅xu) is not a multiple of d.

For each divisor y of d, suppose, we want to perform the move on the subtree of u by multiplying each node value of the subtree with y iff (xu⋅y) is a multiple of d and y is a divisor of xu. In this case, we have to make the GCD of all the subtree of child nodes of u equal to a multiple of LCM(dy,y) before performing the move on the subtree of u. This is because we have to make each node of the subtree a multiple of dy to get the multiple of d after performing the move on the subtree of node u using y. Also, to perform the move of multiplying by y, the value of each subtree node should be a multiple of y. So we have to make each node value a multiple of LCM(dy,y).

So, dp[u][d] will be calculated from dp[v][LCM(dy,y)] for each divisor y of d for all child v of u.

Now, x1⋅D is the answer where D is the largest divisor of x1 such that k≥dp[1][D].

Time Complexity: O(n⋅m2) where m is the number of divisors of x1.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
const int mod = 998244353;
 
int val[N];
vector<int> g[N];
vector<int> divisor[N];
int subtree_gcd[N], par[N];
 
int dp[N][1003];
int gcdd[1003][1003];
 
inline long long ___gcd(long long a, long long b){
    if(gcdd[a][b]) return gcdd[a][b];
 
    return gcdd[a][b] = __gcd(a, b);
}
 
inline long long lcm(long long a, long long b){
    return (a/___gcd(a, b))*b;
}
 
void dfs(int u, int p){
    par[u] = p;
    subtree_gcd[u] = val[u];
    for(int v: g[u]){
        if(v==p) continue;
        dfs(v, u);
        subtree_gcd[u] = ___gcd(subtree_gcd[u], subtree_gcd[v]);
    }
}
 
 
int solve(int u, int d, int p){
    if(subtree_gcd[u]%d==0) return 0;
    if((val[u]*val[u])%d) return (1<<30);
 
 
    if(dp[u][d]!=-1) return dp[u][d];
    
    long long req = d/___gcd(d, subtree_gcd[u]);
 
    long long res = (1<<30);
    for(int div: divisor[val[u]]){
        if((val[u]*div)%d==0 && d%div==0){
            long long r = 1;
            for(int v: g[u]){
                if(v==p) continue;
                r += solve(v, lcm(d/div, div), u);
            }
            res = min(res, r);
        }
    }
 
    return dp[u][d] = min(res, (1LL<<30));
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    for(int i = 2; i < 1001; i++){
        for(int j = i; j < 1001; j+=i){
            divisor[j].push_back(i);
        }
    }
 
    int t;
    cin >> t;
 
    while(t--){
        int n, k;
        cin >> n >> k;
 
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }
 
        for(int i = 1; i <= n; i++){
            cin >> val[i];
        }
        
        for(int i = 0; i <= n; i++){
            for(int d: divisor[val[1]]){
                dp[i][d] = -1;
            }
        }
 
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        dfs(1, 0);
 
        int ans = val[1];
 
        for(int d: divisor[val[1]]){
            int req = 0;
            int f = 1;
            for(int v: g[1]){
                int x = solve(v, d, par[v]);
                if(x>n) f = 0;
                req += x;
            }
 
            if(!f) continue;
 
            req++;
            if(req<=k){
                ans = max(ans, val[1]*d);
            }
        }
 
        cout << ans << "n";
    }
    
    return 0;
}

```
