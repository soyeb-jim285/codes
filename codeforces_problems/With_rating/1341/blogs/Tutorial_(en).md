# Tutorial_(en)


### [1341A - Nastya and Rice](../problems/A._Nastya_and_Rice.md "Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!")

We can get any weight of all grains from $n(a - b)$ to $n(a + b)$, so we need to check that the segments $[n(a - b); n(a + b)]$ and $[c - d; c + d]$ intersect.

Idea: [I_love_myself](https://codeforces.com/profile/I_love_myself "Master I_love_myself")  
Solution: [77904333](https://codeforces.com/contest/1341/submission/77904333 "Submission 77904333 by I_love_myself") 

### [1341B - Nastya and Door](../problems/B._Nastya_and_Door.md "Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!")

Let's make an array consisting of 0 and 1, such that it shows whether the position i is a peak on the whole segment. To do this, we will go through the indices from 2 to n−1, and if the conditions ai−1<ai and ai>ai+1 are true, then we write 1 in a new array at position i. After that, we calculate the prefix sum in the new array pref. Now the number of peaks in the segment [l,l+k−1] is calculated as pref[l+k−2]−pref[l], so we find out how many peaks in the desired segment, not including the boundaries of the segment. It remains only to go through all l from 1 to n−k+1 and find the leftmost l, such that pref[l+k−2]−pref[l] as much as possible.

 Idea: [alexX512](https://codeforces.com/profile/alexX512 "Master alexX512")  
Solution: [77904408](https://codeforces.com/contest/1341/submission/77904408 "Submission 77904408 by I_love_myself") 
### [1341C - Nastya and Strange Generator](https://codeforces.com/contest/1341/problem/C "Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!")

Consider the initial moment of time. Note that the array is $ r = [1, 2, \ldots, n]$, $count = [1, 1, \ldots, 1] $. So the generator will choose a random position from the entire array – let it be the position $ i_1 $. In the next step, $r = [1, 2, \ldots i_1 + 1, i_1 + 1, i + 2, \ldots, n]$, $count = [1, 1, \ldots, 0, 2, 1, \ldots, 1] $. That is, now there is only one maximum and it is reached at the position $ i_1 + 1 $. Thus, we will fill in the entire suffix starting at position $ i_1 $: $ a = [\times, \ldots, \times, 1, \ldots, i_1] $. After this, this procedure will be repeated for some $i_2$ ($ 1 \leq i_2 < i_1 $) and the array will become $ a = [\times, \ldots, \times, i_1 + 1, \ldots, i_1 + i_2, 1, \ldots, i_1] $ . That is, we need to check that the array consists of several ascending sequences.

  
Idea: [Aleks5d](https://codeforces.com/profile/Aleks5d "Grandmaster Aleks5d")  
Solution: [77904455](https://codeforces.com/contest/1340/submission/77904455 "Submission 77904455 by I_love_myself") 
### [1341D - Nastya and Scoreboard](https://codeforces.com/contest/1341/problem/D "Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!")

Let $dp[i][j] = true$, if at the suffix $i \ldots n$ you can turn on exactly $j$ sticks and get the correct sequence of digits and $false$ otherwise. It is easy to recalculate this dynamics: we will make transitions to all possible digits (the mask at position $ i $ should be a submask of the digit).

Asymptotic calculate of the dynamics $O(10nd)$.

Now let's go in order from $1$ to $n$ and will try to eagerly set the maximum possible figure using our dynamics. It is easy to understand that in this way we get the maximum possible number of $n$ digits.

 Idea: [I_love_myself](https://codeforces.com/profile/I_love_myself "Master I_love_myself")  
Solution: [77770331](https://codeforces.com/contest/1340/submission/77770331 "Submission 77770331 by tourist") 
### [1341E - Nastya and Unexpected Guest](https://codeforces.com/contest/1341/problem/E "Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!")

Notice the fact: if we somehow came to safety island and time $i \bmod g$ ($\bmod$ - is a remainder after dividing $i$ by $g$), we don't need anymore to come to this island at time $j$ where $i<j$ and $i\bmod g = j\bmod g$, because this will form a cycle.

So that we can rephrase our task like this: we have some vertices, which are denoted as a pair $(i, t)$, $i$ - is island index, $t$ is a remainder after dividing the time we came to $i$ by $g$. So it will be enough to use only edges between vertices $(i, t) \to (i + 1, (t + a[i + 1] - a[i])\bmod g)$ and $(i, t)\to (i - 1, (t + a[i] - a[i - 1])\bmod g)$, because all remaining edges can be expressed through these ones. Now lets notice that edges, which make time $t + a > g$ can't be used due to restriction of walking on red. But vertices with $t + a = g$ are good for us. So we can say, that while green light is on, Denis can walk without restrictions, and when $t + a = g$ we add $g + r$ to time. So we can use $01$-BFS to solve this task and at the end check find vertex and position from which we can go to our final destination.

Time complexity will be $O(g * m)$.

 Idea: [Aleks5d](https://codeforces.com/profile/Aleks5d "Grandmaster Aleks5d")  
Solution: [77904646](https://codeforces.com/contest/1340/submission/77904646 "Submission 77904646 by I_love_myself") 
### [1341F - Nastya and Time Machine](https://codeforces.com/contest/1341/problem/F "Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!")

Lemma: The maximum time that Denis will visit will be at least $\max\limits_{v = 1}^{n} \deg v = T$

Proof: consider an arbitrary vertex $ v $. We will visit her $ \deg v - 1$ times when we will bypass all her neighbors and another $ 1 $ when we return to her ancestor. But we can't go to vertex at 0 time. So, we need $\deg v$ moments more than 0.

We construct a graph traversal with a maximum time equal to $T$. Let us now stand at $ v $ at a time $ t $ and $ v $ has an un visited son $ u $. We want to go to $ u $, go around its entire subtree and return to $ v $ at time $ t + 1 $. That is, the route will be something like this: $ (v, t) \to (u, t + 1) \to \ldots \to (u, t) \to (v, t + 1) $.

Let $ k = \deg u - 1 $, for $ w_i $ we denote the $ i $ th son of $ u $. If $ t + 1 \leq T - k $, then there are no problems, we will move back in time at the very end of the route: $(v, t)$ $\to$ $(u, t + 1)$ $\to$ $(w_1, t + 2)$ $\to$ $\ldots$ $\to$ $(u, t + 2)$ $\to$ $\ldots$ $\to$ $(w_k, t + k + 1)$ $\to$ $\ldots$ $\to$ $(u, t + k)$ $\to$ $(u, t)$ $\to$ $(v, t + 1)$.

Otherwise, you have to go back in time in the middle of the route (exactly when we get to T) so that after the last visit we will be in $ (v, t + 1) $, that is: $(v, t)$ $\to$ $(u, t + 1)$ $\to$ $(w_1, t + 2)$ $\to$ $\ldots$ $\to$ $(u, t + 2)$ $\to$ $\ldots$ $\to$ $(u, T)$ $\to$ $(u, t')$ $\to$ $\ldots$ $(w_k, t + k + 1)$ $\to$ $\ldots$ $\to$ $(u, t + k)$ $\to$ $(u, t)$ $\to$ $(v, t + 1)$ , where $ t'$ can be easily calculated by the number of not visited sons.

 Idea: [Aleks5d](https://codeforces.com/profile/Aleks5d "Grandmaster Aleks5d")  
Solution: [77904714](https://codeforces.com/contest/1340/submission/77904714 "Submission 77904714 by I_love_myself") 
### [1340E - Nastya and Bees](https://codeforces.com/contest/1340/problem/E "Codeforces Round 637 (Div. 1) - Thanks, Ivan Belonogov!")

*Tutorial is not available*

 It turned out that the author’s solution does not work correctly and so far no one, including participants, can prove that Nastya can be caught. [This](Tutorial_(en).md?#comment-610176) comments contain a lot of good thoughts. But if you can offer at least some solution to this problem, then I (and some participants) will be very happy! Tutorial is loading... Idea: [I_love_myself](https://codeforces.com/profile/I_love_myself "Master I_love_myself")  
Solution: [77904971](https://codeforces.com/contest/1340/submission/77904971 "Submission 77904971 by I_love_myself")  
Thanks to [Holidin](https://codeforces.com/profile/Holidin "Grandmaster Holidin") for help in preparing this problem.