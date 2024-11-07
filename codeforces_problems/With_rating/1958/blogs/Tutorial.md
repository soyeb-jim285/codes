# Tutorial

We hope you enjoyed the problems! Thank you for participation.

The authors are the usual suspects: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [awoo](https://codeforces.com/profile/awoo "Master awoo"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), [Roms](https://codeforces.com/profile/Roms "Master Roms") and me. Huge thanks to the testers: [shnirelman](https://codeforces.com/profile/shnirelman "International Grandmaster shnirelman"), [KIRIJIJI](https://codeforces.com/profile/KIRIJIJI "Candidate Master KIRIJIJI"), [soup](https://codeforces.com/profile/soup "Expert soup"), [Optoed](https://codeforces.com/profile/Optoed "Pupil Optoed"), [le.mur](https://codeforces.com/profile/le.mur "Pupil le.mur"), and the MVP tester [PavelKunyavskiy](https://codeforces.com/profile/PavelKunyavskiy "Grandmaster PavelKunyavskiy"). Without your insights, this round would be impossible!

[1958A - 1-3-5](../problems/A._1-3-5.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1958A - 1-3-5](../problems/A._1-3-5.md "Kotlin Heroes: Episode 10")

There are two main ways to solve this problem: brute force and casework.

To solve this problem with brute force, you can use three nested loops to iterate on the number of coins of each type from 0 to n, check if they give exactly n burles in total, and update the answer. This can be optimized in many different ways, like iterating only on the number of coins worth 3 and 5 burles and calculating the number of coins worth 1 burle in O(1). However, the approach with three nested loops works in O(n3) and is fast enough.

The solution with casework basically works because of an observation that if n is big enough (8 or greater), it can always be expressed as the sum of 3's and/or 5's. So, we can get the answers for n≤7 by hand and if n>7, jsut output 0. This observation is kinda intuitive, but if you want a proof, you can use Chicken McNugget Theorem (in my opinion, one of the coolest names for a math topic!)

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    val ans = IntArray(101) { Int.MAX_VALUE }
    ans[0] = 0
    for (i in ans.indices) {
        for ((d, c) in listOf(1 to 1, 3 to 0, 5 to 0)) {
            if (i + d in ans.indices) ans[i + d] = minOf(ans[i + d], ans[i] + c)
        }
    }
    repeat(readInt()) {
        println(ans[readInt()])
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958B - Clock in the Pool](../problems/B._Clock_in_the_Pool.md "Kotlin Heroes: Episode 10")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1958B - Clock in the Pool](../problems/B._Clock_in_the_Pool.md "Kotlin Heroes: Episode 10")

Let's write down intervals when the clock shows time using formulas. Segments are [3k⋅x+2k,3k⋅(x+1)) for all integer x≥0.

We need to find the first interval that finished later than m. It may start either earlier or later than m, but it must finish later than m.

In formulas, it means that we should find the minimum x such that m<3k⋅(x+1) or x>m3k−1. It means that we should take x=floor(m3k).

Since now we know x, we can calculate when the x-th interval starts: it's moment 3kx+2k. If 3kx+2k>m, we should wait exactly 3kx+2k−m seconds. If 3kx+2k≤m, then time is showing right now, and we don't need to wait.

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    repeat(readInt()) {
        val (k, m) = readInts()
        println(maxOf(0, 2 * k - (m % (3 * k))))
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958C - Firewood](../problems/C._Firewood.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1958C - Firewood](../problems/C._Firewood.md "Kotlin Heroes: Episode 10")

Suppose k is not divisible by 2m (m is an arbitrary positive integer). Then we should have at least one log with weight not divisible by 2m, since if all logs are divisible by 2m, we cannot get the sum of log weights which is not divisible by 2m. 

So, let d be the maximum integer such that k is divisible by 2d. After we split the logs, there should be at least one log having weight 2d or less. So, we need to do at least n−d actions.

