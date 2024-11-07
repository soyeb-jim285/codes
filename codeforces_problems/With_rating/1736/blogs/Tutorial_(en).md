# Tutorial_(en)

Thank you for participation! We apologize for problem D that turned out to be harder than expected. Still, we hope that you liked most of the problems.

In case you found C2 tedious to implement or found many cases to deal with, I would recommend you to have a look at the intended solution. I think it is interesting and easy to implement.

[1736A - Make A Equal to B](../problems/A._Make_A_Equal_to_B.md "Codeforces Round 825 (Div. 2)")

 **Solution**It is easy to observe that the second operation needs to be performed **at most** once. Now, we just need to check 2 cases, one in which the re-arrangement operation is used, and one in which it is not.

If the re-arrangement operation is to be used, then we just need to make the counts of 0s and 1s in a equal to that of b. Without loss of generality assume a contains x more 0s than b, then the cost in this case will just be x+1 (extra one for re-arrangement cost).

If the re-arrangement operation is not to be used, then we just need to make each element of a equal to the corresponding element of b.

Finally, our answer is the smaller cost of these 2 cases.

Time complexity is O(n).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    ll sum=0,ans=0;
    vector<ll> a(n),b(n);
    for(auto &it:a){
        cin>>it;
        sum+=it;
    }
    for(auto &it:b){
        cin>>it;
        sum-=it;
    }
    for(ll i=0;i<n;i++){
        ans+=(a[i]^b[i]);
    }
    ans=min(ans,1+abs(sum));
    cout<<ans<<"n";
}
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll t; cin>>t;
    while(t--){
        solve();
    }
}  
```
[1736B - Playing with GCD](../problems/B._Playing_with_GCD.md "Codeforces Round 825 (Div. 2)")

 **Solution**Take a0=an+1=1.

Now take bi=lcm(ai−1,ai) for 1≤i≤n+1. If b gives us a after performing the gcd operations, then the answer is YES, otherwise the answer is NO. (When answer is NO, we would get a case like gcd(bi,bi+1)=k⋅ai(where k>1 for some i).

Suppose c is some valid array which gives us a. So, ci should be divisible by bi. This means gcd(ci,ci+1)≥gcd(bi,bi+1).

So, if gcd(bi,bi+1)>ai for any i, we should also have gcd(ci,ci+1)>ai. This implies that c is not valid if b is not valid.

Time complexity is O(n⋅log(bmax)).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
ll lcm(ll a,ll b){
    ll g=__gcd(a,b);
    return (a*b/g);
}
void solve(){
    ll n; cin>>n;
    vector<ll> a(n+2,1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> b(n+2,1);
    for(ll i=1;i<=n+1;i++){
        b[i]=lcm(a[i],a[i-1]);
    }
    for(ll i=1;i<=n;i++){
        if(__gcd(b[i],b[i+1])!=a[i]){
            cout<<"NOn";
            return;
        }
    }
    cout<<"YESn";
}
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll t; cin>>t;
    while(t--){
        solve();
    }
}  
```
[1736C1 - Good Subarrays (Easy Version)](../problems/C1._Good_Subarrays_(Easy_Version).md "Codeforces Round 825 (Div. 2)")

 **Solution**Suppose l[i] represents the leftmost point such that subarray a[l[i],i] is good. 

Notice that the array l is non-decreasing. 

So suppose dp[i] denotes the length of longest good subarray which ends at index i.

Take dp[0]=0.

Now dp[i]=min(dp[i−1]+1,a[i]).

Suppose a[i]≥dp[i−1]+1. Now we claim that dp[i]=dp[i−1]+1. We know a[i−dp[i−1],i−1] is \t{good}. Now if we look at array b=a[i−dp[i−1],i], bi≥i for 1≤i≤dp[i−1]. For b to be good, last element of b(which is a[i]) should be greater than or equal dp[i−1]+1(which is consistent with our supposition). So b is good.

We can similarly cover the case when a[i]<dp[i−1]+1.

