<h1 style='text-align: center;'> C. Vlad Building Beautiful Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad was given an array $a$ of $n$ positive integers. Now he wants to build a beautiful array $b$ of length $n$ from it.

Vlad considers an array beautiful if all the numbers in it are positive and have the same parity. That is, all numbers in the beautiful array are greater than zero and are either all even or all odd.

To build the array $b$, Vlad can assign each $b_i$ either the value $a_i$ or $a_i - a_j$, where any $j$ from $1$ to $n$ can be chosen.

To avoid trying to do the impossible, Vlad asks you to determine whether it is possible to build a beautiful array $b$ of length $n$ using his array $a$.

## Input

The first line of input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each case contains $n$ positive integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all cases does not exceed $2 \cdot 10^5$.

## Output

## Output

 $t$ strings, each of which is the answer to the corresponding test case. As the answer, output "YES" if Vlad can build a beautiful array $b$, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

## Input


```

752 6 8 4 351 4 7 6 942 6 4 1075 29 13 9 10000001 11 352 1 2 4 252 4 5 4 342 5 5 4
```
## Output


```

NO
YES
YES
YES
YES
NO
NO

```


#### tags 

#800 #greedy #math 