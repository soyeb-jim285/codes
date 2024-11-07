<h1 style='text-align: center;'> G. Scooter</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The Czech Technical University campus consists of $n$ buildings, indexed from $1$ to $n$. In each building, there can be a math class scheduled, or a computer science class, or neither (but not both). Additionally, in each building, there is at most one professor, and each professor is either an expert in mathematics or in computer science.

As an intern at University Express Inc., your job is to quickly transport the professors to their classes. For this, you have been granted a brand new two-person scooter, able to accommodate yourself, plus at most one passenger.

Initially, you are the only person on the scooter. When you arrive at a building, you may drop off or pick up professors to/from that building. However, in order to improve the efficiency of your task, you are allowed to drive to each of the $n$ buildings at most once, in the order of your choice (you can also decide where to start the itinerary). 

After the end of your itinerary, in each building where a math class is scheduled, there must be a professor expert in math, and in each building where a computer science class is scheduled, there must be a professor expert in computer science.

Devise an itinerary that makes it possible to teach all classes.

## Input

The first line contains an integer $n$ ($1\le n \le 2000$) — the number of buildings in the campus.

The second line contains a string of $c$ of length $n$ consisting of the characters $\texttt{-}$, $\texttt{C}$, $\texttt{M}$ — the $i$-th character denotes the subject of the class scheduled in the $i$-th building. $\texttt{C}$ stands for computer science, $\texttt{M}$ stands for mathematics, while $\texttt{-}$ means that there is no class scheduled in the $i$-th building.

The third line contains a string $p$ of length $n$ consisting of the characters $\texttt{-}$, $\texttt{C}$, $\texttt{M}$ — the $i$-th character denotes the expertise of the professor in the $i$-th building (if there is a professor). $\texttt{C}$ stands for computer science, $\texttt{M}$ stands for mathematics, while $\texttt{-}$ means that there is no professor in the $i$-th building.

It is guaranteed that, for all tests given to your program, there exists a valid itinerary.

## Output

In the first line print an integer $l$ — the number of operations in your chosen itinerary. 

The $i$-th ($1 \leq i \leq l$) of the next $l$ lines must contain one of three commands: 

1. $\texttt{DRIVE } x$ — go to the building with the number $x$ ($1 \leq x \leq n$);
2. $\texttt{PICKUP}$ — pick up the professor which was initially at the current building;
3. $\texttt{DROPOFF}$ — drop off the passenger professor at the current building.

In order for the itinerary to be valid, the following conditions must hold:

1. No two $\texttt{DRIVE}$ instructions should go to the same building;
2. At most one $\texttt{DROPOFF}$ and one $\texttt{PICKUP}$ instruction in this order should be issued at each specific building;
3. For all $\texttt{PICKUP}$ instructions, there must be a professor initially at the building, as well as no one already riding along on the scooter;
4. For all $\texttt{DROPOFF}$ instructions, there must be a professor riding along at the time of the command;
5. After the itinerary, in each building, if there is a class in that building, there must be a professor expert in the class' subject (either initially, or because they were dropped off there).

## Note

 that, in particular, you cannot pick up a professor that you just dropped off for an itinerary to be valid.

## Examples

## Input


```

3CM--CM
```
## Output


```

7
DRIVE 3
PICKUP
DRIVE 2
DROPOFF
PICKUP
DRIVE 1
DROPOFF

```
## Input


```

1CC
```
## Output


```

0

```
## Input


```

2-MMC
```
## Output


```

4
DRIVE 1
PICKUP
DRIVE 2
DROPOFF
```
## Note

In the first sample, You start by driving to building number $3$. You then pick up the mathematics professor. After dropping him off at building number $2$, where a mathematics class is being held, you pick up the computer science professor from there, and drop her off at building number $1$, finishing your itinerary.



#### tags 

#2300 #graphs #greedy 