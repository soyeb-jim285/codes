# Tutorial_(en)

Hope you enjoyed the problems.

 **Direction Change**[1668A - Direction Change](../problems/A._Direction_Change.md "Codeforces Round 783 (Div. 2)")

 **Solution**The moves are symmetrical, so we can assume that n≥m. There is no solution if m=1 and n≥3, because one can only move up and down, but two consecutive down moves is required to reach (n,1).

Otherwise, there is a solution. 

One should move downwards at least n−1 times, and it is forbidden to do that twice in a row, so another n−2 move is necessary (1 between each pair). So at least n−1+n−2=2⋅n−3 moves required. If n+m is even, then one more, because the parity of a+b changes after every move, and the parity is even before the first and after the last move, so the total number of moves should be even.

There is a construction for that lower bound:

Move alternately down and right. After reaching the m-th column, repeat the following sequence of moves: down, left, down, right. With this 4 move long sequence, one can move down two times. 

So we will reach (n−1,m), then one more move is required, or we will reach (n,m). If we add all of these moves, we get the formula: if n+m is even then: 2⋅(m−1)+4⋅(n−m)/2=2⋅n−2,and if n+m is odd then: 2⋅(m−1)+4⋅(n−m−1)/2+1=2⋅n−3.

 **Implementation**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
int t, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n<m) {
            swap(n, m);
        }
        if (m==1 && n>=3) {
            cout << -1 << "n";
        } else {
            cout << 2*n-2-(n+m)%2 << "n";
        }
    }
    return 0;
}
```
 **feedback**Good problem: 


[*268*](https://codeforces.com/data/like?action=like "I like this")





Average problem: 

 
[*57*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*229*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")



 **Social Distance**[1668B - Social Distance](../problems/B._Social_Distance.md "Codeforces Round 783 (Div. 2)")

 **Solution**If there is no one between the i-th and j-th person then max(ai,aj) free chairs should be between them.

So we should find a permutation p of the array a, when max(p1,p2)+max(p2,p3)...+max(pn−1,pn)+max(pn,p1) is minimal.

We can assume that the array is non-decreasing (ai≤ai+1). For each i (1≤i<n) the i largest elements from a (an−i+1 ... an) will appear in the formula at least i+1 times. Every element occurs in two segments, and we only can count i−1 segments twice. So we get a lower bound for the number of free chairs: a2+a3+...+an−1+2⋅an.

This lower bound is reachable for the empty chairs if the permutation of p is sorted. Because max(p1,p2)=p2, max(p2,p3)=p3, ... max(pn−1,pn)=pn, and max(pn,p1)=pn.

They also sit on n chairs. If we add all of these, we get that the answer is `YES` if: n+∑ni=1(ai)−min(ai)+max(ai)≤m. (ai={a1,a2,...an})

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long sum=0, min_val=1e9, max_val=0;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sum+=x, min_val=min(min_val, x), max_val=max(max_val, x);
        }
        cout << (n+sum-min_val+max_val<=m ? "YES" : "NO") << "n";
    }
    return 0;
}
```
 **feedback**Good problem: 

 
