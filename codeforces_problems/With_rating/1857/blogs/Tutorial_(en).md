# Tutorial_(en)

[1857A - Раскраска массива](../problems/A._Array_Coloring.md "Codeforces Round 891 (Div. 3)")

Author: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), prepared: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857A - Раскраска массива](../problems/A._Array_Coloring.md "Codeforces Round 891 (Div. 3)")

Let's analyze the impact of adding odd or even numbers to a set with sum $S$:

1. If you add an even element to the set, the parity of $S$ remains unchanged.
2. If you add an odd element to the set, the parity of $S$ changes.

Based on this observation, let's focus on the coloring of odd elements in the array. The number of odd elements colored in blue and the number of odd elements colored in red must have the same parity for a valid coloring. This is because we need to divide the odd elements into two parts (blue and red).

To achieve the same parity for both blue and red odd elements, the total number of odd elements in the array must be even. If it is not even, we won't be able to create two sets with the same parity.

Hence, the answer is "YES" if the number of odd elements in the array is even, and "NO" otherwise.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(x%2!=0)cnt++;
        }
        if(cnt%2==0)cout<<"YESn";
        else cout<<"NOn";
    }
}
```
 **Code Python**
```cpp
for i in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    cnt=0
    for i in range(n):
        if a[i]%2!=0:cnt+=1
    if cnt%2==0:print('YES')
    else:print('NO')
```
 **Rate the problem*** Good task 


[*426*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*85*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
[1857B - Максимальное округление](../problems/B._Maximum_Rounding.md "Codeforces Round 891 (Div. 3)")

Author: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), prepared: [FBI](https://codeforces.com/profile/FBI "Кандидат в мастера FBI"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857B - Максимальное округление](../problems/B._Maximum_Rounding.md "Codeforces Round 891 (Div. 3)")

First, sorry for the unclear statement. We have rewritten it for several times and have chosen the best one.

Let's define $n$ as the length of the $x$.

Notice, that after applying the rounding to $k$, all the digits to the right of $k$ become $0$. If the $k$-th digit is less than $5$, after the rounding it'll only worsen the answer.

On the other side, if the $k$-th digit is not less than $5$, than rounding to the $k$-th digit always leads to better answer, because after the operation $x$ will increase.

From these observations, we can come up with the following greedy algorithm: look through all $k$ from $1$ to $n$, and if the $k$-th digit is not less than $5$, we use the rounding operation adding one to the ($k+1$)-th digit. And don't worry if that digit which must be increased by one is $9$, because in such case we always use the rounding operation on the next step.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        s='0'+s;
        int p=s.size();
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='5')s[i-1]++,p=i;
        }
        for(int i=(s[0]=='0');i<s.size();i++)
        {
            cout<<(i>=p?'0':s[i]);
        }
        cout<<"n";
    }
}
```
 **Code Python**
```cpp
for i in range(int(input())):
    s=[0]+[*map(int,list(input()))]
    k=len(s)
    for i in range(len(s)-1,0,-1):
        if s[i]>4:s[i-1]+=1;k=i
    if s[0]!=0:print(s[0],end='')
    s=[*map(str,s)]
    print(''.join(s[1:k]+['0']*(len(s)-k)))
```
 **Rate the problem*** Good task 

 
[*217*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*82*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*516*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
[1857C - Построение по минимумам](../problems/C._Assembly_via_Minimums.md "Codeforces Round 891 (Div. 3)")

Author: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), prepared: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857C - Построение по минимумам](../problems/C._Assembly_via_Minimums.md "Codeforces Round 891 (Div. 3)")

Suppose we have an array $a$ that we want to construct, with elements $a_1, a_2, \dots, a_n$. To simplify the process, let's assume that the elements of $a$ are sorted in non-decreasing order, meaning $a_1 \le a_2 \le \dots \le a_n$.

Let's start with $a_1$. Since the elements of $a$ are sorted, the pairs $(a_1, a_2), (a_1, a_3), \dots, (a_1, a_n)$ will have $a_1$ as the smallest element in each pair. Therefore, the number of occurrences of $a_1$ in array $b$ will be $n-1$.

Moving on to $a_2$, we already know that $a_1$ appears $n-1$ times in $b$. Since the elements of $a$ are sorted, all pairs involving $a_2$ will have $a_2$ as the second smallest element. This means $a_2$ will appear $n-2$ times in array $b$.

We continue this process for each element $a_i$ in $a$. The number of occurrences of $a_i$ in array $b$ will be $n-i$.

