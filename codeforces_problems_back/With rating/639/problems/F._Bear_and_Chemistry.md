<h1 style='text-align: center;'> F. Bear and Chemistry</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Limak is a smart brown bear who loves chemistry, reactions and transforming elements.

In Bearland (Limak's home) there are *n* elements, numbered 1 through *n*. There are also special machines, that can transform elements. Each machine is described by two integers *a**i*, *b**i* representing two elements, not necessarily distinct. One can use a machine either to transform an element *a**i* to *b**i* or to transform *b**i* to *a**i*. Machines in Bearland aren't very resistant and each of them can be used at most once. It is possible that *a**i* = *b**i* and that many machines have the same pair *a**i*, *b**i*.

Radewoosh is Limak's biggest enemy and rival. He wants to test Limak in the chemistry. They will meet tomorrow and both of them will bring all their machines. Limak has *m* machines but he doesn't know much about his enemy. They agreed Radewoosh will choose two distinct elements, let's denote them as *x* and *y*. Limak will be allowed to use both his and Radewoosh's machines. He may use zero or more (maybe even all) machines to achieve the goal, each machine at most once. Limak will start from an element *x* and his task will be to first get an element *y* and then to again get an element *x* — then we say that he succeeds. After that Radewoosh would agree that Limak knows the chemistry (and Radewoosh would go away).

Radewoosh likes some particular non-empty set of favorite elements and he will choose *x*, *y* from that set. Limak doesn't know exactly which elements are in the set and also he doesn't know what machines Radewoosh has. Limak has heard *q* gossips (queries) though and each of them consists of Radewoosh's machines and favorite elements. For each gossip Limak wonders if he would be able to succeed tomorrow for every pair *x*, *y* chosen from the set of favorite elements. If yes then print "YES" (without the quotes). But if there exists a pair (*x*, *y*) from the given set that Limak wouldn't be able to succeed then you should print "NO" (without the quotes).

## Input

The first line contains three integers *n*, *m* and *q* (1 ≤ *n*, *q* ≤ 300 000, 0 ≤ *m* ≤ 300 000) — the number of elements, the number of Limak's machines and the number of gossips, respectively.

Each of the next *m* lines contains two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*) describing one of Limak's machines.

Then, the description of *q* gossips follows.

The first line of the description of the *i*-th gossip contains two integers *n**i* and *m**i* (1 ≤ *n**i* ≤ 300 000, 0 ≤ *m**i* ≤ 300 000). The second line contains *n**i* distinct integers *x**i*, 1, *x**i*, 2, ..., *x**i*, *n**i* (1 ≤ *x**i*, *j* ≤ *n*) — Radewoosh's favorite elements in the *i*-th gossip. ## Note

 that *n**i* = 1 is allowed, in this case there are no pairs of distinct elements, so Limak automatically wins (the answer is "YES"). Then *m**i* lines follow, each containing two integers *a**i*, *j*, *b**i*, *j* (1 ≤ *a**i*, *j*, *b**i*, *j*) describing one of Radewoosh's machines in the *i*-th gossip.

The sum of *n**i* over all gossips won't exceed 300 000. Also, the sum of *m**i* over all gossips won't exceed 300 000.

Important: Because we want you to process the gossips online, in order to know the elements in Radewoosh's favorite set and elements that his machines can transform, for on each number that denotes them in the input you should use following function:


```
int rotate(int element)  
{  
   element=(element+R)%n;  
  
   if (element==0) {  
       element=n;  
   }  
  
   return element;  
}  

```
where *R* is initially equal to 0 and is increased by the number of the query any time the answer is "YES". Queries are numbered starting with 1 in the order they appear in the input.

## Output

You should print *q* lines. The *i*-th of them should contain "YES" (without quotes) if for the *i*-th gossip for each pair of elements *x* and *y* (in the set *x**i*, 1, *x**i*, 2, ..., *x**i*, *n**i*) Limak is able to succeed. Otherwise you should print "NO" (without quotes).

## Examples

## Input


```
6 5 4  
1 2  
2 3  
3 4  
2 4  
5 6  
2 0  
4 2  
2 1  
6 2  
3 4  
3 2  
6 3 4  
2 5  
4 6  
2 1  
1 2  
1 2  

```
## Output


```
YES  
NO  
YES  
YES  

```
## Input


```
7 6 2  
1 2  
1 3  
2 4  
2 5  
3 6  
3 7  
7 2  
1 2 3 4 5 6 7  
4 5  
6 7  
7 2  
1 2 3 4 5 6 7  
4 6  
5 7  

```
## Output


```
NO  
YES  

```
## Note

Lets look at first sample:

In first gossip Radewoosh's favorite set is {4, 2} and he has no machines. Limak can tranform element 4 into 2 (so half of a task is complete) and then 2 into 3, and 3 into 4. Answer is "YES", so *R* is increased by 1.

In second gossip set in the input is denoted by {6, 2} and machine by (3, 4), but *R* is equal to 1, so set is {1, 3} and machine is (4, 5). Answer is "NO", so *R* isn't changed.

In third gossip set {6, 4, 3} and machines (2, 5) and (4, 6) are deciphered to be {1, 5, 4}, (3, 6) and (5, 1).

Consider Radewoosh's choices: 

* If he chooses elements 1 and 5, then Limak is able to transform 1 into 5, then 6 into 3, 3 into 2 and 2 into 1.
* If he chooses elements 5 and 4, then Limak is able to transform 5 into 6, 6 into 3, 3 into 4 (half way already behind him), 4 into 2, 2 into 1, 1 into 5.
* If he chooses elements 1 and 4, then Limak is able to transform 1 into 2, 2 into 4, 4 into 3, 3 into 6, 6 into 5 and 5 into 1.

So Limak is able to execute task. Answer is "YES" and *R* is increased by 3 (it's equal to 4 now).

In last gossip {1, 2} and (1, 2) are deciphered to be {5, 6} and (5, 6). Now there are 2 machines (5, 6) so Limak is able to execute task again.



#### tags 

#3300 #data_structures #dfs_and_similar #graphs #trees 