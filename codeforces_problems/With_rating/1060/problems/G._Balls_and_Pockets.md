<h1 style='text-align: center;'> G. Balls and Pockets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a strip with an infinite number of cells. Cells are numbered starting with $0$. Initially the cell $i$ contains a ball with the number $i$.

There are $n$ pockets located at cells $a_1, \ldots, a_n$. Each cell contains at most one pocket.

Filtering is the following sequence of operations:

* All pockets at cells $a_1, \ldots, a_n$ open simultaneously, which makes balls currently located at those cells disappear. After the balls disappear, the pockets close again.
* For each cell $i$ from $0$ to $\infty$, if the cell $i$ contains a ball, we move that ball to the free cell $j$ with the lowest number. If there is no free cell $j < i$, the ball stays at the cell $i$.

Note that after each filtering operation each cell will still contain exactly one ball.

For example, let the cells $1$, $3$ and $4$ contain pockets. The initial configuration of balls is shown below (underscores display the cells with pockets):

 0 1 2 3 4 5 6 7 8 9 ... After opening and closing the pockets, balls 1, 3 and 4 disappear:

 0   2     5 6 7 8 9 ... After moving all the balls to the left, the configuration looks like this:

 0 2 5 6 7 8 9 10 11 12 ... Another filtering repetition results in the following:

 0 5 8 9 10 11 12 13 14 15 ... You have to answer $m$ questions. The $i$-th of these questions is "what is the number of the ball located at the cell $x_i$ after $k_i$ repetitions of the filtering operation?"

### Input

The first line contains two integers $n$ and $m$ — the number of pockets and questions respectively ($1 \leq n, m \leq 10^5$).

The following line contains $n$ integers $a_1, \ldots, a_n$ — the numbers of cells containing pockets ($0 \leq a_1 < \ldots < a_n \leq 10^9$).

The following $m$ lines describe questions. The $i$-th of these lines contains two integers $x_i$ and $k_i$ ($0 \leq x_i, k_i \leq 10^9$).

### Output

Print $m$ numbers — answers to the questions, in the same order as given in the input.

## Example

### Input


```text
3 15  
1 3 4  
0 0  
1 0  
2 0  
3 0  
4 0  
0 1  
1 1  
2 1  
3 1  
4 1  
0 2  
1 2  
2 2  
3 2  
4 2  

```
### Output


```text
0  
1  
2  
3  
4  
0  
2  
5  
6  
7  
0  
5  
8  
9  
10  

```


#### Tags 

#3400 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_513_by_Barcelona_Bootcamp_(rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
