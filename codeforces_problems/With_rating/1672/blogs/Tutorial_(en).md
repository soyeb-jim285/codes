# Tutorial_(en)

Hope that everyone enjoyed the round. Feel free to ask questions in the comments if you do not understand any part of the editorial

[1672A - Log Chopping](../problems/A._Log_Chopping.md "Codeforces Global Round 20")  
Author: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**No matter what move each player does, the result of the game will **always** be the same.

 **Hint 2**Count the number of moves.

 **Tutorial**Let us consider the ending state of the game. It turns out that at the ending state, we will only have logs of 1 meter. Otherwise, players can make a move.

Now, at the ending state of the game, we will have n∑k=1ak logs. And each move we increase the number of logs by exactly 1. Since we started with n logs, there has been exactly (n∑k=1ak)−n turns.

Alternatively, a log of length ak will be cut ak−1 times, so there will be n∑k=1(ak−1) turns.

If there were an odd number of turns errorgorn wins, otherwise maomao90 wins.

 **Solution**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[105];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		int tot=0;
		rep(x,0,n) tot+=arr[x]-1;
		
		if (tot%2==0) cout<<"maomao90"<<endl;
		else cout<<"errorgorn"<<endl;
	}
}

```
[1672B - I love AAAB](../problems/B._I_love_AAAB.md "Codeforces Global Round 20")  
Author: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**Pretend that we can only insert AB.

 **Hint 2**What if we replaced A and B with ( and )?

 **Tutorial**Claim: The string is obtainable if it ends in B and every prefix of the string has at least as many A as B.

An alternative way to think about the second condition is to assign A to have a value of 1 and B to have a value of −1. Then, we are just saying that each prefix must have a non-negative sum. This is pretty similar to bracket sequences.

Now, both conditions are clearly necessary, let us show that they are sufficient too.

We will explicitly construct the string (in the reverse direction). While there are more than 1 occurrences of B in the string, remove the first occurrence of AB. After doing this process, you will eventually end up with the string AAA...AAB.

 **Solution**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		string s;
		cin>>s;
		
		bool ok=(s.back()=='B');
		
		int sum=0;
		for (auto it:s){
			if (it=='A') sum++;
			else sum--;
			if (sum<0) ok=false;
		}
		
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

```
[1672C - Unequal Array](../problems/C._Unequal_Array.md "Codeforces Global Round 20")  
Author: [maomao90](https://codeforces.com/profile/maomao90 "Master maomao90")

 **Hints****Hint 1**If the array is a=[1,1,…,1]. We will need 0 moves if n≤2 and will need max(n−3,1) moves.

 **Hint 2**The only way to reduce the number of i such that ai=ai+1 is when ai=ai+1 and ai+2=ai+3, and you apply the operation on ai+1 and ai+2.

 **Tutorial**Suppose l is the smallest index where al=al+1 and r is the largest index where ar=ar+1. If l=r or l and r does not exist, the condition is already satisfied and we can do 0 operations. Otherwise, the answer is max(1,r−l−1). The proof is as follows:

 1. Suppose l+1=r, then, there are 3 elements that are adjacent to each other. Hence, we can just do one operation with i=l and x=∞ to make the equality of the array 1.
2. Suppose otherwise, then the array will look something like [...,X,X,...,Y,Y,...], with r−l−2 elements between the second X and the first Y. Then, we can do operations on i=l+1,l+2,…,r−2,r−1 to make the equality of the array 1.

To see why we need at least r−l−1 operations, observe that each operation will cause r−l to decrease by at most 1. This is because if we do not do an operation on i∈{l−1,l+1,r−1,r+1}, then both al=al+1 and ar=ar+1 will still hold. We see that r−l only decreases when do we an operation on i∈l+1,r−1 and it is not too hard to show that it only decreases by 1 in those cases while r−l>2

Hence, we keep doing the operation until r−l=2, which will only require 1 operation to change both pairs and make the equality 1.

 **Solution**
```cpp
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int t;
int n;
int a[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        int mn = -1, mx = -1;
        REP (i, 1, n) {
            if (a[i] == a[i - 1]) {
                if (mn == -1) {
                    mn = i;
                }
                mx = i;
            }
        }
        if (mn == mx) {
            cout << 0 << 'n';
        } else {
            cout << max(1, mx - mn - 1) << 'n';
        }
    }
    return 0;
}
```
[1672D - Cyclic Rotation](../problems/D._Cyclic_Rotation.md "Codeforces Global Round 20")  
Author: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**The operation of cyclic shift is equivalent to deleting ai and duplicating aj where ai=aj.

 **Hint 2**Reverse the process.

 **Tutorial 1**We will solve the problem by reversing the steps and transform array b to array a.

We can do the following operation on b:

 * pick index i<j such that bj=bj+1 and remove bj+1 and insert it after position i.

Now, for every consecutive block of identical elements in b, we can remove all but one element from it and move it left. 

If we process from right to left, we can imagine as taking consecutive elemnets in b out and placing in a reserve, and using them to match some elements in a towards the left.

Using this idea, we can use the following greedy two-pointer algorithm:

Let i and j represent the size of a and b respectively (and hence ai and bj will refer to the last elements of a and b respectively). We also have an initially empty multiset S, which represents the reserve. We will perform the following operations in this order:

 1. While bj−1=bj, add bj to the multiset S and decrement j
2. If ai=bj, then decrement both i and j
3. Otherwise, we delete an occurance of ai in S and decrement i. If we cannot find ai in S, it is impossible to transform b to a.
 **Tutorial 2**Let us define an array c where all elements of c is 1. We can rephrase the problem in the following way:

 * Choose i<j such that ai=aj and ci>0. Then update ci←ci−1 and cj←cj+1.

The final array b is obtained by the following: Let b be initially empty, then iterate i from 1 to n and add ci copies of ai to b.

As such, we can consider mapping elements of b into elements of a. More specifically, consider a mapping f where f is non-decreasing, bi=afi and we increment cfi by 1 for all i. All that remains is to determine if we can make such a mapping such that c is valid.

Notice that if all elements of a are identical, the necessary and sufficient condition for a valid array c is that c1+c2+…+ci≤i for all i.

This motivates us to construct an array pa where pai is the number of indices j≤i such that ai=aj. Analogously, construct pb.

Then the necessary and sufficient conditions for a mapping f is that f is non-decreasing, bi=afi and pbi≤pafi. A greedy algorithm to construct f, if it exists, is trivial by minimizing fi for each i.

 **Solution 1**
```cpp
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int t;
int n;
int a[MAXN], b[MAXN];
int cnt[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cnt[i] = 0;
        }
        REP (i, 0, n) {
            cin >> a[i];
        }
        REP (i, 0, n) {
            cin >> b[i];
        }
        int i = 0, j = 0;
        bool pos = 1;
        while (j < n) {
            if (i < n && j < n && a[i] == b[j]) {
                i++; j++;
                continue;
            }
            if (cnt[b[j]] > 0 && b[j] == b[j - 1]) {
                cnt[b[j++]]--;
            } else if (i < n) {
                cnt[a[i++]]++;
            } else {
                pos = 0;
                break;
            }
        }
        if (pos) {
            assert(i == n);
            REP (i, 1, n + 1) {
                assert(cnt[i] == 0);
            }
            cout << "YESn";
        } else {
            cout << "NOn";
        }
    }
    return 0;
}
```
 **Solution 2**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
int brr[200005];
int crr[200005];
int num[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		
		rep(x,1,n+1) num[x]=0;
		rep(x,1,n+1){
			num[arr[x]]++;
			crr[x]=num[arr[x]];
		}
		
		rep(x,1,n+1) num[x]=0;
		int idx=1;
		rep(x,1,n+1){
			num[brr[x]]++;
			while (idx<=n && (arr[idx]!=brr[x] || crr[idx]<num[brr[x]])) idx++;
		}
		
		if (idx>n) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
```
[1672E - notepad.exe](../problems/E._notepad.exe.md "Codeforces Global Round 20")  
Author: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn"), [oolimry](https://codeforces.com/profile/oolimry "Master oolimry")

 **Hints****Hint 1**Find the sum of lengths of words.

 **Hint 2**Given a height, how many "good" widths are there.

 **Tutorial**The first idea that we have is that we want to be able to find the minimum possible width of the text editor for a specific height. We can do this in nlog(n⋅2000) queries using binary search for each height. This is clearly not good enough, so let us come up with more observations.

First, we can binary search for the minimum possible width for height 1. This value is (∑ni=1li)+n−1 which we will denote with S.

Let us consider what we might want to query for height h. Suppose that the words are arranged very nicely such that there are no trailing spaces in each line. Then, the total number of characters will be S−h+1. This means that the minimum possible area for height h will be S−h+1. We also know that if the area is more than S, it will not be useful as the area for h=1 is already S.

Now, we know that the range of possible areas that we are interested in is [S−h+1,S]. There is a total of h possible areas that it can take, and an area is only possible if h⋅w=a, or in other words, the area is divisible by h. Among the h consecutive possible values, exactly one of them will be divisible by h, hence we can just query that one value of w which can very nicely be found as ⌊Sh⌋.

The total number of queries used is n+log(n⋅2000) where n comes from the single query for each height and the log(n⋅2000) comes from the binary search at the start.

 **Solution**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug


int n;

int ask(int i){
	if (i==0) return 0;
	cout<<"? "<<i<<endl;
	int temp;
	cin>>temp;
	
	if (temp==-1){
		exit(0);
	}
	
	return temp;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int lo=-2,hi=5e6,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (ask(mi)==1) hi=mi;
		else lo=mi;
	}
	
	int ans=1e9;
	rep(x,1,n+1){
		int temp=ask(hi/x);
		if (temp) ans=min(ans,temp*(hi/x));
	}
	
	cout<<"! "<<ans<<endl;
}

```
[1672F1 - Array Shuffling](../problems/F1._Array_Shuffling.md "Codeforces Global Round 20") and [1672F2 - Checker for Array Shuffling](../problems/F2._Checker_for_Array_Shuffling.md "Codeforces Global Round 20")  
Author: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**The number of occurances of the most frequent element is important.

 **Hint 2**Let X be the number of occurances of the most common element. The maximal sadness is N−X.

 **Hint 3**For every minimal sequence of swaps, we have duality of maximal number of cycles when considering the graph with edges ai→bi.

 **Tutorial**Let N be the length of A and B.

We want to prove that an optimal swapping from B→A is equivalent to sorting via some cycles. Suppose our swap order is {(l1,r1),(l2,r2),…,(lK,rK)}. Let's consider a graph G with edges being the swaps. Suppose the number of connected components in G is CC, then there is a way to perform the transformation B→A using CC cycles since we can view the labels of each connected component of G as a permutation of the original vertices. One cycle of length X uses X−1 swaps, so we use N−CC swaps in total. Since CC≥N−K, we can always change the swap order to swapping cycles while not performing a bigger number of moves. Now we have changed the problem to maximizing the number of cycles we use.

Let cntx be the number of occurrences of x in A. WLOG cnt1≥cnt2≥….

Let sA(B) denote the **sadness** of B when the original array is A.

Claim: max(sA)≤N−cnt1

Proof: By pigeonhole principle, we know there exist a cycle with 2 occurrences of the element 1.

Consider a cycle that swaps i1→i2→…→iK→i1 where Ai1=Aiz=1. Then we can increase the number of connected components while maintaining B by splitting into 2 cycles i1→i2→…→iz−1→i1 and iz→i2→…→iN→iz.

Therefore, in an optimal solution, there should not be a cycle that passes through the same value twice. ◼

Therefore, we can assume that all occurrences of 1 belong to different cycles. Therefore, #cyc≥cnt1 swaps are used. The number of swaps used is N−#cyc≤N−cnt1.

Therefore, N−cnt1 is a upper bound of s.

Claim: sA(B)<N−cnt1 ⇔ there exists a cycle i1→i2→…→iK→i1 such that all ix≠1.

Proof: (⇒) There exists a cycle decomposition of the graph that uses at least cnt1+1 cycles. Since a single element of 1 can only go to a single cycle, there exists a cycle without 1.

(⇐) Let's remove this cycle to form an arrays A′ and B′. Then sA′(B′)≤N−K−cnt1. Now, we only needed K−1 swaps to remove the cycle, so it much be that sA(B)≤(N−K−cnt1)+(K−1)=N−cnt1−1. ◼

### Constructing maximal B

To construction a permutation such that s(B)=N−cnt1, let's construct a graph Gcnt based on the number of occurrences of each element in A. We draw cnti+1 edges from (i)→(i+1) and cnti−cnti+1 edges from (i)→(1). It is obviously impossible to find a cycle that does not contain 1. Since all edges will be of the form (i)→(i+1).

Another way to construct this permutation is to assume that A is sorted. Then we perform cnt1 cyclic shifts on A to obtain B.

### Checking if B is maximal

Given the graph representation, finding such a cycle i1→i2→…→iK→i1 such that all ix≠1 is easy. Let's remove 1 from the graph then check if the graph is a DAG.

 **Solution for F1**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
int brr[200005];
int cnt[200005];
vector<int> al[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) cnt[x]=0;
		
		rep(x,0,n) cnt[arr[x]]++;
		
		int mx=0;
		rep(x,1,n+1) mx=max(mx,cnt[x]);
		
		rep(x,0,n) brr[x]=arr[x];
		sort(brr,brr+n);
		
		rep(x,0,n) al[brr[x]].pub(brr[(x+mx)%n]);
		
		rep(x,0,n){
			cout<<al[arr[x]].back()<<" n"[x==n-1];
			al[arr[x]].pob();
		}
	}
	
}

