# Tutorial_(en)

Hope you enjoy those tasks!

[1332A - Прогулка](../problems/A._Exercising_Walk.md "Codeforces Round 630 (Div. 2)")

 **Tutorial**
### [1332A - Exercising Walk](../problems/A._Exercising_Walk.md "Codeforces Round 630 (Div. 2)")

The key observation is x-axis and y-axis is independent in this task as the area is a rectangle. Therefore, we should only consider 1D case (x-axis, for example). The optimal path to choose alternates between right and left moves until only one type of move is possible. And sometimes there is no place to make even one move, which has to handled separately. So the verdict is "Yes" if and only if $x_1 \le x-a+b \le x_2$ and ($x_1<x_2$ or $a+b=0$). 

 **Solution (python by pikmike)**
```cpp
t = int(input())
for _ in range(t):
	a, b, c, d = map(int, input().split())
	x, y, x1, y1, x2, y2 = map(int, input().split())
	x += b - a
	y += d - c
	if a + b > 0 and x1 == x2:
		print("No")
	elif c + d > 0 and y1 == y2:
		print("No")
	elif x1 <= x <= x2 and y1 <= y <= y2:
		print("Yes")
	else:
		print("No")
```
 **Solution (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,x,y,x1,y1,x2,y2,xx,yy;

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        xx=x,yy=y;
        x+=-a+b, y+=-c+d;
        if (x>=x1&&x<=x2&&y>=y1&&y<=y2&&(x2>x1||a+b==0)&&(y2>y1||c+d==0)){
            cout<<"Yesn";
        }
        else{
            cout<<"Non";
        }
    }
    return 0;
}
```
[1332B - Непростая покраска](../problems/B._Composite_Coloring.md "Codeforces Round 630 (Div. 2)")

 **Tutorial**
### [1332B - Composite Coloring](../problems/B._Composite_Coloring.md "Codeforces Round 630 (Div. 2)")

The solution is obvious once one note that for any composite number $k$, there exists a prime $d$ such that $d \le \sqrt{k}$ and $k$ is divisible by $d$. Coincidentally, there are exactly $11$ primes below $\sqrt{1000}$. Thus, one can color balls according to their smallest divisor. That works because if all numbers of the same color have the same divisor then each pair has at least this divisor in their GCD.

 **Solution (python by pikmike)**
```cpp
from math import gcd

def getprime(x):
	for i in range(2, x):
		if x % i == 0:
			return i
	return -1

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(x) for x in input().split()]
	used = [False for i in range(11)]
	clr = []
	for i in range(n):
		x = primes.index(getprime(a[i]))
		used[x] = True
		clr.append(x)
	cnt = 0
	num = []
	for i in range(11):
		num.append(cnt)
		if used[i]:
			cnt += 1
	print(cnt)
	for i in range(n):
		x = primes.index(getprime(a[i]))
		print(num[x] + 1, end = " ")
	print()
```
 **Solution (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int n,t;
vector<int> ans[1007];
int res[1007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    auto f=[&](int u){
        for (int i=2;i<=u;++i){
            if (u%i==0) return i;
        }
    };
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=1000;++i) ans[i].clear();
        for (int i=1;i<=n;++i){
           int u;
           cin>>u; ans[f(u)].push_back(i);
        }
        int ret=0;
        for (int i=1;i<=1000;++i){
            if (ans[i].size()){
                ++ret;
                for (auto c:ans[i]){
                    res[c]=ret;
                }
            }
        }
        cout<<ret<<"n";
        for (int i=1;i<=n;++i){
            cout<<res[i]<<" ";
        }
        cout<<"n";
    }
    return 0;
}
```
[1332C - K-полное слово](../problems/C._K-Complete_Word.md "Codeforces Round 630 (Div. 2)")

 **Tutorial**
### [1332C - K-Complete Word](../problems/C._K-Complete_Word.md "Codeforces Round 630 (Div. 2)")

One should notice that word $s$ of length $n$ is $k$-complete if and only if there exists a palindrome $t$ of length $k$ such that $s$ can be generated by several concatenations of $t$.

So in the final string all characters at positions $i$, $k - i + 1$, $k + i$, $2k - i + 1$, $2k + i$, $3k - i + 1$, $\dots$ for all $1 \le i \le k$ should all be equal. This helps us to solve the problem independently for each $i$. To minimize the required number of changes, you should make all the letters equal to the one which appears at these positions the most initially. Calculate that maximum number of appearances and sum up over all $i$. Be careful with an odd $k$ because the letter in the center of each block has a different formula.

 **Solution(python by pikmike)**
