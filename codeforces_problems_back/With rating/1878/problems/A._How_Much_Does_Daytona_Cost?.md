<h1 style='text-align: center;'> A. How Much Does Daytona Cost?</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We define an integer to be the most common on a subsegment, if its number of occurrences on that subsegment is larger than the number of occurrences of any other integer in that subsegment. A subsegment of an array is a consecutive segment of elements in the array $a$.

Given an array $a$ of size $n$, and an integer $k$, determine if there exists a non-empty subsegment of $a$ where $k$ is the most common element.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 100$, $1 \le k \le 100$) — the number of elements in array and the element which must be the most common.

The second line of each test case contains $n$ integers $a_1$, $a_2$, $a_3$, $\dots$, $a_n$ ($1 \le a_i \le 100$) — elements of the array.

## Output

For each test case output "YES" if there exists a subsegment in which $k$ is the most common element, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

## Input


```

75 41 4 3 4 14 12 3 4 45 643 5 60 4 22 51 54 15 3 3 11 335 33 4 1 5 5
```
## Output


```

YES
NO
NO
YES
YES
YES
YES

```
## Note

In the first test case we need to check if there is a subsegment where the most common element is $4$.

On the subsegment $[2,5]$ the elements are $4, \ 3, \ 4, \ 1$. 

* $4$ appears $2$ times;
* $1$ appears $1$ time;
* $3$ appears $1$ time.

This means that $4$ is the most common element on the subsegment $[2, 5]$, so there exists a subsegment where $4$ is the most common element.



#### tags 

#800 #greedy 