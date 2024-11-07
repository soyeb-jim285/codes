<h1 style='text-align: center;'> A. Hossam and Combinatorics</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hossam woke up bored, so he decided to create an interesting array with his friend Hazem.

Now, they have an array $a$ of $n$ positive integers, Hossam will choose a number $a_i$ and Hazem will choose a number $a_j$.

Count the number of interesting pairs $(a_i, a_j)$ that meet all the following conditions:

* $1 \le i, j \le n$;
* $i \neq j$;
* The absolute difference $|a_i - a_j|$ must be equal to the maximum absolute difference over all the pairs in the array. More formally, $|a_i - a_j| = \max_{1 \le p, q \le n} |a_p - a_q|$.
### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 100$), which denotes the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $n$ ($2 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print an integer — the number of interesting pairs $(a_i, a_j)$.

## Example

### Input


```text
256 2 3 8 167 2 8 3 2 10
```
### Output

```text

2
4

```
## Note

In the first example, the two ways are:

* Hossam chooses the fourth number $8$ and Hazem chooses the fifth number $1$.
* Hossam chooses the fifth number $1$ and Hazem chooses the fourth number $8$.

In the second example, the four ways are:

* Hossam chooses the second number $2$ and Hazem chooses the sixth number $10$.
* Hossam chooses the sixth number $10$ and Hazem chooses the second number $2$.
* Hossam chooses the fifth number $2$ and Hazem chooses the sixth number $10$.
* Hossam chooses the sixth number $10$ and Hazem chooses the fifth number $2$.


#### Tags 

#900 #NOT OK #combinatorics #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_837_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
