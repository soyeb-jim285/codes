# Tutorial_(en)

[1307A - Cow and Haybales](../problems/A._Cow_and_Haybales.md)

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1307A - Cow and Haybales](../problems/A._Cow_and_Haybales.md "Codeforces Round 621 (Div. 1 + Div. 2)")

At any point, it is optimal to move a haybale in the closest pile from pile $1$ to the left. So, for every day, we can loop through the piles from left to right and move the first haybale we see closer. If all the haybales are in pile $1$ at some point, we can stop early.

Time Complexity: $O(n \cdot d)$

 **Solution**
```cpp
#include <iostream>
using namespace std;

int N,D,a[105];

int main(){
  int T; cin>>T;
  while (T--){
    cin>>N>>D;
    for (int i=1;i<=N;i++)
      cin>>a[i];
    while (D--){ //loop over D days
      for (int i=2;i<=N;i++)
	if (a[i]>0){ //move closest haybale over
	  a[i]--;
	  a[i-1]++;
	  break;
	}
    }
    cout<<a[1]<<endl;
  }
}
```
 **Alternative O(n) Solution:**
```cpp
#include <iostream>
using namespace std;

int N,D,a[105],ans;

int main(){
  int T; cin>>T;
  while (T--){
    cin>>N>>D;
    for (int i=1;i<=N;i++)
      cin>>a[i];
    for (int i=2;i<=N;i++){
      int move=min(a[i],D/(i-1)); //number of haybales we can move from pile i to pile 1
      a[1]+=move; //update pile 1
      D-=move*(i-1); //update remaining days
    }
    cout<<a[1]<<endl;
  }
}
```
[1307B - Cow and Friend](../problems/B._Cow_and_Friend.md)

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1307B - Cow and Friend](../problems/B._Cow_and_Friend.md "Codeforces Round 621 (Div. 1 + Div. 2)")

If the distance $d$ is in the set, the answer is $1$.

Otherwise, let $y$ denote Rabbit's largest favorite number. The answer is $max(2,\lceil \frac{d}{y}\rceil)$. This is true because clearly the answer is at least $\lceil\frac{d}{y}\rceil$: if it were less Rabbit can't even reach distance $d$ away from the origin. If $\lceil\frac{d}{y}\rceil$ is at least $2$, we can reach $(d,0)$ in exactly that number of hops by hopping to the right $\lceil\frac{d}{y}\rceil-2$ times using $y$ then using the last $2$ hops for up to $2y$ additional distance.

Time Complexity: $O(n)$

 **Solution**
```cpp
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int>a;
//you don't have to use set, it was just easier for us

int main(){
  int T; cin>>T;
  while (T--){
    int N,X;
    cin>>N>>X;
    int far=0; //largest favorite number
    for (int i=0;i<N;i++){
      int A;
      cin>>A;
      a.insert(A);
      far=max(far,A);
    }
    if (a.count(X)) //X is favorite number
      cout<<1<<endl;
    else
      cout<<max(2,(X+far-1)/far)<<endl; //expression as explained in tutorial
    a.clear();
  }
}
```
[1307C - Cow and Message](../problems/C._Cow_and_Message.md)

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1307C - Cow and Message](../problems/C._Cow_and_Message.md "Codeforces Round 621 (Div. 1 + Div. 2)")

We observe that if the hidden string that occurs the most times has length longer than $2$, then there must exist one that occurs just as many times of length exactly $2$. This is true because we can always just take the first $2$ letters; there can't be any collisions. Therefore, we only need to check strings of lengths $1$ and $2$. Checking strings of length $1$ is easy. To check strings of length $2$, we can iterate across $S$ from left to right and update the number of times we have seen each string of length $1$ and $2$ using DP.

Time Complexity: $O(|s|c)$ (c is length of alphabet)

 **Solution**
