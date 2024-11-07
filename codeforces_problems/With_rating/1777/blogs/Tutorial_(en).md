# Tutorial_(en)

We hope you enjoyed the contest!. Thank you for your participation! Do vote under the Feedback section, and feel free to give your review of the problems in the comments.

 

---

[1777A - Everybody Likes Good Arrays!](../problems/A._Everybody_Likes_Good_Arrays!.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")   


Idea: [ShivanshJ](https://codeforces.com/profile/ShivanshJ "Candidate Master ShivanshJ")   
 Preparation: [ShivanshJ](https://codeforces.com/profile/ShivanshJ "Candidate Master ShivanshJ")   
 Editorialist: [ShivanshJ](https://codeforces.com/profile/ShivanshJ "Candidate Master ShivanshJ")

 **Hints****Hint 1**Try to make the problem simpler.

 **Hint 2**Parity?

 **Hint 3**Try replacing even numbers with 0 and odd numbers with 1 in other words consider all numbers modulo 2.

 **Hint 4**Think harder! It works!

 **Solution**
### [1777A - Everybody Likes Good Arrays!](../problems/A._Everybody_Likes_Good_Arrays!.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")

Solution Replace even numbers with 0 and odd numbers with 1 in the array a. Now we observe that the given operation is equivalent to selecting two equal adjacent elements and deleting one of them. 

Now the array can be visualized as strips of zeros (in green) and ones (in red) like this [0,0,0,1,1,1,1,0,1,1]. Note that since the number of adjacent elements (a[i],a[i+1]) such that a[i]≠a[i+1] remains constant (nice invariant!), every strip can be handled independently. The size of every strip must be 1 in the final array and performing an operation reduces the size of the corresponding strip by 1.

So, for a strip of length L, it would require L−1 operations to reduce its size to 1. So, every strip would contribute −1 to the number of operations apart from its length. So, the answer is (n− total no. of strips) which also equals (n−x−1) where x is number of adjacent elements (a[i],a[i+1]) such that (a[i]≠a[i+1]). 

 **Implementation (C++)**
```cpp
                        /* Enjoying CP as always!*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        //Take input
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        //initialize answer..
        int ans=0;
        for(int i=0;i+1<n;i++) {
            ans+=(!((a[i]^a[i+1])&1));
            /*XOR the two numbers and check 0th bit in the resultant, if it is 1
            then, numbers are of different parity, otherwise both are of same parity*/
        }
        cout<<ans<<"n";
    }
    return 0;
}
```
 **Implementation (Python)**
```cpp
def main():
    T = int(input())
    while T > 0:
        T = T - 1
        n = int(input())
        a = [int(x) for x in input().split()]
        ans = 0
 
        for i in range(1, n):
            ans += 1 - ((a[i] + a[i - 1]) & 1)
 
        print(ans)
 
 
if __name__ == '__main__':
    main()
```
 **Feedback*** Good problem: 


[*144*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*204*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
[1777B - Emordnilap](../problems/B._Emordnilap.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")   


Idea: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101") [quantau](https://codeforces.com/profile/quantau "Expert quantau")   
 Preparation: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101")   
 Editorialist: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101")

 **Hints****Hint 1**Will the answer differ for different permutations?

 **Hint 2**If you only look at 2 elements, how much will they contribute to the answer?

 **Solution**
### [1777B - Emordnilap](../problems/B._Emordnilap.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")

Observation: Every permutation has the same beauty.

Consider two indices $i$ and $j$ ($i < j$) in a permutation $p$.

These elements appear in the order $[p_i, p_j, p_j, p_i]$ in array $A$.

Now we have two cases:

Case $1$: $p_i > p_j$

The first $p_i$ appears before both $p_j$'s in this case, accounting for $2$ inversions.

Case $2$: $p_i < p_j$

Both the $p_j$'s appear before the second $p_i$, accounting for $2$ inversions again.

Hence, any pair of indices in $p$ account for $2$ inversions in $A$.

Thus, beauty of every permutation $p = {n\choose 2} \cdot 2 = n \cdot (n - 1)$

Sum of beauties of all permutations $= n \cdot (n - 1) \cdot n!$

 **Implementation (C++)**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    const int N = 1e5 + 5;
    const int mod = 1e9 + 7;
    vector<int> fact(N);
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = n * (n - 1);
        ans %= mod;
        ans = (ans * fact[n]) % mod;
        cout << ans << endl;
    }
    return 0;
}
```
 **Implementation (Python)**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    nf = 1
    mod = int(1e9 + 7)
    for i in range(n):
        nf = nf * (i + 1)
        nf %= mod
    ans = n * (n - 1) * nf
    ans %= mod
    print(ans)
```
 **Feedback*** Good problem: 

 
[*372*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*41*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*74*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
[1777C - Quiz Master](../problems/C._Quiz_Master.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")   


Idea: [quantau](https://codeforces.com/profile/quantau "Expert quantau")   
 Preparation: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101") [quantau](https://codeforces.com/profile/quantau "Expert quantau")   
 Editorialist: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101")

 **Hints****Hint 1**Would sorting the array help?

 **Hint 2**Would iterating over the factors help?

 **Hint 3**If the optimal team has students with maximum smartness M and minimum smartness m, would having students with smartness X such that m≤X≤M the answer will not change.

 **Hint 4**Two pointers?

 **Solution**
### [1777C - Quiz Master](../problems/C._Quiz_Master.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")

We can sort the smartness values and use two pointers.

The two pointers indicate the students we are considering in our team. Let $l$ be the left pointer and $r$ be the right pointer.

$a_l$ is the minimum smartness of our team and $a_r$ is the maximum. If this team is collectively proficient in all topics, then the difference would be $a_r - a_l$.

Now, if $l$ is increased, the team may lose proficiency in some topics. $r$ would either stay the same or increase as well for the team to become proficient again.

For a team to be proficient, each number from $1$ to $m$ should have a smartness value which is a multiple of it.

To check for proficiency, we can maintain a frequency array $f$ of size $m$ and a variable $count$ to indicate the number of topics that have found a multiple.

When we add a student to the team, we iterate through all the factors of their smartness which are less than or equal to $m$ and increase their frequency. If an element had a frequency of $0$ before, then $count$ is increased by $1$.

Similarly, when we remove a student from the team, we go through all the factors less than or equal to $m$ and decrease their frequency. If an element now has $0$ frequency, then $count$ is decreased by $1$.

$count$ being equal to $m$ at any point indicates a collectively proficient team.

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define FASTIO                
    ios ::sync_with_stdio(0); 
    cin.tie(0);               
    cout.tie(0);

using namespace std;

const ll inf = 1e17;
const ll MAXM = 1e5;
vector<ll> factors[MAXM + 5];

void init()
{
    for (ll i = 1; i <= MAXM; i++)
    {
        for (ll j = i; j <= MAXM; j += i)
        {
            factors[j].pb(i);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pii> vec;
    for (ll i = 0; i < n; i++)
    {
        ll value;
        cin >> value;
        vec.pb({value, i});
    }
    sort(all(vec));
    vector<ll> frequency(m + 5, 0);
    ll curr_count = 0;
    ll j = 0;
    ll global_ans = inf;
    for (ll i = 0; i < n; i++)
    {
        for (auto x : factors[vec[i].ff])
        {
            if (x > m)
                break;
            if (!frequency[x]++)
            {
                curr_count++;
            }
        }
        while (curr_count == m)
        {
            ll curr_ans = vec[i].ff - vec[j].ff;
            if (curr_ans < global_ans)
            {
                global_ans = curr_ans;
            }
            for (auto x : factors[vec[j].ff])
            {
                if (x > m)
                    break;
                if (--frequency[x] == 0)
                {
                    curr_count--;
                }
            }
            j++;
        }
    }
    cout << (global_ans >= inf ? -1 : global_ans) << "n";
}

int main()
{
    FASTIO
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```
 **Feedback*** Good problem: 

 
[*552*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*89*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*106*](https://codeforces.com/data/like?action=like "I like this")
[1777D - Score of a Tree](../problems/D._Score_of_a_Tree.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")   


Idea: [AwakeAnay](https://codeforces.com/profile/AwakeAnay "International Master AwakeAnay")   
 Preparation: [mayankfrost](https://codeforces.com/profile/mayankfrost "Candidate Master mayankfrost") [ShivanshJ](https://codeforces.com/profile/ShivanshJ "Candidate Master ShivanshJ")   
 Editorialist: [AwakeAnay](https://codeforces.com/profile/AwakeAnay "International Master AwakeAnay")

 **Hints****Hint 1**What would be the value of a node at time t?

 **Hint 2**The value of a node u after time t would be the xor of the initial values of all nodes in the subtree of u which are at a distance t from u.

 **Hint 3**What is the expected value of xor of k boolean values?

 **Solution**
### [1777D - Score of a Tree](../problems/D._Score_of_a_Tree.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")

We will focus on computing the expected value of F(A) rather than the sum, as the sum is just 2n×E(F(A)).

Let Fu(A) denote the sum of all values at node u from time 0 to 10100, if the initial configuration is A.

Clearly, F(A)=∑Fu(A).

With linearity of expectations,

E(F(A))=∑E(Fu(A))

Define Vu(A,t) as the value of node u at time t, if the initial configuration is A.

Observe that Vu(A,t) is simply 0 if there is no node in u's subtree at a distance of t from u, otherwise, the value is the bitwise xor of the initial values of all nodes in the subtree of u at a distance of t from u.

Thus, define du as the length of the longest path from u to a leaf in u's subtree. Now, E(Vu(A,t)) is half if t is less than or equal to du, otherwise it's 0. This is because the expected value of xor of k boolean values is 0 is k is zero, otherwise it's half. This fact has multiple combinatorial proofs. For example, one can simply count the number of ways of choosing odd number of boolean values, among the k values as 1 to get ∑odd i(ki)=2k−1

We use this to get: E(Fu(A))=E(10100∑0Vu(A,t))=10100∑0E(Vu(A,t)=du+12

All the du values can be computed by a single traversal of the tree.

Our final result is:

2n×∑du+12

Time complexity: O(n)

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
 
long long power(long long a, int b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}
 
int DFS(int v, vector<int> edges[], int p, int dep, int ped[])
{
    int mdep = dep;
    for (auto it : edges[v])
        if (it != p)
            mdep = max(DFS(it, edges, v, dep + 1, ped), mdep);
    ped[v] = mdep - dep + 1;
    return mdep;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, i, j, n, u, v;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<int> edges[n];
        for (i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            u--, v--;
 
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
 
        int ped[n];
        DFS(0, edges, 0, 0, ped);
 
        long long p = power(2, n - 1), ans = 0;
        for (i = 0; i < n; i++)
        {
            ans += p * ped[i] % MOD;
            ans %= MOD;
        }
        cout << ans << "n";
    }
}
```
 **Feedback*** Good problem: 

 
[*225*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*50*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*48*](https://codeforces.com/data/like?action=like "I like this")
[1777E - Edge Reverse](../problems/E._Edge_Reverse.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")   


Idea: [Crocuta](https://codeforces.com/profile/Crocuta "Candidate Master Crocuta")   
 Preparation: [mayankfrost](https://codeforces.com/profile/mayankfrost "Candidate Master mayankfrost")   
 Editorialist: [mayankfrost](https://codeforces.com/profile/mayankfrost "Candidate Master mayankfrost")

 **Hints****Hint 1**If the cost is c, all edges with weight less than or equal to c are reversible.

 **Hint 2**If an edge can be reversed, can it be treated as bidirectional?

 **Hint 3**Let there exist a set of possible starting nodes. If this set is non empty, the highest node h in the topological ordering of nodes will always be present in the set. Think why.

 **Solution**
### [1777E - Edge Reverse](../problems/E._Edge_Reverse.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")

If the cost for completing the task is $c$, we can reverse any edge with cost $\le c$. This is equivalent to making those edges bidirectional since when checking for reachability, we only need to traverse an edge once, and we can choose to reverse it or not, depending upon the need.

We can apply a binary search on the minimum cost and check if there exists at least one node such that all nodes are reachable from it if all edges with cost less than or equal to the current cost become bidirectional.

To check in linear time if there exists such a suitable node, we will use a suppressed version of the Kosa Raju algorithm. We condense the nodes into Strongly Connected Components (SCCs) and perform a topological sort on them. If there exists an SCC from which all SCCs are reachable, then the first element in the topological sort will be that SCC (since in a topological sort, an element can only reach elements coming after it). So, we can choose any node from the first SCC in the topological sort and apply DFS to check if all the nodes are reachable from that node. If they aren't, we conclude it is impossible to complete the task with the current cost.

Overall time complexity: $O((N+M) \cdot \log C)$

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
// Using Kosa Raju, we guarantee the topmost element (indicated by root) of stack is from the root SCC
 
void DFS(int v, bool visited[], int &root, vector<int> edges[])
{
    visited[v] = true;
    for (auto it : edges[v])
        if (!visited[it])
            DFS(it, visited, root, edges);
    root = v;
}
 
int cnt(int v, bool visited[], vector<int> edges[])
{
    int ans = 1;
    visited[v] = true;
    for (auto it : edges[v])
        if (!visited[it])
            ans += cnt(it, visited, edges);
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int i, j, n, m, u, v, w;
        cin >> n >> m;
        vector<pair<int, int>> og_edges[n];
        for (i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            u--, v--;
 
            og_edges[u].push_back({v, w});
        }
 
        int l = -1, r = 1e9 + 1, mid;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
 
            vector<int> edges[n];
            for (i = 0; i < n; i++)
            {
                for (auto it : og_edges[i])
                {
                    edges[i].push_back(it.first);
                    if (it.second <= mid)
                        edges[it.first].push_back(i);
                }
            }
 
            bool visited[n] = {};
            int root;
            for (i = 0; i < n; i++)
            {
                if (!visited[i])
                    DFS(i, visited, root, edges);
            }
 
            memset(visited, false, sizeof(visited));
 
            if (cnt(root, visited, edges) == n)
                r = mid;
            else
                l = mid;
        }
 
        if (r == 1e9 + 1)
            r = -1;
        cout << r << 'n';
    }
    return 0;
}

```
 **Feedback*** Good problem: 

 
[*93*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")
[1777F - Comfortably Numb](../problems/F._Comfortably_Numb.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")   


Idea: [Crocuta](https://codeforces.com/profile/Crocuta "Candidate Master Crocuta")   
 Preparation: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101")   
 Editorialist: [Crocuta](https://codeforces.com/profile/Crocuta "Candidate Master Crocuta")

 **Hints****Hint 1**Can we somehow fix the maximum element ?

 **Hint 2**To calculate the answer over all subarrays with the same maximum element, can we use the trie trick for calculating the maximum xor.

 **Solution**
### [1777F - Comfortably Numb](../problems/F._Comfortably_Numb.md "Codeforces Round 845 (Div. 2) and ByteRace 2023")

The problem can be solved recursively. Keep dividing the array into subarrays at the maximum element of the current subarray. 

Let's say the maximum element of the initial array is at index $x$, so the array gets divided into two subarrays $a[1...x-1]$ and $a[x+1,...n]$. Say we have already calculated the answer for the left and right subarrays. Now, we need to calculate the answer for all the subarrays containing $a[x]$ to complete the process for the array. 

To do this, we will maintain two separate tries for both the left and right parts. This trie will contain all the prefix xor values for all the indices in the respective part. We will iterate over the smaller subarray out of the two. For every index, we will try to find the largest answer that can be obtained from a subarray with one end at this index. This can be done by moving the prefix xor value at the current index (xor'ed with $a[x]$) over the 'prefix xor trie' of the other subarray. This will cover all the subarrays containing $a[x]$, and so the entire array will now get covered. After the process, we will merge the two tries into one by again iterating over the smaller subarray.

Similarly, we can solve for left subarray and right subarray by finding their respective maximum element, and dividing the subarray at that element.

As we follow small-to-large merging, there are about $nlogn$ operations on the trie, and so the overall time complexity is $\mathcal{O}(n \log n \log A)$.

 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
struct Trie{
	struct Trie *child[2]={0};
};
typedef struct Trie trie;
 
void insert(trie *dic, int x)
{
	trie *temp = dic;
	for(int i=30;i>=0;i--) 
	{
		int curr = x>>i&1;
		if(temp->child[curr])
			temp = temp->child[curr];
		else
		{
			temp->child[curr] = new trie;
			temp = temp->child[curr];
		}
	}
}
 
int find_greatest(trie *dic, int x) {
	int res = 0;
	trie *temp = dic;
	for(int i=30;i>=0;i--) {
		int curr = x>>i&1;
		if(temp->child[curr^1]) {
			res ^= 1<<i;
			temp = temp->child[curr^1];
		}
		else {
			temp = temp->child[curr];
		}
	}
	return res;	
}
 
int main() {
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
 
		trie *t[n+2];
		int prexor[n+1];
		prexor[0] = 0;
		for(int i=1;i<=n;i++) {
			t[i] = new trie;
			insert(t[i], prexor[i-1]);
			prexor[i] = prexor[i-1]^a[i];
		}
		t[n+1] = new trie;
		insert(t[n+1], prexor[n]);
		
		pair<int,int> asc[n+1];
		for(int i=1;i<=n;i++) {
			asc[i] = make_pair(a[i],i);
		}
		sort(asc+1,asc+n+1);
		
		int left[n+1], right[n+1];
		stack<int> s;
		for(int i=1;i<=n;i++) {
			while(!s.empty() && a[i]>=a[s.top()])
				s.pop();
			if(s.empty())
				left[i] = 0;
			else
				left[i] = s.top();
			s.push(i);
		}
		while(!s.empty()) 
			s.pop();
		for(int i=n;i>0;i--) {
			while(!s.empty() && a[i]>a[s.top()])
				s.pop();
			if(s.empty())
				right[i] = n+1;
			else
				right[i] = s.top();
			s.push(i);
		}
		
		int ans = 0;
		for(int i=1;i<=n;i++) {
			int x = asc[i].second;
			int r = right[x]-1;
			int l = left[x]+1;
			if(x-l < r-x) {
				for(int j=l-1;j<x;j++) {
					ans = max(ans, find_greatest(t[x+1], prexor[j]^a[x]));
				}
				t[l] = t[x+1];
				for(int j=l-1;j<x;j++) {
					insert(t[l], prexor[j]);
				}
			}
			else {
				for(int j=x;j<=r;j++) {
					ans = max(ans, find_greatest(t[l], prexor[j]^a[x]));
				}
				for(int j=x;j<=r;j++) {
					insert(t[l], prexor[j]);
				}
			}
		}
		cout<<ans << endl;
	}
}

```
 **Feedback*** Good problem: 

 
[*56*](https://codeforces.com/data/like?action=like "I like this")
* Average problem: 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")
* Did not solve: 

 
[*49*](https://codeforces.com/data/like?action=like "I like this")
