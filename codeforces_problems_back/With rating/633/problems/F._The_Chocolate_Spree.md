<h1 style='text-align: center;'> F. The Chocolate Spree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob have a tree (undirected acyclic connected graph). There are *a**i* chocolates waiting to be picked up in the *i*-th vertex of the tree. First, they choose two different vertices as their starting positions (Alice chooses first) and take all the chocolates contained in them.

Then, they alternate their moves, selecting one vertex at a time and collecting all chocolates from this node. To make things more interesting, they decided that one can select a vertex only if he/she selected a vertex adjacent to that one at his/her previous turn and this vertex has not been already chosen by any of them during other move.

If at any moment one of them is not able to select the node that satisfy all the rules, he/she will skip his turns and let the other person pick chocolates as long as he/she can. This goes on until both of them cannot pick chocolates any further.

Due to their greed for chocolates, they want to collect as many chocolates as possible. However, as they are friends they only care about the total number of chocolates they obtain together. What is the maximum total number of chocolates they may pick?

## Input

The first line of the input contains the single integer *n* (2 ≤ n ≤ 100 000) — the number of vertices in the tree.

The second line contains *n* integers *a**i* (1 ≤ *a**i* ≤ 109), *i*-th of these numbers stands for the number of chocolates stored at the node *i*.

Then follow *n* - 1 lines that describe the tree. Each of them contains two integers *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*) — indices of vertices connected by the *i*-th edge.

## Output

Print the number of chocolates Alice and Bob can collect together if they behave optimally.

## Examples

## Input


```
9  
1 2 3 4 5 6 7 8 9  
1 2  
1 3  
1 4  
1 5  
1 6  
1 7  
1 8  
1 9  

```
## Output


```
25  

```
## Input


```
2  
20 10  
1 2  

```
## Output


```
30  

```
## Note

In the first sample, Alice may start at the vertex 9 and Bob at vertex 8. Alice will select vertex 1 and Bob has no options now. Alice selects the vertex 7 and they both stop.

In the second sample, both of them will pick either of the nodes alternately.



#### tags 

#2600 #dfs_and_similar #dp #graphs #trees 