# Tutorial_(en)


### [1111A - Superhero Transformation](../problems/A._Superhero_Transformation.md "CodeCraft-19 and Codeforces Round 537 (Div. 2)")

Check lengths of $s$ and $t$. If they are different, $s$ can never be converted to $t$ and answer is "No".

If for all indexes $i$ either both $s[i]$ and $t[i]$ are vowels or both $s[i]$ and $t[i]$ are consonants, then answer is "Yes", else answer is "No".

 **Author's code**
```cpp
#include "bits/stdc++.h"
using namespace std;

// Checking if a character is vowel
bool isVowel(char a)
{
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return true;
    return false;
}

int main()
{
    string S, T;
    cin >> S;
    cin >> T;
    // Answer is no if size of strings is differents
    if(S.size() != T.size())
    {
        cout << "Non";
        return 0;
    }
    int flag = 1;
    // Checking the condition on all characters one by one 
    for(int i = 0; i < S.size(); ++i)
    {
        if((isVowel(S[i]) && isVowel(T[i])) || (isVowel(S[i]) == false && isVowel(T[i]) == false))
        {
            continue;
        }
        flag = 0;
        break;
    }
    if(flag)
        cout << "Yesn";
    else
        cout << "Non";
    return 0;
}
```
 
### [1111B - Average Superhero Gang Power](../problems/B._Average_Superhero_Gang_Power_.md "CodeCraft-19 and Codeforces Round 537 (Div. 2)")

If we want to remove an element to increase the average it should be the smallest element in our current set. For each deletion, $1$ operation is used. 

Lets try finding $f(i)$ = maximum average by deleting $i$ smallest elements. 

If we delete $i$ elements, then for the remaining $n-i$ elements the maximum increase can be $min(m-i,k*(n-i))$ since $m-i$ operations can be now at max used, and at one particular index at most $k$ operations can be done.

So $f(i) = $( sum of largest $(n-i$) elements $+ min(m-i,k*(n-i)) )/ (n-i)$

The sum of largest $(n-i)$ terms can be computed using prefix sums.

$ans = $max $f(i) $ over all $i$ from $0$ to $min(m,n-1)$

The min condition comes because there is no use of deleting all elements, and the number of deletions is limited by the maximum number of operations possible.

 **Author's code**
```cpp
#include <bits/stdc++.h>
using namespace std;
const long long N = 100010;

long long a[N];

int main()
{
    long long n, k, m, i, sum=0, tp;
    long double mx;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    // Sorting the array
    sort(a+1, a+n+1);
    // Checking for the case where none of the avengers is removed
    mx = (long double)(sum+min(m, n*k))/(long double)(n);
 
    for(int i=1;i<=min(n-1, m);i++)
    {
        sum -= a[i];
        tp = sum + min(m-i, (n-i)*k);
        mx = max(mx, (long double)(tp)/(long double)(n-i));
    }
    cout<<fixed<<setprecision(20)<<mx<<endl;
    return 0;
}
```
 
### [1111C - Creative Snap](../problems/C._Creative_Snap.md "CodeCraft-19 and Codeforces Round 537 (Div. 2)")

Make a recursive function rec($l,r$) where l and r are start and end indexes of subarray to be considered. Start with $l=1$ and $r=2^n$. If there is no avenger in l to r return A (power consumed). Else either power consumed to burn it directly is $b*x*len$ (where x is number of avengers in l to r and len is length of array ($r-l+1$) ) or by dividing the array is the result of recursion($l,mid$) + recursion($mid+1,r$) where $mid=(l+r)/2$. Return the minimum power consumed. If l is equal to r then do not go into recursion further, return power consumed according to first operation. One thing is remaining, the value of x, given l and r. Sort the array containing indices of avengers and then find positions of l and r in that array using binary search. Difference is positions of l and r in array will give x. Time Complexity : $O(n*k*log(k))$. Explanation : Reaching any subarray will take maximum of n operations and we can have maximum k subarrays (each having one avenger), it will take $O(n*k)$. $O(log(k))$ time needed for binary search (calculating x). So net complexity is $O(n*k*log(k))$.

 **Author's code**
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<long long> avengers;
long long n,k,A,B;

