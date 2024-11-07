# Tutorial_(en)

[1526A - Mean Inequality](../problems/A._Mean_Inequality.md "Codeforces Round 723 (Div. 2)")
---------------------------------------------------------------------------------------------------------

Setter: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o")  
Preparer: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn")

 **Hint 1**Notice that the array size is even length. Usually in such problems, we would split the array into 2 equal parts. Can you figure out what those 2 parts are?

 **Hint 2**We sort the array and split it into the big half and the small half.

 **Solution**The main idea is that we can split the numbers into the two halves, the big half and small half, we can place the bigger half at the odd positions and the smaller half at the even positions. 

This works because the smallest big number is larger than the biggest small number. Hence, the mean of any two small numbers is smaller than any big number, and the mean of any two big numbers is bigger than any small number.

 **Code (C++)**
```cpp
//雪花飄飄北風嘯嘯
//天地一片蒼茫

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << " is " << x << endl

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
int arr[55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,2*n) cin>>arr[x];
		
		sort(arr,arr+2*n);
		
		rep(x,0,n) cout<<arr[x]<<" "<<arr[x+n]<<" ";
		cout<<endl;
	}
}
```
 **Code (Python)**
```cpp
[(lambda n: (lambda arr : [print(f'{arr[i]} {arr[i+n]}', end = ' n'[i==n-1]) for i in range(n)])(sorted(list(map(int,input().split())))))(int(input())) for _ in range(int(input()))]
```
[1526B - I Hate 1111](../problems/B._I_Hate_1111.md "Codeforces Round 723 (Div. 2)")
-----------------------------------------------------------------------------------------------------

Setter: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn")  
Preparer: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn")

 **Hint 0**Read the name of the problem ;)

 **Hint 1**1111=11⋅101

 **Hint 2**All numbers other than 11 and 111 are useless.

 **Solution**Method 1
--------

Notice that 1111=11⋅100+11 and similarly 11111=111⋅100+11. This implies that we can construct 1111 and all bigger numbers using only 11 and 111. So it suffices to check whether we can construct X from 11 and 111 only.

Suppose X=A⋅11+B⋅111, where A,B≥0. Suppose B=C⋅11+D, where D<11. Then X=(A+C⋅111)⋅11+D⋅111. So we can just brute force all 11 value of D to check whether X can be made.

Method 2
--------

