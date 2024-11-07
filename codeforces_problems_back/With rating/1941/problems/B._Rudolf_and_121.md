<h1 style='text-align: center;'> B. Rudolf and 121</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rudolf has an array $a$ of $n$ integers, the elements are numbered from $1$ to $n$.

In one operation, he can choose an index $i$ ($2 \le i \le n - 1$) and assign:

* $a_{i - 1} = a_{i - 1} - 1$
* $a_i = a_i - 2$
* $a_{i + 1} = a_{i + 1} - 1$

Rudolf can apply this operation any number of times. Any index $i$ can be used zero or more times.

Can he make all the elements of the array equal to zero using this operation?

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the test.

The first line of each case contains a single integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the number of elements in the array.

The second line of each case contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_j \le 10^9$) — the elements of the array.

It is guaranteed that the sum of the values of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" if it is possible to make all the elements of the array zero using the described operations. Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

## Example

## Input


```

751 3 5 5 252 4 4 5 150 1 3 3 165 6 0 2 3 041 2 7 237 1 041 1 1 1
```
## Output


```

YES
NO
YES
NO
NO
NO
NO

```
## Note

In the first example, the original array is $[1, 3, 5, 5, 2]$, to make all its elements zero, Rudolf can act as follows:

* apply the operation at $i=4$ and get the array $[1, 3, 4, 3, 1]$;
* apply the operation at $i=3$ and get the array $[1, 2, 2, 2, 1]$;
* apply the operation at $i=2$ and get the array $[0, 0, 1, 2, 1]$;
* apply the operation at $i=4$ and get the array $[0, 0, 0, 0, 0]$.


#### tags 

#1000 #brute_force #dp #greedy #math 