# Tutorial

First of all, I would like to thank all testers of the round: [elizarov](https://codeforces.com/profile/elizarov "Candidate Master elizarov"), [IlyaLos](https://codeforces.com/profile/IlyaLos "International Master IlyaLos"), [nuipojaluista](https://codeforces.com/profile/nuipojaluista "Expert nuipojaluista"), [hg333](https://codeforces.com/profile/hg333 "Candidate Master hg333"), [nooinenoojno](https://codeforces.com/profile/nooinenoojno "Expert nooinenoojno"), [winger](https://codeforces.com/profile/winger "International Grandmaster winger"), [neko_nyaaaaaaaaaaaaaaaaa](https://codeforces.com/profile/neko_nyaaaaaaaaaaaaaaaaa "Grandmaster neko_nyaaaaaaaaaaaaaaaaa"), [kort0n](https://codeforces.com/profile/kort0n "Grandmaster kort0n"), [hos.lyric](https://codeforces.com/profile/hos.lyric "Legendary Grandmaster hos.lyric") and [Roms](https://codeforces.com/profile/Roms "Master Roms"). Also huge thanks to co-authors of the contest: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), [vovuh](https://codeforces.com/profile/vovuh "Master vovuh") and [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo").

I hope you enjoyed participating in the round!

Okay, now for the editorial itself:

[1431A - Selling Hamburgers](../problems/A._Selling_Hamburgers.md "Kotlin Heroes 5: ICPC Round")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toLong() }
        val answer = a.sortedDescending().withIndex().maxOf { (it.index + 1) * it.value }
        println(answer)
    }
}
```
[1431B - Polycarp and the Language of Gods](../problems/B._Polycarp_and_the_Language_of_Gods.md "Kotlin Heroes 5: ICPC Round")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val answer = s.count { it == 'w' } + s.split("w").sumOf { it.length / 2 }
        println(answer)
    }
}
```
[1431C - Black Friday](../problems/C._Black_Friday.md "Kotlin Heroes 5: ICPC Round")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon") and [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val p = readLine()!!.split(" ").map { it.toInt() }
        val answer = (1..n / k).maxOf { d ->
            val m = d * k
            p.subList(n - m, n - m + d).sum()
        }
        println(answer)
    }
}
```
[1431D - Used Markers](../problems/D._Used_Markers.md "Kotlin Heroes 5: ICPC Round")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (elizarov)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
            .withIndex().sortedBy { it.value }
        var i = 0
        var j = n - 1
        val answer = ArrayList<Int>(n)
        var bc = 0
        while (i <= j) {
            if (bc >= a[i].value) {
                answer += a[i++].index
                bc = 1
            } else {
                answer += a[j--].index
                bc++
            }
        }
        println(answer.joinToString(" ") { (it + 1).toString() })
    }
}
```
[1431E - Chess Match](../problems/E._Chess_Match.md "Kotlin Heroes 5: ICPC Round")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Ne0n25)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
	val n = readLine()!!.toInt()
	val a = readLine()!!.split(" ").map { it.toInt() }
	val b = readLine()!!.split(" ").map { it.toInt() }
	
	var ans = -1
	var ans_shift = -1
	for (shift in 0 until n) {
		var res = 1e9.toInt()
		for(i in 0 until n)
			res = Math.min(res, Math.abs(a[i] - b[(i + shift) % n]))
		if (res > ans) {
			ans = res
			ans_shift = shift
		}
	}	

	println(IntArray(n) { (it + ans_shift) % n + 1 }.joinToString(" ")) 
}
```
[1431F - Neural Network Problem](../problems/F._Neural_Network_Problem.md "Kotlin Heroes 5: ICPC Round")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**Tutorial is loading... **Solution (vovuh)**
```cpp
import java.util.*

