# Tutorial_(en)

We hope that you have enjoyed this round! Here is the sketch of solutions for the problems. 

### [A. Array and Peaks](../problems/A._Array_and_Peaks.md)

 * Problem Setter: [ajit](https://codeforces.com/profile/ajit "Master ajit")
* Editorialist: [ajit](https://codeforces.com/profile/ajit "Master ajit")

 **Tutorial**
### [1513A - Array and Peaks](../problems/A._Array_and_Peaks.md "Divide by Zero 2021 and Codeforces Round 714 (Div. 2)")

There are many ways to solve this problem. The key idea is we try to use the first $k$ largest elements from $n$ to $n-k+1$ to construct the $k$ peaks. So try constructing the array like this: $1, n, 2, n-1, 3, n-2,..., n-k+1, k+1, k+2,..., n-k$. For this answer to be possible $n-k+1 \gt k+1$ which means $2 \cdot k \lt n$. If this is not the case we output $-1$.

 **Implementation in C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int tests;
     cin>>tests;
     while(tests--)
     {
         int n,k;
         cin>>n>>k;
         vector<int> ans(n+1);
         int num=n;
         for(int i=2;i<n;i+=2)
         {
              if(k==0)break;
              ans[i]=num--;
              k--;
         }
         if(k)
         {
             cout<<-1<<endl;
             continue;
         }
         int cur=1;
         for(int i=1;i<=n;i++)
         {
             if(!ans[i])
             ans[i]=cur++;
         }

         for(int i=1;i<=n;i++)
         cout<<ans[i]<<" ";
         cout<<endl;
     }
}
```
### [B. AND Sequences](../problems/B._AND_Sequences.md)

 * Problem Setter: [ajit](https://codeforces.com/profile/ajit "Master ajit")
* Editorialist: [ajit](https://codeforces.com/profile/ajit "Master ajit")

 **Tutorial**
### [1513B - AND Sequences](../problems/B._AND_Sequences.md "Divide by Zero 2021 and Codeforces Round 714 (Div. 2)")

Consider an arbitrary sequence $b_1,b_2,\dots,b_n$. First let us define the arrays $AND\\_pref$ and $AND\\_suf$ of length $n$ where $AND\\_pref_i = b_1 \: \\& \: b_2 \: \\& \: \dots \: \\& \: b_i$ and $AND\\_suf_i = b_{i} \: \\& \: b_{i+1} \: \\& \: \dots \: \\& \: b_n$ .

According to the definition of good sequence:

$AND\\_pref_1 = AND\\_suf_2$ which means $b_1 = b_2 \: \\& \: b_3 \: \\& \: \dots \: \\& \: b_n$ .

Now $AND\\_pref_2 \leq AND\\_pref_1 = AND\\_suf_2 \leq AND\\_suf_3$. Also according to definition of good sequence, $AND\\_pref_2 = AND\\_suf_3$. This means that $b_1 = AND\\_pref_2 = AND\\_suf_3$. Similarly, for all $i$ from $1$ to $n$, we get $AND\\_pref_i = b_1$ and $AND\\_suf_i = b_1$.

Therefore for the sequence to be good, $b_1 = b_n$ and the $b_i$ must be a super mask of $b_1$ for all $i$ from $2$ to $n-1$.

Initially, we have an array $a_1,a_2,\dots,a_n$. Let the minimum value among these elements be $x$. Let the number of elements that have the value of $x$ be $cnt$.

In order to rearrange the elements of $a_1,a_2,\dots,a_n$ to a good sequence, we need to have $cnt \geq 2$ and the remaining elements need to be a super mask of $x$. If we don't meet this criterion, then the answer is $0$. Else the answer will be $(cnt \cdot (cnt-1) \cdot (n-2)!) \% (10^9+7)$. 

The time complexity is $O(n)$.

 **Implementation in C++**
```cpp
  
#include<bits/stdc++.h>
using namespace std;

void solveTestCase()
{
    int MOD=1e9+7;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    int min1=*min_element(a.begin(),a.end());
    int cnt=0;
    
    for(int x:a)
    {
        if(min1==x)cnt++;
        if((min1&x)!=min1)
        {
            printf("0n");
            return;
        }
    }
    
    int fact=1;
    for(int i=1;i<=n-2;i++)fact=(1LL*fact*i)%MOD;
    int ans=(1LL * cnt * (cnt-1))%MOD;
    ans = (1LL * ans * fact) % MOD;
    printf("%dn",ans);
}

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    solveTestCase();
    return 0;
}

