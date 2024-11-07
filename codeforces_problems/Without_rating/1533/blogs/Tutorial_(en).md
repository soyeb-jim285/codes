# Tutorial_(en)

First of all, I would like to thank all testers of the round: [PavelKunyavskiy](https://codeforces.com/profile/PavelKunyavskiy "International Grandmaster PavelKunyavskiy"), [IlyaLos](https://codeforces.com/profile/IlyaLos "International Master IlyaLos"), [Vladik](https://codeforces.com/profile/Vladik "Candidate Master Vladik"), [ashmelev](https://codeforces.com/profile/ashmelev "International Grandmaster ashmelev"), [nooinenoojno](https://codeforces.com/profile/nooinenoojno "Expert nooinenoojno"), [AlexFetisov](https://codeforces.com/profile/AlexFetisov "Master AlexFetisov"). Also huge thanks to co-authors of the contest: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [vovuh](https://codeforces.com/profile/vovuh "Master vovuh") and [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo").

I hope you enjoyed participating in the round!

Okay, now for the editorial itself:

[1533A - Travel to Bertown](../problems/A._Travel_to_Bertown.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1533A - Travel to Bertown](../problems/A._Travel_to_Bertown.md "Kotlin Heroes: Episode 7")

To solve this problem, we can use an approach similar to finding the maximum element in the array. Initialize the answer with 0, then run a loop for i from 1 to n. In this loop, if k belongs to the segment [li,ri], then the answer should be updated with the value ri−k+1.

 **Solution (Neon)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
  val (n, k) = readLine()!!.split(" ").map { it.toInt() }
  var ans = 0
  repeat(n) {
    val (l, r) = readLine()!!.split(" ").map { it.toInt() }
    if (l <= k) ans = maxOf(ans, r - k + 1)
  }
  println(ans)
}
```
[1533B - Nearest Point Function](../problems/B._Nearest_Point_Function.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**Tutorial is loading... **Solution (vovuh)**
```cpp
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val x = readLine()!!.split(" ").map { it.toInt() }
        var ans = false
        for (i in 1 until n) {
            if ((x[i] - x[i - 1]) % 2 == 0) {
                ans = true
            }
        }
        println(if (ans) "YES" else "NO")
    }
}
```
[1533C - Sweets](../problems/C._Sweets.md "Kotlin Heroes: Episode 7")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
  val (n, k) = readLine()!!.split(" ").map { it.toInt() }
  val s = readLine()!!
  val used = BooleanArray(n) { false }
  var cnt = s.count({ it == '1'})
  var pos = 0
  while (cnt > 0) {
    used[pos] = true
    if (s[pos] == '1') --cnt
    if (cnt == 0) break
    var lft = k
    while (lft > 0) {
      pos = (pos + 1) % n
      if (!used[pos]) --lft;
    }
  }
  println(used.count({ it }))
}
```
[1533D - String Searching](../problems/D._String_Searching.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1533D - String Searching](../problems/D._String_Searching.md "Kotlin Heroes: Episode 7")

To answer a query, it is enough to iterate over a character we delete from the string given in the query, and then check whether the resulting string is in the given set of strings (which should be stored in some associative data structure, for example, in a Set). Note that if deleting different positions can lead to identical strings, you have to count these strings once (i. e., if the query is aaa, then the string aa should be counted $1$ time, not $3$); it can be done by storing all strings we can obtain by deleting one character in another Set, since it removes duplicate elements.

 **Solution (Neon)**