```
 **Solution for F2**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
int brr[200005];

vector<int> al[200005];
bool onstk[200005];
bool vis[200005];

bool cyc;
void dfs(int i){
	onstk[i]=vis[i]=true;
	
	for (auto it:al[i]){
		if (onstk[it]) cyc=true;
		if (!vis[it]) dfs(it);
	}
	
	onstk[i]=false;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) vis[x]=onstk[x]=false;
		
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		
		rep(x,1,n+1) al[arr[x]].pub(brr[x]);
		
		int mx=1;
		rep(x,1,n+1) if (sz(al[x])>sz(al[mx])) mx=x;
		
		vis[mx]=true;
		cyc=false;
		rep(x,1,n+1) if (!vis[x]) dfs(x);
		
		if (cyc) cout<<"WA"<<endl;
		else cout<<"AC"<<endl;
	}
}

```
[1672G - Cross Xor](../problems/G._Cross_Xor.md "Codeforces Global Round 20")  
Author: [maomao90](https://codeforces.com/profile/maomao90 "Master maomao90"), [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**We need to consider 4 cases based on the parity of r and c.

 **Hint 2**Let Ri and Cj denote c⨂j=1ai,j and r⨂i=1ai,j respectively, or the xor-sum of the i-th row and the xor-sum of the j-th column respectively. For some cases, R and C will be constant sequences no matter what sequence of operations we perform.

 **Hint 3**The obvious necessary conditions for R and C are actually sufficient.

 **Hint 4**When at least one of r or c is even, counting the valid grids is easy. When both r and c is odd, consider drawing the bipartite graph where edges are cells with ?.

 **Tutorial**
### Determining which Grids are Obtainable

Let Ri and Cj denote c⨂j=1ai,j and r⨂i=1ai,j respectively, or the xor-sum of the i-th row and the xor-sum of the j-th column respectively.

We will split the problem into 3 cases.

#### Case 1: r is even and c is even

Choose some (x,y) and do an operation on all (i,j) where i=x or j=y. The effect of this series of operations is toggling (x,y).

All possible grids are reachable. Counting them is easy.

#### Case 2: r is even and c is odd

If r is odd and c is even, we can treat it as the same case by swapping a few variables.

Notice that every operation toggles all elements in R. It is neccasary that R all values in R are the same, let us prove that this is sufficient as well.

Now suppose R is all 0. If R is all 1. We can perform the operation on (1,1) and now R is all 0.

If we pick 1≤x≤r and 1≤y<c and perform operations on all (i,j) where i≠x and j=y or j=c, then it is equivalent to toggling (x,y) and (x,c).

We can perform the following new operation:

 * pick 1≤x≤r and 1≤y<c
* toggle (x,y),(x,c)

Since R is all 0, each row has an even number of 1. If we apply the new operation on all (x,y) where ax,y=1 and y<c, then (x,c) will be 0 in the end. Hence, the whole grid will be 0.

#### Case 3: r is odd and c is odd

Notice that every operation toggles all elements in R and C. It is neccasary that both R are C all having the same values, let us prove that this is sufficient as well.

Suppose R is all 0 and C is all 0. If R and C are all 1, we apply the operation on (1,1) to make R and C both all 0

Notice that if we pick 1≤x1<x2≤r and 1≤y1<y2≤c. Let S={(x1,y1),(x1,y2),(x2,y1),(x2,y2)}. When we perform operations on all cells in S, it is equivalent to toggling all cells in S.

We can perform the following new operation:

 * pick 1≤x<r and 1≤y<c
* toggle (x,y),(x,c),(r,y),(r,c)

Since R and C is all 0, each row and column has an even number of 1. If we apply the new operation on all (x,y) where ax,y=1 and x<r and y<c , then (x,c) will be 0 for 0<x<r and (r,y) will be 0 for 0<y<c in the end. And hence, ar,c=0 too since R and C is all 0. Hence, the whole grid will be 0.

### Alternate Justification

Thanks to [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994") for writing this.

Let V=Znm2. V is endowed with the natural scalar product, which induces the concept of orthogonality.

Let M be the subspace generated by the moves. Let M⊥ be the space orthogonal to M. It is a basic result in linear algebra that (M⊥)⊥=M.

One can see that {(x1,y1),(x1,y2),(x2,y1),(x2,y2)} belongs to M (it is a combination of 4 moves). Thus one deduces that if u∈M⊥ then ux,y=ax⊕by for two vectors a∈Zr2,b∈Zc2. Given a,b; the scalar product between u and the move centered at (x,y) is: xor(a)⊕xor(b)⊕(c+1)ax⊕(r+1)by. Assume that u is in M⊥:

 * If r,c are both even, then ax and by must be constant and equal each other. Thus M⊥ is only the 0 vector.
* If r is even and c is odd, then by is constant. Hence M⊥ is generated by any two rows.
* If r is odd and c is even, analogous.
* If r and c are both odd, then the only condition is xor(a)⊕xor(b)=0. This is necessary and sufficient for the orthogonality. And it implies that M⊥ is generated by any two rows and any two columns.

Since we determined M⊥, we have determined also M.

### Counting

Case 1 and 2 are the easy cases while counting case 3 is more involved.

#### Case 1: r is even and c is even

All grids are obtainable. Let #? denote the number of ?s in the grid. Then the answer is 2#? since all grid are obtainable.

#### Case 2: r is even and c is odd

If r is odd and c is even, we can treat it as the same case by swapping a few variables.

Let us fix whether we want R=[0,0,…,0] or R=[1,1,…,1]. We will count the number of valid grids for each case.

Let #?i denote the number of ?s in the i-th row. If #?i>0, then then number of ways to set the i-th row is 2#?i−1. Otherwise, the number of ways is either 0 to 1 depending on the initial value of Ri.

#### Case 3: r is odd and c is odd

Let us define a bipartite graph with vertices r+c vertices, labelled VR,i for 1≤i≤r and VC,j for 1≤j≤c. If ai,j=?, then we will add an (undirected) edge VR,i↔VC,j. Now we assume that each ? is set to 0 at first. We will choose a subset of them to turn into 1. When we do this on ai,j, the value of Ri and Cj will toggle. In terms of the graph, this corresponds to assigning 0 or 1 to each edge. When we assign 1 to the edge connecting VR,i and VC,j, then Ri and Cj will toggle. We can consider Ri and Cj to be the weight of the vertices VR,i and VC,j respecitvely.

Consider a connected component of this bipartite graph. Choose an arbitrary spanning tree of this connected component. By assinging the weights of the edges in the spanning tree, we can arbitrarily set the weights of all but one vertex. We cannot arbitarily set the weight of all vertices as the xor-sum of the weight of vertices is an invariant.

Let us show that we can arbitarily choose the weights of all but one vertex on this connected component using the spanning tree. Let us arbitrarily root the tree. Choose some arbitrary leaf of the tree, if the weight of the leaf is correct, assign the edge connected to that vertex weight 0. Otherwise, assign it weight 1. Then remove the leaf and its corresponding edge. Actually, this shows that there is a one-to-one correspondents between the possible weights of the edges and the possible weights of the vertices.

For the edges not in the spanning tree we have chosen, we can arbitarily set their weights while we are still able to choose the weights of all but one vertex on this connected component by properly assigning weights of the edges in the spanning tree.

Suppose we want this constant value of R and C to be v, where v is either 0 or 1.

Suppose that the connected component has size n, has m edges and the xor of all the initial vertex weights is x.

If n is even:

 * If x=0, then there are 2m−n+1 ways to assign weights to edges.
* If x=1, then there are 0 ways to assign weights to edges.

If n is odd:

 * If x=v, then there are 2m−n+1 ways to assign weights to edges.
* If x≠v, then there are 0 ways to assign weights to edges.
 **Solution**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

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

int n,m;
char grid[2005][2005];

int w[4005];
vector<int> al[4005];

bool vis[4005];
int ss,par,edges;

void dfs(int i){
	if (vis[i]) return;
	vis[i]=true;
	
	ss++;
	par^=w[i];
	edges+=sz(al[i]);
	
	for (auto it:al[i]) dfs(it);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>grid[x];
	
	if (n%2>m%2){
	    swap(n,m);
		rep(x,0,2005) rep(y,0,2005) if (x<y) swap(grid[x][y],grid[y][x]);
	}
	
	// rep(x,0,n){
		// rep(y,0,m) cout<<grid[x][y]<<" "; cout<<endl;
	// }
	
	if (n%2==0 && m%2==0){
		int cnt=0;
		rep(x,0,n) rep(y,0,m) if (grid[x][y]=='?') cnt++;
		cout<<qexp(2,cnt,MOD)<<endl;
	}
	else if (n%2==0 && m%2==1){
		int cnt0=1,cnt1=1;
		
		rep(x,0,n){
			int val=0;
			int cnt=0;
			rep(y,0,m){
				if (grid[x][y]=='?') cnt++;
				else val^=grid[x][y]-'0';
			}
			if (cnt==0){
				if (val==0) cnt1=0;
				else cnt0=0;
			}
			else{
				cnt0=(cnt0*qexp(2,cnt-1,MOD))%MOD;
				cnt1=(cnt1*qexp(2,cnt-1,MOD))%MOD;
			}
		}
		
		cout<<(cnt1+cnt0)%MOD<<endl;
	}
	else{
		rep(x,0,n) rep(y,0,m){
			if (grid[x][y]!='?'){
				w[x]^=grid[x][y]-'0';
				w[y+n]^=grid[x][y]-'0';
			}
			else{
				al[x].pub(y+n);
				al[y+n].pub(x);
			}
		}
		
		int cnt0=1,cnt1=1;
		
		rep(x,0,n+m) if (!vis[x]){
			ss=0,par=0,edges=0;
			dfs(x);
			edges/=2;
			edges-=ss-1; //extra edge
			
			int mul=qexp(2,edges,MOD);
			
			if (ss%2==0){
				if (par) mul=0;
				cnt0=(cnt0*mul)%MOD;
				cnt1=(cnt1*mul)%MOD;
			}
			else{
				if (par==0){
					cnt0=(cnt0*mul)%MOD;
					cnt1=0;
				}
				else{
					cnt0=0;
					cnt1=(cnt1*mul)%MOD;
				}
			}
		}
		
		cout<<(cnt0+cnt1)%MOD<<endl;
	}
}

```
[1672H - Zigu Zagu](../problems/H._Zigu_Zagu.md "Codeforces Global Round 20")  
Author: [maomao90](https://codeforces.com/profile/maomao90 "Master maomao90"), [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**We will always remove a maximal segment, or in other words we will select l and r such that Al−1=Al and Ar=Ar+1.

 **Hint 2**Try to find an invariant.

 **Tutorial**We can first split string A into the minimum number of sections of 010101… and 101010…. Let the number of sections be K. Since we can simply delete each section individually, the worst answer that we can get is K. Also, there is no reason to only delete part of a segment, so from here on we only assume that we delete maximal segments.

Now, we can decompose A based on its K sections and write it as a string D. The rules for the decomposition is as follows:

 * 10…01→x
* 01…10→x′
* 10…10→y
* 01…01→y′

For example, the string A=[0101][1][1010] becomes D=y′xy. Now, let us look at what our operation does on D.

When we remove a section of even length (y or y′) **that is not on the endpoint of the string**, the left and right sections will get combined. This is because the two ends of an even section are opposite, allowing the left and right sections to merge. Otherwise, it results in no merging.

When some sections get combined, the length of string D gets reduced by 2, while the length of D gets reduced by 1 otherwise. Clearly, we want to maximize deleting the number of sections of even length that are not on the endpoints of the string. We will call such a move a **power** move.

Let us classify strings that have no power moves. They actually come in 8 types:

 * xx…x
* y′xx…x
* xx…xy
* y′xx…xy
* x′x′…x′
* yx′x′…x′
* x′x′…x′y′
* yx′x′…x′y′

We can prove that for any string not of this form, there will be always be character y or y′ that is not on the ends of the string. Suppose that the string contains both x and x′, then xyx′ or x′y′x must be a substring. Also, the number of y or y′s on each side cannot be more than 1. Note that strings such that y or yy′ may fall under multiple types.

Furthermore, for string of these types, the number of moves we have to make is equal to the length of the string.

Let us define the balance of x as the number of x minus the number of x′. We will define the balance of y similarly. When we perform a power move, notice that the balance of the string is unchanged. Indeed, each power move either removes a pair of x and x′ or y and y′ from the string.

With this, we can easily find which type of ending string we will end up with based on the perviously mentioned invariants, except for the cases of differentiating between the string xx…x and y′xx…xy (and the case for x′).

To differentiate between these 2 cases, we can note that the first character of our string does not change when we perform power moves. And indeed, x and y′ have different starting characters.

Note that we have to be careful when the balance of x and the balance of y is 0 in the initial string as for strings such as yy′, the final string is not ∅ but yy′. With this, we can answer queries in O(1) since we can query the balance of x, the balance of y and the total length of the decomposed string in O(1).

Furthermore, there is a implementation trick here. Notice that if al−1≠al, then then answer for s[l−1,r] will be equal to the answer for s[l,r]. So in implementation, it is easier to "extend" l and r to find the balance of x and y.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n,q;
string s;
int l[200005];
int r[200005];
int psum[200005];
int balance[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	cin>>s;
	
	s=s[0]+s+s[n-1];
	
	for (int x=1;x<=n;x++){
		if (s[x-1]==s[x]) l[x]=x;
		else l[x]=l[x-1];
	}
	
	for (int x=n;x>=1;x--){
		if (s[x]==s[x+1]){
			r[x]=x;
			psum[x]=1;
			if ((x-l[x])%2==0){
				balance[x]=(s[x]=='1'?1:-1);
			}
		}
		else r[x]=r[x+1];
	}
	
	for (int x=1;x<=n;x++){
		psum[x]+=psum[x-1];
		balance[x]+=balance[x-1];
	}
	
	int a,b;
	while (q--){
		cin>>a>>b;
		a=l[a],b=r[b];
		
		int bl=balance[b]-balance[a-1];
		int sum=psum[b]-psum[a-1];
		
		int ans=(sum+abs(bl))/2;
		
		if ((sum+abs(bl))%2==1) ans++;
		else if (abs(bl)==0) ans++;
		else if (bl>0 ^ s[a]=='1') ans++;
		
		cout<<ans<<"n";
	}
}
```
[1672I - PermutationForces](../problems/I._PermutationForces.md "Codeforces Global Round 20")  
Author: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hints****Hint 1**When removing an element, consider how the costs of other elements change?

 **Hint 2**When removing an element, consider the elements whose cost increase. What are their properties?

 **Hint 3**Is there a greedy algorithm?

 **Hint 4**Yes there is. How to make it run fast?

 **Hint 5**Use monotonicity to reduce one dimension

 **Tutorial**Let us rephrase the problem. Let x and y be arrays where xi=pi and yi=i initially. For brevity, let ci=|xi−yi|.

We want to check if we can do the following operation n times on the array:

 * Choose an index i such that and ci≤s.
* For all j where xi<xj, update xj←xj−1.
* For all j where yi<yj, update yj←yj−1.
* Set xi←∞ and yi←−∞

Let us fix s and solve the problem of checking whether a value of s allows us to transform the permutation into the empty permutation.

### Lemma 1

Let (x,y,c) be the arrays before some arbitrary operation and (x′,y′,c′) be the arrays after that operation. If we only perform moves with ci≤s, then cj≤s implies that c′j≤s i.e. if something was removable before, it will be removable later if we only use valid moves.

Proof: Note that x′j=xj or x′j=xj−1. The case for y is same.

We can see that c′j≤cj+1. So the only case where c′j>s is when cj=s.

Case 1: xj≤yj

Then it must be that x′j=xj and y′j=yj−1. By the definition of our operation, we have the following inequality: xi<xj≤yj<yi.

This implies that ci>s, which is a contradiction.

Case 2: xj≥yj

By similar analysis we see that ci>s. ◼

Suppose that we only remove points with ci≤s for some fixed s. This greedy algorithm works here - at each step, choose any point ci≤s with and remove it. - if no such point exists, the s does not work

Proof:

Given any permutation, let any point with ca≤s be a. Consider any optimal sequence of moves [b1,b2,…,bw,a,…]. We can transform to another optimal solution it by moving a to the front.

Let the element before a to be bw. We will swap a and bw. a is already removable at the start so it will be removable after removing b1,b2,…,bw−1 by lemma 1. After removing everything before b1,b2,…,bw−1, bw is removable, so it will be removable after removing a by lemma 1. Hence we can move a to the front of the sequence of moves by repeatedly swaping elemenets.

By exchange arguement, the greedy solution of removing any point with ca≤s is an optimal solution.

### Time Complexity Speedups

By extension, the following greedy algorithm works:

Set s←0.

 * At each step, choose index i with minimal ci
* Update s←max(s,ci)
* Remove point i

Let's start with s=0 and remove things while we can. If we are at a state that we are stuck, incremenet s. When we increment s, the moves that we haved done before will still be a valid choice with this new value of s. We simply increment s until we can remove the entire permutation which is 

Now the only difficult part about this is maintaining the array ci (the cost) for the points we have not removed.

Let's define a point as **good** as follows:

If y<x, the point is good if there exist no other point (x′,y′) such that y<y′≤x′<x.

Otherwise, the point is good if there exist no other point (x′,y′) such that x<x′≤y′<y.

We maintain only the good elements, because only good elements are candidates for the minimum ci. Suppose element is not good and minimal, then the point that causes it to be not good has a strictly smaller cost, an obvious contradiction.

Now we will use data structures to maintain ci of good points. We will split the good points into the **left good** and **right good** points which are those of xi≤yi and yi≤xi respectively. Notice that if xi=yi, then it is both left good and right good.

We will focus on the left good points. Suppose i and j are both left good with xi<xj, then yi<yj. Suppose otherwise, then we have xi<xj≤yj<yi, making i not good. As such x and y of the left good points are monotone. 

To find this monotone chain of left good points, we can maintain a max segment tree which stores max y for all alive x. Using binary search on segment tree to find the unique point with x′>x such that y′ is minimized. Where (x,y) is a point on the chain, and (x′,y′) is the next point. We can repeatedly do this to find the entire chain of left good elements

We can store a segment tree where i is the key and ci is the value. If an element is left good, it will always be left good until it is removed.

The following two operations are simply range updates on the segment tree since yi is monotone. - For all j such that xj>xi, set xj←xj−1. - For all j such that yj<yi, set yj←yj−1.

Now, when we remove some left good point, some other points will become left good, and we will need to add them. We do this by starting from the previous element of the left good chain, and then keep repeating the same algo using descend on the segment tree.

When we add a new left good point, we need to know the cost at the current point in time. If we consider a point which is initially (x,y), and all other previously removed (x′,y′), x decreases by 1 per x′<x and y decreases by 1 per y′<y. Hence, we can maintain a fenwick tree of the removed point's x and y, and using that we can determine the x and y at the time when we add it to the left good chain (and hence to the segment tree).

Time Complexity: O(nlogn)

#### Quad Trees

Thanks to [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994") for pointing this out.

Surprisingly quad trees are provably O(n√n) here. Take the k-th layer of the quad tree. The n⋅n grid will be split into 4k squares in the k-th layer. Since we are doing half plane covers, our query range will only touch 2k squares. At the same time, the width of those 2k squares is n2k. Since each column only has a single element, our query range will also by bounded by n2k. The time complexity for a single update is given by logn∑k=1min(2k,n2k)=O(√n).

 **Solution**
```cpp
// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ii pair<int,int>
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct FEN{
	int fen[500005];
	
	FEN(){
		memset(fen,0,sizeof(fen));
	}
	
	void upd(int i,int j){
		while (i<500005){
			fen[i]+=j;
			i+=i&-i;
		}
	}
	
	int query(int i){
		int res=0;
		while (i){
			res+=fen[i];
			i-=i&-i;
		}
		return res;
	}
} fval,fidx;

struct dat{
	struct node{
		int s,e,m;
		ii val;
		int lazy=0;
		node *l,*r;
		
		node (int _s,int _e){
			s=_s,e=_e,m=s+e>>1;
			val={1e9,s};
			
			if (s!=e){
				l=new node(s,m);
				r=new node(m+1,e);
			}
		}
		
		void propo(){
			if (lazy){
				val.fi+=lazy;
				if (s!=e){
					l->lazy+=lazy;
					r->lazy+=lazy;
				}
				lazy=0;
			}
		}
		
		void update(int i,int j,int k){
			if (s==i && e==j) lazy+=k;
			else{
				if (j<=m) l->update(i,j,k);
				else if (m<i) r->update(i,j,k);
				else l->update(i,m,k),r->update(m+1,j,k);
				
				l->propo(),r->propo();
				val=min(l->val,r->val);
			}
		}
		
		void set(int i,int k){
			propo();
			if (s==e) val.fi=k;
			else{
				if (i<=m) l->set(i,k);
				else r->set(i,k);
				
				l->propo(),r->propo();
				val=min(l->val,r->val);
			}
		}
	} *root=new node(0,500005);
	
	struct node2{
		int s,e,m;
		int val=-1e9;
		node2 *l,*r;
		
		node2 (int _s,int _e){
			s=_s,e=_e,m=s+e>>1;
			
			if (s!=e){
				l=new node2(s,m);
				r=new node2(m+1,e);
			}
		}
		
		void update(int i,int k){
			if (s==e) val=k;
			else{
				if (i<=m) l->update(i,k);
				else r->update(i,k);
				val=max(l->val,r->val);
			}
		}
		
		ii query(int i,int key){ //find key<=val where i<=s
			if (e<i || val<key) return {-1,-1};
			if (s==e) return {s,val};
			else{
				auto temp=l->query(i,key);
				if (temp!=ii(-1,-1)) return temp;
				else return r->query(i,key);
			}
		}
	} *root2=new node2(0,500005);
	
	set<ii> s={ {500005,500005} };
	
	//root stores the values of each pair
	//root2 stores the left endpoint of each pair to add non-overlapping ranges
	//s stores the pairs are still alive so its easy to do searches
	
	dat *d; //we also store the other guy
	bool orien; //false for i->arr[i]
	
	int pp[500005];
	
	void push(int i,int j){
		pp[j]=i;
		root2->update(j,i);
	}
	
	void add(int i,int j){
		root2->update(j,-1e9);
		s.insert({i,j});
		
		int val;
		if (!orien) val=fval.query(j)-fidx.query(i);
		else val=fidx.query(j)-fval.query(i);
		
		root->set(j,val);
	}
	
	void del(int j){
		ii curr={-1,-1};
		int lim=500005;
		
		if (j!=-1){
			int i=pp[j];
			
			auto it=d->s.ub({j,1e9});
			d->root->update(i,(*it).se-1,-1);
			
			if (!orien) fidx.upd(i,-1),fval.upd(j,-1);
			else fval.upd(i,-1),fidx.upd(j,-1);
			
			it=s.find({i,j});
			if (it!=s.begin()) curr=*prev(it);
			lim=(*next(it)).se;
			s.erase(it);
			root->set(j,1e9);
			root2->update(j,-1e9);
		}
		
		while (true){
			auto temp=root2->query(curr.se,curr.fi);
			swap(temp.fi,temp.se);
			if (temp==ii(-1,-1) || lim<=temp.se) break;
			
			add(temp.fi,temp.se);
			curr=temp;
		}
	}
} *l=new dat(),*r=new dat();

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	//cyclic mapping to each other
	l->d=r;
	r->d=l;
	
	r->orien=true;
	
	cin>>n;
	rep(x,1,n+1){
		int y;
		cin>>y;
		
		if (x<=y) l->push(x,y);
		else r->push(y,x);
	}
	
	rep(x,1,n+1) fidx.upd(x,1),fval.upd(x,1);
	l->del(-1);
	r->del(-1);
	
	int ans=0;
	
	rep(x,0,n){
		if (l->root->val.fi<=r->root->val.fi){
			ans=max(ans,l->root->val.fi);
			l->del(l->root->val.se);
		}
		else{
			ans=max(ans,r->root->val.fi);
			r->del(r->root->val.se);
		}
	}
	
	cout<<ans<<endl;
}
```
