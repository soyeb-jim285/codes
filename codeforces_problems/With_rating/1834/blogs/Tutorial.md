# Tutorial

Thank you for participating!

[1834A - Unit Array](../problems/A._Unit_Array.md "Codeforces Round 879 (Div. 2)") was authored and prepared by [Artyom123](https://codeforces.com/profile/Artyom123 "Grandmaster Artyom123")

[1834B - Maximum Strength](../problems/B._Maximum_Strength.md "Codeforces Round 879 (Div. 2)") was authored by jury of the olympiad, and prepared by [TheEvilBird](https://codeforces.com/profile/TheEvilBird "Expert TheEvilBird")

[1834C - Game with Reversing](../problems/C._Game_with_Reversing.md "Codeforces Round 879 (Div. 2)") was authored and prepared by [sevlll777](https://codeforces.com/profile/sevlll777 "Master sevlll777")

[1834D - Survey in Class](../problems/D._Survey_in_Class.md "Codeforces Round 879 (Div. 2)") was authored by [vaaven](https://codeforces.com/profile/vaaven "Master vaaven") and [Mikhango](https://codeforces.com/profile/Mikhango "Specialist Mikhango") and prepared by [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "Master Alexdat2000")

[1834E - MEX of LCM](../problems/E._MEX_of_LCM.md "Codeforces Round 879 (Div. 2)") was authored by [TeaTime](https://codeforces.com/profile/TeaTime "Master TeaTime") and prepared by [teraqqq](https://codeforces.com/profile/teraqqq "International Grandmaster teraqqq")

[1834F - Typewriter](../problems/F._Typewriter.md "Codeforces Round 879 (Div. 2)") was authored and prepared by [Ziware](https://codeforces.com/profile/Ziware "International Master Ziware")

 
### [1834A - Unit Array](../problems/A._Unit_Array.md "Codeforces Round 879 (Div. 2)")

First, let's make the sum of the array elements $\ge 0$. To do this, we just need to change some $-1$ to $1$. The number of such replacements can be calculated using a formula or explicitly simulated.

After that, there are two possible situations: either the product of all elements is equal to $1$, or the product of all elements is equal to $-1$. In the first case, we don't need to do anything else. In the second case, we need to replace one more $-1$ with $1$ (note that in this case the sum will remain $\ge 0$).

 
### [1834B - Maximum Strength](../problems/B._Maximum_Strength.md "Codeforces Round 879 (Div. 2)")

Let's add leading zeros to $L$ if necessary. Now we can represent the numbers $L$ and $R$ as their longest common prefix, the digit $k$ at which the values differ, and the remaining digits. After digit $k$, any digits can be placed, so it is advantageous to put $9$ in one number and $0$ in the other. Then the answer is equal to $(r_{k} - l_{k}) + 9 \cdot (n - k)$. For example, it is achieved with numbers $A = \overline{l_{1}l_{2} \ldots l_{k} \underbrace{99 \ldots 9}_{n - k}}$ and $B = \overline{r_{1}r_{2} \ldots r_{k} \underbrace{00 \ldots 0}_{n - k}}$.

 
### [1834C - Game with Reversing](../problems/C._Game_with_Reversing.md "Codeforces Round 879 (Div. 2)")

Let's show that the specific choice of a turn by Bob (which of the strings to reverse) does not affect Alice's strategy and therefore the answer to the problem.

Reversing the string twice does not change anything $\to$ we are only interested in the parity of the number of reverses for both strings.

If Bob made an even number of moves in total, then the parity of the number of moves made by Bob with string $s$ coincides with the parity of the number of moves made by Bob with string $t \to$ pairs of characters at the same indices, after all reverses, will be $(s_1, t_1), (s_2, t_2), \ldots, (s_n, t_n)$, possibly in reverse order, but it doesn't matter. Here $s_1, \ldots, s_n$ and $t_1, \ldots, t_n$ are the original indices of the strings, which do not change with reversing.

If Bob made an odd number of moves, then exactly one of the strings will be reversed, and the pairs of characters in the same indices will be: $(s_1, t_n), (s_2, t_{n-1}), \ldots, (s_n, t_1)$ (or in reverse order).

That is, the specific pairs of corresponding characters are determined only by the parity of the total number of moves made by Bob, and it does not matter which specific moves were made.

Therefore, Alice can choose one of two strategies:

* Make $s_1 = t_1, s_2 = t_2, \ldots, s_n = t_n$, and fix the end of the game when the number of moves made by Bob is even.
* Make $s_1 = t_n, s_2 = t_{n-1}, \ldots, s_n = t_1$, and fix the end of the game when the number of moves made by Bob is odd.

Let's count $cnt$ — the number of indices where $s$ and $t$ differ, and $cnt_{rev}$ — the number of indices where $s$ and $\operatorname{rev}(t)$ differ.

For the first strategy, Alice must make at least $cnt$ moves herself, and it is also necessary that the number of moves made by Bob is even $\to$ it is easy to see that for this strategy the game will last $2 \cdot cnt - cnt \% 2$ moves.

For the second strategy, everything is roughly similar: the game will last $2 \cdot cnt_{rev} - (1 - cnt_{rev} \% 2)$ moves, but the case $cnt_{rev} = 0$ needs to be handled separately.

And the answer to the problem will be the minimum of these two values. Asymptotic: $O(n)$.

 
### [1834D - Survey in Class](../problems/D._Survey_in_Class.md "Codeforces Round 879 (Div. 2)")

Let's fix the students who will end up with the highest and lowest hands. Then, to maximize the difference, we can ask all the topics that the student with the highest hand knows. Then the second student will raise his hand for each topic in the intersection of their segments, and lower for each topic that only the first student knows. That is, the problem is to find $2$ segments $a$ and $b$ such that the value of $|a| - |a |\cap b|$ is maximal, since the answer is $2 \cdot (|a| - |a \cap b|)$.

The segment $b$ can intersect the segment $a$ in four ways: intersect the beginning of $a$, intersect the end of $a$, be completely inside $a$, or not intersect it at all. So, if in the answer segment $b$ intersects the beginning of $a$, then you can choose the segment with the minimal right end as the segment $b$ — the intersection of such a segment with $a$ will be no greater than the intersection of $b$ with $a$. Similarly, for the right end, you can select the segment with the maximal left end. If the answer has one segment in another, then you can consider the shortest segment in the set as the inner segment. If the segments in the answer do not intersect, then the segment does not intersect one of the "edge" segments.

Thus, to find the segment with which it has the minimum intersection for a given segment, you need to check 3 candidates: the shortest segment in the set, the segment with the minimal right end, and the one with the maximal left end. In total, to find the answer, you need to check $3n$ pairs of segments.

 
### [1834E - MEX of LCM](../problems/E._MEX_of_LCM.md "Codeforces Round 879 (Div. 2)")

Notice that the MEX of $n^2$ numbers will not exceed $n^2+1$. Let's calculate all possible LCM values on segments that do not exceed $n^2$. To do this, we will iterate over the right endpoint of the segments and maintain a set of different LCM values on segments with such a right endpoint.

Let these values be $x_1 < x_2 < \ldots < x_k$. Then $k \leq 1 + 2\log_2n$, indeed, for each $1 \leq i < k$, it is true that $x_{i+1}$ is divisible by $x_i$, and therefore $x_{i+1} \geq 2x_i$, that is, $n^2 \geq x^2 \geq 2^{k-1}$, from which the required follows. That is, the values $x_1, \ldots, x_k$ can be stored naively in some dynamic array. Now suppose we want to move the right endpoint, then the array $(x_1, \ldots, x_k)$ should be replaced by $([x_1, a_r], \ldots, [x_k, a_k], a_k)$ and remove values greater than $n^2+1$ from the new array, as well as get rid of duplicates.

All these actions can be performed in $O(n \log n)$ time, after which we just need to find the MEX among the known set of values. This solution can also serve as proof that the desired MEX does not exceed $n \cdot (1 + 2 \log_2 n)$, which is less than $10^9$ under the constraints of the problem. Thus, initially, we can only maintain numbers less than $10^9$ and not worry about overflows of a 64-bit integer type.

 
### [1834F - Typewriter](../problems/F._Typewriter.md "Codeforces Round 879 (Div. 2)")

Let's solve the problem if there are no requests. The key object for us will be such cells that the number in them is less than the cell index. Note that for one carriage reset, we can transfer no more than one such number. So we have a lower bound on the answer.

Let's build a graph with edges $i\rightarrow a[i]$. Then it will break up into cycles. Let's find the first position where $a[i] \neq i$, take a number from this position, shift it to $a[i]$, take a number from position $a[i]$, and so on. Then we will put the whole cycle in its place. How many carriage drops will there be? Exactly as many edges as there are such that $a[i] < i$. That is, the answer is exactly equal to the number of positions where $a[i] < i$.

Let's learn how to solve for shifts. Let's find for each cell such positions of the beginning of the array that it will satisfy $a[i] < i$ in this configuration. It is easy to see that for a particular cell, such indexes will form a segment (possibly a prefix + suffix). Let's create a separate array and add one on these segments. Then in the i-th position there will be an answer if the array starts from the i-th cell.

Now let's solve for an array flip. It is easy to see that for this you can simply maintain the entire previous structure, but with the inverted original configuration of cells. Asymptotic: $O(n + q)$.

