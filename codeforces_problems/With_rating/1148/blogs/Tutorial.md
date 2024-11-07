# Tutorial


### [1148A - Another One Bites The Dust](../problems/A._Another_One_Bites_The_Dust.md "Codeforces Global Round 3")

The answer is $2 * c + min(a, b) + min(max(a, b), min(a, b) + 1)$. 

First, you can place all "ab" strings together. 

Then if there are more "a" strings than "b" strings, you can start adding in the end "a" and "b" strings one by one in an alternating order.

If there are more "b" strings than "a" strings, you can do the same thing but add to the begin of the string.

Author: [Egor.Lifar](https://codeforces.com/profile/Egor.Lifar "International Master Egor.Lifar") 

### [1148B - Born This Way](../problems/B._Born_This_Way.md "Codeforces Global Round 3")

If $k \geq n$, we can cancel all flights between A and B, and Arkady won't be able to get to C, so answer will be equal to $-1$. Otherwise, $k < n$.

If the subset of canceled flights is chosen, the Arkady's strategy is clear: use the earliest available flight from A to B, arrive to B at some time moment $t$ and choose the earliest not canceled flight from B to C with a departure time moment greater or equal than $t$.

Suppose we have chosen $x$ — a number of canceled flights between A and B. No matter what subset of flights will be cancelled between B and C, we should cancel the first $x$ flights from A to B. Now we know the exact moment of the Arkady's arrival to B — it is equal to $a_{x+1} + t_a$. Now our optimal strategy is to cancel the first $k-x$ flights between B and C, which Arkady can use. If there is no flights remaining, the answer is $-1$. Otherwise, Arkady will be in C at the $b_j + t_b$-th time moment, where $j$ is the index of the earliest flight, which Arkady can use. $j$ is equal to $pos + (k - x)$, where $pos$ is index of the first flight from B to C, which departure time moment is greater or equal than $a_{x+1} + t_a$.

Now we can just iterate through all possible $x$ and calculate the biggest time moment. Since array $b$ is sorted, you can find $pos$ using binary search. The complexity of this solution is $O(n \log n)$. Also the array of $a_{x + 1} + t_a$ values is sorted too, so you can use two-pointers method. This solution will work with $O(n)$ complexity.

 Author: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN") Tutorial is loading... Author: [Jatana](https://codeforces.com/profile/Jatana "Grandmaster Jatana") Tutorial is loading... Author: [Egor.Lifar](https://codeforces.com/profile/Egor.Lifar "International Master Egor.Lifar") 
### [1148E - Earth Wind and Fire](../problems/E._Earth_Wind_and_Fire.md "Codeforces Global Round 3")

Consider original and target position of stones in sorted order.

Note, that we can always construct an answer preserving the original stones order (suppose we have an answer which doesn't preserve the order. It will happen when there are two stones at the same spot, just move the other one).

So now we simplified our problem — we want to move stone $s_i$ into $t_i$. So we now can compute $\delta_i = t_i - s_i$ — the relative movement of each stone.

To begin with, observe that if $\sum \delta_i \ne 0$ there is no solution, since the operations we can use preserve the sum of the coordinates.

However this is not enough, for example if $\delta_1 < 0$ (you need to move to the left the leftmost stone), there is clearly no answer. The real condition is that elements $\delta_i$ should form a "balanced bracket sequence", that is, the sum of every prefix of $\delta_i$ must be $\ge 0$. In this and only in this case we can match corresponding right-movements with left-movements.

In order to construct the exact answer we can go from left to right maintaining the stack of not-yet-closed "move-to-the right actions", formally we will put on stack pairs (stone_index, steps_to_move). So when we see stone with $\delta_i > 0$ we put it on the stack, and when we see stone with $\delta_i < 0$ we match it with the stones on the stack, removing the elements from the stack if they have moved to the full extent.

 Author: [Jatana](https://codeforces.com/profile/Jatana "Grandmaster Jatana") Tutorial is loading... Author: [Egor.Lifar](https://codeforces.com/profile/Egor.Lifar "International Master Egor.Lifar") Tutorial is loading... Author: [Jatana](https://codeforces.com/profile/Jatana "Grandmaster Jatana") Tutorial is loading... Author: [Egor.Lifar](https://codeforces.com/profile/Egor.Lifar "International Master Egor.Lifar")