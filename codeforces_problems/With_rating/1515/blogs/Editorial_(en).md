# Editorial_(en)

[1515A - Phoenix and Gold](../problems/A._Phoenix_and_Gold.md "Codeforces Global Round 14")

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1515A - Phoenix and Gold](../problems/A._Phoenix_and_Gold.md "Codeforces Global Round 14")

Note that if the sum of all the weights is $x$, the scale will always explode and the answer will be NO. Otherwise, we claim there is always an answer.

Basically, at each point, we choose an arbitrary gold piece to add to the scale so that it doesn't explode. There is always a valid gold piece to add because the weights are distinct. 

For example, we can try adding piece $1$, $2$, $\dots$, $n$, in that order. Suppose we are currently considering the $i$-th piece. If we can add it to the scale without an explosion, we do it. If we can't, then we can just first add piece $i+1$, and then piece $i$ ($w_i \neq w_{i+1}$ because weights are distinct). $i+1$ must be less than or equal to $n$ because otherwise, the total sum of the weights would be $x$.

Time complexity for each test case: $O(n)$

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,x;
  int w[101];
  cin>>n>>x;
  int sum=0;
  for (int i=0;i<n;i++){
    cin>>w[i];
    sum+=w[i];
  }
  //if the sum is x, we cannot avoid the explosion
  if (sum==x){
    cout<<"NO"<<endl;
    return;
  }
  cout<<"YES"<<endl;
  //otherwise, the answer always exists
  //we will keep adding elements from left to right
  //if we can't add element i, we add element i+1 first by swapping the two
  for (int i=0;i<n;i++){
    if (x==w[i]){
      //i+1 will always be less than n because otherwise, the total sum would be x
      swap(w[i],w[i+1]);
    }
    cout<<w[i]<<' ';
    x-=w[i];
  }
  cout<<endl;
  return;
}

int main(){
  int T; cin>>T;
  while (T--)
    solve();
  return 0;
}
```
[1515B - Phoenix and Puzzle](../problems/B._Phoenix_and_Puzzle.md "Codeforces Global Round 14")

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1515B - Phoenix and Puzzle](../problems/B._Phoenix_and_Puzzle.md "Codeforces Global Round 14")

If $n$ can be written as $2x$ or $4x$, where $x$ is a square number, then the answer is YES. Otherwise it is NO.

To visualize this construction, we start by first building a smaller square using exactly $2$ or $4$ pieces (the drawings are in the sample test explanation). We can just use $x$ of those smaller squares to build a larger square.

Let's prove that there are no other answers (although this isn't necessary to solve the problem). Let's define each triangle piece to have a short side of length $1$ and a longer side of length $\sqrt{2}$. Consider one side of the square, and suppose that it has $a$ triangles on the short side and $b$ triangles on the longer side. The side length will be $a+\sqrt{2}b$. The area of the square is a rational number because the area of each triangle piece is rational. So, $(a+\sqrt{2}b)^2$ has to be rational, which means either $a$ is $0$, or $b$ is $0$. If either is $0$, we can use the construction in the previous paragraph.

Time complexity for each test case: $O(\sqrt{n})$ or $O(\log{n})$ (depends on how you check for square numbers)

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

bool isSquare(int x){
  int y=sqrt(x);
  return y*y==x;
}

void solve(){
  int n;
  cin>>n;
  if (n%2==0 && isSquare(n/2))
    cout<<"YES"<<endl;
  else if (n%4==0 && isSquare(n/4))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}

int main(){
  int t; cin>>t;
  while (t--)
    solve();
}
```
[1515C - Phoenix and Towers](../problems/C._Phoenix_and_Towers.md "Codeforces Global Round 14")

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1515C - Phoenix and Towers](../problems/C._Phoenix_and_Towers.md "Codeforces Global Round 14")

Greedily adding blocks to the current shortest tower will always give a valid solution. Let's prove it with contradiction. If the towers weren't beautiful, then some two towers would have a height difference of more than $x$. Since a single block cannot exceed a height of $x$, the difference would be more than one block. This is a contradiction with our solution because we always add to the shortest tower.

To implement this, we can use a set-like structure and store pairs of ($h_i$, $i$) for each $i$ ($1 \le i \le m)$, where $h_i$ is the current height of the $i$-th tower (initialized to $0$). When adding a block, we remove the first element of the sorted set, update the tower height, and add it back into the set. 

Time complexity for each test case: $O(n \log{n})$

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int N,M,X;
int H[100001];

