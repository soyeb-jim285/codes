# Tutorial_(en)

Thank you for taking part in our contest, we know leaves a lot to be desired. But we believe that you can find interesting among our problems.

[A. Nene's Game](../problems/A._Nene's_Game.md)
---------------------------------------------------------------

Idea: [Otomachi_Una](https://codeforces.com/profile/Otomachi_Una "Grandmaster Otomachi_Una")

 **Tutorial**Obviously, a person at place p will be kicked out if and only if p≥a1. 

Therefore, the answer is min(n,a1−1).

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
int a[105];
void solve(){
	int q,k,n;cin>>k>>q;
	for(int i=1;i<=k;i++) cin>>a[i];
	for(int i=1;i<=q;i++){
		cin>>n;
		cout<<min(a[1]-1,n)<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	int _;cin>>_;
	while(_--) solve(); 
}

```
[B. Nene and the Card Game](../problems/B._Nene_and_the_Card_Game.md)
--------------------------------------------------------------------------

Idea: [Otomachi_Una](https://codeforces.com/profile/Otomachi_Una "Grandmaster Otomachi_Una")

 **Hint**The number of pairs on each side should be the same.

 **Tutorial**For each color (in the following text, "this point" refers to the point someone got by playing a card with this color):

 * If you have both cards of this color in your hand, you will be able to get this point.
* If Nene has both cards, you will not be able to get this point.
* If you have only one card, you cannot get this point when Nene is using the following strategy:

 
> When you play one of your paired cards, Nene also plays one of her paired cards; Otherwise, Nene will have the card with the same color. She can play it and get this point.

Therefore, the answer will be the amount of pairs in your hand.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
int cnt[MAXN];
void solve() {
	int n,ans=0;
	scanf("%d",&n);
	fill(cnt+1,cnt+n+1,0);
	for(int i=1,a;i<=n;++i) scanf("%d",&a),ans+=(++cnt[a]==2);
	printf("%dn",ans);
}
signed main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
```
[C. Nene's Magical Matrix](../problems/C._Nene's_Magical_Matrix.md)
-------------------------------------------------------------------------

Idea: [Otomachi_Una](https://codeforces.com/profile/Otomachi_Una "Grandmaster Otomachi_Una")

 **Hint**When n=3, the optimal matrix is the following:

 
```cpp
1 2 3
2 2 3
3 3 3
```
 **Tutorial**The optimal matrix would be:

 
```cpp
1 2 3 ... n
2 2 3 ... n
3 3 3 ... n
..... ... n
n n n n n n
```
Construction method:

 
```cpp
for i in [n, n-1, ..., 1]:
  set the i-th column to [1, 2, ..., n];
  set the i-th row to [1, 2, ..., n];
```
This takes exactly 2n operations.

 **Proof**For the final matrix, we define f(x) as the number of elements greater or equal to x. The sum of all elements in the matrix is ∑ni=1f(i) because an element with value x will be counted x times in the formula before.

Now, we proof that f(x)≤n2−(x−1)2:

Let's rewrite the problem to make it a little simpler:

 
> You have an n×n matrix. In each operation, you can paint exactly x−1 cells white and n−(x−1) cells black in a row or a column. Proof that there will be at most n2−(x−1)2 black cells.

Try to strengthen the conclusion by stating that:

 
> For any matrix of size n×m, each operation can paint a row into x white cells and m−x black cells, or a column into y white cells and n−y black cells. No matter how we paint, the final matrix will have at most nm−xy black cells.

We will prove this by induction.

If x=m or y=n, the conclusion holds.

Otherwise, if the last operation is to paint a row, then this row has exactly m−x black cells. And, by induction, other rows will contain at most (n−1)m−x(y−1) black cells. Painting a column in the last step is similar.

Then, we have proven the conclusion above.

Since the construction above maximizes each f(x), it is the optimal answer.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
void solve(){
	int n;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) ans+=(2*i-1)*i;
	cout<<ans<<' '<<2*n<<endl;
	for(int i=n;i>=1;i--){
		cout<<"1 "<<i<<' ';
		for(int j=1;j<=n;j++) cout<<j<<' ';cout<<endl;
		cout<<"2 "<<i<<' ';
		for(int j=1;j<=n;j++) cout<<j<<' ';cout<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int _;cin>>_;
	while(_--) solve(); 
}
```
[D. Nene and the Mex Operator](../problems/D._Nene_and_the_Mex_Operator.md)
-----------------------------------------------------------------------------

Idea: [Otomachi_Una](https://codeforces.com/profile/Otomachi_Una "Grandmaster Otomachi_Una")

 **Hint**What is the answer when ai=0?

 **Tutorial**When ai=0, the sum can hit n2 with making ai=n at last. Construction:

 
```cpp
//! a function which sets a_1 ... a_k into k.
function solve(k):
  if k is 1:
    operate [1,1]
    return
  end if
  solve(k-1);
  for i in [k-2, ..., 1]:
    operate [1,i] //! this sets a_1 ... a_i into 0
    solve(i)
    //! here, a should be [i, i, ..., i, i+1, i+2, ..., k-1, 0]
  end for
  //! here, a should be [1, 2, 3, ..., k-1, 0]
  operate [1,k]
  return
```
Here, `solve(k)` will take about 2k operations.

Since doing operation [l,r] will make al,⋯,ar≤r−l+1, if for all l≤i≤r, ai is included in at least one of the operations and al−1,ar+1 are not, the optimal strategy will be setting ai=r−l+1 for i∈[l,r] using the construction above.

Finally, we can use DFS or DP to determine whether each element is included in operations.

The number of operations used will not exceed 2n.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,a[20],cnt[20];
vector <array<int,2>> I;
void oper(int l,int r) {
	fill(cnt,cnt+n+1,0);
	for(int i=l;i<=r;++i) if(a[i]<=n) ++cnt[a[i]];
	int mex=0;
	while(cnt[mex]) ++mex;
	for(int i=l;i<=r;++i) a[i]=mex;
	I.push_back({l,r});
}
void build(int l,int r) {
	if(l==r) {
		if(a[l]) oper(l,r);
		return ;
	}
	build(l,r-1);
	if(a[r]!=r-l) oper(l,r),build(l,r-1);
}
void solve() {
	scanf("%d",&n),I.clear(),memset(a,0,sizeof(a));
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	int cur=0,ans=0;
	for(int s=0;s<(1<<n);++s) {
		int tmp=0;
		for(int l=0;l<n;++l) {
			if(s&(1<<l)) {
				int r=l;
				while(r+1<n&&(s&(1<<(r+1)))) ++r;
				tmp+=(r-l+1)*(r-l+1);
				l=r;
			} else tmp+=a[l];
		}
		if(tmp>ans) ans=tmp,cur=s;
	}
	for(int l=0;l<n;++l) if(cur&(1<<l)) {
		int r=l;
		while(r+1<n&&(cur&(1<<(r+1)))) ++r;
		build(l,r),oper(l,r),l=r;
	}
	printf("%d %dn",ans,(int)I.size());
	for(auto i:I) printf("%d %dn",i[0]+1,i[1]+1);
}
signed main() {
	solve();
	return 0;
}
```
[E. Nene vs. Monsters](../problems/E2._Nene_vs._Monsters_(Hard_Version).md)
----------------------------------------------------------------------

idea: [Otomachi_Una](https://codeforces.com/profile/Otomachi_Una "Grandmaster Otomachi_Una")

 **Hint1**If three consecutive monsters have energy level 0,x,y (x,y>0), the monster with energy lever y will "die"(have energy level 0) at last.

 **Hint2**If four consecutive monsters have energy levels 0,x,y,z (x,y,z>0), what will happen to the monster z?

 **Hint3**If four consecutive monsters have energy level x,y,z,w (x,y,z,w>0), how many rounds of spells must be used to make at least one of these monsters die?

 **Tutorial**If four consecutive monsters have energy level x,y,z,w (x,y,z,w>0) and they did not die after t rounds of spells, then y will receive at least t points of damage, z will receive at least (t−1)+(t−2)+⋯=O(t2) of damage, and w will receive at least O(t3) of damage.

That is to say, let V=maxni=1ai, after O(3√V) rounds, at least one of x,y,z,w will die.

So, we can simulate the process by brute force until there are no four consecutive alive monsters, and then the problem is reduced to the one described in Hint 2.

If four consecutive monster have energy level 0,x,y,z (x,y,z>0), x will remain alive, y will die at last and sending D=(y−x)+(y−2x)+⋯+(ymodx) damage to z before that. Therefore, z will remain alive if and only if z>D.

The time complexity is O(n3√V).

Bonus: Actually, it can be shown that after O(k√V) rounds, there will be no k consecutive alive monsters. Making k bigger than 3 can further reduce the time complexity, but it will be harder to implement and optimize little on actual performance.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
const int MAXN=2e5+5;
int n,a[MAXN];bool b[MAXN];
bool check(){
	a[n+1]=a[1],a[n+2]=a[2],a[n+3]=a[3];
	for(int i=1;i<=n;i++)
		if(a[i]&&a[i+1]&&a[i+2]&&a[i+3]) return true;
	return false;
} 
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2){
		while(a[1]&&a[2]){
			a[2]=max(0,a[2]-a[1]);
			a[1]=max(0,a[1]-a[2]);
		}
		b[1]=(a[1]>0);b[2]=(a[2]>0);
	}else if(n==3){
		while(a[1]&&a[2]&&a[3]){
			a[2]=max(0,a[2]-a[1]);
			a[3]=max(0,a[3]-a[2]);
			a[1]=max(0,a[1]-a[3]);
		}
		b[1]=(!a[3]&&a[1]);
		b[2]=(!a[1]&&a[2]);
		b[3]=(!a[2]&&a[3]);
	}else{
		while(check()){
			for(int i=1;i<=n;i++) a[i%n+1]=max(0,a[i%n+1]-a[i]);
		}
		for(int i=1;i<=n;i++) b[i]=false;
		auto attack=[&](ll x,ll y){
			ll k=x/y;
			return (2*x-(k+1)*y)*k/2;
		};
		for(int p=1;p<=n;p++) 
			if(a[p]&&a[p%n+1]) a[p%n+1]=max(0,a[p%n+1]-a[p]);
			else break;
		for(int i=1;i<=n;i++) if(!a[i]&&a[i%n+1]){
			b[i%n+1]=true;
			b[(i+2)%n+1]=(a[(i+2)%n+1]>attack(a[(i+1)%n+1],a[i%n+1]));
		}
	}
	int cnt=0;
	for(int i=0;i<=n;i++) if(b[i]) cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++) if(b[i]) cout<<i<<' ';
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	int _;cin>>_;
	while(_--) solve();
}
```
[F. Nene and the Passing Game](../problems/F._Nene_and_the_Passing_Game.md)
-----------------------------------------------------------------------------

idea: [Otomachi_Una](https://codeforces.com/profile/Otomachi_Una "Grandmaster Otomachi_Una")

 **Hint**Two people i and j (i<j) can pass the ball to each other directly if and only if [i+li,i+ri]∩[j−rj,j−lj]≠∅

 **Tutorial**According to the hint above, we can build the following graph:

 * There are 2n vertices in the graph. Vertice i links to vertices ([n+i−ri,n+i−l1]∪[n+i+li,n+i+ri])∩[n+1,2n]∩Z.

That is, assuming vertices 1 to n are players, vertices n+1 to 2n are temporary spots, and player i links to all the spots where his/her arm can reach.

Then, the answer will be the number of connected components in this graph which contains at least one vertice with an index less than or equal to n.

But there's still a little problem with the solution. For two players i,j (i<j) satisfying [i+li,i+ri]∩[j+li,j+ri]≠∅ (that is, both players reaching out their "right arm"s), they are incorrectly counted as connected.

To solve that, we can delete all the vertices n+x such that ∀i, x∉[i−ri,i−li] or ∀i, x∉[i+li,i+ri] (that is, nobody's left/right arm can reach x). Finding such x can be done easily in O(n).

The last issue is, the graph contains O(n2) edges. but since we only care about connectivity, operation "link x to [y,z]" can be changed to "link x to y, and link i to i+1 for all i in [y,z−1]". After that and removing multiple edges, the number of edges is reduced to O(n).

Finally, counting connected components in a graph can be easily done in O(n), so the time complexity is O(n).

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
const int MAXN=2e6+5;
int n,tot,le[MAXN],ri[MAXN];
int fa[MAXN<<1],s[MAXN],t[MAXN],pre[MAXN],suf[MAXN];
inline int find(int x){
	while(x^fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
void solve(){
	cin>>n;
	for(int i=1;i<=2*n+1;i++) fa[i]=i;
	for(int i=0;i<=n+1;i++) s[i]=t[i]=pre[i]=suf[i]=0;
	for(int i=1;i<=n;i++){
		cin>>le[i]>>ri[i];
		s[max(1,i-ri[i])]++;s[max(0,i-le[i])+1]--;
		t[min(n+1,i+le[i])]++;t[min(n,i+ri[i])+1]--;
	}
	tot=n;
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1],t[i]+=t[i-1];
		if(s[i]&&t[i]) suf[i]=pre[i]=++tot;
	}
	suf[n+1]=0;
	for(int i=1;i<=n;i++) pre[i]=(pre[i]?pre[i]:pre[i-1]);
	for(int i=n;i>=1;i--) suf[i]=(suf[i]?suf[i]:suf[i+1]);
	for(int i=1;i<=n;i++){
		int l=max(1,i-ri[i]),r=max(0,i-le[i]);
		if(l<=r){
			l=suf[l],r=pre[r];
			if(l&&r&&l<=r) for(int i=find(l);i<r;i=find(i)) fa[i]=i+1; 
		}
		l=min(n+1,i+le[i]),r=min(n,i+ri[i]);
		if(l<=r){
			l=suf[l],r=pre[r];
			if(l&&r&&l<=r) for(int i=find(l);i<r;i=find(i)) fa[i]=i+1; 
		}
	}
	for(int i=1;i<=n;i++){
		int l=max(1,i-ri[i]),r=max(0,i-le[i]);
		if(l<=r){
			l=suf[l],r=pre[r];
			if(l&&r&&l<=r) fa[find(i)]=find(l);
		}
		l=min(n+1,i+le[i]),r=min(n,i+ri[i]);
		if(l<=r){
			l=suf[l],r=pre[r];
			if(l&&r&&l<=r) fa[find(i)]=find(l);
		}
	}
	int ans=0;
	for(int i=1;i<=tot;i++) if(fa[i]==i) ans++; 
	cout<<ans<<'n';
}
int main(){
	ios::sync_with_stdio(false);
	// freopen("Otomachi_Una.in","r",stdin);
	// freopen("Otomachi_Una.out","w",stdout);
	int _;cin>>_;
	while(_--) solve();
	return 0;
}
```
