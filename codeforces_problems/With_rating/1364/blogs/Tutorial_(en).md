# Tutorial_(en)


### [1364A - XXXXX](../problems/A._XXXXX.md "Codeforces Round 649 (Div. 2)")

Let's start with the whole array. If every element in it is divisible by xx, the answer is −1−1; if its sum isn't divisible by xx, the answer is nn. Otherwise, we must remove some elements. The key idea is that removing an element that is divisible by xx doesn't do us any benefits, but once we remove an element that **isn't**, the sum won't be divisible by xx. So let the first non-multiple of xx be at index ll, and the last one be at index rr. We must either remove the prefix all the way up to ll or the suffix all the way up to rr, and we'll clearly remove whichever shorter.

Code link: [https://pastebin.com/j2Y8AJBA](https://codeforces.com/https://pastebin.com/j2Y8AJBA)

Alternatively, we can notice that this means the answer is either a prefix or a suffix, so we can simply bruteforce them all.

### [1364B - Most socially-distanced subsequence](../problems/B._Most_socially-distanced_subsequence.md "Codeforces Round 649 (Div. 2)")

TL;DR the answer contains the first element, last element, and all the local minima and maxima, where a local minimum is an element less than its 2 adjacents, and a local maximum is an element greater than it 2 adjacents.

Let's look at the expression in the problem for 3 numbers. If a>ba>b and b>cb>c or if a<ba<b and b<cb<c, |a−b|+|b−c|=|a−c||a−b|+|b−c|=|a−c|, so it's never optimal to use aa, bb, and cc in a row because you can use just aa and cc and achieve a shorter subsequence. If you keep erasing your bb's from the original permutation, you'll end up with the first element, the last element, and the local minima and maxima. You can see that erasing any of them would decrease the expression, so this is the optimal answer.

Code link: [https://pastebin.com/e2HHuKFY](https://codeforces.com/https://pastebin.com/e2HHuKFY)

### [1364C - Ehab and Prefix MEXs](../problems/C._Ehab_and_Prefix_MEXs.md "Codeforces Round 649 (Div. 2)")

The key observation is: if for some index ii, ai≠ai−1ai≠ai−1, then bibi must be equal to ai−1ai−1, since it's the only way to even change the prefix MEXMEX. We can use this observation to fill some indices of bb. Now, how do we fill the rest? Let's start by **avoiding** every element in aa. Something special will happen if we avoid using any element from aa again. If we look at the first ii numbers in bb, aiai will indeed be excluded, so MEX(b1,b2,…,bi)≤aiMEX(b1,b2,…,bi)≤ai. Now we need to make it as big as possible. How do we make it as big as possible? The logical thing to do is to fill the rest of bb with the numbers not in aa **in increasing order**. It turns out this construction always satisfies the conditions. Indeed, if we look at the first ii elements in bb, every element less than aiai will be present because ai≤iai≤i and we added the rest of the elements in increasing order.

Code link: [https://pastebin.com/x9VtuBym](https://codeforces.com/https://pastebin.com/x9VtuBym)

### [1364D - Ehab's Last Corollary](../problems/D._Ehab's_Last_Corollary.md "Codeforces Round 649 (Div. 2)")

The common idea is: if the graph is a tree, you can easily find an independent set with size ⌈n2⌉⌈n2⌉ by bicoloring the vertices and taking the vertices from the more frequent color. Otherwise, the graph is cyclic. Let's get a cycle that doesn't have any edges "cutting through it." In other words, it doesn't have any pair of non-adjacent vertices connected by an edge. If its length is at most kk, print it. Otherwise, take every other vertex (take a vertex and leave a vertex) and you'll end up with a big enough independent set. How to find such cycle?

### First solution

Let's do a dfs in our graph. In the very first time we hit a node that has a back-edge, we take the back-edge that goes to the deepest possible node to close our cycle. This cycle can't have any edges crossing it because none of our node's ancestors has a back-edge (by definition.)

Code link: [https://pastebin.com/wsCXuzGy](https://codeforces.com/https://pastebin.com/wsCXuzGy)

### Second solution

Let's get any cycle in the graph. Now, let's iterate over the edges that don't belong to the cycle. Whenever we meet one that "crosses the cycle," we use it to cut the cycle into 2 cycles with smaller length and keep any of them. When we finish, we'd have our desired cycle.

Code link: [https://pastebin.com/ezwEURKW](https://codeforces.com/https://pastebin.com/ezwEURKW)

### [1364E - X-OR](../problems/E._X-OR.md "Codeforces Round 649 (Div. 2)")

The common idea is: if we find the index that contains 00, we can query it with every element in pp and finish in nn queries (if you didn't do that, pleaaase share your solution.) How to get this index?

### First solution

Let's try to make a magic function that takes an index ii and tells us pipi. Assume you have an array zz such that zjzj is some index in the permutation that has a 00 in the jthjth bit. Building our magic function with it turns out to be very easy. We'll just return query(i,z0)query(i,z0)&query(i,z1)query(i,z1)&……&query(i,z10)query(i,z10). Why does that work? If pipi has a 11 in the jthjth bit, this expression will also have a 11 because pipi will make every single clause have a 11. If it has a 00, query(i,zj)query(i,zj) will also have a 00, making the whole expression have a 00!

But how do we find zz? This turns out to be very easy. We'll query random pairs of indices, see where the result has a 00, and update zz. We stop once we fill every index in zz. This works quickly because for any bit, at least half the numbers from 00 to n−1n−1 will have a 00.

Now we already have an nlog(n)nlog(n) solution (call our magic function with every index,) but how to make less calls? Let's carry an index idxidx that's supposed to have the index of 00 in the end, and let pidxpidx be stored in valval. Initially, idxidx is 11 and valval could be found with our magic function. Now, let's iterate over the permutation. We'll query the current index, ii, with idxidx. If the result isn't a subset of valval, pipi can't be 00, so let's throw it in the trash. Otherwise, we'll make idxidx equal to ii and use our magic function to update valval.

Code link: [https://pastebin.com/kBQGrEqP](https://codeforces.com/https://pastebin.com/kBQGrEqP)

 **analysis**In my analysis, I'll use c to denote something that's clearly small but needs big math to analyze it, so it's better to omit these analysis (or something that I can't analyze *nervous chuckles*.)

Since every time val is replaced with a subset of it, we only call our magic function at most log(n) times, so the number of queries is at most 2n+log2(n)+c.

The cool thing about this solution is that it barely relies on randomness, so even if you run it for a million test cases, it would still pass. In fact, try to make it deterministic with n2 more queries.

There's a nice speed-up, but it relies much more on randomness: ask your indices in a random order, and make an itsy bitsy edit in the magic function: if val has a 0 in the jth bit, you don't really need to query i with zj. You can set the jth bit in the result to 0 right away because pi is a subset of val. That way, it doesn't always do log(n) queries; it does however many ones val has queries. This actually improves the solution to 2n+2log(n)+c on average! The intuition is: you start with a random number that has log(n)2 ones in it (on average,) and every time you face a subset of it, the number of ones is expected to be halved, so the number of queries is around log(n)+log(n)2+log(n)4+…<2log(n).

Code link: [https://pastebin.com/HWA1HuyF](https://codeforces.com/https://pastebin.com/HWA1HuyF)

### Second solution

Thanks, [Utkarsh.25dec](https://codeforces.com/profile/Utkarsh.25dec "Master Utkarsh.25dec") for this solution.

I'll describe a way to start with nn candidates to be 00 and end up with √nn−−√ candidates. Let's query random pairs until we find a pair whose bitwise-or has at most log(n)2log(n)2 bits. Take one of the 2 indices in the pair (let's call it ii) and query it with every candidate you have, and take the bitwise-and of the results. That will give you pipi. Now, let's make the numbers whose query result with ii is pipi (hence, a subset of pipi) our new candidates. Since ii has at most log(n)2log(n)2 ones, the number of its subsets is √nn−−√, and we have our desired result!

Now, to find the index of 00, we'll just do this recursively until we have 2 candidates. We'll keep querying them with random indices until the results differ. The one giving a smaller result is our 00.

Code link: [https://pastebin.com/zMV5CPAz](https://codeforces.com/https://pastebin.com/zMV5CPAz)

 **analysis**This solution does 2n+√n+√√n+…+c queries.

You may think this is much worse than the first solution, but apparently √n is smaller than log2(n) for small n. And by small, I mean ~105.

### Third solution

Thanks, [Mohammad_Yasser](https://codeforces.com/profile/Mohammad_Yasser "Master Mohammad_Yasser") for this solution.

Assume you have 2 candidates for 00 called aa and bb such that one of them is the index of 00 at the end of our algorithm, and we always know (pa|pb)(pa|pb). Let's iterate over our indices **in a random order** and try to update aa and bb. Assume the current index is cc. Let's query to get (pb|pc)(pb|pc). We have 3 cases:

 * If (pa|pb)<(pb|pc)(pa|pb)<(pb|pc), pcpc can't be 00, so we'll throw it away.
* If (pa|pb)>(pb|pc)(pa|pb)>(pb|pc), papa can't be 00, so we'll throw it away and change aa to be cc.
* Otherwise, pbpb can't be 00 because that would imply pa=pcpa=pc (recall that pp is a permutation.) So we can throw it away and change bb to be cc. But notice that we now don't know (pa|pb)(pa|pb), so we're gonna have to make one more query, since we need to keep track of it.

After we're done, we can narrow our 2 candidates down to 1 with the same way described in the previous solution.

Code link: [https://pastebin.com/Trifp8p3](https://codeforces.com/https://pastebin.com/Trifp8p3)

 **analysis**This solution does 2n+c queries, where c mostly comes from however many times we fall into the third case. I have no idea how to prove it happens very few times (just intuitions,) but very surprisingly, it's 3.37 on average and only 11 when we maximize across 10000 cases.