```cpp
#include <iostream>
using namespace std;

typedef long long ll;
ll arr1[26],arr2[26][26];

int main(){
  string S;
  cin>>S;
  for (int i=0;i<S.length();i++){
    int c=S[i]-'a';
    for (int j=0;j<26;j++)
      arr2[j][c]+=arr1[j];
    arr1[c]++;
  }
  ll ans=0;
  for (int i=0;i<26;i++)
    ans=max(ans,arr1[i]);
  for (int i=0;i<26;i++)
    for (int j=0;j<26;j++)
      ans=max(ans,arr2[i][j]);
  cout<<ans<<endl;
}
```
[1307D - Cow and Fields](../problems/D._Cow_and_Fields.md)

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1307D - Cow and Fields](../problems/D._Cow_and_Fields.md "Codeforces Round 621 (Div. 1 + Div. 2)")

There are a few solutions that involve breadth first search (BFS) and sorting, this is just one of them. First, let's use BFS to find the distance from fields $1$ and $n$ to each special field. For a special field $i$, let $x_i$ denote the distance to node $1$, and $y_i$ denote the distance to $n$.

We want to choose two fields $a$ and $b$ to maximize $min(x_a+y_b,y_a+x_b)$. Without loss of generality, suppose $x_a+y_b \le y_a+x_b$.

Now we want to maximize $x_a+y_b$ subject to $x_a-y_a \le x_b-y_b$. This can be done by sorting by $x_i-y_i$ and iterating $a$ over $x$ while keeping a suffix maximum array of $y$ to compute $\max_{b>a}{y_b}$.

Remember that an upper bound of the answer is the distance between field $1$ and $n$.

Time Complexity: $O(n\log{n}+m)$

 **Solution**
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>

const int INF=1e9+7;

int N;
int as[200005];

std::vector<int> edges[200005];

int dist[2][200005];
int q[200005];

void bfs(int* dist,int s){
  std::fill(dist,dist+N,INF);
  int qh=0,qt=0;
  q[qh++]=s;
  dist[s]=0;
  while(qt<qh){
    int x=q[qt++];
    for(int y:edges[x]){
      if(dist[y]==INF){
	dist[y]=dist[x]+1;
	q[qh++]=y;
      }
    }
  }
}

