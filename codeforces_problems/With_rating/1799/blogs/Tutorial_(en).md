# Tutorial_(en)


### [1799A - Recent Actions](../problems/A._Recent_Actions.md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

Note, that posts will be removed in the order n,n−1,…,1.

The post n−k+1 will be removed at the first time, when there are at least k different numbers among p1,p2,…,pi.

So let's calculate the number of different numbers among p1,p2,…,pi for each i using boolean array of length m iterating i from 1 to m. Using them we can calculate the answer.

Time complexity: O(n+m).

 
### [1799B - Equalize by Divide](../problems/B._Equalize_by_Divide.md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

If all numbers are equal initially — we can do nothing.

Otherwise if some ai=1, answer do not exist: this ai can't became bigger during operations and all other elements can't be equal to 1 simultaniously, because after the last operation aj>1 (otherwise we can remove this operation).

If all ai≥2, the answer exists and we can simulate such algorithm: let's take i, such that ai is maximum possible and j, such that aj is smallest possible. Make operation with (i,j). Note, that after at most 30n operations all elements will be equal.

It is true, because after each operation ai decreases at least by 2 times (and rounded up) and all elements are bounded ax≥2 after each operation. Each number can't be decreased more than 30 times.

Time complexity: O(n2logC), where C=109.

 Tutorial is loading... 
### [1799D2 - Hot Start Up (hard version)](../problems/D2._Hot_Start_Up_(hard_version).md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

Consider maintaining the following 2-dimensional DP: dpi,j will be the minimum time needed to run all previous programs such that the last program run on CPU 1 was program i, and the last program run on CPU 2 was program j. Initially we have dp0,0=0 (here, 0 is a placeholder program) and dpi,j=INF for (i,j)≠(0,0). 

When we come to a program x, we can transition as follows. First, create a new DP array ndp, initialized to all INF. Then: 

* For all dpi,j with i≠x, set ndpx,j=min.
* For all dp_{x,j}, set ndp_{x,j} = \min(ndp_{x,j}, dp_{x,j} + hot_x).
* For all dp_{i,j} with j \neq x, set ndp_{i,x} = \min(ndp_{i,x}, dp_{i,j} + cold_x).
* For all dp_{i,x}, set ndp_{i,x} = \min(ndp_{i,x}, dp_{i,x} + hot_x).

After all updates, replace dp with ndp.

This works in O(nk^2). To optimize it, we can notice that after processing a program x, only entries in dp with the row or column equal to x will be non-INF. Consider instead the following 1-dimensional DP array: dp_i contains the minimum time to run previous programs if one CPU last ran program x, and the other last ran program i. 

Initially, dp_0 = 0 and all other dp_i = INF. Also, we add a dummy program with ID 0, and hot_0 = cold_0 = 0 (this will make implementation easier).

When we come to a program x, again, let's create a new DP array ndp, again initialized to all INF. Then, we can case on whether the previous program was equal to x.

* If the last program run was also x:
	+ For all i, set ndp_i = \min(ndp_i, dp_i + hot_x).
	+ For all i \neq x, set ndp_x = \min(ndp_x, dp_i + cold_x).
	+ Set ndp_x = \min(ndp_x, dp_x + hot_x).
* Otherwise, let y be the last program run.
	+ For all i, set ndp_i = \min(ndp_i, dp_i + cold_x).
	+ For all i \neq x, set ndp_y = \min(ndp_y, dp_i + cold_x).
	+ Set ndp_y = \min(ndp_y, dp_x + hot_x).

This gets us a O(nk) solution which gets accepted in the easy version.

To optimize it further, we can use a data structure to perform updates (since with each transition we either add some value to every dp element, or add some value to a single index). It is possible to do this in constant time per update, or using a segment tree or some other range update structure (though this is somewhat overkill). The overall complexity then becomes O(n + k) or O(n \log k + k) per test.

 
### [1799E - City Union](../problems/E._City_Union.md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

Let's note, that the resulting grid is correct if and only if filled cells form continious segment in each row and column (condition *) and there is one city.

So we can define a filling operation: given a grid, fill all cells between the most left and most right cells in each row and the most up and most down cells in each column. Doing this operation (n+m) times we get that condition * is satisfied and we filled cells that definitely should be filled. If now there is one city, we solved the problem.

But if there are still two cities, their projections to horisontal and vertical axes do not intersect. So we need to connect them with some path.

Let's consider the case when one city is upper left than the other city (otherwise we can apply rotation and get this case). Let's define the lowest row of the first city as i_1, the right column of the first city as j_1, the upper row of the second city as i_2 and the left column of the second city as j_2. We can fill cells on any Manhattan shortest path between cells (i_1, j_1), (i_2, j_2). After that again using filling operation we will fill cells that should be filled.

It is easy to see, that by this solution we will get the smallest possible number of filled cells.

