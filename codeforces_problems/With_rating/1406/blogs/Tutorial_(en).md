# Tutorial_(en)

**Upd**: fixed author's solution links.

Sorry for the slow Editorial, I am new using Polygon.

Special thanks to [TechNite](https://codeforces.com/profile/TechNite "Master TechNite") for his help.

About one hour before the contest [Retired_cherry](https://codeforces.com/profile/Retired_cherry "Expert Retired_cherry") found the same problem, then we changed it to k=4k=4 and he found another same one again. We are running out of time so we didn't have time for a new one, so we changed kk to 55. But we didn't know there is still a similar problem. Sorry again.

 
### [1406A - Subset Mex](../problems/A._Subset_Mex.md "Codeforces Round 670 (Div. 2)")

Let us store the count of each number from $0$ to $100$ in array $cnt$. 

Now $mex(A)$ would be the smallest $i$ for which $cnt_i=0$.Let this $i$ be $x$. $mex(B)$ would be smallest $i$ for which $cnt_i\leq 1$. This is because one count of each number less than $x$ would go to $A$ therefore the element which was present initially once would now not be available for $B$.

Overall Complexity: $O(n)$.

idea:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") solution:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") tutorial:[TechNite](https://codeforces.com/profile/TechNite "Master TechNite")

Jury solution:[92671575](https://codeforces.com/contest/1406/submission/92671575 "Submission 92671575 by feecIe6418")

 
### [1406B - Maximum Product](../problems/B._Maximum_Product.md "Codeforces Round 670 (Div. 2)")

First, if all numbers are less than $0$, then you should print the product of the five biggest numbers of them.

Otherwise, the maximum product must be non-negative. Sort the numbers by their absolute value from big to small. 

If the first five numbers' product is positive then print it. Then we can always change one of the five to one of the $n-5$ other numbers to make this product positive. Enumerate which one to replace, and you can solve this problem in $O(n)$ time.

idea: [feecIe6418](https://codeforces.com/profile/feecIe6418 "Candidate Master feecIe6418") solution:[feecIe6418](https://codeforces.com/profile/feecIe6418 "Candidate Master feecIe6418") tutorial:[feecIe6418](https://codeforces.com/profile/feecIe6418 "Candidate Master feecIe6418")

Jury solution:[92671590](https://codeforces.com/contest/1406/submission/92671590 "Submission 92671590 by feecIe6418")

 
### [1406C - Link Cut Centroids](../problems/C._Link_Cut_Centroids.md "Codeforces Round 670 (Div. 2)")

Let vertex $1$ be the root of the tree. If there is only one centroid, just cut any edge and link it back.

Otherwise there are two centroids. Let them be $x$ and $y$, then there must be an edge connecting $x$ and $y$. (If not, choose any other vertex on the path from $x$ to $y$ and the size of the largest connected component after cutting it will be smaller than $x$ and $y$).

Let $x$ be $y$'s father. (If not, swap $x$ and $y$) Then just cut a leaf from $y$'s subtree and link it with $x$. After that, $x$ becomes the only centroid.

Proof: It's easy to see that the size of $y$'s subtree must be exactly $\dfrac{n}{2}$. After cutting and linking, the maxinum component size of $y$ becomes $\dfrac{n}{2}+1$ while the maxinum component size of $x$ is still $\dfrac{n}{2}$.

idea:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") solution:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") tutorial:[feecIe6418](https://codeforces.com/profile/feecIe6418 "Candidate Master feecIe6418")

Jury solution:[92671713](https://codeforces.com/contest/1406/submission/92671713 "Submission 92671713 by feecIe6418")

 
### [1406D - Three Sequences](../problems/D._Three_Sequences.md "Codeforces Round 670 (Div. 2)")

Since sequence $b$ is non-decreasing and sequence $c$ is non-increasing, we need to mimimize $\max(c_1,b_n)$.

Now observe that if $a_i>a_{i-1}$ then $b_i=b_{i-1}+a_i-a_{i-1}$ and $c_i=c_{i-1}$.Else if $a_i<a_{i-1}$ then $b_i=b_{i-1}$ but $c_i=c_{i-1}+a_i-a_{i-1}$. Now we calculate $\sum\limits_{i=2}^{n}\max(0,a_i-a_{i-1})$.Let this sum be $K$. Now lets assume $c_1$ is $x$. So then $b_1$ is $a_1-x$.And as observed before $b_n = a_1-x+K$. 

Now we just need to minimize $\max(x,a_1-x+K)$. Now it is easily observable that $x$ should be $\dfrac{a_1+K}{2}$.

For the changes, since we only need to know $\sum\max(0,a_i-a_{i-1})$, so only $a_l-a_{l-1}$ and $a_r-a_{r-1}$ will change.

Total time complexity: $O(n+q)$.

idea:[isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27") solution:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") tutorial:[TechNite](https://codeforces.com/profile/TechNite "Master TechNite")

Jury solution:[92671763](https://codeforces.com/contest/1406/submission/92671763 "Submission 92671763 by feecIe6418")

 
### [1406E - Deleting Numbers](../problems/E._Deleting_Numbers.md "Codeforces Round 670 (Div. 2)")

If we know what prime factors x has, we can find $x$ just using bruteforce.

To find the prime factors, we can just do $B~p$ for every prime $p$ in ascending order, meanwhile calculate the numbers there supposed to be without $x$, if it differs with the number the interactor gives, then $x$ contains the prime factor $p$.

This way, we can find every prime factor except for the smallest one.

Let $m$ be the number of primes no greater than $n$. 

Then we can split the prime numbers into $\sqrt m$ groups.

After finishing asking a group, ask $A~1$ and check if the return value same as it supposed to be without $x$. If it's the first time finding it different, it means the smallest prime number is in the range, then just check every prime numbers in the range by asking $A~p$.

After finding the prime factors, for each factor, ask $A~p^k$, it can be proved this step will be done around $\log(n)$ times.

The total number of operations if around $m+2\sqrt m+\log(n)$, the total time complexity is $O(n\log n)$

idea:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") solution:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20") tutorial:[gyh20](https://codeforces.com/profile/gyh20 "Master gyh20")

Jury solution:[92671740](https://codeforces.com/contest/1406/submission/92671740 "Submission 92671740 by feecIe6418")

