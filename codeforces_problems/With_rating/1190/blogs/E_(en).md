# E_(en)

[1191A - Tokitsukaze and Enhancement](https://codeforces.com/contest/1191/problem/A "Codeforces Round 573 (Div. 2)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Master tokitsukaze")

 **Tutorial**Just enumerating the increment can pass.

However, by increasing at most 2 points, the value of her HP can always become an odd number, and thus the highest possible level is either A or B. We can just solve case by case.

 **Solution (by Claris)**
```cpp
#include<cstdio>
int x,i,A;char B;
char cal(int x){
  x%=4;
  if(x==0)return 'D';
  if(x==1)return 'A';
  if(x==2)return 'C';
  return 'B';
}
int main(){
  scanf("%d",&x);
  A=0;
  B=cal(x);
  for(i=1;i<=2;i++){
    if(cal(x+i)<B){
      A=i;
      B=cal(x+i);
    }
  }
  printf("%d %c",A,B);
}
```
 **Solution (by tokitsukaze)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	if(x%4==0) puts("1 A");
	else if(x%4==1) puts("0 A");
	else if(x%4==2) puts("1 B");
	else if(x%4==3) puts("2 A");
	return 0;
}
```
[1191B - Tokitsukaze and Mahjong](https://codeforces.com/contest/1191/problem/B "Codeforces Round 573 (Div. 2)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Master tokitsukaze"), [2014CAIS01](https://codeforces.com/profile/2014CAIS01 "Master 2014CAIS01")

 **Tutorial**There are only two types of **mentsu**s, so you can enumerate the **mentsu** you want her to form, and check the difference between that and those currently in her hand.

Alternatively, you can find out that the answer is at most 2, since she can draw two extra identical tiles which are the same as one of those in her hand. You may enumerate at most 1 extra tile for her and check if it can contribute to a **mentsu**. If she can't, the answer will be 2.

 **Solution (by skywalkert)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	int idx[257] = {}, c[3][9] = {}, ans = 2;
	idx['m'] = 1;
	idx['p'] = 2;
	idx['s'] = 3;
	for(int i = 0; i < 3; ++i) {
		char buf[3];
		scanf("%s", buf);
		++c[idx[buf[1]] - 1][buf[0] - '1'];
	}
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 9; ++j) {
			ans = min(ans, 3 - c[i][j]);
			if(j + 2 < 9)
				ans = min(ans, 3 - !!c[i][j] - !!c[i][j + 1] - !!c[i][j + 2]);
		}
	printf("%dn", ans);
	return 0;
}
```
 **Solution (by isaf27)**
