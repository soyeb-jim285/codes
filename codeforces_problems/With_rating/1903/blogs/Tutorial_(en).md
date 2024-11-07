# Tutorial_(en)

Problems A, B, C, D1 and E were authored by me and [Adam_GS](https://codeforces.com/profile/Adam_GS "Grandmaster Adam_GS") authored D2 and F.

[1903A - Halloumi Boxes](../problems/A._Halloumi_Boxes.md "Codeforces Round 912 (Div. 2)")

 **Hint**If k is greater or equal to 2 you can always swap adjacent elements.

 **Solution**
### [1903A - Halloumi Boxes](../problems/A._Halloumi_Boxes.md "Codeforces Round 912 (Div. 2)")

If the array is already sorted or k>1 then there is always a way (reverse of size 2= swap consecutive elements). Else it is not possible since when k=1 the array remains the same.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        if(is_sorted(arr,arr+n) || k > 1){
            cout<<"YESn";
        }
        else{
            cout<<"NOn";
        }
    }
    return 0;
}
```
 **Rate this problem**Good 


[*498*](https://codeforces.com/data/like?action=like "I like this")





Mid 

 
[*118*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*52*](https://codeforces.com/data/like?action=like "I like this")



[1903B - StORage room](../problems/B._StORage_room.md "Codeforces Round 912 (Div. 2)")

 **Hint**Think of each bit independently.

 **Solution**
### [1903B - StORage room](../problems/B._StORage_room.md "Codeforces Round 912 (Div. 2)")

Solution:

Initially, we set all ai=230−1 (all bits on).

You can through every i,j such that i≠j and do ai&=Mi,j and aj&=Mi,j.

Then we check if Mi,j=ai|aj for all pairs. If this holds you found the array else the answer is NO.

Proof:

Initially, all elements have all their bits set on and we remove only the bits that affect our answer. If Mi,j doesn't have a specific bit then definitely neither ai nor aj should have it. If Mi,j has a specific bit on then we don't have to remove anything (in the end we want at least one of ai and aj to have the bit on).

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m[n][n];
        int arr[n];
        for(int i = 0;i < n;i++){
            arr[i] = (1<<30) - 1;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin>>m[i][j];
                if(i != j){
                    arr[i] &= m[i][j];
                    arr[j] &= m[i][j];
                }
            }
        }
        bool ok = true;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j && (arr[i] | arr[j]) != m[i][j]){
                    ok = false;
                }
            }
        }
        if(!ok){
            cout<<"NOn";
        }
        else{
            cout<<"YESn";
            for(int i = 0;i < n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"n";
        }
    }
}
```
 **Rate this problem**Good 

 
