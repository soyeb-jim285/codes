# Tutorial

[1775A1 - Gardener and the Capybaras (easy version)](../problems/A1._Gardener_and_the_Capybaras_(easy_version).md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775A1 - Gardener and the Capybaras (easy version)](../problems/A1._Gardener_and_the_Capybaras_(easy_version).md "Codeforces Round 843 (Div. 2)")

To solve this problem, it was enough just to consider all options of splitting the string into three substrings, and there are only $O(n^2)$ ways to do it.

[1775A2 - Gardener and the Capybaras (hard version)](../problems/A2._Gardener_and_the_Capybaras_(hard_version).md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775A2 - Gardener and the Capybaras (hard version)](../problems/A2._Gardener_and_the_Capybaras_(hard_version).md "Codeforces Round 843 (Div. 2)")

Consider five cases to solve the task:

* If the string starts with $aa$, then we can split it into $a = s[0]$, $b = s[1]$, $c = s[2 ... n - 1]$.
* If the string starts with $bb$, then we can split it into $a = s[0]$, $b = s[1]$, $c = s[2 ... n - 1]$.
* If the string starts with $ba$, then we can split it into $a = s[0]$, $b = s[1]$, $c = s[2 ... n - 1]$.
* If the string starts with $ab$, and then there is another letter a at position $i > 1$, then we can split it into $a = s[0]$, $b = s[1 ... i - 1]$, $c = s[i ... n - 1]$.
* If the string starts with $ab$, and all other letters are b, then we can split it into $a = s[0 ... n - 3]$, $b = s[n - 2]$, $c = s[n - 1]$.
[1775B - Gardener and the Array](../problems/B._Gardener_and_the_Array.md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775B - Gardener and the Array](../problems/B._Gardener_and_the_Array.md "Codeforces Round 843 (Div. 2)")

The problem can be solved as follows: for each bit count the number of its occurrences in all numbers in the test. If each number has a bit which occurs in all numbers exactly once, then the answer is "NO", otherwise the answer is "YES".

Let's try to prove this solution. Let there be a number in which all bits occurs in all numbers at least $2$ times. But then it is possible to construct a sequence $a$ using all numbers, and a sequence $b$ using all numbers except the given one.

If each number has "unique" bits, then all $f(x)$ will be different.

[1775C - Interesting Sequence](../problems/C._Interesting_Sequence.md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775C - Interesting Sequence](../problems/C._Interesting_Sequence.md "Codeforces Round 843 (Div. 2)")

Note that the answer $-1$ will be when $n$ AND $x \neq x$. This holds if there is a bit with number $b$ which exists in number $x$, but it does not exist in number $n$. What is clear now is that some bits in $n$ must be zeroed. Since we have bitwise AND going sequentially with numbers larger than $n$, we change the bits from the lowest to the highest. Thus, in number $n$ some bit prefix is zeroed out, so if number $x$ is not number $n$ with a zeroed prefix (possibly empty) of bits, then there is no answer.

Now we can calculate for each bit $i$ the minimal number $m_i$ such that $n$ AND $n + 1$ AND $\ldots$ AND $m_i$ has $0$ in the $i$-th bit.

Now calculate $m_{zero}$ as the maximum $m_i$ on all bits to be zeroed, and $m_{one}$ as the minimum $m_i$ on all bits to be left untouched. Then, if $m_{zero} < m_{one}$, we will take $m_{zero}$ as the answer, otherwise there is no answer. The problem can also be solved by binary search: we will use it to find $m$, and check the answer by the formula: for each bit find the nearest $m$, at which it will be zeroed. We can do this using the following fact: for $i$-th bit, the first $2^i$ numbers (starting from zero) will not contain it, then $2^i$ will, then $2^i$ again will not and so on. Such a solution works for $O(\log^2 n)$.

[1775D - Friendly Spiders](../problems/D._Friendly_Spiders.md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775D - Friendly Spiders](../problems/D._Friendly_Spiders.md "Codeforces Round 843 (Div. 2)")

Note that if we construct the graph by definition, it will be large. This will lead us to the idea to make it more compact. Let us create a bipartite graph whose left part consists of $n$ vertices with numbers $a_i$. And in the right part each vertex corresponds to some prime number, not larger than the maximal number from the left part. Draw an edge from the vertex $v$ of the left part to the vertex $u$ of the right lpart if and only if $a_v$ is divisible by a prime number corresponding to the vertex $u$. In this graph from vertex $s$ to vertex $t$, run bfs and output the distance divided by $2$.

