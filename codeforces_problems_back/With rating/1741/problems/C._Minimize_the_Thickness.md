<h1 style='text-align: center;'> C. Minimize the Thickness</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence $a=[a_1,a_2,\dots,a_n]$ consisting of $n$ positive integers.

Let's call a group of consecutive elements a segment. Each segment is characterized by two indices: the index of its left end and the index of its right end. Denote by $a[l,r]$ a segment of the sequence $a$ with the left end in $l$ and the right end in $r$, i.e. $a[l,r]=[a_l, a_{l+1}, \dots, a_r]$.

For example, if $a=[31,4,15,92,6,5]$, then $a[2,5]=[4,15,92,6]$, $a[5,5]=[6]$, $a[1,6]=[31,4,15,92,6,5]$ are segments.

We split the given sequence $a$ into segments so that: 

* each element is in exactly one segment;
* the sums of elements for all segments are equal.

For example, if $a$ = [$55,45,30,30,40,100$], then such a sequence can be split into three segments: $a[1,2]=[55,45]$, $a[3,5]=[30, 30, 40]$, $a[6,6]=[100]$. Each element belongs to exactly segment, the sum of the elements of each segment is $100$.

Let's define thickness of split as the length of the longest segment. For example, the thickness of the split from the example above is $3$.

Find the minimum thickness among all possible splits of the given sequence of $a$ into segments in the required way.

## Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases.

Each test case is described by two lines.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2000$) — the length of the sequence $a$.

The second line of each test case contains exactly $n$ integers: $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — elements of the sequence $a$.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2000$.

## Output

For each test case, output one integer — the minimum possible thickness of a split of the sequence $a$ into segments.

## Note

 that there always exist a split, you can always consider whole sequence as one segment.

## Example

## Input


```

4655 45 30 30 40 100410 23 7 13510 55 35 30 6564 1 1 1 1 4
```
## Output


```

3
4
2
3

```
## Note

The split in the first test case is explained in the statement, it can be shown that it is optimal.

In the second test case, it is possible to split into segments only by leaving a single segment. Then the thickness of this split is equal to the length of the entire sequence, that is, $4$.

In the third test case, the optimal split will be $[10, 55], [35, 30], [65]$. The thickness of the split equals to $2$.

In the fourth test case possible splits are:

* $[4] + [1, 1, 1, 1] + [4]$;
* $[4, 1, 1] + [1, 1, 4]$.


#### tags 

#1100 #brute_force #greedy #math #two_pointers 