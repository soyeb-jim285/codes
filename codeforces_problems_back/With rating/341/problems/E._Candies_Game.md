<h1 style='text-align: center;'> E. Candies Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iahub is playing an uncommon game. Initially, he has *n* boxes, numbered 1, 2, 3, ..., *n*. Each box has some number of candies in it, described by a sequence *a*1, *a*2, ..., *a**n*. The number *a**k* represents the number of candies in box *k*. 

The goal of the game is to move all candies into exactly two boxes. The rest of *n* - 2 boxes must contain zero candies. Iahub is allowed to do several (possible zero) moves. At each move he chooses two different boxes *i* and *j*, such that *a**i* ≤ *a**j*. Then, Iahub moves from box *j* to box *i* exactly *a**i* candies. Obviously, when two boxes have equal number of candies, box number *j* becomes empty.

Your task is to give him a set of moves such as Iahub to archive the goal of the game. If Iahub can't win the game for the given configuration of boxes, output -1. Please note that in case there exist a solution, you don't need to print the solution using minimal number of moves.

## Input

The first line of the input contains integer *n* (3 ≤ *n* ≤ 1000). The next line contains *n* non-negative integers: *a*1, *a*2, ..., *a**n* — sequence elements. It is guaranteed that sum of all numbers in sequence *a* is up to 106. 

## Output

In case there exists no solution, output -1. Otherwise, in the first line output integer *c* (0 ≤ *c* ≤ 106), representing number of moves in your solution. Each of the next *c* lines should contain two integers *i* and *j* (1 ≤ *i*, *j* ≤ *n*, *i* ≠ *j*): integers *i*, *j* in the *k*th line mean that at the *k*-th move you will move candies from the *j*-th box to the *i*-th one.

## Examples

## Input


```
3  
3 6 9  

```
## Output


```
2  
2 3  
1 3  

```
## Input


```
3  
0 1 0  

```
## Output


```
-1
```
## Input


```
4  
0 1 1 0  

```
## Output


```
0  

```
## Note

For the first sample, after the first move the boxes will contain 3, 12 and 3 candies. After the second move, the boxes will contain 6, 12 and 0 candies. Now all candies are in exactly 2 boxes.

For the second sample, you can observe that the given configuration is not valid, as all candies are in a single box and they should be in two boxes. Also, any move won't change the configuration, so there exists no solution.

For the third sample, all candies are already in 2 boxes. Hence, no move is needed.



#### tags 

#3000 #constructive_algorithms #greedy 