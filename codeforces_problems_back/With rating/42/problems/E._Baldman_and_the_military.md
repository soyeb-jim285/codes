<h1 style='text-align: center;'> E. Baldman and the military</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Baldman is a warp master. He possesses a unique ability — creating wormholes! Given two positions in space, Baldman can make a wormhole which makes it possible to move between them in both directions. Unfortunately, such operation isn't free for Baldman: each created wormhole makes him lose plenty of hair from his head.

Because of such extraordinary abilities, Baldman has caught the military's attention. He has been charged with a special task. But first things first.

The military base consists of several underground objects, some of which are connected with bidirectional tunnels. There necessarily exists a path through the tunnel system between each pair of objects. Additionally, exactly two objects are connected with surface. For the purposes of security, a patrol inspects the tunnel system every day: he enters one of the objects which are connected with surface, walks the base passing each tunnel at least once and leaves through one of the objects connected with surface. He can enter and leave either through the same object, or through different objects. The military management noticed that the patrol visits some of the tunnels multiple times and decided to optimize the process. Now they are faced with a problem: a system of wormholes needs to be made to allow of a patrolling which passes each tunnel exactly once. At the same time a patrol is allowed to pass each wormhole any number of times.

This is where Baldman comes to operation: he is the one to plan and build the system of the wormholes. Unfortunately for him, because of strict confidentiality the military can't tell him the arrangement of tunnels. Instead, they insist that his system of portals solves the problem for any arrangement of tunnels which satisfies the given condition. Nevertheless, Baldman has some information: he knows which pairs of objects he can potentially connect and how much it would cost him (in hair). Moreover, tomorrow he will be told which objects (exactly two) are connected with surface. Of course, our hero decided not to waste any time and calculate the minimal cost of getting the job done for some pairs of objects (which he finds likely to be the ones connected with surface). Help Baldman!

## Input

First line of the input contains a single natural number *n* (2 ≤ *n* ≤ 100000) — the number of objects on the military base. The second line — one number *m* (1 ≤ *m* ≤ 200000) — the number of the wormholes Baldman can make. The following *m* lines describe the wormholes: each line contains three integer numbers *a*, *b*, *c* (1 ≤ *a*, *b* ≤ *n*, 1 ≤ *c* ≤ 100000) — the numbers of objects which can be connected and the number of hair Baldman has to spend to make this wormhole.

The next line contains one natural number *q* (1 ≤ *q* ≤ 100000) — the number of queries. Finally, the last *q* lines contain a description of one query each — a pair of numbers of different objects *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*). There could be more than one wormhole between a pair of objects.

## Output

Your program should output *q* lines, one for each query. The *i*-th line should contain a single integer number — the answer for *i*-th query: the minimum cost (in hair) of a system of wormholes allowing the optimal patrol for any system of tunnels (satisfying the given conditions) if *a**i* and *b**i* are the two objects connected with surface, or "-1" if such system of wormholes cannot be made.

## Examples

## Input


```
2  
1  
1 2 3  
1  
1 2  

```
## Output


```
0  

```
## Input


```
3  
1  
1 2 3  
2  
1 2  
1 3  

```
## Output


```
-1  
3  

```


#### tags 

#2700 #dfs_and_similar #graphs #trees 