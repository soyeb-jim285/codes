# Tutorial_(en)

[1498A - GCD Sum](../problems/A._GCD_Sum.md "CodeCraft-21 and Codeforces Round 711 (Div. 2)")
==================================================================================================================

#### [**Video Editorial**](https://codeforces.com/https://www.youtube.com/watch?v=lV5cb8wh3sE)

**Author and Problemsetting:** [ninja_28](https://codeforces.com/profile/ninja_28 "Candidate Master ninja_28")  
**Editorialist:** [sigma_g](https://codeforces.com/profile/sigma_g "Master sigma_g") 

 **Hint**Can you think of the simplest properties that relate a number and its sum of digits?

 **Hint 2**Note that if X is a multiple of 3, then **both** X as well as the sum of digits of X are a multiple of 3! Can you put this property to use here?

 **Hint 3**If X is a multiple of 3, then gcd-sum(X)≥3. Therefore, we are guaranteed that at least every third number will satisfy the constraints required by our problem (gcd-sum(X)>1).

 **Solution**Therefore, for the input n, we can simply check which one of n, n+1, and n+2 has its gcd-sum >1, and print the lowest of them.

 **Corner cases**Note that you must take `long long`, as input integers exceed the range of int.

Moreover, simply outputting ceil((n/3)×3) is incorrect as some non-multiples of three may also may have gcd-sum >1, for example, 26.

 **C++ solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

long long int gcd_sum(long long int num) {
// returns gcd-sum
long long int tmp = num, digitsum = 0;

    while (tmp > 0) {
        digitsum += tmp % 10;
        tmp /= 10;
    }

    long long int gcd = __gcd(num, digitsum);
    return gcd;
}

int main(void) {
int t;
cin >> t;

    while (t--) {
        long long int n;
        cin >> n;
        if (gcd_sum(n) != 1) {
            cout << n << endl;
        } else if (gcd_sum(n + 1) != 1) {
            cout << n + 1 << endl;
        } else if (gcd_sum(n + 2) != 1) {
            cout << n + 2 << endl;
        }
    }
    return 0;
}

```
 **Python solution**
```cpp
from math import gcd

def valid(x):
    return gcd(x, sum([ord(c) - ord('0') for c in str(x)])) != 1

t = int(input())

while t > 0:
    t -= 1

    n = int(input())
    while not valid(n):
        n += 1

    print(n)
```
[1498B - Box Fitting](../problems/B._Box_Fitting.md "CodeCraft-21 and Codeforces Round 711 (Div. 2)")
======================================================================================================================

#### [**Video Editorial**](https://codeforces.com/https://www.youtube.com/watch?v=gC4dcf1PN40)

**Author and Editorialist:** [sigma_g](https://codeforces.com/profile/sigma_g "Master sigma_g")  
**Problemsetting:** [ninja_28](https://codeforces.com/profile/ninja_28 "Candidate Master ninja_28") 

 **Hint**There can exist multiple optimal packings for a given set of rectangles. However, all of them can always be rearranged to follow a specific pattern, based on the rectangles' sizes.

 **Hint 2**Can you show that it is always possible to replace a set of consecutive small blocks with a single large block? (of same or larger size)

 **Solution summary**We follow a greedy strategy:

 1. Initialize height of box as 1.
2. Initialize current layer size as W.
3. Pick the largest available rectangle that can fit into the current layer, and place it there. Repeat until this layer cannot fit any more rectangles.
4. If more rectangles remain, increment height by 1 and now repeat the last three steps. Else, output the current value of height.
 **Solution implementation**First count sort the given rectangles based on their widths. There can only be 20 distinct rectangle widths in the range [1,109], so the following works:

 
```cpp
counts = [0 for w in range(0, 20)]
for w in widths:
    counts[log2(w)] += 1
```
The solution can be implemented by iterating N times.

At each iteration, step through the `counts` array and take the largest available rectangle that can fit into the current space. If no rectangle was able to fit, increment height by 1 and reset box width to W.

This has complexity O(nlog(wmax)).

 **Another implementation**It is also possible to implement the solution with a `multiset` and `upper_bound`, for a complexity of O(nlog(n)).

Store all rectangle sizes in a multiset. At each iteration, find using `upper_bound` the largest rectangle that can fit into the current space we have, and fit it in. If no rectangle can fit in this space, reset the space to maximum, increment height, and repeat.

 **Proof of correctness - brief**It is always possible to replace several smaller blocks with a single larger block if it is available. Because all blocks are powers of two, it must so happen that smaller powers of two will sum to a larger power. Therefore, we can always place a larger block first if it can be placed there.

 **Proof of correctness - elaborate**This elaborate proof isn't actually required for solving the problem. The intuition in the brief proof is sufficient for solving the problem. This proof is for correctness purpose only.

Let's first note a property: if a1+…+an>a0, then there exists some i such that a1+…+ai=a0, when all ai are powers of 2 AND a1 to an is a non-increasing sequence (AND a1<=a0, of course). Why is this so? You can take an example and observe this intuitively, this is a common property of powers of two. For example, 4+2+2+1+1>8, but 4+2+2 (prefix) =8. Formally: if a1=a0, this property is trivially true. If a1<a0, we can splilt a0=2ka1 for some k into 2k parts and — by strong induction — claim this property holds.

Let us now compare some optimal solution and our greedy solution. Before comparing, we first sort all blocks in each layer of the optimal solution in decreasing order. This does not affect the final answer but helps in our comparison. This comparison goes from bottom to top, left to right. Let us look at the first point of difference: when the block placed by us (BG) is different from the block placed by the optimal solution (BO). There are three cases.

If BO>BG: this is impossible, as in our greedy solution, we are always placing the largest possible block. We wouldn't place BG in there if BO was also possible. If BO==BG: we have nothing to worry about (this isn't a point of difference)

If BO<BG: let us assume that the optimal solution places several consecutive small blocks, and not just one BO. Since the blocks are in decreasing order, none of them would be bigger than BG. Note that either all of these blocks will sum to less than BG or a prefix of them will be exactly equal to BG. In either case, we can swap them with one single large block BG (swapping with a BG which was placed in some higher layer in the optimal solution)

Hence, in the last case, we have shown that any optimal solution (an arrangement of blocks) can be rearranged such that each layer fits the largest possible block first. This is also what is done in our greedy strategy. Therefore, with this proof by rearrangement, we conclude that our greedy strategy gives the same minimum height as that of the optimal answer.

 **Alternate implementation with easier proof**There is a binary search method to solve this problem. We binary search for the minimum height required. Given a height h — how to check if it can fit all rectangles?

We first preprocess the given array to construct a new array ci = number of rectangles of width 1«i. The size of this array is < 20.

We iterate from largest width to smallest width. Let its width is wi. Then, we know that it fits only W/wi times in one layer. Therefore, with height h, the box can only fit in fi=h×(W/wi). So, we can say that if fi<ci, then this height is insufficient.

Therefore, we now know that for any i, if fi<ci, then the height is insufficient. Do we need more conditions to provably state that the given height is sufficient?

Yes! We also need to check if we can fit in the i-th block *in combination with* tthe i+1-th block. That is, when checking if the i-th block has enough space, we need to account for the space that **has already been used** by the i+1-th block. So, we need to update ci=ci+2×ci+1+4×ci+2…. 

Therefore, we only need to compute the suffix sum ci like so and then check the above conditions. Complexity is O(n+log(wmax)log(n)).

 **Does this solution work when block widths are not a power of two?**As we understood in the proof, this solution only works when it's guaranteed that smaller blocks will always exactly sum to any larger block. Therefore, if the blocks are not powers of two, this guarantee does not hold.

The following counterexample suffices:

 
```cpp
6 13
6 6 4 4 3 3
```
As you can see here the smaller blocks are not guaranteed to sum to the larger block (no prefix of 4,3,3 sums to 6). Our greedy solution gives minimum height 3, but best possible minimum height is 2 (first layer: 6,4,3, second layer: 6,4,3)

 **C++ solution**
```cpp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, box_width, w;
        cin >> n >> box_width;

        vector<int> counts(20);
        for (int i = 0; i < n; i++) {
            cin >> w;
            counts[log2(w)]++;
        }

        int height = 1, space_left = box_width;

        for (int iter = 0; iter < n; iter++) {
            int largest = -1;

            for (int size = 19; size >= 0; size--) {
                if (counts[size] and (1 << size) <= space_left) {
                    largest = size;
                    break;
                }
            }

            if (largest == -1) {
                space_left = box_width;
                height++;
                for (int size = 19; size >= 0; size--) {
                    if (counts[size] and (1 << size) <= space_left) {
                        largest = size;
                        break;
                    }
                }
            }

            counts[largest] -= 1;
            space_left -= 1 << largest;
        }

        cout << height << endl;
    }

}
```
 **Python solution**
```cpp
from math import log2