So our answer is ∑ni=1dp[i]. Time complexity is O(n).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    vector<ll> dp(n+5,0);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        dp[i]=min(dp[i-1]+1,x);
        ans+=dp[i];
    }
    cout<<ans<<"n";
}
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll t; cin>>t;
    while(t--){
        solve();
    }
}  
```
[1736C2 - Good Subarrays (Hard Version)](../problems/C2._Good_Subarrays_(Hard_Version).md "Codeforces Round 825 (Div. 2)")

 **Solution**Let us continue the idea of C1. 

Suppose track[i] denotes ∑nj=idp[j] if dp[i]=a[i].

We can precalculate array track.

Now suppose ap is changed to x and adp[i] denotes the length of longest good subarray which ends at index i in the updated array. 

It is easy to see that adp[i]=dp[i] for 1≤i<p. Now let q be the smallest index greater than p such that adp[q]=a[q](It might be the case that there does not exist any such q which can be handled similarly). So we have 3 ranges to deal with — (1,p−1), (p,q−1) and (q,n). 

Now ∑p−1i=1adp[i] = ∑p−1i=1dp[i](which can be stored as prefix sum).

Also ∑ni=qadp[i] = track[q].

Now we only left with range (p,q−1). An interesting observation is adp[i]=adp[i−1]+1 for p<i<q.

This approach can be implemented neatly in many ways(one way is answer each query offline).

Time complexity is O(n⋅log(n)).

 **Code(Offline queries)**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
#define f first
#define s second
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll n; cin>>n;
    vector<ll> track(n+5,0),sum(n+5,0);
    vector<pair<ll,pair<ll,ll>>> trav; 
    vector<ll> pref(n+5,0),dp(n+5,0);
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        sum[i]=sum[i-1]+i; trav.push_back({x-i,{i,0}});
        dp[i]=min(dp[i-1]+1,x); pref[i]=pref[i-1]+dp[i];    
    }
    ll q; cin>>q;
    vector<ll> ans(q+5,0);  
    for(ll i=1;i<=q;i++){
        ll p,x; cin>>p>>x; x=min(dp[p-1]+1,x); 
        trav.push_back({x-p,{p,i}});
    }
    set<ll> found; found.insert(n+1);  
    sort(trav.begin(),trav.end()); 
    for(auto it:trav){
        if(it.s.s){
            ll r=*found.upper_bound(it.s.f);
            ans[it.s.s]=pref[it.s.f-1]+track[r]+sum[r-it.s.f]+(it.f+it.s.f-1)*(r-it.s.f);
        }
        else{
            ll r=*found.lower_bound(it.s.f); found.insert(it.s.f);
            track[it.s.f]=track[r]+sum[r-it.s.f]+(it.f+it.s.f-1)*(r-it.s.f);
        }
    }
    for(ll i=1;i<=q;i++){
        cout<<ans[i]<<"n";
    }
}  
```
 **Code(Online queries)**
```cpp
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long  
const ll INF_MUL=1e13;
const ll INF_ADD=1e18;  
#define pb push_back               
#define mp make_pair        
#define nline "n"                         
#define f first                                          
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()   
#define vl vector<ll>         
#define vvl vector<vector<ll>>    
#define vvvl vector<vector<vector<ll>>>          
#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);  
#endif     
const ll MOD=1e9+7;     
const ll MAX=100010;   
ll cal(ll n){
    ll now=(n*(n+1))/2;      
    return now; 
} 
class ST {
public:
    vector<ll> segs;
    ll size = 0;
    ll ID = INF_ADD;
 
    ST(ll sz) {
        segs.assign(2 * sz, ID);  
        size = sz;  
    }   
      
    ll comb(ll a, ll b) {
        return min(a, b);  
    }
 
    void upd(ll idx, ll val) {
        segs[idx += size] = val;
        for(idx /= 2; idx; idx /= 2) segs[idx] = comb(segs[2 * idx], segs[2 * idx + 1]);
    }
 
    ll query(ll l, ll r) {
        ll lans = ID, rans = ID;  
        for(l += size, r += size + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) lans = comb(lans, segs[l++]);
            if(r & 1) rans = comb(segs[--r], rans);
        }
        return comb(lans, rans);
    }
};  
void solve(){  
    ll n; cin>>n;
    vector<ll> a(n+5,0),use(n+5,0),pref(n+5,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];  
        use[i]=min(use[i-1]+1,a[i]); pref[i]=pref[i-1]+use[i]; 
    }
    ST segtree(n+5);  
    auto get=[&](ll l,ll r,ll till,ll pos,ll tar){
        while(l<=r){
            ll mid=(l+r)/2;     
            if(segtree.query(pos,mid)>=tar){     
                till=mid,l=mid+1;  
            }     
            else{
                r=mid-1;         
            }  
        }  
        return till;        
    };        
    vector<ll> track(n+5,0);         
    for(ll i=n;i>=1;i--){   
        segtree.upd(i,a[i]-i); ll till=get(i,n,i,i,a[i]-i);  
        track[i]=track[till+1]+cal(a[i]+till-i)-cal(a[i]-1); 
    }
    ll q; cin>>q;
    while(q--){
        ll p,x; cin>>p>>x; ll target=min(x,use[p-1]+1);
        ll till=get(p+1,n,p,p+1,target-p);
        ll ans=pref[p-1]+track[till+1]+cal(target+till-p)-cal(target-1);
        cout<<ans<<nline;
    }
    return;
}                 
int main()                                                                           
{                     
    ios_base::sync_with_stdio(false);                           
    cin.tie(NULL);                         
    #ifndef ONLINE_JUDGE               
    freopen("input.txt", "r", stdin);                                           
    freopen("output.txt", "w", stdout);  
    freopen("error.txt", "w", stderr);                        
    #endif    
    ll test_cases=1;                   
    //cin>>test_cases;
    while(test_cases--){   
        solve();     
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
} 
```
[1736D - Equal Binary Subsequences](../problems/D._Equal_Binary_Subsequences.md "Codeforces Round 825 (Div. 2)")

 **Solution**It is easy to see that a necessary condition for a solution to exist is that the number of 1 in s should be even. It turns out that this condition is sufficient too.