fun main() {
    val (n, k, x) = readLine()!!.split(" ").map { it.toInt() }
    val a = readLine()!!.split(" ").map { it.toInt() }
    var l = 0L
    var r = 10L * 1000 * 1000 * 1000
    var res = -1L

    fun can(sum : Long) : Boolean {
        var cursum = 0L
        var need = 0
        var cur = PriorityQueue<Int>(compareBy<Int> { -it })
        for (i in 0 until n) {
            cursum += a[i]
            cur.add(a[i])
            while (cur.size > x || cursum > sum) {
                cursum -= cur.first()
                cur.remove()
                need += 1
            }
            if (cur.size == x) {
                cursum = 0L
                cur.clear()
            }
        }
        return need <= k
    }

    while (l <= r) {
        val mid = (l + r) / 2
        if (can(mid)) {
            res = mid
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    println(res)
}
```
[1431G - Number Deletion Game](../problems/G._Number_Deletion_Game.md "Kotlin Heroes 5: ICPC Round")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (Ne0n25)**
```cpp
fun main() {
	val (n, k) = readLine()!!.split(' ').map { it.toInt() }
	val a =	readLine()!!.split(" ").map { it.toInt() }.sorted()
	
	val p = IntArray(n + 1) { 0 }
	for (i in 0 until n) p[i + 1] = p[i] + a[i]
	
	val dp = Array(n + 1) { IntArray(k + 1) { -1 } }

 	dp[0][0] = 0
 	for (i in 0 until n) {
 		for (j in 0 until k + 1) {
 			if (dp[i][j] < 0)
 				continue
 			dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i][j])
 			val maxx = Math.min(k - j, (n - i) / 2)
 			for (x in 1..maxx)
 				dp[i + 2 * x][j + x] = Math.max(dp[i + 2 * x][j + x], dp[i][j] + p[i + 2 * x] - p[i + x] - p[i + x] + p[i])	
 		}
 	}
 	
 	println(dp[n][k])
}
```
[1431H - Rogue-like Game](../problems/H._Rogue-like_Game.md "Kotlin Heroes 5: ICPC Round")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Ne0n25)**
```cpp
fun main() {
	val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }	
	val a = readLine()!!.split(" ").map { it.toLong() }
	val b = readLine()!!.split(" ").map { it.toLong() }
	val c = Array(n) { readLine()!!.split(" ").map { it.toLong() } }
	
	val ev = Array(n + m) {
		if (it < n)
			longArrayOf(a[it], 1L, it.toLong())
		else
			longArrayOf(b[it - n], 0L, (it - n).toLong())
	}
	
	ev.sortWith(compareBy({ it[0] }))
	
	val vals = LongArray(n + m) { 0 }
	
	for (e in 0 until n + m) {
		if (ev[e][1] == 1L) {
			val i = ev[e][2].toInt()
			vals[e] = b.indices.filter { b[it] <= ev[e][0] }.map { c[i][it] }.max()!!
		} else {
			val j = ev[e][2].toInt()
			vals[e] = a.indices.filter { a[it] <= ev[e][0] }.map { c[it][j] }.max()!!
		}
	}
	
	var ans = 1e18.toLong()
	
	for (bonus in 1 until n + m) {
		vals[bonus] += k.toLong()
		var (res, cur, mx) = LongArray(3) { 0 }
		var i = 0
		while (true) {
			while (i < n + m && ev[i][0] <= cur) {
				mx = Math.max(mx, vals[i])
				++i;
			}
			if (i == n + m) break
			val need = (ev[i][0] - cur + mx - 1) / mx
			res += need
			cur += need * mx
		}
		ans = Math.min(ans, res)
		vals[bonus] -= k.toLong()
	}

	println(ans)
}
```
[1431I - Cyclic Shifts](../problems/I._Cyclic_Shifts.md "Kotlin Heroes 5: ICPC Round")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Ne0n25)**
```cpp
import java.io.PrintWriter