def solve_tc():
    n, w = list(map(int, input().split()))
    widths = list(map(int, input().split()))

    counts = [0 for _ in range(20)]

    for width in widths:
        counts[int(log2(width))] += 1

    space = w
    height = 1

    for it in range(n):
        largest = -1

        for size, count_width in list(enumerate(counts))[::-1]:
            if counts[size] > 0 and (2 ** size) <= space:
                largest = size
                break

        if largest == -1:
            space = w
            height += 1

            for size, count_width in list(enumerate(counts))[::-1]:
                if counts[size] > 0 and (2 ** size) <= space:
                    largest = size
                    break

        assert(largest != -1)
        counts[largest] -= 1
        space -= 2 ** largest

    print(height)


t = int(input())

while t > 0:
    t -= 1

    solve_tc()

```
 **C++ solution - multiset**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, w;
        int box_width;
        cin >> n >> box_width;

        multiset<int> st;
        for (int i = 0; i < n; i++) {
            cin >> w;
            st.insert(w);
        }

        int height = 1, space_left = box_width;

        while (!st.empty()) {
            auto it = st.upper_bound(space_left);
            if (it != st.begin()) {
                it--;
                int val = *it;
                space_left -= val;
                st.erase(it);
            } else {
                space_left = box_width;
                height++;
            }
        }

        cout << height << endl;
    }
    return 0;

}
```
 **C++ solution for easier proof**
