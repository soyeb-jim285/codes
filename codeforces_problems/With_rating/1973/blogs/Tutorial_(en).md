# Tutorial_(en)

We hope you enjoyed the problems! Thank you for your participation! We are really sorry that A and D turned out to be harder than usual.

[Problem A](../problems/A._Chess_For_Three.md): idea by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo") and [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343"), prepared by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo")

 **Hint 1:**If someone would claim that the number of draws that happened between the three players are d1,2, d1,3 and d2,3, can you check in O(1) whether this can be true?

 **Hint 2:**The constraints are very small. The number of draws between any two players is at most 30.

 **Hint 3:**Hint 3: Try all the possibilities for d1,2, d1,3 and d2,3 and find the one with the biggest sum out of all possibilities that could've been the result of game that ended with scores p1, p2 and p3. 

 **Solution:**After each round, sum of players' scores increases by 2, so if the sum p1+p2+p3 is odd, answer is −1. 

Now, as the hints suggest, you can try all possible combinations of d1,2, d1,3 and d2,3 with three for-loops and check for each combination whether it could result in scores p1, p2 and p3. Specifically, it must hold that p1−d1,2−d1,3≡0mod2, d1,2+d1,3≤p1 and the same two conditions for p2 and p3 analogously. Now you can find the biggest value of d1,2 + d1,3 + d2,3 over all valid choices and print it as the answer.

The time complexity is O(t⋅max(p)3).

Implementation in Python: [261998440](https://codeforces.com/contest/1973/submission/261998440 "Submission 261998440 by myvaluska")

 **Bonus:**There exists an O(1) solution with simpler implementation. Claim: The answer is min((p1+p2+p3)/2,p1+p2). Let's prove this: if p1+p2≤p3, then it's possible that players 1 and 2 played p1 and p2 draws with player 3, after which there can't happen any additional draws in the game. if p1+p2>p3, that means p1>p3−p2, so player 1 can first play p3−p2 draws with player 3. Note, that if sum p1+p2+p3 is even, then p1−(p3−p2) will also be even, so player 1 can play (p1−(p3−p2))/2 draws with each of players 2 and 3, thus adding up his score to exactly p1. Finally, players 2 and 3 can play p2−(p1−(p2−p3))/2 draws anong them, after which their scores become p2 and p3 respectively. Thus, it is possible that all rounds played ended with draws, making answer equal to (p1+p2+p3)/2.

Implementation in C++: [261998652](https://codeforces.com/contest/1973/submission/261998652 "Submission 261998652 by myvaluska")

[Problem B](../problems/B._Cat,_Fox_and_the_Lonely_Array.md): idea by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo"), prepared by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo")

 **Definition:**We will say that the array is k-lonely if ai|ai+1|…|ai+k−1=aj|aj+1|…|aj+k−1 is true for any two positive integers 1≤i,j≤n−k+1. Let A be the maximum value an element in array a can have.

 **Hint 1:**how to check if the array is k-lonely in O(nlogA)?

 **Hint 2:**if the array is k-lonely, the array is also k+1-lonely

 **Hint 3:**binary search the answer :)

 **Solution:**If the array is k-lonely, then since ai|…|ai+k=(ai|…|ai+k−1)|(ai+1|…|ai+k)=(aj|…|aj+k−1)|(aj+1|…|aj+k)=aj|…|aj+k, the array is also k+1-lonely.

You can check whether an array is k-lonely in O(nlogA) by calculating the OR of every segment of length k. You can do this by iterating i from 1 to n−k+1 and mantaining an array t of size logn where t[j] will be equal to the number of elements from ai,...,ai+k−1 that have the bit 2j set. For i=1 we can calculate this array in O(klogA) and then when moving i to the right, we can update the array in O(logA) complexity and we can also calculate the OR of all elements in the segment, using the array t, in O(logA). 

Once you have a checking function that runs in O(nlogA), you can binary search the answer in O(nlogAlogn) time, which is fast enough to pass.

Implementation in C++: [261999140](https://codeforces.com/contest/1973/submission/261999140 "Submission 261999140 by myvaluska")

 **Bonus 1:**There also exists a nice O(nlogA) solution, you can try to find it and get AC with it too :)

 **Hint:**Try calculating the lower bound on the total loneliness for each bit separately. Then the maximum of these is the answer. 

 **Bonus 2:**Originally the problem had the same constraints, but you could also insert up to one arbitrary number in the array and find the minimum loneliness you can achieve in this way. It was proposed as the problem C. However, since the original B turned out to be too hard, this problem was made easier and shifted to this position.

[Problem C](../problems/C._Cat,_Fox_and_Double_Maximum.md): idea by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo"), prepared by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo")

 **Hint 1:**n is even. What is the obvious upper bound on the number of the local maximums?

 **Hint 2:**Right, it is n2−1. We can actually achieve this value for any permutation.

 **Hint 3:**Consider p1=n. Can you find q such that all other odd positions will be local maximums? 

 **Solution:**We can easily prove that the sequence can have at most n2−1 local maximums, because the corner elements can't be the local maximums and no two consecutive elements can be local maximums. Let's see how we can achieve this upper bound.