fun main() {
	val (n, m, q) = readLine()!!.split(' ').map { it.toInt() }
	val s = Array(n) { readLine()!! }
	val c = Array(m + 1) { IntArray(n) { 0 } }
	val rc = Array(m + 1) { IntArray(n) { 0 } }
	
	for (j in m - 1 downTo 0) {
		val cur = Array(n) { intArrayOf(s[it][j].toInt(), c[j + 1][it], it) }
		cur.sortWith(compareBy({it[0]}, {it[1]}))
		for (i in 0 until n) rc[j][i] = cur[i][2]
		c[j][cur[0][2]] = 0
		for (i in 1 until n) {
			val add = if (cur[i][0] == cur[i - 1][0] && cur[i][1] == cur[i - 1][1]) 0 else 1
			c[j][cur[i][2]] = c[j][cur[i - 1][2]] + add
		}
	}
	
	val writer = PrintWriter(System.out)
	
	repeat(q) {
		val t = readLine()!!
		var ans = 0
		var j = 0
		while (j < m) {
			var (nj, L, R) = intArrayOf(j, 0, n - 1)
			while (nj < m) {
				var (l1, r1, nL) = intArrayOf(L, R, R + 1)
				while (l1 <= r1) {
					val mid = (l1 + r1) / 2
					if (s[rc[j][mid]][nj] >= t[nj]) {
						nL = mid
						r1 = mid - 1
					} else {
						l1 = mid + 1
					}
				}
				
				var (l2, r2, nR) = intArrayOf(nL, R, nL - 1)
				while (l2 <= r2) {
					val mid = (l2 + r2) / 2
					if (s[rc[j][mid]][nj] <= t[nj]) {
						nR = mid
						l2 = mid + 1
					} else {
						r2 = mid - 1
					}
				}
				
				if (nL > nR)
					break
					
				L = nL
				R = nR
				++nj
			}
			
			if (j == nj) {
				ans = 0
				break
			}
			
			ans += 1
			j = nj
		}
		
		writer.println(ans - 1)
	}
	
	writer.close()
}
```
[1431J - Zero-XOR Array](../problems/J._Zero-XOR_Array.md "Kotlin Heroes 5: ICPC Round")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (Ne0n25)**
```cpp
fun main() {
	val MOD = 998244353
	
	fun add(x : Int, y : Int) : Int {
		return x + y - if (x + y < MOD) 0 else MOD	
	}
	
	fun mul(x : Int, y : Int) : Int {
		return (1L * x * y % MOD).toInt()
	}
	
	val inv = IntArray(60) { 0 }.also { it[0] = 1; it[1] = (MOD + 1) / 2 }
	for (i in 2 until 60) {
		inv[i] = mul(inv[i - 1], inv[1])
	}
	
	val n = readLine()!!.toInt()
	val a =	readLine()!!.split(" ").map { it.toLong() }
	val target = a.fold(0.toLong()) { res, it -> res xor it }
	val dp = Array(n) { Array(2) { IntArray(2) { 0 } } }
	
	var ans = 0
	
	val m = 1 shl (n - 1)
	for (mask in 0 until m) {
		val cur = Array(n - 1) { longArrayOf(a[it], a[it + 1]) }
		val used = BooleanArray(n - 1) { false }
		
		for (pw in 59 downTo 0) {
			for (i in 0 until n)
				for (cnt in 0 until 2)
					for (fl in 0 until 2)
						dp[i][cnt][fl] = 0
			dp[0][0][0] = 1
			for (i in 0 until n - 1) {
				for (cnt in 0 until 2) {
					for (fl in 0 until 2) {
						if (dp[i][cnt][fl] == 0)
							continue
						val (l, r) = cur[i]
						if ((l shr pw) == (r shr pw)) {
							if (!used[i] && ((mask shr i) and 1) == 1)
								continue
							val c = (l shr pw).toInt()
							val len = (cur[i][1] - cur[i][0] + 1)
							dp[i + 1][cnt xor c][fl] = add(dp[i + 1][cnt xor c][fl], mul((len % MOD).toInt(), dp[i][cnt][fl]))
						} else for (c in 0 until 2) {
							if (!used[i] && (c != (mask shr i) and 1))
								continue
							val nl = if (c == 1) 0L else l
							var nr = if (c == 1) r - (1L shl pw) else (1L shl pw) - 1
							val len = nr - nl + 1
							val nfl = if (len == (1L shl pw) && (c != ((mask shr i) and 1))) 1 else 0
							dp[i + 1][cnt xor c][fl or nfl] = add(dp[i + 1][cnt xor c][fl or nfl], mul((len % MOD).toInt(), dp[i][cnt][fl]))
						}
					}
				}
			}
			
			var cnt = ((target shr pw) and 1).toInt()
			ans = add(ans, mul(dp[n - 1][cnt][1], inv[pw]))
			if (pw == 0) 
				ans = add(ans, dp[n - 1][cnt][0])
			
			for (i in 0 until n - 1) {
				val (l, r) = cur[i]
				if ((l shr pw) == (r shr pw)) {
					val c = (l shr pw)
					cnt = cnt xor c.toInt()
					cur[i][0] -= c shl pw
					cur[i][1] -= c shl pw
				} else {
					used[i] = true
					val c = (mask shr i) and 1
					cnt = cnt xor c.toInt()
					cur[i][0] = if (c == 1) 0 else cur[i][0]
					cur[i][1] = if (c == 1) cur[i][1] - (1L shl pw) else (1L shl pw) - 1
				}
			}
			
			if (cnt != 0)
				break
		}
	}
	
	println(ans)
}
```
