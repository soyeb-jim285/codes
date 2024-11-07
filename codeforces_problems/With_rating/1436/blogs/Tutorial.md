# Tutorial


### [1436A - Reorder](../problems/A._Reorder.md "Codeforces Round 678 (Div. 2)")

You can notice that the $ i $-th number in the array will be included in the sum $i$ times, which means that the value $ \frac {a_i} {i} $ will add $ a_i $ to the sum. That is, the permutation of the elements does not affect the required sum, and therefore it is enough to check whether the sum of the array elements is equal to the given number.

**Author:** [aropan](https://codeforces.com/profile/aropan "Grandmaster aropan")

**author's solution:** [96602393](https://codeforces.com/contest/1436/submission/96602393 "Submission 96602393 by aropan")

 
### [1436B - Prime Square](../problems/B._Prime_Square.md "Codeforces Round 678 (Div. 2)")

First, note that the numbers 0 and 1 are not prime. Now let's try to build a square from only these numbers. To begin with, fill in the main and secondary diagonal of the square with ones.

If $n$ is even, then the sum in each row and each column is $2$ (prime number), and we have met the condition.

If $n$ is odd, then the sum in the row with the number $ \frac {n + 1} {2} $ and in the column with the number $ \frac {n + 1} {2} $ will be equal to one. To fix this, add ones to the cells $ (\frac {n} {2}, \frac {n + 1} {2}) $ and $ (\frac {n + 1} {2}, \frac {n + 1} {2} + 1) $. As a result, the sum in columns and rows will be equal to two or three, and we have fulfilled the condition of the problem.

**Author:** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111")

**author's solution:** [96598752](https://codeforces.com/contest/1436/submission/96598752 "Submission 96598752 by AleXman111")

 
### [1436C - Binary Search](../problems/C._Binary_Search.md "Codeforces Round 678 (Div. 2)")

Let's simulate a binary search algorithm. Initially, we have the required position $pos$. For the next $middle$ position in the binary search, we can determine exactly whether the next number at this position should be greater or less than $x$. For all other positions, the values can be eiteher greater or less than $x$. As a result of the simulation of the algorithm, we have $cntBig$ positions at which numbers must be greater than $x$ and $ cntLess $ positions at which numbers must be less than $x$. Let the large numbers be $hasBig$, and the smaller ones $hasLess$. Now let's count the number of ways to place large numbers in $cntBig$ positions using the formula $C(hasBig, cntBig) \cdot cntBig!$.

Let's calculate in a similar way for smaller numbers, and the product of the resulting results will be the answer to the problem.

**Author:** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111")

**author's solution:** [96598711](https://codeforces.com/contest/1436/submission/96598711 "Submission 96598711 by AleXman111")

 
### [1436D - Bandit in a City](../problems/D._Bandit_in_a_City.md "Codeforces Round 678 (Div. 2)")

First, let's assume that all the citizens are at the root of the tree. Then the answer to the problem will be $ \lceil \frac{a_1}{leaves} \rceil $, where $leaves$ is the number of leaves in the tree. According to the Dirichlet principle, this would be the minimum possible number of caught citizens.

The answer to the original problem is $ max_i {\lceil \frac{sum_{a_v}}{leafs_i} \rceil} $, where $v$ lies in the subtree of $i$, $leaves_i$ is the number of leaves in the subtree $i$.

Consider some vertex $i$, for which it is impossible to split the citizens equally. Then there will be a vertex $m$ in which in the optimal splitup will have the maximum number of citizens. Obviously, it is not profitable for us to send any citizen from vertex $i$ to $m$.

In this case, we can go one level down in the tree in the direction of $m$. We will repeat this step until we can divide the citizens equally. Hence it is clear why the above formula is correct.

**Author:** [hloya_ygrt](https://codeforces.com/profile/hloya_ygrt "Grandmaster hloya_ygrt")

**author's solution:** [96727317](https://codeforces.com/contest/1436/submission/96727317 "Submission 96727317 by Vladik")

 
### [1436E - Complicated Computations](../problems/E._Complicated_Computations.md "Codeforces Round 678 (Div. 2)")

Let's iterate over the answer. Let the current answer be $ x $, then we can get it only when there are no subarrays, whose MEX is $ x $. Note that we need to check the MEX of the subarrays that are between all occurrences of $ x $. This can be done, for example, using a segment tree, processing its occurrences in order. A number for which MEX is not found will be the answer.

**Author:** [andrew](https://codeforces.com/profile/andrew "Grandmaster andrew")

**author's solution:** [96601544](https://codeforces.com/contest/1436/submission/96601544 "Submission 96601544 by andrew")

 
### [1436F - Sum Over Subsets](../problems/F._Sum_Over_Subsets.md "Codeforces Round 678 (Div. 2)")

Let's calculate the required product of the sums $ans_i$ for the sets, the greatest common divisor of the elements of which is $i$. First, let's select all the elements that are divisible by $i$. To find only those sets whose GCD is exactly $i$, one can find the product of the sums for all subsets and subtract the answers of all $ans_j$ such that $i<j$ and $i$ divides $j$ without a remainder. To find the products of all subsets of a set of $ k $ elements, consider two cases: 

* the product $ a_i \cdot a_i $ will be counted $ 2^{k-2} \cdot (k - 1) $ times. Each element in the set $ A $ can be removed and this will add the product $ a_i^2 $. The number of elements $ k - 1 $ and the number, select the rest of the subset $ 2 ^ {k-2} $;
* the product $ a_i \cdot a_j $ will be counted $ 2 ^ {k-3} \cdot (k - 2) + 2 ^ {k-2} $. The first term is similar to the example above. And the second is obtained if $ a_i $ is removed from the set $ A $ - the number of ways to choose a subset of $ k - 2 $ elements is $ 2 ^ {k-2} $.

 It is only to count the individual sums $ a_i \cdot a_i $ and $ a_i \cdot a_j $ for all elements that are divisible by $ i $. To do this, you can maintain for already added numbers their number, sum, sum of squares of numbers and pairwise sum of numbers. The answer to the problem will be $ans_1$.**Author:** [hloya_ygrt](https://codeforces.com/profile/hloya_ygrt "Grandmaster hloya_ygrt")

**author's solution:** [96727345](https://codeforces.com/contest/1436/submission/96727345 "Submission 96727345 by Vladik")

**P.S.** We will add our own solutions soon

