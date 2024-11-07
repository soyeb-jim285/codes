# Tutorial_(en)

[1594A - Consecutive Sum Riddle](../problems/A._Consecutive_Sum_Riddle.md "Codeforces Round 747 (Div. 2)")

 **Hint**See how n=2 case works.

 **Solution**
### [1594A - Consecutive Sum Riddle](../problems/A._Consecutive_Sum_Riddle.md "Codeforces Round 747 (Div. 2)")

You can take (−n+1)+(−n+2)+…+(n−1)+n, so the sum will be n. Thus, l=−n+1 and r=n.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<-n+1<<" "<<n<<endl;
    }
}
```
[1594B - Special Numbers](../problems/B._Special_Numbers.md "Codeforces Round 747 (Div. 2)")

 **Hint**Think of the numbers in base n.

 **Solution**
### [1594B - Special Numbers](../problems/B._Special_Numbers.md "Codeforces Round 747 (Div. 2)")

The problem is the same as finding the k-th number that in base n has only zeros and ones.

So you can write k in binary system and instead of powers of 2 add powers of n.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ll,ii>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll p = 1;
        ll ans = 0;
        f(j,0,31){
            if(k & (1<<j)){
                ans = (ans + p) % INF;
            }
            p *= n;
            p %= INF;
        }
        cout<<ans<<"n";
    }
}
```
[1594C - Make Them Equal](../problems/C._Make_Them_Equal.md "Codeforces Round 747 (Div. 2)")

 **Hint**You need atmost 2 operations.

 **Solution**
### [1594C - Make Them Equal](../problems/C._Make_Them_Equal.md "Codeforces Round 747 (Div. 2)")

If the whole string is equal to c then you don't need to make any operations.

In order to find if it is possible with exactly 1 operation, we can pass through every x and count all the letters c that are divisible by x. This takes O(|s|log|s|) time complexity.

If for some x all its multiples are c then the answer is 1 operation with that x.

If all the above conditions don't hold you can always make 2 operations and make all the elements equal.

One possible way is with x=|s| and x=|s|−1.

After the first operation only the last element of s is not c thus if we use x=|s|−1 since gcd(|s|,|s|−1)=1 then |s| is not divisible by |s|−1 and it will become equal to c.

