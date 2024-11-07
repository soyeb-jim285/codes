# Tutorial_(en)

A. LuoTianyi and the Palindrome String
--------------------------------------

Consider the substring of ss from the second character to the last, or s2s3⋯sns2s3⋯sn. If it's not palindrome, then the answer must be n−1n−1. What if it's palindrome? This implies that s2=sns2=sn, s3=sn−1s3=sn−1, and so on. Meanwhile, the fact that ss is palindrome implies s1=sns1=sn, s2=sn−1s2=sn−1, etc. So we get s1=sn=s2=sn−1=⋯s1=sn=s2=sn−1=⋯ or that all characters in ss is the same. In this situation, every subsequence of ss is palindrome of course, so the answer should be −1−1.

 **Code**
```cpp
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#define ll int
#define ft first
#define sd second
//#define endl 'n'
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define no cout<<"NO"<<'n'
#define no_ cout<<"No"<<'n'
#define _no cout<<"no"<<'n'
#define lowbit(a) ((a)&-(a))
#define yes cout<<"YES"<<'n'
#define yes_ cout<<"Yes"<<'n'
#define _yes cout<<"yes"<<'n'
#define ull unsigned long long
#define all(x) x.begin(),x.end()
#define nps fixed<<setprecision(10)<<
#define mem(a,k) memset(a,k,sizeof(a))
#define debug(x) cout<<#x<<"="<<x<<endl
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
const ll mod1=1e9+7;
const ll mod2=998244353;
const ll base=1610612741;
const ll INF=0x3f3f3f3f3f;
const ll inf=9223372036854775807;
const ll Z=mod2;
const ll mod=Z;
using namespace std;
int ddir[2][2]={{0,1},{1,0}};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dir3[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
struct custom_hash
{
    static ull splitmix64(ull x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(ull x)const{static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}
    //unordered_map<ll,ll,custom_hash>mp;
};
struct mint
{
    ll x;
    mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}
    mint(const mint &ope) {x = ope.x;}
    mint operator-(){return mint(-x);}
    mint operator+(const mint &ope){return mint(x) += ope;}
    mint operator-(const mint &ope){return mint(x) -= ope;}
    mint operator*(const mint &ope){return mint(x) *= ope;}
    mint operator/(const mint &ope){return mint(x) /= ope;}
    mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}
    mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}
    mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}
    mint& operator/=(const mint &ope){ll n = mod-2; mint mul = ope;while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}return *this;}
    mint inverse(){return mint(1) / *this;}
    bool operator ==(const mint &ope){return x == ope.x;}
    bool operator !=(const mint &ope){return x != ope.x;}
    bool operator <(const mint &ope)const{return x < ope.x;}
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a,ll b){return __gcd(a,b);}
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
ll rnd(ll l,ll r){ll ans=uniform_int_distribution<ll>(l,r)(rng);return ans;}
ll qpow(ll a,ll b){ll res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}
ll qpow(ll a,ll b,ll m){a%=m;ll res=1;while(b>0){if(b&1)res=res*a%m;a=a*a%m;b>>=1;}return res;}
double psqrt(double x,double y,double xx,double yy){double res=((x-xx)*(x-xx)+(y-yy)*(y-yy));return res;}
double ssqrt(double x,double y,double xx,double yy){double res=sqrt(psqrt(x,y,xx,yy));return res;}
ll INV(ll x){return qpow(x,Z-2,Z);}
void cominit(ll fac[],ll inv[]){fac[0]=1;rep(i,1,1000000)fac[i]=fac[i-1]*i%Z;
inv[1000000]=INV(fac[1000000]);per(i,1000000-1,0)inv[i]=inv[i+1]*(i+1)%Z;}
ll t,n,m,k,tt,tp,res,sum,ans,cnt;
const ll N=1e6+5;
ll a[N],b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    //IO
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        auto check=[&]()
        {
            for(int i=0;i<s.size()/2;++i)if(s[i]!=s[s.size()-i-1])return 0;
            return 1;
        };
        if(!check())ans=s.size();
        else if(s.size()>1)
        {
            s.pop_back();
            if(!check())ans=s.size();
            else ans=-1;
        }
        else ans=-1;
        cout<<ans<<"n";
    }
}
```
B. LuoTianyi and the Grid
-------------------------

