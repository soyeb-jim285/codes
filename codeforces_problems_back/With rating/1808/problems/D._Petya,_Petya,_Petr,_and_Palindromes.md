<h1 style='text-align: center;'> D. Petya, Petya, Petr, and Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya and his friend, the robot Petya++, have a common friend — the cyborg Petr#. Sometimes Petr# comes to the friends for a cup of tea and tells them interesting problems.

Today, Petr# told them the following problem.

A palindrome is a sequence that reads the same from left to right as from right to left. For example, $[38, 12, 8, 12, 38]$, $[1]$, and $[3, 8, 8, 3]$ are palindromes.

Let's call the palindromicity of a sequence $a_1, a_2, \dots, a_n$ the minimum count of elements that need to be replaced to make this sequence a palindrome. For example, the palindromicity of the sequence $[38, 12, 8, 38, 38]$ is $1$ since it is sufficient to replace the number $38$ at the fourth position with the number $12$. And the palindromicity of the sequence $[3, 3, 5, 5, 5]$ is two since you can replace the first two threes with fives, and the resulting sequence $[5, 5, 5, 5, 5]$ is a palindrome.

Given a sequence $a$ of length $n$, and an odd integer $k$, you need to find the sum of palindromicity of all subarrays of length $k$, i. e., the sum of the palindromicity values for the sequences $a_i, a_{i+1}, \dots, a_{i+k-1}$ for all $i$ from $1$ to $n-k+1$.

The students quickly solved the problem. Can you do it too?

 ![](images/379c2d1eded22e3073b56466b9aa3830e8caa4d5.png) ## Input

The first line of the input contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$, $1 \le k \le n$, $k$ is odd) — the length of the sequence and the length of subarrays for which it is necessary to determine whether they are palindromes.

The second line of the input contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 2 \cdot 10^5$) — the sequence itself.

## Output

## Output

 a single integer — the total palindromicity of all subarrays of length $k$.

## Examples

## Input


```

8 5
1 2 8 2 5 2 8 6

```
## Output


```

4

```
## Input


```

9 9
1 2 3 4 5 4 3 2 1

```
## Output


```

0

```
## Note

In the first example, the palindromicity of the subarray $[1, 2, 8, 2, 5]$ is $1$, the palindromicity of the string $[2, 8, 2, 5, 2]$ is also $1$, the palindromicity of the string $[8, 2, 5, 2, 8]$ is $0$, and the palindromicity of the string $[2, 5, 2, 8, 6]$ is $2$. The total palindromicity is $1+1+0+2 = 4$.

In the second example, the only substring of length $9$ coincides with the entire string, and its palindromicity is $0$, so the answer is also $0$.



#### tags 

#2100 #binary_search #brute_force #data_structures #two_pointers 