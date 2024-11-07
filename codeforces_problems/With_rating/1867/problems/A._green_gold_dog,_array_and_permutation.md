<h1 style='text-align: center;'> A. green_gold_dog, array and permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

green_gold_dog has an array $a$ of length $n$, and he wants to find a permutation $b$ of length $n$ such that the number of distinct numbers in the element-wise difference between array $a$ and permutation $b$ is maximized.

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation (as $2$ appears twice in the array) and $[1,3,4]$ is also not a permutation (as $n=3$, but $4$ appears in the array).

The element-wise difference between two arrays $a$ and $b$ of length $n$ is an array $c$ of length $n$, where $c_i$ = $a_i - b_i$ ($1 \leq i \leq n$).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 4 \cdot 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 4 \cdot 10^4$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $4 \cdot 10^4$.

### Output

For each test case, output $n$ numbers - a suitable permutation $b$. If there are multiple solutions, print any of them.

## Example

### Input


```text
3110000021 1310 3 3
```
### Output

```text

1 
2 1 
1 3 2 

```
## Note

In the first set of input data, the element-wise difference of the arrays is [99999]. Here, there is one distinct number, and it is obvious that in an array of length one, there cannot be more than one different element.

In the second set of input data, the element-wise difference of the arrays is [-1, 0]. Here, there are two distinct numbers, and it is obvious that in an array of length two, there cannot be more than two different elements.

In the third set of input data, the element-wise difference of the arrays is [9, 0, 1]. Here, there are three distinct numbers, and it is obvious that in an array of length three, there cannot be more than three different elements.



#### Tags 

#800 #OK #constructive_algorithms #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_897_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