int main(){
  int M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<K;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  std::sort(as,as+K);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  bfs(dist[0],0);
  bfs(dist[1],N-1);
  std::vector<std::pair<int,int> > data;
  for(int i=0;i<K;i++){
    data.emplace_back(dist[0][as[i]]-dist[1][as[i]],as[i]);
  }
  std::sort(data.begin(),data.end());
  int best=0;
  int max=-INF;
  for(auto it:data){
    int a=it.second;
    best=std::max(best,max+dist[1][a]);
    max=std::max(max,dist[0][a]);
  }
  printf("%dn",std::min(dist[0][N-1],best+1));
}
```
[1307E - Cow and Treats](../problems/E._Cow_and_Treats.md)

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1307E - Cow and Treats](../problems/E._Cow_and_Treats.md "Codeforces Round 621 (Div. 1 + Div. 2)")

First, we observe that it is impossible to send more than one cow with the same favorite sweetness on the same side without upsetting any of them. This means we can send at most two cows of each favorite sweetness, one on each side.

Now, let's assume we know the index of the rightmost cow that came from the left side. 

For each sweetness $i$, we denote the number of units of grass to the left of the index as $l_i$ and to the right as $r_i$. There are three cases we have to consider. If there does not exist a cow of this favorite sweetness or the one of this favorite sweetness with minimum hunger cannot be satisfied from either direction, then $0$ cows of the type will be asleep. Otherwise, $1$ or $2$ cows will be asleep, and we can derive a simple formula based on $l_i$, $r_i$, and the cows of this type. Remember that we always maximize the number of sleeping cows first.

We maintain how much each sweetness contributed to the answer. When we shift this index of the rightmost cow to the right, we can undo and recompute our answer.

You can speed up the solution using binary search, but we chose not to require it. We also chose to allow other $O(n^2)$ and $O(n^2\log{n})$ solutions to pass.

Time Complexity: $O(n\log{n})$

 **Solution**
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

const int MOD=1e9+7;

int modexp(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int x){
  return modexp(x,MOD-2);
}

int fs[100005];
int left[100005],right[100005];
std::vector<int> cows[100005];//cows[f]: hunger of cows that like flavor f 
int asleep[100005];
int ways[100005];
int total_asleep=0,total_ways=1;

void calc_ways(int f){
  int a=std::upper_bound(cows[f].begin(),cows[f].end(),left[f])-cows[f].begin();
  int b=std::upper_bound(cows[f].begin(),cows[f].end(),right[f])-cows[f].begin();
  if(a>b) std::swap(a,b);
  long long cnt2=1LL*a*b-a;
  int cnt1=a+b;
  cnt2%=MOD;
  if(cnt2>0){
    asleep[f]=2;
    ways[f]=cnt2;
  }else if(cnt1>0){
    asleep[f]=1;
    ways[f]=cnt1;
  }else{
    asleep[f]=0;
    ways[f]=1;
  }
}

//fixed left cow, with hunger left[i]
//precondition: such cow exists
void calc_ways_stuck(int f){
  int b=std::upper_bound(cows[f].begin(),cows[f].end(),right[f])-cows[f].begin();
  if(right[f]>=left[f])
    b--;
  int cnt2=b;
  if(cnt2>0){
    asleep[f]=2;
    ways[f]=cnt2;
  }else{
    asleep[f]=1;
    ways[f]=1;
  }
}

int ans_asleep=0,ans_ways=0;

void add_to_ans(int asleep,int ways){
  if(asleep>ans_asleep){
    ans_asleep=asleep;
    ans_ways=0;
  }
  if(asleep==ans_asleep)
    ans_ways=(ans_ways+ways)%MOD;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf("%d",&fs[i]);
    right[fs[i]]++;
  }
  for(int i=0;i<M;i++){
    int F,H;
    scanf("%d %d",&F,&H);
    cows[F].push_back(H);
  }
  for(int f=1;f<=N;f++)
    std::sort(cows[f].begin(),cows[f].end());
  for(int f=1;f<=N;f++){
    calc_ways(f);
    total_asleep+=asleep[f];
    total_ways=1LL*total_ways*ways[f]%MOD;
  }
  add_to_ans(total_asleep,total_ways);
  for(int i=1;i<=N;i++){
    total_asleep-=asleep[fs[i]];
    total_ways=1LL*total_ways*inverse(ways[fs[i]])%MOD;
    right[fs[i]]--;
    left[fs[i]]++;
    if(std::binary_search(cows[fs[i]].begin(),cows[fs[i]].end(),left[fs[i]])){
      calc_ways_stuck(fs[i]);
      int here_asleep=total_asleep+asleep[fs[i]];
      int here_ways=1LL*total_ways*ways[fs[i]]%MOD;
      add_to_ans(here_asleep,here_ways);
    }
    calc_ways(fs[i]);
    total_asleep+=asleep[fs[i]];
    total_ways=1LL*total_ways*ways[fs[i]]%MOD;
  }
  printf("%d %dn",ans_asleep,ans_ways);
}
```
[1307F - Cow and Vacation](../problems/F._Cow_and_Vacation.md)

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1307F - Cow and Vacation](../problems/F._Cow_and_Vacation.md "Codeforces Round 621 (Div. 1 + Div. 2)")

We will run a BFS from all the rest stops in parallel and use union-find to determine which rest stops can reach each other directly. We will split each edge into two to simplify this process. Note that this means Bessie can now travel at most $2k$ roads before needing a rest. While we perform the BFS, we also color all nodes that are within distance $k$ from a rest stop and store the rest stop that can reach each colored node in an array. When two frontiers collide, merge them. 

Let's consider each query individually. First of all, if $a$ can reach $b$ directly, the answer is YES.

Otherwise, let's walk $a$ towards $b$ for $k$ edges, and $b$ towards $a$ for $k$ edges. Note that they may cross over $lca(a,b)$ in the process. The walks will not meet because if they did, the condition that $a$ can reach $b$ directly would have been satisfied.

Then, the answer is YES if the new $a$ is a colored node, the new $b$ is a colored node, and they both belong to the same component of rest stops which we can check from our union find.

Otherwise, the answer is NO.

Time Complexity: $O((n+v)\log{n})$

 **Solution**
