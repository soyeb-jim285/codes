# Tutorial_(en)

[A — The Ultimate Square](../problems/A._The_Ultimate_Square.md)
------------------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Master Gheal")

 **Hints****Hint 1**If n is odd, it is possible to create a square using all n blocks.

 **Hint 2**If n is even, it is possible to create a square using only the first n−1 blocks, since n−1 is odd. Can we use the last block to create a larger square?

 **Solution**If n is odd, let k=n+12 be the width of the last block. It is possible to create a square of side length k using every block as follows:

 * Line 1 contains a 1×k block;
* Line 2 contains a 1×1 block and a 1×(k−1) block;
* Line 3 contains a 1×2 block and a 1×(k−2) block;
* …
* Line i contains a 1×(i−1) block and a 1×(k−i+1) block;
* …
* Line k contains a 1×(k−1) block and a 1×1 block.

Since the area of this square is k2, and the n+1-th block has a width of k tiles, the total area of the first n+1 blocks is equal to k2+k<(k+1)2. Therefore, the answer for n+1 is also k.

In conclusion, the answer for each testcase is ⌊n+12⌋.

Time complexity per testcase: O(1).

 **Code (C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
void testcase(){
    ll n;
    cin>>n;
    cout<<(n+1)/2<<'n';
}
int main()
{
    ll t; cin>>t; while(t--)
       testcase();
    return 0;
}

```
 **Rate Problem**Good problem 


[*171*](https://codeforces.com/data/like?action=like "I like this")





Ok problem 

 
[*355*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*45*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")



[B — Balanced Substrings](../problems/B._Diverse_Substrings.md)
------------------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Master Gheal")

 **Hints****Hint 1**What is the maximum number of distinct characters in a diverse string?

 **Hint 2**What is the maximum frequency of a character in a diverse string?

 **Hint 3**What is the maximum possible length a diverse string?

 **Solution**In a diverse string, there are at most 10 distinct characters: '0', '1', …, '9'. Therefore, each of these characters can appear at most 10 times in a diverse string.

With all this in mind, the maximum possible length of a diverse string is 102=100. To solve this problem, we only need to check whether each substring of length l≤100 is diverse.

Time complexity per testcase: O(n⋅102)

 **Code(C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
void tc(){
    ll n;
    string s;
    cin>>n>>s;
    ll ans=0;

    for(ll i=0;i<s.size();i++){

        int fr[10]{}, distinct=0, max_freq=0;

        for(ll j=i;j<s.size() && (++fr[s[j]-'0'])<=10;j++){

            max_freq=max(max_freq,fr[s[j]-'0']);
            if(fr[s[j]-'0']==1) distinct++;

            if(distinct>=max_freq) ans++;
        }
    }
    cout<<ans<<'n';
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t; cin>>t; while(t--) tc();
    return 0;
}


```
 **Rate problem**Good problem 

 
[*907*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*106*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*163*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*113*](https://codeforces.com/data/like?action=like "I like this")



[C — Zero Sum Prefixes](../problems/C._Zero-Sum_Prefixes.md)
----------------------------------------------------------------------

Idea: [Gheal](https://codeforces.com/profile/Gheal "Master Gheal"), Solution: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")

 **Hints****Hint 1**What is the answer if a1=0 and ai≠0 for all 2≤i≤n?

 **Hint 2**What is the answer if ai=0 and aj≠0 for all 1≤j≤n, j≠i?

 **Hint 3**What is the answer if there are only two indices i and j for which ai=aj=0?

 **Solution**Let's consider the prefix sum array s=[a1,a1+a2,…,a1+a2+…+an]. 

For every index i such that ai=0, if we change the value of ai to x, then every element from the suffix [si,si+1,…,sn] will be increased by x. Therefore, if ai1=ai2=…=aik=0, we'll partition array s into multiple subarrays: 

 * [s1,s2,…,si1−1];
* [si1,si1+1,…,si2−1];
* [si2,si2+1,…,si3−1];
* …
* [sik,sik+1,…,sn];

Since none of the elements from the first subarray can be changed, it will contribute with the number of occurences of 0 in [s1,s2,…,si1−1] towards the final answer.

For each of the other subarrays [sl,sl+1,…,sr], let x be the most frequent element in the subarray, appearing fr[x] times. Since al=0, we can change the value of al to −x. In this case, every x in this subarray will become equal to 0, and our current subarray will contribute with fr[x] towards the final answer.

Time complexity per testcase: O(NlogN)

 **Code(C++)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

ll a[MAXN];
map<ll,ll> freq;

void tc(){
    ll n;
    cin>>n;
    ll maxfr=0,current_sum=0,ans=0;
    bool found_wildcard=0;
    freq.clear();
    for(ll i=0;i<n;i++){
        cin>>a[i];

        if(a[i]==0){

            if(found_wildcard) ans+=maxfr;
            else ans+=freq[0];

            found_wildcard=1;

            maxfr=0,freq.clear();
        }

        current_sum+=a[i];
        maxfr=max(maxfr,++freq[current_sum]);
    }
    if(found_wildcard) ans+=maxfr;
    else ans+=freq[0];

    cout<<ans<<'n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    ll t; cin>>t; while(t--)
        tc();
    return 0;
}

```
 **Rate problem**Good problem 

 
[*731*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*67*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*91*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*72*](https://codeforces.com/data/like?action=like "I like this")



[D — ConstructOR](../problems/D._ConstructOR_.md)
----------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Master Gheal")

 **Hints****Hint 1**If at least one of a and b is odd, and d is even, then there are no solutions.

 **Proof**Without loss of generality, we will only consider the case when a is odd and d is even. Since the last bit of a is 1, then the last bit of a|x must also be 1. 

Therefore, a|x cannot be a multiple of d, as a|x is odd, while d is even.

Note that there are more cases in which no solutions exist, however they are more generalised versions of this case. 

 **Hint 2**If a triplet (a,b,d) has no solutions, then (a⋅2,b⋅2,d⋅2) has no solutions as well. 

Combined with the first hint, we can say that a triplet (a,b,d) has no solutions if min(lsb(a),lsb(b))<lsb(d). Here, lsb(x) represents the [least significant bit](https://codeforces.com/https://en.wikipedia.org/wiki/Bit_numbering#Bit_significance_and_indexing) of x.

 **Hint 3**Since both a|x and b|x must be divisible by d, it's better to choose an x such that a|x=b|x=x.

 **Hint 4**If d is odd, since a,b<230, we can ensure that a|x=b|x=x by setting the last 30 bits of c to 1.

If d is even, then the last lsb(d) bits of x should be set to 0, while the other bits from the last 30 bits should be set to 1. Here, lsb(x) represents the [least significant bit](https://codeforces.com/https://en.wikipedia.org/wiki/Bit_numbering#Bit_significance_and_indexing) of x.

 **Solution**Let k=lsb(d), where lsb(d) represents the [least significant bit](https://codeforces.com/https://en.wikipedia.org/wiki/Bit_numbering#Bit_significance_and_indexing) of d.

Since a|x and b|x are multiples of d, the last k bits of a and b (and also x) must be equal to 0. 

Otherwise, there are no solutions and we can print −1.

To simplify the construction process, we will try to find some x such that a|x=b|x=x. Since we already know that the last k bits of a, b and x are 0, we will consider that the other 30−k of the 30 least significant bits of x are equal to 1:

 x(2)=p 1 1 1 … 1 0 0 … 0This gives the following general formula for x:

 x=2k⋅(p⋅230−k+(230−k−1))Now, we'll try to find some p for which x is a multiple of d=2k⋅d′:

 x=2k⋅(p⋅230−k+(230−k−1)≡0mod2k⋅d′⇔ ⇔(p⋅230−k+(230−k−1)≡0modd′⇔ ⇔(p+1)⋅230−k≡1modd′⇔ ⇔p+1≡2k−30modd′⇔ ⇔p+1≡(2−1)30−kmodd′⇔ ⇔p+1≡(d′+12)30−kmodd′⇒ ⇒p=((d′+12)30−k+d′−1)modd′Time complexity per testcase: O(logd)

Note that if a|b is already a multiple of d, we can consider x=a|b. 

 **Code(C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void tc(){
    ll a,b,d,k=0,inverse_of_2,total_inverse=1;
    cin>>a>>b>>d;
    a|=b;
    if(a%d==0){
        cout<<a<<'n';
        return;
    }
    while(a%2==0 && d%2==0)
        a/=2,d/=2,k++;
    inverse_of_2=(d+1)/2;
    if(a%2==1 && d%2==0){
        cout<<"-1n";
        return;
    }

    for(ll i=0;i<30-k;i++)
        total_inverse=total_inverse*inverse_of_2%d;

    cout<<((total_inverse<<(30-k))-1)*(1ll<<k)<<'n';
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    ll t; cin>>t; while(t--)
        tc();
}

```
 **Rate problem**Good problem 

 
[*240*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*126*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*72*](https://codeforces.com/data/like?action=like "I like this")



[E — Yet Another Array Counting Problem](../problems/E._Yet_Another_Array_Counting_Problem.md)
---------------------------------------------------------------------------------------

Author: [Gheal](https://codeforces.com/profile/Gheal "Master Gheal")

 **Hints****Hint 1**Let m be the position of the leftmost maximum on the segment [1;n]. 

 1. If l≤m≤r, then the position of the leftmost maximum on the segment [l;r] is equal to m.
2. If l≤r<m, then the leftmost maximum on the segment [l;r] is some element ap, p<m.
3. If m<l≤r, then the leftmost maximum on the segment [l;r] is some element ap2, p2>m.
 **Hint 2**Let m be the position of the leftmost maximum on the segment [l;r]. 

If p is the position of the leftmost maximum on the segment [l;m−1] and p2 is the position of the leftmost maximum on the segment [m+1;r], then bm>bp and bm≥bp2. 

 **Hint 3**Using the idea from the previous hint, we can recursively build a binary tree where the children of node m are nodes p and p2.

 **Hint 4**Can this problem be boiled down to a tree dp? (Note that n⋅m≤106)

 **Solution**Let f(i,j) be the position of the leftmost maximum in the interval (i;j), 1≤i≤j≤n.

Let's consider an interval (l;r) such that f(l,r)=m. For the sake of simplicity, let's assume that l<m<r.

Let p=f(l,m−1) and p2=f(m+1,r). Since am is the leftmost maximum in (l;r), p<m and p2>m, the following conditions must hold for array b:

 * bm>bp
* bm≥bp2

Let's consider a binary tree where the children of node u=f(l,r) are nodes p=f(l,u−1) and p2=f(u+1,r), for every 1≤u≤n. 

Note that if u=l, f(l,l−1) is not defined, and, as such, node u will have no left child. Similarly, if u=r, then node u will have no right child.

Let dp[u][x] be equal to the number of ways to assign values to every element bv from the subtree rooted in u, if bu=x. 

 * If u has a left child and x=1, then dp[u][x]=0;
* Otherwise, if u has two children, then dp[u][x]=(∑x−1i=1dp[p][i])⋅(∑xi=1dp[p2][i]);
* If u only has a left child, then dp[u][x]=∑x−1i=1dp[p][i];
* If u only has a right child, then dp[u][x]=∑xi=1dp[p2][i];
* If u has no children, then dp[u][x]=1.

To optimise the transitions, we'll also need to compute sum[u][x]=∑xi=1dp[u][x] alongside our normal dp.

Intended time complexity per testcase: O(n⋅m+n⋅log(n))

 **Additional implementation details**In order to construct the binary tree, we can use a recursive divide and conquer function divide(l,r) to split our current interval (l;r) into two new intervals (l;m−1) and (m+1;r).

Additionally, we can also compute the values of dp[m][x] and sum[m][x] inside divide(l,r) after calling divide(l,m−1) and divide (m+1,r).

Range leftmost maximumum queries can be answered in O(1) using a sparse table, see the model solution for more information.

 **Code(C++)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll NMAX=2e5+5,LGMAX=18,MOD=1e9+7;
int n,m;

int leftmost_maximum[LGMAX][NMAX],msb[NMAX];
int v[NMAX];

vector<vector<ll>> dp,sum;

int leftmost_maximum_query(int l, int r){
    int bit=msb[r-l+1];
    if(v[leftmost_maximum[bit][l]]>=v[leftmost_maximum[bit][r-(1<<bit)+1]]) return leftmost_maximum[bit][l];
    else return leftmost_maximum[bit][r-(1<<bit)+1];
}
int divide(int l, int r){

    if(l>r) return -1;

    int mid=leftmost_maximum_query(l,r);

    int p=divide(l,mid-1),p2=divide(mid+1,r);

    for(int i=1;i<=m;i++){
        if(p!=-1 && i==1) dp[mid][1]=0;
        else dp[mid][i]=(p>=0?sum[p][i-1]:1ll)*(p2>=0?sum[p2][i]:1ll)%MOD;

        sum[mid][i]=(sum[mid][i-1]+dp[mid][i])%MOD;
    }
    return mid;
}
void tc(){

    cin>>n>>m;
    dp.resize(n),sum.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];

        leftmost_maximum[0][i]=i;

        dp[i].resize(m+1),sum[i].resize(m+1);
        for(int j=0;j<=m;j++) dp[i][j]=sum[i][j]=0;
    }

    for(int bit=1;bit<LGMAX;bit++){
        for(int i=0;i+(1<<bit)<=n;i++){
            if(v[leftmost_maximum[bit-1][i]]>=v[leftmost_maximum[bit-1][i+(1<<(bit-1))]])
                leftmost_maximum[bit][i]=leftmost_maximum[bit-1][i];
            else
                leftmost_maximum[bit][i]=leftmost_maximum[bit-1][i+(1<<(bit-1))];
        }
    }

    divide(0,n-1);

    cout<<sum[leftmost_maximum_query(0,n-1)][m]<<'n';
}
int main()
{
    for(int i=2;i<NMAX;i++)
        msb[i]=msb[i-1]+((i&(i-1))==0); /// msb = floor(log2)

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
        tc();

    return 0;
}

```
 **Rate problem**Good problem 

 
[*172*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")



[F — Circular Xor Reversal](../problems/F._Circular_Xor_Reversal.md)
--------------------------------------------------------------------------

Idea: [Gheal](https://codeforces.com/profile/Gheal "Master Gheal"), Solution: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")

 **Hints****Hint 1**How can we perform ai=ai⊕aj for any 0≤i,j<n, i≠j?

 **Hint 2**We can swap the values of ai and aj by performing the following sequence of xor assignments:

 * ai=ai⊕aj;
* aj=aj⊕ai;
* ai=ai⊕aj;
 **Hint 3**Performing ai=ai⊕aj on its own is pretty wasteful, as it requires 4⋅dist(i,j)−c operations, where dist(i,j)=(j+n−i)modn, and c is a constant.

If j=i+3, can we perform ai=ai⊕aj and ai+1=ai+1⊕aj−1 simultaneously?

 **Hint 4**Building on the idea presented in hint 3, can we perform the following n2 xor assignments simultaneously if n is even?

 * a0=a0⊕an−1;
* a1=a1⊕an−2;
* a2=a2⊕an−3;
* …
* an2−1=an2−1⊕an2

The target number of operations for performing all n2 assignments is n22.

 **Hint 5**Using hints 2 and 4, we can already solve the problem if n is even. 

If m=dist(i,j)>0 and bk=a(i+k)modn, let f(i,j) be a sequence of operations that performs:

 * b0=b0⊕bm;
* b1=b1⊕bm−1;
* b2=b2⊕bm−2;
* …
* b⌊m−22⌋=b⌊m−12⌋⊕b⌊m+22⌋

We can reverse array a by performing f(0,n−1), f(n2,n2−1) and f(0,n−1), in this order.

Otherwise, if n is odd, we can perform f(0,n−1), f(n+12,n−32) and f(0,n−1), in this order.

The total number of operations is 3⋅n22≤3⋅40022=240000<250000.

 **Solution**If m=dist(i,j)=((j+n−i)modn), m>0 and bk=a(i+k)modn, let f(i,j) be a sequence of operations that performs:

 * b0=b0⊕bm−1;
* b1=b1⊕bm−2;
* b2=b2⊕bm−3;
* …
* b⌊m−12⌋=b⌊m−12⌋⊕b⌊m+22⌋

If n is even, we can reverse array a by performing f(0,n−1), f(n2,n2−1) and f(0,n−1), in this order.

Otherwise, if n is odd, we can perform f(0,n−1), f(n+12,n−32) and f(0,n−1), in this order.

One possible way to construct f(i,j) is as follows:

 * Perform an operation on every i from m−1 to 0:

 ⇒b=[(0..m),(1..m),(2..m)…,(i..m),…,bm] * Perform an operation on every i from 1 to m−1:

 ⇒b=[(0..m),b1,b2,…,bi,…,bm] * Perform an operation on every i from m−2 to 1:

 ⇒b=[(0..m),(1..m−1),(2..m−1),…,(i..m−1),…,bm−1,bm] * Perform an operation on every i from 2 to m−2:

 ⇒b=[(0..m),(1..m−1),b2,b3,…,bi,…,bm−1,bm] * …

 ⇒b=[(0..m),(1..m−1),(2..m−2),…,(i..m−i),(⌊m−12⌋..⌊m+22⌋),b⌊m+12⌋,…,bj,bm−1] * The last step is to perform an operation on every i from 0 to ⌊m−22⌋:

 ⇒b=[a0⊕am,a1⊕am−1,…,ai⊕am−i,…,b⌊m−12⌋⊕b⌊m+22⌋,b⌊m+12⌋,…,bj,…,bm]Here, (l..r) denotes bl⊕bl+1⊕…⊕br.

The number of operations needed for f(i,j) is equal to m+(m−1)+…+1+(m2)=m⋅(m+1)2+m2=m2+2⋅m2, therefore the total number of operations needed to reverse the array is 32⋅(m2+2⋅m). Since m≤n−1, 32⋅(m2+2⋅m)≤32⋅(3992+2⋅399)<250000.

Time complexity per testcase: O(N2)

 **Code(C++)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int n;
void add_op(int pos){
    ans.push_back(pos%n);
}
void f(int l, int r){

    if(r<l) r+=n;

    int m=r-l,direction=0,start=l;
    r--;
    while(l<=r){

        if(direction==0){
            for(int i=r;i>=l;i--)
                add_op(i);
            l++;
        }
        else{
            for(int i=l;i<=r;i++)
                add_op(i);
            r--;
        }

        direction=1-direction;
    }
    for(int i=start;i<start+m/2;i++)
        add_op(i);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin>>n;

    f(0,n-1);

    f((n+1)/2,(n-2)/2);

    f(0,n-1);

    cout<<ans.size()<<'n';

    for(auto it : ans) cout<<it<<' ';
}

```
 **Rate problem**Good problem 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*67*](https://codeforces.com/data/like?action=like "I like this")



If there is anything wrong or unclear in this editorial, feel free to ping me in the comments.

