# Tutorial_(en)

Thank you for participating! We hope you liked our problems.

 
### [1166A - Silent Classroom](../problems/A._Silent_Classroom.md "Codeforces Round 561 (Div. 2)")

First, note that we can solve the problem for each starting letter independently, because two students whose name starts with a different letter never form a chatty pair.

How do we solve the problem when all the students' names start with the same letter? We claim that it's best to split as evenly as possible. If one classroom has a students, and the other has b students with a>b+1, then by moving one of the students from the first classroom into the second we remove a−1 chatty pairs from the first classroom and create b new chatty pairs in the second, for a net result of (a−1)−b>0 chatty pairs removed. So in the best splitting we have |a−b|≤1, meaning we split as evenly as possible.

Then, if cnta denotes the number of students whose name starts with a, we will split them into a classroom containing ⌊cnta2⌋ students and one containing ⌈cnta2⌉ students. So the total number of chatty pairs among students whose name starts with a is

(⌊cnta2⌋2)+(⌈cnta2⌉2)

The expression is the same for the other letters in the alphabet, and adding them all up gives us our answer. We can also solve the problem without determining what the best splitting is. If, for each starting letter, we try all the possible number of students to send into the first classroom, and choose the one that gives the minimal x, then we will only have to do O(n) checks in total, which is more than fast enough to solve the problem.

Complexity: O(n).

 
### [1166B - All the Vowels Please](../problems/B._All_the_Vowels_Please.md "Codeforces Round 561 (Div. 2)")

First, which boards could we feasibly fill with characters satisfying that every row and column contains one vowel at least once? Well, if we have a board with less than 5 rows, then each column contains less than 5 characters, so we cannot have every vowel on each column, and we can't fill the board. Similarly, we can't fill a board with less than 5 columns.

Ok, so say now that we have a board with at least 5 rows and at least 5 columns. Can we fill it? Yes we can! It's enough to fill it by diagonals, as shown in the following picture:

 ![](images/e520ae6c2191a2fa325b19b5cda6cd25db42a5a7.png) Now we can easily solve the problem. If n⋅m=k, then n must divide k and m=kn. So we can iterate over all possible n from 5 to k, check whether n divides k and in that case, check whether m=kn is at least 5. If this works for at least one value of n then we can fill the n⋅m board by diagonals as shown before, and obtain our vowelly word by reading the characters row by row. If we don't find any values of n satisfying this, then no vowelly word exists.

Complexity: O(k).

 
### [1166C - A Tale of Two Lands](../problems/C._A_Tale_of_Two_Lands.md "Codeforces Round 561 (Div. 2)")

Formally, the condition for the legend being true reads

min(|x−y|,|x+y|)≤|x|,|y|≤max(|x−y|,|x+y|)

Now, it is possible to characterize when this condition happens through casework on the signs and sizes of x and y, but this can be tricky to do right. However, there is a neat trick that allows us to solve the problem without any casework. What happens if we change x into −x? The values of |x| and |y| stay the same, while |x−y| and |x+y| will swap values. This means that the pair {x,y} works if and only if {−x,y} works. Similarly we can switch the sign of y. This means that we can replace x and y by their absolute values, and the original pair works if and only if the new one works.

If x≥0 and y≥0 then the condition becomes |x−y|≤x,y≤x+y. The upper bound obviously always holds, while the lower bound is equivalent by some simple algebra to

x≤2y and y≤2x

So the problem reduces to counting the number of pairs {x,y} with |x|≤2|y| and |y|≤2|x|. To solve this we now take the absolute values of all the ai and sort them into an array b1≤b2≤⋯≤bn. The answer to the problem is the number of pairs (l,r) with l<r and br≤2bl. For each fixed l we calculate the largest r that satisfies this condition, and just add r−l to the answer, as the values l+1,l+2,…,r are all the ones that work for this l. We can either do a binary search for the best r at each l, or calculate the optimal r's for all of the l's in O(n) using two pointers. Either way, our final complexity is O(nlogn) as this is the time required to sort the array.

Complexity: O(nlogn)

 
### [1166D - Cute Sequences](../problems/D._Cute_Sequences.md "Codeforces Round 561 (Div. 2)")

We will first deal with determining when the sequence doesn't exist. To do this, we place some bounds on the values of xn. If we choose all values of the ri to be equal to 1 then we can calculate that xn=2n−2(x1+1). Reciprocally if we choose all ri to be equal to m then we find xn=2n−2(x1+m). All other values give something inbetween, so we get

2n−2(x1+1)≤xn≤2n−2(x1+m)

Therefore, if b doesn't lie on any of the intervals [2n−2(a+1),2n−2(a+m)] for some value of n, then it is impossible for b to be a term of an m-cute sequence starting at a. This can be checked naively in O(log(1014)) since there are this many relevant values of n. We can convince ourselves that all values in these intervals are feasible through some experimentation, so we now turn to the more difficult problem of actually constructing a sequence.

First, notice that we can rearrange the definition of the sequence as follows:

xn=x1+x2+⋯+xn−1+rn=(x1+⋯+xn−2)+xn−1+rn=(xn−1−rn−1)+xn−1+rn=2xn−1+rn−rn−1

Now, we can try to find a pattern. We see that x2=a+r1, x3=2a+r1+r2, x4=4a+2r1+r2+r3, and in general it would seem that.

xn=2n−2a+2n−3r2+2n−4r3+⋯+2rn−2+rn−1+rn

This is actually very easy to prove inductively using xn=2xn−1+rn−rn−1: All coefficients double from one term to the next, but we substract rn−1 once, so that coefficient becomes 1 instead. Now we can also find an explicit solution: Write b as 2n−2(a+k)+r where r<2n−2, and consider the binary representation r=dn−3dn−4…d0 of r. Then choosing ri=k+dn−1−i (where d−1=0) works, because

