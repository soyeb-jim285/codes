# Tutorial_(en)


### [1704A - Two 0-1 Sequences](../problems/A._Two_0-1_Sequences.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

Considering that whichever the operation you use, the length of $a$ would decrease $1$.

So you can only modify the first $n-m+1$ elements of $a$, otherwise the length of $a$ can't be equal to the length of $b$. That means $\{a_{n-m+2},\dots,a_n\}$ must equals to $\{b_2,\dots,b_m\}$.

And about the first element of $b$: 

* if $b_1$ is $0$, you can use Operation 1 to make $0$ and remove elements.
* if $b_1$ is $1$, you can use Operation 2 to make $1$ and remove elements.

So just check the first $n-m+1$ elements in $a$ to find if there is anyone that equals to $b_1$. 

 **solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        if (n < m) {
            cout << "NOn";
            continue;
        }
        bool same = true;
        for (int i = 1; i < b.size(); ++i) {
            if (a[i + n - m] != b[i]) {
                same = false;
                break;
            }
        }
        if (!same) {
            cout << "NOn";
            continue;
        }
        for (int i = 0; i < n - m + 1; ++i) {
            if (a[i] == b[0]) {
                same = false;
            }
        }
        if (same) {
            cout << "NOn";
        }
        else {
            cout << "YESn";
        }
    }
}
```
 
### [1704B - Luke is a Foodie](../problems/B._Luke_is_a_Foodie.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

For $a_i$, if $|v-a_i| \leq x$, then $ a_i-x \leq v \leq a_i+x$.

Then consider using the greedy strategy. We will only change $v$ when we cannot find any possible $v$ to satisfy the current conditions. 

Therefore, we can determine the range of $v$. Initially, set $l=a_1-x,r=a_1+x$, then $v \in [l,r]$. For $a_i$, change $l=\max(l,a_i-x),r=\min(r,a_i+x)$. Once $l>r$, which means from the last time that we changed $v$ to the current $a_i$ we cannot find any possible $v$ to satisfy the all the conditions between the two positions, we should change $l=a_i-x,r=a_i+x$, and add $1$ to answer.

 **solution**
```cpp
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <cstdio>
#include <assert.h>
#include <iostream>
const int MAXN = 300005;
int numbers[MAXN];
int main() {
	int t;
	int n, x;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &numbers[i]);
		}
		int num_min = numbers[1];
		int num_max = numbers[1];
		int res = 0;
		for (int i = 2; i <= n; i++) {
			if (numbers[i] > num_max) {
				num_max = numbers[i];
			}
			if (numbers[i] < num_min) {
				num_min = numbers[i];
			}
			if (num_max - num_min > 2 * x) {
				res++;
				num_min = num_max = numbers[i];
			}
		}
		printf("%dn", res);
	}
	return 0;
}
```
 
### [1704C - Virus](../problems/C._Virus.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

First, considering it is easier to calculate the number of houses which are not infected, so we focus on it firstly.

Conspicuously, if between $a_i$ and $a_{i+1}$ there are $x$ houses (Array $a$ has been sorted.), and the infection will last $y$ days, there will remain $x-2 \times y$ houses on the end. Simultaneously, every day we can protect at least one house permanently, which indicates that for every distance between $a_i$ and $a_{i+1}$, if $x- 2\times y > 0$, we have an opportunity to get one house protected. 

Moreover, the longer uninfected segments have priorities, because we can set two houses to stop the spread of inflection and the loss per day will be prevented. By contrast, for shorter segments, when all the houses in this segment are infected, then there won't be any loss afterwards. In other words, the loss of longer segments will last for longer time if we do not take actions in time. As a result, if we operate the longer segments as early as possible, we can protect more houses. 

In conclusion, our final strategy can be decribed as following: Sort the uninfected segments of houses according to their length, then the longer the segment is, the earlier we will deal with the houses lying on the side of the segment. 

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 500005, inf = 2147483647, M = 1004535809;
int n, m, a[N], T, k;
struct str {
	int x, y;
}t[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		k = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + m);
		for (int i = 2; i <= m; ++i)
			t[++k] = { a[i] - a[i - 1] - 1,2 };
		int num_tmp = a[1] + n - a[m] - 1;
		if (num_tmp > 0) {
			t[++k] = { num_tmp, 2 };
		}
		sort(t + 1, t + 1 + k, [](str a, str b) {return a.x > b.x; });
		long long ans = 0, cnt = 0;
		for (int i = 1; i <= k; ++i) {
		    if (t[i].x - cnt * 2 > 0) {
		      int num_tmp = max(1ll, t[i].x - cnt * 2 - 1);
			  ans += num_tmp;
		    }
		    cnt += 2;
		}
		printf("%lldn", n - ans);
	}
}
```
 