// rec(l,r) returns minimum power needed to destroy l to r (inclusive)
long long rec(long long l, long long r)
{
	long long i=lower_bound(avengers.begin(),avengers.end(),l)-avengers.begin();
	long long j=upper_bound(avengers.begin(),avengers.end(),r)-avengers.begin();
	j--;
        // calculating positions of l and r in avengers array to calculate x
	long long x=j-i+1;
	long long power_consumed;
        // if there is no avenger in that subarray
	if(x==0)
		power_consumed=A;
	else
	{
	    power_consumed=B*x*(r-l+1);
            // power consumed for operation 2. (r-l+1 is length of subarray)
	}
        // if l is equal to r or if there is no avenger in the subarray, then do not go into recursion further
	if(l==r || x==0)
		return power_consumed;
	long long mid=(l+r)/2;
	// taking minimum of two operations.
	long long minPower=min(power_consumed, rec(l,mid)+rec(mid+1,r));
	return minPower;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>A>>B;
	int i;
	for(i=0;i<k;i++)
	{
		int val;
		cin>>val;
		avengers.push_back(val);
	}
	sort(avengers.begin(),avengers.end());
	long long x = (long long)1<<n;
	cout<<rec(1,x)<<endl;
	return 0;
}
```
 
### [1111D - Destroy the Colony](../problems/D._Destroy_the_Colony.md "CodeCraft-19 and Codeforces Round 537 (Div. 2)")

The question reduces to the following. Given a string s with lowercase and uppercase characters,a good string is one which can be generated by reshuffling characters, such that all occurences of a particular alphabet are in the same half. ( (1 to n/2) or (n/2+1 to n)) and this condition is true for all alphabets. Now given a pair $i$ and $j$, you want to find the number of good strings such that all the occurences of $s[i]$ and $s[j]$ in the string are also in the same half in the string.

Lets first try to find the number of good strings. $k$ = total number of alphabets.

Store the frequencies of the alphabets as their order does not matter, and let them be $c1,c2,c3..ck$ Now if we can select indices $i_1, i_2, \ldots, i_p$ such that $ci_1 + ci_2 + \ldots, ci_p$ = n/2 then we can arrange those alphabets in the first half, and the remaining in the second half. Total ways for arranging in first half = $(n/2!)/(ci1!* ci2!* ci3!.. cip!)$

Similarly total ways for arranging in 2nd half = $(n/2!)/$(product of factorials of remaining frequencies.)

Thus total ways = $((n/2!)*(n/2!))/$(product of factorials of frequencies of all alphabets) $= W$(say) Thus notice that, for all combinations of frequencies adding upto $n/2$, the number of ways comes out to be constant. 

Hence now the total number of good strings $= W*$ (number of combinations of frequencies adding to $n/2$)

The part for the number of combinations adding upto $n/2$ can be computed using standard knapsack dp.

Now let's try to solve for the condition that all occurrences of $s[i]$ and $s[j]$, should all also be in the same half, apart from the condition of the string being a good string.

This basically means now we want to select alphabet frequencies adding upto $n/2$ from the remaining frequencies ( excluding the frequency of alphabet $s[i]$ and $s[j]$). One way is to use the same method we did above for all good strings.

This gives complexity O$(n*k)$ for every pair, taking a total of O$(n*k^3)$ for $k^2$ pairs.

Now using the idea of adding items to a knapsack, we can also extend it to remove items.

In short, we can use the pre-computed dp table to remove the number of ways which included the ith item, by reversing the direction of the loop and the operation ( addition becomes subtraction). Let the frequency of the element we want to remove be $x$.

dp[j] = number of ways to get sum as j using all elements. 

for (int j=x;j<=n;j++)

$\quad$dp[j]-=dp[j-x];

( see the code for more details)

In this way for every pair $(x,y)$, you copy the precomputed dp into a temporary array, remove ways using characters $x$ and $y,$ and then the answer will be $2*dp[n/2]*W$ ( 2 because you can choose the first or the second half for putting the group containing $x$ and $y$). After precomputation, each query is answered in O$(1)$. Total time O$(2*n)$, for every pair and there are $(k*(k-1))/2$ pairs. Final time complexity O$(n*k^2)$

 **Author's code**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,st,en) for(i=st;i<=en;i++)

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100010;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
    b =(b*b)%mod;exp/=2ll;
    }
    return res;
}

ll buc[101];
ll fac[N],inv[N];
ll dp[N],temp_dp[N];
ll ans[55][55];
string s,s1,s2;

int find(char c)
{
    if(c>='A' && c<='Z')return (int)(c-'A'+26);
    else return (c-'a');
}

inline void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
inline void sub(ll &a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,n,i,j,m,q;
    cin>>s;
    n = s.length();
    //Store the frequencies in buc
    for(int i=0;i<n;i++)buc[find(s[i])]++;
    
    //Compte factorial and inverse factorials modulo mod
    fac[0]=1;
    rep(i,1,n)fac[i]=(fac[i-1]*1ll*i)%mod;
    inv[n] = fmod(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)inv[i]=(inv[i+1]*1ll*(i+1))%mod;


    //Compute n/2! * n/2! divided by factorials of frequencies of all
    ll num = (fac[n/2]*fac[n/2])%mod;
    for(int i=0;i<52;i++)num = (num*inv[buc[i]])%mod;

    //DP for subset sum
    dp[0]=1;
    for(int i=0;i<52;i++)
    {
        if(!buc[i])continue;
        for(int j=n;j>=buc[i];j--)
            add(dp[j],dp[j-buc[i]]);
    }
    fr(i,52)ans[i][i]=dp[n/2];

    fr(i,52)
    {
        if(!buc[i])continue;
        //Temporrily store dp using all characters in an array
        for(int k=0;k<=n;k++)
            temp_dp[k]= dp[k];

        //Remove all ways consisting of the ith character from temp array
        for(int k=buc[i];k<=n;k++)
            sub(temp_dp[k],temp_dp[k-buc[i]]);
        

        for(int j=i+1;j<52;j++)
        {
            if(!buc[j])continue;
            //Now remove the jth character from the temp
            for(int k=buc[j];k<=n;k++)
                sub(temp_dp[k],temp_dp[k-buc[j]]);

            // Answer will be twice since ith and jth can be in 1st or 2nd half
            ans[i][j]= (2ll*temp_dp[n/2])%mod;
            ans[j][i]= ans[i][j]; //Symmetric
                
            //Restore condition by adding ways using jth to reset temp to without i
            for(int k=n;k>=buc[j];k--)
                add(temp_dp[k],temp_dp[k-buc[j]]);
        }
    }
    cin>>q;
    int x,y;
    while(q--)
    {
        cin>>x>>y;
        int l = find(s[x-1]);
        int r = find(s[y-1]);
        //Use precomputed num and ans, for all queries
        cout<<(num*ans[l][r])%mod<<"n";
    }
    
    return 0;
}
```
 
