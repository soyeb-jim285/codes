<h1 style='text-align: center;'> A. Maximise The Score</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $2n$ positive integers written on a whiteboard. Being bored, you decided to play a one-player game with the numbers on the whiteboard.

You start with a score of $0$. You will increase your score by performing the following move exactly $n$ times: 

* Choose two integers $x$ and $y$ that are written on the whiteboard.
* Add $\min(x,y)$ to your score.
* Erase $x$ and $y$ from the whiteboard.

 
## Note

 that after performing the move $n$ times, there will be no more integers written on the whiteboard.

Find the maximum final score you can achieve if you optimally perform the $n$ moves.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 5000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 50$) — the number of integers written on the whiteboard is $2n$.

The second line of each test case contains $2n$ integers $a_1,a_2,\ldots,a_{2n}$ ($1 \leq a_i \leq 10^7$) — the numbers written on the whiteboard.

### Output

For each test case, output the maximum final score that you can achieve.

## Example

### Input


```text
312 321 1 2 131 1 1 1 1 1
```
### Output

```text

2
2
3

```
## Note

In the first test case, you can only make one move. You select $x=2$ and $y=3$, and your score will be $\min(x,y)=2$.

In the second test case, the following is a sequence of moves that achieves a final score of $2$:

* In the first move, select $x=1$ and $y=1$. Then, add $\min(x,y)=1$ to the score. After erasing $x$ and $y$, the integers left on the whiteboard are $1$ and $2$.
* In the second move, select $x=1$ and $y=2$. Then, add $\min(x,y)=1$ to the score. After removing $x$ and $y$, no more integers will be left on the whiteboard.

 It can be proved that it is not possible to get a score greater than $2$.In the third test case, you will perform the move thrice, adding $1$ to the score each time.



#### Tags 

#800 #NOT OK #greedy #sortings 

## Blogs
- [All Contest Problems](../think-cell_Round_1.md)
- [think-cell Round 1 (en)](../blogs/think-cell_Round_1_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Discussion (en)](../blogs/Discussion_(en).md)
