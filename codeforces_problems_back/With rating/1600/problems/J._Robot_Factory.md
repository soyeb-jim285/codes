<h1 style='text-align: center;'> J. Robot Factory</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have received data from a Bubble bot. You know your task is to make factory facilities, but before you even start, you need to know how big the factory is and how many rooms it has. When you look at the data you see that you have the dimensions of the construction, which is in rectangle shape: N x M. 

Then in the next N lines you have M numbers. These numbers represent factory tiles and they can go from 0 to 15. Each of these numbers should be looked in its binary form. Because from each number you know on which side the tile has walls. For example number 10 in it's binary form is 1010, which means that it has a wall from the North side, it doesn't have a wall from the East, it has a wall on the South side and it doesn't have a wall on the West side. So it goes North, East, South, West. 

It is guaranteed that the construction always has walls on it's edges. The input will be correct. 

Your task is to print the size of the rooms from biggest to smallest. 

## Input

The first line has two numbers which are N and M, the size of the construction. Both are integers: 

$n$ ($1 \leq n \leq 10^3$)

$m$ ($1 \leq m \leq 10^3$)

Next N x M numbers represent each tile of construction.

## Output

Once you finish processing the data your output consists of one line sorted from biggest to smallest room sizes. 

## Example

## Input


```

4 5
9 14 11 12 13
5 15 11 6 7
5 9 14 9 14
3 2 14 3 14

```
## Output


```

9 4 4 2 1 

```


#### tags 

#1400 #bitmasks #dfs_and_similar 