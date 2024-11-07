<h1 style='text-align: center;'> F. Gifts from Grandfather Ahmed</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Grandfather Ahmed's School has $n+1$ students. The students are divided into $k$ classes, and $s_i$ students study in the $i$-th class. So, $s_1 + s_2 + \ldots + s_k = n+1$.

Due to the upcoming April Fools' Day, all students will receive gifts!

Grandfather Ahmed planned to order $n+1$ boxes of gifts. Each box can contain one or more gifts. He plans to distribute the boxes between classes so that the following conditions are satisfied:

1. Class number $i$ receives exactly $s_i$ boxes (so that each student can open exactly one box).
2. The total number of gifts in the boxes received by the $i$-th class should be a multiple of $s_i$ (it should be possible to equally distribute the gifts among the $s_i$ students of this class).

Unfortunately, Grandfather Ahmed ordered only $n$ boxes with gifts, the $i$-th of which contains $a_i$ gifts.

Ahmed has to buy the missing gift box, and the number of gifts in the box should be an integer between $1$ and $10^6$. Help Ahmed to determine, how many gifts should the missing box contain, and build a suitable distribution of boxes to classes, or report that this is impossible.

#### Input

The first line of the input contains two integers $n$ and $k$ ($1 \le n, k \le 200$, $k \le n + 1$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^6$) — the number of gifts in the available boxes.

The third line contains $k$ integers $s_1, s_2, \ldots, s_k$ ($1 \le s_i \le n+1$) — the number of students in classes. It is guaranteed that $\sum s_i = n+1$.

#### Output

If there is no way to buy the remaining box, output the integer $-1$ in a single line.

Otherwise, in the first line, output a single integer $s$ — the number of gifts in the box that Grandfather Ahmed should buy ($1 \le s \le 10^6$).

Next, in $k$ lines, print the distribution of boxes to classes. In the $i$-th line print $s_i$ integers — the sizes of the boxes that should be sent to the $i$-th class.

If there are multiple solutions, print any of them.

## Examples

#### Input


```text
4 2
7 7 7 127
2 3
```
#### Output


```text
1
7 7 
7 127 1 
```
#### Input


```text
18 4
1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9
6 1 9 3
```
#### Output


```text
9
7 1 7 6 5 4 
9 
1 2 3 8 3 2 9 8 9 
6 5 4 
```
## Note

In the first test, Grandfather Ahmed can buy a box with just $1$ gift. After that, two boxes with $7$ gifts are sent to the first class. $7 + 7 = 14$ is divisible by $2$. And the second class gets boxes with $1, 7, 127$ gifts. $1 + 7 + 127 = 135$ is evenly divisible by $3$.

In the second test, the classes have sizes $6$, $1$, $9$, and $3$. We show that the available boxes are enough to distribute into classes with sizes $6$, $9$, $3$, and in the class with size $1$, you can buy a box of any size. In class with size $6$ we send boxes with sizes $7$, $1$, $7$, $6$, $5$, $4$. $7 + 1 + 7 + 6 + 5 + 4 = 30$ is divisible by $6$. In class with size $9$ we send boxes with sizes $1$, $2$, $3$, $8$, $3$, $2$, $9$, $8$, $9$. $1 + 2 + 3 + 8 + 3 + 2 + 9 + 8 + 9 = 45$ is divisible by $9$. The remaining boxes ($6$, $5$, $4$) are sent to the class with size $3$. $6 + 5 + 4 = 15$ is divisible by $3$.



#### Tags 

#2500 #NOT OK #dp #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_860_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
