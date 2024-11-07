# Tutorial_(en)

[A. Beautiful Sequence](../problems/A._Beautiful_Sequence.md)

 **Hint**What is the necessary and sufficient condition?

 **Tutorial**The necessary and sufficient condition for a beautiful sequence is that there exist one i, such that ai≤i. Just check the sequence for the condition.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int a[100005];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i  =1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++) {
        if(a[i] <= i) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}
```
[B. Candies](../problems/B._Candies.md)

 **Hint**How the binary representation changes after an operation?

 **Tutorial**First, we notice that after each operation, the number of candies is always a odd number. So even numbers can not be achieved.

Then consider how the binary representation changes for a odd number x, after turn it into 2x+1 or 2x−1.

 * For the 2x+1 operation: ¯…1 turns into ¯…11.
* For the 2x−1 operation: ¯…1 turns into ¯…01.

So, the operation is just insert a 0/1 before the last digit. And the answer for an odd n is just the binary representation of n, after removing the last digit.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;scanf("%d",&n);
    if(n % 2 == 0) {
        puts("-1");return;
    }
    vector<int> v;
    int f = 0;
    for(int i = 29;i >= 1;i--) {
        if((n >> i) & 1) {
            f = 1;
            v.push_back(2);
        }
        else if(f) {
            v.push_back(1);
        }
    }
    printf("%dn",v.size());
    for(auto x : v) {
        printf("%d ",x);
    }
    printf("n");
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
    return 0;
}
```
[C.Make It Permutation](../problems/C._Make_It_Permutation.md)

 **Hint 1**Try the enumerate the length n of permutation.

 **Hint 2**There're too many lengths to be checked. How to decrease the amount of n?

 **Tutorial**Firstly, we need to remove numbers such that each number appears at most once, this part of cost is unavoidable. Then, let's sort the array a1,a2…am (1≤ai<a2<⋯<am).

Secondly, assume we enumerate the length of the permutation n. We need to remove all the ai greater than n, and insert some numbers x (x≤n) but does not appear in the array a. We can find some i such that ai≤n<ai+1, the cost here is simply (m−i)⋅a+(n−i)⋅b. Here, m is the length of array a, after removing the repeated numbers.

However, n can up to 109 and can not be enumerated. But for all the n∈[ai,ai+1), the smaller n has a smaller cost. (see that (m−i)⋅a do not change, and (n−i)⋅b decreases). Thus, the possible n can only be some ai, and we can caculate the cost in O(n) in total.

Don't forget the special case: remove all the numbers and add a 1.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int p[100005];
typedef long long ll;
void solve()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    set<int> st;
    ll sol = 0 , ans = 2e18;
    for(int i = 1;i <= n;i++) {
        int x;scanf("%d",&x);
        if(st.find(x) == st.end()) st.insert(x);
        else sol += a;
    }
    int c = 0;
    for(auto x : st) p[++c] = x;
    for(int i = 1;i <= c;i++) {
        ans = min(ans , 1LL*(p[i] - i)*b + 1LL*(c-i)*a);
    }
    ans = min(ans , 1LL*c*a + b) ;
    printf("%lldn",ans+sol);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}
