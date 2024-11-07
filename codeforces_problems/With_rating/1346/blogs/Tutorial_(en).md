# Tutorial_(en)

First of all, I would like to thank all of the testers: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov"), [darnley](https://codeforces.com/profile/darnley "Grandmaster darnley"), [IlyaLos](https://codeforces.com/profile/IlyaLos "International Master IlyaLos"), [_overrated_](https://codeforces.com/profile/_overrated_ "Master _overrated_"), [SergeyMelnikov](https://codeforces.com/profile/SergeyMelnikov "Master SergeyMelnikov"), [winger](https://codeforces.com/profile/winger "International Grandmaster winger"), [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix"), [infinitepro](https://codeforces.com/profile/infinitepro "Expert infinitepro"), [Sho](https://codeforces.com/profile/Sho "Expert Sho"), [GrandDaddy](https://codeforces.com/profile/GrandDaddy "Expert GrandDaddy"), [bfs.07](https://codeforces.com/profile/bfs.07 "Expert bfs.07"), [spookywooky](https://codeforces.com/profile/spookywooky "Expert spookywooky"). Also huge thanks to co-authors of the contest: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [Roms](https://codeforces.com/profile/Roms "Master Roms"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), [vovuh](https://codeforces.com/profile/vovuh "Master vovuh") and [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo").

I hope you enjoyed participating in the round!

Okay, now for the editorial itself:

[1346A - Color Revolution](../problems/A._Color_Revolution.md "Kotlin Heroes: Episode 4")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1346A - Color Revolution](../problems/A._Color_Revolution.md "Kotlin Heroes: Episode 4")

Notice that all division sizes are determined by the size of the first one. So the sizes are $n_1, n_1 \cdot k, n_1 \cdot k^2, n_1 \cdot k^3$. Their sum is $n_1 + n_1 \cdot k + n_1 \cdot k^2 + n_1 \cdot k^3$. Let's rewrite it as $n_1 \cdot (1 + k + k^2 + k^3)$. Now it's easy to see that $n_1$ can be obtained by dividing $n$ by $(1 + k + k^2 + k^3)$.

Alternatively, you can binary search for $n_1$ because the sum of sizes only increases with the increase of $n_1$.

Overall complexity: $O(1)$ or $O(\log maxn)$ per testcase.

 **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val n1 = n / (1 + k + k * k + k * k * k)
        val n2 = n1 * k
        val n3 = n2 * k
        val n4 = n3 * k
        println("$n1 $n2 $n3 $n4")
    }
}
```
[1346B - Boot Camp](../problems/B._Boot_Camp.md "Kotlin Heroes: Episode 4")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1346B - Boot Camp](../problems/B._Boot_Camp.md "Kotlin Heroes: Episode 4")

The following greedy strategy works: iterate on days from the first one to the last, and place the maximum possible number of lectures during each day so that no constraint breaks. So, during excursion days, we will place $0$ lectures, and during non-excursion days, we will place $\min(k_1, k_2 - prev)$ lectures (where $prev$ is the number of lectures during the previous day).

Why is it optimal? Suppose that there exists a better solution if we didn't place the maximum possible number of lectures during some day $i$. Consider the days $i$ and $i + 1$. If we didn't conduct any lectures during day $i + 1$ (or $i + 1 > n$), then we can increase the number of lectures during day $i$, and the answer becomes better. If there are some lectures during the day $i + 1$, we may move the maximum possible number of them to the day $i$, and the answer won't become worse (but after several such steps it will have the same structure as we described earlier).

 **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k1, k2) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        var m = 0
        var prev = 0
        for (c in s) {
            if (c == '1') {
                prev = minOf(k2 - prev, k1)
                m += prev
            } else {
                prev = 0
            }
        }
        println(m)
    }
}
```
[1346C - Spring Cleaning](../problems/C._Spring_Cleaning.md "Kotlin Heroes: Episode 4")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1346C - Spring Cleaning](../problems/C._Spring_Cleaning.md "Kotlin Heroes: Episode 4")

There are only two possible cases in the problem: we remove all books from all bookcases or at least one bookcase is not removed.

In the first case, the answer is just $n \cdot x$.

