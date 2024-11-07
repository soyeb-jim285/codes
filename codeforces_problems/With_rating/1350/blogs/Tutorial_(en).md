# Tutorial_(en)

You can view Chinese editorial here: [https://www.luogu.com.cn/blog/Caro23333/codeforces-round-641-zhong-wen-ti-xie](https://www.luogu.com.cn/blog/Caro23333/codeforces-round-641-zhong-wen-ti-xie)

Div2.A Problem and editorial by [BlueSmoke](https://codeforces.com/profile/BlueSmoke "Candidate Master BlueSmoke")

 **Editorial**
### [1350A - Orac and Factors](../problems/A._Orac_and_Factors.md "Codeforces Round 641 (Div. 2)")

 If we simulate the whole process we will get TLE because $k$ is too large. So we need some trivial observations:

* If $n$ is even, then for each operation $n$ will be added by $2$ and keep being even.
* If $n$ is odd, then for the first time $n$ will be added by an odd number and then become even.

So it's easy to see that the answer is $$ \left\{ \begin{array}{lcl} n+2k & n\textrm{ is even}\\\ n+2(k-1)+d(n) & n\textrm{ is odd}\\\ \end{array} \right. $$ where $d(n)$ is the smallest positive factor of $x$ except $1$, which can be calculated in $O(n)$ time.

The overall complexity is $O(n)$ .

 **Code**
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		if(n%2==0)
		{
			cout << n+2*k << endl;
			continue;
		}
		int p = 0;
		for(int i = n; i>=2; i--)
			if(n%i==0)
		    	p = i;
		cout << n+p+2*(k-1) << endl;
	}
	return 0;
}

```
Div2.B Problem and editorial by [BlueSmoke](https://codeforces.com/profile/BlueSmoke "Candidate Master BlueSmoke")

 **Editorial**
### [1350B - Orac and Models](../problems/B._Orac_and_Models.md "Codeforces Round 641 (Div. 2)")

Considering DP, we can design DP statuses as follow: $f_i$ stands for the length of the longest beautiful sequence end up with index $i$. 

We can find the transformation easily: $$ f_i = \max\limits_{j\mid i, s_j<s_i} \{f_j + 1\} $$

Then, the length of answer sequence is the maximum value among $f_1,f_2,\cdots,f_n$.

About the complexity of DP: If you transform by iterating multiples, it will be $O(n\log n)$ (According to properties of Harmonic Series); if you iterate divisors, then it will be $O(n\sqrt n)$. Fortunately, both of them are acceptable in this problem.

 **Code**
```cpp
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 500005;
inline int readint()
{
	int res = 0;
	char c = 0;
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
		res = res*10+c-'0', c = getchar();
	return res;	
}
int n,a[MAXN],f[MAXN];

int main()
{
	int T = readint();
	while(T--)
	{
		n = readint();
		for(int i = 1; i<=n; i++)
			a[i] = readint();
		for(int i = 1; i<=n; i++)
			f[i] = 1;
		for(int i = 1; i<=n; i++) 
			for(int j = i*2; j<=n; j += i)
				if(a[i]<a[j])
					f[j] = max(f[j],f[i]+1);
		int ans = 0;
		for(int i = 1; i<=n; i++)
			ans = max(ans,f[i]);
		cout << ans << endl;
	}
	return 0;
}

```
Div1.A Problem and editorial by [mydiplomacy](https://codeforces.com/profile/mydiplomacy "Candidate Master mydiplomacy")

 **Editorial**
### [1349A - Orac and LCM](https://codeforces.com/contest/1349/problem/A "Codeforces Round 641 (Div. 1)")

In this tutorial $p$ stands for a prime, $v$ stands for the maximum of $a_i$ and $ans$ stands for the answer.

Observation. $p^k\ \mid\ ans$ if and only if there are at least $n-1$ integers in $a$ that $\mathrm{s.t. }\ p^k\mid\ a_i$.

Proof. if there are at most $n-2$ integers in $a$ that $\mathrm{s.t. }\ p^k\mid\ a_i$, there exists $x\neq y$ $\mathrm{s.t.}\ p^k\nmid a_x$ $\mathrm{and}$ $p^k\nmid a_y$, so $p^k \nmid \textrm{lcm}(\{a_x,a_y\})$ and $p^k\ \nmid\ ans$. On the contrary, if there are at least $n-1$ integers in $a$ $\mathrm{s.t. }\ p^k\mid\ a_i$, between every two different $a_i$ there will be at least one multiple of $p^k$. So for every $(x,y)$, $p^k \mid \textrm{lcm}(\{a_x,a_y\})$. Therefore $p^k\ \mid\ ans$.

Solution 1. Define $d_i$ as a set that consists of all the numbers in $a$ except $a_i$. So $\gcd(d_i)$ is divisible by at least $n-1$ numbers in $a$. Also, if at least $n-1$ integers in $a$ $\mathrm{s.t. }\ p^k\ \mid\ a_i$, we can always find $i$ $\mathrm{s.t. }\ p^k \mid \gcd(d_i)$. According to the Observation, $ans=\textrm{lcm}(\{\gcd(d_1),\gcd(d_2),\gcd(d_3),...,\gcd(d_n)\})$.

Now consider how to calculate $\gcd(d_i)$. For every $i$, calculate $pre_i=\gcd(\{a_1,a_2,...,a_i\})$ and $suf_i=\gcd(\{a_{i},a_{i+1},...,a_n\})$. Therefore $\gcd(d_i)=\gcd(\{pre_{i-1},suf_{i+1}\})$ and we can get $pre$ and $suf$ in $O(n\cdot \log(v))$ time.

Time complexity: $O(n \log v)$

Solution 2. Enumerate every prime $\leq v$. For a prime $p$, enumerate every $a_i$ and calculate $k_i$ which stands for the maximum integer that $\mathrm{s.t. }\ p^{k_i} \mid a_i$. According to the Observation, the second smallest $k_i$ is the maximum integer $k$ that $\mathrm{s.t. }\ p^k \mid ans$. Now let's optimize this solution. If there has been at least two $a_i$ not divisible by $p$, then $p \nmid ans$, so just stop enumerate $a_i$.

Time complexity of the optimized solution is $O(v+n \log v)$ because every integer can be divided for at most $\log v $ times.

 **Code**
```cpp
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const int maxn=100005;

