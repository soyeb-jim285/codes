# Tutorial_(en)

Today, I solved a beautiful problem from the NEERC Subregional Contest: [Problem M](../problems/M._Algoland_and_Berland.md). Since I didn't find an editorial nor a solution in the comments, I decided to write this blog about my solution. For a visualization of my solution see: [Visualization of the program](https://codeforces.com/https://www.jeroenopdebeek.nl/GeometryVisuals/spanningtree.html) 

The problem boils down to constructing a spanning tree of a 2D point set with certain constraints. No three points in the point set are collinear. The points have two colors: red and blue. There is at least one blue and one red point. The constraints on the spanning tree are: 

* Edges of the spanning tree can only intersect at the ends, if they are drawn as line segments.
* Edges of the spanning tree can only connect points with different colors.
* For each blue point, the degree of the point in the spanning tree should be equal to ri.

The constraints on ri are nice: 1≤ri≤
# of red points. And ∑ri=n−1, which is of course needed if the final graph needs to be a tree. It turns out that these conditions are strong enough that it is always possible to construct a spanning tree!

Let's prove this by induction on the size of the point set, n.

### Base case n=2

Because there is at least one red and one blue point, the smallest case is n=2: one red and one blue point. Because of the constraint ∑ri=n−1=1, this means that the degree of the only blue point left is 1. The trivial solution is to connect the blue and the red point.

### Induction step n>2:

Now the hard part; Let's assume it is possible to make a spanning tree for all 2≤k<n. Now we are given a point set with n points, how do we construct the spanning tree for it? First, let's sort the points on their x-coordinate. We use the y-coordinate as a tiebreaker. Let's do casework on the colors of the leftmost and rightmost point:

#### Case 1: extreme points have different colors

Let's analyze the convex hull of the point set. As these two points both lie on the convex hull, the convex hull contains at least one red and one blue point. Certainly, there must be an adjacent pair of points on the hull with different colors. Let's connect these with an edge. If ri of the blue point is 1, we delete this point. Else we delete the red point, and lower ri by one. Notice that both the ∑ri and n decreased by one, so the resulting ri satisfy all constraints. It can also be verified that at least one red and blue point remain, with some casework. So we can use the induction hypothesis on this smaller point set, which gives us a spanning tree. Could our newly added edge intersect with an existing edge? No, because the edge lies on the convex hull. So in this case we are done.

For the last two cases, where both extreme points have the same color, we will use a different technique. Let's give each point a weight, For blue points, we set wi=−1+ri. For red points we set wi=−1. If the sum of weights is -1, that means ∑all points−1+∑blue pointsri=−1⟹∑blue pointsri=n−1. 

So if we could somehow split the point set with a vertical line through some point, such that the left and right halve both have the sum of weights equal to -1, we could use the induction hypothesis. For this to work we need both sides to have at least one point of each color. 

#### Case 2: extreme points are both blue

Let's look at the prefix sums of the weights of the point set in sorted order. So the prefix sum is pk=∑i<kwi, where the points are labeled from left to right. Because the total prefix sum is −1, and the prefix sum starts at 0, it must cross from nonnegative to negative at some point. Because the weights of all blue points are nonnegative the only place this can happen is at a red point. Because the weight of a red point is −1, it will cross from 0 to −1, and this is exactly what we wanted, a sum of weight equal to −1. Now we can draw a vertical line through this red point, and by the induction hypothesis construct two spanning trees, one containing all points to the left and the mid point, and one with all points to the right and the middle red point. Note that because the red point can't be one of the extreme points, the two point sets are definitely smaller than the initial point set. Since these spanning trees exist in two disjoint regions, they don't intersect. And they connect at the midpoint, so their union is a valid spanning tree of the whole point set! To ensure the regions are disjoint even if there are ties in x-coordinates, we tilt the splitting line slighly.

#### Case 3: extreme points are both red

We do exactly the same, looking for a prefix sum which is equal to −1. Now it turns out this is sometimes not possible. But by similar (but inverted) logic as in Case 2, there exists a blue point, such that the prefix sum goes from negative to nonnegative. We again make a vertical splitting line through this point, but now we modify the ri we will use for this blue midpoint in the left and right subproblem. We choose these new ri's such that the sum of weights in the left and right point sets is again −1. Then we apply the induction hypothesis to get two valid spanning trees of the left and right side. And the union of these spanning trees will be a valid spanning tree for the entire point set. This concludes the proof.

This proof is constructive, so for actually generating a spanning tree we can follow the induction logic backwards until the spanning tree is fully constructed. 

The easiest way to code this is to make a recursive function that constructs a spanning tree for the point set it's given. Based on the colors of the outermost points we either calculate a convex hull or prefix sums from left to right and call the function recursively. We only recurse n times, and the complexity per call can be made O(nlogn), so this gives O(n2logn). 

But if we additionally presort the points and ensure the point set stays sorted in the recursive calls, the convex hull calculation can also be done in linear time, resulting in O(n2) running time. 

Although this is not needed, I think this approach can be optimized further by using [Smart divide and conquer](https://codeforces.com/https://mzhang2021.github.io/cp-blog/divide-and-conquer/#:~:text=But%20we%20can%20do%20better) and [Decremental convex hull](https://codeforces.com/https://www.researchgate.net/publication/221209465_Applications_of_a_Semi-Dynamic_Convex_Hull_Algorithm), and some modifications to quickly find two oppositely colored adjacent points on the convex hull. This would give a recursive formula for the time complexity of T(n)=max1≤k<nT(k)+T(n−k)+O(min(k,n−k)log(n))=O(nlog2n), but this is definitely not needed to get AC.

My code can be found here: [submission](https://codeforces.com/contest/1070/submission/165107392)