Time complexity: O(nm (n + m)).

 
### [1799F - Halve or Subtract](../problems/F._Halve_or_Subtract.md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

For convenience, let half(x) denote \lceil \frac{x}{2} \rceil, and sub(x) denote \max(x - b, 0).

First, notice that if we apply both operations to some element, it will be optimal to apply halving first, then subtraction. We can prove this with 2 cases: 

1. a_i \le 2b. In this case, half(a_i) \le b, and so sub(half(a_i)) = 0. Since applying either function to a nonnegative integer results in a nonnegative integer, 0 = sub(half(a_i)) \le half(sub(a_i)).
2. Otherwise, a_i > 2b. Then sub(half(a_i)) = a_i - \lfloor \frac{a_i}{2} \rfloor - b, and half(sub(a_i)) = a_i - b - \lfloor \frac{a_i - b}{2} \rfloor. Since \lfloor \frac{a_i - b}{2} \rfloor \le \lfloor \frac{a_i}{2} \rfloor, sub(half(a_i)) \le half(sub(a_i)).

Next, suppose there are exactly p elements to which we apply both operations. Then, it will be optimal to apply both operations to the p greatest elements in the array. This should be somewhat intuitive, but here's a proof: 

* Suppose there are some a_i, a_j such that a_i < a_j. Suppose we apply both operations to a_i, and only one operation to a_j. Then applying both operations to a_j and a single operation to a_i instead won't increase the resulting sum. We can prove this with two cases:
	1. We apply half to a_j. Note that since it's optimal to apply half first when applying both operations, this case is essentially: halve both elements, then choose one to apply sub to. And it's better to subtract b from the greater element, since x - sub(x) \le y - sub(y) for x \le y.
	2. We apply sub to a_j. We can analyze this with (surprise!) a few cases:
		+ a_i, a_j \le 2b. Then whichever element we apply both operations to will be 0, and the result will depend only on the other element. sub(x) \le sub(y) for x \le y, so it's better to apply both operations to the greater element.
		+ a_j > 2b. If we apply both operations to the greater element, we subtract \min(a_i, b) + \lfloor \frac{a_j}{2} \rfloor + b from the sum. But applying both operations to the lesser element subtracts \lfloor \frac{a_i}{2} \rfloor + \min(half(a_i), b) + b \le \min(a_i, b) + \lfloor \frac{a_i}{2} \rfloor + b from the sum. So it's optimal to apply both operations to the greater element. And this covers all cases where a_i < a_j.

Let's fix p, the number of elements we apply both operations to. After taking them out, we will be left with the n-x smallest elements in the array. Suppose we have v_1 operations of type 1 left, and v_2 operations of type 2 left. We'll assume v_1 + v_2 \le n - x (otherwise we can apply both operations to more elements).

Notice that it's optimal to apply our v_1 + v_2 operations to the v_1 + v_2 greatest remaining elements: subtracting from a greater element can't decrease the amount we subtract, and halving a greater element can't decrease the amount we take away. So we're left with v_1 + v_2 elements, and we want to choose v_1 of them to apply the halving to. 

Let's consider a few cases and try to analyze them. Let a_i \le a_j, and suppose we want to apply half to one of them and sub to the other. 

* a_i, a_j \le b. Then it will be optimal to apply sub to the greater element.
* b \le a_i, a_j. Then it will be optimal to apply sub to the smaller element.

Using this information, we can form the final lemma we need for our solution: 

* Let a_i \le a_j \le a_k. Suppose we apply sub to a_i and a_k, and half to a_j. Then it will not increase the answer to apply half to one of a_i or a_k instead.

There are 4 cases we should consider to prove this lemma: 

* a_k \le b. Then we should apply half to a_i and sub to the others.
* b \le a_i. Then we should apply half to a_k and sub to the others.
* a_i, a_j \le b \le a_k. Then we should apply half to a_i and sub to the others.
* a_i \le b \le a_j, a_k. Then we should apply half to a_k and sub to the others.

You can verify that doing this produces the optimal answer. And using this lemma, we find that the optimal answer has all sub operations applied to some of the middle elements, with all half operations applied to the endpoints.

To summarize, the optimal answer will have a form like this (assuming a is sorted in non-increasing order, a_1 \ge a_2 \ge a_3 \ge \ldots \ge a_n): 

* First come some elements to which we apply both operations.
* Second come some elements to which we apply only half.
* Third come some elements to which we apply only sub.
* Fourth come some elements to which we apply only half.
* Finally come some elements to which we apply no operations.

Note that some of these segments may be empty.

It's easy to verify that it's optimal to use all given operations. So if we loop through all possible sizes for the first two segments, we can uniquely determine the sizes of the last three. Finally, using prefix sums to quickly find the sums of elements in a segment, we get an O(n^2) solution.

