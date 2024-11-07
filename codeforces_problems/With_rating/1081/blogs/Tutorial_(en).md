# Tutorial_(en)

[1081A - Определенная игра](../problems/A._Definite_Game.md "Avito Cool Challenge 2018")

Idea: [sunset](https://codeforces.com/profile/sunset "Легендарный гроссмейстер sunset") Developer: [sunset](https://codeforces.com/profile/sunset "Легендарный гроссмейстер sunset")

 **Hint**1 sounds like the minimum value we can get. Why? Is it always true?

 **Solution**When *n* ≤ 2, we can do nothing.

When *n* ≥ 3, since ![](images/3d5314c1a4331427610c77504be9ab70bbdae24a.png), *n* - 1 isn't a divisor of *n*, so we can choose it and get 1 as the result.

 **Code (yjq_naiive)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 2) {
    puts("2");
  } else {
    puts("1");
  }
  return 0;
}
```
[1081B - Прощальная вечеринка](../problems/B._Farewell_Party.md "Avito Cool Challenge 2018")

Idea: [yanQval](https://codeforces.com/profile/yanQval "Международный гроссмейстер yanQval") Developer: [yanQval](https://codeforces.com/profile/yanQval "Международный гроссмейстер yanQval")

 **Hint**Consider the number of people wearing hats of the same color.

 **Solution**let *b**i* = *n* - *a**i* represent the number of people wearing the same type of hat of *i*-th person.

Notice that the person wearing the same type of hat must have the same *b*s. Suppose the number of people having the same *b**i* be *t*, there would be exactly ![](images/ea56a677f48f7e7ab9727bc15d043206d71b62ed.png) kinds of hats with *b**i* wearers. Therefore, *t* must be a multiple of *b**i*. Also this is also sufficient, just give *b**i* people a new hat color, one bunch at a time.

 **Code (yanQval)**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
pair<int,int> a[maxn];
int Ans[maxn],cnt;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].first=n-a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for(int l=1,r=0;l<=n;l=r+1){
        for(r=l;r<n&&a[r+1].first==a[r].first;++r);
        if((r-l+1)%a[l].first){
            cout<<"Impossible"<<endl;
            return 0;
        }
        for(int i=l;i<=r;i+=a[l].first){
            cnt++;
            for(int j=i;j<i+a[l].first;++j)Ans[a[j].second]=cnt;
        }
    }
    cout<<"Possible"<<endl;
    for(int i=1;i<=n;i++)cout<<Ans[i]<<' ';
	return 0;
}
```
[1081C - Цветные кирпичики](../problems/C._Colorful_Bricks.md "Avito Cool Challenge 2018")

Idea: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE") Developer: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE")

 **Hint**No hint here :)

 **Solution**Let *f*[*i*][*j*] be the ways that there're *j* bricks of a different color from its left-adjacent brick among bricks numbered 1 to *i*. Considering whether the *i*-th brick is of the same color of *i* - 1-th, we have *f*[*i*][*j*] = *f*[*i* - 1][*j*] + *f*[*i* - 1][*j* - 1](*m* - 1). *f*[1][0] = *m* and the answer is *f*[*n*][*k*].

Also, there is a possibly easier solution. We can first choose the bricks of a different color from its left and then choose a different color to color them, so the answer can be found to be simply ![](images/712e4de69a7d96cee37b3627da168e5b507664fa.png).

 **Code1 (fjzzq2002)**
```cpp
//quadratic
#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,k;
long long f[2005][2005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	f[1][0]=m;
	for(int i=1;i<n;++i)
		for(int j=0;j<=k;++j)
			(f[i+1][j]+=f[i][j])%=MOD,
			(f[i+1][j+1]+=f[i][j]*(m-1))%=MOD;
	printf("%dn",int(f[n][k]));
}
```
 **Code2 (fjzzq2002)**
```cpp
//linear
#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
typedef long long ll;
ll fac[2333],rfac[2333];
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
int n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[n]=qp(fac[n],MOD-2);
	for(int i=n;i;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	printf("%lldn",m*qp(m-1,k)%MOD*fac[n-1]%MOD
	*rfac[k]%MOD*rfac[n-1-k]%MOD);
}

```
[1081D - Максимальное расстояние](../problems/D._Maximum_Distance.md "Avito Cool Challenge 2018")

