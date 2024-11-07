<h1 style='text-align: center;'> B. Candies</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This problem is about candy. Initially, you only have $1$ candy, and you want to have exactly $n$ candies.

You can use the two following spells in any order at most $40$ times in total.

* Assume you have $x$ candies now. If you use the first spell, then $x$ candies become $2x-1$ candies.
* Assume you have $x$ candies now. If you use the second spell, then $x$ candies become $2x+1$ candies.

Construct a sequence of spells, such that after using them in order, you will have exactly $n$ candies, or determine it's impossible.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Their description follows.

Each test case contains one line with a single integer $n$ ($2 \le n \le 10^9$) — the required final number of candies.

### Output

For each test case, output the following.

If it's possible to eventually have $n$ candies within $40$ spells, in the first line print an integer $m$ ($1 \le m \le 40$), representing the total number of spells you use.

In the second print $m$ integers $a_{1}, a_{2}, \ldots, a_{m}$ ($a_{i}$ is $1$ or $2$) separated by spaces, where $a_{i} = 1$ means that you use the first spell in the $i$-th step, while $a_{i} = 2$ means that you use the second spell in the $i$-th step.

## Note

 that you do not have to minimize $m$, and if there are multiple solutions, you may output any one of them.

If it's impossible, output $-1$ in one line.

## Example

### Input


```text
423717
```
### Output

```text

-1
1
2 
2
2 2 
4
2 1 1 1 

```
## Note

For $n=3$, you can just use the second spell once, and then have $2 \cdot 1 + 1 = 3$ candies.

For $n=7$, you can use the second spell twice. After the first step, you will have $3$ candies. And after the second step, you will have $2 \cdot 3 + 1 = 7$ candies.



#### Tags 

#800 #OK #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../CodeTON_Round_4_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
