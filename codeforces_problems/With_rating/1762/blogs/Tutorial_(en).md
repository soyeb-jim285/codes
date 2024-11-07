# Tutorial_(en)

Thank you for participation! I hope you liked atleast one problem from the set (:

We tried hard to have an interesting problemset.

It is sad to see people disliking the round only because some problems were hard. Please read the intended solutions to know why we decided to put the problems(especially D) at current positions. 

[1762A - Divide and Conquer](../problems/A._Divide_and_Conquer.md "Codeforces Round 838 (Div. 2)")

Idea:[satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**If sum is even, answer is 0. Otherwise we need to change parity of atleast one element of a.

 **Hint 2**It it optimal to change parity of atmost one element. 

 **Hint 3**Answer can be atmost 20, as we need to divide any integer x (1≤x≤106) atmost 20 times to change its parity.

 **Solution**We are assuming initial sum is odd. Suppose f(x)(1≤x≤106) gives the minimum number of operations needed to change parity of x.

Iterate from i=1 to n and calculate f(ai) for each i.

Answer is minimum among all the calculated values.

Time complexity is O(n⋅log(Amax)).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    ll sum=0,ans=21;
    vector<ll> a(n);
    for(auto &it:a){
        cin>>it;
        sum+=it;
    }
    if(sum&1){
        for(auto &it:a){
            ll cur=it,now=0;
            while(!((cur+it)&1)){
                now++;
                cur/=2;
            }
            ans=min(ans,now);
        }
    }
    else{
        ans=0;
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
[1762B - Make Array Good](../problems/B._Make_Array_Good.md "Codeforces Round 838 (Div. 2)")

Idea:[satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**Suppose we have a prime number p. Suppose there are two perfect powers of p — l and r. Now it is easy to see max(l,r) is divisible by min(l,r).

 **Hint 2**So now we need to choose some prime number p. Let us start with the smallest prime number p=2.

 **Hint 3**Here is one interesting fact. There always exists a power of 2 in the range [x,2x] for any positive integer x.

 **Solution**Suppose f(x) gives the smallest power of 2 which is greater than x.

Iterate from i=1 to n and change ai to f(ai) by adding f(ai)−ai to i-th element. 

Time complexity is O(n⋅log(Amax)).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
ll f(ll x){
    ll cur=1;
    while(cur<=x){
        cur*=2;
    }
    return cur;
}
void solve(){
    ll n; cin>>n;
    cout<<n<<"n";
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        cout<<i<<" "<<f(x)-x<<"n";
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
[1762C - Binary Strings are Fun](../problems/C._Binary_Strings_are_Fun.md "Codeforces Round 838 (Div. 2)")

Idea:[satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**Let us first find f(s[1,n]). 

 **Hint 2**f(s[1,n])=2len−1 where len is the length of longest suffix of s in which all characters are same. 

 **Hint 3**How to prove the result in hint 2? 

First of all it is easy to see if all characters of s are same, f(s[1,n])=2n−1 as median is always si. 

Now we assume that s contains distinct characters. 

Suppose t is one good extension of s. Assume we are index i. If there exists an index j(j>i) such that si≠sj, we should have t2i≠si. 

Why? Assume k is the smallest index greater than i such that si≠sk. Now if we have t2i=si, sk can never be median of subarray t[1,2k−1]. So if longest suffix of s having same characters of starts at index i, t2j≠sj for all j(1≤j<i) and t2j can be anything(either 0 or 1) for all j(i≤j<n).

 **Solution**Now we know how to solve for whole string s.

We can similarly solve for all prefixes.

To find f(s[1,i]), we need to find the longest suffix of s[1,i] containing same character. 

We can easily calculate this all prefixes while moving from i=1 to n.

Time complexity is O(n).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
const ll MOD=998244353;
void solve(){
    ll n; cin>>n;
    string s; cin>>s; s=" "+s;
    ll ans=0,cur=1;
    for(ll i=1;i<=n;i++){
        if(s[i]==s[i-1]){
            cur=(2*cur)%MOD;
        }
        else{
            cur=1;
        }
        ans=(ans+cur)%MOD;
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
[1762D - GCD Queries](../problems/D._GCD_Queries_.md "Codeforces Round 838 (Div. 2)") 

Idea:[amurto](https://codeforces.com/profile/amurto "Master amurto") Prepared by:[errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hint 1**Intended solution uses 2⋅(n−2). You are allowed to guess two indices. Doesn't this hint towards something? 

 **Hint 2**If we can eliminate n−2 elements that cannot be 0 for sure, we are done.

 **Hint 3**Suppose we have three distinct indices i, j and k. Is it possible to remove one index(say x) out of these three indices such that px≠0 for sure. You are allowed to query two times. 

 **Solution**So suppose we have three distinct indices i, j and k.

Let us assume l=query(i,k) and r=query(j,k)

Now we have only three possibilities.

 * l=r In this case, pk cannot be 0. Why? pi and pj are distinct, and we have gcd(0,x)≠gcd(0,y) if x≠y

 * l>r In this case, pj cannot be 0. Why? Note gcd(0,pk)=pk and gcd(m,pk) can be atmost pk for any non negative integer. If l>r, this means r cannot be pk. Thus pr≠0 for sure

 * l<r In this case, pi cannot be 0. Why? Refer to the above argument.

This we can eliminate one index on using 2 queries. We will perform this operation n−2 times. Refer to attached code for details.

Time complexity is O(n).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){
    ll n; cin>>n;
    ll l=1,r=2;
    for(ll i=3;i<=n;i++){
        ll ql,qr;
        cout<<"? "<<l<<" "<<i<<endl;
        cin>>ql;
        cout<<"? "<<r<<" "<<i<<endl;
        cin>>qr;
        if(ql>qr){
            r=i;
        }
        else if(ql<qr){
            l=i;
        }
    }
    cout<<"! "<<l<<" "<<r<<endl;
    ll check; cin>>check;
    assert(check==1); 
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
[1762E - Tree Sum](../problems/E._Tree_Sum.md "Codeforces Round 838 (Div. 2)")

Idea:[satyam343](https://codeforces.com/profile/satyam343 "Master satyam343") Improved by:[TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**There does not exist any good tree of size n if n is odd. 

How to prove it? Suppose f(v) gives the product of weight of edges incident to node v in a good tree. We know that f(i)=−1 as if tree is good. Now ∏ni=1f(i)=−1 if n is odd. 

There is another way to find ∏ni=1f(i). Look at contribution of each edge. Each edge contribitues 1 to ∏ni=1f(i), no matter what the weight of this edge is, as it gets multiplied twice. Thus we get ∏ni=1f(i)=1. We got contradiction. Thus no good tree of size n exists.

 **Hint 2**Now assume n is even.

Here is an interesting claim. 

For any unweighted tree,there exists exactly **one** assignment of weight of edges which makes it good. 

Thus there are nn−2 distinct edge-weighted trees.

 **Hint 3**How to prove the claim in hint 2?

Arbitrarily root the tree at node 1. 

Now start from leaves and move towards root and assign the weight of edges in the path.

First of all the edge incident to any leaf node will have −1 as the weight. While moving towards root, it can be observed that weight of edge between u and parent of u depends on the product of weight of edges between u and its children. 

As we are moving from leaves towards root, weight of edges between u and its children are already fixed. Weight of edge between u and parent u is −1⋅∏x∈C(u)pw(x), where pw(x) gives the weight of edge between x and its parent, and C(u) denotes the set of children of u.

 **Solution**Time for one more interesting claim. The weight of edge e is (−1)l if there are l nodes on one side and n−l nodes on other side of e, irrespective of the structure of tree.

We can prove this claim by induction, similar to what we did in hint 3.

To find answer we will look at contribution of each edge. 

Here's detailed explanation on how to dot it.

In total, we have nn−2⋅(n−1) edges. 

Suppose for some edge(say e), we have l nodes(including node 1) on left side and r nodes(including node n) on right side. 

Among nn−2⋅(n−1) edges, how many possibilities do we have for e? 

It is (n−2l−1)⋅l⋅r⋅ll−2⋅rr−2. Why? First we select l−1 nodes(as node 1 is fixed to be on left side) to be on left side, we get (n−2l−1) for this.

Now we have l nodes on left side and r nodes on right side. Edge e will connect one among l nodes on left and one among r nodes on right. So edge e will exist between l⋅r pairs. We know that number of distinct trees having x nodes is xx−2.

Now on selecting one node from left and one from right, we have fixed the root of subtree on left side, and have also fixed the root of subtree on right side. So, number of distinct subtrees on left side is ll−2, and number of distinct subtrees on right side is rr−2. 

Thus, on mutliplying all(since they are independent), we get (nl)⋅l⋅r⋅ll−2⋅rr−2 possibilities for e.

Now this edge lies on the path from 1 to n as both lie on opposite sides of this node.

So this edge contributes (−1)l⋅(n−2l−1)⋅l⋅r⋅ll−2⋅rr−2 to answer.

Hence d(1,n)=∑n−1l=1(−1)l⋅(n−2l−1)⋅l⋅r⋅ll−2⋅rr−2 where l+r=n. Note that we assumed that we are always going from left subtree to right subtree while calculating contribution. As we have tried all possibilties for l, all cases get covered. We used left and right subtrees just for our own convention.

Time complexity is O(n⋅log(n)).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
const ll MOD=998244353;
const ll MAX=500500;
vector<ll> fact(MAX+2,1),inv_fact(MAX+2,1);
ll binpow(ll a,ll b,ll MOD){
    ll ans=1;
    a%=MOD;  
    while(b){
        if(b&1)
            ans=(ans*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return ans;
}
ll inverse(ll a,ll MOD){
    return binpow(a,MOD-2,MOD);
} 
void precompute(ll MOD){
    for(ll i=2;i<MAX;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    inv_fact[MAX-1]=inverse(fact[MAX-1],MOD);
    for(ll i=MAX-2;i>=0;i--){
        inv_fact[i]=(inv_fact[i+1]*(i+1))%MOD;
    }
}
ll nCr(ll a,ll b,ll MOD){
    if((a<0)||(a<b)||(b<0))
        return 0;   
    ll denom=(inv_fact[b]*inv_fact[a-b])%MOD;
    return (denom*fact[a])%MOD;  
}
void solve(){         
    ll n,ans=0; cin>>n;
    if(n&1){  
        cout<<0;    
        return;
    }
    ll sgn=1;  
    for(ll i=1;i<n;i++){ 
        sgn*=-1; 
        ll r=n-i,l=i;
        ll fix_l=nCr(n-2,l-1,MOD); //fixing l nodes on left side  
        ll fix_root=(l*r)%MOD; //fixing roots of subtrees on both sides 
        ll trees=(binpow(l,l-2,MOD)*binpow(r,r-2,MOD))%MOD; //counting no of subtrees
        ll no_of_e=(((fix_l*fix_root)%MOD)*trees)%MOD; //no of possibilities for e
        ans=(ans+sgn*no_of_e)%MOD;
    }     
    ans=(ans+MOD)%MOD;          
    cout<<ans; 
    return;            
} 
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    precompute(MOD);
    ll t=1; 
    //cin>>t;
    while(t--){
        solve();
    }
} 
```
[1762F - Good Pairs](../problems/F._Good_Pairs_.md "Codeforces Round 838 (Div. 2)") 

Idea:[satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**We should have |aij−aij+1|≤k. This seems a bit hard, as we can have aij+1 greater than, smaller than or equal to aij.

Why not solve the easier version first?

A pair (l,r) is *good* if there exists a sequence of indices i1,i2,…,im such that

 * i1=l and im=r;
* ij<ij+1 for all 1≤j<m; and
* 0<aij−aij+1≤k for all 1≤j<m.

Suppose F(a,k) number of pairs (l,r) (1≤l<r≤n) that are good.

Find F(a,k).

 **Hint 2**To solve the problem in hint 1, let us define dpi as the number of pairs j(i<j) such that (i,j) is good. 

Let us move from i=n to 1. To find dpi, let us first find the smallest index j such that aj lies in range [ai+1,ai+k].

We can observe that dpi=dpj+f(i,ai+1,aj), where f(i,l,r) gives us the number of indices x among last i elements of a such that ax lies in the range [l,r]. We can use fenwik tree or ordered set to find f(i,l,r).

 **Hint 3**Now let us get back to original problem. 

First let us count number of pairs (i,j)(1≤i≤j) such that ai=aj. Assume cnt is number of such pairs.

Time for another cool claim!

For our original problem, answer is cnt+F(a,k)+F(rev(a),k), where rev(a) denotes the array a when it is reversed.

 **Solution**How to prove the claim in hint 3? 

Suppose we have a good pair (l,r) such that al≠ar. Now using exchange arguments we can claim that there always exists a sequence(say s) starting at index l and ending at index r

 * such that difference between adjacent elements of a is atmost k
* strictly increasing if al<ar
* strictly decreasing if al>ar

Thus (l,r) will be counted in F(a,k) if al<ar and (l,r) will be counted in F(rev(a),k) if al>ar.

Time complexity is O(n⋅log(n)).

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
const ll MAX=1000100;
class ST{
public:
    vector<ll> segs;
    ll size=0;                       
    ll ID=MAX;
 
    ST(ll sz) {
        segs.assign(2*sz,ID);
        size=sz;  
    }   
   
    ll comb(ll a,ll b) {
        return min(a,b);  
    }
 
    void upd(ll idx, ll val) {
        segs[idx+=size]=val;
        for(idx/=2;idx;idx/=2){
            segs[idx]=comb(segs[2*idx],segs[2*idx+1]);
        }
    }
 
    ll query(ll l,ll r) {
        ll lans=ID,rans=ID;
        for(l+=size,r+=size+1;l<r;l/=2,r/=2) {
            if(l&1) {
                lans=comb(lans,segs[l++]);
            }
            if(r&1){
                rans=comb(segs[--r],rans);
            }
        }
        return comb(lans,rans);
    }
};
struct FenwickTree{
    vector<ll> bit; 
    ll n;
    FenwickTree(ll n){
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<ll> a):FenwickTree(a.size()){
        ll x=a.size();
        for(size_t i=0;i<x;i++)
            add(i,a[i]);
    }
    ll sum(ll r) {
        ll ret=0;
        for(;r>=0;r=(r&(r+1))-1)
            ret+=bit[r];
        return ret;
    }
    ll sum(ll l,ll r) {
        if(l>r)
            return 0;
        return sum(r)-sum(l-1);
    }
    void add(ll idx,ll delta) {
        for(;idx<n;idx=idx|(idx+1))
            bit[idx]+=delta;
    }
};
FenwickTree freq(MAX);  
ST segtree(MAX);
vector<ll> dp(MAX,0);
ll solve(vector<ll> a,ll n,ll k){
    ll now=0;
    for(ll i=n-1;i>=0;i--){  
        ll j=segtree.query(a[i]+1,a[i]+k);
        if(j<n){
            dp[i]=dp[j]+freq.sum(a[i]+1,a[j]);
        }
        else{
            dp[i]=0;
        }
        now+=dp[i];
        segtree.upd(a[i],i);
        freq.add(a[i],1);
    }  
    for(auto it:a){  
        segtree.upd(it,MAX);  
        freq.add(it,-1); 
    }
    return now;
}
void solve(){         
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    ll ans=0;
    map<ll,ll> cnt;  
    for(auto &it:a){
        cin>>it;
        cnt[it]++;
        ans+=cnt[it];
    }
    ans+=solve(a,n,k);
    reverse(a.begin(),a.end());
    ans+=solve(a,n,k);
    cout<<ans<<"n"; 
    return;            
} 
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll t=1; 
    cin>>t;
    while(t--){
        solve();
    }
} 
```
[1762G - Unequal Adjacent Elements](../problems/G._Unequal_Adjacent_Elements.md "Codeforces Round 838 (Div. 2)")

Idea:[satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**Answer is NO only when there exists an element of a which occurs more that ⌈n2⌉ times.

 **Hint 2**Let us say an array b is beautiful if length of b is odd and mode(say x) of b occurs exactly ⌈n2⌉ times. 

If a is beautiful, there exists only one permutation. 

We have rearrange such that x occupies all the odd indices and keep the elements at even indices such that condition 2 in satisfied.

 **Hint 3**To solve the original problem, we will divide the array a into multiple beautiful subarrays and arrange the elements in those subarrays. 

 **Solution**Let us continue from where we left off.

So our motivation is to break the original array into multiple beautiful subarrays and the elements in those subarrays, as mentioned before. Now for condition 1 to be satisfied, we should not have two adjacent subarrays such that the elements at the end positions of both subarrays(after rearranging the elements) are the same.

Here is one construction using which we can achieve our goal.

Suppose l denotes the leftmost point of our concerned subarray.

If al≠al+1, we move forward, as subarray a[l,l] is good.

Otherwise, we keep moving towards the right till index r(here, r should be the smallest possible) such that the subarray a[l,r] is beautiful and al≠ar+1. So it is easy to notice the following observations about the subarray a[l,r]

 * length of this subarray is odd
* al occurs exactly ⌈r−l+12⌉ times in this subarray

Now we can rearrange the elements of this subarray a[l,r].

Do note that the subarray a[1,r] satisfies both the conditions stated in the statement.

So our task is to make the subarray a[r+1,n] good now. 

We can now update l=r+1 and continue searching for the corresponding r and so on.

Now it might be the case that we did not get a valid r for the last search. 

From here, I assume we did not get valid r for the last search. We could print the obtained permutation if we got it, as a would satisfy both conditions.

Assume that we had started at pos=l and couldn't find r. 

Subarray a[1,pos−1] is already good.

To fix this issue, we will do a similar search that we did before.

We start from the back(from index n) and move towards left till index m such that

 * m<pos
* a[m,n] is beautiful
* apos occurs exactly ⌈n−m+12⌉ times in this subarray
* apos≠am−1

Now we arrange elements of this subarray in the same fashion that we did before. 

Are we done? 

No. First, we must prove that we will always get some m.

Let us have function f(a,l,r,x), which denotes the score of the subarray a[l,r] for the element x. f(a,l,r,x)=freqx−(r−l+1−freqx), where freqx denotes the frequency of element x in the subarray a[l,r] 

It is easy to note that f(a,pos,n,apos)>1 

(Hint — Prove that f(a,pos,r,apos)≠0 for pos≤r≤n. Why?(If it does then a[pos,r−1] would be beautiful ))

Now we start from the back and move towards the right to find m with n as our right endpoint of the concerned subarray. 

Note that f(a,1,n,apos)≤1 (Why? apos would have occurred at most ⌈n2⌉ times in a)

So while moving from pos to 1 we will indeed find a m such that f(a,m,n,apos)=1, and am−1≠apos (assuming a0=−1)

Are we done?

Not still :p. We can observe that condition 1 is satisfied, but sometimes condition 2 would not be. For example, simulate the above approach on the array a=[1,1,2,3,3].

How to fix this issue? It's pretty easy to fix this issue.

 **Hint**Instead of rearranging the subarray a[m,n], we will rearrange the subarray a[m−1,n]. 

How to rearrange? 

Okay, time for one more hint.

What will be the answer for a=[1,1,2,3,3]?

 **Answer**p=[1,4,2,5,3]

You can refer to the attached code for implementation details.

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;  
#define ll long long  
#define all(x) x.begin(),x.end()     
void solve(){    
    ll n; cin>>n;
    vector<ll> a(n+5),freq(n+5,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i]; freq[a[i]]++;
    }
    for(ll i=1;i<=n;i++){
        ll till=(n+1)/2;
        if(freq[i]>till){
            cout<<"NOn";
            return;
        }
    }
    cout<<"YESn";
    vector<ll> ans;
    ll cur=1;
    while(cur<=n){
        ll val=a[cur];
        vector<ll> v1,v2;
        while(cur<=n){
            if(a[cur]==val){
                v1.push_back(cur);
            }
            else{
                v2.push_back(cur);
            }
            if(v1.size()==v2.size()){
                for(ll i=0;i<v1.size();i++){
                    ans.push_back(v1[i]); ans.push_back(v2[i]);
                }
                ans.pop_back();
                break; 
            }
            if(cur==n){
                while(1){
                    if(ans.empty()||v1.size()==v2.size()){
                        sort(all(v1)); sort(all(v2));
                        if(v1.size()!=v2.size()){
                            ans.push_back(v1[0]);
                            v1.erase(v1.begin());
                        }
                        if(!v2.empty()&&!ans.empty()){
                            if(a[ans.back()]==a[v2[0]]){
                                swap(v1,v2);
                            }
                        }
                        for(ll i=0;i<v1.size();i++){
                            ans.push_back(v2[i]); ans.push_back(v1[i]);  
                        }
                        break;
                    }
                    if(a[ans.back()]==val){
                        v1.push_back(ans.back());
                    }
                    else{
                        v2.push_back(ans.back());
                    }
                    ans.pop_back();
                }
                cur=n+1;
            }
            cur++;
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<"n";
    return;                                
}                                                
int main()                                                                                             
{                          
    ll test_cases=1;               
    cin>>test_cases;
    while(test_cases--){
        solve();
    } 
}  
```
