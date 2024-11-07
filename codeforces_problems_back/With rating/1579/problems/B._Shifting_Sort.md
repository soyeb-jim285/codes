<h1 style='text-align: center;'> B. Shifting Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The new generation external memory contains an array of integers $a[1 \ldots n] = [a_1, a_2, \ldots, a_n]$.

This type of memory does not support changing the value of an arbitrary element. Instead, it allows you to cut out any segment of the given array, cyclically shift (rotate) it by any offset and insert it back into the same place.

Technically, each cyclic shift consists of two consecutive actions: 

1. You may select arbitrary indices $l$ and $r$ ($1 \le l < r \le n$) as the boundaries of the segment.
2. Then you replace the segment $a[l \ldots r]$ with it's cyclic shift to the left by an arbitrary offset $d$. The concept of a cyclic shift can be also explained by following relations: the sequence $[1, 4, 1, 3]$ is a cyclic shift of the sequence $[3, 1, 4, 1]$ to the left by the offset $1$ and the sequence $[4, 1, 3, 1]$ is a cyclic shift of the sequence $[3, 1, 4, 1]$ to the left by the offset $2$.

For example, if $a = [1, \color{blue}{3, 2, 8}, 5]$, then choosing $l = 2$, $r = 4$ and $d = 2$ yields a segment $a[2 \ldots 4] = [3, 2, 8]$. This segment is then shifted by the offset $d = 2$ to the left, and you get a segment $[8, 3, 2]$ which then takes the place of of the original elements of the segment. In the end you get $a = [1, \color{blue}{8, 3, 2}, 5]$.

Sort the given array $a$ using no more than $n$ cyclic shifts of any of its segments. ## Note

 that you don't need to minimize the number of cyclic shifts. Any method that requires $n$ or less cyclic shifts will be accepted.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The next $2t$ lines contain the descriptions of the test cases. 

The first line of each test case description contains an integer $n$ ($2 \leq n \leq 50$) — the length of the array. The second line consists of space-separated elements of the array $a_i$ ($-10^9 \leq a_i \leq 10^9$). Elements of array $a$ may repeat and don't have to be unique.

## Output

Print $t$ answers to all input test cases. 

The first line of the answer of each test case should contain an integer $k$ ($0 \le k \le n$) — the number of actions to sort the array. The next $k$ lines should contain descriptions of the actions formatted as "$l$ $r$ $d$" (without quotes) where $l$ and $r$ ($1 \le l < r \le n$) are the boundaries of the segment being shifted, while $d$ ($1 \le d \le r - l$) is the offset value. Please remember that only the cyclic shifts to the left are considered so the chosen segment will be shifted by the offset $d$ to the to the left.

## Note

 that you are not required to find the minimum number of cyclic shifts needed for sorting. Any sorting method where the number of shifts does not exceed $n$ will be accepted.

If the given array $a$ is already sorted, one of the possible answers is $k = 0$ and an empty sequence of cyclic shifts.

If there are several possible answers, you may print any of them.

## Example

## Input


```

4
2
2 1
3
1 2 1
4
2 4 1 3
5
2 5 1 4 3

```
## Output


```

1
1 2 1
1
1 3 2
3
2 4 1
2 3 1
1 3 2
4
2 4 2
1 5 3
1 2 1
1 3 1

```
## Note

Explanation of the fourth data set in the example: 

1. The segment $a[2 \ldots 4]$ is selected and is shifted to the left by $2$: $[2, \color{blue}{5, 1, 4}, 3] \longrightarrow [2, \color{blue}{4, 5, 1}, 3]$
2. The segment $a[1 \ldots 5]$ is then selected and is shifted to the left by $3$: $[\color{blue}{2, 4, 5, 1, 3}] \longrightarrow [\color{blue}{1, 3, 2, 4, 5}]$
3. After that the segment $a[1 \ldots 2]$ is selected and is shifted to the left by $1$: $[\color{blue}{1, 3}, 2, 4, 5] \longrightarrow [\color{blue}{3, 1}, 2, 4, 5]$
4. And in the end the segment $a[1 \ldots 3]$ is selected and is shifted to the left by $1$: $[\color{blue}{3, 1, 2}, 4, 5] \longrightarrow [\color{blue}{1, 2, 3}, 4, 5]$


#### tags 

#1100 #implementation #sortings 