int n;
ll a[maxn];

ll pre[maxn],suf[maxn];

ll gcd(ll x, ll y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

ll ga,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	pre[1]=a[1]; suf[n]=a[n];
	for(int i=2;i<=n;i++)
		pre[i]=gcd(pre[i-1],a[i]);
	for(int i=n-1;i>=1;i--)
		suf[i]=gcd(suf[i+1],a[i]);
	for(int i=0;i<=n-1;i++)
	{
		if(i==0)
			ans=suf[2];
		else if(i==n-1)
			ans=ans*pre[n-1]/gcd(pre[n-1],ans);
		else
			ans=ans*gcd(pre[i],suf[i+2])/gcd(gcd(pre[i],suf[i+2]),ans);
	}
	printf("%lldn",ans);
	return 0;
}

```
Div1.B Problem and editorial by [A.K.E.E.](https://codeforces.com/profile/A.K.E.E. "International Grandmaster A.K.E.E.")

 **Editorial**
### [1349B - Orac and Medians](https://codeforces.com/contest/1349/problem/B "Codeforces Round 641 (Div. 1)")

Let $B_i=\left\{\begin{aligned} 0,A_i<k\\\1,A_i=k\\\2,A_i>k\end{aligned} \right.$，then just consider whether it can be done to make all elements in $B$ become $1$ in a finite number of operations. 

It can be proved that a solution exists if and only if $\exists 1\le i\le n,\mathrm{s.t.}B_i=1$ and $\exists 1\le i<j\le n,\mathrm{s.t.}j-i\le2,B_i>0,B_j>0$ .

The necessity is obvious: if $\forall 1\le i\le n, B_i\neq 1$ , no elements in $B$ can be transformed into $1$; If there are at least two zeros between any two positive numbers, then the median of each interval equals to $0$, no solution exists. 

Consider the sufficiency. If there are two adjacent elements in $B$ both equals to $1$ , just select an interval which contains at least three elements and exact one element unequal to $1$ , and operate once on this interval. After this operation, there are still two adjacent elements in $B$ both equals to $1$, so we keep doing this until all elements are transformed into $1$.

Therefore, if there is a interval $[l,r]$ which satisfies $r-l+1\ge2$ and the median of $\{B_l,B_{l+1},\dots,B_r\}$ equals to $1$, just perform an operation on $[l,r]$ , then use the above strategy. It can be shown that such an interval can always be created in several operations with the condition.

* If an interval $[i,i+2]$ satisfies $\{B_i,B_{i+1},B_{i+2}\}=\{0,1,2\}$ or $\{1,1,2\}$ or $\{0,1,1\}$ or $\{1,1,1\}$，just perform an operation on $[i,i+2]$ .
* If $[i,i+2]$ satisfies $\{B_i,B_{i+1},B_{i+2}\}=\{1,2,2\}$ , then $\{B_i,B_{i+1}\}=\{1,2\}$ or $\{B_{i+1},B_{i+2}\}=\{1,2\}$ . Perform an operation on $[i,i+1]$ or $[i+1,i+2]$ .
* If any interval with three elements doesn't satisfy the above conditions, because $\exists 1\le i<j\le n,\mathrm{s.t.}j-i\le2,B_i>0,B_j>0$ ，there is an interval $[i,i+2]$ which satisfies $\{B_i,B_{i+1},B_{i+2}\}=\{0,2,2\}$ or $\{2,2,2\}$ . Take such an interval $[i,i+2]$ , perform an operation on $[i,i+2]$ first, then select an interval which contains at least three elements and exact one element unequal to $2$ until two adjacent numbers equals to $1$ and $2$ respectively. Perform one operation on these two adjacent elements.

Therefore, the sufficiency is proved. So just check whether there is an element in $B$ equals to $1$, and whether there is a pair of two positive integers $(i,j)$ which satisfies $1\le j-i\le 2,B_i>0,B_j>0$ . The complexity is $O(n)$. 

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=500005;

int n,k,a[MAXN];
bool solve()
{
	readint(n),readint(k);
	bool flag=0;
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);
		if(a[i]<k)a[i]=0;
		else if(a[i]>k)a[i]=2;
		else a[i]=1;
		if(a[i]==1)flag=1;
	}
	if(!flag)return 0;
	if(n==1)return 1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n && j-i<=2;++j)
			if(a[i] && a[j])return 1;
	return 0;
}

int main()
{
	int T;
	readint(T);
	while(T--)printf(solve()?"yesn":"non");
	return 0;
}
```
Div1.C Problem and editorial by [A.K.E.E.](https://codeforces.com/profile/A.K.E.E. "International Grandmaster A.K.E.E.")

 **Editorial**
### [1349C - Orac and Game of Life](https://codeforces.com/contest/1349/problem/C "Codeforces Round 641 (Div. 1)")

A cell $(i,j)$ is said to be good if and only if there is a cell $(i',j')$ adjacent to $(i,j)$ which has the same color to $(i,j)$ . If a cell $(i,j)$ is not good, it is said to be bad. Therefore, the color of a cell changes after a turn if and only if the cell is good.

According to the definition, any cell never changes its color if every cell is bad. Also, a good cell $(i,j)$ would never turn into a bad cell .

For a bad cell $(i,j)$, if there is a good cell $(i',j')$ adjacent to $(i,j)$, $(i,j)$ will turn into a good cell after a turn because $(i',j')$ currently has a different color from $(i,j)$ and the color of $(i',j')$ will change after a turn but the color of $(i,j)$ won't change; otherwise, after a turn, the color of $(i,j)$ and cells adjacent to $(i,j)$ stays the same, so $(i,j)$ is still bad.

For a cell $(i,j)$, let $f_{i,j}$ be the number of turns needed for that $(i,j)$ becomes a good cell. According to the paragraph above, $f_{i,j}$ equals to the minimal Manhattan distance from $(i,j)$ to a good cell. Therefore, $f_{i,j}$ can be figured out by BFS. 

Notice that for $k \le f_{i,j}$ , the color of $(i,j)$ stays the same after the $k$-th turn; for $k>f_{i,j}$ , the color of $(i,j)$ changes after the $k$-th turn. Therefore, each query can be processed with $O(1)$ time complexity. The total time complexity is $O(nm+t)$ .

P.S. R.I.P. John Horton Conway, you are a great mathematician that should be remembered forever.

 **Code**
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll;
const int MAXN = 1005;
inline ll readint()
{
	ll res = 0, f = 1;
	char c = 0;
	while(!isdigit(c))
	{
		c = getchar();
		if(c=='-')
			f = -1;
	}
	while(isdigit(c))
		res = res*10+c-'0', c = getchar();
	return res*f;
}
int n,m,T,a[MAXN][MAXN];
char str[MAXN];
int f[MAXN][MAXN],pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool vis[MAXN][MAXN];
inline bool check(int x, int y)
{
	for(int i = 0; i<4; i++)
	{
		int nx = x+pos[i][0], ny = y+pos[i][1];
		if(a[nx][ny]==a[x][y])
			return true;	
	}
	return false;
}
pii q[MAXN*MAXN];
inline void bfs()
{
	int front = 0, rear = 0;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			if(check(i,j))
				f[i][j] = 0, vis[i][j] = true, q[rear++] = mp(i,j);
	while(front<rear)
	{
		pii now = q[front++];
		for(int i = 0; i<4; i++)
		{
			int nx = now.fi+pos[i][0], ny = now.se+pos[i][1];
			if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny])
				continue;
			f[nx][ny] = f[now.fi][now.se]+1;
			vis[nx][ny] = true;
			q[rear++] = mp(nx,ny);
		}
	}
}

