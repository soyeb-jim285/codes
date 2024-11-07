# Tutorial_(en)

Thank you for your participation!

[1734A — Select Three Sticks](../problems/A._Select_Three_Sticks.md)
----------------------------------------------------------------------------

We first sort the array aa in non-decreasing order.

Denote the indices of the elements that we choose from aa to be xx, yy, and zz, where 1≤x<y<z≤n1≤x<y<z≤n, and the final value (after performing the operations) of the concerned elements to be vv.

The minimum required number of operations is then |ax−v|+|ay−v|+|az−v||ax−v|+|ay−v|+|az−v|. It is well-known that such expression attains its minimum value when vv is the median of axax, ayay, and azaz. Since the array aa has already been sorted, it is best to assign vv to be ayay.

Our expression then becomes |ax−ay|+|ay−ay|+|az−ay|=(ay−ax)+0+(az−ay)=az−ax|ax−ay|+|ay−ay|+|az−ay|=(ay−ax)+0+(az−ay)=az−ax. We would like to minimize the value of azaz, which implies zz should be as small as possible since aa is sorted. It is clear that taking z=y+1z=y+1 would minimize the value of the expression. Similarly, we can show that we can take x=y−1x=y−1 to minimize the value of the expression.

Therefore, the only possible values of the triplets (x,y,z)(x,y,z) are of the form (t,t+1,t+2)(t,t+1,t+2) for positive integers 1≤t≤n−21≤t≤n−2, and we can iterate through all such triplets and find the best one. 

The time complexity is Θ(nlogn)Θ(nlogn) per case due to sorting.

 **Code in C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int a[n+1];
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=2e9;
	for (int i=3; i<=n; i++){
		ans=min(ans,a[i]-a[i-2]);
	}
	cout<<ans<<'n';
}
int main(){
	int t;
	cin>>t;
	for (int i=1; i<=t; i++){
		solve();
	}
}

```
[1734B — Bright, Nice, Brilliant](../problems/B._Bright,_Nice,_Brilliant.md)
--------------------------------------------------------------------------------

Note that the brightnesses of the rooms on the ii-th floor is at most ii. This is because in room (i,1)(i,1), only ii rooms, namely, (1,1)(1,1), (2,1)(2,1), ……, (i,1)(i,1) can reach to (i,1)(i,1) through some number of staircases.

It is also possible to find a configuration of torches in the pyramid such that the brightnesses of the rooms on the ii-th floor is exactly ii, i.e. it attains the upper bound. 

The configuration is as follows: Room (i,j)(i,j) contains a torch if and only if it is the leftmost room (i=1i=1) or the rightmost room (i=ji=j) on the ii-th floor. 

This is valid because for all rooms (i,j)(i,j), it can be reached from (1,1)(1,1), (2,1)(2,1), (3,1)(3,1), ……, (i−j+1,1)(i−j+1,1) and (2,2)(2,2), (3,3)(3,3), ……, (j,j)(j,j). In other words, room (i,j)(i,j) has brightness (i−j+1)+j−1=i(i−j+1)+j−1=i, so the pyramid is nice.

 **Code in C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << (j == 1 || j == i) << ' ';
            }
            cout << 'n';
        }
    }
}
```
[1734C — Removing Smallest Multiples](../problems/C._Removing_Smallest_Multiples.md)
------------------------------------------------------------------------------------

One operation should be used to remove every element not belonging to TT.

Let vv be an element not belonging to TT. Suppose a xx-cost operation removes value vv, then vv must be divisible by xx. Furthermore, the multiples x,2x,⋯(k−1)xx,2x,⋯(k−1)x must have been already removed from SS, where we write v=kxv=kx.

Since removed elements stay removed, the above is only possible if all of x,2x,⋯(k−1)xx,2x,⋯(k−1)x does not belong to TT.

For each vv, let f(v)f(v) be the smallest integer xx satisfying the above condition. As we can always remove vv using a vv-cost operation, f(v)≤vf(v)≤v and in particular f(v)f(v) exists.

The total cost must be at least ∑i∉Tf(i)∑i∉Tf(i). We claim that this cost can be achieved.

To do so, we should remove the required elements in ascending order. When removing vv, we assume all w∉Tw∉T with w<vw<v have already been removed. At this state, an f(v)f(v)-cost operation would be able to remove vv. 

