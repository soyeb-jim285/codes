# Kotlin_Heroes_Editorial_(en)

[1170A - Three Integers Again](../problems/A._Three_Integers_Again.md "Kotlin Heroes: Episode 1")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

Solution: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov")

 **Tutorial**
### [1170A - Three Integers Again](../problems/A._Three_Integers_Again.md "Kotlin Heroes: Episode 1")

We always can consider that the numbers in the input are x=a+b and y=b+c. If x>y let's swap them. Note, that a+b+c=a+b+(y−b)=a+y. That's why it's optimal to minimize value of a. So the value of a can always be 1. Then we can restore b=x−a, and c=y−b.

 **Solution**
```cpp
fun main() {
    val q = readLine()!!.toInt()
    repeat(q) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }.sorted()
        println("1 ${x - 1} ${y - x + 1}")
    }
}
```
[1170B - Bad Days](../problems/B._Bad_Days.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Solution: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    var m1 = 0
    var m2 = 0
    var c = 0
    for (x in a) {
        if (m2 > x) {
            c++
        }
        when {
            x > m1 -> {
                m2 = m1
                m1 = x
            }
            x > m2 -> {
                m2 = x
            }
        }
    }
    println(c)
}
```
[1170C - Minus and Minus Give Plus](../problems/C._Minus_and_Minus_Give_Plus.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Solution: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
fun main() {
    val k = readLine()!!.toInt()
    repeat(k) {
        val s = readLine()!!
        val t = readLine()!!
        println(if (solve(s, t)) "YES" else "NO")
    }
}

private fun solve(s: String, t: String): Boolean {
    var i = 0
    var j = 0
    while (i < s.length && j < t.length) {
        when (s[i]) {
            t[j] -> {}
            '+' -> return false
            else -> { // '-' -> '+'
                i++
                if (i >= s.length || s[i] != '-') return false
            }
        }
        i++
        j++
    }
    return i == s.length && j == t.length
}
```
[1170D - Decoding of Integer Sequences](../problems/D._Decoding_of_Integer_Sequences.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Solution: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov")

 **Tutorial**
### [1170D - Decoding of Integer Sequences](../problems/D._Decoding_of_Integer_Sequences.md "Kotlin Heroes: Episode 1")

The number of occurrences of '-1' is exactly $n$ (the number of sequences). Construct a linked list $l$ containing all the numbers from $0$ to $n-1$ (i.e. all the sequence indices) and $n$ empty sequences. Now process the input sequence, each time you take an element $b_i$ append it to the corresponding sequence. The index of the corresponding sequence is exactly the value of the current element in $l$ (use an iterator). If $b_i=-1$ then the corresponding sequence is over and just remove from $l$ the current element and move to the next (or to the first if there is no next element). If $b_i \ne -1$ then simply move to the next (or to the first if there is no next element). 

 **Solution**
```cpp
import java.util.*

fun main() {
    val m = readLine()!!.toInt()
    val b = readLine()!!.split(" ").map { it.toInt() }
    val n = b.count { it == -1 }
    val a = Array(n) { ArrayList<Int>() }
    val ix = LinkedList<Int>((0 until n).toList())
    var iter = ix.iterator()
    for (x in b) {
        if (!iter.hasNext()) iter = ix.iterator()
        val i = iter.next()
        if (x == -1) {
            iter.remove()
        } else {
            a[i].add(x)
        }
    }
    println(n)
    println(a.joinToString("n") {
        "${it.size} ${it.joinToString(" ")}"
    })
}
```
[1170E - Sliding Doors](../problems/E._Sliding_Doors.md "Kotlin Heroes: Episode 1")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

Solution: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
fun main() {
    val (n, m) = readInts()
    val a = readInts().toIntArray()
    val q = readInt()
    val b = IntArray(4 * a.size)

    fun buildTree(il: Int, ir: Int, p: Int): Int {
        val s = if (il == ir) {
            a[il]
        } else {
            val im = (il + ir) / 2
            buildTree(il, im, 2 * p + 1) + buildTree(im + 1, ir, 2 * p + 2)
        }
        b[p] = s
        return s
    }

    buildTree(0, n - 1, 0)
    val ans = List(q) {
        val w = readInts().drop(1) + (m + 1) // sentinel
        if (solveDoors(n, m, b, w)) "YES" else "NO"
    }.joinToString("n")
    println(ans)
}

private fun solveDoors(n: Int, m: Int, b: IntArray, w: List<Int>): Boolean {
    var pp = 0
    var i = 0
    var rem = 0

    fun queryTree(il: Int, ir: Int, p: Int, i: Int): Int {
        if (il == i && rem >= b[p]) {
            rem -= b[p]
            return ir + 1
        }
        if (il == ir) return i
        val im = (il + ir) / 2
        if (i > im) return queryTree(im + 1, ir, 2 * p + 2, i)
        val j = queryTree(il, im,2 * p + 1, i)
        if (j <= im) return j
        return queryTree(im + 1, ir,2 * p + 2, im + 1)
    }

    for (cp in w) {
        rem = cp - pp - 1
        i = queryTree(0, n - 1, 0, i)
        if (i >= n) return true
        pp = cp
    }
    return false
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map { it.toInt() }
```
[1170F - Wheels](../problems/F._Wheels.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh"), [pashka](https://codeforces.com/profile/pashka "Grandmaster pashka")

Solution: [Benq](https://codeforces.com/profile/Benq "Legendary Grandmaster Benq")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
import java.util.*

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve() {
    val (n,m,k) = nextInts()
    var A = nextLongs()
    var a = arrayListOf<Long>()
    a.addAll(A)
    a.sort()
    var ans = (1e18).toLong()
    var ind = 0
    var above:Long = 0
    var below:Long = 0
    for (i in 0..m-1) above += a[i]-a[0]
    for (i in 0..n-m) {
        val des = i+(m-1)/2
        while (ind < des) { // try to get closer to median if possible
            if (below+(a[ind+1]-a[ind])*(ind+1-i) <= k) {
                below += (a[ind+1]-a[ind])*(ind+1-i)
                above -= (a[ind+1]-a[ind])*(i+m-1-ind) // ind+1 to i+m-1
                ind ++
            } else break
        }
        assert (k >= below)
        if (ind < des) {
            var oops: Long = (k-below)/(ind+1-i)
            ans = minOf(ans,below+above-(i+m-1-ind)*oops+(ind+1-i)*oops)
            assert(i+m-1-ind >= ind+1-i)
        } else ans = minOf(ans,above+below)
        if (i < n-m) {
            below -= a[ind]-a[i]
            above += a[i+m]-a[ind]
        }
    }
    print(ans)
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) solve()
}
```
[1170G - Graph Decomposition](../problems/G._Graph_Decomposition.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Solution: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov")

 **Tutorial**
### [1170G - Graph Decomposition](../problems/G._Graph_Decomposition.md "Kotlin Heroes: Episode 1")

If there exists vertex with the odd degree then the answer is "NO", otherwise the answer is "YES". Let's find a way to constuct it.

Almost all we need is to run euler cycle finding for each component of the given graph. It can be done with the following code: 


```cpp
  
dfs(v) {  
    while (v.hasAdjacentVertices) {  
        to = v.anyAdjacentVertex  
        v.removeOneEdge(to)  
        to.removeOneEdge(v)  
        dfs(to)  
    }  
    path.push(v)  
}  

```
In the part when we pushes a new vertex into the path we should try to restore a new cycle. How do we check and do it? Let's maintain an array used: usedv is true when the vertex v is in path. When we try to add the vertex v that already in path (usedv is true), let's extract the new simple cycle instead of adding this vertex. Let's pop out all vertices u we pushed until the last vertex equals to v (and don't forget to set usedu to false). Otherwise let's add this vertex into the list and set usedv to true.

 **Solution**
```cpp
  
  
fun main() {
    solveEuler()
}

class E(
    val y: Int,
    var c: Int = 0
)

class Edges {
    private val e = HashMap<Int, E>(2)
    private val c = ArrayList<E>(2)
    private var first = 0

    fun degree() = c.sumBy { it.c }

    fun add(y: Int) {
        val cur = e.getOrPut(y) { E(y) }
        if (cur.c == 0) c.add(cur)
        cur.c++
    }

    fun first() = c[first].y

    fun hasNext() = first < c.size

    fun rem(y: Int) {
        val cur = e.getValue(y)
        if (--cur.c == 0) {
            while (first < c.size && c[first].c == 0) first++
        }
    }
}

private fun solveEuler() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val g = Array(n) { Edges() }
    repeat(m) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() - 1 }
        g[x].add(y)
        g[y].add(x)
    }
    if (!g.all { it.degree() % 2 == 0 }) {
        println("NO")
    } else {
        val c = ArrayList<List<Int>>()
        var start = 0
        val v = IntArray(n) { -1 }
        while (true) {
            while (start < n && !g[start].hasNext()) start++
            if (start >= n) break
            val list = ArrayList<Int>()
            var x = start
            while (true) {
                v[x] = list.size
                list.add(x)
                val y = g[x].first()
                g[x].rem(y)
                g[y].rem(x)
                if (y == start) break
                if (v[y] >= 0) {
                    val d = list.subList(v[y], list.size)
                    c.add(d.toList())
                    for (z in d) v[z] = -1
                    d.clear()
                }
                x = y
            }
            c.add(list)
            for (z in list) v[z] = -1
        }
        println("YES")
        println(c.size)
        val ans = c.joinToString("n") { list ->
            "${list.size + 1} ${list.joinToString(" ") { (it + 1).toString() }} ${list[0] + 1}"
        }
        println(ans)
    }
}

```
[1170H - Longest Saw](../problems/H._Longest_Saw.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Solution: [pashka](https://codeforces.com/profile/pashka "Grandmaster pashka")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

/**
 * @author: pashka
 */

fun solve(a: IntArray): IntArray {
    val n = a.size
    var l = 0
    var r = a.size + 1
    var best = IntArray(0)
    while (r > l + 1) {
        var m = (l + r) / 2
        val c = IntArray(m)
        for (i in 0 until m) {
            if (i % 2 == 0) {
                c[i] = a[i / 2]
            } else {
                c[i] = a[n - m / 2 + i / 2]
            }
        }
        var ok = true
        for (i in 0 until m - 1) {
            if (c[i] == c[i + 1]) {
                ok = false
            }
        }
        if (!ok && m % 2 == 0) {
            for (i in 0 until m step 2) {
                val t = c[i]
                c[i] = c[i + 1]
                c[i + 1] = t
            }
            ok = true
            for (i in 0 until m - 1) {
                if (c[i] == c[i + 1]) {
                    ok = false
                }
            }
        }
        if (ok) {
            l = m
            best = c
        } else {
            r = m
        }
    }
    return best
}

private fun solveTest() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    a.sort()
    val best1 = solve(a)
    a.reverse()
    val best2 = solve(a)
    val best = if (best1.size > best2.size) best1 else best2
    println(best.size)
    println(best.joinToString(" "))
}

fun main() {
    val n = readLine()!!.toInt()
    for (i in 0 until n) {
        solveTest()
    }
}
```
[1170I - Good Subsets](../problems/I._Good_Subsets.md "Kotlin Heroes: Episode 1")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Solution: [pashka](https://codeforces.com/profile/pashka "Grandmaster pashka")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

/**
 * @author: pashka
 */

val MOD = 998244353L

internal class SegmentTree(private val size: Int) {

    private val sum = LongArray(4 * size)
    private val add = LongArray(4 * size)
    private val mult = LongArray(4 * size)

    public fun add(l: Int, r: Int, c: Long) {
        add(0, 0, size, l, r, c)
    }

    private fun add(n: Int, ll: Int, rr: Int, l: Int, r: Int, c: Long) {
        push(n, ll, rr)
        if (ll >= l && rr <= r) {
            add[n] += c
            sum[n] += c * (rr - ll)
            add[n] %= MOD
            sum[n] %= MOD
        } else if (ll >= r || l >= rr) {
            return
        } else {
            val m = (ll + rr) / 2
            add(n * 2 + 1, ll, m, l, r, c)
            add(n * 2 + 2, m, rr, l, r, c)
            sum[n] = (sum[2 * n + 1] + sum[2 * n + 2]) % MOD
        }
    }

    public fun mult(l: Int, r: Int, c: Long) {
        mult(0, 0, size, l, r, c)
    }

    private fun mult(n: Int, ll: Int, rr: Int, l: Int, r: Int, c: Long) {
        push(n, ll, rr)
        if (ll >= l && rr <= r) {
            mult[n] *= c
            add[n] *= c
            sum[n] *= c
            mult[n] %= MOD
            add[n] %= MOD
            sum[n] %= MOD
        } else if (ll >= r || l >= rr) {
            return
        } else {
            val m = (ll + rr) / 2
            mult(n * 2 + 1, ll, m, l, r, c)
            mult(n * 2 + 2, m, rr, l, r, c)
            sum[n] = (sum[2 * n + 1] + sum[2 * n + 2]) % MOD
        }
    }

    private fun push(n: Int, ll: Int, rr: Int) {
        if (rr - ll > 1) {
            val m = ll + rr shr 1
            for (i in 1..2) {
                mult[2 * n + i] *= mult[n]
                add[2 * n + i] *= mult[n]
                sum[2 * n + i] *= mult[n]
                add[2 * n + i] += add[n]
                sum[2 * n + i] += add[n] * (if (i == 1) (m - ll) else (rr - m))
                mult[2 * n + i] %= MOD
                add[2 * n + i] %= MOD
                sum[2 * n + i] %= MOD
            }
        }
        add[n] = 0
        mult[n] = 1
    }

    public fun sum(l: Int, r: Int): Long {
        return sum(0, 0, size, l, r)
    }

    private fun sum(n: Int, ll: Int, rr: Int, l: Int, r: Int): Long {
        push(n, ll, rr)
        if (ll >= l && rr <= r) {
            return sum[n]
        } else if (ll >= r || l >= rr) {
            return 0
        } else {
            val m = (ll + rr) / 2
            return (sum(n * 2 + 1, ll, m, l, r) + sum(n * 2 + 2, m, rr, l, r)) % MOD
        }
    }
}

private fun solve() {
    val n = nextInt()
    val l = IntArray(n)
    val r = IntArray(n)
    for (i in 0 until n) {
        l[i] = nextInt()
        r[i] = nextInt()
    }
    var all = l + r
    all.sort()
    var m = 1
    for (i in 1 until all.size) {
        if (all[i] != all[m - 1]) {
            all[m] = all[i]
            m++
        }
    }
    all = all.copyOf(m)
    for (i in 0 until n) {
        l[i] = all.binarySearch(l[i])
        r[i] = all.binarySearch(r[i])
    }
    val c = IntArray(2 * m)
    for (i in 0 until n) {
        c[l[i] * 2]++
        c[r[i] * 2 + 1]--
    }
    for (i in 1 until 2 * m) {
        c[i] += c[i - 1]
    }
    val q = IntArray(2 * m)
    var mm = 0
    for (i in 0 until 2 * m) {
        if (c[i] > 0) {
            q[i] = mm
            mm++
        }
    }
    m = mm
    for (i in 0 until n) {
        l[i] = q[2 * l[i]]
        r[i] = q[2 * r[i]]
    }
    var p = List(n) { x: Int -> x }.sortedBy { x: Int -> r[x] }
    val st = SegmentTree(m + 1)
    st.add(0, 1, 1)
    for (i in p) {
        st.mult(0, l[i], 2)
        val x = st.sum(l[i], r[i] + 2)
        st.add(r[i] + 1, r[i] + 2, x)
    }
    out.println(st.sum(m, m + 1))
}

fun main() {
    solve()
    out.close()
}

private var br = BufferedReader(InputStreamReader(System.`in`))
private var st: StringTokenizer? = null
private var out = PrintWriter(System.out)

@Throws(IOException::class)
private fun next(): String {
    while (st == null || !st!!.hasMoreTokens()) {
        st = StringTokenizer(br.readLine())
    }
    return st!!.nextToken()
}

@Throws(IOException::class)
private fun nextInt(): Int {
    return Integer.parseInt(next())
}
```