And we can show that n−d actions are always sufficient. Split the smallest log every time, so you get logs of size 2n−1,2n−2,2n−3,…,2d+1,2d,2d. We can always choose a subset of logs with total weight equal to k, if k is divisible by 2d and less than n. For example, we can make this subset if for every bit set to 1 in k, we take the corresponding log.

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    repeat(readInt()) {
        val (n, k) = readLongs()
        println(n - k.countTrailingZeroBits())
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958D - Staircase](../problems/D._Staircase.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1958D - Staircase](../problems/D._Staircase.md "Kotlin Heroes: Episode 10")

There are two approaches to this problem: greedy and dynamic programming.

Greedy approach. It's quite easy to see that we only have to consider broken steps, and repair them only once. So, we can consider each consecutive block of broken steps and solve the problem separately for it.

If a block has even length, then there is only one way to repair it in the minimum possible number of days — repair the first and the second step on the same day, then the third and the fourth, and so on. So, for an even-length block, the total effort is the 2⋅∑ai.

If a block has odd length, we can choose a step which will be left without a pair (so the effort for this step will not be doubled), and all the other steps will be paired. However, if we choose a step on an even position as a single step, it has an odd number of steps to the left and an odd number of steps to the right, so we cannot split them into pairs. So, we can choose a "single" step only among steps on odd positions from the block, and it's quite easy to see that the best step to choose is having the maximum ai.

Dynamic programming approach. Let dpi be a pair of two integers:

* the minimum number of days to repair the first i steps;
* the minimum total effort to repair the first i steps, if we do it in the minimum number of days.

When updating dynamic programming values, we try to minimize the first value, and to break ties, minimize the second value.

The transitions are pretty straightforward:

* if the step i+1 is intact, you can just skip it and go from dpi to dpi+1;
* if the step i+1 is broken, you can go from dpi to dpi+1, adding 1 to the number of days and ai+1 to the total effort;
* if both steps i+1 and i+2 are broken, you can go from dpi to dpi+2, adding 1 to the number of days and 2⋅(ai+1+ai+2) to the total effort.

Both of these solutions can be implemented in O(n).

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    repeat(readInt()) {
        readInt()
        val d = mutableListOf(mutableListOf<Long>())
        for (i in readLongs()) {
            if (i == 0L) {
                d.add(mutableListOf())
            } else {
                d.last().add(i)
            }
        }
        println(d.sumOf { l -> 2 * l.sum() - ((l.indices step 2).takeIf { l.size % 2 == 1 }?.maxOfOrNull { l[it] } ?: 0) })
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958E - Yet Another Permutation Constructive](../problems/E._Yet_Another_Permutation_Constructive.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1958E - Yet Another Permutation Constructive](../problems/E._Yet_Another_Permutation_Constructive.md "Kotlin Heroes: Episode 10")

Let the current size of the array be m. When an operation is applied, at least ⌊m2⌋ elements will be removed, because if an element is not removed, both of its neighbors will be removed.