### [1704D - Magical Array](../problems/D._Magical_Array.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

First, let's focus on $\textbf{operation 1}$ and do some calculations:

1. $a_{i-1} \times (i-1) + a_i \times i + a_j \times j + a_{j+1} \times (j+1) = i \times (a_{i-1}+a_i) + j \times (a_j+a_{j+1}) -a_{i-1} + a_{j+1}$

2. $(a_{i-1}+1) \times (i-1) + (a_i-1) \times i + (a_j-1) \times j + (a_{j+1}+1) \times (j+1) $ $\ \ \ = i \times (a_{i-1}+a_i) + j \times (a_j+a_{j+1}) -a_{i-1} + a_{j+1}$

See what? Yes, even if you give lots of $\textbf{operation 1}$ to array $a$, the sum of $(a_{i} \times i)$ remains. Thus, you can easily find $c_k$. 

And how to find the number of $\textbf{operation 2}$ ? Let's do some calculations again:

1. $a_{i-1} \times (i-1) + a_i \times i + a_j \times j + a_{j+1} \times (j+1) +a_{j+2} \times (j+2)$ $\ \ \ = i \times (a_{i-1}+a_i) + j \times (a_j+a_{j+1}+a_{j+2}) -a_{i-1} + a_{j+1}+2 \times a_{j+2}$

2. $(a_{i-1}+1) \times (i-1) + (a_i-1) \times i + (a_j-1) \times j + a_{j+1} \times (j+1) + (a_{j+2}+1) \times (j+2)$ $\ \ \ = i \times (a_{i-1}+a_i) + j \times (a_j+a_{j+1}+a_{j+2}) -a_{i-1} + a_{j+1}+ 2 \times a_{j+2} +1$

This operation will add $1$ to the result of $\sum a_i\times i$.

Just minus the initial $\sum a_i\times i$ and you will get the number of operations applied.

 **solution**
```cpp
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <cassert>
const int MAXN = 500005;
std::vector<long long> numbers[MAXN];
std::map<long long, long long> val_to_index;
int main()
{
	int t;
	int n, m;
	scanf("%d ", &t);
	while (t--)
	{
		val_to_index.clear();
		scanf("%d %d", &n, &m);
		long long num_tmp;
		for (int i = 1; i <= n; i++) {
		    numbers[i].clear();
		    numbers[i].push_back(0);
			for (int j = 1; j <= m; j++) {
				scanf("%lld", &num_tmp);
				numbers[i].push_back(num_tmp);
			}
		}
		long long res_tmp = -1;
		for (long long i = 1; i <= n; i++) {
			long long val = 0;
			for (long long j = 1; j <= m; j++) {
				val += (j * numbers[i][j]);
			}
			if (val_to_index.find(val) != val_to_index.end()) {
			    res_tmp = val;
				val_to_index[val] = -1;
			}
			else {
				val_to_index[val] = i;
			}
		}
		assert(val_to_index.size() == 2);
		for (auto &item : val_to_index) {
			if (item.second != -1ll) {
				printf("%lld %lldn", item.second, std::abs(res_tmp - item.first));
				break;
			}
		}
	}
	return 0;
}
```
 
### [1704E - Count Seconds](../problems/E._Count_Seconds.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

For the sink point, We can find that it may be zero at some time $t$ and $t \leq n$, then it will be full for some continous time, and then will be zero forever. That's because for time $t\ge n$, for some certain $a_x>0$, all roads from $x$ to the sink point must be greater than $0$ since $n$ rounds are enough for such $a_x$ to spread along these roads. Meanwhile, when some $a_y$ is decreased, it will also receive the numbers from upper nodes $x$. As a result, after $n$ turns, $a_y$ will be greater than $0$ until all $a_x$ turns to $0$ for all $x$ that there's an edge from $x$ to $y$.

Simulate the first $n$ rounds, then we just need to calculate what's the final number on the sink node if the the number on the sink point is never decreased. That's exactly the rounds it will take the sink point to be decreased to $0$.

Let $dp_i$ be the total number of $1$s the i-th node will add to some sink point finally if there is an $1$ on the i-th node. We can easily get the $dp_i$ in O(n) time for every sink point. 

Do a topological sort, and add the $sum_i$ of the current node $i$ to the $sum_j$ of the newly queued point $j$ during the sorting process. 

Calculate the sum of $s_i \times dp_i$ and you can get the answer. The total time complexity will be $O(n^2)$.

