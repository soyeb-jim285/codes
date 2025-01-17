<h1 style='text-align: center;'> E. Flow Optimality</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a computer network consisting of *n* nodes numbered 1 through *n*. There are links in the network that connect pairs of nodes. A pair of nodes may have multiple links between them, but no node has a link to itself.

Each link supports unlimited bandwidth (in either direction), however a link may only transmit in a single direction at any given time. The cost of sending data across a link is proportional to the square of the bandwidth. Specifically, each link has a positive weight, and the cost of sending data across the link is the weight times the square of the bandwidth.

The network is connected (there is a series of links from any node to any other node), and furthermore designed to remain connected in the event of any single node failure.

You needed to send data from node 1 to node *n* at a bandwidth of some positive number *k*. That is, you wish to assign a bandwidth to each link so that the bandwidth into a node minus the bandwidth out of a node is  - *k* for node 1, *k* for node *n*, and 0 for all other nodes. The individual bandwidths do not need to be integers.

Wishing to minimize the total cost, you drew a diagram of the network, then gave the task to an intern to solve. The intern claimed to have solved the task and written the optimal bandwidths on your diagram, but then spilled coffee on it, rendering much of it unreadable (including parts of the original diagram, and the value of *k*).

From the information available, determine if the intern's solution may have been optimal. That is, determine if there exists a valid network, total bandwidth, and optimal solution which is a superset of the given information. Furthermore, determine the efficiency of the intern's solution (if possible), where efficiency is defined as total cost divided by total bandwidth.

## Input

## Input

 will begin with two integers *n* and *m* (2 ≤ *n* ≤ 200000; 0 ≤ *m* ≤ 200000), the number of nodes and number of known links in the network, respectively. Following this are *m* lines with four integers each: *f*, *t*, *w*, *b* (1 ≤ *f* ≤ *n*; 1 ≤ *t* ≤ *n*; *f* ≠ *t*; 1 ≤ *w* ≤ 100; 0 ≤ *b* ≤ 100). This indicates there is a link between nodes *f* and *t* with weight *w* and carrying *b* bandwidth. The direction of bandwidth is from *f* to *t*.

## Output

If the intern's solution is definitely not optimal, print "BAD *x*", where *x* is the first link in the input that violates the optimality of the solution. If the intern's solution may be optimal, print the efficiency of the solution if it can be determined rounded to the nearest integer, otherwise print "UNKNOWN".

## Examples

## Input


```
4 5  
1 2 1 2  
1 3 4 1  
2 3 2 1  
2 4 4 1  
3 4 1 2  

```
## Output


```
6  

```
## Input


```
5 5  
2 3 1 1  
3 4 1 1  
4 2 1 1  
1 5 1 1  
1 5 100 100  

```
## Output


```
BAD 3  

```
## Input


```
6 4  
1 3 31 41  
1 5 59 26  
2 6 53 58  
4 6 97 93  

```
## Output


```
UNKNOWN  

```
## Input


```
7 5  
1 7 2 1  
2 3 1 1  
4 5 1 0  
6 1 10 0  
1 3 1 1  

```
## Output


```
BAD 4  

```
## Note

Although the known weights and bandwidths happen to always be integers, the weights and bandwidths of the remaining links are not restricted to integers.



#### tags 

#3000 #constructive_algorithms #flows #math 