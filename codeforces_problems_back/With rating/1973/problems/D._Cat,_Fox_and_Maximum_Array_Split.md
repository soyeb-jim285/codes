<h1 style='text-align: center;'> D. Cat, Fox and Maximum Array Split</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Fox gave Cat two positive integers $n$ and $k$. She has a hidden array $a_1, \ldots , a_n$ of length $n$, such that $1 \leq a_i \leq n$ for every $i$. Now they are going to play the following game:

For any two integers $l, r$ such that $1 \leq l \leq r \leq n$, define $f(l, r) = (r - l + 1) \cdot \max\limits_{x=l}^r a_x$. In other words, $f(l, r)$ is equal to the maximum of the subarray $a_l, \ldots, a_r$ multiplied by its size.

Cat can ask Fox at most $2 n$ questions about the array. He will tell her two integers $l$ and $x$ ($1 \leq l \leq n, 1 \leq x \leq 10^9$), and she will tell him one integer $p$ as the answer — the smallest positive integer $r$ such that $f(l, r) = x$, or $n+1$ if no such $r$ exists.

Now, Cat needs to find the largest value $m$ such that there exists a sequence $c_1, \ldots, c_{k-1}$ such that $1 \leq c_1 < \ldots < c_{k-1} < n$ and $f(1, c_1) = f(c_1 + 1, c_2) = \ldots = f(c_{k-1}+1, n) = m$. If no such $m$ exists, he should indicate this and take $-1$ as the answer. ## Note

 that for $k = 1$, $m$ is always equal to $f(1, n)$.

In other words, the goal is to find the largest $m$ such that you can split the array into exactly $k$ subarrays ($k$ is the constant given to you in the beginning of the interaction) so that all the subarrays have the product of their length and their maximum equal to $m$, or determine that no such $m$ exists. Every element should belong in exactly one of the subarrays.

Cat doesn't know what he should do, so he asked you to play the game for him.

## Interaction

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two positive integers $n$ and $k$ ($1 \leq k \leq n \leq 10^4$) — the length of the hidden array and the number of subarrays in the desired split.

Now you are allowed to make queries in the following way — print one line of the form "$\mathtt{?} \ l \ x$" (it must hold that $1 \leq l \leq n$, $1 \leq x \leq 10^9$) and you will receive the smallest integer $r$ such that $l \leq r \leq n$ and $f(l, r) = x$, or $n + 1$ if no such $r$ exists. 

If you want to print the answer, output "$\mathtt{!} \ m$" and you will recieve $1$ if your answer is correct and $-1$ otherwise. In the first case, the interaction continues with the next test case. ## Note

 that printing the answer doesn't count towards the number of queries made. Please note that you don't receive the values for the next test case immediately, you will first have to read whether your answer to the last test case was correct. 

If you receive the integer $-1$ at any moment, it means your program has made an invalid query, exceeded the query limit, or gave an incorrect answer. Your program must terminate immediately to receive a Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream. 

After printing a query, do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

It is guaranteed that the total sum of $n$ over the test cases won't exceed $10^4$.

Hacks

The format of the hacks should be the following: the first line should contain one integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The description of the test cases should follow.

The first line of each test case should contain two integers $n$ and $k$ ($1 \leq k \leq n \leq 10^4$) — the length of the array $a$ and the number of subarrays you want to split it into.

The second line should contain $n$ integers $a_1, a_2, \ldots, a_n $ ($1 \leq a_i \leq n $). 

The sum of $n$ over all test cases should not exceed $10^4$.

## Example

Input
```

3
1 1

1
2 2

1

3

1
6 3

7

2

3

6

1
```
Output
```

! 1


? 1 1

? 2 1

! -1


? 1 9

? 1 6

? 3 6

? 4 6

! 6
```
## Note

The hidden arrays in the three testcases are $[1]$, $[1, 2]$ and $[1, 3, 6, 1, 2, 1]$. In the second testcase, no split satisfies the constraints, so the answer is $-1$. 

The answer for the first query of the third testcase is $7$ since no valid $r$ exists. For the second query of the third testcase, since $2 \cdot \max(1, 3) = 6$, we will get $2$ as the answer, since $r = 1$ doesn't satisfy the constraint.

The sample interaction guessed all three answers ($1, -1$ and $6$) correctly, so it received $1$ after each answer.



#### tags 

#2400 #brute_force #interactive #math 