void solve(){
  cin>>N>>M>>X;
  cout<<"YES"<<endl;
  set<pair<int,int>>s; //stores pairs of (height, index)
  for (int i=1;i<=M;i++)
    s.insert({0,i});
  for (int i=0;i<N;i++){
    cin>>H[i];
    pair<int,int>p=*s.begin();
    s.erase(p);
    cout<<p.second<<' ';
    s.insert({p.first+H[i],p.second});
  }
  cout<<endl;
}

int main(){
  int T; cin>>T;
  while (T--)
    solve();
}
```
[1515D - Phoenix and Socks](../problems/D._Phoenix_and_Socks.md "Codeforces Global Round 14")

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1515D - Phoenix and Socks](../problems/D._Phoenix_and_Socks.md "Codeforces Global Round 14")

First, let's remove all pairs that are already matching because an optimal solution will never change them. Suppose there remain $l$ left socks and $r$ right socks.

Without loss of generality, assume $l \geq r$. If not, we can just swap all left and right socks. We know that regardless of other operations, we will always need to turn $(l-r)/2$ left socks into right socks. So, if there are any pairs of left socks with the same color, we will first make matching pairs by turning half of them into right socks (while making sure $l$ is always at least $r$). This is optimal because since we need to turn left socks into right socks eventually, we might as well do it in a way that yields matching pairs immediately. After we equalize the number of left socks and right socks, or run out of pairs of left socks with the same color, we can finish by turning any $(l-r)/2$ left socks into right socks and then recoloring all left socks to match a right sock. Note that $l$ and $r$ change throughout this process.

Time complexity for each test case: $O(n)$

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int N,L,R;
int C[200001];
int lcnt[200001],rcnt[200001];

void solve(){
  cin>>N>>L>>R;
  for (int i=1;i<=N;i++){
    lcnt[i]=0;
    rcnt[i]=0;
  }
  for (int i=1;i<=N;i++){
    cin>>C[i];
    if (i<=L)
      lcnt[C[i]]++;
    else
      rcnt[C[i]]++;
  }
  //remove pairs that are already matching
  for (int i=1;i<=N;i++){
    int mn=min(lcnt[i],rcnt[i]);
    lcnt[i]-=mn;
    rcnt[i]-=mn;
    L-=mn;
    R-=mn;
  }
  if (L<R){
    swap(lcnt,rcnt);
    swap(L,R);
  }
  //now, there are at least as many left socks as right socks
  int ans=0;
  for (int i=1;i<=N;i++){
    int extra=L-R; //always even
    int canDo=lcnt[i]/2;
    int Do=min(canDo*2,extra);
    //turn "Do"/2 left socks of color i into right socks
    ans+=Do/2;
    L-=Do;
  }
  //turn extra lefts into rights, then adjust all colors
  ans+=(L-R)/2+(L+R)/2;
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T; cin>>T;
  while (T--)
    solve();
  return 0;
}

```
[1515E - Phoenix and Computers](../problems/E._Phoenix_and_Computers.md "Codeforces Global Round 14")

Idea: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

 **Tutorial**
### [1515E - Phoenix and Computers](../problems/E._Phoenix_and_Computers.md "Codeforces Global Round 14")

Let's first determine how many ways there are to turn on a segment of $k$ computers without any of them turning on automatically (we manually enable all $k$). We have two methods:

Method 1:

* If we turn on computer $1$ first, then we must turn on $2$, $3$, $\dots$, $k$ in that order. There are $k-1 \choose 0$ ways to do this, by stars and bars.
* If we turn on computer $2$ first, then we must turn on $3$, $4$, $\dots$, $k$ in that order, with computer $1$ inserted somewhere. There are $k-1 \choose 1$ ways to do this.
* If we turn on computer $3$ first, then we must turn on $4$, $5$, $\dots$, $k$ in that order, with computers $2$ and $1$ inserted somewhere (also in that order). There are $k-1 \choose 2$ ways to do this.
* In total, there are $k-1 \choose 0$ $+$ $k-1 \choose 1$ $+$ $\dots$ $+$ $k-1 \choose k-1$$ = 2^{k-1}$ ways.

Method 2: 

* We can prove it with induction. For the base case $k=1$, there is $1$ way. Now, if there are $x$ ways for some $k$, we wish to show that there are $2x$ ways for $k+1$.
* The critical observation is that the last computer in the sequence is either computer $1$ or computer $k+1$. If the last computer is $k+1$, then we have $x$ ways (we simply append $k+1$ to each previous sequence). If the last computer is $1$, then we also have $x$ ways (we append $1$ and increment every computer in the previous sequences). In total, we have $x+x=2x$ ways. Therefore, there are $2^{k-1}$ ways for any $k$.

 Any sequence that turns on all computers will look like this from left to right: several manual computers, one automatic computer, several manual computers, one automatic computer, and so on. In other words, computers $1 \dots i_1$ are manual, $i_1+1$ is automatic, $i_1+2 \dots i_2$ are manual, and so on. We will merge together the segments of manual computers using binomial coefficients.As a result, we can write $dp[len][cnt]$  — the number of ways to turn on a prefix of length $len-1$ computers having manually turned on $cnt$ computers. The last one $len$ (if $len < n$) will be turned on automatically.

