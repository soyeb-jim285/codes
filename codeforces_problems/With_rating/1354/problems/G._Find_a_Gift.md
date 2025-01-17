<h1 style='text-align: center;'> G. Find a Gift</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem. Don't forget to flush output after printing queries using cout.flush() or fflush(stdout) in C++ or similar functions in other programming languages.

There are $n$ gift boxes in a row, numbered from $1$ to $n$ from left to right. It's known that exactly $k$ of them contain valuable gifts — other boxes contain just lucky stones. All boxes look the same and differ only in weight. All boxes with stones have the same weight and are strictly heavier than boxes with valuable items. But valuable gifts may be different, so the boxes with valuable items may have different weights.

You can ask no more than $50$ queries (printing an answer doesn't count). By each query you can compare total weights of two non-intersecting subsets of boxes $a_1, a_2, \dots, a_{k_a}$ and $b_1, b_2, \dots, b_{k_b}$. In return you'll get one of four results:

* FIRST, if subset $a_1, a_2, \dots, a_{k_a}$ is strictly heavier;
* SECOND, if subset $b_1, b_2, \dots, b_{k_b}$ is strictly heavier;
* EQUAL, if subsets have equal total weights;
* WASTED, if the query is incorrect or the limit of queries is exceeded.

Using such queries (or, maybe, intuition) find the box with a valuable gift with the minimum index.

### Input

The input consists of several cases. In the beginning, you receive the integer $T$ ($1 \le T \le 500$) — the number of test cases.

At the beginning of each test case, you receive two integers $n$ and $k$ ($2 \le n \le 1000$, $1 \le k \le \frac{n}{2}$) — the number of boxes in a row and the number of boxes with valuable gifts.

It's guaranteed that the order of boxes is fixed beforehand and that the sum of $n$ in one test doesn't exceed $1000$.

### Output

For each test case print the minimum index among all boxes with a valuable gift in the following format: "! $x$" where $x$ ($1 \le x \le n$) — the index of the box.

## Interaction

Print each query in three lines. In the first line print the sizes of subset in the following format: "? $k_a$ $k_b$" where $k_a$ and $k_b$ ($1 \le k_a, k_b \le n$; $k_a + k_b \le n$) — the corresponding sizes.

In the second line print $k_a$ integers $a_1, a_2, \dots, a_{k_a}$ ($1 \le a_i \le n$; $a_i \neq a_j$ if $i \neq j$) — indexes of boxes in the first subset.

In the third line print $k_b$ integers $b_1, b_2, \dots, b_{k_b}$ ($1 \le b_i \le n$; $b_i \neq b_j$ if $i \neq j$) — indexes of boxes in the second subset.

The subsets shouldn't intersect, i. e. $a_i \neq b_j$ for all $i$ and $j$.

You'll receive one of four responses described above. In the case of WASTED stop your program to avoid getting random verdict instead of Wrong Answer.

## Example

### Input


```text
2
2 1
-
-
-
FIRST
-
5 2
-
-
-
FIRST
-
-
-
SECOND
-
-
-
EQUAL
-
```
### Output

```text

-
-
? 1 1
1
2
-
! 2
-
? 1 1
1
2
-
? 2 3
4 2
1 3 5
-
? 1 1
4
5
-
! 1
```
## Note

Additional separators "–" in the sample are used only to increase the readability of the sample. Don't print any unnecessary symbols or line breaks in your solution when you send it to the system.

Hacks are forbidden in this task.



#### Tags 

#2600 #NOT OK #binary_search #interactive #probabilities 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_87_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
