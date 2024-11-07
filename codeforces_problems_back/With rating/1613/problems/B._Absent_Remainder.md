<h1 style='text-align: center;'> B. Absent Remainder</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence $a_1, a_2, \dots, a_n$ consisting of $n$ pairwise distinct positive integers.

Find $\left\lfloor \frac n 2 \right\rfloor$ different pairs of integers $x$ and $y$ such that: 

* $x \neq y$;
* $x$ and $y$ appear in $a$;
* $x~mod~y$ doesn't appear in $a$.

## Note

 that some $x$ or $y$ can belong to multiple pairs.

$\lfloor x \rfloor$ denotes the floor function — the largest integer less than or equal to $x$. $x~mod~y$ denotes the remainder from dividing $x$ by $y$.

If there are multiple solutions, print any of them. It can be shown that at least one solution always exists.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the length of the sequence.

The second line of each testcase contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$).

All numbers in the sequence are pairwise distinct. The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

The answer for each testcase should contain $\left\lfloor \frac n 2 \right\rfloor$ different pairs of integers $x$ and $y$ such that $x \neq y$, $x$ and $y$ appear in $a$ and $x~mod~y$ doesn't appear in $a$. Print the pairs one after another.

You can print the pairs in any order. However, the order of numbers in the pair should be exactly such that the first number is $x$ and the second number is $y$. All pairs should be pairwise distinct.

If there are multiple solutions, print any of them.

## Example

## Input


```

4
2
1 4
4
2 8 3 4
5
3 8 5 9 7
6
2 7 5 3 4 8

```
## Output


```

4 1
8 2
8 4
9 5
7 5
8 7
4 3
5 2
```
## Note

In the first testcase there are only two pairs: $(1, 4)$ and $(4, 1)$. $\left\lfloor \frac 2 2 \right\rfloor=1$, so we have to find one pair. $1~mod~4=1$, and $1$ appears in $a$, so that pair is invalid. Thus, the only possible answer is a pair $(4, 1)$.

In the second testcase, we chose pairs $8~mod~2=0$ and $8~mod~4=0$. $0$ doesn't appear in $a$, so that answer is valid. There are multiple possible answers for that testcase.

In the third testcase, the chosen pairs are $9~mod~5=4$ and $7~mod~5=2$. Neither $4$, nor $2$, appears in $a$, so that answer is valid.



#### tags 

#1000 #greedy #implementation #sortings 