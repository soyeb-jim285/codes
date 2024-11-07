# Tutorial_3_(en)


#### [1998A - Find K Distinct Points with Fixed Center](../problems/A._Find_K_Distinct_Points_with_Fixed_Center.md "Codeforces Round 965 (Div. 2)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution** We can construct a solution by fixing all xi as xc or all yi as yc. For example, if we fix all yi as yc, then we can output pairs (xc−1,yc),(xc+1,yc),(xc−2,yc),(xc+2,yc),...,(xc−⌊k2⌋,yc),(xc+⌊k2⌋,yc). If the k is odd, we need one more pair, so just output (xc,yc).

 **Code (C++)**
```cpp
#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		int x, y, k; cin >> x >> y >> k;
		for(int i = 0; i < k - k % 2; i++){
			cout << x - (i & 1 ? 1 : -1) * (i / 2 + 1) << " " << y << "n";
		} 
		if(k & 1){
			cout << x << " " << y << "n";
		}
	}
}
```
#### [1998B - Minimize Equal Sum Subarrays](../problems/B._Minimize_Equal_Sum_Subarrays.md "Codeforces Round 965 (Div. 2)")

Problem Credits: [satyam343](https://codeforces.com/profile/satyam343 "Specialist satyam343")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution** We can always construct a solution such that the number of pairs (i,j) is 1 where the only pair is (1,n). There exists several constructions, such as rotating p once or increment all pi (and pi=n turns into pi=1).

Consider the former construction, where q=[p2,p3,...,pn,p1]. For an arbitrarily interval [i,j], p[i..j] and q[i..j] will have exactly 1 element that's different, disregarding ordering. Since we have a permutation and all elements are distinct, the sum in the range will never be the same. The only exception is the entire array, of course.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> p(n);
		for(int& i: p) cin >> i;
		rotate(p.begin(), p.begin() + 1, p.end());
		for(int i: p) cout << i << " ";
		cout << "n";
	}
}
```
#### [1998C - Perform Operations to Maximize Score](../problems/C._Perform_Operations_to_Maximize_Score.md "Codeforces Round 965 (Div. 2)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry"), [satyam343](https://codeforces.com/profile/satyam343 "Specialist satyam343")   
 Analysis: [sum](https://codeforces.com/profile/sum "Master sum"), [satyam343](https://codeforces.com/profile/satyam343 "Specialist satyam343"), [Dominater069](https://codeforces.com/profile/Dominater069 "International Grandmaster Dominater069")

 **Hint 1**First, solve for k=0. Find some nice characterization about med(ci) and thus the maximum score.

 **Hint 2**Divide into 2 cases where we either increment the max element or the median.

 **Hint 3**Apply binary search

 **Solution**Let's forget about the operations of adding 1 to ai and figure out how to find an array's score. Assume the array a is sorted in increasing order as the order doesnt change the problem. 

First observe how med(ci) changes with respect to i. med(ci) is always either a⌊n2⌋ or a⌊n+22⌋. You can prove this formally by considering different positions of i with respect to the initial median position. Specifically, for all i≤⌊n2⌋, med(ci)=a⌊n+22⌋, and for other i, med(ci)=a⌊n2⌋.

**Claim 1** : The score of the final array (after sorting in increasing order) is an+med(cn)

 **Proof 1**There are 2 cases we need to consider.

1) med(ci)=a⌊n2⌋, in which case optimum value of i is n as we want to maximise ai. Thus score in this case is an+a⌊n2⌋.

2) med(ci)=a⌊n+22⌋, in which case optimum value of i is ⌊n2⌋ as this is the largest value of i which will change median. This obtains a score of a⌊n2⌋+a⌊n+22⌋

The score in Case 1 is clearly larger than Case 2, hence it is optimal.

Hence, our score can be nicely characterized by "max + median of the others".

**Claim 2** : Either we will use all k operations on the element which eventually becomes max element in our array, or we will use all operations trying to improve med(cn) and keep max element constant.

 **Proof 2**Suppose we did x (0<x<k) operations on the element which eventually became maximum. 

Then, we could have done the remaining (k−x) operations on this element too, as this is already the max element and doing operations on it guaranteedly improves our score each time by 1. Doing operations on any other element can only improve our score by atmost 1

Thus, we are in 2 cases now, either increase max, or increase median of the rest. We will solve the problem considering both cases separately.

**Case 1** : We do operations on the element which becomes max eventually.

 **Solution**Lets fix i to be the index that will become max. Then bi=1 must hold. We want to find med(ci), i.e. the median of the other (n−1) elements. This can be done with the observation mentioned above that med(ci) is always either a⌊n2⌋ or a⌊n+22⌋. 

Another possible way to solve this case is observe that we should only do operations on the largest index i such that bi=1. While intuitive, the proof is left as an exercise to the reader.

**Case 2** : We do operations to increase the median of the others. 

 **Solution**an is fixed as the max element in this case, and we want to find the largest possible median by using the k operations on the other (n−1) elements. 

Let's binary search! Suppose we want to check if we can get med(cn)≥x or not. 

Some elements are already ≥x, and we will not modify them.

Some of the other elements can be incremented to become ≥x too. Obviously, we should choose the largest indices i such that ai<x and bi=1, and greedily increment as many as possible. 

Let z be the maximum number of elements which become ≥x at the end. The check is true iff z≥⌊n+12⌋.

Thus, the problem is solved in O(N⋅log(MAX)). The code is nicely written and commented, you may want to check it out.

 **Code (C++)**
```cpp
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int t; cin >> t;
    
    while (t--){
        int n, k; cin >> n >> k;
        
        vector <pair<int, int>> a(n);
        for (auto &x : a) cin >> x.first;
        for (auto &x : a) cin >> x.second;
        sort(a.begin(), a.end());
        
        long long ans = 0;
        // case 1 : increment max 
        for (int i = 0; i < n; i++) if (a[i].second == 1){
            // find med(c_i) 
            int mc;
            if (i < n / 2) mc = a[n / 2].first;
            else mc = a[(n - 2) / 2].first;
            
            ans = max(ans, 0LL + a[i].first + k + mc);
        }
        
        // case 2 : increment median
        int lo = 0, hi = 2e9;
        while (lo != hi){
            int mid = (1LL + lo + hi) / 2;
            
            int z = 0;
            vector <int> smaller_list;
            for (int i = 0; i < n - 1; i++){
                if (a[i].first >= mid){
                    z++;
                } else if (a[i].second == 1){
                    smaller_list.push_back(mid - a[i].first); // list of numbers smaller than x but b[i] = 1 
                }
            }
            
            reverse(smaller_list.begin(), smaller_list.end()); // list will be sorted in ascending, but we want sorted in descending, as greedily changing largest elements 
            int kk = k;
            for (auto x : smaller_list) if (kk >= x){
                kk -= x;
                z++;
            }
            
            if (z >= (n + 1) / 2) lo = mid;
            else hi = mid - 1;
        }
        
        ans = max(ans, 0LL + a[n - 1].first + lo);
        
        cout << ans << "n";
    }
    return 0;
}
```
#### [1998D - Determine Winning Islands in Race](../problems/D._Determine_Winning_Islands_in_Race.md "Codeforces Round 965 (Div. 2)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution** First, let's consider if there was no alternative bridges. Then obviously, if Bessie starts at island i and keeps moving forwards, it is impossible for Elsie to move past island i since the bridge would have already collapsed. From this, we can deduce that Bessie cannot let Elsie use these alternative bridges to overtake the island Bessie is on, or else Elsie will always reach the end first.

Therefore, Bessie will keep moving right in hopes of breaking enough bridges so that it is impossible to for Elsie to overtake Bessie. This can be simplified to: consider we are at island i and t units of time has passed, for all alternative bridges that Elsie can take with an endpoint v>i+t, we have to reach v before her.

Let di denote the minimum amount of time Elsie takes to reach island i. For the first case, consider all bridges with endpoints v>S, then dv≥v−S−1 must hold true since we want to reach v before Elsie does when we keep going right. We can rearrange the equation as S≥v−dv−1. To make sure this holds true for all bridges, we just have to make sure this is true for the maximum value of v−dv.

All di can be calculated using a linear sweep to the right, and we can track all v−dv with a sweep to the left. Note that we cannot take a bridge if it starts past S, so we need to track the maximum with a multiset and erasing as we sweep. 

Time Complexity is O(nlogn). There exists other solutions using prefix sums in O(n) and segment tree in O(nlogn)

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n), rg(n);
	FOR(i,0,m){
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].pb(v);
		rg[v].pb(u);
	}
	FOR(i,0,n-1) g[i].pb(i+1);
	vector<int> dist(n, -1);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		trav(i, g[f]){
			if(dist[i] == -1){
				dist[i] = dist[f] + 1;
				q.push(i);
			}
		}
	}
	multiset<int> max_good_rights;
	vector<vector<int>> to_erase(n);
	string ans = string(n - 1, '0');
	ROF(i,n-1,0){
		trav(j, rg[i]){
			int max_right = i - dist[j];
			max_good_rights.insert(max_right);
			to_erase[j].pb(max_right);
		}
		trav(j, to_erase[i]){
			max_good_rights.erase(max_good_rights.find(j));
		}
		if(i < n - 1){
			int max_good_right = max_good_rights.empty() ? -1 : *prev(max_good_rights.end());
			if(i >= max_good_right - 1){
				ans[i] = '1';
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
```
#### [1998E1 - Eliminating Balls With Merging (Easy Version)](../problems/E1._Eliminating_Balls_With_Merging_(Easy_Version).md "Codeforces Round 965 (Div. 2)")

