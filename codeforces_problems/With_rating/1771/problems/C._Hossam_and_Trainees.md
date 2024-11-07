<h1 style='text-align: center;'> C. Hossam and Trainees</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hossam has $n$ trainees. He assigned a number $a_i$ for the $i$-th trainee. 

A pair of the $i$-th and $j$-th ($i \neq j$) trainees is called successful if there is an integer $x$ ($x \geq 2$), such that $x$ divides $a_i$, and $x$ divides $a_j$.

Hossam wants to know if there is a successful pair of trainees.

Hossam is very tired now, so he asks you for your help!

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$), the number of test cases. A description of the test cases follows.

The first line of each test case contains an integer number $n$ ($2 \le n \le 10^5$).

The second line of each test case contains $n$ integers, the number of each trainee $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

Print the answer — "YES" (without quotes) if there is a successful pair of trainees and "NO" otherwise. You can print each letter in any case.

## Example

### Input


```text
2332 48 7314 5 9
```
### Output

```text

YES
NO

```
## Note

In the first example, the first trainee and the second trainee make up a successful pair: 

$a_1 = 32, a_2 = 48$, you can choose $x = 4$.



#### Tags 

#1600 #NOT OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_837_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