Let's consider the case when n is at odd position in the original array first. We will construct a permutation q such that the resulting array a will have local maximums at all the odd positions except the first one. We can do this by placing the numbers n2+1,n2+2,…n at the odd indexes in q, giving the bigger numbers to the indexes with smaller pi, and placing the numbers 1,2,…,n2 at the even indexes in p, giving the smaller numbers to the indexes with bigger pi. Then since n belongs to an odd index, the ai for each odd i will be at least n+1 while the ai for each even i will be at most n. So every element of a at odd position, except for the corner, will be a local maximum. This means we will have n2−1 local maximums, which is optimal, as we noitced above.

We can get the solution for the case when n is at even position analogously. For example, by reversing the permutation p, calculating the right permutation q, reversing them again and printing this q as the answer.

Time complexity: O(nlogn) because of sorting. Actually, since you are sorting a permutation, you can do it in just O(n) but it's not necessary.

Implementation in C++: [261999352](https://codeforces.com/contest/1973/submission/261999352 "Submission 261999352 by myvaluska")

[Problem D](../problems/D._Cat,_Fox_and_Maximum_Array_Split.md): idea by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo") and [TimDee](https://codeforces.com/profile/TimDee "Candidate Master TimDee"), prepared by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo") and [TimDee](https://codeforces.com/profile/TimDee "Candidate Master TimDee")

 **Hint 1:**Let m be value we want to find. What values can m take?

 **Hint 2:**Look at the maximum value in array a.

 **Hint 3:**Can you find the maximum value in array?

 **Hint 4:**Think about the segment containing the maximum value.

 **Hint 5:**Can you finish the problem in n queries?

 **Solution:**Let's denote maximum value in array a as mx. Since the element with maximum value will belong to some segment, then if m exists, m will be divisible by mx. Obviously, m can't be greater than n⋅mx, so now the candidates for value of m are mx,2⋅mx,3⋅mx,…,n⋅mx.

To find the value of mx we can query ? 1 n⋅i for each 1≤i≤n and mx will be equal to such i, querying which will give n as the answer.

We can check each of n possible values in k queries, but that wouldn't fit in query limit.

Actually, since the length of each segment in partition will be greater than or equal to mmx, and there are exactly k segments, we can get a simple inequality k⋅mmx≤n (since sum of lengths of segments is exactly n), which means m can not be greater than mx⋅⌊n/k⌋, so it is enough to check first ⌊n/k⌋ candidates for m in k queries each. Total number of queries used would be n+k⋅⌊n/k⌋ which doesn't exceed 2n.

Implementation in C++: [261999488](https://codeforces.com/contest/1973/submission/261999488 "Submission 261999488 by myvaluska")

[Problem E](../problems/E._Cat,_Fox_and_Swaps_.md): idea by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo"), prepared by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo")

 **Hint 1:**Forget about graphs and data structures, there exists a simple O(n) solution.

 **Hint 2:**Find the number of pairs with l=r for which you can sort the permutation.

 **Hint 3:**Okay now that you have the special case handled, let's proceed to the general case. Find the minimum and maximum number that need to be swapped. Write down the inequalities that l and r have to satisfy so that we can swap these two elements with some other elements. This is the obvious necessary condition, right?

 **Hint 4:**Right, so if l≠r and additionally, l and r satisfy the inequalities mentioned above, is it enough?

 **Hint 5:**Yes, it is enough. But you can try to find the proof too :)

 **Solution:**Let's consider the pairs l,r that have l=r first. Then you can swap each x with at most one other element, l−x. So if i≠pi for some i, then we need to be able to swap the element i with the element pi, so it must hold that l=i+pi. This is obviously also a sufficient condition, so it's enough to just find all i+pi for i≠pi, if there exist more then one different value, there's no good pair with l=r, if there's exactly one different value, there's exactly one good pair with l=r and otherwise there are 2n such pairs.

Now let's count the pairs with l≠r. If the array is sorted already, all pairs of l,r are good. From now, consider only the case when the array isn't sorted yet.

Let L be the smallest value such that pL≠L and R the largest such value respectively. We obviously need to be able to swap L and R with some other values. 

Note that L≠n and R≠1, otherwise the array would be sorted already. Now we can get the inequalities l≤L+n and R+1≤r, those are the necessary conditions for being able to swap the numbers L,R with at least one other element. 

We can actually prove that these are the sufficient conditions too. If l,r satisfy these conditions, then for any number X in the range [L,R−1], we can find an x in the range [l,r] such that 1≤x−X≤n and then we can swap the numbers X and X+1, while not affecting any other element, by swapping X and x−X first and then swapping X+1 and x−X. Thanks to this, we can sort the whole range of values between L and R — while the array isn't sorted, we will always find the smallest index i that doesn't have the right value and keep swapping the value pi with the value pi−1, so eventually we will get pi=i and we can continue sorting on the right.

So it's enough to just count the number of pairs l,r such that l≠r, l≤L+n and R+1≤r, add it to the answer and print it. 

All of this can be done in time and memory complexity O(n).