```
### [C. Add One](../problems/C._Add_One.md)

 * Problem Setter: [kalpitk](https://codeforces.com/profile/kalpitk "Master kalpitk")
* Editorialist: [dvshah](https://codeforces.com/profile/dvshah "Master dvshah")

 **Tutorial**
### [1513C - Add One](../problems/C._Add_One.md "Divide by Zero 2021 and Codeforces Round 714 (Div. 2)")

We can solve this problem using 1D dp.

Let $dp_i$ be defined as the length of the string after applying operation $i$-times to the number $10$. Then, 

* $dp_i =2$, $\forall$ $i$ in $[0,8]$
* $dp_i =3$, if $i=9$ (The final number after applying $9$ operations to the number $10$ is $109$.)
* $dp_i =dp_{i-9}+dp_{i-10}$, Otherwise.(length would be the sum of $i-9$ operations and $i-10$ operations.)

 We can precalculate the above table until $m$ (Note: $1 \le m < 2 \cdot 10^5$).Now for each test case, the final answer is:

$ans=\sum_{i=1}^{|s|}\Bigl( \bigr(m+(int)(s[i]-'0')<10 \bigr) ? 1 : dp_{m-10+(int)(s[i]-'0')} \Bigr)$, where $s$ is $n$ (in form of string).

Time Complexity O($m$+$t \cdot $|$s$|), where |$s$| is the number of digits in $n$.

 **Implementation in C++**
```cpp
  
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int max_n = 200005, mod = 1000000007;
int dp[max_n];

signed main(){

    for(int i=0; i<9; i++)dp[i] = 2;
    dp[9] = 3;
    for(int i=10; i<max_n; i++){
        dp[i] = (dp[i-9] + dp[i-10])%mod;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int ans = 0;
        while(n > 0){
            int x = n%10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= mod;
            n/=10;
        }
        cout<<ans<<"n";
    }
    return 0;
}

```
### [D. GCD and MST](../problems/D._GCD_and_MST.md)

 * Problem Setter: [ajit](https://codeforces.com/profile/ajit "Master ajit")
* Editorialist: [ajit](https://codeforces.com/profile/ajit "Master ajit")

 **Tutorial**
### [1513D - GCD and MST](../problems/D._GCD_and_MST.md "Divide by Zero 2021 and Codeforces Round 714 (Div. 2)")

We will iterate from smallest to largest number like in krushkal's algorithm. By this, we will consider the edges with the smallest weight first.

Now, while iterating, we will assume the current value as the gcd we want to get, let's say $g$ and we will go left and then right while going left/right, if $gcd(new\\_element, g) = g$, we will add an edge in the graph between corresponding positions of $new\\_element$ and $g$. Also while adding edge we must keep in mind that we shouldn't create a cycle. If we are forming a cycle, we shouldn't add this edge and stop spanning in that direction. We can use a DSU to check this but in this particular problem, this is not required. We can simply check previously whether there is any edge connected to $new\\_element$. If so, we will add this edge and stop spanning further as any further entry forms a cycle (Think why this is so. Hint: This is because we are adding edges in segments kind of fashion). 

Also, we need to stop when the current $g$ we are considering is greater than the parameter $p$ since we can connect the currently connected components by edges with weight $p$. 

Thus the number of edges considered would be $O(N)$, and then the overall complexity of finding $MST$ would be $O(N \log N)$ due to sorting.

 **Implementation in C++**
```cpp
#include<bits/stdc++.h>
using namespace std;