```cpp
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

#define PW 20
array<int, PW> arr;
int n, w;

bool valid(int height) {
    for (int pw = 0; pw < PW; pw++) {
        long long units_i_have = 1ll * height * (w / (1 << pw));
        if (units_i_have < arr[pw]) return false;
    }

    return true;
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> n >> w;

        for (int i = 0; i < PW; i++) arr[i] = 0;

        for (int _ = 0; _ < n; _++) {
            int w; cin >> w;
            arr[log2(w)] += 1;
        }

        // suffix cumulative count
        for (int i = PW - 2; i >= 0; i--) arr[i] += 2 * arr[i + 1];

        int beg = 1, end = n, ans = -1;
        while (beg <= end) {
            int mid = (beg + end) / 2;

            if (valid(mid)) {
                end = mid - 1;
                ans = mid;
            } else {
                beg = mid + 1;
            }
        }

        assert(ans != -1);
        cout << ans << endl;
    }
}
```
[1498C - Planar Reflections](../problems/C._Planar_Reflections.md "CodeCraft-21 and Codeforces Round 711 (Div. 2)")
=============================================================================================================================

#### [**Video Editorial**](https://codeforces.com/https://www.youtube.com/watch?v=VFNzluTWIBc)

**Author, Problemsetter and Editorialist:** [sigma_g](https://codeforces.com/profile/sigma_g "Master sigma_g") 

 **Hint 1**We can use dynamic programming to store the state of the simulation at a given time. Therefore, we can simulate the entire situation by reusing the dp states.

 **Solution idea**I will describe the most intuitive solution. Naturally, looking at the constraints as well as at the output that is required, we can store a 3-state dp: `dp[n][k][2]`. Here, `dp[n][k][d]` indicates the total number of particles (at the end of the simulation) when one particle of decay age k hits the n-th plane in the direction d. (d is either 0 or 1, and indicates the direction (left/right) in which the particle is going)

There can be two directions, N planes and maximum decay age is K. So, this dp requires 2×1000×1000×4 bytes ≈24MB which is well within our memory constraints.

 **Solution details**How to update the DP states? If k=1, the value of `dp[n][1][d]` for any n or d is obviously 1 (as no copies are produced).

So, let us consider a particle P with k>1. This particle P produces a copy P′ going in the opposite direction. We can count the number of particles produced by P′ as `dp[n - 1][k - 1][1 - d]`, as it hits the previous plane with a smaller decay age and in the opposite direction. Moreover, the particle P itself hits the next plane and continues to produce more stuff. We can calculate its number of particles produced as `dp[n + 1][k][d]`, as it hits the next plane with the same decay age and the same direction!

Finally, we can combine these two values to get the value of `dp[n][k][d]`.

 **Implementation details**We can implement this is easily as a recursive dp with memoization. At each state, we only need to iterate in the correct order (in one case, from right to left, and in the other, from left to right), and update states as required. Look at the implementation for more details. The total complexity of this algorithm is O(nk)

 **Note**Obviously, there exist much better solutions which do not use a third state and are much sleaker. However, I wanted to describe the simplest idea required to solve the problem.

 **C++ solution**
```cpp
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1001;
const int K = 1001;

int n, k;
const int mod = 1e9 + 7;

int dp[N][K][2];

int solve(int curr, int k, int dir) {
    if (k == 1) {
        return 1;
    }

    if (dp[curr][k][dir] != -1) {
        return dp[curr][k][dir];
    }

    int ans = 2;  // me and my copy

    if (dir == 1) {
        if (curr < n)
            ans += solve(curr + 1, k, dir) - 1;

        ans %= mod;

        if (curr > 1)
            ans += solve(curr - 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    } else {
        if (curr > 1)
            ans += solve(curr - 1, k, dir) - 1;

        ans %= mod;

        if (curr < n)
            ans += solve(curr + 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << endl;
    }
}
```
 **Python Iterative solution**
```cpp
mod = int(1e9 + 7)

def iter_solver(N, K):
    dp = [[[-1 for _ in range(2)] for __ in range(K + 1)] for ___ in range(N + 1)]
    for i in range(1, N + 1):
        dp[i][1][0] = dp[i][1][1] = 1

    for k in range(2, K + 1):
        
# forward dir
        for n in range(N, 0, -1):
            ans = 2

            if n < N:
                ans += dp[n + 1][k][0] - 1
                ans %= mod

            if n > 1:
                ans += dp[n - 1][k - 1][1] - 1
                ans %= mod

            dp[n][k][0] = ans

        
# backward dir
        for n in range(1, N + 1):
            ans = 2

            if n < N:
                ans += dp[n + 1][k - 1][0] - 1
                ans %= mod

            if n > 1:
                ans += dp[n - 1][k][1] - 1
                ans %= mod

            dp[n][k][1] = ans

    return dp[1][K][0]

t = int(input())

while t > 0:
    t -= 1

    n, k = list(map(int, input().split()))

    print(iter_solver(n, k))
```
[1498D - Bananas in a Microwave](../problems/D._Bananas_in_a_Microwave.md "CodeCraft-21 and Codeforces Round 711 (Div. 2)")
=================================================================================================================================

#### [**Video Editorial**](https://codeforces.com/https://www.youtube.com/watch?v=nsrKedxfyvU)

**Author:** [shash42](https://codeforces.com/profile/shash42 "Candidate Master shash42")  
**Problemsetting and Editorialist:** [sigma_g](https://codeforces.com/profile/sigma_g "Master sigma_g") 

 **Brute force solution**We have a brute force O(N⋅M2) solution.

At every timestep t, for each banana bi that has already been reached previously, apply this timestep's operation yt times on bi. For all the yt bananas reachable from bi, update their minimum reachability time if they hadn't been reached previously.

Why is this correct? Simply because we are simulating each possible step of the algorithm exactly as it is described. Therefore, we cannot get an answer that's better or worse than that of the optimal solution.

 **Optimizing the brute force: hint**Observe if we can reduce our search space when we visit nodes that have already been visited previously.

 **Optimizing the brute force: hint 2**Let us take an example. We have some timestep t,x,y=1,5,10. If we start visiting from k=10, we will visit k=15,20,…,55,60. Let us say that k=40 was an already visited state. Do we now need to continue visiting k=45,…,60 or can we stop our search here? 

 **Optimizing the brute force: details**We can actually stop our search as soon as we reach a previouly visited node! Why is this so? This is because — within the same iteration — that already visited node will once again start its own search, and will hit all the points that we were going to hit, and some more!

For example, let us say we would reach points a,a⋅x,a⋅x2,…,a⋅xy−1. Now, assume that a⋅x5 had been previously reached, then it is better to stop at a⋅x5, as this node itself will reach a⋅x5,a⋅x6,…,a⋅xy−2,a⋅xy−1,a⋅xy,…,a⋅x5+y−1. Note the latter range includes as a prefix the entire remaining suffix of the former range! Therefore, in this approach, nodes that would *have* been visited, will eventually be visited, and get assigned the minimum timestamp.

 **Optimized solution implementation**We can implement the optimized solution by simply adding an extra `if already_visited[k]: break` to our inner loop. Yup, really, that's all it takes to solve this question!

Complexity analysis: We can show that each node is visited at most twice: an unvisited node is reached atmost once, whereas a visited node is reached atmost twice (once during the main loop and once when searching from the immediately previous visited node) There are N iterations, and in each iteration, each of the M nodes is visited at most twice. Therefore, the total complexity is O(2NM).

 **Common mistakes**1. Integer overflows: x′ does not fit in integer range
2. Out of bounds access: simulating the yt steps of the algorithm even when k exceeds M prematurely
 **C++ solution**
```cpp
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int DIV = 1e5;
inline LL ceil(LL x, LL y) {
    return (x + y - 1) / y;
}

int main() {
    int T, M; cin >> T >> M;

    vector<bool> is_seen(M + 1, false);
    is_seen[0] = true;
    vector<int> answer(M + 1, -1);
    answer[0] = 0;

    for (int timestep = 1; timestep <= T; timestep++) {
        auto new_is_seen = is_seen;

        int t, y; LL x;
        cin >> t >> x >> y;

        auto operation = [&] (long long &curr) {
            if (t == 1) {
                curr = curr + ceil(x, DIV);
            } else {
                curr = ceil(curr * x, DIV);
            }
        };

        for (int k = 0; k <= M; k++) {
            if (is_seen[k]) {
                long long curr = k;
                operation(curr);

                for (int a = 1; a <= y;) {
                    if (curr > M) break;
                    if (is_seen[curr]) break;
                    
                    new_is_seen[curr] = true;
                    answer[curr] = timestep;

                    a++;
                    operation(curr);
                }
            }
        }

        is_seen = new_is_seen;
    }

    for (int i = 1; i <= M; i++)
        cout << answer[i] << " ";

    cout << endl;
}
```
 **Python solution**
```cpp
import sys
input = lambda: sys.stdin.readline().rstrip()

DIV = int(1e5)

def ceil(x, y):
    return (x + y - 1) // y

T, M = list(map(int, input().split()))

is_seen = [0 for _ in range(M + 1)]
is_seen[0] = 1
answer = [-1 for _ in range(M + 1)]
answer[0] = 0

o = 0

for timestep in range(1, T + 1):
    t, x, y = list(map(int, input().split()))

    def operation(val):
        if t == 1:
            return curr + ceil(x, DIV)
        else:
            return ceil(curr * x, DIV)

    k = 0

    setting = []

    while k <= M:
        if is_seen[k]:
            curr = k

            i = 0
            while i < y:
                i += 1

                o += 1

                curr = operation(curr)

                if curr > M:
                    break
                if is_seen[curr]:
                    break

                setting.append(curr)
                answer[curr] = timestep

        k += 1

    for idx in setting:
        is_seen[idx] = 1

sys.stdout.write(" ".join(map(str, answer[1:])))

```
[1498E - Two Houses](../problems/E._Two_Houses.md "CodeCraft-21 and Codeforces Round 711 (Div. 2)")
=====================================================================================================================

**Author, Problemsetting and Editorialist:** [dixitgarg](https://codeforces.com/profile/dixitgarg "Master dixitgarg") 

 **Description**In this problem we have to output two nodes a and b such that there is a path from a to b and b to a and the absolute value of the difference of the indegree (|ka−kb|) should be maximum. First of all, let us think of bireachability only i.e how to find two nodes a and b such that they are both reachable from each other? How can we verify this from the judge? Because if we ask "? a b" i.e whether there is a path from a to b or not, then if the judge answers "Yes", we can't ask further queries. So we have to ask queries for those pairs (a,b) for which we are sure that there is a path from b to a. So how to ensure whether there is a path from b to a or not?

 **Hint1**The answer lies in the fact that the given graph is not an ordinary graph, it is a special one. For every pair of vertices in this graph, there is a directed edge. So this type of graph has some interesting properties which we are going to see now.

Image how the compressed SCC of the graph will look like. For every pair of nodes of compressed SCC, there will be an edge, so it will have exactly one source, one sink and there would be only one possible topological sorting of this compressed SCC.

 **Proof of unique topological sorting**Since there is an edge between every pair of nodes, for every pair of nodes in the compresses SCC also, there would be an edge. And we know that if there is an edge between node a to node b, then node a comes before node b in the topological sort. So for every pair of nodes of compressed SCC, we know which node would come first in the topological sorting, so it would result in a unique topological sorting.

 **Hint2**Now we'll see one interesting and important property of this graph.

Property: Consider two consecutive strongly connected components in the topological sorting, then all nodes present in the left component will have indegree strictly less than all nodes present in the right component. Here left denotes lower enumeration in the topological sorting.

 **Proof**Consider two nodes u and v from the left component and right component respectively. Since the contribution to the indegree from the nodes which don't lie in these two components would be the same for both u and v (because u and v lie in adjacent components), we are ignoring it as we have to just compare their values. If we consider all the edges between the nodes of the left component and the right component, then all of them would be directed from the node in the left component to the node in the right component. So the node v would have minimum indegree of SizeofLeftComponent. The node u would have the maximum indegree of SizeofLeftComponent−1. This is because there is no edge directed from the right component to the node u and the maximum indegree will be when all other nodes in the left component have an edge directed towards node u. In that case, it would be SizeofLeftComponent−1. So the indegree of u is strictly less than the indegree of v. Since u and v are arbitrary nodes, it is true for all pairs of nodes.

 **Hint3**Using the above property we can argue that if indegree of node a is greater than the indegree of node b, then node a is reachable from node b. Because either node a lies in the same SCC or to the SCC of higher enumeration in topological sorting. In both cases a is reachable from b.

So we can store all pairs of nodes (a,b),1≤a≤n,1≤b≤n,a<b in an array and sort it according to decreasing order of absolute value of difference of indegrees i.e |ka−kb|. And if we pick a pair, let it be (a,b) and indegree[b]>indegree[a], then we are sure that b is reachable from a so we need to check whether a is reachable from b or not, so we ask "? b a" and if the judge responds by "Yes", then it means both a and b are reachable from each other. Since we were iterating in the decreasing order of |ka−kb|, we get the optimal answer. If the judge never outputs "Yes" in the whole process, then there is no pair of nodes that are reachable from each other. So we will output "? 0 0"

Overall Complexity : O(n2log2n)

 **C++ solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> indegree(n);
    for (int i = 0; i < n; i++) {
        cin >> indegree[i];
    }
    vector<pair<int, pair<int, int>>> vec;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (indegree[i] > indegree[j])
                vec.push_back({indegree[i] - indegree[j], {i, j}});
            else
                vec.push_back({indegree[j] - indegree[i], {j, i}});
        }
    }
    sort(vec.rbegin(), vec.rend());
    for (auto it : vec) {
        if (it.first < 0)
            break;

        int a = it.second.first, b = it.second.second;
        cout << "? " << a + 1 << " " << b + 1 << endl;
        cout.flush();
        string str;
        cin >> str;
        if (str == "Yes") {
            cout << "! " << a + 1 << " " << b + 1 << endl;
            cout.flush();
            return 0;
        }
    }

    cout << "! 0 0" << endl;
    cout.flush();

    return 0;
}
```
 **Python solution**
```cpp
import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())

