<h1 style='text-align: center;'> E. Triangle Platinum?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Made in Heaven is a rather curious Stand. Of course, it is (arguably) the strongest Stand in existence, but it is also an ardent puzzle enjoyer. For example, it gave Qtaro the following problem recently:

Made in Heaven has $n$ hidden integers $a_1, a_2, \dots, a_n$ ($3 \le n \le 5000$, $1 \le a_i \le 4$). Qtaro must determine all the $a_i$ by asking Made in Heaven some queries of the following form: 

* In one query Qtaro is allowed to give Made in Heaven three distinct indexes $i$, $j$ and $k$ ($1 \leq i, j, k \leq n$).
* If $a_i, a_j, a_k$ form the sides of a non-degenerate triangle$^\dagger$, Made in Heaven will respond with the area of this triangle.
* Otherwise, Made in Heaven will respond with $0$.

By asking at most $5500$ such questions, Qtaro must either tell Made in Heaven all the values of the $a_i$, or report that it is not possible to uniquely determine them.

Unfortunately due to the universe reboot, Qtaro is not as smart as Jotaro. Please help Qtaro solve Made In Heaven's problem. 

 —————————————————————— $^\dagger$ Three positive integers $a, b, c$ are said to form the sides of a non-degenerate triangle if and only if all of the following three inequalities hold: 

* $a+b > c$,
* $b+c > a$,
* $c+a > b$.
## Interaction

The interaction begins with reading $n$ ($3 \le n \le 5000$), the number of hidden integers. 

To ask a question corresponding to the triple $(i, j, k)$ ($1 \leq i < j < k \leq n$), output "? $i$ $j$ $k$" without quotes. Afterward, you should read a single integer $s$. 

* If $s = 0$, then $a_i$, $a_j$, and $a_k$ are not the sides of a non-degenerate triangle.
* Otherwise, $s = 16 \Delta^2$, where $\Delta$ is the area of the triangle. The area is provided in this format for your convenience so that you need only take integer input.

If the numbers $a_i$ cannot be uniquely determined print "! $-1$" without quotes. On the other hand, if you have determined all the values of $a_i$ print "! $a_1$ $a_2$ $\dots$ $a_n$" on a single line.

The interactor is non-adaptive. The hidden array $a_1, a_2, \dots, a_n$ is fixed beforehand and is not changed during the interaction process.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hacks

You can hack a solution with the following input format.

The first line contains a single integer $n$ ($3 \le n \le 5000$) — the number of hidden integers.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 4$) — the hidden array.

## Examples

Input
```

3

63

```
Output
```


? 1 2 3

! -1
```
Input
```

6

0

0

0

63

15

135


```
Output
```

? 1 2 3

? 2 3 4

? 4 5 6

? 1 5 6

? 3 5 6

? 1 2 4

! 3 2 1 4 2 2
```
Input
```


15

3

3

3

3

3

0


```
Output
```



? 1 2 3

? 4 6 7

? 8 9 10

? 11 12 13

? 13 14 15

? 4 5 6

! -1

```
Input
```


15

3

15

0

3

3

3


```
Output
```



? 1 2 3

? 3 4 5

? 4 5 6

? 7 8 9

? 10 11 12

? 13 14 15

! 1 1 1 2 2 4 1 1 1 1 1 1 1 1 1 1

```
Input
```


10

3

48

3

48

63

0



```
Output
```


? 1 3 5

? 4 6 8

? 1 5 9

? 6 8 10

? 4 2 6

? 7 10 8

! 1 3 1 2 1 2 4 2 1 2

```
## Note

In the first example, the interaction process happens as follows:

 

| Stdin | Stdout | Explanation |
| --- | --- | --- |
| 3 |  | Read $n = 3$. There are $3$ hidden integers |
|  | ? 1 2 3 | Ask for the area formed by $a_1$, $a_2$ and $a_3$ |
| 63 |  | Received $16\Delta^2 = 63$. So the area $\Delta = \sqrt{\frac{63}{16}} \approx 1.984313$ |
|  | ! -1 | Answer that there is no unique array satisfying the queries. |

 From the area received, we can deduce that the numbers that forms the triangle are either ($4$, $4$, $1$) or ($3$, $2$, $2$) (in some order). As there are multiple arrays of numbers that satisfy the queries, a unique answer cannot be found.

In the second example, the interaction process happens as follows:

 

| Step | Stdin | Stdout | Explanation |
| --- | --- | --- | --- |
| 1 | 6 |  | Read $n = 6$. There are $6$ hidden integers |
| 2 |  | ? 1 2 3 | Ask for the area formed by $a_1$, $a_2$ and $a_3$ |
| 3 | 0 |  | Does not form a non-degenerate triangle |
| 4 |  | ? 2 3 4 | Ask for the area formed by $a_2$, $a_3$ and $a_4$ |
| 5 | 0 |  | Does not form a non-degenerate triangle |
| 6 |  | ? 4 5 6 | Ask for the area formed by $a_4$, $a_5$ and $a_6$ |
| 7 | 0 |  | Does not form a non-degenerate triangle |
|  |
| 8 |  | ? 1 5 6 | Ask for the area formed by $a_1$, $a_5$ and $a_6$ |
| 9 | 63 |  | Received $16\Delta^2 = 63$. So the area $\Delta = \sqrt{\frac{63}{16}} \approx 1.984313$ |
| 10 |  | ? 3 5 6 | Ask for the area formed by $a_3$, $a_5$ and $a_6$ |
| 11 | 15 |  | Received $16\Delta^2 = 15$. So the area $\Delta = \sqrt{\frac{15}{16}} \approx 0.968245$ |
| 12 |  | ? 1 2 4 | Ask for the area formed by $a_3$, $a_5$ and $a_6$ |
| 13 | 135 |  | Received $16\Delta^2 = 135$. So the area $\Delta = \sqrt{\frac{135}{16}} \approx 2.904738$ |
| 14 |  | ! 3 2 1 4 2 2 | A unique answer is found, which is $a = [3, 2, 1, 4, 2, 2]$. |

 From steps $10$ and $11$, we can deduce that the the multiset $\left\{a_3, a_5, a_6\right\}$ must be $\left\{2, 2, 1\right\}$.

From steps $8$ and $9$, the multiset $\left\{a_1, a_5, a_6\right\}$ must be either $\left\{4, 4, 1\right\}$ or $\left\{3, 2, 2\right\}$.

As $\left\{a_3, a_5, a_6\right\}$ and $\left\{a_1, a_5, a_6\right\}$ share $a_5$ and $a_6$, we conclude that $a_5 = a_6 = 2$, as well as $a_1 = 3$, $a_3 = 1$.

From steps $6$ and $7$, we know that $a_5 = a_6 = 2$, and $a_4$, $a_5$ and $a_6$ cannot form a non-degenerate triangle, hence $a_4 = 4$.

With all the known information, only $a_2 = 2$ satisfies the queries made in steps $2$, $3$, $4$, $5$, $12$ and $13$.

In the third example, one array that satisfies the queries is $[1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]$.



#### tags 

#2900 #brute_force #combinatorics #implementation #interactive #math #probabilities 