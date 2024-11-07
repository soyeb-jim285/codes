<h1 style='text-align: center;'> C. Digital Logarithm</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define $f(x)$ for a positive integer $x$ as the length of the base-10 representation of $x$ without leading zeros. I like to call it a digital logarithm. Similar to a digital root, if you are familiar with that.

You are given two arrays $a$ and $b$, each containing $n$ positive integers. In one operation, you do the following: 

1. pick some integer $i$ from $1$ to $n$;
2. assign either $f(a_i)$ to $a_i$ or $f(b_i)$ to $b_i$.

Two arrays are considered similar to each other if you can rearrange the elements in both of them, so that they are equal (e. g. $a_i = b_i$ for all $i$ from $1$ to $n$).

What's the smallest number of operations required to make $a$ and $b$ similar to each other?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of the testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of elements in each of the arrays.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i < 10^9$).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_j < 10^9$).

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print the smallest number of operations required to make $a$ and $b$ similar to each other.

## Example

### Input


```text
411100041 2 3 43 1 4 232 9 31 100 91075019 709259 5 611271314 9024533 81871864 9 3 6 48659503 2 371245467 6 7 37376159 8 364036498 52295554 169
```
### Output

```text

2
0
2
18

```
## Note

In the first testcase, you can apply the digital logarithm to $b_1$ twice.

In the second testcase, the arrays are already similar to each other.

In the third testcase, you can first apply the digital logarithm to $a_1$, then to $b_2$.



#### Tags 

#1400 #OK #data_structures #greedy #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_135_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
