<h1 style='text-align: center;'> G. AI robots</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the last mission, MDCS has successfully shipped $N$ AI robots to Mars. Before they start exploring, system initialization is required so they are arranged in a line. Every robot can be described with three numbers: position ($x_i$), radius of sight ($r_i$) and IQ ($q_i$).

Since they are intelligent robots, some of them will talk if they see each other. Radius of sight is inclusive, so robot can see other all robots in range $[x_i - r_i, x_i + r_i]$. But they don't walk to talk with anybody, but only with robots who have similar IQ. By similar IQ we mean that their absolute difference isn't more than $K$. 

 Help us and calculate how many pairs of robots are going to talk with each other, so we can timely update their software and avoid any potential quarrel.

## Input

The first line contains two integers, numbers $N (1 \leq N \leq 10^5) $ and $K (0 \leq K \leq 20)$.

Next $N$ lines contain three numbers each $x_i, r_i, q_i (0 \leq x_i,r_i,q_i \leq 10^9)$ — position, radius of sight and IQ of every robot respectively.

## Output

## Output

 contains only one number — solution to the problem.

## Example

## Input


```
3 2  
3 6 1  
7 3 10  
10 5 8  

```
## Output


```
1
```
## Note

The first robot can see the second, but not vice versa. The first robot can't even see the third. The second and the third robot can see each other and their IQs don't differ more than 2 so only one conversation will happen.



#### tags 

#2200 #data_structures 