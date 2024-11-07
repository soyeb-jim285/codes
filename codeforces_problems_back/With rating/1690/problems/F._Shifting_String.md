<h1 style='text-align: center;'> F. Shifting String</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp found the string $s$ and the permutation $p$. Their lengths turned out to be the same and equal to $n$.

A permutation of $n$ elements — is an array of length $n$, in which every integer from $1$ to $n$ occurs exactly once. For example, $[1, 2, 3]$ and $[4, 3, 5, 1, 2]$ are permutations, but $[1, 2, 4]$, $[4, 3, 2, 1, 2]$ and $[0, 1, 2]$ are not.

In one operation he can multiply $s$ by $p$, so he replaces $s$ with string $new$, in which for any $i$ from $1$ to $n$ it is true that $new_i = s_{p_i}$. For example, with $s=wmbe$ and $p = [3, 1, 4, 2]$, after operation the string will turn to $s=s_3 s_1 s_4 s_2=bwem$.

Polycarp wondered after how many operations the string would become equal to its initial value for the first time. Since it may take too long, he asks for your help in this matter.

It can be proved that the required number of operations always exists. It can be very large, so use a 64-bit integer type. 

## Input

The first line of input contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases in input.

The first line of each case contains single integer $n$ ($1 \le n \le 200$) — the length of string and permutation.

The second line of each case contains a string $s$ of length $n$, containing lowercase Latin letters.

The third line of each case contains $n$ integers — permutation $p$ ($1 \le p_i \le n$), all $p_i$ are different.

## Output

## Output

 $t$ lines, each of which contains the answer to the corresponding test case of input. As an answer output single integer — the minimum number of operations, after which the string $s$ will become the same as it was before operations.

## Example

## Input


```

35ababa3 4 5 2 15ababa2 1 4 5 310codeforces8 6 1 7 5 2 9 3 10 4
```
## Output


```

1
6
12

```
## Note

In the first sample operation doesn't change the string, so it will become the same as it was after $1$ operations.

In the second sample the string will change as follows:

* $s$ = babaa
* $s$ = abaab
* $s$ = baaba
* $s$ = abbaa
* $s$ = baaab
* $s$ = ababa


#### tags 

#1700 #graphs #math #number_theory #strings 