To transition, iterate the length $k$ of a new segment of manual computers to add and calculate the number of ways with formula ($dp[len+k+1][cnt+k]$ $+=$ $dp[len][cnt]$ $\cdot$ $cnt + k \choose k$ $\cdot$ $2^{k - 1}$). The answer will be $\sum\limits_{i = 1}^{n} dp[n+1][i]$.

Time Complexity: $O(n^3)$

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD;

int N;
ll dp[405][405];

ll fastexp(ll b, ll exp){
  if (exp==0)
    return 1;
  ll temp=fastexp(b,exp/2);
  temp=(temp*temp)%MOD;
  if (exp%2==1)
    temp*=b;
  return temp%MOD;
}

ll fact[405],inv[405],choose[405][405],pow2[405];

void precompute(){
  fact[0]=1;
  inv[0]=1;
  for (int i=1;i<=N;i++){
    fact[i]=(fact[i-1]*i)%MOD;
    inv[i]=fastexp(fact[i],MOD-2);
  }
  for (int i=0;i<=N;i++)
    for (int j=0;j<=i;j++)
      choose[i][j]=((fact[i]*inv[j])%MOD*inv[i-j])%MOD;
  for (int i=0;i<=N;i++)
    pow2[i]=fastexp(2,i);
}

int main()
{
  cin>>N>>MOD;
  precompute();
  dp[0][0]=1;
  for (int i=0;i<N;i++){
    for (int j=0;j<=i;j++){
      for (int k=1;i+k<=N;k++){
	dp[i+k+1][j+k]+=((dp[i][j]*pow2[k-1])%MOD*choose[j+k][k]);
	dp[i+k+1][j+k]%=MOD;
      }
    }
  }
  ll ans=0;
  for (int i=0;i<=N;i++)
    ans=(ans+dp[N+1][i])%MOD;
  cout<<ans<<endl;
  return 0;
}
```
[1515F - Phoenix and Earthquake](../problems/F._Phoenix_and_Earthquake.md "Codeforces Global Round 14")

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1515F - Phoenix and Earthquake](../problems/F._Phoenix_and_Earthquake.md "Codeforces Global Round 14")

First, note that cities connected by roads behave as one city with the total amount of asphalt. This means building a road is equivalent to merging two cities and summing their asphalt.

If the total asphalt is less than $(n-1)$ $\cdot$ $x$, then we don't have enough asphalt to repair all the roads. It turns out that if the total asphalt is at least $(n-1)$ $\cdot$ $x$, it is always possible to repair all the roads. We can prove this by induction on the number of vertices. This is obviously true for $n=1$. Now we just need to show there is always a road that can be repaired, because doing so will reduce the number of vertices by one and the resulting asphalt will be at least $(n-2)$ $\cdot$ $x$, so the resulting graph can be merged by the inductive hypothesis.

If some city has at least $x$ asphalt, we can merge it with any neighbor.

Otherwise, all cities have less than $x$ asphalt. It turns out that any two cities $i$ and $j$ must have at least $x$ asphalt between them. To see why, notice that $a_k<x$ for all $1\le k\le n$, so if $a_i+a_j<x$, then the total asphalt must be less than $(n-1)$ $\cdot$ $x$.

Thus, one approach is to repeatedly find the city with the most asphalt and merge it with any of its neighbors. This can be implemented with a priority queue and union-find data structure in $O(m+n\log n)$.

There are other approaches as well. For example, since only connectedness of the graph is important, we can discard all edges except for a spanning tree. Pick any leaf. If it can be merged with its parent, do so. Otherwise, it must have less than $x$ asphalt. This means deleting the leaf will leave a connected graph with at least $(n-2)$ $\cdot$ $x$ asphalt, which can be merged recursively. The leaf is merged last. This can be implemented with a DFS in $O(m+n)$.

 **Solution**
```cpp
// Fix a spanning tree
// Pick a leaf, either merge it into its parent or postpone it to the end
#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXV=300005;
const int MAXE=300005;

int N,M,X;
long long as[MAXV];

int elist[MAXE*2];
int head[MAXV];
int prev[MAXE*2];
int tot=0;

bool vis[MAXV];

