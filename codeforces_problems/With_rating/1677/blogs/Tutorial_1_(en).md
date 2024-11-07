# Tutorial_1_(en)

[1678A - Tokitsukaze and All Zero Sequence](https://codeforces.com/contest/1678/problem/A "Codeforces Round 789 (Div. 2)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Expert tokitsukaze")   
 Prepare: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Expert tokitsukaze")

 **Tutorial**We observe that when there is 0 in the sequence, it is optimal to choose 0 and any number other than 0 for each operation.

Therefore, when there is 0 in the sequence, let cnt be the number of 0s, the answer is n−cnt.

Otherwise, when 0 does not exist in the sequence, there are two situations:

 1. When there exist two equal numbers in the sequence, we can perform the operation 1 time to convert it into the situation of having 0 in the sequence. So the answer must be n.
2. When all numbers in the sequence are distinct, we can perform the operation 2 times to convert it into the situation of having 0 in the sequence. So the answer must be n+1.
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> a(n);
		for(int i=0;i<n;i++)
			scanf("%i",&a[i]);
		sort(a.begin(),a.end());
		int zero=count(a.begin(),a.end(),0);
		if(zero>0)
			printf("%in",n-zero);
		else{
			bool same=false;
			for(int i=1;i<n;i++)
				if(a[i]==a[i-1])
					same=true;
			if(same)printf("%in",n);
			else printf("%in",n+1);
		}
	}
	return 0;
}
```
 **Feedback*** Good problem 


[*356*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*60*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")
[1678B1 - Tokitsukaze and Good 01-String (easy version)](https://codeforces.com/contest/1678/problem/B1 "Codeforces Round 789 (Div. 2)") and [1678B2 - Tokitsukaze and Good 01-String (hard version)](https://codeforces.com/contest/1678/problem/B2 "Codeforces Round 789 (Div. 2)")

Idea: [qsmcgogo](https://codeforces.com/profile/qsmcgogo "Master qsmcgogo")-B1, [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR")-B2   
 Prepare: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Expert tokitsukaze")

 **Tutorial(greedy)**Obviously, the operation is, for each pair of adjacent and unequal characters, change both of them to 0 or 1. In other words, the string is divided into many adjacent binaries with length of 2. If the binary is "01" or "10", it needs 1 operation, otherwise the operation is not required.

If you want to minimize the number of "contiguous segments", a simple greedy way is to change each "binary requiring operation" (i.e. 01 or 10) into the form of the previous or next "binary requiring no operation" (i.e. 11 or 00). For example: "0010" change to "0000" and "1101" change to "1111". In this way, this "binary requiring operation" has no contribution to the final number of contiguous segments. We only need to count the number of contiguous "11" and "00" binaries.

In particular, if all binaries are "01" or "10", the final contribution to the number of final contiguous segments is 1 in total.

 **Tutorial(DP)**Obviously, the operation is, for each pair of adjacent and unequal characters, change both of them to 0 or 1. In other words, the string is divided into many adjacent binaries with length of 2.

Consider the recursion from the front to the back, it can be observed that the previously maintained prefix must end with "00" or "11". Therefore, it's necessary to convert each divided binary into "00" or "11" by enumerating the cost of changing the current binary into "00" and "11". Maintain the minimum number of operations in the process of DP, try to make the current string consistent with the end of the prefix subsegment.

dp[n][2], set the first dimension as the maintained length of prefix and the second dimension as the suffix state of the prefix.

Then the DP transfer equation is:

 dp[i][0]=min(dp[i−2][0]+{c0,0},dp[i−2][1]+{c0,1}) dp[i][1]=min(dp[i−2][0]+{c1,1},dp[i−2][1]+{c1,0})where ck represents the cost of converting the current binary to "kk".

 **Solution(greedy)**
```cpp
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, L = -1, x = 0, y = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) x += 1;
            else {
                if (L != s[i]) y += 1;
                L = s[i];
            }
        }
        cout << x << " " << max(y, 1) << "n";
    }
}
```
 **Solution(DP)**
```cpp
#include<bits/stdc++.h>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define lowit(x) (x&-x)

#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

#define sto                             
    std::ios::sync_with_stdio(false);   
    std::cin.tie(nullptr);              
    std::cout.tie(nullptr);
    
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;

inline ll read(){
	ll x=0;char ch;bool f=true;
	for(ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')f^=f;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return f?x:-x;
}
//#define LOCAL_DEFINE
#define DEBUG(x) cerr<<(#x)<<'='<<(x)<<endl
const int N=2e5+7;
const int INF=1e9;
char s[N];
int c[N];
PII dp[N][2];
void solve(){
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)s[i]-='0';
	for(int i=1;i<=n/2;i++)c[i]=s[i*2]+s[i*2-1]*2;
	for(int i=1;i<=n/2;i++)for(int j=0;j<2;j++)dp[i][j]={INF,INF};
	for(int i=1;i<=n/2;i++)for(int j=0;j<2;j++){
		int cc=c[i],dd=j?3:0,cnt=((dd%2)^(cc%2))+((dd/2)^(cc/2));
		for(int k=0;k<2;k++)
			dp[i][j]=min(dp[i][j],{dp[i-1][k].first+cnt,dp[i-1][k].second+(j!=k)});
	}
	PII ans=min(dp[n/2][0],dp[n/2][1]);
	cout<<ans.first<<" "<<ans.second+1<<"n";
}

