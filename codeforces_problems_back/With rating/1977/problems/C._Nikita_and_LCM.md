<h1 style='text-align: center;'> C. Nikita and LCM</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nikita is a student passionate about number theory and algorithms. He faces an interesting problem related to an array of numbers.

Suppose Nikita has an array of integers $a$ of length $n$. He will call a subsequence$^\dagger$ of the array special if its [least common multiple (LCM)](https://en.wikipedia.org/wiki/Least_common_multiple) is not contained in $a$. The LCM of an empty subsequence is equal to $0$.

Nikita wonders: what is the length of the longest special subsequence of $a$? Help him answer this question!

$^\dagger$ A sequence $b$ is a subsequence of $a$ if $b$ can be obtained from $a$ by the deletion of several (possibly, zero or all) elements, without changing the order of the remaining elements. For example, $[5,2,3]$ is a subsequence of $[1,5,7,8,2,4,3]$.

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 2000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2000$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

## Output

For each test case, output a single integer — the length of the longest special subsequence of $a$.

## Example

## Input


```

651 2 4 8 1663 2 10 20 60 172 3 4 6 12 100003 120003692 42 7 3 6 7 7 1 684 99 57 179 10203 2 11 4081211
```
## Output


```

0
4
4
5
8
0

```
## Note

In the first test case, the LCM of any non-empty subsequence is contained in $a$, so the answer is $0$.

In the second test case, we can take the subsequence $[3, 2, 10, 1]$, its LCM is equal to $30$, which is not contained in $a$.

In the third test case, we can take the subsequence $[2, 3, 6, 100\,003]$, its LCM is equal to $600\,018$, which is not contained in $a$.



#### tags 

#1900 #brute_force #data_structures #dp #greedy #math #number_theory #sortings 