```cpp
from sys import stdin

t = int(stdin.readline())
for _ in range(t):
	n, k = map(int, stdin.readline().split())
	s = stdin.readline()
	cnt = [[0 for i in range(26)] for j in range((k + 1) // 2)]
	for i in range(n):
		cnt[min(i % k, k - i % k - 1)][ord(s[i]) - ord('a')] += 1
	ans = 0
	for i in range(k // 2):
		ans += 2 * n // k - max(cnt[i])
	if k % 2 == 1:
		ans += n // k - max(cnt[k // 2])
	print(ans)
```
 **Solution(C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;

int n,k,ans=0;
int cnt[maxn][26];
string s;

int differ(int u,int v){
    int ret=0,mx=0;
    for (int j=0;j<26;++j){
        ret+=cnt[u][j]+cnt[v][j];
        mx=max(mx,cnt[u][j]+cnt[v][j]);
    }
    return ret-mx;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n>>k>>s;
        for (int i=0;i<k;++i){
            for (int j=0;j<26;++j){
                cnt[i][j]=0;
            }
        }
        for (int i=0;i<n;++i){
            cnt[i%k][s[i]-'a']++;
        }
        int ans=0;
        for (int i=0;i<k;++i){
            ans+=differ(i,k-1-i);
        }
        cout<<ans/2<<"n";
    }
    return 0;
}
```
[1332D - Прогулка по матрице](../problems/D._Walk_on_Matrix.md "Codeforces Round 630 (Div. 2)")

 **Tutorial**
### [1332D - Walk on Matrix](../problems/D._Walk_on_Matrix.md "Codeforces Round 630 (Div. 2)")

In fact, the following matrix will work: $$\left( \begin{array}{ccc} 2^{17}+k & 2^{17} & 0\\\ k & 2^{17}+k & k\\\ \end{array} \right)$$

To find such a matrix, one should find out why the dp solution fails.

One should notice that $dp_{2,2}=\max(a_{1,1}\\&a_{1,2}\\&a_{2,2},a_{1,1}\\&a_{2,1}\\&a_{2,2})$ and dp solution will choose the optimal path from $(1,1)$ to $(2,2)$ for later decision. However, we should notice that we can only discard the suboptimal result if and only if $ans_{suboptimal} \\& ans_{optimal}=ans_{suboptimal}$ rather than $ans_{suboptimal} < ans_{optimal}$. Based on above analysis, we can construct the matrix easily. 

In fact, even if $n,m$ is fixed satisfying that $n \ge 2,m \ge 2$ and $n\cdot m>4$, we could easily construct a matrix for a given $k$ based on our $2 \times 3$ matrix.

 **Solution(python by pikmike)**
```cpp
k = int(input())
x = 2**17
print(2, 3)
print(x^k, x, 0)
print(k, x^k, k)
```
[1332E - Все высоты равны](../problems/E._Height_All_the_Same.md "Codeforces Round 630 (Div. 2)")

 **Tutorial**
### [1332E - Height All the Same](../problems/E._Height_All_the_Same.md "Codeforces Round 630 (Div. 2)")

Observation 1. The actual values in the cells don't matter, only parity matters.

Proof. Using the second operation one can make all the values of same parity equal by applying it to the lowest value until done.

That observation helps us to get rid of the second operation, let us only have the first one.

Observation 2. Player is able to change parity of any pair of cells at the same time.

Proof. For any given cell $u$ and cell $v$, there exists a path from $u$ to $v$, namely $p=w_0w_1\ldots w_k$, such that $w_0=u$ and $w_n=v$. Perform operation for adjacent cells $w_{i-1}$ and $w_{i}$ for all $1 \le i \le n$

Observation 3. If $n \times m$ is odd, player can always reach the goal no matter what the initial state is.

Proof. There are two cases: there is an even number of even cells or there is an even number of odd cells. Whichever of these holds, we can change all cells of that parity to the opposite one with the aforementioned operation, making all cells the same parity.

Observation 4. If $n \times m$ is even, and $\sum_{i=1}^n \sum_{j=1}^m a_{i,j}$ is even, player can reach the goal.

Proof. Similar to the proof of Observation 3. Proof is omitted.

Observation 5. If $n \times m$ is even and $\sum_{i=1}^n \sum_{j=1}^m a_{i,j}$ is odd, player can never reach the goal no matter what strategies player takes.

Proof. Note that applying the operation never changes the parity of the number of cells of each parity (i.e. if we start with an odd number of odd cells and an odd number of even cells, they will both be odd until the end). Thus, there is no way to make zero cells of some parity.

How does that help us to calculate the answer?

The first case ($n \times m$ is odd) is trivial, the answer is all grids. Let's declare this as $total$ value.

The second case ($n \times m$ is even) is harder. Me and pikmike have different formulas to obtain it but the answer is the same.

WLOG, let's move the range of values from $[L; R]$ to $[0; R - L]$, let $k = R - L$.

Easy combinatorics solution (me):

Let's find out the number of ways to choose the grid such that the number of even cells is even and $0 \le a_i \le k$.

Suppose that there are $E$ even numbers in $[0,k]$, $O$ odds. Therefore, for any given $0 \le i \le nm$, the number of ways to have exactly $i$ even numbers should be $E^i O^{nm-i} \times \binom{nm}{i}$. Thus, the total answer should be $\sum \limits_{i=0}^{nm/2} E^{2i} O^{nm-2i} \binom{nm}{2i}$, which should remind you of the Newton expansion.

Note that $$(E+O)^{nm}=\sum_{i=0}^{nm/2}E^{2i}O^{nm-2i}\binom{nm}{2i}+\sum_{i=1}^{nm/2}E^{2i-1} O^{nm-(2i-1)} \binom{nm}{2i-1}$$

and 

$$(E-O)^{nm}=\sum_{i=0}^{nm/2}E^{2i}O^{nm-2i}\binom{nm}{2i}-\sum_{i=1}^{nm/2}E^{2i-1} O^{nm-(2i-1)} \binom{nm}{2i-1}$$.

Adding those two formulas will get us exactly the formula we were looking for but doubled. Thus, the answer is that divided by $2$.

Easy intuition solution (pikmike):

There is a general solution to this kind of problems. Let's try to pair up each valid grid with exactly one invalid grid. Valid in our problem is such a grid that the number of even cells is even. If such a matching exists then the answer is exactly half of all grids $(\frac{total}{2})$.

Let's come up with some way to pair them up. For example, this works but leaves us with two cases to handle.

Let $k$ be odd. For each grid let's replace $a_{0,0}$ with $a_{0,0}~xor~1$. You can see that the parity changed, thus the number of even cells also changed its parity. So if the grid was invalid it became valid and vice versa.

For an even $k$ it's slightly trickier but actually one can show that almost all grids pair up with each other and only a single grid remains unpaired. So we can add a fake grid and claim that the answer is $\frac{total + 1}{2}$.

The algorithm is the following. Find the first position such that the value $a_{i,j}$ on it is not equal to $k$. Replace it with $a_{i,j}~xor~1$. You can easily see that only grid that consists of all numbers $k$ has no pair.

 **Solution 1(python by pikmike)**
```cpp
MOD = 998244353

