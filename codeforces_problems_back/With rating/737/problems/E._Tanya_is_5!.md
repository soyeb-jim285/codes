<h1 style='text-align: center;'> E. Tanya is 5!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tanya is now five so all her friends gathered together to celebrate her birthday. There are *n* children on the celebration, including Tanya.

The celebration is close to its end, and the last planned attraction is gaming machines. There are *m* machines in the hall, they are numbered 1 through *m*. Each of the children has a list of machines he wants to play on. Moreover, for each of the machines he knows the exact time he wants to play on it. For every machine, no more than one child can play on this machine at the same time.

It is evening already, so every adult wants to go home. To speed up the process, you can additionally rent second copies of each of the machines. To rent the second copy of the *j*-th machine, you have to pay *p**j* burles. After you rent a machine, you can use it for as long as you want.

How long it will take to make every child play according to his plan, if you have a budget of *b* burles for renting additional machines? There is only one copy of each machine, so it's impossible to rent a third machine of the same type.

The children can interrupt the game in any moment and continue it later. If the *i*-th child wants to play on the *j*-th machine, it is allowed after you rent the copy of the *j*-th machine that this child would play some part of the time on the *j*-th machine and some part of the time on its copy (each of these parts could be empty). The interruptions and changes take no time and can be performed in any integer moment of time. Of course, a child can't play on more than one machine at the same time.

Remember, that it is not needed to save money (no one saves money at the expense of children happiness!), it is needed to minimize the latest moment of time some child ends his game.

## Input

The first line contains three integers *n*, *m* and *b* (1 ≤ *n* ≤ 40, 1 ≤ *m* ≤ 10, 0 ≤ *b* ≤ 106) — the number of children, the number of gaming machines and the budget for renting additional machines.

The second line contains *m* integers *p*1, *p*2, ..., *p**m* (1 ≤ *p**j* ≤ 106), where *p**j* is the rent price for the second copy of the *j*-th machine.

*n* lines follow, *i*-th of them describes the wishes of the *i*-th child. The line starts with an integer *k**i* (0 ≤ *k**i* ≤ *m*) — the number of machines, the *i*-th child wants to play on. Then there are *k**i* pairs in the line, the *y*-th of them is *x**iy*, *t**iy*. It means that, the *i*-th child wants to play *t**iy* (1 ≤ *t**iy* ≤ 2500) minutes on the *x**iy*-th (1 ≤ *x**iy* ≤ *m*) machine. In each of these *n* lines the values *x**iy* are distinct.

## Output

In the first line print the minimum time in which all the children can finish their games.

In the second line print a string of length *m* consisting of zeros and ones. The *j*-th character is '1', if the copy of *j*-th machine should be rated, and '0' otherwise.

In the third line print integer *g* (0 ≤ *g* ≤ 106) — the total number of time segments of continuous playing for all of the children. Then in *g* lines print the segments as four integers *i*, *j*, *s*, *d*, meaning that the *i*-th child was playing on the *j*-th machine or its copy from the time moment *s* (*s* ≥ 0) for *d* minutes (*d* ≥ 1). You can print these lines in arbitrary order.

If there are multiple answers, print any of them.

## Examples

## Input


```
2 2 100  
3 7  
2 1 3 2 1  
2 1 3 2 1  

```
## Output


```
4  
10  
8  
1 1 0 1  
2 2 0 1  
1 1 1 1  
2 1 1 1  
2 1 2 1  
1 1 2 1  
1 2 3 1  
2 1 3 1  

```
## Input


```
3 2 15  
11 7  
2 2 10 1 5  
1 2 20  
2 1 4 2 3  

```
## Output


```
20  
01  
17  
2 2 0 4  
2 2 4 1  
1 1 5 2  
2 2 5 2  
1 2 7 5  
2 2 7 5  
2 2 12 1  
1 2 12 1  
3 1 13 4  
2 2 13 4  
1 2 13 4  
1 1 17 2  
3 2 17 2  
2 2 17 2  
1 1 19 1  
2 2 19 1  
3 2 19 1  

```


#### tags 

#3300 #graph_matchings #graphs #greedy #schedules 