int ans[MAXV];
int front,back;

void dfs(int u){
  vis[u]=true;
  for(int e=head[u];e!=-1;e=prev[e]){
    int v=elist[e^1];
    if(vis[v]) continue;
    dfs(v);
    if(as[u]+as[v]>=X){
      as[u]+=as[v]-X;
      ans[front++]=e>>1;
    }else{
      ans[--back]=e>>1;
    }
  }
}

int main(){
  scanf("%d %d %d",&N,&M,&X);
  long long total=0;
  for(int i=0;i<N;i++){
    scanf("%lld",&as[i]);
    total+=as[i];
  }
  if(total<1LL*(N-1)*X){
    printf("NOn");
    return 0;
  }
  std::fill(head,head+N,-1);
  for(int i=0;i<M*2;i++){
    int U;
    scanf("%d",&U);
    U--;
    prev[i]=head[U];
    head[U]=i;
    elist[i]=U;
  }
  back=N-1;
  dfs(0);
  printf("YESn");
  for(int i=0;i<N-1;i++){
    printf("%dn",ans[i]+1);
  }
}
```
[1515G - Phoenix and Odometers](../problems/G._Phoenix_and_Odometers.md "Codeforces Global Round 14")

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1515G - Phoenix and Odometers](../problems/G._Phoenix_and_Odometers.md "Codeforces Global Round 14")

We can solve for each strongly-connected component independently. From now on, we will assume the graph is strongly-connected.

Define the length of a walk to be the sum of the weights of its edges, modulo $MOD$, the distance at which the odometer resets. This is different for different queries, but the important thing is some $MOD$ exists.

If there is a walk from $a$ to $b$ with length $x$, there is a walk from $b$ to $a$ with length $-x$ (for any $MOD$). To see this, note that since the graph is strongly-connected, there is a path from $b$ to $a$. Let its length be $y$. We can walk from $b$ to $a$ and back $MOD-1$ times and then go to $a$ for a total length of $(MOD)y+(MOD-1) x\equiv -x$. Note that this works for any $MOD$, even if we don't know what it is yet.

We can show that if $a$ is in a cycle of length $x$, then $b$ is in a cycle of length $x$. Suppose a path from $a$ to $b$ has length $y$. We can go from $b$ to $a$, go around the cycle, and go back to $b$ for a total length of $y+x+(-y)=x$.

$a$ is in a cycle of length $0$. If $a$ is in a cycle of length $x$, it is in a cycle of $kx$ for any integer $k$. If $a$ is in a cycle of length $x$ and a cycle of length $y$, it is in a cycle of length $x+y$.

The set of possible cycle lengths of cycles containing vertex $a$ are exactly the multiples of some number, namely the $\gcd$ of all possible cycle lengths.

So, if we want to determine all possible cycle lengths, we just need to compute this gcd. Fix an arbitrary spanning tree rooted at $r$ and denote the length of the tree path from $r$ to $a$ by $\phi(a)$.

If there is an edge of length $l$ from $a$ to $b$, then $r$ is in a cycle of length $\phi(a)+l-\phi(b)$. This cycle can be constructed by taking the walk along tree edges from $r$ to $a$, across the edge from $a$ to $b$, then backwards along tree edges from $b$ to $a$.

Thus, we can make any cycles whose length is a multiple of $G=\gcd\{\phi(a)+l-\phi(b):(a,b,l)\in E\}$. It turns out these are the only possible lengths.

If a walk from $a$ to $b$ has length $x$, then $x\equiv \phi(b)-\phi(a)\pmod G$. This can be proved by induction on the number of edges in the walk.

Now that we know which cycle lengths are possible, we can answer the queries.

An odometer can be reset if and only if $S$ plus some multiple of $T$ is a multiple of $G$.

An odometer can be reset if and only if $S$ is a multiple of $\gcd(T,G)$.

For implementation, the easiest way to get a spanning tree is by DFS. This can be done while computing strongly-connected components.

 **Solution**
```cpp
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>

using ll = long long;

std::vector<std::pair<int,int> > fwd[200005];
std::vector<std::pair<int,int> > rev[200005];

int vis[200005];
int cc[200005];
ll offset[200005];
int ncc;
ll loop[200005];
std::vector<int> ord;

ll gcd(ll a,ll b){
  return b?gcd(b,a%b):a;
}

void dfs_fwd(int x){
  vis[x]=1;
  for(auto e:fwd[x]){
    int y=e.first;
    if(vis[y]!=1){
      dfs_fwd(y);
    }
  }
  ord.push_back(x);
}