```
[D.Climbing the Tree](../problems/D._Climbing_the_Tree.md)

 **Hint**The possible L is always an interval. How to maintain it?

 **Tutorial**The main idea is to that for each a,b,n, the possible L is a interval [l,r]. We will show how to calculate that.

In the first n−1 days, the snail will climb (n−1)⋅(a−b) meters. And in the daytime of the n-th day, the snail will climb a meters. So after n days, the snail climbs at most (n−1)⋅(a−b)+a meters, which means L≤(n−1)⋅(a−b)+a. Also, the snail can not reach L before n days, which means L>(n−2)⋅(a−b)+a. So L∈[(n−2)⋅(a−b)+a+1,(n−1)⋅(a−b)+a]. n=1 is a special case, where L∈[1,a] .

Now after each operation 1, we can maintain a possible interval [Lmin,Lmax]. When a snail comes, we let the new [L′min,L′max] be [Lmin,Lmax]∩[l,r], where [l,r] is the possible interval for the new snail. If the new interval is empty, we ignore this information, otherwise adopt it.

Now let's focus on another problem: for a fixed L,a,b, how to calculate the number of days the snail needs to climb? We can solve the equation (n−2)(a−b)+a<L≤(n−1)(a−b)+a, and get n−2<L−aa−b≤n−1, which means n equals to ⌈L−aa−b⌉+1. Still, special judge for L≤a, where n=1 in this case.

Then, for each query of type 2, we just calculate the number of days we need for Lmin and Lmax. If they are the same, output that number. Otherwise output −1.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int q;scanf("%d",&q);
    ll L = 1 , R = 1e18;
    while(q--) {
        int op;scanf("%d",&op) ;
        if(op == 1) {
            int a,b,n;scanf("%d%d%d",&a,&b,&n);
            ll ql = 1LL*(n - 2)*(a - b) + a + 1, qr = 1LL*(n - 1)*(a - b) + a;
            if(n == 1) ql = 1 , qr = a;
            if(ql > R || qr < L) {
                puts("0");
            }
            else L = max(L , ql) , R = min(R , qr) , puts("1");
        }
        else {
            int a,b;scanf("%d%d",&a,&b);
            ll ans1 = max(1LL,(L - b - 1) / (a - b) + 1) , ans2 = max(1LL,(R - b - 1) / (a - b) + 1);
            if(ans1 == ans2) printf("%lldn",ans1);
            else puts("-1");
        }
    }
    return;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}

```
[E.Monsters](../problems/E._Monsters.md)

 **Hint 1**How to check whether it is possible to defeat all the monsters, starting from a fixed vertex u?

 **Hint 2**Let S(u) be the vertices set that can be reached, starting from vertex u. What's the relationship between S(u) and S(v), where v∈S(u)?

 **Tutorial**For some vertex set T, let's define 

Unable to parse markup [type=CF_MATHJAX]

 as the ''neighbours'' of vertex set T. Formally, v∈E(T) if and only if v∉T, but there exist some vertex u, such that there's an edge (u,v) in the graph, and u∈T.Now let's consider how to solve the problem for some fixed starting vertex u? Let's maintain the set S(u) and E(S(u)). Initially, S(u)=u. We keep doing the procedure: choose a vertex v∈E(S(u)) with minimal value av. If av≤|S(u)|, we add v into set S(u), and update set E(S(u)) simultaneously. Since S(u) is always connected during the procedure, we are actually doing such a thing: find a vertex v that is ''reachable'' now with minimal value av, and try to defeat the monster on it. Our goal is to find some u such that |S(u)|=n.

