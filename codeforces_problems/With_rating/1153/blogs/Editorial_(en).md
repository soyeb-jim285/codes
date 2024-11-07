# Editorial_(en)

[1153A - Serval and Bus](../problems/A._Serval_and_Bus.md "Codeforces Round 551 (Div. 2)")

Author: [Serval](https://codeforces.com/profile/Serval "Candidate Master Serval"), preparation: [bzh](https://codeforces.com/profile/bzh "Master bzh")

 **Editorial**Find the first bus Serval can see in each route and find the earliest one. For each route, finding the first bus Serval sees can work in O(1).

Or mark all the time no more than max(si,t+max(di)) which bus would come or there will be no bus, then search the nearest one.

[1153B - Serval and Toy Bricks](../problems/B._Serval_and_Toy_Bricks.md "Codeforces Round 551 (Div. 2)")

Author: [Serval](https://codeforces.com/profile/Serval "Candidate Master Serval"), Preparation: [bzh](https://codeforces.com/profile/bzh "Master bzh")

 **Editorial**Fill in all the bricks, and then remove all bricks you must remove (which in some view, there is empty). This can be solved in O(nm).

[1153C - Serval and Parenthesis Sequence](../problems/C._Serval_and_Parenthesis_Sequence.md "Codeforces Round 551 (Div. 2)")

Author & preparation: [Serval](https://codeforces.com/profile/Serval "Candidate Master Serval")

 **Editorial**First let `(` be +1, `)` be −1 and `?` be a missing place, so we will replace all the missing places in the new +1,−1 sequence by +1 and −1.

Obviously, for each prefix of a correct parenthesis sequence, the sum of the new +1,−1 sequence is not less than 0. And for the correct parenthesis sequence itself, the sum of the new sequence should be 0. So we can calculate how many +1 (let a denotes it) and how many −1 (let b denotes it) that we should fill in the missing places.

According to the problem, our goal is to fill the missing place with +1 and −1 to make sure there is no strict prefix (prefixes except the whole sequence itself) exists with the sum equal to 0. This can be solved in greedy. We want the sum of prefixes as large as possible to avoid the sum touching 0. So let the first a missing places be filled with +1 and the last b missing places be filled with −1.

Check it whether it is a correct parenthesis sequence or not at last. The complexity is O(n).

[1153D - Serval and Rooted Tree](../problems/D._Serval_and_Rooted_Tree.md "Codeforces Round 551 (Div. 2)")

Author & preparation: [bzh](https://codeforces.com/profile/bzh "Master bzh")

 **Editorial**If we want to check whether x is the answer (I didn't say I want to do binary search), then we can set all the numbers no less than x as 1, and the numbers less than x as 0. Then we can use dpi to represent that the maximum number on node i is the dpi-th smallest number of leaves within subtree of i. There should be at least dpi ones in the subtree of i such that the number on i is one. Then k+1−dp1 is the final answer. Complexity O(n).

 **Code**
```cpp
#include <cstdio>
using namespace std;
struct node{
	int to;
	node *next;
};
int i,j,m,n,a[1000005],f[1000005],dp[1000005],deg[1000005],k;
node *nd[1000005];
void addd(int u,int v){
	node *p=new node();
	p->to=v;
	p->next=nd[u];
	nd[u]=p;
}
void dfs(int u){
	node *p=nd[u];
	if ((u>1)&&(deg[u]==1)){//note that u>1
		dp[u]=1;
		k++;
		return;
	}
	if (a[u]) dp[u]=1000000000;
	else dp[u]=0;
	while(p){
		dfs(p->to);
		if (a[u]){
			if (dp[p->to]<dp[u]) dp[u]=dp[p->to];
		}else{
			dp[u]+=dp[p->to];
		}
		p=p->next;
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=2;i<=n;i++){
		scanf("%d",&f[i]);
		deg[i]++;
		deg[f[i]]++;
		addd(f[i],i);
	}
	dfs(1);
	printf("%dn",k+1-dp[1]);
	return 0;
}
```
 **Another Solution**We can solve this problem in greedy. At first we use leafu to represent the number of leaves in the subtree whose root is u, and fu to represent the maximum number we can get on the node u. Note that since we are concidering the subtree of u, we just number those leafu nodes from 1 to leafu, and fu is between 1 and leafu, too.

Let's think how to find the maximum number a node can get.

 1. If the operation of the node u we concerned is max, for all the nodes v whose father or parent is u, we can find the minimum leafv−fv. Let vmin denotes the node reaches the minimum. And we can construct an arrangement so that the number written in the node u can be leafu−(leafvmin−fvmin). When we number the leaves in the subtree of u from 1 to leafu, we number the leaves in other subtrees of children of u first, and then number the leaves in subtree of vmin. It can be proved this arrangement is optimal.
2. If the operation of the node u is min, we can construct an arrangement of the numbers written in the leaves to make the number written in u be as large as possible. For all sons or children v of u, we number the first fv−1 leaves in subtree of v first according to the optimal arrangement of the node v. And then no matter how we arrange the remaining numbers, the number written in u is 1+∑v is a son of u(fv−1). This is the optimal arrangement.

We can use this method and get the final answer f1.

 **Code for Another Solution**
```cpp
#include <cstdio>
using namespace std;
const int N=1000005;
int n,p;
int h[N],nx[N];
int t[N],sz[N];
void getsize(int u)
{
	if (!h[u])
		sz[u]++;
	for (int i=h[u];i;i=nx[i])
	{
		getsize(i);
		sz[u]+=sz[i];
	}
}
int getans(int u)
{
	if (!h[u])
		return 1;
	int ret=0,tmp;
	if (t[u])
	{
		for (int i=h[u];i;i=nx[i])
		{
			tmp=getans(i)+sz[u]-sz[i];
			if (tmp>ret)
				ret=tmp;
		}
		return ret;
	}
	for (int i=h[u];i;i=nx[i])
		ret+=getans(i)-1;
	return ret+1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		nx[i]=h[p];
		h[p]=i;
	}
	getsize(1);
	printf("%dn",getans(1));
	return 0;
}
```
[1153E - Serval and Snake](../problems/E._Serval_and_Snake.md "Codeforces Round 551 (Div. 2)")

Authors & preparation: [Serval](https://codeforces.com/profile/Serval "Candidate Master Serval"), [bzh](https://codeforces.com/profile/bzh "Master bzh")

 **Editorial**If the answer to a rectangle is odd, there must be exactly one head or tail in that rectangle. Otherwise, there must be even number (0 or 2) of head and tail in the given rectangle.

We make queries for each of the columns except the last one, then we can know for each column whether there are odd number of head and tails in it or not. Because the sum is even, we can know the parity of the last column.

If the head and tail are in different columns, we can find two columns with odd answer and get them. Then we can do binary search for each of those two columns separately and get the answer in no more than 999+10+10=1019 queries totally. 

If the head and tail are in the same column, we will get all even answer and know that fact. Then we apply the same method for rows. Then we can just do binary search for one of the rows, and use the fact that the other is in the same column as this one. In this case, we have made no more than 999+999+10=2008 queries.

 **Bonus: How to save more queries?**How to save one more query? We first make queries for row 2 to row n−1. If we find any ones, make the last query for row, and use the method above. If we cannot find any ones, we make n−1 queries for columns. If none of them provide one, we know that for row 1 and row n, there must be exactly one head or tail in them, and they are in the same column. In this case, we do binary search for one of the rows, then the total number of queries is 998+999+10=2007.

If we can find two ones in the columns, we know that: if one of them is in row 2 to row n−1, the other must be in the same row, because for row 2 to row n, we know that there are even number of head and tails, and them can't appear in the other columns. Then we do binary search, when we divide the length into two halves, we let the one close the the middle to be the longer one, and the one close to one end to be the shorter one. Then, if it turns out that, the answer is in row 1 (or row n), the number of queries must be logn rounded down, and we can use one more query to identify, whether the head or tail in the other column is in row 1 or row n. If it turns out that, the answer is in one of the rows in row 2 to row n, we may used logn queries rounded up, but in this case, we don't need that extra query. So the total number of queries is 999+998+9+1=2007 (or 999+998+10=2007).

In fact, if the interactor is not adaptive and we query for columns and rows randomly, we can use far less than 2007 queries. And if we query for rows and columns alternatively, we can save more queries.

[1153F - Serval and Bonus Problem](../problems/F._Serval_and_Bonus_Problem.md "Codeforces Round 551 (Div. 2)")

Author: [Serval](https://codeforces.com/profile/Serval "Candidate Master Serval"), preparation: [Serval](https://codeforces.com/profile/Serval "Candidate Master Serval"), [bzh](https://codeforces.com/profile/bzh "Master bzh")

 **Editorial**Without loss of generality, assume that l=1. For a segment covering, the total length of the legal intervals is the probability that we choose another point P on this segment randomly such that it is in the legal intervals. Since all 2n+1 points (P and the endpoints of each segment) are chosen randomly and independently, we only need to find the probability that point P is in the legal intervals. Note that only the order of these 2n+1 points make sense. Because the points are chosen in the segment, the probability that some of them coincide is 0, so we can assume that all points do not coincide.

Now the problem is, how to calculate the number of arrangements that P is between at least k pairs of endpoints. It can be solved by dynamic programming in time complexity of O(n2). We define f(i,j,x) as the number of arrangements for the first i positions, with j points haven't been matched, and P appeared x times (obviously x=0 or 1). So we can get three different types of transition for the i-th position below:

 * Place P at i-th position (if j≥k): f(i−1,j,0)→f(i,j,1)
* Start a new segment (if i+j+x<2n): f(i−1,j−1,x)→f(i,j,x)
* Match a started segment, note that we have j choices of segments: f(i−1,j+1,x)×(j+1)→f(i,j,x)

Then f(2n+1,0,1) is the number of legal arrangements. Obviously, the total number of arrangements is (2n+1)!. However, there are n pairs of endpoints whose indices can be swapped, and the indices n segments can be rearranged. So the final answer is f(2n+1,0,1)×n!×2n(2n+1)!.

 **Code**
```cpp
#include <cstdio>
using namespace std;
const int mod=998244353;
const int N=4005;
const int K=2005;
int n,k,l;
int fac,ans;
int f[N][K][2];
int fpw(int b,int e=mod-2)
{
	if (!e)
		return 1;
	int ret=fpw(b,e>>1);
	ret=1ll*ret*ret%mod;
	if (e&1)
		ret=1ll*ret*b%mod;
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&k,&l);
	f[0][0][0]=1;
	for (int i=1;i<=2*n+1;i++)
		for (int j=0;j<=n;j++)
			for (int x=0;x<=1;x++)
				if (f[i-1][j][x])
				{
					if (j)
						f[i][j-1][x]=(f[i][j-1][x]+1ll*f[i-1][j][x]*j)%mod;
					if (i+j-1<2*n+x)
						f[i][j+1][x]=(f[i][j+1][x]+f[i-1][j][x])%mod;
					if (j>=k&&!x)
						f[i][j][1]=(f[i][j][1]+f[i-1][j][x])%mod;
				}
	fac=1;
	for (int i=n+1;i<=2*n+1;i++)
		fac=1ll*fac*i%mod;
	ans=f[2*n+1][0][1];
	ans=1ll*ans*fpw(2,n)%mod;
	ans=1ll*ans*fpw(fac)%mod*l%mod;
	printf("%dn",ans);
	return 0;
}
```
**UPD:** We fixed some mistakes and added another solution for D.

