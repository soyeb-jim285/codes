<h1 style='text-align: center;'> B. Symmetric and Transitive</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Johnny has recently learned about set theory. Now he is studying binary relations. You've probably heard the term "equivalence relation". These relations are very important in many areas of mathematics. For example, the equality of the two numbers is an equivalence relation.

A set ρ of pairs (*a*, *b*) of elements of some set *A* is called a binary relation on set *A*. For two elements *a* and *b* of the set *A* we say that they are in relation ρ, if pair ![](images/7078d187b1ce0690fa4e0a5dac4b9a6327f07714.png), in this case we use a notation ![](images/e33776c12b1110b886c2b3b8860063bd6b3676f1.png).

Binary relation is equivalence relation, if:

1. It is reflexive (for any *a* it is true that ![](images/bc3a0bfef232965ec28452821d9ab08fffccaefe.png));
2. It is symmetric (for any *a*, *b* it is true that if ![](images/e33776c12b1110b886c2b3b8860063bd6b3676f1.png), then ![](images/cfc217552b88c13e840fc59501c2a60c23b6ee2d.png));
3. It is transitive (if ![](images/e33776c12b1110b886c2b3b8860063bd6b3676f1.png) and ![](images/e2faf9b3b19a369533dbc402f00118160d034ee9.png), than ![](images/82e31464f277331194858117731fe1dea18d5598.png)).

Little Johnny is not completely a fool and he noticed that the first condition is not necessary! Here is his "proof":

Take any two elements, *a* and *b*. If ![](images/e33776c12b1110b886c2b3b8860063bd6b3676f1.png), then ![](images/cfc217552b88c13e840fc59501c2a60c23b6ee2d.png) (according to property (2)), which means ![](images/bc3a0bfef232965ec28452821d9ab08fffccaefe.png) (according to property (3)).

It's very simple, isn't it? However, you noticed that Johnny's "proof" is wrong, and decided to show him a lot of examples that prove him wrong.

Here's your task: count the number of binary relations over a set of size *n* such that they are symmetric, transitive, but not an equivalence relations (i.e. they are not reflexive).

Since their number may be very large (not 0, according to Little Johnny), print the remainder of integer division of this number by 109 + 7.

## Input

A single line contains a single integer *n* (1 ≤ *n* ≤ 4000).

## Output

In a single line print the answer to the problem modulo 109 + 7.

## Examples

## Input


```
1  

```
## Output


```
1  

```
## Input


```
2  

```
## Output


```
3  

```
## Input


```
3  

```
## Output


```
10  

```
## Note

If *n* = 1 there is only one such relation — an empty one, i.e. ![](images/8891a227c918474e5d76377d4644cd7cc01e1ffd.png). In other words, for a single element *x* of set *A* the following is hold: ![](images/947c6cf761375432db9bd77796bccc89f1f1546d.png).

If *n* = 2 there are three such relations. Let's assume that set *A* consists of two elements, *x* and *y*. Then the valid relations are ![](images/8891a227c918474e5d76377d4644cd7cc01e1ffd.png), ρ = {(*x*, *x*)}, ρ = {(*y*, *y*)}. It is easy to see that the three listed binary relations are symmetric and transitive relations, but they are not equivalence relations.



#### tags 

#1900 #combinatorics #dp #math 