Then let's move to a lemma: if v∈S(u), then S(v)⊆S(u). 

 **Proof**If it is not, consider the procedure above and the first time we add some vertex x such that x∉S(u) into S(v). At this moment, |S(v)|≤|S(u)| must hold(since it's the first time we add some vertex not in S(u)). On the other side, x∈E(S(u)) must hold, and hence ax>|S(u)|≥|S(v)|. Thus, we can not add x into S(v).

Then we can tell, if |S(u)|<n, then for v∈S(u), |S(v)|<n. So it's unnecessary to search starting from v. And we can construct such an algorithm: Search from 1,2,3,…n in order, if some i has been included in some S(j) before, do not search from it.

Surprisingly, this algorithm is correct. We can prove it's time complexity. For each vertex v, if v∈S(u) now, and when searching from vertex u′, v is add into S(u′) again, then |S(u′)|>2|S(u)|. Thus, one vertex can not be visited more than log(n) times, which means the time complexity is O(nlog2(n)).

This problem has many other methods to solve. This one I think is the easiest to implement.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int vis[200005];
int n , m;
vector<int> E[200005];
int a[200005];
int T = 1;
bool span(int u)
{
    set<pair<int,int> > st;
    st.insert(pair<int,int>{a[u] , u});
    int amt = 0 , df = 0;
    while(st.size()) {
        auto pa = (*st.begin()) ; vis[pa.second] = u;
        if(pa.first > df) {return (amt == n);}
        st.erase(st.begin());
        amt++ ; df++ ;
        for(auto v : E[pa.second]) {
            if(vis[v] < u) {
                st.insert(pair<int,int>{a[v] , v});
            }
        }
    }
    return (amt == n);
}
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i= 1;i <= n;i++) scanf("%d",&a[i]) , vis[i] = 0, E[i].clear();
    for(int i = 1;i <= m;i++) {
        int u,v;scanf("%d%d",&u,&v);E[u].push_back(v) ; E[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] == 0 && !vis[i]) {
            if(span(i)){puts("YES");return;}
        }
    }
    puts("NO");
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}
```
[F.M-tree](../problems/F._M-tree.md)

 **Hint 1**Can you solve a single query using binary search? How to check the answer?

 **Hint 2**Try to find a closed formula for this problem.

 **Tutorial**Let numi be the number of occurances of integer i in the array a. To check whether the answer can be ≤x or not, we can do the following greedy: Starting with a single vertex written x, which is the root. For each i(from large ones to small ones), if the number of current leaves is smaller than numi, then we can not make the answer ≤x. Otherwise, let numi leaves stop, and other leaves ''grow'' m children each(these vertices are no longer leaves, but their children are). We can discover that each round, the ''stopped'' vertices have dep=x−i, which represents their value is x.

We can use the following code to calculate it.

 
```cpp
bool check(int x)
{
    int d = 1;
    for(int i = x;i >= 1;i--){
        if(d < num[i]) return 0;
        d = (d - num[i]) * m;
    }
    return 1;
}
```
Since a negtive number multiplies m is still a negtive number, the code can be as following:

 
```cpp
bool check(int x)
{
    int d = 1;
    for(int i = x;i >= 1;i--){
        d = (d - num[i]) * m;
    }
    return d >= 0;
}
```
Find out something? The final d is just mx−∑xi=1numi⋅mi, which represents it's equivalent to checking mx≥∑ni=1mai! So now the answer is just ⌈logm∑ni=1mai⌉. This is the highest bit plus one of ∑mai in m-base representation(except for that it's just some mx. In this case the answer is x but not x+1). We can use a segment tree, supporting interval min/max query and interval covering to solve the question.

 **Solution**
```cpp
using namespace std;
int n , m , q;
const int N = 2e5 + 40;
int num[N];
int a[N];
int cov[N*4 + 5] , mx[N*4 + 5] , mn[N*4 + 5];
void rec(int u)
{
    mx[u] = max(mx[u<<1|1] , mx[u<<1]) ; mn[u] = min(mn[u<<1|1] , mn[u<<1]);
}
void pd(int u)
{
    if(cov[u] != -1) {
        cov[u<<1] = mn[u<<1] = mx[u<<1] = cov[u];
        cov[u<<1|1] = mn[u<<1|1] = mx[u<<1|1] = cov[u];
        cov[u] = -1;
    }
    return;
}
void build(int u,int l,int r)
{
    cov[u] = -1;
    if(l == r) {mn[u] = mx[u] = num[l] ; return;}
    build(u<<1 , l , (l + r >> 1)) ; build(u<<1|1 , (l + r >> 1) + 1 , r);
    rec(u) ; return;
}
void modify(int u,int l,int r,int ql,int qr,int v)
{
    if(ql <= l && qr >= r) {
        cov[u] = mn[u] = mx[u] = v; return;
    }
    pd(u);
    int md = (l + r>> 1);
    if(ql <= md) modify(u<<1 , l , md , ql , qr ,v);
    if(qr > md) modify(u<<1|1 , md +1 , r , ql , qr , v);
    rec(u);
    return;
}
 
int qumax(int u,int l,int r,int ql)
{
    if(mn[u] == m - 1) return -1;
    if(l == r) return l;
    pd(u);
    int md = (l + r>> 1);
    if(ql > md) return qumax(u<<1|1 , md + 1 , r , ql);
    if(ql == l) {
        if(mn[u<<1] < m - 1) return qumax(u<<1 , l , md , ql);
        return qumax(u<<1|1 , md + 1 , r , md + 1);
    }
    int w = qumax(u<<1 , l , md , ql) ;
    if(w == -1) return qumax(u<<1|1 , md + 1 , r , md + 1);
    return w;
}
int qumin(int u,int l,int r,int ql)
{
    if(mx[u] == 0) return -1;
    if(l == r) return l;
    pd(u);
    int md = (l + r>> 1) ;
    if(ql > md) return qumin(u<<1|1 , md + 1 , r , ql);
    if(ql == l) {
        if(mx[u<<1] > 0) return qumin(u<<1 , l , md , ql);
        return qumin(u<<1|1 , md + 1 , r , md + 1);
    }
    int w = qumin(u<<1 , l , md , ql);
    if(w == -1) return qumin(u<<1|1 , md + 1 , r , md + 1);
    return w;
}
 