So, for every value of k, we can calculate the minimum possible size of an array n (let's call it fk). For k=1, fk=2; for k>1, this value is fi=2⋅fk−1−1. We can actually derive an exact formula fk=2k−1+1, but we don't actually have to, since it can be calculated in O(n).

If n<fk, obviously, there is no solution. Let's show how to construct the answer for n=fk, and then let's deal with the case n>fk.

For k=1, we can use an array [1,2]. If we want to go from k to k+1, we can insert elements which will be removed on the first operation between the existing elements, while increasing the existing elements by the number of elements we added (so that they are actually greater). For example, [1,2]→[2,1,3]→[4,1,3,2,5] (every element on even position is a newly inserted element). That's how we can resolve the case n=fk.

What if n>fk? Construct the answer for n=fk. Let's say we have m=n−fk "extra" elements. Let's insert them in such a way that they will all be deleted during the first operation, and will not affect the existing elements. For example, we can increase every existing element by m, and then add 1,2,3,…,m to the beginning of the array, so that they don't affect existing elements, and are all deleted during the first operation.

You have to take into account that fk might overflow. And you should first check that fk≤n, and only then construct the answer, since it takes O(fk+n).

 **Solution (PavelKunyavskiy)**
```cpp
private fun solve(): String {
    val (n, k) = readInts()
    var ans = listOf(n - 1, n)
    repeat(k - 1) {
        val min = ans.min()
        val prevStart = min - ans.size + 1
        if (prevStart <= 0) {
            return "-1"
        }
        ans = ans.zip(prevStart .. min).flatMap { (a, b) -> listOf(a, b) }.dropLast(1)
    }
    ans = (1 until ans.min()) + ans
    return ans.joinToString(" ")
}
fun main() {
    repeat(readInt()) {
        println(solve())
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958F - Narrow Paths](../problems/F._Narrow_Paths.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1958F - Narrow Paths](../problems/F._Narrow_Paths.md "Kotlin Heroes: Episode 10")

If there are no blocked cells, then there are a total of n different paths. Initially, Monocarp goes to the right, then descends in some column and goes all the way to the right. That is, the chosen column determines the path.

Now with blocked cells. Why might a path be inaccessible? Either Monocarp cannot go further to the right, or one of the cells in the column is blocked, or it cannot reach the end to the right. From this, the following conclusion can be drawn. In the first row, only the leftmost blocked cell is important, and in the second row, only the rightmost one is important.

If in the first row the leftmost blocked cell is at position x, and the rightmost in the second row is at position y, then Monocarp has access to x−y+1 paths. We will deal with the case when there are no blocked cells in one of the rows later.

It can be noticed that the difference can be non-positive, but this simply means that there are 0 paths. In practice, this case can be eliminated by calculating all the positive answers and subtracting them from the total number of ways to choose k blocked cells out of 2n−2 options.

Let's say we have fixed x−y=d. Then the two fixed cells can be at positions (d+1,1),(d+2,2),…,(n,n−d). In the case of (d+1,1), the remaining k−2 cells can be chosen from among n−(d+1) to the right of the first cell and among 0 to the left of the second cell, totaling n−(d+1). In the case of (d+1,1), this is n−(d+2) and 1, again totaling n−(d+1). That is, with a fixed difference, we always have the same number of ways to choose the remaining k−2 cells — (n−d−1k−2). And we know that the positions for the two cells can be chosen in n−d ways. That is, the contribution to the answer for d−1 is (n−d−1k−2)⋅(n−d).

We still need to deal with the ways in which one of the rows has no blocked cells. Let's assume this is the case for the second row. Then the number of paths is still determined by the position of the leftmost blocked cell in the first row. Let's iterate over it and count the ways to arrange the remaining k−1 cells. There are (n−i−1k−1) ways for the cell at position i.

If there are no blocked cells in the second row, then the answer is exactly the same. We iterate over the position of the rightmost cell and arrange the rest. It turns out to be symmetrical to the first method, so the formula is the same. We just calculate it once and multiply by 2.

You can pre-calculate factorials to compute the binomial coefficient in O(n+logMOD).

Overall complexity: O(n+logMOD).

 **Solution (PavelKunyavskiy)**
```cpp
private const val MOD =  1000000007

@JvmInline
@Suppress("NOTHING_TO_INLINE")
private value class ModInt(val x: Int) {
    inline operator fun plus(other: ModInt) = ModInt((x + other.x).let { if (it >= MOD) it - MOD else it })
    inline operator fun minus(other: ModInt) = ModInt((x - other.x).let { if (it < 0) it + MOD else it })
    inline operator fun times(other: ModInt) = ModInt((x.toLong() * other.x % MOD).toInt())
    fun power(p_: Int): ModInt {
        var a = this
        var res = ModInt(1)
        var p = p_
        while (p != 0) {
            if ((p and 1) == 1) res *= a
            a *= a
            p = p shr 1
        }
        return res
    }

    inline operator fun div(other: ModInt) = this * other.inv()
    inline fun inv() = power(MOD - 2)

    companion object {
        inline fun from(x: Int) = ModInt((x % MOD + MOD) % MOD)
        inline fun from(x: Long) = ModInt(((x % MOD).toInt() + MOD) % MOD)
    }
}

@JvmInline
private value class ModIntArray(val storage:IntArray) {
    operator fun get(index: Int) = ModInt(storage[index])
    operator fun set(index: Int, value: ModInt) { storage[index] = value.x }
    val size get() = storage.size
}
private inline fun ModIntArray(n: Int, init: (Int) -> ModInt) = ModIntArray(IntArray(n) { init(it).x })

private const val COMB_MAX = 400_010

private val fs = ModIntArray(COMB_MAX) { ModInt(1) }.apply {
    for (i in 1 until size) {
        set(i, get(i - 1) * ModInt.from(i))
    }
}
private val ifs = ModIntArray(COMB_MAX) { fs[it].inv() }

private fun cnk(n: Int, k: Int) = if (n >= k) fs[n] * ifs[k] * ifs[n - k] else ModInt(0)

fun main() {
    val (n, k) = readInts()
    val ans = ModIntArray(n + 1) { ModInt(0) }

    for (diff in -n..n) {
        val ways = maxOf(0, diff - 1)
        val ll = maxOf(1, diff)
        val rr = minOf(n, n - 1 + diff)
        ans[ways] += ModInt(maxOf(0, rr - ll)) * cnk(n - diff - 1, k - 2)
    }
    for (i in 1 until n) {
        ans[i] += cnk(n - i - 1, k - 1)
    }
    for (j in 0 until n - 1) {
        ans[n - j - 1] += cnk(j, k - 1)
    }
    println(ans.storage.joinToString(" "))
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958G - Observation Towers](../problems/G._Observation_Towers.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1958G - Observation Towers](../problems/G._Observation_Towers.md "Kotlin Heroes: Episode 10")

Let's start with a simple case: the points are visible from different towers. That is, for each point, we need to find a tower to increase as little as possible, and add the two answers together.

Let's solve for point l. There are three possibilities here. The point is already covered by some tower, there is a tower to the left of the point, and there is a tower to the right of the point.

Let's start with the case to the left. Which points are visible from the towers to the left? We don't care about the left boundaries, and the right boundaries are equal to xi+hi for all such i that xi<l. If we increase the height by k, it will be xi+hi+k. So, we need to find the tower with the greatest value of xi+hi. Then the answer will be l−(xi+hi). You can notice that if xi+hi≥l, then we can take the maximum with 0 in the formula, and the first case will disappear by itself. For the tower to the right, the situation is symmetric: we need to find the tower with the smallest value of xi−hi, and the answer will be max(0,(xi−hi)−l).

Thus, we can build prefix maximums based on the values of xi+hi at position xi and suffix minimums based on the values of xi−hi at position xi and make queries in O(1).

Now the case where both points are covered by the same tower. Again, we will divide the problem into two cases. Either we will first see point l from the tower, and then r, or vice versa. Where should the tower be for each case? Obviously, in the first case it is closer to l, and in the second case it is closer to r. That is, if xi≤l+r2 (formula without rounding), then the first case, otherwise the second.

It turns out that we have now reduced the problem to the case with independent towers. In the first case, we need to find a tower on the prefix up to the middle between l and r, from which r will be visible as soon as possible — maximum by xi+hi. In the second case — a tower on the suffix from the middle between l and r, from which l will be visible as soon as possible — minimum by xi−hi. That is, we can use the same prefix and suffix arrays.

Overall complexity: O(n+q).

 **Solution (PavelKunyavskiy)**
```cpp
import kotlin.math.abs
import kotlin.math.sign

fun main() {
    readInts()
    val x = readInts()
    val h = readInts()
    val ord = buildList {
        for (i in x.indices.sortedBy { x[it] }) {
            while (isNotEmpty() && h[i] - h[last()] >= x[i] - x[last()]) {
                removeLast()
            }
            if (isEmpty() || h[last()] - h[i] <= x[i] - x[last()]) {
                add(i)
            }
        }
    }.map { x[it] to h[it] }

    fun nextAfter(pos: Int) = ord.binarySearch { (x, _) -> if (x >= pos) 1 else -1 }.inv()
    fun coverBy(idx: Int, pos: Int) = ord.getOrNull(idx)?.let { (x, h) -> maxOf(0, abs(x - pos) - h) } ?: Int.MAX_VALUE
    fun cover(pos: Int): Int {
        val a = nextAfter(pos)
        return minOf(coverBy(a - 1, pos), coverBy(a, pos))
    }

    fun cover2(l: Int, r: Int): Int {
        val a = nextAfter((l + r) / 2)
        return minOf(maxOf(coverBy(a, l), coverBy(a, r)), maxOf(coverBy(a - 1, l), coverBy(a - 1, r)))
    }

    val ans = List(readInt()) {
        val (l, r) = readInts()
        minOf(
            cover(l) + cover(r),
            cover2(l, r)
        )
    }
    println(ans.joinToString(" "))
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958H - Composite Spells](../problems/H._Composite_Spells.md "Kotlin Heroes: Episode 10")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms"), preparation: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1958H - Composite Spells](../problems/H._Composite_Spells.md "Kotlin Heroes: Episode 10")

First of all, the total health value might be very large. It may grow exponentially, so we can't use basic integer types to handle the health values. Thankfully, Kotlin has a BigInteger class which allows us to deal with arbitrarily large number addition/subtraction in O(S), where S is the size of the greater number. Using induction on the total length of the composite spells, we can show that the length of each number is O(∑si). So, we need a solution that makes O(n+m+∑si) operations with big integers.

Suppose we calculate the total change of health for every composite spell with dynamic programming (let it be deltai for the i-th spell). If we try iterating on components of the spell we cast, we will know our health value after using each component. However, we might miss the moment when the health of the monster went to 0 or lower in the middle of a component.

We need a way to know if a spell puts the monster into non-positive health in the middle of casting. Let's consider the minimum value the monster's health becomes during casting the spell. Obviously, if it is positive, then the monster survives the spell, otherwise it dies.

To quickly calculate the minimum health value, let's introduce another dynamic programming: let minDeltai be the minimum change of health while the i-th spell is cast. Using the values of deltai, we can calculate it recursively as follows: let the i-th spell consist of components c1,c2,…,ck. The minimum health is achieved when we have finished casting the first several parts of the spell and are in the middle of casting the next part. So, the value of minDeltai can be calculated as kminj=1j−1∑v=1deltacv+minDeltacj, and we can compute it in O(k) additions/subtractions/comparisons of big integers.

Okay, now we know the value of deltai and minDeltai for each spell. For each composite spell we cast, we are now able to understand whether it will put the monster's health to 0 or lower in the middle of casting. So, to find the basic spell that kills the monster, we can use recursion.

Let rec(remHP,idCompSpell) be a recursive function that computes the answer if the current health of the monster is remHP, and we cast the spell idCompSpell. We can iterate on the first component of the spell that will bring the monster to non-positive health, and make a recursive call with the health value of the monster right before this component is cast, and the id of this component. Each call decreases the value of idCompSpell at least by 1, so we will call this function at most once for each composite spell, so all calls will work in O(∑si).

So, the complexity of our solution is O(∑si⋅(n+m+∑si)).

 **Solution (Neon)**
```cpp
import java.math.BigInteger

fun main() = repeat(readLine()!!.toInt()) {
  val (n, hp) = readLine()!!.split(" ").let { (n, hp) -> n.toInt() to BigInteger(hp) } 
  val s = readLine()!!.split(" ").map { BigInteger(it) }
  val m = readLine()!!.toInt()
  val c = Array(m) { readLine()!!.split(" ").drop(1).map { it.toInt() - 1 } }
  val delta = Array(m) { BigInteger.ZERO }
  val minDelta = Array(m) { BigInteger.ZERO }
  for (i in 0 until m) {
    var curHP = BigInteger.ZERO
    for (id in c[i]) {
      if (id < n) {
        curHP += s[id]
        minDelta[i] = minOf(minDelta[i], curHP)
      } else {
        minDelta[i] = minOf(minDelta[i], curHP + minDelta[id - n])
        curHP += delta[id - n]
      }
    }
    delta[i] = curHP
  }
  
  fun rec(remHP : BigInteger, idCompSpell : Int) : Int {
    var curHP = remHP
    for (id in c[idCompSpell]) {
      if (id < n) {
        curHP += s[id]
        if (curHP <= BigInteger.ZERO)
          return id + 1
      } else {
        if (curHP + minDelta[id - n] <= BigInteger.ZERO)
          return rec(curHP, id - n)
        curHP += delta[id - n]
      }
    }
    return -1
  }
  
  println(rec(hp, m - 1))
}
```
[1958I - Equal Trees](../problems/I._Equal_Trees.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1958I - Equal Trees](../problems/I._Equal_Trees.md "Kotlin Heroes: Episode 10")

The constraint n≤40 might imply that we are looking for a meet-in-the-middle approach. Let's try to reduce this problem to one of the problems that can be solved using meet-in-the-middle.

The first key observation that we need is that if i is an ancestor of j, and we don't remove any of these vertices from the tree, i will always be an ancestor of j.

Let's try to figure out when two vertices i and j cannot be left in the answer together. If i is an ancestor of j in one of the trees, but not in the other tree (same for swapping i and j), then leaving them both in the answer means that the trees won't be equal.

The second key observation is that any set of vertices such that the "ancestor relations" between them are the same in both trees is a valid set (i. e. if we leave only vertices from these sets, both trees will be equal). This is because if we know the set of ancestors for every vertex, the structure of the rooted tree is uniquely determined (for every vertex i, its parent is the vertex j such that it is an ancestor of i and not an ancestor of any other ancestor of i).

So, let's construct a graph on n vertices, where an edge between i and j means that the "ancestor relation" between i and j is the same in both trees. We have to find the maximum clique in this graph, and this clique will be the set of vertices we don't delete.

We can use meet-in-the-middle to find the maximum clique. However, I want to showcase a very cool technique of finding the maximum clique in O(n⋅20.5n) without using meet-in-the-middle.

Let's write a recursive brute force approach. Let the current "state" of brute force be the bitmask of vertices such that they are adjacent to every vertex we already picked. Also, let our recursive function return the maximum number of vertices from the mask we can take.

Find the first vertex in the mask (let it be v). There are two cases:

* either v belongs to the clique; then we call the recursive function from the bitwise AND of the current mask and the mask of all vertices adjacent to v;
* or v does not belong to the clique; then we call the recursive function from the current mask with the v-th bit set to 0.

If we add memoization (save the answer for every recursive call), it works in O(n⋅20.5n)! This exclamation mark is not the factorial sign. To prove it, consider the depth of recursion:

* if the depth is at least n2, all n2 first bits are set to 0, so there are 20.5n possible values for the mask;
* otherwise, we made at most n2 choices from two options, so there are also just 20.5n possible values for the mask.
 **Solution (PavelKunyavskiy)**
```cpp
fun readTree(n: Int) : List<BooleanArray> {
    val p = listOf(null) + readInts().map { it - 1 }
    return List(n) { a -> BooleanArray(n) { b -> a in generateSequence(b) { p[it] } } }
}
fun main() {
    val n = readInt()
    val t1 = readTree(n)
    val t2 = readTree(n)
    val masks = LongArray(n) { a ->
        (0 until n).filter { b -> a != b && t1[a][b] == t2[a][b] && t1[b][a] == t2[b][a] }.sumOf { 1L shl it }
    }
    val data = mutableMapOf<Long, Int>()
    data[0] = 0
    fun compute(mask: Long) : Int = data.getOrPut(mask) {
        val index = mask.countTrailingZeroBits()
        maxOf(compute(mask xor (1L shl index)), compute(mask and masks[index]) + 1)
    }
    println(2 * (n - compute((1L shl n) - 1)))
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1958J - Necromancer](../problems/J._Necromancer.md "Kotlin Heroes: Episode 10")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1958J - Necromancer](../problems/J._Necromancer.md "Kotlin Heroes: Episode 10")

