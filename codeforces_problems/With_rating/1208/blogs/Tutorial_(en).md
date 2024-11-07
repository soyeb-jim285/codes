# Tutorial_(en)


### [1208A — XORinacci](../problems/A._XORinacci.md)

The sequence is aa, bb, a⊕ba⊕b, aa, bb, a⊕ba⊕b ⋯⋯

Since, the sequence has a period of 33, f[i]=f[imod3]f[i]=f[imod3].   


 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,a,b,n;
    cin>>test;
    while(test--){
        cin>>a>>b>>n;
        switch (n%3){
            case 0:
              cout<<a<<endl;
              break;
            case 1:
              cout<<b<<endl;
              break;
            default:
              cout<<(a^b)<<endl;
        }
    }
    return 0;
}
```
### [1208B — Uniqueness](../problems/B._Uniqueness.md)

After removing a sub-segment, a prefix and a suffix remain, possibly of length 00. Let us fix the prefix which does not contain any duplicate elements and find the maximum suffix we can get without repeating the elements. We can use map/set to keep track of the elements.

Time complexity: O(n2⋅log(n))O(n2⋅log(n))   


 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int ans = n - 1;
    map<int, int> freq; 
    for(int i = 0; i < n; ++i){
        bool validPrefix = true;
        for(int j = 0; j < i; ++j){
            freq[a[j]]++;
            if(freq[a[j]] == 2){
                validPrefix = false;
                break;
            }
        }
        int min_index_suffix = n;
        for(int j = n - 1; j >= i; --j){
            freq[a[j]]++;
            if(freq[a[j]] == 1){
                min_index_suffix = j;
            }
            else break;
        }
        if(validPrefix){
            ans = min(ans, min_index_suffix - i);
        }
        
        freq.clear();
    }
    cout << ans << 'n';
```
 **Bonus**Try to solve this problen in O(n⋅log(n))

### [1208C — Magic Grid](../problems/C._Magic_Grid.md)

Divide the grid into four quadrants. Assign distinct integers to the first quadrant from 00 to (N24−1)(N24−1). Copy this quadrant to the other three. This way XOR of each row and column becomes 00. 

Now, to make numbers distinct among the quadrants, multiply the numbers by 44. Add 11, 22, and 33 to the numbers in 1st1st, 2nd2nd and 3rd3rd quadrants respectively. The XOR of each row and column would still remain 00 as N/2N/2 is also even but the elements will become distinct while being in the range [0,N2−1].[0,N2−1].

Another approach in this problem is to use a 4×44×4 grid given in the sample itself and replicate it in N×NN×N grid by adding 16,32,48⋯16,32,48⋯ to make the elements distinct.

Of course, there are multiple ways to solve the problem. These are just a few of them.   


 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define ld      long double
#define pii     pair<int ,int>
#define pld     pair<ld ,ld>
#define F       first
#define S       second
#define mod     1000000007
#define pb      push_back
#define mp      make_pair
#define all(x)  x.begin(),x.end()
#define mset(x) memset(x, 0, sizeof(x));
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1000;

