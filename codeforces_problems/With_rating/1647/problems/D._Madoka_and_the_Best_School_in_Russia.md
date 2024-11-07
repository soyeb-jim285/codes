<h1 style='text-align: center;'> D. Madoka and the Best School in Russia</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Madoka is going to enroll in "TSUNS PTU". But she stumbled upon a difficult task during the entrance computer science exam:

* A number is called good if it is a multiple of $d$.
* A number is called beatiful if it is good and it cannot be represented as a product of two good numbers.

Notice that a beautiful number must be good.

Given a good number $x$, determine whether it can be represented in at least two different ways as a product of several (possibly, one) beautiful numbers. Two ways are different if the sets of numbers used are different.

Solve this problem for Madoka and help her to enroll in the best school in Russia!

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — number of test cases. Below comes their description.

Each test case consists of two integers $x$ and $d$, separated by a space ($2 \leq x, d \leq 10^9$). It is guaranteed that $x$ is a multiple of $d$.

### Output

For each set of input data, output "NO" if the number cannot be represented in at least two ways. Otherwise, output "YES".

You can output each letter in any case (for example, "YES", "Yes", "yes", "yEs", "yEs" will be recognized as a positive answer).

## Example

### Input


```text
86 212 236 28 21000 102376 6128 416384 4
```
### Output

```text

NO
NO
YES
NO
YES
YES
NO
YES

```
## Note

In the first example, $6$ can be represented as $6$, $1 \cdot 6$, $2 \cdot 3$. But $3$ and $1$ are not a good numbers because they are not divisible by $2$, so there is only one way.

In the second example, $12$ can be represented as $6 \cdot 2$, $12$, $3 \cdot 4$, or $3 \cdot 2 \cdot 2$. The first option is suitable. The second is— no, because $12$ is not beautiful number ($12 = 6 \cdot 2$). The third and fourth are also not suitable, because $3$ is not good number.

In the third example, $36$ can be represented as $18 \cdot 2$ and $6 \cdot 6$. Therefore it can be decomposed in at least two ways.



#### Tags 

#1900 #NOT OK #constructive_algorithms #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_777_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