We can't determine the exact value of $a_n$ , because it won't be written to array b. Therefore, for $a_n$ we can choose any number in the range $[a_{n-1};10^9]$. 

In case there are multiple elements $b_i$ in array $b$ that satisfy the condition for a particular $a_i$, we choose the smallest $b_i$. This greedy approach works, because we are constructing $a$ in non-decreasing order.

The complexity is $O(n^2 \log n)$.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int m=n*(n-1)/2,b[m];
        for(int i=0;i<m;i++)cin>>b[i];
        sort(b,b+m);
        for(int i=0;i<m;i+=--n)cout<<b[i]<<' ';
        cout<<"1000000000n";
    }
}
```
 **Code Python**
```cpp
for _ in range(int(input())):
    n=int(input())
    l=sorted(map(int,input().split()))
    j=0
    for i in range(n-1,0,-1):
        print(l[j],end=' ')
        j+=i
    print(l[-1])
```
 **Rate the problem*** Good task 

 
[*537*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*62*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*62*](https://codeforces.com/data/like?action=like "I like this")
[1857D - Сильные вершины](../problems/D._Strong_Vertices.md "Codeforces Round 891 (Div. 3)")

Author: [Pa_sha](https://codeforces.com/profile/Pa_sha "Эксперт Pa_sha"), prepared: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857D - Сильные вершины](../problems/D._Strong_Vertices.md "Codeforces Round 891 (Div. 3)")

The first step is to modify the inequality. 

$a_u-a_v \geq b_u-b_v \Leftrightarrow a_u-b_u \geq a_v-b_v$.

We can create a new array $c$, where $c_i=a_i-b_i$ and our inequality is transformed to $c_u\geq c_v$. 

Suppose the set $p_1,\dots p_m$ is the set of such vertices $v$ that $c_v$ is maximum possible. From each $p_i$ there will be a path to all other vertices, because $c_{p_i}$ is not less than any other $c_u$, so the set $p$ is guaranteed will be in our answer. 

Now the question is whether there are other vertices in our answer?

Let's prove that from any such vertex $v$, that is not maximum, there is no path to any vertex from $p$. The first observation, that there is no edge between $v$ and any $p_i$. So the path must go through other vertices. But even if there exist a path to another vertex $u$, $c_u$ will be still less that $c_{p_i}$, so it is impossible to get any $p_i$.

In such way we proved that the answer will always be the set of such $v$, that $c_v$ is maximized.

The complexity is $O(n)$.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int mx=INT_MIN;
        for(int i=1;i<=n;i++)mx=max(mx,a[i]-b[i]);
        int c=0;
        for(int i=1;i<=n;i++)c+=(a[i]-b[i]==mx);
        cout<<c<<"n";
        for(int i=1;i<=n;i++)if(a[i]-b[i]==mx)cout<<i<<' ';
        cout<<"n";
    }
}
```
 **Code Python**
```cpp
for _ in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    b=[*map(int,input().split())]
    c=[a[i]-b[i] for i in range(n)]
    mx=max(c)
    ans=[]
    for i in range(n):
        if c[i]==mx:ans.append(i+1)
    print(len(ans))
    print(*ans)
```
 **Rate the problem*** Good task 

 
[*335*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*53*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
[1857E - Мощность точек](../problems/E._Power_of_Points.md "Codeforces Round 891 (Div. 3)")

Author: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), prepared: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857E - Мощность точек](../problems/E._Power_of_Points.md "Codeforces Round 891 (Div. 3)")

If we have the segments $[l_1,r_1],\dots,[l_n,r_n]$, the sum of $f_p$ is the sum of the segments' lengths. That's because a segment $[a,b]$ intersect exactly $b-a+1$ points. Now we can find the answer for fixed $s$ in $O(N)$. 

How to do it more efficiently?

Let's sort the given points so that $x_1\le x_2\le \dots \le x_n$.

Processing $s=x_i$ we get that for all $j\le i$ the segments are $[x_j,s]$ and for all $j>i$ the segments are $[s,x_j]$. We need to summarize their lengths. Formally we need to calculate 

$$ \sum\limits_{j=1}^{i}(s-x_j+1)+\sum\limits_{j=i+1}^{n}(x_j-s+1)= $$

$$ n+s \cdot i-\sum\limits_{j=1}^{i}x_j+\sum\limits_{j=i+1}^{n}x_j -s(n-i)= $$

