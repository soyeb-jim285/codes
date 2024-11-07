<h1 style='text-align: center;'> D. Theft of Blueprints</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Insurgents accidentally got hold of the plan of a top secret research polygon created on a distant planet for the needs of the Galaxy Empire. The insurgents suppose that this polygon is developing new deadly weapon. The polygon consists of *n* missile silos connected by bidirectional underground passages. The passages are linked to laboratories where research is conducted. Naturally, the passages are guarded severely: the passage between silos *i* and *j* is patrolled by *c**i*, *j* war droids.

The insurgents studied the polygon plan and noticed its unusual structure. As it turned out, for any *k*-element set of silos *S* there is exactly one silo that is directly connected by a passage with each silo from *S* (we'll call this silo adjacent with *S*). Having considered that, the insurgents decided to act as follows:

1. they choose a *k*-element set of silos *S*;
2. a group of scouts lands from the air into each silo from *S*;
3. each group moves along the corresponding passage to the silo, adjacent with *S* (as the scouts move, they check out the laboratories and watch for any signs of weapon blueprints);
4. in the silo, adjacent with *S*, the groups get on the ship and fly away.

The danger of the operation is the total number of droids that patrol the passages through which the scouts will go. The danger of the operation obviously only depends on the way to choose set *S*. The insurgents haven't yet decided on the exact silos to send the scouts to. However, they already want to start preparing the weapons for the scout groups. To do that, the insurgents need to know the mathematical average of the dangers of the operations that correspond to all possible ways to choose set *S*. Solve this problem to help the insurgents protect the ideals of the Republic!

## Input

The first line contains two integers *n* and *k* (2 ≤ *n* ≤ 2000, 1 ≤ *k* ≤ *n* - 1) — the number of silos and the number of scout groups, correspondingly. The next *n* - 1 lines describe the polygon plan: the *i*-th of these lines contains *n* - *i* integers *c**i*, *i* + 1, *c**i*, *i* + 2, ..., *c**i*, *n* — the number of droids that patrol the corresponding passages (-1 ≤ *c**i*, *j* ≤ 109; if *c**i*, *j* =  -1, then silos *i* and *j* don't have a passage between them). All passages are bidirectional, that is, we can assume that *c**i*, *j* = *c**j*, *i*. No passages connect a silo with itself. It is guaranteed that the polygon plan meets the conditions of the problem statement.

## Output

Print the average danger of the scouting operation, rounded down to an integer. ## Note

 that at the given limits the answer to the problem always fits into the standard integer 64-bit data type.

Please do not use the %lld specifier to write 64-bit integers in С++. It is preferred to use the cout stream or the %I64d specifier.

## Examples

## Input


```
6 1  
-1 -1 -1 8 -1  
-1 5 -1 -1  
-1 -1 3  
-1 -1  
-1  

```
## Output


```
5  

```
## Input


```
3 2  
10 0  
11  

```
## Output


```
14  

```
## Note

In the first sample there are 6 one-element sets of silos. For sets {1}, {5} the operation danger will equal 8, for sets {3}, {6} — 3, for sets {2}, {4} — 5. The mathematical average equals ![](images/3bc833659595c25e73150ed7f23907011961ceca.png).

In the second sample there are 3 two-elements sets of silos: {1, 3} (danger equals 21), {1, 2} (danger equals 11), {2, 3} (danger equals 10). The average operation danger equals ![](images/02946ba8c525c97041629189ab4acc976074d8d1.png).



#### tags 

#2400 #graphs #math 