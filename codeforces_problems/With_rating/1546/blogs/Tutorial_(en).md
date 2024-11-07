# Tutorial_(en)


### [1546A - AquaMoon and Two Arrays](../problems/A._AquaMoon_and_Two_Arrays.md "Codeforces Round 732 (Div. 2)")

First, if the sum of elements in a is not equal to the sum of elements in b, then the solution does not exist.

Each time find a position i satisfying ai>bi, and find such a j satisfying aj<bj. Then let ai−1, aj+1, until the two arrays become the same.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define O(x) cout<<#x<<" "<<(x)<<"n"
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=104;
int n,sum,a[N];
vector<pair<int,int> >ans;
inline void solve(){
	n=read();
	sum=0;
	ans.clear();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		a[i]-=read();
		sum+=a[i];
	}
	if(sum){puts("-1");return;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			for(int k=1;k<=n;k++)if(a[k]<0){
				ans.push_back(make_pair(i,k));
				++a[k];
				break;
			}
		}
	}
	cout<<ans.size()<<"n";
	for(auto v:ans)cout<<v.first<<" "<<v.second<<"n";
}
int main(){
	for(int T=read();T--;)solve(); 
	return 0;
}
```
Idea: [Cirno_9baka](https://codeforces.com/profile/Cirno_9baka "International Grandmaster Cirno_9baka") 

### [1546B - AquaMoon and Stolen String](../problems/B._AquaMoon_and_Stolen_String.md "Codeforces Round 732 (Div. 2)")

We can find that for each letter of the answer must appear an odd number of times in its column(Since for other strings, they appear twice in total. The operation does not change the number of the occurrence of some certain letter in one column).

So we can consider each position individually. There is always exactly one letter that occurs an odd number of times. So just take them out and they are the letters of the stolen string.

 **solution**
```cpp
#include <cstdio>
const int Maxn=1000000;
char s[Maxn+5];
char ans[Maxn+5];
int n,m;
void solve(){
    scanf("%d%d",&n,&m);
    n=(n<<1)-1;
    for(int i=1;i<=m;i++){
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            ans[j]^=s[j];
        }
    }
    for(int i=1;i<=m;i++){
        putchar(ans[i]);
    }
    putchar('n');
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
	return 0;
}
```
Idea: [AquaMoon](https://codeforces.com/profile/AquaMoon "International Master AquaMoon") 

### [1546C - AquaMoon and Strange Sort](https://codeforces.com/contest/1546/problem/C "Codeforces Round 732 (Div. 2)")

It's easy to see that each number needs to move an even distance.

For the same number, count how many of them are in the odd position and even position. 

Sort the array and count again.

The given array named A, the sorted array named B.

For every number, if the number of its occurrence in the odd position in A is different from its occurrence in the odd position in B, or the number of its occurrence in the even position in A is different from its occurrence in the even position in B, then the answer is NO. Otherwise the answer is YES.

 **solution**
```cpp
#include <bits/stdc++.h>
std::vector<int> a;
int cnt[100001][2];
int main() {
  int n, T, flag;
  scanf("%d", &T);
  while(T--){
	scanf("%d", &n), a.resize(n), flag = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]), ++cnt[a[i]][i % 2];
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
      --cnt[a[i]][i % 2];
    for (int i = 0; i < n; ++i)
      if (cnt[a[i]][0] != 0 || cnt[a[i]][1] != 0) {
        puts("NO"), flag = 1;
		break;
      }
    if (flag == 0) puts("YES");
	a.clear();
	for (int i = 0; i < n; ++i)
      cnt[a[i]][0] = cnt[a[i]][1] = 0;
  }
  return 0;
}
```
Idea: [Cirno_9baka](https://codeforces.com/profile/Cirno_9baka "International Grandmaster Cirno_9baka") 

### [1546D - AquaMoon and Chess](https://codeforces.com/contest/1546/problem/D "Codeforces Round 732 (Div. 2)")

We enumerate $i$ from $1$ to $n$. If position $i-1$ and $i$ both contain a chess and $i-1$ is not in other groups, then we divide them into one group.

We can change the operation a little: Each time we can swap the two consecutive $1$ and the element to their left or right. It's easy to see this operation equals to the initial one. 

So that means we can take out the groups (two consecutive $1$) and insert them to any position of the chessboard. So let the number of groups be $m$, the number of zeros be $n$, it's easy to find that the answer is $\binom{n+m}{m}$(Since inserting one group to the left of some $1$ or to the right of it are the same).

 **solution**
```cpp
#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100010;
const int MOD = 998244353;
char str[MAXN];
long long F[MAXN], rF[MAXN];
long long inv(long long a, long long m) {
	if (a == 1) return 1;
	return inv(m%a, m) * (m - m/a) % m;
}
int main() {
	int T;
	int n;
	F[0] = rF[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		F[i] = F[i-1] * i % MOD;
		rF[i] = rF[i-1] * inv(i, MOD) % MOD;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		int cg = 0;
		int c0 = 0;
		int c1 = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == '0') {
				c0++;
			} else if (i+1 < n && str[i+1] == '1') {
				cg++;
				i++;
			} else {
				c1++;
			}
		}
		long long ans = F[cg + c0] * rF[c0] % MOD * rF[cg] % MOD;
		printf("%dn", (int) ans);
	}
	return 0;
}
```
Idea: [Cirno_9baka](https://codeforces.com/profile/Cirno_9baka "International Grandmaster Cirno_9baka") 

### [1546E - AquaMoon and Permutations](https://codeforces.com/contest/1546/problem/E "Codeforces Round 732 (Div. 2)")

Among all the arrays not be chosen, if an array have a number which appears exactly once at its column, that the array must belong to the $n$ original arrays. So, we can choose the array and delete all arrays have at least one same bit with it.

If there not exists such an array discribed above, according to the Pigeonhole Principle, all numbers of the unchosen arrays must appear exactly twice on their columns. It means either the original arrays or the additional arrays can form a correct latin square. So, it's correct to choose any one of the unchosen array and delete all arrays have at least one same bit with it. Meanwhile, we need to multiply the number of solutions by 2.

We need to repeat the above operations, until we have chosen $n$ arrays.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
const long long mod=998244353;
typedef pair<int,int> pii;
int n,x,y,s,t;
int a[maxn*2+5][maxn+5],b[maxn+5][maxn+5],f[maxn+5];
vector <pii> v;
vector <int> c[maxn+5][maxn+5];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                b[i][j]=0;
                c[i][j].clear();
            }
        }
        for (int i=1;i<=n*2;i++)
        {
            f[i]=0;
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                b[j][a[i][j]]++;
                c[j][a[i][j]].push_back(i);
            }
        }
        int top=0,tail=0;
        int cnt=0,idx=1;
        long long ans=1;
        v.clear();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (b[i][j]==1)
                {
                    tail++;
                    v.push_back(pii(i,j));
                }
            }
        }
        while (cnt<n)
        {
            if (top<tail)
            {
                x=v[top].first;
                y=v[top].second;
                if (b[x][y]!=1)
                {
                    top++;
                    continue;
                }
                for (int i=0;i<c[x][y].size();i++)
                {
                    if (f[c[x][y][i]]==0)
                    {
                        t=c[x][y][i];
                        break;
                    }
                }
            }
            else
            {
                while (f[idx]!=0)
                {
                    idx++;
                }
                t=idx;
                ans=ans*2%mod;
            }
            f[t]=1;
            cnt++;
            for (int i=1;i<=n;i++)
            {
                b[i][a[t][i]]=0;
            }
            for (int i=1;i<=n;i++)
            {
                for (int j=0;j<c[i][a[t][i]].size();j++)
                {
                    s=c[i][a[t][i]][j];
                    if (f[s]==0)
                    {
                        f[s]=2;
                        for (int k=1;k<=n;k++)
                        {
                            b[k][a[s][k]]--;
                            if (b[k][a[s][k]]==1)
                            {
                                tail++;
                                v.push_back(pii(k,a[s][k]));
                            }
                        }
                    }
                }
            }
            top++;
        }
        s=0;
        printf("%lldn",ans);
        for (int i=1;i<=n*2;i++)
        {
            if (f[i]==1)
            {
                s++;
                if (s<n) printf("%d ",i); else printf("%dn",i);
            }
        }
    }
}
```
Idea: [AquaMoon](https://codeforces.com/profile/AquaMoon "International Master AquaMoon") 

### [1546F - AquaMoon and Wrong Coordinate](https://codeforces.com/contest/1546/problem/F "Codeforces Round 732 (Div. 2)")

Let's denote for $sum[t]$ the sum of all coordinates at the moment $t$, and for $sum2[t]$ the sum of all squared coordinates at the moment $t$.

If there is no error, the sum of the coordinates of all moments will be an arithmetic series, and the difference is $\sum_{i=1}^m v_i$. It's easy to find the moment that contains the modified coordinate. 

Assuming that the moment that contains the modified coordinate is found, first use three consecutive moments without the modified coordinate. Suppose it is $t$, $t + 1$, $t + 2$. Sum of squared coordinates of moment $t$ is $sum2[t] = \sum_{i=1}^m (x_i + t * v_i)^2$. Sum of squared coordinates of moment $t+1$ is $sum2[t+1] = \sum_{i=1}^m (x_i + (t+1) * v_i)^2$. Sum of squared coordinates of moment $t+2$ is $sum2[t+2] = \sum_{i=1}^n (x_i + (t+2) * v_i)^2$. We could easy to get $sum2[t] + sum2[t+2] - 2 \times sum2[t+1] = 2 \times \sum_{i=1}^m v_i^2$. In this way, we can know the value of $2 \times \sum_{i=1}^m v_i^2$.

Then we can enumerate which integer was modified at the moment $y$. We could try to update the integer back to the original coordinate, so that it can meet both $sum[y-1] + sum[y+1] = 2 \times sum[y]$ and $sum2[y-1] + sum2[y+1] - 2 \times sum2[y] = 2 \times \sum_{i=1}^m v_i^2 $. It would be easy to get the original coordinate.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,ans1,ans2;
long long a[1010][1010];
long long c[1010],x,y,s,t,temp;
 
int main()
{
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%lld",&a[i][j]);
            c[i]+=a[i][j];
        }
    }
    x=(c[m-1]-c[0])/(m-1);
    for (i=1;i<m;i++)
    {
        if ((c[i]-c[0])!=x*i)
        {
            ans1=i;
            y=c[i]-c[0]-x*i;
            break;
        }
    }
    for (i=1;i<m-1;i++)
    {
        if (i-1!=ans1&&i!=ans1&&i+1!=ans1)
        {
            x=0;
            for (j=1;j<=n;j++)
            {
                x+=a[i-1][j]*a[i-1][j]+a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j]*2;
            }
            break;
        }
    }
    i=ans1;
    t=s=0;
    for (j=1;j<=n;j++)
    {
        s+=a[i-1][j]*a[i-1][j]+a[i+1][j]*a[i+1][j];
        t+=a[i][j]*a[i][j]*2;
    }
    s-=x;
    for (j=1;j<=n;j++)
    {
        temp=t-a[i][j]*a[i][j]*2+(a[i][j]-y)*(a[i][j]-y)*2;
        if (temp==s)
        {
            ans2=a[i][j]-y;
            break;
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
}
```
Idea: [AquaMoon](https://codeforces.com/profile/AquaMoon "International Master AquaMoon") 

### [1545E2 - AquaMoon and Time Stop (hard version)](https://codeforces.com/contest/1545/problem/E2 "Codeforces Round 732 (Div. 1)")

We scan through the time, each time. We need to get minimum answer for all positions of this certain time.

We can use some data structure to maintain it.

In detail, we use balance tree to maintain every segments which are not covered for some time t.

We can see that after some time, the answer of every position of the segment is shifted. A new arithmetic sequence is added to the left, and the rightmost part is erased. We use lazy tags to maintain them(We update the segment only when we need to use the answer of it).

When a segment is banned, then we just erase it.

When a segment is added, we need to consider the answer of at most two neighboring segment. 

There are two conditions:

1. We use two of the neighboring segment to get the answer of the new-added segment. We need to merge the two segments and insert two arithmetic sequences between them.

2. We use only one of the neighboring segment to get the answer of the new-added segment, and this one will even influence the other. We just use brute force to erase some arithmetic sequences of the influenced segment at the end.

For each segment, we use a balance tree to maintain the arithmetic sequences in it.

Since each time we will only add segments of a constant number, so the time complexity is O(nlogn).

(The easy version is for solution without too many data structures)

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=2000005,E=1000001;
struct str{
	int l;
	long long x;
	int d;
	long long las(){return x+(l-1)*d;}
}a[N];
int ch[N][2],fa[N],h[N],tot,hc,ls[N],siz[N],i;
struct seg{
	int l,r,x;
	bool operator <(const seg &a)const
	{
		return a.r>r;
	}
};
set<seg> p;
void pushup(int i)
{
	siz[i]=siz[ch[i][0]]+siz[ch[i][1]]+a[i].l;
}
void rotate(int x)
{
    int y=fa[x];bool d=(ch[y][0]==x);
    ch[y][!d]=ch[x][d];
    if(ch[x][d]!=0)fa[ch[x][d]]=y;
    fa[x]=fa[y];if(fa[y])ch[fa[y]][ch[fa[y]][1]==y]=x;
    ch[x][d]=y;fa[y]=x;pushup(y);
}
void splay(int i,int x,int t=0)
{
	for(int y=fa[x];y!=t;rotate(x),y=fa[x])
		if(fa[y]!=t&&(ch[fa[y]][0]==y)==(ch[y][0]==x))
			rotate(y);
	pushup(x);
	h[i]=x;
}
void Findmx(int x)
{
	int i=h[x];
	while(ch[i][1])
		i=ch[i][1];
	splay(x,i);
}
void Findmn(int x)
{
	int i=h[x];
	while(ch[i][0])
		i=ch[i][0];
	splay(x,i);
}
void MMerge(int x,int y)
{
	if(h[y]==0||h[x]==0)
	{
		h[x]=h[y]=max(h[x],h[y]);
		return;
	}
	int i=h[y];
	for(;ch[i][0];i=ch[i][0]);
	ch[i][0]=h[x];
	fa[h[x]]=i;
	splay(y,h[x]);
}
int Merge(int x,int y)
{
	Findmx(x),Findmn(y);
	if(abs(a[h[x]].las()-a[h[y]].x)<=1)
	{
		MMerge(x,y);
		return x;
	}
	if(a[h[x]].las()>a[h[y]].x)
	{
		long long la=a[h[y]].x;
		while(h[x]&&abs(a[h[x]].las()-la)>1)
		{
			if(a[h[x]].d==-1)
				la+=a[h[x]].l;
			else
			{
				if(la+a[h[x]].l<a[h[x]].x)
					la+=a[h[x]].l;
				else
				{
					int li=(a[h[x]].l-a[h[x]].x+la+2)/2;
					la+=a[h[x]].l-li;
					a[h[x]].l=li;
					break;
				}
			}
			h[x]=ch[h[x]][0];
			fa[h[x]]=0;
			Findmx(x);
		}
		h[++hc]=++tot;
		a[tot]={(int)(la-a[h[y]].x),la,-1};
		pushup(tot);
		ls[hc]=ls[x];
		MMerge(x,hc);
		MMerge(hc,y);
	}
	else
	{
		long long la=a[h[x]].las();
		while(h[y]&&abs(a[h[y]].x-la)>1)
		{
			if(a[h[y]].d==1)
				la+=a[h[y]].l;
			else
			{
				if(a[h[y]].las()>la+a[h[y]].l)
					la+=a[h[y]].l;
				else
				{
					int li=(a[h[y]].x-la)/2;
					a[h[y]].x-=li;
					a[h[y]].l-=li;
					la+=li;
					break;
				}
			}
			h[y]=ch[h[y]][1];
			fa[h[y]]=0;
			Findmn(y);
		}
		h[++hc]=++tot;
		a[tot]={(int)(la-a[h[x]].las()),a[h[x]].las()+1,1};
		pushup(tot);
		ls[hc]=ls[x];
		MMerge(x,hc);
		MMerge(hc,y);
	}
	return hc;
}
void Find(int n,int x,int w)
{
	if(w<siz[ch[x][0]])
		Find(n,ch[x][0],w);
	else
		if(siz[ch[x][0]]+a[x].l>w)
		{
			if(siz[ch[x][0]]==w)
			{
				splay(n,x,0);
				return;
			}
			int tmp=ch[x][1];
			ch[x][1]=++tot;
			ch[tot][1]=tmp;
			if(tmp)
				fa[tmp]=tot;
			fa[tot]=x;
			a[tot].l=a[x].l-(w-siz[ch[x][0]]);
			a[x].l=w-siz[ch[x][0]];
			a[tot].x=a[x].x+a[x].d*a[x].l;
			a[tot].d=a[x].d;
			splay(n,tot,0);
			return;
		}
		else
			Find(n,ch[x][1],w-a[x].l-siz[ch[x][0]]);
}
void Update(int l,int x)
{
	if(l==ls[x])
		return;
	int ti=l-ls[x];
	ls[x]=l;
	Findmn(x);
	long long w=a[h[x]].x;
	h[++hc]=++tot;
	a[tot]={ti,w+ti,-1};
	pushup(tot);
	MMerge(hc,x);
	while(1)
	{
		Findmx(x);
		if(ti<a[h[x]].l)
		{
			a[h[x]].l-=ti;
			break;
		}
		ti-=a[h[x]].l;
		h[x]=ch[h[x]][0];
		fa[h[x]]=0;
	}
}
void Add(int ti,int l,int r)
{
	h[++hc]=++tot;
	a[tot]={r-l+1,1<<30,1};
	pushup(tot);
	seg t={l,r,hc};
	ls[hc]=ti;
	auto it=p.lower_bound(t);
	if(it!=p.end()&&it->l==r+1)
	{
		Update(ti,it->x);
		t.x=Merge(t.x,it->x);
		t.r=it->r;
		p.erase(it);
	}
	it=p.lower_bound(t);
	if(it!=p.begin())
	{
		--it;
		if(it->r==l-1)
		{
			Update(ti,it->x);
			t.x=Merge(it->x,t.x);
			t.l=it->l;
			p.erase(it);
		}
	}
	p.insert(t);
}
void Del(int ti,int l,int r)
{
	seg t=*p.lower_bound({l,r,0});
	p.erase(t);
	Update(ti,t.x);
	Find(t.x,h[t.x],l-t.l);
	int u=ch[h[t.x]][0];
	fa[u]=ch[h[t.x]][0]=0;
	pushup(h[t.x]);
	int v=0;
	if(siz[h[t.x]]!=r-l+1)
	{
		Find(t.x,h[t.x],r-l+1);
		v=ch[h[t.x]][0];
		fa[v]=ch[h[t.x]][0]=0;
		v=h[t.x];
	}
	if(l!=t.l)
	{
		h[++hc]=u;
		ls[hc]=ti;
		p.insert({t.l,l-1,hc});
	}
	if(r!=t.r)
	{
		h[++hc]=v;
		ls[hc]=ti;
		p.insert({r+1,t.r,hc});
	}
}
int n,l,r,x,y,u,v,tree[N*4],lazy[N*4];
long long as=1<<30;
struct node{
	int l,r;
};
vector<node> ad[E+5],de[E+5];
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]+=x;
		tree[i]+=x;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	tree[i]=max(tree[i<<1],tree[i<<1|1])+lazy[i];
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,s=0;
	if(mid>=ll)
		s=max(s,Query(i<<1,l,mid,ll,rr));
	if(mid<rr)
		s=max(s,Query(i<<1|1,mid+1,r,ll,rr));
	return s+lazy[i];
}
int Findmx(int i,int l,int r,int ll,int s)
{
	if(s+tree[i]==0)
		return -1;
	if(l==r)
		return l-1;
	int mid=l+r>>1;
	s+=lazy[i];
	if(l>=ll)
	{
		int y=Findmx(i<<1,l,mid,ll,s);
		if(y!=-1)
			return y;
		else
			return Findmx(i<<1|1,mid+1,r,ll,s);
	}
	if(mid>=ll)
	{
		int y=Findmx(i<<1,l,mid,ll,s);
		if(y!=-1)
			return y;
	}
	return Findmx(i<<1|1,mid+1,r,ll,s);
}
int Findmn(int i,int l,int r,int rr,int s)
{
	if(s+tree[i]==0)
		return -1;
	if(l==r)
		return l+1;
	int mid=l+r>>1;
	s+=lazy[i];
	if(r<=rr)
	{
		int y=Findmn(i<<1|1,mid+1,r,rr,s);
		if(y!=-1)
			return y;
		else
			return Findmn(i<<1,l,mid,rr,s);
	}
	if(mid<rr)
	{
		int y=Findmn(i<<1|1,mid+1,r,rr,s);
		if(y!=-1)
			return y;
	}
	return Findmn(i<<1,l,mid,rr,s);
}
void dfs(int i)
{
	if(!i)
		return;
	as=min({as,a[i].x,a[i].las()});
	dfs(ch[i][0]);
	dfs(ch[i][1]);
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&x);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d %d",&l,&r,&u,&v);
		--l,++r;
		de[l].push_back({u,v});
		ad[r].push_back({u,v});
	}
	p.insert({0,E*2+5,++hc});
	h[hc]=++tot;
	a[tot]={E*2+5-x+1,0,1};
	ch[tot][0]=2;
	fa[++tot]=1;
	a[tot]={x,x,-1};
	pushup(2);
	pushup(1);
	for(i=0;i<=E+1;++i)
	{
		for(auto it:ad[i])
		{
			modify(1,0,E,it.l,it.r,-1);
			auto ii=p.lower_bound({it.l,it.r,0});
			int nr=ii->l-1;
			--ii;
			int nl=ii->r+1;
			if(nl>nr)
				continue;
			int y=Findmx(1,0,E,nl,0);
			if(y>=nr||y==-1)
				Add(i,nl,nr);
			else
			{
				if(y>=nl)
					Add(i,nl,y);
				int y=Findmn(1,0,E,nr,0);
				if(y<=nr)
					Add(i,y,nr);
			}
		}
		for(auto it:de[i])
		{
			modify(1,0,E,it.l,it.r,1);
			while(1)
			{
				auto y=p.lower_bound({0,it.l,0});
				if(y!=p.end())
				{
					if(min(it.r,y->r)>=max(it.l,y->l))
						Del(i,max(it.l,y->l),min(it.r,y->r));
					else
						break;
				}
				else
					break;
			}
		}
	}
	dfs(h[p.begin()->x]);
	cout<<as;
}
```
Idea: [AquaMoon](https://codeforces.com/profile/AquaMoon "International Master AquaMoon") and [mejiamejia](https://codeforces.com/profile/mejiamejia "Expert mejiamejia") 

Tutorial is loading... **solution**
```cpp
// (insert magical incantation)
// (insert offerings for the Gods of codeforces judging servers)
//LXLORZ!!!!//rejudg
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define SQRTN 210

namespace io {
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1,
                                           __c, qu[55];
int __f, qr, _eof;
#define Gc()                                                                   
  (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),               
               (iS == iT ? EOF : *iS++))                                       
            : *iS++)
inline void flush() { fwrite(obuf, 1, oS - obuf, stdout), oS = obuf; }
inline void gc(char &x) { x = Gc(); }
inline void pc(char x) {
  *oS++ = x;
  if (oS == oT)
    flush();
}
inline void pstr(const char *s) {
  int __len = strlen(s);
  for (__f = 0; __f < __len; ++__f)
    pc(s[__f]);
}
inline void gstr(char *s) {
  for (__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)
    __c = Gc();
  for (; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc())
    *s = __c;
  *s = 0;
}
template <class I> inline bool gi(I &x) {
  _eof = 0;
  for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) {
    if (__c == '-')
      __f = -1;
    _eof |= __c == EOF;
  }
  for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc())
    x = x * 10 + (__c & 15), _eof |= __c == EOF;
  x *= __f;
  return !_eof;
}
template <class I> inline void print(I x) {
  if (!x)
    pc('0');
  if (x < 0)
    pc('-'), x = -x;
  while (x)
    qu[++qr] = x % 10 + '0', x /= 10;
  while (qr)
    pc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
} // namespace io
using io::gc;
using io::gi;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;

int n;
int a[MAXN], X[MAXN], Y[MAXN];

int Xa[MAXN], Ya[MAXN];

int dyn[SQRTN + 5];
bool dynp[MAXN];

int ps1[MAXN];
ll ps2[MAXN];

ll ps_7j[MAXN];

int fake_a[MAXN], fake_Xa[MAXN], fake_Ya[MAXN];

// TODO: replace with linked list

struct offl {
  int val, id, nxt;
} detecpool[(SQRTN * SQRTN * 11) / 2 + 5];

int detec[MAXN];
// int detec7[MAXN];
int detec8f[MAXN];
int detecX[MAXN], detecY[MAXN];

int dryans[(SQRTN * SQRTN * 3) / 2 + 5];
int dryansX[(SQRTN * SQRTN) / 2 + 5];
int dryansY[(SQRTN * SQRTN * 4) / 2 + 5];
ll dryans_7[(SQRTN * SQRTN) / 2 + 5];
ll dryans_8_former[(SQRTN * SQRTN * 2) / 2 + 5];
ll ijk_static[MAXN];

void dryrun(vector<pii> ops) {
  copy(a, a + n, fake_a);
  copy(Xa, Xa + n, fake_Xa);
  copy(Ya, Ya + n, fake_Ya);
  memset(detec, -1, sizeof detec);
  memset(detecX, -1, sizeof detecX);
  memset(detecY, -1, sizeof detecY);
  // memset(detec7, -1, sizeof detec7);
  memset(detec8f, -1, sizeof detec8f);
  int pooln = 0;
  auto push_back = [&](int *ve, int pos, int va, int id) {
    detecpool[pooln] = {va, id, ve[pos]};
    ve[pos] = pooln;
    pooln++;
  };
  int dryid = 0, dryidX = 0, dryidY = 0, dryid7 = 0, dryid8f = 0;
  for (auto [opn, r] : ops) {
    if (opn != -1) {
      assert(dynp[opn]);
      a[opn] = r;
      Xa[opn] = X[r];
      Ya[opn] = Y[r];
    } else {
      int mxdyn = 0;
      for (int i = 0; dyn[i] <= r; i++)
        mxdyn++;
      for (int _j = 0; _j < mxdyn; _j++) {
        int j = dyn[_j];
        int pfx_xai_km1 = 0;
        if (j != 0) {
          // int pfx_ixaj_jm1 = dryans[dryid++];
          // int pfx_iyaj_r = dryans[dryid++];
          // int pfx_iyaj_j = dryans[dryid++];
          push_back(detecX, j - 1, a[j], dryidX++);
          push_back(detecY, r, a[j], dryidY++);
          push_back(detecY, j, a[j], dryidY++);

          int k = dyn[_j];
          // pfx_xai_km1 = dryans[dryid++];
          // int pfx_yak_km1 = dryans[dryid++];
          push_back(detec, k - 1, Xa[k], dryid++);
          push_back(detec, k - 1, Ya[k], dryid++);

          // ll pfx_yak_km1 = dryans_7[dryid7++];
          // push_back(detec7, k - 1, Ya[k], dryid7++);
        }
        int i = j;
        if (i != r) {
          // ll sfx_xai_ip1 = dryans_8_former[dryid8f++];
          // ll sfx_xai_rp1 = dryans_8_former[dryid8f++];
          // int pfx_xai_r = dryans[dryid++];
          // int pfx_xai_i = pfx_xai_km1;
          // int pfx_iyxai_n = dryans[dryid++];
          // int pfx_iyxai_r = dryans[dryid++];
          push_back(detec8f, i + 1, Xa[i], dryid8f++);
          push_back(detec8f, r + 1, Xa[i], dryid8f++);
          push_back(detec, r, Xa[i], dryid++);
          push_back(detecY, n, Xa[i], dryidY++);
          push_back(detecY, r, Xa[i], dryidY++);
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (i != n && !dynp[i]) {
      ps1[a[i]]++;
    }
    for (int pid = detec[i]; pid != -1; pid = detecpool[pid].nxt)
      dryans[detecpool[pid].id] = ps1[detecpool[pid].val];
  }
  memset(ps1, 0, n * (sizeof(int)));
  ll cpsm = 0;
  for (int i = 0; i <= n; i++) {
    if (i != n && !dynp[i]) {
      cpsm += ps_7j[Ya[i]];
      ps_7j[a[i]] += ps1[a[i]];
      ps1[Xa[i]]++;
    }
    ijk_static[i] = cpsm;
    for (int pid = detecX[i]; pid != -1; pid = detecpool[pid].nxt) {
      dryansX[detecpool[pid].id] = ps1[detecpool[pid].val];
      dryans_7[detecpool[pid].id] = ps_7j[Y[detecpool[pid].val]];
    }
  }
  memset(ps1, 0, n * (sizeof(int)));
  for (int i = 0; i <= n; i++) {
    if (i != n && !dynp[i]) {
      ps1[Ya[i]]++;
    }
    for (int pid = detecY[i]; pid != -1; pid = detecpool[pid].nxt)
      dryansY[detecpool[pid].id] = ps1[detecpool[pid].val];
  }
  memset(ps1, 0, n * (sizeof(int)));
  memset(ps_7j, 0, n * (sizeof(ll)));

  for (int i = n; i >= 0; i--) {
    if (i != n && !dynp[i]) {
      ps2[a[i]] += ps1[a[i]];
      ps1[Ya[i]]++;
    }
    for (int pid = detec8f[i]; pid != -1; pid = detecpool[pid].nxt)
      dryans_8_former[detecpool[pid].id] = ps2[detecpool[pid].val];
  }
  memset(ps1, 0, n * (sizeof(int)));
  memset(ps2, 0, n * (sizeof(ll)));
  copy(fake_a, fake_a + n, a);
  copy(fake_Xa, fake_Xa + n, Xa);
  copy(fake_Ya, fake_Ya + n, Ya);
}

int PfxGud3[MAXN], SfxGud4[MAXN];

void process(vector<pii> ops) {
  set<int> mdfd;
  for (auto [xx, b] : ops)
    if (xx != -1)
      mdfd.insert(xx);
  int dync = 0;
  memset(dyn, 1, sizeof dyn);
  for (int i : mdfd)
    dyn[dync++] = i;
  memset(dynp, 0, sizeof dynp);
  for (int i = 0; i < dync; i++)
    dynp[dyn[i]] = 1;
  dryrun(ops);
  int dryid = 0, dryidX = 0, dryidY = 0, dryid6l = 0, dryid7 = 0, dryid8f = 0;
  for (auto [opn, r] : ops) {
    if (opn != -1) {
      a[opn] = r;
      Xa[opn] = X[r];
      Ya[opn] = Y[r];
    } else {
      int mxdyn = 0;
      for (int i = 0; dyn[i] <= r; i++)
        mxdyn++;
      ll P1 = ijk_static[r], P2 = 0, P3 = 0, P4 = 0, P5 = 0, P6 = 0, P7 = 0,
         P8 = 0;
      for (int _i = 0; _i < mxdyn; _i++) {
        int i = dyn[_i];
        PfxGud3[i] = ps1[a[i]];
        P2 += ps2[Ya[i]];
        ps2[a[i]] += ps1[a[i]];
        ps1[Xa[i]]++;
      }
      for (int _i = 0; _i < mxdyn; _i++) {
        int i = dyn[_i];
        ps2[a[i]] = 0;
        ps1[Xa[i]] = 0;
      }
      for (int _i = mxdyn - 1; _i >= 0; _i--) {
        int i = dyn[_i];
        SfxGud4[i] = ps1[a[i]];
        ps1[Ya[i]]++;
      }
      for (int _i = 0; _i < mxdyn; _i++) {
        int i = dyn[_i];
        ps1[Ya[i]] = 0;
      }
      for (int _j = 0; _j < mxdyn; _j++) {
        int j = dyn[_j];
        int pfx_xai_km1 = 0;
        if (j != 0) {
          int pfx_ixaj_jm1 = dryansX[dryidX++];
          int pfx_iyaj_r = dryansY[dryidY++];
          int pfx_iyaj_j = dryansY[dryidY++];
          P3 += PfxGud3[j] * (pfx_iyaj_r - pfx_iyaj_j);
          P4 += pfx_ixaj_jm1 * SfxGud4[j];
          P5 += 1ll * pfx_ixaj_jm1 * (pfx_iyaj_r - pfx_iyaj_j);

          int k = dyn[_j];
          pfx_xai_km1 = dryans[dryid++];
          int pfx_yak_km1 = dryans[dryid++];
          int pfxDyn_ixyak = ps1[Ya[k]];
          ll pfxDyn_BAD_ixyak = ps2[Ya[k]];
          ps1[Xa[k]]++;
          ps2[Xa[k]] += pfx_xai_km1;
          P6 += 1ll * pfx_yak_km1 * pfxDyn_ixyak - pfxDyn_BAD_ixyak;

          P7 += dryans_7[dryid7++];
        } else {
          ps1[Xa[j]]++;
        }
        int i = j;
        if (i != r) {
          ll sfx_xai_ip1 = dryans_8_former[dryid8f++];
          ll sfx_xai_rp1 = dryans_8_former[dryid8f++];
          int pfx_xai_r = dryans[dryid++];
          int pfx_xai_i = pfx_xai_km1;
          int pfx_iyxai_n = dryansY[dryidY++];
          int pfx_iyxai_r = dryansY[dryidY++];
          P8 += (sfx_xai_ip1 - sfx_xai_rp1) -
                1ll * (pfx_xai_r - pfx_xai_i) * (pfx_iyxai_n - pfx_iyxai_r);
        }
      }
      for (int _i = 0; _i < mxdyn; _i++) {
        int i = dyn[_i];
        ps2[Xa[i]] = 0;
        ps1[Xa[i]] = 0;
      }
      print(P1 + P2 + P3 + P4 + P5 + P6 + P7 + P8);
      pc('n');
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  gi(n), gi(m);
  for (int i = 0; i < n; i++) {
    gi(a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    gi(X[i]);
    X[i]--;
  }
  for (int i = 0; i < n; i++) {
    gi(Y[i]);
    Y[i]--;
  }
  for (int i = 0; i < n; i++) {
    Xa[i] = X[a[i]];
    Ya[i] = Y[a[i]];
  }
  vector<pii> opq;
  for (int qx = 0; qx < m; qx++) {
    int op, v;
    gi(op);
    gi(v);
    if (op == 1) {
      int r;
      gi(r);
      opq.push_back({v - 1, r - 1});
    } else {
      opq.push_back({-1, v - 1});
    }
    if (opq.size() == SQRTN) {
      process(opq);
      opq.clear();
    }
  }
  process(opq);
}
```
Idea: [ODT](https://codeforces.com/profile/ODT "Master ODT") and [box](https://codeforces.com/profile/box "International Master box")

**UPD:** Chinese editorial can be found [here](https://codeforces.com/https://www.cnblogs.com/invisible-eyes/p/15003033.html).