int qmax(int u,int l,int r,int ql,int qr)
{
    if(ql <= l && qr >= r) {
        return mx[u];
    }
    pd(u);
    int md = (l + r>> 1) , ans = 0;
    if(ql <= md) ans = max(ans , qmax(u<<1 , l , md , ql , qr ));
    if(qr > md) ans = max(ans , qmax(u<<1|1 , md +1 , r , ql , qr));
    return ans;
}
int qmin(int u,int l,int r,int ql,int qr)
{
    if(ql <= l && qr >= r) {
        return mn[u];
    }
    pd(u);
    int md = (l + r>> 1) , ans = 1e9;
    if(ql <= md) ans = min(ans , qmin(u<<1 , l , md , ql , qr ));
    if(qr > md) ans = min(ans , qmin(u<<1|1 , md +1 , r , ql , qr));
    return ans;
}
int ask(int u,int l,int r)
{
    if(l == r) return l;
    int md = (l + r >> 1);
    pd(u);
    if(mx[u<<1|1] == 0) return ask(u<<1 , l , md);
    return ask(u<<1|1 , md + 1 , r) ;
}
int get()
{
    int highbit = ask(1 , 1 , n+35);
    if(highbit == 1 || qmax(1 , 1 , n+35 , 1 , highbit - 1) == 0) return highbit;
    return highbit + 1;
}
void add(int u)
{
    int l = qumax(1 , 1 , n + 35 , u);
    if(l > u) modify(1 , 1 , n+35 , u , l - 1 , 0) ;
    modify(1 , 1 , n+35 , l , l , qmax(1 , 1 , n + 35 , l , l ) + 1);
    return;
}
void sub(int u)
{
    int l = qumin(1 , 1 , n + 35 , u);
    if(l > u) modify(1 , 1 , n+35 , u , l - 1 , m - 1) ;
    modify(1 , 1 , n+35 , l , l , qmax(1 , 1 , n + 35 , l , l ) - 1);
    return;
}
void solve()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i <= n + 35;i++) num[i] = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);num[a[i]]++;
    }
    for(int i = 1;i <= n + 35;i++) {
        num[i + 1] += num[i] / m;num[i] %= m;
    }
    build(1 , 1 , n + 35);
    while(q--) {
        int u , v;scanf("%d%d",&u,&v);
        sub(a[u]) ; a[u] = v; add(a[u]) ;
        printf("%d%c",get(), " n"[q == 0]);
    }
    return;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}

```
[G. The Maximum Prefix](../problems/G._The_Maximum_Prefix.md)

 **Hint**How to calculate the maximal prefix sum? One possible way is let fn+1=0 and fi=max(fi+1,0)+ai.

 **Tutorial**Consider this method to find maximal prefix sum: let fn+1=0 and fi=max(fi+1,0)+ai. We can discover that the only influence [ai+1,ai+2…an] has(to the whole array's maximal prefix sum) is its maximal prefix sum. Then we let dpi,j be : the expect score we can get, if we assume that the maximal prefix sum of [ai+1,ai+2…an] is j (Read the definition carefully). The answer for each k is dpk,0, since if the maximal prefix sum for [ak+1,ak+2…an] is 0, that is equivalent to removing them from the array. And also dp0,j=hj.

And we have dpi,j=pi⋅dpi−1,j+1+(1−pi)⋅dpi−1,max(j−1,0). The first section represents chosing ai=1 and the second one represents chosing ai=−1.

We also have other solutions, using inclusion-exclusion or generate function. Actually all the testers' solutions differs from each other.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5005;
int p[N] , q[N];
int n;
int f[N][N];
int h[N];
int fpow(int a,int b)
{
    int ans = 1;
    while(b){
        if(b & 1) ans = 1LL*ans*a%mod;
        a = 1LL*a*a%mod;b >>= 1;
    }
    return ans;
}
void solve()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        int a,b;scanf("%d%d",&a,&b);
        p[i] = 1LL*a*fpow(b , mod - 2) % mod;
        q[i] = (1 - p[i] + mod) % mod;
    }
    for(int i = 0;i <= n;i++) scanf("%d",&h[i]);
    for(int i = 0;i <= n;i++) f[0][i] = h[i];
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= n;j++) {
            f[i][j] = (1LL*p[i]*f[i - 1][j + 1] + 1LL*q[i]*f[i - 1][max(0 , j - 1)] ) % mod;
        }
        printf("%d ",f[i][0]);
    }
    printf("n");
    return;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
    return 0;
}
```
[H.Last Number](../problems/H._Last_Number.md)

 **Hint**Actually I don't know how to hint. Try to find some rules related to √5+12, fibnacci or similar

 **Tutorial**Assume that the moment before the x-th operation(but after x−1-th), the first time we have Smax≤2Smin. Let's divide the operation into two part: before x and equal or after x.

