# Tutorial_(en)


### [1004A - Sonya and Hotels](../problems/A._Sonya_and_Hotels.md "Codeforces Round 495 (Div. 2)")

One hotel always can be built to the left of the first hotel. One more can be built to the right of the last hotel. Let's look at each pair of the adjacent hotels. If the distance between these two hotels is greater than $2\cdot d$, we can build one hotel at a distance of $d$ to the right from the left hotel and one more at a distance of $d$ to the left from the right hotel. If the distance between these two hotels is equal to $2\cdot d$, we can build only one hotel in the middle of them. Otherwise, we can not build a hotel between them.

 
### [1004B - Sonya and Exhibition](../problems/B._Sonya_and_Exhibition.md "Codeforces Round 495 (Div. 2)")

Note, that it is always optimal to use roses in even positions and lilies in odd positions. That is, the string 01010101010… is always optimal.

 
### [1004C - Sonya and Robots](../problems/C._Sonya_and_Robots.md "Codeforces Round 495 (Div. 2)")

Let's assume that our left robot is located in the $p$ position. The robot could be there only if the value that is written there did not occur earlier. The number of possible locations of the second robot is equal to the number of distinct numbers on the segment $[(p+1)\ldots n]$. Let $dp_i$ be the number of different numbers on $[(p+1)\ldots n]$. Let's find these number from right to left. If $a_i$ occurs the first time $dp_i=dp_{i+1} + 1$, otherwise, $dp_i=dp_{i+1}$.

 
### [1004D - Sonya and Matrix](../problems/D._Sonya_and_Matrix.md "Codeforces Round 495 (Div. 2)")

Suppose that a matrix has sizes $n\times m$, zero is located at $(x,y)$. Let $a$ be the distance to the cell $(1,1)$, and let $b$ the distance to the cell $(n,m)$. Obvious that the farthest distance from the zero cell will be to a corner cell. The maximum number in the list is equal to the maximum distance to a corner cell (let's assume that it is $b$).

We know that 

1. $n\cdot m = t$;
2. $a=x-1+y-1$;
3. $b=n-x+m-y$;
4. $n+m=a+b+2$.

And 

1. $a=n+m-b-2$;
2. $x-1+y-1=n+m-b-2$;
3. $y=n+m-b-x$.

Let's find the minimum $i$ $(i>0$) such that the number of occurrences of $i$ in the list is not equal to $4\cdot i$. We can notice that $x=i$. Let's look at each pair $(n, m)$ ($n\cdot m=t$). If we know $n, m, x$, and $b$, we can find $y$ and restore the matrix. If it could be done, we already found the answer.

 
### [1004E - Sonya and Ice Cream](../problems/E._Sonya_and_Ice_Cream.md "Codeforces Round 495 (Div. 2)")

The editorial for the main solution with centroid decomposition will be published later.

Another Solution (without really formal proof)

It is possible to show, that if we have all weights equal to $1$, then optimal answer is always a middle part of diameter of right length.

However, weights are arbitrary. Then we need to select a "weighted" middle part.

We can do it in a following way: set two pointers — one to the diameter beginning, and one to the end.

And while the number of vertices is greater $k$ we move the pointer, which has moved less from it's end.

However, in fact, sometimes we need to look at the neighboring $\pm 1$ possible subpaths —- for example if the last step was the same distance, then the optimal move depends on where the edge was longer.

This way we need to count answer for $\le 3$ paths. To count the answer for path we can run few dfs's, each of them will cover only part of graph, which hangs on related vertex of the path.

Complexity is $\mathcal{O}(n)$.

The sketch of the proof is something like this:

Examine the diameter. Notice, that the answer should contain it's middle point (vertex, which is most close to $1/2$) because the answer would be greater than the largest half of this diameter otherwise. 

From this we already bounded our answer, but we need more.

Then we want to start to grow the way to the ends of the diameter, so that at least from the end of the diameter of the distance was small.

Not the fact that this will be enough (for example, if there are several diameters), but it is necessary.

Two pointers are needed because growing in two directions may be necessary unevenly.

 
### [1004F - Sonya and Bitwise OR](../problems/F._Sonya_and_Bitwise_OR.md "Codeforces Round 495 (Div. 2)")

Will be added soon.

