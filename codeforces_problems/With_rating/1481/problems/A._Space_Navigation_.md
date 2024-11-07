<h1 style='text-align: center;'> A. Space Navigation </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You were dreaming that you are traveling to a planet named Planetforces on your personal spaceship. Unfortunately, its piloting system was corrupted and now you need to fix it in order to reach Planetforces.

 ![](images/568c62f260f1415f25de67de3c3378cf28d9b1ed.png) Space can be represented as the $XY$ plane. You are starting at point $(0, 0)$, and Planetforces is located in point $(p_x, p_y)$.

The piloting system of your spaceship follows its list of orders which can be represented as a string $s$. The system reads $s$ from left to right. Suppose you are at point $(x, y)$ and current order is $s_i$: 

* if $s_i = \text{U}$, you move to $(x, y + 1)$;
* if $s_i = \text{D}$, you move to $(x, y - 1)$;
* if $s_i = \text{R}$, you move to $(x + 1, y)$;
* if $s_i = \text{L}$, you move to $(x - 1, y)$.

Since string $s$ could be corrupted, there is a possibility that you won't reach Planetforces in the end. Fortunately, you can delete some orders from $s$ but you can't change their positions.

Can you delete several orders (possibly, zero) from $s$ in such a way, that you'll reach Planetforces after the system processes all orders?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case consists of two lines. The first line in each test case contains two integers $p_x$ and $p_y$ ($-10^5 \le p_x, p_y \le 10^5$; $(p_x, p_y) \neq (0, 0)$) — the coordinates of Planetforces $(p_x, p_y)$.

The second line contains the string $s$ ($1 \le |s| \le 10^5$: $|s|$ is the length of string $s$) — the list of orders.

It is guaranteed that the sum of $|s|$ over all test cases does not exceed $10^5$.

### Output

For each test case, print "YES" if you can delete several orders (possibly, zero) from $s$ in such a way, that you'll reach Planetforces. Otherwise, print "NO". You can print each letter in any case (upper or lower).

## Example

### Input


```text
6
10 5
RRRRRRRRRRUUUUU
1 1
UDDDRLLL
-3 -5
LDLDLDDDR
1 2
LLLLUU
3 -2
RDULRLLDR
-1 6
RUDURUUUUR
```
### Output


```text
YES
YES
YES
NO
YES
NO
```
## Note

In the first case, you don't need to modify $s$, since the given $s$ will bring you to Planetforces.

In the second case, you can delete orders $s_2$, $s_3$, $s_4$, $s_6$, $s_7$ and $s_8$, so $s$ becomes equal to "UR".

In the third test case, you have to delete order $s_9$, otherwise, you won't finish in the position of Planetforces.



#### Tags 

#800 #NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_699_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
