<h1 style='text-align: center;'> A. Portal</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

CQXYM found a rectangle $A$ of size $n \times m$. There are $n$ rows and $m$ columns of blocks. Each block of the rectangle is an obsidian block or empty. CQXYM can change an obsidian block to an empty block or an empty block to an obsidian block in one operation.

A rectangle $M$ size of $a \times b$ is called a portal if and only if it satisfies the following conditions:

* $a \geq 5,b \geq 4$.
* For all $1 < x < a$, blocks $M_{x,1}$ and $M_{x,b}$ are obsidian blocks.
* For all $1 < x < b$, blocks $M_{1,x}$ and $M_{a,x}$ are obsidian blocks.
* For all $1<x<a,1<y<b$, block $M_{x,y}$ is an empty block.
* $M_{1, 1}, M_{1, b}, M_{a, 1}, M_{a, b}$ can be any type.

 
## Note

 that the there must be $a$ rows and $b$ columns, not $b$ rows and $a$ columns.
## Note

 that corners can be any type

CQXYM wants to know the minimum number of operations he needs to make at least one sub-rectangle a portal.

#### Input

The first line contains an integer $t$ ($t \geq 1$), which is the number of test cases.

For each test case, the first line contains two integers $n$ and $m$ ($5 \le n \le 400$, $4 \le m \le 400$). 

Then $n$ lines follow, each line contains $m$ characters $0$ or $1$. If the $j$-th character of $i$-th line is $0$, block $A_{i,j}$ is an empty block. Otherwise, block $A_{i,j}$ is an obsidian block.

It is guaranteed that the sum of $n$ over all test cases does not exceed $400$.

It is guaranteed that the sum of $m$ over all test cases does not exceed $400$.

#### Output

#### Output

 $t$ answers, and each answer in a line.

## Examples

#### Input


```text
1
5 4
1000
0000
0110
0000
0001
```
#### Output


```text
12
```
#### Input


```text
1
9 9
001010001
101110100
000010011
100000001
101010101
110001111
000001111
111100000
000110000
```
#### Output


```text
5
```
## Note

In the first test case, the final portal is like this:


```text
  
1110  
1001  
1001  
1001  
0111  

```


#### Tags 

#1700 #NOT OK #brute_force #data_structures #dp #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_745_(Div._1).md)
- [Codeforces Round #745 (en)](../blogs/Codeforces_Round_745_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