Note that the numbers on the nodes may be a multiple of $998244353$, so pay attention to them when simulating in the first $n$ turns.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 500005, inf = 2147483647, M = 998244353;
int n, m, a[N], u, v, i, d[N], q[N], r, mx;
int b[N], tmp[N];
vector<int> g[N], z[N];
long long s[N];
int p[15];
void NEX(int M) {
	for (int i = 1; i <= n; ++i)
		if (b[i]) {
			tmp[i] += b[i] - 1;
			for (auto it : g[i])
				++tmp[it];
		}
	for (int i = 1; i <= n; ++i) {
		if (tmp[i] >= M)
			b[i] = tmp[i] % M + M;
		else
			b[i] = tmp[i] % M;
		tmp[i] = 0;
	}
}
int cal(int M) {
	for (int i = 1; i <= n; ++i) {
		b[i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		bool fl = false;
		for (int j = 1; j <= n; ++j)
			if (b[j])
				fl = true;
		if (!fl)
			return i - 1;
		NEX(M);
	}
	return n;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			g[i].clear();
			z[i].clear();
			d[i] = 0;
			tmp[i] = 0;
			s[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d %d", &u, &v);
			++d[u];
			g[u].push_back(v);
			z[v].push_back(u);
		}
		mx = cal(M);
		if (mx < n) {
			cout << mx << endl;
			continue;
		}
		r = 0;
		for (int i = 1; i <= n; ++i)
			if (!d[i])
				q[++r] = i;
		s[q[1]] = 1;
		for (int i = 1; i <= r; ++i) {
			s[q[i]] %= M;
			for (auto it : z[q[i]]) {
				--d[it];
				s[it] += s[q[i]];
				if (!d[it])
					q[++r] = it;
			}
		}
		long long ans = n;
		for (int i = 1; i <= n; ++i)
			ans = (ans + s[i] * b[i]) % M;
		cout << ans << endl;
	}
}
```
 
### [1704F - Colouring Game](../problems/F._Colouring_Game.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

First, when the number red cells and blue cells are not equal, the player who owns a larger numberof his/her corresponding cells will win (Alice owns red and Bob owns blue). His/Her strategy can be: each time paint one segment of RB or BR white until there is none. This operation doesn't change the difference between the number of R and B and will decrease the number of the color of his/her opponent. Then Alice will only paint RW and WR, while Bob will only paint BW or WB. This operation will only decreace his/her own number of color, so the player who owns more cells of color will certainly win.

When the number of red cells and blue cells are the same, Alice and Bob will play games first on red-and-blue segments, until there is no RB or BR, and the player who faces this situation will lose.

Playing games on red-and-blue segments can be described as the following game: each player can take two neighbouring cells which has not be taken yet in his/her turn. As a result, this game becomes equal, then we can use SG function to forecast the result.

This SG function has the following calculating method: $SG(n)=mex_{i=0}^{n-2} SG(i)\oplus SG(n-2-i)$. In order to speed up, we can observe that ${SG(i)}$ has a cyclic section of length $34$ except for the first few elements. It can also be proved by verifying the first $34^2$ elements has this cyclic section, and this demonstrates that for all kinds of xor combination of the cyclic section leads to this cycle. Use Mathematical Induction and we can know this combination will be the the same (just add some repeated numbers to the calculation of $mex$ as the previous $34$-th number) for the subsequent elements. The total time complexity can be reduced to $O(n)$ in calculating the SG function.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=500005,inf=2147483647,M=998244353;
int n,i,t,f[N],vis[N];
char c[N];
int main(){
    for(int i=1;i<=1000;++i){
        for(int j=0;j<=i-2;++j)
            vis[f[j]^f[i-2-j]]=1;
        int j;
        for(j=0;vis[j];++j);
        f[i]=j;
        for(int j=0;j<=i;++j)
            vis[j]=0;
    }
    for(int i=1001;i<N;++i)
        f[i]=f[i-34];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",c+1);
        int s=0;
        for(int i=1;i<=n;++i)
            if(c[i]=='R')
                ++s;
            else
                --s;
        if(s>0)
            puts("Alice");
        if(s<0)
            puts("Bob");
        if(s==0){
            int ans=0;
            for(int i=1;i<=n;){
                int j=i+1;
                for(;j<=n&&c[j]!=c[j-1];++j);
                    ans^=f[j-i];
                i=j;
            }
            puts(ans?"Alice":"Bob");
        }
    }
}
```
 
### [1704G - Mio and Lucky Array](../problems/G._Mio_and_Lucky_Array.md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

Let's define $f_i = a_i + 2 a_{i-1} + a_{i-2}, g_i = b_i + 2b_{i-1} + b_{i-2}$. Cosidering after the operation on some index $i$, for any $j\ne i$, $f_j$ will remain the same; For $j=i$, $f_j$ will be increased by $1$. Then we can find the operation on $a$ is a single point operation on $f$. 

It can be proved that the following conditions are equivalent to the condition that $b[1,m]$ can match $a[k+1,k+m]$:

