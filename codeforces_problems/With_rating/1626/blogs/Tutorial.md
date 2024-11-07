# Tutorial

[1626A - Equidistant Letters](../problems/A._Equidistant_Letters.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1626A - Equidistant Letters](../problems/A._Equidistant_Letters.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Let's consider a very special case of equal distances. What if all distances were equal to 1? It implies that if some letter appears exactly twice, both occurrences are placed right next to each other.

That construction can be achieved if you sort the string, for example: first right down all letters 'a', then all letters 'b' and so on. If a letter appears multiple times, all its occurrences will be next to each other, just as we wanted.

Overall complexity: O(|s|log|s|) or O(|s|) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
  print(''.join(sorted(input())))
```
[1626B - Minor Reduction](../problems/B._Minor_Reduction.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1626B - Minor Reduction](../problems/B._Minor_Reduction.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Let's think how a reduction changes the length of x. There are two cases. If two adjacent letters sum up to 10 or greater, then the length doesn't change. Otherwise, the length decreases by one.

Obviously, if there exists a reduction that doesn't change the length, then it's better to use it. Which among such reduction should you choose? Well, notice that such a reduction always makes the number strictly smaller (easy to see with some case analysis). Thus, the logical conclusion is to leave the longest possible prefix of x untouched. So, the rightmost such reduction will change the number as little as possible.

If all reductions decrease the length, then a similar argument can be applied. The sum will be a single digit, but a digit that is greater than or equal to the left one of the adjacent pair. If it was just greater, it's easy to see that the leftmost such reduction will make the number the largest possible. The equal case adds more case analysis on top of the proof, but the conclusion remains the same: the leftmost reduction is the best one.

As an implementation note, since all the reductions are of the same type, the leftmost reduction always includes the first and the second digits.

Overall complexity: O(|x|) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
  x = [ord(c) - ord('0') for c in input()]
  n = len(x)
  for i in range(n - 2, -1, -1):
    if x[i] + x[i + 1] >= 10:
      x[i + 1] += x[i] - 10
      x[i] = 1
      break
  else:
    x[1] += x[0]
    x.pop(0)
  print(''.join([chr(c + ord('0')) for c in x]))
```
[1626C - Monsters And Spells](../problems/C._Monsters_And_Spells.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1626C - Monsters And Spells](../problems/C._Monsters_And_Spells.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Consider the problem with n=1. There is a single monster with some health h that appears at some second k. In order to kill it, we have to wind up our spell until it has damage h. So we have to use it from second k−h+1 to second k. Look at it as a segment [k−h+1;k] on a timeline.

Actually, to avoid handling zero length segments, let's instead say that a segment covers the time from k−h non-inclusive to k inclusive, producing a half-interval (k−h;k]. This way, the total mana cost will be len(len+1)2, where len is the length of the half-interval.

Now n=2. There are two time segments.

If they don't intersect (segments (1;2] and (2;3] don't intersect, since they are half-intervals), then it's always better to wind up the spell for the monsters separately instead of saving the damage.

However, if they intersect, then we don't have the choice other than to save the damage from the earlier one to the later one. Otherwise, there won't be enough time to wind up the spell.

What that means in a mathematic sense? The answer is the union of two half-intervals. If they don't intersect, they are left as is. Otherwise, they become one half-interval that covers them both.

Now add the third monster into the construction. The same argument applies. While there exists a pair of intersecting half-intervals, keep uniting them.

The union of all half-intervals can be found in O(nlogn), but the constraints allowed slower approaches as well.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
  n = int(input())
  k = list(map(int, input().split()))
  h = list(map(int, input().split()))
  st = []
  for i in range(n):
    st.append([k[i] - h[i], k[i]])
  st.sort()
  l, r = -1, -1
  ans = 0
  for it in st:
    if it[0] >= r:
      ans += (r - l) * (r - l + 1) // 2
      l, r = it
    else:
      r = max(r, it[1])
  ans += (r - l) * (r - l + 1) // 2
  print(ans)
```
[1626D - Martial Arts Tournament](../problems/D._Martial_Arts_Tournament.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1626D - Martial Arts Tournament](../problems/D._Martial_Arts_Tournament.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Sort the weights, now choosing x and y will split the array into three consecutive segments.

Consider a naive solution to the problem. You can iterate over the length of the first segment and the second segment. The third segment will include everyone remaining.

Now you have to check if there exist some x and y that produce such segment. x can be equal to the first element of the second segment (since only all elements of the first segment are smaller than it). Similarly, y can be equal to the first element of the third segment.

However, if the last element of some segment is equal to the first element of the next segment, no x or y can split the array like that.

Otherwise, you can split an array like that. So you can iterate over the lengths, check the correctness and choose the best answer.

Now let's optimize it using the condition about powers of two.

First, iterate over the size of the middle division (which is a power of two). Then over the length of the first segment (which can be not a power of two). Check if the first segment is valid.

So we fixed the length of the first segment and some value which is greater or equal than the length of the second segment. That value isn't necessarily equal to the length of the second segment because the produced segment might be invalid.

So there is a greedy idea that the second segment should be as long as possible under the constraint that it doesn't exceed the fixed value. The intuition is the following. Consider the longest possible valid segment. Now take the last element away from it. We will have to invite one more participant to the middle division. And that element will also get added to the third segment, increasing its length. So potentially, you can only increase the required number of participants to invite.

This can be implemented in the following fashion. For each position i precalculate lefti — the closest possible segment border from the left. Iterate over the size of the middle division mid as a power of two. Iterate over the length of the first segment len1. Find the closest border to the left of len1+mid=left[len1+mid]. Get the lengths of the second and the third segments. Find the closest powers of two to each length and update the answer.

Overall complexity: O(nlogn) per testcase.

 **Solution (awoo)**
```cpp
calc = 1
nxt = [1, 0]

for _ in range(int(input())):
  n = int(input())
  a = sorted(list(map(int, input().split())))
  while calc <= n:
    for i in range(calc):
      nxt.append(calc - i - 1)
    calc *= 2
  left = []
  for i in range(n + 1):
    if i == 0 or i == n or a[i] != a[i - 1]:
      left.append(i)
    else:
      left.append(left[-1])
  mid = 1
  ans = n + 2
  while mid <= n:
    for len1 in range(n + 1):
      if left[len1] == len1:
        len2 = left[min(n, len1 + mid)] - len1
        len3 = n - len1 - len2
        ans = min(ans, nxt[len1] + (mid - len2) + nxt[len3])
    mid *= 2
  print(ans)
```
[1626E - Black and White Tree](../problems/E._Black_and_White_Tree.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1626E - Black and White Tree](../problems/E._Black_and_White_Tree.md "Educational Codeforces Round 121 (Rated for Div. 2)")

I think there are some ways to solve this problem with casework, but let's try to come up with an intuitive and easy-to-implement approach.

It's always possible to move closer to some black vertex, no matter in which vertex you are currently and which black vertex was used in the previous operation. However, sometimes if you try to move along an edge, you immediately get forced back. Let's analyze when we can move without being forced back.

We can move along the edge x→y so that our next action is not moving back if:

* either y is black (there is no next action);
* or, if we remove the edge between x and y, the number of black vertices in y's component is at least 2 (we can use one of them to go from x to y, and another one to continue our path).

Note that the cases x→y and y→x may be different (sometimes it will be possible to move in one direction, and impossible to move in the opposite direction).

Let's treat this possible move x→y as an arc in a directed graph. We can find all such arcs if we can answer the queries of the type "count black vertices in a subtree of some vertex", and this can be done by rooting the tree and calculating this information for each subtree with DFS.

Now, if there is a way from some vertex i to some black vertex along these arcs, the answer for the vertex i is 1. How can we find all such vertices? Let's transpose the graph (change the direction of each arc to opposite), now we need to find all vertices reachable from black ones — which is easily done with multisource BFS or DFS.

The complexity of this solution is O(n).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 300043;

vector<int> g[N];
int cnt[N];
int c[N];
vector<int> g2[N];
int par[N];
int used[N];

void dfs(int x, int p = -1)
{
    par[x] = p;
    for(auto y : g[x])
        if(y != p)
        {
            dfs(y, x);
            cnt[x] += cnt[y];
        }
    cnt[x] += c[x];
}   

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
        for(auto j : g[i])
        {
            if(i == par[j])
            {
                if(c[i] == 1 || cnt[0] - cnt[j] > 1)
                    g2[i].push_back(j);
            }
            else
            {
                if(c[i] == 1 || cnt[i] > 1)
                    g2[i].push_back(j);
            }
        }
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(c[i] == 1)
        {
            q.push(i);
            used[i] = 1;
        }
    }
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        for(auto y : g2[k])
            if(used[y] == 0)
            {
                used[y] = 1;
                q.push(y);
            }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", used[i]);
    puts("");
}
```
[1626F - A Random Code Problem](../problems/F._A_Random_Code_Problem.md "Educational Codeforces Round 121 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1626F - A Random Code Problem](../problems/F._A_Random_Code_Problem.md "Educational Codeforces Round 121 (Rated for Div. 2)")

I think it's easier to approach this problem using combinatorics instead of probability theory methods, so we'll calculate the answer as "the sum of values of ans over all ways to choose the index on each iteration of the loop".

If a number aidx is chosen on the iteration i of the loop, then it is reduced to the maximum number divisible by i that doesn't exceed the initial value. So, if a number is divisible by all integers from 1 to k, i. e. divisible by L=LCM(1,2,…,k), it won't be changed in the operation. Furthermore, if ⌊aidxL⌋=x, then the value of this element won't become less than x⋅L.

It means that we can interpret each number ai as ai=x⋅L+y, where x=⌊aiL⌋ and y=aimodL. The part with x⋅L will always be added to the variable ans when this element is chosen, so let's add k⋅nk−1⋅x⋅L to the answer (which is the contribution of x⋅L over all ways to choose the indices in the operations), and work with aimodL instead of ai.

Now all elements of the array are less than L. We can use this constraint by writing the following dynamic programming to solve the problem: dpi,j is the number of appearances of the integer i in the array a over all ways to choose the indices for the first j iterations.

For j=0, dp is just the number of occurrences of each integer in the array a. The transitions from dpi,j are the following ones:

* if this element is chosen in the operation, then it becomes i′=i−(imod(j+1)), and we transition to the state dpi′,j+1;
* otherwise, the element is unchanged, and we transition to the state dpi,j+1, multiplying the current value by n−1, which is the number of ways to choose some other element in the operation.

How can we use this dynamic programming to get the answer? On the (j+1)-th iteration, the number of times we choose the integer i is exactly dpi,j, and the number of ways to use the integers in the next operations is nk−j−1, so we add i⋅dpi,j⋅nk−j−1 to the answer for every such state dpi,j.

This solution runs in time O(n+LCM(1,2,…,k)⋅k), which may be too slow if not implemented carefully. Fortunately, we have an easy way to optimize it: use L=LCM(1,2,…,k−1) instead of L=LCM(1,2,…,k), which divides L by 17 in the worst case scenario for our solution. We can do this because even if an integer is changed on the k-th operation, we are not interested in this change since this is the last operation.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int MOD = 998244353;
const int L = 720720;

int add(int x, int y, int m = MOD)
{
    x += y;
    if(x >= m) x -= m;
    return x;
}

int mul(int x, int y, int m = MOD)
{
    return (x * 1ll * y) % m;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int main()
{
    int n, a0, x, y, k, M;
    cin >> n >> a0 >> x >> y >> k >> M;
    vector<int> arr(n);
    arr[0] = a0;
    for(int i = 1; i < n; i++)
        arr[i] = add(mul(arr[i - 1], x, M), y, M);
    int ans = 0;
    int total_ways = binpow(n, k);
    int coeff = mul(divide(total_ways, n), k);
    vector<vector<int>> dp(k, vector<int>(L));
    for(int i = 0; i < n; i++)
    {
        int p = arr[i] / L;
        int q = arr[i] % L;
        dp[0][q]++;
        ans = add(ans, mul(p, mul(L, coeff)));
    }
    int cur_coeff = divide(total_ways, n);
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < L; j++)
        {
            int cur = dp[i - 1][j];
            if(i < k)
                dp[i][j] = add(dp[i][j], mul(n - 1, cur));
            ans = add(ans, mul(j, mul(cur, cur_coeff)));
            if(i < k)
                dp[i][j - (j % i)] = add(dp[i][j - (j % i)], cur);
        }
        cur_coeff = divide(cur_coeff, n);
    }
    cout << ans << endl;        
}
```
