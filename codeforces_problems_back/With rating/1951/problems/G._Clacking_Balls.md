<h1 style='text-align: center;'> G. Clacking Balls</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Rammstein - Ausländer](https://youtu.be/3eEA6H_y1VI)ඞThere are $m$ baskets placed along a circle, numbered from $1$ to $m$ in clockwise order (basket $m$ is next to basket $1$). Furthermore, there are $n$ balls, where ball $i$ is initially placed in basket $a_i$, and no basket contains more than one ball.

Alice is allowed to perform the following operation, which always takes exactly one second whether you move/throw a ball or not: 

* Alice chooses an integer $i$ between $1$ and $n$ uniformly at random.
* If ball $i$ was thrown away before, do nothing.
* Otherwise, ball $i$ is moved from the basket currently containing it to the next basket (in clockwise order). If the target basket currently contains another ball $j$, throw ball $j$ away.

She repeats this operation until there is exactly one ball left. Calculate the expected time needed (in seconds) for Alice to end the process.

It can be proven that the answer can be represented as a rational number $\frac{p}{q}$ with coprime $p$ and $q$. You need to output $p \cdot q^{-1} \bmod 10^9 + 7$. It can be proven that $10^9 + 7 \nmid q$.

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le 3 \cdot 10^5, n \le m \le 10^9$) — the number of balls and the number of baskets.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le m$, $a_i$'s are pairwise distinct) — the initial position of each ball.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, print one integer: the expected amount of time (in seconds) Alice needs to end the process, modulo $10^9 + 7$.

## Example

## Input


```

53 105 1 42 1515 16 61 2 3 4 5 66 96 5 4 3 2 11 10069
```
## Output


```

600000042
14
35
333333409
0

```
## Note

In the first test case, Alice could have proceeded as follows (we define $a_i = -1$ if ball $i$ has been thrown out): 

* Initially, $a = [5, 1, 4]$.
* Alice chooses $i = 2$ with probability $\frac{1}{3}$, and ball $2$ is moved to basket $2$. After this, $a = [5, 2, 4]$.
* Alice chooses $i = 2$ with probability $\frac{1}{3}$, and ball $2$ is moved to basket $3$. After this, $a = [5, 3, 4]$.
* Alice chooses $i = 2$ with probability $\frac{1}{3}$, and ball $2$ is moved to basket $4$. As basket $4$ previously contains ball $3$, this ball is thrown out. After this, $a = [5, 4, -1]$.
* Alice chooses $i = 3$ with probability $\frac{1}{3}$. Ball $3$ has already been thrown out, so nothing happens. After this, $a = [5, 4, -1]$.
* Alice chooses $i = 2$ with probability $\frac{1}{3}$, and ball $2$ is moved to basket $5$, which throws out ball $1$. After this, $a = [-1, 5, -1]$, and the process ends.

 The answer for this test case is $\frac{189}{5}$.The answer for the second test case is $14$ (note that these two balls are next to each other).

The answer for the third test case is $35$.

The answer for the fourth test case is $\frac{220}{3}$.

In the fifth test case, as there is only one ball initially, the answer is $0$.



#### tags 

#3100 #combinatorics #math #probabilities 