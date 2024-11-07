<h1 style='text-align: center;'> A. Weights</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $A$ of length $N$ weights of masses $A_1$, $A_2$...$A_N$. No two weights have the same mass. You can put every weight on one side of the balance (left or right). You don't have to put weights in order $A_1$,...,$A_N$. There is also a string $S$ consisting of characters "L" and "R", meaning that after putting the $i-th$ weight (not $A_i$, but $i-th$ weight of your choice) left or right side of the balance should be heavier. Find the order of putting the weights on the balance such that rules of string $S$ are satisfied. 

### Input

The first line contains one integer $N$ ($1 \leq N \leq 2*10^5$) - the length of the array $A$ The second line contains $N$ distinct integers: $A_1$, $A_2$,...,$A_N$ ($1 \leq A_i \leq 10^9$) - the weights given The third line contains string $S$ of length $N$ consisting only of letters "L" and "R" - string determining which side of the balance should be heavier after putting the $i-th$ weight of your choice

### Output

The output contains $N$ lines. In every line, you should print one integer and one letter - integer representing the weight you are putting on the balance in that move and the letter representing the side of the balance where you are putting the weight. If there is no solution, print $-1$.

## Example

### Input


```text
5
3 8 2 13 7
LLRLL
```
### Output


```text
3 L
2 R
8 R
13 L
7 L
```
## Note

Explanation for the test case:  

after the 1st weight: 3 L (left side is heavier)

after the 2nd weight: 2 R (left side is heavier)

after the 3rd weight: 8 R (right side is heavier)

after the 4th weight: 13 L (left side is heavier)

after the 5th weight: 7 L (left side is heavier)

So, the rules given by string $S$ are fulfilled and our order of putting the weights is correct.



#### Tags 

#2600 #NOT OK #constructive_algorithms #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Bubble_Cup_14_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred,_Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
