# Tutorial_(en)


#### [959A - Mahmoud and Ehab and the even-odd game](../problems/A._Mahmoud_and_Ehab_and_the_even-odd_game.md "Codeforces Round 473 (Div. 2)")

It's easy to see that if *n* = 0, the next player loses. If *n* is even, Mahmoud will choose *a* = *n* and win. Otherwise, Mahmoud will have to choose *a* < *n*. *n* is odd and *a* is even, so *n* - *a* is odd. Ehab will then subtract it all and win. Therefore, if *n* is even Mahmoud wins. Otherwise, Ehab wins. *n* = 1 doesn't follow our proof, yet Ehab still wins at it because Mahmoud won't be even able to choose *a*. 

Code link (me) : [https://pastebin.com/X3D08tg9](https://codeforces.com/https://pastebin.com/X3D08tg9)

Code link ([mahmoudbadawy](https://codeforces.com/profile/mahmoudbadawy "Candidate Master mahmoudbadawy")) : [https://pastebin.com/4u3RHE7n](https://codeforces.com/https://pastebin.com/4u3RHE7n)

Time complexity : *O*(1).

**Bonus task :** If there were multiple integers, and each player can choose which integer to subtract from, who will win?

 **Solution**Ehab can follow a good greedy strategy : make some number odd and leave it till the end of the game. Mahmoud won't be able to make it 0 so Ehab will win. If there's already an odd integer, or there are at least 2 even integers, Ehab can do that. Therefore, the only case Mahmoud wins is when there's one even integer!

#### [959B - Mahmoud and Ehab and the message](../problems/B._Mahmoud_and_Ehab_and_the_message.md "Codeforces Round 473 (Div. 2)")

It's easy to see that for every word, the minimum cost of sending it is the minimum cost of sending any word in its group. For each group, we'll maintain the minimum cost for sending a word in it (let it be *cost**i*) and for each word, we'll maintain its group (let it be *group**i*). For every word *i* in the message, we'll add *cost**group**i* to the answer.

Code link (me) : [https://pastebin.com/3RFeEkgD](https://codeforces.com/https://pastebin.com/3RFeEkgD)

Code link ([mahmoudbadawy](https://codeforces.com/profile/mahmoudbadawy "Candidate Master mahmoudbadawy")) : [https://pastebin.com/sR5eZy7d](https://codeforces.com/https://pastebin.com/sR5eZy7d)

Time complexity : *O*((*n* + *m*)*log*(*n*) * *len*).

**Bonus task :** Try to solve the problem if the input was given as pairs of words that are synonyms (assuming synonymy is transitive).

 **Solution**Use dsu to transform the bonus task to the original problem.

#### [959C - Mahmoud and Ehab and the wrong algorithm](../problems/C._Mahmoud_and_Ehab_and_the_wrong_algorithm.md "Codeforces Round 473 (Div. 2)")

### The first tree

For *n* ≥ 6, you can connect nodes 2, 3, and 4 to node 1 and connect the rest of the nodes to node 2. The real vertex cover is the set {1, 2} of size 2 while the found vertex cover will have size *min*(3, *n* - 3). As *n* ≥ 6, that value will be 3 which is incorrect.

For *n* < 6, the answer doesn't exist.

### The second tree

There are multiple ways to construct it. One easy way is the star tree. Connect all the nodes to node 1. The real and the found vertex cover will be simply {1}. Another easy way is a path. Connect node *i* to node *i* + 1 for all 1 ≤ *i* < *n*. The real and the found vertex cover has size ![](images/832254ba69494673dbc525f2e9193b28c955acd0.png).

Code link (me) : [https://pastebin.com/7J8B9fXx](https://codeforces.com/https://pastebin.com/7J8B9fXx)

Code link ([mahmoudbadawy](https://codeforces.com/profile/mahmoudbadawy "Candidate Master mahmoudbadawy")) : [https://pastebin.com/54jZ8sGM](https://codeforces.com/https://pastebin.com/54jZ8sGM)

Time complexity : *O*(*n*).

**Bonus task :** Try to find an elegant proof that the answer for *n* < 6 doesn't exist for the first tree.

 **Solution**First, the actual vertex cover is at most ![](images/ff3debcd979cb1dbc17aecf1e75e31f997a019f8.png). Second, the found vertex cover is also at most ![](images/ff3debcd979cb1dbc17aecf1e75e31f997a019f8.png) (because both *evenCnt* and *oddCnt* can't be both greater than ![](images/ff3debcd979cb1dbc17aecf1e75e31f997a019f8.png) at the same time!). The algorithm is greedy so its answer is greater than or equal to the actual answer. As *n* < 6, The actual and the found answer can't exceed 2. Therefore, the only case where the algorithm is wrong is when the actual answer is 1 and the found answer is 2. That can't happen because the actual answer is 1 only in the case of a star tree. If all the nodes are connected to the root, *evenCnt* = 1. Otherwise, *oddCnt* = 1. Therefore, there's no case where the algorithm will fail.

#### [959D - Mahmoud and Ehab and another array construction task](../problems/D._Mahmoud_and_Ehab_and_another_array_construction_task.md "Codeforces Round 473 (Div. 2)")

**Common things :** Let's call a number "ok" if it could be inserted to array *b*, as a new element, without breaking any of the conditions (i.e it should be coprime with all the previously inserted elements). Let's call the maximum number that could be inserted in the worst case *mx*. For each integer from 2 to *mx*, we'll precompute its prime divisors with sieve.

### First solution by me

Create an `std::set` that contains all the numbers from 2 to *mx*. That set has all the "ok" numbers and will be updated each time we insert a new element to array *b*. We'll insert the elements to array *b* greedily one by one. At index *i*, let *cur* be the minimum number in the set greater than or equal to *a**i* i.e `std::lower_bound(a[i])`. If cur isn't equal to *a**i*, the lexicographically greater condition is satisfied and we're no longer restricted to *a*, so, starting from index *i* + 1, we'll greedily choose *cur* to be the first (minimum) number in the set instead. We'll insert *cur* to *b*. Each time, we'll remove all the integers that aren't coprime with *cur* from the set. To do that, we'll loop over the multiples of its precomputed prime divisors and remove them from the set.

Code link (me) : [https://pastebin.com/bg3Hi6r2](https://codeforces.com/https://pastebin.com/bg3Hi6r2)

### Second solution by [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN")

Let *used*[*i*] indicate whether some prime is already a factor of one of elements in *b* (so we shouldn't use it). Each time we insert an element to *b*, we update *used* by iterating over its precomputed prime divisors and make them all used. We'll start inserting elements to *b* greedily one by one. To check if a number is "ok", we'll iterate over its precomputed prime divisors and check that all of them aren't used. While *a**i* is "ok", we'll keep inserting it to *b*. We'll reach an integer that isn't "ok". In this case, we'll iterate naiively until we find an integer that is "ok" and insert it to *b*. The lexicographically greater condition is now satisfied and we can insert whatever we want (no restriction to *a*). Notice that starting from now, *b* will be sorted in increasing order. That's because if it's not, we can sort it and reach a better answer without breaking any of the conditions. The naiive solution is to loop starting from 2 until we find an "ok" integer for each *i*. However, as the array is sorted, we can loop starting from 2 the first time and then loop starting from *b**i* - 1 + 1 and save a lot of loops that we're sure will fail!

Code link (me) : [https://pastebin.com/Xh2QgqUf](https://codeforces.com/https://pastebin.com/Xh2QgqUf)

Time complexity : *O*(*mxlog*(*mx*)). *mx* has an order of ![](images/f48c77507932d24bb8e9faedf28d03bfc496aa50.png) because the *n**th* prime is expected to be *O*(*nlog*(*n*)) and the number of primes less that *n* is expected to be ![](images/933531031a12506fc86e8ea35267f478529d3083.png).

#### [959E - Mahmoud and Ehab and the xor-MST](../problems/E._Mahmoud_and_Ehab_and_the_xor-MST.md "Codeforces Round 473 (Div. 2)")

For convenience, let *n* be the label of the last node not the number of nodes (i.e *n* = *n**input* - 1).

Denote *lsb*(*x*) = *x*&( - *x*) as the value of the least significant bit set to 1 in *x*. The answer is ![](images/3bad024ea46d373b9792b2eda008b2b53c97ded0.png), which means that node *u* is connected to node ![](images/ce80a7046290e456ec906ffff5b2ac9af25684b5.png) for all 1 ≤ *u* ≤ *n* (node *u* is connected to node *u* without that bit).

 **Formal proof**Let's take a look at a version of Boruvka's algorithm for the MST. It starts with an empty MST and then at each step, it chooses some components. For each of them, it finds the edge with the minimum cost connecting this component to any other component and adds this edge to the minimum spanning tree. Let's apply this algorithm here. Assume that at step #*x*, the components are of the form of intervals of length 2*x* i.e component #*i* has nodes in [*i* * 2*x*;(*i* + 1) * 2*x* - 1]. Let's see what the algorithm does. Let's see what happens for components where *i* is odd. Assume the minimum cost for connecting this component is *c*. You can see that *c* can't be less than 2*x*. That's because this intervals contains integers that have all the possible combinations of the first *x* bits. Take *x* = 2 and *i* = 1, for example: the numbers are (in binary) 100, 101, 110, 111. All the possible combinations for the first *x* bits are there! Notice that if you choose *c* < 2*x*, you're changing the first *x* bits. We have all possible combinations of them in the component so we'll make a cycle. That makes the minimum cost 2*x*. There's always a way to make a connection with cost 2*x* which is connecting the first node of this component with the first node of the previous component (i.e connect node *i* * 2*x* with node (*i* - 1) * 2*x*). Notice that ![](images/f1f1ee818b5e2cb601a2ea471ab1e24c8ef8f8cc.png) because *i* is odd (Can you see why this is false for even *i*?). After that happens, the 2 components will form one big component and the components will be in the form of intervals of length 2*x* + 1 and the algorithm will repeat the same pattern!! Notice that at the beginning, the nodes are of the form of intervals with length 1 so the algorithm will work like that until the MST is constructed. Each node is the first node of its component and its component will have an odd index exactly once because after that it'll be in the middle of another big component. When that happens, it'll be when 2*x* = *lsb*(*x*). Therefore, node *u* adds *lsb*(*u*) to the answer!

Now let's see how to calculate that quickly.

### Math solution

Let *f*(*x*) be the number of integers *y* such that 1 ≤ *y* ≤ *n* and *lsb*(*y*) = *x*, then ![](images/88a0d8116fed14589f7bcbf5f0f5b45d9cd0f780.png). *f*(*i*) > 0 if and only if *i* is a power of 2 so this sum is equivalent to ![](images/8631d9f550f185332ae24f02b2352d6af81258ec.png). Basically, the first number *y* such that *lsb*(*y*) = *x* is *x* and then the period is 2 * *x*. Take 4 to see that. The integers *y* such that *lsb*(*y*) = 4 are {4, 12, 20, 28, *etc*.} Therefore, ![](images/e6c1f1a8e6c7153b642127514779a7ed2e9b667f.png) for 1 ≤ *x* ≤ *n* and x is a power of 2.

Code link (me) : [https://pastebin.com/dNuR9k0Y](https://codeforces.com/https://pastebin.com/dNuR9k0Y)

### DP solution

Let's see how the sequence of *lsb*(*x*) is constructed. We start with {1} and at the *i**th* step, we copy the sequence and concatenate it to itself and add 2*i* in the middle.

![](images/0294ad4703f583238baaab65854618d9c875d985.png)

Let ![](images/8b714b42b599eb3b4c9c2e1c347372df55ff77ca.png). Let *dp*[*i*] = *f*(2*i* - 1).

You can see from the pattern above that *dp*[*i*] = 2 * *dp*[*i* - 1] + 2*i* - 1 for 1 < *i* (with the base case that *dp*[1] = 1). Let's find a recurrence for *f*(*x*). Denote *msb*(*x*) as the value of the most significant bit set to 1. The sum can be split into 2 parts : the sum from 1 to *msb*(*x*) and the sum from *msb*(*x*) + 1 to *x*. You can see that in the second sum, *lsb*(*i*) can never be equal to *msb*(*x*), so we can remove that bit safely without affecting the answer. Removing that bit is like xoring with *msb*(*x*) which makes the sum start at 1 and end at ![](images/50cc356285c719a6446b9894191a2e5a1913207d.png) which is ![](images/070a12291d7778abb5b71512e46a17065f245518.png). Therefore, ![](images/9a915b56e0109532ec61256cc209dc30d671135b.png). The first part can be calculated with the help of our *dp* because *msb*(*x*) is a power of 2 and the second part goes recursively. Basically, for each *i* such that the *i**th* bit is set to 1, we add *dp*[*i*] + 2*i* to the answer.

Code link (me) : [https://pastebin.com/wnhBZx2v](https://codeforces.com/https://pastebin.com/wnhBZx2v)

Time complexity : *O*(*log*(*n*)).

#### [959F - Mahmoud and Ehab and yet another xor task](../problems/F._Mahmoud_and_Ehab_and_yet_another_xor_task.md "Codeforces Round 473 (Div. 2)")

Let's solve a simpler version of the problem. Assume the queries only ask you to see whether the answer is 0 or positive instead of the exact answer. We can answer all the queries offline. We can keep a set containing all the possible xors of subsequences and update it for each prefix. Initially, the set contains only 0 (the xor of the empty subsequence). For each index *i* in the array, we can update the set by adding ![](images/4cbbe0d4d0f7a8236ae838a5e8131376aced1904.png) to the set for all *x* in the set. The intuition behind it is that there's a subsequence with xor equal to *x* (as *x* is in the set) and if we add *a**i* to it, its xor will be ![](images/4cbbe0d4d0f7a8236ae838a5e8131376aced1904.png), so we should add it to the set. That's a slow solution to update the set, but we have some observations:-

 1. If *x* is in the set and *y* is in the set, ![](images/b364f2e04c665b78b924ec10666327a4ef4635bc.png) must be in the set. To see that, let *x* be the xor of some elements and *y* be the xor of other elements. ![](images/b364f2e04c665b78b924ec10666327a4ef4635bc.png) must be the xor of the non-common elements (because the common elements will annihilate) so it must be in the set.
2. If *x* is in the set and *y* isn't in the set, ![](images/b364f2e04c665b78b924ec10666327a4ef4635bc.png) can't be in the set. This could be proved by contradiction. Assume ![](images/b364f2e04c665b78b924ec10666327a4ef4635bc.png) is in the set, then, by the first observation, ![](images/e9a6deafccf1e72fc1339d11b0b051126fd87c0b.png) must be in the set. This is equivalent to *y* which we said that it isn't in the set. Therefore, ![](images/b364f2e04c665b78b924ec10666327a4ef4635bc.png) isn't in the set.

Basically, if *a**i* is already in the set, we do nothing because updating the set would do nothing but extra operations according to the first observation, and if *a**i* isn't in the set, we don't even waste a single operation without extending the set! That makes the total complexity *O*(*n* + *maxAi*) or *O*((*n* + *maxAi*)*log*(*maxAi*)) depending on implementation because each element is added to the set exactly once.

To solve our problem, let's see the naiive dynamic programming solution. Let *dp*[*i*][*x*] be the number of subsequences of the first *i* elements with xor *x*. ![](images/6469d5b868c8d59b9dbc37de6319674b5ef18855.png). The intuition behind it is exactly the same as the intuition behind the set construction. Let's prove that *dp*[*i*][*x*] is equal for all *x* belonging to the set! Let's assume this holds true for *i* - 1 and see what happens in the transition to *i*. Notice that it holds true for *i* = 0. Let *j* be the value that *dp*[*i* - 1][*x*] is equal to for all *x* belonging to the set. If *a**i* is in the set, and *x* is in the set, ![](images/4cbbe0d4d0f7a8236ae838a5e8131376aced1904.png) is in the set (observation #1). Therefore, *dp*[*i* - 1][*x*] = *j* and ![](images/30ecf3a40eae16867c3a3d1809472f9a1b450c97.png) which makes *dp*[*i*][*x*] = 2 * *j* for all *x* in the set. Notice that the set doesn't change so *dp*[*i*][*x*] = 0 for all *x* that aren't in the set. If *a**i* isn't in the set, we have 3 cases for *x*. If *x* is in the set, ![](images/4cbbe0d4d0f7a8236ae838a5e8131376aced1904.png) isn't in the set. Therefore, *dp*[*i*][*x*] = *j* + 0 = *j*. If *x* is to be added to the set in this step, ![](images/4cbbe0d4d0f7a8236ae838a5e8131376aced1904.png) is in the set. Therefore, *dp*[*i*][*x*] = 0 + *j* = *j*. Otherwise, *dp*[*i*][*x*] = 0. To summarize, we'll maintain the set. For each integer, if it's in the set, we'll just multiply *j* by 2. Otherwise, we'll update the set. We'll then answer all the queries for that prefix (saying 0 or *j*) depending on whether *x* is in the set.

Code link (me) : [https://pastebin.com/Kfi0NWTi](https://codeforces.com/https://pastebin.com/Kfi0NWTi)

Time complexity : *O*(*n* + *maxAi*) if you implement the "set" with a vector and an array.

**Bonus task :** Can you make this solution work online? Can you do that with *maxAi* < 230?

 **Solution**Let's consider each number as a vector in a 30-dimensional space. The *i**th* coordinate will be 1 if the *i**th* bit is 1 and 0 otherwise. The bitwise-xor operation of 2 integers is equivalent to adding the 2 vectors modulo 2. Therefore, ordinary methods of linear algebra work! A linear combination of some vectors is achieved by multiplying each vector by 0 or 1 and summing them up (modulo 2). Let's find the basis (the vectors such that any vector can be formed as a linear combination of them). To do that, we'll just use gaussian elimination. There can't be more than 30 basis vectors. In each query, we'll find the basis vectors with index less than or equal to *l* and check that *x* can be formed by a linear combination of them with gaussian elimination. If it can't, the answer is of course 0. Otherwise, let the number of basis vectors be *cnt*. The answer is 2*l* - *cnt*. The reason is that for each subsequence of the vectors that aren't basis vectors, we can add a linear combination of the basis vectors to it and achieve *x*. Their count is 2*l* - *cnt*. I strongly recommend this [linear algebra tutorial](https://codeforces.com/https://www.youtube.com/watch?v=kjBOesZCoqc&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab) to understand the intuitions.

