# Tutorial


### [1031A - Golden Plate](../problems/A._Golden_Plate.md "Technocup 2019 - Elimination Round 2")

The number of gilded cells in the first (outer) ring is the number of border cells, that is, $2(w + h) - 4$, in the second ring — the number of border cells of the center rectangle with side lengths 4 less, that is, $2(w - 4 + h - 4) - 4$, and so on. This sum can be calculated in a single loop.

 
### [1031B - Curiosity Has No Limits](../problems/B._Curiosity_Has_No_Limits.md "Technocup 2019 - Elimination Round 2")

Let's solve the problem for $0 \leq a_i, b_i, t_i \leq 1$, that is, for binary sequences. There are two options for $t_1$, the remaining part can be determined one number by one after this:

* If $t_1 = 0$ and $a_1 = 0$ and $b_1 = 0$ then $t_2$ = 0;
* If $t_1 = 0$ and $a_1 = 0$ and $b_1 = 1$ then there is no such $t_2$.
* If $t_1 = 0$ and $a_1 = 1$ and $b_1 = 0$ then $t_2$ = 1;
* If $t_1 = 0$ and $a_1 = 1$ and $b_1 = 1$ then $t_2$ = 1;
* If $t_1 = 1$ and $a_1 = 0$ and $b_1 = 0$ then there is no such $t_2$.
* If $t_1 = 1$ and $a_1 = 0$ and $b_1 = 1$ then there is no such $t_2$.
* If $t_1 = 1$ and $a_1 = 1$ and $b_1 = 0$ then $t_2$ = 0;
* If $t_1 = 1$ and $a_1 = 1$ and $b_1 = 1$ then $t_2$ = 1;

One can similarly find all other $t_i$-s ($3 \leq i \leq n$) or get a contradiction.

For bitwise operations from the statement one can solve the problem independently for every bit and restore the original sequence $t_1, t_2, \ldots, t_n$.

 Tutorial is loading... Tutorial is loading... 
### [1031E - Triple Flips](../problems/E._Triple_Flips.md "Technocup 2019 - Elimination Round 2")

This problem has a lot of solutions including those ones which are difficult to prove. Let's describe one of the author's solutions.

We can find answer with bruteforce if size of array is rather small. For example we can check all combinations of arithmetic progressions with length equals to three.

We can find by hand or bruteforce that for $3 \le n \le 7$ arrays with no solution exists but for $n = 8$ (and consequently for $n \ge 8$) we always can make all elements be equal to zero.

We want solution with such steps: 

1. If $n$ is small just run bruteforce
2. Else try to make all elements besides the first $k$ ($k \ge 8$) be equal to zero
3. Run bruteforce on the first $k$ elements.

How to make the second step? Let's try to make three last elements of array be equal to zero with only one operation. We can use previous elements. So if we have array $\dots, 0, 0, 1$ we can change values of the first, the fourth and the seventh elements from the end. But $\dots, 0, 1, 1$ is counter-example.

Ok, let's try to make six last elements of array be equal to zero with two operations. We can check by hand or bruteforce that it can be done and $n \ge 11$ is enough.

So we have such solution:

1. Let $k$ is the number of first elements of array which we didn't try to make be equal to zero. In the start $k = n$
2. While $k \ge 11$ make $k$-th, $(k - 1)$-th,.., $(k - 5)$-th elements be equal to zero. Subtract 6 from $k$.
3. If $k \le 10$ run bruteforce on the first $10$ elements or on the whole array if $n < 10$.

How many operations will be done? 

* In the second item the number of operations is less or equal than $2 \cdot \lfloor \frac{n}{6} \rfloor \le \lfloor \frac{n}{3} \rfloor$
* In the third item the number of operations is less or equal than 6 (can be checked by hand or bruteforce)
* So the total number of operations is less or equal than $\lfloor \frac{n}{3} \rfloor + 6$, what is good enough.
 Tutorial is loading... Tutorial is loading...