Assume that n>mn>m. Greedily thinking, we want the maximum possible aa to appear as the maximum value of as many subtables as possible, meanwhile, we also want the minimum possible aa to appear as the minimum value of as many subtables as possible. This gives us two choices: making the upper-left square the minimum or the maximum. It's symmetrical so we'll only consider the minimum situation.

Now all the subtables have the same minimum value, we want to maximize the number of subtables where the maximum aa appears as the maximum value. Placing it at (1,2)(1,2) and (2,1)(2,1) makes the number n(m−1),m(n−1)n(m−1),m(n−1) each, because n>mn>m, we have m(n−1)>n(m−1)m(n−1)>n(m−1), so we place the largest aa at (2,1)(2,1) and the second largest at (1,2)(1,2), the answer for this case is m(n−1)×max+m×second max−mn×minm(n−1)×max+m×second max−mn×min.

 **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=2e5+5;
ll a[mxn];
inline void solve(){
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	sort(a+1,a+n*m+1);
	if(n>m)swap(n,m);
	if(n==1)cout<<(m-1)*(a[n*m]-a[1])<<'n';
	else{
		ll ans1=(n*m-1)*(a[n*m])-a[1]*(n*(m-1))-a[2]*(n-1);
		ll ans2=a[n*m]*(n*(m-1))+a[n*m-1]*(n-1)-a[1]*(n*m-1);
		cout<<max(ans1,ans2)<<'n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	for(;T--;)solve();
	return 0;
}
```
C. LuoTianyi and the Show
-------------------------

First we can notice that, if someone with a specific favourite seat(i.e. not −1−1 nor −2−2) has got his seat taken by a −1−1 guy or a −2−2 guy, it's better to let the first man go first, and the −1−1 or −2−2 one go after him.

Now, we know it's better to make those with a favourite seat go in first. After they have seated, now we consider filling the space between them with −1−1 and −2−2. It's easy to notice that we can find two non-overlapping prefix and suffix, and fill the blank seats in the prefix with −1−1, and the blanks in the suffix with −2−2. We now only need to find the answer greedily for each division point between the prefix and the suffix.

The time complexity is O(n)O(n).

 **Code**
```cpp
// Problem: C. LuoTianyi and the Theater
// Contest: Codeforces - test vocaloid cf round
// URL: https://codeforces.com/gym/394370/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, m, a[N], buc[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		int cntL = 0, cntR = 0;
		rep(i, 1, n) {
			if(a[i] == -1) ++cntL;
			else if(a[i] == -2) ++cntR;
			else ++buc[a[i]];
		}
		int nowL = 0, nowR = 0, vis = 0;
		rep(i, 1, m) {
			if(buc[i]) ++vis;
			else ++nowR;
		}
		int ans = max(cntL, cntR) + vis;
		rep(i, 1, m) {
			// printf("%d : %d %d; %d %d; %dn", i, cntL, nowL, cntR, nowR, vis);
			if(buc[i]) chkmax(ans, min(cntL, nowL) + min(cntR, nowR) + vis);
			else ++nowL, --nowR;
			// printf(" -> %dn", ans);
		}
		chkmin(ans, m);
		printf("%dn", ans);
		rep(i, 1, m) buc[i] = 0;
	}
	return 0;
}
```
D. LuoTianyi and the Floating Islands
-------------------------------------

Call a node special if there is a person in it. 

When kk is odd, we find that there is only one node satisfying the conditions. 

Proof. Assume distinct node x and node y are good nodes. Let x be the root of the tree. Define si as the number of special nodes in subtree i. Think about the process we move from x to y. If we try to move the chosen node from its father to i, the variation of cost is k−2si. When move from x to its son i which si is maximal, k−2si≥0 is held (Otherwise, x isn't a good node). And we can get k−2si>0 further because k is odd and 2si is even. Since min1≤j≤nk−2sj=k−2si, we find k−2sj>0 for all j. So y can't be good node.

Then think about the situation that k is even. Choose a node as root arbitrarily. With the same method, we find that good nodes satisfy 2si=k. It's also sufficient. Define pi as the possibility that si=k2, then the answer is 1+∑ni=1pi. 

Define Si as the size of subtree i. When si=k2, there are k2 special nodes in subtree i and k2 in the other part. The number of ways to place special nodes is (nk), and (Sik2)(n−Sik2) of them satisfying the condition. So pi=(Sik2)(n−Sik2)(nk).

So we can solve the problem in O(n).

 **Code**
```cpp
//Was yea ra,rra yea ra synk sphilar yor en me exec hymme METAFALICA waath!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define rg register
#define ll long long
#define ull unsigned ll
#define lowbit(x) (x&(-x))
#define djq 1000000007
const double eps=1e-10;
const short sint=0x3f3f;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const double alpha=0.73;
const double PI=acos(-1);
inline void file(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
}
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,(1<<20)+5,stdin),p1==p2)?EOF:*p1++;
}
//#define getc getchar
inline ll read(){
	rg ll ret=0,f=0;char ch=getc();
    while(!isdigit(ch)){if(ch==EOF)exit(0);if(ch=='-')f=1;ch=getc();}
    while(isdigit(ch)){ret=ret*10+ch-48;ch=getc();}
    return f?-ret:ret;
}
inline void rdstr(char* s){
	char ch=getc();
	while(ch<33||ch>126) ch=getc();
	while(ch>=33&&ch<=126) (*s++)=ch,ch=getc();
}
#define ep emplace
#define epb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define it iterator
#define mkp make_pair
#define naive return 0*puts("Yes")
#define angry return 0*puts("No")
#define fls fflush(stdout)
#define rep(i,a) for(rg int i=1;i<=a;++i)
#define per(i,a) for(rg int i=a;i;--i)
#define rep0(i,a) for(rg int i=0;i<=a;++i)
#define per0(i,a) for(rg int i=a;~i;--i)
#define szf sizeof
typedef vector<int> vec;
typedef pair<int,int> pii;
struct point{ int x,y; point(int x=0,int y=0):x(x),y(y) {} inline bool operator<(const point& T)const{ return x^T.x?x<T.x:y<T.y; }; };
inline int ksm(int base,int p){int ret=1;while(p){if(p&1)ret=1ll*ret*base%djq;base=1ll*base*base%djq,p>>=1;}return ret;}
inline void pls(int& x,const int k){ x=(x+k>=djq?x+k-djq:x+k); }
inline int add(const int a,const int b){ return a+b>=djq?a+b-djq:a+b; }
inline void sub(int& x,const int k){ x=(x-k<0?x-k+djq:x-k); }
inline int inc(const int a,const int b){ return a<b?a-b+djq:a-b; }
inline void ckmn(int& x,const int k){ x=(k<x?k:x); }
inline void ckmx(int& x,const int k){ x=(k>x?k:x); }
 
