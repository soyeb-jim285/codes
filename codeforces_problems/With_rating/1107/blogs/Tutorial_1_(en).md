# Tutorial_1_(en)

Continuing with the theme from last time, here's a quick writeup of my approaches:

#### [1107A - Digits Sequence Dividing](../problems/A._Digits_Sequence_Dividing.md "Educational Codeforces Round 59 (Rated for Div. 2)")

Since we just want to make two numbers such that the first number is smaller than the second, our best bet is to use only the first digit for the first number and the rest of the digits for the second number. Note that since the numbers can have up to 300 digits we shouldn't actually evaluate the second number. Instead, since the digits only include 1 through 9, we can handle that case by checking the number of digits. Code: [49002957](https://codeforces.com/contest/1107/submission/49002957 "Submission 49002957 by neal")

#### [1107B - Digital root](../problems/B._Digital_root.md "Educational Codeforces Round 59 (Rated for Div. 2)")

The key observation is that the digital root of an integer *k* is the single-digit number 1 ≤ *d* ≤ 9 such that ![](images/711f6e1186e3cd32ab2be88f0715c076c602ef3f.png). You can prove this by noticing that ![](images/312b55ca6a7c7c6fe8bba2ee005ce59903bc0c5d.png) for all *p*. Once we observe this, finding the *k*-th number is very simple; see the code: [48993705](https://codeforces.com/contest/1107/submission/48993705 "Submission 48993705 by neal")

#### [1107C - Brutality](../problems/C._Brutality.md "Educational Codeforces Round 59 (Rated for Div. 2)")

Since we are only allowed to push the same button *k* times in a row, let's do a two-pointer sweep to find all segments of consisting of just one button. Within each segment, we'll sort and take the *k* highest values. See the code for details on the two-pointer sweep: [48994498](https://codeforces.com/contest/1107/submission/48994498 "Submission 48994498 by neal")

#### [1107D - Compression](../problems/D._Compression.md "Educational Codeforces Round 59 (Rated for Div. 2)")

After some tinkering with the given condition, we notice that an *x*-compression is possible iff *x* divides *n* and the *n* × *n* matrix is divisible into *x* × *x* matrices such that each matrix is either all 1 or all 0. We can loop over all such *x* and check the condition in *n*2 time per *x*, but this is potentially too slow.

To speed this up, we can precompute rectangle sums for every rectangle containing the upper-left corner, which enables us to compute the sum of any rectangle in ![](images/34429d3fd71191b755681162f135c11209a37d16.png). This improves our time complexity to ![](images/c4657edf923e38fbcf3075e25be32710a4145ed6.png). Since ![](images/3c168375d55ac2cd3e25857a0c91fe92f6ef3cb2.png) ([really!](https://codeforces.com/https://en.wikipedia.org/wiki/Basel_problem)), this means our solution is ![](images/2ea07df0930018e7899f810e5f4842f0e6499e40.png). Code: [49028814](https://codeforces.com/contest/1107/submission/49028814 "Submission 49028814 by neal")

#### [1107E - Vasya and Binary String](../problems/E._Vasya_and_Binary_String.md "Educational Codeforces Round 59 (Rated for Div. 2)")

We set up a DP on (start index, end index, number of consecutive digits matching our start index). In other words, the current string we are solving is the substring from start index to end index, plus some number of additional digits (all equal to S[start]) added as a prefix to our substring.

We then have two choices from any given state:

 * Cash in on our consecutive digits at the start and recurse on ![](images/5530c302445edcc45b75f38b986c86eb94c57aaf.png).
* Pick an index *i* such that S[start] = S[i], and collapse everything between those two indices in order to merge them together for an even larger prefix. This results in a score of ![](images/7db9205883461ab1c98609d6f4d2b74d4a8c9fd5.png), and we can loop over all *i* to take the maximum.

The runtime is ![](images/52f5eb64c79099e50853c05d5eeed424185b604b.png), with a very good constant factor. Code: [49036191](https://codeforces.com/contest/1107/submission/49036191 "Submission 49036191 by neal")

Does anybody have ![](images/29165e38e9dc2f1300719e31f973634e704eef6c.png)?

#### [1107F - Vasya and Endless Credits](../problems/F._Vasya_and_Endless_Credits.md "Educational Codeforces Round 59 (Rated for Div. 2)")

Notice that if we take offer *i* exactly *m* months **before** we buy the car, it will provide us with ![](images/73821086e437b55594e89f74a83bb2153beecf8a.png) money at the time of the car purchase. Moreover, the only values of *m* that make sense are 0 ≤ *m* ≤ *n* - 1. This means we can immediately solve the problem via an algorithm for the [assignment problem](https://codeforces.com/https://en.wikipedia.org/wiki/Assignment_problem), such as min-cost flow or the Hungarian algorithm. This has a runtime of ![](images/29165e38e9dc2f1300719e31f973634e704eef6c.png) or ![](images/0aca4e31ea1d03a6c65bf59deb7b144628ff930d.png), which manages to fit under the time limit with a good implementation. Code: [49033783](https://codeforces.com/contest/1107/submission/49033783 "Submission 49033783 by neal")

The better solution is to notice that for all offers *i* where we don't use up all *k**i* months, it's best to sort them by *b**i* (so that the highest values of *b**i* have the lowest values of *m*). This leads to a very nice ![](images/2ea07df0930018e7899f810e5f4842f0e6499e40.png) DP solution: [49035446](https://codeforces.com/contest/1107/submission/49035446 "Submission 49035446 by neal")

#### [1107G - Vasya and Maximum Profit](../problems/G._Vasya_and_Maximum_Profit.md "Educational Codeforces Round 59 (Rated for Div. 2)")

We can first compute all values of ![](images/52b1856c112c7e636671e89f8d0bf5558f0b3a65.png). Since we only care about the maximum such value within our segment, we can use div-conquer to solve every segment. In particular, if we know the index of the maximum value in ![](images/b601db4a3289ccd8d57241c112b472f8c89a3e47.png), we know that any segment crossing this index has this value as its maximum. We can thus solve all segments crossing this maximum and recurse on the left and right sides.

To find the best crossing segment, note that each problem contributes a value of *a* - *c**i*. We can independently find the largest sum starting from our crossing index going left and the largest sum going right, and add these two together for the best overall crossing segment.

Unfortunately, since we can't guarantee that the maximum indices will divide our interval nicely in half, this does not lead to the usual ![](images/063033c13a9fdf5042f3bf7ddeb599f41195fe62.png) runtime of div-conquer but is instead ![](images/2ea07df0930018e7899f810e5f4842f0e6499e40.png) in the worst case. To improve on this, we can precompute partial sums of *a* - *c**i* and use [RMQ](https://codeforces.com/https://en.wikipedia.org/wiki/Range_minimum_query) to find the minimum sum left of the crossing index and the maximum sum right of the crossing index. This reduces the crossing computation from ![](images/92de30bfabf583a2c3a88f74b1d279cf6e3b0abf.png) per index to ![](images/5b2f815f09fbbfe4a43afff11d4a11ee3223401c.png) or ![](images/34429d3fd71191b755681162f135c11209a37d16.png), giving an overall runtime of ![](images/063033c13a9fdf5042f3bf7ddeb599f41195fe62.png). Code: [49036431](https://codeforces.com/contest/1107/submission/49036431 "Submission 49036431 by neal")

