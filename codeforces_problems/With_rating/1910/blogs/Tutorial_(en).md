# Tutorial_(en)

The contest was prepared by [awoo](https://codeforces.com/profile/awoo "Master awoo"), [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), [Roms](https://codeforces.com/profile/Roms "Master Roms") and me. We are very grateful to all of the testers of the contest: [PavelKunyavskiy](https://codeforces.com/profile/PavelKunyavskiy "Grandmaster PavelKunyavskiy"), [ashmelev](https://codeforces.com/profile/ashmelev "Grandmaster ashmelev"), [vladmart](https://codeforces.com/profile/vladmart "Master vladmart"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya") and [mariibykova](https://codeforces.com/profile/mariibykova "Newbie mariibykova").

We hope you enjoyed both the problems and coding in Kotlin! 

Okay, now let's talk about how these problems can be solved:

[1910A - Username](../problems/A._Username.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1910A - Username](../problems/A._Username.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

There are many ways to find a valid username. Let's consider one of them.

Let's look at the last character of the string. If it is a digit from 1 to 9, then we can take the given string except for the last character as the username. If the last character of the string is 0, then the above method doesn't work because the number appended to the username must be positive and not have leading zeros. Therefore, we have to consider the second character from the end, and we can apply similar reasoning. Thus, we have obtained the following solution: remove all the zeros from the end of the string plus one more character. The remaining string is the answer to the problem.

One of the simplest ways to implement it is to use functions like dropLast and dropLastWhile.

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    repeat(readInt()) {
        println(readln().dropLastWhile { it == '0' }.dropLast(1))
    }
}

private fun readInt() = readln().toInt()
```
[1910B - Security Guard](../problems/B._Security_Guard.md)

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms"), preparation: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1910B - Security Guard](../problems/B._Security_Guard.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

If the sequence is already plausible, we don't have to swap anything. To check that, you can iterate over the characters of the string, and maintain some sort of balance — the number of plus signs minus the number of minus signs. Basically, keep track of how many people are currently inside. If all values are non-negative, the sequence is plausible. You can print "1 1", for example.

Otherwise, there exist positions, where the balance is negative. We'd want to fix them all. Consider what happens to the balances when two characters get swapped. If the characters are the same, nothing happens. So, we'd have to swap a plus with a minus. Consider the case with $s_i = $ '-', $s_j = $ '+' and $i < j$. Swapping them will increase all balances between $i$ and $j - 1$ by $2$. For $i > j$, the balances between $j$ and $i - 1$ will decrease by $2$.

Thus, it only makes sense to swap a minus with a plus that is to the right of it. Moreover, of all options, why not swap the leftmost minus with the rightmost plus? A segment of increasing balances for any other swap is included in the segment for that swap. Check for plausibility again and print the answer.

Overall complexity: $O(n)$ per testcase.

 **Solution (Neon)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
  val s = readLine()!!.toCharArray()
  val x = s.indexOf('-').takeIf { it >= 0 } ?: 0
  val y = s.lastIndexOf('+').takeIf { it >= x } ?: x
  s[x] = s[y].also { s[y] = s[x] }
  val bal = s.runningFold(0) { cur, c -> cur + if (c == '-') -1 else 1 }
  println(if (bal.min() == 0) "${x + 1} ${y + 1}" else "-1")
}
```
[1910C - Poisonous Swamp](../problems/C._Poisonous_Swamp.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1910C - Poisonous Swamp](../problems/C._Poisonous_Swamp.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

View the grid the following way: first, there is a line of lily pads in the first row, then a line in the second row, and so on. Notice that you can solve the problem completely independently over these lines and sum up the answers.

So we will solve a problem for one line of lily pads with frogs of length x. Can all x frogs survive? Well, no. In order to survive, the first frog has to jump right. So the second frog also has to jump right. So one until the last frog. It has nowhere safe to jump, so it can't survive. However, x−1 is totally fine, using the same algorithm.

Thus, the task is to extract the lines from the grid, then sum up their lengths minus one. This can be calculated in a lot of ways. For my solution, I also realized that this number is equal to n minus the number of lines. Or even n−1 minus the number of times it changes from a lily pad to swamp or vice versa in the first row (or the second row, since these values are the same).

Overall complexity: O(n) per testcase.

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    repeat(readInt()) {
        readInt()
        val s = readln() + '.' + readln()
        println(s.split(".").sumOf { maxOf(0, it.length - 1) })
    }
}
 
private fun readInt() = readln().toInt()
```
[1910D - Remove and Add](../problems/D._Remove_and_Add.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1910D - Remove and Add](../problems/D._Remove_and_Add.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

Consider the problem with no removal operation. You are allowed to increase some elements by $1$, and you are asked to determine if you can make the array strictly increasing.

This can be solved with a simple greedy. Process elements one by one. If some element is smaller than the previous one, you definitely can't. If it's equal, you have to increase it by $1$. If it's greater, it's optimal to not change it. You are allowed to not change it, and this will give more freedom to later elements.

How can a removal help? Well, if the process completes as is, then it doesn't matter. You can remove any element, and the array will remain strictly increasing.

Otherwise, it gets stuck at some point: some element is smaller than the previous one. The idea is that it's enough to only consider removing one of these two elements. The solution would be to try both options and run the algorithms with no removals on both of them. If any succeeds, then the answer is YES. If neither does, the answer is NO. 

Why are they enough? Obviously, removing anything to the right of them won't help, they will still fail the algorithm. The next step is to realize that the former of the two elements have to be increased by $1$ in the algorithm. Moreover, before the increase, it had to be equal to the latter one. If any of these things don't hold, nothing will get fixed. Why was that element increased then? The element before it was equal to it. Thus, removing the former element will leave an element equal to the latter one. And not removing it will also leave an element equal to the latter one. Thus, it's never more optimal to remove anything to the left of these elements.

Overall complexity: $O(n)$ per testcase.

 **Solution (PavelKunyavskiy)**
```cpp
private fun solve() : Boolean {
    val n = readInt()
    val a = readInts().toIntArray()
    var dropped = false
    for (i in 1 until n) {
        if (a[i] == a[i-1]) {
            a[i]++
        } else if (a[i] < a[i-1]) {
            if (dropped) return false
            dropped = true
            if (i != 1) {
                when {
                    a[i-2] > a[i] -> a[i] = a[i-1]
                    a[i-2] == a[i] -> a[i]++
                    else -> {}
                }
            }
        }
    }
    return true
}
fun main() {
    repeat(readInt()) {
        println(if (solve()) "YES" else "NO")
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1910E - Maximum Sum Subarrays](../problems/E._Maximum_Sum_Subarrays.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1910E - Maximum Sum Subarrays](../problems/E._Maximum_Sum_Subarrays.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

There are greedy and dynamic programming solutions. We will describe the dynamic programming solution.

The main task is to choose two segments (one for the first array and one for the second) the sum of which is maximum, while we can swap $a_i$ and $b_i$. We can use dynamic programming $dp_{i, f1, f2}$, where $i$ is the number of positions that have already been considered (from $0$ to $n$), $f1$ ($f2$) is the flag showing the current state (whether we are before the chosen segment, inside the segment, or after the segment) for the first (second) array. Transitions in such dynamic programming are quite simple: we have a choice to take $a_i$ for the first array and $b_i$ for the second or vice versa; we can also change the state of any flag (note that you can only switch from the current state to the subsequent ones, i.e., for example, you cannot switch from the state "the segment has already ended" to the state "inside the segment"). If the current state of the flag is "inside the segment", then the corresponding value should be added to the dynamic programming value itself.

You can also simplify the implementation quite a bit by, for example, making sure that $a_i \ge b_i$ since they can be swapped (that way, whenever the current index belongs to exactly one of two chosen segments, you always know which element to take).

So, we got a solution in $O(n)$.

 **Solution 1 (Neon)**
```cpp
fun main() = repeat(readLine()!!.toInt()) {
  val n = readLine()!!.toInt()
  val a = readLine()!!.split(" ").map { it.toLong() }
  val b = readLine()!!.split(" ").map { it.toLong() }
  val dp = Array(3) { LongArray(3) { 0 } }
  for ((x, y) in a zip b) {
    for (i in 0..2) for (j in 0..2) {
      dp[i][j] += maxOf(
      	(if (i == 1) x else 0) + (if (j == 1) y else 0),
      	(if (i == 1) y else 0) + (if (j == 1) x else 0)
      );
    }
    for (i in 0..2) for (j in 0..2) {
      if (i < 2) dp[i + 1][j] = maxOf(dp[i + 1][j], dp[i][j]);
      if (j < 2) dp[i][j + 1] = maxOf(dp[i][j + 1], dp[i][j]);
    }
  }
  println(dp[2][2]);
}
```
 **Solution 2 (PavelKunyavskiy)**
```cpp
fun best(a: List<Int>, k: Int): Long {
    val r = LongArray(4)
    var sum = 0L
    for (v in a) {
        sum += v
        r[0] = maxOf(r[0], -sum)
        r[1] = maxOf(r[1], r[0] + sum)
        r[2] = maxOf(r[2], r[1] - sum)
        r[3] = maxOf(r[3], r[2] + sum)
    }
    return r[2 * k - 1]
}

fun main() {
    repeat(readInt()) {
        readInt()
        val a = readInts()
        val b = readInts()
        val mins = a.zip(b).map { minOf(it.first, it.second) }
        val maxs = a.zip(b).map { maxOf(it.first, it.second) }
        println(maxOf(best(mins, 1) + best(maxs, 1), best(maxs, 2)))
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1910F - Build Railway Stations](../problems/F._Build_Railway_Stations.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**
### [1910F - Build Railway Stations](../problems/F._Build_Railway_Stations.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

Consider an easier problem. Instead of upgrading cities, let's upgrade the roads directly.

Since every path between two vertices on a tree is unique, upgrading a single road will decrease the answer by the number of paths that pass through it. These upgrades are completely independent of each other, so the solution would be to upgrade $k$ roads that have the most paths passing through them. This is easy to calculate. Root the tree by any vertex. For each vertex, calculate the number of vertices in its subtree. Then the value for an edge $(v, u)$, where $u$ is the lower vertex, is $\textit{size}_u \cdot (n - \textit{size}_u)$.

Turns out, this solution is basically the solution to the original problem. The edges with the most paths passing through them actually compose a connected subgraph of the tree. So it's always possible to choose $k-1$ best edges overall by picking some $k$ vertices.

How to prove it? Root the tree by its centroid. This will guarantee that the size of every subtree (except the root) is less than or equal to $\frac{n}{2}$. Consider some edge $(v, u)$. The idea is that for any child of $u$, an edge $(u, w)$ has lower value. Their numbers of paths are: $x \cdot (n - x)$ and $y \cdot (n - y)$ for some $x > y$. On the other hand, $\frac{n}{2} \ge x$. So it's common knowledge that it holds. Since going down the tree only decreases the number of paths, the edges with the most paths will always form a connected subgraph that includes the root — the centroid.

Overall complexity: $O(n \log n)$ or $O(n)$ (by coding nth_element function yourself) per testcase.

 **Solution (PavelKunyavskiy)**
```cpp
fun main() {
    repeat(readInt()) {
        val (n, k) = readInts()
        val g = List(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readInts().map { it - 1 }
            g[a].add(b)
            g[b].add(a)
        }
        val size = IntArray(n)
        fun dfs(v: Int, p:Int) : Int {
            size[v] = 1 + g[v].sumOf { if (it == p) 0 else dfs(it, v) }
            return size[v]
        }
        dfs(0, 0)
        val ns = size.map { it.toLong() * (n - it) }.sortedDescending()
        println(ns.subList(0, k - 1).sum() + ns.subList(k - 1, ns.size).sum() * 2)
    }
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1910G - Pool Records](../problems/G._Pool_Records.md)

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1910G - Pool Records](../problems/G._Pool_Records.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

There are basically two types of meetings between Alice and Bob: they meet while moving in opposite directions or while moving in the same direction (we will count meetings at the border of the pool as both types).

Let's look at these types independently. Suppose they are moving in the opposite directions and met at point p1. Suppose, the next time they met in point p2. The total distance they swim is (p1+p2)+(50−p1+50−p2)=2⋅50=100. The total speed they travel until the next encounter is vA+vB.

So the period of time between two consecutive meeting moments are always 100vA+vB. Let's name it as short period ps.

Analogically, let's analyze the case when they met while swimming in the same direction. Without loss of generality, let's say that vA>vB. Then the relative speed of Alice with respect to Bob is |vA−vB| and they will meet again after Alice will swim one more cycle, or 100. Then, the period of time between two meeting moments is 100|vA−vB|. Let's name it as long period pl.

In total, we understand that all values ti must be divisible either by ps or by pl, since Alice and Bob started at 0, each meeting moment is one of two types and difference between moments of the same type must be equal to the corresponding period.

So, if we know both values ps and pl we can check is t valid or not. Since vA,vB>0 then ps<pl. And since t1 is the first moment, then short period ps has to be equal to t1.

So we know that ps=t1, but how to find pl? Let's find the minimum ti such that ti is not divisible by ps. Since it's not divisible by ps it has to be divisible by pl. And it's not hard to prove that pl is exactly ti. (We can prove it by contradiction: suppose pl=tj (j<i); since all tj<ti are divisible by ps then pl=tj is also divisible by ps, but ti is not divisible by ps, so ti is not divisible by pl — contradiction).

So, now we know both ps and pl, how to check: is t valid? Let's just create an array t′ — the first n meeting moments for a pair of periods ps and pl and compare it with a given array t.

To create t′ let's do the following: 

1. create list S=[ps,2ps,…,n⋅ps];
2. create list L=[pl,2pl,…,n⋅pl];
3. merge S and L in one list t′ taking only unique values from both lists (for example, using union);
4. sort t′ if necessary and take only first n elements from it.

If generated t′ and given t are equal, then t is a valid array, otherwise it's invalid.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readln().toInt()) {
        val n = readln().toInt()
        val t = readln().split(' ').map { it.toLong() }

        fun Long.genMoments() = List(n) { (it + 1) * this }

        val sPeriod = t[0]
        val lPeriod = t.firstOrNull { it % sPeriod != 0L }

        val sMoments = sPeriod.genMoments()
        val lMoments = lPeriod?.genMoments() ?: listOf()

        val req = sMoments.union(lMoments).sorted().take(n)
        println(if (req == t) "VALID" else "INVALID")
    }
}

```
[1910H - Sum of Digits of Sums](../problems/H._Sum_of_Digits_of_Sums.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1910H - Sum of Digits of Sums](../problems/H._Sum_of_Digits_of_Sums.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

To solve this problem, we can use the fact that the sum of digits of $x+y$ is equal to $F(x) + F(y) - 9 \cdot c$, where $c$ is the number of digits where the result of the addition was carried over to the next digit. So, to calculate the answer for $a_i$, we have to consider each digit and calculate the number of values of $a_j$ such that, when $a_i + a_j$ is calculated, this digit is carried over to the next digit.

For the lowest digit, it is quite easy: you have to consider if the sum of the last digit of $a_i$ and $a_j$ is greater than or equal to $10$. But for all other digits, it is way more difficult, because carrying from lower digits may affect higher digits.

However, there is a simple way to avoid dealing with any carrying from lower digits. Suppose that we have to check that when we compute $a_i + a_j$, a carry happens from the $k$-th digit to the $k+1$-th digit. Let's consider both numbers modulo $10^k$ (i. e. consider $a_i \bmod 10^{k+1}$ and $a_j \bmod 10^{k+1}$). If the sum of these two numbers has more than $k$ digits, then a carry happens in the respective position.

So, for the fixed $a_i$ and $k$, we should find the number of integers $a_j$ such that $a_i \bmod 10^{k+1} + a_j \bmod 10^{k+1} \ge 10^{k+1}$. In order to do it fast, for every $k$, we can prepare a sorted list of remainders modulo $10^{k}$, and then use binary search to calculate the number of integers that are greater than or equal to $10^{k+1} - a_i \bmod 10^{k+1}$; this is exactly the number of integers $a_j$ such that computing $a_i + a_j$ requires a carry in the $k$-th digit.

Note that the standard binary search function in Kotlin does not necessarily return the leftmost of equal elements, so you probably should implement your own binary search or make sure that no element meets the binary search criteria (as it is done in the solution by Pavel Kunyavskiy).

Solution complexity: $O(n \log n \log A$).

 **Solution (PavelKunyavskiy)**
```cpp
private fun digitSum(a: Int) = a.toString().toCharArray().sumOf { it.digitToInt() }
private fun List<Int>.lowerBound(x: Int) = binarySearch { if (it < x) -1 else 1 }.inv()
fun main() {
    val n = readInt()
    val a = readInts()
    val pw10 = buildList<Int> {
        add(1)
        repeat(9) { add(last() * 10) }
        removeAt(0)
    }
    val d = pw10.map { p -> a.map { it % p }.sorted() }
    val ds = a.sumOf { digitSum(it) }
    println(a.map { x ->
        ds + n * digitSum(x) - 9 * pw10.indices.sumOf {
            n - d[it].lowerBound(pw10[it] - (x % pw10[it]))
        }
    }.joinToString(" "))
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
[1910I - Inverse Problem](../problems/I._Inverse_Problem.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Master awoo")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
val MOD = 998244353

fun main() {
	val (n, k, c) = readLine()!!.split(' ').map { it.toInt() }
	val t = readLine()!!
	val cnt = n / k + 1
	val dp = Array(2) { IntArray(cnt) {0} }
	val pw = IntArray(cnt) {1}
	dp[0][0] = 1
	for (ii in 0 until n % k) {
		val i = ii and 1
		val ni = i xor 1
		var sum = 0
		val cur = c - (t[ii].toInt() - 'a'.toInt()) - 1
		var pr = 1
		for (j in 1 until cnt) {
			pw[j] = (pw[j - 1] * (cur + 1).toLong() % MOD).toInt()
		}
		for (j in 0 until cnt) {
			sum = ((sum * cur.toLong() + pr * dp[i][j].toLong()) % MOD).toInt()
			pr = (pr * c.toLong() % MOD).toInt()
			dp[ni][j] = (sum * pw[cnt - j - 1].toLong() % MOD).toInt()
		}
	}
	var ans = 0
	for (i in 0 until cnt) {
		ans = (ans + dp[n % k % 2][i]) % MOD
	}
	for (i in 0 until n) {
		if (i % k >= n % k) {
			ans = (ans * c.toLong() % MOD).toInt()
		}
	}
	println(ans)
}
```
[1910J - Two Colors](../problems/J._Two_Colors.md)

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1910J - Two Colors](../problems/J._Two_Colors.md "Kotlin Heroes: Episode 9 (Unrated, T-Shirts + Prizes!)")

It's quite easy to see that if the number of red vertices is not equal to the number of blue vertices, the answer can be as large as you want. To prove it rigorously, we can notice that if we obtained some answer, by subtracting $1$ from vertices of one color and adding $1$ to vertices of the other color, we can increase it.

Okay, now let's deal with the case when the number of red vertices is equal to the number of blue vertices. There is a way to handle it with some mathematical transformations related to linear programming duality, but the model approach is different. Basically, the fact that the number of red vertices is the same as the number of blue vertices is a hint that this problem is related to matchings. You can try recalling solutions to different matching-based problems and noticing anything similar in the statement.

The constraints given in the statement are exactly the constraints for the potentials in the Hungarian algorithm for the weighted matching problem (also known as the assignment problem). So, we have to solve the assignment problem on the matrix where the integers in the matrix are equal to distances in the tree between the corresponding vertices. The Hungarian algorithm states that the sum of potentials is equal to the minimum weight of the perfect matching; so we need to somehow solve the following problem:

You are given a weighted tree, where each vertex has one of two colors, red or blue. The number of red vertices is equal to the number of blue vertices. Match the vertices of different colors so that the sum of distances between vertices in each pair is the minimum possible.

We have to solve it in something like $O(n)$ or $O(n \log n)$. Fortunately, it is not that difficult.

Let's root the tree at an arbitrary vertex, and for each vertex, calculate the number of red and blue vertices in its subtree. The difference between these two numbers (its absolute value) corresponds to the minimum number of times the edge leading into this subtree should be counted in the answer (i. e. if there are $3$ red and $5$ blue vertices in the subtree, at least $2$ pairs of vertices consist of a vertex in the subtree and an outside vertex, so the edge leading into the subtree is counted at least twice in the answer).

Okay, we got a lower bound for the answer. Let's show that it's reachable. I think there are ways to do this without using flows, but our proof is based on them.

If we model our problem using minimum cost flows, we have to build the following flow network: each edge of the tree transforms into an undirected edge with infinite capacity and cost equal to the weight of the edge. Then, a source is added, and for each red vertex in the tree, we send a directed edge from the source to it with capacity equal to $1$. Then, we add a sink and from each blue vertex, add a directed edge from it to the sink with capacity equal to $1$.

Let's transform our lower bound for the answer into a valid maximum flow for this network. For each vertex, if the number of red vertices in its subtree is $x$ and the number of blue vertices in its subtree is $y$, let the edge from it to its parent have flow equal to $x - y$ (if $y > x$, then $y - x$ units of flow are transferred from the parent into the subtree). It's quite easy to see that if we also add $1$ unit of flow on all edges that are incident to the source or the sink, we will get a valid flow.

So, our lower bound for the answer is reachable, and we can calculate it in $O(n)$.

 **Solution (PavelKunyavskiy)**
```cpp
import kotlin.math.abs

fun main() {
    val n = readInt()
    val c = readInts()
    val g = List(n) { mutableListOf<Pair<Int, Int>>() }
    repeat(n - 1) {
        val (a, b, w) = readInts()
        g[a - 1].add(b - 1 to w)
        g[b - 1].add(a - 1 to w)
    }
    val size = List(2) { IntArray(n) }
    var ans = 0L
    fun dfs(v: Int, p: Int) {
        size[c[v]][v] = 1
        for ((u, w) in g[v]) {
            if (u != p) {
                dfs(u, v)
                size[0][v] += size[0][u]
                size[1][v] += size[1][u]
                ans += abs(size[0][u] - size[1][u]) * w.toLong()
            }
        }
    }
    dfs(0, 0)
    println(ans)
}

private fun readInt() = readln().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
```