In the second case, let's apply the following greedy approach: sort all bookcases and iterate over the number of remaining bookcases from $1$ to $n$. Of course, we want to remain bookcases which contain the least amount of books. Let's maintain the current sum of $i$ first bookcases (in sorted order) $sum$. If $sum > n \cdot k$ then we just need to stop the algorithm. Otherwise, we can distribute all the books of the first $i$ bookcases between all $n$ bookcases to satisfy the conditions of the statement. Then we need to spend $(n-i) \cdot x$ seconds to remove books from other bookcases and if $a_{i-1} > k$ then we need to spend $y$ seconds in addition to distribute remaining books. So we can update the answer with the calculated value.

Time complexity: $O(n \log{n})$.

 **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k, x, y) = readLine()!!.split(" ").map { it.toInt() }
        val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
        val maxSum = k * n.toLong()
        var sum = 0L
        var ans = 0
        var ok = true
        var i = 0
        while (i < n && sum + a[i] <= maxSum) {
            sum += a[i]
            if (ok && a[i] > k) {
                ok = false
                ans = (n - i) * x // can simply drop the rest 
            }
            i++
        }
        ans = if (ok) (n - i) * x // drop the rest
            else minOf(ans, (n - i) * x + y) // drop the rest & rearrange
        println(ans)
    }
}
```
[1346D - Constructing the Dungeon](../problems/D._Constructing_the_Dungeon.md "Kotlin Heroes: Episode 4")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1346D - Constructing the Dungeon](../problems/D._Constructing_the_Dungeon.md "Kotlin Heroes: Episode 4")

The following greedy strategy works: let the number of monsters in room $i$ be the maximum number of coins in tunnels connected to the room $i$. After computing $[a_1, a_2, \dots, a_n]$ according to it, check that all conditions are satisfied. If some condition is not satisfied, then there is no answer; otherwise we obtained a unique answer.

Why is the answer unique, and why does our strategy always find it? Suppose there exists some other answer $[b_1, b_2, \dots, b_n]$ that differs from our answer in index $i$. Let's prove that this answer is either suboptimal, or incorrect:

* if $b_i < a_i$, then the constraint on some tunnel connected to room $i$ is not met;
* if $b_i > a_i$, then we can decrease $b_i$ since it is greater than the weights of all tunnels connected to room $i$, and the total number of monsters will be decreased.
 **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val e = List(m) {
            val (u, v, w) = readLine()!!.split(" ").map { it.toInt() }
            Tun(u - 1, v - 1, w)
        }
        val a = solveDungeon(n, e)
        if (a != null) {
            println("YES")
            println(a.joinToString(" "))
        } else {
            println("NO")
        }
    }
}

private class Tun(val u: Int, val v: Int, val w: Int)

private fun solveDungeon(n: Int, e: List<Tun>): IntArray? {
    val a = IntArray(n)
    for (t in e.sortedByDescending { it.w }) {
        if (a[t.u] == 0) a[t.u] = t.w
        if (a[t.v] == 0) a[t.v] = t.w
        if (t.w != minOf(a[t.u], a[t.v])) return null
    }
    return a
}
```
[1346E - Magic Tricks](../problems/E._Magic_Tricks.md "Kotlin Heroes: Episode 4")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1346E - Magic Tricks](../problems/E._Magic_Tricks.md "Kotlin Heroes: Episode 4")

First, let's design an $O(nq)$ solution with dynamic programming. Let $dp_{a, b}$ be the minimum number of fake swaps required to put the special ball on position $a$ after exactly $b$ swaps. Initially, $dp_{k, 0} = 0$, all other states are unreachable. When we want to process the $i$-th operation, we may choose one of the following options:

* the ball is currently on position $x_i$ and should stay there, then we have to make a fake swap;
* the ball is currently on position $x_i$ and should move to $y_i$, then we don't fake the swap;
* the ball is currently on position $y_i$ and should stay there, then we have to make a fake swap;
* the ball is currently on position $y_i$ and should move to $x_i$, then we don't fake the swap;
* the ball is currently on position unaffected by the swap, so the swap does not change anything (and we don't have to fake it).

For most positions, the value of $dp_{a, b + 1}$ is equal to the value of $dp_{a, b}$. Only positions affected by the swap have their $dp$ value changed, so we may instead get rid of the second state altogether and recalculate $dp$ values for only two positions during each swap.

 **Solution (elizarov)**
```cpp
fun main() {
    val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    val inf = Int.MAX_VALUE - 1
    val s = IntArray(n) { inf }
    s[k - 1] = 0
    repeat(m) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() - 1 }
        val sx = s[x]
        val sy = s[y]
        s[x] = minOf(sx + 1, sy)
        s[y] = minOf(sy + 1, sx)
    }
    println(s.joinToString(" ") { (if (it == inf) -1 else it).toString() })
}
```
[1346F - Dune II: Battle For Arrakis](../problems/F._Dune_II:_Battle_For_Arrakis.md "Kotlin Heroes: Episode 4")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1346F - Dune II: Battle For Arrakis](../problems/F._Dune_II:_Battle_For_Arrakis.md "Kotlin Heroes: Episode 4")