```cpp
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00
 
//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-7;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;
 
//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;
 
bool check(string a, string b, string c)
{
    if (a == b && b == c) return true;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a[1] == b[1] && b[1] == c[1])
    {
        if (a[0] + 1 == b[0] && b[0] + 1 == c[0])
            return true;
    }
    return false;
}
 
int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    if (check(a, b, c))
    {
        cout << "0";
        return 0;
    }
    vector<string> var;
    for (int i = 1; i <= 9; i++)
    {
        string s = "";
        s += (char)(i + '0');
        var.push_back(s + "m");
        var.push_back(s + "p");
        var.push_back(s + "s");
    }
    for (string s : var)
    {
        if (check(s, a, b))
        {
            cout << "1";
            return 0;
        }
        if (check(s, a, c))
        {
            cout << "1";
            return 0;
        }
        if (check(s, b, c))
        {
            cout << "1";
            return 0;
        }
    }
    cout << "2";
    return 0;
}
```
[1190A - Tokitsukaze and Discard Items](../problems/A._Tokitsukaze_and_Discard_Items.md "Codeforces Round 573 (Div. 1)") / [1191C - Tokitsukaze and Discard Items](https://codeforces.com/contest/1191/problem/C "Codeforces Round 573 (Div. 2)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Master tokitsukaze")

 **Tutorial**The order of discarding is given, so we can simulate the process of discarding.

In each time, we can calculate the page that contains the first special item that has not been discarded, and then locate all the special items that need to be discarded at one time. Repeat this process until all special items are discarded.

Each time at least one item would be discarded, so the time complexity is O(m).

 **Solution (by tokitsukaze)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
ll p[MAX];
int main()
{
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
	int ans=0;
	int sum=0;
	int now=1;
	while(now<=m)
	{
		ll r=((p[now]-sum-1)/k+1)*k+sum;
	//	cout<<"r:"<<r<<endl;
		while(now<=m&&p[now]<=r)
		{
			sum++;
			now++;
		}
		ans++;
	}
	printf("%dn",ans);
	return 0;
}
```
[1190B - Tokitsukaze, CSL and Stone Game](../problems/B._Tokitsukaze,_CSL_and_Stone_Game.md "Codeforces Round 573 (Div. 1)") / [1191D - Tokitsukaze, CSL and Stone Game](https://codeforces.com/contest/1191/problem/D "Codeforces Round 573 (Div. 2)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Master tokitsukaze")

 **Tutorial**Unless the first player must lose after the first move, the numbers of stones in these piles should form a permutation obtained from 0 to (n−1) in the end, in order to ensure that there are no two piles include the same number of stones.

Let's use cnt[x] to represent the number of piles which have exactly x stones in the beginning. There are four cases that Tokitsukaze will lose after the first move:

 * cnt[0]>1;
* cnt[x]>2 for some x;
* cnt[x]>1 and cnt[y]>1 for some x, y (x≠y);
* cnt[x]>1 and cnt[x−1]>0 for some x.

If Tokitsukaze won't lose after the first move, then we only need to check the parity of the total number of stones that can be taken.

By the way, if you don't want to discuss the above four cases, you can just enumerate her first move.

 **Solution (by tokitsukaze)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int n;
	cin>>n;
	map<int,int> mp;
	int ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		ok&=(mp[a[i]]<3); //situation 1: one >=3 
	}
	int cnt=0;
	for(auto it:mp)
	{
		if(it.second>=2) cnt++;
	}
	ok&=(cnt<=1);// situation 2: more than two >=2
	for(auto it:mp)
	{
		if(it.second==2)
		{
			ok&=(mp.count(it.first-1)==0);// situation 3: reduce one but add another
			if(it.first==0) ok=0;// situation 4: two pile is zero
		} 
	}
	if(!ok) return 0*puts("cslnb");
	// normal situation 
	sort(a+1,a+1+n);
	ll s=0;
	for(int i=1;i<=n;i++)
	{
		assert(a[i]>=i-1);
		s+=a[i]-(i-1);
	}
	s%=2;
	return 0*puts(s?"sjfnb":"cslnb");
}
```
 **Solution (by skywalkert)**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 1;
int n, a[maxn], c[3];
void update(int x, int d) {
	static map<int, int> ctr;
	int &v = ctr[x];
	--c[min(v, 2)];
	v += d;
	++c[min(v, 2)];
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		update(a[i], 1);
	}
	bool chk = 0;
	for(int i = 0; !chk && i < n; ++i)
		if(a[i]) {
			update(a[i], -1);
			update(a[i] - 1, 1);
			chk |= !c[2];
			update(a[i] - 1, -1);
			update(a[i], 1);
		}
	if(chk) {
		chk = 0;
		for(int i = 0; i < n; ++i)
			chk ^= (a[i] + i) & 1;
	}
	puts(chk ? "sjfnb" : "cslnb");
	return 0;
}
```
[1190C - Tokitsukaze and Duel](../problems/C._Tokitsukaze_and_Duel.md "Codeforces Round 573 (Div. 1)") / [1191E - Tokitsukaze and Duel](https://codeforces.com/contest/1191/problem/E "Codeforces Round 573 (Div. 2)")

Idea: [teitoku](https://codeforces.com/profile/teitoku "Candidate Master teitoku"), [winterzz1](https://codeforces.com/profile/winterzz1 "Candidate Master winterzz1")

 **Tutorial**If a player can make a move from a situation to that situation again, this player will not lose. Except for some initial situations, one can move from almost every situation to itself. Based on these two conclusions, we can get a solution.

If Tokitsukaze cannot win after her first move, she cannot win in the future. In this case, we can quickly check if k is so limited that she cannot win.

After her first move, it is possible that Quailty wins in the next move. If he cannot, in order to prevent failure, he can just leave the situation to his opponent by doing useless flipping and thus result in a draw.

Therefore, we can check if no matter how Tokitsukaze moves, Quailty has no chance to win after his first move. It can be easily checked linearly if we do some precalculation and enumerate Tokitsukaze's first move. Alternatively, we can find and check the pattern of initial situations in which Quailty can win.

 **Solution (by quailty)**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,k;
char str[MAXN];
vector<int> loc[2];
int main()
{
    scanf("%d%d%s",&n,&k,str);
    for(int i=0;i<n;i++)
        loc[str[i]-'0'].push_back(i);
    if(loc[0].empty() || loc[1].empty())
        return 0*printf("tokitsukazen");
    int flag=0;
    for(int l=0,r=k-1;r<n;l++,r++)
    {
        vector<int> tmp[2];
        for(int i=0;i<2;i++)
        {
            if(loc[i].front()<l || loc[i].front()>r)
                tmp[i].push_back(loc[i].front());
            if(loc[i].back()<l || loc[i].back()>r)
                tmp[i].push_back(loc[i].back());
            auto itr=lower_bound(loc[i].begin(),loc[i].end(),l);
            if(itr!=loc[i].begin())
                tmp[i].push_back(*--itr);
            itr=upper_bound(loc[i].begin(),loc[i].end(),r);
            if(itr!=loc[i].end())
                tmp[i].push_back(*itr);
            sort(tmp[i].begin(),tmp[i].end());
        }
        if(tmp[0].empty() || tmp[1].empty())
            return 0*printf("tokitsukazen");
        flag|=(tmp[0].back()-tmp[0].front()>=k
            || tmp[1].back()-tmp[1].front()>=k);
    }
    return 0*printf("%sn",(flag ? "once again" : "quailty"));
}
```
 **Solution (by skywalkert)**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 1;
