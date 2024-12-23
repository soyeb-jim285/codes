<h1 style='text-align: center;'> B. Friends</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Igor K. stopped programming and took up math. One late autumn evening he was sitting at a table reading a book and thinking about something. 

The following statement caught his attention: "Among any six people there are either three pairwise acquainted people or three pairwise unacquainted people"

Igor just couldn't get why the required minimum is 6 people. "Well, that's the same for five people, too!" — he kept on repeating in his mind. — "Let's take, say, Max, Ilya, Vova — here, they all know each other! And now let's add Dima and Oleg to Vova — none of them is acquainted with each other! Now, that math is just rubbish!"

Igor K. took 5 friends of his and wrote down who of them is friends with whom. Now he wants to check whether it is true for the five people that among them there are either three pairwise acquainted or three pairwise not acquainted people.

## Input

The first line contains an integer *m* (0 ≤ *m* ≤ 10), which is the number of relations of acquaintances among the five friends of Igor's.

Each of the following *m* lines contains two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ 5;*a**i* ≠ *b**i*), where (*a**i*, *b**i*) is a pair of acquainted people. It is guaranteed that each pair of the acquaintances is described exactly once. The acquaintance relation is symmetrical, i.e. if *x* is acquainted with *y*, then *y* is also acquainted with *x*.

## Output

Print "FAIL", if among those five people there are no either three pairwise acquainted or three pairwise unacquainted people. Otherwise print "WIN".

## Examples

## Input


```
4  
1 3  
2 3  
1 4  
5 3  

```
## Output


```
WIN  

```
## Input


```
5  
1 2  
2 3  
3 4  
4 5  
5 1  

```
## Output


```
FAIL  

```


#### tags 

#1300 #graphs #implementation #math 