Problem Credits: [cry](https://codeforces.com/profile/cry "International Master cry"), [sum](https://codeforces.com/profile/sum "Master sum"), [satyam343](https://codeforces.com/profile/satyam343 "Specialist satyam343")   
 Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Solution 1**Consider the ball with the maximum number. Let this ball be m. That ball can clearly be the last ball remaining. And if we are able to merge some ball i with ball m (whilst removing m), then ball i can also be the last ball remaining.

We can do a divide and conquer solution. For some range [l,r], let m be the ball with the maximum value. Clearly, m can be the last ball remaining if we *only* consider the range [l,r]. 

Let's first recurse on [l,m) and (m,r]. Let sl=al+al+1+⋯+am−1 (i.e. the sum of the left half). If sl<am then no ball in the left half can be the last one remaining. Otherwise, the results (i.e. whether each ball can be the last one standing) for range [l,r] for balls in [l,m) is the results we computer when recursing onto [l,m). The same reasoning holds for the right half.

We can use a sparse table to find the maximum ball in any range. This leads to a O(nlogn) solution.

 **Code 1 (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define pll pair<ll, ll>

const int MAX = 2e5 + 5;

int n, x, ans; ll A[MAX], bad[MAX], P[MAX]; pll rmq[MAX][18];

void dnq(int l, int r){
    if (l >= r)
        return;
    
    int lg = 31 - __builtin_clz(r - l + 1);
    int mid = max(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]).second;
    
    dnq(l, mid - 1);
    dnq(mid + 1, r);

    ll sum1 = P[mid - 1] - P[l - 1];
    ll sum2 = P[r] - P[mid];

    // Left half bad
    if (A[mid] > sum1){
        bad[l] += 1;
        bad[mid] += -1;
    }
    // Right half bad
    if (A[mid] > sum2){
        bad[mid + 1] += 1;
        bad[r + 1] += -1;
    }
}

void solve(){
    cin >> n >> x;

    for (int i = 1; i <= n; i++){
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
        bad[i] = 0;
        rmq[i][0] = {A[i], i};
    }
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    
    dnq(1, n);

    ans = 0;

    for (int i = 1; i <= n; i++){
        bad[i] += bad[i - 1];
        ans += !bad[i];
    }
    cout << ans << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
 **Solution 2**For some ball i, let li and ri be the first balls on the left and right that have a value greater than ai. 

Proccess the balls from largest ai to smallest ai. For each ball i, let ansi denote whether it can be the last ball remaining. We know that if we merge ball i with some ball j (while discarding j) and ansj=1, then ansi=1. Furthermore, we know that balls li and ri can freely merge with balls j where j is in interval [li+1…ri−1] while discarding j (i.e. ansli and ansri would have taken this into account). 

This motivates the following idea. Let s be the sum of values in [li+1…ri−1]. If s≥ali then we do ansi:=ansi|ansli. Similarly, if s≥ari, then we do ansi:=ansi|ansri. This solution runs in O(nlogn) due to sorting. 

 **Code 2 (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std; 

#define ll long long

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> A(n + 5);
    vector<ll> P(n + 5);
    vector<int> ans(n + 5, 0);
    vector<int> ord(n);
    set<int> S{0, n + 1};

    for (int i = 1; i <= n; i++){
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return A[a] > A[b];
    });
    for (int i : ord){
        int l = *(--S.lower_bound(i));
        int r = *S.lower_bound(i);
        ll sum = P[r - 1] - P[l];

        if (i == ord[0])
            ans[i] = true;
        if (sum >= A[l])
            ans[i] |= ans[l];
        if (sum >= A[r])
            ans[i] |= ans[r];
        
        S.insert(i);
    }
    cout << accumulate(ans.begin(), ans.end(), 0) << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
#### [1998E2 - Eliminating Balls With Merging (Hard Version)](../problems/E2._Eliminating_Balls_With_Merging_(Hard_Version).md "Codeforces Round 965 (Div. 2)")

Problem Credits: [cry](https://codeforces.com/profile/cry "International Master cry"), [sum](https://codeforces.com/profile/sum "Master sum"), [satyam343](https://codeforces.com/profile/satyam343 "Specialist satyam343")   
 Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Solution** Consider the naive greedy solution. We continuously merge with the balls on the left and right without removing our ball until we can't anymore or our ball is the final remaining one. 

Suppose at some point in this greedy approach, we can **not** merge with the balls on our left and right anymore without discarding our ball. Let our ball be i. Then we have the following cases.

 1. There is a ball l on the left of i and ball r on the right of i. Then: min(al,ar)>al+1+al+2+⋯+ar−1.
2. There is a ball l on the left of i but no ball on the right of i. Then: al>al+1+al+2+⋯+alast.
3. There exists no ball on the left of i but a ball r on the right of i. Then: ar>a1+a2+⋯+ar−1.

**For some ball i, if there exists some l and/or some r such that one of the above is true, then there exists no way for our ball to be the last one remaining. Otherwise, the ball can be the last one remaining.** 

Let p be the prefix sum array of a (i.e. pi=a1+a2+⋯+ai).

For some ball i, we want to do the following.

 1. Find the smallest r1 such that there exists some l such that (l,r1) is a pair (i.e. min(al,ar1)>al+1+al+2+⋯+ar1−1). Finding this is more difficult than the other cases and will be focused on later.
2. Find the smallest r2 such that ar2>a1+a2+⋯+arr−1. We can rewrite it as as ar2>pr2−1 and it can easily be found.
3. Find the smallest rl such that there exists no l on the left of i such that al>al+1+al+2+⋯+arl. We can rewrite the inequality as finding the first rl such that prl≥al+pl which can be done with binary search.

Suppose at some i, we know its rl, r1, and r2. Then we know ball i can be the last one remaining for prefixes spanning from rl to min(r1−1,r2−1) so we can do a range add with prefix sums.

The only thing we have not resolved yet is how to find the smallest r1 for some i such that min(al,ar1)>al+1+al+2+⋯+ar1−1. 

Let's iterate over r. For each r we want to find the leftmost l such that min(al,ar)>al+1+al+2+⋯+ar−1

A key observation is that we can write the following inequality as al>al+1+al+2+⋯+ar−1 **and** ar>al+1+al+2+⋯+ar−1 (both have to be true).

Using prefix sums, the equations can be rewritten as al+pl>pr−1 **and** pl>pr−1−ar.

So some (l,r) works if the equation above is satisfied. Consider the second part pl>pr−1−ar. We can binary search to find the range of available l that satisfy this. Specifically, let lb be the lower bound of the range. Then, any l in [lb...i) satisfies this.

Now, let's try to satisfy al+pl>pr−1. Unfortunately, al+pl is not monotonic so the method above will not work. Instead, we can create a sparse table over all ai+pi. Then we can binary search to find the first lopt such that the maximum in range [lb,lopt] (which can be found with the sparse table) is greater than pr−1.

Circling back, r1 is the minimum r of an interval covering i which can be found with things such as sweepline. In all, this solution runs in O(nlogn) time.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n, x;
    cin >> n >> x;

    vector<ll> A(n + 5, 0);
    vector<ll> P(n + 5, 0);
    vector<vector<ll>> rmq(n + 5, vector<ll>(18, 0));

    for (int i = 1; i <= n; i++){
        cin >> A[i];
        P[i] = P[i - 1] + A[i];        
        rmq[i][0] = A[i] + P[i];
    }
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);

    vector<vector<int>> add(n + 5), rem(n + 5);

    auto ins = [&](int l, int r, int v){
        l = max(l, 1);

        if (l > r)
            return;

        add[l].push_back(v);
        rem[r + 1].push_back(v);
    };
    for (int r = 1; r <= n; r++){
        // r is a roadblock
        if (A[r] > P[r - 1])
            ins(1, r - 1, r);

        // Find leftmost l possible
        int lowerB = upper_bound(P.begin() + 1, P.begin() + n + 1, P[r - 1] - A[r]) - P.begin();
        int lo = lowerB, hi = r - 1;

        while (lo < hi){
            int mid = (lo + hi) / 2;

            // Query lowerB...mid
            int lg = 31 - __builtin_clz(mid - lowerB + 1);
            ll val = max(rmq[lowerB][lg], rmq[mid - (1 << lg) + 1][lg]);

            val > P[r - 1] ? hi = mid : lo = mid + 1;
        }
        ins(lo + 1, r - 1, r);
    }

    multiset<int> badR{n + 1};
    vector<int> ans(n + 5, 0);
    ll worst = 0; 

    for (int i = 1; i <= n; i++){
        for (int v : add[i])
            badR.insert(v);
        for (int v : rem[i])
            badR.erase(badR.find(v));

        int l = lower_bound(P.begin() + i, P.begin() + n + 1, worst) - P.begin();
        int r = *badR.begin();

        // Active for interval [l...r)
        if (l <= r){
            ans[l]++;
            ans[r]--;
        }
        worst = max(worst, A[i] + P[i]);
    }
    
    for (int i = x; i <= n; i++){
        ans[i] += ans[i - 1];
        cout << ans[i] << " n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