### [1111E - Tree](../problems/E._Tree.md "CodeCraft-19 and Codeforces Round 537 (Div. 2)")

Assume that we didn't have to root at Y in each query. Lets first solve the problem for all queries having root at 1. 

While processing the query, let's sort the given set of nodes according to the dfs order. Let dp[i][j] denotes the number of ways to divide the first i nodes in the set into j non-empty groups. For a node i, let h[i] denote the number of ancestors in the query set. Now,

dp[i][j] = dp[i-1][j]$\cdot$(j-h[i]) + dp[i-1][j-1]

The first part basically says, that apart from the groups of the ancestors of i, it can be included in any other group, hence (j-h[i]) choices for allocating a group to i. The second part is including $i$-th node in a completely new group. 

Thus our final answer would have been the sum of dp[n][j] for all j from 1 to x. Now how to find h[i]? If we mark all the nodes which have appeared in the query, h[i] is the number of marked nodes from i to the root. This can be computed using standard range updates and point queries on Euler tree. For all nodes i, perform a range update on the range [ST(i),EN(i)] and h[i] basically becomes query(ST[i]). 

Now a key observation. Notice that actually we only care that for node i, before updating its dp, all its ancestors are visited. This means we actually do not need the dfs order, instead just the level-wise order. So all we need to do is sort all nodes in the query set according to the h[i] values. By removing the condition for dfs order on the ordering of the dp, the condition for rerooting can also be handled. 

If the tree is rooted at Y, Now hnew[i] becomes the number of marked nodes between i and root Y. This can be computed using the same technique of range update and query. hnew[i] = h[i] + h[Y] - 2$\cdot$h[ LCA(i,Y)] + (mark[LCA(i,Y)]==true) -1