It remains to find the values f(v)f(v). To do so efficiently, we can perform the above process in a bottom-up manner similar to the Sieve of Eratosthenes. Please refer to the code below for implementation details. The overall complexity is n(1+12+13+⋯+1n)=Θ(nlogn)n(1+12+13+⋯+1n)=Θ(nlogn).

 **Code in C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    bool a[n + 1];
    string str;
    cin >> str;
    for (int i = 1; i <= n; i++) {
        a[i] = (str[i - 1] == '1');
    }
    long long ans = 0;
    int cost[n + 1];
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j += i) {
            if (a[j]) break;
            cost[j] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) ans += cost[i];
    }
    cout << ans << 'n';
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
```
[1734D — Slime Escape](../problems/D._Slime_Escape.md)
---------------------------------------------------------------------

Let's call a group of slime **good** if their total health is at least 00, or if defeating this group allows you to reach the exits. 

We partition the slimes into good groups in a two-pointer like manner. To form the groups to the right, start from position kk, then find the smallest position rr such that slimes from k+1k+1 through rr form a good group. We do the same starting from r+1r+1 again. Repeat this process until slimes to the right are partitioned into groups, which can be done by maintaining the sum of health. We partition the left slimes into groups in a similar way. 

We can observe that in an optimal strategy, we may assume the player absorbs group-by-group.

 **Proof**Assuming there is a valid strategy S to reach the exit. Let X be the first group to the left, and Y be the first group to the right. Without loss of generality, assume all slimes of X are absorbed before all slimes of Y are absorbed first. Suppose there are x slimes in X and y slimes in Y.

Suppose we did not absorb all of X at a time. For example, if there are 6 slimes in X and 5 or more slimes in Y, the beginning of our strategy may look like this: 

LLRRLRLLRL....

Consider instead the strategy where we move all `L' to the front. We claim that the strategy stays valid. That is, the following strategy 

LLLLLLRRRR.... is at least as good.

We check that at every moment of strategy LLLLLLRRRR...., there is some point in time LLRRLRLLRL.... which we would have less than or equal amount of health.

For the state T1 that we take a moves to the left in LLLLLLRRRR...., we compare it with any moment T2 in LLRRLRLLRL.... that we have taken a moves to the left. To reach T2, we take b moves to the right. We can check that under the assumption, 0≤b<y. Since Y is the smallest good group to the right, taking these b extra right moves must have reduced our health. So, we have more health at T1 than in T2. 

Now consider the state T3 in LLLLLLRRRR.... where we take all x left moves and b more right moves. We should compare it with any moment T4 in LLRRLRLLRL.... that we have taken b right moves and some a left moves. We can check that under the assumption 0≤a<x. Since X is the smallest good group, taking only a moves to the left gives us less health compared to taking all x moves to the left. Therefore, we have more health at T3 than in T4.

Therefore, if LLRRLRLLRL.... is valid, LLLLLLRRRR.... must be valid. So, we only need to consider strategies of the second form. 

By applying this claim recursively, we notice that we only need to consider strategies that absorb whole groups at a time.

This works for all strategies, we just referred to the starting strategy as LLRRLRLLRL...., and the better strategy as LLLLLLRRRR.... to simplify notations.

For any good group, since the total health is positive, there is no drawback to absorbing a good group. In other words, whenever it is possible to absorb a good group, we will absorb it. 

For each group GG, we calculate the ``requirement'' of the group — the lowest health we can begin with, such that we can absorb the group while maintaining non-negative health at all times. The requirement of a group of slime with health a1,a2⋯ana1,a2⋯an can be expressed as

 −minnk=0(∑ki=1ai)−minnk=0(∑ki=1ai)Finally, we can simply simulate the process. We repeatedly attempt to absorb good groups to the left or to the right. We keep track of the current health, initially equal to akak. Whenever we consider whether to absorb a group or not, we absorb it if and only if the current health is at least as high as its requirement. Otherwise, we ignore it for now and attempt to do so for the group on the other side. If it is possible to reach a state where either all left groups or all right groups are absorbed, then we can win the game. If at some point, it is not possible to absorb the left group nor the right group, then we lose.

The overall complexity is Θ(n)Θ(n). 

