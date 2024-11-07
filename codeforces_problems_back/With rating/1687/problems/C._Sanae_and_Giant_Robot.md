<h1 style='text-align: center;'> C. Sanae and Giant Robot</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Is it really?! The robot only existing in my imagination?! The Colossal Walking Robot?!!— Kochiya Sanae Sanae made a giant robot — Hisoutensoku, but something is wrong with it. To make matters worse, Sanae can not figure out how to stop it, and she is forced to fix it on-the-fly.The state of a robot can be represented by an array of integers of length $n$. Initially, the robot is at state $a$. She wishes to turn it into state $b$. 

As a great programmer, Sanae knows the art of copy-and-paste. In one operation, she can choose some segment from given segments, copy the segment from $b$ and paste it into the same place of the robot, replacing the original state there. However, she has to ensure that the sum of $a$ does not change after each copy operation in case the robot go haywire. Formally, Sanae can choose segment $[l,r]$ and assign $a_i = b_i$ ($l\le i\le r$) if $\sum\limits_{i=1}^n a_i$ does not change after the operation.

Determine whether it is possible for Sanae to successfully turn the robot from the initial state $a$ to the desired state $b$ with any (possibly, zero) operations.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2\cdot 10^4$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains two integers $n$, $m$ ($2 \leq n\leq 2\cdot 10^5$, $1 \leq m\leq 2\cdot 10^5$) — the length of $a$, $b$ and the number of segments.

The second line contains $n$ intergers $a_1,a_2,\ldots,a_n$ ($1 \leq a_i \leq 10^9$) — the initial state $a$.

The third line contains $n$ intergers $b_1,b_2,\ldots,b_n$ ($1 \leq b_i \leq 10^9$) — the desired state $b$.

Then $m$ lines follow, the $i$-th line contains two intergers $l_i,r_i$ ($1 \leq l_i < r_i \leq n$) — the segments that can be copy-pasted by Sanae.

It is guaranteed that both the sum of $n$ and the sum of $m$ over all test cases does not exceed $2 \cdot 10 ^ 5$.

## Output

For each test case, print "YES" (without quotes) if $a$ can be turned into $b$, or "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

25 21 5 4 2 33 2 5 4 11 32 55 21 5 4 2 33 2 4 5 11 22 4
```
## Output


```

YES
NO

```
## Note

Test case 1:

One possible way of turning $a$ to $b$:

First, select $[1,3]$. After the operation, $a=[3,2,5,2,3]$.

Then, select $[2,5]$. After the operation, $a=[3,2,5,4,1]=b$.

Test case 2:

It can be shown that it is impossible to turn $a$ into $b$. 



#### tags 

#2500 #binary_search #brute_force #data_structures #dsu #greedy #sortings 