Implementation in C++: [261999566](https://codeforces.com/contest/1973/submission/261999566 "Submission 261999566 by myvaluska") (I used set and therefore the time complexity is O(nlogn) because it was more comfortable)

[Problem F](../problems/F._Maximum_GCD_Sum_Queries.md): idea by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo"), prepared by [prvocislo](https://codeforces.com/profile/prvocislo "Grandmaster prvocislo")

 **Hint 1:**What are the possible pairs of gcd's of the two arrays we can have after some swaps?

 **Hint 2:**For every pair (X,Y) such that X divides a1 and Y divides b1, let's calculate the total number of indices i such that we can have X|ai and Y|bi (either with or without the swap), and the minimum cost of swaps to achieve this. This is all we need to solve the problem, right?

 **Hint 3:**Write for each i the conditions that the pair (X,Y) has to satisfy in order to add i to the result/make swap on the position i. Use something like SOS-DP to add up all the values efficiently.

 **Solution:**Let k be the maximum value of ai, bi on input (108). Let D(k) be the maximum number of divisors a number in range [1,…,k] can have and P(k) the maximum number of prime divisors such number can have.

Let's think about how to solve one query (with M coins) for now. Assume that in the optimal solution, we never swap a1 and b1. In the end, we will just run the same solution on input where a1 and b1 is swapped and M is decreased by c1, and then we will take the maximum of the two values these two runs will find.

So now, in the optimal solution, the gcd of a is always a divisor of a1, and the gcd of b is a divisor of b1. Let's start by factorizing the two numbers in O(√k).

Now we will precalculate something in order to be efficiently able to determine for every X, a divisor of a, and Y, a divisor of b1, whether we can have gcd(a1,…,an)=X and gcd(b1,...,bn)=Y simultaneously (and also the minimum cost of making it so). Then we can obviously answer the query by finding the best pair with sum at most M. 

Let's create new two dimensional arrays P and S of size D(a1)×D(b1). We will use P to be able to tell the number of indexes i such that we have either X|ai and Y|bi or X|bi and Y|ai. If this count won't be n, then obviously we can't have X and Y as gcd's of a and b. Also, we will use S to tell us the sum of costs of all swaps we need to perform to have X|gcd(a1,…,an) and Y|gcd(b1,...,bn).

Now how to make two such arrays efficiently? It is obvious that if the pair of gcd s (X,Y) is consistent with some indexes in the original array, then for every pair (x,y) such that x|X and y|Y, this pair of gcds is also consistent with those indexes (and maybe even more, also maybe some swaps just became unnecessary, but the point is, it doesn't get worse). So if we want to add some value to a pair, we also want to get it added to all its divisors. That's why, in order to calculate the arrays efficiently, we will first add some values on some positions and then do something like 2D prefix sums — for every cell (x,y) we will sum the values for all pairs (X,Y) such that x|X and y|Y and update its current value with it. Assuming this is going to happen in the end, let's look at every i and consider what pairs are "good" for this index — with or without the swap:

a) If X divides ai and Y divides bi: For this type of pairs, we don't need to make any swaps on this index. Let's add 1 to P[gcd(a1,ai)][gcd(b1,bi)] to indicate that for all (X,Y) such that X|ai and Y|bi, we don't have to perform any swaps at the position i, the index is good as it is.

b) X divides bi and Y divides ai: In this case we will add 1 to P[gcd(a1,bi)][gcd(b1,ai])] and ci to S[gcd(a1,bi)][gcd(b1,ai)] to indicate that if we pick X, Y such that X|bi and Y|ai, we can make index i good if we swap ai and bi.

c) X and Y both divide both ai and bi: To avoid counting both of the previous cases and therefore overcounting, we will add −1 to P[gcd(a1,ai,bi)][gcd(b1,ai,bi)] and −ci to S[gcd(a1,ai,bi)][gcd(b1,ai,bi)] (we have to undo paying for the swap since in this case we actually don't have to pay for it, but it falls under the case b) too).

This step can be done in O(nlogk).

Now let's fix the arrays P and S so they store the actual values, not just the values we need to add. 

We will go through all primes p dividing a1 and update P[X][Y] with P[p⋅X][Y] and S[X][Y] with S[p⋅X][Y], similarly for all primes dividing b1. If we make those updates in the right order, we achieve that P[x][y] is the sum of all original values P[X][Y] for all the pairs (X,Y) such that x|X and y|Y like we wanted (and we can do the same for S).

By careful precalculation of divisors and their order while factorizing, we can do this step in O(D(k)2P(k)). Some efficient implementations with extra log might pass also, but you will have to be more careful.

For multiple queries, after precalculating the possible sums of gcd s and their costs, you can sort them and use binary search to answer the queries.

Time complexity: O(nlogk+√k+D(k)2P(k)+D(k)2logD(k)+qlogD(k)) Memory complexity: O(n+D(k)2+P(k))

Implementation in C++: [261999743](https://codeforces.com/contest/1973/submission/261999743 "Submission 261999743 by myvaluska")

Fun fact: While making the original proposal, I invented a version of this problem with lower constraints and thought it could be nice Div2C. Few days later, while I was on a walk, I realized this solution exists, so we decided to try to propose it as the hardest problem.

