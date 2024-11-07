<h1 style='text-align: center;'> E. Sofia and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sofia has a string $s$ of length $n$, consisting only of lowercase English letters. She can perform operations of the following types with this string.

1. Select an index $1 \le i \le |s|$ and remove the character $s_i$ from the string.
2. Select a pair of indices $(l, r)$ ($1 \le l \le r \le |s|$) and sort the substring $s_{l} s_{l+1} \ldots s_r$ in alphabetical order.

 Here, $|s|$ denotes the current length of $s$. In particular, $|s| = n$ before the first operation. For example, if $s = \mathtt{sofia}$, then performing the operation of the first type with $i=4$ results in $s$ becoming $\mathtt{sofa}$, and performing the operation of the second type with $(l, r) = (2, 4)$ after that results in $s$ becoming $\mathtt{safo}$.Sofia wants to obtain the string $t$ of length $m$ after performing zero or more operations on string $s$ as described above. Please determine whether it is possible or not.

## Input

The first line contains one integer $t$ ($1 \leq t \leq 10\,000$) — the number of test cases.

The first line of each test case contains two integers $n$, $m$ ($1\leq m \leq n \leq 2\cdot 10^5$) — the lengths of string $s$ and $t$, respectively.

The second line of each test case contains the string $s$ of length $n$, consisting only of lowercase English letters.

The third line of each test case contains the string $t$ of length $m$, consisting only of lowercase English letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, output "YES" if Sofia can obtain the string $t$ from $s$ using the operations above. Otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

## Input


```

85 5sofiaafios3 2cbabc5 1sofiae15 7anavolimilovanaaamanan26 4abcdefghijklmnopqrstuvwxyznope26 4zyxwvutsrqponmlkjihgfedcbanope7 3apricotcat3 3cbaacb
```
## Output


```

YES
YES
NO
YES
NO
YES
NO
YES

```
## Note

In the first test case, Sofia can perform the following operation: 

1. operation of the second type with $l=1$ and $r=5$: string $s$ becomes $\mathtt{afios}$ after it.

In the second test case, Sofia can perform the following operations: 

1. operation of the second type with $l=1$ and $r=2$: string $s$ becomes $\mathtt{bca}$ after it;
2. operation of the first type with $i=3$: string $s$ becomes $\mathtt{bc}$ after it.

In the third test case, it can be shown that it is impossible to obtain $t$ from $s$ using the provided operations.



#### tags 

#2200 #data_structures #greedy #sortings #strings #two_pointers 