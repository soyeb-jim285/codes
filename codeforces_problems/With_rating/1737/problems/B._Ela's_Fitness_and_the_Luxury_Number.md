<h1 style='text-align: center;'> B. Ela's Fitness and the Luxury Number</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>



|  | While working at DTL, Ela is very aware of her physical and mental health. She started to practice various sports, such as Archery, Yoga, and Football. |
| --- | --- |



Since she started engaging in sports activities, Ela switches to trying a new sport on days she considers being "Luxury" days. She counts the days since she started these activities, in which the day she starts is numbered as day $1$. A "Luxury" day is the day in which the number of this day is a luxurious number. 

An integer $x$ is called a luxurious number if it is divisible by ${\lfloor \sqrt{x} \rfloor}$.

Here $\lfloor r \rfloor$ denotes the "floor" of a real number $r$. In other words, it's the largest integer not greater than $r$.

For example: $8$, $56$, $100$ are luxurious numbers, since $8$ is divisible by $\lfloor \sqrt{8} \rfloor = \lfloor 2.8284 \rfloor = 2$, $56$ is divisible $\lfloor \sqrt{56} \rfloor = \lfloor 7.4833 \rfloor = 7$, and $100$ is divisible by $\lfloor \sqrt{100} \rfloor = \lfloor 10 \rfloor = 10$, respectively. On the other hand $5$, $40$ are not, since $5$ are not divisible by $\lfloor \sqrt{5} \rfloor = \lfloor 2.2361 \rfloor = 2$, and $40$ are not divisible by $\lfloor \sqrt{40} \rfloor = \lfloor 6.3246 \rfloor = 6$.

Being a friend of Ela, you want to engage in these fitness activities with her to keep her and yourself accompanied (and have fun together, of course). Between day $l$ and day $r$, you want to know how many times she changes the activities.

### Input

Each test contains multiple test cases. The first line has the number of test cases $t$ ($1 \le t \le 10\ 000$). The description of the test cases follows.

The only line of each test case contains two integers $l$ and $r$ ($1 \le l \le r \le 10^{18}$) — the intervals at which you want to know how many times Ela changes her sports.

### Output

For each test case, output an integer that denotes the answer.

## Example

### Input


```text
58 198 20119 1211 1000000000000000001234567891011 1000000000000000000
```
### Output

```text

5
6
2
948683296
2996666667

```
## Note

In the first test case, $5$ luxury numbers in range $[8, 19]$ are: $8, 9, 12, 15, 16$.



#### Tags 

#1300 #NOT OK #binary_search #implementation #math 

## Blogs
- [All Contest Problems](../Dytechlab_Cup_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