Still, at the moment just before the x-th operation, let us sort the elements in the multiset in non-decreasing order, S0,S1…Sk. We will show that the answer is S0⋅(−1)k+∑ki=1Si⋅(−1)i+1.

 **Proof**This lemma is based on the fact that, after each operation(which is after x-th), S1 to Sk−1 will not change, Sk is removed, and S0 turn to Sk−S0. Which also means Sk−S0≤S1 always holds.

At the very beginning, Sk−S0≤S0≤S1 obviously holds. And we can observe that either Sk=Sk−1 or Sk−1=Sk−1. When Sk−1=Sk, the new S0 after two operations is equal to the old S0. When Sk−1=Sk−1, the new S0 after two operations is equal to the old S0 minus one. So if we write the S0 as an array t0,t1…tk by time order, ti+2≤ti always holds. Thus, ti≤S1 always holds.

Let di be the Smax value in the i-th operation. Let's prove that before the x-th operation, di=n−⌈iϕ⌉+1, where ϕ=√5+12.

 **Proof**We prove this by Mathematical induction. One fact should be known that during these operations, Smin=i always holds for the i-th operation(since Smax−Smin>Smin).

For i=1, it is true because d1=n and n−⌈1ϕ⌉+1=n.

Assume for i≤k, it is true. Still use the fact that dk+1=dk or dk+1=dk+1. The necessary and sufficient condition for dk+1>dk is all the numbers greater or equal to dk is ''used''. How many numbers are there? We have n−dk+1 numbers from the original multiset, and some numbers that occurs during the operations, which are the number of j satisfying dj−j≥dk. Thus, dk+1>dk is equivalent to:

    ∑kj=1[dj−j≥dk]+n−dk+1=k

⇔∑kj=1[dj−j≥dk]=k−⌈kϕ⌉

⇔∑kj=1[dj−j≥dk]=⌊k(ϕ−1)ϕ⌋

⇔∑kj=1[⌈jϕ+j⌉≤⌈kϕ⌉]=⌊k(ϕ−1)ϕ⌋

⇔∑kj=1[⌈j(ϕ+1)ϕ⌉≤⌈kϕ⌉]=⌊k(ϕ−1)ϕ⌋

Note that j(ϕ+1)ϕ is always increasing, which means that formula ⌈j(ϕ+1)ϕ⌉≤⌈kϕ⌉ holds for j=⌊k(ϕ−1)ϕ⌋, but does not hold for j=⌊k(ϕ−1)ϕ⌋+1.

The first equation, ⌈⌊k(ϕ−1)ϕ⌋⋅ϕ+1ϕ⌉≤⌈kϕ⌉ always holds. Because ϕ−1ϕ⋅ϕ+1ϕ=1ϕ, and ofcourse ⌊ka⌋b≤kab.

Let's do the research when the second equation does not hold. Let m1={i(ϕ−1)ϕ}, and m2={iϕ} ({x}=x−⌊x⌋). Note that m1+m2=1, since {i(ϕ−1)ϕ}={i−iϕ}. The topic we are going to research is when ⌈(⌊k(ϕ−1)ϕ⌋+1)⋅ϕ+1ϕ⌉>⌈kϕ⌉ hold(which also means, dk+1>dk).

⇔⌈(i(ϕ−1)ϕ−m1)⋅ϕ+1ϕ+ϕ+1ϕ⌉>⌈iϕ⌉

⇔⌈iϕ−m1⋅ϕ+1ϕ+ϕ+1ϕ⌉>⌈iϕ⌉

⇔⌈iϕ−(1−m1)⋅ϕ+1ϕ⌉>⌈iϕ⌉

⇔(1−m1)⋅ϕ+1ϕ>1−m2

⇔ϕ+1ϕ>1m2−1

⇔m2>ϕ2ϕ+1

Then let's focus on, if dk+1=n−⌈k+1ϕ⌉+1, when will dk+1>dk hold? It's easy to find when m2>1−1ϕ, dk+1>dk holds. And since ϕ=√5+12, we can tell ϕ2ϕ+1=1−1ϕ. Thus, we proved the topic, for all k<x(before the x-th operation), dk=n−⌈kϕ⌉+1.

