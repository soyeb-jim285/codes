<h1 style='text-align: center;'> G. Three Occurrences</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ consisting of $n$ integers. We denote the subarray $a[l..r]$ as the array $[a_l, a_{l + 1}, \dots, a_r]$ ($1 \le l \le r \le n$).

A subarray is considered good if every integer that occurs in this subarray occurs there exactly thrice. For example, the array $[1, 2, 2, 2, 1, 1, 2, 2, 2]$ has three good subarrays:

* $a[1..6] = [1, 2, 2, 2, 1, 1]$;
* $a[2..4] = [2, 2, 2]$;
* $a[7..9] = [2, 2, 2]$.

Calculate the number of good subarrays of the given array $a$.

## Input

The first line contains one integer $n$ ($1 \le n \le 5 \cdot 10^5$).

The second line contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($1 \le a_i \le n$).

## Output

Print one integer — the number of good subarrays of the array $a$.

## Examples

## Input


```

9
1 2 2 2 1 1 2 2 2

```
## Output


```

3

```
## Input


```

10
1 2 3 4 1 2 3 1 2 3

```
## Output


```

0

```
## Input


```

12
1 2 3 4 3 4 2 1 3 4 2 1

```
## Output


```

1

```


#### tags 

#2500 #data_structures #divide_and_conquer #hashing #two_pointers 