Consider the map in $0$-indexation. If we move the entire army into the cell $(x, y)$ then the answer can be represented as $\sum\limits_{i=0}^{n-1}\sum\limits_{j=0}^{m-1} (|x-i| + |y-j|) \cdot a_{i, j}$. This can be rewritten as $\sum\limits_{i=0}^{n-1}\sum\limits_{j=0}^{m-1} |x-i| \cdot a_{i, j} + \sum\limits_{i=0}^{n-1}\sum\limits_{j=0}^{m-1} |y-j| \cdot a_{i, j}$. Let $xs_i$ be the number of units in the $i$-th row ($xs_i = \sum\limits_{j=0}^{m-1} a_{i, j}$) and $ys_j$ be the number of units in the $j$-th column. Then the last equation can be represented as $\sum\limits_{i=0}^{n-1} |x-i| \cdot xs_i + \sum\limits_{j=0}^{m-1} |y-j| \cdot ys_j$.

So, we see that the problem can be solved independently for rows and columns. Now we have at least $O(nmq)$ solution. How do we speed it up?

Consider the following sequence: $\underbrace{0, 0, \dots, 0}_{xs_0}, \underbrace{1, 1, \dots, 1}_{xs_1}, \dots, \underbrace{n-1, n-1, \dots, n-1}_{xs_{n-1}}$. Let $sum$ be the sum of all $a_{i, j}$. Then we can show that it is always optimally to move the entire army into the cell which has the index $\lfloor\frac{sum-1}{2}\rfloor$ in the sequence above (in other words, it is always optimally to move the entire army to the median). So, if we know the real value of this cell in the sequence above, we can calculate the answer for rows in $O(n)$. And we can find the value of this cell in $O(n)$ (just find the first such $x$ that $\sum\limits_{i=0}^{x} \ge \lfloor\frac{sum-1}{2}\rfloor$.

We can do the same for columns and the array $ys$. And now we have the required point $(x, y)$ and can calculate the answer in $O(n+m)$. So this part costs $O(n+m)$ in total.

And we can process the queries easily: because we only use $a$, $sum$, $xs$ and $ys$ as precalculated values, we can change them according to the query and solve the problem in $O(n+m)$ again.

Total time complexity: $O((n+m)q)$.

 **Solution (elizarov)**
```cpp
import kotlin.math.*

fun main() {
    val (n, m, q) = readLine()!!.split(" ").map { it.toInt() }
    val a = Array(n) { readLine()!!.split(" ").map { it.toInt() }.toIntArray() }
    val rs = LongArray(n) { i -> (0 until m).map { j -> a[i][j].toLong() }.sum() }.toDistSum()
    val cs = LongArray(m) { j -> (0 until n).map { i -> a[i][j].toLong() }.sum() }.toDistSum()
    fun ans() = rs.min()!! + cs.min()!!
    print(ans())
    repeat(q) {
        val (x1, y1, z) = readLine()!!.split(" ").map { it.toInt() }
        val (x, y) = (x1 - 1) to (y1 - 1)
        val d = (z - a[x][y]).toLong()
        for (i in 0 until n) rs[i] += abs(x - i) * d
        for (j in 0 until m) cs[j] += abs(y - j) * d
        a[x][y] = z
        print(" ${ans()}")
    }
}

private fun LongArray.toDistSum(): LongArray {
    val s = LongArray(size)
    var su = 0L
    var wsu = 0L
    var sd = 0L
    var wsd = 0L
    for (i in 0 until size) {
        sd += get(i)
        wsd += (i + 1) * get(i)
    }
    for (i in 0 until size) {
        wsd -= sd
        sd -= get(i)
        s[i] = wsu + wsd
        su += get(i)
        wsu += su
    }
    return s
}
```
[1346G - Two IP Cameras](../problems/G._Two_IP_Cameras.md "Kotlin Heroes: Episode 4")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1346G - Two IP Cameras](../problems/G._Two_IP_Cameras.md "Kotlin Heroes: Episode 4")

Since there are only two cameras, in each triple of interesting moments there exists a pair of them which are photographed by the same camera. For example, let's take three moments $x_1$, $x_2$ and $x_3$, and check three cases:

* $x_1$ and $x_2$ are photographed by the same camera;
* $x_1$ and $x_3$ are photographed by the same camera;
* $x_2$ and $x_3$ are photographed by the same camera.

Suppose moments $a$ and $b$ are photographed by the same camera. Then its period must be a divisor of $b - a$. Let's check all values in $[p_1, p_2, \dots, p_k]$ and try each divisor of $b - a$ as the period for the first camera (and $a$ as the starting moment for it). Numbers not exceeding $10^6$ have up to $240$ divisors, so if we are able to check each divisor in time $O(n + k)$, then we'll obtain a working solution.

To check the given period and starting moment for the first camera, find all interesting moments that aren't photographed by it (let these moments, listed in ascending order, be $[z_1, z_2, \dots, z_m]$). The starting moment for the second camera should be $z_1$, and its period should be a divisor of $z_2 - z_1$, $z_3 - z_2$, ..., $z_m - z_{m - 1}$. We can find the greatest common divisor of these pairwise differences (denote it as $g$), and check every possible period to find the one which divides $g$. If we find a divisor of $g$ in $[p_1, \dots, p_k]$, then it should be the period for the second camera, and the problem is solved.

 **Solution (elizarov)**
```cpp
fun main() {
    val (k, n) = readLine()!!.split(" ").map { it.toInt() }
    val p = readLine()!!.split(" ").map { it.toInt() }
    val x = readLine()!!.split(" ").map { it.toInt() }
    val c = solveCams(n, p, x)
    if (c == null) {
        println("NO")
    } else {
        println("YES")
        println("${c.s1} ${c.p1}")
        println("${c.s2} ${c.p2}")
    }
}

private class Cams(val s1: Int, val p1: Int, val s2: Int, val p2: Int)

private tailrec fun gcd(x: Int, y: Int): Int = if (y == 0) x else gcd(y, x % y)

private fun solveCams(n: Int, p: List<Int>, x: List<Int>): Cams? {
    fun place2(s1: Int, p1: Int): Cams? {
        val f = BooleanArray(n) { j -> (x[j] - s1) % p1 == 0 }
        val i = f.indexOf(false)
        if (i < 0) return Cams(s1, p1, s1, p1)
        val s2 = x[i]
        var j = i + 1
        while (j < n && f[j]) j++
        if (j >= n) return Cams(s1, p1, s2, p[0])
        var p2m = x[j] - s2
        while (++j < n) {
            if (!f[j]) p2m = gcd(p2m, x[j] - s2)
        }
        for (p2 in p) if (p2m % p2 == 0) {
            return Cams(s1, p1, s2, p2)
        }
        return null
    }
    fun tryPlace2(s1: Int, p1m: Int): Cams? {
        for (p1 in p) if (p1m % p1 == 0) {
            place2(s1, p1)?.let { return it }
        }
        return null
    }
    if (n == 2) return Cams(x[0], p[0], x[1], p[0])
    for (t1 in 1..2) {
        tryPlace2(x[0], x[t1] - x[0])?.let { return it }
    }
    return tryPlace2(x[1], x[2] - x[1])
}
```
[1346H - Game with Segments](../problems/H._Game_with_Segments.md "Kotlin Heroes: Episode 4")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms"), preparation: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1346H - Game with Segments](../problems/H._Game_with_Segments.md "Kotlin Heroes: Episode 4")

Let's denote the center of segment $[l, r]$ as $\frac{l + r}{2}$ (in code it's actually $l + r$, so that all calculations are integral). If for some initial segment $[l_i, r_i]$ there exists some terminal segment $[L_i, R_i]$ with the same center, and $R_i - L_i \le r_i - l_i$, then Bob can force the game to end in such a segment by using symmetric strategy: if Alice changes the left endpoint, Bob changes the right endpoint, and vice versa. So Bob can end the game in the number of turns equal to the distance to the longest such terminal segment $[L_i, R_i]$.