(-1 because we do not want to include i in hnew[i])

Now we do the same dp and compute the answer.

For every query: Sorting = O(KlogK), LCA computation = O(KlogN), bit update and query= O(KlogN) LCA precomputation = O(NlogN) Thus final complexity = O( NlogN + logN$\cdot$(summation over all values of K))

(where summation of K <= 10^5)

 **Author's code**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,st,en) for(i=st;i<=en;i++)

typedef long long ll;
typedef pair<int,int> pii;
const int N = 200010;
const int LN = 20;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
        b =(b*b)%mod;exp/=2ll;
    }
    return res;
}

int ver[2*N]; // gives the id of the vertex in the euler array
ll bit[2*N];
int st[N],en[N],A[N]; // st and en are the start and end time of node i
int f[N];
ll dp[N];
int par[N][LN];
int mark[N],lev[N];

vector<int> adj[N];

int tim = 0,n;

/* Normal DFS and LCA functions */
void dfs(int i,int p=-1)
{
    
    if (p+1)
    {
        lev[i]=lev[p]+1;
        par[i][0]=p;
        for(int j=1;j<LN;j++)
            if (par[i][j-1]+1)
                par[i][j]=par[par[i][j-1]][j-1];
    }
    st[i]=(++tim);
    ver[tim]= i;
    for(auto ve:adj[i])
        if(p-ve)
            dfs(ve,i);
    en[i]=(++tim);
    ver[tim]= i;
}

int lca(int u,int v)
{
    if (lev[u]<lev[v])
        swap(u,v);
    for(int j=LN-1;j>=0;j--)
        if (par[u][j]+1 && lev[par[u][j]]>=lev[v])
            u=par[u][j];
    if (u==v)
        return u;
    for(int j=LN-1;j>=0;j--)
    {
        if (par[u][j]+1 && par[u][j]!=par[v][j])
        {
            u=par[u][j];
            v=par[v][j];
        }
    }
    return par[u][0];
}

/* Helper functions */
inline ll add(ll a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
void upd(int ind,int val)
{
    for(int i=ind;i<=2*n;i+=(i&-i))
        bit[i]+=val;
}

ll query(int ind)
{
    ll res = 0;
    for(int i=ind;i>0;i-=(i&-i))
        res+=bit[i];
    return res; // returns the number of marked nodes from 1 to ind inclusive.
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,i,j,m,q,u,v,w,typ,e,k,x;
    memset(par,-1,sizeof(par));
    cin>>n>>q;
    rep(i,1,n-1)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    int root;
    while(q--)
    {
        cin>>k>>x>>root;

        rep(i,1,k){
            cin>>A[i];
            mark[A[i]]=1; //mark nodes given in the set
            upd(st[A[i]],1);  // range update by updating at start and end time in bit
            upd(en[A[i]]+1,-1);
        }
        int ans_root = query(st[root]);
        rep(i,1,k){
            int lp = lca(A[i],root);
            //query function is inclusive, hence subtract 1 to remove current node from answer
            f[i]= query(st[A[i]])+ans_root-2*query(st[lp])+(mark[lp]==1)-1;
        }
        //Sorting level-wise using f[i] values
        sort(f+1,f+k+1);
        rep(i,1,k){
            upd(st[A[i]],-1); // reverse the updates to nullify effect
            upd(en[A[i]]+1,1);
            mark[A[i]]=0;  // unmark nodes in the set
        }
        rep(i,0,x)dp[i]=0;
        dp[0]=1;
        //If number of groups less than maximum height no way possible
        int fl = 0;
        rep(i,1,k)if(f[i]>=x)fl=1;
        if(fl)cout<<"0n";
        else{
        dp[0]=1;
        //For every value of f[i], update dp. Note loop for j will be reverse.
        rep(i,1,k){
            for(int j=min(i,x);j>=0;j--)
            {
                if(j<=f[i])dp[j]=0; //no way possible since less than height
                else dp[j]= add(((dp[j]*1ll*(j-f[i]))%mod),dp[j-1]); 
            }
        }
        ll ans = 0;
        // AT MOST x in the question
        rep(i,1,x){
            ans = add(ans,dp[i]);
        }
        cout<<ans<<"n";
        }
    }
    return 0;
}

```