void dfs_rev(int x){
  vis[x]=2;
  for(auto e:rev[x]){
    int y=e.first,l=e.second;
    if(vis[y]!=2){
      cc[y]=cc[x];
      offset[y]=offset[x]+l;
      dfs_rev(y);
    }else if(cc[y]==cc[x]){
      loop[cc[x]]=gcd(loop[cc[x]],std::llabs(offset[x]+l-offset[y]));
    }
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B,L;
    scanf("%d %d %d",&A,&B,&L);
    A--,B--;
    fwd[A].push_back({B,L});
    rev[B].push_back({A,L});
  }
  for(int i=0;i<N;i++){
    if(vis[i]!=1){
      dfs_fwd(i);
    }
  }
  std::reverse(ord.begin(),ord.end());
  for(int i:ord){
    if(vis[i]!=2){
      cc[i]=ncc++;
      offset[i]=0;
      dfs_rev(i);
    }
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int V,S,T;
    scanf("%d %d %d",&V,&S,&T);
    V--;
    assert(0<=S&&S<T);
    if(S%gcd(loop[cc[V]],T)==0){
      printf("YESn");
    }else{
      printf("NOn");
    }
  }
}
```
[1515H - Phoenix and Bits](../problems/H._Phoenix_and_Bits.md "Codeforces Global Round 14")

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1515H - Phoenix and Bits](../problems/H._Phoenix_and_Bits.md "Codeforces Global Round 14")

We store the binary representation of all the numbers in a trie. To perform operations on a range, we split the trie to extract the range, perform the operation, and merge everything back.

AND $x$ is equivalent to the sequence XOR $2^{20}-1$, OR $x\oplus(2^{20}-1)$, XOR $2^{20}-1$. XOR does not affect the number of numbers in a subtrie, so we can just lazily propagate it. This leaves just OR operations.

Suppose we want to set the $k$th bit in a subtrie. If all numbers in it have the $k$th bit set, we do nothing; if no numbers in it have the $k$th bit set, we lazily XOR that bit.

Thus, we can handle OR operations recursively, merging the children if the bit to be set is at the current level, and stopping when all bits to be set satisfy one of those two conditions. We can detect these conditions by storing, in every trie node, a mask of bits that are set in some leaf and a mask of bits not set in some leaf.

This approach can be shown to be $O((n+q)\log^2C)$ by amortized analysis. Intuitively, the expensive OR operations will make the bits in a subtrie more similar.

Define $\Phi_k$ to be the number of trie nodes that have some leaf with the $k$th bit set and some leaf with the $k$th bit not set. Define $\Phi_*$ to be $1+\log C$ times the total number of trie nodes. Define the total potential to be the $\sum_{k=0}^{\log C-1}\Phi_k+\Phi_*$. This is always nonnegative and at most $O(n\log^2 C)$.

Split operations create at most $\log C$ nodes, each adding at most $O(\log C)$ to the potential, so its amortized time complexity is $O(\log^2 C)$.

Merge operations where one side is empty take $O(1)$. Recursive merge operations combine the two roots, the decrease in $\Phi_*$ paying for the possible increase in $\Phi_k$ at the root. (As usual, the recursive calls are not included in the cost as they are paid for by their own potential decrease).

An OR operation only recurses when there is some $k$ such that the subtrie has both a leaf with the $k$th bit set and a leaf with the $k$ bit not set. After the operation, all leaves will have the $k$th bit set. Thus, the recursion is paid for by the decrease in $\Phi_k$ at the root.

 **Solution**
```cpp
#include <cstdio>
#include <cassert>
#include <utility>
#include <functional>

//numbers up to 2^MAXLOGX-1
const int MAXLOGX=20;

template<int k>
struct Trie{
  Trie<k-1>* chd[2];
  int cnt;
  int lazy;
  int has[2];
  int get_cnt(){
    assert(this!=NULL);
    return cnt;
  }
  int get_has(int d){
    assert(this!=NULL);
    push();
    assert(has[d]<(1<<(k+1)));
    return has[d];
  }
  Trie(Trie<k-1>* l,Trie<k-1>* r):chd{l,r},cnt(0),lazy(0),has{0,0}{
    if(l){
      cnt+=l->get_cnt();
      has[0]|=l->get_has(0)|(1<<k);
      has[1]|=l->get_has(1);
    }
    if(r){
      cnt+=r->get_cnt();
      has[0]|=r->get_has(0);
      has[1]|=r->get_has(1)|(1<<k);
    }
    assert(has[0]<(1<<(k+1)));
    assert(has[1]<(1<<(k+1)));
  }
  void push(){
    assert(lazy<(1<<(k+1)));
    if(!lazy) return;
    //handle kth bit
    if(lazy&(1<<k)){
      std::swap(chd[0],chd[1]);
      if((has[0]^has[1])&(1<<k)){
	has[0]^=(1<<k);
	has[1]^=(1<<k);
      }
      lazy^=(1<<k);
    }
    //handle rest of bits
    int flip=(has[0]^has[1])&lazy;
    has[0]^=flip;
    has[1]^=flip;
    if(chd[0]) chd[0]->lazy^=lazy;
    if(chd[1]) chd[1]->lazy^=lazy;
    lazy=0;
    assert(has[0]<(1<<(k+1)));
    assert(has[1]<(1<<(k+1)));
  }
};