2n−2a+2n−3(k+dn−3)+⋯+2(k+d1)+(k+d0)+k=2n−2a+(2n−3+2n−4+⋯+2+1+1)k+2n−3dn−3+2n−4dn−4+⋯+d0=2n−2a+2n−2k+r=2n−2(a+k)+r

Alternatively, after getting the formula, we can iterate on i from 2 to k and greedily choose the values of ri to be as large as we can without exceeding b. This can be easily shown to work using that the coefficients are consecutive powers of two.

Both of these approaches can be implemented in O(log(1014)) per query.

Complexity: O(qlog(1014))

 
### [1166E - The LCMs Must be Large](../problems/E._The_LCMs_Must_be_Large.md "Codeforces Round 561 (Div. 2)")

We denote by $\textrm{lcm}\; A$ the $\textrm{lcm}$ of all elements in a collection $A$. Also, denote by $D_i$ and $S_i$ the collections that Dora and Swiper bought on day $i$, respectively.

First, when can we say for sure that the values of $a_i$ cannot exist? Well, suppose that $D_i = S_j$ for some $i$ and $j$. Then we also have $D_j = S_i$, so if the condition were true we would have

$$\textrm{lcm}\; D_i > \textrm{lcm}\; S_i = \textrm{lcm}\; D_j > \textrm{lcm}\; S_j = \textrm{lcm}\; D_i$$

Which is of course impossible. What now? We can actually make our impossibility condition a bit stronger by noticing that $\textrm{lcm}\; B \le \textrm{lcm}\; A$ whenever $B$ is a collection contained in $A$, which happens because $\textrm{lcm}\; B$ actually divides $\textrm{lcm}\; A$. Then, if the stores Dora bought from on day $i$ are completely disjoint from the stores Dora bought from on day $j$, then $D_j$ would be completely contained in $S_i$ and vice-versa, so

$$\textrm{lcm}\; D_i > \textrm{lcm}\; S_i \geq \textrm{lcm}\; D_j > \textrm{lcm}\; S_j \geq \textrm{lcm}\; D_i$$

Which is again a contradiction.

Ok, any two days must have a common store for the statement to be possible, so what? The remarkable fact here is that this is the only condition we need to check: i.e., the solution exists if and only if the sets of stores that Dora visited on days $i$ and $j$ intersect for all $i$ and $j$.

How do we get a valid solution? We will take $m$ different prime numbers $p_1, p_2, \dots, p_m$ and set $a_i$ to be the product of $p_j$ for all the $j$'s such that Dora visited store $i$ on day $j$. Then $p_j$ is a divisor of $a_i$ if and only if Dora visited store $i$ on day $j$.

Now proving that this works is easy: We know that on day $i$, Dora bought an integer from a store that she also visited on day $j$, and this number must be a multiple of $p_j$. So $\textrm{lcm}\; D_i = p_1p_2 \dots p_m$ for all $i$. On the other hand, $S_i$ contains no multiples of $p_i$, because they are all in $D_i$. So the $\textrm{lcm}$ of $S_i$ is strictly smaller.

Now we just need to check that any two days have a common store, which can be done in $\mathcal{O}(nm^2)$ by checking each pair of days and determining for each $i$ whether Dora visited both stores on day $i$ in $\mathcal{O}(n)$. You can achieve a slight speedup if you check this using a bitset, but this wasn't necessary to solve the problem.

Complexity: $\mathcal{O}(nm^2)$.

 
### [1166F - Vicky's Delivery Service](../problems/F._Vicky's_Delivery_Service.md "Codeforces Round 561 (Div. 2)")

Let G be the graph with cities as vertices and roads as edges. Note that the edges originally in G can be regarded as m queries of the "add edge" type, so we will just describe a solution that can handle m+q queries of any type.

We need a way to capture the idea of going through two roads of the same color in a row. To do this, consider a graph G∗ with the same vertices as G, in which vertices u and v are connected by an edge if uw and vw are edges of the same color for some vertex w. Then any path in this graph corresponds to a double rainbow in the original. However, this doesn't solve the problem yet, because of the condition that the final edge of a double rainbow can be of any color.

To help in solving this issue, consider n sets Sv such that Sv has all of the G∗-connected components of both v and any neighbor of v. Then we can see that we have a double rainbow from u to v if and only if the connected component of u is in Sv (either we reach v directly, or we reach one of its neighbors and then use our final edge to go to v). So as long as we can mantain these sets, we have a O(logn) time way to answer queries of the second type.

Now we need to deal with adding edges. To do this, we will store the connectivity of G∗ using a DSU. When we connect two connected components in G∗, we do the merges from small to large. If we merge component b into component a then for each vertex u in component b and every neighbor v of u we remove b from Sv and insert a instead. By merging from small to large we guarantee that each vertex changes component at most O(logn) times, and thus we also update Sv through the edge uv at most O(logn) times. Each update is just two O(logn) operations, so over all updates this amortizes to O((m+q)log(n)2) (because we have O(m+q) edges), plus O(nlogn) for actually moving the vertices.

There's an easy to fix, but important note, which is that the number of edges in G∗ can be quadratically large. However, we can check that for each edge uv of color x that we add, we only need to add two edges to G∗. Namely, if u′ and v′ are neighbors of u and v respectively through an edge of color x, then it is enough to add edges uv′ and u′v. (If one of u′ or v′ doesn't exist then we just don't add the corresponding edge). We can store these x-colored neighbors of each vertex in sets which have total size at most m+q, so we can find in O(logn) which updates we need to perform, and we perform a constant number of updates per added edge.

Complexity: O(nlog(n)+(m+q)log(n)2), or O((n+m+q)log(n)) using hash tables.