```cpp
fun main() {
  val (n, m) = readLine()!!.split(" ").map { it.toInt() }
  val used = Array(n) { readLine()!! }.toSet()
  repeat(readLine()!!.toInt()) {
    val t = readLine()!!
    val s = (0..m).map { i -> t.removeRange(i..i) }.toSet()
    println(s.count { used.contains(it) } )
  }
}
```
[1533E - Chess Team Forming](../problems/E._Chess_Team_Forming.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
fun main() {
	val n = readLine()!!.toInt()
	val a = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
	val b = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
	val m = readLine()!!.toInt()
	val c = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
	a.sort()
	b.sort()
	val pr = IntArray(n + 1) { -2e9.toInt() }
	for (i in 0 until n) {
		pr[i + 1] = maxOf(pr[i], b[i] - a[i])
	}
	val su = IntArray(n + 1) { -2e9.toInt() }
	for (i in (n-1) downTo 0) {
		su[i] = maxOf(su[i + 1], b[i + 1] - a[i])
	}
	val ans = IntArray(m)
	for (i in 0 until m) {
		var pos = a.binarySearch(c[i])
		if (pos < 0) {
			pos = -pos - 1
		}
		ans[i] = maxOf(pr[pos], su[pos], b[pos] - c[i])
	}
	println(ans.joinToString(" "))
}
```
[1533F - Binary String Partition](../problems/F._Binary_String_Partition.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
fun main() {
  val s = readLine()!!.map { (it - '0').toInt() }.toIntArray()
  val pos = Array(2) { c -> s.indices.filter { s[it] == c }.toIntArray() }
  val sum = Array(2) { c -> s.runningFold(0) { cur, x -> cur + if (x == c) 1 else 0 }.toIntArray() }
  println((1..s.size).map { k -> 
    generateSequence(0) { i ->
      IntArray(2) { c -> pos[c].getOrElse(sum[c][i] + k) { s.size } }.maxOrNull()!!
    }.indexOf(s.size)
  }.joinToString(" "))
}
```
[1533G - Biome Map](../problems/G._Biome_Map.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
  val (n, m) = readLine()!!.split(" ").map { it.toInt() }
  val a = Array(n) { readLine()!!.split(" ").map { it.toInt() } }
  val used = BooleanArray(111) { false }
  val ord = ArrayList<Int>()
  
  val dx = intArrayOf(0, 1, 0, -1)
  val dy = intArrayOf(1, 0, -1, 0)
  
  fun dfs(x : Int, y : Int) {
    ord.add(a[x][y])
    used[a[x][y]] = true
    for (i in 0 until 4) {
      val nx = x + dx[i]
      val ny = y + dy[i]
      if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != 0 && !used[a[nx][ny]]) {
        dfs(nx, ny)
        ord.add(a[x][y])
      }
    }
  }
  
  var k = 0
  
  for (x in 0 until n) {
    for (y in 0 until m) {
      if (a[x][y] != 0) {
        k += 1
        if (ord.isEmpty()) dfs(x, y)
      }
    } 
  }
  
  if (ord.count() != 2 * k - 1) {
    return@repeat println(-1)
  }
  
  println("$k $k")
  for (x in 0 until k) {
    for (y in 0 until k) {
      print("${ord[x + y]} ")
    }
    println()
  }
}

