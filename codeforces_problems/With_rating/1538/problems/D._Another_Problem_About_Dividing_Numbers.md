<h1 style='text-align: center;'> D. Another Problem About Dividing Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $a$ and $b$. In one turn, you can do one of the following operations: 

* Take an integer $c$ ($c > 1$ and $a$ should be divisible by $c$) and replace $a$ with $\frac{a}{c}$;
* Take an integer $c$ ($c > 1$ and $b$ should be divisible by $c$) and replace $b$ with $\frac{b}{c}$.

Your goal is to make $a$ equal to $b$ using exactly $k$ turns.

For example, the numbers $a=36$ and $b=48$ can be made equal in $4$ moves: 

* $c=6$, divide $b$ by $c$ $\Rightarrow$ $a=36$, $b=8$;
* $c=2$, divide $a$ by $c$ $\Rightarrow$ $a=18$, $b=8$;
* $c=9$, divide $a$ by $c$ $\Rightarrow$ $a=2$, $b=8$;
* $c=4$, divide $b$ by $c$ $\Rightarrow$ $a=2$, $b=2$.

For the given numbers $a$ and $b$, determine whether it is possible to make them equal using exactly $k$ turns.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$). Then $t$ test cases follow.

Each test case is contains three integers $a$, $b$ and $k$ ($1 \le a, b, k \le 10^9$).

### Output

For each test case output: 

* "Yes", if it is possible to make the numbers $a$ and $b$ equal in exactly $k$ turns;
* "No" otherwise.

The strings "Yes" and "No" can be output in any case.

## Example

### Input


```text
8
36 48 2
36 48 3
36 48 4
2 8 1
2 8 2
1000000000 1000000000 1000000000
1 2 1
2 2 1
```
### Output


```text
YES
YES
YES
YES
YES
NO
YES
NO
```


#### Tags 

#1700 #NOT OK #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_725_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
