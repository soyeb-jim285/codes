<h1 style='text-align: center;'> C. Interesting Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya and his friend, robot Petya++, like to solve exciting math problems.

One day Petya++ came up with the numbers $n$ and $x$ and wrote the following equality on the board: $$n\ \\&\ (n+1)\ \\&\ \dots\ \\&\ m = x,$$ where $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND). Then he suggested his friend Petya find such a minimal $m$ ($m \ge n$) that the equality on the board holds.

Unfortunately, Petya couldn't solve this problem in his head and decided to ask for computer help. He quickly wrote a program and found the answer.

Can you solve this difficult problem?

 ![](images/031794267bde972f35f17902ed959e8302b26c14.png) ## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2000$). The description of the test cases follows.

The only line of each test case contains two integers $n$, $x$ ($0\le n, x \le 10^{18}$).

## Output

For every test case, output the smallest possible value of $m$ such that equality holds.

If the equality does not hold for any $m$, print $-1$ instead.

We can show that if the required $m$ exists, it does not exceed $5 \cdot 10^{18}$.

## Example

## Input


```

510 810 1010 4220 161000000000000000000 0
```
## Output


```

12
10
-1
24
1152921504606846976

```
## Note

In the first example, $10\ \\&\ 11 = 10$, but $10\ \\&\ 11\ \\&\ 12 = 8$, so the answer is $12$.

In the second example, $10 = 10$, so the answer is $10$.

In the third example, we can see that the required $m$ does not exist, so we have to print $-1$.



#### tags 

#1600 #bitmasks #math 