Since gcd(11,111)=1, by the [Chicken McNugget Theorem](https://codeforces.com/https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem), all numbers greater than 1099 can be written as a sum of 11 and 111. We can use brute force to find the answer to all values less than or equal to 1099 and answer yes for all other numbers.

 **Code (C++)**
```cpp
//雪花飄飄北風嘯嘯
//天地一片蒼茫

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << " is " << x << endl

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		rep(x,0,20){
			if (n%11==0){
				cout<<"YES"<<endl;
				goto done;
			}
			
			n-=111;
			if (n<0) break;
		}
		cout<<"NO"<<endl;
		
		done:;
	}
}
```
 **Code (Python)**
```cpp
[(lambda n : print("YES" if (n >= 111*(n%11)) else "NO"))(int(input())) for _ in range(int(input()))]
```
[1526C1 - Potions (Easy Version)](../problems/C1._Potions_(Easy_Version).md "Codeforces Round 723 (Div. 2)") and [1526C2 - Potions (Hard Version)](../problems/C2._Potions_(Hard_Version).md "Codeforces Round 723 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Setter: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn") and [oolimry](https://codeforces.com/profile/oolimry "Master oolimry")  
Preparer: [oolimry](https://codeforces.com/profile/oolimry "Master oolimry")

 **Hint 1**Try dp!

 **Hint 2**The dp states are position and number of potions drank.

 **Hint 3**Speedup dp or use greedy for full solution.

 **Solution**Method 1 — DP
-------------

Let's consider a dynamic programming solution. Let dp[i][k] be the maximum possible health achievable if we consider only the first i potions, and k is the total number of potions taken. 

The transition is as follows: dp[i][k]=max(dp[i−1][k−1]+ai,dp[i−1][k]) if dp[i−1][k−1]+ai≥0, and just dp[i−1][k] otherwise. The first term represents the case if we take potion i and the second term is when we ignore potion i.

This runs in O(n2) and passes the easy version.

Method 2 — Greedy 1
-------------------

We iterate through the potions in non-decreasing order and drink the potion if we do not die.

For convenience, we define ci=ai+i⋅ϵ, where ϵ is a very small real number so that we can treat ci as distinct integers. We will show by exchange argument that our greedy is optimal.

Let S be the set of potions that is an optimal solution.

Suppose i<j and ci<cj. If i∈S and j∉S, then removing i and adding j into S will still make S a valid solution.

Now, suppose that position i is not drunk. We can assume that there are no k (k<i) such that ck<ci and k is drunk by the previous assertion. Suppose we add i into S. If we reach a position j (we possibly die at j) where cj<ci, then we can remove j from S and add i to S. Otherwise, our greedy will also not choose i, as it was not chosen when we only consider indexes k such that ck<ci.

Notice that we can arbitrarily define the way ϵ is added, so basically we can process ai in any non-increasing fashion.

Doing this naively is O(n2) as well. However, using a range add range max lazy propagation segment tree, we can check if a certain potion can be drunk without dying, and the solution runs in O(nlogn).

Method 3 — Greedy 2 / DP 2
--------------------------

We process the potions from left to right. At the same time, we maintain the list of potions we have taken so far. When processing potion i, if we can take i without dying, then we take it. Otherwise, if the most negative potion we've taken is more negative than potion i, then we can swap out potion i for that potion. To find the most negative potion we've taken, we can maintain the values of all potions in a minimum priority_queue. This runs in O(nlogn) as well

To prove that this works, let's consider best solution where we take exactly k potions (best as in max total health). The solution involves taking the k largest values in our priority queue. Then when considering a new potion, we should see whether swapping out the new potion for the $k$th largest potion will improve the answer. 

Since the priority queue is strictly decreasing, there will be a cutoff K, where for k at most K, the answer is not affected, and for larger than K, we swap out the kth largest potion. It turns out this process is equivalent to inserting the new potion's value into the priority_queue. For those positions at most K, they are not affected. For the positions larger than K, the elements get pushed back one space, meaning that the smallest element is undrinked.

This can also be seen as an efficient way to to transition from one layer of the dp table to the next.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;

struct node{
	int s, e, m;
	long long val = 0; long long lazy = 0;
	node *l, *r;
	
	node(int S, int E){
		s = S, e = E, m = (s+e)/2;
		if(s != e){
			l = new node(s, m);
			r = new node(m+1, e);
		}
	}
	
	void apply(long long L){
		val += L;
		lazy += L;
	}
	void push(){
		if(s == e) return;
		l->apply(lazy);
		r->apply(lazy);
		lazy = 0;
	}
	
	void update(int S, int E, long long L){
		push();
		if(s == S && E == e){
			apply(L);
			return;
		}
		else if(E <= m) l->update(S, E, L);
		else if(S >= m+1) r->update(S, E, L);
		else l->update(S, m, L), r->update(m+1, E, L);
		val = min(l->val, r->val);
	}
	
	long long query(int S, int E){
		push();
		if(s == S && E == e) return val;
		else if(E <= m) return l->query(S, E);
		else if(S >= m+1) return r->query(S, E);
		else return min(l->query(S, m), r->query(m+1, E));
	}
} *root;	


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	ii arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int ans = 0;
	root = new node(0, n-1);
	for(int i = 0;i < n;i++){
		int pos = arr[i].second;
		long long x = arr[i].first;
		
		if(x + root->query(pos,n-1) >= 0){
			ans++;
			root->update(pos,n-1,x);
		}
	}
	
	cout << ans;
}
```
 **Code 2 (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	long long S = 0;
	
	for(int i = 1;i <= n;i++){
		long long x; cin >> x;
		S += x;
		pq.push(x);
		
		while(S < 0){
			S -= pq.top();
			pq.pop();
		}
	}
	
	cout << (int) pq.size();
}
```
 **Code (Python)**
```cpp
import heapq
H = []
n=int(input())
for i in list(map(int,input().split())):
    tot = (tot+i if 'tot' in locals() or 'tot' in globals() else i)
    tot -= ((heapq.heappush(H,i) if tot >= 0 else heapq.heappushpop(H,i)) or 0)
print(len(H))
```
[1526D - Kill Anton](../problems/D._Kill_Anton.md "Codeforces Round 723 (Div. 2)")
----------------------------------------------------------------------------------------------------

Setter: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn")  
Preparer: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn")

 **Hint 1**The time it takes for Anton's body to revert the string is related to inversion number.

 **Solution**We claim that in the optimal answer all characters of some type will appear consecutively. 

 **Proof**Consider the character at position i in string s. We define Ci as the position in which that character will be in string t. For s=CAGCAA and t=AAGCAC, C=4,1,3,6,2,5. Then the minimum number of moves to transformed s to t is given by the inversion index of C.

Suppose we find a substring of s where it is XXAA...AA[A]XX...XX[A]AA...AAXX, where characters X can be either one of TCG. The square brackets are just for clarity of explanation. We will show that it our solution will not be worse if we merge these 2 contiguous segments of A.

Consider transforming the string into XXAA...AAXX...XX[A][A]AA...AAXX and XXAA...AA[A][A]XX...XXAA...AAXX. Let the difference in the number of moves be D1 and D2 respectively. And let the index of [A]s be i and j respectively.

Then D1=j−1∑k=i+1σ(Ck−Ci) and D2=j−1∑k=i+1σ(Cj−Ck), where σ(x)=x|x|, or rather σ is the [sign function](https://codeforces.com/https://en.wikipedia.org/wiki/Sign_function).

I claim that D1+D2≥0. Suppose that D1+D2<0, then there exist k such that σ(Ck−Ci)+σ(Cj−Ck)<0 which implies Ck−Ci<0 and Cj−Ck<0. However, this implies that Cj<Ci which is clearly a contradiction.

Since D1+D2≥0, either D1≥0 or D2≥0. WLOG, D1≥0. This implies that we turn s into XXAA...AAXX...XX[A][A]AA...AAXX without decreasing the number of moves to transform s into t. Now, consider the rest of the A on the left segment of A. We can move it too the right also. Recall that D1+D2≥0. In this case, we know that D2≤0 as it is the cost to move the left [A] back to its original position. So D1≥0. Therefore, we have merged 2 different segments of A without decreasing the number of moves to transform s into t.

So, we can try all 24 possible strings and check the number of moves Anton's body needs to transform each string. The time limit is relaxed enough for a O(nlogn) similar to [1430E - String Reversal](https://codeforces.com/contest/1430/problem/E "Educational Codeforces Round 96 (Rated for Div. 2)").

But there is a O(n) solution, the number of moves Anton's body needs to transform each string is given by the number of inversions in the string. But since we know that we only care about strings that have all the same characters appear consecutively, we can just keep a count of the number of inversions for each pair of characters.

 **Code (C++)**
```cpp
//雪花飄飄北風嘯嘯
//天地一片蒼茫

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << " is " << x << endl

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
string s;
int cnt[4];

ll flips[4][4];

map<char,int> id={{'A',0},{'N',1},{'O',2},{'T',3}};
string cset="ANOT";

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>s;
		n=sz(s);
		
		memset(cnt,0,sizeof(cnt));
		memset(flips,0,sizeof(flips));
		
		rep(x,0,n){
			cnt[id[s[x]]]++;
		}
		rep(a,0,4){
			int curr=0;
			rep(x,0,n){
				flips[a][id[s[x]]]+=curr;
				if (id[s[x]]==a) curr++;
			}
		}
		
		ll best=-1;
		vector<int> ans;
		
		vector<int> v={0,1,2,3};
		do{
			ll curr=0;
			rep(x,0,4){
				rep(y,x+1,4){
					curr+=flips[v[y]][v[x]];
				}
			}
			
			if (curr>best){
				best=curr;
				ans=v;
			}
		} while (next_permutation(all(v)));
		
		for (auto &it:ans) rep(x,0,cnt[it]) cout<<cset[it];
		cout<<endl;
	}
}
```
 **Code (Python)**
```cpp
import itertools

TC=int(input())

m={"A":0,"N":1,"O":2,"T":3}
st="ANOT"

for _ in range(TC):
	s=input()
	arr=[]
	
	for ch in s:
		arr.append(m[ch])
	
	cnt=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
	cnt1=[0,0,0,0]
	
	for i in arr:
		for j in range(4):
			cnt[j][i]+=cnt1[j]
		cnt1[i]+=1
	
	val=-1
	best=[]
	
	for perm in itertools.permutations([0,1,2,3]):
		curr=0
		for i in range(4):
			for j in range(i+1,4):
				curr+=cnt[perm[j]][perm[i]]	
		
		if (curr>val):
			val=curr
			best=perm
			
	
	for i in range(4):
		for j in range(cnt1[best[i]]): print(st[best[i]],end="")
	
	print()
```
[1526E - Oolimry and Suffix Array](../problems/E._Oolimry_and_Suffix_Array.md "Codeforces Round 723 (Div. 2)")
------------------------------------------------------------------------------------------------------------------

Setter: [iLoveIOI](https://codeforces.com/profile/iLoveIOI "Candidate Master iLoveIOI")  
Preparer: [iLoveIOI](https://codeforces.com/profile/iLoveIOI "Candidate Master iLoveIOI")

 **Hint 1**Try to solve the problem of the minimal K needed to make a string with such a suffix array.

 **Solution**First, let's consider a simpler problem. 

Is it possible to make a string with a certain suffix array given an alphabet size k.

Consider two adjacent suffixes in the suffix array "xy" and "ab" where b and y are some strings and x and a are some characters i.e. x is the first character of that suffix and similarly for a. If b and y don't exist we consider them as \$, i.e. smaller than everything. Also, "xy" comes before "ab". 

Observation: If the position of b is less than the position of y in the suffix array, x must be less than a. Otherwise, x must be less than or equal to a.

This can be easily shown as "xy" must be lexicographically smaller than "ab". This is sufficient also. 

Thus we can iterate through the suffix array and check if pos[arr[i]+1]>pos[arr[i+1]+1] where arr is the suffix array and pos is the position of the ith element in the suffix array. If this condition holds then the arr[i] th character must be strictly less than the arr[i+1] th character. Thus we can just count how many such pairs exist. If this count is larger than the alphabet size no such string is possible. Otherwise, such string exists. Note that special care must be taken when considering arr[i]=n−1 as pos[n] may not be defined (0-indexed). 

After tackling the simpler question we move on to the full question of counting how many such strings are there. If we consider the string as an array and the order of the array as the order of the suffix array meaning that the i th element of this array is the arr[i] th element of the string. We have now transformed the question into **"Given that some elements must be greater than the previous elements while others can be equal. Count how many arrays are there such that the largest element is less than k"**. 

Consider the difference array, some elements must be ≥1 while some can be ≥0. We add padding to the front and back of the array so as to account for the first value being non-zero and the last element being less than k. These two elements are both ≥0. Let cnt be the number of elements that must be ≥1 in the difference array. Now, this becomes count how many arrays of (n−1+2)=(n+1) non-negative elements sum to k−cnt. This can be solved using stars and bars so the final answer comes out to be (n+1+k−cntn) which can be found easily. Note that we define (ab)=0 when a<b.

Final Complexity O(nlogMOD) or O(n) depending on how you find the modular inverse. 

Btw k was chosen to also be ≤2×105 so as to hide the final complexity :)

 **Code (C++)**
```cpp
/*input
5 4
3 4 2 1 0

*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld long double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll maxn=2e5+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e17;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
ll mult(ll a,ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll mypow(ll a,ll b){

    if(b<=0) return 1;
    if(a<=0) return 0;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}
int arr[maxn],pos[maxn];
ll inv(ll x){
    return mypow(x,MOD-2);
}
int32_t main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k;
    cin>>n>>k;
    --k;
    REP(i,n) cin>>arr[i],pos[arr[i]]=i;
    pos[n]=-1;
    int cnt=0;
    REP(i,n-1){
        // character at arr[i] and arr[i+1] cannot be the same
        if(pos[arr[i]+1]>pos[arr[i+1]+1]){
            ++cnt;
        }
    } 
    //calculate c(k-cnt+n+1-1,n+1-1)
    k-=cnt;
    if(k<0){
        cout<<0;
        return 0;
    }
    ll ans=1;
    REP1(i,n){
        ans=mult(ans,inv(i));
        ans=mult(ans,(k+i));
    }
    cout<<ans;
}
```
 **Code (Python)**
```cpp
MOD=998244353

n,k=map(int,input().split())
arr=list(map(int,input().split()))

pos=[0]*(n+1)

for i in range(n):
	pos[arr[i]]=i
pos[n]=-1

cnt=0

for i in range(n-1):
	if (pos[arr[i]+1]>pos[arr[i+1]+1]): cnt+=1

#k-cnt+n-1 choose n
num,denom=1,1

for i in range(n):
	num=num*(k-cnt+n-1-i)%MOD
	denom=denom*(i+1)%MOD

print(num*pow(denom,MOD-2,MOD)%MOD)
```
[1526F - Median Queries](../problems/F._Median_Queries.md "Codeforces Round 723 (Div. 2)")
--------------------------------------------------------------------------------------------------------

Setter: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn") and [oolimry](https://codeforces.com/profile/oolimry "Master oolimry")  
Preparer: [errorgorn](https://codeforces.com/profile/errorgorn "International Master errorgorn")

 **Hint 1**Find elements 1 and 2 in N+420 queries.

 **Hint 2**Find a pair (a,b) such that |p[b]−p[a]|≤n3−c, where c is some constant.

 **Solution**The problem can be broken into 2 main parts:

 * Finding a pair (a,b) such that |p[a]−p[b]| is roughly less than a third.
* Finding elements 1 and 2 (actually we may find N and N−1 but it is the same).
* Find the rest of the elements

A convenient way to think about the queries, is that given p[a]<p[b]<p[c], we will be returned max(p[b]−p[a],p[c]−p[b]).

We will spend the first queries to find a tuple (a,b,c) such that the return value of this query is at most ⌊n−46⌋. The easiest way to do this is by randomly choosing distinct a,b,c and querying it. See proof 1 for the random analysis. But there is also a deterministic solution. Choose any 13 elements from the array, and it is guaranteed that there exists a tuple in those 13 elements such that the return value of the query is at most ⌊n−46⌋, see proof 2. To query all tuples in this sub-array of size 13, it takes 286 queries, which fits very comfortably under 420. [user14767553](https://codeforces.com/profile/user14767553 "Candidate Master user14767553") conjectured that a sub-array of size 10 works, however we are unable to prove it. You can try to hack his solution at [117685511](https://codeforces.com/contest/1526/submission/117685511 "Submission 117685511 by user14767553").

Among a, b, and c, we choose a and b. The important idea here is that the gap between a and b is small, because we have found a tuple (a,b,c) is less than or equal to ⌊n−46⌋, so |p[a]−p[b]|≤2⋅⌊n−46⌋≤⌊n−43⌋. Now, we query all tuples (a,b,x) for all x≠a and x≠b. Since the gap between a and b is small, we should be able to identify either (1,2) or (n,n−1). This is because either p[a]−1>p[b]−p[a] or n−p[b]>p[b]−p[a] (WLOG assuming p[b]>p[a]), see proof 3. Therefore, the furthest x will return the largest value when querying for (a,b,x). (If there's ties choose anyone).

Suppose we found element 1, there are at most two possible candidates for element 2, y1 and y2 (the other possible candidate will be either n or n−1). We can use 2 queries to figure out which of them is element 2. We can query (1,y1,a) and (1,y2,a). Whichever produces the smaller value is element 2, see proof 4.

Once we have found elements 1 and 2, solving the rest of the problem is simple. Querying (1,2,x) will always return x−2. And we can find the rest of the elements in another n−2 queries. Do not forgot about the condition that p[0]<p[1]!

 **Proof 1**This is a rough asymptotic analysis for large n.

Observe that if

 * n6<b<5n6 (this happens around 23 of the time)
* b−n6<a<b (around 16 of the time)
* b<c<b+n6 (around 16 of the time)

Around 154, we will get a return value of less than 16. Since there are 6 permutations (i.e. relative orderings of a,b,c), there is a probability of roughly 19 that some permutation of (a,b,c) satisfies the above condition.

The probability that we do not find such a tuple after 420 queries is (89)420≈3.28⋅10−22. To put this into perspective, you have a higher chance of:

 * Flipping heads 70 times in a row
* Drawing a royal flush 5 times in a row
* Anton not rejecting a data structure problem
 **Proof 2**We will use contradiction.

let d1,d2,…... refer to the gaps between the elements. If the maximum any two consecutive gaps is at most ⌊n−46⌋, one of the queries will work. As such, it is necessary that least 6 of these gaps are at least ⌊n−46⌋.

Then we have 6⋅(⌊n−46⌋+1)+13 as the smallest possible size of the original array.

However, 6⋅(⌊n−46⌋+1)+13≥6⋅(n−96+1)+13=n+10 which is a clear contradiction. 

 **Proof 3**We proof this statement by contrapositive.

This statement is equivalent to: if a−1≤b−a and n−b≤b−a, then b−a>⌊n−43⌋. Abbreviating p[a] and p[b] to a and b respectively.

Using algebra, a−1≤b−a implies 2a−1≤b and n+a≤2b. 

Therefore, n+3a−1≤3b. 

Then, n−13≤b−a. 

It is trivial to see that ⌊n−43⌋<n−13. 

Therefore, we have shown that b−a>⌊n−43⌋.

 **Proof 4**Suppose that y1=2 and y2=n−1 or y2=n. We can bound a by y1<a<y2

We want to show that the query of (1,y1,a) is smaller than (1,a,y2).

This is equivalent to showing that max(|1−2|,|2−a|)<max(|1−a|,|a−y2|). 

Since 2<a, max(|1−2|,|2−a|)=a−2. 

Case 1: |1−a|≥|a−y2|  
max(|1−a|,|a−y2|)=a−1.  
Therefore, max(|1−2|,|2−a|)=a−2<a−1=max(|1−a|,|a−y2|).

Case 2: |a−y2|>|1−a|  
max(|1−a|,|a−y2|)=|a−y2|.  
Therefore, max(|1−2|,|2−a|)=a−2<a−1=|1−a|<|a−y2|=max(|1−a|,|a−y2|).

 **Code (C++)**
```cpp
//雪花飄飄北風嘯嘯
//天地一片蒼茫

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(177013);

int query(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	int temp;
	cin>>temp;
	
	return temp;
}

void sort(int &a,int &b,int &c){
	 if (a>b) swap(a,b);
	 if (b>c) swap(b,c);
	 if (a>b) swap(a,b);
}

void solve(){
	int n;
	cin>>n;
	
	vector<int> ans(n+5,0);
	
	set<tuple<int,int,int> > s;
	
	int a,b,c;
	rep(x,1,14) rep(y,x+1,14) rep(z,y+1,14){
		if (query(x,y,z)<=(n-4)/6){
			a=x,b=y,c=z;
			break;
		}
	}
	
	map<int,vector<int>,greater<int> > m;
	rep(x,1,n+1) if (x!=a && x!=b){
		m[query(a,b,x)].push_back(x);
	}
	
	int hv=(*m.begin()).fi;
	if (sz(m[hv-1])>=2){ //there must be exactly 2
		if (query(m[hv][0],m[hv-1][0],a)>
			query(m[hv][0],m[hv-1][1],a))
				swap(m[hv-1][0],m[hv-1][1]);
	}
	
	int hi=m[hv][0],hi2=m[hv-1][0];
	
	//cout<<hi2<<" "<<hi<<endl;
	
	ans[hi]=1,ans[hi2]=2;
	rep(x,1,n+1) if (x!=hi2 && x!=hi){
		ans[x]=query(hi,hi2,x)+2;
	}
	
	if (ans[1]>ans[2]) rep(x,1,n+1) ans[x]=n-ans[x]+1;
	
	cout<<"! "; rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
	
	cin>>n; //read stupid value
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		solve();
	}
}
```
 **Code (Python)**
```cpp
import sys, random

print = sys.stdout.write
input = sys.stdin.readline

def query(a, b, c):
    print("? " + str(a+1) + " " + str(b+1) + " " + str(c+1) + "n")
    sys.stdout.flush()
    return int(input())

def answer():
    print("! " + " ".join([str(i) for i in ans]) + "n")
    sys.stdout.flush()
    return int(input())

T = int(input())
testVal = 13

randomQueryOrder = []
for i in range(testVal):
    for j in range(i+1, testVal):
        for k in range(j+1, testVal):
            randomQueryOrder.append((i, j, k))

for caseno in range(T):
    N = int(input())
    
    a = -1
    b = -1

    ans = [0 for i in range(N)]
    res = [0 for i in range(N)]
    order = [i for i in range(N)]
    
    minVal = N+5
    
    random.shuffle(order)
    random.shuffle(randomQueryOrder)
    for ijk in randomQueryOrder:
        i, j, k = ijk
        i = order[i]
        j = order[j]
        k = order[k]
        temp = query(i, j, k)
        
        if temp <= (N-4)//6:
            a = i
            b = j
            break
    
    assert(a != -1 and b != -1)

    ''' Now, the key thing to note is that abs(P[a]-P[b]) is less than (roughly speaking) N/3.
    Observe that the index c such that query(a, b, c) is maximum must be such that P[c] == 1 or P[c] == N (some steps skipped).
    But given the condition P[1] < P[2], we can assume either, then flip using P[i] = N+1-P[i] if condition not satisfied.
    '''

    
# Now, we assume P[c] = 1
    
# There always exists another index d such that query(a, b, d) = query(a, b, c)-1 and P[d] = 2
    
# There can be only at most 2 d which satisfy the former, and we can check which is which by comparing query(a, c, d)

    maxVal = -1
    c = -1
    for i in range(N):
        if a == i or b == i:
            continue
        
        res[i] = query(a, b, i)
        if res[i] > maxVal:
            maxVal = res[i]
            c = i

    d2 = []
    for i in range(N):
        if a == i or b == i:
            continue
        
        if res[i] == maxVal-1:
            d2.append(i)

    d = -1
    if len(d2) == 1:
        d = d2[0]
    elif len(d2) == 2:
        temp1 = query(a, c, d2[0])
        temp2 = query(a, c, d2[1])
        if temp1 < temp2:
            d = d2[0]
        else:
            d = d2[1]
    else:
        assert(False)

    
# After finding indices c and d such P[c] = 1 and P[d] = 2, we can now find the rest of the values
    ans[c] = 1
    ans[d] = 2
    for i in range(N):
        if i == c or i == d:
            continue
        ans[i] = 2 + query(c, d, i)

    
# Flip since P[1] < P[2] not satisfied
    if ans[0] >= ans[1]:
        for i in range(N):
            ans[i] = N+1-ans[i]

    result = answer()

    
# I dislike getting WA, hence I make my code MLE
    if result != 1:
        MLE = [1 for i in range(1<<27)]
        sys.stdout.write(MLE[0])
```
Code Golf
---------

You may have realized that python codes in the editorial are quite short. We actually had a code golf challenge among testers. You are invited to try code golf our problems and put them in the comments. Maybe I will put the shortest codes in the editorial ;)

Rules for code golf:

 * any language allowed
* codes will be judged by number of characters
* must get AC in the respective problems
