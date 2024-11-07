# Tutorial

[1735A - Working Week](../problems/A._Working_Week.md "Codeforces Round 824 (Div. 2)")

 **Hint1**Let's consider that l1, l2, and l3 are sorted working segments. Can we explicitly say something about one of them? 

 **Answer to Hint1**l1 must be equal to 1.

 **Solution**Let's consider that l1, l2, and l3 are sorted working segments.

If l1 is not equal to 1 then we can decrease l1 by 1 and increase l3 by 1. So we'll increase the answer.

We've got that l1=1 and we have to work just with l2 and l3.

Now, our problem can be rewritten as:  
l2+l3=n−4, maximize min(l2−1,l3−l2).

And as we know that l3=n−4−l2, just:  
maximize min(l2−1,n−4−2⋅l2).

If we increase both values under the minimum scope by one, solutions don't change:  
maximize min(l2,(n−3)−2⋅l2).

If we choose l2=⌊n−33⌋, then min(l2,(n−3)−2⋅l2)=⌊n−33⌋.  
If the answer is greater, then l2>n−33 and (n−3)−2⋅l2>n−33, and it means that 2⋅(l2)+((n−3)−2⋅l2)>n−3 but 2⋅(l2)+((n−3)−2⋅l2)=n−3.

The only thing is left to do is to calculate final answer. And it is ⌊n−33⌋−1 or just ⌊n3⌋−2.