indegs = list(map(int, input().split()))

pairs = []
for i in range(n):
    for j in range(i + 1, n):
        if indegs[i] > indegs[j]:
            pairs.append((indegs[i] - indegs[j], (i, j)))
        else:
            pairs.append((indegs[j] - indegs[i], (j, i)))


pairs = sorted(pairs, reverse=True)
l = len(pairs)

for _, nodes in pairs:
    ni, nj = nodes

    sys.stdout.write(f"? {ni + 1} {nj + 1}n")
    sys.stdout.flush()

    s = input()
    if s == "Yes":
        sys.stdout.write(f"! {ni + 1} {nj + 1}n")
        exit(0)

sys.stdout.write("! 0 0n")
```
[1498F - Christmas Game](../problems/F._Christmas_Game.md "CodeCraft-21 and Codeforces Round 711 (Div. 2)")
=========================================================================================================================

**Author:** [nikhil_c](https://codeforces.com/profile/nikhil_c "Expert nikhil_c")  
**Problemsetting and editorialist:** [sigma_g](https://codeforces.com/profile/sigma_g "Master sigma_g")

 **How do we solve a standard Nim game on arrays?**By the Sprague-Grundy theorem, we know that the current player has a winning strategy if a1⊕a2⊕…⊕an (xorsum of sizes of the existing piles) is non-zero. For a proof, read details on [CP-algorithms](https://codeforces.com/https://cp-algorithms.com/game_theory/sprague-grundy-nim.html).

 **How to solve tree nim game for one rooting if K = 1: classifying odd/even steps**Let us classify nodes into odd or even depending on their depth relative to the root. Note that even steps do not affect the game state. Let us prove how:

Let us say it's Alice's turn. If Alice moves some coins from an even step to an odd step, then Bob can move *exactly those same coins* from that odd step back to an even step. After this transition, once again it's Alice's move. In fact, we realize that Bob can "revert" every even->odd move by Alice.

Therefore, if Alice wants to win, she has to play at least one odd->even move. Moves that go from even->odd do not affect the game state at all, as the other player can always play another move that reverts them. Therefore, we can say that any coins present on even steps will not change the game state.

 **How to solve tree nim game for one rooting if K = 1: how bad are even steps**Let us now analyze what happens if some coins move from the odd steps to even steps. We know that any coins on even nodes will not contribute to the game state. In fact, we realize that it does not matter whether these coins were present on the even nodes before the game started or whether they came by on the even nodes during the game. Once they are on an even step, they no longer contribute to the game state.

Hence, we can conclude that moving a coin from odd step to an even step is as good as taking a coin from the odd step and throwing it away.

 **Reducing tree nim game to linear array: the stair case nim**As we can see, we have effectively reduced the Nim game on tree to a linear nim game where only the odd positioned nodes determine the winning strategy. This is known as the staircase nim. The result is the following: the current player has a winning strategy if xorsum of all values at the odd steps is non-zero.

 **Extending to general K**In general K, we can extend this idea to: parity of d′=⌊dK⌋ where d is the depth of this node (zero-indexed). All nodes — such that d′ is odd for them — will contribute to the final xorsum. Take a moment to digest this.

How to calculate these xors? At each node x, we store a vector of size D(n)=2⋅K where D(n)i is the xorsum of all nodes having their depth = i — relative to node x — in the subtree of node n.

 **Calculating the answer for all roots**How to propagate these values in a DFS? We know that the nodes at depth `i` is at depth `i + 1` for my child nodes. So, we can simply cycle through them and update the values. Check the implementation for details.

 **C++ solution**
```cpp
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 1;
const int K = 20 + 1;