int n, grid[N][N];
void run(){
    cin >> n;

    /* 
    Divide Grid into Quandrants as follows:
    1 | 2
    -----
    3 | 4
    */

    int fill = 0;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){

            grid[i][j]              = 4*fill + 1;   // 1st quadrant
            grid[i][j + n/2]        = 4*fill + 2;   // 2nd quadrant
            grid[i + n/2][j]        = 4*fill + 3;   // 3rd quadrant
            grid[i + n/2][j + n/2]  = 4*fill;       // 4th quadrant
            
            fill++;

        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(){
    int tests = 1;
    // cin >> tests;
    for(int i = 1; i <= tests; i++) run();
    return 0;
}
```
### [1208D — Restore Permutation](../problems/D._Restore_Permutation.md)

##### **Approach 1**

Let us fill the array with numbers from 11 to NN in increasing order.

11 will lie at the last index ii such that si=0si=0. Find and remove this index ii from the array and for all indices greater than ii, reduce their sisi values by 11. Repeat this process for numbers 2,3,...N2,3,...N. In the ithith turn, reduce the elements by ii.

To find the last index with value zero, we can use segment tree to get range minimum query with lazy propagation.

Time complexity: O(N⋅log(N))O(N⋅log(N))   


 **Code**
```cpp
#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

typedef long long ll;

const ll INF = 1e16 + 239;
const int MAXN = 1e6 + 239;

ll a[MAXN];

namespace SegmentTree {
	int n;
	ll t[4 * MAXN];
	ll mod[4 * MAXN];

	void pull(int v) {
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}

	void apply(int v, ll val) {
		t[v] += val;
		mod[v] += val;
	}

	void push(int v) {
		if (mod[v] != 0) {
			apply(2 * v + 1, mod[v]);
			apply(2 * v + 2, mod[v]);
			mod[v] = 0;
		}
	}

	void build(int v, int l, int r) {
		if (l + 1 == r) {
			t[v] = a[l];
		} else {
			int m = (r + l) >> 1;
			build(2 * v + 1, l, m);
			build(2 * v + 2, m, r);
			pull(v);
		}
	}

	void add(int v, int l, int r, int ql, int qr, ll val) {
		if (r <= ql || qr <= l) {
			return;
		} else if (ql <= l && r <= qr) {
			apply(v, val);
		} else {
			push(v);
			int m = (r + l) >> 1;
			add(2 * v + 1, l, m, ql, qr, val);
			add(2 * v + 2, m, r, ql, qr, val);
			pull(v);
		}
	}

	int go_down(int v, int l, int r) {
		if (l + 1 == r) {
			return l;
		} else {
			push(v);
			int m = (r + l) >> 1;
			int res = -1;
			if (t[2 * v + 2] == 0) {
				res = go_down(2 * v + 2, m, r);
			} else {
				res = go_down(2 * v + 1, l, m);
			}
			pull(v);
			return res;
		}
	}

	void init(int n_) {
		n = n_;
		build(0, 0, n);
	}

	void add(int l, int r, ll val) {
		add(0, 0, n, l, r, val);
	}

	void add(int pos, ll val) {
		add(0, 0, n, pos, pos + 1, val);
	}

	int last_zero() {
		return go_down(0, 0, n);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree::init(n);
	vector<int> ans(n, -1);
	for (int i = 1; i <= n; i++) {
		int pos = SegmentTree::last_zero();
		ans[pos] = i;
		SegmentTree::add(pos, INF);
		SegmentTree::add(pos + 1, n, -i);
	}
	for (auto t : ans) {
		cout << t << ' ';
	}
	cout << endl;
}
```
##### **Approach 2**

For every i from NN to 1, let's say the value of the sisi is x. So it means there are kk smallest unused numbers whose sum is xx. We simply put the k+1k+1st number in the output permutation at this ii, and continue to move left. This can be implemented using BIT and binary lifting.

Thanks to [real.emerald](https://codeforces.com/profile/real.emerald "Expert real.emerald") for expressing the solution in the above words.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long BIT[N], s[N];
int n;
int ans[N];

void update(int x, int delta){
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}

long long query(int x){
     long long sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int searchNumber(long long prefSum){

    int num = 0;
    long long sum = 0;
    for(int i = 21; i>=0 ; --i){
        if((num + (1<<i) <= n) && (sum + BIT[num + (1<<i)] <= prefSum)){
            num += (1<<i);
            sum += BIT[num];
        }
    }
    return num + 1;
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
        update(i, i);
		scanf("%lld", &s[i]);
	}
	for(int i = n; i >= 1; --i){
        ans[i] = searchNumber(s[i]);
        update(ans[i], -ans[i]);
    } 
    for(int i = 1; i <= n; ++i){
        printf("%d", ans[i]);
        if(i < n){
            printf(" ");
        }
        else printf("n");
    }
}
```
### [1208E — Let them slide](../problems/E._Let_Them_Slide.md)

For every array ii from 11 to NN, let us maintain 2 pointers L[i]L[i] and R[i]R[i], representing the range of elements in ithith array, that can be accessed by the current column index jj. 

Initially all L[i]L[i] and R[i]R[i] would be set equal to 0.

As we move from jthjth index to (j+1)th(j+1)th index, some L[i]L[i] and R[i]R[i] would change. Specifically, all those arrays which have size≥min(j,W−j−1)size≥min(j,W−j−1) would have their L[i]L[i] and R[i]R[i] change. 

Since overall movement of L[i]L[i] and R[i]R[i] would be equal to 2⋅2⋅ size_of_array(ii). Overall change would be of order of O(∑a[i])O(∑a[i]). For every array we need range max query in (L[i],R[i])(L[i],R[i]).

We can use multisets/ segment trees/ deques to update the answers corresponding to an array if its L[i],R[i]L[i],R[i] changes. This way we can get complexity O(N)O(N) or O(N⋅log(N))O(N⋅log(N)) depending upon implementation.   


 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
long long ans[N];
vector<pair<int, int> > add_element[N], remove_element[N];
multiset<int> global_ms[N];

int main(){
	int n,w;
	scanf("%d %d", &n, &w);
	for(int i = 0; i < n; ++i){
		int cnt;
		scanf("%d", &cnt);
		for(int j = 0; j < cnt; ++j){
			int x,l,r;
			scanf("%d", &x);
			add_element[j].push_back(make_pair(x, i));
			remove_element[j + w - cnt].push_back(make_pair(x, i));
		}
		if(cnt < w){
			add_element[cnt].push_back(make_pair(0, i));
			remove_element[w - 1].push_back(make_pair(0, i));
			add_element[0].push_back(make_pair(0, i));
			remove_element[w - 1 - cnt].push_back(make_pair(0, i));
		}
	}
	for(int i = 0; i < w; ++i){

		for(auto j:add_element[i]){
			int idx = j.second;
			int val = j.first;
			ans[i] -= (global_ms[idx].empty()? 0: *global_ms[idx].rbegin());
			global_ms[idx].insert(val);
			ans[i] += *global_ms[idx].rbegin();
		}	

		if(i < w - 1){
			ans[i + 1] = ans[i];
			for(auto j:remove_element[i]){
				int idx = j.second;
				int val = j.first;
				ans[i + 1] -= (*global_ms[idx].rbegin());
				global_ms[idx].erase(global_ms[idx].find(val));
				ans[i + 1] += (global_ms[idx].empty()? 0: *global_ms[idx].rbegin());
			}
		}
		printf("%lld ",ans[i]);
	}
	printf("n");
}
```
### [1208F — Bits And Pieces](../problems/F._Bits_And_Pieces.md)

The idea is to first fix some a[i]a[i] and try to get the bits which are off in a[i]a[i] from any 22 elements to the right of ii. Since, we need to maximize the value, we will try to get higher bits first. What we need now is, for every number xx from 00 to 221−1221−1, the 22 right most positions such that the bits present in xx are also present in the elements on those positions. This can be done by iterating over submasks(slow) or SOS-DP(fast).

Once we process the positions for every xx, let us fix some a[i]a[i] and iterate over the bits which are off in a[i]a[i] from the highest to the lowest. Lets say the current maximum we have got is ww and we are going to consider the ythyth bit. We can get this bit if the 22 positions for w|2yw|2y are to the right of ii else we can not.

The final answer would be the maximum of a[i]|wa[i]|w over all ii from 11 to NN.

Time complexity O((M+N)⋅logM)O((M+N)⋅logM) where MM is the max element in the array.   


 **Code**
```cpp
#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        'n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int n,a[1000006],ans,bits;
pii dp[1<<21];

void add(int mask,int w){
    if(dp[mask].x==-1) dp[mask].x=w;
    else if(dp[mask].y==-1){
        if(dp[mask].x==w) return;
        dp[mask].y=w;
        if(dp[mask].x>dp[mask].y) swap(dp[mask].x,dp[mask].y);
    }
    else{
        if(dp[mask].y<w){
            dp[mask].x=dp[mask].y;
            dp[mask].y=w;
        }
        else if(dp[mask].x<w and dp[mask].y!=w) dp[mask].x=w;
    }
}


void merge(int m1,int m2){
    if(dp[m2].x!=-1) add(m1,dp[m2].x);
    if(dp[m2].y!=-1) add(m1,dp[m2].y);
}

void solve(){
	memset(dp,-1,sizeof dp);
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        add(a[i],i);
        bits=max((int)log2(a[i]),bits);
    }
    bits++;
    rep(i,0,bits){
        rep(mask,0,1<<bits){
            if(mask&(1<<i)){
                merge(mask^(1<<i),mask);
            }
        }
    }
    rep(i,0,n){
        int cur=(1<<bits)-1-a[i];
        int opt=0;
        for(int j=bits-1;j>=0;j--){
            if((cur>>j)&1){
                if(dp[opt^(1<<j)].y!=-1 and dp[opt^(1<<j)].x>i){
                    opt^=(1<<j);
                }
            }
        }
        if(dp[opt].y!=-1 and dp[opt].x>i) ans=max(ans,a[i]^opt);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
### [1208G — Polygons](../problems/G._Polygons.md)

If we choose a polygon with side length ll, it is profitable to choose polygons with side lengths as divisors of ll as well, because this will not increase the answer.

So our final set would be such that for every polygon with side length ll, we would have polygons with side length as divisors of ll as well.

All polygons should have at least one common point in the final arrangement, say PP or else we can rotate them and get such PP. For formal proof, please refer [this comment](Tutorial_(en).md?#comment-538545) by [orz](https://codeforces.com/profile/orz "International Master orz").

Let us represent points on the circle as the distance from point PP. Like for kk sided polygon, 00,1k,2k,…k−1k1k,2k,…k−1k.

Now the number of unique fractions over all the polygons would be our answer, which is equal to sum of ϕ(l)ϕ(l) over all side lengths ll of the polygons because for ll sided polygon there will be ϕ(l)ϕ(l) extra points required by it as compared to its divisors.

One observation to get to the final solution is ϕ(l)≥ϕ(divisor(l))ϕ(l)≥ϕ(divisor(l)). So, we can sort the side lengths by their ϕϕ values and take the smallest kk of them. This will minimize the number of points as well as satisfy the property of our set.

**NOTE:** We can not consider polygon of side length 22. This can be handled easily.   


 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
int phi[1000006];
void process_phis(int n){
    iota(phi,phi+n+1,0);
    for(int i = 2 ; i<=n;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(int j=2*i;j<=n;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<3<<endl;
        return 0;
    }
    process_phis(n);
    k+=2;
    sort(phi+1,phi+n+1);
    cout<<accumulate(phi+1,phi+k+1,0LL)<<endl;
    return 0;
}
```
 
### [1208H - Red Blue Tree](../problems/H._Red_Blue_Tree.md "Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2)")

* Transform queries into two types: "change color of a leaf", and "answer color of some vertex if k is given".
* Note that when $k = -\infty$ all internal vertices are red. When increasing $k$, each vertex will change its color exactly once, let's call this value of $k$ as boundary value for this vertex.
* If we can keep boundary values for all vertices, answering queries is easy.
* Let's do sqrt decomposition on queries: group them in blocks and process in blocks of size $m$.
* When starting a block, compress the tree so that there are $O(m)$ interesting vertices: vertices involved in queries and LCAs of them.
* Let's call subtrees without interesting vertices as outer subtrees. We can compute the boundary values for all vertices in outer subtrees once for each block since the colors of leaves do not change.
* Now we should compress the paths between the interesting vertices. Note that the boundary values on a path only depend on the color of the vertex in the bottom end of the path. So for each such path compute two boundary values: if the vertex in the bottom end is red or blue.
* Now we can process queries by using the corresponding values of boundary values, going down-up.
* Straightforward implementation leads to $O(n\log{n})$ preprocessing of each block and $O(m\log{n})$ query time, meaning the overall complexity is $O((n + q) \sqrt{n + q} \log{n})$. The logarithms are from sorting and binary search, respectively, so this solution is already fast enough to get AC.
* To implement compression in $O(n)$ you need to go from lowest to highest possible $k$ and maintain which vertices are red in outer subtrees. Note that the number of different boundary values is $O(n)$, so you can store for each $k$ the list of vertices having this boundary value.
* To implement queries in $O(m)$, you need to precompute binary search outcomes for the given $O(m)$ values while computing the boundary values.
* This way the overall complexity becomes $O((n + q) \sqrt{n + q})$.
 **Code**
```cpp
/**
 * This line was copied from template
 * This is nk_sqrt_300.cpp
 * 
 * @author: Nikolay Kalinin
 * @date: Fri, 23 Aug 2019 22:28:23 +0300
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;
const int infk = maxn;

const int BSZ = 700;

vector<int> gr[maxn];
vector<int> dead_ends[maxn];
int th[maxn][2];
int threshold[maxn];
int up[maxn], fastup[maxn];
bool isleaf[maxn];
int curcnt[maxn];
int was[maxn];
int curk, curkid;
int n;
int timer;
int c[maxn];
bool isinteresting[maxn];
vector<int> interesting;
pair2<int> qs[BSZ];
vector<int> at[2 * BSZ];
queue<int> q;
int path[maxn];
vector<int> ks;
vector<int> cntdead[2 * BSZ];
int intid[maxn];
vector<int> order;
int newid[maxn];
vector<int> grinit[maxn];
int compk[2 * infk + 5];

void leavedesc(int cur, int pr)
{
    newid[cur] = order.size();
    up[newid[cur]] = newid[pr];
    order.pb(cur);
    for (int i = 0; i < (int)grinit[cur].size(); i++)
    {
        if (grinit[cur][i] == pr)
        {
            swap(grinit[cur][i], grinit[cur].back());
            grinit[cur].pop_back();
            i--;
        } else
        {
            leavedesc(grinit[cur][i], cur);
        }
    }
}


inline void computecolor(int cur)
{
    if (was[cur] != timer) curcnt[cur] = 0;
    int cntred = curcnt[cur];
    cntred += (int)cntdead[intid[cur]].size() <= curkid ? cntdead[intid[cur]].back() : cntdead[intid[cur]][curkid];
    int cntblue = (int)gr[cur].size() - cntred;
    if (cntblue - cntred >= curk) c[cur] = 1;
    else c[cur] = 0;
}

inline void pushtoparent(int cur)
{
    if (cur == 0) return;
    int par = fastup[cur];
    
    int colorup = 1 - (curk >= th[cur][c[cur]]);
    
    if (was[par] != timer)
    {
        was[par] = timer;
        curcnt[par] = 0;
    }
    curcnt[par] += 1 - colorup;
}

int main()
{
    scanf("%d%d", &n, &curk);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        grinit[u].pb(v);
        grinit[v].pb(u);
    }
    leavedesc(0, -1);
    
    for (int i = 0; i < n; i++)
    {
        for (auto t : grinit[i]) gr[newid[i]].pb(newid[t]);
    }
    
    for (int i = 0; i < n; i++) scanf("%d", &c[newid[i]]);
        
    for (int i = 0; i < n; i++) if (c[i] != -1) isleaf[i] = true;
    int nq;
    scanf("%d", &nq);
    for (int lq = 0; lq < nq; lq += BSZ)
    {
        int rq = min(nq, lq + BSZ);
        memset(isinteresting, 0, sizeof isinteresting);
        ks.clear();
        ks.pb(curk);
        for (int q = lq; q < rq; q++)
        {
            int t;
            scanf("%d", &t);
            if (t == 1)
            {
                int v;
                scanf("%d", &v);
                v--;
                v = newid[v];
                isinteresting[v] = true;
                qs[q - lq] = {v, -1};
            } else if (t == 2)
            {
                int v, newc;
                scanf("%d%d", &v, &newc);
                v--;
                v = newid[v];
                isinteresting[v] = true;
                qs[q - lq] = {v, newc};
            } else
            {
                int newk;
                scanf("%d", &newk);
                qs[q - lq] = {-1, newk};
                ks.pb(newk);
            }
        }
        
        sort(all(ks));
        ks.resize(unique(all(ks)) - ks.begin());
        int kssz = ks.size();
        ks.pb(infk);
        int curcompkid = 0;
        for (int i = -infk; i <= infk; i++)
        {
            compk[i + infk] = curcompkid;
            if (curcompkid < kssz && ks[curcompkid] == i) curcompkid++;
        }


        isinteresting[0] = true;
        interesting.clear();

        for (int i = 0; i <= kssz; i++) at[i].clear();

        for (int cur = 0; cur < n; cur++)
        {
            dead_ends[cur].clear();
            path[cur] = -1;
            if (isinteresting[cur])
            {
                path[cur] = -2;
            }
        }

        for (int cur = n - 1; cur >= 0; cur--)
        {
            int ret = -1;
            if (isinteresting[cur])
            {
                intid[cur] = interesting.size();
                interesting.pb(cur);
                cntdead[intid[cur]].clear();
                cntdead[intid[cur]].pb(0);
            }
            if (path[cur] == -1)
            {
                if (isleaf[cur])
                {
                    if (c[cur] == 0) at[compk[-infk + infk]].pb(cur);
                    else at[compk[infk + infk]].pb(cur);
                } else
                {
                    curcnt[cur] = 0;
                    int cntred = 0;
                    int cntblue = gr[cur].size();
                    at[compk[cntblue - cntred + 1 + infk]].pb(cur);
                }
            } else if (path[cur] == -2)
            {
                ret = cur;
            } else
            {
                ret = path[cur];
            }
            if (cur == 0) break;
            if (ret == -1) continue;
            
            if (path[up[cur]] == -1) path[up[cur]] = ret;
            else if (path[up[cur]] >= 0)
            {
                isinteresting[up[cur]] = true;
                fastup[path[up[cur]]] = up[cur];
                fastup[ret] = up[cur];
                path[up[cur]] = -2;
            } else
            {
                fastup[ret] = up[cur];
            }
        }
        
        timer++;
        for (int i = 0; i <= kssz; i++)
        {
            for (auto t : at[i]) q.push(t);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                if (was[cur] == timer) continue;
                was[cur] = timer;
                if (path[up[cur]] == -1)
                {
                    curcnt[up[cur]]++;
                    int cntred = curcnt[up[cur]];
                    int cntblue = gr[up[cur]].size() - cntred;
                    if (cntblue - cntred + 1 <= ks[i]) q.push(up[cur]);
                    else at[compk[cntblue - cntred + 1 + infk]].pb(up[cur]);
                } else if (path[up[cur]] == -2)
                {
                    int id = intid[up[cur]];
                    while ((int)cntdead[id].size() <= i) cntdead[id].pb(cntdead[id].back());
                    cntdead[id].back()++;
                } else { // in path
                    dead_ends[up[cur]].pb(ks[i]);
                }
            }
        }
        
        for (int cur = n - 1; cur >= 0; cur--) if (path[cur] != -1)
        {
            int cntchildren = gr[cur].size();
            if (path[cur] == -2)
            {
                th[cur][0] = -infk;
                th[cur][1] = +infk;
            } else
            {
                th[cur][0] = cntchildren + 1;
                th[cur][1] = cntchildren + 1;
                th[cur][0] = min(th[cur][0], max(th[path[cur]][0], cntchildren - 1 - 1 + 1));
                th[cur][1] = min(th[cur][1], max(th[path[cur]][1], cntchildren - 1 - 1 + 1));
                for (int i = 0; i < (int)dead_ends[cur].size(); i++)
                {
                    int cntred = i + 1;
                    int cntblue = cntchildren - cntred;
                    th[cur][0] = min(th[cur][0], max(dead_ends[cur][i], cntblue - cntred + 1));
                    th[cur][1] = min(th[cur][1], max(dead_ends[cur][i], cntblue - cntred + 1));
        
                    cntred = i + 1 + 1;
                    cntblue = cntchildren - cntred;
                    th[cur][0] = min(th[cur][0], max(max(th[path[cur]][0], dead_ends[cur][i]), cntblue - cntred + 1));
                    th[cur][1] = min(th[cur][1], max(max(th[path[cur]][1], dead_ends[cur][i]), cntblue - cntred + 1));
                }
                th[path[cur]][0] = th[cur][0];
                th[path[cur]][1] = th[cur][1];
            }
        }
        
        
        ::curkid = lower_bound(all(ks), curk) - ks.begin();
        for (int q = 0; q < rq - lq; q++)
        {
            timer++;
            if (qs[q].fi == -1)
            {
                curk = qs[q].se;
                ::curkid = lower_bound(all(ks), curk) - ks.begin();
            } else if (qs[q].se != -1) c[qs[q].fi] = qs[q].se;
            else
            {
                for (auto v : interesting)
                {
                    if (!isleaf[v]) computecolor(v);
                    pushtoparent(v);
                }
                printf("%dn", c[qs[q].fi]);
            }
        }
    }
    return 0;
}

```