template<>
struct Trie<-1>{
  int lazy;
  Trie():lazy(0){
  }
  int get_cnt(){
    assert(this!=NULL);
    return 1;
  }
  int get_has(int d){
    assert(this!=NULL);
    return 0;
  }
};

template<int k>
Trie<k>* create(int x){
  if(x&(1<<k)){
    return new Trie<k>(NULL,create<k-1>(x));
  }else{
    return new Trie<k>(create<k-1>(x),NULL);
  }
}
template<>
Trie<-1>* create(int x){
  return new Trie<-1>();
}

template<int k>
std::pair<Trie<k-1>*,Trie<k-1>*> destruct(Trie<k>* a){
  assert(a!=NULL);
  a->push();
  auto res=std::make_pair(a->chd[0],a->chd[1]);
  delete a;
  return res;
}

template<int k>
Trie<k>* join(Trie<k-1>* l,Trie<k-1>* r){
  if(l==NULL&&r==NULL) return NULL;
  return new Trie<k>(l,r);
}

template<int k>
Trie<k>* merge(Trie<k>* a,Trie<k>* b){
  if(!a) return b;
  if(!b) return a;
  auto aa=destruct(a);
  auto bb=destruct(b);
  Trie<k-1>* l=merge<k-1>(aa.first,bb.first);
  Trie<k-1>* r=merge<k-1>(aa.second,bb.second);
  return join<k>(l,r);
}

template<>
Trie<-1>* merge<-1>(Trie<-1>* a,Trie<-1>* b){
  if(!a) return b;
  if(!b) return a;
  delete b;
  return a;
}

template<int k>
//<thres and >=thres
std::pair<Trie<k>*,Trie<k>*> split(Trie<k>* a,int thres){
  if(a==NULL){
    return {NULL,NULL};
  }
  if(thres<=0) return {NULL,a};
  if(thres>=(1<<(k+1))) return {a,NULL};
  assert(k>=0);
  auto aa=destruct(a);
  if(thres<(1<<k)){
    Trie<k-1>* l,*r;
    std::tie(l,r)=split<k-1>(aa.first,thres);
    return std::make_pair(join<k>(l,NULL),join<k>(r,aa.second));
  }else if(thres>(1<<k)){
    Trie<k-1>* l,*r;
    std::tie(l,r)=split<k-1>(aa.second,thres-(1<<k));
    return std::make_pair(join<k>(aa.first,l),join<k>(NULL,r));
  }else{
    return std::make_pair(join<k>(aa.first,NULL),join<k>(NULL,aa.second));
  }
}

template<>
std::pair<Trie<-1>*,Trie<-1>*> split<-1>(Trie<-1>* a,int thres){
  assert(0);
}

template<int k>
Trie<k>* update(Trie<k>* a,int val){
  if(a==NULL) return NULL;
  a->push();
  assert(val<(1<<(k+1)));
  if((val&a->has[0]&a->has[1])==0){
    a->lazy^=(val&a->has[0]);
    return a;
  }
  Trie<k-1>* l,*r;
  std::tie(l,r)=destruct(a);
  l=update<k-1>(l,val&~(1<<k));
  r=update<k-1>(r,val&~(1<<k));
  if(val&(1<<k)){
    return join<k>(NULL,merge<k-1>(l,r));
  }else{
    return join<k>(l,r);
  }
}

template<>
Trie<-1>* update<-1>(Trie<-1>* a,int val){
  return a;
}

