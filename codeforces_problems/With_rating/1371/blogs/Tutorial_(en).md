# Tutorial_(en)


### [1371A - Magical Sticks](../problems/A._Magical_Sticks.md "Codeforces Round 654 (Div. 2)")

Output $\lceil \frac{n}{2} \rceil$.

* When $n$ is even, we can create $1+n = 2+(n-1) = 3+(n-2) = ...$
* When $n$ is odd, we can create $n = 1+(n-1) = 2+(n-2) = ...$

Initially, there are only $1$ stick which has length $i (1 \le i \le n)$. If we connect $2$ sticks $s_1$ and $s_2$, after that, there is a stick which has a different length from $s_1$ and $s_2$. Then, we can create at most $1 + \lfloor \frac{n-1}{2} \rfloor$ sticks that have the same length. The value is equal to $\lceil \frac{n}{2} \rceil$.

Total complexity: $O(1)$

Jury solution: [85699387](https://codeforces.com/contest/1371/submission/85699387 "Submission 85699387 by physics0523") 

### [1371B - Magical Calendar](../problems/B._Magical_Calendar.md "Codeforces Round 654 (Div. 2)")

First, let's consider in case of a week has exactly $w$ days.

* If $w<n$ , the length of painted cells is strictly more than one week. So there are $w$ valid shapes. (The first week contains $1,2,...,w$ days) The shapes have $w$-day width, then if the value of $w$ are different, the shapes are also different.
* Otherwise $(n \le w)$ , there is only one valid liner pattern. The shape is insensitive to the chosen value of $w$.

We can sum up this for $1 \le w \le r$, by using following well-known formula: $a+(a+1)+(a+2)+...+b = \frac{(a+b)*(b-a+1)}{2}$

Total complexity : $O(1)$

 Jury solution: [85699884](https://codeforces.com/contest/1371/submission/85699884 "Submission 85699884 by physics0523") 
### [1371C - A Cookie for You](../problems/C._A_Cookie_for_You.md "Codeforces Round 654 (Div. 2)")

If $m < \min (a,b) , n+m \le a+b$ are satisfied, the answer is "Yes". Otherwise, the answer is "No". Let's proof it.

Of course, $n+m \le a+b$ must be satisfied, because violating this inequality means lack of cookies.

When a type $2$ guest comes, or when $a=b$, the value of $\min(a,b)$ is decremented by $1$. 

You need to consider only about the case that all type $2$ guests come first and after that all type $1$ guests come, because if there is a type $1$ guest before a type $2$ guest, swapping them is better to make no one angry. (Because if there is a type $1$ guest before a type $2$ guest, the type $1$ guest have a possibility to decrease the value of $min(a,b)$ unnecessarily.)

At last, all of type $1$ guests eat one cookie when there is at least one cookie(both types are ok).

Total complexity: $O(1)$

 Jury solution: [85699939](https://codeforces.com/contest/1371/submission/85699939 "Submission 85699939 by physics0523")UPD: m<min(a,b) is wrong, the right text is m≤min(a,b) 

### [1371D - Grid-00100](../problems/D._Grid-00100.md "Codeforces Round 654 (Div. 2)")

We can construct a grid $A$ which has $f(A)=0$ if $k\%n=0$ , $f(A)=2(1^2+1^2)$ otherwise (the values are smallest almost obviously.) in following method:

First, initialize $A_{i,j}=0$ for all $i,j$. Then, change a $0$ into $1$ $k$ times by using following pseudo code:

 let p=0 , q=0

     for i = 1..k

         Change A[p+1][q+1] into 1

         let p=(p+1) , q=(q+1)%n

         if(p==n)

             let p=0 , q=(q+1)%n

 Total complexity : $O(n^2)$

 Jury solution: [85700178](https://codeforces.com/contest/1371/submission/85700178 "Submission 85700178 by physics0523") 
### [1371E1 - Asterism (Easy Version)](../problems/E1._Asterism_(Easy_Version).md "Codeforces Round 654 (Div. 2)")

Let's define $m = max(a_1,a_2,...,a_n)$.

Yuzu should have at least $m-n+1$ candies initially to win all duels, then $f(x)=0$ for $x < m-n+1$. This is divisible by $p$.

And if Yuzu have equal or more than $m$ candies initially, any permutation will be valid, then $f(x)=n!$ for $x \ge m$. This is divisible by $p$ , too. (because $p \le n$)

Then, in this subtask, you should find whether each $f(x)$ are divisible by $p$ for $m-n+1 \le x < m$ in $O(n)$.

You can find the value of $f(x)$ by following simulation:

* First, let $v$={the number of enemies they have strictly less than $x$ candies}, $ans=1$.
* Then do the following steps for $i=x,x+1,...,x+(n-1)$.
* $v = v$ + {the number of enemies they have exactly $i$ candies}
* $ans = ans * v$
* $v = v - 1$

Now, $p$ is a prime. Then, "Whether $f(x)$ is divisible by $p$" is "Whether $p$ was multiplied to $ans$ as $v$ at least once."

This can be simulated in $O(n)$ time for each $x$.

Total complexity : $O(n^2)$

 Jury solution: [85700334](https://codeforces.com/contest/1371/submission/85700334 "Submission 85700334 by physics0523") 
### [1371E2 - Asterism (Hard Version)](../problems/E2._Asterism_(Hard_Version).md "Codeforces Round 654 (Div. 2)")

There are two different solutions to solve this problem.

Solution 1:

First, find the minimum $s$ which has $f(s) > 0$. You can use binary search or cumulative sum for it.

Now, we can say the answers form a segment $[s,t]$ (or there are no answers). Find $t$ and proof this.

Let's define $b_i$ as the number of the enemies who has equal or less than $i$ candies.

Then, observe the value $C_i(x) = b_{x+i}-i \ (0 \le i \le N-1)$ :

* $f(x) = \prod_{i=0}^{N-1} C_i(x)$
* once the value $C_i(x)$ exceed $p$ , $f(x)$ is divisible by $p$ because $C(x)$ is decremented by (at most) 1 in one step and contains some $C_i(x) = p$ in this $x$.
* $C_i(x) \le C_i(x+1)$ are always satisfied.
* Then, once $f(x)$ is divisible by $p$ , $f(x+\alpha)$ is also divisible by $p$, so $t$ can be find by using binary search.
* We can find $t$ without binary search by the following method:1. let $i \leftarrow 0, t \leftarrow max(A)$ 

2. if($C_i(t)<p$){i++;}else{t–;}

3. Repeat the step 2. And when become $i=N$ and the algorithm stops, $t$ is the maximum value which we want.

Solution 2:

We can say that $f(x) = \prod\limits_{i=x}^{x+n-1} b_i-(i-x) = \prod\limits_{i=x}^{x+n-1} x-(i-b_i)$ .

We should find all $x \in \mathbb{Z}$, such that there is no $x \leq i < x + n$, such that $x \equiv i - b_i \, (\bmod p)$.

It's easy to see, that there should be $max(a_i) - n \leq x \leq max(a_i)$ to have $f(x) \neq 0$ and $f(x) \neq n!$ (they are both divisible by $p$).

Let's calculate $i - b_i$ for all necessary values $max(a_i) - n \leq x \leq max(a_i) + n$ and after that we can solve the problem by $O(n)$.

Anyway, the total complexity is $O(n)$ or $O(n \log n)$.

 Jury solution (Solution 1): [85700515](https://codeforces.com/contest/1371/submission/85700515 "Submission 85700515 by physics0523")Jury solution (Solution 2): [85700518](https://codeforces.com/contest/1371/submission/85700518 "Submission 85700518 by physics0523") 

### [1371F - Raging Thunder](../problems/F._Raging_Thunder.md "Codeforces Round 654 (Div. 2)")

First, observe where the balls fall. When there is a ">>>...>><<...<<<" structure, the balls on there will fall into one hole. So, our goal is handling this structure.

Each query is asking about a segment. Then, to solve this problem, we can use segment tree.

Each node maintains following:

* Prefix structure
* Suffix structure
* The answer for between above structures

For example, a string "><<>><>><<>>>>" will be converted to the following data:

* Prefix structure : "><<"
* Suffix structure : ">>>>"
* The answer for between above structures : take the answer of ">><" or ">><<". the largest answer is $4$.

And we need to implement that combining two data ( [left data] + [right data] ). Mainly we should merge left suffix and right prefix, and calculate the answer for the segment, but notice that there are some exceptions. The exceptions are in case of there are only one structure in the merged node, like ">>><<" or "<<<". (You may maintain other flags for your implement.)

Then, how to handling each queries? We also keep above data for when '>' are changed into '<' and vice versa on each node of the segment tree. And when a change query actually comes to some nodes, swap these data. Apply lazy propagation for handling this. When calculate the answer for a query, don't forget to consider about the prefix(or the suffix).

Total complexity : $O(n + q \log n)$

 Jury solution: [85700669](https://codeforces.com/contest/1371/submission/85700669 "Submission 85700669 by physics0523")Feel free to share your approach here!