$$ \left\{\begin{matrix} b_1=a_{k+1} \\\ b_2 + b_1 = a_{k+2} + a_{k+1} \\\ g_i = f_{k+i} (i \ge 3) \\\ \end{matrix}\right. $$

For $i \le k+2$, operation on $i$ will make $a_{k+1}+a_{k+2} \gets a_{k+1} + a_{k+2} + (-1)^{k-i}$. So the second condition restricts the difference of operating times between odd positions and even positions among first $k+2$ positions. When conducting an operation on $i$ it will make $a_{k+1} \gets a_{k+1} + (k+2-i)\times (-1)^{k-i}$.

So we can convert the problem to: using $-0,+1,-2,+3,-4,+5\cdots,(-1)^n n$, to make the number of subtractions(operations which make $a_{k+1}$ be decreased) minus the number of additions(operations which make $a_{k+1}$ be increased) is $a$, and the final $a_{k+1}$ should be $b$.

Further, suppose I first select all the subtractions($-0,-2,-4,-6,\dots$), i.e. take all the operation on odd/even(depending on the parity of $k$) positions. If I don't want to select it afterwards, it can be regarded as a re-add operation, then the first and second restrictions can be converted to $a \gets a +\lfloor\frac{k+1}{2}\rfloor+1, b\gets b+\sum_{i= 0}^{\lfloor \frac{k+1}{2}\rfloor} 2i$, where $a$ indicates that $a$ numbers need to be selected, and $b$ indicates that the selected sum is $b$. All $b$ which satisfies $\sum_{i=0}^{a-1} i \le b \le \sum_{i=k+1-a}^{k+1} i$ are legal and easy to construct.

Next consider the third restriction, the constructor $f(k) = \sum_{i=3}^m (g_i-f_{i+k})(g_i-f_{i+k}-1)$. If $f_{i+k}=g_i$ or $f_{i+k}+1=g_i$, then the above formula is 0. Whether $f_{i+k}=g_i$ respectively represents whether we need to operate on $k+i$, otherwise the above formula must be greater than 0. If $b[1,m]$ matches $a[k+1,k+m]$, then $f(k) = 0$, otherwise it must not match. So consider how to calculate $f$. $$ f(k) = \sum_{i=3}^m f_{i+k}^2+g_i^2-2f_{i+k}g_i-g_i+f_i $$ For $2f_{i+k}g_i$ is in the form of differential convolution, $g$ can be flipped and converted into polynomial multiplication, which can be solved by FFT. The other items are also simple.

Considering that $f(k)$ may be quite large, you need to test several different prime numbers if you use NTT, in order to avoid hacking.

The total time complexity $O(n\log n)$.

Also the available $k$ which satisfies the third restriction can also be found using bitset, the total time complexity $O(\frac{n^2}{\omega})$.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int M1=998244353,M2=1004535809,M3=469762049,E=524288,N=200005;
struct poly{
    const int M;
    poly(int _M):M(_M){}
    int R[N*4];
    long long qpow(long long a,long long b){
        long long ans=1;
        while(b){
            if(b&1)
                ans=ans*a%M;
            a=a*a%M;
            b>>=1;
        }
        return ans;
    }
    long long wn[N*4],iwn[N*4],inv[N*4],fac[N*4],ifac[N*4];
    void init(int E,int g){
        int i;
        iwn[E/2]=wn[E/2]=1;
        long long s1=qpow(g,(M-1)/E);
        long long s2=qpow(s1,M-2);
        for(i=E/2+1;i<E;++i){
            wn[i]=wn[i-1]*s1%M;
            iwn[i]=iwn[i-1]*s2%M;
        }
        for(i=E/2-1;i;--i){
            wn[i]=wn[i<<1];
            iwn[i]=iwn[i<<1];
        }
        ifac[0]=fac[0]=inv[1]=1;
        for(i=2;i<E;++i)
            inv[i]=inv[M%i]*(M-M/i)%M;
        for(i=1;i<E;++i){
            ifac[i]=inv[i]*ifac[i-1]%M;
            fac[i]=fac[i-1]*i%M;
        }
    }
    unsigned long long ccc[N*4];
    void NTT(long long *f,int lim,int op){
        int i,j,k;
        for(i=0;i<lim;++i){
            R[i]=(R[i>>1]>>1)|(i&1?lim>>1:0);
            if(R[i]<i)
                swap(f[R[i]],f[i]);
        }
        for(i=0;i<lim;++i)
            ccc[i]=(f[i]%M+M)%M;
        for(i=1;i<lim;i<<=1)
            for(j=0;j<lim;j+=(i<<1))
                for(k=j;k<j+i;++k){
                    long long w=(op==1?wn[k-j+i]:iwn[k-j+i]);
                    unsigned long long p=ccc[k+i]*w%M;
                    ccc[k+i]=ccc[k]+M-p;
                    ccc[k]+=p;
                }
        for(i=0;i<lim;++i)
            f[i]=ccc[i]%M;
        if(op==-1){
            long long inv=qpow(lim,M-2);
            for(i=0;i<lim;++i)
                f[i]=f[i]*inv%M;
        }
    }
    long long ta[N*4],tb[N*4];
    void mult(long long *a,int n,long long *b,int m,long long *c){
        int lim=1;
        while(lim<n+m)
            lim<<=1;
        copy(a,a+n,ta);
        copy(b,b+m,tb);
        for(int i=n;i<lim;++i)
            ta[i]=0;
        for(int i=m;i<lim;++i)
            tb[i]=0;
        NTT(ta,lim,1);
        NTT(tb,lim,1);
        for(int i=0;i<lim;++i)
            ta[i]=ta[i]*tb[i]%M;
        NTT(ta,lim,-1);
        copy(ta,ta+lim,c);
    }
}X(M1),Y(M2),Z(M3);
int n,m,o[N],t,tn;
long long a[N],b[N],c[N],d[N*4],e[N],f[N*4],ss[N],td[N],tf[N];
bool fl[N],zz;
vector<int> ans;
long long cal(int l,int r){
    return 1ll*(l+r)*(r-l+1)/2;
}
long long cal2(int u,int v){
    return 1ll*((v-u)/2+1)*(u+v)/2;
}
bool iok(int n,int p,int q){
    long long ss=q+1ll*(n/2)*(n/2+1);
    p=p+(n/2+1);
    long long mn=cal(0,p-1),mx=cal(n-p+1,n);
    if(mn<=ss&&ss<=mx){
        for(int i=n;i<n+m-2;++i)
            if(td[i]!=tf[i-n+1]&&td[i]!=tf[i-n+1]-1)
                return false;
        ss-=mn;
        for(int i=n;i<n+m-2;++i)
            if(td[i]!=tf[i-n+1])
                ans.push_back(i+2);
        fill(fl,fl+1+n,0);
        for(int i=0;i<p;++i)
            fl[(ss/p+(i>=p-ss%p)+i)]=1;
        for(int i=0;i<=n;++i)
            if(fl[i]^(i&1)^1)
                if(n+1-i<=tn)
                    ans.push_back(n+1-i);
        zz=true;
        return true;
    }
    return false;
}
void OT(){
    if(!zz)
        puts("-1");
    else{
        printf("%dn",ans.size());
        for(auto it:ans)
            printf("%d ",it);
        printf("n");
    }
}
void judgement(poly &v,long long *c,long long *e){
    for(int i=0;i<n-2;++i)
        d[i]=(c[i+1]+c[i+2])%v.M;
    for(int i=0;i<m-2;++i)
        f[i]=(e[i+1]+e[i+2])%v.M;
    reverse(f,f+m-2);
    long long s=0;
    for(int i=0;i<m-2;++i)
        s+=(f[i]*f[i]-f[i])%v.M;
    for(int i=1;i<=n-2;++i)
        ss[i]=(ss[i-1]+d[i-1]*(d[i-1]+1))%v.M;
    v.mult(d,n-2,f,m-2,d);
    for(int i=m-3;i<n-2;++i)
        if((s+ss[i+1]-ss[i-m+3]-2*d[i])%v.M!=0)
            o[i-m+4]=0;
}
int main(){
    X.init(E,3);
    Y.init(E,3);
    Z.init(E,3);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tn=n;
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;++i)
            scanf("%lld",&b[i]);
        for(int i=1;i<n;++i)
            c[i]=a[i]+a[i+1];
        for(int i=1;i<m;++i)
            e[i]=b[i]+b[i+1];
        fill(o,o+1+n,0);
        ans.clear();
        for(int i=1;i<=n;++i)
            o[i]=1;
        if(m>2){
            for(int i=0;i<n-2;++i)
                td[i+1]=c[i+1]+c[i+2];
            for(int i=0;i<m-2;++i)
                tf[i+1]=e[i+1]+e[i+2];
            judgement(X,c,e);
            judgement(Y,c,e);
            judgement(Z,c,e);
        }
        else
            for(int i=1;i<=n;++i)
                o[i]=1;
        int x=-1;
        zz=false;
        if(m==1){
            for(int i=1;i<=n;++i)
                if(-cal2(0,i/2*2)<=b[1]-a[i]&&b[1]-a[i]<=cal2(1,(i-1)/2*2+1)){
                    for(int j=-(i/2+1);j<=(i+1)/2;++j)
                        if(iok(i,j,b[1]-a[i]))
                            break;
                    break;
                }
        }
        else
            for(int i=1;i+m-1<=n;++i)
                if(o[i]&&iok(i,(a[i]+a[i+1])-(b[1]+b[2]),b[1]-a[i]))
                    break;
        OT();
    }
}

