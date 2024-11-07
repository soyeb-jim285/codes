# Tutorial_1


### [1100A - Roman and Browser](../problems/A._Roman_and_Browser.md "Codeforces Round 532 (Div. 2)")

The constraints in this task allowed us to simply iterate over the closed tab and check the answer, but we can solve it more quickly — calculate the sum for each value modulo kk and count the total sum for the whole array. After that, you just need to go through the module tab numbers that we delete, and update the answer.

Complexity — O(n2)O(n2) or O(n+k)O(n+k).

 
### [1100B - Build a Contest](../problems/B._Build_a_Contest.md "Codeforces Round 532 (Div. 2)")

We will keep the arrays, how many problems are created for each specific complexity ii — cnticnti and how many problems have been created for the round jj — existjexistj. Then if we create a task with complexity cc, we will recalculate cntc=cntc+1cntc=cntc+1, existcntc=existcntc+1existcntc=existcntc+1. Suppose we have already given kk rounds. Then, after adding the next task, we only need to check that existk=nexistk=n, in this case we can held the next round, otherwise not.

The complexity is O(m)O(m).

 
### [1100C - NN and the Optical Illusion](../problems/C._NN_and_the_Optical_Illusion.md "Codeforces Round 532 (Div. 2)")

Consider three circles — inner and two outer. Since all the circles are tangent, the sides of the triangle constructed on the centers of the circles pass through the tangency points of the circles. Denote by αα the angle in an equilateral nn -gon. Then α=π(n−2)nα=π(n−2)n. On the other hand, Rr+R=cos( alpha2)Rr+R=cos( alpha2). It can be noted that Rr+R=R+r−rr+R=1−rr+RRr+R=R+r−rr+R=1−rr+R, i.e. the function increases with RR. On this basis, a binary search can be used to find the answer, or explicitly derive the formula R=rcos(α2)1−cos(α2)R=rcos(α2)1−cos(α2)

The complexity is O(1)O(1) or O(logC)O(logC).

 
### [1100D - Dasha and Chess](../problems/D._Dasha_and_Chess.md "Codeforces Round 532 (Div. 2)")

One of the possible strategies: the king goes to the center, then goes to the corner that he has as few rooks as possible behind his back. The solution uses the Pigeonhole principle, since in the largest corner and in two neighbors to it, the sum will be no less than 666∗3/4>499666∗3/4>499 rooks, i.e. ≥500≥500 rooks, and since the king gets to the corner for 499499 of moves, he will definitely get under check of the rook.

 
### [1100E - Andrew and Taxi](../problems/E._Andrew_and_Taxi.md "Codeforces Round 532 (Div. 2)")

Suppose we have kk traffic controllers. They can turn all edges whose weight is less than or equal to kk. Then let's remove all these edges from the graph, make a topological sorting of the remaining graph, and orient the other edges in the order of topological sorting. If there are cycles left in the graph after removing the edges, then we cannot get rid of them, having kk traffic controllers. Otherwise, by adding edges we will not add new loops. The parameter kk can be iterated through a binary search. Also in binary search, you can go through not all possible values ​​of kk, but only the values ​​that are on the edges.

Complexity — O((n+m)logC)O((n+m)logC) or O((n+m)logm)O((n+m)logm).

 
### [1100F - Ivan and Burgers](../problems/F._Ivan_and_Burgers.md "Codeforces Round 532 (Div. 2)")

Note that to answer on a segment, it is enough to know the basis of this segment, that is, the minimum set of numbers, with which you can represent all the numbers that are representable on this segment. Since 0≤ai≤10000000≤ai≤1000000, then the basis will be no more than 2020. To find the maximum number, run the Gauss algorithm for the basis so that there is no pair of numbers in the basis for which the maximum bit is the same. Then the maximum representable number can be obtained by the following algorithm: we will consider the numbers starting from the maximum, and add them to the answer if they increase the current answer.

The complete problem can be solved using the "divide and conquer" method: if we split the segment in half, then all requests on it either completely lie into one of the segments, or lieinto both. For requests that completely lie in one of the segments, we respond recursively. For queries that fall in both segments, we combine two linear hulls — hull[l,mid]hull[l,mid] and hull[mid+1,r]hull[mid+1,r]. All linear hulls of the form hull[i,mid]hull[i,mid] and hull[mid+1,j]hull[mid+1,j] can be obtained by adding vectors sequentially from right to left (on the right segment from left to right).

An alternative solution was proposed at the contest. Note that a query on a segment is a suffix of some array prefix. We will gradually increase the array prefix and maintain the "maximally right" array basis (if for the current prefix we go right through to the left, then the "maximally right" basis is the greedily typed basis of array values). When adding an element, it can either not be presented in the current basis, then it must be added to the current basis. If we can represent the element, then it is necessary to find the left-most element whose removal does not change the linear hull. This can be done by simulating Gauss algorithm from right to left: the first representable element must be removed from the basis. Since the basis is small, this operation can be done with each addition of a vector. We can get the answer to the problem, since for the fixed right element, we know at what point the basis changes as the left border moves from right to left.

Complexity is O((n+q)log2C)O((n+q)log2C) or O(nlog2C+q)O(nlog2C+q).

