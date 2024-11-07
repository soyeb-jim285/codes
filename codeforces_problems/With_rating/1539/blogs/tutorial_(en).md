# tutorial_(en)

Thanks for the participation!

[1539A - Contest Start](../problems/A._Contest_Start.md "Codeforces Round 727 (Div. 2)") was authored and prepared by [grphil](https://codeforces.com/profile/grphil "Master grphil")

[1539B - Love Song](../problems/B._Love_Song.md "Codeforces Round 727 (Div. 2)") was authored by jury and prepared by [talant](https://codeforces.com/profile/talant "Grandmaster talant")

[1539C - Stable Groups](../problems/C._Stable_Groups.md "Codeforces Round 727 (Div. 2)") was authored by [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123") and prepared by [Artyom123](https://codeforces.com/profile/Artyom123 "International Master Artyom123") and [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")

[1539D - PriceFixed](../problems/D._PriceFixed.md "Codeforces Round 727 (Div. 2)") was authored by Helen Andreeva and prepared by [Siberian](https://codeforces.com/profile/Siberian "Grandmaster Siberian")

[1539E - Game with Cards](../problems/E._Game_with_Cards.md "Codeforces Round 727 (Div. 2)") was authored and prepared by [TeaTime](https://codeforces.com/profile/TeaTime "Master TeaTime")

[1539F - Strange Array](../problems/F._Strange_Array.md "Codeforces Round 727 (Div. 2)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

 
### [1539A - Contest Start](../problems/A._Contest_Start.md "Codeforces Round 727 (Div. 2)")

Let's find which participants will disturb participant $i$. Those are participants with number between $i + 1$ and $i + min(t / x, n)$. So each of first $max(0, n - t / x)$ participants will get $t / x$ dissatisfaction, and each next participant will get 1 dissatisfaction less, than previous. So the total answer is $max(0, n - t / x) \cdot t / x + min(n - 1, t / x - 1) \cdot min(n, t / x) / 2$.

 
### [1539B - Love Song](../problems/B._Love_Song.md "Codeforces Round 727 (Div. 2)")

One can notice that letter with number $x$ will add exactly $x$ to the answer. So, all we have to do is calculate the sum of numbers of letters in our substring. This can be done using prefix sums.

 
### [1539C - Stable Groups](../problems/C._Stable_Groups.md "Codeforces Round 727 (Div. 2)")

Firstly, we will find the amount of groups needed if we don't add any new students. Let's consider the students in the increasing order of their knowledge level. Students are greedily determined to the same group if the difference of their knowledge levels is not greater than $x$. Else we create another group. After that all students will be split into continuous non-intersecting segments  — stable groups.

Merging two segments with knowledge difference $d$ may be done by adding $\lceil\frac{d}{x}\rceil - 1$ new students. Each such merge decreases the answer by $1$ so we should maximize the amount of merges. To do that we should just consider the merges in increasing order of their costs.

 
### [1539D - PriceFixed](../problems/D._PriceFixed.md "Codeforces Round 727 (Div. 2)")

Let $m$ be the sum of all $a_i$

Important greedy observations: 

1. If there is an item which costs 1, then we will not make the answer worse by buying this item.
2. If all prices are 2, then we will not make the answer worse by buying the item with max $b_i$.

Therefore we can sort all items by $b_i$ and on each iteration we will only need to consider two items: with max $b_i$ and with min $b_i$ among us all not bought items.

Another important observation: We already know how many items with price 2 we should buy to be able to buy something with a discount. This means that we can buy multiple items with full price together. Similarly, we can buy multiple items with a discount at once. This solution can be implemented using a two pointers technique which allows to find the answer in $O(n \cdot \log{n})$.

 
### [1539E - Game with Cards](../problems/E._Game_with_Cards.md "Codeforces Round 727 (Div. 2)")

Let's use dynamic programming to solve the problem. $dp_L[i]$ is equal to 1 if we can correcly answer queries on suffix the way that $i$-th card is taken in left hand and $i+1$-th card is taken in right hand. $dp_R[i]$ is equal to 1 if we can correcly answer queries on suffix the way that $i$-th card is taken in right hand and $i+1$-th card is taken in left hand. Let's consider transitions to count $dp_L$. Let's suppose we have $j$ such that $dp_R[j] = 1$.

Then we can tell that $dp_L[i] = 1$, if these 2 conditions hold:

* We can take all cards with indexes $[i + 1, j]$ in right hand.
* Card in query $i$ fits constraints on value written on card in left hand in queries with indexes $[i, j]$.

 This way we got solution which works in $O(n ^ 2)$. Let's notice that if there exists $j$, that $dp_R[j] = 1$ then its optimal to consider such smallest $j$ because it has less strict constraints. We will use the same approach to count values of $dp_R$. This way we get soluton which uses $O(n)$ time and memory. 
### [1539F - Strange Array](../problems/F._Strange_Array.md "Codeforces Round 727 (Div. 2)")

Note that the distance from the given element to the median element (the center of a sorted segment) can be defined in terms of numbers of elements that are less, equal or bigger than the given element. Let $cnt_L$ be the number of elements that are less, $cnt_M$ — equal (excluding the given) and $cnt_R$ — bigger than the given element.

Then the distance may be calculated in the following way: 

* If $a_i$ is bigger than the median element: $ans = \lfloor \frac{cnt_L + cnt_M - cnt_R}{2}\rfloor$
* otherwise $ans = \lfloor \frac{cnt_R + cnt_M - cnt_L + 1}{2}\rfloor$

To solve the problem you firstly need to assume that the given element is greater than the median element, then consider the other case and take the maximum of two answers. Hereinafter only the second case is considered (in which the element is not greater than the median one), the first case can be done analogically.

Since we need to maximize $cnt_R + cnt_M - cnt_L$, let's do it separately for the elements to the left and to the right of ours.

Let's sort the indices so that the corresponding elements go in increasing order.

Let array $D = [1, 1 \ldots, 1]$ (its size is $n$) and $P = [1, 2, \ldots n]$. We will need operations "+= on the segment" and "min/max on the segment", so let's build a segment tree for $P$. 

We will iterate through the indices in the received order and when considering the index $i$ we'll change $D$ and $P$ so that they correspond to the following conditions: 

* For each $1 \le j \le n$ if $a_j < a_i$ then $D_j = -1$, else $D_j = 1$
* Array $P$ is a prefix sum array for $D$ (changes to $P$ are made via a segment tree)

In order to find $\max(cnt_R + cnt_M - cnt_L)$ among elements to the left of $i$ we need to find $\min\limits_{j=1}^{i} P_j$.

In order to find $\max(cnt_R + cnt_M - cnt_L)$ among elements to the right of i will find $\max \limits_{j=i}^{n} P_j$.

We will find these values using the segment tree for $P$ and consider the next index.

Note that for all the changes we will need only $n$ actions, because in array $D$ each element is firstly equal to 1, and then once becomes -1 and never changes again.

The described solution's time complexity is $O(n \cdot \log(n))$

