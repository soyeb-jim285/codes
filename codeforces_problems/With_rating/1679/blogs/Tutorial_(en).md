# Tutorial_(en)

[1679A - AvtoBus](../problems/A._AvtoBus.md "Codeforces Round 791 (Div. 2)")

Author: [iakovlev.zakhar](https://codeforces.com/profile/iakovlev.zakhar "Grandmaster iakovlev.zakhar")

Preparation: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

Editorial: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

 **Editorial**
### [1679A - AvtoBus](../problems/A._AvtoBus.md "Codeforces Round 791 (Div. 2)")

Let the number of buses with two axles is x and the number of buses with three axles is y. Then the equality 4x+6y=n must be true. If n is odd, there is no answer, because the left part of the equality is always even. Now we can divide each part of the equality by two: 2x+3y=n2.

Let's maximize the number of buses. Then we should make x as large as possible. So, we will get 2+…+2+2=n2 if n2 is even, and 2+…+2+3=n2 otherwise. In both cases the number of buses is ⌊n2⌋.

Now let's minimize the number of buses. So, we should make y as large is possible. We will get 3+…+3+3+3=n2 if n2 is divisible by 3, 3+…+3+3+2=n2 if n≡2(mod3), and 3+…+3+2+2=n2 if n≡1(mod3). In all cases the number of buses is ⌈n3⌉.

Also don't forget the case n=2 — each bus has at least four wheels, so in this case there is no answer.

Time complexity: O(1).

[1679B - Stone Age Problem](../problems/B._Stone_Age_Problem.md "Codeforces Round 791 (Div. 2)")

Author: [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

Preparation: [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

Editorial: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous") and [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

 **Editorial**
### [1679B - Stone Age Problem](../problems/B._Stone_Age_Problem.md "Codeforces Round 791 (Div. 2)")

As we want to perform queries fast, we will store some variables: current sum of all elements in the array sum, index of the last query of the second type lastSecondQuery and its value lastSecondQueryValue. For each element of the array we will also store index of the last query of the first type that changed this element lastFirstQuery[i] and its value lastFirstQueryValue[i].

Now let's answer the queries. If we are going to perform a query of the first type, we have to know, what the number ai equals now. If lastSecondQuery>lastFirstQuery[i], then ai=lastSecondQueryValue now, and ai=lastFirstQueryValue[i] otherwise. Now let's subtract ai from the sum, change lastFirstQuery[i] and lastFirstQueryValue[i], and add the new value ai to the sum.

If we are going to perform a query of the second type, we have to update values lastSecondQuery and lastSecondQueryValue. The new sum of all elements of the array is n⋅lastSecondQueryValue.

Time complexity: O(n+q).

[1679C - Rooks Defenders](../problems/C._Rooks_Defenders.md "Codeforces Round 791 (Div. 2)")

Author: [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

Preparation: [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

Editorial: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous") and [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

 **Editorial**
### [1679C - Rooks Defenders](../problems/C._Rooks_Defenders.md "Codeforces Round 791 (Div. 2)")

Consider some subrectangle. Note that each its cell is attacked by some rook if and only if there is at least one rook in each row x (x1≤x≤x2) or in each column y (y1≤y≤y2).

Now we will solve the problem using this criterium. Let's create a set freeRows where we will store indices of rows in which there are no rooks. Similarly, we will store indices of columns in which there are no rooks in a set freeCols. If we have to answer the query of the third type, we have to check if there is at least one x in the freeRows set such that x1≤x≤x2 or there is at least one y in the freeCols set such that y1≤y≤y2. If we will store these two sets sorted, we can perform this type of query in O(logn) using binary search.

Now we're going to answer queries of the first and the second types. Let's store for each row and column, how many rooks are there in this row or column. When we add a new rook we should increment this counters for the corresponding row and column and remove the row from freeRows set and the column from freeColumns set. When we remove a rook we should decrement counters for its row and column and if there is no more rooks in the row or in the column, we should add their indices to freeRows or freeCols.

Time complexity: O(qlogn).

[1679D - Toss a Coin to Your Graph...](../problems/D._Toss_a_Coin_to_Your_Graph....md "Codeforces Round 791 (Div. 2)")

Author: [Kon567889](https://codeforces.com/profile/Kon567889 "Master Kon567889")

Preparation: [Masha237](https://codeforces.com/profile/Masha237 "Expert Masha237")

Editorial: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

 **Editorial**
### [1679D - Toss a Coin to Your Graph...](../problems/D._Toss_a_Coin_to_Your_Graph....md "Codeforces Round 791 (Div. 2)")

Note that the function of existence of the answer relatively to the minimum value of the maximum in the path is monotonous. If we were able to construct the path with maximum, not greater than x, we are able to construct the path with maximum, not greater than x+1. This leads to the idea of binary search the answer.

Let binary search to fix some integer x. We have to check, if there is a path in the graph, that consists of k−1 edges and the maximum on this path is not greater than x. In the beginning let's leave in consideration only vertices which values are not greater than x. Now we need to check if the needed path exist in the resulting graph.

If there is a cycle in the graph, there is a path of every length in it, so there is a path of length k−1. Otherwise we have a directed acyclic graph. Let's find a longest path in it and compare its length with k−1. Let's sort the graph topologically and calculate dp[v] — the length of the longest path in the graph that begins in vertex v, it's a well-known classical problem.

Time complexity: O((n+m)logMAX).

[1679E - Typical Party in Dorm](../problems/E._Typical_Party_in_Dorm.md "Codeforces Round 791 (Div. 2)")

Author: [andr1y](https://codeforces.com/profile/andr1y "Master andr1y") and [welleyth](https://codeforces.com/profile/welleyth "Candidate Master welleyth")

Preparation: [andr1y](https://codeforces.com/profile/andr1y "Master andr1y") and [welleyth](https://codeforces.com/profile/welleyth "Candidate Master welleyth")

Editorial: [andr1y](https://codeforces.com/profile/andr1y "Master andr1y") and [welleyth](https://codeforces.com/profile/welleyth "Candidate Master welleyth")

 **Editorial**
### [1679E - Typical Party in Dorm](../problems/E._Typical_Party_in_Dorm.md "Codeforces Round 791 (Div. 2)")

We are given a string s, we need to count the number of palindromes in all possible versions of it if the characters "?" can be replaced by some letters of the English alphabet, which are set by queries. 

Let us solve the problem initially for a 1 query.

First, we can see that instead of counting the number of palindromes in each possible version of string s, we can count the number of strings in which a substring [l;r] would be a palindrome.

Consider the substring [l;r]. Suppose the set of allowed characters in this query is Q. What would be the effect of the substring on the answer? Divide the characters of the substring into pairs: first with last, second with penultimate, and so on. If the length of the substring is odd, pair the central character with itself. Now let's consider each pair separately: 

* If two characters of the pair are equal and they are not question marks, then this pair does not affect the answer.
* If two characters of the pair are equal and they are question marks, then this pair multiplies the answer by |Q|, where |Q|  — the number of possible characters to replace in this query. (Let's call the number of such pairs f).
* If two characters of the pair are not equal and there is no question mark among them, then this substring will never be a palindrome.
* If two characters of a pair are not equal and there is a question mark among them, you must check if the letter that is not a question mark belongs to the set Q, if not, then in this query this substring will never be a palindrome.

 Those pairs that cause this substring not to be a palindrome will be called blocking. Thus, we got the number of possible ways to replace question marks in substring [l;r] with valid characters such that substring [l;r]  — a palindrome  — is |Q|f, or 0 if we have a blocking pair. To get the total number of lines in which [l;r] is a palindrome, just multiply the previous value by |Q|d, where d  — is the number of question marks that not lie within [l;r].Thus, to get the answer for the substring [l;r] it is enough: 

* Check for blocking pairs  — if they exist, the answer is 0 by definition.
* Otherwise, the answer is |Q|d+f, where d and f are defined above.

Let's assign to each possible set of letters a binary mask of size α, where α  — the size of the alphabet in the problem. In the future, we will assume that mask and set are the same.

Consider possible blocking pairs of some substring [l;r], they are of two kinds: 

1. If two characters of the pair are not equal and there is no question mark among them, then this substring will never be a palindrome and we do not consider it.
2. If two characters of the pair are not equal and there is a question mark between them, a character that is not a question mark must be in the query for us to consider this substring.

 Thus, from the characters in pairs of the second type, we can create a set of "necessary" characters, let's call it P.Next, let us note the following fact: d+f does not depend on the query Q, because d depends only on l and r, and f  — on the number of pairs where both characters are question marks.

It follows that every substring of the form [l;r]: 

* Or is simply ignored if it has a blocking pair of the first type. (These substrings will not be mentioned further in the tutorial  — when we say substrings, we automatically mean the one described below).
* Either is characterized by a pair of numbers (P; d+f).

Consider an arbitrary query Q, how to calculate the answer for it? We need to go through all substrings, check whether P⊆Q and if so, add |Q|d+f to the answer.

The values of P and d+f for the substring [l;r] can be found quickly by knowing the same values for the substring [l+1;r−1]. Thus, by iterating over the parity of the palindrome length, then its center, and then its length itself, we can quickly find these values for all the substrings.

Thus, our solution has asymptotics so far O(n2 + q⋅n2), which is obviously too slow. 

But first, let's figure out how to solve the problem if we have |Q|  — fixed? Let's create an array of size 2α (let's call it R). For each substring, let's add to RP value |Q|d+f. What does this give us? We will then have in Ri the sum of answers from all the substrings P of which is equal to i. To find the answer in this case we have to sum all Ri where i⊆Q.

Actually, we have reached the asymptotics O(n2 + q⋅2α) or O(n2 + 3α).

But! The problem of finding the sum of subset values is a well-known one and solves our subproblem for O(α ⋅ 2α). In more detail: <https://codeforces.com/blog/entry/45223>

Well, here we have reached the asymptotics of O(n2 + α⋅2α), which is enough.

Let us return to the original problem. First, note that we don't have many different |Q|  — just α. So we create α different arrays of size 2α. When processing the current substring, we add id+f to each of the α arrays at position P, where i  — the index of the current array. Thus, it is as if we α times solved the problem for a fixed |Q|. We need to take the sum over subsets of Q from the |Q|th array to get the answer.

The final asymptotic of the solution  — O(α⋅n2 + α2⋅2α).

Applied optimizations in the author's solution: 

* Power optimization: we will often need different values of numbers from 1 to α in powers from 0 to n, so to remove log from the asymptotic, a precalculation of these values is used. This optimization is necessary to guarantee a full score on the problem.
* Addition optimization: we do not need to add a subset (P; d+f) to arrays whose index is less than |P|. This is since they will not affect the answer in any way. (Since the sets from which the answer will be taken in this array have fewer elements than P, they cannot, by definition, be P supersets.) This optimization is unlikely to have much effect on runtime. It is written here for a clearer understanding of the author's solution.
* Modulo optimization: The take modulo operation is slower than other operations, so it is worth avoiding. Here we often use the sum modulo of two numbers that do not exceed 998244353, so we will replace it by using (a+b >= M ? a+b-M : a+b) instead of (a+b)%M
[1679F - Formalism for Formalism](../problems/F._Formalism_for_Formalism.md "Codeforces Round 791 (Div. 2)")

Author: [iura](https://codeforces.com/profile/iura "Master iura")

Preparation: [iura](https://codeforces.com/profile/iura "Master iura")

Editorial: [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

 **Editorial**
### [1679F - Formalism for Formalism](../problems/F._Formalism_for_Formalism.md "Codeforces Round 791 (Div. 2)")

If you carefully read the problem statement, it becomes clear that we can do some transformations some numbers into others and we have to calculate the number of equivalence classes of all numbers consisting of n digits. Let's say that the representative of some equivalence class is the lexicographically minimal number in this class. Now the problem is to calculate the number of distinct integers that are representatives of some equivalence classes.

For convenience let's build an undirected graph which vertices will be digits and an edge will connect some digits u and v if and only if we are given a pair of digits (u,v) or a pair of digits (v,u).

It's easy to see that the number is a representative of some class if and only if it doesn't have a substring of kind [x,d1,d2,…,ds,y], where x>y, and there are edges (y,ds),(y,ds−1),…,(y,d1),(y,x) in the graph.

Now, knowing the criterium, let's calculate dp[suff][mask] — the number of equivalence classes if we have added suff digits from right to left in our number and now we can move to front only digits from the mask. Let's go over the next digit c that will be added to the left. If there is a digit i in the mask such that c>i and there is an edge (c,i) in the graph, we cannot add digit c, because it will break our criterium. Otherwise we can add digit c, it remains to calculate the new mask. Firstly, there will be a digit c in the new mask. Secondly, all digits i>c such that digit i was in the old mask and there is an edge (c,i) in the graph, will be in the new mask too. After that let's perform a transition from state (suff,mask) to state (suff+1,newMask).

The time complexity of this solution is O(n⋅2Σ⋅Σ2), where Σ is the size of the alphabet — 10 for this problem.

It's slow a bit, so we will optimize this solution. We can precalculate the newMask for each pair (c,mask) using the algorithm described above. After that, using this information, we can recalculate dp faster.

Time complexity: O(2Σ⋅Σ2+n⋅2Σ⋅Σ).