Now suppose there is no such segment (or Bob doesn't want to force the game into it, and instead wants to win faster). If there exist two terminal segments $[L_j, R_j]$ and $[L_k, R_k]$ such that $L_j + R_j = l + r - 2$, $L_k + R_k = l + r + 2$, $R_j - L_j \le r - l - 2$ and $R_k - L_k \le r - l - 2$, then Bob can force the game to end up in one of these segments: the first Bob's action should be the same as the first Alice's action, and then he uses symmetrical strategy. If we choose two longest segments $[L_j, R_j]$ and $[L_k, R_k]$ meeting these constraints, then Bob can end the game in $\dfrac{\max(r - R_j + L_j - l, r - R_k + L_k - l)}{2}$ moves.

Note that we only considered segments having center either equal to the center of the initial segment, or different from it exactly by $1$. It turns out that Bob can't force the game into any other segment since Alice also has a symmetric strategy after the first Bob's turn that allows her to stay near the center of the initial segment. So we only have to consider two aforementioned options.

To find the segments we are interested in, we may group all terminal segments by $[L_i + R_i]$, sort them by length in each group, and use binary search to find the segment having the biggest length not exceeding some given number.

 **Solution (tourist)**
```cpp
import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
 
fun main(args: Array<String>) {
    var (tt, n) = readInts()
    var lstart = IntArray(tt)
    var rstart = IntArray(tt)
    for (i in 0 until tt) {
        var (x, y) = readInts()
        lstart[i] = x
        rstart[i] = y
    }
    var l = ArrayList<Int>()
    var r = ArrayList<Int>()
    for (i in 0 until n) {
        var (x, y) = readInts()
        l.add(x)
        r.add(y)
    }
    var order = ArrayList<Int>()
    for (i in 0 until n) {
        order.add(i)
    }
    order.sortWith(compareBy({l[it] + r[it]}, {l[it]}))
    val inf = 787788789
    fun getDistance(L: Int, R: Int) : Int {
        var low = 0
        var high = n
        while (low < high) {
            var mid = (low + high) / 2
            if (l[order[mid]] + r[order[mid]] < L + R ||
                (l[order[mid]] + r[order[mid]] == L + R && l[order[mid]] < L)) {
                low = mid + 1
            } else {
                high = mid
            }
        }
        if (low < n && l[order[low]] + r[order[low]] == L + R) {
            return l[order[low]] - L
        }
        return inf
    }
    var res = IntArray(tt) {-1}
    for (qq in 0 until tt) {
        var L = lstart[qq]
        var R = rstart[qq]
        var a = getDistance(L, R - 2) + 1
        var b = getDistance(L, R)
        var c = getDistance(L + 2, R) + 1
        res[qq] = maxOf(minOf(a, b), minOf(b, c))
        if (res[qq] >= inf) {
            res[qq] = -1
        }
    }
    println(res.joinToString(" "))
}
```
[1346I - Pac-Man 2.0](../problems/I._Pac-Man_2.0.md "Kotlin Heroes: Episode 4")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1346I - Pac-Man 2.0](../problems/I._Pac-Man_2.0.md "Kotlin Heroes: Episode 4")

We will first try to solve two easier versions of this problem. Let's denote $\sum a_i$ as $P$ (the total number of pellets in the game world).

Version 1: there is only one goal with $C_i = P$.

That's quite an easy one, we should visit all the vertices of the graph in minimum number of steps. This can be done with bitmask dynamic programming similar to searching for the Hamiltonian path: let $dp_{cur, mask}$ be the minimum number of steps to visit vertices from $mask$ and end up in vertex $cur$, if we start from vertex $s$. We are interested in states having full masks, and the minimum of their values is the minimum number of steps required to visit all vertices.

Version 2: all goals have $C_i \bmod P = 0$.

In this version, we have to traverse the whole graph exactly $\frac{C_i}{P}$ times. Let's construct a new weighted graph consisting of $n$ vertices, where the arc from vertex $x$ to vertex $y$ has weight equal to the minimum number of steps required to start in vertex $x$, visit all vertices in the graph, and end up in vertex $y$. To calculate the weights of these arcs, we can use the dynamic programming approach similar to the solution of Version 1 (the main difference is that we try all starting vertices instead of just $s$).