[*572*](https://codeforces.com/data/like?action=like "I like this")



Mid 

 
[*50*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*178*](https://codeforces.com/data/like?action=like "I like this")



[1903C - Theofanis' Nightmare](../problems/C._Theofanis'_Nightmare.md "Codeforces Round 912 (Div. 2)")

 **Hint**Think of suffixes.

 **Solution**
### [1903C - Theofanis' Nightmare](../problems/C._Theofanis'_Nightmare.md "Codeforces Round 912 (Div. 2)")

Let sufi be the suffix sum of the array (from the ith position to the nth).

ans= sum of sufLi where Li is the leftmost element of the ith subarray.

Definitely, L1=1 and we can take any other we want (at most once). So we start with ans=suf1 and for every i>1 we add sufi if it is positive.

We can easily see that this greedy works.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        long long suf[n+1] = {0};
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        for(int i = n-1;i >= 0;i--){
            suf[i] = suf[i+1] + arr[i];
        }
        long long ans = suf[0];
        for(int i = 1;i < n;i++){
            if(suf[i] > 0){
                ans += suf[i];
            }
        }
        cout<<ans<<"n";
    }
}
```
 **Rate this problem**Good 

 
[*579*](https://codeforces.com/data/like?action=like "I like this")



Mid 

 
[*51*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*158*](https://codeforces.com/data/like?action=like "I like this")



[1903D1 - Maximum And Queries (easy version)](../problems/D1._Maximum_And_Queries_(easy_version).md "Codeforces Round 912 (Div. 2)")

 **Hint**Try using greedy to construct the answer bit by bit.

 **Solution**
### [1903D1 - Maximum And Queries (easy version)](../problems/D1._Maximum_And_Queries_(easy_version).md "Codeforces Round 912 (Div. 2)")

Construct the answer by iterating through every single bit from large to small (260 to 20).

Denote x a the current answer and b a the bit we want to add. 

For each i (1≤i≤n) if the b-th bit in ai is on we do not need to use any operations. If the b-th bit in ai is 0 then we need to increase ai by 2b−ai mod 2b.

If the total number of operations required to get from x to x+2b is smaller than k, decrease k by that number and change the array accordingly. Otherwise do nothing.

 **Code (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
ll T[LIM], P[LIM], n, k;
void solve() {
  rep(i, n) T[i]=P[i];
  ll ans=0;
  for(ll i=60; i>=0; --i) {
    ll sum=0;
    rep(j, n) {
      if(T[j]&(1ll<<i)) continue;
      ll p=(T[j]/(1ll<<i))*(1ll<<i)+(1ll<<i);
      p+=ans^(p&ans);
      sum+=p-T[j];
      if(sum > k){
          break;
      }
    }
    if(sum>k) continue;
    rep(j, n) {
      if(T[j]&(1ll<<i)) continue;
      ll p=(T[j]/(1ll<<i))*(1ll<<i)+(1ll<<i);
      p+=ans^(p&ans);
      T[j]=p;
    }
    ans+=1ll<<i;
    k-=sum;
  }
  cout << ans << 'n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> q;
  rep(i, n) cin >> P[i];
  while(q--) {
    cin >> k;
    solve();
  }
} 
```
 **Rate this problem**Good 

 