Idea: [fateice](https://codeforces.com/profile/fateice "Легендарный гроссмейстер fateice") Developer: [fateice](https://codeforces.com/profile/fateice "Легендарный гроссмейстер fateice")

Sorry for the weak pretest.

 **Hint**Consider the MST of the graph.

 **Solution**Consider the minimum spanning tree formed from the *n* vertexes, we can find that the distance between two vertexes is the maximum weight of edges in the path between them in the minimum spanning tree (it's clear because of the correctness of Kruskal algorithm).

Take any minimum spanning tree and consider some edge in this spanning tree. If this edge has all special vertexes on its one side, it cannot be the answer. Otherwise, it can always contribute to the answer, since for every special vertex, we can take another special vertex on the other side of this edge. Therefore, answers for all special vertexes are the maximum weight of the edges that have special vertexes on both sides.

Besides implementing this directly, one can also run the Kruskal algorithm and maintain the number of special vertexes of each connected component in the union-find-set. Stop adding new edges when all special vertexes are connected together and the last edge added should be the answer.

 **Code (fateice)**
```cpp
#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,t,f[100010],p;
bool a[100010];
inline int fa(int i)
{
    return f[i]==i?i:f[i]=fa(f[i]);
}
struct edge
{
    int u,v,w;
    inline void unit()
    {
        u=fa(u);
        v=fa(v);
        if(u!=v)
          {
           if(a[u])
             f[v]=u;
           else
             f[u]=v;
           if(a[u] && a[v])
             p--;
           if(p==1)
             {
              for(int i=1;i<=t;i++)
                printf("%d ",w);
              printf("n");
              exit(0);
             }
          }
    }
}x[100010];
inline bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&t);
    p=t;
    for(i=1;i<=t;i++)
      {
       scanf("%d",&j);
       a[j]=1;
      }
    for(i=1;i<=m;i++)
      scanf("%d%d%d",&x[i].u,&x[i].v,&x[i].w);
    sort(x+1,x+m+1,cmp);
    for(i=1;i<=n;i++)
      f[i]=i;
    for(i=1;i<=m;i++)
      x[i].unit();
    return 0;
}
```
[1081E - Недостающие числа](../problems/E._Missing_Numbers.md "Avito Cool Challenge 2018")

Idea: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE") Developer: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE")

 **Hint**How to solve *n* = 2?

 **Solution**Let ![](images/2a8da75b8741fc27a224f99622f117cfd8b4ed89.png), *x**max* = 2 × 105.

Since *x*2*i* = *s*2*i* - *s*2*i* - 1 = *t*2*i*2 - *t*2*i* - 12 ≥ (*t*2*i* - 1 + 1)2 - *t*2*i* - 12 = 2*t*2*i* - 1 + 1, so 2*t*2*i* - 1 + 1 ≤ *x**max*, *t*2*i* - 1 < *x**max*.

For every ![](images/412083ad375a58908af24bcf9b69334a8c779257.png), we can precalculate all possible (*a*, *b*)s so that *x* = *b*2 - *a*2: enumerate all possible *a* ![](images/5e693d8ef436ba860832cb6bce422a82f9218ae6.png), then for every *a* enumerate *b* from small to large starting from *a* + 1 and stop when *b*2 - *a*2 > *x**max*, record this (*a*, *b*) for *x* = *b*2 - *a*2. Since ![](images/9d45d0c9c8de41d389b95effbb790946eb3ec342.png), then ![](images/19c9c5c692744be201f294faf803311f2aff587c.png), its complexity is ![](images/9e312081b49f4588c11ba41443c6cc4bc68c72fb.png).

Now, we can try to find a possible *s* from left to right. Since *x*2*i* - 1 is positive, we need to ensure *t*2*i* - 2 < *t*2*i* - 1. Becuase *x*2*i* = *t*2*i*2 - *t*2*i* - 12, we can try all precalculated (*a*, *b*)s such that *x*2*i* = *b*2 - *a*2. If we have several choices, we should choose the one that *a* is minimum possible, because if the current sum is bigger, it will be harder for the remaining number to keep positive.

**Bonus:** Solve *n* ≤ 103, *x*2*i* ≤ 109.

 **Bonus Hint***t*2*i*2 - *t*2*i* - 12 = (*t*2*i* - *t*2*i* - 1)(*t*2*i* + *t*2*i* + 1). Factor *x*2*i*.

 **Code1 (fjzzq2002)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
ll sq[100099];
#define S 200000
vector<pii> v[S+55];
int main()
{
	for(int i=1;i<=S;++i)
	{
		if(i*2+1>S) break;
		for(int j=i+1;j*(ll)j-i*(ll)i<=S;++j)
			v[j*(ll)j-i*(ll)i].push_back(pii(i,j));
	}
	scanf("%d",&n);
	for(int i=2;i<=n;i+=2)
	{
		int x; scanf("%d",&x);
		for(auto t:v[x])
			if(sq[i-2]<t.first)
			{
				sq[i-1]=t.first,sq[i]=t.second;
				break;
			}
		if(!sq[i-1])
		{puts("No"); return 0;}
	}
	puts("Yes");
	for(int i=1;i<=n;++i)
		printf("%lld%c",sq[i]*(ll)sq[i]-sq[i-1]
		*(ll)sq[i-1]," n"[i==n]);
}
```
 **Code2 (fjzzq2002)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> d[200099];
ll su[100099],x[100099];
int main()
{
	for(int i=1;i<=200000;++i)
		for(int j=i;j<=200000;j+=i)
			d[j].push_back(i);
	scanf("%d",&n);
	for(int i=2;i<=n;i+=2)
		scanf("%lld",x+i);
	for(int i=2;i<=n;i+=2)
	{
		for(auto j:d[x[i]])
		{
			int a=j,b=x[i]/j;
			if(((a+b)&1)||a>=b) continue;
			int s1=(b-a)/2;
			if(su[i-2]<(ll)s1*s1)
				x[i-1]=(ll)s1*s1-su[i-2];
		}
		if(x[i-1]==0)
		{
			puts("No");
			return 0;
		}
		su[i-1]=su[i-2]+x[i-1];
		su[i]=su[i-1]+x[i];
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%lld%c",x[i]," n"[i==n]);
}
```
[1081F - Коварный интерактор](../problems/F._Tricky_Interactor.md "Avito Cool Challenge 2018")

Idea: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE") Developer: [fateice](https://codeforces.com/profile/fateice "Легендарный гроссмейстер fateice"), [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE")

