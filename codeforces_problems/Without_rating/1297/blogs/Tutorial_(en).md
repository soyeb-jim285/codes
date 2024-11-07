# Tutorial_(en)

[1297A - Likes Display](../problems/A._Likes_Display.md "Kotlin Heroes: Episode 3")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        when (val n = readLine()!!.toInt()) {
            in 0..999 -> println(n)
            in 1000..999_499 -> println("${(n + 500) / 1000}K")
            else -> println("${(n + 500_000) / 1_000_000}M")
        }
    }
}
```
[1297B - Cartoons](../problems/B._Cartoons.md "Kotlin Heroes: Episode 3")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    class M(val a: Int, val b: Int)
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ms = Array(n) {
            readLine()!!.split(" ").map { it.toInt() }.let { (a, b) -> M(a, b) }
        }
        var ans = -1
        fun check(x: Int) {
            if (ms.count { m -> x in m.a..m.b } == 1) ans = x
        }
        for (m in ms) {
            for (d in -1..1) {
                check(m.a + d)
                check(m.b + d)
            }
        }
        println(ans)
    }
}
```
[1297C - Dream Team](../problems/C._Dream_Team.md "Kotlin Heroes: Episode 3")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val s = a.withIndex().sortedByDescending { it.value }
        val i = s.indexOfLast { it.value > 0 }
        val j = s.indexOfFirst { it.value < 0 }
        val c = CharArray(n) { '0' }
        for (k in 0 until i) c[s[k].index] = '1'
        if (j >= 0 && -s[j].value < s[i].value) {
            c[s[i].index] = '1'
            c[s[j].index] = '1'
        }
        val sum = s.sumBy { if (c[it.index] == '1') it.value else 0 }
        println(sum)
        println(c.joinToString(""))
    }
}
```
[1297D - Bonus Distribution](../problems/D._Bonus_Distribution_.md "Kotlin Heroes: Episode 3") 

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val a = readLine()!!.split(" ").map { it.toInt() }
        val s = a.withIndex().sortedByDescending { it.value }
        val d = IntArray(n)
        var rem = k
        for (p in 1 until n) {
            val i = s[p - 1].index
            val j = s[p].index
            d[j] = minOf(a[i] + d[i] - a[j] - 1, rem)
            rem -= d[j]
        }
        val add = rem / n
        val ext = rem % n
        for (p in 0 until n) d[s[p].index] += add + if (p < ext) 1 else 0
        println(d.joinToString(" "))
    }
}
```
[1297E - Modernization of Treeland](../problems/E._Modernization_of_Treeland.md "Kotlin Heroes: Episode 3")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
//        readLine() // skip empty line
        solveCase()
    }
}

private fun solveCase() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val gf = IntArray(n) { -1 }
    val gy = IntArray(2 * n)
    val gn = IntArray(2 * n)
    var ec = 0
    fun edge(x: Int, y: Int) {
        gy[ec] = y
        gn[ec] = gf[x]
        gf[x] = ec++
    }
    repeat(n - 1) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() - 1 }
        edge(x, y)
        edge(y, x)
    }
    val v = BooleanArray(n)
    val q = IntArray(n)
    var h = 0
    var t = 0
    fun enqueue(x: Int) {
        q[t++] = x
        v[x] = true
    }
    enqueue(0)
    var lc = 1
    while (lc < k && h < t) {
        val x = q[h++]
        var i = gf[x]
        var cc = 0
        while (i >= 0 && lc < k) {
            val y = gy[i]
            if (!v[y]) {
                enqueue(y)
                if (cc++ > 0) lc++
            }
            i = gn[i]
        }
        if (x == 0 && cc == 1) lc++
    }
    if (lc < k) {
        println("No")
        return
    }
    println("Yes")
    println(v.count { it })
    println(v.withIndex().filter { it.value }.joinToString(" ") { (it.index + 1).toString() })
}
```
[1297F - Movie Fan](../problems/F._Movie_Fan.md "Kotlin Heroes: Episode 3")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
//        readLine() // skip empty line
        solveCase()
    }
}

private data class Mv(val i: Int, val a: Int, val b: Int, var t: Int = 0) : Comparable<Mv> {
    override fun compareTo(other: Mv): Int = if (b != other.b) b.compareTo(other.b) else i.compareTo(other.i)
}

private fun solveCase() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val d = Array(n) { i ->
        readLine()!!.split(" ").map { it.toInt() }.let { (a, b) -> Mv(i, a, b) }
    }
    d.sortBy { it.a }
    var t = 0
    val w = TreeSet<Mv>()
    fun advance(to: Int) {
        while (t < to && !w.isEmpty()) {
            repeat(minOf(w.size, m)) {
                val v = w.first()
                v.t = t
                w -= v
            }
            t++
        }
        t = to
    }
    for (v in d) {
        advance(v.a)
        w += v
    }
    advance(Int.MAX_VALUE)
    d.sortBy { it.i }
    println(maxOf(0, d.map { it.t - it.b }.max()!!))
    println(d.joinToString(" ") { it.t.toString() })
}
```
[1297G - M-numbers](../problems/G._M-numbers.md "Kotlin Heroes: Episode 3")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    val (m, k) = readLine()!!.split(" ").map { it.toInt() }
    val f = factor(m) ?: run {
        println(-1)
        return
    }
    val dp = HashMap<Long,Long>()
    val dig = IntArray(100_000)
    fun count(nd: Int, p: Long = -1): Long {
        val e = f[0] + (f[1] shl 5) + (f[2] shl 10) + (f[3] shl 15) + (nd.toLong() shl 20)
        if (nd == 0) return if (e == 0L) 1 else 0
        if (p == -1L) dp[e]?.let { return it }
        var cnt = 0L
        for (d in 1..9) {
            dig[nd - 1] = d
            val df = factors[d]
            for (i in 0..3) f[i] -= df[i]
            if (f.all { it >= 0 }) {
                val nc = count(nd - 1)
                if (p >= 0 && cnt + nc > p) return count(nd - 1, p - cnt)
                cnt += nc
            }
            for (i in 0..3) f[i] += df[i]
        }
        dp[e] = cnt
        return cnt
    }
    var num = 1L
    var nd = 1
    while (count(nd) <= k - num) num += count(nd++)
    check(count(nd, k - num) == 1L)
    println(dig.take(nd).reversed().joinToString(""))
}