int main(){
	#ifdef ONLINE_JUDGE
	#else	
		//fre("1");
	#endif
	ll T=1;
	T=read();
	for(int i=1;i<=T;i++)solve();
	#ifdef LOCAL_DEFINE
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.n";
	#endif
	return 0;
}
```
 **Feedback-B1*** Good problem 

 
[*601*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*74*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")
 **Feedback-B2*** Good problem 

 
[*407*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*542*](https://codeforces.com/data/like?action=like "I like this")
[1677A - Tokitsukaze and Strange Inequality](../problems/A._Tokitsukaze_and_Strange_Inequality.md "Codeforces Round 789 (Div. 1)")

Idea: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Expert tokitsukaze")   
 Prepare: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Expert tokitsukaze")

 **Tutorial**We can calculate the answer in two steps.

The first step, for each b, let fb represents the number of pd where pb>pd in the interval [b+1,n]. We can calculate f in O(n2).

The second step, calculate the answer. First we enumerate c from 1 to n, and then enumerate a from 1 to c−1. When pa<pc, add fb in the interval [a+1,c−1] to the answer. Before enumerating a, we can calculate the prefix sum of f first, so we can add the fb in the interval to the answer in O(1). The time complexity of this step is O(n2). However, this will add the result of d in the interval [a+1,c−1] to the answer, which is illegal because c<d is required. So we need to maintain f while enumerating c: enumerate b from 1 to c−1, if pb>pc, fb minus 1. pc is actually regarded as pd, that is, subtract the case where c is equal to d, so as to subtract the illegal case. The time complexity of this step is also O(n2).

Time complexity:O(n2).

By the way, use Fenwick Tree or Segment Tree can also pass, the time complexity is O(n2log n)

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
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
typedef vector<PII > VPII;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," n"[i==r]);}
/*************** IO end  ***************/
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
int a[MAX];
ll f[MAX],bitf[MAX];
void go()
{
	int n,i,j,k,l,T;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		mem(f,0);
		for(j=1;j<=n;j++)
		{
			for(l=j+1;l<=n;l++)
			{
				if(a[j]>a[l]) f[j]++;
			}
		}
		ans=0;
		for(k=1;k<=n;k++)
		{
			for(j=1;j<k;j++)
			{
				if(a[j]>a[k]) f[j]--;
			}
			bitf[0]=0;
			for(i=1;i<=k;i++) bitf[i]=bitf[i-1]+f[i];
			for(i=1;i<k;i++)
			{
				if(a[i]<a[k]) ans+=bitf[k-1]-bitf[i];
			}
		}
		printf("%lldn",ans);
	}
}


```
 **Feedback*** Good problem 

 
