# Tutorial_(en)

Thank you for your participation! I hope you liked atleast one problem from the set (:

[1930A - Maximise The Score](../problems/A._Maximise_The_Score.md "think-cell Round 1")

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [Non-origination](https://codeforces.com/profile/Non-origination "Expert Non-origination")

 **Hint 1**Selecting the smallest two elements on the whiteboard is a good choice in the first move.

 **Solution**Let b denote the sorted array a. Assume that b contains only distinct elements for convenience. We prove by induction on n that the maximum final score is b1+b3+…+b2n−1.

For the base case n=1, the final and only possible score that can be achieved is b1.

Now let n>1. 

**Claim**: It is optimal to choose b1 with b2 for some move.

 **Proof**Suppose that in some move, b1 is choosen with bi and b2 is choosen with bj, for some 2<i,j<2n,i≠j.

The contribution to the score according to these choices is min.

However, if we had chosen b_{1} and b_{2} in one move, and b_i and b_j in the other move, the score according to these choices is \min(b_{1}, b_{2}) + \min(b_{i}, b_{j}) = b_{1} + \min(b_{i}, b_{j}). 

As i, j > 2, b_i > b_{2} and b_j > b_{2} \implies \min(b_{i}, b_{j}) > b_2. Thus, we can achieve a strictly larger score by choosing b_1 with b_2 in some move.

The choice of selecting b_1 and b_2 contributes a value of b_1 to the score. The maximum score that can achieved for the remaining numbers [b_3, b_4, \ldots, b_{2n}] on the whiteboard in the remaining moves is b_3 + b_5 + b_7 + \ldots b_{2n-1} by the induction hypothesis.

Note that we can extend the arguments for the case where a has duplicate elements.

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){ 
    ll n; cin>>n;
    vector<ll> a(2*n);
    ll ans=0;
    for(auto &it:a){
        cin>>it;
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<2*n;i+=2){
        ans+=a[i];
    }
    cout<<ans<<"n";
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[video editorial by aryanc403](https://codeforces.com/https://youtu.be/OJdMGnC7SHM)

[1930B - Permutation Printing](../problems/B._Permutation_Printing.md "think-cell Round 1")

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**For integers x (\lfloor \frac{n}{2} \rfloor < x \leq n), there does not exist integer y (y > x) such that y is divisible by x.

 **Solution**Consider the permutation p such that p=[1, n, 2, n - 1, \ldots \lceil \frac{n+1}{2} \rceil]. It is valid. Why?

 **Proof**We have \max(p_a, p_{a+1}) > \lfloor \frac{n}{2} \rfloor for all 1 \leq a < n - 1. So we cannot ever have a pair of integers (a,b) such that:

 * 1 \leq a < n - 1
* 1 \leq b < n
* a \neq b
* p_a divides p_b and p_{a+1} divides p_{b+1}

Now, we just need to check for a = n - 1. First of all, notice that p_a does not divide p_1.

There does not exist an integer b (2 \leq b < n - 1) such that p_{a+1} divides p_{b+1} as 2 \cdot p_{a+1} \ge n and p_{c+1} < n for all c (2 \leq c < n - 1).

Note that we covered all possible pairs of indices and did not find two **distinct** indices i and j (1 \leq i, j < n; i \neq j) such that p_i divides p_j and p_{i+1} divides p_{j+1}.

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){ 
    ll n; cin>>n;
    ll l=1,r=n;
    for(ll i=1;i<=n;i++){
        if(i&1){
            cout<<l<<" ";
            l++;
        }
        else{
            cout<<r<<" ";
            r--;
        }
    }
    cout<<"n";
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[video editorial by aryanc403](https://codeforces.com/https://youtu.be/woPPBKBkCFk)

[1930C - Lexicographically Largest](../problems/C._Lexicographically_Largest.md "think-cell Round 1")

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [Non-origination](https://codeforces.com/profile/Non-origination "Expert Non-origination") and [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**Consider an array c of length n such that c_i := *number of indices smaller than i which were chosen before index i*.

So set S will be a collection of a_i + i - c_i over all 1 \leq i \leq n.

 **Solution**Now one might wonder what type of arrays c is it possible to get.

First, it is easy to see that we should have 0 \leq c_i < i for all i. Call an array c of length n *good*, if 0 \leq c_i < i for all 1 \leq i \leq n. The claim is that all *good* arrays of length n can be obtained.

 **Proof**We can prove it by induction on n. 

c_1 = 0 always holds. Now c_2 can either be 0 or 1. We can obtain c_2 = 0 by deleting the element at index 2 before the element at index 1. We can also obtain c_2 = 1 by deleting it after deleting the element at index 1. Thus, all *good* arrays of length 2 can be obtained. 

Now assume that it is possible to obtain all *good* arrays of length atmost k. Choose an integer x (0 \leq x \leq k) arbitrarily. Consider the following sequence for the order of deletion:

 * The elements at indices 1, 2, \ldots, x in the same order.
* The element at index k.
* The elements at indices x + 1, \ldots, k - 1 in the same order.

It is easy to see that the array obtained on performing the above sequence of operations is a *good* array of length k + 1 with c_{k+1} = x. Hence we can establish a bijection between the sequence of order of deletion and the number of *good* arrays.

So we have the following subproblem. We have a set S. We will iterate i from 1 to n, select an integer c_i (0 \leq c_i \leq i - 1) and insert a_i + i - c_i into set S and move to i + 1. Now using exchange arguments, we can prove that it is never bad if we select the smallest integer v (0 \leq v \leq i - 1) such that a_i + i - v is not present in the set S, and assign it to c_i. Note that as we have i options for v, and we would have inserted exactly i-1 elements before index i, there always exists an integer v (0 \leq v \leq i - 1) such that a_i + i - v is not present in the set S. You can refer to the attached submission to see how to find v efficiently for each i.

 **Code**
```cpp
#include <bits/stdc++.h>     
using namespace std;
#define ll long long
void solve(){ 
    ll n; cin>>n;
    set<ll> used,not_used;
    vector<ll> ans;
    for(ll i=1;i<=n;i++){
        ll x; cin>>x; x+=i;
        if(!used.count(x)){
            not_used.insert(x);
        }
        ll cur=*(--not_used.upper_bound(x)); //find the largest element(<= x) which is not in set "used"
        not_used.erase(cur);
        ans.push_back(cur);
        used.insert(cur);
        if(!used.count(cur-1)){
            not_used.insert(cur-1);
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }  
    cout<<"n";
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[video editorial by aryanc403](https://codeforces.com/https://youtu.be/d8_f4ae0lJ8)

[1930D1 - Sum over all Substrings (Easy Version)](../problems/D1._Sum_over_all_Substrings_(Easy_Version).md "think-cell Round 1") 

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**To find f(s), we can partition s into multiple independent substrings of length atmost 3 and find best answer for them separately.

 **Hint 2**There always exists a string g such that:

 1. g is s-good
2. there are f(s) number of \mathtt{1} s in g
3. g is of the form b_1 + b_2 + \ldots b_q, where b_i is either equal to \mathtt{0} or \mathtt{010}.
 **Solution**First of all, append n \mathtt{0}  s to the back of s for our convenience. Note that this does not change the answer. 

Now let us call a binary string p of size d *nice* if:

 1. there exists a positive integer k such that d = 3k
2. p is of form  f(\mathtt{0} , k) + f(\mathtt{1} , k) + f(\mathtt{0} , k) , where f(c, z) gives a string containing exactly z characters equal to c.

Suppose binary string t is one of the s-good strings such that there are exactly f(s) \mathtt{1}  s in t. 

We claim that for any valid t, there always exists a binary string t' such that:

 1. t' is permutation of t
2. t' is s-good
3. t' is of the form f(\mathtt{0}, d_1) + z_1 + f(\mathtt{0}, d_2) + z_2 + f(\mathtt{0}, d_3) + \ldots + z_g + f(\mathtt{0}, d_{g+1}) , where z_1, z_2, \ldots z_g are *nice* binary strings and d_1, d_2, \ldots d_{g+1} are non-negative integers.

 **Proof**Initially, all the \mathtt{1} s in s are unmarked. We will mark all of them and modify the string t in the process.

We will do the following recursive process unless all the \mathtt{1}  s in s are marked.

Find the index of leftmost unmarked \mathtt{1}  in s. Suppose its index is x. Now suppose y is the largest index such that there are an equal number of \mathtt{0}  s and \mathtt{1}  s in substring t[x, y]. Note that y will always exist as we appended some extra \mathtt{0} s in the starting. Now we can rearrange the characters in substring t[x,y], as they will still contain an equal number of \mathtt{0}  s and \mathtt{1}  s and \mathtt{1}  will still be the mode of substring t[x,y]. Obviously rearranging the characters in t[x,y] to \mathtt{0} \ldots \mathtt{0} \mathtt{1} \ldots \mathtt{1} is the best we can do. We will mark all the \mathtt{1}  s in substring s[x,y]. Suppose y-x+1 = 2v. Now t[y+1,y+v] might contain some \mathtt{1}  s. Say there are z \mathtt{1}  s in t[y+1,y+v] initially. We will do the following operation exactly z times. 

 * Find the leftmost \mathtt{1}  in substring t[y+1,y+v]. Find the leftmost \mathtt{0}  in substring t[y+v+1,2n]. Swap both characters.

Now note that t[x,x+3v-1] will be of form f(\mathtt{0}, v) + f(\mathtt{1}, v) + f(\mathtt{0}, v). It is easy to verify that in the updated t, there won't be any index i for which there does not exist two indices 1 \le l \le i \le r \le 2n such that s_i is *mode* of t[l,r].

Now we can mark all the \mathtt{1}  s in substring s[x+2v,x+3v-1] too, as t[x+v,x+3v-1] contain equal number of \mathtt{0}  s and \mathtt{1}  s.

It is not hard to conclude that the updated t will be of form f(\mathtt{0}, d_1) + z_1 + f(\mathtt{0}, d_2) + z_2 + f(\mathtt{0}, d_3) + \ldots + z_g + f(\mathtt{0}, d_{g+1}) , where z_1, z_2, \ldots z_g are *nice* binary strings and d_1, d_2, \ldots d_{g+1} are non-negative integers.

Note that the \mathtt{1} s in t[x, x + 3v - 1] won't help the \mathtt{1} s in s[x + 3v, 2n]. So, we can solve for s[x + 3v, 2n] independently.

Let t' be the updated t.

Now, carefully observe the structure of t'. We can replace all the substrings of the form  f(\mathtt{0} , k) + f(\mathtt{1} , k) + f(\mathtt{0} , k)  in t' with  \mathtt{0} \mathtt{1} \mathtt{0} \mathtt{0} \mathtt{1} \mathtt{0} \ldots \mathtt{0} \mathtt{1} \mathtt{0} \mathtt{0} \mathtt{1} \mathtt{0}.

So the updated t'(say t") will be of form b_1 + b_2 + \ldots b_q, where b_i is either equal to \mathtt{0} or \mathtt{010}.

So whenever we need to find f(e) for some binary string e, we can always try to find a string of form t" using as few \mathtt{1} s as possible. Notice that we can construct t" greedily. You can look at the attached code for the implementation details. Also, we don't need to actually append the \mathtt{0} s at the back of s. It was just for proof purposes.

 **Code**
```cpp
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll long long
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
const ll MOD=1e9+7;
const ll MAX=500500;
ll f(string s){
    ll len=s.size(),ans=0,pos=0;
    while(pos<len){
        if(s[pos]=='1'){
            ans++;
            pos+=2;
        }
        pos++;
    }
    return ans;
}
void solve(){ 
    ll n,ans=0; cin>>n;
    string s; cin>>s; 
    for(ll i=0;i<n;i++){
        string t; 
        for(ll j=i;j<n;j++){
            t.push_back(s[j]);
            ans+=f(t);
        }
    }
    cout<<ans<<nline;
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[1930D2 - Sum over all Substrings (Hard Version)](../problems/D2._Sum_over_all_Substrings_(Hard_Version).md "think-cell Round 1") 

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**We can use the idea of D1 and dynamic programming to solve in O(n).

 **Solution**Suppose dp[i][j] denotes f(s[i,j]) for all 1 \le i \le j \le n. 

Performing the transition is quite easy.

If s_i = \mathtt{1}, dp[i][j]=1+dp[i+3][j], otherwise dp[i][j]=dp[i+1][j]. Note that dp[i][j] = 0 for if i > j.

So if we fix j, we can find dp[i][j] for all 1 \le i \le j in O(n), and the original problem in O(n^2).

Now, we need to optimise it. 

Suppose track[i] = \sum_{j=i}^{n} dp[i][j] for all 1 \le i \le n, with base condition that track[i] = 0 if i > n.

There are two cases:

 * s_i = \mathtt{0} :

 1. track[i] = \sum_{j=i}^{n} dp[i][j]
2. track[i] = dp[i][i] + \sum_{j=i+1}^{n} dp[i][j]
3. track[i] = dp[i][i] + \sum_{j=i+1}^{n} dp[i+1][j]
4. track[i] = track[i+1] as dp[i][i]=0

 * s_i = \mathtt{1} :

 1. track[i] = \sum_{j=i}^{n} dp[i][j]
2. track[i] = \sum_{j=i}^{n} 1 + dp[i+3][j]
3. track[i] = n - i + 1 + \sum_{j=i+3}^{n} dp[i+3][j] as dp[i+3][i]=dp[i+3][i+1]=dp[i+3][i+2]=0
4. track[i] = n - i + 1 + \sum_{j=i+3}^{n} dp[i+3][j]
5. track[i] = n - i + 1 + track[i+3]

So, the answer to the original problem is \sum_{i=1}^{n} track[i], which we can do in O(n).

 **Code**
```cpp
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll long long
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
const ll MOD=1e9+7;
const ll MAX=500500;
void solve(){ 
    ll n,ans=0; cin>>n;
    string s; cin>>s; s=" "+s;
    vector<ll> dp(n+5,0);
    for(ll i=n;i>=1;i--){
        if(s[i]=='1'){
            dp[i]=dp[i+3]+n-i+1;
        }
        else{
            dp[i]=dp[i+1];
        }
        ans+=dp[i];
    }
    cout<<ans<<nline;
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[1930E - 2..3...4.... Wonderful! Wonderful!](../problems/E._2..3...4...._Wonderful!_Wonderful!.md "think-cell Round 1") 

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**Suppose you are given some array b of length m and a positive integer k. How to check whether we can get the array b if we start with an array a of length n such that a_i = i for all i (1 \leq i \leq n)?

 **Hint 2**First of all, array b should be a subsequence of a. Now consider an increasing array c (possibly empty) such that it contains all the elements of a which are not present in b. Now look at some trivial necessary conditions. 

 * The length of array c should divisible by 2k, as exactly 2k elements were deleted in one operation.
* There should be atleast one element v in b such that there are atleast k elements smaller than v in the array c, and alteast k elements greater than v in the array c. Why? Think about the last operation. We can consider the case of empty c separately.

In fact, it turns out that these necessary conditions are sufficient (Why?).

 **Solution**Now, we need to find the number of possible b. We can instead find the number of binary strings s of length n such that s_i = 1 if i is present in b, and s_i=0 otherwise.

For given n and k, let us call s **good** if there exists some b which can be achieved from a. 

Instead of counting strings s which are **good**, let us count the number of strings which are not **good**. 

For convenience, we will only consider strings s having the number of \mathtt{0}'s divisible by 2k. 

Now, based on the conditions in hint 2, we can conclude that s is **bad** if and only if there does not exist any 1 between the k-th 0 from the left and the k-th 0 from the right in s. 

Let us compress all the \mathtt{0}'s between the k-th 0 from the left and the k-th 0 from the right into a single 0 and call the new string t. Note that t will have exactly 2k - 1 \mathtt{0}'s. We can also observe that for each t, a unique s exists. This is only because we have already fixed the parameters n and k. Thus the number of **bad** s having exactly x \mathtt{1}'s is {{x + 2k - 1} \choose {2k - 1}} as there are exactly {{x + 2k - 1} \choose {2k - 1}} binary strings t having 2k - 1 \mathtt{0}'s and x \mathtt{1}'s.

Finally, there are exactly \binom{n}{x} - \binom{x + 2k - 1}{2k - 1} **good** binary strings s having x \mathtt{1}'s and n-x \mathtt{0}'s. Now, do we need to find this value for each x from 1 to n? No, as the number(n-x) of \mathtt{0}'s in s should be a multiple of 2k. There are only O(\frac{n}{2k}) useful candidates for x.

Thus, our overall complexity is O(n \log(n)) (as \sum_{i=1}^{n} O(\frac{n}{i}) = O(n \log(n))).

 **Code**
```cpp
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll long long
const ll INF_ADD=1e18;
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
const ll MOD=998244353;
const ll MAX=5000500;
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
    if(a==b){
        return 1;
    }
    if((a<0)||(a<b)||(b<0))
        return 0;   
    ll denom=(inv_fact[b]*inv_fact[a-b])%MOD; 
    return (denom*fact[a])%MOD;    
}
ll n,k;    
ll ways(ll gaps,ll options){
    gaps--;
    ll now=nCr(gaps+options-1,options-1,MOD);
    return now;
}
void solve(){
    cin>>n; 
    for(ll k=1;k<=(n-1)/2;k++){
        ll ans=1;
        for(ll deleted=2*k;deleted<=n-1;deleted+=2*k){
            ll options=2*k,left_elements=n-deleted;
            ans=(ans+ways(left_elements+1,deleted+1)-ways(left_elements+1,options)+MOD)%MOD;  
        }
        cout<<ans<<" ";
    }
    cout<<nline;
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
    cin>>test_cases;
    precompute(MOD);
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[1930F - Maximize the Difference](../problems/F._Maximize_the_Difference.md "think-cell Round 1") 

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**For an array b consiting of m non-negative integers, f(b) = \max\limits_{p=1}^{m} ( \max\limits_{i = 1}^{m} (b_i | b_p) - \min\limits_{i = 1}^{m} (b_i | b_p)). In other, we can get the maximum possible value by choosing x=b_p for some p (1 \leq p \leq m).

 **Hint 2**f(b) is the maximum value of b_i \land  ~ b_j over all pairs of (i,j) (1 \leq i,j \leq m), where \land is the bitwise AND operator, and ~ is the bitwise One's complement operator.

 **Solution**Let us see how to find f(b) in O(n \log(n)) first. We will focus on updates later. Let us have two sets S_1 and S_2 such that 

 * S_1 contains all submasks of b_i for all 1 \leq i \leq m
* S_2 contains all submasks of ~b_ifor all 1 \leq i \leq m

We can observe that f(b) is the largest element present in both sets S_1 and S_2.

Now, we can insert all submasks naively. But it would be pretty inefficient. Note that we need to insert any submask atmost once in either of the sets. 

Can you think of some approach in which you efficiently insert all the non-visited submasks of some mask?

 **Pseudo Code**
```cpp
insert_submask(cur, S){
    return if mask cur is present in S
    add mask cur to the set S
    vec = list of all the set bits of the mask cur
    for i in vec:
        insert_submask(cur - 2^i)
}
```
Note that the above pseudo code inserts all the all submasks efficiently. As all the masks will be visited atmost once, the amortised complexity will be O(n \log(n)^2). Note that instead of using a set, we can use a boolean array of size n to reduce the complexity to O(n \log(n)).

Thus, we can use the above idea to find f(b) in O(n \log(n)). For each i from 1 to m, we can insert all submasks of b_i into set S_1 and insert all the submasks of ~b_i into set S_2.

The above idea hints at how to deal with updates. If we need to append an element z to b, we can just insert all submasks of z into set S_1 and insert all the submasks of ~z into set S_2.

Hence, the overall complexity is O(n \log(n)).

 **Code**
```cpp
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll long long
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end() 
const ll MAX=100100; 
void solve(){     
    ll n,q; cin>>n>>q;
    ll till=1,len=1;
    while(till<n){
        till*=2;
        len++;
    }
    ll ans=0;
    vector<vector<ll>> track(2,vector<ll>(till+5,0));
    auto add=[&](ll x,ll p){
        queue<ll> trav;
        if(track[p][x]){
            return;
        }
        trav.push(x); track[p][x]=1;
        while(!trav.empty()){
            auto it=trav.front();
            trav.pop();
            if(track[0][it]&track[1][it]){
                ans=max(ans,it);
            }
            for(ll j=0;j<len;j++){
                if(it&(1<<j)){
                    ll cur=(it^(1<<j));   
                    if(!track[p][cur]){
                        track[p][cur]=1;
                        trav.push(cur);
                    }
                }
            }
        }
    };
    ll supermask=till-1;
    vector<ll> a(q+5);
    for(ll i=1;i<=q;i++){
        ll h; cin>>h; 
        a[i]=(h+ans)%n;
        add(a[i],0);
        add(supermask^a[i],1);
        cout<<ans<<" n"[i==q];
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[1930G - Prefix Max Set Counting](../problems/G._Prefix_Max_Set_Counting.md "think-cell Round 1") 

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**Consider some subsequence S of [1,2, \ldots n] such that there exists atleast one pre-order a such that F(a)=S. Look for some non-trivial properties about S. Node S_i will be visited before the node S_{i+1}.

 **Hint 2**Assume |S|=k. First of all, we should S_1=1 and S_k = n. There cannot exists there distinct indices a, b and c (1 \leq a < b < c \leq |k|) such that S_c lies on the path from S_a to S_b. Assume LCA_i is the lowest common ancestor of S_i and S_{i+1}. For all i(1 \leq i <k), the largest value over all the nodes on the unique path from S_i to S_{i+1} should be S_{i+1}. 

 **Hint 3**Suppose nax_p is the maximum value in the subtree of p. There is one more important restriction if S_i does not lie on the path from S_{i+1} to 1. Suppose m is the child of LCA_i, which lies on the path from S_i to LCA_i. We should have S_{i+1} > nax_m. In fact, if you observe carefully you will realise that we should have S_i = nax_m.

 **Solution**Let us use dynamic programming. Suppose dp[i] gives the number of valid subsequences(say S) such that the last element of S is i. Note that the answer to our original problem will be dp[n].

Suppose nax(u,v) denotes the maximum value on the path from u to v(including the endpoints).

Let us have a O(n^2) solution first.

We have dp[1]=1. 

Suppose we are at some node i(i > 1), and we need to find dp[i]. Let us consider some node j(1 \le j < i) and see if we can append i to all the subsequences which end with node j. If we can append, we just need to add dp[j] to dp[i].

But how do we check if we can append i to all the subsequences that end with node j?

Check hints 2 and 3.

So, we have a n^2 solution now. 

We need to optimise it now.

We will move in the increasing value of the nodes(from 2 to n) and calculate the dp values.

Suppose nax(1, par_i) = v, where par_i denotes the parent of i.

Assume we go from node j(j < i) to node i.

There are two cases:

 1. j lies on the path from 1 to i: This case is easy, as we just need to ensure that nax(j,par_i) = j. We can add dp[j] to dp[i] if we have nax(j,par_i) = j. Note that there exists only one node(node v) for which might add dp[v] to dp[i]
2. j does not lie on the path from 1 to i : We will only consider the case in which dp[j] will be added to dp[i]. Suppose lca is the lowest common ancestor of j and i, and m is the child of lca, which lies on the path from j to lca. Notice that the largest value in the subtree of m should be j. This observation is quite helpful. We can traverse over all the ancestors of i. Suppose that we are at ancestor u. We will iterate over all the child(say c) of u such that nax_c < i, and add dp[nax_c] to dp[i] if nax(u,par_i) < nax_c. Suppose track[u][i] stores the sum of dp[nax_c] for all c such that nax_c < i. So we should add track[u][i] to dp[i]. But there is a catch. This way, dp[nax_c] will also get added dp[i] even when nax_c < nax(u, par_i). So, we need to subtract some values, which is left as an exercise for the readers. Now, track[u][d] = track[u][d-1] + dp[nax_c] if nax_c = d. So, instead of keeping a two-dimensional array track, we can just maintain a one-dimensional array track. Note that we will only need the sum of track[u] for all the ancestors of i, which we can easily calculate using the euler tour.

You can look at the attached code for the implementation details.

The intended time complexity is O(n \cdot \log(n)). 

 **Code**
```cpp
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll long long
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
const ll MOD=998244353;
const ll MAX=1000100;
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
        for(;r>=0;r=(r&(r+1))-1){
            ret+=bit[r];
            ret%=MOD;
        }
        return ret;
    }
    ll sum(ll l,ll r) {
        if(l>r)
            return 0;
        ll val=sum(r)-sum(l-1)+MOD;
        val%=MOD;
        return val;
    }
    void add(ll idx,ll delta) {
        for(;idx<n;idx=idx|(idx+1)){
            bit[idx]+=delta;
            bit[idx]%=MOD;
        }
    }
};
vector<vector<ll>> adj;
vector<ll> tin(MAX,0),tout(MAX,0);
vector<ll> parent(MAX,0);
vector<ll> overall_max(MAX,0);
ll now=1;
vector<ll> jump_to(MAX,0),sub(MAX,0);
void dfs(ll cur,ll par){
    parent[cur]=par;
    tin[cur]=now++;
    overall_max[cur]=cur;
    for(auto chld:adj[cur]){
        if(chld!=par){
            jump_to[chld]=max(jump_to[cur],cur);
            dfs(chld,cur);
            overall_max[cur]=max(overall_max[cur],overall_max[chld]);
        }
    }
    tout[cur]=now++;
}
vector<ll> dp(MAX,0);
void solve(){ 
    ll n; cin>>n;
    adj.clear();
    adj.resize(n+5);
    for(ll i=1;i<=n-1;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);  
        adj[v].push_back(u);
    }  
    now=1;      
    dfs(1,0);      
    ll ans=0;    
    FenwickTree enter_time(now+5),exit_time(now+5);
    overall_max[0]=MOD;   
    dp[0]=1;    
    for(ll i=1;i<=n;i++){
        ll p=jump_to[i];
        dp[i]=(enter_time.sum(0,tin[i])-exit_time.sum(0,tin[i])-sub[p]+dp[p]+MOD+MOD)%MOD;
        if(p>i){  
            dp[i]=0;
        }
        ll node=i;
        while(overall_max[node]==i){
            node=parent[node];
        }
        enter_time.add(tin[node],dp[i]);
        exit_time.add(tout[node],dp[i]);
        sub[i]=(enter_time.sum(0,tin[i])-exit_time.sum(0,tin[i])+MOD)%MOD;
    }
    cout<<dp[n]<<nline;
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[1930H - Interactive Mex Tree](../problems/H._Interactive_Mex_Tree.md "think-cell Round 1")

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1**\operatorname{MEX} of the path from u to v will be the minimum value over all the nodes of T which do not lie on the path from u to v.

 **Hint 2**p_1 and p_2 are associated with the Euler tour

 **Hint 3**p_1 is the permutation of [1,2, \ldots n] sorted in increasing order on the basis on tin time observed during Euler tour. Similarly, p_2 is the permutation of [1,2, \ldots n] sorted in increasing order based on tout time. Note that any Euler tour is fine.

 **Solution**Now we have p_1 and p_2 with us. Suppose we need to find \operatorname{MEX} of the path from u to v. Assume that tin_u < tin_v for convenience. Assume T' is the forest we get if we remove all the nodes on the path from u to v from T. Our goal is to find the minimum value over all the nodes in T'. Assume that T' is non-empty, as \operatorname{MEX} will be n if T' is empty. Assume LCA is the lowest common ancestor of u and v. Suppose m is the child of LCA(u,v), which lies on the path from v to LCA(u,v).

Let us consider some groups of nodes p such that.

 1. tout_p < tin_u
2. tin_u < tin_p < tin_m
3. tin_m < tout_p < tin_v
4. tin_v < tin_p
5. tout_{LCA} < tout_p

Note that we have precisely 5 groups, with the i-th group consisting of only those nodes which satisfy the i-th condition.

Here comes the interesting claim. All nodes in T' are present in atleast one of the above 5 groups. There does not exist a node p such that p is on the path from u from v and p is present in any of the groups.

Now, it is not hard to observe that if we consider the nodes of any group, they will form a continuous segment in either p_1 or p_2. So we can cover each group in a single query. Hence, we can find the \operatorname{MEX} of the path in any round using atmost 5 queries.

 **Code**
```cpp
  
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll long long
const ll INF_ADD=1e18;
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
const ll MOD=998244353;
const ll MAX=200200;   
vector<ll> adj[MAX];
ll now=0,till=20;
vector<ll> tin(MAX,0),tout(MAX,0),depth(MAX,0);
vector<vector<ll>> jump(MAX,vector<ll>(till+1,0));
void dfs(ll cur,ll par){
    jump[cur][0]=par;
    for(ll i=1;i<=till;i++)
        jump[cur][i]=jump[jump[cur][i-1]][i-1];
    tin[cur]=++now;
    for(ll chld:adj[cur]){
        if(chld!=par){
            depth[chld]=depth[cur]+1;
            dfs(chld,cur);
        }
    }
    tout[cur]=++now;
} 
bool is_ancestor(ll a,ll b){
    if((tin[a]<=tin[b])&&(tout[a]>=tout[b]))
        return 1;
    return 0;
} 
ll lca(ll a,ll b){
    if(is_ancestor(a,b))
        return a;
    for(ll i=till;i>=0;i--){
        if(!is_ancestor(jump[a][i],b))
            a=jump[a][i];
    }
    return jump[a][0];
}  
void solve(){
    ll n; cin>>n;
    ll m; cin>>m;
    vector<ll> a(n+5);
    for(ll i=1;i<=n-1;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    now=1;
    dfs(1,1);
    vector<ll> p(n),q(n);
    for(ll i=0;i<n;i++){
        p[i]=q[i]=i+1;
    }
    sort(all(p),[&](ll l,ll r){
        return tin[l]<tin[r];
    });
    sort(all(q),[&](ll l,ll r){
        return tout[l]<tout[r];
    });
    for(auto it:p){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:q){
        cout<<it<<" ";
    }
    cout<<endl;
    auto query_p=[&](ll l,ll r){
        ll left_pos=n+1,right_pos=-1;
        for(ll i=0;i<n;i++){
            ll node=p[i];
            if((tin[node]>=l) and (tin[node]<=r)){
                left_pos=min(left_pos,i);
                right_pos=i;
            }
        }
        ll now=n+5;
        if(right_pos!=-1){
            left_pos++,right_pos++;
            cout<<"? 1 "<<left_pos<<" "<<right_pos<<endl;
            cin>>now;
        }
        return now;
    };
    auto query_q=[&](ll l,ll r){
        ll left_pos=n+1,right_pos=-1;
        for(ll i=0;i<n;i++){
            ll node=q[i];
            if((tout[node]>=l) and (tout[node]<=r)){
                left_pos=min(left_pos,i);
                right_pos=i;
            }
        }
        ll now=n+5;
        if(right_pos!=-1){
            left_pos++,right_pos++;
            cout<<"? 2 "<<left_pos<<" "<<right_pos<<endl;
            cin>>now;
        }
        return now;
    };
    while(m--){
        ll u,v; cin>>u>>v;
        if(tout[u]>tout[v]){
            swap(u,v);
        }
        ll lca_node=lca(u,v);
        ll ans=n;
        if(lca_node==v){
            ans=min(ans,query_q(1,tin[u]));
            ans=min(ans,query_p(tin[u]+1,tout[v]));
            ans=min(ans,query_q(tout[v]+1,now));
            cout<<"! "<<ans<<endl;
            ll x; cin>>x;
            continue;
        }
        ans=min(ans,query_q(1,tin[u]));
        ll consider=v;
        for(auto it:adj[lca_node]){
            if(is_ancestor(lca_node,it) and is_ancestor(it,v)){
                consider=it;
            }
        }
        ans=min(ans,query_p(tin[u]+1,tin[consider]-1));
        ans=min(ans,query_q(tin[consider],tin[v]));
        ans=min(ans,query_p(tin[v]+1,tout[lca_node]));
        ans=min(ans,query_q(tout[lca_node]+1,now));
        cout<<"! "<<ans<<endl;
        ll x; cin>>x;
    }
    for(ll i=1;i<=n;i++){
        adj[i].clear();
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
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
[1930I - Counting Is Fun](../problems/I._Counting_Is_Fun.md "think-cell Round 1") 

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Full Solution: [Elegia](https://codeforces.com/profile/Elegia "Legendary Grandmaster Elegia")  
Editorial: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hint 1**[A167510](https://codeforces.com/https://oeis.org/A167510)

 **Solution**It is convinient here to assign weights to \mathtt{0} \to -1 and \mathtt{1} \to 1.

Given a string t, we can define the prefix sum p of it's weights. For example, if t=\mathtt{0010111}, then p=[0,-1,-2,-1,-2,-1,0,1]. So that if t is bad and i is a index that violates the definition, then \max(p_0,p_1,\ldots,p_{i-1}) < \min(p_i,p_{i+1},\ldots,p_n) if s_i = \mathtt{0} or \min(p_0,p_1,\ldots,p_{i-1}) > \max(p_i,p_{i+1},\ldots,p_n) if s_i = \mathtt{1}.

Naturally, it is convinient to assume that p_0 < p_n. All string with p_0 = p_n are clearly good and p_0 > p_n is handled similarly. For strings with p_0 < p_n, the condition can only be violated on an index with s_i = \mathtt{0}.

The solution works using PIE. Let us fix a set of positions I that are bad, so that if i \in I, then s_i =\mathtt{0} and \max(p_0,p_1,\ldots,p_{i-1}) < \min(p_i,p_{i+1},\ldots,p_n). Then we need to count the number of ways to construct p satisfying these conditions and then add it to the answer multiplied by (-1)^{|I|}. 

Suppose that I = i_1,i_2,\ldots,i_k. t[1,i_1] and t[i_k,n] need to be a ballot sequence of length i_1-1 and n-i_k respectively (A001405, denote it as f(n)) while t[i_j,i_{j+1}] needs to be bidirectional ballot sequence of length i_{j+1}-i_j-1 (A167510, denote it as g(n)). Note that in our definition of ballot sequence, we are do not require that prefixes and suffixes have strictly more \mathtt{1} s thatn \mathtt{0} s. It is the same sequence, but note that we need to shift it by a few places when refering to OEIS.

The first n terms of f is easily computed in linear time. We will focus on how to compute the first n terms of g in O(n \log^2 n).

**Computing g(n)** Firstly, let us consider the number of bidirectional sequences with \frac{n+k}{2} \mathtt{1} s and \frac{n-k}{2} \mathtt{0} s. We will imagine this as lattice walks from (0,0) to (n,k) where \mathtt{1} \to (1,1) and \mathtt{0} \to (1,-1). If we touch the lines y=-1 or y=k+1, the walk is invalid. 

We can use the reflection method here, similar to a proof of Catalan. The number of valid walks is #(*) - #(T) + #(TB) - #(TBT) ..... - #(B) + #(BT) - #(BTB) + ..... where #(BTB) denotes the number of walks that touch the bottom line, then the top line, then the bottom line, and then may continue to touch the top and bottom line after that.

We have #(*) = \binom{n}{\frac{n+k}{2}}, #(T) =  \binom{n}{\frac{n+k+2}{2}}, #(TB) =  \binom{n}{\frac{n+3k+4}{2}}, #(TBT) =  \binom{n}{\frac{n+3k+6}{2}}, \ldots, #(B) =  \binom{n}{\frac{n+k+2}{2}}, #(BT) =  \binom{n}{\frac{n+k+4}{2}}, #(BTB) =  \binom{n}{\frac{n+3k+6}{2}}, \ldots

This already gives us a method to compute g(n) in O(n \log n) since for a fixed k, we can compute the above sum in O(\frac{n}{k}), since only the first O(\frac{n}{k}) terms are not 0.

First, notice that we can aggregate them sums without iterating on k, for some fixed j, we can find the coefficient c_j of \binom{n}{\frac{n+j}{2}} across all k. Notice that this coefficient is independent across all n, so we only need to compute c once.

Now, note that \binom{n}{\frac{n+z}{2}} = [x^z] (x^{-1} + x) ^ n. So that g(n) = [x^0] C \cdot (x^{-1} + x)^n, where C is the ogf of c.

From this formulation, we can describe how to compute the first n terms of g in O(n \log^2 n) using Divide and Conquer.

DnC(l,r,V) computes the g(l) \ldots g(r) where V is the coefficents between [l-r,r-l] of C \cdot (x^{-1} + x)^l. DnC(l,r,V) will call DnC(l,m,V) and DnC(m+1,r,V \cdot (x^{-1}+x)^{m-l+1}). We have the reccurence T(n) = 2 T(\frac{n}{2}) + O(n \log n) so T(n) = O(n \log^2 n).

Of course, for constant time speedup, you can choose to split the odd and even coefficients, but that is not needed.

It is possible to compute the first n of g in O(n \log n) but it does not improve the overall complexity of the solution.

**Final Steps**

Now that we obtained the n terms of f and g, let us return to the origial problem.

If s_i =\mathtt{0}, define dp_i = f(i-1) - \sum\limits_{s_j = \mathtt{0}} dp_j \cdot g(j-i-1). Then this contributes f(n-i) \cdot dp_i to the number of bad strings.

Again, we will use Divide and Conquer to perform this quickly.

Briefly, DnC(l,r) will compute the values of dp[l,r] given that contributions from dp[1,l-1] has been transferred to dp[l,r] already.

We will call DnC(l,m), compute the contribution from dp[l,m] to dp[m+1,r] using FFT and then call DnC(m+1,r). The complexity of this is O(n \log^2 n).

 **Code(errorgorn)**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());


const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, qexp(root, mod >> s, mod)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vector<int> rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = qexp(n, mod - 2, mod);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int n;
string s;

int c[100005];
int f[100005];

void calc(int l,int r,vector<int> v){
	while (sz(v)>(r-l)*2+1) v.pob();
	
	if (l==r){
		f[l]=v[0];
		return;
	}
	
	int m=l+r>>1;
	
	calc(l,m,vector<int>(v.begin()+(r-m),v.end()));
	vector<int> a;
	int t=m-l+1;
	rep(x,0,t+1) a.pub(nCk(t,x)),a.pub(0);
	
	v=conv(v,a);
	calc(m+1,r,vector<int>(v.begin()+(2*t),v.end()));
}

int ans[100005];

void solve(int l,int r){
	if (l==r) return;
	int m=l+r>>1;
	solve(l,m);
	auto a=conv(vector<int>(ans+l,ans+m+1),vector<int>(f,f+(r-l)));
	rep(x,m+1,r+1) if (s[x]=='0') ans[x]=fix(ans[x]-a[x-1-l]);
	solve(m+1,r);
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	rep(x,1,100005){
		c[x]++;
		
		int curr=x;
		while (curr<100005){
			if (curr+2<100005) c[curr+2]-=2;
			if (curr+4<100005) c[curr+4]++;
			if (curr+2*x+4<100005) c[curr+2*x+4]++;
			curr+=2*x+4;
		}
	}
	
	cin>>n;
	cin>>s;
	
	vector<int> v;
	rep(x,n+1,1) v.pub(fix(c[x]+(x>=2?c[x-2]:0LL)));
	calc(1,n,v);
	f[0]=1;
	
	int fin=qexp(2,n,MOD);
	rep(_,0,2){
		rep(x,0,n) ans[x]=(s[x]=='0')?nCk(x,x/2):0LL;
		solve(0,n-1);
		rep(x,0,n) if (s[x]=='0') fin=fix(fin-ans[x]*nCk((n-x-1),(n-x-1)/2));
		
		for (auto &it:s) it^=1;
	}
	
	cout<<fin<<endl;
}
```
