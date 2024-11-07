# Tutorial_(en)


### [1236A - Stones](../problems/A._Stones.md "Codeforces Round 593 (Div. 2)")

We can use many ways to solve the problem. If you just enumerate how many operations of the first and the second type, it will also pass.

Of course there is a greedy solution. We make the second operation as much as possible, and then use the first operation. It takes $O(1)$ time.

 
### [1236B - Alice and the List of Presents](../problems/B._Alice_and_the_List_of_Presents.md "Codeforces Round 593 (Div. 2)")

The answer is $(2^m-1)^n$.

If we consider each present, it may contain only in the first box, in the second ... both in the first and second box, in the first and the third one ... in the first,the second and the third one ... There are $2^m-1$ ways.

There are $n$ presents, so there are $(2^m-1)^n$ ways in total according to the Multiplication Principle.

 
### [1236C - Labs](../problems/C._Labs.md "Codeforces Round 593 (Div. 2)")

The maximum number is $\lfloor\frac{n^2}{2}\rfloor$.

It can be proved we cannot find a larger answer. There is $n^2$ pipes between any two groups. So the valid pairs of the minimum of them does not exceed $\lfloor\frac{n^2}{2}\rfloor$.

Then we try to find a way to achieve the maximum. We find if we put the first lab in the first group, the second one to the second group ... the $n$-th one to the $n$-th group. Then put the $n+1$-th one in the $n$-th group, the $n+2$-th one in the $n-1$-th group ... the $2n$-th one to the first group. And then again use the method for the $2n+1$-th to the $4n$-th lab. if $n$ is odd, then we will only use the previous half of the method.

 
### [1236D - Alice and the Doll](../problems/D._Alice_and_the_Doll.md "Codeforces Round 593 (Div. 2)")

Consider just simulate the whole process. We walk straight, and then turn right when meet the obstacle or the border of the grid. Then we can use set to make it faster. We can check along the direction, which is the first obstacle. To check whether any cell is covered, we can calculate the number of cells we walk across and then check if it equals to $n*m-k$. Also,we can sort the obstacles by x and y, then use binary search to find the first obstacle along the direction.

Time complexity is $O(nlogn)$.

 
### [1236E - Alice and the Unfair Game](../problems/E._Alice_and_the_Unfair_Game.md "Codeforces Round 593 (Div. 2)")

First there is a conclusion: each start point will be able to reach a consecutive segment of end points except for n=1.

It's easy to prove, when a place is banned, we can make a move to make it reachable again.

So with the conclusion then we can solve the problem. First we will come up with a greedy algorithm. We can move the doll to the left (or right) if possible, otherwise we can keep it at its place. Then we will get the left bound and the right bound of one start point. It's $O(n^2)$ and not enough to pass.

Consider we try to find the left bound. We scan the array $a$ and deal with all start points together. For the first element of $a$, it will only influence one start point (that is, if we start from there, we will meet the element can then we need to keep it at its place). So we can move the start point to its right box (because when it starts from that place, we will get the same answer). Then we can delete the first element. But then there will be more than one start point in the same cell, we can use dsu to merge two set of start points.

Note that the doll cannot move to $0$ or $n+1$. We can also have to deal with this using the algorithm above. And it is the same to find the right bound.

Time complexity is $O(n)$.

Another solution: Consider a grid that there is obstacles on $(i,a_i)$. Each time we start from $(0,y)$ and if there is no obstacle on $(x+1,y-1)$ then we move to it, otherwise we move to $(x,y-1)$. We find we may change the direction only if we reach the place $(i-1,a_i+1)$ and we will walk to $(i,a_i+1)$. So only the $O(k)$ positions are useful. We can use binary search to find the next position for each useful position and start point. Then we get a tree. Just using dfs then we will get left bound for each start points. The Time complexity is $O(nlogn)$.

 Tutorial is loading...