It is also possible to use a range maxmax/minmin segment tree form the groups instead of using two-pointers, in which case its complexity would be Θ(nlogn)Θ(nlogn).

 **Code in C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n, k, P;
    cin >> n >> k;
    k--;
    long long L[n];
    for (int i = 0; i < n; i++) cin >> L[i];
    P = L[k];
    L[k] = 0;
    long long ps[n + 1];
    ps[0] = 0;
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + L[i - 1];
    int l = k, r = k + 1;
    vector<pair<long long, long long> > LG, RG;
    for (int i = k - 1; i >= 0; i--) {
        if (ps[i] <= ps[l] || i == 0) {
            lpng long worst = 0, cur = 0;
            for (int j = l - 1; j >= i; j--) {
                cur += L[j];
                worst = min(worst, cur);
            }
            LG.push_back({cur, -worst});
            l = i;
        }
    }
    for (int i = k + 2; i <= n; i++) {
        if (ps[i] >= ps[r] || i == n) {
            long long worst = 0, cur = 0;
            for (int j = r; j <= i - 1; j++) {
                cur += L[j];
                worst = min(worst, cur);
            }
            RG.push_back({cur, -worst});
            r = i;
        }
    }
    reverse(LG.begin(), LG.end());
    reverse(RG.begin(), RG.end());
    long long curp = P;
    while (true) {
        bool acted = false;
        if (!LG.empty() && curp >= LG.back().second) {
            curp += LG.back().first;
            LG.pop_back();
            acted = true;
        }
        if (!RG.empty() && curp >= RG.back().second) {
            curp += RG.back().first;
            RG.pop_back();
            acted = true;
        }
        if (LG.empty() || RG.empty()) {
            cout << "YESn";
            return;
        }
        if (!acted) {
            cout << "NOn";
            return;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
```
[1734E — Rectangular Congruences](../problems/E._Rectangular_Congruence.md)
--------------------------------------------------------------------------------

We say a matrix to be good if it satisfies the congruence condition (the second condition). 

When we have a good matrix, we can add any value cc to a whole row while maintaining the congruence relation. The same is true for adding the same value to a whole column.

Suppose we have any good matrix AA, then by adding bi−ai,ibi−ai,i to the ii-th row for each of i=1,2,⋯,ni=1,2,⋯,n, we obtain a good matrix that has the desired values on the diagonal. 

In fact, there are a lot of possible constructions. We present a few of them here:

 * ai,j=i×j(modn)ai,j=i×j(modn)
* ai,j=(i+j)2(modn)ai,j=(i+j)2(modn). This needs special handling when n=2n=2.
* ai,j=(i+j)(i+j+1)2(modn)ai,j=(i+j)(i+j+1)2(modn).
* The coolest part is that all quadratic polynomials in the form ai2+bij+cj2+di+ej+fai2+bij+cj2+di+ej+f are valid for all integers a,b,c,d,e,fa,b,c,d,e,f and b≢0(modn)

As a bonus, we prove that the general quadratic polynomial gives a good construction.

 **Proof**Since we can add values to a whole row or column, and i2,j2,i,j,1 are also constant on the rows and columns, adding them by ai,j has no effect. So we may just assume a=c=d=e=f=0.

So it suffices to show that ai,j=bij(modn) satisfies the condition. We can see directly that ar1,c1−ar2,c1−ar1,c2+ar2,c2=b(r1−r2)(c1−c2). As r1≠r2, c1≠c2, b≢0(modn), and n is a prime, this expression must be nonzero (modn). 

Here are some extra observations that may enable one to find a good matrix more quickly. 

 **Some extra observations**For each j, the values ai,j−ai−1,j over all 0≤i<n must be a permutation of 0,1,⋯,n−1.

A good matrix stays good if we permute the rows or permute the columns. Therefore, we can show that there exists some good matrix with a1,j=ai,1=0, and a2,j=j−1, ai,2=i−1. Assuming this, it should not be difficult to discover ai,j=(i−1)(j−1) yields one of the good matrices. 

Let b be the two dimensional difference array of a, that is, bi,j=ai,j−ai−1,j−ai,j−1+ai−1,j−1. Then, the condition becomes sum of any rectangles of b must be nonzero (modn). It is easy to see b=1 is valid. This corresponds to the solution that ai,j=i×j(modn).

 **Code in C++**
```cpp
#include <bits/stdc++.h>
using namespace std;

int want[355];
int board[355][355];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n ; i ++){
        cin >> want[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = (i * j) % n;
        }
    }
    for(int i = 0; i < n; i ++){
        int extra = (want[i] + n - board[i][i] )% n ;
        for (int j = 0; j < n; j++) {
            board[i][j] += extra;
            board[i][j] %= n;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}
```
[1734F — Zeros and Ones](../problems/F._Zeros_and_Ones.md)
-----------------------------------------------------------------------

Observe that the i-th character is `1' if and only if i has an odd number of set bits in its binary representation. Both solutions make use of this fact.

The constraints allows solutions of up to Θ(qlog3n). Yet, both of the model solution runs in Θ(logn).

### 1. Digit DP solution

The question can be reformulated as follows: How many integers x between 0 and m−1 inclusive have the property that the total number of set bits of x and x+n is an odd number? 

This can be solved with digit DP. We process the bit position from ⌈log(max)⌉ down to 0. We maintain three states: 

 * ans, a boolean value;
* trailzeros, an integer between 0 and ⌈log(max)⌉ inclusive; and
* under, a boolean value.

We can thus conclude the following: the number of trailing zeros is all we need to decide the answer.

After processing each bit k, we should have the following: the number of integers x between 0 and ⌊m2k⌋ inclusive which have the following property:

 * the total number of set bits of x and x+⌊n2k⌋ is equal to ansmod2;
* the number of trailing `1's of x+⌊n2k⌋ is equal to trailzeros;
* the boolean value [x<⌊m2k⌋] (where [] is the Iverson bracket).

Now onto the transitions. Suppose we are adding the (k−1)-th digit, and let d be the new digit of x, and z be the (k−1)-th digit of n.

 * If z+d=0, then (ans,trailzeros) after digit k will be transited to (ans,0) after digit k−1;
* if z+d=1, then (ans,trailzeros) after digit k will be transited to ((ans+z+d)mod2,trailzeros+1) after digit k−1;
* if z+d=2, then (ans,trailzeros) after digit k will be transited to ((ans+z+trail+1)mod2,0) after digit k−1

The final answer is the total number of values for which ans=1 and under=1.

The above solution runs in Θ(log2(max)) per query. There is a simple way to optimize this to Θ(log(max)): note that we only need to keep parity of trailzero. 

There are many other digit DP approaches that give similar time complexity. The constraints should allow most of them pass.

 **Code in Kotlin**
```cpp
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
fun main(){
    repeat(readLine()!!.toInt()){

        val (n,m) = (readLine()!!.split(" ").map { it.toLong() })
        var DP = Array(2){Array(2){LongArray(64)}}

        DP[0][0][0] = 1

        for(bit in 60 downTo 0 ){
            var new = Array(2){Array(2){LongArray(64)}}
            for(under in 0 until 2){
                for(ans in 0 until 2){
                    for(nd in 0 until 2){
                        if(under == 0 && nd == 1 && !m.has(bit)) continue
                        val nunder = ((under == 1) || (nd == 0 && m.has(bit))).chi


                        val np = nd + n.has(bit).chi

                        for(trail in 0 until 62){
                            var nans = ans
                            if(nd == 1){
                                nans = 1 - nans
                            }
                            var newtrail:Int

                            if(np == 0){
                                newtrail = 0
                            }else if(np == 1){
                                nans = 1 - nans
                                newtrail = trail + 1
                            }else if(np == 2){
                                nans = (nans + trail + 1) %2
                                newtrail = 0
                            }else{
                                error("oh no")
                            }

                            new[nunder][nans][newtrail] += DP[under][ans][trail]
                        }
                    }
                }
            }
            DP = new
        }


        var ret = 0L
        for(trail in 0 until 64){
            ret += DP[1][1][trail]
        }
        println(ret)

    }
}

```
### 2. Recursive Solution, by [darkkcyan](https://codeforces.com/profile/darkkcyan "Grandmaster darkkcyan")

Define the function f(x):= the parity of bit one in the number x. 

We have thus reworded the statement into evaluating the follow expression:

 T=∑k−1i=0[f(i)≠f(i+n)]The formula can be further transformed as:

 T=∑k−1i=0f(i⊕(i+n))since [f(a)≠f(b)]=f(a⊕b) holds true for all non-negative integers a and b.

Imagine we construct a grid and assign the value at row r and column c to be f(r⊕c). Then, T is sum of a diagonal of length k which starts at either (0,n) or (n,0). Without loss of generality, we use (0,n) in this editorial. 

The grid can be constructed similarly to the way we construct the string S. We start with a 1-by-1 matrix M0=[0].

Then, the matrix Mi of size 2i×2i can be constructed as follows:

 Mi=[Mi−1¯Mi−1¯Mi−1Mi−1]where ¯Mi−1 is the matrix Mi−1 but with flipped bits.

Here is another way of constructing the grid: let Ci be an infinite chess board with alternating colors, similar to a regular chess board, but with each of the cells being size 2i×2i. For example, C0, C1 and C2 in an 8-by-8 grid is as follows:

 **Illustration**
```cpp
.*.*.*.*
*.*.*.*.
.*.*.*.*
*.*.*.*.
.*.*.*.*
*.*.*.*.
.*.*.*.*
*.*.*.*.


..**..**
..**..**
**..**..
**..**..
..**..**
..**..**
**..**..
**..**..


....****
....****
....****
....****
****....
****....
****....
****....
```
We claim that our grid is the xor of all chess board Ci. The proof is easy: Ci is constructed by xor-ing the i-th bit of the the row and column number.

We are therefore motivated to proceed in the following way: if we drop the least significant bit (by making it to be 0), we are still solving a very similar problem to the original problem, because dropping the first bit is similar to removing C0. And when we shift Ci to Ci−1, it is a recursion of the same problem!

Going back to the problem, where we are computing sum of a diagonal of length k. If k is odd, we can make it odd by adding the last element to the result and decreasing k by one. Now, k is even, and we can utilize the recurrence as follows: 

 * remove C0.
* scale the board down by 2 (including n and k). By doing so, Ci becomes Ci−1.
* solve the new problem.
* scale the board up again and add C0 back.
* from the result of the scaled down problem, some how calculate the result of the original problem

The result of the scaled down problem is the number of 2-by-2 cells with value 1. From the number of 2-by-2 cells with value 1, we compute the number of cells with value 0 as well. It is not hard to observe that it crosses the 2-by-2 cells at all places. The only thing that matters is the parity of n.

 * If n is even, then the diagonal crosses the diagonal of the 2-by-2 cells. In the scaled-down version, the diagonal is still a single diagonal starting at (0,n2); otherwise,
* if n is odd, it crosses the corner of the 2-by-2 cells. In the scaled-down version, the diagonal is actually 2 neighboring diagonals starting at (0,n−12) and (0,n+12).

Also, the 2-by-2 cells with values 0 and 1 respectively will also have the form: 

 **Illustration**
```cpp
.*    *.
*.    .*
```
From here we have everything we need to compute the result of the original problem.

Overall, the number of states we have to visit is Θ(logk).

 **Code in Python**
```cpp
import random

cache = {}

def popcount(n):
    res = 0
    while n:
        res += 1
        n &= n - 1
    return res

def solve(n, k):
    if k == 0:
        return 0
    if k == 1:
        return popcount(n) & 1
    if k % 2 == 1:
        t = solve(n, k - 1)
        x = popcount((k - 1) ^ (n + k - 1)) & 1
        
# print(t, x)
        return t + x
    if (n, k) in cache:
        return cache[(n, k)]
    if n % 2 == 0:
        one_cell = 2
        zero_cell = 0
        cnt1 = solve(n // 2, k // 2)
        cnt0 = k // 2 - cnt1
    else:
        one_cell = 0
        zero_cell = 1
        cnt1 = solve(n // 2, k // 2) + solve(n // 2 + 1, k // 2)
        cnt0 = k - cnt1
    res = one_cell * cnt1 + zero_cell * cnt0
    
# print(f"n = {n}, k = {k}, cnt1 = {cnt1}, cnt0 = {cnt0}, one_cell = {one_cell}, zero_cell = {zero_cell}")
    cache[(n, k)] = res
    return res

t = int(input())
for _ in range(t):
    cache.clear()
    n, k = map(int, input().split())
    print(solve(n, k))
```
