<h1 style='text-align: center;'> A. Division</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Oleg's favorite subjects are History and Math, and his favorite branch of mathematics is division.

To improve his division skills, Oleg came up with $t$ pairs of integers $p_i$ and $q_i$ and for each pair decided to find the greatest integer $x_i$, such that: 

* $p_i$ is divisible by $x_i$;
* $x_i$ is not divisible by $q_i$.

 Oleg is really good at division and managed to find all the answers quickly, how about you?
### Input

The first line contains an integer $t$ ($1 \le t \le 50$) — the number of pairs.

Each of the following $t$ lines contains two integers $p_i$ and $q_i$ ($1 \le p_i \le 10^{18}$; $2 \le q_i \le 10^{9}$) — the $i$-th pair of integers.

### Output

Print $t$ integers: the $i$-th integer is the largest $x_i$ such that $p_i$ is divisible by $x_i$, but $x_i$ is not divisible by $q_i$.

One can show that there is always at least one value of $x_i$ satisfying the divisibility conditions for the given constraints.

## Example

### Input


```text
3
10 4
12 6
179 822
```
### Output


```text
10
4
179
```
## Note

For the first pair, where $p_1 = 10$ and $q_1 = 4$, the answer is $x_1 = 10$, since it is the greatest divisor of $10$ and $10$ is not divisible by $4$.

For the second pair, where $p_2 = 12$ and $q_2 = 6$, note that 

* $12$ is not a valid $x_2$, since $12$ is divisible by $q_2 = 6$;
* $6$ is not valid $x_2$ as well: $6$ is also divisible by $q_2 = 6$.

 The next available divisor of $p_2 = 12$ is $4$, which is the answer, since $4$ is not divisible by $6$.

#### Tags 

#1500 #NOT OK #brute_force #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_680_(Div._1,_based_on_Moscow_Team_Olympiad).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
