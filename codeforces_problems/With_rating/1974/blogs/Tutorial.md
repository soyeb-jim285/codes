# Tutorial

[1974A - Phone Desktop](../problems/A._Phone_Desktop.md "Codeforces Round 946 (Div. 3)")

Idea: [Aksenov239](https://codeforces.com/profile/Aksenov239 "Candidate Master Aksenov239")

 **Tutorial**
### [1974A - Phone Desktop](../problems/A._Phone_Desktop.md "Codeforces Round 946 (Div. 3)")

Note that on one screen we can put no more than two 2×2 icons. Thus, we need at least Z=⌈y/2⌉ screens. Then, we check how many 1×1 icons we can put on these screens: 15⋅Z−4⋅y. The 1×1 icons left we need to put on additional screens.

 **Solution**
```cpp
nt = int(input())
 
for t in range(nt):
    line = input()
    x, y = [int(q) for q in line.split()]
    mm = (y + 1) // 2
    x -= (mm * 5 * 3 - y * 2 * 2)
    x = max(x, 0)
    mm += (x + 5 * 3 - 1) // (5 * 3)
    print(mm)
```
[1974B - Symmetric Encoding](../problems/B._Symmetric_Encoding.md "Codeforces Round 946 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1974B - Symmetric Encoding](../problems/B._Symmetric_Encoding.md "Codeforces Round 946 (Div. 3)")

Let's construct a string r according to the definition from the condition: we write down all the letters from s once in ascending order.

After that, we just need to replace all the characters in s with their symmetric characters in the string r. The length of string r does not exceed 26, so the position of this character can be found by linear search.

 **Solution**
```cpp
def solve():
    n = int(input())
    b = input()
    cnt = [0] * 26
    for c in b:
        cnt[ord(c) - ord('a')] = 1
    tmp = ''
    for i in range(26):
        if cnt[i] > 0:
            tmp += chr(ord('a') + i)
    a = ''
    for c in b:
        a += tmp[-1 - tmp.find(c)]
    print(a)
    
 
for _ in range(int(input())):
    solve()
```
[1974C - Beautiful Triple Pairs](../problems/C._Beautiful_Triple_Pairs.md "Codeforces Round 946 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1974C - Beautiful Triple Pairs](../problems/C._Beautiful_Triple_Pairs.md "Codeforces Round 946 (Div. 3)")

To consider each pair only once, we will go from left to right and while adding a new triplet, we will add to the answer the number of already added triplets that form a beautiful pair with the current one.

We will maintain a map with triplets, to denote a triplet with an error, we will place 0 (or any other value that cannot occur in the array a) in place of the error.

Thus, for each triplet b, the already found triplets (0,b2,b3), (b1,0,b3), (b1,b2,0) will be good. In each case, triplets equal to b will also be included, so they need to be subtracted from each of the three cases.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    cnt = dict()
    ans = 0
    for i in range(n - 2):
        triplet = (a[i], a[i + 1], a[i + 2])
        mist = [0] * 3
        mist[0] = (0, a[i + 1], a[i + 2])
        mist[1] = (a[i], 0, a[i + 2])
        mist[2] = (a[i], a[i + 1], 0)
        for trip in mist:
            ans += cnt.get(trip, 0) - cnt.get(triplet, 0)
            cnt[trip] = cnt.get(trip, 0) + 1
        cnt[triplet] = cnt.get(triplet, 0) + 1
    print(ans)
    
    
for i in range(int(input())):
    solve()
```
[1974D - Ingenuity-2](../problems/D._Ingenuity-2.md "Codeforces Round 946 (Div. 3)")

Idea: [MaxBuzz](https://codeforces.com/profile/MaxBuzz "Master MaxBuzz")

 **Tutorial**
### [1974D - Ingenuity-2](../problems/D._Ingenuity-2.md "Codeforces Round 946 (Div. 3)")

For the string S, calculate the 2D-coordinates (x,y) of the point obtained as a result of sequentially executing all instructions (for example, N decreases y by 1, S increases y by 1, E increases x by 1, W decreases x by 1). Consider the following cases: 

* xmod or y \bmod 2 \neq 0. Obviously, a solution does not exist.
* x = 0, y = 0, |S| = 2. This is one of the strings NS, SN, WE, EW. Again, in this case, it is impossible to construct a solution, as both the rover and the helicopter must execute at least 1 instruction.
* x = 0, y = 0, |S| > 2. A solution exists: assign the first instruction to the helicopter, as well as one of its complements, which exists. Assign all the remaining positive number of instructions to the rover. Both will obviously end up at (0, 0).
* All other cases: a solution exists. Assign |x|/2 and |y|/2 instructions moving in the direction of the sign of x and y respectively — which definitely exist — to the helicopter, and the rest to the rover. Both subsets of instructions will be non-empty.
 **Solution**
```cpp
inv = {'N':'S', 'S': 'N',
    'E': 'W', 'W': 'E'}

def solve():
    n = int(input())
    s = input()
    x, y = 0, 0
    for c in s:
        if c == 'N':
            y += 1
        if c == 'S':
            y -= 1
        if c == 'E':
            x += 1
        if c == 'W':
            x -= 1
    if x % 2 == 1 or y % 2 == 1:
        print('NO')
        return
    ans = ['R'] * n
    if x == y == 0:
        if n == 2:
            print('NO')
            return
        ans[0] = ans[s.find(inv[s[0]])] = 'H'
    else:
        for i in range(n):
            if s[i] == 'N' and y > 0:
                y -= 2
                ans[i] = 'H'
            if s[i] == 'S' and y < 0:
                y += 2
                ans[i] = 'H'
            if s[i] == 'E' and x > 0:
                x -= 2
                ans[i] = 'H'
            if s[i] == 'W' and x < 0:
                x += 2
                ans[i] = 'H'
    print(*ans, sep='')
    
    
for _ in range(int(input())):
    solve()
```
[1974E - Money Buys Happiness](../problems/E._Money_Buys_Happiness.md "Codeforces Round 946 (Div. 3)")

Idea: [RobinFromTheHood](https://codeforces.com/profile/RobinFromTheHood "Expert RobinFromTheHood")

 **Tutorial**
### [1974E - Money Buys Happiness](../problems/E._Money_Buys_Happiness.md "Codeforces Round 946 (Div. 3)")

Let's consider the classic knapsack problem. Let dp[j] be the minimum cost required to achieve happiness j. In the i-th month, we iterate through dp[k] and check if dp[k]+c_i \le (i-1) \cdot x, and if so, we can afford to transition to dp[k+h_i] and accordingly update dp[k+h_i].

The complexity is O(m \cdot \sum_i h_i) for each set of input data.

 **Solution**
```cpp
T = int(input())
big = float('inf')
for _ in range(T):
    m, x = map(int, input().split())
    c = []
    h = []
    for i in range(m):
        ci, hi = map(int, input().split())
        c.append(ci)
        h.append(hi)
    mh = sum(h)
    dp = [0] + [big] * mh
    for i in range(m):
        for j in range(mh, h[i]-1, -1):
            if dp[j-h[i]] + c[i] <= i*x:
                dp[j] = min(dp[j], dp[j-h[i]]+c[i])
    for i in range(mh, -1, -1):
        if dp[i] != big:
            print(i)
            break
```
[1974F - Cutting Game](../problems/F._Cutting_Game.md "Codeforces Round 946 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1974F - Cutting Game](../problems/F._Cutting_Game.md "Codeforces Round 946 (Div. 3)")

First, let's sort all cells with chips in non-decreasing order of the x-coordinate (let's denote the array as ver), also in a separate array hor we will sort them in non-decreasing order of the y-coordinate.

As we add moves, we will maintain the boundaries of the original matrix to which it was cut: we will shift the respective boundary by k. Obviously, the moves U will remove some prefix from the array ver and add it to the answer, and the moves D will remove some suffix from the array ver and add it to the answer. The same goes for the moves L and R and the array hor. Instead of removing elements, the current boundaries of the arrays can be maintained using two pointers.

However, with this calculation, some chips may be counted twice: when removed vertically and when removed horizontally. To prevent this from happening, we will maintain a set of already removed vertices and before adding a chip to the answer, we will check that it has not been removed before.

 **Solution**
```cpp
def solve(tc):
    a, b, n, m = map(int, input().split())
    ver, hor = [], []
    for i in range(n):
        x, y = map(int, input().split())
        ver.append((x, y))
        hor.append((y, x))
    deleted = set()
    hor.sort()
    ver.sort()
    ans = [0, 0]
    u, d = 1, a
    l, r = 1, b
    hl, hr = 0, n - 1
    vl, vr = 0, n - 1
    for i in range(m):
        c, k = input().split()
        k = int(k)
        if c == 'U':
            u += k
            while vl <= vr and ver[vl][0] < u:
                if ver[vl] not in deleted:
                    ans[i % 2] += 1
                    deleted.add(ver[vl])
                vl += 1
        if c == 'D':
            d -= k
            while vl <= vr and ver[vr][0] > d:
                if ver[vr] not in deleted:
                    ans[i % 2] += 1
                    deleted.add(ver[vr])
                vr -= 1
        if c == 'L':
            l += k
            while hl <= hr and hor[hl][0] < l:
                if (hor[hl][1], hor[hl][0]) not in deleted:
                    ans[i % 2] += 1
                    deleted.add((hor[hl][1], hor[hl][0]))
                hl += 1
        if c == 'R':
            r -= k
            while hl <= hr and hor[hr][0] > r:
                if (hor[hr][1], hor[hr][0]) not in deleted:
                    ans[i % 2] += 1
                    deleted.add((hor[hr][1], hor[hr][0]))
                hr -= 1
    print(ans[0], ans[1])


t = int(input())
for i in range(1, t + 1):
    solve(i)
```
[1974G - Money Buys Less Happiness Now](../problems/G._Money_Buys_Less_Happiness_Now_.md "Codeforces Round 946 (Div. 3)") 

Idea: [RobinFromTheHood](https://codeforces.com/profile/RobinFromTheHood "Expert RobinFromTheHood"), [izban](https://codeforces.com/profile/izban "International Grandmaster izban"), [Aksenov239](https://codeforces.com/profile/Aksenov239 "Candidate Master Aksenov239")

 **Tutorial**
### [1974G - Money Buys Less Happiness Now](../problems/G._Money_Buys_Less_Happiness_Now_.md "Codeforces Round 946 (Div. 3)")

Let us consider the smallest element c_m (and the rightmost if equal). Suppose we do not take it. Now, we emulate the decisions from the first month up to month m. Note that if we chose some element on the left of m we could have chosen the smallest one c_m instead. Thus, we can go greedy: go over the costs in the sorted order and check whether we can take it. To check whether there are enough pounds from the previous months we can use the segment tree. When we take the happiness during month m we need to reduce the amount of pounds on the left by c_m.

This greedy approach can be implemented simpler. We just need to go over the costs from the first month and maintain the heap (or set/priority queue) of chosen costs. When we go over a new cost we check whether we can pay for it and, if positive, we add it to our answer. Otherwise, we remove the largest chosen cost from the heap, compare it with the current cost, and put back the smaller one.

 **Solution**
```cpp
from heapq import *
for _ in range(int(input())):
    m, x = map(int, input().split())
    c = [int(x) for x in input().split()]
    budget = 0
    Q = []
    for i in c:
        if budget >= i:
            heappush(Q, -i)
            budget -= i
        elif Q and -Q[0] > i:
            budget += -heappop(Q)-i
            heappush(Q, -i)
        budget += x
    print(len(Q))
```