```
 
### [1704H1 - Game of AI (easy version)](../problems/H1._Game_of_AI_(easy_version).md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

Consider calculate the number of possible sequences $a$ for a fixed sequence $b$.

We can find that if $b_i\ne i$, that means $i$ is occupied by $b_i$ finally, so we have $a_{b_i}$=i. If $b_i=i$, that means for all $j$ that $a_j=i$, $j$ is occupied before it begins its attack. As a result, we must have $b_j\ne j$.

The sequences $a$ which satisfies the above conditions is also possible to match a valid $p$. The attacking order can be arranged easily.

Now for how to count, we can build a graph according to the information given by $b_i\ne i$. We can see that the graph will in the form of some chains. Also, we can find that for a graph which consists of some chains, we can find the unique $b$ which satisfies the graph. Then some positions of array $a$ is also fixed, except the top of each chain. As for how to decide the these $a_i$($i$ is the top of some chain), we need to divide into two situations: one is the chain's length is greater than $1$, we can see that this $a_i$ can take any number between $1$ and $n$ except $i$; The other one is the chain's length is one, so $a_i$ cannot be any bottom of each chain. Then we can easily calculate the number of arrays $a$ by product the possible number of values of each $a_i$.

In conclusion, we can enumerate the number of chains, and the number of chains with length $1$, then use combination number to calculate. Time complexity is $O(n^2)$.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=200005,E=15000005;
const long long inf=1000000000000000000ll;
int n,M,mi[5005][5005];
long long fac[N],inv[N],ans;
long long C(int n,int m){
    return fac[n]*inv[m]%M*inv[n-m]%M;
}
long long qpow(long long a,long long b){
    long long s=a,ans=1;
    while(b){
        if(b&1)
            ans=ans*s%M;
        s=s*s%M;
        b>>=1;
    }
    return ans;
}
int main(){
    cin>>n>>M;
    fac[0]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=inv[M%i]*(M-M/i)%M;
    for(int i=1;i<=n;++i){
        inv[i]=inv[i-1]*inv[i]%M;
        fac[i]=fac[i-1]*i%M;
    }
    long long s1=1;
    for(int i=0;i<=n;++i){
        mi[i][0]=1;
        for(int j=1;j<=n;++j)
            mi[i][j]=1ll*mi[i][j-1]*i%M;
    }
    for(int j=1;2*j<=n;++j){
        s1=s1*(n-1)%M;
        for(int i=0;i<=n-2*j;++i)
            ans=(ans+C(n,i)*fac[n-i]%M*s1%M*mi[n-i-j][i]%M*C(n-i-j-1,j-1)%M*inv[j])%M;
    }
    cout<<ans<<endl;
}
```
 