[*481*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*89*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*235*](https://codeforces.com/data/like?action=like "I like this")
[1677B - Tokitsukaze and Meeting](../problems/B._Tokitsukaze_and_Meeting.md "Codeforces Round 789 (Div. 1)")

Idea: [funer](https://codeforces.com/profile/funer "Candidate Master funer")   
 Prepare: [tokitsukaze](https://codeforces.com/profile/tokitsukaze "Expert tokitsukaze"), [funer](https://codeforces.com/profile/funer "Candidate Master funer")

 **Tutorial**Obviously, we can calculate the answers of rows and columns separately.

For the answers of columns, we can observe that since there are only n⋅m students in total, no students will leave, and every time a new student entering the meeting hall, all columns will move one step to the right circularly, so the answer will not decrease. If the i-th student is a serious student, for all the previous students with subscript j where 0<j<i, and j%m=i%m are naughty students, the answer in the column will increase by 1.

For the answer of rows, we can transfer it from the answer of i−m, which is equivalent to adding a new row to the answer of i−m. Suppose the last serious student is the j-th student. If i−j<m, the answer will increase by 1, otherwise the answer will be the same as that of when the i−m student enters the meeting hall.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int rownum[1000100];
int col[1000100];
int n,m;
void init(){
	for(int i = 0;i <= max(n,m);i++) {
		rownum[i] = col[i] = 0;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	init();
	int las = -n*m;
	int colnum = 0;
	char tmp;
	for(int i = 0;i < n*m;i++) {
		scanf(" %c",&tmp);
		tmp -= '0';
		if(tmp == 1) {
			las = i;
			if(col[i%m] == 0) {
				col[i%m] = 1;
				colnum++;
			}
		}
		if(i - las < m) {
			rownum[i%m]++;
		}
		if(i!=0) printf(" ");
		printf("%d",rownum[i%m] + colnum);
		
	}
	printf("n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
} 
```
 **Feedback*** Good problem 

 
[*256*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*79*](https://codeforces.com/data/like?action=like "I like this")
[1677C - Tokitsukaze and Two Colorful Tapes](../problems/C._Tokitsukaze_and_Two_Colorful_Tapes.md "Codeforces Round 789 (Div. 1)")

Idea: [qsmcgogo](https://codeforces.com/profile/qsmcgogo "Master qsmcgogo"), [winterzz1](https://codeforces.com/profile/winterzz1 "Master winterzz1")   
 Prepare: [winterzz1](https://codeforces.com/profile/winterzz1 "Master winterzz1")

 **Tutorial**First, find the cycle directly, take out all the cycles, and then fill each cycle in the order: maximum, minimum, maximum, minimum ….

Note that when you encounter an odd cycle, the last one should be empty and fill in the middle value.

For example, in a ternary cycle, if the first and the second position are filled with 1 and 9, it can be observed that the contribution of the ternary cycle to the answer remains unchanged no matter which number between 2∼8 is filled in the middle. So this situation can be left out first, and finally fill in whatever number is left. The same to the cycles with odd sizes such as self cycles and five membered cycles, because the last number does not provide any contribution. In this way, you can directly construct a solution with the maximum score.

We notice that if we take out the numbers that has already been filled in each cycle and put them into a new cycled array h, in fact, the numbers providing contribution are only at the "peak" and "valley" points of the array. We define "peak" as the point with subscript i where hi>hi−1 and hi>hi+1, and "valley" is the point with subscript i where hi<hi−1 and hi<hi+1. Obviously, each "peak" will provide contribution of 2⋅hi, each "valley" will provide contribution of −2⋅hi. For the points which are neither "peak"s nor "valley"s, they do not provide any contribution.

In order to maximize the score, we make the larger number in the permutation "peak" and the smaller number "valley". There are ⌊CircleSize2⌋ "peak"s and "valley"s for a circle with a length of Circlesize.

So the expression of the final answer can be derived from the summation formula of the arithmetic sequence:

Let c=∑⌊CircleSize2⌋, N represents the size of the permutation, score=2c⋅(N−c).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n,col[2][MAXN],col_to_pos_1[MAXN];
long long output;
bool vis_0[MAXN];
int T,cnt;
long long c;
void dfs(int pos)
{
	if(vis_0[pos])return;
	vis_0[pos]=true;
	++cnt;
	dfs(col_to_pos_1[col[0][pos]]);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			vis_0[i]=false;
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&col[0][i]);
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&col[1][i]);
			col_to_pos_1[col[1][i]]=i;
		}
		c=0;
		for(int i=1;i<=n;++i)
		{
			cnt=0;
			dfs(i);
			c+=cnt/2;
		}
		printf("%lldn", (c*(n-c))<<1);
	}
	
	return 0;
}
```
 **Feedback*** Good problem 

 
[*191*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*58*](https://codeforces.com/data/like?action=like "I like this")
[1677D - Tokitsukaze and Permutations](../problems/D._Tokitsukaze_and_Permutations.md "Codeforces Round 789 (Div. 1)")

Idea: [dark_light](https://codeforces.com/profile/dark_light "Grandmaster dark_light"), [FreshP_0325](https://codeforces.com/profile/FreshP_0325 "International Master FreshP_0325")   
 Prepare: [dark_light](https://codeforces.com/profile/dark_light "Grandmaster dark_light")

 **Tutorial**Consider finding out the relationship between sequence v and permutation p. It can be observed that the permutation p have bijective relationship with sequence c. That is to say, sequence c will only correspond to one permutation p, as it can be proved:

Let S=1,2,…,n, and find that the last number can be determined through cn, because there is no number after this position. We observe that pn is the (cn+1) largest number in S, then delete pn from S, we can get pn−1. So repeat the process, we can get the whole permutation.

Consider counting v, we observe that each bubble sort will first make vi=max(vi−1,0), then the whole v moves left, v1 is directly covered, vn is set to 0. Because each valued vi is preceded by a number larger than the current position, then it will definitely be exchanged and moved forward, vi minus 1. 

For example, if the current v=[0,0,2,1,1], after once bubble sort, v=[0,1,0,0,0]. 

To avoid confusion, the V array below is the v in the input. It's easy to count after knowing the above conclusion. 

For the position i(i≤k), it can be observed that after k times of bubble sort , it is directly covered, so just multiply the answer by ∏ki=1i. 

For the position i(k<i≤n), if Vi−k≠−1, then obviously vi is uniquely determined; If Vi−k=−1, then vi has i possible values, multiply the answer by i; If Vi−k=0, then vi−k≤0, multiply the answer by k+1. 

Note that for the position i(i≥n−k+1), Vi should be 0 or −1, otherwise the answer must be 0.

Complexity:O(n).

 **Solution**
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<ctime>
#include<cmath>
#include<unordered_map> 
using namespace std;
#define LL long long
#define pp pair<int,pair<int,int>>
#define mp make_pair 
#define fi first
#define se second.first
#define th second.second
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& x){
		x=0; int f=1;char c=gc();
		if(c=='-')f=-1;
		for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
		x=x*f;
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='n'){
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
using IO::pc;
int t,n,a[1000005],ans,k;
const int mod=998244353;
signed main(){
	srand(time(0));
	gi(t);
	while(t--){
		gi(n),gi(k);
		bool f=0;
		for(int i=1;i<=n;i++)gi(a[i]),f|=(a[i]>i-1);
		if(f){
			pi(0,'n');
			continue;
		}
		ans=1;
		for(int i=1;i<=k;i++)ans=1ll*ans*i%mod;
		for(int i=n-k+1;i<=n;i++){
			if(a[i]!=-1&&a[i]){
				pi(0,'n');
				f=1;
				break;
			}
		}
		if(f)continue;
		for(int i=k+1;i<=n;i++){
			int limit=i-1;
			if(a[i-k]==-1){
				ans=1ll*ans*i%mod;
			}else{
				if(a[i-k]){
					limit=a[i-k]+k;
					if(limit>i-1)f=1;
				}
				else {
					limit=min(limit,k),ans=1ll*ans*(limit+1)%mod; 
				}	
			}
		}
		if(f)ans=0;
		pi(ans,'n');
	} 
	return 0;
}
```
 **Feedback*** Good problem 

 
[*83*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*23*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
[1677E - Tokitsukaze and Beautiful Subsegments](../problems/E._Tokitsukaze_and_Beautiful_Subsegments.md "Codeforces Round 789 (Div. 1)")

Idea: [Frank_DD](https://codeforces.com/profile/Frank_DD "Master Frank_DD")   
 Prepare: [Frank_DD](https://codeforces.com/profile/Frank_DD "Master Frank_DD")

 **Tutorial**Let's sort the queries [l,r] with r in ascending order.

Let's move R from 1 to n, and answer queries [l,r] when r=R.

Use segment tree to solve this problem, each leaf node [ul,ul] in the segment tree maintenance the number that how many intervals [ul,R] are beautiful, then answering queries is to get sum. 

Use monotone stack to maintain the maximum number. When moving R one step right, the monotone stack will pop some and push one.

Let's think about the number x in monotone stack, which means the maximum number of the intervals [lp,R] (l1≤lp≤l2) is x. If there exist a ll in [l1,l2] which satisfies all∗aR=x, then before x is poped, intervals [l,rr] are beautiful(l∈[l1,l2],l≤ll ,R≤rr).

So we can assume that x will not be poped when it is pushed in the monotone stack, and do something like difference algorithm in the segment tree, by using the current R as the time stamp. Each node in the segment tree has to maintain a∗R+b,which like a linear function.

So when moving R right step, let's enumerate the factor of aR to update old intervals in monotone stack, enumerate the multiple of aR to update the new interval in monotone stack and update the intervals which are poped.

Time complexity: O(nlognlogn+qlogn).

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef pair<int,int> pp;
int n,m,ti,top,a[N],d[N],p[N],bz[N],bo[N];
long long ans[1000005];
vector<pp>q[1000005];
vector<int>w[N];
struct dd
{
	long long x,y,tg,len;
}tr[N*4];
void make(int x,int l,int r)
{
	tr[x].len=r-l+1;
	if (l==r) return;
	int mid=l+r>>1;
	make(x<<1,l,mid),make(x<<1|1,mid+1,r);
}
void down(int x)
{
	if (tr[x].x==tr[x].len)
	{
		tr[x<<1].x=tr[x<<1].len;
		tr[x<<1|1].x=tr[x<<1|1].len;
	}
	if (tr[x].x==0)
	{
		tr[x<<1].x=0;
		tr[x<<1|1].x=0;
	}
	tr[x<<1].tg+=tr[x].tg;
	tr[x<<1].y+=tr[x].tg*tr[x<<1].len;
	tr[x<<1|1].tg+=tr[x].tg;
	tr[x<<1|1].y+=tr[x].tg*tr[x<<1|1].len;
	tr[x].tg=0;
}
void up(int x)
{
	tr[x].x=tr[x<<1].x+tr[x<<1|1].x;
	tr[x].y=tr[x<<1].y+tr[x<<1|1].y;
}
void clear(int x,int l,int r,int ll,int rr)
{
	if (l>=ll && r<=rr)
	{
		tr[x].tg+=ti;
		tr[x].y+=ti*tr[x].len;
		tr[x].x=0;
		return;
	}
	down(x);
	int mid=l+r>>1;
	if (ll<=mid) clear(x<<1,l,mid,ll,rr);
	if (rr>mid) clear(x<<1|1,mid+1,r,ll,rr);
	up(x);
}
void add(int x,int l,int r,int ll,int rr)
{
	if (l>=ll && r<=rr)
	{
		tr[x].tg-=ti;
		tr[x].x=tr[x].len;
		tr[x].y-=ti*tr[x].len;
		return;
	}
	down(x);
	int mid=l+r>>1;
	if (ll<=mid) add(x<<1,l,mid,ll,rr);
	if (rr>mid) add(x<<1|1,mid+1,r,ll,rr);
	up(x);
}
long long find(int x,int l,int r,int ll,int rr)
{
	if (l>=ll && r<=rr) return tr[x].y+ti*tr[x].x;
	down(x);
	int mid=l+r>>1;
	long long ans=0;
	if (ll<=mid) ans+=find(x<<1,l,mid,ll,rr);
	if (rr>mid) ans+=find(x<<1|1,mid+1,r,ll,rr);
	return ans;
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),bz[a[i]]=i;
	for (int i=1;i<=m;i++) 
	{
		int l,r;
		scanf("%d%d",&l,&r);
		q[r].emplace_back(l,i);
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
		w[j].emplace_back(i);
	make(1,1,n);
	for (int i=1;i<=n;i++)
	{
		while (top && a[d[top]]<a[i])
		{
			if (p[top]>d[top-1]) clear(1,1,n,d[top-1]+1,p[top]);
			bo[d[top]]=0;
			top--;
		}
		for (int j=a[i];j<=n;j+=a[i])
		if (bo[bz[j]])
		{
			int pt=bo[bz[j]];
			int l=d[pt-1]+1,r=d[pt];
			int e=bz[j/a[i]];
			if (e<l || e>=i) continue;
			e=min(e,r);
			if (e<=p[pt]) continue;
		//	if (l<=p[pt]) clear(1,1,n,l,p[pt]);
			add(1,1,n,p[pt]+1,e);
			p[pt]=e;
		}
		d[++top]=i;
		bo[i]=top;
		p[top]=d[top-1];
		for (auto j:w[a[i]])
		{
			int l=d[top-1]+1,r=i;
			int e1=bz[j],e2=bz[a[i]/j];
			if (e2<=e1) continue;
			if (e1<l || e2>i) continue;
			if (e1<=p[top]) continue;
		//	if (l<=p[top]) clear(1,1,n,l,p[top]);
			add(1,1,n,p[top]+1,e1);
			p[top]=e1;
		}
		ti++;
		for (auto t:q[i]) ans[t.second]=find(1,1,n,t.first,i);
	}
	for (int i=1;i<=m;i++) printf("%lldn",ans[i]);	
	return 0;
}
```
 **Feedback*** Good problem 

 
[*34*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*87*](https://codeforces.com/data/like?action=like "I like this")
[1677F - Tokitsukaze and Gems](../problems/F._Tokitsukaze_and_Gems.md "Codeforces Round 789 (Div. 1)")

Idea: [dark_light](https://codeforces.com/profile/dark_light "Grandmaster dark_light")   
 Prepare: [dark_light](https://codeforces.com/profile/dark_light "Grandmaster dark_light")

 **Tutorial**First, consider how to calculate the contribution of a legal path. It can be found that the contribution of a legal path is equivalent to the following formula, where bi indicates the number of the i-th gems on the path.

 ∑b1i1=0∑b2i2=0…∑bnin=0(∑nj=1(Pijikj)×∑nj=1[ij≠0])This formula seems impossible to calculate, but it can be observed that there is a chain structure behind it. Consider dynamic programming, try to calculate the 1∼(i+1)-th gems' answer by only considering the 1∼i-th gems' answer. Consider maintenance these:

dpn,1=∑b1i1=0∑b2i2=0…∑bnin=0(∑nj=1(Pijikj)×∑nj=1[ij≠0])

dpn,2=∑b1i1=0∑b2i2=0…∑bnin=0∑nj=1(Pijikj)

dpn,3=∑b1i1=0∑b2i2=0…∑bnin=0∑nj=1[ij≠0]

dpn,4=∑b1i1=0∑b2i2=0…∑bnin=01

It can be observed that if we enumerate how many the (n+1)-th gem are selected, this can actually be transferred, for example:

dpn+1,1=∑bn+1p=0∑b1i1=0∑b2i2=0…∑bnin=0((∑nj=1Pijikj+Pppk)×(∑nj=1[ij≠0])+[p≠0])

Then spread.

A=∑bn+1p=0∑b1i1=0∑b2i2=0…∑bnin=0(∑nj=1Pijikj×∑nj=1[ij≠0])=(1+bn+1)dpn,1

B=∑bn+1p=0∑b1i1=0∑b2i2=0…∑bnin=0∑nj=1Pijikj[p≠0]=bn+1dpn,2

C=∑bn+1p=0∑b1i1=0∑b2i2=0…∑bnin=0Pppk×∑nj=1[ij≠0]=dpn,3×∑bn+1p=0Pppk=dpn,3×∑bn+1p=1Pppk

D=∑bn+1p=0∑b1i1=0∑b2i2=0…∑bnin=0(Pppk)×[p≠0]=dpn,4×∑bn+1p=1Pppk

Now it can be transferred. The main problem is how to calculate ∑ni=1ikxi quickly, ensuring that x>1.

Let hk,n represent ∑ni=1ikxi.

Calculate the sum according to the proportional sequence, h0,n=xn+1−xx−1.

 xhk,n−hk,n=∑ni=1xi+1ik−∑ni=1xiik =xn+1nk+∑ni=1xi((i−1)k−ik) =xn+1nk+∑ni=1xi([∑kj=0(−1)k−j(kj)ij]−ik) =xn+1nk+∑k−1i=0(−1)k−j(kj)hi,nFinally we get

 hk,n=xn+1nk+∑k−1i=0(−1)k−j(kj)hi,nx−1According to this recurrence formula, we can get

 h0,n=xn+1(1x−1)−x×(1x−1) h1,n=xn+1(nx−1−1(x−1)2)−x(−1(x−1)2)When k is constant, there exist a k-degree polynomial gk(x) about n, making hk,n=xn+1gk(n)−xgk(0). This conclusion can be proved by mathematical induction.

Consider how to use interpolation to get this polynomial, we only need to find gk(0)∼gk(k).

Consider difference method, hk,n−hk,n−1=xn+1gk(n)−xngk(n−1)=nkxn.

So xgk(n)−gk(n−1)=nk. But we still can't get C. There is a conclusion: the (n+1)-th difference of the n-degree polynomial f(x) is 0. That is to say, ∑n+1i=0(−1)n+1−i(n+1i)f(i)=0.

So we can get gk(0), then use polynomial fast interpolation, and then polynomial multipoint evaluation to get the value of every point we need.

It can be observed that the DP transfer can be replaced by matrix, so there are matrices each position, the problem is equivalent to get the sum of the matrix products of all intervals. It's easy to solve. You can solve it in the way you like.

Overall complexity: O(klog2k+n).

 **Solution**
```cpp
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<assert.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define int long long
const int MAXN=4e5+5;
const int MAXNN=1e5+5;
int n,k,P,fac[MAXN],ifac[MAXN],Inv[MAXN],rev[MAXN],x[MAXN],y[MAXN],K[MAXN],B[MAXN],g[MAXN],F[MAXN],Q[MAXN],val[MAXN]; 
int a[MAXNN],b[MAXNN],W[21][MAXN*2];
const int mod=998244353;
vector<int>G[MAXNN];
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int dec(int a,int b){return ((a-b)%mod+mod)%mod;}
inline int add(int a,int b){return ((a+b)%mod+mod)%mod;}
inline int qkpow(int a,int b){
	int ans=1,base=a;
	while(b){
		if(b&1)ans=mul(ans,base);
		base=mul(base,base);
		b>>=1;
	}
	return ans;
}
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& x){
		x=0; char c=gc();
		for(;c<'0'||c>'9';c=gc());
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='n'){
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
using IO::pc;
const int S=4;
struct Matrix{
	int a[4][4];
	Matrix(){memset(a,0,sizeof a);}
	void clear(){memset(a,0,sizeof a);}
	void init(){for(int i=0;i<S;i++)a[i][i]=1;}
	int* operator [] (int x){return a[x];}
	Matrix friend operator +(Matrix A,Matrix B){
		Matrix ret=Matrix();
		for(int i=0;i<S;i++)
			for(int j=0;j<=i;j++)
				ret[i][j]=add(A[i][j],B[i][j]);	
		return ret;
	}
	Matrix friend operator -(Matrix A,Matrix B){
		Matrix ret=Matrix();
		for(int i=0;i<S;i++)
			for(int j=0;j<=i;j++)
				ret[i][j]=dec(A[i][j],B[i][j]);	
		return ret;
	}
	Matrix friend operator *(Matrix A,Matrix B){
		Matrix ret=Matrix();
		for(int k=0;k<S;k++)
			for(int j=0;j<=k;j++)
				if(B[k][j])
					for(int i=k;i<S;i++)
						ret[i][j]=1ll*(ret[i][j]+1ll*A[i][k]*B[k][j])%mod;	
		return ret;
	}
	Matrix friend operator *(Matrix A,int x){
		Matrix ret=Matrix();
		for(int i=0;i<S;i++)
				for(int j=0;j<=i;j++)
					ret[i][j]=1ll*A[i][j]*x%mod;
		return ret;
	}
}d[MAXNN],dp[MAXNN],ans;
Matrix operator += (Matrix &p,Matrix q){return p=p+q;}
Matrix operator -= (Matrix &p,Matrix q){return p=p-q;}
Matrix operator *= (Matrix &p,Matrix q){return p=p*q;}
inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void init(){
	fac[0]=ifac[0]=Inv[0]=Inv[1]=1;
	for(int i=1;i<MAXN;i++)fac[i]=1ll*fac[i-1]*i%mod; 
	ifac[MAXN-1]=qkpow(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
    for(int i=2;i<MAXN;i++)Inv[i]=1ll*(mod-mod/i)*Inv[mod%i]%mod;
    int wn;
    for(int i=0,x=1;x<MAXN;i++,x<<=1){
        W[i][x]=1;
        wn=qkpow(3,(mod-1)/(x<<1));
        for(int j=1;j<x;j++)W[i][x+j]=1ll*wn*W[i][x+j-1]%mod;
        wn=qkpow(wn,mod-2);
        for(int j=1;j<x;j++)W[i][x-j]=1ll*wn*W[i][x-j+1]%mod;
    } 
} 
inline void NTT(int *a,int type,int n){
    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    LL x,y;
    for(int i=1,cnt=0;i<n;cnt++,i<<=1){
        for(int j=0;j<n;j+=(i<<1)){
            for(int t=0,k=j;k<j+i;k++,t+=type){
                x=a[k],y=1ll*W[cnt][i+t]*a[k+i];
                a[k]=(x+y)%mod;
                a[k+i]=(x-y)%mod;
            }
        }
    }
    if(type==-1)for(int i=0;i<n;i++)a[i]=mul(a[i],Inv[n]);
}
void Polyinv(int *a,int *b,int len){
	static int c[MAXN];
	if(len==1){
		b[0]=qkpow(a[0],mod-2);
		return ;
	}
	Polyinv(a,b,(len+1)>>1);
	int l=0,m=(len<<1),n=1;
	for(;n<=m;n<<=1,l++);
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<len;i++)c[i]=a[i];
	for(int i=len;i<n;i++)c[i]=0;
	NTT(c,1,n),NTT(b,1,n);
	for(int i=0;i<n;i++)b[i]=1ll*(2-1ll*b[i]*c[i])%mod*b[i]%mod;
	NTT(b,-1,n);
	for(int i=len;i<n;i++)b[i]=0;
}
inline void Polydao(int *Aa,int *Bb,int len){
	Bb[len-1]=0;
	for(int i=1;i<len;i++)Bb[i-1]=1ll*i*Aa[i]%mod;
}
int init_NTT(int L){
	int l=0,m=L,n=1;
	for(;n<=m;n<<=1,l++);
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	return n;
}
void MUL(int *a,int *b,int *c,int n,int m,int lim){
	static int t1[MAXN],t2[MAXN],t3[MAXN];
	for(int i=0;i<n;i++)t1[i]=a[i];
	for(int i=0;i<m;i++)t2[i]=b[i];
	for(int i=n;i<lim;i++)t1[i]=0;
	for(int i=m;i<lim;i++)t2[i]=0;
	NTT(t1,1,lim),NTT(t2,1,lim);
	for(int i=0;i<lim;i++)t3[i]=1ll*t1[i]*t2[i]%mod;
	NTT(t3,-1,lim);
	for(int i=0;i<n+m-1;i++)c[i]=t3[i]; 
}
namespace Evaluation{
	#define ls(p) p<<1
	#define rs(p) p<<1|1
	int *T1[MAXN],*T2[MAXN],T3[MAXN],T4[MAXN],flow[MAXN*32],*now=flow;
	void clear(){now=flow;}
	inline void MUL2(int *a,int *b,int *c,int n,int m,int lim){
		static int t1[MAXN],t2[MAXN],t3[MAXN];
		for(int i=0;i<n;i++)t1[i]=a[i];
		for(int i=0;i<m;i++)t2[i]=b[i];
		reverse(t2,t2+m);
		for(int i=n;i<lim;i++)t1[i]=0;
		for(int i=m;i<lim;i++)t2[i]=0;
		NTT(t1,1,lim),NTT(t2,1,lim);
		for(int i=0;i<lim;i++)t3[i]=1ll*t1[i]*t2[i]%mod;
		NTT(t3,-1,lim);
		for(int i=m-1;i<n;i++)c[i-m+1]=t3[i]; 
	}
	void pre(int *Q,int p,int l,int r){
		T1[p]=now,now+=r-l+2;
		T2[p]=now,now+=r-l+2;
		for(int i=0;i<=r-l+1;i++)T1[p][i]=T2[p][i]=0;
		if(l==r){
			T1[p][0]=1;
			T1[p][1]=(mod-Q[l])%mod;
			return ; 
		}
		int mid=(l+r)>>1;
		pre(Q,ls(p),l,mid);
		pre(Q,rs(p),mid+1,r);
		if(r-l+1<=256){
			for(int i=0;i<=mid-l+1;i++)
				for(int j=0;j<=r-mid;j++)
					T1[p][i+j]=add(T1[p][i+j],1ll*T1[ls(p)][i]*T1[rs(p)][j]%mod);
		}else{
			int lim=init_NTT(r-l+1);
			MUL(T1[ls(p)],T1[rs(p)],T1[p],mid-l+2,r-mid+1,lim); 
		}
	}
	void Solve(int *S,int p,int l,int r){
		if(l==r){
			S[l]=T2[p][0];
			return ;
		}
		int mid=(l+r)>>1;
		int lim=init_NTT(r-l+1);
		MUL2(T2[p],T1[rs(p)],T2[ls(p)],r-l+1,r-mid+1,lim);
		MUL2(T2[p],T1[ls(p)],T2[rs(p)],r-l+1,mid-l+2,lim);
		Solve(S,ls(p),l,mid);
		Solve(S,rs(p),mid+1,r);
	}
	//opt0/1 区分多点求值/快速插值 
	void evaluation(int *F,int *Q,int *S,int n,int m,int opt){
		clear();
		static int AF[MAXN];
		n=max(n,m+1),m=max(m,n-1);
		pre(Q,1,1,m);
		if(opt){
			for(int i=0;i<n;i++)AF[i]=T1[1][i];
			reverse(AF,AF+n); 
			Polydao(AF,AF,n+1);
		}
		Polyinv(T1[1],T3,m+1);
		reverse(T3,T3+m+1);
		int lim=init_NTT(n+m+1); 
		if(!opt)MUL(F,T3,T4,n,m+1,lim);
		else MUL(AF,T3,T4,n,m+1,lim);
		for(int i=n;i<n+m;i++)T2[1][i-n]=T4[i];
		Solve(S,1,1,m);
		for(int i=1;i<=m;i++)S[i]=(1ll*S[i]*Q[i]%mod+(!opt?F[0]:AF[0]))%mod;
		for(int i=0;i<=n+m+1;i++)T3[i]=T4[i]=0;
	}
};
namespace Lagrange_Interpolation{
	#define ls(p) p<<1
	#define rs(p) p<<1|1
	int S[MAXN],*T[MAXN],flow[MAXN*32],*now=flow,tmp1[MAXN],tmp2[MAXN],e1[MAXN],e2[MAXN];
	void solve(int p,int l,int r){
		T[p]=now,now+=r-l+2;
		if(l==r){
			T[p][0]=S[l];
			return ;
		}
		int mid=(l+r)>>1;
		solve(ls(p),l,mid);
		solve(rs(p),mid+1,r);
		for(int i=0;i<mid-l+1;i++)tmp1[i]=T[ls(p)][i];
		for(int i=0;i<r-mid;i++)tmp2[i]=T[rs(p)][i];
		for(int i=0;i<r-mid+1;i++)e1[i]=Evaluation::T1[rs(p)][i];
		reverse(e1,e1+r-mid+1);
		for(int i=0;i<mid-l+2;i++)e2[i]=Evaluation::T1[ls(p)][i];
		reverse(e2,e2+mid-l+2);
		int lim=init_NTT(r-l+1); 
		MUL(tmp1,e1,e1,mid-l+1,r-mid+1,lim);
		MUL(tmp2,e2,e2,r-mid,mid-l+2,lim);
		for(int i=0;i<=r-l;i++)T[p][i]=add(e1[i],e2[i]);
	}
	void Interpolation(int *x,int *y,int *ans,int n){
		Evaluation::evaluation(x,x,S,n+1,n,1);
		for(int i=1;i<=n;i++)S[i]=1ll*y[i]*qkpow(S[i],mod-2)%mod;
		solve(1,1,n);
		for(int i=0;i<n;i++)ans[i]=T[1][i];
	}
}
void Pre(int P){
	int	invP=qkpow(P,mod-2),kk=0,bb=0;
	K[0]=1,B[0]=0;
	for(int i=1;i<=k+1;i++){
		K[i]=1ll*K[i-1]*invP%mod;
		B[i]=1ll*(B[i-1]+qkpow(i,k))*invP%mod;
		int Num=C(k+1,i);
		if(i&1)kk=dec(kk,1ll*Num*K[i]%mod),bb=dec(bb,1ll*Num*B[i]%mod);
		else kk=add(kk,1ll*Num*K[i]%mod),bb=add(bb,1ll*Num*B[i]%mod);
	} 
	kk=(kk+1),kk=(kk==mod?0:kk);
	g[0]=1ll*(mod-bb)*qkpow(kk,mod-2)%mod;
	for(int i=1;i<=k;i++)g[i]=add(1ll*g[0]*K[i]%mod,B[i]);
	for(int i=1;i<=k+1;i++)x[i]=i-1,y[i]=(g[i-1]+mod)%mod;
	Lagrange_Interpolation::Interpolation(x,y,F,k+1);
	for(int i=0;i<=k;i++)F[i]=(F[i]+mod)%mod; 
//	cout<<endl;
	for(int i=1;i<=n;i++)Q[i]=b[i];
	Evaluation::evaluation(F,Q,val,k+1,n,0);
	for(int i=1;i<=n;i++)val[i]=(val[i]+mod)%mod;
}
inline void makeit(int Id,int y,Matrix& S){
	//[S1S2,S1,S2,product of b]
	int X=dec(1ll*qkpow(P,y+1)*val[Id]%mod,1ll*P*g[0]%mod);
	S.a[0][0]=add(y,1),S.a[1][0]=y,S.a[2][0]=X,S.a[3][0]=X;
	S.a[1][1]=add(y,1),S.a[3][1]=X;
	S.a[2][2]=add(y,1),S.a[3][2]=y; 
	S.a[3][3]=add(y,1);
} 
signed main(){
	gi(n),gi(k),gi(P);
	init();
	for(int i=1;i<=n;i++)gi(b[i]);
	Pre(P);
	for(int i=1;i<=n;i++)makeit(i,b[i],d[i]);
	dp[1]=d[1];
	for(int i=2;i<=n;i++)dp[i]=dp[i-1]*d[i]+d[i];
	for(int i=1;i<=n;i++)ans+=dp[i];
	pi(ans.a[3][0],'n');
	return 0;
}

```
 **Feedback*** Good problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*80*](https://codeforces.com/data/like?action=like "I like this")
