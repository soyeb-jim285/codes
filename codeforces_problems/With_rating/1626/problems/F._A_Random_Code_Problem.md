<h1 style='text-align: center;'> F. A Random Code Problem</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an integer array $a_0, a_1, \dots, a_{n - 1}$, and an integer $k$. You perform the following code with it:


```text
long long ans = 0; // create a 64-bit signed variable which is initially equal to 0  
for(int i = 1; i <= k; i++)  
{  
  int idx = rnd.next(0, n - 1); // generate a random integer between 0 and n - 1, both inclusive  
                                // each integer from 0 to n - 1 has the same probability of being chosen  
  ans += a[idx];  
  a[idx] -= (a[idx] % i);  
}  

```
Your task is to calculate the expected value of the variable ans after performing this code.

## Note

 that the input is generated according to special rules (see the input format section).

#### Input

The only line contains six integers $n$, $a_0$, $x$, $y$, $k$ and $M$ ($1 \le n \le 10^7$; $1 \le a_0, x, y < M \le 998244353$; $1 \le k \le 17$).

The array $a$ in the input is constructed as follows:

* $a_0$ is given in the input;
* for every $i$ from $1$ to $n - 1$, the value of $a_i$ can be calculated as $a_i = (a_{i - 1} \cdot x + y) \bmod M$.
#### Output

Let the expected value of the variable ans after performing the code be $E$. It can be shown that $E \cdot n^k$ is an integer. You have to output this integer modulo $998244353$.

## Examples

#### Input


```text
3 10 3 5 13 88
```
#### Output


```text
382842030
```
#### Input


```text
2 15363 270880 34698 17 2357023
```
#### Output


```text
319392398
```
## Note

The array in the first example test is $[10, 35, 22]$. In the second example, it is $[15363, 1418543]$.



#### Tags 

#2800 #NOT OK #combinatorics #dp #math #number_theory #probabilities 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_121_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
