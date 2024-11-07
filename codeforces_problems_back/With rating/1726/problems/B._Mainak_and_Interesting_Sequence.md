<h1 style='text-align: center;'> B. Mainak and Interesting Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mainak has two positive integers $n$ and $m$.

Mainak finds a sequence $a_1, a_2, \ldots, a_n$ of $n$ positive integers interesting, if for all integers $i$ ($1 \le i \le n$), the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all elements in $a$ which are strictly less than $a_i$ is $0$. Formally if $p_i$ is the bitwise XOR of all elements in $a$ which are strictly less than $a_i$, then $a$ is an interesting sequence if $p_1 = p_2 = \ldots = p_n = 0$.

For example, sequences $[1,3,2,3,1,2,3]$, $[4,4,4,4]$, $[25]$ are interesting, whereas $[1,2,3,4]$ ($p_2 = 1 \ne 0$), $[4,1,1,2,4]$ ($p_1 = 1 \oplus 1 \oplus 2 = 2 \ne 0$), $[29,30,30]$ ($p_2 = 29 \ne 0$) aren't interesting.

Here $a \oplus b$ denotes bitwise XOR of integers $a$ and $b$.

Find any interesting sequence $a_1, a_2, \ldots, a_n$ (or report that there exists no such sequence) such that the sum of the elements in the sequence $a$ is equal to $m$, i.e. $a_1 + a_2 \ldots + a_n = m$.

As a reminder, the bitwise XOR of an empty sequence is considered to be $0$.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Description of the test cases follows.

The first line and the only line of each test case contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $1 \le m \le 10^9$) — the length of the sequence and the sum of the elements.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, if there exists some interesting sequence, output "Yes" on the first line, otherwise output "No". You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

If the answer is "Yes", output $n$ positive integers $a_1, a_2, \ldots, a_n$ ($a_i \ge 1$), forming an interesting sequence such that $a_1 + a_2 \ldots + a_n = m$. If there are multiple solutions, output any.

## Example

## Input


```

4
1 3
6 12
2 1
3 6

```
## Output


```

Yes
3
Yes
1 3 2 2 3 1
No
Yes
2 2 2

```
## Note

* In the first test case, $[3]$ is the only interesting sequence of length $1$ having sum $3$.
* In the third test case, there is no sequence of length $2$ having sum of elements equal to $1$, so there is no such interesting sequence.
* In the fourth test case, $p_1 = p_2 = p_3 = 0$, because bitwise XOR of an empty sequence is $0$.


#### tags 

#1100 #bitmasks #constructive_algorithms #math 