void solveTestCase()
{
     int n,x;
     cin>>n>>x;
     vector<int> a(n);
     for(int i=0;i<n;i++)cin>>a[i];
     
     //tells whether vertices i and i+1 are connected for 0<=i<n-1
     vector<bool> isConnected(n);
     vector<pair<int,int>> vals;
     
     for(int i=0;i<n;i++)
     vals.push_back(make_pair(a[i],i));

     sort(vals.begin(),vals.end());
     long long int ans=0;
     for(auto p:vals)
     {
         int cur_val=p.first;
         int i=p.second;

         if(cur_val>=x)break;
         
         while(i>0)
         {
              if(isConnected[i-1])break;
              if(a[i-1]%cur_val==0)
              {
                   isConnected[i-1]=true;
                   ans+=cur_val;
                   i--;
              }
              else
              break;
         }
         
         i=p.second;
         while(i<n-1)
         {
             if(isConnected[i])break;
             if(a[i+1]%cur_val==0)
             {
                 isConnected[i]=true;
                 ans+=cur_val;
                 i++;
             }
             else
             break;
         }
         
     }

     for(int i=0;i<n-1;i++)
     {
         if(!isConnected[i])
         ans+=x;
     }

     cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
         solveTestCase();
    }  
    return 0;
}
```
### [E. Cost Equilibrium](../problems/E._Cost_Equilibrium.md)

 * Problem Setter: [7dan](https://codeforces.com/profile/7dan "Expert 7dan")
* Editorialist: [kalpitk](https://codeforces.com/profile/kalpitk "Master kalpitk")

 **Tutorial**
### [1513E - Cost Equilibrium](../problems/E._Cost_Equilibrium.md "Divide by Zero 2021 and Codeforces Round 714 (Div. 2)")

let $S$ = $\sum_0^{n-1}(a_i)$.

The first and foremost condition is that $ S\%n=0 $, and the final values in the beautiful array will be equal to $x=S/n$.

Since a node cannot operate as both, a source and a sink, therefore:

1. Nodes with $values > x$ can only be the source vertices.
2. Nodes with $values < x$ can only be the sink vertices.
3. Nodes with $values = x$ with not be used as a source or a sink.

The given condition, $minimumCost=maximumCost$ condition holds only when at least one of the below condition holds:

1. Number of source vertices are zero or one.
2. Number of sink vertices are zero or one.
3. All the source vertices are before the sink vertices in the permutation.
4. All the source vertices are after the sink vertices in the permutation.

$f(i)$ denotes the factorial of $i$. Thus, the answer would be:

1. If the number of source or sink is less than or equal to one, we need to consider all the unique permutations.$Ans = f(n) / (f(x_1)*f(x_2)*...)$ where $x_1, x_2, \dots$ are frequencies of different values.
2. Else,$Ans = 2 * A * B * C$


	* $A = ($
# ways arranging source nodes$) = f(src) / (f(x_1) * f(x_2) * \dots)$ where $x_1, x_2, \dots$ are frequencies of different values in source nodes.
	* $B = ($
# ways arranging sink nodes$) = f(snk) / (f(x_1) * f(x_2) * \dots)$ where $x_1, x_2, \dots$ are frequencies of different values in sink nodes.
	* $C = ($
# ways filling $(n-src-snk)$ identical values in $(src+snk+1)$ places) = $Binomial(n, src + src)$.
	* We have an additional factor of $2$ to cover the two possibilities: all sources before all sinks, and all sources after all sinks.

The overall complexity of the solution would be $O(n)$.

 **Implementation in C++**
```cpp
#include "bits/stdc++.h"
#define ll long long
#define MOD 1000000007
ll power(ll x,ll y, ll md=MOD){ll res = 1;x%=md;while(y){if(y&1)res = (res*x)%md;x *= x; if(x>=md) x %= md; y >>= 1;}return res;}
 
using namespace std;

#define int long long

#define MAX 100005

vector<int> f(MAX);
vector<int> inv(MAX);

