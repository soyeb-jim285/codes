<h1 style='text-align: center;'> F. Zigzag Game</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a complete bipartite graph with $2n$ nodes, with $n$ nodes on each side of the bipartition. Nodes $1$ through $n$ are on one side of the bipartition, and nodes $n+1$ to $2n$ are on the other side. You are also given an $n \times n$ matrix $a$ describing the edge weights. $a_{ij}$ denotes the weight of the edge between nodes $i$ and $j+n$. Each edge has a distinct weight.

Alice and Bob are playing a game on this graph. First Alice chooses to play as either "increasing" or "decreasing" for herself, and Bob gets the other choice. Then she places a token on any node of the graph. Bob then moves the token along any edge incident to that node. They now take turns playing the following game, with Alice going first.

The current player must move the token from the current vertex to some adjacent unvisited vertex. Let $w$ be the last weight of the last edge that was traversed. The edge that is traversed must be strictly greater than $w$ if the player is playing as "increasing", otherwise, it must be strictly less. The first player unable to make a move loses.

You are given $n$ and the edge weights of the graph. You can choose to play as either Alice or Bob, and you will play against the judge. You must win all the games for your answer to be judged correct.

## Interaction

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 50$). Description of the test cases follows.

Each test starts with an integer $n$ ($1 \leq n \leq 50$) — the number of nodes on each side of the bipartition.

The next $n$ lines contain $n$ integers $a_{ij}$ ($1 \leq a_{ij} \leq n^2$). $a_{ij}$ denotes the weight of the edge between node $i$ and node $j+n$. All $a_{ij}$ will be distinct.

You first print a string "A" or "B", denoting which player you want to play ("A" for Alice and "B" for Bob).

If playing as Alice, first print either "I" or "D" (denoting whether you choose "increasing" or "decreasing"). Then, print the node that you wish to start at.

If playing as Bob, read in a character "I" or "D" (denoting whether the judge chose "increasing" or "decreasing"), then the node that the judge chooses to start at.

To make a move, print the index of the node that you wish to go to. To read what move the judge made, read an integer from standard in.

If the judge responds with $-1$, then that means the judge has determined it has no legal moves (or it may have just given up) and that you won the case. Stop processing this case immediately and start processing the next case.

If the judge responds with $-2$, that means that the judge has determined that you made an invalid move, so you should exit immediately to avoid getting other verdicts.

If you are unable to make a move or give up, print $-1$ and then exit immediately. This will give you a Wrong answer verdict.

After printing a move do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hack Format

To hack, use the following format. 
## Note

 that you can only hack with one test case.

The first line should contain a single integer $t$ ($t=1$).

The second line should contain an integer $n$ ($1 \leq n \leq 50$).

The next $n$ lines should contain $n$ integers each, the $a_{ij}$ ($1 \leq a_{ij} \leq n^2$). $a_{ij}$ denotes the weight of the edge between node $i$ and node $j+n$. All $a_{ij}$ must be distinct.

The judge will play a uniformly random legal move with this case versus the hacked program. If it has no legal moves left, it will give up and declare the player as the winner.

## Example

#Input
```text

2
3
3 1 9
2 5 7
6 4 8
6
-1
1
1
I 1
-1
```
#Output
```text

A
D 3
2
B
2
```
## Note

The first example has two test cases. In the first test case, the graph looks like the following.

 ![](images/79cabebed134a7a08cbbd18f977eb7954441552a.png) In the sample output, the player decides to play as Alice and chooses "decreasing" and starting at node $3$. The judge responds by moving to node $6$. After, the player moves to node $2$. At this point, the judge has no more moves (since the weight must "increase"), so it gives up and prints $-1$.

In the next case, we have two nodes connected by an edge of weight $1$. The player decides to play as Bob. No matter what the judge chooses, the player can move the token to the other node and the judge has no moves so will lose.



#### Tags 

#3500 #NOT OK #games #interactive 

## Blogs
- [All Contest Problems](../Forethought_Future_Cup_-_Final_Round_(Onsite_Finalists_Only).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
