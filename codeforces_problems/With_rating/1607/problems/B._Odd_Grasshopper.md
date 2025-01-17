<h1 style='text-align: center;'> B. Odd Grasshopper</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The grasshopper is located on the numeric axis at the point with coordinate $x_0$.

Having nothing else to do he starts jumping between integer points on the axis. Making a jump from a point with coordinate $x$ with a distance $d$ to the left moves the grasshopper to a point with a coordinate $x - d$, while jumping to the right moves him to a point with a coordinate $x + d$.

The grasshopper is very fond of positive integers, so for each integer $i$ starting with $1$ the following holds: exactly $i$ minutes after the start he makes a jump with a distance of exactly $i$. So, in the first minutes he jumps by $1$, then by $2$, and so on.

The direction of a jump is determined as follows: if the point where the grasshopper was before the jump has an even coordinate, the grasshopper jumps to the left, otherwise he jumps to the right.

For example, if after $18$ consecutive jumps he arrives at the point with a coordinate $7$, he will jump by a distance of $19$ to the right, since $7$ is an odd number, and will end up at a point $7 + 19 = 26$. Since $26$ is an even number, the next jump the grasshopper will make to the left by a distance of $20$, and it will move him to the point $26 - 20 = 6$.

Find exactly which point the grasshopper will be at after exactly $n$ jumps.

### Input

The first line of input contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

Each of the following $t$ lines contains two integers $x_0$ ($-10^{14} \leq x_0 \leq 10^{14}$) and $n$ ($0 \leq n \leq 10^{14}$) — the coordinate of the grasshopper's initial position and the number of jumps.

### Output

Print exactly $t$ lines. On the $i$-th line print one integer — the answer to the $i$-th test case — the coordinate of the point the grasshopper will be at after making $n$ jumps from the point $x_0$.

## Example

### Input


```text
9
0 1
0 2
10 10
10 99
177 13
10000000000 987654321
-433494437 87178291199
1 0
-1 1
```
### Output


```text
-1
1
11
110
190
9012345679
-87611785637
1
0
```
## Note

The first two test cases in the example correspond to the first two jumps from the point $x_0 = 0$. 

Since $0$ is an even number, the first jump of length $1$ is made to the left, and the grasshopper ends up at the point $0 - 1 = -1$.

Then, since $-1$ is an odd number, a jump of length $2$ is made to the right, bringing the grasshopper to the point with coordinate $-1 + 2 = 1$.



#### Tags 

#900 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_753_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
