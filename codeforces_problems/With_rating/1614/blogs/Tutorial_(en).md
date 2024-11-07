# Tutorial_(en)

[A. Divan and a Store](../problems/A._Divan_and_a_Store.md) 

 **Solution**To solve this problem, let's use the following greedy algorithm.

Let's sort the prices of chocolate bars in increasing order, after which we will go from left to right and take chocolates that have a price not less than l, but not more than r until we run out of money.

The number of chocolate bars that we took will be the answer to the problem.

The resulting asymptotics in time: O(nlogn).

[B. Divan and a New Project](../problems/B._Divan_and_a_New_Project_.md)

 **Solution**Obviously, the more often we have to go to the i building, the closer it should be to the main office.

This implies a greedy algorithm. Let's put the main office at 0 and sort the rest by ai. Then we put the most visited building at a point with a coordinate of 1, the second at −1, the third at 2, etc. 

The resulting asymptotics in time is O(nlogn).

[C. Divan and bitwise operations](../problems/C._Divan_and_bitwise_operations.md?locale=en)

 **Solution**Let's count for each bit how many times it will be included in the answer.

Let us now consider the i-th bit. Note that if no number contains the included i-th bit, then such a bit will never be included in the answer. Otherwise, each of the subsequences contains i-th bit even or odd number of times. If a bit enters an even number of times, then we should not count such a subsequence, because the bitwise exclusive OR for this bit will be zero. If the bit enters an odd number of times, then we must count such a subsequence, because the bitwise exclusive OR for this bit will be equal to one.

It is stated that the number of subsequences in which the i-th bit enters an odd number of times is equal to 2n−1. Let's prove it.

Divide the numbers into two sets A and B. In the set A there will be numbers whose ith bit is off, in the set B there will be numbers whose i-th bit is on.

Note that the numbers from the set A do not affect the answer in any way, because xXOR0=1. Thus, whichever subset of A we take, the i-th bit will not change its parity. There will be 2|A| in total of such subsets.

Let k=1 if |B| is even, or k=0 if |B| is odd. In order for the i-th bit to enter the subsequence an odd number of times, you need to take an odd number of elements from the set B. This number is equal to C1|B|+C3|B|+…+C|B|−k|B|=2|B|−1.

Thus, the i-th bit is included in exactly 2|A|⋅2|B|−1=2n−1 subsequences, which was required to be proved.

Then the solution to this problem turns out to be very simple: let x be equal to the bitwise OR of all elements of the sequence (or, the same thing, bitwise OR of all given segments), then the answer will be equal to x⋅2n−1 modulo 109+7.

The resulting asymptotics in time: O(n).

[D1. Divan and Kostomuksha (easy version)](../problems/D1._Divan_and_Kostomuksha_(easy_version).md)

 **Solution**Let's solve the dynamic programming problem. Let dpi be the maximum answer for all arrays, the last element of which is divisible by i. Let's calculate the dynamics from C to 1, where C is the maximum value of ai. Initially, dpi=cnti⋅i, where cnti is the amount of ai=i. How do we recalculate our dynamic programming? dpi=max(dpi,dpj+i⋅(cnti−cntj)), for all j such that j mod i=0 (i.e. j is divisible by i). In this dynamic, we iterate over the past change of our gcd on the prefix, and greedily add all possible elements.

The resulting asymptotics in time is O(ClogC).

[D2. Divan and Kostomuksha (hard version)](../problems/D2._Divan_and_Kostomuksha_(hard_version).md)

 **Solution**To solve D2, we can notice that to recalculate the dynamics, we can iterate over all such j that differ from i by multiplying exactly 1 prime number. Also, to speed up the solution, we can use the linear sieve of Eratosthenes to find primes and factorization.

The resulting asymptotics in time: O(CloglogC).

[E. Divan and a Cottage](../problems/E._Divan_and_a_Cottage.md)

 **Solution**Let anstemp the current answer for temperature temp. Before all days, anstemp is considered equal to temp.

In order to respond to a request with a temperature of x, we will just need to output the value of ansx. But how to maintain ans? With the help of an implicit tree of segments, at the vertices of which the minimum and maximum will be stored, as well as the variable add, which will contain the value that needs to be added to the current vertex (that is, such a variable that is needed to perform lazy operations on the segment tree).

At the beginning of the next day you get the temperature T. Now we need to change the current answer for some temp. We need to find such anstemp that anstemp<T and add +1 to them, and then find such anstemp that anstemp>T and add −1 to them. All this is not difficult to do, just starting from the root of the segment tree and stopping at the moments when:

 * the maximum of the current vertex is less than T — here we add +1;
* the minimum of the current vertex is greater than T — here we add −1;
* the minimum of the vertex is equal to the maximum of the vertex (and, therefore, the T itself) — here we do not add anything.

The resulting asymptotics in time: O(nlogT).

