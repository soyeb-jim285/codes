<h1 style='text-align: center;'> A. Dorm Water Supply</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The German University in Cairo (GUC) dorm houses are numbered from 1 to *n*. Underground water pipes connect these houses together. Each pipe has certain direction (water can flow only in this direction and not vice versa), and diameter (which characterizes the maximal amount of water it can handle).

For each house, there is at most one pipe going into it and at most one pipe going out of it. With the new semester starting, GUC student and dorm resident, Lulu, wants to install tanks and taps at the dorms. For every house with an outgoing water pipe and without an incoming water pipe, Lulu should install a water tank at that house. For every house with an incoming water pipe and without an outgoing water pipe, Lulu should install a water tap at that house. Each tank house will convey water to all houses that have a sequence of pipes from the tank to it. Accordingly, each tap house will receive water originating from some tank house.

In order to avoid pipes from bursting one week later (like what happened last semester), Lulu also has to consider the diameter of the pipes. The amount of water each tank conveys should not exceed the diameter of the pipes connecting a tank to its corresponding tap. Lulu wants to find the maximal amount of water that can be safely conveyed from each tank to its corresponding tap.

## Input

The first line contains two space-separated integers *n* and *p* (1 ≤ *n* ≤ 1000, 0 ≤ *p* ≤ *n*) — the number of houses and the number of pipes correspondingly. 

Then *p* lines follow — the description of *p* pipes. The *i*-th line contains three integers *a**i* *b**i* *d**i*, indicating a pipe of diameter *d**i* going from house *a**i* to house *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*, 1 ≤ *d**i* ≤ 106).

It is guaranteed that for each house there is at most one pipe going into it and at most one pipe going out of it.

## Output

Print integer *t* in the first line — the number of tank-tap pairs of houses.

For the next *t* lines, print 3 integers per line, separated by spaces: *tank**i*, *tap**i*, and *diameter**i*, where *tank**i* ≠ *tap**i* (1 ≤ *i* ≤ *t*). Here *tank**i* and *tap**i* are indexes of tank and tap houses respectively, and *diameter**i* is the maximum amount of water that can be conveyed. All the *t* lines should be ordered (increasingly) by *tank**i*.

## Examples

## Input


```
3 2  
1 2 10  
2 3 20  

```
## Output


```
1  
1 3 10  

```
## Input


```
3 3  
1 2 20  
2 3 10  
3 1 5  

```
## Output


```
0  

```
## Input


```
4 2  
1 2 60  
3 4 50  

```
## Output


```
2  
1 2 60  
3 4 50  

```


#### tags 

#1400 #dfs_and_similar #graphs 