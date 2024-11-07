# Tutorial_(en)

We are really sorry that C is tough and E is easier than D. But anyway hope you can enjoy the problems themselves and learn something from them.

[1806A - Walking Master](../problems/A._Walking_Master.md "Codeforces Round 858 (Div. 2)")

 **Solution**
### [1806A - Walking Master](../problems/A._Walking_Master.md "Codeforces Round 858 (Div. 2)")

Hint 1: The value of $b$ is always non-decreasing, and the value of $a-b$ is always non-increasing.

It is possible to move from $(a,b)$ to $(c,d)$ if and only if $d\ge b$ and $a-b\ge c-d$, since the value of $b$ is always non-decreasing and the value of $a-b$ is always non-increasing.

If it is possible, the answer is $(d-b)+((a+d-b)-c)$. One possible way is $(a,b)\to (a+d-b,d)\to (c,d)$.

Another way to understand this: $(a,b)\to (a+d-b,d)\to (c,d)$ is always a valid path if it is possible to move from $(a,b)$ to $(c,d)$. So first let $a\leftarrow a+(d-b)$ and $b\leftarrow d$, then the answer only depends on $a$ and $c$.

 **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=500005;
const int inf=0x3f3f3f3f;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b<=d&&c<=a+d-b) {
			cout<<(d-b)+(a+d-b-c)<<"n";
		} else {
			cout<<"-1n";
		}
	}
}
```
[1806B - Mex Master](../problems/B._Mex_Master.md "Codeforces Round 858 (Div. 2)")

 **Solution**
### [1806B - Mex Master](../problems/B._Mex_Master.md "Codeforces Round 858 (Div. 2)")

Hint 1: $ans\le 2$.

First, let's determine if $ans$ can be $0$. That means we can't place two $0$s next to each other. This is achievable when the number of $0$s is not greater than $\lceil\frac{n}{2}\rceil$.

Then determine if $ans$ can be $1$. That means we can't place $0$ and $1$ next to each other. Therefore, if there is no $1$ in $a$ or there exist an element $x\ge 2$ in $a$, we can simply rearrange $a$ as $[0,0,\ldots,0,x,1,1,\ldots]$ to make $ans=1$.

The last case：there are only $0$ and $1$ in $a$ and the number of $0$s is greater than $\lceil\frac{n}{2}\rceil$. We want to make $ans=2$ which is the minimum. Since the number of $1$s is not greater than the number of $0$s, we can rearrange $a$ as $[0,1,0,1,\ldots,0,1,0,0,\ldots]$ to make $ans=2$.

 **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		int sum0=0;
		bool f=false;
		for(int i=1;i<=n;i++) {
			int x;
			cin>>x;
			if(x==0) {
				sum0++;
			} else if(x>=2) {
				f=true;
			}
		}
		if(sum0<=(n+1)/2) {
			cout<<"0n";
		} else if(f||sum0==n) {
			cout<<"1n";
		} else {
			cout<<"2n";
		}
	}
}
```
[1806C - Sequence Master](../problems/C._Sequence_Master.md "Codeforces Round 858 (Div. 2)")

 **Solution**
### [1806C - Sequence Master](../problems/C._Sequence_Master.md "Codeforces Round 858 (Div. 2)")

Hint 1: The number of good sequences is small.

Hint 2: Consider two cases: all elements in $q$ are (not) equal.

In case that all elements in $q$ are equal, we have $q_1^n=nq_1$. The integer solutions to this equation is $q_1=0$, $n=1$ or $(q_1,n)=(2,2)$.

In the other case, we can see that the constraints are strong, so let's list some equations to find good sequences, using the property that not all elements are equal.

Let $q$ be such a good sequence. WLOG $q_1\neq q_2$. Then we have:

$$ q_1\cdot q_3q_4\cdots q_{n+1}=q_2+q_{n+2}+q_{n+3}+\cdots+q_{2n}\tag{1} $$

$$ q_2\cdot q_3q_4\cdots q_{n+1}=q_1+q_{n+2}+q_{n+3}+\cdots+q_{2n}\tag{2} $$

Substract $(2)$ from $(1)$:

$$ (q_1-q_2)q_3q_4\cdots q_{n+1}=q_2-q_1\\\ \iff (q_1-q_2)(q_3q_4\cdots q_{n+1}+1)=0 $$

Since $q_1-q_2\neq 0$, there must be $q_3q_4\cdots q_{n+1}=-1$.

Similarly, for each exactly $n-1$ numbers in $q_3,q_4,\cdots,q_{2n}$, their product will be $-1$, which leads to $q_3=q_4=\cdots =q_{2n}$. Therefore, we have $q_3^{n-1}=-1$, which leads to $2\mid n$ and $q_3=q_4=\cdots=q_{2n}=-1$.

Bringing it back to $(1)$, we have $q_1+q_2=n-1$.

Since $q_1q_2\cdots q_n=q_{n+1}+\cdots q_{2n}$, we know $q_1q_2=-n$.

The only solution is $\{q_1,q_2\}=\{-1,n\}$. Q.E.D.