int main()
{
	n = readint(), m = readint(), T = readint();
	memset(a,-1,sizeof(a));
	for(int i = 1; i<=n; i++)
	{
		scanf("%s",str+1);
		for(int j = 1;	j<=m; j++) 
			a[i][j] = str[j]-'0';
	}
	bfs();
	int x,y;
	ll t;
	while(T--)
	{
		x = readint(), y = readint(), t = readint();
		if(vis[x][y])
			printf("%dn",a[x][y]^(max(0ll,t-f[x][y])&1)); 
		else
			printf("%dn",a[x][y]);
	}
	return 0;
}

```
Div1.D Problem and editorial by [Rebelz](https://codeforces.com/profile/Rebelz "International Grandmaster Rebelz")

Part of solution by [Elegia](https://codeforces.com/profile/Elegia "International Grandmaster Elegia")

 **Editorial**
### [1349D - Slime and Biscuits](https://codeforces.com/contest/1349/problem/D "Codeforces Round 641 (Div. 1)")

Let $E_x$ be the sum of probability times time when the game end up with all biscuits are owned by the x-th person (At here, the sum of probability is not 1, though the sum of probability in all $E_x$ is 1). So the answer is $\sum\limits_{i=1}^nE_i$

Let $E'_x$ be the expectation of time when the game only ends when the x-th person own all the biscuits.

Let $P_x$ be the probability that the game end up with all biscuits are owned by the x-th person. It's easy to find that $\sum\limits_{i=1}^n P_i = 1$。

And we let constant $C$ be the expect time from when all biscuits are owned by i-th person to when all biscuits are owned by j-th person (now the end condition is that all biscuits are owned by j-th person, is the same with $E'_x$ . And for all (i, j), the value of $C$ is the same). So we have a identity:

$$E_x = E'_x-\sum\limits_{i=1}^n[i\neq x]( P_i\cdot C+E_i)$$ 

We can get this by consider which people own all the biscuits when the game ends in all possible situation of $E'_x$ .

Then we can get:

$$\sum\limits_{i=1}^n E_i=E'_x-C\cdot \sum\limits_{i=1}^n[i\neq x]P_i$$ 

Sum it up for $x=1,2,\cdots,n$ , and we get:

$$n\sum\limits_{i=1}^nE_i=\sum\limits_{i=1}^nE'_i-C(n-1)\sum\limits_{i=1}^nP_i$$ 

Mention that $ans=\sum\limits_{i=1}^nE_i$ and $\sum\limits_{i=1}^nP_i=1$ , so we find that:

$$n\cdot ans=\sum\limits_{i=1}^nE'_i-C(n-1)$$ 

When we find the value of $E'_x$ and $C$ , we only want to know whether the biscuit is owned by the person we want or not, so we can let $f_m$ represent the expect time the person will own $m+1$ biscuits when the person own $m$ biscuits now. We can easily get $f_0$ and equation between $f_i$ and $f_{i-1}$ .

So we can get all $f_m$ and $C$ in $O(\sum\limits_{i=1}^na_i \cdot \log\ mod)$ time. And we can get the answer.

The overall complexity is $O(\sum\limits_{i=1}^na_i \cdot \log\ mod)$ .

 **Code**
```cpp
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
ll a[100005],ans[300005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),m+=a[i];
	ll invm=qpow(m,cys-2),invn1=qpow(n-1,cys-2);
	for(int i=m;i>=1;i--){
		ll k1=i*invm%cys*invn1%cys,k2=(m-i)*invm%cys;
		ans[i]=(k2*ans[i+1]+1)%cys*qpow(k1,cys-2)%cys;
	}
	for(int i=1;i<=m;i++) ans[i]=(ans[i]+ans[i-1])%cys;
	ll res=0;
	for(int i=1;i<=n;i++) res=(res+ans[m-a[i]])%cys;
	res=(res+cys-ans[m]*(n-1)%cys)%cys;
	printf("%lldn",res*qpow(n,cys-2)%cys);
	return 0;
}
```
Div1.E Problem and editorial by [A.K.E.E.](https://codeforces.com/profile/A.K.E.E. "International Grandmaster A.K.E.E.")

 **Editorial**
### [1349E - Slime and Hats](https://codeforces.com/contest/1349/problem/E "Codeforces Round 641 (Div. 1)")

First, let's renumber the players for convenience. Number the player at the front as $n$ ，the player sitting behind him as $n-1$ , and so on. 

Let $c_i$ be the color of player $i$'s hat. Consider how to calculate ${t_i}$ if we have already known $c_1,c_2,\dots,c_n$. If $c_1=c_2=\dots=c_n=0$, then $t_1=t_2=\dots=t_n=1$. Otherwise, let $x$ be the maximal number of a player with a black hat. In the first turn, player $1$ knows that someone wears a black hat.

* If $x=1$, player $1$ finds out that everyone except him wears a white hat, so he wears a black hat and he leaves. In the second turn, other players can figure out that $c_2=c_3=\dots=c_n=0$. Therefore, $t_1=1,t_2=t_3=\dots=t_n=2$.
* If $x\ge 2$, there is a player with a black hat sitting in front of player $1$ , so he can't figure out the color of his own hat and doesn't leave. Other players know that $x\ge 2$ in the next turn, and the problem is transformed into a subproblem on player $2,3,\dots,n$. No one leaves until the $x$-th turn, player $x$ knows that there is at least one player with a black hat in $x,x+1,\dots,n$, but player $x,x+1,\dots,n$ all wear white hats, so he leaves. In the next turn, $x+1,x+2,\dots,n$ leaves.

According to the above process, player $x$ leaves in the $x$-th turn, player $x+1,x+2,\dots,n$ leave in the $(x+1)$-th turn, and a new process begins. Therefore, we can figure out the value of $t_1,t_2,\dots,t_n$. 

- If $c_i=1$ , then $t_i=\sum\limits_{j\ge i,c_j=1}j$ . Let $b_i=i$ . - If $c_i=0$ , let $k$ be the maximal number which satisfies $c_k=1$ and $k<i$ , then $t_i=t_k+1$ . For convenience, let $c_0=1, t_0=\sum\limits_{c_j=1}j$ , so $k$ always exists. Let $b_i=k$.

Therefore, we can calculate $t_1,t_2,\dots,t_n$ using $c_1,c_2,\dots c_n$, and $t_i=t_{b_i}+(1-c_i)$ is satisfied. 

Consider how to solve the original problem. Before using dynamic programming to solve the problem, we need to do some preparation for that.

If $i\ge j$ and $c_i=c_j=1$ , it is obviously that $t_i\le t_j$. Also, if $t_i>t_j$, $b_i\ge b_j$. Therefore, $$ \forall i>j, t_i-t_j=t_{b_i}+(1-c_i)-t_{b_j}-(1-c_j)=t_{b_i}-t_{b_j}+(c_j-c_i)\le c_j-c_i\le 1 $$ In fact, if $i>j$ , we have $$ \left\{ \begin{array}{lcl} t_i-t_j=1,\space\mathrm{if}\space c_j=1\ \textrm{and}\ \forall i\ge k>j,c_k=0 \\\ t_i-t_j=0,\space\mathrm{if}\space \exists i>k>j,c_k=1,c_1=c_2=\dots=c_{k-1}=c_{k+1}=\dots=c_n=0\ \textrm{or}\ \forall i\ge k\ge j,c_k=0 \\\ t_i-t_j<0,\space\mathrm{otherwise} \end{array} \right. $$ It is not difficult to prove the formula above with some simple classified discussions.

Define a set of intervals $A=\{[l_1,r_1],[l_2,r_2],\dots,[l_m,r_m]\}$ which satisfies these rules:

* $1\le l_1\le r_1<l_2\le r_2<\dots<l_m\le r_m\le n$
* $\forall 1\le k\le m, \exists l_k\le i\le r_k$, $t_i$ is given.
* $\forall 1\le i\le n$, if $t_i$ is given, $\exists k, \mathrm{s.t.}\space l_k\le i\le r_k$
* For all pairs $(i,j)$ where $i>j$ and $t_i,t_j$ are both given, $i$ and $j$ are in the same interval if and only if $t_i\ge t_j$.

If $l_i\neq 1$, it can be known that $c_{l_i+1}=c_{l_i+2}=\dots=c_{r_i}=0$ and $b_{l_i}=b_{l_i+1}=\dots=b_{r_i}$. Let $B_i=b_{l_i}$.

After the preparatory work, let's work on dp. Let $f_{i,j}$ be the maximal possible value of $B_i$ when $c_{l_i}=j$ . Consider how to calculate $f_{i,j'}$ if we know the value of $f_{i+1,0}$ and $f_{i+1,1}$ . For $f_{i+1,j}$, enumerate all possible $f_{i,j'}$ from large to small, $B_i=f_{i,j'}$ might be satisfied if $$ t_{f_{i,j'}}=\sum\limits_{k\ge f_{i,j'},c_k=1}k=\left(\sum\limits_{k\ge f_{i+1,j},c_k=1}k\right) + \left(\sum\limits_{f_{i+1,j}>k\ge f_{i,j'},c_k=1}k\right)   
  
=t_{f_{i+1,j}}+f_{i,j'}+\sum\limits_{r_i<k<f_{i+1,j},c_j=1}k $$ If can be noticed that $t_{f_{i,j'}},f_{i,j'},t_{f_{i+1,j}}$ are already known, so we just need to check whether there exists some distinct integers in $[r_i+1,f_{i+1,j}-1]$ where the sum of them equals to $t_{f_{i,j'}}-f_{i,j'}-t_{f_{i+1,j}}$ , which can be easily solved by binary search.

Besides $f_{i,j}$, record whether $f_{i,j}$ is transformed from $f_{i+1,0}$ or $f_{i+1,1}$. Using these we can easily give a solution.

Notice that when $l_1=1$, $[l_1,r_1]$ doesn't satisfy $c_{l_1+1}=c_{l_1+2}=\dots=c_{r_1}=0$ . However, there is at most one $i$ in $[l_1,r_1]$ where $c_i=1$. Just brute force which $c_i$ equals to $1$ is okay. The whole complexity is $O(n\log n)$. 

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define x first
#define y second
#define pb push_back
const int MAXN=200005;

int n,m,cnt;
pii a[MAXN];
bool avis[MAXN];
struct Range
{
	int l,r,type;
	ll val;
	Range(){}
	Range(int l,int r,int type,ll val):l(l),r(r),type(type),val(val){}
}b[MAXN];

int f[2][MAXN],wh[2][MAXN],res[MAXN];
vector<int> str[2][MAXN];
bool check(ll s,int l,int r)
{
	if(s<=0)return !s && r-l+1>=0;
	ll L=1,R=r-l+1,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if((l+l+mid-1)*mid<=s*2)ans=mid,L=mid+1;
		else R=mid-1;
	}
	return s*2<=(r+r-ans+1)*ans;
}
void modify(ll s,int l,int r,vector<int> &tar,int start)
{
	ll L=1,R=r-l+1,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if((l+l+mid-1)*mid<=s*2)ans=mid,L=mid+1;
		else R=mid-1;
	}
	for(int i=l;i<=r;i++)
		if(ans && (i+i+ans-2)*(ans-1)<=(s-i)*2 && (s-i)*2<=(r+r-ans+2)*(ans-1))
			{--ans,s-=i;tar.pb(1);}
		else tar.pb(0);
}
void update(int i,int ti,int ti_1,int pos,ll d)
{
	if(pos<=f[ti][i])return;
	str[ti][i].clear();
	f[ti][i]=pos;wh[ti][i]=ti_1;
	str[ti][i].pb(1);
	for(int j=f[ti][i]+1;j<=b[i].r;j++)str[ti][i].pb(0);
	modify(d-f[ti][i],b[i].r+1,f[ti_1][i-1]-1,str[ti][i],f[ti][i]);
}

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll y;
		scanf("%lld",&y);
		if(!y)continue;
		a[++m]=make_pair(n-i+1,y);
		avis[n-i+1]=1;
	}
	if(!m)
	{
		for(int i=1;i<=n;i++)putchar('0');
		return 0;
	}
	sort(a+1,a+m+1);
	b[cnt=1]=Range(a[m].x,a[m].x,2,a[m].y);
	for(int i=m-1;i;i--)
	{
		if(a[i].y==a[i+1].y)b[cnt].l=a[i].x,b[cnt].type=0;
		else if(a[i].y==a[i+1].y-1)b[cnt].l=a[i].x,b[cnt].type=1,b[cnt].val--;
		else b[++cnt]=Range(a[i].x,a[i].x,2,a[i].y);
	}
	b[cnt+1]=Range(-1,-1,0,0);
	bool error=0;
	f[0][0]=-1;f[1][0]=n+1;
	for(int i=1;i<=cnt;i++)
	{
		f[0][i]=f[1][i]=-1;
		for(int t=0;t<=1;t++)
			if(f[t][i-1]>b[i].r)
			{
				if(b[i].type==0 || b[i].type==2)
				{
					ll d=(b[i].val-1)-(b[i-1].val-1+t);
					int pos=-1;
					for(int j=min(b[i].l-1ll,d);j>b[i+1].r;--j)
						if(check(d-j,b[i].r+1,f[t][i-1]-1)){pos=j;break;}
					update(i,0,t,pos,d);
				}
				if(b[i].type==1 || b[i].type==2)
				{
					ll d=b[i].val-(b[i-1].val-1+t);
					if(check(d-b[i].l,b[i].r+1,f[t][i-1]-1))
						update(i,1,t,b[i].l,d);
				}
			}
		if(f[0][i]<0 && f[1][i]<0 && i==cnt && !b[i].type)error=1;
	}
	if(error)
	{
		for(int t=0;t<=1;t++)
			if(f[t][cnt-1]>b[cnt].r)
			{
				ll d=(b[cnt].val-1)-(b[cnt-1].val-1+t);
				int pos=-1;
				for(int j=min((ll)b[cnt].r,d);j>=b[cnt].l;--j)
				{
					if(avis[j])continue;
					if(check(d-j,b[cnt].r+1,f[t][cnt-1]-1)){pos=j;break;}
				}
				update(cnt,0,t,pos,d);
			}
	}
	int cur=(f[1][cnt]>0);
	for(int i=1;i<f[cur][cnt];i++)res[i]=0;
	for(int i=cnt;i>0;i--)
	{
		for(int j=0;j<(int)str[cur][i].size();j++)res[j+f[cur][i]]=str[cur][i][j];
		cur=wh[cur][i];
	}
	for(int i=n;i>0;i--)putchar(res[i]+'0');
	return 0;
}
```
Div1.F Problem and editorial by [Rebelz](https://codeforces.com/profile/Rebelz "International Grandmaster Rebelz")

Hard version solution by [Elegia](https://codeforces.com/profile/Elegia "International Grandmaster Elegia")

 **Editorial for easy version**
### [1349F1 - Slime and Sequences (Easy Version)](https://codeforces.com/contest/1349/problem/F1 "Codeforces Round 641 (Div. 1)")

First we can make a bijection between all the good sequences and permutations. Let a permutation of length $n$ be $a_1,a_2,\cdots , a_n$ , and we fill '>' or '<' sign between each $a_i$ and $a_{i+1}$ , so the value of $p_{a_i}$ is the number of '<' sign between $a_1,a_2,\cdots, a_i$ plus one, it's easy to proof that this is a correct bijection.

Let $ d_{i,j}$ be the number of permutations of length $i+1$ that have at least $j$ '<' signs in it. Then for each '<' sign, we can combine the places next to it, so for some combined places, there are only one way to put the numbers in it for a fix set of numbers. And we know that $d_{i,j}$ have $i-j+1$ sets of combined places, so the value of $d_{i,j}$ is the number of ways to assign $i+1 $ numbers into $i-j+1$ different sets. From the EGF of the second kind of Stirling numbers, we know that $d_{i,j}=(i+1)![z^{i+1}](e^z-1)^{i-j+1}$ . We can also use DP that similar with the Stirling numbers to get all $d_{i,j}$ .

When we find the answers, for each $1\leq i\leq n$ , we consider the contribution of each places, so for each $a_j$ , we need to find the number of permutations that have $i-1$ '<' signs before it. So we can get:

$$ans_{i+1}=\sum\limits_{x=0}^{n-1}\sum\limits_{y=i}^x (-1)^{y-i} {y\choose i}d_{x,y}\frac{n!}{(x+1)!}$$ $$=\frac {n!}{i!}\sum\limits_{x=0}^{n-1}\sum\limits_{y=i}^x (-1)^{y-i}\frac{y!d_{x,y}}{(y-i)!(x+1)!} $$

$$=\frac{n!}{i!} \sum\limits_{y=i}^{n-1}\frac{(-1)^{y-i}y!}{(y-i)!}\sum\limits_{x=y}^{n-1}\frac{d_{x,y}}{(x+1)!}$$ 

$$=\frac {n!}{i!}\sum\limits_{y=i}^{n-1} \frac{(-1)^{y-i}y!}{(y-i)!} \sum\limits_{x=y}^{n-1}[z^{x+1}](e^z-1)^{x-y+1}$$

If we can find $\sum\limits_{x=y}^{n-1}[z^{x+1}](e^z-1)^{x-y+1}$ for each $y$ , then we can find the answer in one convolution.

And because of the simple $O(n^2)$ DP algorithm to find all $d_{x,y}$ , so we can get a $O(n^2)$ complexity to solve the problem, and it can pass the easy version (other forms of DP can also get to this time complexity, but now we only introduce the form that leads to the solution of the hard version).

 **Code**
```cpp
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n;
ll fac[5005],inv[5005],d[5005][5005],ans[5005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	d[0][0]=fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) d[i][j]=(d[i-1][j-1]*(i-j+1)+d[i-1][j]*j)%cys;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i]=(ans[i]+d[j][i]*inv[j])%cys;
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]*fac[n]%cys);
	printf("n");
	return 0;
}

```
 **Editorial for hard version**
### [1349F2 - Slime and Sequences (Hard Version)](https://codeforces.com/contest/1349/problem/F2 "Codeforces Round 641 (Div. 1)")

Now we consider how to get these values in less than $O(n^2)$ time.

$$\sum\limits_{x=y}^{n-1}[z^{x+1}](e^z-1)^{x-y+1}=\sum\limits_{x=y+1}^n[z^x](e^z-1)^{x-y}$$ 

$$=[z^y]\sum\limits_{x=y+1}^n(\frac{e^z-1}z)^{x-y}=[z^y]\sum\limits_{x=1}^{n-y}(\frac{e^z-1}z)^x$$ 

Let $F=\frac{e^z-1}z$ , so now we just want to find $[z^i]\sum\limits_{k=1}^{n-i}F^k$ for each $0\leq i\leq n-1$ .

$$[z^i]\sum\limits_{k=1}^{n-i}F^k =[z^i]\frac 1{1-F}-[z^i]\frac{F^{n-i+1}}{1-F}$$ 

We can get the value of $[z^i]\frac 1{1-F}$ in one polynomial inversion, now we only need to deal with the second one.

$$[z^i]\frac{F^{n-i+1}}{1-F}=[z^{n+1}]\frac{(zF)^{n-i+1}}{1-F}$$ 

Let $w(z)=zF(z)$ , $\phi(z)$ satisfies $\frac{w(z)}{\phi (w(z))}=z$ , so $\frac{zF(z)}{\phi (w(z))}=z$ , $F=\phi (w)$ .

$$[z^{n+1}]\frac{(zF)^{n-i+1}}{1-F}=[z^{n+1}u^{n-i+1}]\sum\limits_{k=0}^\infty \frac{(uzF)^k}{1-F}$$ 

$$=[z^{n+1}u^{n-i+1}] \frac 1{1-\phi (w)}\frac 1{1-uw}$$ 

And from the Lagrange Inversion

$$=[u^{n-i+1}]\frac 1{n+1} [z^n] ((\frac 1{1-\phi z}\frac 1{1-uz})'\cdot \phi (z)^{n+1})$$ 

$$=\frac 1{n+1} [z^nu^{n-i+1}] (\phi (z)^{n+1}\frac{u+\phi'(z)-u\phi(z)-uz\phi'(z)}{(1-\phi (z))^2(1-uz)^2})$$

$$=\frac 1{n+1} [z^nu^{n-i+1}] (\phi(z)^{n+1}(\frac {u}{(1-\phi (z))(1-uz)^2}+\frac {\phi'(z)}{(1-\phi (z))^2(1-uz)}))$$ 

$$=\frac 1{n+1}[z^nu^{n-i+1}](\phi (z)^{n+1}(\frac 1{1-\phi(z)}\sum\limits_{k=0}^\infty (k+1)z^ku^{k+1}+\frac{\phi'(z)}{(1-\phi (z))^2}\sum\limits_{k=0}^\infty z^ku^k))$$ 

$$=\frac 1{n+1}[z^n](\phi (z)^{n+1}(\frac{(n-i+1)z^{n-i}}{1-\phi (z)}+\frac{\phi'(z)z^{n-i+1}}{(1-\phi(z))^2}))$$

$$=\frac 1{n+1}([z^i](\phi(z)^{n+1}\frac{n-i+1}{1-\phi(z)})+[z^{i-1}](\phi(z)^{n+1}\frac{\phi'(z)}{(1-\phi(z))^2}))$$

We can get $\phi(z)^{n+1}\frac{n-i+1}{1-\phi(z)}$ and $\phi(z)^{n+1}\frac{\phi'(z)}{(1-\phi(z))^2}$ in $O(n\log n)$ or $O(n\log ^2n)$ time, and then get the answer.

The overall complexity is $O(n\log n)$ or $O(n\log ^2n)$ .

 **Code**
```cpp
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,g=3,invg=(cys+1)/3;
int n;
ll ni[200015],fac[200015],inv[200015],tw[200005];

int mod(int x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

vi operator+(vi a,vi b){
	vi ret(max(a.size(),b.size()));
	for(int i=0;i<ret.size();i++) ret[i]=mod((i<a.size()?a[i]:0)+(i<b.size()?b[i]:0));
	return ret;
}

vi operator-(vi a,vi b){
	vi ret(max(a.size(),b.size()));
	for(int i=0;i<ret.size();i++) ret[i]=mod((i<a.size()?a[i]:0)+cys-(i<b.size()?b[i]:0));
	return ret;
}

vi operator*(vi a,ll b){
	for(int i=0;i<a.size();i++) a[i]=1ll*a[i]*b%cys;
	return a;
}

vi operator>>(vi a,int b){
	for(int i=0;i<a.size()-b;i++) a[i]=a[i+b];
	a.resize(a.size()-b);
	return a;
}

namespace poly{
	int N,l;
	int A[1100000],B[1100000],r[1100000],pre1[20][600000],pre2[20][600000];
	void pre(){
		for(int i=1,r=0;i<(1<<19);i<<=1,r++){
			int w=1,wn=qpow(g,(cys-1)/(i<<1));
			for(int j=0;j<i;j++,w=1ll*w*wn%cys) pre1[r][j]=w;
		}
		for(int i=1,r=0;i<(1<<19);i<<=1,r++){
			int w=1,wn=qpow(invg,(cys-1)/(i<<1));
			for(int j=0;j<i;j++,w=1ll*w*wn%cys) pre2[r][j]=w;
		}
	}
	void ntt(int *A,int N,int f){
		for(int i=0;i<N;i++) if(i<r[i]) swap(A[i],A[r[i]]);
		for(int i=1,r=0;i<N;i<<=1,r++){
			for(int j=0;j<N;j+=(i<<1)){
				for(int k=j;k<j+i;k++){
					int x=A[k],y=1ll*A[k+i]*(f>0?pre1[r][k-j]:pre2[r][k-j])%cys;
					A[k]=mod(x+y); A[k+i]=mod(x+cys-y);
				}
			}
		}
		if(f<0){
			int invn=qpow(N,cys-2);
			for(int i=0;i<N;i++) A[i]=1ll*A[i]*invn%cys;
		}
	}
	void init(int t){
		N=1,l=0;
		for(;N<t;N<<=1) l++;
		for(int i=0;i<N;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	}
	void getmul(){
		ntt(A,N,1); ntt(B,N,1);
		for(int i=0;i<N;i++) A[i]=1ll*A[i]*B[i]%cys;
		ntt(A,N,-1);
	}
	vi mul(vi a,vi b){
		init(a.size()+b.size());
		for(int i=0;i<N;i++) A[i]=i<a.size()?a[i]:0;
		for(int i=0;i<N;i++) B[i]=i<b.size()?b[i]:0;
		getmul();
		vi ret(a.size()+b.size()-1);
		for(int i=0;i<ret.size();i++) ret[i]=A[i];
		return ret;
	}
	vi polyinv(vi a,int l){
		if(l==1) return vi(1,qpow(a[0],cys-2));
		a.resize(l);
		vi b=polyinv(a,(l+1)/2);
		init(l<<1);
		for(int i=0;i<N;i++) A[i]=i<l?a[i]:0;
		for(int i=0;i<N;i++) B[i]=i<(l+1)/2?b[i]:0;
		ntt(A,N,1); ntt(B,N,1);
		for(int i=0;i<N;i++) A[i]=1ll*A[i]*B[i]%cys*B[i]%cys;
		ntt(A,N,-1);
		vi t=b*2;
		t.resize(l);
		for(int i=0;i<l;i++) t[i]=mod(t[i]+cys-A[i]);
		return t;
	}
	vi polydiff(vi a){
		for(int i=0;i<a.size()-1;i++) a[i]=1ll*(i+1)*a[i+1]%cys;
		a.resize(a.size()-1);
		return a;
	}
	vi polyint(vi a){
		a.resize(a.size()+1);
		for(int i=a.size()-1;i>=1;i--) a[i]=1ll*a[i-1]*ni[i]%cys;
		a[0]=0;
		return a;
	}
	vi polyln(vi a,int l){
		return polyint(mul(polydiff(a),polyinv(a,l)));
	}
	vi polyexp(vi a,int l){
		if(l==1) return vi(1,1);
		a.resize(l);
		vi b=polyexp(a,(l+1)/2);
		init(l<<1);
		vi t=mul(b,vi(1,1)-polyln(b,l)+a);
		t.resize(l);
		return t;
	}
	vi polypow(vi a,int l,int k){
		return polyexp(polyln(a,l)*k,l);
	}
}

vi getans(){
	vi f(0);
	for(int i=0;i<=n+1;i++) f.push_back(inv[i+1]);
	vi tmp=poly::mul(f,poly::polyinv((vi(1,1)-f)>>1,n+1));
	vi tw(0); tw.resize(n);
	for(int i=0;i<n;i++) tw[i]=tmp[i+1];
	vi h(0);
	h.push_back(1),h.push_back(1);
	h=poly::polyinv(poly::polyln(h,n+3)>>1,n+2);
	vi g=poly::polyinv((vi(1,1)-h)>>1,n+1);
	vi ph=poly::polypow(h,n+1,n+1);
	vi t1=poly::mul(g,ph);
	vi tmp1=poly::mul(poly::polydiff(h),ph);
	tmp1.resize(n+1);
	vi tmp2=poly::mul(g,g);
	tmp2.resize(n+1);
	vi t2=poly::mul(tmp1,tmp2);
	for(int i=0;i<n;i++) tw[i]=mod(tw[i]+cys-ni[n+1]*mod(t1[i+1]*(n-i+1)%cys+t2[i+1])%cys);
	for(int i=0;i<n;i++) tw[i]=tw[i]*fac[i]%cys;
	reverse(tw.begin(),tw.end());
	tmp.clear();
	for(int i=0;i<n;i++) tmp.push_back(i&1?cys-inv[i]:inv[i]);
	tw=poly::mul(tw,tmp);
	tw.resize(n);
	reverse(tw.begin(),tw.end());
	return tw;
}

int main(){
	poly::pre();
	n=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n+5;i++) fac[i]=fac[i-1]*i%cys;
	inv[n+5]=qpow(fac[n+5],cys-2);
	for(int i=n+4;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=n+5;i++) ni[i]=inv[i]*fac[i-1]%cys;
	vi res=getans();
	for(int i=0;i<n;i++) printf("%lld ",res[i]*fac[n]%cys*inv[i]%cys);
	printf("n");
	return 0;
}
```
You can also view Div1.F editorial by [Elegia](https://codeforces.com/profile/Elegia "International Grandmaster Elegia") here: <https://codeforces.com/blog/entry/77280>

Anyway, hope you like these problems and thank you for participating!

