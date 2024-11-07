# Tutorial_(en)


### [1325A - EhAb AnD gCd](../problems/A._EhAb_AnD_gCd.md "Codeforces Round 628 (Div. 2)")

a=1a=1 and b=x−1b=x−1 always work.

Code link: [https://pastebin.com/ddHKD09B](https://codeforces.com/https://pastebin.com/ddHKD09B)

First AC: [sevlll777](https://codeforces.com/profile/sevlll777 "Candidate Master sevlll777")

**Bonus task:** can you count the valid pairs?

### [1325B - CopyCopyCopyCopyCopy](../problems/B._CopyCopyCopyCopyCopy.md "Codeforces Round 628 (Div. 2)")

Let the number of distinct elements in aa be called dd. Clearly, the answer is limited by dd. Now, you can construct your subsequence as follows: take the smallest element from the first copy, the second smallest element from the second copy, and so on. Since there are enough copies to take every element, the answer is dd.

Code link: [https://pastebin.com/hjcxUDmY](https://codeforces.com/https://pastebin.com/hjcxUDmY)

First AC: [socho](https://codeforces.com/profile/socho "Candidate Master socho")

### [1325C - Ehab and Path-etic MEXs](../problems/C._Ehab_and_Path-etic_MEXs.md "Codeforces Round 628 (Div. 2)")

Notice that there will be a path that passes through the edge labeled 00 and the edge labeled 11 no matter how you label the edges, so there's always a path with MEXMEX 22 or more. If any node has degree 3 or more, you can distribute the labels 00, 11, and 22 to edges incident to this node and distribute the rest of the labels arbitrarily. Otherwise, the tree is a bamboo, and it doesn't actually matter how you label the edges, since there will be a path with MEXMEX n−1n−1 anyway.

Code link: [https://pastebin.com/u4H7Dtbd](https://codeforces.com/https://pastebin.com/u4H7Dtbd)

First AC: [vintage_Vlad_Makeev](https://codeforces.com/profile/vintage_Vlad_Makeev "International Grandmaster vintage_Vlad_Makeev")

### [1325D - Ehab the Xorcist](../problems/D._Ehab_the_Xorcist.md "Codeforces Round 628 (Div. 2)")

First, let's look at some special cases. If u>vu>v or uu and vv have different parities, there's no array. If u=v=0u=v=0, the answer is an empty array. If u=v≠0u=v≠0, the answer is [u][u]. Now, the length is at least 2. Let x=v−u2x=v−u2. The array [u,x,x][u,x,x] satisfies the conditions, so the length is at most 3. We just need to figure out whether there's a pair of number aa and bb. Such that a⊕b=ua⊕b=u and a+b=va+b=v. Notice that a+b=a⊕b+2∗(aa+b=a⊕b+2∗(a&b)b), so we know that aa&b=v−u2=xb=v−u2=x (surprise surprise.) The benefit of getting rid of a+ba+b and looking at aa&bb instead is that we can look at aa and bb bit by bit. If xx has a one in some bit, aa and bb must both have ones, so a⊕b=ua⊕b=u must have a 0. If xx has a zero, there are absolutely no limitation on uu. So, if there's a bit where both xx and uu have a one, that is to say if xx&u≠0u≠0, you can't find such aa and bb, and the length will be 3. Otherwise, xx&u=0u=0 which means x⊕u=x+ux⊕u=x+u, so the array [u+x,x][u+x,x] works. Can you see how this array was constructed? We took [u,x,x][u,x,x] which more obviously works and merged the first 2 elements, benefiting from the fact that uu&x=0x=0.

Code link: [https://pastebin.com/7XuMk1v8](https://codeforces.com/https://pastebin.com/7XuMk1v8)

First AC: [jqdai0815](https://codeforces.com/profile/jqdai0815 "Legendary Grandmaster jqdai0815")

### [1325E - Ehab's REAL Number Theory Problem](../problems/E._Ehab's_REAL_Number_Theory_Problem.md "Codeforces Round 628 (Div. 2)")

Notice that for each element in the array, if some perfect square divides it, you can divide it by that perfect square, and the problem won't change. Let's define normalizing a number as dividing it by perfect squares until it doesn't contain any. Notice than any number that has 3 different prime divisors has at least 8 divisors, so after normalizing any element in the array, it will be 11, pp, or p∗qp∗q for some primes pp and qq. Let's create a graph where the vertices are the prime numbers (and 11,) and the edges are the elements of the array. For each element, we'll connect pp and qq (or pp and 11 if it's a prime after normalizing, or 11 with 11 if it's 11 after normalizing.) What's the significance of this graph? Well, if you take any walk from node pp to node qq, multiply the elements on the edges you took, and normalize, the product you get will be p∗qp∗q! That's because every node in the path will be visited an even number of times, except pp and qq. So the shortest subsequence whose product is a perfect square is just the shortest cycle in this graph!

The shortest cycle in an arbitrary graph takes O(n2)O(n2) to compute: you take every node as a source and calculate the bfs tree, then you look at the edges the go back to the root to close the cycle. That only finds the shortest cycle if the bfs source is contained in one. The graph in this problem has a special condition: you can't connect 2 nodes with indices greater than sqrt(maxAi)sqrt(maxAi). That's because their product would be greater than maxAimaxAi. So that means ANY walk in this graph has a node with index ≤√maxAi≤maxAi−−−−−−√. You can only try these nodes as sources for your bfs.

Code link: [https://pastebin.com/4ixLQyvg](https://codeforces.com/https://pastebin.com/4ixLQyvg)

**Bonus task:** try to prove the answer can't exceed 2√maxAi2maxAi−−−−−−√.

### [1325F - Ehab's Last Theorem](../problems/F._Ehab's_Last_Theorem.md "Codeforces Round 628 (Div. 2)")

Let sqsq denote ⌈√n⌉⌈n−−√⌉.

#### A solution using DFS trees

If you're not familiar with back-edges, I recommend reading [this](https://codeforces.com/blog/entry/68138) first.

Let's take the DFS tree of our graph. Assume you're currently in node uu in the DFS. If uu has sq−1sq−1 or more back-edges, look at the one that connects uu to its furthest ancestor. It forms a cycle of length at least sqsq. If uu doesn't have that many back-edges, you can add it to the independent set (if none of its neighbors was added.) That way, if you don't find a cycle, every node only blocks at most sq−1sq−1 other nodes, the ones connected to it by a back-edge, so you'll find an independent set!

Code link: [https://pastebin.com/b9phCSW8](https://codeforces.com/https://pastebin.com/b9phCSW8)

First AC: [imeimi](https://codeforces.com/profile/imeimi "International Grandmaster imeimi")

#### A solution using degrees

There's a pretty obvious greedy algorithm for finding large independent sets: take the node with the minimal degree, add it to the independent set, remove it and all its neighbors from the graph, and repeat. If at every step the node with the minimal degree has degree <sq−1<sq−1, that algorithm solves the first problem. Otherwise, there's a step where EVERY node has degree at least sq−1sq−1. For graphs where every node has degree at least dd, you can always find a cycle with length d+1d+1. To do that, we'll first try to find a long path then close a cycle. Take an arbitrary node as a starting point, and keep trying to extend your path. If one of this node's neighbors is not already in the path, extend that path with it and repeat. Otherwise, all of the last node's dd neighbors are on the path. Take the edge to the furthest and you'll form a cycle of length at least d+1d+1!

Code link: [https://pastebin.com/1VwZYPCj](https://codeforces.com/https://pastebin.com/1VwZYPCj)

First AC: [imeimi](https://codeforces.com/profile/imeimi "International Grandmaster imeimi") after only 11 minutes!

There are probably other solutions and heuristics. Can you share yours?