Back to the problem. For the first case, it is easy to calculate the distance. For the second case, let $S=\sum_{i=1}^n |q_i-(-1)|$, the answer is $\min_{1\le j\le n}\{S-|q_j-(-1)|+|q_j-n|\}$.

 **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=400005;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll a[maxn];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		ll ans=0,sum=0;
		for(int i=1;i<=n*2;i++) {
			cin>>a[i];
			ans+=abs(a[i]);
			sum+=abs(a[i]-(-1));
		}
		if(n==1) {
			ans=min(ans,abs(a[1]-a[2]));
		}
		if(n==2) {
			ans=min(ans,abs(a[1]-2)+abs(a[2]-2)+abs(a[3]-2)+abs(a[4]-2));
		}
		if(n%2==0) {
			for(int i=1;i<=n*2;i++) {
				ans=min(ans,sum-abs(a[i]-(-1))+abs(a[i]-n));
			}
		}
		cout<<ans<<"n";
	}
}
```
[1806D - DSU Master](../problems/D._DSU_Master.md "Codeforces Round 858 (Div. 2)")

 **Solution**Tutorial is loading... **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
 
const int maxn=500005;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int a[maxn];
int f[maxn];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=1;i<=n-1;i++) {
			cin>>a[i];
		}
		f[1]=1;
		for(int i=1;i<=n-1;i++) {
			f[i+1]=1ll*f[i]*(i-a[i])%mod;
		}
		int ans=0;
		for(int i=1;i<=n-1;i++) {
			ans=(1ll*ans*i+(!a[i])*f[i])%mod;
			cout<<ans<<" ";
		}
		cout<<"n";
	}
}
```
[1806E - Tree Master](../problems/E._Tree_Master.md "Codeforces Round 858 (Div. 2)")

 **Solution**Tutorial is loading... **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=100005;
const int sqrtn=325;
const int B=320;
const int inf=0x3f3f3f3f;

int n,q;
int a[maxn];
int h[maxn];
int fa[maxn];
int cnt[maxn];
int depth[maxn];
ll f[maxn][sqrtn];
vector<int> tree[maxn]; 

void dfs(int x,int d) {
	h[x]=++cnt[d],depth[x]=d;
	for(int to:tree[x]) {
		dfs(to,d+1);
	}
}

ll ask(int x,int y) {
	if(!x&&!y) {
		return 0;
	}
	if(cnt[depth[y]]<=B&&f[x][h[y]]) {
		return f[x][h[y]];
	}
	ll ans=ask(fa[x],fa[y])+1ll*a[x]*a[y];
	if(cnt[depth[y]]<=B) {
		f[x][h[y]]=ans;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=2;i<=n;i++) {
		cin>>fa[i];
		tree[fa[i]].push_back(i);
	}
	dfs(1,0);
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<ask(x,y)<<"n";
	}
}
```
[1806F2 - GCD Master (hard version)](../problems/F2._GCD_Master_(hard_version).md "Codeforces Round 858 (Div. 2)")

 **Solution**Tutorial is loading... **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
#define int128 __int128
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=1000005;
const ll inf=9e18;
const int128 inf128=(int128)(inf)*(int128)(inf);

ll a[maxn];
ll b[maxn];
ll g[maxn];
ll ra[maxn];
int128 suma[maxn];
int128 sumb[maxn];
int128 ans[maxn];

ll gcd(ll x,ll y) {
	return !y?x:gcd(y,x%y);
}

void print(int128 x) {
	if(!x) {
		return ;
	}
	print(x/10);
	cout<<(int)(x%10);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n,k;
		ll m;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int t=0,r=0;
		for(int i=1;i<=n;i++) {
			if(i>1&&a[i]==a[i-1]) {
				b[++r]=a[i];
			} else {
				ra[++t]=a[i];
			}
		}
		n=t;
		for(int i=1;i<=n;i++) {
			a[i]=ra[i];
			g[i]=gcd(g[i-1],a[i]);
			suma[i]=suma[i-1]+a[i];
		}
		for(int i=0;i<=k;i++) {
			ans[i]=-inf128;
		}
		for(int l=1;l<=n;) {
			int r=l;
			while(r<=n&&g[r]==g[l]) {
				r++;
			}
			r--;
			ll Max=-inf;
			for(int i=r+1;i<=n;i++) {
				a[i]=gcd(a[i],g[l]);
				Max=max(Max,a[i]-ra[i]);
			}
			for(int i=r;i>=l;i--) {
				ans[i]=suma[n]-suma[i]+Max;	
				a[i]=gcd(a[i],g[l]);
				Max=max(Max,a[i]-ra[i]);
			}
			l=r+1;
		}
		for(int i=1;i<=r;i++) {
			sumb[i]=sumb[i-1]+b[i];
		}
		int128 final=-inf128;
		if(k<=r) {
			final=suma[n]+sumb[r]-sumb[k];
		}
		for(int i=0;i<=r&&i<=k;i++) {
			final=max(final,sumb[r]-sumb[i]+ans[k-i]);
		}
		print(final);
		cout<<"n";
	}
}
```
