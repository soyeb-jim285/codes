<h1 style='text-align: center;'> A. Variable, or There and Back Again</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Life is not easy for the perfectly common variable named Vasya. Wherever it goes, it is either assigned a value, or simply ignored, or is being used!

Vasya's life goes in states of a program. In each state, Vasya can either be used (for example, to calculate the value of another variable), or be assigned a value, or ignored. Between some states are directed (oriented) transitions.

A path is a sequence of states *v*1, *v*2, ..., *v**x*, where for any 1 ≤ *i* < *x* exists a transition from *v**i* to *v**i* + 1.

Vasya's value in state *v* is interesting to the world, if exists path *p*1, *p*2, ..., *p**k* such, that *p**i* = *v* for some *i* (1 ≤ *i* ≤ *k*), in state *p*1 Vasya gets assigned a value, in state *p**k* Vasya is used and there is no state *p**i* (except for *p*1) where Vasya gets assigned a value.

Help Vasya, find the states in which Vasya's value is interesting to the world.

## Input

The first line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the numbers of states and transitions, correspondingly.

The second line contains space-separated *n* integers *f*1, *f*2, ..., *f**n* (0 ≤ *f**i* ≤ 2), *f**i* described actions performed upon Vasya in state *i*: 0 represents ignoring, 1 — assigning a value, 2 — using.

Next *m* lines contain space-separated pairs of integers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*), each pair represents the transition from the state number *a**i* to the state number *b**i*. Between two states can be any number of transitions.

## Output

Print *n* integers *r*1, *r*2, ..., *r**n*, separated by spaces or new lines. Number *r**i* should equal 1, if Vasya's value in state *i* is interesting to the world and otherwise, it should equal 0. The states are numbered from 1 to *n* in the order, in which they are described in the input.

## Examples

## Input


```
4 3  
1 0 0 2  
1 2  
2 3  
3 4  

```
## Output


```
1  
1  
1  
1  

```
## Input


```
3 1  
1 0 2  
1 3  

```
## Output


```
1  
0  
1  

```
## Input


```
3 1  
2 0 1  
1 3  

```
## Output


```
0  
0  
0  

```
## Note

In the first sample the program states can be used to make the only path in which the value of Vasya interests the world, 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 3 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 4; it includes all the states, so in all of them Vasya's value is interesting to the world.

The second sample the only path in which Vasya's value is interesting to the world is , — 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 3; state 2 is not included there.

In the third sample we cannot make from the states any path in which the value of Vasya would be interesting to the world, so the value of Vasya is never interesting to the world.



#### tags 

#1700 #dfs_and_similar #graphs 