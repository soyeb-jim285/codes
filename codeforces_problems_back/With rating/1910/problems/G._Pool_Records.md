<h1 style='text-align: center;'> G. Pool Records</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are swimming in the pool under the guidance of their instructor Monocarp.

The pool can be represented as a segment on the OX-axis from $0$ to $50$. Both Alice and Bob started at moment $0$ at point $0$ with positive real speeds $v_A$ and $v_B$ correspondingly.

Both Alice and Bob swim from $0$ to point $50$, then instantly turn back and swim from $50$ to $0$. At $0$ they turn back again and swim to $50$ and so on.

Monocarp logged all valuable info about Alice and Bob, including moments of time when they met at the same point (Alice and Bob swim on parallel lanes, so they don't bother each other). Let's name that moments of time as sequence $t_1, t_2, \dots, t_n$.

Due to some incident, Monocarp lost almost all data he recorded, and all he has now is array $t$. Monocarp remembers that Alice and Bob had distinct positive real swimming speeds $v_A$ and $v_B$ ($v_A > 0$; $v_B > 0$; $v_A \neq v_B$) and that sequence $t$ contains the first $n$ meeting moments.

But looking at sequence $t$ he noticed that all $t_i$ are integer values, and now he doubts is sequence $t$ valid or there are some errors in it. Help Monocarp to check array $t$!

## Input

The first line contains a single integer $c$ ($1 \le c \le 10^4$) — the number of test cases. Then $c$ cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the size of array $t$.

The second line of each test case contains $n$ integers $t_1, t_2, \dots, t_n$ ($1 \le t_1 < t_2 < \dots < t_n \le 10^9$) — the meeting moments in the increasing order.

It's guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print VALID if the array $t$ is a valid array, or (in other words) exist such real values $v_A$ and $v_B$ ($v_A, v_B > 0$; $v_A \neq v_B$) that array $t$ contains the first $n$ meeting moments of Alice and Bob in the pool.

Otherwise, print INVALID.

You can output the answer in any case (upper or lower). For example, the strings "vALid", "valid", "Valid", and "VALID" will be recognized as positive responses.

## Example

## Input


```

714243 4 6 851 2 3 4 53999999998 999999999 100000000054 6 8 12 1646 11 12 14210 30
```
## Output


```

VALID
VALID
VALID
INVALID
VALID
INVALID
INVALID

```
## Note

In the first test case, imagine a situation: $v_A = 1$ and $v_B = \frac{29}{21}$. Then, at moment $42$ Alice and Bob will be at point $42$.

In the second test case, imagine a situation: $v_A = \frac{175}{6}$ and $v_B = \frac{25}{6}$. Then, at moment $3$ Alice and Bob will meet at point $12.5$, at $4$ they'll meet at point $\frac{50}{3}$, at moment $6$ they'll meet at $25$ and at moment $8$ — at point $\frac{100}{3}$. Since it's exactly the first $4$ meeting moments. Array $t$ may be valid.

In the third test case, one of the possible situations is $v_A = 25$ and $v_B = 75$.



#### tags 

#2700 #*special #greedy 