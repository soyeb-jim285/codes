# Tutorial_(en)

[1088A - Ehab and another construction problem](../problems/A._Ehab_and_another_construction_problem.md "Codeforces Round 525 (Div. 2)")
-------------------------------------------------------------------------------------------------------------------------------

Well, the constraints allow a brute-force solution, but here's an *O*(1) solution:

If *x* = 1, there's no solution. Otherwise, just print *x* - *x*%2 and 2.

Code link: [https://pastebin.com/LXvuX8Ez](https://codeforces.com/https://pastebin.com/LXvuX8Ez)

Time complexity: *O*(1).

[1088B - Ehab and subtraction](../problems/B._Ehab_and_subtraction.md "Codeforces Round 525 (Div. 2)")
--------------------------------------------------------------------------------------------------------------

Let *s* be the set of numbers in input (sorted and distinct). In the *i**th* step, *s**i* is subtracted from all bigger or equal elements, and all smaller elements are 0. Thus, the answer in the *i**th* step is *s**i* - *s**i* - 1 (*s*0 = 0).

Code link: [https://pastebin.com/bpz1YxBe](https://codeforces.com/https://pastebin.com/bpz1YxBe)

Time complexity: *O*(*nlog*(*n*)).

[1088C - Ehab and a 2-operation task](../problems/C._Ehab_and_a_2-operation_task.md "Codeforces Round 525 (Div. 2)")
----------------------------------------------------------------------------------------------------------------------

The editorial uses 0-indexing.

Both solutions make *a**i* = *i*.

#### First solution, n adds and 1 mod

First, let's make *a**i* = *x* * *n* + *i* (for some *x*). Then, let's mod the whole array with *n* (making *a**i* = *i*). If the "add update" changed one index, we can just add *i* + *n* - *a**i*%*n* to index *i*. The problem is, if we make *a**i* = *x* * *n* + *i*, then update an index *j* > *i*, *a**i* will be ruined. Just start from the back of the array!

Code link: [https://pastebin.com/dBfhNBL8](https://codeforces.com/https://pastebin.com/dBfhNBL8)

#### Second solution, 1 add and n mods

**Note**: for any *a*, *b*, if *b* > *a*, *a*%*b* = *a*. Additionally, if *a* ≥ *b* > ![](images/be27e77d171d6e092063ab474427ebf2128422d7.png), *a*%*b* = *a* - *b*.

Let's add 5·105 to the whole array, loop over *a**i* (in order), and mod prefix *i* with *a**i* - *i*. Why does this work? Notice that *a**i*%(*a**i* - *i*) = *a**i* - (*a**i* - *i*) = *i* (the second note). Also, *a**i* won't be changed afterwards (the first note).

Code link: [https://pastebin.com/L6suPC1f](https://codeforces.com/https://pastebin.com/L6suPC1f)

Time complexity: *O*(*n*).

[1088D - Ehab and another another xor problem](../problems/D._Ehab_and_another_another_xor_problem.md "Codeforces Round 525 (Div. 2)")
------------------------------------------------------------------------------------------------------------------------------

This problem is particularly hard to explain :/ I recommend the simulation.

Let's build *a* and *b* bit by bit from the most significant to the least significant (assume they're stored in *curA* and *curB*). Then, at the *i**th* step, ![](images/7b2e1fd6837f4af02cc7f16a34293f21dfb7589c.png) and ![](images/9ebc69cee44151e28ef1dcf56c417f0cbf556acb.png) have all bits from the most significant to the (*i* + 1)*th* set to 0. Notice that whether *x* is greater or less than *y* is judged by the most significant bit in which they differ (the one that has 1 is bigger). Let's query with ![](images/653699f50d276dd31c39224dcad7e06a71a87acf.png) and ![](images/186b404dc3884bf84247c551c0843f3dbd2a5b60.png). ![](images/448754475d92f0f10758b9e0ba35d743c89bce3a.png) and ![](images/63ab24ec29bd05e4c122c3065f70febbaeb8d465.png) can only differ in the *i**th* bit (or a bit less significant). Now, if the results of the queries are different, *a* and *b* have the same value in this bit, and this value can be determined by the answer of respective queries (1 if the second query's answer is 1, 0 otherwise). If the queries give the same result, *a* and *b* must differ in this bit. How to know which of them has a 1 and which has a 0? We know that the greater between them (after setting the processed bits to 0) has a 1 and the other has a 0. The trick is to keep track of the greater between them. Before all queries, we send (0, 0) to know the greater. Every time they differ in a bit, the greater may change. It'll simply change to the answer of the 2 queries we sent! In other words, we know when we sent the queries that after making *a* and *b* equal in this bit, some other bit became the most significant bit in which they differ. Also, we know who has a 1 in this bit (the greater in this query). Thus, we'll keep the answer of this query for the future, so when this bit comes, we don't need additional queries.

 **Simulation for an example**Let's simulate for *a* = 6 and *b* = 5.

In the first query, we'll send (0, 0) to know that *a* > *b*.

In the second query, we'll send (4, 0) (the answer is -1) and (0, 4) (the answer is 1). Since the answers differ, this bit has the same value for *a* and *b*. Since the answer to the second query is 1, they both have a 1. Now, *curA* = *curB* = 4.

In the third query, we'll send (6, 4) (the answer is -1) and (4, 6) (the answer is -1). Since the answers are the same, *a* and *b* differ in this bit. Since *a* is currently the greater, *a* has a 1 and *b* has a 0. Now, the greater is *b* (the next time 2 bits differ, *b* will have a 1). Also, *curA* = 6 and *curB* = 4.

In the last query, we'll send (7, 4) (the answer is 0) and (6, 5) (the answer is 0). Since the answers are the same, *a* and *b* differ in this bit. Since *b* is currently greater, *b* has a 1. Now, *curA* = 6 and *curB* = 5 and we're done :D

Code link: [https://pastebin.com/b9zgKuJ6](https://codeforces.com/https://pastebin.com/b9zgKuJ6)

Time complexity: *O*(*log*(*n*)).

[1088E - Ehab and a component choosing problem](../problems/E._Ehab_and_a_component_choosing_problem.md "Codeforces Round 525 (Div. 2)")
-------------------------------------------------------------------------------------------------------------------------------

Assume you already chose the components. Let the sum of nodes in the *i**th* component be *b**i*. Then, the expression in the problem is equivalent to *average*(*b*1, *b*2, ..., *b**k*). Assume we only bother about the fraction maximization problem and don't care about *k*. Then, it'll always be better to choose the component with the maximum *b**i* and throw away the rest! This is because of the famous inequality:

*max*(*b*1, *b*2, ..., *b**k*) ≥ *average*(*b*1, *b*2, ..., *b**k*) and the equality only occurs if all *b**i* are equal!

This means that the maximum value of the fraction is simply the maximum sum of a sub-component in the tree. To calculate it, let's root the tree at node 1, and calculate *dp*[*node*], the maximum sum of a sub-component that contains node. Now, I'll put the code, and explain it after.

 
```cpp
void dfs(int node,int p,bool f)
{
    dp[node]=a[node];
    for (int u:v[node])
    {
        if (u!=p)
        {
            dfs(u,node,f);
            dp[node]+=max(dp[u],0LL);
        }
    }
    if (f)
    ans=max(ans,dp[node]);
    else if (dp[node]==ans)
    {
        dp[node]=0;
        k++;
    }
}
```
*ans* denotes the maximum sub-component sum.

First, we call *dfs*(1, 0, 1). We calculate the *dp* of all the children of *node*. For every child *u*, we extend the component of *node* with the component of *u* if *dp*[*u*] > 0, and do nothing otherwise. Now, we solved the first half of our problem, but what about maximizing *k*? Notice that all components you choose must have a sum of weights equal to *ans* (because the equality occurs if and only if all *b**i* are equal). You just want to maximize their count. Let's calculate our *dp* again. Assume *dp*[*node*] = *ans*. We have 2 choices: either mark the *node* and its component as a component in the answer (but then other nodes won't be able to use them because the components can't overlap), or wait and extend the component. The idea is that there's no reason to wait. If we extend the component with some nodes, they won't change the sum, and they may even have another sub-component with maximal sum that we're merging to our component and wasting it! Thus, we'll always go with the first choice, making *dp*[*node*] = 0 so that its parent can't use it, and increasing *k* :D

Code link: [https://pastebin.com/8pCrTfuP](https://codeforces.com/https://pastebin.com/8pCrTfuP)

Time complexity: *O*(*n*).

[1088F - Ehab and a weird weight formula](../problems/F._Ehab_and_a_weird_weight_formula.md "Codeforces Round 525 (Div. 2)")
-------------------------------------------------------------------------------------------------------------------------

First, let's reduce the problem to ordinary MST. We know that each edge {*u*, *v*} adds ⌈*log*2(*dist*(*u*, *v*))⌉·*min*(*a**u*, *a**v*) to *w*. In fact, it also adds 1 to *deg**u* and *deg**v*. Thus, the problem is ordinary MST on a complete graph where each edge {*u*, *v*} has weight (⌈*log*2(*dist*(*u*, *v*))⌉ + 1)·*min*(*a**u*, *a**v*) + *max*(*a**u*, *a**v*)!

Let the node with the minimum weight be *m*. Let's root the tree at it.

**Lemma**: for every node *u* and a child *v*, *a**v* > *a**u*. In simpler words, the weight increase as we go down the tree.

**Proof**: the proof is by contradiction. Assume *a**v* ≤ *a**u*. Then, the condition in the problem (that every node has an adjacent node with less weight) isn't satisfied yet for *v*. Therefore, *v* must have a child *k* such that *a**k* < *a**v*. However, the condition isn't satisfied for *k*, so *k* needs another child and the child needs another child etc. (the tree will be infinite) which is clearly a contradiction.

From that, we know that the weights decrease as we go up the tree and increase as we go down.

Back to the MST problem. From Kruskal's algorithm, we know that the minimal edge incident to every node will be added to the MST (because the edges are sorted by weight). Let's analyze the minimal edge incident to every node *u*. Let its other end be *v*. Except for node *m*, ***v* will be an ancestor of *u***. Why? Assume we fix the distance part and just want to minimize *a**v*. We'll keep going up the tree (it's never optimal to go down, since the weights will increase) until we reach the desired distance. Now, since the minimal edge incident to every node will be added to the MST (by Kruskal's algorithm), and they're distinct (because, otherwise, you're saying that *u* is an ancestor of *v* and *v* is an ancestor of *u*), THEY ARE THE MST. Now, the problem just reduces to finding the minimal edge incident to every node and summing them up (except for *m*). To do that, we'll fix the ⌈*log*2(*dist*(*u*, *v*))⌉ (let it be *k*), and get the 2*k**th* ancestor with the well-known sparse-table (binary lifting).

Code link: [https://pastebin.com/vzJqh8si](https://codeforces.com/https://pastebin.com/vzJqh8si)

Time complexity: *O*(*nlog*(*n*)).

