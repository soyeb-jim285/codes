# Tutorial

Tutorial is loading...(Developing and idea — [vintage_Vlad_Makeev](https://codeforces.com/profile/vintage_Vlad_Makeev "Master vintage_Vlad_Makeev"))

 Tutorial is loading...(Developing and idea — [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"))

 Tutorial is loading...(Developing — [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot"), idea — jury)

 Tutorial is loading...(Developing — [Sehnsucht](https://codeforces.com/profile/Sehnsucht "Master Sehnsucht"), idea — Helen Andreeva)

 Tutorial is loading...(Developing and idea — [VFeafanov](https://codeforces.com/profile/VFeafanov "Candidate Master VFeafanov"))

 
### [1131F - Asya And Kittens](../problems/F._Asya_And_Kittens.md "Codeforces Round 541 (Div. 2)")

In this problem we are given a disjoint set union process with $n - 1$ steps, merging $n$ initial 1-element sets into one $n$-element set. We have to put elements into a linear array of cells, so that the cells to be joined at each step of the process were immediate neighbours (i.e. not separated by other cells).

This problem can be solved in $O(n\log n)$ or in $O(n\alpha(n))$ (where $\alpha(n)$ is the inverse Ackermann function) via standard disjoint-set data structure, additionally storing lists of elements in each set. 

The simplest solution is based on a set-size version of rank heuristic: 

* storing mapping from item to id (representative) of its current set, and the inverse mapping from set to the list of its elements
* when we have to merge two sets $A$ and $B$, we make the smaller set part of the larger set and update mappings, assigning new set ids for elements in $O(min(|A|, |B|))$ and concatenating the lists (can be done in $O(1)$ or in $O(min(|A|, |B|))$)

This gives us $O(n\log n)$: element can not change its set more than $log n$ times, because the change leads to (at least) doubling of the element's set size.

In order to get $O(n\alpha(n))$, we have to use the disjoint set structure with both path compression and rank heuristics, plus concatenation of lists should be done in $O(1)$.

(Developing and idea — [Sender](https://codeforces.com/profile/Sender "Expert Sender"))

 Tutorial is loading...(Developing and idea — [voidmax](https://codeforces.com/profile/voidmax "Master voidmax"))