Time complexity: O(|s|log|s|) per test case.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ll,ii>
#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;
        vector<int>ans;
        bool ok = true;
        for(auto x:s){
            if(x != c){
                ok = false;
            }
        }
        if(!ok){
            f(i,1,n+1){
                ok = true;
                f(j,i,n+1){
                    ok &= (s[j-1] == c);
                    j += i-1;
                }
                if(ok){
                    ans.pb(i);
                    break;
                }
            }
            if(!ok){
                ans.pb(n);
                ans.pb(n-1);
            }
        }
        cout<<ans.size()<<"n";
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<"n";
    }
}
```
[1594D - The Number of Imposters](../problems/D._The_Number_of_Imposters.md "Codeforces Round 747 (Div. 2)")

 **Hint**Construct a graph from the comments.

 **Solution**
### [1594D - The Number of Imposters](../problems/D._The_Number_of_Imposters.md "Codeforces Round 747 (Div. 2)")

If person A said in a comment that person B is a crewmate then A and B belong to the same team (either imposters or crewmates).

If person A said in a comment that person B is an imposter then A and B belong to different teams.

Solution 1:

You can build a graph and check if all its components are bipartite.

If person A said that B is an imposter then we add an edge from A to B.

If person A said that B is a crewmate then we add an edge from A to a fake node and from the same fake node to B.

For each component, we check if it's bipartite and take the maximum from the two colours.

If a component is not bipartite then the answer is −1.

Solution 2:

We can build the graph in the other way:

If A and B are in the same team then we add edge with weight 0, otherwise with weight 1. 

Then you can use dfs and colour the nodes either 0 or 1 maintaining the property that u⊕v=w(u,v).

 **Code 1(C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ll,ii>
#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
vector<vector<ii> >adj;
int c[2];
int colour[700005];
bool ok;
int n;
void dfs(int idx){
    c[colour[idx]]+= (idx <= n);
    for(auto x:adj[idx]){
        if(colour[x.F] == -1){
            colour[x.F] = colour[idx] ^ x.S;
            dfs(x.F);
        }
        else if(colour[x.F] != (colour[idx] ^ x.S)){
            ///impossible
            ok = false;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>n>>m;
        ///n original + m atmost fake nodes
        adj.assign(n+m+5,vector<ii>());
        f(i,0,n+m+5){
            colour[i] = -1;
        }
        int fake = n+1;
        f(i,0,m){
            int a,b;
            string c;
            cin>>a>>b>>c;
            if(c == "crewmate"){
                ///same team
                adj[a].pb(ii(fake,1));
                adj[fake].pb(ii(a,1));
                adj[fake].pb(ii(b,1));
                adj[b].pb(ii(fake,1));
                fake++;
            }
            else{
                ///different team
                adj[a].pb(ii(b,1));
                adj[b].pb(ii(a,1));
            }
        }
        int ans = 0;
        ok = true;
        f(i,1,n+1){
            if(colour[i] == -1){
                colour[i] = 0;
                c[0] = c[1] = 0;
                dfs(i);
                ans += max(c[0],c[1]);
            }
        }
        if(!ok){
            ans = -1;
        }
        cout<<ans<<"n";
    }
}
```
 **Code 2(C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ll,ii>
#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
vector<vector<ii> >adj;
int c[2];
int colour[200005];
bool ok;
void dfs(int idx){
    c[colour[idx]]++;
    for(auto x:adj[idx]){
        if(colour[x.F] == -1){
            colour[x.F] = colour[idx] ^ x.S;
            dfs(x.F);
        }
        else if(colour[x.F] != (colour[idx] ^ x.S)){
            ///impossible
            ok = false;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        adj.assign(n+5,vector<ii>());
        f(i,0,n+5){
            colour[i] = -1;
        }
        f(i,0,m){
            int a,b;
            string c;
            cin>>a>>b>>c;
            if(c == "crewmate"){
                ///same team
                adj[a].pb(ii(b,0));
                adj[b].pb(ii(a,0));
            }
            else{
                ///different team
                adj[a].pb(ii(b,1));
                adj[b].pb(ii(a,1));
            }
        }
        int ans = 0;
        ok = true;
        f(i,1,n+1){
            if(colour[i] == -1){
                colour[i] = 0;
                c[0] = c[1] = 0;
                dfs(i);
                ans += max(c[0],c[1]);
            }
        }
        if(!ok){
            ans = -1;
        }
        cout<<ans<<"n";
    }
}
```
[1594E1 - Rubik's Cube Coloring (easy version)](../problems/E1._Rubik's_Cube_Coloring_(easy_version).md "Codeforces Round 747 (Div. 2)")

 **Hint**Think of how many colorings there are if you color only the root with one color.

 **Solution**
### [1594E1 - Rubik's Cube Coloring (easy version)](../problems/E1._Rubik's_Cube_Coloring_(easy_version).md "Codeforces Round 747 (Div. 2)")

You have 6 choices for the first node and 4 for each other node. Thus, the answer is 6⋅42k−2. 

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin>>k;
    ll othernodes = (1LL<<k) - 2;
    ll ans = power(4,othernodes,INF);
    ans *= 6;
    ans %= INF;
    cout<<ans<<"n";
}
```
[1594E2 - Rubik's Cube Coloring (hard version)](../problems/E2._Rubik's_Cube_Coloring_(hard_version).md "Codeforces Round 747 (Div. 2)")

 **Hint**If you have a tree with a root with a fixed color and the others are all not predefined the number of colorings is 4nodes−1.

 **Solution**
### [1594E2 - Rubik's Cube Coloring (hard version)](../problems/E2._Rubik's_Cube_Coloring_(hard_version).md "Codeforces Round 747 (Div. 2)")

Let's define a node as marked if it has a predefined node in its subtree. There is always at least 1 marked node since all predefined nodes are definitely marked. 

You can see that marked nodes form a path for the root to any predefined node. Thus there are at most n⋅k marked nodes and we can run a standard dp[i][j] on them (node i is colored with j). Depending on the implementation the dp can have time complexity O(n⋅k⋅6⋅4) or O(n⋅k⋅log(n⋅k)⋅6⋅4) if you use map.

You multiply the result with 4m where m is the number of unmarked nodes. This holds because if their parent has a fixed color they always have 4 choices and so on. 

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
ll dp[(60 * 10000) + 5][6];
vll color[6];
vector<vector<int> >adj;
map<ll,int>label;
ll c[(60 * 10000) + 5];
ll solve(int i,int j){
    if(c[i] != -1 && c[i] != j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans = 0;
    ll sum[2] = {0};
    for(auto x:color[j]){
        f(j,0,adj[i].size()){
            sum[j] += solve(adj[i][j],x);
            sum[j] %= INF;
        }
    }
    if(adj[i].empty()){
        sum[0] = sum[1] = 1;
    }
    if((ll)adj[i].size() == 1){
        sum[1] = 1;
    }
    ans = (sum[0] * sum[1]) % INF;
    return dp[i][j] = ans;
}
ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    color[0] = {1,2,4,5};
    color[1] = {0,2,3,5};
    color[2] = {0,1,3,4};
    color[3] = {1,2,4,5};
    color[4] = {0,2,3,5};
    color[5] = {0,1,3,4};
    map<string,ll>mp;
    mp["white"] = 0;
    mp["blue"] = 1;
    mp["red"] = 2;
    mp["yellow"] = 3;
    mp["green"] = 4;
    mp["orange"] = 5;
    memset(dp,-1,sizeof dp);
    memset(c,-1,sizeof c);
    ll k;
    cin>>k;
    ll n;
    cin>>n;
    ll posoi = (1LL<<k) - 1;
    int lab = 0;
    map<ll,int>ar;
    f(i,0,n){
        ll x;
        cin>>x;
        string s;
        cin>>s;
        ar[x] = mp[s];
        ll cur = x;
        while(cur >= 1 && !label.count(cur)){
            label[cur] = lab;
            lab++;
            posoi--;
            cur /= 2;
        }
    }
    adj.assign(lab + 5,vector<int>());
    for(auto x:label){
        if(ar.count(x.F)){
            c[x.S] = ar[x.F];
        }
        if(label.count(x.F * 2)){
            adj[x.S].pb(label[x.F * 2]);
        }
        if(label.count(x.F * 2 + 1)){
            adj[x.S].pb(label[x.F * 2 + 1]);
        }
    }
    ll ans = power(4,posoi,INF);
    ll sum = 0;
    f(j,0,6){
        sum += solve(label[1],j);
        sum %= INF;
    }
    ans *= sum;
    ans %= INF;
    cout<<ans<<"n";
}
```
[1594F - Ideal Farm](../problems/F._Ideal_Farm.md "Codeforces Round 747 (Div. 2)")

 **Solution**
### [1594F - Ideal Farm](../problems/F._Ideal_Farm.md "Codeforces Round 747 (Div. 2)")

The problem is the same as:

We have an array a of length n where every element of it is a positive integer and the sum of the whole array is s. If no matter how we construct the array a, we can find a non-zero length subarray which has sum equal to k print "YES" else print "NO".

If s=k then the answer is obviously "YES" and if s<k then the answer is obviously "NO".

Let pre[i]=∑j<=ij=1a[j] (1 - indexed)

All the elements of array pre are different as all a[i] are positive integers. Let b[i]=pre[i]+k but we also have b[0]=k.

Again all the elements of b are different because all a[i] are positive integers. 

Array pre has size n and array b has size n+1.

If and only if an element from pre is equal to an element from b then it means that pre[i]=pre[j]+k or pre[i]=k. If it is the second case then obviously there is a subarray with sum equal to k. 

If it's the first case then pre[i]−pre[j]=k so the subarray [j+1,i] has sum k.

But when do we have an equation in these two arrays?

There are n+(n+1)=2n+1 elements and they can be values from 1 to s+k.

If the maximum number of distinct elements that we can take is less than 2n+1 the answer is "YES" else the answer is "NO".

Let m be the maximum number of elements that we can take. 

We go through the last k elements ([s−k+1,s]) and we count the number of elements that have the same modulo k. 

For each element in this range, if there are odd elements that have the same modulo, we can't take all of them because for every element x that we add in pre that we also add x+k to b. Thus one element would have a x+k out of range.

Therefore we count all the elements that have odd elements with the same modulo k and subtract them from s+k to find m.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e9+7;
ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k,s;
        cin>>s>>n>>k;
        if(s == k){
            cout<<"YESn";
        }
        else if(k > s){
            cout<<"NOn";
        }
        else{
            ll posa = s+k;
            ll l = s-k+1,r = s;
            ll siz = r - l + 1;
            ll a = 0,b = 0;
            ll num = (s / k) * k;
            b = r - num + 1;
            a = siz - b;
            if((s / k) % 2 == 1){
                posa -= b;
            }
            else{
                posa -= a;
            }
            if((2 * n + 1) > posa){
                cout<<"YESn";
            }
            else{
                cout<<"NOn";
            }
        }
    }
}
```
