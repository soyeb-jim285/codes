<h1 style='text-align: center;'> D. Michael and Hotel</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Michael and Brian are stuck in a hotel with $n$ rooms, numbered from $1$ to $n$, and need to find each other. But this hotel's doors are all locked and the only way of getting around is by using the teleporters in each room. Room $i$ has a teleporter that will take you to room $a_i$ (it might be that $a_i = i$). But they don't know the values of $a_1,a_2, \dots, a_n$.

Instead, they can call up the front desk to ask queries. In one query, they give a room $u$, a positive integer $k$, and a set of rooms $S$. The hotel concierge answers whether a person starting in room $u$, and using the teleporters $k$ times, ends up in a room in $S$.

Brian is in room $1$. Michael wants to know the set $A$ of rooms so that if he starts in one of those rooms they can use the teleporters to meet up. He can ask at most $2000$ queries.

The values $a_1, a_2, \dots, a_n$ are fixed before the start of the interaction and do not depend on your queries. In other words, the interactor is not adaptive.

### Input

The input contains a single integer $n$ ($2 \leq n \leq 500$).

## Interaction

To ask a query, print a line in the format "? u k |S| S_1 S_2 ... S_|S|" with $1 \leq u, S_1, \ldots, S_{|S|} \leq n$, all the $S_i$ distinct, and $1 \leq k \leq 10^9$.

As a response to the query you will get "1" if the answer is yes, and "0" if the answer is no.

To output an answer, you should print "! |A| A_1 A_2 ... A_|A|" with $1 \leq A_1, \ldots, A_{|A|} \leq n$ all distinct. Printing the answer doesn't count as a query.

See the interaction example for more clarity.

If you ask too many queries or you ask a malformed query, you will get Wrong answer.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hack format

For the hacks use the following format.

The first line should contain $n$ — the number of rooms.

The second line should contains $n$ integers $a_1, a_2, \dots, a_n$ — the teleporter in room $i$ leads to room $a_i$.

## Example

### Input


```text

5

0

1
```
#Output
```text

? 3 5 2 2 3

? 2 5 2 2 3

! 3 1 3 4
```
## Note

In the sample test, there are $n=5$ rooms and the (hidden) array describing the behavior of the teleporters is $[1, 2, 1, 3, 2]$.

* The first query asks whether starting from room number $a=3$, and using the teleporters $5$ times, one ends up in one of the two rooms $S=\{2, 3\}$. This action results in ending up in the room $1$, so the answer is $0$.
* The second query asks whether starting from room number $a=2$, and using the teleporters $5$ times, one ends up in one of the two rooms $S=\{2, 3\}$. This action results in ending up in the room $2$, so the answer is $1$.


#### Tags 

#3000 #NOT OK #binary_search #interactive #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_889_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