Then, by solve n−⌈xϕ⌉+1≤2x, we can get x=⌈(n+1)ϕ−1ϕ⌉. Now let's prove for k≥x, dk=n−⌈kϕ⌉+1 also holds !

 **Proof**Using the similar idea as lemma 2, find out when dk+1>dk holds. However, at this time, only j≤x−1 will contribute(since for those j>x−1, according to lemma 1, they become the minimal one and do not contribute to anything). Similarly, that is ∑x−1j=1[dj−j≥dk]=⌊k(ϕ−1)ϕ⌋. 

Seems to be different this time, but actually they are the same, because ⌊k(ϕ−1)ϕ⌋≤x−1 holds(the proving is easy, leave it as a exercise). This condition holds means that we can use the same method in lemma 2 to prove it.

Till now, the lemmas told us the solving the problem is actually solving something like ∑(−1)i⋅(n−⌈iϕ⌉+1). We can divide them into positive part and negtive part, and then solving ∑⌊C⋅i⌋, where i range from some l to r, and C is a irrational constant. Since n is not very large, we can approximate C by ab, where a,b are integers, and turn it into a traditional task. (Maybe it is called floor sum or something like, I'm not sure about the algorithm's english name).

The marvelous jiangly told me a,b in long long range is enough. But the tester used int128.