Yet another binary search?

 **Hint**What about parity?

 **Solution**Assuming the number of 1s changed from *a* to *b* after flipping a range of length *s*.

Let the number of 1s in the range before this flip be be *t*, then *b* - *a* = (*l* - *t*) - *t* = *s* - 2*t*, so ![](images/9eebab71564fea798e52c3f476ee8159b2a6263f.png).

So if we made a query *l*, *r*, the parities of the lengths of [1, *r*] and [*l*, *n*] are different, we can find out which one is actually flipped by parity of delta. Also if we only want [1, *r*] or [*l*, *n*] to be flipped and nothing else, we can keep querying *l*, *r* and record all the flips happened until it's the actual case (since flipping a range twice is equivalent to no flipping at all). The expected number of queries needed is 3.

 **Proof for expectation**Let *s**a*, *b* be, currently *a* ≡  the number of times [1, *r*] is flipped ![](images/a135055b720bab043a1c88ce564dcee6e8695362.png), *b* ≡  the number of times [*r*, *n*] is flipped ![](images/a135055b720bab043a1c88ce564dcee6e8695362.png), the expectation of remaining number of queries needed to complete our goal. Then *s*1, 0 = 0 (goal), we're going to find out *s*0, 0.

*s*0, 0 = (*s*0, 1 + *s*1, 0) / 2 + 1, *s*0, 1 = (*s*0, 0 + *s*1, 1) / 2 + 1, *s*1, 1 = (*s*1, 0 + *s*0, 1) / 2 + 1.

Solve this equation you'll get *s*0, 0 = 3, *s*0, 1 = 4, *s*1, 1 = 3.

Since ![](images/dce8b480e25313552f2025d9a6c8305b014be064.png), it's easy to arrive at such arrangements.

When ![](images/bdbeb9933fd5a53eae7de0226bfc38942dee1b69.png), try to query (1, 1), (1, 1), (2, 2), (2, 2), (3, 3), (3, 3)...(*n*, *n*), (*n*, *n*) and use the method described above to flip [1, 1], [1, 1], [1, 2], [1, 2], [1, 3], [1, 3]...[1, *n*], [1, *n*]. Thus we'll know *s*1, *s*1 + *s*2, *s*1 + *s*2 + *s*3...*s*1 + *s*2 + ... + *s**n* and *s* becomes obvious.

When ![](images/4e08aae15ecf5b990ad265bd3c27e271f63cf3dc.png), try to query (2, *n*), (2, *n*), (1, 2), (1, 2), (2, 3), (2, 3)...(*n* - 1, *n*), (*n* - 1, *n*) and use the method described above to flip [2, *n*], [2, *n*], [1, 2], [1, 2][1, 3], [1, 3]...[1, *n*], [1, *n*]. Thus we'll know *s*2 + *s*3 + ... + *s**n*, *s*1 + *s*2, *s*1 + *s*2 + *s*3...*s*1 + *s*2 + ... + *s**n* and *s* also becomes obvious.

Also, we can flip every range only once instead of twice by recording whether every element is currently flipped or not, although it will be a bit harder to write.

 **Code (fjzzq2002)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,ss[10005],sn=0,q[333];