After we construct this new graph, our problem is to find the shortest path consisting of exactly $\frac{C_i}{P}$ edges in it. This problem can be solved with an approach similar to fast matrix exponentiation (you may read about it here: [https://cp-algorithms.com/graph/fixed_length_paths.html](https://codeforces.com/https://cp-algorithms.com/graph/fixed_length_paths.html)) in $O(n^3 \log C)$ for each query; though since we have up to $5000$ queries, we should speed it up by precalculating $[M, M^2, M^4, M^8, \dots]$ (where $M$ is the matrix we use) in $O(n^3 \log C)$ and then answer each query by $O(\log C)$ matrix-vector multiplications instead of matrix-matrix multiplications, so each query is answered in time $O(n^2 \log C)$. Note that this approach gives us the shortest path with $\frac{C_i}{P}$ edges for each last vertex in the path, we will need it later to solve the original problem.

Back to the original version: no additional constraints on $C_i$. 

Let $F = \lfloor\frac{C_i}{P}\rfloor$ and $R = C_i \bmod P$. In order to obtain $C_i$ pellets, we have to traverse the whole graph $F$ times, and then collect at least $R$ pellets by traversing some of the vertices. Let's iterate on the vertex $v$ where we will end up after $F$ full traversals. Solution of Version 2 allows us to calculate the number of steps required to perform full traversals and end up in vertex $v$, so we somehow need to compute the minimum number of steps required to collect at least $R$ pellets starting from vertex $v$.

The dynamic programming used to build the auxiliary graph also calculates the minimum number of steps required to visit each subset of vertices, starting from the chosen vertex. So, for each vertex $v$ and number of steps $t$ (which is up to $n^2$), we may store the maximum number of pellets that we can collect in $t$ steps starting from $v$ — which allows us to answer each query in something like $O(n^3 + n^2 \log C)$.

 **Solution (Ne0n25)**
```cpp
import kotlin.math.abs

fun main() {
    val INF = 1e9.toInt()
    val INF64 = 1e18.toLong()
    val LOG = 60
    var (n, m, q, s) = readLine()!!.split(' ').map { it.toInt() }
    s--
    val a = readLine()!!.split(' ').map { it.toInt() }
    
    val summask = LongArray(1 shl n) { 0 }
    for (mask in 0 until (1 shl n)) {
        for (i in 0 until n) {
            if ((mask and (1 shl i)) > 0)
                summask[mask] += a[i].toLong()
        }
    }

    val d = Array(n) { IntArray(n) { INF } }
    for (i in 0 until m) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() }
        d[x - 1][y - 1] = 1
    }
    
    val C = readLine()!!.split(' ').map { it.toLong() }

    for (k in 0 until n) {
        for (i in 0 until n) {
            for (j in 0 until n)
                d[i][j] = minOf(d[i][j], d[i][k] + d[k][j])
        }
    }

    val dp = Array(n) { Array(n) { IntArray(1 shl n) { INF } } }
    for (st in 0 until n) {
        dp[st][st][1 shl st] = 0

        for (mask in 0 until (1 shl n)) {
            for (i in 0 until n) {
                if ((mask and (1 shl i)) == 0)
                    continue
                for (j in 0 until n) {
                    if ((mask and (1 shl j)) > 0)
                        continue
                    dp[st][j][mask or (1 shl j)] =
                            minOf(dp[st][j][mask or (1 shl j)], dp[st][i][mask] + d[i][j])
                }
            }
        }
    }

    val bst = Array(n) { LongArray(n * n) { 0 } }
    for (i in 0 until n) {
        for (mask in 0 until (1 shl n)) {
            if ((mask and (1 shl i)) > 0) {
                for (j in 0 until n) {
                    if (dp[i][j][mask] != INF)
                        bst[i][dp[i][j][mask]] = maxOf(bst[i][dp[i][j][mask]], summask[mask])
                }
            }
        }
    }

    val steps = Array(LOG) { Array(n) { LongArray(n) { INF64 } } }
    for (i in 0 until n) {
        for (j in 0 until n)
            steps[0][i][j] = dp[i][j][(1 shl n) - 1].toLong()
    }

    for (t in 1 until LOG) {
        for (i in 0 until n) {
            for (j in 0 until n) {
                for (k in 0 until n)
                    steps[t][i][j] = minOf(steps[t][i][j], steps[t - 1][i][k] + steps[t - 1][k][j])
            }
        }
    }

    for (qr in 0 until q) {
        val sum = summask[(1 shl n) - 1]
        val need = C[qr] / sum

        var cur = LongArray(n) { INF64 }
        cur[s] = 0

        for (t in 0 until LOG - 1) {
            if ((need and (1L shl t)) > 0) {
                val ncur = LongArray(n) { INF64 }
                for (i in 0 until n) {
                    for (j in 0 until n)
                        ncur[i] = minOf(ncur[i], steps[t][j][i] + cur[j])
                }
                cur = ncur
            }
        }

        var ans = INF64
        for(i in 0 until n) {
            val lft = C[qr] % sum
            for (j in 0 until n * n) {
            	if (bst[i][j] >= lft)
            		ans = minOf(ans, cur[i] + j);
            }
        }

        println(ans)
    }
}
```