```cpp
#include <cstdio>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>

const int INF=1e9+7;

std::vector<int> edges[400005];

int anc[19][400005];
int depth[400005];

void dfs(int node){
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    anc[0][child]=node;
    for(int k=1;k<19;k++){
      anc[k][child]=anc[k-1][anc[k-1][child]];
    }
    depth[child]=depth[node]+1;
    dfs(child);
  }
}

int la(int node,int len){
  for(int k=19-1;k>=0;k--){
    if(len&(1<<k)){
      node=anc[k][node];
    }
  }
  return node;
}

int lca(int a,int b){
  if(depth[a]<depth[b]) std::swap(a,b);
  a=la(a,depth[a]-depth[b]);
  if(a==b) return a;
  for(int k=19-1;k>=0;k--){
    if(anc[k][a]!=anc[k][b]){
      a=anc[k][a];
      b=anc[k][b];
    }
  }
  return anc[0][a];
}

//move x steps from a to b
//assumes x<=dist(a,b)
int walk(int a,int b,int x){
  int c=lca(a,b);
  if(x<=depth[a]-depth[c]){
    return la(a,x);
  }
  int excess=x-(depth[a]-depth[c]);
  assert(excess<=(depth[b]-depth[c]));
  return la(b,depth[b]-depth[c]-excess);
}

int uf[400005];
int dist[400005];//dist[x]=0 iff x is rest stop

int find(int a){
  while(a!=uf[a]){
    a=uf[a]=uf[uf[a]];
  }
  return a;
}

bool query(int K){
  int A,B;
  scanf("%d %d",&A,&B);
  A--,B--;
  int C=lca(A,B);
  if(depth[A]+depth[B]-2*depth[C]<=2*K){
    return true;
  }else{
    return find(walk(A,B,K))==find(walk(B,A,K));
  }
}

int main(){
  int N,K,R;
  scanf("%d %d %d",&N,&K,&R);
  int oldN=N;
  for(int i=0;i<oldN-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(N);
    edges[N].push_back(X);
    edges[Y].push_back(N);
    edges[N].push_back(Y);
    N++;
  }
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  std::fill(dist,dist+N,INF);
  std::queue<int> frontier;
  for(int i=0;i<R;i++){
    int X;
    scanf("%d",&X);
    X--;
    dist[X]=0;
    frontier.push(X);
  }
  while(!frontier.empty()){
    int x=frontier.front();
    if(dist[x]>K-1) break;
    frontier.pop();
    for(int y:edges[x]){
      uf[find(y)]=find(x);
      if(dist[y]==INF){
	dist[y]=dist[x]+1;
	frontier.push(y);
      }
    }
  }
  dfs(0);
  int V;
  scanf("%d",&V);
  while(V--){
    if(query(K)){
      printf("YESn");
    }else{
      printf("NOn");
    }
  }
}
```
[1307G - Cow and Exercise](../problems/G._Cow_and_Exercise.md)

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1307G - Cow and Exercise](../problems/G._Cow_and_Exercise.md "Codeforces Round 621 (Div. 1 + Div. 2)")

This problem can be formulated as a linear program, and looks like the LP dual of min-cost flow.