$$ n+s(2\cdot i-n)-\sum\limits_{j=1}^{i}x_j+\sum\limits_{j=i+1}^{n}x_j $$

We can maintain the sum of coordinates on the prefix and suffix, and calculate this formula for fixed $s$ in $O(1)$.

The total complexity is $O(n\log n)$.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
pair<int,int>x[N];
long long a[N];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        long long s1=0,s2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i].first;
            x[i].second=i;
            s2+=x[i].first;
        }
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++)
        {
            s2-=x[i].first;
            s1+=x[i].first;
            a[x[i].second]=n+1ll*x[i].first*(2*i-n)-s1+s2;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" n"[i==n];
    }
}
```
 **Code Python**
```cpp
for i in range(int(input())):
    n=int(input())
    a=sorted([(b,i)for i,b in enumerate(map(int,input().split()))])
    ans=[0]*n
    s1=0
    s2=sum(a[i][0] for i in range(n))
    for i in range(n):
        ans[a[i][1]]=s2-a[i][0]*(n-i)+n-i+a[i][0]*i-s1+i
        s1+=a[i][0]
        s2-=a[i][0]
    print(*ans)
```
 **Rate the problem*** Good task 

 
[*319*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*54*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*30*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")
[1857F - Сумма и произведение](../problems/F._Sum_and_Product.md "Codeforces Round 891 (Div. 3)")

Author: [Pa_sha](https://codeforces.com/profile/Pa_sha "Эксперт Pa_sha"), prepared: [Pa_sha](https://codeforces.com/profile/Pa_sha "Эксперт Pa_sha"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857F - Сумма и произведение](../problems/F._Sum_and_Product.md "Codeforces Round 891 (Div. 3)")

The system of equations in the statement resembles Vieta's formula for quadratic equations. If we have $$ \begin{cases} a_i + a_j = b \\\ a_i \cdot a_j = c \end{cases} $$ the quadratic equation will be $x^2 - bx + c = 0$, here $a_i$ and $a_j$ will be its roots.

To find the roots of the quadratic equation, we can use the discriminant formula, $D = b^2 - 4ac$. The roots will then be $x_1 = \frac{b - \sqrt{D}}{2}$ and $x_2 = \frac{b + \sqrt{D}}{2}$.

Once we have the potential integer values for $a_i$ and $a_j$, we can calculate the number of pairs by multiplying the number of occurrences, respectively.

However, remember to consider some special cases:

1. If $D < 0$, the equation won't have real roots.
2. If $D = 0$, then $x_1 = x_2$, the formula for counting pairs in this case is different.

The complexity of this solution is $O((n + q) \log n)$, using maps to store integer occurrences.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
map<long long,int>cnt;
long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
long long get(int b,long long c)
{
    long long D=1ll*b*b-4ll*c;
    if(D<0)return 0;
    long long x1=(b-my_sqrt(D))/2;
    long long x2=(b+my_sqrt(D))/2;
    if(x1+x2!=b||x1*x2!=c)return 0;
    if(x1==x2)return 1ll*cnt[x1]*(cnt[x1]-1)/2ll;
    else return 1ll*cnt[x1]*cnt[x2];
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cnt.clear();
        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            cnt[x]++;
        }
        int q;cin>>q;
        for(int i=0;i<q;i++)
        {
            int b;long long c;
            cin>>b>>c;
            cout<<get(b,c)<<" n"[i==q-1];
        }
    }
}
```
 **Code Python**
```cpp
from collections import Counter
from math import sqrt
 
for _ in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    d=Counter(map(str,a))
    for i in range(int(input())):
        x,y=map(int,input().split())
        if x*x-4*y<0:print(0);continue
        D=int(sqrt(x*x-4*y))
        x1=(x+D)//2
        x2=(x-D)//2
        if x1+x2!=x or x1*x2!=y:print(0);continue
        if x1!=x2:print(d[str(x1)]*d[str(x2)])
        else:print(d[str(x1)]*(d[str(x1)]-1)//2)
```
 **Rate the problem*** Good task 

 