private val pr = listOf(2, 3, 5, 7)
private val factors = Array(10) { factor(it)!! }

private fun factor(m: Int): IntArray? {
    val f = IntArray(4)
    if (m <= 1) return f
    var rem = m
    for ((i, p) in pr.withIndex()) {
        while (rem % p == 0) {
            rem /= p
            f[i]++
        }
    }
    return f.takeIf { rem == 1 }
}
```
[1297H - Paint the String](../problems/H._Paint_the_String.md "Kotlin Heroes: Episode 3")

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    class Ans(val a: String, val m: String)
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val n = s.length
        val dp = Array(n) { i -> arrayOfNulls<Ans>(i + 1) }
        dp[0][0] = Ans(s.substring(0, 1), "R")
        var best = Ans(s, "")
        fun updateBest(p: Ans) {
            if (p.a <= best.a) best = p
        }
        fun updateDP(i: Int, j: Int, p: Ans) {
            val cur = dp[i][j]
            if (cur == null || p.a < cur.a) dp[i][j] = p
        }
        for (i in 1 until n) {
            for (j in 0 until i) {
                val p = dp[i - 1][j] ?: continue
                updateDP(i, j, Ans(p.a + s[i], p.m + "R"))
                if (j >= i - j) continue
                if (s[i] == p.a[j]) updateDP(i, j + 1, Ans(p.a, p.m + "B"))
                if (s[i] < p.a[j]) updateBest(Ans(p.a, p.m + "B".repeat(n - i)))
            }
        }
        for (p in dp[n - 1]) if (p != null) updateBest(p)
        println(best.m)
    }
}
```
[1297I - Falling Blocks](../problems/I._Falling_Blocks.md "Kotlin Heroes: Episode 3")

Authors: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix"), [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

 **Editorial**Tutorial is loading... **Solution (elizarov)**
```cpp
import java.util.*

private class Block(val l: Int, val r: Int) : Comparable<Block> {
    fun cover(c: Block) = l <= c.l && r >= c.r
    override fun compareTo(other: Block): Int = l.compareTo(other.l)
}

fun main() {
    val (n, d) = readLine()!!.split(" ").map { it.toInt() }
    val bh = arrayOfNulls<TreeSet<Block>>(n + 1) // blocks by height
    // Segment tree
    val tt = BooleanArray(4 * d) // terminal(leaf) node in segment tree
    val th = IntArray(4 * d) // max height in this segment
    tt[0] = true
    // Segment tree functions
    fun findMax(b: Block, i: Int, tl: Int, tr: Int): Int {
        if (tt[i] || b.l <= tl && b.r >= tr) return th[i]
        val tm = (tl + tr) / 2
        return maxOf(
            if (b.l <= tm) findMax(b, 2 * i + 1, tl, tm) else 0,
            if (b.r > tm) findMax(b, 2 * i + 2, tm + 1, tr) else 0
        )
    }
    fun setLeaf(i: Int, h: Int) {
        tt[i] = true
        th[i] = h
    }
    fun place(b: Block, h: Int, i: Int, tl: Int, tr: Int) {
        if (b.l <= tl && b.r >= tr) return setLeaf(i, h)
        val tm = (tl + tr) / 2
        val j1 = 2 * i + 1
        val j2 = 2 * i + 2
        if (tt[i]) { // split node
            tt[i] = false
            setLeaf(j1, th[i])
            setLeaf(j2, th[i])
        }
        if (b.l <= tm) place(b, h, j1, tl, tm)
        if (b.r > tm) place(b, h, j2, tm + 1, tr)
        th[i] = maxOf(th[j1], th[j2])
    }
    // Simulate each incoming block & print answer
    var bc = 0
    repeat(n) {
        val b = readLine()!!.split(" ").map { it.toInt() }.let{ (l, r) -> Block(l, r) }
        var maxH = findMax(b, 0, 1, d)
        while (true) {
            val bs = bh[maxH] ?: break
            var floor = bs.floor(b)
            if (floor != null && floor.r < b.l) floor = bs.higher(floor)
            if (floor == null) floor = bs.first()
            check(floor.l <= b.r)
            val list = bs.tailSet(floor).takeWhile { it.l <= b.r }
            if (!b.cover(list.first()) || !b.cover(list.last())) break
            for (c in list) bs -= c // don't use bs.removeAll(list)
            bc -= list.size
            maxH--
        }
        val h = maxH + 1
        place(b, h, 0, 1, d)
        val bs = bh[h] ?: run { TreeSet<Block>().also { bh[h] = it } }
        bs += b
        println(++bc)
    }
}
```
