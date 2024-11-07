# Tutorial_(en)

Thank you for participating!

[1873A - Short Sort](../problems/A._Short_Sort.md "Codeforces Round 898 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1873A - Short Sort](../problems/A._Short_Sort.md "Codeforces Round 898 (Div. 4)")

There are only 6 possible input strings, and they are all given in the input, so you can just output NO if s is bca or cab and YES otherwise.

Another way to solve it is to count the number of letters in the wrong position. A swap changes 2 letters, so if at most two letters are in the wrong position, then it's possible, otherwise it's not possible.

Of course, you can also brute force all possible swaps and check if it works.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
string alph = "abc";
 
void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		cnt += (s[i] != alph[i]);
	}
	cout << (cnt <= 2 ? "YESn" : "NOn");
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1873B - Good Kid](../problems/B._Good_Kid.md "Codeforces Round 898 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1873B - Good Kid](../problems/B._Good_Kid.md "Codeforces Round 898 (Div. 4)")

Just brute force all possibilties for the digit to increase, and check the product each time. The complexity is O(n2) per testcase.

You can make it faster if you notice that it's always optimal to increase the smallest digit (why?), but it wasn't necessary to pass.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a[0]++;
    for(int i = 0; i < n; i++)
    {
        ans*=a[i];
    }
    cout << ans << endl;
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
 
 
```
[1873C - Target Practice](../problems/C._Target_Practice.md "Codeforces Round 898 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1873C - Target Practice](../problems/C._Target_Practice.md "Codeforces Round 898 (Div. 4)")

You can just hardcode the values in the array below, and iterate through the grid; if it is an X, we add the value to our total. See the implementation for more details. [1111111111122222222112333333211234444321123455432112345543211234444321123333332112222222211111111111] The time complexity — O(1) per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
 
void solve() {
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c;
			cin >> c;
			if (c == 'X') {ans += score[i][j];}
		}
	}
	cout << ans << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1873D - 1D Eraser](../problems/D._1D_Eraser.md "Codeforces Round 898 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1873D - 1D Eraser](../problems/D._1D_Eraser.md "Codeforces Round 898 (Div. 4)")

The key idea is greedy. Let's go from the left to the right, and if the current cell is black, we should use the operation starting at this cell (it may go off the strip, but that's okay, we can always shift it leftwards to contain all the cells we need it to).

We can implement this in O(n): iterate from left to right with a variable i, and when you see a black cell, you should skip the next k−1 cells (because the eraser will take care of them) and increase the number of operations by 1. The answer is the total number of operations.

Why does it work? Notice the order of operations doesn't matter. Consider the leftmost black cell we erase. It means none of the cells to its right are black. So it doesn't make sense to use the operation on any of the cells to its right, since they are already white. It is at least as good to use the operation starting at this cell and to the k−1 cells on the left, since we may or may not hit another black cell.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') {
			res++; i += k - 1;
		}
	}
	cout << res << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1873E - Building an Aquarium](../problems/E._Building_an_Aquarium.md "Codeforces Round 898 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1873E - Building an Aquarium](../problems/E._Building_an_Aquarium.md "Codeforces Round 898 (Div. 4)")

We need to find the maximum height with a certain upper bound — this is a tell-tale sign of binary search. If you don't know what that is, you should read [this Codeforces EDU article](https://codeforces.com/edu/course/2/lesson/6/2).

For a given value of h, in the i-th column we will need h−ai units of water if h≥ai, or 0 units otherwise. (This is equal to max(h−ai,0), why?) So we can compute the amount of water for all n columns by simply iterating through and summing the total amount of water needed for each column, and see if it's not larger than x.

Then you can binary search on the optimal value of h. The model solution uses the starting bounds l=0, r=2ai+ε, because the optimal height could be ai+x. So the complexity is O(nlogai) per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int n;
	long long x;
	cin >> n >> x;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long lo = 0, hi = 2'000'000'007;
	while (lo < hi) {
		long long mid = lo + (hi - lo + 1) / 2;
		long long tot = 0;
		for (int i = 0; i < n; i++) {
			tot += max(mid - a[i], 0LL);
		}
		if (tot <= x) {lo = mid;} 
		else {hi = mid - 1;}
	}
	cout << lo << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1873F - Money Trees](../problems/F._Money_Trees.md "Codeforces Round 898 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1873F - Money Trees](../problems/F._Money_Trees.md "Codeforces Round 898 (Div. 4)")

Let's compute lenl for each l≤n, the maximum r such that the subarray [hl…hr] satisfies the height divisibility condition.

Now let's do a binary search on the size of the segment, where we check every i such that leni≥i+size−1. 

Check the sum between i and i+size−1 using a prefix sum. If it is smaller or equal to k, we update the lower bound of the binary search, otherwise, if we find no such i for this size then we update the upper bound.

Final complexity O(nlogn)

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int N = 200'000;
 
int n, k;
int a[N+5], h[N+5], pref[N+5], length[N+5];
 
bool get(int dist)
{
    bool found = false;
    for(int i = 0; i < n-dist+1; i++)
    {
        if(length[i] < dist){continue;}
        int sum = pref[i+dist]-pref[i];
        if(sum <= k)
        {
            found = true;
            break;
        }
    }
    return found;
}
 
void solve()
{
    pref[0] = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i+1] = pref[i]+a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    length[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
    {
        if(h[i]%h[i+1] == 0)
        {
            length[i] = length[i+1]+1;
        }
        else
        {
            length[i] = 1;
        }
    }
    int l = 1, r = N;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(get(mid))
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << r << endl;
}
 
int main() {
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}


```
[1873G - ABBC or BACB](../problems/G._ABBC_or_BACB.md "Codeforces Round 898 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1873G - ABBC or BACB](../problems/G._ABBC_or_BACB.md "Codeforces Round 898 (Div. 4)")

Preface 

Before we get into the editorial, I want to make a note that this type of problem is not traditional for Div. 4 on purpose, and is a lot more ad-hoc than usual. My goal was to make a sort of "introductory" ad-hoc problem, and I hope you enjoyed it. The editorial is a bit long, mainly because I want to go into a lot of detail regarding how to approach such ad-hoc problems, since usually most Div. 4 problems are unlike this, and instead focused on noticing and implementing the correct algorithm. I don't think anyone solving the problem will actually go through all this detail explicitly, but I wanted to provide a very explicit walk-through for anyone not knowing how to start.

But I think ad-hoc skills are important for Codeforces especially, hence this problem. Maybe you'll see more soon. ;) 



|  |
| --- |
|  |

 Analyzing the situation Let's think about how we can repeatedly use the operations first. If we have a string AAAB, then we can do the operations AAAB→AABC→ABCC→BCCC. Similarly, if we have a string BAAA, then we can do the operations BAAA→CBAA→CCBA→CCCB.

In a sense, it's useful to think of the B as "eating" the As in a sense: whenever a B is next to an A, it eats covers it and eats it, and then it moves on. Note that B cannot eat Cs.

Let's replace the characters as follows: replace A with . and C with _. Then, it's much clear what is going on. Here is a series of moves on the string BAAABA, which becomes B...B. after the replacing: B...B.→_B..B.→__B.B.→___BB.→___B_B

Now you can see how each B is eating all the dots in one direction (it can't travel over blank spaces represented by _=C). 



|  |
| --- |
|  |

 Solving the problem Okay, we have this intuition, how to solve the problem now? We need to eat the maximum number of dots (As in the original string), since Bs cannot eat anything else. Note that for each B, it can eat all the As to its left or to its right, but not both; one it leaves its original spot, it is stuck on that side: ..B.→.B_.→B__. but the B cannot reach the rightmost dot ever. This small example actually gives us a clue: for each B, let's count the number of As on either side, and pick the largest one. This might work, but note that multiple Bs may be able to reach the same dot.

This is where our original string comes into play. Suppose our original string starts with B, so it must be of the form BA…A⏟some number, possibly 0BA…A⏟some number, possibly 0BA…A⏟some number, possibly 0… Then each B can simply eat all the As after it, and so our answer is just the total number of As. Similarly, if our string ends with B, then it must be of the form …A…A⏟some number, possibly 0BA…A⏟some number, possibly 0BA…A⏟some number, possibly 0B Then each B can simply eat all the As before it, and so our answer is just the total number of As.

So we only have to look at the case where our string starts and ends with A, meaning our string looks something like: A…A⏟some number, possibly 0BA…A⏟some number, possibly 0…BA…A⏟some number, possibly 0 If any of the Bs are next to each other, like A…A⏟some number, possibly 0BBA…A⏟some number, possibly 0 then note that we can split the string into two strings, both of which either start or end with B, and so we can eat all the As. So in this case, too, it is possible to get all the As.

What's the only other case? Start and end with A, and there are no two Bs next to each other. In this case, you can see there is one more "group" of As than there are Bs, but each B can only get one group of As. So we won't be able to get all of them.

What's the best we can do? Note that each B can only get one group, if it goes left or right, so we can get all As except one group. Now the answer is simply greedy: it is the total number of As, minus the smallest group (since we want to get the most number of coins, we will take groups as large as possible).

You can also envision this as a sort of greedy: each B takes the largest group available, and we stop once no more Bs are free.

The time complexity for finding groups is O(n), so the whole solution runs in that time as well.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	string s;
	cin >> s;
	int n = s.length(), cnt = 0;
	bool all = (s[0] == 'B' || s[n - 1] == 'B');
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == 'B') {all = true;}
	}
	vector<int> lens;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {curr++;}
		else {
			if (curr != 0) {lens.push_back(curr);}
			curr = 0;
		}
	}
	if (curr != 0) {lens.push_back(curr);}
	sort(lens.begin(), lens.end());
	
	if (lens.empty()) {cout << 0 << 'n'; return;}
	
	int tot = 0;
	if (all) {tot += lens[0];}
	for (int i = 1; i < lens.size(); i++) {
		tot += lens[i];
	}
	cout << tot << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1873H - Mad City](../problems/H._Mad_City.md "Codeforces Round 898 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1873H - Mad City](../problems/H._Mad_City.md "Codeforces Round 898 (Div. 4)")

Because we have a tree with an additional edge, our graph has exactly one cycle.

If Marcel and Valeriu share the same starting building then the answer is "NO".

If we do a depth-first search from Valeriu's node, when we encounter an already visited node that is not the current node's parent, the node is part of the cycle. Moreover, it's the node where Valeriu enters the cycle.

Valeriu can escape Marcel forever if and only if he reaches this node before Marcel can. This is because if Valeriu is in a cycle then he always has 2 choices of buildings where he would run that still keep him in the cycle. Marcel can only be in one building at any given time and Valeriu knows Marcel's next move, which means Valeriu can always escape him.

So it just remains to check with a breadth-first search or a depth-first search if Marcel arrives at Valeriu's entry node after Valeriu.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200005;
 
vector<int> adj[N];
vector<bool> vis(N);
 
int entry_node = -1;
vector<int> path;
 
bool dfs1(int u, int p)
{
    vis[u] = true;
    for(auto v : adj[u])
    {
        if(v != p && vis[v])
        {
            entry_node = v;
            return true;
        }
        else if(v != p && !vis[v])
        {
            if(dfs1(v, u))
            {
                return true;
            }
        }
    }
    return false;
}
 
int dfs2(int u)
{
    vis[u] = true;
    int distbruh = N;
    for(auto v : adj[u])
    {
        if(v == entry_node)
        {
            return 1;
        }
        if(!vis[v])
        {
            int dist = dfs2(v)+1;
            distbruh = min(dist, distbruh);
        }
    }
    return distbruh;
}
 
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(b, -1);
    vis.assign(n+1, false);
    int distMarcel = N, distValeriu = 0;
    if(entry_node == a)
    {
        distMarcel = 0;
    }
    else
    {
        distMarcel = dfs2(a);
    }
    vis.assign(n+1, false);
    if(entry_node == b)
    {
        distValeriu = 0;
    }
    else
    {
        distValeriu = dfs2(b);
    }
    if(distValeriu < distMarcel)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
 


```