Here is one valid construction:

We make n pairs of the form (s[2i−1],s[2i]) for (1≤i≤n).

Assume we have x pairs in which both elements are different and n−x pairs in which both elements are same.

\textbf{Claim} — x should be even.

\textbf{Proof} — Assume that among the n−x pairs in which both elements are same, we have y pairs in which both elements are 1. So number of 1 in s is x+2⋅y. We know that number of 1 in s is even, so for x+2⋅y to be even, x should also be even.

Now we will select x indices; exactly one index from each of the x pairs in which both elements are distinct. Take the index of 0 from ith pair if i is odd, else take the index of 1. Thus our selected characters = 0,1,0,1,…,0,1

Now on cyclically shifting the selected characters clockwise once, we can see that elements at selected indices got flipped.

Since, elements in those x pairs were distinct initially, and we flipped exactly one character from each of those x pairs, both elements of those x pairs are same now.

Hence, in updated s, s[2i−1]=s[2i].

So, for s1, we can select characters of all odd indices.

Finally we'll have s1=s2. Time complexity is O(n).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll freq=0;
    vector<ll> ans;
    ll need=0;
    for(ll i=0;i<2*n;i+=2){
        if(s[i]!=s[i+1]){
            freq++;
            ans.push_back(i+1);
            if(s[i]-'0'!=need){
                ans.back()++;
            }
            need^=1;
        }
    }
    if(freq&1){
        cout<<"-1n";
        return;
    }
    cout<<ans.size()<<" ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<"n";
    for(ll i=1;i<=2*n;i+=2){
        cout<<i<<" n"[i+1==2*n];
    }
}
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll t; cin>>t;
    while(t--){
        solve();
    }
}  
```
[1736E - Swap and Take](../problems/E._Swap_and_Take.md "Codeforces Round 825 (Div. 2)")

 **Solution**As the constraints suggest, we should use dp to solve this problem. 

Let's write the original indices of the array that are added during this process — p1,p2,…,pn. None of added numbers are zeroed in an optimal answer. It gives that p1≤p2≤…≤pn and the answer is equal to the sum of a[pk] (1≤k≤n). 

To get the optimal answer we'll use dp[t][last][m] = maximum score on t-th turn if pt=last and we have performed m swapping moves (the first dimension can be omitted). Note that **m≤i**. It can be updated by considering the next index but it will take O(n4). The most straightforward way to improve it to O(n3) is to use prefix maximums.

Here are some details.

We have only two cases:

 1. pt=pt−1 — In this case, our transition is just dp[t][last][m]=dp[t−1][last][m−1]+a[last]
2. pt>pt−1 — Let us make some observations. First of all, pt≥t. So number of swaps to bring pt to index t is fixed. It is pt−t. So dp[t][last][m]=maxlast−1j=1(dp[t−1][j][m−(pt−t)])+a[last]. Note that we can find maxlast−1j=1(dp[t−1][j][m−(pt−t)]) in O(1). Hint — use prefix maximum.

Time complexity is O(n3).

 **Code**
```cpp
#include <bits/stdc++.h>   
using namespace std;
const int MAX=505; 
vector<vector<vector<int>>> dp(MAX,vector<vector<int>>(MAX,vector<int>(MAX,-(int)(1e9))));
int main()                                                                          
{                        
    int n; cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> prefix(n+5,vector<int>(n+5,0));
    int ans=0;  
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ 
            for(int k=0;k<=i;k++){
                if(k){ 
                    dp[i][j][k]=dp[i-1][j][k-1]+a[j];
                }
                if(j>=i){
                    int need=j-i;
                    if(need>k){
                        continue;
                    }
                    dp[i][j][k]=max(dp[i][j][k],prefix[k-need][j-1]+a[j]); 
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<=i;k++){
                prefix[k][j]=max(prefix[k][j],dp[i][j][k]); 
            }
        }
        for(int j=0;j<=i;j++){
            for(int k=1;k<=n;k++){
                prefix[j][k]=max(prefix[j][k],prefix[j][k-1]);
                ans=max(ans,prefix[j][k]);
            }
        }
    }
    cout<<ans;
} 
```
