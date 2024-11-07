# Tutorial

Author: [GreenGrape](https://codeforces.com/profile/GreenGrape "Candidate Master GreenGrape") 

### [1025A - Doggo Recoloring](../problems/A._Doggo_Recoloring.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

It's easy to see that, if there exists such a color xx that at least two puppies share this color, the answer is "Yes" as we can eliminate colors one by one by taking the most numerous color and recoloring all puppies of this color into some other (the number of colors will decrease, but the more-than-one property for the most numerous color will hold, so apply induction).

If all puppies' colors are distinct, the answer is "No" except for the case when n=1n=1 (since there's no need to recolor the only puppy).

Author: [GreenGrape](https://codeforces.com/profile/GreenGrape "Candidate Master GreenGrape") 

### [1025B - Weakened Common Divisor](../problems/B._Weakened_Common_Divisor.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

The obvious solution of finding all divisors of all numbers in O(n⋅√amax)O(n⋅amax−−−−√) definitely won't pass, so we have to come up with a slight optimization.

One may notice that is's sufficient to take a prime WCD (because if some value is an answer, it can be factorized without losing the answer property). To decrease the number of primes to check, let's get rid of the redundant ones. 

Take an arbitrary pair of elements (aiai, bibi) and take the union of their prime factorizations. It's easy to see at this point that the cardinality of this union doesn't exceed 2⋅logamax2⋅logamax. The rest is to check whether there exists such prime that divides at least one element in each pair in O(n⋅logamax)O(n⋅logamax) time.

Author: [GreenGrape](https://codeforces.com/profile/GreenGrape "Candidate Master GreenGrape") 

### [1025C - Plasticine zebra](../problems/C._Plasticine_zebra.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

Imagine just for a second, that in reality our string is cyclic with a cut at point 00 and clockwise traversal direction.

Now let's apply the cut & reverse operation at point ii. The key fact here is that nothing happens to the cyclic string — it's just the traversal direction and the cut point (now ii instead of 00) that change.

Here's an example. Let the string be bwwbwbbwbwwbwbbw and we cut it after the 22-nd letter (11-indexed). It's easy to see that it transforms to wbwbbwbwwbwbbwbw, which equals the initial one after shifting it to the left by 22 and inverting the traversal direction.

This observation helps us see that all strings obtained within these operations are in fact just cuts of one cyclic strings with precision up to traversal direction. In other words, it's enough to find the longest zebra inside the cyclic string — this value will be the answer to the problem.

Author: [GreenGrape](https://codeforces.com/profile/GreenGrape "Candidate Master GreenGrape") 

### [1025D - Recovering BST](../problems/D._Recovering_BST.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

Let dp(l,r,root)dp(l,r,root) be a dp determining whether it's possible to assemble a tree rooted at rootroot from the subsegment [l..r][l..r].

It's easy to see that calculating it requires extracting such rootleftrootleft from [l..root−1][l..root−1] and rootrightrootright from [root+1..right][root+1..right] that:

* gcd(aroot,arootleft)>1gcd(aroot,arootleft)>1;
* gcd(aroot,arootright)>1gcd(aroot,arootright)>1;
* dp(l,root−1,rootleft)=1dp(l,root−1,rootleft)=1;
* dp(root+1,r,rootright)=1dp(root+1,r,rootright)=1.

This can be done in O(r−l)O(r−l) provided we are given all dp(x,y,z)dp(x,y,z) values for all subsegments of [l..r][l..r]. Considering a total of O(n3)O(n3) dp states, the final complexity is O(n4)O(n4). That's too much.

Let's turn our dp into dpnew(l,r,side)dpnew(l,r,side) where sideside can be either 00 or 11 — is it possible to make a tree from [l..r][l..r] rooted at l−1l−1 or r+1r+1 respectively. It immediately turns out that dp(l,r,root)dp(l,r,root) is inherited form dpnew(l,root−1,1)dpnew(l,root−1,1) and dpnew(root+1,r,0)dpnew(root+1,r,0). Now we have O(n2)O(n2) states, but at the same time all transitions are performed in linear time; thus final complexity is O(n3)O(n3) which is sufficient to pass.

Author: [ashmelev](https://codeforces.com/profile/ashmelev "Grandmaster ashmelev") 

### [1025E - Colored Cubes](../problems/E._Colored_Cubes.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

We're gonna show how to turn an arbitrary arrangement of cubes into the arrangement where ii-th cube is located at (i,i)(i,i) (we call such an arrangement basic) in no more than 2∗n22∗n2 operations. For simplicity, we imply that we have exactly nn cubes where nn is even.

Say we have some arrangement where ii-th cube occupies some cell (xi,yi)(xi,yi). On the first step, we turn it into the arrangement where all cubes have distinct xx coordinates. In order to do this, we sort cubes in ascending order of their xx coordinates xx (with ties broken arbitrarily) . If cube ii is at position jj in the sorted list, we say that its desired coordinates are (j,yi)(j,yi). It's easy to check that such choice always allows to move at least one cube from its current position to the desired one through the y=yiy=yi line. If we perform this operation nn times, we'll move all cubes to their desired positions. In addition, the maximum number of operations will occur if all the cubes were initially located on the line x=1x=1 or x=nx=n, and in this case the number of operations will be equal to 0+1+...+(n−1)0+1+...+(n−1) < n2/2n2/2. 

The formal proof of this inequality can be given using the induction principle. Indeed, the base (n=1n=1) is obvious. Now let the statement be true for all k≤nk≤n. Let's prove that if the number of cubes (and the size of the board) changes from nn to (n+1)(n+1), the upper limit of the number of operations increases by no more than nn. Consider the cube ii with maximum xx coordinate which we have to move to xi=nxi=n. If initially xixi is less than nn, we move this cube to the desired position in no more than nn operations, and other nn cubes have coordinates xj≤nxj≤n which implies the upper limit of n∗(n−1)/2n∗(n−1)/2 operations by definition. But if xixi is initially nn, we don't have to move it whereas each of the remaining nn cubes requires one more additional (i.e nn total) operation since we added only one diagonal. In total we'll make a total of n+n∗(n−1)/2=n∗(n+1)/2n+n∗(n−1)/2=n∗(n+1)/2 operations.

Now all xx coordinates are distinct and that means that nothing restricts us from changing their yy coordinates. Let's move the cubes in such a way that ii-th cube ends at position yi=iyi=i. One cube can be processed in no more than min(i−1,n−i)min(i−1,n−i) operations. According to this, we need at most (n−1)+(n−2)+...+n/2+n/2+...+(n−1)=2∗((n/2)∗(n/2+n−1)/2)=3∗n∗(n−2)/4≤3∗n2/4(n−1)+(n−2)+...+n/2+n/2+...+(n−1)=2∗((n/2)∗(n/2+n−1)/2)=3∗n∗(n−2)/4≤3∗n2/4 operations in total. Now we obtain an arrangement where all yy coordinates are also distinct. If we apply the same operation to cubes' xx coordinates, we will end up with ii-th cube at position (i,i)(i,i). This requires no more than n2/2+2∗(3∗n2/4)=2∗n2n2/2+2∗(3∗n2/4)=2∗n2 operations.

Now we can switch any arrangement to the basic one. Let's get the list of operations for turning the initial position to basic and the final position to basic. Now it's sufficient to reverse one of the lists and concatenate these actions. This yields no more than 4∗n2≤100004∗n2≤10000 operations in total.

Note that this estimate is quite rough; however, this is enough under given constraints.

Author: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto") 

### [1025F - Disjoint Triangles](../problems/F._Disjoint_Triangles.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

The most challenging part of the problem is to think of the way how to count each pair of triangles exactly once.

It turns out, that this can be done in a nice and geometrical way.

Each pair of triangles has exactly two inner tangents between them. Moreover, exactly one of them (if we direct tangent from point of the first polygon to the point of the second polygon) leaves the first rectangle on the right side and the other tangent leaves it on the left side.

So let's brute-force the inner tangent. If we continue the tangent to draw the line and count the number of points on the left and on the right of it, say k1k1 and k2k2 respectively, then we simply need to add k1(k1−1)2k2(k2−1)2k1(k1−1)2k2(k2−1)2 to our answer, since if we select arbitrary pair of vertices on each halfplanes, together with tangent points we will form a pair of triangles with such a tangent.

The question is how to count k1k1 and k2k2 for each tangent efficiently. If the points would be sorted by direction, perpendicular to the tangent, we could have answered this query with binary search (since points of one halfplane form a prefix of the sorted array and the other — suffix).

However, if we wrote down all the interesting directions, sort them by angle, and make a scanline on it, we could maintain the points in sorted order.

Basically, points aiai and ajaj change their order in the sorted array at the direction rotate90(ai−aj)rotate90(ai−aj), and, since there are no three points on one line, these points are neighbours in the sorted array at the moment of the swap.

The complexity is O(n2log(n))O(n2log(n)) since we need to sort all n2n2 directions and for each direction make a binary search on the sorted array.

Author: [Lewin](https://codeforces.com/profile/Lewin "Grandmaster Lewin") 

### [1025G - Company Acquisitions](../problems/G._Company_Acquisitions.md "Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

You can solve this most likely by brute forcing small cases and looking for a pattern.

Here's a proof of the pattern. Let's define a potential of a startup with kk followers to be equal to 2k−12k−1. For example, an active startup with zero followers has potential zero.

Now, in one day, if we choose a startup with pp followers, and a startup with qq followers, the expected change in sum of potentials is equal to 12((2p+1−1−2p+1)−2q+1)+12((2q+1−1−2q+1)−2p+1)=112((2p+1−1−2p+1)−2q+1)+12((2q+1−1−2q+1)−2p+1)=1, regardless of the values of pp and qq.

The potential of the final state is 2n−1−12n−1−1, and we can compute the current potential in linear time, so the expected number of turns is the difference between them.

To prove this more rigorously, we can use show that this process is a martingale, so we can use https://en.wikipedia.org/wiki/Optional_stopping_theorem to show that the expected number of days is exactly equal to this difference.

