# Tutorial_(en)

[1764A - Doremy's Paint](../problems/A._Doremy's_Paint.md "Codeforces Global Round 24")

idea: [Cocoly1990](https://codeforces.com/profile/Cocoly1990 "Master Cocoly1990")

 **Solution**
### [1764A - Doremy's Paint](../problems/A._Doremy's_Paint.md "Codeforces Global Round 24")

Assume that you have picked a interval $[L,R]$ as your answer. Now try to move the left point to make the answer larger.

Compare $[L,R]$ with $[L-1,R]$.

$\Delta(r-l)=1$ because the length of the interval increases by $1$.

$\Delta c(l,r)$ increases at most $1$. If $a_L$ appears in $[L,R]$, $c(L,R)=c(L-1,R)$; If $a_L$ does not appear in $[L,R]$, $c(L,R)+1=c(L-1,R)$.

So $[L-1,R]$ is always better than $[L,R]$.

Furthermore, we can see that if $a\le b \le c \le d$, then $[a,d]$ is better than $[b,c]$.

Since $[1,n]$ includes all intervals, it is always better than any other interval. So just output $1$ and $n$. 

 **Code**By [Imakf](https://codeforces.com/profile/Imakf "International Master Imakf")

 
```cpp
#include <iostream>

void solve(){
    int n; std::cin >> n;
    for(int i = 1 ,nouse ; i <= n ; ++i){
        std::cin >> nouse;
    }
    std::cout << "1 " << n << std::endl;
}

int main(){
    int t; std::cin >> t;
    while(t--) solve();
    return 0;
}
```
[1764B - Doremy's Perfect Math Class](../problems/B._Doremy's_Perfect_Math_Class.md "Codeforces Global Round 24")

idea: [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg")

 **Solution**
### [1764B - Doremy's Perfect Math Class](../problems/B._Doremy's_Perfect_Math_Class.md "Codeforces Global Round 24")

For any two natural numbers $x,y$ , assign $|x-y|$ to the bigger number. Repeat this process until the smaller number becomes $0$, and then the bigger number will become $\gcd(x,y)$.

So we can know that if $x,y\in S$, then it is guaranteed that $\gcd(x,y)\in S$. So $\gcd(a_1,a_2,\dots,a_n)\in S$.

Let $t=\gcd(a_1,a_2,\dots,a_n),A=\max(a_1,a_2,\dots,a_n)=Kt$, then $t,A\in S$. So $t,2t,\dots,Kt\in S$.

Because $|x-y|\le \max(x,y)$, any number bigger than $A$ will not be in $S$. Because $|xt-yt|=|x-y|t$, any number which is not divisible by $t$ will not be in $S$. And $0\not\in S$. So $t,2t,\dots,Kt$ are all the numbers that can be in $S$.

 **Code**By [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg")

 
```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int tmp=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			tmp=gcd(tmp,a[i]);
		}
		printf("%dn",a[n]/tmp+(a[1]==0));
	}
	return 0;
}
```
[1764C - Doremy's City Construction](../problems/C._Doremy's_City_Construction.md "Codeforces Global Round 24")

idea: [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg")

 **Solution**
### [1764C - Doremy's City Construction](../problems/C._Doremy's_City_Construction.md "Codeforces Global Round 24")

We can first assume that no edge links two vertices with the same value, then for each vertex $u$ and his neighbors $S_u$, either $a_u>\max\limits_{v\in S_u}a_v$ or $a_u<\min\limits_{v\in S_u}a_v$. If $a_u>\max\limits_{v\in S_u}a_v$, we paint $u$ black, otherwise we paint it white. Then it's obviously that any edge connects two vertices with different color.

So we can first determine the color of each vertex and then add as many as edges according to the color. $(u,v)$ is addable only when $u$ is black, $v$ is white and $a_u>a_v$. If we paint $u$ black and $v$ white and $a_u<a_v$, we can swap the colors and the edges connecting to these 2 vertices and the answer will be no worse. So the best painting plan is determining a value $A$, painting $u$ black if and only if $a_u\ge A$, painting $u$ white if and only if $a_u<A$.

If we add an edge linking two vertices with the same value, then the two vertices can not connect other vertices. This plan will only be considered when $a_1=a_2=\cdots=a_n$. When $a_1=a_2=\cdots=a_n$, the answer is $\lfloor\frac{n}{2}\rfloor$.

 **Code**By [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg")

 
```cpp
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch()){x=x*10+(c&15);}x*=f;
}
template<typename T>void write(T x){
	static char q[64];int cnt=0;
	if(x==0)return pc('0'),void();
	if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int maxn=200005;
int a[maxn];
int main(){
	int t;read(t);
	while(t--){
		int n;read(n);
		for(int i=1;i<=n;++i)
			read(a[i]);
		sort(a+1,a+n+1);
		if(a[1]==a[n]){
			write(n/2),pc('n');
			continue;
		}
		long long ans=0;
		for(int l=1,r=1;l<=n;l=r=r+1){
			while(r+1<=n&&a[r+1]==a[l])++r;
			ans=max(ans,1ll*(n-r)*r);
		}
		write(ans),pc('n');
	}
	return 0;
}
```
[1764D - Doremy's Pegging Game](../problems/D._Doremy's_Pegging_Game.md "Codeforces Global Round 24")

idea: [Imakf](https://codeforces.com/profile/Imakf "International Master Imakf")

 **Solution**
### [1764D - Doremy's Pegging Game](../problems/D._Doremy's_Pegging_Game.md "Codeforces Global Round 24")

The game will end immediately when the blue peg is not inside the convex formed by all remaining red pegs. Namely, there are $\lfloor \frac{n}{2} \rfloor$ consecutive red pegs removed. It can be proven by geometry. 

Assume $t=\lfloor \frac{n}{2} \rfloor$, and $n$ is odd.

Let's enumerate the ending status: there are $i$ ($t \le i\le n -2$) consecutive red pegs removed and another $j$ ($0 \le j \le n - 2 - i$) red pegs removed.

The last move makes the rubber band to stretch and touch the blue peg. So there is $2t-i$ ways to choose the last move. There are $\binom{n-2-i}{j}$ ways to choose another $j$ pegs. And there are $\binom{i+j-1}{j}j!(i-1)!$ ways to combine them.

When $n$ is even, the analysis is similar. The only difference is that there is a special case when $i = n-1$.

So the answer is: $$ \begin{aligned} & n\sum_{i=t}^{n-2} \sum_{j=0}^{n-i-2}\binom{n-i-2}{j}(i+j-1)!\cdot(2t-i) \\\ +&[n \text{ is even}]n(n-2)! \end{aligned} $$ which can be easily calculated in $O(n^2)$. 

 **Code**By [Imakf](https://codeforces.com/profile/Imakf "Master Imakf")

 
```cpp
#include <cstdio>
#include <iostream>

#define LL long long

const int MX = 5000 + 233;
LL C[MX][MX] ,n ,p ,fac[MX];

void init(){
	for(int i = 0 ; i < MX ; ++i) C[i][0] = 1;
	for(int i = 1 ; i < MX ; ++i)
		for(int j = 1 ; j < MX ; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	fac[0] = fac[1] = 1 % p;
	for(int i = 2 ; i < MX ; ++i) fac[i] = fac[i - 1] * i % p;
}

int main(){
	std::cin >> n >> p;
	init();
	int t = n / 2;
	LL Ans = 0;
	for(int i = t ; i <= n - 1 ; ++i){
		if((n & 1) && i == n - 1) break;
		int upper = (i == n - 1) ? n - i - 1 : n - i - 2;
		for(int j = 0 ; j <= upper ; ++j){
			Ans = (Ans + n * (2 * t - i) * C[upper][j] % p * fac[j + i - 1]) % p;
		}
	}
	std::cout << Ans << std::endl;
	return 0;
}
```
[1764E - Doremy's Number Line](../problems/E._Doremy's_Number_Line.md "Codeforces Global Round 24")

idea: [Imakf](https://codeforces.com/profile/Imakf "International Master Imakf")

 **Solution**
### [1764E - Doremy's Number Line](../problems/E._Doremy's_Number_Line.md "Codeforces Global Round 24")

First if $k$ can be colored with certain color, then any $K<k$ can also be colored the this color. So we only need to calculate what is the biggest number color $1$ can be. Apparently this value will not exceed $x_1+y_1$. 

If $x_1$ is not maximum among all $x$, you can pick any $j$ such that $x_j\ge x_1$. Color point $x_1$ with color $j$, then color point $x_1+y_1$ with color $1$. So $x_1+y_1$ is the answer in this case.

If $x_1$ is maximum, just enumerate which color precedes color $1$.

* No color precedes. Directly color $x_1$ with color $1$.
* Color $j$ precedes, but $x_j$ is not maximum among $x_2,x_3,\cdots,x_n$. In this case, point $x_j+y_j$ can always be colored with color $j$. Point $\min\{x_j+y_j,x_1\}+y_1$ can be colored with color $1$.
* Color $j$ precedes, meanwhile $x_j$ is maximum among $x_2,x_3,\cdots,x_n$. In this case, we can just enumerate which color precedes color $j$, which leads to a recursion, until there is only one color remaining.

Time complexity is $O(n \log n)$ due to sorting.

 **Code**By [Imakf](https://codeforces.com/profile/Imakf "Master Imakf")

 
```cpp
#include <bits/stdc++.h>

#define debug(...) fprintf(stderr ,__VA_ARGS__)
#define LL long long
const int MX = 2e5 + 5;

int n ,s;
struct Goat{
    int x ,y ,id;
}A[MX];

bool cmp(Goat a ,Goat b){
    return a.x < b.x;
}

int mx[MX];
int calc(int id){
    if(id == 1) return A[id].x;
    int far = std::max(calc(id - 1) ,mx[id - 2]);
    return std::max(std::min(far ,A[id].x) + A[id].y ,A[id].x);
}

int ans[MX];
void solve(){
    scanf("%d%d" ,&n ,&s);
    for(int i = 1 ,x ,y ; i <= n ; ++i){
        scanf("%d%d" ,&x ,&y);
        A[i] = (Goat){x ,y ,i};
        ans[i] = false;
    }
    std::sort(A + 1 ,A + 1 + n ,cmp);
    for(int i = 1 ; i <= n ; ++i){
        mx[i] = std::max(A[i].x + A[i].y ,mx[i - 1]);
    }
    for(int i = 1 ; i < n ; ++i){
        if(A[i].x + A[i].y >= s){
            ans[A[i].id] = true;
        }
    }
    if(calc(n) >= s) ans[A[n].id] = true;
    puts(ans[1] ? "YES" : "NO");
}

int main(){
    int t; scanf("%d" ,&t);
    while(t--) solve();
    return 0;
}
```
[1764F - Doremy's Experimental Tree](../problems/F._Doremy's_Experimental_Tree.md "Codeforces Global Round 24")

idea: [Cocoly1990](https://codeforces.com/profile/Cocoly1990 "Master Cocoly1990")

 **Solution**
### [1764F - Doremy's Experimental Tree](../problems/F._Doremy's_Experimental_Tree.md "Codeforces Global Round 24")

If path $(x,y) \subset (X,Y)$, then $f(x,y) > f(X,Y)$.

Then we build a graph based on $f(i,j)$, the weight of the edge between $i,j$ is $f(i,j)$. It can be shown that the MST of the graph have the same structure as the original tree.

Then we need to compute the weight for each edge. The weight of the edge between $x$ and $y$ is $\frac{f(x,x)-f(x,y)}{size_y}$, where $x$ is $y$'s parent on the tree, $size_y$ is the size of subtree $y$.

 **Code**By [Imakf](https://codeforces.com/profile/Imakf "International Master Imakf")

 
```cpp
#include <bits/stdc++.h>

#define debug(...) fprintf(stderr ,__VA_ARGS__)
#define LL long long

const int MX = 3e3 + 5;

bool vis[MX];
LL w[MX][MX] ,dis[MX];

std::vector<int> e[MX];

int size[MX];
void dfs(int x ,int f){
    size[x] = 1;
    for(auto i : e[x]){
        if(i == f) continue;
        dfs(i ,x);
        size[x] += size[i];
    }
    for(auto i : e[x]){
        if(i == f) continue;
        printf("%d %d %lldn" ,x ,i ,(w[1][x] - w[1][i]) / size[i]);
    }
}

int main(){
    int n; scanf("%d" ,&n);
    memset(w ,-0x3f ,sizeof w);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= i ; ++j){
            scanf("%lld" ,&w[i][j]);
            w[j][i] = w[i][j];
        }
    }
    memset(dis ,-0x3f ,sizeof dis);
    dis[1] = 0;
    for(int i = 1 ; i <= n ; ++i){
        int x = 0;
        for(int j = 1 ; j <= n ; ++j){
            if(!vis[j] && (!x || dis[j] > dis[x])){
                x = j;
            }
        }
        //debug("x = %d " ,x);
        //ans += dis[x];
        if(i != 1) for(int j = 1 ; j <= n ; ++j){
            if(w[j][x] == dis[x] && vis[j]){
                e[x].push_back(j);
                e[j].push_back(x);
                //debug("%d %dn" ,x ,j);
            }
        }
        vis[x] = true;
        for(int j = 1 ; j <= n ; ++j){
            dis[j] = std::max(dis[j] ,w[x][j]);
        }
    }
    //return 0;
    dfs(1 ,1);
    return 0;
}
```
[1764G3 - Doremy's Perfect DS Class (Hard Version)](../problems/G3._Doremy's_Perfect_DS_Class_(Hard_Version).md "Codeforces Global Round 24")

idea: [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg")

 **Solution**
### [1764G3 - Doremy's Perfect DS Class (Hard Version)](../problems/G3._Doremy's_Perfect_DS_Class_(Hard_Version).md "Codeforces Global Round 24")

If we add an edge between numbers $a,b$ when $\lfloor\frac{a}{2}\rfloor=\lfloor\frac{b}{2}\rfloor$, then when $n$ is an odd number, $1$ is the only one which has no neighbor, so let's consider the odd case at first.

Let the number of edges $(u,v)$ satisfying $u,v\in [l,r]$ be $C(l,r)$, then $C(l,r)+Q(l,r,2)=r-l+1$. That is to say, we can get any $C(l,r)$ with a query.

Try to use binary search to solve this problem. The key problem is for a certain $m$, determining whether $1$ is in $[1,m]$ or $[m+1,n]$. Let $2C(1,m)+x=m,2C(m+1,n)+y=n-m$. The edges between $[1,m]$ and $[m+1,n]$ must connect the remaining $x$ numbers in $[1,m]$ and the remaining $y$ numbers in $[m+1,n]$. There is exactly one number with no neighbor, so if $x=y+1$, $1$ is in $[1,m]$, otherwise $y=x+1$ and $1$ is in $[m+1,n]$. So we can do this case in $20$ queries.

If $n$ is an even number, then $1,n$ will be the only two number which has no neighbor. With the similar analysis as above, we can know if $x>y$, $1,n$ are in $[1,m]$, if $y>x$, $1,n$ are in $[m+1,n]$, otherwise $1,n$ are in the different sides. When $l<r$, we can use $Q(l,r,n)$ to check whether $n$ is in $[l,r]$. Because $n\ge 3$, we can use this method to determine $1$ is in which side. So we can do this case in $30$ queries.

Finding that we only need one extra query $Q(l,r,n)$, we can do the even case in $21$ queries.

When we decrease the range of $1$ to $[l,r]$, we have already got $C(1,l-1),C(1,r),C(l,n),C(r+1,n)$. When $l+1=r$, if $C(1,l-1)+1=C(1,r)$, we only need to know $C(1,l)$ to get the answer, if $C(l,n)=C(r+1,n)+1$, we only need to know $C(r,n)$ to get the answer, otherwise it means that $p_l=1,p_r=n$ or $p_l=n,p_r=1$, this case we also only need one more query. So we decrease the number of queries by $1$, solving this case in $20$ queries.

 **G1 Code**By [Imakf](https://codeforces.com/profile/Imakf "International Master Imakf")

 
```cpp
#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)

std::map<std::pair<int, int>, int> M;
int n;
int query(int l, int r, int k = 2) {
    if (l == r) return 1;
    if (l == 1 && r == n) {
        return n / k + 1; 
    }
    if (k == 2 && M.count(make_pair(l, r)))
        return M[make_pair(l, r)];
    printf("? %d %d %dn",l ,r, k);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (k == 2) {
        M[make_pair(l, r)] = x;
    }
    return x;
}

void answer(int x) {
    printf("! %dn", x);
    fflush(stdout);
    exit(0);
}

int main() {
     scanf("%d", &n);

    int npos = 0;
    if (n % 2 == 0) {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;

            if (query(1, mid, n) == 2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            npos = r + 1;
        }
        if (npos == 1 || npos == 2) {
            if (query(2, n, n) == 1) {
                npos = 1;
            } else {
                npos = 2;
            }
        }
    }
    //answer(npos);
    //if (n & 1) {
        int l = 1, r = n - 1, mid;
        while (l <= r) {
            debug("[%d ,%d]n",l ,r);
            mid = (l + r) >> 1;
            int lq = 2 * query(1, mid) - (mid - 1 + 1);
            int rq = 2 * query(mid + 1, n) - (n - (mid + 1) + 1);
            if (npos) {
                if (npos <= mid) --lq;
                else --rq;
            }
            if (lq > rq) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // cut [r + 1, r + 2]
        ++r;
        // now cut [r, r + 1]
        answer(r);
   // }
}
```
 **G3 Code**By [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg")

 
```cpp
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int query(int l,int r,int k){
	printf("? %d %d %dn",l,r,k);
	fflush(stdout);int re;scanf("%d",&re);
	return re;
}
void answer(int x){
	printf("! %dn",x);
	fflush(stdout);
}
int rt=-1;
void divide(int l,int r,int l1,int l2,int r1,int r2){
	if(l==r){
		answer(l);
		return;
	}
	if(l+1==r){
		if(r1==r2+1){
			if(query(r,n,2)==r2+1)answer(r);
			else answer(l);
		}
		else if(l1==l2+1){
			if(query(1,l,2)==l2+1)answer(l);
			else answer(r);
		}
		else{
			if(l>1){
				if(query(1,l,n)==2)answer(r);
				else answer(l);
			}
			else{
				if(query(r,n,n)==2)answer(l);
				else answer(r);
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	int L=query(1,mid,2),R=query(mid+1,n,2);
	if(L*2-mid>R*2-(n-mid))divide(l,mid,L,l2,r1,R);
	else if(L*2-mid<R*2-(n-mid))divide(mid+1,r,l1,L,R,r2);
	else{
		if(~rt){
			if(rt)divide(l,mid,L,l2,r1,R);
			else divide(mid+1,r,l1,L,R,r2);
		}
		if(query(1,mid,n)==2)rt=0,divide(mid+1,r,l1,L,R,r2);
		else rt=1,divide(l,mid,L,l2,r1,R);
	}
}
int main(){
	scanf("%d",&n);
	divide(1,n,n/2+1,0,n/2+1,0);
	return 0;
}
```
[1764H - Doremy's Paint 2](../problems/H._Doremy's_Paint_2.md "Codeforces Global Round 24")

idea: [Imakf](https://codeforces.com/profile/Imakf "International Master Imakf"), [waaitg](https://codeforces.com/profile/waaitg "International Master waaitg") and [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Solution**
### [1764H - Doremy's Paint 2](../problems/H._Doremy's_Paint_2.md "Codeforces Global Round 24")

The main idea of the solution is that we can try to the answers for position $x,x+1,\ldots,x+k$ all at once. We do this by representing the interval $[x+i,x+k+i)$ as $[x+i,x+k) \cup [x+k,x+k+i)$ and perform sweep line on both halves of interval.

Firstly, after applying some operations on the array $a$, we will have $a_i \leq a_{i+1}$. That is, we can instead count the number of indices such that $a_i \neq a_{i+1}$ for one less than the number of distinct elements. From here on, we will be counting the number of elements that $a_i \neq a_{i+1}$ instead.

Let us consider that the state of the array is $a$ after applying operations $[s+1,e]$. Consider the effect of applying operations $[s,e]$ instead. The change this operation will make is that we replace all $i$ such that $a_i \in [l_{s},r_{s}]$ with $a_i=l_{s}$. We can think about it as only counting $a_i \not\cong a_{i+1}$ where we can view the above operation of replacing $a_i \in [l_{s},r_{s}]$ with $l_{s}$ as instead merging $[l_{s},r_{s}]$ values as a single equivalence class which we label $l_s$.

So for interval $[x+i,x+k+i) = [x+i,x+k) \cup [x+k,x+k+i)$ we will get the equivalence class for values when considering ranges $[l_j,r_j$] with $j \in [x+i,x+k-1]$. This is a natural line sweep when considering going from $[s,x+k-1]$ to $[s-1,x+k-1]$ that uses $O(n \log n)$ by amortized analysis.

We can find the state of the array when applying operations $[x+k,x+k],[x+k,x+k+1],\ldots,[x+k,x+2k-1]$ in $O(n \log n)$ time by amoritzed analysis by only storing contiguous values as a set. By storing the changes we made when we go from $[x+k,e]$ to $[x+k,e+1]$, we are able to "undo" the changes to go from $[x+k,e+1]$ to $[x+k,e]$.

Now, we want to go from applying operations in $[x+i+1,x+k+i+1) = [x+i+1,x+k) \cup [x+k,x+k+i+1)$ to $[x+i,x+k+i) = [x+i,x+k) \cup [x+k,x+k+i)$, first we go from $[x+k,x+k+i+1)$ to $[x+k,x+k+i)$ by undoing the operation (and checking how many adjacent values are $\not\cong$), then we update our equivalence classes to go from $[x+i+1,x+k)$ to $[x+i,x+k)$.

However, The problem is that this algorithm runs in $O(\frac{m}{k} n \log n)$ time. However, we note that we can discretize the range $[1,n]$ using the ranges $[l_j,r_j]$ with $j \in [x,x+2k)$, so that our amortization works in $O(k \log k)$, to obtain a complexity of $O(\frac{m}{k} k \log k) = O(m \log k)$ (with a super huge constant). Note that since the element of the array $a$ are integers but are instead ranges now, there are some implementation details that are left as an exercise to the reader.

 **Code**By [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl 'n'

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
ii arr[600005];
int ans[400005];

vector<int> uni;
int nxt[200005];
int state[200005];
int state2[200005];

bool has(int l,int r,set<int> &s){
	auto it=s.lb(l);
	return *it<r;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	rep(x,0,m) cin>>arr[x].fi>>arr[x].se;
	rep(x,0,m) arr[x].fi--,arr[x].se--;
	rep(x,0,2*m) arr[x+m]=arr[x];
	
	int l=0;
	
	while (l<m){
		uni={0,n};
		rep(x,l,l+2*k) uni.pub(arr[x].fi),uni.pub(arr[x].se+1);
		sort(all(uni)); uni.erase(unique(all(uni)),uni.end());
		rep(x,0,sz(uni)-1) nxt[uni[x]]=uni[x+1];
		
		set<ii> s; for (auto it:uni) s.insert({it,it}); //position, color
		rep(x,0,sz(uni)) state[uni[x]]=state2[uni[x]]=1;
		
		vector<iii> proc; //time, position, state
		rep(x,l+k,l+2*k){
			if (s.count({arr[x].fi,arr[x].fi}) && state[arr[x].fi]){
				proc.pub({x,arr[x].fi,state[arr[x].fi]});
				state[arr[x].fi]=0;
			}
			
			while (true){
				auto it=s.ub(ii(arr[x].fi,1e9));
				if ((*it).fi>arr[x].se) break;
				
				if (arr[x].se+1<(*next(it)).fi) s.insert({arr[x].se+1,(*it).se});
				else{
					proc.pub({x,(*it).se,state[(*it).se]});
					state[(*it).se]=0;
				}
				
				s.erase(it);
			}
		}
		
		int curr=0;
		set<int> pos={n};
		for (auto [a,b]:s) if (b!=n){
			curr++;
			if (state[b]) curr+=nxt[b]-b-1;
			pos.insert(b);
		}
		
		s.clear(); for (auto it:uni) s.insert({it,it}); //color, position
		set<ii> ranges; rep(x,0,sz(uni)-1) ranges.insert({uni[x],uni[x+1]});
		
		rep(x,l+k,l){
			//merge things
			auto it=s.lb({arr[x].fi,-1});
			vector<int> v={(*it).se};
			while ((*it).fi<=arr[x].se){
				it=next(it);
				s.erase(prev(it));
				v.pub((*it).se);
			}
			
			if (sz(v)>1){
				rep(x,0,sz(v)-1){
					if (state[v[x]] && state2[v[x]]) curr-=v[x+1]-v[x]-1;
					state2[v[x]]=0;
					curr-=has(v[x],v[x+1],pos);
					ranges.erase({v[x],v[x+1]});
				}
				curr+=has(v[0],v[sz(v)-1],pos);
				s.insert({arr[x].fi,v[0]});
				ranges.insert({v[0],v[sz(v)-1]});
			}
			
			while (!proc.empty() && get<0>(proc.back())==x+k){
				int a,b,c; tie(a,b,c)=proc.back(); proc.pob();
				if (c){
					state[b]=c;
					if (state[b] && state2[b]) curr+=nxt[b]-b-1;
				}
				
				if (!pos.count(b)){
					auto it=prev(ranges.ub({b,1e9}));
					int l,r; tie(l,r)=*it;
					if (!has(l,r,pos)) curr++;
					pos.insert(b);
				}
			}
			
			ans[x]=curr;
		}
		
		
		l+=k;
	}
	
	rep(x,0,m) cout<<ans[x]<<" "; cout<<endl;
}
```