```
[1533H - Submatrices](../problems/H._Submatrices.md "Kotlin Heroes: Episode 7")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
fun main() {
  val AL = 5
  val (n, m) = readLine()!!.split(" ").map { it.toInt() }
  val s = Array(n) { readLine()!! }
  val res = LongArray(1 shl AL) { mask ->
    val d = IntArray(m) { 0 }
    var sum = 0L
    for (i in 0 until n) {
      for (j in 0 until m) {
        val cur = (mask shr (s[i][j] - 'A')) and 1 
        d[j] = if (cur == 1) d[j] + 1 else 0
      }
      val l = IntArray(m) { -1 }
      val q = IntArray(m) { 0 }
      var ptr = -1
      for (j in 0 until m) {
        while (ptr >= 0 && d[q[ptr]] >= d[j]) ptr -= 1
        if (ptr >= 0) l[j] = q[ptr]
        ptr += 1
        q[ptr] = j
      }
      val r = IntArray(m) { m }
      ptr = -1
      for (j in m - 1 downTo 0) {
        while (ptr >= 0 && d[q[ptr]] > d[j]) ptr -= 1
        if (ptr >= 0) r[j] = q[ptr]
        ptr += 1
        q[ptr] = j
      }
      for (j in 0 until m) sum += (j - l[j]) * (r[j] - j) * d[j].toLong()
    }
    sum
  }
  
  for (i in 0 until AL) {
    for (mask in 1 until (1 shl AL)) {
      if (((mask shr i) and 1) == 0) res[mask or (1 shl i)] -= res[mask]
    }
  }
  
  val ans = LongArray(AL + 1) { 0 }
  for (mask in 1 until (1 shl AL)) ans[mask.countOneBits()] += res[mask]
  
  println(ans.drop(1).joinToString(" "))
}
```
[1533I - Excursions](../problems/I._Excursions.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
import java.util.Queue
import java.util.LinkedList

fun main() {
  val (n1, n2, m) = readLine()!!.split(" ").map { it.toInt() }
  val S = n1 + n2
  val T = S + 1
  val V = T + 1
  
  data class Edge(val y : Int, val c : Int, var f : Int, val cost : Int)
  
  val e = ArrayList<Edge>()
  val g = Array(V) { ArrayList<Int>() }
  
  fun addEdge(x : Int, y : Int, c : Int, cost : Int) {
    g[x].add(e.size)
    e.add(Edge(y, c, 0, cost))
    g[y].add(e.size)
    e.add(Edge(x, 0, 0, -cost))
  }
  
  var sum = 0
  readLine()!!.split(" ").mapIndexed { i, value ->
    val k = value.toInt()
    addEdge(i, T, 1, -k)
    sum += k
  }
  
  val deg = IntArray(n2) { 0 }
  repeat(m) {
    val (x, y) = readLine()!!.split(" ").map { it.toInt() - 1 }
    addEdge(y + n1, x, 1, 0)
    deg[y] += 1
  }
  
  for (i in 0 until n2) {
    addEdge(S, i + n1, deg[i] - 1, 0)
  }
  
  var mincost = 0
  
  fun enlarge() : Boolean {
    val q: Queue<Int> = LinkedList<Int>()
    val inq = IntArray(V) { 0 }
    val d = IntArray(V) { 1e9.toInt() }
    val p = IntArray(V) { -1 }
    val pe = IntArray(V) { -1 }
    
    q.add(S)
    inq[S] = 1
    d[S] = 0

    while (!q.isEmpty()) {
      val k = q.poll()
      g[k].forEach { a ->
        val (to, c, f, w) = e[a]
        if (c - f != 0 && d[to] > d[k] + w) {
          d[to] = d[k] + w
          p[to] = k
          pe[to] = a
          if (inq[to] == 0) {
            q.add(to)
            inq[to] = 1
          }
        }
      }
    }
    
    if (p[T] == -1) return false
    
    var cur = T
    while (cur != S) {
      mincost += e[pe[cur]].cost
      e[pe[cur]].f += 1
      e[pe[cur] xor 1].f -= 1
      cur = p[cur]
    }
    
    return true
  }
  
  while (enlarge());
  
  println(sum + mincost)
  
}
```
[1533J - Pawns](../problems/J._Pawns.md "Kotlin Heroes: Episode 7")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
fun main() {
  val N = 500043
  val n = readLine()!!.toInt()
  val pts = Array(N) { ArrayList<Int>() }
  repeat(n) {
    val (x, y) = readLine()!!.split(" ").map { it.toInt() }
    pts[y].add(x)
  }
  pts.forEach { it.sort() }
  
  data class Event(val y : Int, val t : Int, val value : Int)
  
  fun recalc(v1 : ArrayList<Pair<Int, Int>>, v2 : ArrayList<Int>, flag : Boolean) : ArrayList<Pair<Int, Int>> {
    val events = ArrayList<Event>()
    if (flag) {
      v1.forEach { events.add(Event(it.first, 0, it.second)) }
      v2.forEachIndexed { i, value -> events.add(Event(value, 1, i + 1)) }
      events.add(Event(0, 1, 0))
      events.sortWith(compareBy({ -it.y }, { it.t }, { it.value }))
    } else {
      v1.forEach { events.add(Event(it.first, 0, it.second)) }
      v2.forEachIndexed { i, value -> events.add(Event(value, 1, v2.size - i)) }
      events.add(Event(N + 43, 1, 0))
      events.sortWith(compareBy({ it.y }, { it.t }, { it.value }))
    }
    var cur = 0
    val res = ArrayList<Pair<Int, Int>>()
    events.forEach { 
      if (it.t == 0) {
        cur = maxOf(cur, it.value)
      } else {
        res.add(Pair(it.y, it.value + cur))
      }
    }
    return res
  }
  
  fun calc(flag : Int) : Int {
    var cur = ArrayList<Pair<Int, Int>>()
    pts.forEachIndexed { i, value -> cur = recalc(cur, value, flag != i % 2) }
    var res = 0
    cur.forEach { res = maxOf(res, it.second) }
    return res
  }
  
  println(calc(0) + calc(1) - n)
}
```