const int lim=2e5;
int fac[200005],ifac[200005];
inline int C(int n,int m){ return (m<=n&&m>=0&&n>=0)?1ll*fac[n]*ifac[m]%djq*ifac[n-m]%djq:0; }
void initC(){
	fac[0]=ifac[0]=1;
	rep(i,lim) fac[i]=1ll*fac[i-1]*i%djq;
	ifac[lim]=ksm(fac[lim],djq-2);
	per(i,lim-1) ifac[i]=1ll*ifac[i+1]*(i+1)%djq;
}
int n,k,u,v,sz[200005];
vec e[200005];
void dfs(int x,int fa){
	sz[x]=1;
	for(int y:e[x]) if(y^fa) dfs(y,x),sz[x]+=sz[y];
}
signed main(){
	//file();
	initC();
	n=read(),k=read();
	rep(i,n-1) u=read(),v=read(),e[u].epb(v),e[v].epb(u);
	dfs(1,0);
	if(k&1) return 0*puts("1");
	else{
		int ans=0;
		for(rg int i=2;i<=n;++i) pls(ans,1ll*C(sz[i],k/2)*C(n-sz[i],k/2)%djq);
		ans=1ll*ans*ksm(C(n,k),djq-2)%djq;
		pls(ans,1);
		printf("%dn",ans);
	}
	return 0;
}
```
E. LuoTianyi and XOR-Tree
--------------------------

Hint: Consider a brute force dynamic programming solution and try to optimize it.

Denote the minimum number of operations needed to make every path from a leaf inside the subtree of u to the root have the xor value of w as fu,w. Observe that for every u, there are only 2 possible different values for fu,w. This is because if fu,w1−fu,w2>1, we can use an operation of xor-ing au with w1 xor w2 to make all the xor values from w2 to w1, which takes fu,w2+1 steps instead of fu,w1.

Now we only need to calculate minnu=minfu,w, and the set Su of w that makes fu,w minimum. We have minnv=0 and Sv=the xor value from root to v for leaf v. It's trivial to calculate minnu.

Note that Su contains of the numbers appearing the most times in the sets of u's son. We can maintain Su using a map and merging it heuristically. Consider when merging sets into a new set S′. If every element of S′ appears only once in the original sets, then we keep S′ as the result, otherwise, brute force the whole set S′ and find the elements appearing the most times. For the second situation, every element's count of appearance is at least halved(those appearing once have 0 and others have 1 afterwards), so the number of brute force checking operations is O(nlogn).

The final time complexity is O(nlog2n).

 **Code**
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
int n,a[100005];
vector<int> e[100005];
set<int> s[100005],stmp;
int ans=0,sid[100005],stp=0;
bool cmp(int x,int y)
{
	return (int)s[sid[x]].size()>(int)s[sid[y]].size();
}
void set_xor(int x,int y)
{
	stmp.clear();
	set<int>::iterator it=s[x].begin();
	while(it!=s[x].end())
	stmp.insert(y^(*(it++)));
	s[x]=stmp;
	return ;
}
void dfs(int u,int f)
{
	vector<int> v;
	for(int i=0;i<(int)e[u].size();i++)
	if(e[u][i]!=f)
	{
		dfs(e[u][i],u);
		v.push_back(e[u][i]);
	}
	if((int)v.size()==0)
	{
		sid[u]=(++stp);
		s[sid[u]].insert(0);
		return ;
	}
	sort(v.begin(),v.end(),cmp);
	int hv_tg=a[v[0]];
	a[v[0]]=0;
	a[u]^=hv_tg;
	bool flg=false;
	set<int> setchk;
	for(int i=1;i<(int)v.size();i++)
	{
		int x=v[i];
		set_xor(sid[x],a[x]^hv_tg);
		set<int>::iterator it=s[sid[x]].begin();
		while(it!=s[sid[x]].end())
		{
			int val=(*it); it++;
			if(s[sid[v[0]]].find(val)!=s[sid[v[0]]].end())
			flg=true;
			if(setchk.find(val)!=setchk.end())
			flg=true;
			setchk.insert(val);
		}
	}
	if(flg==false)
	{
		//cout<<"Node "<<u<<" "<<(int)v.size()-1<<endl;
		ans+=(int)v.size()-1;
		for(int i=1;i<(int)v.size();i++)
		{
			int x=v[i];
			set<int>::iterator it=s[sid[x]].begin();
			while(it!=s[sid[x]].end())
			s[sid[v[0]]].insert(*(it++));
		}
		sid[u]=sid[v[0]];
		return ;
	}
	map<int,int> h;
	for(int i=0;i<(int)v.size();i++)
	{
		int x=v[i];
		set<int>::iterator it=s[sid[x]].begin();
		while(it!=s[sid[x]].end())
		h[*(it++)]++;
	}
	sid[u]=(++stp);
	int mx_app=0;
	map<int,int>::iterator it=h.begin();
	while(it!=h.end())
	{
		pair<int,int> p=(*it);
		if(p.second>mx_app)
		{
			mx_app=p.second;
			s[sid[u]].clear();
		}
		if(p.second==mx_app)
		s[sid[u]].insert(p.first);
		it++;
	}
	ans+=(int)v.size()-mx_app;
	return ;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	set_xor(sid[1],a[1]);
	if(s[sid[1]].find(0)==s[sid[1]].end())
	ans++;
	printf("%dn",ans);
	return 0;
}
```
F. LuoTianyi and the Function
-----------------------------

