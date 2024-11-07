<h1 style='text-align: center;'> B. Make Majority</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a sequence $[a_1,\ldots,a_n]$ where each element $a_i$ is either $0$ or $1$. You can apply several (possibly zero) operations to the sequence. In each operation, you select two integers $1\le l\le r\le |a|$ (where $|a|$ is the current length of $a$) and replace $[a_l,\ldots,a_r]$ with a single element $x$, where $x$ is the majority of $[a_l,\ldots,a_r]$.

Here, the majority of a sequence consisting of $0$ and $1$ is defined as follows: suppose there are $c_0$ zeros and $c_1$ ones in the sequence, respectively. 

* If $c_0\ge c_1$, the majority is $0$.
* If $c_0<c_1$, the majority is $1$.

For example, suppose $a=[1,0,0,0,1,1]$. If we select $l=1,r=2$, the resulting sequence will be $[0,0,0,1,1]$. If we select $l=4,r=6$, the resulting sequence will be $[1,0,0,1]$. 

Determine if you can make $a=[1]$ with a finite number of operations.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 4\cdot 10^4$). Description of the test cases follows.

The first line of each testcase contains one integer $n$ ($1\le n\le 2\cdot 10^5$).

The second line of each testcase contains a string consisting of $0$ and $1$, describing the sequence $a$.

It's guaranteed that the sum of $n$ over all testcases does not exceed $2\cdot 10^5$.

### Output

For each testcase, if it's possible to make $a=[1]$, print YES. Otherwise, print NO. You can output the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will be recognized as positive responses.

## Example

### Input


```text
5101120191000000019000011000
```
### Output

```text

No
Yes
No
Yes
No

```
## Note

In the fourth testcase of the example, initially $a=[1,0,0,0,0,0,0,0,1]$. A valid sequence of operations is: 

1. Select $l=2,r=8$ and apply the operation. $a$ becomes $[1,0,1]$.
2. Select $l=1,r=3$ and apply the operation. $a$ becomes $[1]$.


#### Tags 

#900 #OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_958_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
