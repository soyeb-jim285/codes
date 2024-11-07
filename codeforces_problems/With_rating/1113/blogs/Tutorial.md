# Tutorial

Tutorial is loading...[Author's solution](https://codeforces.com/https://ideone.com/hxF5jk) 

Tutorial is loading... [Author's solution](https://codeforces.com/https://ideone.com/mkondU) Tutorial is loading... [Author's solution](https://codeforces.com/https://ideone.com/Jf8Za8) Tutorial is loading... [Author's solution](https://codeforces.com/https://ideone.com/5XG0Bp) [Solution of bonus task](https://codeforces.com/https://ideone.com/mwSGec) 
### [1109C - Sasha and a Patient Friend](https://codeforces.com/contest/1109/problem/C "Codeforces Round 539 (Div. 1)")

Let's keep not deleted pairs (t,s) in a treap where t will be the key of some node. 

Also we need some auxiliary variables. So each node in the treap will store that:

* time  — time of the event
* speed  — speed of the tap since second time
* tL, tR  — the minimum and the maximum time in the subtree of that node
* speedR  — the speed of the event with maximum time in the subtree of that node
* res  — the value of patience after processing all events from the subtree (we assume that the value before tL-th second is 0)
* mn  — what is the minumum value of patience if we process all events from the subtree (also initial value is 0)
* links to the left child and to the right child

 It turns out that this information is enough. Now to make treap work correctly it should be possible to merge two chilrens of some node. Let's look how to do it (suppose that this node has either left child (LC) or right child (RC)): 

* time doesn't change
* speed doesn't change
* tL=LC.tL, tR=RC.tR, speedR=RC.speedR
* It is easier to calculate res and mn simulatenously. Look at this block of code: 
```cpp
  
mn = 0, res = 0    
mn = min(mn, LC.mn)    
res += LC.res + LC.speedR * (time - LC.tR)    
mn = min(mn, res)    
res += speed * (RC.tL - time)    
mn = min(mn, res + RC.mn)    
res += RC.res    
mn = min(mn, res)    

```
 It goes through all possible periods of time where mn can be, and finds the best one, during this it calculates res.

If there is no left or right child then the calculation doen't change too much.

So if you have combine function then you can do insert, delete, split, merge.

You can answer queries of the 3-rd type in the following way. Cut out the needed range from the treap. And go down the treap starting from the root while you can (you go to the left child, if the value of patience becomes equal to 0 earlier than time, you can check that using the imformation stored in nodes, then check the right one if it is needed). So it is left to consider some extreme cases, which I leave you as and exercise, and that is all. 

The complexity is O(q⋅log(q)). If you don't like treaps, you can actually use segment tree on pointers, or make coordinate compression and write a simple segment tree, the complexity will stay the same.

 [Author's solution](https://codeforces.com/https://ideone.com/2jVhHb) 
### [1109D - Sasha and Interesting Fact from Graph Theory](https://codeforces.com/contest/1109/problem/D "Codeforces Round 539 (Div. 1)")

Let's fix $edges$  — the number of edges on the path between $a$ and $b$. Then on this path there are $edges-1$ vertices between $a$ and $b$, and they can be choosen in $A(n - 2, edges - 1)$ ways. The amount of ways to place numbers on edges in such a way, that their sum is equal to $m$, is $\binom{m-1}{edges-1}$ (stars and bars method). If an edge doesn't belong to out path, then doesn't metter what number is written on it, so we can multiply answer by $m^{n-edges-1}$. Now, we want to form a forest from remaining $n-edges-1$ vertices and to hang it to any of $edges + 1$ vertexes from our path. According to one of generalizations of [Cayley's formula](https://codeforces.com/https://bit.ly/2S1EWbr), number of forsests of $x$ vertices, where vertices $1,2, \ldots, y$ belong to different trees is $f(x, y) = y \cdot x^{x - y - 1}$. So for fixed $edges$ we got the formula $trees(edges) = A(n - 2, edges - 1) \cdot f(n, edges + 1) \cdot \binom{m - 1}{edges - 1} \cdot m^{n - edges - 1}$

Complexity is $O((n + m) \cdot log(mod))$ or $O(n + m)$, in case you precompute all powers, factorials and thier inverse in linear time.

 [Author's solution](https://codeforces.com/https://ideone.com/vbiC9L) Tutorial is loading... [Author's solution](https://codeforces.com/https://ideone.com/wmOHHu) Tutorial is loading... [Author's solution](https://codeforces.com/https://ideone.com/GWzJof)