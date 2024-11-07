<h1 style='text-align: center;'> B. Mathematics Curriculum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $c_1, c_2, \ldots, c_n$ be a permutation of integers $1, 2, \ldots, n$. Consider all subsegments of this permutation containing an integer $x$. Given an integer $m$, we call the integer $x$ good if there are exactly $m$ different values of maximum on these subsegments.

Cirno is studying mathematics, and the teacher asks her to count the number of permutations of length $n$ with exactly $k$ good numbers.

Unfortunately, Cirno isn't good at mathematics, and she can't answer this question. Therefore, she asks you for help.

Since the answer may be very big, you only need to tell her the number of permutations modulo $p$.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

A sequence $a$ is a subsegment of a sequence $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

###### Input

The first line contains four integers $n, m, k, p$ ($1 \le n \le 100, 1 \le m \le n, 1 \le k \le n, 1 \le p \le 10^9$).

###### Output

###### Output

 the number of permutations modulo $p$.

## Examples

###### Input


```text
4 3 2 10007
```
###### Output


```text
4
```
###### Input


```text
6 4 1 769626776
```
###### Output


```text
472
```
###### Input


```text
66 11 9 786747482
```
###### Output


```text
206331312
```
###### Input


```text
99 30 18 650457567
```
###### Output


```text
77365367
```
## Note

In the first test case, there are four permutations: $[1, 3, 2, 4]$, $[2, 3, 1, 4]$, $[4, 1, 3, 2]$ and $[4, 2, 3, 1]$.

Take permutation $[1, 3, 2, 4]$ as an example:

For number $1$, all subsegments containing it are: $[1]$, $[1, 3]$, $[1, 3, 2]$ and $[1, 3, 2, 4]$, and there're three different maxima $1$, $3$ and $4$.

Similarly, for number $3$, there're two different maxima $3$ and $4$. For number $2$, there're three different maxima $2$, $3$ and $4$. And for number $4$, there're only one, that is $4$ itself.



#### Tags 

#2600 #NOT OK #brute_force #combinatorics #dp #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_745_(Div._1).md)
- [Codeforces Round #745 (en)](../blogs/Codeforces_Round_745_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