Now about how to construct such a graph quickly. Obviously, the number $a_i$ will have at most $\log a_i$ different prime divisors. Then let us factorize $a_v$ and draw edges from vertex $v$ to each prime in factorization.

[1775E - The Human Equation](../problems/E._The_Human_Equation.md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775E - The Human Equation](../problems/E._The_Human_Equation.md "Codeforces Round 843 (Div. 2)")

Let's calculate an array of prefix sums. What do the operations look like in this case? If we calculate the array of prefix sums, we'll see that the operations now look like "add 1 on a subsequence" or "take away 1 on a subsequence". Why? If we take the indices $i$ and $j$ and apply our operation to them (i.e. $a_i = a_i + 1$ and $a_j = a_j - 1$), it will appear that we added $1$ on the segment $[i ... j - 1]$ in the prefix sums array.

We still need to make the array all zeros. How? We will add $1$ to all elements that are less than zero, then subtract $1$ from all elements that are greater than $0$.

From this we get that the answer is the difference between the maximum and minimum prefix sums.

[1775F - Laboratory on Pluto](../problems/F._Laboratory_on_Pluto.md "Codeforces Round 843 (Div. 2)")

 **Solution**
### [1775F - Laboratory on Pluto](../problems/F._Laboratory_on_Pluto.md "Codeforces Round 843 (Div. 2)")

Let us find out the minimal perimeter for a fixed $n$ in $O(1)$.

Let $a = \lfloor \sqrt{n} \rfloor$: 

1. If $a^2 < n$ and $n \leq a \cdot (a+1)$, then the minimum perimeter will be $2 \cdot (2 \cdot a + 1)$.
2. If $a \cdot a + a < n$ and $n \leq (a + 1)^2$, then the minimum perimeter will be $4 \cdot (a + 1)$.
3. If 1) and 2) are not satisfied, then the minimum perimeter is $4 \cdot a$.

For convenience, we denote the semiperimeter by $p$. Let's check one of the rectangle's side $x$ from $1$ to $p$. We will immediately get $y = p - x$. Then if the area of the rectangle is at least $n$, then for tests with $u=1$ we can derive a rectangle with sides $x$ and $y$ by removing some number of cells from the 1st row or column of this matrix. 

Consider a matrix with sides $x$ and $y$ with minimal perimeter and area at least $n$. It is easy to see that if we gradually remove one corner cell of a given figure, the perimeter will not change. Suppose we have some good figure. Let's look at all four figures that form empty cells in the matrix. These figures form a kind of 'staircase', that is, the number of cells in the past row is not less than the number of cells. Why is this so? Suppose that in some line we delete a cell so that the figure ceases to form a staircase. In that case the perimeter of the piece will increase by $2$, which will be the bad piece. 

Now the problem is reduced to the following:

For each matrix with dimensions $x$ by $y$ with minimal perimeter and area not less than $n$, calculate the number of ways to arrange the staircases in 4 corners such that the sum of cells occupied by the staircases equals $x \cdot y - n$. How to do this?

Assume DP $dp_{angles, sum, last}$ — the number of ways to arrange staircases in $angles$, not more than 4, so that the sum of all cells occupied by staircases equals $sum$ and the length of the last line of staircase equals $last$. Then how to count the given DP? Go through $angles, sum, last$ and $cur \leq last$ - the length of the line we will add to the current staircase, then go from $dp_{angles, sum, last}$ to $dp_{angles, sum + cur, cur}$. Or go to the next corner $dp_{angles + 1, sum, maxP}$. This DP works for $O(n \cdot \sqrt{n})$.

To answer $n$ we go through all good rectangles, as specified above, and add $f_{4, x \cdot y - n, maxP}$ to the answer.

To solve the problem for a full score, you must optimize the above DP to $O(n)$. The final difficulty is $O(n + t \cdot \sqrt{n})$.

Now it is time for the bonus task and author solutions!

 **Bonus**Problem A can be solved for O(n) even if the alphabet consists of all letters. Think about how this can be done.

 **Bonus answer**The size of the second string is 1. You can just go through it.

 **Code for Problem A (solution for large alphabet)**[Link](https://codeforces.com/https://pastebin.com/FgbwFDwH)

 **Code for Problem B**[Link](https://codeforces.com/https://pastebin.com/afRvBL6h)

 **Code for Task C**[Link](https://codeforces.com/https://pastebin.com/BKe2W3XT)

 **Code for Task D**[Link](https://codeforces.com/https://pastebin.com/QbWVMjWm)

 **Code for Task E**[Link](https://codeforces.com/https://pastebin.com/7aRpkZNB)

 **Code for Task F**[Link](https://codeforces.com/https://pastebin.com/t0xEXsfh)