void init() {
	f[0] = 1;
	for(int i=1;i<MAX;i++) f[i] = (f[i-1]*i)%MOD;
	inv[MAX-1] = power(f[MAX-1], MOD-2, MOD);
	for(int i=MAX-2;i>=0;i--) inv[i] = (inv[i+1]*(i+1)) % MOD;

	for(int i=0;i<MAX;i++) assert(inv[i]==power(f[i],MOD-2,MOD));
}

int ncr(int n, int r) {
	if(r > n || r < 0) return 0;

	int ans = f[n];
	ans *= (inv[r] * inv[n - r]) % MOD;
	ans %= MOD;

	return ans;
}

int solve(const vector<int> &v) {

	int n = v.size();
	int s = 0;
	for(auto x: v) s += x;

	if(!(s % n == 0)) return 0;

	int src = 0;
	int snk = 0;

	map<int,int> freqSrc, freqSnk;
	for(auto x: v) {
		if(s / n < x) {
			freqSrc[x]++;
			src ++;
		}
		if(s / n > x) {
			freqSnk[x]++;
			snk ++;
		}
	}

	if(src == 0 && snk == 0) return 1;

    if(src == 1 || snk == 1) {
		int ans = f[n];
		for(auto x: freqSnk) {
			ans = (ans * inv[x.second]) % MOD;
		}
		for(auto x: freqSrc) {
			ans = (ans * inv[x.second]) % MOD;
		}
		ans *= inv[n - src - snk];
		ans %= MOD;
		return ans;
	}

	int ans = (2 * f[src] * f[snk]) % MOD;

	// Divide by freq of repeating elements
	for(auto x: freqSnk) {
		ans = (ans * inv[x.second]) % MOD;
	}
	for(auto x: freqSrc) {
		ans = (ans * inv[x.second]) % MOD;
	}

	int tot = src + snk;
	int left = n - tot;

	// Number of Solution: x_0 + x_1 + x_2 + ... + x_tot = left
	ans = (ans * ncr(left + tot, tot)) % MOD;
	return ans;
}

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	int n;
	cin>>n;

	vector<int> v(n);
	for(auto &x: v) cin>>x;

	cout<<solve(v);
	
}
```
### [F. Swapping Problem](../problems/F._Swapping_Problem.md)

 * Problem Setter: [7dan](https://codeforces.com/profile/7dan "Expert 7dan")
* Editorialist: [mtnshh](https://codeforces.com/profile/mtnshh "Master mtnshh")

 **Tutorial**
### [1513F - Swapping Problem](../problems/F._Swapping_Problem.md "Divide by Zero 2021 and Codeforces Round 714 (Div. 2)")

Let's form 2 sets $X$ and $Y$. $X$ contains those indices $i$ such that $A_i$ < $B_i$ and $Y$ contains those indices $i$ such that $A_i$ > $B_i$. 

We call a segment $L_i$, $R_i$ as $L_i = min(A_i, B_i)$ and $R_i = max(A_i, Bi_i)$

Let break this Question into a series of observation:

Observation 1: 

The answer will reduce by swapping two indexes $i$ and $j$ in $B$ only if: 

1. If an index $i$ belongs to X and $j$ belongs to Y.
2. Segment $i$ and $j$ overlap.

Observation 2:

Based on previous observation, we are now left with only a few cases. WLOG we can fix $A_i$ and $B_i$, and see where our index $j$ be located.

1. $B_j \le A_i$ and $A_i \le A_j \le B_i$
2. $B_j \le A_i$ and $B_i \le A_j$
3. $B_j \ge A_i$ and $A_i \le A_j \le B_i$
4. $B_j \ge A_i$ and $B_i \le A_j$

Observation 3:

We can see that, in each of the cases our final answer changes by, 

$final\\_answer = original\\_answer - 2 * overlap(Segment_i, Segment_j)$

So, the algorithm would like this:

$final\\_answer = original\\_answer - 2 * max(0, A, B)$

$A = max(min(r_i, prefix\\_Maxima(Y, l_i)) - l_i)$ where $(l_i, r_i)$ is a member of X.

$B = max(min(r_i, prefix\\_Maxima(X, l_i)) - l_i)$ where $(l_i, r_i)$ is a member of Y.

$prefix\\_Maxima(P,q)$ gives the maximum value of $r$ such that $l <= q$, where $(l, r)$ is a member of $P$.

$prefix\\_Maxima$ can be implemented using a map, segment tree, or two-pointer approach.

The overall complexity of the solution would be O(n*lg(n))

 **Implementation1 in C++**
```cpp
#include "bits/stdc++.h"
#define ll long long
#define MOD 1000000007
#define inf 1000000000000000000LL
 