In this problem, most people were submitting solutions working in O((n+q)√Alogn), where A is the maximum monster health value. A good implementation with this complexity might pass, but the model solution has a slightly better complexity: O((n+q)√Alogn). 

The main idea is that if we process the first M monsters for a query naively, then the total strength of zombies becomes at least M, so for every remaining monster, we will use at most AM turns.

For every monster i and every value j from 1 to AM we find the minimum left border l such that, if we consider a query with left border l, we need at least j operations to kill the monster. It means that the total strength of all monsters from l to i−1 is less than ⌈aij−1⌉ (this is the minimum total strength that allows killing the i-th monster in less than j turns). Using prefix sums, we can find every such border in O(logn): let si be the total strength of the first i monsters. Then, if we consider monsters in 0-indexation, we need the minimum l such that ⌈aij−1⌉>si−sl. In other words, we need the minimum l such that sl>si−⌈aij−1⌉, and we can use binary search to find it. Let's remember that in this left border l the number of turns required to kill the i-th monster increases by 1.

Then, we use a sweep line approach. Sort all queries according to their left borders, and maintain a data structure that allows adding +1 to a single element and querying the sum on a segment (Fenwick tree, for example). In this structure, for every monster, we store the number of turns required to kill it, considering the current left border. When the left border gets moved from l−1 to l, we add 1 to every monster, for which the number of turns increases (it might increase more than by 1 for some monsters, but we can handle it because we precalculated the left border for every monster and every number of turns required to kill it).

