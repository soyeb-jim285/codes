<h1 style='text-align: center;'> H. Hidden Fortress</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem!

As part of your contribution in the Great Bubble War, you have been tasked with finding the newly built enemy fortress. The world you live in is a giant $10^9 \times 10^9$ grid, with squares having both coordinates between $1$ and $10^9$. 

You know that the enemy base has the shape of a rectangle, with the sides parallel to the sides of the grid. The people of your world are extremely scared of being at the edge of the world, so you know that the base doesn't contain any of the squares on the edges of the grid (the $x$ or $y$ coordinate being $1$ or $10^9$). 

To help you locate the base, you have been given a device that you can place in any square of the grid, and it will tell you the manhattan distance to the closest square of the base. The manhattan distance from square $(a, b)$ to square $(p, q)$ is calculated as $|a−p|+|b−q|$. If you try to place the device inside the enemy base, you will be captured by the enemy. Because of this, you need to make sure to never place the device inside the enemy base. 

Unfortunately, the device is powered by a battery and you can't recharge it. This means that you can use the device at most $40$ times. 

## Input

The input contains the answers to your queries. 

## Interaction

Your code is allowed to place the device on any square in the grid by writing "? $i$ $j$" $(1 \leq i,j \leq 10^9)$. In return, it will recieve the manhattan distance to the closest square of the enemy base from square $(i,j)$ or $-1$ if the square you placed the device on is inside the enemy base or outside the grid. 

If you recieve $-1$ instead of a positive number, exit immidiately and you will see the wrong answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

Your solution should use no more than $40$ queries. 

Once you are sure where the enemy base is located, you should print "! $x$ $y$ $p$ $q$" $(1 \leq x \leq p\leq 10^9, 1 \leq y \leq q\leq 10^9)$, where $(x, y)$ is the square inside the enemy base with the smallest $x$ and $y$ coordinates, and $(p, q)$ is the square inside the enemy base with the largest $x$ and $y$ coordinates. Note that answering doesn't count as one of the 40 queries.

After printing a query or printing the answer, do not forget to output end of line and flush the output. Otherwise, you will get idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* See the documentation for other languages.
## Example

## Input


```

1
1
2
1

```
Output
```

? 2 2
? 5 5
? 4 7
? 1 5
! 2 3 4 5

```


#### tags 

#2100 #interactive #math 