using namespace std;

#define int long long


signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	vector<int> a(n), b(n);
	for(auto &x: a) cin>>x;
	for(auto &x: b) cin>>x;

	map<int,int> segX, segY;
	
	for(int i=0;i<n;i++) {
		if(a[i]<=b[i]) {
			if(!segX.count(a[i])) segX[a[i]] = b[i];
			else segX[a[i]] = max(segX[a[i]], b[i]);
		}
		else {
			if(!segY.count(b[i])) segY[b[i]] = a[i];
			else segY[b[i]] = max(segY[b[i]], a[i]);
		}
	}

	// Construct prefix maxima
	int mx = -inf;
	for(auto &x: segX) {
		mx = max(mx, x.second);
		x.second = mx;
	}

	mx = -inf;
	for(auto &x: segY) {
		mx = max(mx, x.second);
		x.second = mx;
	}


	// Find best swap
	int mxGain = 0;
	for(int i=0;i<n;i++) {
		if(a[i]<=b[i]) {
			auto it = segY.upper_bound(a[i]);
			if(it==segY.begin()) continue;

			it--;
			int overlap = min(it->second, b[i]) - a[i];
			mxGain = max(mxGain, 2*overlap);
		}
		else {
			auto it = segX.upper_bound(b[i]);
			if(it==segX.begin()) continue;

			it--;
			int overlap = min(it->second, a[i]) - b[i];
			mxGain = max(mxGain, 2*overlap);
		}
	}

	// Find ans = initial val - mxGain
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += abs(a[i]-b[i]);
	}

	ans -= mxGain;
	cout<<ans;
	
}
```
 **Implementation2 in C++**
```cpp
// created by mtnshh
 
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e18;
#define PI 3.14159265
 
const ll N = 100005;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    
    ll A[n], B[n];
    
    rep(i,0,n)  cin >> A[i];
    rep(i,0,n)  cin >> B[i];

    Vpll x1, x2, y1, y2;

    ll ans = 0;

    rep(i,0,n){

        ans += abs(A[i]-B[i]);

        if(A[i]<B[i]){
            x1.pb({A[i], B[i]});
            x2.pb({B[i], A[i]});
        }
        else{
            y1.pb({A[i], B[i]});
            y2.pb({B[i], A[i]});
        }
    }

    ll fin = ans;

    // 

    set<ll> s1;

    sort(all(x1));
    sort(all(y2));

    ll cur1 = 0;

    for(auto i: x1){

        while(cur1 < y2.size() and y2[cur1].ft <= i.ft){
            s1.insert(y2[cur1].sd);
            cur1++;
        }

        if(s1.size() > 0){
            ll last = *s1.rbegin();
            fin = min(fin, ans - 2 * (min(i.sd, last) - i.ft));
        }

    }

    set<ll> s2;

    sort(all(x1));
    sort(all(y2));

    ll cur2 = 0;

    for(auto i: y2){

        while(cur2 < x1.size() and x1[cur2].ft <= i.ft){
            s2.insert(x1[cur2].sd);
            cur2++;
        }

        if(s2.size() > 0){
            ll last = *s2.rbegin();
            fin = min(fin, ans - 2 * (min(last, i.sd) - i.ft));
        }
        
    }

    cout << fin << endl;

    return 0;
}
```