int main(){
  Trie<MAXLOGX-1>* root=NULL;
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    root=merge(root,create<MAXLOGX-1>(A));
  }
  for(int i=0;i<Q;i++){
    int T,L,R;
    scanf("%d %d %d",&T,&L,&R);
    Trie<MAXLOGX-1>* left,*right;
    std::tie(left,root)=split(root,L);
    std::tie(root,right)=split(root,R+1);
    if(T==4){
      printf("%dn",root?root->cnt:0);
    }else{
      int X;
      scanf("%d",&X);
      if(root!=NULL){
	if(T==1){
	  root->lazy^=((1<<MAXLOGX)-1);
	  root=update(root,X^((1<<MAXLOGX)-1));
	  root->lazy^=((1<<MAXLOGX)-1);
	}else if(T==2){
	  root=update(root,X);
	}else if(T==3){
	  assert(X<(1<<MAXLOGX));
	  root->lazy^=X;
	}
      }
    }
    root=merge(root,left);
    root=merge(root,right);
  }
}
```
[1515I - Phoenix and Diamonds](../problems/I._Phoenix_and_Diamonds.md "Codeforces Global Round 14")

Idea: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Tutorial**
### [1515I - Phoenix and Diamonds](../problems/I._Phoenix_and_Diamonds.md "Codeforces Global Round 14")

Suppose the largest weight of an item is less than $2^k$. Call an item heavy if its weight is in the range $[2^{k-1},2^k)$ and light if its weight is in the range $(0,2^{k-1})$. Sort the items in decreasing order by value. As the thief moves left to right, his remaining capacity is nonincreasing. Consider the point where it drops below $2^{k-1}$. Before this point, he takes all light items. After this point, he takes no heavy items. The latter can be solved recursively by querying the same data structure only on light items, starting at the appropriate point. The former is a bit trickier.

The thief will take every item until his capacity drops below $2^k$. This point can be found by binary searching on a segment tree of sums. After this point, he can only take at most one more heavy item. To find this item (if it exists), we can binary search on a segment tree storing range minimums of prefix sum of light items plus weight of heavy item. The first item that is small enough will be taken, if it exists. Either way, we've located all heavy items that will be taken and can recursively handle the light items.

To handle updates, reserve space for all items offline and change their multiplicity as needed. When an item is updated, we can modify all segment trees that it participates in.

This solution is $O((n+q)\log{n}\log{C})$.

 **Solution**
```cpp
#include <cstdio>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <cassert>

using ll=long long;

const ll INF=1e18+7;

struct Diamond{
  int w,v,t;
  ll a;
}diamonds[200005];
int index[200005];
int N;

struct Node{
  ll sum_w[31];//sum of weights of all diamonds with weight <2^k
  ll sum_v[31];//sum of values of all diamonds with weight <2^k
  ll one_w[31];//sum of weights of light+first heavy when restricted to <2^k
  ll one_v[31];//sum of values of light+first heavy when restricted to <2^k
}st[800005];

void rebuild(int w,int L,int R,int a,int b){
  if(a>=R||b<=L) return;
  if(R-L==1){
    for(int k=1;k<=30;k++){
      st[w].sum_w[k]=diamonds[L].a*diamonds[L].w*(diamonds[L].w<(1<<k));
      st[w].sum_v[k]=diamonds[L].a*diamonds[L].v*(diamonds[L].w<(1<<k));
      st[w].one_w[k]=INF;//query capacity never exceed INF
      st[w].one_v[k]=INF;
      if(diamonds[L].w>=(1<<(k-1))&&diamonds[L].w<(1<<k)&&diamonds[L].a>0){
	st[w].one_w[k]=diamonds[L].w;
	st[w].one_v[k]=diamonds[L].v;
      }
    }
  }else{
    int M=(L+R)/2;
    rebuild(w*2+1,L,M,a,b);
    rebuild(w*2+2,M,R,a,b);
    for(int k=1;k<=30;k++){
      st[w].sum_w[k]=st[w*2+1].sum_w[k]+st[w*2+2].sum_w[k];
      st[w].sum_v[k]=st[w*2+1].sum_v[k]+st[w*2+2].sum_v[k];
      if(st[w*2+1].one_w[k]<st[w*2+1].sum_w[k-1]+st[w*2+2].one_w[k]){
	st[w].one_w[k]=st[w*2+1].one_w[k];
	st[w].one_v[k]=st[w*2+1].one_v[k];
      }else{
	st[w].one_w[k]=st[w*2+1].sum_w[k-1]+st[w*2+2].one_w[k];
	st[w].one_v[k]=st[w*2+1].sum_v[k-1]+st[w*2+2].one_v[k];
      }
    }
  }
}

//only consider weights <2^k
//take maximal prefix possible
void query_all(int w,int L,int R,int& i,int k,ll& cap,ll& value){
  assert(i>=L&&i<=R);
  assert(R-L>0);
  if(i==R) return;
  if(i==L&&st[w].sum_w[k]<=cap){
    cap-=st[w].sum_w[k];
    value+=st[w].sum_v[k];
    i=R;
  }else if(R-L>1){
    int M=(L+R)/2;
    if(i<M){
      query_all(w*2+1,L,M,i,k,cap,value);
    }
    if(i>=M){
      query_all(w*2+2,M,R,i,k,cap,value);
    }
  }
}