LP formulation of min-cost flow (see for example here: https://imada.sdu.dk/%7Ejbj/DM85/mincostnew.pdf):

$x_{vw}$ is flow on edge $(v,w)$

$c_{vw}$ is cost on edge $(v,w)$

$u_{vw}$ is capacity on edge $(v,w)$

$b_v$ is demand at vertex $v$ (flow in minus flow out)

Find $\min{\Sigma_{vw}c_{vw}x_{vw}}$ subject to $$\Sigma_{(v,w)\in E}(x_{wv}-x_{vw})=b_v$$ for $v\in V$

(Hopefully the signs are right.)

$$0\le x_{vw} \le u_{vw}$$ for $(v,w)\in E$

The LP Dual is

$$\max{\Sigma{b_vy_v}-\Sigma{u_{vw}z_{vw}}}$$ subject to $$y_w\le y_v+c_{vw}+z_{vw}$$ $$z_{vw}\ge 0$$ for all $(v,w)\in E$

This is exactly what we need, except the objective function is a bit messy. Letting $b_{src}=-F$, $b_{snk}=F$, $b_v=0$ for other $v$, $D=y_{snk}-y_{src}$, $C=\Sigma{vw}{u_{vw}z_{vw}}$, the objective becomes

$$\max{FD-C}$$

We have the unweighted case, so assign capacities (cost in original problem) $u_{vw}=1$ for all edges.

We can interpret $y_v$ as distance from $src$ and $z_{vw}$ as the amount added to edge edge to it.

The set of all valid assignments to the variables form a convex polytope. If we project it onto the 2D space of $D$ and $C$, it will still be convex. By varying $F$, we can get a piecewise linear function describing all Pareto optimal solutions. From this function, we can find the minimum $C$ required to get some fixed $D$ or maximum $D$ achieve by some fixed $C$.

Since a feasible solution to a min-cost flow problem is optimal iff it has no negative cost cycles, and both successive shortest path and primal-dual never create negative cycles, they maintain optimal solutions to their current min-cost flow problems, which only differs in $F$. Thus, they effectively trace out the function as $F$ varies from $0$ to maximum. By binary searching and lerping, we can answer queries in $O(\log{N})$.

(Since the cost is integral and bounded by $N$, there are at most $N$ linear pieces.)

Time Complexity: $O(n^2m+q\log{n})$

 **Solution**
```cpp
#include <cstdio>
#include <queue>
#include <vector>
#include <stdint.h>
#include <algorithm>

const long long INF=1e9+7;

const long long MAXV=50;
const long long MAXE=MAXV*(MAXV-1);

long long SRC,SNK;

long long elist[MAXE*2];
long long next[MAXE*2];
long long head[MAXV];
long long cap[MAXE*2];
long long cost[MAXE*2];
long long tot=0;

void add(long long x,long long c,long long w){
  elist[tot]=x;
  cap[tot]=c;
  cost[tot]=w;
  next[tot]=head[x];
  head[x]=tot++;
}

long long dist[MAXV];
long long prev[MAXV];
std::queue<long long> q;

long long total_cost=0;
long long total_flow=0;

int main(){
  long long N,M;
  scanf("%lld %lld",&N,&M);
  SRC=0,SNK=N-1;
  std::fill(head,head+N,-1);
  for(long long i=0;i<M;i++){
    long long A,B,C;
    scanf("%lld %lld %lld",&A,&B,&C);
    A--,B--;
    add(A,1,C);
    add(B,0,-C);
  }
  std::vector<std::pair<long long,long long> > crit;
  crit.push_back({0,0});
  while(true){
    std::fill(dist,dist+N,INF);
    dist[SRC]=0;
    prev[SRC]=-1;
    q.push(SRC);
    while(!q.empty()){
      long long node=q.front();
      q.pop();
      for(long long e=head[node];e!=-1;e=next[e]){
	long long i=elist[e^1];
	if(cap[e]){
	  if(dist[i]>dist[node]+cost[e]){
	    dist[i]=dist[node]+cost[e];
	    prev[i]=e;
	    q.push(i);
	  }
	}
      }
    }
    crit.push_back({1LL*total_flow*dist[SNK]-total_cost,dist[SNK]});
    if(dist[SNK]==INF) break;
    long long aug=INF;
    for(long long x=SNK;x!=SRC;x=elist[prev[x]]){
      aug=std::min(aug,cap[prev[x]]);
    }
    for(long long x=SNK;x!=SRC;x=elist[prev[x]]){
      cap[prev[x]]-=aug;
      cap[prev[x]^1]+=aug;
    }
    total_flow+=aug;
    total_cost+=1LL*dist[SNK]*aug;
  }
  long long Q;
  scanf("%lld",&Q);
  while(Q--){
    long long X;
    scanf("%lld",&X);
    auto it=std::lower_bound(crit.begin(),crit.end(),std::pair<long long,long long>{X+1,0});
    double D=(long double)((X-(it-1)->first)*it->second+(it->first-X)*((it-1)->second))/(it->first-(it-1)->first);
    printf("%.10lfn",D);
  }
  return 0;
}
```