It was a mathematician way of solving. As it's pretty obvious that l2 is approximately n3, you could check l2=n3±5 and choose the best among them.

 **Code**[174443363](https://codeforces.com/contest/1735/submission/174443363 "Submission 174443363 by Akulyat")

[1735B - Tea with Tangerines](../problems/B._Tea_with_Tangerines.md "Codeforces Round 824 (Div. 2)")

 **Hint1**Is there a way to cut pieces to save the minimum value and satisfy required conditions?

 **Hint2**What is the minimum possible number of operations to perform it?  
Is there any better solution? 

 **Solution**Let's start with a simple solution.

Let's choose the minimum piece from a and assume that it will remain the minimum until the end.  
As the array is sorted, let's define the minimum piece as a1.  
It means that in the end, all pieces must be smaller or equal to 2⋅a1−1. 

The lower bound of the answer for this solution is n∑i=1⌈ai2⋅a1−1⌉. 

Let's show that this is achievable.  
For each piece, while its size greater than 2⋅a1−1, let's cut off a piece of size 2⋅a1−1.  
The only problem is that we could get a piece smaller than a1 in the end.  
But it means that before the last cut we had a piece in the range [2⋅a1,3⋅a1−2]. All pieces in this range can be easily cut into pieces of the right size in one move. 

The only left question is why the minimum piece in the end should have size a1. Actually, it shouldn't, but it gives the best answer anyway.  
As was described above, the lower bound of the solution with the minimal piece of size x in the end is n∑i=1⌈ai2⋅x−1⌉.  
Having a minimal piece with a smaller size, we can't get anything better, because the lower bound will be equal or greater for all x<a1.

 **Code**[174443424](https://codeforces.com/contest/1735/submission/174443424 "Submission 174443424 by Akulyat")

[1735C - Phase Shift](../problems/C._Phase_Shift.md "Codeforces Round 824 (Div. 2)")

 **Hint1**What is the first letter in the answer?

 **Answer to Hint1**a if t doesn't start with a and b otherwise.

 **Hint2**Ask the same question as Hint1 for each position. 

 **Hint3**When we can't choose the minimum unused letter?

 **Answer to Hint3**If we form a circle of size less then 26.  
Maintain any structure to check it.

 **Solution**First of all, the encryption process is reversible. If we obtained t from s using the circle c, we can obtain s from t using the same cycle c, but reversed.  
So, let's think in terms of encryption of t.

Lexicographical order itself is a greedy thing. So, we can create a greedy algorithm.

Let's go from left to right and generate the result letter by letter. We have to choose the best possible option at each step. Let's describe the options we have.

 * If the current letter was used earlier, we already know the replacement we need to choose.
* Otherwise, we would like to choose the minimum possible option. We need to maintain some structure to know what is acceptable.

Let's keep the circle that is already generated(it's a graph). For each letter we have one incoming edge and one outgoing edge in the end. Let's keep them for every letter: arrays in[26], out[26].  
When we want to generate an outgoing edge at some step(let's define the letter on this step as x), we have to choose the minimum letter that doesn't have an incoming edge yet. With one exception: if creating the edge using this rule creates a circle of size less than 26. It would mean that we wouldn't have a full circle in the end. It's easy to see that there is no more than one such letter, as this letter is just the end of a chain starting in x.  
To check that a small circle wasn't generated, we can go along an outgoing edge 26 times, starting at x. If we end up in x or there was no edge at some step then everything is ok, we can create this edge.

Complexity is O(26⋅26+n), that is, O(n).

 **Code**[174443480](https://codeforces.com/contest/1735/submission/174443480 "Submission 174443480 by Akulyat")

[1735D - Meta-set](../problems/D._Meta-set.md "Codeforces Round 824 (Div. 2)")

 **Hint1**How many sets can fit in 5 cards?

 **Answer to Hint1**At most two.  
If there are two sets among 5 cards, there will be a central card.  
Consider each card as a central card.

 **Solution**For every two cards, there is always a single card that forms a set with them.  
[1] That means that two sets can share at most one card.

Let's prove that there are no more than 2 sets in a meta-set.  
Let's define 5 cards as c1,c2,c3,c4,c5. Let's guess that (c1,c2,c3) is a set.  
All other sets can have at most one card among (c1,c2,c3) (according to [1]), so they must include c4 and c5. So we have at most one other set, otherwise they would have two same cards, which is prohibited according to [1].

So, every meta-set looks like 2 sets with one common card. Let's call this card a central card.

Now there is just a simple combinatorics. For each card, we want to know the number of sets that include it. If this number is s, then we should add s(s−1)2 to the answer — it is the number of meta-sets with this card as a central card.

To get the number of sets for each card, we can iterate over all pairs of cards (i,j), generate the complement to the set, and add 1 to that card in a map/hashmap.

Complexity is O(kn2log(n)) or O(kn2).

 **Code**[174443540](https://codeforces.com/contest/1735/submission/174443540 "Submission 174443540 by Akulyat")

[1735E - House Planning](../problems/E._House_Planning.md "Codeforces Round 824 (Div. 2)")

 **Hint1**How many possible options are there for the distance between p1 and p2.

 **Answer to Hint1**We can limit it with 2⋅n options.  
Consider options d1[1]+d2[i], |d1[1]−d2[i]|. Solve each one in linear(almost) time.

 **Hint2**Consider the biggest distance among d1 and d2.  
Can we match it with something?

 **Hint3**Remove them one by one while they exceed the distance between p1 and p2. Then the problem is trivial.

 **Solution**Let's assume that considered point p1 was to the left of considered point p2.  
Let's assume that we know the distance l between considered points p1 and p2. Let's show how to solve this problem in linear time(almost linear).

As long as there is a value greater than l, let's get the largest among them(let's call it x). Let's assume that this value is from d1.  
It's easy to see that this point is to the right of the considered point p2 (because the largest distances is to the point p1). It means that we can match distance x from d1 to the distance x−l from d2. 

When there is no value greater than l, all other houses are located between considered points. We can match them by sorting.

That is the O(nlog(n)) solution.

Let's limit possible options of l with O(n) options.  
If we know that some house has distances x and y to considered options, then there are 2 options of l: x+y and |x−y|.  
Let's consider 2⋅n options d1[1]+d2[i], |d1[1]−d2[i]|.

Complexity is O(n2log(n)).

 **Code**[174443587](https://codeforces.com/contest/1735/submission/174443587 "Submission 174443587 by Akulyat")

[1735F - Pebbles and Beads](../problems/F._Pebbles_and_Beads.md "Codeforces Round 824 (Div. 2)")

 **Hint1**Draw currencies on 2D plane.  
Assume that you can throw out any amount of money at any moment.  
What will an area of possible points look like? 

 **Hint2**It will look like a convex polygon in the upper-right quarter.  
Keep its edges.  
How does the structure change when a new day comes?

 **Hint3**A new segment is added. A prefix of old segments is shifted by vector, the remaining suffix of old segments is shifted by opposite vector, 

 **Solution**Let's draw currencies on 2D plane. Having x pebbles and y beads is described as point (x,y).  
Let's assume that we can throw out any amount of money at any moment. In this case, an area of possible points can be described as a convex polygon in the upper-right quarter. Initially it is the rectangle [(0,0),(0,b),(a,b),(a,0)].  
At any moment, this polygon can be described as a list of segments starting at point (0,y0) and finishing at point (xk,0). In the rectangle described above, there are 2 segments.  
Let's keep those segments sorted by angle. 

When a new day comes, each point can be shifted by the vector c⋅(pi,−qi) ∀c∈[−1,1] if the new point has non-negative coordinates.  
If we forget about new points to be non-negative, how new segments look like?  
We just have to add new segment (2⋅pi,−2⋅qi) and shift a prefix of old segments by (−pi,qi) and remaining suffix of segments by (pi,−qi).  
Then the only thing left to do is to cut segments to keep our polygon non-negative.  
Sounds great, but sounds like O(n2).

Do we need to maintain segments explicitly?  
No!  
Let's just keep the set of their lengths and angles. Knowledge of extreme points (0,y0) and (xk,0) is enough.  
So we need to: 

* Insert a new segment to the set. (You need just length and angle).
* Shift extreme points (0,y0) and (xk,0) by (−pi,qi) and (pi,−qi) correspondingly.
* Delete or cut the last and first segments while they are out of the non-negative area.

Complexity O(nlog(n)). 

There is another simple O(n2log(n)) approach:  
We can keep the area as a polygon. At each step, create two copies shifted by corresponding vectors. Build a convex hull of them. Cut this convex hull to be in the non-negative area.  
It won't fit. Mentioned just for fun.

 **Code**[174443858](https://codeforces.com/contest/1735/submission/174443858 "Submission 174443858 by Akulyat")