std::array<ll,2> query_one_range_simpl(int w,int L,int R,int a,int b,int k){
  if(a>=R||b<=L) return {INF,0};
  if(a<=L&&b>=R){
    return {st[w].one_w[k],st[w].sum_w[k-1]};
  }else{
    int M=(L+R)/2;
    std::array<ll,2> lsum,rsum;
    lsum=query_one_range_simpl(w*2+1,L,M,a,b,k);
    rsum=query_one_range_simpl(w*2+2,M,R,a,b,k);
    if(lsum[0]<lsum[1]+rsum[0]){
      return {lsum[0],lsum[1]+rsum[1]};
    }else{
      return {lsum[1]+rsum[0],lsum[1]+rsum[1]};
    }
  }
}

std::array<ll,4> query_one_range(int w,int L,int R,int a,int b,int k){
  if(a>=R||b<=L) return {INF,INF,0,0};
  if(a<=L&&b>=R){
    return {st[w].one_w[k],st[w].one_v[k],st[w].sum_w[k-1],st[w].sum_v[k-1]};
  }else{
    int M=(L+R)/2;
    std::array<ll,4> lsum,rsum;
    lsum=query_one_range(w*2+1,L,M,a,b,k);
    rsum=query_one_range(w*2+2,M,R,a,b,k);
    if(lsum[0]<lsum[2]+rsum[0]){
      return {lsum[0],lsum[1],lsum[2]+rsum[2],lsum[3]+rsum[3]};
    }else{
      return {lsum[2]+rsum[0],lsum[3]+rsum[1],lsum[2]+rsum[2],lsum[3]+rsum[3]};
    }
  }
}

//returns min j such that one_w[i..j) <= cap, or -1 if none exist
//reduce cap by weight of light in [max(i,L),R)
int query_one_range_search_(int w,int L,int R,int& i,int k,ll& cap){
  assert(i>=L&&i<=R);
  assert(R-L>0);
  if(i==R) return -1;
  if(i==L&&st[w].one_w[k]>cap){
    cap-=st[w].sum_w[k-1];
    i=R;
    return -1;
  }else if(R-L==1){
    assert(i==L);
    assert(st[w].one_w[k]<=cap);
    cap-=st[w].sum_w[k-1];
    i=R;
    return R;
  }else{
    int M=(L+R)/2;
    int res=-1;
    if(i<M){
      res=query_one_range_search_(w*2+1,L,M,i,k,cap);
    }
    if(res!=-1) return res;
    if(i>=M){
      res=query_one_range_search_(w*2+2,M,R,i,k,cap);
    }
    return res;
  }
}

int query_one_range_search(int i,int k,ll cap){
  //note this copy of cap will be modified
  return query_one_range_search_(0,0,N,i,k,cap);
}

void query_one(int& L,int k,ll& cap,ll& value){
  int high=query_one_range_search(L,k,cap);
  //v[high]<=cap
  if(high!=-1){
    auto v=query_one_range(0,0,N,L,high,k);
    L=high;
    cap-=v[0];
    value+=v[1];
  }
}

ll query(ll cap){
  ll value=0;
  int i=0;
  for(int k=30;k>0;k--){
    query_all(0,0,N,i,k,cap,value);
    if(i==N) break;
    ll take=std::min(diamonds[i].a,cap/diamonds[i].w);
    cap-=take*diamonds[i].w;
    value+=take*diamonds[i].v;
    i++;
    query_one(i,k,cap,value);
  }
  return value;
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%lld %d %d",&diamonds[i].a,&diamonds[i].w,&diamonds[i].v);
    diamonds[i].t=i;
  }
  std::sort(diamonds,diamonds+N,[](Diamond x,Diamond y){
      return (x.v!=y.v)?(x.v>y.v):(x.w<y.w);
    });
  for(int i=0;i<N;i++){
    index[diamonds[i].t]=i;
  }
  rebuild(0,0,N,0,N);
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int K,D;
      scanf("%d %d",&K,&D);
      D--;
      diamonds[index[D]].a+=K;
      rebuild(0,0,N,index[D],index[D]+1);
    }else if(T==2){
      int K,D;
      scanf("%d %d",&K,&D);
      D--;
      diamonds[index[D]].a-=K;
      assert(diamonds[index[D]].a>=0);
      rebuild(0,0,N,index[D],index[D]+1);
    }else{
      ll C;
      scanf("%lld",&C);
      printf("%lldn",query(C));
    }
  }
}
```
