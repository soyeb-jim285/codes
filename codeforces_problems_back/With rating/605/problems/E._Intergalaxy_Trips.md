<h1 style='text-align: center;'> E. Intergalaxy Trips</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The scientists have recently discovered wormholes — objects in space that allow to travel very long distances between galaxies and star systems. 

The scientists know that there are *n* galaxies within reach. You are in the galaxy number 1 and you need to get to the galaxy number *n*. To get from galaxy *i* to galaxy *j*, you need to fly onto a wormhole (*i*, *j*) and in exactly one galaxy day you will find yourself in galaxy *j*. 

Unfortunately, the required wormhole is not always available. Every galaxy day they disappear and appear at random. However, the state of wormholes does not change within one galaxy day. A wormhole from galaxy *i* to galaxy *j* exists during each galaxy day taken separately with probability *p**ij*. You can always find out what wormholes exist at the given moment. At each moment you can either travel to another galaxy through one of wormholes that exist at this moment or you can simply wait for one galaxy day to see which wormholes will lead from your current position at the next day.

Your task is to find the expected value of time needed to travel from galaxy 1 to galaxy *n*, if you act in the optimal way. It is guaranteed that this expected value exists.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 1000) — the number of galaxies within reach.

Then follows a matrix of *n* rows and *n* columns. Each element *p**ij* represents the probability that there is a wormhole from galaxy *i* to galaxy *j*. All the probabilities are given in percents and are integers. It is guaranteed that all the elements on the main diagonal are equal to 100.

## Output

Print a single real value — the expected value of the time needed to travel from galaxy 1 to galaxy *n* if one acts in an optimal way. Your answer will be considered correct if its absolute or relative error does not exceed 10- 6. 

Namely: let's assume that your answer is *a*, and the answer of the jury is *b*. The checker program will consider your answer correct, if ![](images/c97ba2000ebfad962bff7ffd8d043594f5ae1086.png).

## Examples

## Input


```
3  
100 50 50  
0 100 80  
0 0 100  

```
## Output


```
1.750000000000000  

```
## Input


```
2  
100 30  
40 100  

```
## Output


```
3.333333333333333  

```
## Note

In the second sample the wormhole from galaxy 1 to galaxy 2 appears every day with probability equal to 0.3. The expected value of days one needs to wait before this event occurs is ![](images/af1e8c68b44c3e2e8dc07919e5f90699f09c9dc1.png).



#### tags 

#2700 #probabilities #shortest_paths 