[*309*](https://codeforces.com/data/like?action=like "I like this")



Average problem: 

 
[*57*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*41*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")



 **Make it Increasing**[1668C - Make it Increasing](https://codeforces.com/contest/1668/problem/C "Codeforces Round 783 (Div. 2)")

 **Solution**If the final array, is b1, b2 ... bn, than the solution is surely unoptimal if there is an 2≤i≤n, when bi>0, and bi−ai>bi−1, or b1>0. Because there was one unnecessary move on bi or on b1.

Similarly it is unoptimal, if bi<0 and bi+ai<bi+1 or bn<0.

We can see, that there will be a 0 in the final array. If we fix the position of the 0 element, than we can set the other values greadily: find the smallest value for each element, which is bigger than the previous one, and similarly before that element.

We can fix each element, and calculate the answer for that in O(n) time. The minimum of these values will be the final answer. So the final complexity is O(n2).

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
long long n, a[5005], ans=1e18;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int pos=1; pos<=n; pos++) {
        long long prev=0, sum=0;
        for (int i=pos-1; i>=1; i--) {
            prev+=a[i]-prev%a[i];
            sum+=prev/a[i];
        }
        prev=0;
        for (int i=pos+1; i<=n; i++) {
            prev+=a[i]-prev%a[i];
            sum+=prev/a[i];
        }
        ans=min(ans, sum);
    }
    cout << ans << "n";
    return 0;
}
```
 **feedback**Good problem: 

 
[*550*](https://codeforces.com/data/like?action=like "I like this")



Average problem: 

 
[*79*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*79*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")



 **Optimal Partition**[1668D - Optimal Partition](https://codeforces.com/contest/1668/problem/D "Codeforces Round 783 (Div. 2)")

 **Solution**Let dpi be the answer for the first i elements, and v(i,j) the value of the subarray [i,j]. With prefix sums it is easy to calculate v(i,j) quickly. With this we can get a n2 solution: dpi=max(dpj+v(j+1,i)) for j<i. 

Lets call a segment winning, drawing, or losing, if the value of it is positive, 0, or negative respectively. There is an optimal solution if the length of the drawing and losing segments are 1. (The task is solvable without this observation, but it is harder to implement.) Proof: For a losing segment in the worst case we can get two losing segments with the same total length (the same value).

For a drawing segment with length k if k is even than the answer is the same if we split it into two segments with length k/2. For odd k if the sum in the first (k−1)/2 or last (k−1)/2 elements is negative, than it is possible to increase the answer, otherwise one can split the segment into (k−1)/2, 1, and (k−1)/2 long segments, and the answer for the new partition can't lessen.

So there is an optimal solution when only winning segments might be longer than 1. It is easy to handle the 1 long segments. For each i (1≤i≤n) we have to find j, 0<=j<i, where v(j+1,i)>0, and dpj+v(j+1,i) is maximal (dp0=0).

If we store the prefix sums, and assign a permutation according to the prefix sums, than we can get all the positions 1≤j<i, where v(j+1,i)>0.

Than v(j+1,i)=i−j. 

So when we calculate dpi, we should update with dpi−i. This way, finding the optimal j for each i is just a prefix maximum. One can solve the problem with Fenwick tree or segment tree.

Final complexity is O(n⋅log(n)).

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;
const int max_n=500005, inf=10000000;
int t, n, a[max_n], dp[max_n], ord[max_n], fen[max_n];
long long pref[max_n];


// Fenwick tree with prefix maximum
int lsb(int a) {
    return (a & -a);
}
void add(int pos, int val) {
    while (pos<=n) {
        fen[pos]=max(fen[pos], val);
        pos+=lsb(pos);
    }
}
int ask(int pos) {
    int val=-inf;
    while (pos) {
        val=max(fen[pos], val);
        pos-=lsb(pos);
    }
    return val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<long long, int> > v;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            pref[i]=pref[i-1]+a[i];
            v.push_back({pref[i], -i});
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++) {
            ord[-v[i].second]=i+1;
        }
        // smaller prefix sum, smaller ord[i]
        // if j<i they have equal prefix sums, than ord[i]<ord[j], this way we cannot count [j+1, ... i] as a winning segment


        for (int i=1; i<=n; i++) {
            fen[i]=-inf;
        }

        for (int i=1; i<=n; i++) {
            dp[i]=(dp[i-1]+(a[i]<0 ? -1 : a[i]>0 ? 1 : 0));
            // The last segment is 1 long.

            dp[i]=max(dp[i], ask(ord[i])+i);
            if (pref[i]>0) dp[i]=i;
            // Segment [1, ... i] is winning, so dp[i]=i;

            add(ord[i], dp[i]-i);
        }
        cout << dp[n] << "n";

        for (int i=0; i<=n; i++) {
            a[i]=0, dp[i]=0, ord[i]=0, fen[i]=0, pref[i]=0;
        }
    }
    return 0;
}

```
 **feedback**Good problem: 

 
[*304*](https://codeforces.com/data/like?action=like "I like this")



Average problem: 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*116*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*126*](https://codeforces.com/data/like?action=like "I like this")



 **Half Queen Cover**[1668E - Half Queen Cover](https://codeforces.com/contest/1668/problem/E "Codeforces Round 783 (Div. 2)")

 **Solution**Let's assume that there is a solution for k half-queens. There are at least n−k rows, and columns, which contains no half-queen. 

If the uncovered rows are r1,r2,...ra, and the columns are c1,c2,...cb, (in increasing order), each diagonal (when the difference is a constant) contains at most one of the following a+b−1 squares: (ra,c1),(ra−1,c1),...(r1,c1),(r1,c2),...(r1,cb). So a different half-queen attacks these cells.

We know that: a+b−1≤k,n−k≤a,n−k≤b, so 2⋅n≤3⋅k+1. We have a lower bound for k. It turns out, that there is a consturction, for this k.

For n=3⋅x+2, k=2⋅x+1, and we can place x+1 in the top left corner, diagonally, and x half queens in the bottom right corner diagonally.

For n=8 an optimal construction could be: (1,3), (2,2), (3,1), (7,8), (8,7).

If n=3⋅x, or n=3⋅x+1 we can put one or two half-queens, in the bottom right corner, and use the previous construction.

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{   
    int n;
    cin >> n;
    cout << n/3+(n+2)/3 << "n";
    if (n==1) {
        cout << 1 << " " << 1 << "n";
        return 0;
    }
    while (n%3!=2) {
        cout << n << " " << n << "n";
        n--;
    }
    int a=(n+1)/3;
    for (int i=1; i<=a; i++) {
        cout << i << " " << a+1-i << "n";
    }
    for (int i=1; i<a; i++) {
        cout << n-a+i+1 << " " << n-i+1 << "n";
    }
    return 0;
}
```
 **feedback**Good problem: 

 
[*93*](https://codeforces.com/data/like?action=like "I like this")



Average problem: 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*225*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")



 **Edge Elimination**[1668F - Edge Elimination](https://codeforces.com/contest/1668/problem/F "Codeforces Round 783 (Div. 2)")

 **Solution**When an edge is removed, the two neighbouring vertex have the same parity of edges. We say that an edge is odd, if the parity is odd, and the edge is even otherwise.

One can see, that a vertex with even degree will have the same amount of odd and even edges. For a vertex with odd degree, there will be one more odd edge.

Starting from the leaves, we can decide the parity of each edge (an edge connected to a leaf is odd).

If there is a contradiction somewhere than the answer is `NO`.

Otherwise, there is a construction.

In each vertex decide the removal order of the outgoing edges. Any order is good, when it always changes parity, and ends with an odd edge. Consider the directed graph with these conditions. One can see, that this graph is acyclic, so there is a topological order of that graph which will satisfy all the conditions.

Also, it is possible to solve it recursively.

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
const int c=200005;
int t, n, up[c];
bool parity[c], vis[c], no_sol;
vector<int> edges[c];
void dfs(int a) {
    vis[a]=true;
    int cnt[2]={0, 0};
    for (auto x:edges[a]) {
        if (!vis[x]) {
            up[x]=a;
            dfs(x);
            cnt[parity[x]]++;
        }
    }
    if (a!=1) {
        if (parity[a]=(cnt[0]>=cnt[1]));
        cnt[parity[a]]++;
    }
    if (cnt[1]-cnt[0]<0 || cnt[1]-cnt[0]>1) {
        no_sol=1;
    }
}
void solve(int a) {
    vector<int> p[2];
    for (auto x:edges[a]) {
        if (x!=up[a]) {
            p[parity[x]].push_back(x);
        } else {
            p[parity[a]].push_back(a);
        }
    }
    int si=edges[a].size(), id=si%2;
    for (int i=0; i<si; i++) {
        int val=p[id].back();
        if (val==a) {
            cout << a << " " << up[a] << "n";
        } else {
            solve(val);
        }
        p[id].pop_back();
        id=1-id;
    }
 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int test=0; test<t; test++) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b), edges[b].push_back(a);
        }
        dfs(1);
        if (no_sol) {
            cout << "NOn";
        } else {
            cout << "YESn";
            solve(1);
        }
 
        for (int i=1; i<=n; i++) {
            parity[i]=0, up[i]=0, vis[i]=0;
            edges[i].clear();
        }
        no_sol=0;
    }
    return 0;
}
```
 **feedback**Good problem: 

 
[*74*](https://codeforces.com/data/like?action=like "I like this")



Average problem: 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")



 **Centroid Probabilities**[1667E - Centroid Probabilities](https://codeforces.com/contest/1667/problem/E "Codeforces Round 783 (Div. 1)")

 **Solution**Let S=n+12, binomi,j=i!j!⋅(i−j)!, dpi the result of some precalculation (see below) and ansi the final answer for the i-th vertex.

Root the tree in vertex 1. It is easy to see that in the possible trees the parent of vertex 2≤i≤n is smaller than i. The cetroid will be the largest vertex, where the size of its subtree is at least S.

For each i first calculate: how many times the subtree of vertex i will be at least S (dpi).

If i=1, then dpi=(n−1)!. If i>S then the dpi=0. Otherwise (2≤i≤S) dpi=∑n−ij=S−1binomn−i,j⋅j!⋅(n−j−2)!⋅(i−1)

Proof: Let's assume that the size of the subtree is j+1. Color the subtree of vertex i except i red. Color every other vertex except the first and the i-th one to blue. We have binomn−i,j differnt colorings, because we have to choose j values between i+1 and n. (binomn−i,j)

There are k possibilities for the parent of the k-th smallest blue or the k-th smallest red vertex. (j!⋅(n−j−2)!)

The parent of the i-th vertex can be anything. (i−1)

If we multiply all of these, we get the described formula.

Then ansi=dpi−∑nj=i+1ansji

Proof: if the subtree of i is at least S, and the centroid is not i, than the centroid is in the subtree of i. If j is the centroid, there is exactly 1i chance, that the path from j to 1 will cross vertex i. So we have to subract ansji for each j>i.

This gives us an O(n2) solution, which is slow because of the two sum formulas.

∑n−ij=S−1binomn−i,j⋅j!⋅(n−j−2)!⋅(i−1)=∑n−ij=S−1(n−i)!⋅j!⋅(n−j−1)!⋅(i−1)j!⋅(n−i−j)!=∑n−ij=S−1(n−i)!⋅(n−j−2)!⋅(i−1)(n−i−j)!

(n−i)!⋅(i−1) is a constant (for fixed i), and the difference between n−j−2 and n−i−j is i−2, is also a constant for fixed i. If we reverse the inv array, then we can calculate ∑n−ij=S−1(n−j−2)!(n−i−j)! in n⋅log(n) time for 2≤i≤S with ntt.

We can do the calculation of ansi in linear time if we store the suffix sums of the latter values.

This gives us the final complexity: O(n⋅log(n)).

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
 
 
// ntt - this code is not mine
const int _ = 1 << 20 , mod = 998244353 , G = 3;
int upd(int x) {
    return x + (x >> 31 & mod);
}
int add(int x , int y) {
    return upd(x + y - mod);
}
int sub (int x , int y){
    return upd(x - y);
}
int mul (int a, int b) {
    return 1ll*a*b%mod;
}
int poww(long long a , int b) {
    int tms = 1;
    while (b) {
        if(b & 1) tms = tms * a % mod;
        a = a * a % mod; b >>= 1;}
    return tms;
}
 
int dir[_] , need , invnd , w[_];
void init(int len){
	static int L = 1; need = 1;
	while (need < len) need <<= 1;
	invnd = poww(need , mod - 2);
	for (int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for (int &i = L ; i < need ; i <<= 1) {
        w[i] = 1;
        int wn = poww(G , mod / i / 2);
        for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % mod;
    }
}
 
void dft(vector < int > &arr , int tmod){
	arr.resize(need);
	for (int i = 1 ; i < need ; ++i) {
        if (i < dir[i]) swap(arr[i] , arr[dir[i]]);
	}
	for(int i = 1 ; i < need ; i <<= 1) {
		for (int j = 0 ; j < need ; j += i << 1) {
			for (int k = 0 ; k < i ; ++k) {
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % mod;
				arr[j + k] = add(x , y); arr[i + j + k] = sub(x , y);
			}
		}
	}
	if(tmod == -1) {
        reverse(arr.begin() + 1 , arr.end());
        for(auto &t : arr) {
            t = 1ll * t * invnd % mod;
        }
    }
}
 
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    init(a.size()+b.size());
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
 
    dft(fa, 1);
    dft(fb, 1);
    for (int i = 0; i < need; i++) {
        fa[i] = 1ll * fa[i] * fb[i] % mod;
    }
    dft(fa, -1);
    return fa;
}
 
const int max_n=200005;
long long n, fact[max_n], inv[max_n], dp[max_n], ans[max_n], suf, s;
vector<int> v1, v2, v3;
long long po(long long a, long long b) {
    long long res=1;
    while (b) {
        if (b%2) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
 
 
int main()
{
    cin >> n;
    s=(n+1)/2;
    fact[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=po(fact[i], mod-2);
    }
 
    for (int i=0; i<s-1; i++) {
        v1.push_back(fact[i]);
        v2.push_back(inv[i]);
    }
    reverse(v2.begin(), v2.end());
    v3=multiply(v1, v2);
 
    dp[1]=fact[n-1];
    for (int i=2; i<=s; i++) {
        dp[i]=fact[n-i]*v3[i+s-4]%mod*(i-1)%mod;
    }
 
    for (int i=s; i>=1; i--) {
        ans[i]=(dp[i]-suf*po(i, mod-2)%mod+mod)%mod;
        suf=(suf+ans[i])%mod;
    }
 
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "n";
    return 0;
}
```
 **feedback**Good problem: 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")



Average problem: 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")



Bad problem: 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")



Did not solve: 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")



 **Yin Yang**[1667F - Yin Yang](https://codeforces.com/contest/1667/problem/F "Codeforces Round 783 (Div. 1)")

 **Solution**Border: cells in the first or last row or first or last column. One can see that on the border both the black and the white part is connected. So there is no solution if there is a `BWBW` subsequence on the border.

Otherwise there is a solution. 

Solve an easier task first. Assume that there is no colored cell on the border.

Then there is a nice construction. Color white all cells in the first column, and in the 4∗k+2-nd and 4∗k+3-rd row, which is not in the last column.

One can see that the stripes (2 consequtive white rows) are connected, because no two initially colored cell shares a corner. Also different stripes are connected to each other because of the left column. If there is a white cell in the middle of a black stripe, then it must be orthogonally adjacent to a white stripe.

Similarly the black cells will be connected too. 

If there are colored cells on the border, than it is impossible to do exactly this. But the most of the cells might be the same: the white stripes, and the white column on the left side. In this way, the white part is connected. For the black part, there might be 3 issues: the border is not connected to the black stripes, there are isolated black cells in the 2-nd or n−1-th row, and different black stripes might be unconnected. All of these issues is solvable locally with changing the color of some cells from white to black and vice versa.

 **Implementation**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
const int c=505;
int t, n, m, fix[c][c], ans[c][c], rotcnt, change, old_cl, new_cl;
int fix2[c][c], ans2[c][c];
void color_boundary() {
    for (int cnt=1; cnt<=2; cnt++) {
        for (int j=2; j<=m; j++) {
            if (!ans[1][j]) ans[1][j]=ans[1][j-1];
            if (ans[1][j]!=ans[1][j-1]) change++;
        }
        for (int i=2; i<=n; i++) {
            if (!ans[i][m]) ans[i][m]=ans[i-1][m];
            if (ans[i][m]!=ans[i-1][m]) change++;
        }
        for (int j=m-1; j>=1; j--) {
            if (!ans[n][j]) ans[n][j]=ans[n][j+1];
            if (ans[n][j]!=ans[n][j+1]) change++;
        }
        for (int i=n-1; i>=1; i--) {
            if (!ans[i][1]) ans[i][1]=ans[i+1][1];
            if (ans[i][1]!=ans[i+1][1]) change++;
        }
        if (!ans[1][1]) ans[1][1]=1;
        if (cnt==1) change=0;
    }
}
void rotate_90() {
    rotcnt++;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans2[i][j]=ans[i][j], fix2[i][j]=fix[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans[j][n+1-i]=ans2[i][j];
            fix[j][n+1-i]=fix2[i][j];
        }
    }
    swap(n, m);
}
void good_rotation() {
    for (int cnt=1; cnt<=4; cnt++) {
        bool same=1, opposite=0;
        for (int i=1; i<=n; i++) {
            if (ans[i][1]!=ans[1][1]) same=0;
            if (1<i && i<n && ans[1][1]!=ans[i][m]) opposite=1;
        }
        if (!same || !opposite) rotate_90();
    }
}
void color_the_stripes() {
    for (int i=2; i<n; i++) {
        for (int j=2; j<m; j++) {
            if (!fix[i][j]) {
                if (i%4==2 || i%4==3) ans[i][j]=old_cl;
                else ans[i][j]=new_cl;
            }
        }
    }
}
void avoid_touching() {
    for (int i=1; i<n; i++) {
        if (ans[i][m-1]==ans[i+1][m] && ans[i+1][m-1]==ans[i][m] && ans[i][m]!=ans[i+1][m]) {
            if (!fix[i][m]) ans[i][m]=3-ans[i][m];
            else ans[i+1][m]=3-ans[i+1][m];
        }
    }
}
void boundary_stripe_connection() {
    int first=0, last=0;
    for (int i=1; i<=n; i++) {
        if (ans[i][m]==new_cl) {
            if (!first) first=i;
            last=i;
        }
    }
    if (first==0 || (last>3 && first<n-2)) return;
    if (last<=3 && fix[4][m-1]==old_cl) {
        for (int i=3; i<=5; i++) {
            ans[i][m]=new_cl;
        }
        return;
    }
    if (first>=n-2 && fix[n-3][m-1]==old_cl) {
        for (int i=n-4; i<=n-2; i++) {
            ans[i][m]=new_cl;
        }
        return;
    }
    int x=(last<=3 ? 2 : n-2);
    for (int i=x; i<=x+1; i++) {
        for (int j=m-1; j<=m; j++) {
            if (!fix[i][j]) ans[i][j]=new_cl;
        }
    }
}
void connect_isolated_point(int x, int y) {
    if (ans[x-1][y]==new_cl || ans[x+1][y]==new_cl || ans[x][y+1]==new_cl) return;
    int x1=(x==2 ? 1 : n), x2=(x==2 ? 2 : n-1), x3=(x==2 ? 3 : n-2), x4=(x==2 ? 4 : n-3);
    if (y<=m-2 && ans[x1][y+2]==new_cl) {
        ans[x1][y]=new_cl;
        ans[x1][y+1]=new_cl;
        return;
    }
    if (y<=m-2 && ans[x2][y+2]==new_cl) {
        ans[x2][y+1]=new_cl;
        return;
    }
    if (fix[x4][y]!=old_cl) {
        ans[x3][y]=new_cl;
    } else {
        int y2=(y+1<m ? y+1 : y-1);
        ans[x2][y2]=new_cl;
        ans[x3][y2]=new_cl;
    }
}
void bridge_through_the_stripe(int x) {
    for (int j=2; j<=4; j++) {
        bool good=1;
        for (int i=x-1; i<=x+2; i++) {
            if (fix[i][j]==old_cl) good=0;
        }
        if (good) {
            ans[x][j]=new_cl;
            ans[x+1][j]=new_cl;
            return;
        }
    }
    for (int i=x-1; i<=x+2; i++) {
        if (!fix[i][3]) ans[i][3]=new_cl;
    }
    if (fix[x-1][3]) {
        ans[x-1][2]=old_cl;
        ans[x][4]=new_cl;
    }
    if (fix[x+2][3]) {
        ans[x+2][2]=old_cl;
        ans[x+1][4]=new_cl;
    }
    if (fix[x][3] || fix[x+1][3]) {
        ans[x][2]=new_cl;
        ans[x+1][2]=new_cl;
    }
}
int main()
{
    cin >> t;
    for (int tc=1; tc<=t; tc++) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                fix[i][j]=(c=='B' ? 1 : c=='W' ? 2 : 0);
                ans[i][j]=fix[i][j];
            }
        }
        color_boundary();
        if (change>=4) {
            cout << "NOn";
        } else {
            good_rotation();
            old_cl=ans[1][1], new_cl=3-ans[1][1];
            color_the_stripes();
            avoid_touching();
            boundary_stripe_connection();
            for (int j=2; j<m; j++) {
                if (fix[2][j]==new_cl) connect_isolated_point(2, j);
                if (fix[n-1][j]==new_cl) connect_isolated_point(n-1, j);
            }
            for (int i=6; i<=n-6; i+=4) {
                if (ans[1][1]==ans[i][m] || ans[1][1]==ans[i+1][m]) bridge_through_the_stripe(i);
            }
            while (rotcnt<4) rotate_90();
            cout << "YESn";
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    cout << (ans[i][j]==1 ? "B" : "W");
                }
                cout << "n";
            }
        }
        rotcnt=0, change=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                fix[i][j]=0, ans[i][j]=0;
                fix[j][i]=0, ans[j][i]=0;
            }
        }
    }
    return 0;
}
```