We can dig more about the ϕ. Let bi=Si+1−Si (sorted, before the x-th operation), and what we care is b1+b3+b5…. We can find that array b is actually a consecutive substring of [fibonacci string](https://codeforces.com/https://oeis.org/A096270). More over, let Fn be the starting point of array b in the fibonacci string when the initial size is n, we have the conclusion for n≥5:

F[5…inf]=[3,0],[4,1],[8,0],[12,1]…[fi+3+(−1)i+1,1+(−1)i], where fi=fi−1+fi−2,f1=f2=1 . [r,l] represents a list of numbers [r,r−1,r−2…l+1,l].

Now the only left problem is to find the prefix sum of fibonacci string(of even positions, or of odd positions). This is quite a simple task by using any log(n) or log2(n) solution.

 **Solution 1(floor sum)**
```cpp
#include <bits/stdc++.h>
 
void solve(__int128 n, __int128 a, __int128 b, __int128 c, __int128 &f) {
    if (n < 0) { f = 0; return; }
    if (a >= c || b >= c) {
        solve(n, a % c, b % c, c, f);
        f += (a / c) * (n * (n + 1) / 2) + (b / c) * (n + 1);
    } else if (a) {
        __int128 m = (a * n + b) / c;
        solve(m - 1, c, c - b - 1, a, f);
        f = n * m - f;
    }
}
 
const long double k = (1 + sqrt((long double) 5)) / 2;
 
int n;
long long ans;
__int128 a, b, c, d;
 
int main() {
    int T;
    scanf("%d", &T);
    __int128 x = (__int128) 2000000000000000000ll * 1000000000;
    __int128 y = (__int128) 1000000000000000000ll * 1000000000;
    __int128 z = (__int128) 1618033988749894848ll * 1000000000 + 204586834;
    for (; T; T--) {
        scanf("%d", &n);
        int i = 0;
        for (int l = 0, r = n - 1, mid; l <= r; ) {
            mid = l + r >> 1;
            if (n - floor(mid / k) <= mid + mid) {
                i = mid; r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        solve((n - 1) / 2, x, 0, z, a);
        solve((i - 1) / 2, x, 0, z, b);
        solve((n - 2) / 2, x, y, z, c);
        solve((i - 2) / 2, x, y, z, d);
        ans = i + (i % 2 ? -1 : 1) * ((a - b) - (c - d));
        if ((n - i) % 2) { ans = n - ans; }
        printf("%lldn", ans);
    }
    return 0;
}

```
 **Solution 2(fibonacci)**
```cpp
#include<bits/stdc++.h>
using namespace std;
int l[500];
int fib[500];
int evenfib[500];
int getsum(int i,int n) ///1-index
{
    if(n == 0) return 0;
    if(i <= 1) return fib[i];
    if(n <= l[i - 2]) return getsum(i - 2,  n);
    return fib[i - 2] + getsum(i - 1 , n - l[i - 2]);
}
int getsum2(int i,int n,int p) ///n = 2*k+p, 0-index
{
    if(i <= 0) return 0;
    if(i <= 1) return 1^p;
 
    if(n <= l[i - 2] - 1) return getsum2(i - 2 , n , p);
    int L;
    if(p) L = (l[i - 2] - !(l[i-2]&1));
    else L = (l[i- 2] - (l[i - 2] & 1));
    int ans ;
    if(p) ans = fib[i - 2] - evenfib[i - 2];
    else ans = evenfib[i - 2];
    ans += getsum2(i - 1 , n - l[i - 2] , p ^ ((l[i - 2] & 1)));
    return ans;
}
int getfib(int n) ///0-index
{
    if(n <= 0) return 0;
    n++;
    int ans = 0;
    int i;
    for(i = 0;l[i] <= n;i++) {
        ans += fib[i] ; n -= l[i];
    }
    return ans + getsum(i , n);
}
int get_even(int n) ///n = 2*k
{
    n++;
    int ans = 0;
    int i , lbefore = 0;
    for(i = 0;l[i] <= n;i++) {
        if(lbefore) ans += fib[i] - evenfib[i];
        else ans += evenfib[i];
        lbefore ^= (l[i]&1);
        n -= l[i];
    }
    if(n) ans += getsum2(i , n - 1, lbefore);
    return ans;
}
const double phi = (3 - sqrt(5)) / 2;
const double eps = 1e-6;
int getstart(int n)
{
    if(n == 3) return 0;
    if(n == 4) return 1;
    n -= 4;
    int i;
    for(i = 1;1;i++) {
        int lft ;
        if(i & 1) lft = fib[i + 3] + 1;
        else lft = fib[i + 3] - 1;
        if(n <= lft) break;
        n -= lft;
    }
    int start ;
    if(i & 1) start = fib[i + 3] - n + 1;
    else start = fib[i + 3] - n;
    return start;
}
typedef long long ll;
const int L = 95;
int a[120] = {8,0,6,0,1,8,5,9,7,2,9,7,2,9,2,0,5,5,7,9,0,1,8,1,7,3,5,9,3,7,4,9,2,7,7,3,1,5,5,4,6,8,7,3,1,7,3,2,4,9,1,0,2,8,0,9,6,9,7,2,2,8,8,1,6,3,4,3,6,5,6,1,3,1,4,5,9,7,1,5,1,5,0,1,0,5,2,1,1,0,6,6,9,1,8,3};
ll b[120];
double cal(int n)
{
    memset(b,0,sizeof(b));
    for(int i = 0;i <= L;i++) b[i] = 1LL*n*a[i];
    for(int i = 0;i <= L + 15;i++) {
        b[i + 1] += (b[i] / 10) ; b[i] %= 10;
    }
    int ans = 0;
    for(int i = L + 11;i >= L + 1;i--) ans = (ans * 10 + b[i]) ;
    return ans;
}
void solve(int n)
{
    if(n <= 2) {puts("1");return;}
    int v = cal(n);
    int len = n - v;v++;
    int start = getstart(n);
    int ans = 0;
    if(len & 1) {
        ans = v; ///[start + 1 , start + 3...start + len - 2]
        if(start & 1) ans -= (get_even(start + len - 2) - get_even(start - 1));
        else ans -= (getfib(start + len - 1) - get_even(start + len - 1) - getfib(start) + get_even(start));
    }
    else {
        ans = getfib(start + len - 2) - getfib(start - 1);
        ///[start + 1 , start + len - 3]
        if(start & 1) ans -= (get_even(start + len - 3) - get_even(start - 1));
        else ans -= (getfib(start + len - 2) - get_even(start + len - 2) - getfib(start) + get_even(start));
    }
    printf("%dn",ans);return;
}
int main()
{
    l[0] = l[1] = 1;
    fib[0] = 0 , fib[1] = 1;
    evenfib[1] = 1;
    for(int i = 2;l[i-1] <= 1000000000;i++) {
        l[i] = l[i - 1] + l[i - 2];
        fib[i] = fib[i - 1] + fib[i - 2];
        if(l[i - 2] & 1) evenfib[i] = evenfib[i - 2] + fib[i - 1] - evenfib[i - 1];
        else evenfib[i] = evenfib[i - 2] + evenfib[i - 1];
    }
 
    int t;scanf("%d",&t);
    while(t--) {
        int n;scanf("%d",&n);solve(n);
    }
    return 0;
}

```
