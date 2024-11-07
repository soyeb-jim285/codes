<h1 style='text-align: center;'> A. Array and Peaks</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sequence of $n$ integers is called a permutation if it contains all integers from $1$ to $n$ exactly once.

Given two integers $n$ and $k$, construct a permutation $a$ of numbers from $1$ to $n$ which has exactly $k$ peaks. An index $i$ of an array $a$ of size $n$ is said to be a peak if $1 < i < n$ and $a_i \gt a_{i-1}$ and $a_i \gt a_{i+1}$. If such permutation is not possible, then print $-1$.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

Then $t$ lines follow, each containing two space-separated integers $n$ ($1 \leq n \leq 100$) and $k$ ($0 \leq k \leq n$) — the length of an array and the required number of peaks.

## Output

## Output

 $t$ lines. For each test case, if there is no permutation with given length and number of peaks, then print $-1$. Otherwise print a line containing $n$ space-separated integers which forms a permutation of numbers from $1$ to $n$ and contains exactly $k$ peaks. 

If there are multiple answers, print any.

## Example

## Input


```

5
1 0
5 2
6 6
2 1
6 1

```
## Output


```

1 
2 4 1 5 3 
-1
-1
1 3 6 5 4 2

```
## Note

In the second test case of the example, we have array $a = [2,4,1,5,3]$. Here, indices $i=2$ and $i=4$ are the peaks of the array. This is because $(a_{2} \gt a_{1} $, $a_{2} \gt a_{3})$ and $(a_{4} \gt a_{3}$, $a_{4} \gt a_{5})$. 



#### tags 

#800 #constructive_algorithms #implementation 