using VI = vector<unsigned int>;
using VVI = vector<vector<unsigned int>>;

VVI dp(N, VI(2 * K));
VI a(N);
vector<bool> win(N);
int n, k, k2;

void dfs(VVI &adj, int node, int prev) { 
    dp[node][0] = a[node];

    for (auto neigh : adj[node]) {
        if (neigh == prev) continue;
        dfs(adj, neigh, node);

        for (int rem = 1; rem < k2; rem++)
            dp[node][rem] ^= dp[neigh][rem - 1];

        dp[node][0] ^= dp[neigh][k2 - 1];
    }
}

void dfs2(const VVI &adj, const int node, const int prev, const vector<unsigned int> &my_xors) {
    vector<unsigned int> final_xors(k2);
    for (int i = 0; i < k2; i++) 
        final_xors[i] = my_xors[i] ^ dp[node][i];

    unsigned int odd_layer_xor = 0;
    for (int i = k; i < k2; i++)
        odd_layer_xor ^= final_xors[i];
    win[node] = odd_layer_xor > 0;

    for (auto neigh : adj[node]) {
        if (neigh == prev) continue;
       
        auto xor_send = final_xors;

        // remove all contribution of this subtree
        for (int i = 1; i < k2; i++)
            xor_send[i] ^= dp[neigh][i - 1];
        
        xor_send[0] ^= dp[neigh][k2 - 1];

        // whatever was depth k for me is depth k+1 for my child node
        int last = xor_send.back();
        for (int i = k2 - 1; i > 0; i--)
            xor_send[i] = xor_send[i - 1];

        xor_send[0] = last;

        dfs2(adj, neigh, node, xor_send);
    }
}

