<h1 style='text-align: center;'> E. Policeman and a Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree (a connected non-oriented graph without cycles) with vertices numbered from 1 to *n*, and the length of the *i*-th edge is *w**i*. In the vertex *s* there is a policeman, in the vertices *x*1, *x*2, ..., *x**m* (*x**j* ≠ *s*) *m* criminals are located.

The policeman can walk along the edges with speed 1, the criminals can move with arbitrary large speed. If a criminal at some moment is at the same point as the policeman, he instantly gets caught by the policeman. Determine the time needed for the policeman to catch all criminals, assuming everybody behaves optimally (i.e. the criminals maximize that time, the policeman minimizes that time). Everybody knows positions of everybody else at any moment of time.

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 50) — the number of vertices in the tree. The next *n* - 1 lines contain three integers each: *u**i*, *v**i*, *w**i* (1 ≤ *u**i*, *v**i* ≤ *n*, 1 ≤ *w**i* ≤ 50) denoting edges and their lengths. It is guaranteed that the given graph is a tree.

The next line contains single integer *s* (1 ≤ *s* ≤ *n*) — the number of vertex where the policeman starts.

The next line contains single integer *m* (1 ≤ *m* ≤ 50) — the number of criminals. The next line contains *m* integers *x*1, *x*2, ..., *x**m* (1 ≤ *x**j* ≤ *n*, *x**j* ≠ *s*) — the number of vertices where the criminals are located. *x**j* are not necessarily distinct.

## Output

If the policeman can't catch criminals, print single line "Terrorists win" (without quotes).

Otherwise, print single integer — the time needed to catch all criminals.

## Examples

## Input


```
4  
1 2 2  
1 3 1  
1 4 1  
2  
4  
3 1 4 1  

```
## Output


```
8  

```
## Input


```
6  
1 2 3  
2 3 5  
3 4 1  
3 5 4  
2 6 3  
2  
3  
1 3 5  

```
## Output


```
21  

```
## Note

In the first example one of the optimal scenarios is the following. The criminal number 2 moves to vertex 3, the criminal 4 — to vertex 4. The policeman goes to vertex 4 and catches two criminals. After that the criminal number 1 moves to the vertex 2. The policeman goes to vertex 3 and catches criminal 2, then goes to the vertex 2 and catches the remaining criminal.



#### tags 

#2700 #dp #graphs #trees 