n, m, l, r = map(int, input().split())
if n * m % 2 == 1:
	print(pow(r - l + 1, n * m, MOD))
elif (r - l + 1) % 2 == 0:
	print(pow(r - l + 1, n * m, MOD) * (MOD + 1) // 2 % MOD)
else:
	print((pow(r - l + 1, n * m, MOD) + 1) * (MOD + 1) // 2 % MOD)
```
 **Solution 2(python by pikmike)**
```cpp
MOD = 998244353

n, m, l, r = map(int, input().split())
if n * m % 2 == 1:
	print(pow(r - l + 1, n * m, MOD))
else:
	e = r // 2 - (l - 1) // 2	
	o = (r - l + 1) - e
	print((pow(e + o, n * m, MOD) + pow(e - o, n * m, MOD)) * (MOD + 1) // 2 % MOD)
```
[1332F - Независимое множество](../problems/F._Independent_Set.md "Codeforces Round 630 (Div. 2)")

 **Tutorial**
### [1332F - Independent Set](../problems/F._Independent_Set.md "Codeforces Round 630 (Div. 2)")

We will call one vertice is colored if and only if it is in the independent set. And a coloring is valid if and only if no two adjacent vertices are both colored.

Therefore, we are asked to calculate the sum of number of valid colorings over all edge induced subgraphs.

To deal with the task, one should notice that for a edge induced subgraph and one valid coloring, we may add those vertices which are removed due to the generation of edge induced subgraph, and remain it uncolored.

Therefore, for a coloring on the original graph $G=(V,E)$, we could consider removing edges such that it will behave the same with above procedure.

In fact, given a coloring, we can define edge removing is valid if and only if there is no adjacent colored vertice and no isolated vertex is colored. We can actually show that there is almost a one to one corresponding relation betweeen those two procedure except for the case where all vertices remains uncolored and all edges are removed.

Therefore, we can actually solve the following task:

Given a tree $G=(V,E)$, for any given coloring, define a edge removal is valid if it satisfies above constrains.

And it will suddenly becoming something easy to solve with tree dp. Define $dp_{u,0}$ be the answer for subtree rooted at $u$ with additional constraint such that $u$ is not colored, $dp_{u,1}$ be the answer where $u$ is colored and $dp_u$ be the answer where edges from $u$ to its children are removed.

Therefore, the dp formula should be 

* $dp_{u,0}=\prod_{v}(2dp_{v,0}+2dp_{v,1}-dp_v)$
* $dp_{u,1}=\prod_{v}(2dp_{v,0}+dp_{v,1}-dp_v)$
* $dp_{u}=\prod_{v}(dp_{v,0}+dp_{v,1}-dp_v)$

The answer is easily calculated with those three states.

 **Solution(C++)**
```cpp
#include<bits/stdc++.h>
#define int long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
#define debug cout<<"potxdy"<<endl; 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=300007;
const int mod=998244353;

int n,dp[maxn][2],f[maxn]; 
VI vec[maxn];

int mult(int u,int v){
    u=(u%mod+mod)%mod, v=(v%mod+mod)%mod;
    return 1ll*u*v%mod;
}

void dfs(int u,int p){
    dp[u][0]=dp[u][1]=f[u]=1;
    for (auto c:vec[u]){
        if (c==p) continue;
        dfs(c,u);
        dp[u][0]=mult(dp[u][0],2*dp[c][0]+2*dp[c][1]-f[c]);
        dp[u][1]=mult(dp[u][1],dp[c][1]+2*dp[c][0]-f[c]);
        f[u]=mult(f[u],dp[c][0]+dp[c][1]-f[c]);
    }
}

#undef int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        vec[u].pb(v), vec[v].pb(u);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1]-f[1]-1+2*mod)%mod<<endl;
    return 0;
}
```
[1332G - Без монотонных троек](../problems/G._No_Monotone_Triples.md "Codeforces Round 630 (Div. 2)")

Contributor of idea of the solution: [awoo](https://codeforces.com/profile/awoo "Мастер awoo")

 **Tutorial**
### [1332G - No Monotone Triples](../problems/G._No_Monotone_Triples.md "Codeforces Round 630 (Div. 2)")

We will solve this task with the following observations.

Observation 1. If an array $x$ of length $k$ ($k \ge 3$) has no monotone triple, then one of the following is true: 

* $x_1<x_2>x_3<x_4>x_5<\ldots$
* $x_1>x_2<x_3>x_4<x_5>\ldots$

Observation 2. If an array $x$ of length $k$ ($k \ge 4$) has no monotone triple, then its subsequence has no monotone triple.

Observation 3. If an array $x$ of length 4 has no monotone triple, then $max(x_2,x_3)>max(x_1,x_4)$, $min(x_2,x_3)<min(x_1,x_4)$,vice versa.

Proof. WLOG, we assume $max(x_2,x_3)\le x_1$, by observation 1 we will know that $x_1>x_2<x_3>x_4$, since $x_1\ge x_3$, we get a monotone triple $(1,3,4)$, leading to contradiction. Second part can be verified easily.

Observation 4. For every array $x$ of length $k$ ($k \ge 5$), $x$ must have monotone triple.

Proof. WLOG, we just need to prove the observation holds when $k=5$ and cases when not all elements are equal. In that case, one of extremal can be reached in position other than $3$. WLOG, we will assume that maximum is reached at position $2$. However, $x_2,x_3,x_4,x_5$ cannot be monotone-triple-free, leading to contradiction!

Combining those observations (or Erdos–Szekeres theorem if you know it), we would like to get the following solution, which runs in $O(q n^4)$. 

* If the subsequence is monotone, the answer should be 0.
* If there exists $i,j,k,l$ such that $L \le i<j<k<l \le R$ and $a_i$, $a_l$ fails to reach maximum and minimum among those four numbers, the answer should be 4.
* Otherwise, the answer should be 3.

In the following paragraphs, we will only focus on the case of $4$. Other stuffs can be dealt similarly (or easily).

$O(n^2)$ solution(the observation is crucial to obtain a faster solution)

Notice that constraint is equivalent to that there exists $i,j$ such that $a_i,a_j$ fails to reach maximum and minimum among $a_i,a_{i+1},\ldots,a_j$. This observation allows us to solve this task in $O(n^2)$ with some precalculation. (though it's still not enough to get accepted).

$O(n \log n)$ solution

Let's solve the task for a sequence of a pairwise distinct numbers and then change the conditions to a general sequence.

Let's fix $a_i$ — the leftmost element of $b$ and look at what we are asked to find. So there should be some position $j$ to the right of $i$ so that the range of values on positions $[i, j]$ excluding the greatest and the smallest values includes both $a_i$ and $a_j$.

Let's process the array from right to left, maintaining two stacks. The top element in both stacks is the currently processed one. Next element of the first stack is the closest to the right element greater than the top one, and the next element of the second stack is the closest to the right smaller than the top one. And the stacks go like that until the end of array.

Iterating over one of these stacks will show the increase of the range of values in one direction, iterating over both at the same time will show how the range of values changes in total.

So I claim that the sequence we are looking for exists iff both stacks include more than $1$ element and there is an element to the right of second elements of both stacks such that it is included in neither of the stacks. Naturally that condition tells that there is some position in which neither maximum, nor minimum values are updated.

The values that are in neither of stacks can be maintained in a queue or in a BIT.

Basically, the position when the range of values doesn't change is such a value which is both smaller than the maximum value on the segment and greater than the minimum one. Thus, we can choose $a_i$, the latest elements in both stacks up to that position and that position itself.

How to deal with not pairwise distinct elements? Well, it's enough to change the conditions in stacks to the next greater or equal and the next smaller or equal. However, that will push the elements equal to the current one right next to it to the both stacks. Previously we kinda used the fact that no element except the current one is in both stacks. I think that the easiest way to deal with it is to get the answer for the rightmost of the consecutive equal elements and then just say that the answer for the rest of them is the same. Finally, push all these consecutive equal elements to the both stacks.

As for queries. I previously said that we can take the position where the value range doesn't change. Basically, the first valid position is coincidentally the shortest length valid segment starting from $i$. So to find the first position you just need to do a binary search over that queue or BIT of the values which are in neither of the stacks. We can easily remember it for each position and then do a range minimum query checking if any of the positions in $[l, r]$ have their shortest right border smaller than $r$.

 **Solution (C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int maxn=200007;
int n,q,a[maxn],b[maxn],c[maxn],t[maxn],sum[maxn];
int st1[maxn],st2[maxn],p1,p2,r1,r2,s1,s2;
int ans1[maxn][4],ans2[maxn][4];
set<int> s;

bool cmp1(int u,int v){
    return a[u]<a[v];
}

bool cmp2(int u,int v){
    return a[u]>a[v];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    p1=p2=r1=r2=0;
    s.insert(n+1);
    for (int i=n;i>0;--i){
        while (p1){
            int u=st1[p1];
            if (a[u]>a[i]){
                t[u]--;
                if (!t[u]) s.insert(u);
                p1--;
                r1=0;
            }
            else{
                break;
            }
        }
        while (p2){
            int u=st2[p2];
            if (a[u]<a[i]){
                t[u]--;
                if (!t[u]) s.insert(u);
                p2--;
                r2=0;
            }
            else{
                break;
            }
        }
        s1=lower_bound(st1+1,st1+p1+1,i,cmp1)-st1-1, s2=lower_bound(st2+1,st2+p2+1,i,cmp2)-st2-1;
        b[i]=i+max(r1,r2)+1;
        ans1[i][0]=i, ans1[i][1]=b[i]-1, ans1[i][2]=b[i];
        if (s1&&s2){
            c[i]=*s.lower_bound(max(st1[s1],st2[s2]));
            if (c[i]<=n){
                int u=lower_bound(st1+1,st1+p1+1,c[i],greater<int>())-st1,v=lower_bound(st2+1,st2+p2+1,c[i],greater<int>())-st2;
                ans2[i][0]=i, ans2[i][1]=min(st1[u],st2[v]), ans2[i][2]=max(st1[u],st2[v]), ans2[i][3]=c[i];
            }
        }
        else{
            c[i]=n+1;
        }
        st1[++p1]=i;
        st2[++p2]=i;
        r1++, r2++;
        t[i]+=2;
        if (i<n&&b[i]>b[i+1]){
            b[i]=b[i+1];
            for (int j=0;j<3;++j){
                ans1[i][j]=ans1[i+1][j];
            }
        }
        if (i<n&&c[i]>c[i+1]){
            c[i]=c[i+1];
            for (int j=0;j<4;++j){
                ans2[i][j]=ans2[i+1][j];
            }
        }
    }
    while (q--){
        int l,r;
        cin>>l>>r;
        if (r>=c[l]){
            cout<<"4n";
            for (int j=0;j<4;++j){
                cout<<ans2[l][j]<<" ";
            }
            cout<<"n";
        }
        else{
            if (r>=b[l]){
                cout<<"3n";
                for (int j=0;j<3;++j){
                    cout<<ans1[l][j]<<" ";
                }
                cout<<"n";
            }
            else{
                cout<<"0nn";
            }
        }
    }
    return 0;    
}
```