When we process a query with left border l, our Fenwick tree stores the values of min(AM,cnti,l) for the monsters, where cnti,l is the number of turns to kill the i-th monster when we start from the left border l. Process the first M monsters in the query in O(M), so our Fenwick tree stores the "actual" values for all remaining monsters, and use a range sum query to process the remaining monsters in O(logn).

We get O(nAMlogn) for preprocessing and O(M+logn) for each query. If we choose M close to √Alogn, the solution complexity becomes O((n+q)√Alogn).

 **Solution (Neon)**
```cpp
const val M = 1000
const val K = 10

fun main() {  
  val (n, q) = readLine()!!.split(" ").map { it.toInt() }
  val a = readLine()!!.split(" ").map { it.toInt() }
  val b = readLine()!!.split(" ").map { it.toInt() }
  val l = IntArray(q)
  val r = IntArray(q)
  for (i in 0 until q) {
    val (x, y) = readLine()!!.split(" ").map { it.toInt() - 1}
    l[i] = x
    r[i] = y
  }
  val s = b.scan(0, Int::plus)
  val ev = Array(n) { mutableListOf<Int>() }
  for (i in 0 until n) {
    for (j in 1 until K) {
      val x = s[i] - (a[i] + j - 1) / j + 1
      val pos = s.binarySearch { if (it < x) -1 else 1 }.inv()
      if (pos < i) ev[pos].add(i)
    }
  }
  val qr = Array(n) { mutableListOf<Int>() }
  for (i in 0 until q) qr[l[i]].add(i)
  val f = IntArray(n) { 0 }
  fun inc(i : Int) = generateSequence(i) { (it or (it + 1)).takeIf { it < n } }.forEach { ++f[it] }
  fun sum(i : Int) = generateSequence(i) { ((it and (it + 1)) - 1).takeIf { it >= 0 } }.sumOf { f[it] }
  for (i in 0 until n) inc(i)
  val ans = IntArray(q) { 0 }
  for (i in 0 until n) {
    for (j in ev[i]) inc(j)
    for (j in qr[i]) {
      var cur = b[l[j]]
      for (x in 1 until M.coerceAtMost(r[j] - l[j] + 1)) {
        ans[j] += (a[l[j] + x] + cur - 1) / cur
        cur += b[l[j] + x]
      }
      if (l[j] + M <= r[j]) ans[j] += sum(r[j]) - sum(l[j] + M - 1)
    }
  }
  println(ans.joinToString("n"))
}
```