[*252*](https://codeforces.com/data/like?action=like "I like this")



Mid 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*56*](https://codeforces.com/data/like?action=like "I like this")



[1903D2 - Maximum And Queries (hard version)](../problems/D2._Maximum_And_Queries_(hard_version).md "Codeforces Round 912 (Div. 2)")

 **Hint**Try optimizing the greedy approach from O(n) to O(1).

 **Solution**
### [1903D2 - Maximum And Queries (hard version)](../problems/D2._Maximum_And_Queries_(hard_version).md "Codeforces Round 912 (Div. 2)")

Let S=∑(220−ai). If k≥S then the answer is 220+⌊k−Sn⌋.

Similarly to D1 let's construct the answer bit by bit. Let x be the current answer and b be the bit we want to add. 

Let's look at the amount of operations we need to do on the i-th element to change our answer from x to x+2b.

* if x is not a submask of ai, then after constructing answer x it has 0s on all bits not greater than b. In this case we need to increase the i-th element by 2b.
* if x+2b is a submask of ai, then we do not need to increase the i-th element.
* otherwise we need to increase the i-th element by 2b−ai mod 2b.

We can handle all three cases efficiently if we precompute the following two arrays:

A(mask) – how many elements from the array is mask a submask of.

B(mask,b) – sum of ai mod 2b over all ai for which x is a submask.

Both arrays can be calculated efficiently using SOS dp.

This allows us to answer the queries in O(q×log a) with O(a log2 a) preprocessing

 **Code (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
ll dpsum[1<<20][20], dpcnt[1<<20], T[LIM];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, q;
  cin >> n >> q;
  ll sto=0, sfrom=0;
  rep(i, n) {
    cin >> T[i];
    sto+=(1ll<<20ll)-T[i];
    sfrom+=T[i];
    ++dpcnt[T[i]];
    ll sum=0;
    rep(j, 20) {
      sum+=T[i]&(1ll<<j);
      dpsum[T[i]][j]+=sum;
    }
  }
  rep(i, 20) rep(j, 1<<20) if(!(j&(1<<i))) dpcnt[j]+=dpcnt[j+(1<<i)];
  rep(i, 20) rep(j, 1<<20) if(!(j&(1<<i))) rep(l, 20) dpsum[j][l]+=dpsum[j+(1<<i)][l];
  while(q--) {
    ll k;
    cin >> k;
    if(k>=sto) {
      k+=sfrom;
      cout << k/n << 'n';
      continue;
    }
    ll ans=0;
    for(ll i=19; i>=0; --i) {
      ll x=(n-dpcnt[ans|(1<<i)])*(1ll<<i);
      x-=dpsum[ans][i]-dpsum[ans|(1<<i)][i];
      if(x<=k) {
        k-=x;
        ans|=1<<i;
      }
    }
    cout << ans << 'n';
  }
}
 

```
 **Rate this problem**Good 

 
[*106*](https://codeforces.com/data/like?action=like "I like this")



Mid 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")



[1903E - Geo Game](../problems/E._Geo_Game.md "Codeforces Round 912 (Div. 2)")

 **Hint**Do mod 2 in all coordinates and see how many different types of points you have in the end.

 **Solution**
### [1903E - Geo Game](../problems/E._Geo_Game.md "Codeforces Round 912 (Div. 2)")

If we went from point (a,b) to (c,d) then we will add to the sum a2+c2−2ac+b2+d2−2bd which is equal to a⊕b⊕c⊕d mod 2 (⊕ is bitwise xor).

For each point, we find (x mod 2) ⊕ (y mod 2).

Let p0= the number of (x mod 2) ⊕ (y mod 2) ==0, p1= the number of (x mod 2) ⊕ (y mod 2) ==1 and v= (sx mod 2) ⊕ (sy mod 2).

Let's say that we create a binary string starting with v and has another p0 zeros and p1 ones.

If the number of si≠si+1 is odd then the sum will be odd otherwise the sum will be even.

If you are the first player then you want to have an even number of si≠si+1.

That holds iff the first element of s is the same as the last element of s.

Thus, the second player will want to put all pv occurrences of v before the end (so that the last element is not equal to the first).

He can do this iff pv<(n−1)/2 (rounded down) (this means that pv<pv⊕1).

If pv⊕1≤pv you play as the first player and you choose occurrences of v⊕1 until there aren't any

and else (pv<pv⊕1) you play as the second player and you choose occurrences of v until there aren't any.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sx,sy;
        cin>>sx>>sy;
        int x[n],y[n];
        set<int>p[2];
        for(int i = 0;i < n;i++){
            cin>>x[i]>>y[i];
            p[(x[i] % 2) ^ (y[i] % 2)].insert(i+1);
        }
        int v = (sx % 2) ^ (sy % 2);
        if(p[v].size() >= p[v^1].size()){
            cout<<"First"<<endl;
            v ^= 1;
            for(int i = 0;i < n;i++){
                if(i % 2 == 0){
                    int j;
                    if(!p[v].empty()){
                        j = (*p[v].begin());
                        p[v].erase(j);
                    }
                    else{
                        j = (*p[v^1].begin());
                        p[v^1].erase(j);
                    }
                    cout<<j<<endl;
                }
                else{
                    int j;
                    cin>>j;
                    if(p[0].count(j)){
                        p[0].erase(j);
                    }
                    else{
                        p[1].erase(j);
                    }
                }
            }
        }
        else{
            cout<<"Second"<<endl;
            for(int i = 0;i < n;i++){
                if(i % 2 == 1){
                    int j;
                    if(!p[v].empty()){
                        j = (*p[v].begin());
                        p[v].erase(j);
                    }
                    else{
                        j = (*p[v^1].begin());
                        p[v^1].erase(j);
                    }
                    cout<<j<<endl;
                }
                else{
                    int j;
                    cin>>j;
                    if(p[0].count(j)){
                        p[0].erase(j);
                    }
                    else{
                        p[1].erase(j);
                    }
                }
            }
        }
    }
}
```
 **Rate this problem**Good 

 
[*129*](https://codeforces.com/data/like?action=like "I like this")



Mid 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*31*](https://codeforces.com/data/like?action=like "I like this")



[1903F - Babysitting](../problems/F._Babysitting.md "Codeforces Round 912 (Div. 2)")

 **Hint**Use binary search the answer and 2-sat.

 **Solution**
### [1903F - Babysitting](../problems/F._Babysitting.md "Codeforces Round 912 (Div. 2)")

We can solve this problem using 2-sat and binary search the answer. 

In order to have a vertex cover we should have (ui|vi). 

And if we want to check if the answer is greater or equal to mid we want to have (!x|!y) for all pairs 1≤x,y≤n such that |x−y|<mid.

However, this way we will have too many edges. 

To fix this problem we can create some helping nodes and edges in a similar structure of a segment tree.

In 2-sat when we connect two nodes there are two possibilities for each (taken or not taken). If we have an edge from a to b it means that when a holds then definitely also b holds. 

So, we build a binary tree in a similar structure to a segment tree so that each node is connected to two children creating a binary-directed tree and each node corresponds to a range. When we want to have edges from x to [x+1,x+mid) and (x−mid,x−1] we just choose the nodes in this binary tree that are needed to make the range (they are at most log(n)).

So that makes the total time complexity to: O(Mlog2(n))

There is also an O(Mlog(n)) solution. Shootout to jeroenodb for pointing it out.

The idea is similar. 

We use 2-sat and binary search the answer, however, this time we do 2-sat differently. 

In our graph, we will have the m edges to have a vertex cover. So we should have (ui|vi). 

We add those edges and then we should also have the edges corresponding to (!x|!y) for all pairs 1≤x,y≤n such that |x−y|<mid. 

But we don't need all of them. We can just only go to first to the left and first to the right by storing the set of unvisited nodes and doing lower bound with dsu. 

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
vector<vector<ll> >adj,rev;
vector<ll>order;
vector<ll>vis,comp;
ll c;
ll cur;
ll val(ll idx,bool v){
    return cur + (2 * idx + v);
}
void dfs1(ll idx){
    vis[idx] = true;
    for(auto x:adj[idx]){
        if(!vis[x]){
            dfs1(x);
        }
    }
    order.pb(idx);
}
void dfs2(ll idx){
    comp[idx] = c;
    for(auto x:rev[idx]){
        if(!comp[x]){
            dfs2(x);
        }
    }
}
void build(ll s,ll e,ll idx){
    if(s == e){
        adj[idx].pb(val(s,0));
        rev[val(s,0)].pb(idx);
        return;
    }
    ll mid = (s+e)/2;
    build(s,mid,idx*2);
    build(mid+1,e,idx*2+1);
    adj[idx].pb(idx*2);
    adj[idx].pb(idx*2+1);
    rev[idx*2].pb(idx);
    rev[idx*2+1].pb(idx);
}
void update(ll s,ll e,ll qs,ll qe,ll idx,ll k){
    if(qs <= s && e <= qe){
        adj[val(k,1)].pb(idx);
        rev[idx].pb(val(k,1));
        return;
    }
    if(s > qe || qs > e){
        return;
    }
    ll mid = (s+e)/2;
    update(s,mid,qs,qe,idx*2,k);
    update(mid+1,e,qs,qe,idx*2+1,k);
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll u[m],v[m];
        f(i,0,m){
            cin>>u[i]>>v[i];
        }
        ll l = 1,r = n;
        ll ans = 1;
        cur = 4*n;
        while(l <= r){
            ll mid = (l+r)/2;
            order.clear();
            vis.assign(6*n+5,0);
            comp.assign(6*n+5,0);
            adj.assign(6*n+5,vector<ll>());
            rev.assign(6*n+5,vector<ll>());
            f(i,0,m){
                adj[val(u[i],0)].pb(val(v[i],1));
                adj[val(v[i],0)].pb(val(u[i],1));
                rev[val(u[i],1)].pb(val(v[i],0));
                rev[val(v[i],1)].pb(val(u[i],0));
            }
            build(1,n,1);
            f(k,1,n+1){
                ll l = max(1,k - mid + 1),r = k-1;
                update(1,n,l,r,1,k);
                l = k+1;
                r = min(n,k + mid - 1);
                update(1,n,l,r,1,k);
            }
            bool ok = true;
            c = 1;
            f(i,1,n+1){
                if(!vis[val(i,0)]){
                    dfs1(val(i,0));
                }
                if(!vis[val(i,1)]){
                    dfs1(val(i,1));
                }
            }
            reverse(order.begin(),order.end());
            for(auto x:order){
                if(!comp[x]){
                    dfs2(x);
                    c++;
                }
            }
            f(i,1,n+1){
                ok &= comp[val(i,0)] != comp[val(i,1)];
            }
            if(ok){
                l = mid + 1;
                ans = max(ans,mid);
            }
            else{
                r = mid - 1;
            }
        }
        cout<<ans<<"n";
    }
}
```
 **jeroenodb's solution O(M log N)**
```cpp
#pragma GCC optimize("O3")
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<basic_string<int>> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
template<int (*merge)(int,int), int (*init)(int)> struct DSU{
    vi sz, dat;
    DSU(int n) : sz(n,-1),dat(n) {
        for(int i=0;i<n;++i) dat[i] = init(i);
    }
    void link(int a, int b) {
        if(sz[a]>sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        sz[b]=a;
        dat[a] = merge(dat[a],dat[b]);
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int get(int i) {
        return dat[find(i)];
    }
    int find(int a) {
        if(sz[a]<0) return a;
        return sz[a] = find(sz[a]);
    }
};
int dec(int i) {return i-1;}
int inc(int i) {return i+1;}
int mymin(int a, int b) {return min(a,b);}
int mymax(int a, int b) {return max(a,b);}
bool solve(const vvi& adj, const vvi& rev, int mid) {
    int n = rev.size()/2;

    DSU<mymin, dec> dsuL(n);
    DSU<mymax, inc> dsuR(n);
    auto getL = [&](int i) {
        if(i>=n) i-=n;
        int l = dsuL.get(i);
        if(l==-1 or abs(i-l)>=mid) return 0;
        return l+1;
    };
    auto getR = [&](int i) {
        if(i>=n) i-=n;
        int r = dsuR.get(i);
        if(r==n or abs(i-r)>=mid) return 0;
        return r+1;
    };
    auto rem = [&](int at) {
        if(at>=n) at-=n;
        if(at) dsuR.unite(at-1,at);
        if(at+1<n) dsuL.unite(at,at+1);
    };
    vector<bool> vis(n*2);
    vi ord;
    auto dfs = [&](auto&& self, int at) -> void {
        vis[at]=1;
        if(at<n) {
            while(int l = getL(at)) self(self,l-1+n);
            while(int r = getR(at)) self(self,r-1+n);
        } else rem(at);
        for(int to : adj[at]) if(!vis[to]) self(self,to);
        ord.push_back(at);

    };
    for(int i=0;i<2*n;++i) if(!vis[i]) dfs(dfs,i);
    reverse(all(ord));

    fill(all(vis),0);
    dsuL = DSU<mymin,dec>(n);
    dsuR = DSU<mymax,inc>(n);
    int comp=0;
    vi comps(2*n);
    auto dfs2 = [&](auto&& self, int at) -> void {
        comps[at]=comp;
        vis[at]=1;
        if(at>=n) {
            while(int l = getL(at)) self(self,l-1);
            while(int r = getR(at)) self(self,r-1);
        } else rem(at);
        for(int to : rev[at]) if(!vis[to]) self(self,to);

    };

    for(int i : ord) if(!vis[i]) {
        dfs2(dfs2,i);
        comp++;
    }
    for(int i=0;i<n;++i) if(comps[i]==comps[i+n]) return false;
    return true;


}
void solve() {
    int n,m; cin >> n >> m;
    vvi adj(2*n),rev(2*n);
    auto addE = [&](int u, int v) {
        adj[u].push_back(v);
        rev[v].push_back(u);
    };
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        addE(u+n,v);
        addE(v+n,u);
    }

    int lo=1,hi=n;
    while(lo<hi) {
        int mid = (lo+hi+1)/2;
        if(solve(adj,rev,mid)) {
            lo= mid;
        } else hi = mid-1;
    }
    cout << lo << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}
```
 **Rate this problem**Good 

 
[*72*](https://codeforces.com/data/like?action=like "I like this")



Mid 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")



Bad 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")