int main() {
    cin >> n >> k;
    k2 = 2 * k;

    VVI adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) cin >> a[i];

    dfs(adj, 1, 0);
    dfs2(adj, 1, 0, vector<unsigned int>(k2));

    for (int i = 1; i <= n; i++) cout << (win[i] ? 1 : 0) << " ";

    return 0;
}
```
 **Python solution**
```cpp
n, k = list(map(int, input().split()))
k2 = 2 * k

dp = [[0 for _ in range(k2)] for _ in range(n + 1)]
adj = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    _x, _y = list(map(int, input().split()))
    adj[_x].append(_y)
    adj[_y].append(_x)

a = [0] + list(map(int, input().split()))

win = [0 for _ in range(n + 1)]

parent = [0 for _ in range(n + 1)]


def dfs(node):
    global parent
    global dp

    stack = [node]

    pass_num = [0 for _ in range(n + 1)]

    while stack:
        node = stack[-1]

        pass_num[node] += 1

        if pass_num[node] == 1:
            for neigh in adj[node]:
                if neigh == parent[node]:
                    continue

                parent[neigh] = node
                stack.append(neigh)

            continue

        dp[node][0] = a[node]
        stack.pop()

        for neigh in adj[node]:
            if neigh == parent[node]:
                continue

            for rem in range(1, k2):
                dp[node][rem] ^= dp[neigh][rem - 1]

            dp[node][0] ^= dp[neigh][k2 - 1]


def dfs2(node):
    global win

    stack = [[node, [0 for __ in range(k2)]]]

    global dp

    while stack:
        node, prev_xors = stack[-1]
        stack.pop()

        final_xors = [x ^ y for x, y in zip(prev_xors, dp[node])]

        for neigh in adj[node]:
            if neigh == parent[node]:
                continue

            send_xors = [x for x in final_xors]
            for i in range(1, k2):
                send_xors[i] ^= dp[neigh][i - 1]
            send_xors[0] ^= dp[neigh][k2 - 1]

            send_xors = [send_xors[-1]] + send_xors[:-1]
            stack.append([neigh, send_xors])

        odd_xor = 0
        for i in range(k, k2):
            odd_xor ^= final_xors[i]

        win[node] = 1 if odd_xor > 0 else 0


dfs(1)
dfs2(1)
print(" ".join(list(map(str, win[1:]))))
```