### [1704H2 - Game of AI (hard version)](../problems/H2._Game_of_AI_(hard_version).md "CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)")

Given $b$, The conclusion of possible array $a$ remains. If we fix array $a$, we will find that for each $i$, $b_i$ will only be $j$ that $a_j=i$ or $j=i$. For any pair $(x,y)$, if $a_x=y$, we will find that $b_x=x$ and $b_y=y$ at the same time is impossible. All arrays $b$ which satisfies the above conditions are valid.

So for a fixed array $a$, and we fix the position that $b_i=i$(It can be shown that the chosen nodes form a independent set), then the number of possible $b$ will be product of each in-degree of each $x$ that $b_x\ne x$.

Now we can see if we build a graph according to $a$, the answer will be the sume of product over all independent sets. We need to solve the problem of three parts: the nodes form a tree, some trees' roots form a ring, some trees based on rings form a graph.

For the tree part, let $P(x)$ be generating function of the sum of pruducts if the root is not included in the independent set, and $Q(x)$ otherwise. Then we have:

$$P(x)=x(P(x)+Q(x))e^{P(x)+Q(x)}$$

$$Q(x)=xe^{P(x)}$$

We can solve the equation, and use Newton's method to calculate $P(x)$ and $Q(x)$.

Consider how to merge trees together. If one root is not in the independent set, It can either be occupied by one of its children or the previous node on the ring, so its generating function can be represented as $A(x)$(compared with $P(x)$, it adds the contribution caused by that it's occupied by the previous node on the ring), which is easy to calculate.

For those which are in the independent set, their previous nodes must not be in. So we binding them together and their generating functions can be represented as $B(x)$.

The final answer is $\sum_{i=1}^{+\infty} \frac{(A(x)+B(x))^i}{i}-A(x)=-\ln(1-A(x)-B(x))-A(x)$.

Note that when every node on the ring is occupied by previous node, it is also impossible. So we need to minus this answer. It can be calculated with similar method.

At last, we need to combine these rings into a graph, which can be done with $exp$ operation.

Time complexity is $O(n\log n)$.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=2147483647;
const long long sq5=200717101;
int M;
namespace poly{
    int R[N*4];
    long long qpow(long long a,long long b){
        long long ans=1;
        while(b){
            if(b&1)
                ans=ans*a%M;
            a=a*a%M;
            b>>=1;
        }
        return ans;
    }
    long long wn[N*4],iwn[N*4],inv[N*4],fac[N*4],ifac[N*4],g;
    void init(int E){
        int i;
        iwn[E/2]=wn[E/2]=1;
        long long s1=qpow(g,(M-1)/E);
        long long s2=qpow(s1,M-2);
        for(i=E/2+1;i<E;++i){
            wn[i]=wn[i-1]*s1%M;
            iwn[i]=iwn[i-1]*s2%M;
        }
        for(i=E/2-1;i;--i){
            wn[i]=wn[i<<1];
            iwn[i]=iwn[i<<1];
        }
        ifac[0]=fac[0]=inv[1]=1;
        for(i=2;i<E;++i)
            inv[i]=inv[M%i]*(M-M/i)%M;
        for(i=1;i<E;++i){
            ifac[i]=inv[i]*ifac[i-1]%M;
            fac[i]=fac[i-1]*i%M;
        }
    }
    unsigned long long ccc[N*4];
    void NTT(long long *f,int lim,int op){
        int i,j,k;
        for(i=0;i<lim;++i){
            R[i]=(R[i>>1]>>1)|(i&1?lim>>1:0);
            if(R[i]<i)
                swap(f[R[i]],f[i]);
        }
        for(i=0;i<lim;++i)
            ccc[i]=(f[i]%M+M)%M;
        for(i=1;i<lim;i<<=1)
            for(j=0;j<lim;j+=(i<<1))
                for(k=j;k<j+i;++k){
                    long long w=(op==1?wn[k-j+i]:iwn[k-j+i]);
                    unsigned long long p=ccc[k+i]*w%M;
                    ccc[k+i]=ccc[k]+M-p;
                    ccc[k]+=p;
                }
        for(i=0;i<lim;++i)
            f[i]=ccc[i]%M;
        if(op==-1){
            long long inv=qpow(lim,M-2);
            for(i=0;i<lim;++i)
                f[i]=f[i]*inv%M;
        }
    }
    long long ta[N*4],tb[N*4];
    void mult(long long *a,int n,long long *b,int m,long long *c){
        int lim=1;
        while(lim<n+m)
            lim<<=1;
        copy(a,a+n,ta);
        copy(b,b+m,tb);
        for(int i=n;i<lim;++i)
            ta[i]=0;
        for(int i=m;i<lim;++i)
            tb[i]=0;
        NTT(ta,lim,1);
        NTT(tb,lim,1);
        for(int i=0;i<lim;++i)
            ta[i]=ta[i]*tb[i]%M;
        NTT(ta,lim,-1);
        copy(ta,ta+lim,c);
    }
    long long tmp[N*4],tans[N*4];
    void Getinv(long long *a,long long *ans,int lim){
        ans[0]=qpow(a[0],M-2);
        for(int i=1;i<lim;i<<=1){
            for(int j=i;j<(i<<2);++j)
                ans[j]=tans[j]=tmp[j]=0;
            for(int j=0;j<(i<<1);++j)
                tmp[j]=a[j];
            for(int j=0;j<i;++j)
                tans[j]=ans[j];
            NTT(tmp,i<<2,1);
            NTT(tans,i<<2,1);
            for(int j=0;j<(i<<2);++j)
                tmp[j]=tmp[j]*tans[j]%M*tans[j]%M;
            NTT(tmp,i<<2,-1);
            for(int j=0;j<(i<<1);++j)
                ans[j]=(2*ans[j]-tmp[j])%M;
        }
    }
    long long tinv[N*4];
    void Getln(long long *a,long long *ans,int n){
        for(int i=0;i<n-1;++i)
            ans[i]=a[i+1]*(i+1)%M;
        Getinv(a,tinv,n);
        mult(ans,n-1,tinv,n,ans);
        for(int i=n;i>=1;--i)
            ans[i]=ans[i-1]*inv[i]%M;
        ans[0]=0;
    }
    long long tln[N*4];
    void Getexp(long long *a,long long *ans,int n){
        ans[0]=1;
        for(int i=1;i<n;i<<=1){
            for(int j=i;j<(i<<1);++j)
                ans[j]=0;
            Getln(ans,tln,i<<1);
            for(int j=0;j<(i<<1);++j)
                tln[j]=-tln[j]+a[j];
            ++tln[0];
            mult(ans,i,tln,i<<1,ans);
        }
    }
    void Getroot(long long *a,long long *ans,int n){
        ans[0]=1;
        for(int i=1;i<n;i<<=1){
            fill(ans+i,ans+(i<<1),0);
            Getinv(ans,tinv,i<<1);
            mult(tinv,i<<1,a,i<<1,tinv);
            for(int j=0;j<(i<<1);++j)
                ans[j]=(ans[j]+tinv[j])*inv[2]%M;
        }
    }
    long long ttln[N*4];
    void Getpow(long long *a,long long *ans,int n,int m){
        Getln(a,ttln,m);
        for(int i=0;i<m;++i)
            ttln[i]=ttln[i]*n%M;
        Getexp(ttln,ans,m);
    }
};
int n,m;
long long f[N*4],g[N*4],h[N*4],hd[N*4],tmp[N*4],eh[N*4],tmp2[N*4],inv[N*4];
void Newton(int lim){
    f[0]=f[1]=0;
    for(int i=2;i<lim;i<<=1){
        poly::Getexp(f,g,i<<1);
        for(int j=(i<<1)-1;j>=1;--j)
            g[j]=g[j-1];
        g[0]=0;
        for(int j=0;j<(i<<1);++j)
            h[j]=(f[j]+g[j])%M;
        poly::Getexp(h,eh,i<<1);
        poly::mult(eh,i<<1,h,i<<1,tmp);
        ++h[0];
        ++g[0];
        poly::mult(g,i<<1,h,i<<1,tmp2);
        poly::mult(tmp2,i<<1,eh,i<<1,tmp2);
        for(int j=(i<<1);j>=1;--j){
            tmp2[j]=-tmp2[j-1];
            tmp[j]=-tmp[j-1];
        }
        tmp2[0]=1;
        for(int j=0;j<(i<<1);++j)
            tmp[j]=(tmp[j]+f[j])%M;
        poly::Getinv(tmp2,inv,i<<1);
        poly::mult(inv,i<<1,tmp,i<<1,h);
        for(int j=0;j<(i<<1);++j)
            f[j]=(f[j]-h[j])%M;
    }
}
long long rt[N*4],X[N*4],Y[N*4],p1[N*4],p2[N*4],p[N*4],e1[N*4],e2[N*4];
long long fd[N*4],gd[N*4],as[N*4],ans[N*4],as2[N*4];
int lim=1;
int main(){
    cin>>n>>M;
    int tmpp=M-1;
    vector<int> dz;
    for(int i=2;i*i<=tmpp;++i)
        while(tmpp%i==0){
            tmpp/=i;
            dz.push_back(i);
        }
    if(tmpp!=1)
        dz.push_back(tmpp);
    for(int i=2;i<M;++i){
        int z=M-1;
        bool fl=true;
        for(auto it:dz)
            if(poly::qpow(i,z/it)==1){
                fl=false;
                break;
            }
        if(fl){
            poly::g=i;
            break;
        }
    }
    poly::init(262144);
    ++n;
    while(lim<=n*2)
        lim<<=1;
    Newton(n+1);
    memset(inv,0,sizeof(inv));
    poly::Getexp(f,g,n+1);
    for(int j=n;j>=1;--j)
        g[j]=g[j-1];
    g[0]=0;
    for(int j=0;j<=n;++j)
        h[j]=(f[j]+g[j])%M;
    poly::Getexp(h,eh,n+1);
    for(int j=1;j<=n;++j)
        tmp[j]=-eh[j-1];
    tmp[0]=1;
    poly::Getln(tmp,as2,n+1);
    for(int j=1;j<=n;++j)
        as2[j]=(as2[j]-f[j])%M;
    poly::mult(eh,n+1,h,n+1,X);
    for(int i=0;i<=n;++i)
        eh[i]=(X[i]+eh[i])%M;
    for(int i=n;i>=1;--i){
        eh[i]=eh[i-1];
        Y[i]=eh[i];
    }
    eh[0]=0;
    poly::mult(eh,n+1,g,n+1,eh);
    for(int i=1;i<=n;++i)
        h[i]=(-eh[i]-Y[i])%M;
    h[0]=1;
    poly::Getln(h,as,n+1);
    for(int i=0;i<=n;++i)
        as[i]=(-as[i]+as2[i])%M;
    poly::Getexp(as,ans,n+1);
    --n;
    for(int i=1;i<=n;++i)
        printf("%lldn",(ans[i]*poly::fac[i]%M+M)%M);
}
```