Consider an alternative method of calculating g. Notice that g(i,j) is the minimum of the last appearing position of all colors(let's call different values of ax colors for short) in the interval [i,j].

Consider the sequence from an to a1. Adding ai to the front of the sequence only affects the values g(i,x)(i≤x<nxti), where nxti is the next position after i having the same a value as it. Or it's to say to modify g values in the submatrix of [(1,i),(i,nxti−1)] to i, which can be done in O(nlog2n), but it's not fast enough.

Because the queries happen after all modifications take place, you can store the queries offline, and calculate a submatrix using 4 queries of submatrixes having (1,1) as the upper-left corner. Now we need to maintain a data structure that can: 1. set all values in an interval as a same value x, 2. query the history sum(sum of values on all previous editions). We can maintain the segments of adjacent positions with the same values, and turn the modification into 'range add' for a segment.

An operation makes at most O(1) new segments, and now there's only O(n) range add modifications and O(m) range history sum queries, now the problem can be solved in O(nlogn) time complexity with segment tree.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define L long long
int n,m,stt,a[N],nxt[N],siz[N],top,ll[N],rr[N],xx[N],yy[N];
L out[N];
struct ds{
	L t[2][N],ta;
	inline void add(int op,int x,L v){while(x<=n) t[op][x]+=v,x+=(x&-x);}
	inline L ask(int op,int x){ta=0;while(x) ta+=t[op][x],x^=(x&-x);return ta;}
	void Add(int l,int r,L v){add(0,l,v),add(0,r+1,-v),add(1,l,v*(l-1)),add(1,r+1,-v*r);}
	L Ask(int l,int r){return r*ask(0,r)-(l-1)*ask(0,l-1)-ask(1,r)+ask(1,l-1);}
} b1,b2;
struct node{int l,r,v;} st[N];
struct query{int id,op;} pl[2*N]; 
query *v[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],siz[a[i]]=n+1;
	for(int i=n;i>=1;--i) nxt[i]=siz[a[i]],siz[a[i]]=i;
	memset(siz,0,sizeof siz);
	for(int i=1;i<=m;++i){
		cin>>ll[i]>>rr[i]>>xx[i]>>yy[i];
		siz[ll[i]]++,siz[rr[i]+1]++;
	}
	for(int i=1;i<=n+1;++i) v[i]=pl+top,top+=siz[i];
	memset(siz,0,sizeof siz);
	for(int i=1;i<=m;++i) v[ll[i]][siz[ll[i]]++]=(query){i,1},v[rr[i]+1][siz[rr[i]+1]++]=(query){i,-1};
	for(int i=n,l,r;i>=1;--i){
		l=i,r=nxt[i]-1;
		while(stt&&r>=st[stt].r){
			node &nw=st[stt];
			b1.Add(nw.l,nw.r,1ll*-i*nw.v),b2.Add(nw.l,nw.r,-nw.v);
			stt--;
		}
		if(stt&&st[stt].l<=r){
			node &nw=st[stt];
			b1.Add(nw.l,r,1ll*-i*nw.v),b2.Add(nw.l,r,-nw.v);
			nw.l=r+1;
		}
		st[++stt]=(node){l,r,i};
		b1.Add(l,r,1ll*i*i),b2.Add(l,r,i);
		for(int j=0;j<siz[i];++j) out[v[i][j].id]+=1ll*v[i][j].op*(b1.Ask(xx[v[i][j].id],yy[v[i][j].id])-1ll*(i-1)*b2.Ask(xx[v[i][j].id],yy[v[i][j].id]));
	}
	for(int i=1;i<=m;++i) cout<<out[i]<<'n';
}
```
G. LuoTianyi and Cartridge
--------------------------

Consider finding the maximum value of B+D for every min(A,C). Denote min(A,C) as x. We call a vertex u satisfying au≥x or an edge satisfying ce≥x **optional**. Denote as V the optional vertex set and as E0 the optional edge set.

Firstly, if all optional vertices are on the same side of an edge, this edge mustn't be chosen. Delete these edges from E0 and we get the edge set E. Formally, an edge e is in E if and only if ce≥x and there exists u,v so that e is on the path between them.

Lemma. **There exists an optimal Tans=(Vans,Eans) that either V=Vans or E=Eans.**

Proof. Assume an optimal T′=(V′,E′) with V′≠V,E′≠E. Choose an edge e that is in E but not in E′. Because V′≠V, there must exist two vertices u,v on different sides of edge e and u∈V′,v∉V′. Consider adding the edge e and the vertex v into our chosen tree, the resulting graph is obviously a tree. Note that bv,de≥0, so the resulting choice is no worse than T′.

When we delete the edges in E from the original tree, we get some connected components. Shrink one component into a single vertex to get V′, and then for all edges (u,v)∈E, connect u's and v's component together in the new graph and get E′. Obviously, the new graph T′=(V′,E′) is a tree.

For any leaf vertex u′ on the new tree T′, there must exist a vertex u in the component u′ that is chosen, otherwise the edge connecting to u′, let's say, e′ is not chosen either. Adding u and e′ into our answer tree achieves a better answer.

Assume that now we have chosen a vertex u for every leaf u′, denote the set of chosen vertices as Vx. Consider an arbitary choice of vertex for components Vc and edge choice Ec satisfying Vx⊆Vc⊆V,Ec⊆E,|Vc|−1=|Ec|. It's easy to prove that the choice is a legal answer, given the fact that every e∈Ec has at least one leaf component on each side and every leaf component contains a chosen vertex.

Reconsider the lemma, and we can get a solution for a fixed x:

 1. Find V,E. Calculate the components and get V′,E′.
2. Find the vertex with the maximum b in every leaf-component in V′ and get Vx.
3. Let m be min(|V|,|E|+1), and m′ be |Vx|. Choose the vertices in V∖Vx with the first m−m′ largest b, and the edges in E with the first m−1 largest d and get the answer.

Consider the process when x gets larger, the sets V,E get smaller and smaller while the components merge into each other. We use segment trees to maintain the b value of the vertices and the d value of the edges, when merging two components, we simply merge the two segment trees.

The final time complexity is O(nlogn).

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
 
struct Segment_Tree
{
	static const int N = 1<<18, SIZ = N * 2 + 5;
	pii mx[SIZ];
	Segment_Tree(void){ clear();}
	void clear(void)
	{
		for(int i=0; i<N; ++i)
			mx[N+i] = {-inf, i};
		for(int i=N-1; i>=1; --i)
			mx[i] = max(mx[i<<1], mx[i<<1|1]);
	}
	void set(int i,int k)
	{
		i += N;
		mx[i].first = k;
		while((i >>= 1) != 0)
			mx[i] = max(mx[i<<1], mx[i<<1|1]);
	}
	pii query(int l,int r)
	{
		pii res = {-inf, -inf};
		for(l+=N-1, r+=N+1; l^r^1; l>>=1, r>>=1)
		{
			if(~l&1) res = max(res, mx[l^1]);
			if( r&1) res = max(res, mx[r^1]);
		}
		return res;
	}
}tree;
 
struct DS
{
	multiset<int> l,r;
	ll sum;
	DS(void){ clear();}
	void clear(void){ l.clear(); r.clear(); sum = 0;}
	void insert(int x)
	{
		if(!r.size() || x < *r.begin()) l.emplace(x);
		else r.emplace(x), sum += x;
	}
	void erase(int x)
	{
		if(l.find(x) != l.end())
			l.erase(l.find(x));
		else
			r.erase(r.find(x)), sum -= x;
	}
	int size(void) const
	{
		return (int)l.size() + (int)r.size();
	}
	ll query(int k)
	{
		while((int)r.size() > k)
		{
			int x = *r.begin(); r.erase(r.begin()); sum -= x;
			l.emplace(x);
		}
		while((int)r.size() < k && l.size())
		{
			int x = *l.rbegin(); l.erase(prev(l.end()));
			r.emplace(x); sum += x;
		}
		return sum;
	}
};
 
array<int,2> p[MAXN];
array<int,4> es[MAXN];
 
vector<pii> g[MAXN];
 
int anc[MAXN], ancid[MAXN];
void dfs_tree(int u,int fa)
{
	for(auto it: g[u]) if(it.first != fa)
	{
		int v = it.first;
		anc[v] = u;
		ancid[v] = it.second;
		dfs_tree(v,u);
	}
}
 
int dfnl[MAXN], dfnr[MAXN], seq[MAXN], curdfn;
void dfs_dfn(int u,int fa)
{
	dfnl[u] = ++curdfn; seq[curdfn] = u;
	for(auto it: g[u]) if(it.first != fa)
		dfs_dfn(it.first, u);
	dfnr[u] = curdfn;
}
 
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&p[i][0]);
	for(int i=1; i<=n; ++i)
		scanf("%d",&p[i][1]);
	for(int i=1; i<n; ++i)
		for(int &t: es[i])
			scanf("%d",&t);
	
	vector<pii> vec;
	for(int i=1; i<=n; ++i)
		vec.emplace_back(p[i][0], i << 1 | 0);
	for(int i=1; i<n; ++i)
	{
		vec.emplace_back(es[i][2], i << 1 | 1);
		
		int u = es[i][0], v = es[i][1];
		g[u].emplace_back(v,i);
		g[v].emplace_back(u,i);
	}
	
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	ll ans = 0;
	vector<pii> eff;
	
	int cntp = 0, cnte = 0;
	ll sump = 0, sume = 0;
	DS ds;
	
	// Part 1
	{
		int rt;
		{
			int i = 0;
			while(vec[i].second % 2 == 1) ++i;
			rt = vec[i].second >> 1;
		}
		
		anc[rt] = 0; ancid[rt] = 0;
		dfs_tree(rt,0);
		
		static int tage[MAXN];
		
		auto insert_edge = [&] (int i,int curval)
		{
			if(tage[i] != 3) return;
//			printf("insert_edge %dn",i);
			eff.emplace_back(curval, i << 1 | 1);
			ds.insert(es[i][3]);
			cnte += 1;
			sume += es[i][3];
		};
		auto insert_node = [&] (int u,int curval)
		{
//			printf("insert_node %dn",u);
			eff.emplace_back(curval, u << 1 | 0);
			cntp += 1;
			sump += p[u][1];
			
			while(u != rt && (tage[ancid[u]] & 1) == 0)
			{
				tage[ancid[u]] |= 1;
				insert_edge(ancid[u], curval);
				u = anc[u];
			}
		};
		
		for(auto t: vec)
		{
			int i = t.second >> 1, type = t.second & 1;
			if(type == 0)
			{
				insert_node(i, t.first);
			}
			else
			{
				tage[i] |= 2;
				insert_edge(i, t.first);
			}
			
			if(cntp >= 1 && cnte >= cntp - 1)
			{
				ll cur = sump + ds.query(cntp - 1);
				ans = max(ans, t.first * cur);
			}
		}
	}
	
	// Part 2
	{
		int rtid, rt1, rt2;
		{
			int i = 0;
			while(eff[i].second % 2 == 0) ++i;
			rtid = eff[i].second >> 1;
			rt1 = es[rtid][0];
			rt2 = es[rtid][1];
		}
		
		dfs_dfn(rt1,rt2);
		dfs_dfn(rt2,rt1);
		
		cntp = cnte = sump = sume = 0;
		ds.clear();
		map<int,pii> seg;
		ll has = 0;
		
		auto insert_seg = [&] (int l,int r)
		{
			auto it = seg.lower_bound(l);
			if(it != seg.end() && it -> second.first <= r) return;
			if(it != seg.begin())
			{
				--it;
				if(it -> second.first >= l)
				{
					int j = it -> second.second;
					seg.erase(it);
					ds.insert(p[j][1]);
					tree.set(dfnl[j], p[j][1]);
					has -= p[j][1];
				}
			}
			
			assert(tree.query(l,r).second != -inf);
			int j = seq[ tree.query(l,r).second ];
			ds.erase(p[j][1]);
			tree.set(dfnl[j], -inf);
			has += p[j][1];
			seg[l] = {r, j};
		};
		
		for(auto t: eff)
		{
			int i = t.second >> 1, type = t.second & 1;
			if(type == 0)
			{
				bool flag = [&] (void) -> bool
				{
					auto it = seg.upper_bound(dfnl[i]);
					if(it == seg.begin()) return 0;
					
					--it;
					if(it -> second.first < dfnl[i]) return 0;
					
					int j = it -> second.second;
					if(p[j][1] >= p[i][1]) return 0;
					
					ds.insert(p[j][1]);
					tree.set(dfnl[j], p[j][1]);
					it -> second.second = i;
					has = has - p[j][1] + p[i][1];
					return 1;
				}();
				
				if(!flag)
				{
					ds.insert(p[i][1]);
					tree.set(dfnl[i], p[i][1]);
				}
				
				++cntp; sump += p[i][1];
			}
			else
			{
				if(i == rtid)
				{
					insert_seg(dfnl[rt1], dfnr[rt1]);
					insert_seg(dfnl[rt2], dfnr[rt2]);
				}
				else
				{
					int u = es[i][0], v = es[i][1];
					if(dfnl[u] < dfnl[v]) swap(u, v);
					insert_seg(dfnl[u], dfnr[u]);
				}
				
				++cnte; sume += es[i][3];
			}
			
			if(cntp >= cnte + 1)
			{
				ll cur = sume + has + ds.query(cnte + 1 - (int)seg.size());
				ans = max(ans, t.first * cur);
			}
		}
	}
	
	printf("%lldn",ans);
	return 0;
}
```