There is an interesting fact: if we will fix the size of the first group p and calculate the answer f(p) for it, the function f is convex. So the ternary or binary search can be used here to find the minimum in O(n \log{n}) time, but it was not necessary.

 
### [1799G - Count Voting](../problems/G._Count_Voting.md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

Let's solve the problem using inclusion-conclusion principle. If we do not consider teams, there are \frac{n!}{\prod\limits_{i=1}^{n} c_i!} ways to make votings.

But now consider such sets of bad votings: person i made a vote for the person from the same team t_i. We want to calculate the size of the union of such sets of votings.

So the answer to the problem is \sum\limits_{k=0}^{n} (-1)^k f_k, where f_k is the number of ways to make votings, where we firstly fix some subset of k people who will vote for the same team (for others the vote can be any) and calculate the number of votings for it, and we sum these numbers for all subsets of k people.

Let's define b_1, b_2, \ldots, b_n, where 0 \leq b_i \leq c_i is the number of people from the same team who made a vote for i-th person (so, \sum\limits_{i=1}^{n} b_i = k). So, f_k = \sum\limits_{0 \leq b_i \leq c_i} cnt(b_1, b_2, \ldots, b_n), where cnt(b_1, b_2, \ldots, b_n) is the number of votings, where for each i we firstly fix b_i people from team t_i that will vote for i and calculate the number of votings, and we sum these numbers for all ways to fix.

How cnt is calculated? There are \frac{(\sum\limits_{i=1}^{n} c_i - b_i)!}{\prod\limits_{i=1}^{n} (c_i - b_i)!} = \frac{(n - k)!}{\prod\limits_{i=1}^{n} (c_i - b_i)!} ways to make votes for people who were not selected into subset. This should be multiplied for the number of ways to vote for people that were fixed. This should be found for each team separately.

Let's consider some team 1, 2, \ldots, m of m people (WLOG they are first m people). There are \frac{m!}{(\prod\limits_{i=1}^{m} b_i!) (m - \sum\limits_{i=1}^{m} b_i)!} ways (*) to fix people in this team. These counts should be multiplied for all teams.

Now to sum all cnt for all b we of course can't iterate over all possible b, we will do it using dynamic programming. Let's iterate over all possible teams and calculate dp_{i,k} — the sum of current counts for all prefixes of arrays b, where we considered first i teams and the sum of elements of b on this prefix is k.

When we add a new team to our dp, we can write dp_{i+1, k+s} += dp_{i,k} t_{i+1,s}, where t_{i+1,s} is the sum of (*) multiplied by \frac{1}{\prod\limits_{i=1}^{m} (c_i - b_i)!} for all ways to choose b inside the team i+1 with sum of b_j in this team equal to s.

To calculate values t_{i,s} for each team i we can also use a prefix dynamic programming inside the team.

At the end we found f_k = dp_{t,k} (n-k)!, where t is the number of teams.

So, the time complexity of this solution is O(n^2). Where are many different ways of how the solution can be implemented (and even optimized with power series), but the inclusion-conclusion is necessary to solve the problem.

 
### [1799H - Tree Cutting](../problems/H._Tree_Cutting.md "Codeforces Round 854 by cybercats (Div. 1 + Div. 2)")

We should calculate the number of ways to choose some k edges of our tree (and directions of them) corresponding to operations, such that the operations that will be done with them will result in the given sequence of written numbers.

To calculate these ways let's consider a subtree dp_{v,mask} for our main tree. Here v corresponds to subtree of our tree with root in vertex v, also we include an edge from v to the parent into this subtree. mask is a submask of \{1, 2, \ldots, k\}, meaning that we have chosen in this subtree edges corresponding to operations from mask.

First of all, consider the case, when the edge from v to parent is not chosen to any of the operations. So let's iterate over children of v and calculate the same dynamic programming for the considered prefix of subtrees. To add the new subtree, we should iterate over mask_1 mask of operations that have been done on prefix and mask_2 mask of operations that have been done in new subtree. For these masks the condition mask_1 \cap mask_2 = \emptyset should hold.

In the case, when the edge from v to parent is chosen let's iterate of the operation i corresponding to it. After that, sz_{v} = s_i or sz_{v} = n - s_i should hold. If sz_{v} = s_i we can choose this edge for the operation i and orient it from parent to v. So, the operations in mask \setminus \{i\} should be with indices > i. Iterate such masks and update the dp value corresponding to it (using dp values already calculated for subtree of v for the case when edge to parent is not chosen). In the case sz_{v} = n - s_i similarly sz_{v} = n - s_i should hold and operations in mask \setminus \{i\} should be with indices \leq i.

We can see, that the number of ways calculated with such dp is correct, because if we assigned operation i to some edge with some direction, we ensured the written size after the operation is correct and that the operations in the subtree have been done before or after the operation i (in relation to direction of edge).

Time complexity: O(n (3^k + 2^k k)), but it can be improved to O(n 2^k k) with sum over subsets calculation.

