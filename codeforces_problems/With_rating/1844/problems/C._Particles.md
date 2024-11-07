<h1 style='text-align: center;'> C. Particles</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have discovered $n$ mysterious particles on a line with integer charges of $c_1,\dots,c_n$. You have a device that allows you to perform the following operation: 

* Choose a particle and remove it from the line. The remaining particles will shift to fill in the gap that is created. If there were particles with charges $x$ and $y$ directly to the left and right of the removed particle, they combine into a single particle of charge $x+y$.

For example, if the line of particles had charges of $[-3,1,4,-1,5,-9]$, performing the operation on the $4$th particle will transform the line into $[-3,1,9,-9]$.

 ![](images/e03b7cd1557bc6141aa5ceb08d033c7fb1f3d7a9.png) If we then use the device on the $1$st particle in this new line, the line will turn into $[1,9,-9]$. 

You will perform operations until there is only one particle left. What is the maximum charge of this remaining particle that you can obtain?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $c_1,\dots,c_n$ ($-10^9 \le c_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output one integer, the maximum charge of the remaining particle.

## Example

### Input


```text
36-3 1 4 -1 5 -95998244353 998244353 998244353 998244353 9982443531-2718
```
### Output

```text

9
2994733059
-2718

```
## Note

In the first test case, the best strategy is to use the device on the $4$th particle, then on the $1$st particle (as described in the statement), and finally use the device on the new $3$rd particle followed by the $1$st particle.

In the second test case, the best strategy is to use the device on the $4$th particle to transform the line into $[998244353,998244353,1996488706]$, then on the $2$nd particle to transform the line into $[2994733059]$. Be wary of integer overflow.

In the third test case, there is only one particle, so no operations can be performed.



#### Tags 

#1300 #OK #dp #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_884_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