[*239*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*83*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*83*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*28*](https://codeforces.com/data/like?action=like "I like this")
[1857G - Подсчет графов](../problems/G._Counting_Graphs.md "Codeforces Round 891 (Div. 3)")

Author: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), prepared: [SashaT9](https://codeforces.com/profile/SashaT9 "Эксперт SashaT9"), [Skillful_Wanderer](https://codeforces.com/profile/Skillful_Wanderer "Эксперт Skillful_Wanderer")

 **Tutorial**
### [1857G - Подсчет графов](../problems/G._Counting_Graphs.md "Codeforces Round 891 (Div. 3)")

The first observation is that the graphs will consist of $n$ vertices because the MST is fixed. Hence, the graphs will look like the given tree with some new vertices connected.

The next step is to determine the possible weights of a new edge between vertices $u$ and $v$. Let $P(u,v)$ be the maximum weight on the simple path from $u$ to $v$. I assume that we can add a new edge between vertices $u$ and $v$ with any weight in the range $[P(u,v)+1,S]$. This becomes clear when we consider some examples. If the edge has a weight less or equal than $P(u,v)$, the MST will change by taking the new edge instead of the edge with the maximal weight on the path.

Notice that if we add a new edge, and it doesn't affect the MST, we can add one more edge independently from the previous.

So now the task is to calculate $\prod\limits_{1\le u < v \le n}{} (S-P(u,v)+1)$, because for each pair of vertices, we can assign a new weight from the range, which gives us $S-P(u,v)$ cases, or we can choose not to add any edge, which is one more case.

Now, let's discuss how to calculate the formula efficiently:

1. Sort the given edges in ascending order according to their weights: $w_1\le w_2\le \dots \le w_{n-1}$.
2. We'll begin from the graph without edges, and add new ones step by step. Suppose, we already added all the edges up to $u_i,v_i,w_i$. Now, we want to add the $i$-th one. Notice that $w_i$ is greater than any of the weights before, and $u_i$ and $v_i$ are from different components.
3. After adding the edge, we need to calculate the number of paths that go through this edge. If we know the sizes of the components containing $u_i$ and $v_i$, denoted as $s_u$ and $s_v$ respectively, then there exist $s_u\cdot s_v-1$ paths through edge $u_i,v_i$ without including the path formed by these two vertices.
4. We know the number of paths, and on each of these paths, we can determine the weight we can put on the edge. Thus, we need to multiply answer by $(S-w_i+1)^{s_u\cdot s_v-1}$, using binary exponentiation.

To add edges and find the sizes of the components efficiently, you can use DSU (Disjoint Set Union).

The complexity of this approach is $O(n\log n)$.

 **Code C++**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=200000,mod=998244353;
int p[N+1],sz[N+1];
struct edge
{
    int u,v,w;
    void read(){cin>>u>>v>>w;}
    bool operator<(edge x){return w<x.w;}
}a[N+1];
int leader(int v)
{
    if(p[v]==v)return v;
    else return p[v]=leader(p[v]);
}
void unite(int u,int v)
{
    u=leader(u);
    v=leader(v);
    p[u]=v;
    sz[v]+=sz[u];
}
long long binpow(long long a,long long n)
{
    if(n==0)return 1;
    if(n%2==0)return binpow(a*a%mod,n/2);
    else return a*binpow(a,n-1)%mod;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,S;cin>>n>>S;
        for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
        for(int i=0;i<n-1;i++)a[i].read();
        sort(a,a+n-1);
        long long ans=1;
        for(int i=0;i<n-1;i++)
        {
            int sub_u=sz[leader(a[i].u)];
            int sub_v=sz[leader(a[i].v)];
            ans=ans*binpow(S-a[i].w+1,1ll*sub_u*sub_v-1)%mod;
            unite(a[i].u,a[i].v);
        }
        cout<<ans<<"n";
    }
}
```
 **Code Python**
```cpp
mod=998244353
def find_(v):
    stack=[v]
    while dsu[v]!=v:
        stack.append(dsu[v])
        v=stack[-1]
    while stack:
        dsu[stack[-1]]=dsu[v]
        v=stack.pop()
    return dsu[v]
 
for i in range(int(input())):
    n,S=map(int,input().split())
    l=[tuple(map(int,input().split()))for i in range(n-1)]
    l.sort(key=lambda x:x[2])
    ans=1
    dsu=[i for i in range(n)]
    coun=[1]*n
    for a,b,c in l:
        a-=1;b-=1
        if find_(a)!=find_(b):
            ans=ans*pow(S-c+1,coun[dsu[a]]*coun[dsu[b]]-1,mod)
            ans%=mod
            coun[dsu[a]]+=coun[dsu[b]]
            coun[dsu[b]]=0
            dsu[b]=dsu[a]
    print(ans)
```
 **Rate the problem*** Good task 

 
[*313*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")
