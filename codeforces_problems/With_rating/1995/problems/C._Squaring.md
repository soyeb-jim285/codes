<h1 style='text-align: center;'> C. Squaring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

ikrpprpp found an array $a$ consisting of integers. He likes justice, so he wants to make $a$ fair — that is, make it non-decreasing. To do that, he can perform an act of justice on an index $1 \le i \le n$ of the array, which will replace $a_i$ with $a_i ^ 2$ (the element at position $i$ with its square). For example, if $a = [2,4,3,3,5,3]$ and ikrpprpp chooses to perform an act of justice on $i = 4$, $a$ becomes $[2,4,3,9,5,3]$.

What is the minimum number of acts of justice needed to make the array non-decreasing?

### Input

First line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases. It is followed by the description of test cases.

For each test case, the first line contains an integer $n$ — size of the array $a$. The second line contains $n$ ($1 \le n \le 2 \cdot 10 ^5$) integers $a_1, a_2,\ldots, a_n$ ($1 \le a_i \le 10 ^ 6$). 

The sum of $n$ over all test cases does not exceed $2 \cdot {10}^5$.

### Output

For each testcase, print an integer — minimum number of acts of justice required to make the array $a$ non-decreasing. If it is impossible to do that, print $-1$.

## Example

### Input


```text
731 2 323 233 1 541 1 2 334 3 2916 2 4 2 256 2 4 2 81110010 10009 10008 10007 10006 10005 10004 10003 10002 10001 10000
```
### Output

```text

0
1
-1
0
3
15
55

```
## Note

In the first test case, there's no need to perform acts of justice. The array is fair on its own!

In the third test case, it can be proven that the array cannot become non-decreasing.

In the fifth test case, ikrpprppp can perform an act of justice on index 3, then an act of justice on index 2, and finally yet another act of justice on index 3. After that, $a$ will become $[4, 9, 16]$.



#### Tags 

#1800 #NOT OK #brute_force #constructive_algorithms #greedy #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_961_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