bool tf(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl<<flush;
	cin>>ss[++sn];
	return (ss[sn]-ss[sn-1])&1;
}
int main()
{
	cin>>n>>ss[0]; q[n]=ss[0];
	for(int i=1;i<n;++i)
	{
		int j=i-n%2;
		if(j==0)
		{
			int t[2]={0,0},u=ss[sn];
			while(t[0]!=1||t[1]!=0)
				t[tf(2,n)]^=1;
			int v=ss[sn];
			q[i]=q[n]-(n-1-v+u)/2;
			while(t[0]||t[1])
				t[tf(2,n)]^=1;
		}
		else
		{
			int t[2]={0,0},u=ss[sn];
			while(t[0]!=1||t[1]!=0)
				t[(tf(j,i)^i)&1]^=1;
			int v=ss[sn];
			q[i]=(i-v+u)/2;
			while(t[0]||t[1])
				t[(tf(j,i)^i)&1]^=1;
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;++i)
		printf("%d",q[i]-q[i-1]);
	cout<<endl<<flush;
}
```
[1081G - Сортировка слиянием наносит ответный удар](../problems/G._Mergesort_Strikes_Back.md "Avito Cool Challenge 2018")

Idea: [quailty](https://codeforces.com/profile/quailty "Гроссмейстер quailty") Developer: [fateice](https://codeforces.com/profile/fateice "Легендарный гроссмейстер fateice"), [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE"), [sunset](https://codeforces.com/profile/sunset "Легендарный гроссмейстер sunset")

 **Hint**How does "merge" work? What is this "mergesort" actually doing?

 **Solution**First, consider how "merge" will work when dealing with two arbitrary arrays. Partition every array into several blocks: find all elements that are larger than all elements before them and use these elements as the start of the blocks. Then, by 'merging' we're just sorting these blocks by their starting elements. (This is because that when we decided to put the start element of a block into the result array, the remaining elements in the block will be sequentially added too since they're smaller than the start element)

Now back to the merge sort. What this "mergesort" doing is basically dividing the array into several segments (i.e. the ranges reaching the depth threshold). In every segment, the relative order stays the same when merging, so the expected number of inversions they contribute is just ![](images/a21c72bd7fc3e5e5f58be330a0f9d439e7df1ac4.png) (for a segment of length *l*). Again suppose every segment is divided into blocks aforementioned, we're just sorting those blocks altogether by the beginning elements.

Let's consider inversions formed from two blocks in two different segments. Say the elements forming the inversion are initially the *i*-th and *j*-th of those two segments (from left to right), then the blocks they belong start from the maximum of the first *i*-th and the first *j*-th of those two segments. Consider the maximum among these *i* + *j* numbers, if it is one of these two elements, the inversion can't be formed. The probability that the maximum is neither *i* nor *j* is ![](images/b8b8b5954e8bb5d204e8c994c0cd8af70108ff5c.png), and if the maximum is chosen, there are 50% percent of odds that the order of *i* and *j* is different from that of two maximums, because these two elements' order can be changed by swapping these two elements while leaving the maximums' order unchanged. So their probability of forming an inversion is just ![](images/6bc436be8b02b7edb0c07cb626e2b3afc7e19eb7.png).

Enumerate two blocks and *i* and precalculate the partial sum of reciprocals, we can calculate the expectation of inversions formed from these two blocks in *O*(*n*) time. However, there might be *O*(*n*) blocks. But there is one more property for this problem: those segments are of at most two different lengths. By considering same length pairs only once, we can get a *O*(*n*) or ![](images/49d24101dcdd81f4a7959288cb2ee875414fdc6a.png) solution.

 **proof of two lengths**Do an induction on *k*.

Suppose for *k* - 1 we have only segments of length *a* and *a* + 1.

If 2|*a*, let *a* = 2*t*, from 2*t* and 2*t* + 1 only segments of length *t* and *t* + 1 will be formed.

Otherwise, let *a* = 2*t* + 1, from 2*t* + 1 and 2*t* + 2 still only segments of length *t* and *t* + 1 will be formed.

**Bonus:** solve this problem when the segments' length can be arbitary and *n* ≤ 105.

 **Code (fjzzq2002)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define SZ 123456
int n,k,MOD,ts[SZ],tn=0;
ll inv[SZ],invs[SZ];
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
void go(int l,int r,int h)
{
	if(h<=1||l==r) ts[++tn]=r-l+1;
	else
	{
		int m=(l+r)>>1;
		go(l,m,h-1); go(m+1,r,h-1);
	}
}
map<ll,int> cnt;
ll calc(int a,int b)
{
	ll ans=a*(ll)b%MOD;
	for(int i=1;i<=a;++i)
		ans-=(invs[i+b]-invs[i])*2LL,ans%=MOD;
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&k,&MOD);
	for(int i=1;i<=max(n,2);++i)
		inv[i]=qp(i,MOD-2),
		invs[i]=(invs[i-1]+inv[i])%MOD;
	go(1,n,k); ll ans=0;
	for(int i=1;i<=tn;++i)
		++cnt[ts[i]],ans+=ts[i]*(ll)(ts[i]-1)/2,ans%=MOD;
	for(auto t:cnt)
		if(t.se>=2)
			ans+=calc(t.fi,t.fi)*((ll)t.se*(t.se-1)/2%MOD),ans%=MOD;
	for(auto a:cnt)
		for(auto b:cnt)
			if(a.fi<b.fi)
				ans+=calc(a.fi,b.fi)*((ll)a.se*b.se%MOD),ans%=MOD;
	ans=ans%MOD*inv[2]%MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%dn",int(ans));
}
```
[1081H - Палиндромная магия](../problems/H._Palindromic_Magic.md "Avito Cool Challenge 2018")

Idea: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE") Developer: [TLE](https://codeforces.com/profile/TLE "Легендарный гроссмейстер TLE"), [sunset](https://codeforces.com/profile/sunset "Легендарный гроссмейстер sunset")

This problem is quite educational and we didn't expect anyone to pass. :P

 **Hint**What will be counted twice?

 **Solution**Warning: This editorial is probably new and arcane for ones who are not familiar with this field. If you just want to get a quick idea about the solution, you can skip all the proofs (they're wrapped in spoiler tags).

Some symbols: All indices of strings start from zero. *x**R* stands for the reverse of string *x*. (e.g. '*abc*'*R* = '*cba*'), *xy* stands for concatenation of *x* and *y*. (e.g. *x* = '*a*', *y* = '*b*', *xy* = '*ab*'), *x**a* stands for concatenation of *a* copies of *x* (e.g. *x* = '*ab*', *x*2 = '*abab*'). *x*[*a*, *b*] stands for the substring of *x* starting and ending from the *a*-th and *b*-th character. (e.g. '*abc*'[1, 2] = '*bc*')

Border of *x*: strings with are common prefix & suffix of *x*. Formally, *x* has a border of length *t* (*x*[0, *t* - 1]) iff *x**i* = *x*|*x*| - *t* + *i* (![](images/60c4300471a97d01c8acc26c1c219e42d0a7d18a.png)).

Period of *x*: *x* has a period of length *t* iff *x**i* = *x**i* + *t* (0 ≤ *i* < |*x*| - *t*). When *t*||*x*| we also call *t* a full period. From the formulas it's easy to see *x* has a period of length *t* iff *x* has a border of length |*x*| - *t*. (![](images/83125b04df60d7e97ff6f22d81548ed289c1bfac.png))

Power: *x* is a power iff the minimum full period of *x* isn't |*x*|. e.g. abab is a power.

Lemma 1 (weak periodicity lemma): if *p* and *q* are periods of *s*, *p* + *q* ≤ |*s*|, *gcd*(*p*, *q*) is also a period of *s*.

 **Proof**Suppose *p* < *q*, *d* = *q* - *p*.

If |*s*| - *q* ≤ *i* < |*s*| - *d*, *s**i* = *s**i* - *p* = *s**i* + *d*.

If 0 ≤ *i* < |*s*| - *q*, *s**i* = *s**i* + *q* = *s**i* + *q* - *p* = *s**i* + *d*.

So *q* - *p* is also a period. Using Euclid algorithm we can get *gcd*(*p*, *q*) is a period.

Lemma 2: Let *S* be the set of period lengths  ≤ |*s*| / 2 of *s*, if *S* is non-empty, ![](images/ba9e954f7c6a07746a4a2762f160bc2d5b038da3.png).

 **Proof**Let *min* *S* = *v*, since *v* + *u* ≤ |*s*|, *gcd*(*v*, *u*) is also a valid period, so *gcd*(*v*, *u*) ≥ *v*, *v*|*u*.

Let *border*(*x*) be the longest (not-self) border of *x*. e.g. *border*('*aba*') = '*a*', *border*('*ab*') = ".

If *x* is a palindrome, its palindromic prefix and suffix must be its border. Therefore, its (not-self) longest palindromic prefix (suffix) is *border*(*x*).

 **Proof**Let |*x*| = *a*, *x* has a border of length *b* iff *x**i* = *x**a* - *b* + *i* (![](images/f6662567fc2bbb7e2d5b697adfff4be20324dab2.png)), *x* has a palindromic prefix of length *b* iff *x**i* = *x**b* - 1 - *i* (![](images/f6662567fc2bbb7e2d5b697adfff4be20324dab2.png)). Since *x**i* = *x**a* - 1 - *i*, they are just the same.

If *S* = *pq*, *p* and *q* are palindromic and non-empty, we call (*p*, *q*) a palindromic decomposition of *S*. If *S* = *pq*, *p* and *q* are palindromic, *q* is non-empty (*p* can be empty) we call (*p*, *q*) a non-strict palindromic decomposition of *S*.

Lemma 3: if *S* = *x*1 *x*2 = *y*1 *y*2 = *z*1 *z*2, |*x*1| < |*y*1| < |*z*1|, *x*2, *y*1, *y*2, *z*1 are palindromic and non-empty, then *x*1 and *z*2 are also palindromic.

 **Proof**Let *z*1 = *y*1 *v*.

*v**R* is a suffix of *y*2, also a suffix of *x*2. So *v* is a prefix of *x*2, then *x*1*v* is a prefix of *z*1.

Since *y*1 is a palindromic prefix of *z*1, *z*1 = *y*1 *v*, |*v*| is a period of *z*1. Since *x*1*v* is a prefix, so |*v*| is also a period of *x*1 *v*.

Suppose *t* be some arbitary large number (you can think of it as ∞), then *x*1 is a suffix of *v**t*.

Since *v**R* is prefix of *z*1, *x*1 is a prefix of (*v**R*)*t*. So *x*1*R* is a suffix of *v**t*, then *x*1 = *x*1*R*, so *x*1 is palindromic. *z*2 is palindromic similarly.

Lemma 4: Suppose *S* has some palindromic decomposition. Let the longest palindromic prefix of *S* be *a*, *S* = *ax*, longest palindromic suffix of *S* be *b*, *S* = *yb*. At least one of *x* and *y* is palindromic.

 **Proof**If none of them are palindromic, let *S* = *pq* be a valid palindromic decomposition of *S*, then *S* = *yb* = *pq* = *ax*, by Lemma 3, contradiction.

Lemma 5: *S* = *p*1 *q*1 = *p*2 *q*2 (|*p*1| < |*p*2|, *p*1, *q*1, *p*2, *q*2 are palindromic, *q*1 and *q*2 are non-empty), then *S* is a power.

 **Proof**We prove this by proving *gcd*(|*p*2| - |*p*1|, |*S*|) is a period.

Let |*S*| = *n*, |*p*2| - |*p*1| = *t*.

Because *p*1 is a palindromic prefix of *p*2, *t* is a period of *p*2. Similarly *t* is a period of *q*1. Since they have a common part of length *t* (namely *S*[*p*1, *p*2 - 1]), *t* is a period of *S*. So *t* is a period of *S*.

For ![](images/efb161bbe2ff1bc9611814f49964b7f2b9368901.png), *s**x* = *s*|*p*2| - 1 - *x* = *s**n* - 1 + |*p*1| - (|*p*2| - 1 - *x*) = *s**n* - *t* + *x* (first two equations are because *p*2 and *q*1 and palindromic). So *n* - *t* is also a period of *S*.

Since *t* + *n* - *t* = *n*, *gcd*(*t*, *n* - *t*) = *gcd*(*t*, *n*) is also a period of *S*. (weak periodicity lemma)

Lemma 6: Let *S* = *p*1 *q*1 = *p*2 *q*2 = ... = *p**t* *q**t* be all non-strict palindromic decompositions of *S*, *h* be the minimum full period of *S*. When *t* ≠ 0, *t* = |*S*| / *h*.

 **Proof**From Lemma 5, it's clear that *h* = |*S*| iff *t* = 1. In the following *t* ≥ 2 is assumed.

Let α = *S*[0, *h* - 1], because α is not a power (otherwise *s* will have smaller full period), α has at most one non-strict palindromic decomposition (from Lemma 5).

Let *S* = *pq* be any non-strict palindromic decomposition, then *max*(|*p*|, |*q*|) ≥ *h*. When |*p*| ≥ *h*, α = *p*[0, *h* - 1], so ![](images/bdb125e46621aa09038fd7f7b33fa201dc906b01.png), then ![](images/e6b1b70b33dde24d2fdddd9db54544cd217394d0.png) is palindromic. Similarly ![](images/905b40ceab151f665bafaebc60253224ae8b61b6.png) is also palindromic. When |*q*| ≥ *h* similar arguments can be applied. Therefore, ![](images/e6b1b70b33dde24d2fdddd9db54544cd217394d0.png) and ![](images/905b40ceab151f665bafaebc60253224ae8b61b6.png) is a non-strict palindromic decomposition of α.

Therefore, α has a non-strict palindromic decomposition. Let its only non-strict palindromic decomposition be α[0, *g* - 1] and α[*g*, *h* - 1]. Therefore, every *p**i* must satisfy ![](images/4591639e6301843b2ac41c4366cd2b27fae55f3c.png), so *t* ≤ |*s*| / *h*. Also, these all |*s*| / *h* decompositions can be obtained.

Lemma 7: Let *S* = *p*1 *q*1 = *p*2 *q*2 = ... = *p**t* *q**t* be all non-strict palindromic decompositions of *S*. (|*p**i*| < |*p**i* + 1|) For every ![](images/970d98273dae3d763a47e45a890f7dfb238baf82.png), at least one of *p**i* = *border*(*p**i* + 1) and *q**i* + 1 = *border*(*q**i*) is true.

 **Proof**Instead of proving directly, we first introduce a way to compute all decompositions.

Let the longest palindromic prefix of *S* be *a* (*a* ≠ *S*), *S* = *ax*, longest palindromic suffix of *S* be *b* (it may be *S*), *S* = *yb*.

If *x* = *b* obviously *S* = *ab* is the only way to decompose.

If *S* = *pq* and *p* ≠ *a*, *q* ≠ *b*, *p* and *q* are palindromic, by Lemma 3 we have *x*, *y* are also palindromic.

So if neither *x* or *y* is palindromic, then *S* can't be composed to two palindromes.

If exactly one of *x* and *y* is palindromic, it's the only way to decompose *S*.

If both of them are palindromic, we can then find the second-longest non-self palindromic prefix of *S*: *c*. Let *S* = *cz*, if *z* is not palindromic or *c* = *y*, then *S* = *ax* = *yb* are the only non-strict palindromic decompositions. Otherwise, we can find all palindromic suffix of |*S*| whose lengths between |*z*| and |*b*|, their prefixes must also be palindromic (using Lemma 3 for *ax* and *cz*), then *S* = *ax* = *cz* = ... = *yb* (other palindromic suffixes and their corresponding prefixes are omitted)

Back to the proof of Lemma 7, the only case we need to prove now is *S* = *ax* = *yb*. Suppose the claim is incorrect, let *p* = *border*(*a*), *s* = *border*(*y*), *S* = *ax* = *pq* = *rs* = *yb*, (|*a*| > |*p*| > |*y*|, |*a*| > |*r*| > |*y*|, *p* and *s* are palindromic)

Continuing with the proof of Lemma 6, since *t* = 2, *S* = α2. If |*p*| ≥ |α|, ![](images/e526f8a09f4315689ebe1ff34c2a0cf798189b87.png), so *q* would also be palindromic, contradiction. Therefore, |*p*| < |α| and similarly |*s*| < |α|. Let α = *pq*' = *r*'*s* and the non-strict palindromic decomposition of α be α = βθ. Since α = *pq*' = βθ = *r*'*s*, by Lemma 3 *q*' and *r*' should also be palindromic, contradiction.

Lemmas are ready, let's start focusing on this problem. A naive idea is to count the number of palindromes in *A* and in *B*, and multiply them. This will obviously count a string many times. By Lemma 7, suppose *S* = *xy*, to reduce counting, we can check if using *border*(*x*) or *border*(*y*) to replace *x* or *y* can also achieve *S*. If any of them do, reduce the answer by 1, then we're done.

So for a palindromic string *x* in *A*, we want to count strings that are attainable from both *x* and *border*(*x*) and subtract from the answer. Finding *x* and *border*(*x*) themselves can be simply done by the palindromic tree.

Let *x* = *border*(*x*)*w*, we want to count *T*s in *B* that *T* = *wS* and both *T* and *S* are palindromic. Since |*w*| is the shortest period of *x*, *w* can't be a power.

If |*w*| > |*S*|, *w* = *S* + *U*. *S* are *U* are both palindromes. Since *w* is not a power, it can be decomposed to be two palindromes in at most one way (Lemma 5). We can find that only way (by checking maximal palindromic suffix & prefix) and use hashing to check if it exists in *B*.

If |*w*| ≤ |*S*|, if *S* is not maximum palindromic suffix of *T*, *w* must be a power (Lemma 2), so we only need to check maximum palindromic suffixes (i.e. *S* = *border*(*T*)).

We need to do the similar thing to *y*s in *B*, then adding back both attainable from *border*(*x*) and *border*(*y*). Adding back can be done in a similar manner, or directly use hashing to find all matching *w* s.

Finding maximal palindromic suffix and prefix of substrings can be done by binary-lifting on two palindromic trees (one and one reversed). Let *up**i*, *j* be the resulting node after jumping through fail links for 2*j* steps from node *i*. While querying maximal palindromic suffix for *s*[*l*, *r*], find the node corresponding to the maximal palindromic suffix of *s*[1, *r*] (this can be stored while building palindromic tree). If it fits into *s*[*l*, *r*] we're done. Otherwise, enumerate *j* from large to small and jump 2*j* steps (with the help of *up*) if the result node is still unable to fit into *s*[*l*, *r*], then jump one more step to get the result.

 **Code (yjq_naiive)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 234567;
const int LOG = 18;
const int ALPHA = 26;
const int base = 2333;
const int md0 = 1e9 + 7;
const int md1 = 1e9 + 9;

struct hash_t {
  int hash0, hash1;

  hash_t(int hash0 = 0, int hash1 = 0):hash0(hash0), hash1(hash1) {
  }

  hash_t operator + (const int &x) const {
    return hash_t((hash0 + x) % md0, (hash1 + x) % md1);
  };

  hash_t operator * (const int &x) const {
    return hash_t((long long)hash0 * x % md0, (long long)hash1 * x % md1);
  }

  hash_t operator + (const hash_t &x) const {
    return hash_t((hash0 + x.hash0) % md0, (hash1 + x.hash1) % md1);
  };

  hash_t operator - (const hash_t &x) const {
    return hash_t((hash0 + md0 - x.hash0) % md0, (hash1 + md1 - x.hash1) % md1);
  };

  hash_t operator * (const hash_t &x) const {
    return hash_t((long long)hash0 * x.hash0 % md0, (long long)hash1 * x.hash1 % md1);
  }

  long long get() {
    return (long long)hash0 * md1 + hash1;
  }
} ha[N], hb[N], power[N];

struct palindrome_tree_t {
  int n, total, p[N], pos[N], value[N], parent[N], go[N][ALPHA], ancestor[LOG][N];
  char s[N];

  palindrome_tree_t() {
    parent[0] = 1;
    value[1] = -1;
    total = 1;
    p[0] = 1;
  }

  int extend(int p, int w, int n) {
    while (s[n] != s[n - value[p] - 1]) {
      p = parent[p];
    }
    if (!go[p][w]) {
      int q = ++total, k = parent[p];
      while (s[n] != s[n - value[k] - 1]) {
        k = parent[k];
      }
      value[q] = value[p] + 2;
      parent[q] = go[k][w];
      go[p][w] = q;
      pos[q] = n;
    }
    return go[p][w];
  }

  void init() {
    for (int i = 1; i <= n; ++i) {
      p[i] = extend(p[i - 1], s[i] - 'a', i);
    }
    for (int i = 0; i <= total; ++i) {
      ancestor[0][i] = parent[i];
    }
    for (int i = 1; i < LOG; ++i) {
      for (int j = 0; j <= total; ++j) {
        ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
      }
    }
  }

  int query(int r, int length) {
    r = p[r];
    if (value[r] <= length) {
      return value[r];
    }
    for (int i = LOG - 1; ~i; --i) {
      if (value[ancestor[i][r]] > length) {
        r = ancestor[i][r];
      }
    }
    return value[parent[r]];
  }

  bool check(int r, int length) {
    r = p[r];
    for (int i = LOG - 1; ~i; --i) {
      if (value[ancestor[i][r]] >= length) {
        r = ancestor[i][r];
      }
    }
    return value[r] == length;
  }
} A, B, RA, RB;

map<long long, int> fa, fb, ga, gb;
long long answer;
char a[N], b[N];
int n, m;

hash_t get_hash(hash_t *h, int l, int r) {
  return h[r] - h[l - 1] * power[r - l + 1];
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%s %s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  A.n = RA.n = n;
  B.n = RB.n = m;
  for (int i = 1; i <= n; ++i) {
    A.s[i] = RA.s[n - i + 1] = a[i];
    ha[i] = ha[i - 1] * base + a[i];
  }
  for (int i = 1; i <= m; ++i) {
    B.s[i] = RB.s[m - i + 1] = b[i];
    hb[i] = hb[i - 1] * base + b[i];
  }
  power[0] = hash_t(1, 1);
  for (int i = 1; i <= max(n, m); ++i) {
    power[i] = power[i - 1] * base;
  }
  A.init();
  B.init();
  RA.init();
  RB.init();
  answer = (long long)(A.total - 1) * (B.total - 1);
  for (int i = 2; i <= A.total; ++i) {
    ++fa[get_hash(ha, A.pos[i] - A.value[i] + 1, A.pos[i]).get()];
    int p = A.parent[i];
    if (p < 2) {
      continue;
    }
    int l = A.pos[i] - (A.value[i] - A.value[p]) + 1, r = A.pos[i];
    if (A.value[i] <= A.value[p] << 1) {
      ++ga[get_hash(ha, l, r).get()];
    }
  }
  for (int i = 2; i <= B.total; ++i) {
    ++fb[get_hash(hb, B.pos[i] - B.value[i] + 1, B.pos[i]).get()];
    int p = B.parent[i];
    if (p < 2) {
      continue;
    }
    int l = B.pos[i] - B.value[i] + 1, r = B.pos[i] - B.value[p];
    if (B.value[i] <= B.value[p] << 1) {
      ++gb[get_hash(hb, l, r).get()];
    }
  }
  for (int i = 2; i <= A.total; ++i) {
    int p = A.parent[i];
    if (p < 2) {
      continue;
    }
    int l = A.pos[i] - (A.value[i] - A.value[p]) + 1, r = A.pos[i];
    long long value = get_hash(ha, l, r).get();
    if (gb.count(value)) {
      answer -= gb[value];
    }
    int longest_palindrome_suffix = A.query(r, r - l + 1);
    if (longest_palindrome_suffix == r - l + 1) {
      continue;
    }
    if (RA.check(n - l + 1, r - l + 1 - longest_palindrome_suffix)) {
      int length = r - l + 1 - longest_palindrome_suffix;
      if (fb.count(get_hash(ha, l, l + length - 1).get()) && fb.count((get_hash(ha, l, r) * power[length] + get_hash(ha, l, l + length - 1)).get())) {
        --answer;
      }
      continue;
    }
    int longest_palindrome_prefix = RA.query(n - l + 1, r - l + 1);
    if (A.check(r, r - l + 1 - longest_palindrome_prefix)) {
      int length = longest_palindrome_prefix;
      if (fb.count(get_hash(ha, l, l + length - 1).get()) && fb.count((get_hash(ha, l, r) * power[length] + get_hash(ha, l, l + length - 1)).get())) {
        --answer;
      }
      continue;
    }
  }
  for (int i = 2; i <= B.total; ++i) {
    int p = B.parent[i];
    if (p < 2) {
      continue;
    }
    int l = B.pos[i] - B.value[i] + 1, r = B.pos[i] - B.value[p];
    long long value = get_hash(hb, l, r).get();
    if (ga.count(value)) {
      answer -= ga[value];
    }
    int longest_palindrome_suffix = B.query(r, r - l + 1);
    if (longest_palindrome_suffix == r - l + 1) {
      continue;
    }
    if (RB.check(m - l + 1, r - l + 1 - longest_palindrome_suffix)) {
      int length = longest_palindrome_suffix;
      if (fa.count(get_hash(hb, r - length + 1, r).get()) && fa.count((get_hash(hb, r - length + 1, r) * power[r - l + 1] + get_hash(hb, l, r)).get())) {
        --answer;
      }
      continue;
    }
    int longest_palindrome_prefix = RB.query(m - l + 1, r - l + 1);
    if (B.check(r, r - l + 1 - longest_palindrome_prefix)) {
      int length = r - l + 1 - longest_palindrome_prefix;
      if (fa.count(get_hash(hb, r - length + 1, r).get()) && fa.count((get_hash(hb, r - length + 1, r) * power[r - l + 1] + get_hash(hb, l, r)).get())) {
        --answer;
      }
      continue;
    }
  }
  for (int i = 2; i <= A.total; ++i) {
    int p = A.parent[i];
    if (p < 2) {
      continue;
    }
    int l = A.pos[i] - (A.value[i] - A.value[p]) + 1, r = A.pos[i];
    if (A.value[i] > A.value[p] << 1) {
      ++ga[get_hash(ha, l, r).get()];
    }
  }
  for (int i = 2; i <= B.total; ++i) {
    int p = B.parent[i];
    if (p < 2) {
      continue;
    }
    int l = B.pos[i] - B.value[i] + 1, r = B.pos[i] - B.value[p];
    if (B.value[i] > B.value[p] << 1) {
      ++gb[get_hash(hb, l, r).get()];
    }
  }
  for (auto p : ga) {
    answer += (long long)p.second * gb[p.first];
  }
  printf("%lldn", answer);
  return 0;
}
```
Hope you enjoyed the round! See you next time!

