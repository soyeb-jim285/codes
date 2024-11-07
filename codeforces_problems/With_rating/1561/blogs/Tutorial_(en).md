# Tutorial_(en)

Hope you enjoyed the round!

 
### [1561A - Простая странная сортировка](../problems/A._Simply_Strange_Sort.md "Codeforces Round 740 (Div. 2, основан на VK Cup 2021 - Финал (Engine))")

The described sorting algorithm is similar to [Odd-even sort](https://codeforces.com/https://en.wikipedia.org/wiki/Odd-even_sort).

In this problem, it's enough to carefully implement the process described in the problem statement. Here is one sample implementation in C++:


```cpp
#include <bits/stdc++.h>  
  
using namespace std;  
  
int main() {  
  int tt;  
  cin >> tt;  
  while (tt–) {  
    int n;  
    cin >> n;  
    vector<int> a(n);  
    for (int i = 0; i < n; i++) {  
      cin >> a[i];  
    }  
    int ans = 0;  
    while (!is_sorted(a.begin(), a.end())) {  
      for (int i = ans % 2; i + 1 < n; i += 2) {  
        if (a[i] > a[i + 1]) {  
          swap(a[i], a[i + 1]);  
        }  
      }  
      ans += 1;  
    }  
    cout << ans << endl;  
  }  
  return 0;  
}  

```
To estimate the complexity of this solution, we need to know the maximum number of iterations required to sort a permutation of length nn. It turns out that this number is equal to exactly nn, thus the complexity of the algorithm is O(n2)O(n2). This is intuitive because the algorithm looks similar to bubble sort that requires nn iterations too, or you can directly check that sorting [n,n−1,…,1][n,n−1,…,1] requires nn iterations and reason that "more sorted" sequences can't require more iterations than "less sorted" sequences, and [n,n−1,…,1][n,n−1,…,1] is naturally the "least sorted" sequence of them all. For a formal proof see e.g. the linked [Wikipedia page](https://codeforces.com/https://en.wikipedia.org/wiki/Odd-even_sort). The proof also follows from the editorial of problem F in Div. 1. If you have a simpler proof, please share in comments!

 
### [1558A - Очарованные игрой](https://codeforces.com/contest/1558/problem/A "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

First of all, we don't know who served first, but there are only two options, so let's just try both and unite the sets of kk's we get.

Assume that Alice served first. Exactly a+ba+b games were played. If a+ba+b is even, both players served exactly a+b2a+b2 times, and if a+ba+b is odd, Alice served one more time than Borys.

The simplest way to consider both cases is to say that Alice served p=⌈a+b2⌉p=⌈a+b2⌉ times, and Borys served q=⌊a+b2⌋q=⌊a+b2⌋ times (⌈t⌉⌈t⌉ denotes rounding up, and ⌊t⌋⌊t⌋ denotes rounding down).

Let xx be the number of times Borys broke Alice's serve (0≤x≤p0≤x≤p), and let yy be the number of times Alice broke Borys' serve (0≤y≤q0≤y≤q).

In this case, the number of games Alice won is a=(p−x)+ya=(p−x)+y, and the number of games Borys won is b=x+(q−y)b=x+(q−y).

We know neither xx nor yy, but let's loop over x=0…px=0…p. From a=(p−x)+ya=(p−x)+y, we can calculate y=a−(p−x)y=a−(p−x). If 0≤y≤q0≤y≤q, the values of xx and yy represent a valid scenario of the match with exactly x+yx+y breaks in total.

The case when Borys served first is handled similarly.

Analyzing the formulas further, we can find a "closed-form" solution: 

* Let d=⌊|a−b|2⌋d=⌊|a−b|2⌋.
* If a+ba+b is even, all possible values of kk are d,d+2,d+4,…,a+b−dd,d+2,d+4,…,a+b−d.
* If a+ba+b is odd, all possible values of kk are d,d+1,d+2,…,a+b−dd,d+1,d+2,…,a+b−d.
 
### [1561C - Самый нижний уровень](../problems/C._Deep_Down_Below.md "Codeforces Round 740 (Div. 2, основан на VK Cup 2021 - Финал (Engine))")

Consider a single cave ii. Suppose that the hero enters the cave with power xx. To beat the first monster, xx has to be greater than ai,1ai,1. After that, the hero's power will increase to x+1x+1, and to beat the second monster, x+1x+1 has to be greater than ai,2ai,2. Continuing this reasoning, we can write down kiki inequalities: 

* x>ai,1x>ai,1;
* x+1>ai,2x+1>ai,2;
* x+2>ai,3x+2>ai,3;
* ...
* x+(ki−1)>ai,kix+(ki−1)>ai,ki.

Let bi=max(ai,1,ai,2−1,ai,3−2,…,ai,ki−(ki−1))bi=max(ai,1,ai,2−1,ai,3−2,…,ai,ki−(ki−1)). The system of inequalities above is equivalent to a single inequality: x>bix>bi.

Thus, the hero can enter cave ii with power xx if and only if x>bix>bi, and the hero's power will increase by kiki.

Armed with this knowledge, can we determine the best order to visit the caves for the hero?

It turns out it's always best to enter the caves in non-decreasing order of bibi. Indeed, if the hero can enter cave ii, he should always do that because entering a cave never makes things worse. If the hero enters a cave with greater bb right before a cave with smaller bb, he might enter these caves in reverse order as well.

Let's sort the caves accordingly and assume b1≤b2≤…≤bnb1≤b2≤…≤bn. What is the smallest power the hero can start the level with?

We can use the same reasoning that we used for a single cave.

Suppose the hero starts the level with power xx. To enter the first cave, xx has to be greater than b1b1. After that, the hero's power will increase to x+k1x+k1, and to enter the second cave, x+k1x+k1 has to be greater than b2b2. Continuing this reasoning, we can write down nn inequalities: 

* x>b1x>b1;
* x+k1>b2x+k1>b2;
* x+k1+k2>b3x+k1+k2>b3;
* ...
* x+n−1∑i=1ki>bnx+∑i=1n−1ki>bn.

Let p=max(b1,b2−k1,b3−(k1+k2),…,bn−n−1∑i=1ki)p=max(b1,b2−k1,b3−(k1+k2),…,bn−∑i=1n−1ki). The system of inequalities above is equivalent to a single inequality: x>px>p. Thus, the answer to the problem is p+1p+1.

Alternatively, instead of solving the inequalities, one can use binary search on xx.

 
### [1558B - Верхняя ячейка](https://codeforces.com/contest/1558/problem/B "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

This problem was inspired by [Blogewoosh #4](https://codeforces.com/blog/entry/61501) a long time ago (Blogewoosh #8 when?).

Pretty clearly, we are facing a dynamic programming problem. Let f(x)f(x) be the number of ways to move from cell xx to cell 11. Then, f(1)=1f(1)=1, f(x)=x−1∑y=1f(x−y)+x∑z=2f(⌊xz⌋)f(x)=∑y=1x−1f(x−y)+∑z=2xf(⌊xz⌋), and f(n)f(n) is the answer to the problem. However, a straightforward implementation has O(n2)O(n2) time complexity and is too slow.

Let's look at the main formula for f(x)f(x) again: f(x)=x−1∑y=1f(x−y)+x∑z=2f(⌊xz⌋)f(x)=∑y=1x−1f(x−y)+∑z=2xf(⌊xz⌋).

The first sum, x−1∑y=1f(x−y)∑y=1x−1f(x−y), is easy to optimize: just maintain the sum of f1…fx−1f1…fx−1 and recalculate it by adding f(x)f(x). This takes just O(1)O(1) time per cell.

For the second sum, x∑z=2f(⌊xz⌋)∑z=2xf(⌊xz⌋), note that ⌊xz⌋⌊xz⌋ can take at most O(√x)O(x−−√) different values over z∈[2;x]z∈[2;x]. We can handle this sum as follows: 

* Find the sum over all z<√xz<x−−√ directly.
* We only need to consider z≥√xz≥x−−√ now. For any such value, ⌊xz⌋≤√x⌊xz⌋≤x−−√. Let's loop over a cell c≤√xc≤x−−√, for how many different values of zz it's true that c=⌊xz⌋c=⌊xz⌋? By definition of the floor function, c≤xz<c+1c≤xz<c+1. Solving this inequality, we get z∈[⌊xc+1⌋+1;⌊xc⌋]z∈[⌊xc+1⌋+1;⌊xc⌋]. The length of this segment gives us the coefficient of f(c)f(c) in the sum.

This gives us an O(n√n)O(nn−−√) solution which is enough for the subtask in Division 2.

To get a faster solution, let S(x)S(x) denote the multiset of cells where we can go to from cell xx (this multiset contains 2x−22x−2 values). How is S(x+1)S(x+1) different from S(x)S(x)? 

* S(x+1)S(x+1) contains an extra occurrence of xx because we can subtract 11 from x+1x+1.
* S(x+1)S(x+1) contains an extra occurrence of 11 because we can divide x+1x+1 by x+1x+1.
* For each i>1i>1 that is a divisor of x+1x+1, S(x+1)S(x+1) contains an occurrence of ii that replaces an occurrence of i−1i−1.

We don't need to maintain S(x)S(x) itself, but we can maintain the sum of f(i)f(i) over all i∈S(x)i∈S(x) and recalculate this sum as we go from xx to x+1x+1. The total number of changes to SS is limited by the total number of divisors of all numbers from 11 to nn, that is, n1+n2+…+nn=O(nlogn)n1+n2+…+nn=O(nlogn).

However, if implemented directly, we need to quickly find the divisors of each xx, and we can only afford O(n)O(n) memory due to the memory limit. We can achieve that by preparing a sieve of Eratosthenes, factorizing xx and generating all its divisors.

A better way is do it the reverse way: once we find f(c)f(c) for some cc, let's traverse x=2c,3c,…x=2c,3c,… and add f(c)−f(c−1)f(c)−f(c−1) to f(x)f(x). This way the time complexity stays O(nlogn)O(nlogn) and the memory complexity is O(n)O(n).

 
### [1558C - Прелестные перевороты](https://codeforces.com/contest/1558/problem/C "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

First of all, consider what happens when we reverse a prefix of odd length pp. Elements ap+1ap+1 to anan don't move at all, and for each ii from 11 to pp, aiai moves to ap−i+1ap−i+1. Note that ii and p−i+1p−i+1 have the same parity: therefore, no element can ever change the parity of its position. In the final sorted permutation, we need to have ai=iai=i for all ii: that is, the parity of each element's position must match the parity of its value.

This leads to the following necessary condition: for each i∈[1,n]i∈[1,n], aimod2=imod2aimod2=imod2. If for any ii this doesn't hold, the permutation can not be sorted.

It turns out this condition is also sufficient.

Let's devise a procedure to sort a permutation of odd length nn. If an=nan=n and an−1=n−1an−1=n−1, we don't have to touch an−1an−1 and anan ever again, and we can proceed to sorting a permutation of length n−2n−2. Can we actually move nn and n−1n−1 to their final positions with a simple sequence of steps?

Indeed we can. Here is one way to do this in exactly 55 steps: 

* Let ax=nax=n (note that xx is odd). Reverse a prefix of length xx to move nn to position 11.
* Let ay=n−1ay=n−1 (note that yy is even). Reverse a prefix of length y−1y−1 to move nn to position y−1y−1.
* Reverse a prefix of length y+1y+1 to move n−1n−1 to position 22 and nn to position 33.
* Reverse a prefix of length 33 to move nn to position 11 (n−1n−1 stays at position 22).
* Reverse a prefix of length nn to move nn to position nn and n−1n−1 to position n−1n−1, as desired.

We can use this procedure n−12n−12 times to first move nn and n−1n−1 to their final positions, then n−2n−2 and n−3n−3, and so on. This solution requires exactly 5(n−1)25(n−1)2 steps.

 
### [1558D - Истинные вставки](https://codeforces.com/contest/1558/problem/D "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

First of all, note that the sequence of insertions uniquely determines where each element goes. For example, for n=5n=5 and a sequence of insertions (3,1),(4,1),(5,3)(3,1),(4,1),(5,3), the initial sequence [a1,a2,a3,a4,a5][a1,a2,a3,a4,a5] is always transformed into [a4,a3,a5,a1,a2][a4,a3,a5,a1,a2], no matter what aiai are. Thus, instead of counting the initial sequences, we might count the final sequences instead.

Let the final sequence be [b1,b2,…,bn][b1,b2,…,bn]. From its sortedness, we know that bi≤bi+1bi≤bi+1 for every i∈[1;n−1]i∈[1;n−1].

Consider a single iteration ii of the sorting algorithm. If ai≥ai−1ai≥ai−1, no insertion occurs. This actually doesn't give us any extra information: we know that aiai is placed later than ai−1ai−1 in the final sequence anyway.

What happens though if aiai is inserted into position jj?

We know that ai<ajai<aj and also, since jj is the smallest index with such property, ai≥aj−1ai≥aj−1. Again, a non-strict inequality doesn't give us anything. However, knowing that ai<ajai<aj is actually important.

It turns out that we are interested in elements aiai such that we have ever inserted an element right before aiai during sorting. For every such element, we know that the previous element in the sorted order is strictly smaller. All other pairs of neighboring elements can either be equal, or the earlier one can be smaller.

All in all, let cc be the number of indices i∈[1;n−1]i∈[1;n−1] such that bi<bi+1bi<bi+1 (for all the other values of ii, bi≤bi+1bi≤bi+1). How many different sequences bb with integers from 11 to nn satisfy this? This number can be shown to be equal to (2n−1−cn)(2n−1−cn).

(The proof can go as follows: for each ii such that bi≤bi+1bi≤bi+1, increase each of bi+1,bi+2,…,bnbi+1,bi+2,…,bn by 11. Now for every ii we have bi<bi+1bi<bi+1, and the maximum possible value of an element increased to n+(n−1−c)n+(n−1−c). Thus, we have built a bijection from the sequences we are searching for to the sequences of nn distinct numbers between 11 and n+(n−1−c)n+(n−1−c). The number of the latter sequences is clearly (2n−1−cn)(2n−1−cn).)

How to find cc? It can be done by going through the insertions and maintaining a balanced binary search tree of your choice. However, implementation becomes simpler if we process the insertions in reverse order.

Let's maintain a set SS of positions in the final sorted order that are not yet filled in. Initially, the set contains all integers from 11 to nn. For each insertion (xi,yi)(xi,yi) (in reverse order), let pp be the yiyi-th smallest element of SS, and let qq be the (yi+1)(yi+1)-th smallest element of SS. Since we insert pp before qq, mark position qq as "a position such that we have ever inserted an element right before it" (which is important for calculating cc). Then, erase pp from the set.

As a data structure that can handle finding the kk-th smallest element, we can use a balanced binary search tree, a segment tree, or binary search over Fenwick tree (in C++ we can also use a built-in policy-based data structure).

Finally, to solve each test case in O(mlogn)O(mlogn) and not O(nlogn)O(nlogn), we can have a single data structure instance for solving all test cases, and roll back any changes we apply while solving each test case.

 
### [1558E - Нижний уровень](https://codeforces.com/contest/1558/problem/E "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

Let's find the smallest possible initial power with binary search. Suppose the initial power is pp.

The main idea behind the solution is to maintain a set of caves where we have beaten all the monsters, and try to extend the set by finding "augmenting" paths.

However, we can not just go in an arbitrary unvisited cave and pretend we add it to the set: since we are not allowed to turn back, it might happen that we can not move forward anymore because we don't have enough power. It's important that we must be able to reach any cave inside the set only going through caves belonging to the set itself.

Initially, the set contains just cave 11.

What can an augmenting path look like? 

* The path can start somewhere inside the set, go out of the set, follow a simple route visiting some new caves (and beating monsters inside them), and go back to a cave belonging to the set. For example, if caves 11 and 22 belong to the set, the route can look like 1→3→4→5→21→3→4→5→2, and we can add caves 33, 44, and 55 to the set.
* Alternatively, instead of going back to a cave from the set, the path might go into a cave belonging to the route. For example, if caves 11 and 22 belong to the set, the route can look like 1→3→4→5→6→41→3→4→5→6→4, and we can add caves 33, 44, 55, and 66 to the set.

How do we find any augmenting path satisfying us?

It turns out that we can use the following property. Suppose we have a path v→u1→u2→…→uk→xv→u1→u2→…→uk→x (where vv is the only cave belonging to the set) that we can follow and beat all the monsters in the caves we visit. Suppose that we have another such path v′→u′1→u′2→…→u′k′→x. Suppose that following the former path, we arrive at x with the same or higher power than following the latter path. In this case, notice that 

 v→u1→u2→…→uk→x→u′k′→…→u′1→v′  is actually a valid augmenting path!Thus, we can simply use BFS or DFS to find all reachable caves. Once we find a path leading back into the set, or we find two different paths leading into the same unvisited cave, we can build an augmenting path, extend the set, and start over, until the set contains all caves (in which case we can try to decrease the initial power level p) or until we can not find any augmenting path (in which case we must increase p).

At each binary search iteration, we can have at most n augmenting paths and we find each of them in O(m). Thus, the time complexity of the solution is O(nmlogamax).

 
### [1558F - Странная сортировка](https://codeforces.com/contest/1558/problem/F "Codeforces Round 740 (Div. 1, основан на VK Cup 2021 - Финал (Engine))")

Let's draw a wall of n towers of cubes, with the i-th tower having height ai. For example, for a=[4,5,7,1,3,2,6] the picture will look as follows (1 stands for a cube): 


```cpp
0010000  
0010001  
0110001  
1110001  
1110101  
1110111  
1111111  

```
 When two elements get swapped, their corresponding towers get swapped as well.Note that applying f(i) to the permutation (swapping ai and ai+1 if ai>ai+1) is equivalent to applying f(i) to each row of the above matrix independently (swapping cells i and i+1 if the i-th cell is 1 and the i+1-th cell is 0). 

Also note that in the final state, when the permutation is [1,2,…,n], each row of the matrix is sorted in non-descending order too (0's go before 1's), and vice versa — if each row is sorted, the permutation is sorted as well.

Thus, it's enough to find the number of iterations required to sort each row of the matrix, and the maximum of these numbers is the answer for the given permutation.

The rows of the matrix are bi=[ai≥x] for x=1,2,…,n.

How to solve the problem for a sequence of 0's and 1's?

We can assume that the instances of 0's don't change their relative order, and the same for 1's. Let the positions of zeros in the initial sequence be 1≤p1<p2<…<pm≤n. The i-th zero from the left is moving towards position i in the sorted sequence.

Let s(i) be the number of steps it takes the i-th zero from the left to get to its final position i.

If the i-th zero is already in position i, then s(i)=0.

Otherwise, if i>1, note that s(i)≥s(i−1)+1, because the i-th zero can only get to position i after the (i−1)-th zero gets to position i−1.

Moreover, let there be ki ones to the left of the i-th zero in the initial sequence. Then s(i)≥ki+(pimod2), because the 0 has to swap with every 1 to the left of it, and also the first iteration is useless if pi is odd.

It turns out that s(i)=max(s(i−1)+1,ki+(pimod2)) — the i-th zero either gets stuck into the (i−1)-th zero (and then si=s(i−1)+1), or consistently swaps with 1's on each iteration except for maybe the first (in which case si=ki+(pimod2)).

We are interested in s(m). Let the number of 0's at the start of the initial sequence be t. It can be seen that s(m)=mmaxi=t+1(ki+(pimod2)+(m−i)), and this is exactly the number of iterations required.

Recall that we need to find the number of iterations for n different binary sequences. However, these binary sequences are very similar to each other.

Let's maintain the values of (ki+(pimod2)+(m−i)) for all zeros in a segment tree (and, say, −∞ for positions containing ones). Start with the sequence bi=[ai≥x] for x=1 — that is, a sequence of all ones. As we increase x by one, a single 1 in b gets replaced with 0. We can handle these changes using a segment tree with "range add" and "range max". The time complexity of the solution is O(nlogn).

(Another equivalent formula is: s(m)=rmaxi=lc1([b1,b2,…,bi])+c0([bi+1,…,bn])+(imod2)−1. Here cx(seq) is the number of x's in seq; l is the smallest position such that c1([b1,b2,…,bl])>0; and r is the largest position such that c0([br+1,…,bn])>0. This formula can also be proven using induction. In short, consider this formula applied to the number of remaining iterations — the difference is that instead of (imod2), we sometimes have 1−(imod2), depending on the parity of the current iteration number. Consider all positions i where the value is maximized. Then it can be shown that after one iteration the value for all such positions decreases by 1: if the parity is incorrect, after one iteration the parity becomes correct; otherwise, observe that bi=1 and bi+1=0, which get swapped in the next iteration. Moreover, the value for all other positions has the same parity, increases by at most 1, and thus doesn't become too big either.)

