<h1 style='text-align: center;'> F. Koxia and Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mari has three integers $n$, $x$, and $y$.

Call an array $a$ of $n$ non-negative integers good if it satisfies the following conditions:

* $a_1+a_2+\ldots+a_n=x$, and
* $a_1 \, | \, a_2 \, | \, \ldots \, | \, a_n=y$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

The score of a good array is the value of $a_1 \oplus a_2 \oplus \ldots \oplus a_n$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Koxia wants you to find the total bitwise XOR of the scores of all good arrays. If there are no good arrays, output $0$ instead.

##### Input

The first line of input contains three integers $n$, $x$ and $y$ ($1 \leq n < 2^{40}$, $0 \leq x < 2^{60}$, $0 \leq y < 2^{20}$).

##### Output

##### Output

 a single integer — the total bitwise XOR of the scores of all good arrays.

## Examples

##### Input


```text
3 5 3
```
##### Output


```text
2
```
##### Input


```text
100 0 100
```
##### Output


```text
0
```
##### Input


```text
79877974817 749875791743978 982783
```
##### Output


```text
64
```
## Note

In the first test case, there are $12$ good arrays totally as follows.

* $[0,2,3]$, $[0,3,2]$, $[2,0,3]$, $[2,3,0]$, $[3,0,2]$ and $[3,2,0]$ — the score is $0 \oplus 2 \oplus 3 = 1$;
* $[1, 2, 2]$, $[2, 1, 2]$ and $[2, 2, 1]$ — the score is $1 \oplus 2 \oplus 2 = 1$;
* $[1, 1, 3]$, $[1, 3, 1]$ and $[3, 1, 1]$ — the score is $1 \oplus 1 \oplus 3 = 3$.

Therefore, the total bitwise xor of the scores is $\underbrace{1 \oplus \ldots \oplus 1}_{9\text{ times}} \oplus 3 \oplus 3 \oplus 3 = 2$.

In the second test case, there are no good sequences. The output should be $0$.



#### Tags 

#3100 #NOT OK #bitmasks #combinatorics #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Good_Bye_2022:_2023_is_NEAR.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