int n, m, p[maxn], lft[maxn], rht[maxn];
char buf[maxn];
int main() {
	scanf("%d%d%s", &n, &m, buf);
	for(int i = 0, las[2] = {-1, -1}; i < n; ++i) {
		int o = buf[i] - '0';
		lft[i] = las[o ^ 1];
		las[o] = i;
	}
	for(int i = n - 1, las[2] = {n, n}; i >= 0; --i) {
		int o = buf[i] - '0';
		rht[i] = las[o ^ 1];
		las[o] = i;
	}
	bool fir = 0, sec = 1;
	for(char op = '0'; op <= '1' && !fir; ++op) {
		int sz = 0;
		for(int i = 0; i < n; ++i)
			if(buf[i] != op)
				p[sz++] = i;
		for(int L = 0, R = m - 1, pL = 0, pR = -1; R < n; ++L, ++R) {
			for( ; pL < sz && p[pL] < L; ++pL);
			for( ; pR + 1 < sz && p[pR + 1] <= R; ++pR);
			if(pL == 0 && pR == sz - 1) {
				fir = 1;
				break;
			}
			int uL = p[pL ? 0 : pR + 1];
			int uR = p[pR < sz - 1 ? sz - 1 : pL - 1];
			int vL = uL > 0 ? 0 : min(rht[uL], uR + 1);
			int vR = uR < n - 1 ? n - 1 : max(lft[uR], uL - 1);
			sec &= uR - uL + 1 <= m || vR - vL + 1 <= m;
		}
	}
	puts(fir ? "tokitsukaze" : (sec ? "quailty" : "once again"));
	return 0;
}
```
 **Solution (by winterzz1)**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int n,k,T;
int a[MAXN],sum[MAXN];
int q_sum(int l,int r)
{
    if(l>r)return 0;
    return sum[r]-sum[l-1];
}
bool check_fir()
{
    for(int i=1;i+k-1<=n;++i)
    {
        int lala=q_sum(1,i-1)+q_sum(i+k,n);
        if(lala==0||lala+k==n)return true;
    }
    return false;
}
bool check_sec()
{
    if(k*2<n||k==1)return false;
    int len=n-k-1;
    for(int i=2;i<=len;++i)
    {
        if(a[i]!=a[i-1]||a[n-i+1]!=a[n-i+2])return false;
    }
    if(a[len]==a[len+1]||a[n-len]==a[n-len+1]||a[1]==a[n])return false;
    return true;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%1d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    if(check_fir())
    {
        printf("tokitsukazen");
    }
    else
    {
        if(check_sec())
        {
            printf("quailtyn");
        }
        else
        {
            printf("once againn");
        }
    }
    return 0;
}
```
[1190D - Tokitsukaze and Strange Rectangle](../problems/D._Tokitsukaze_and_Strange_Rectangle.md "Codeforces Round 573 (Div. 1)") / [1191F - Tokitsukaze and Strange Rectangle](https://codeforces.com/contest/1191/problem/F "Codeforces Round 573 (Div. 2)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Master tokitsukaze")

 **Tutorial**For each strange rectangular area and its corresponding set of points, we only need to focus on the lowest y-coordinate yB, the leftmost x-coordinate xL and the rightmost x-coordinate xR of points in this set. Different sets must have different yB, xL, xR, so we can count them by enumerating these values.

Let's enumerate yB first. Then, we need to list all the possible x-coordinates of points (xi,yi) satisfying that yi≥yB and mark every possible x′ satisfying there is a point (x′,yB). By doing so, we can make sure when enumerating xL and xR, the requirement for yB is met as well. However, enumerating forcibly, which is in time complexity O(n3), is too slow to pass, so let's optimize the enumeration step by step.

Let's pick and sort the points (x′1,yB),(x′2,yB),…,(x′m,yB) from left to right. Assuming that x′0=0, and (x′j,yB) is the leftmost point of them that is in the chosen set, we can count the number of aforementioned different x-coordinates in ranges [x′j−1+1,x′j] and [x′j,∞) and then count the number of possible pairs (xL,xR) immediately. More specifically, let cnt(l,r) be the number of different x-coordinates of points in the area {(x,y)|l≤x≤r,y≥yB}, and we know the number of possible pairs (xL,xR) is cnt(x′j−1+1,x′j)⋅cnt(x′j,∞). After precalculating c(1,x) for each yB, we can reduce the time complexity into O(n2).

The very last step is using the trick of sweeping lines. We can enumerate yB from highest to lowest, and during that process, use data structures to maintain possible x-coordinates. What we need to implement is to maintain a container, check if a coordinate is already in the container, add a coordinate to the container, and query the number of coordinates in a range. These requirements can be easily achieved by Fenwick tree, segment tree or others. With the last optimization, we can solve in time complexity O(nlogn).

By the way, there also exist solutions using other approaches, such as *divide and conquer*.

 **Solution (by tokitsukaze)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int get(int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	int query(int l,int r)
	{
		return get(r)-get(l-1);
	}
}tr;
VI x[MAX],y;
void go()
{
	int n,i,tot,pre;
	ll ans;
	while(~scanf("%d",&n))
	{
		tr.init(n);
		y.clear();
		map<int,int> idx,idy,cntx;
		tot=0;
		for(i=0;i<n;i++)
		{
			int X,Y;
			scanf("%d%d",&X,&Y);
			if(!idy.count(Y))
			{
				x[tot].clear();
				idy[Y]=tot++;
				y.pb(Y);
			}
			x[idy[Y]].pb(X);
			cntx[X]++;
		}
		tot=0;
		for(auto it:cntx)
		{
			idx[it.fi]=++tot;
			tr.insert(tot,1);
		}
		sort(all(y));
		ans=0;
		for(auto Y:y)
		{
			sort(all(x[idy[Y]]));
			pre=1;
			for(auto X:x[idy[Y]])
			{
				ans+=1LL*tr.query(pre,idx[X])*tr.query(idx[X],tot);
				pre=idx[X]+1;
				cntx[X]--;
				if(cntx[X]==0)
				{
					cntx.erase(X);
					tr.insert(idx[X],-1);
				}
			}
		}
		printf("%lldn",ans);
	}
}
```
 **Solution (by winterzz1)**
```cpp
#include <bits/stdc++.h>
using namespace std;
//priority_queue<int> q;
//priority_queue<int,vector<int>, greater<int> > q;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> less_rbtree;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> greater_rbtree;

typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> multi_less_rbtree;
typedef tree<pair<int,int>, null_type, greater<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> multi_greater_rbtree;
const int MAXN=300005;
less_rbtree div_tree;
long long ans;
struct node
{
    int x,y;
}p[MAXN],temp[MAXN];
int n;
bool cmp1(const node & A,const node & B)
{
    return A.x<B.x;
}
bool cmp2(const node & A,const node & B)
{
    if(A.y!=B.y)return A.y>B.y;
    return A.x<B.x;
}
void div_algorithm(int l,int r)
{
    if(l>r)return;
    div_tree.clear();
    for(int i=l;i<=r;++i)
    {
        temp[i]=p[i];
    }
    int mid_line=p[(l+r)>>1].x;
    long long preans=ans;
    int lpos=-1,rpos=-1;
    sort(temp+l,temp+r+1,cmp2);
    for(int i=l;i<=r;++i)
    {
        div_tree.insert(temp[i].x);
        if(temp[i].x<=mid_line)
        {
            if(lpos==-1||lpos<temp[i].x)
            {
                lpos=temp[i].x;
            }
        }
        if(temp[i].x>=mid_line)
        {
            if(rpos==-1||rpos>temp[i].x)
            {
                rpos=temp[i].x;
            }
        }
        if(i==r||temp[i+1].y!=temp[i].y)
        {

            long long lsum=div_tree.order_of_key(lpos+1);
            long long Lsum=div_tree.order_of_key(mid_line+1);
            long long rsum=div_tree.size()-div_tree.order_of_key(rpos);
            long long Rsum=div_tree.size()-div_tree.order_of_key(mid_line);
            if(lpos==-1)
            {
                ans+=Lsum*rsum;
            }
            else if(rpos==-1)
            {
                ans+=lsum*Rsum;
            }
            else
            {
                ans+=lsum*Rsum+Lsum*rsum-lsum*rsum;
            }
            lpos=-1;
            rpos=-1;
        }
    }
    int pin1=l,pin2=r;
    while(p[pin1].x!=mid_line)++pin1;
    while(p[pin2].x!=mid_line)--pin2;
    div_algorithm(l,pin1-1);
    div_algorithm(pin2+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    sort(p+1,p+1+n,cmp1);
    div_algorithm(1,n);
    printf("%I64dn",ans);
    return 0;
}
```
[1190E - Tokitsukaze and Explosion](../problems/E._Tokitsukaze_and_Explosion.md "Codeforces Round 573 (Div. 1)")

Idea: [chenjb](https://codeforces.com/profile/chenjb "Grandmaster chenjb"), [Subconscious](https://codeforces.com/profile/Subconscious "International Grandmaster Subconscious")

 **Tutorial**It is obvious that we can binary search the answer because we can pull any line closer to O and the situation won't change. Applying a binary search, we focus on if it is possible to set m barriers with the same distance to O and meet the requirement. By doing so, we can draw a circle whose center is O such that the closest point to O on each barrier is on the circumference. Then it becomes a classic problem — for each barrier we can get the angle range of its closest point on the circle, and we have to choose at most m points on the circle to ensure that there is at least one point within each range.

This kind of greedy trick is very simple on a sequence. As to ranges on a sequence, you only have to sort all ranges in increasing order of left endpoint and take every necessary right endpoint. As to ranges on a circle, you can enumerate a position to break the circle into a sequence. But if you enumerate as the same way on the sequence, the time complexity will be O(n2) which is not enough.

Instead, we can double and extend these ranges into 2n ranges and then regard them as on a sequence. We can do some precalculation, such as if we want to choose a point to cover the i-th sorted range and other ranges in its right as many as possible, what is the next range that we cannot cover. Let's denote that as f[i][0], and then we can calculate the next range after 2p repeated steps from the i-th range as f[i][p], which can be obtained from f[f[i][p−1]][p−1]. After preparation, we can enumerate the beginning position and use binary lifting method, each time in complexity O(logm), to know that whether we can use m steps to cover all the ranges.

Therefore, the total time complexity can be O(nlogmlogD), where D is the precision requirement.

 **Solution (by chenjb)**
```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pi acos(-1.0)
#define LOG 20
#define eps 1e-9
 
using namespace std;
const int N = 500010;
const double twopi = 2*acos(-1.0);
int n,m,tot,fa[N*2][LOG];
bool nd[N*2];
double xx[N],yy[N],di[N];
struct Segment
{
    double l,r; bool typ;
    Segment(){}
    Segment(double l,double r,bool typ):l(l),r(r),typ(typ){} 
}q[N*2];
bool cmp(const Segment &a,const Segment &b){ if(a.typ!=b.typ) return a.typ<b.typ; return a.l<b.l; }
bool check(double cur)
{
    tot = 0;
    for(int i=1;i<=n;i++)
    {
        double deg = atan2(yy[i],xx[i]), p = acos(cur/di[i]);
        q[++tot] = Segment(deg-p,deg+p,0);
        q[++tot] = Segment(deg-p+twopi,deg+p+twopi,1);
    }
    sort(q+1,q+1+tot,cmp);
    double mr = 2147483600;
    memset(nd,1,tot+1);
    for(int i=tot;i;i--)
    {
        if(q[i].r>=mr) nd[i] = 0;
        else mr = q[i].r;
    }
    tot = 0;
    for(int i=1;i<=n;i++) if(nd[i]) q[++tot] = q[i];
    for(int i=1;i<=tot;i++) q[i+tot] = Segment(q[i].l+twopi,q[i].r+twopi,1);
    tot <<= 1;
    int j = 1;
    for(int i=1;i<=tot;i++)
    {
        while(j<=tot&&q[i].r>=q[j].l) j++;
        fa[i][0] = j;
    }
    for(int j=1;(1<<j)<=tot;j++)
        for(int i=1;i<=tot;i++)
            fa[i][j] = fa[fa[i][j-1]][j-1];
    for(int i=1;(i<<1)<=tot;i++)
    {
        int p = i, tmp = 0;
        for(int k=m;k;k>>=1,tmp++) 
            if(k&1) p = fa[p][tmp];
        if(p==0||p>=i+(tot>>1)) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    double l = 0, r = 1e100;
    for (int i=1;i<=n;i++) {
        scanf("%lf%lf",&xx[i],&yy[i]);
        di[i] = sqrt(xx[i]*xx[i]+yy[i]*yy[i]);
        r = min(r, di[i]);
    }
    if(m>=n) {
        printf("%.10fn",r);
        return 0;
    }
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid; else r = mid;
    }
    printf("%.10fn", l);
    return 0;
}
```
 **Solution (by quailty)**
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;

const int MAXN=100005;
const int DEP=18;

vector<pair<int,int> > filter(int n,vector<pair<int,int> > &seg)
{
    vector<pair<int,int> > now;
    for(auto &t:seg)
    {
        t.second=(t.second+n-1)%n;
        int l=t.first,r=t.second;
        if(l<=r)
        {
            now.push_back(make_pair(l,-r));
            now.push_back(make_pair(l+n,-(r+n)));
        }
        else now.push_back(make_pair(l,-(r+n)));
    }
    sort(now.begin(),now.end());
    vector<pair<int,int> > stk;
    for(auto &t:now)
    {
        while(!stk.empty() && stk.back().second<=t.second)
            stk.pop_back();
        stk.push_back(t);
    }
    vector<pair<int,int> > res;
    for(auto &t:stk)if(t.first<n)
        res.push_back(make_pair(t.first,-t.second));
    return res;
}
int go[MAXN<<1][DEP];
int cal(int n,vector<pair<int,int> > &seg)
{
    seg=filter(n,seg);
    int m=(int)seg.size();
    if(m<2)return m;
    for(int i=0;i<m;i++)
    {
        int l=seg[i].first,r=seg[i].second;
        seg.push_back(make_pair(l+n,r+n));
    }
    for(int i=0;i<2*m;i++)
        go[i][0]=lower_bound(seg.begin(),seg.end(),make_pair(seg[i].second+1,0))-seg.begin();
    go[2*m][0]=2*m;
    for(int j=1;j<DEP;j++)
        for(int i=0;i<=2*m;i++)
            go[i][j]=go[go[i][j-1]][j-1];
    int res=m;
    for(int i=0;i<m;i++)
    {
        int t=i,cnt=0;
        for(int j=DEP-1;j>=0;j--)
            if(go[t][j]<i+m)
                t=go[t][j],cnt+=(1<<j);
        if(res>cnt+1)res=cnt+1;
    }
    return res;
}

const db PI=acos(-1.0);
ll x[MAXN],y[MAXN];
db dis[MAXN],ang[MAXN],angl[MAXN],angr[MAXN],anga[MAXN<<1];

bool check(int n,int m,db r)
{
    for(int i=0;i<n;i++)
    {
        db t=acos(min(1.0L,r/dis[i]));
        angl[i]=ang[i]-t,angr[i]=ang[i]+t;
        if(angl[i]<0)angl[i]+=2*PI;
        if(angr[i]>=2*PI)angr[i]-=2*PI;
        anga[i<<1]=angl[i],anga[i<<1|1]=angr[i];
    }
    sort(anga,anga+2*n);
    int k=unique(anga,anga+2*n)-anga;
    vector<pair<int,int> > seg;
    for(int i=0;i<n;i++)
    {
        int l=lower_bound(anga,anga+k,angl[i])-anga;
        int r=lower_bound(anga,anga+k,angr[i])-anga;
        seg.push_back({l,r});
    }
    return cal(k,seg)<=m;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&x[i],&y[i]);
    db md=1e7;
    for(int i=0;i<n;i++)
    {
        dis[i]=sqrtl(x[i]*x[i]+y[i]*y[i]);
        ang[i]=atan2(y[i],x[i]);
        if(ang[i]<0)ang[i]+=2*PI;
        md=min(md,dis[i]);
    }
    if(md<1e-7)return 0*printf("%.12Lfn",0.0L);
    db tl=0,tr=1;
    while(tr<md && check(n,m,tr))
        tl=tr,tr=min(md,2*tr);
    for(int _=0;_<25;_++)
    {
        db tm=(tl+tr)/2;
        if(check(n,m,tm))tl=tm;
        else tr=tm;
    }
    return 0*printf("%.12Lfn",(tl+tr)/2);
}
```
[1190F - Tokitsukaze and Powers](../problems/F._Tokitsukaze_and_Powers.md "Codeforces Round 573 (Div. 1)")

Idea: [skywalkert](https://codeforces.com/profile/skywalkert "Grandmaster skywalkert")

 **Tutorial**Firstly, let me briefly review this problem for you. Given integers n, m and p (n>0, m>1, p≠0), we denote S={x|x∈Z,0≤x<m,gcd(m,x)=1} and T={pemodm|e∈Z,e≥0}, where gcd(m,x) means the greatest common divisor of m and x, and you are asked to pick up n distinct integers from (S−T), the set of elements in S but not in T, or report that it is unachievable. Besides, there is an additional restriction, m=qk for a prime number q and a positive integer k.

It is not difficult to show |S|, the size of S, equals to φ(m)=m(1−1q). When gcd(m,p)>1, there is only one element p0modm=1 in T which is coprime to m, so in that case, |S−T|=φ(m)−1. To output a solution, you can just enumerate the smallest integers and skip the integer 1 and any multiples of q. In this process, you won't need to enumerate more than (2n+1) integers, because n1−1q+1≤2n+1.

When gcd(m,p)=1, we can observe that T⊆S. Let |T| be λ, and we may conclude from Euler's totient theorem that λ≤φ(m), and even λ|φ(m). When n>φ(m)−λ, there is no solution, so we need to calculate λ in order to determine the existence of solutions.

To calculate λ, you can just enumerate all the divisors of φ(m) and check them using *Fast Power Algorithm*, because the number of divisors is not too large due to the restrictions. Alternatively, you can do it more advanced and check more efficiently like the following.

 
```cpp
lambda = phi(m)
for each x in prime factors of phi(m) :
	if pow(p, lambda / x, m) == 1 :
		lambda = lambda / x
```
The above approach requires O(logφ(m)) calls of *Fast Power Algorithm*. It is used more regularly when searching a random primitive root in modulo some integer.

When implementing *Fast Power Algorithm*, you may notice an issue that the modular multiplication may not be easy to code, when the 128-bit integer operations are not directly provided on this platform. In a precise way, you can implement another like *Fast Multiplying Algorithm*, though it is a bit slow. But if you believe you are lucky enough and you prefer using C/C++, you can try the following code in a convenient way.

 
```cpp
typedef long long LL;
typedef long double LD;
LL mod_mul(LL x, LL y, LL mod) { // 0 <= x, y < mod
	LL ret = x * y - (LL)((LD)x * y / mod + 0.5) * mod;
	return ret < 0 ? ret + mod : ret;
}
```
No matter what approach you used, the factorization of (q−1) is inevitable, so the problem requires you to factorize a relatively large number (less than 1018) a bit quickly. For example, you can use *Pollard's Rho Algorithm* with *Miller-Rabin Primality Test*. By *Birthday Paradox*, which is a heuristic claim, when x is not a prime, *Pollard's Rho Algorithm* can split x into u⋅v in O(√min(u,v))=O(x1/4) iterations. By the way, you can obtain q from m by enumerating possible k from large to small, instead of factorization.

Let's go back to the case that gcd(m,p)=1 and n≤φ(m)−λ. When any solution exists, we can observe that φ(m)−λ≥φ(m)2, so there may exist some solutions based on random distribution. That is, if you are able to check whether an integer is in T or not, you can roughly pick 2n integers in S and check them. One approach is like the mechanism built in the problem checker, but as space is limited, I would not expend it at here. One thing you should be aware of is that you can't pick them without checking, as the probability of failure may be so large, like 12. Moreover, you can't use *Baby-Step-Giant-Step algorithm* since its time complexity O(√nm) is too slow.

If there exists at least one primitive root in modulo m, then we can construct the output integers. Since a primitive root g can represent S as {gemodm|e∈Z,0≤e<φ(m)}, we can reduce the problem into something about modular equation that only concerns the exponents. As the number of primitive root in modulo m is φ(φ(m)), if the root exists, we can get a random primitive root easily. Now let's assume we find a primitive root g and p \equiv g^u \pmod{m}. An integer (g^v \bmod m) is in T if and only if the equation e u \equiv v \pmod{\varphi(m)} has a solution of e. It is easy to show, when \gcd(\varphi(m), u) | v, a solution of e always exists, so the construction is quite straightforward.

The only case we left is when no primitive root exists in modulo m, which occurs when m = 2^k, k \geq 3. In this case, we cannot represent all the elements in S as non-negative integer powers of one specific number, but we can find a pseudo-primitive root g' to use its powers to represent all the elements in the form of (4 t + 1) in S (as the group (S, \times_m), also known as (\mathbb{Z}/m\mathbb{Z})^{\times}, is isomorphic to a direct product of cyclic groups, \mathrm{C}_2 \times \mathrm{C}_{2^{k - 2}}). Besides, \lbrace m - ({g'}^{e} \bmod m) | e \in \mathbb{Z}, 0 \leq e < 2^{k - 2} \rbrace can represent the rest numbers (in the form of (4 t + 3)) in S. As the product of two integers in the form of (4 t + 3) is in the form of (4 t + 1), we can discuss the parity of e in expression (p^e \bmod m) and check if an integer is in T, so the construction could work after a little modification. By the way, there exist many different construction methods for this case.

In summary, to solve this problem, we need to factorize \varphi(m), calculate the order of p in modulo m, find a primitive root g (or a pseudo-primitive root g') in modulo m and enumerate some small integers (values or exponents) to construct a solution.

**Time complexity: \mathcal{O}((m^{1 / 4} + n) M(m)), where M(m) means the cost of one multiplication modulo m.** Some slow solutions are accepted as well.

 **Solution (by skywalkert)**
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
inline LL mod_add(LL x, LL y, LL mod) {
	return (x += y) < mod ? x : x - mod;
}
inline LL mod_mul(LL x, LL y, LL mod) {
	const int BLEN = __builtin_clzll(mod) - 1;
	const LL BMSK = (1LL << BLEN) - 1;
	LL ret = 0;
	if(x < y)
		swap(x, y);
	while(y > 0) {
		ret += x * (y & BMSK);
		ret = ret < mod ? ret : ret % mod;
		y >>= BLEN;
		x <<= BLEN;
		x = x < mod ? x : x % mod;
	}
	return ret;
/*
	typedef long double LD;
	LL ret = x * y - (LL)((LD)x * y / mod + 0.5) * mod;
	return ret < 0 ? ret + mod : ret;
*/
}
inline LL mod_pow(LL x, LL k, LL mod) {
	LL ret = mod > 1 ? 1 : 0;
	for( ; k > 0; k >>= 1, x = mod_mul(x, x, mod))
		if(k & 1)
			ret = mod_mul(ret, x, mod);
	return ret;
}
inline LL int_pow(LL x, int k, LL upp) {
	LL ret = 1, lim = (++upp) / x;
	for( ; k > 0; --k) {
		if(ret > lim)
			return upp;
		ret *= x;
	}
	return ret;
}
inline bool miller_rabin(LL n) {
	if(n == 2)
		return 1;
	if(n < 2 || !(n & 1))
		return 0;
	LL s, r;
	for(s = 0, r = n - 1; !(r & 1); r >>= 1, ++s);
	static const int ptot = 12, pr[ptot] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for(int p : pr) {
		if(p >= n)
			break;
		LL cur = 1, nxt = p;
		for(LL k = r; k > 0; k >>= 1, nxt = mod_mul(nxt, nxt, n))
			if(k & 1)
				cur = mod_mul(cur, nxt, n);
		for(int i = 0; i < s; ++i) {
			nxt = mod_mul(cur, cur, n);
			if(nxt == 1 && cur != 1 && cur != n - 1)
				return 0;
			cur = nxt;
		}
		if(cur != 1)
			return 0;
	}
	return 1;
}
inline LL pollard_rho(LL n) {
	static mt19937_64 rnd(996);
	while(1) {
		LL x = rnd() % (n - 3) + 2, y = x, c = rnd() % n, tim = 0, prd = 1;
		for(LL i = 1, stp = 2; ; ++i) {
			if(i == stp) {
				y = x;
				stp <<= 1;
			}
			if((x = mod_add(mod_mul(x, x, n), c, n)) == y)
				break;
			LL tmp = prd;
			if((prd = mod_mul(prd, abs(y - x), n)) == 0)
				return __gcd(tmp, n);
			static const int maxt = 100;
			if((++tim) < maxt)
				continue;
			if((prd = __gcd(prd, n)) > 1)
				return prd;
			tim = 0;
		}
		if(tim > 0 && (prd = __gcd(prd, n)) > 1)
			return prd;
	}
	assert(0);
}
inline vector<pair<LL, LL> > factorize(LL n) {
	vector<LL> vec;
	queue<LL> que;
	que.push(n);
	while(!que.empty()) {
		LL x = que.front();
		que.pop();
		for(LL y : vec)
			for( ; x % y == 0; x /= y, vec.push_back(y));
		if(x == 1)
			continue;
		if(miller_rabin(x)) {
			vec.push_back(x);
		} else {
			LL y = pollard_rho(x);
			que.push(y);
			que.push(x / y);
		}
	}
	sort(vec.begin(), vec.end());
	vector<pair<LL, LL> > ret;
	for(LL x : vec)
		if(!ret.empty() && ret.back().first == x) {
			++ret.back().second;
		} else {
			ret.push_back(make_pair(x, 1LL));
		}
	return ret;
}

const int maxn = (int)5e5 + 1, maxe = 60;
int n;
LL m, sp, pr, ex, phi, ord, gen;
void init() {
	scanf("%d%lld%lld", &n, &m, &sp);
	for(ex = maxe - 1; ex >= 1; --ex) {
		if(m < (1LL << ex))
			continue;
		LL low = 2, upp;
		for(upp = low << 1; int_pow(upp, ex, m) <= m; upp <<= 1);
		while(low < upp) {
			LL mid = (low + upp + 1) >> 1;
			if(int_pow(mid, ex, m) <= m) {
				low = mid;
			} else {
				upp = mid - 1;
			}
		}
		if(int_pow(low, ex, m) == m) {
			pr = low;
			break;
		}
	}
	assert(ex >= 1 && miller_rabin(pr));
	phi = m - m / pr;
	if(sp % pr == 0) {
		ord = gen = -1;
		return;
	}
	ord = phi;
	vector<pair<LL, LL> > vec = factorize(pr - 1);
	if(ex > 1)
		vec.push_back(make_pair(pr, ex - 1));
	for(pair<LL, LL> it : vec)
		for( ; it.second > 0 && mod_pow(sp, ord / it.first, m) == 1; --it.second, ord /= it.first);
	if(pr == 2 && m >= 8) {
		assert((sp & 3) != 3 || !(ord & 1));
		LL half_phi = phi / 2;
		for(gen = 1; gen < m; gen += 4) {
			bool chk = mod_pow(gen, half_phi, m) == 1;
			for(pair<LL, LL> it : vec)
				chk &= mod_pow(gen, half_phi / it.first, m) != 1;
			if(chk)
				break;
		}
	} else {
		for(gen = 0; gen < m; ++gen) {
			bool chk = mod_pow(gen, phi, m) == 1;
			for(pair<LL, LL> it : vec)
				chk &= mod_pow(gen, phi / it.first, m) != 1;
			if(chk)
				break;
		}
	}
}
void solve() {
	if(n > phi - abs(ord)) {
		puts("-1");
		return;
	}
	if(ord == -1) {
		LL val = 1;
		for(int i = 1; i <= n; ++i) {
			for(++val; val < m && val % pr == 0; ++val);
			assert(val < m);
			printf("%lld%c", val, " n"[i == n]);
		}
		return;
	}
	if(pr == 2 && m >= 8 && (sp & 3) == 3) {
		LL upp = phi / 2, stp = upp / (ord / 2);
		for(LL e = 0, u = 1, v = sp; e < upp && n > 0; ++e, u = mod_mul(u, gen, m), v = mod_mul(v, gen, m))
			if(e % stp > 0) {
				printf("%lld%c", u, " n"[!(--n)]);
				if(n > 0)
					printf("%lld%c", v, " n"[!(--n)]);
			}
	} else {
		LL upp = pr == 2 ? phi / 2 : phi, stp = upp / ord;
		for(LL e = 0, v = 1; e < upp && n > 0; ++e, v = mod_mul(v, gen, m)) {
			if(e % stp > 0)
				printf("%lld%c", v, " n"[!(--n)]);
			if(n > 0 && pr == 2)
				printf("%lld%c", m - v, " n"[!(--n)]);
		}
	}
	assert(n == 0);
}
int main() {
	init();
	solve();
	return 0;
}
```
 **Solution (by quailty)**
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline ll mul_mod(ll a, ll b, ll m)
{
    a=(a%m+m)%m,b=(b%m+m)%m;
    return ((a*b-(ll)(1.0L*a/m*b+0.5L)*m)%m+m)%m;
}
inline ll pow_mod(ll a,ll k,ll m)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=mul_mod(res,a,m);
        a=mul_mod(a,a,m);
        k>>=1;
    }
    return res;
}

bool strong_pseudo_primetest(ll n,int b)
{
    ll n2=n-1,res;
    int s=0;
    while(n2%2==0)n2>>=1,s++;
    res=pow_mod(b,n2,n);
    if((res==1)|| (res==n-1))return 1;
    s--;
    while(s>=0)
    {
        res=mul_mod(res,res,n);
        if(res==n-1)return 1;
        s--;
    }
    return 0;
}
bool is_prime(ll n)
{
    static ll testNum[]={2,3,5,7,11,13,17,19,23,29,31,37};
    static ll lim[]={4,0,1373653LL,25326001LL,25000000000LL,2152302898747LL,3474749660383LL,341550071728321LL,0,0,0,0};
    if(n<2 || n==3215031751LL)return 0;
    for(int i=0;i<12;i++)
    {
        if(n<lim[i])return 1;
        if(!strong_pseudo_primetest(n,testNum[i]))return 0;
    }
    return 1;
}

inline ll func(ll x,ll n)
{
    return (mul_mod(x,x,n)+1)%n;
}
ll pollard(ll n)
{
    if(is_prime(n))return n;
    if(~n&1)return 2;
    for(int i=1;i<20;i++)
    {
        ll x=i,y=func(x,n),p=__gcd(y-x,n);
        while(p==1)x=func(x,n),y=func(func(y,n),n),p=__gcd((y-x+n)%n,n)%n;
        if(p==0 || p==n)continue;
        return p;
    }
    return 1;
}
vector<ll> factor(ll n)
{
    if(n==1)return {};
    ll x=pollard(n);
    if(x==n)return {n};
    vector<ll> res=factor(x);
    vector<ll> t=factor(n/x);
    res.insert(res.end(),t.begin(),t.end());
    return res;
}

vector<ll> solve_easy(int n,ll m)
{
    vector<ll> res;
    for(ll i=2;i<m && (int)res.size()<n;i++)
        if(__gcd(i,m)==1)res.push_back(i);
    return res;
}

bool dfs_sol(int i,int k,ull x,ull p,ull t)
{
    if(i>k)return 1;
    ull mask=(1ULL<<i)-1;
    if((t&mask)==(x&mask) && dfs_sol(i+1,k,x,p*p,t))return 1;
    if(((t*p)&mask)==(x&mask) && dfs_sol(i+1,k,x,p*p,t*p))return 1;
    return 0;
}
vector<ll> solve_even(int n,ll m,ll p,int k)///m=2^k
{
    vector<ll> res;
    for(ll i=3;i<m && (int)res.size()<n;i+=2)
        if(!dfs_sol(3,k,i,p,1))res.push_back(i);
    return res;
}

void dfs_fac(int dep,ll val,vector<pair<ll,int> > &pcnt,vector<ll> &fac)
{
    if(dep==(int)pcnt.size())
    {
        fac.push_back(val);
        return;
    }
    for(int i=0;i<=pcnt[dep].second;i++)
    {
        dfs_fac(dep+1,val,pcnt,fac);
        val*=pcnt[dep].first;
    }
}
vector<ll> solve_root(int n,ll m,ll p,vector<ll> pm)
{
    ll phi=m/pm[0]*(pm[0]-1);
    vector<ll> pphi=factor(phi);
    sort(pphi.begin(),pphi.end());
    vector<pair<ll,int> > pcnt;
    for(int i=0,j=0;i<(int)pphi.size();i=j)
    {
        while(j<(int)pphi.size() && pphi[i]==pphi[j])j++;
        pcnt.push_back({pphi[i],j-i});
    }
    pphi.erase(unique(pphi.begin(),pphi.end()),pphi.end());
    vector<ll> fac;
    dfs_fac(0,1,pcnt,fac);
    ll pmr=0;
    while(++pmr)
    {
        bool isok=(__gcd(pmr,m)==1);
        for(int i=0;i<(int)pphi.size() && isok;i++)
            isok&=(pow_mod(pmr,phi/pphi[i],m)>1);
        if(isok)break;
    }
    ll len=phi;
    for(auto &t:fac)
        if(pow_mod(p,t,m)==1)
            len=min(len,t);
    if(len==phi)return {};
    vector<ll> res;
    for(ll i=0;i<phi && (int)res.size()<n;i++)
        if(i%(phi/len))res.push_back(pow_mod(pmr,i,m));
    return res;
}

int main()
{
    int n;
    ll m,p;
    scanf("%d%lld%lld",&n,&m,&p);
    vector<ll> res;
    if(__gcd(m,p)>1)
        res=solve_easy(n,m);
    else
    {
        vector<ll> pm=factor(m);
        if(pm[0]==2 && (int)pm.size()>2)
            res=solve_even(n,m,p,(int)pm.size());
        else
            res=solve_root(n,m,p,pm);
    }
    if((int)res.size()<n)
        printf("-1n");
    else for(int i=0;i<n;i++)
        printf("%lld%c",res[i]," n"[i==n-1]);
    return 0;
}
```
