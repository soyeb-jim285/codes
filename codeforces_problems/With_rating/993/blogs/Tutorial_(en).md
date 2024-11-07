# Tutorial_(en)


### [994A - Fingerprints](https://codeforces.com/contest/994/problem/A "Codeforces Round 488 by NEAR (Div. 2)")

The problem can be solved by iterating over every number of the sequence, then iterating over the sequence of fingerprints to check if the number corresponds to a key with a fingerprint, resulting in an O(n×m) solution.

 
### [994B - Knights of a Polygonal Table](https://codeforces.com/contest/994/problem/B "Codeforces Round 488 by NEAR (Div. 2)")

Sort the knights by increasing the power. Now we can iterate over an array and greedy store set of k prevous knights with maximum if coins. After handling knight, if set contains less than k elements, we add current knight in set. Else if number of coins from current knight greater than from knight with minimum coins in set, we can replace this knight with current knight. You can store the set in vector, multiset or priority_queue. Be careful with overflowing and corner case k=0.

Time complexity is O(n⋅k) or O(n⋅log(k)).

 
### [994C - Two Squares](https://codeforces.com/contest/994/problem/C "Codeforces Round 488 by NEAR (Div. 2)")

It can be shown that if two squares intersect, then at least for one of the squares it is true that either one of its corners lies within the other square, or its center lies within the other square.

It is very easy to check if any corner or the center of the square rotated by 45 degrees lies within the square with sides parallel to the axes.

To check in the opposite directions in a similarly simple fashion, it is enough to rotate both squares by 45 degrees. To turn both squares by 45 degrees (with some scaling, which is OK) it is sufficient to replace each x coordinate with x+y and each y coordinate with x−y.

 
### [994D - Open Communication](https://codeforces.com/contest/994/problem/D "Codeforces Round 488 by NEAR (Div. 2)")

One way to approach this problem is to

1. Iterate over each pair p1 communicated by the first participant, and do the following:

Iterate over all pairs p2 of the second participant that are not equal to p1 and count whether the first number of p1 appears in any of them and whether the second number of p1 appears in any of them. If only one of them appears, that number is a candidate to be the matching number. If after iterating over all pairs communicated by the first participant only one candidate number was observed, then we know with certainty that that number is the one, and can immediately return it.

2. Do (1) but iterating over the numbers communicated by the second participant in the outer loop.

3. If at this point no number was returned, the answer is either -1 or 0. It is -1 iff for some pair (a,b) communicated by one of the participants, there are both pairs (a,c) and (b,d) among pairs communicated by the other participants, such that c≠b and d≠a (but possibly c=d), since in that case if the first participant indeed has the pair (a,b), they can't tell whether the actual number is a or b. Otherwise the answer is 0.

 
### [994E - Careful Maneuvering](https://codeforces.com/contest/994/problem/E "Codeforces Round 488 by NEAR (Div. 2)")

One way to solve the problem is to fix one spaceship in the left half and one spaceship in the right half, and assume that they shoot each other by the means of shooting towards one of the small spaceships. This gives us a coordinate of one small spaceship. Once we have it, iterate over all the large spaceships, mark those that are already shot.

Now all that is left is to find the best place to position the second spaceship. To do that, create a map from a coordinate to number of unmarked spaceships that would be destroyed if the second small spaceship is at that coordinate. Iterate over each unique spaceship coordinate on the left and each unique spaceship coordinate on the right, and increment the value in the map that corresponds to the position of the second small spaceship that would result in those two large spaceships shooting each other down by the number of large unmarked spaceships at the fixed coordinates.

Then update the final answer with the largest value in the map plus the number of marked spaceships and move to the next pair of spaceships in the outer loop.

This is a O((n×m)2)O((n×m)2) solution.

 
### [994F - Compute Power](https://codeforces.com/contest/994/problem/F "Codeforces Round 488 by NEAR (Div. 2)")

First observe that if for some threshold there's a way to assign tasks in a way that they will finish computation, it is also possible for all higher thresholds.

Because of that, we can use binary search to find the threshold. Now the problem is reduced to figuring out if for a given threshold the tasks can be assigned in a way that the system doesn't blow up too early.

For that, observe that if the average power per processor exceeds a given threshold, it also means that the average power exceeds the threshold multiplied by the number of processors, which in turn means that the average power minus threshold multiplied by the number of processors exceeds 0. By regrouping summands, we can associate the value (*power* - *threshold* * *num*_*of*_*processors*) to each task, and reduce the problem to finding the mapping of tasks to computers that minimizes the sum of values of all the tasks assigned as the first task, and compare it to zero.

To do that, we can use sort the tasks by the power value in decreasing order and use dynamic programming. The dimensions are:

*i*: The current task considered

*j*: How many tasks that use strictly more power than the *i* - 1st task are assigned as the first task to some computer that doesn't have a second task yet.

*k*: How many tasks that use exactly as much power as the *i* - 1st task are assigned as the first task to some computer that doesn't have a second task yet.

Transitions involve either assigning the task as a first task to some computer that has no tasks yet (increasing *k*, increasing the value by the value of the *i*-th task) or assigning the task to some computer that has a first task (decreasing *j*, not changing the value). Whenever *i*-th task's power differs from *i* - 1st task, *j* increases by *k*, and *k* becomes equal to zero.

The minimal sum of task values is then equal to the minimum of *dp*[*n*][*j*][*k*] over all *j*, *k*. Update the state of the binary search depending on whether the minimal sum is greater than zero or not.

Note that this is *O*(*n*3) × *log*(*precision*). As an exercise, find a solution that is *O*(*n*2) × *log*(*precision*)

 
### [993E - Nikita and Order Statistics](../problems/E._Nikita_and_Order_Statistics.md "Codeforces Round 488 by NEAR (Div. 1)")

First, we can find amount of numbers that less than xx for each prefix of aa (including empty prefix). We get array ss of this values. You can see that for each i,j,i<ji,j,i<j the truth that s[i]≤s[j]s[i]≤s[j] and if s[i]<s[j]s[i]<s[j] then i<ji<j. 

Let's count array rr such that r[i]r[i] is number of occurences ii in ss. Then answer for each dd from 11 to kk answer ans[d]ans[d] is ∑i,j,i−j=dr[i]⋅r[j]∑i,j,i−j=dr[i]⋅r[j].

Let's create array vv, v[i]=r[n−i]v[i]=r[n−i]. 

If p=r×vp=r×v then p[n+d]=∑i,h,i+h=n+dr[i]⋅v[h]=∑i,j,i+n−j=n+dr[i]⋅r[j]=∑i,j,i−j=dr[i]⋅r[j]=ans[d]p[n+d]=∑i,h,i+h=n+dr[i]⋅v[h]=∑i,j,i+n−j=n+dr[i]⋅r[j]=∑i,j,i−j=dr[i]⋅r[j]=ans[d].

Multiplication rr and vv can be done by FFT. You should write it accuracy or use extended floating point types because values in pp can reach 10101010. Also you can use NTT by two modules and Chinese Remainder Theorem.

Case k=0k=0 should be processed separately because of if s[i]≤s[j]s[i]≤s[j] it's not true that i<ji<j. We can get answer easily by using set or array of labels.

Time complexity is O(n⋅log(n))O(n⋅log⁡(n)).

 
### [993F - The Moral Dilemma](../problems/F._The_Moral_Dilemma.md "Codeforces Round 488 by NEAR (Div. 1)")

First lets observe that for the original and the inverted circuit to return the same value for each input, for each possible input one of the two conditions must be met: either in the original circuit all the gates in the second layer return 0, or in the inverted circuit all the gates in the second layer return 0.

This in turn means, that for each input *each* gate in the second layer must return zero in either original or inverted circuit. Since its output only depends on at most two gates in the first layer, and at most four inputs, we can iterate over all possible configurations of gates in the first layer, gate in the second layer, and connections to the inputs to find all configurations that meet this criteria.

All these configurations will share an important property: for a gate to return zero for each input in either the original or inverted circuit, it must either return zero in the original circuit for all inputs, or return zero in the inverted circuit for all inputs.

Some of these configurations (e.g. and(nand(a,b),and(a,b))and(nand(a,b),and(a,b))) always return 0 in one circuit, and 1 in the opposite circuit. Other configurations (e.g. and(and(a,b),nor(a,c))and(and(a,b),nor(a,c))) return 0 in one circuit, and something depending on the input in another, but critically 0 for the case of all inputs equal to 1.

For a circuit to meet the condition in the problem, it needs to have gates such that all of them return zero in either original or inverted circuit, and at least one of them to return one in the other circuit. WLOG let's consider the case of all gates returning zero in the original configuration, and at least one returning zero in the inverted configuration. Such circuit has two properties:

1. The circuit only contains the following gates in the second layer: and(nand(a,b),and(a,b))and(nand(a,b),and(a,b)), and(or(a,b),nor(a,b))and(or(a,b),nor(a,b)), nor(nand(a,b),and(a,b))nor(nand(a,b),and(a,b)), nor(or(a,b),nor(a,b))nor(or(a,b),nor(a,b)), and(and(a,b),nor(a,c))and(and(a,b),nor(a,c)), nor(nand(a,b),or(a,b))nor(nand(a,b),or(a,b)). The first four of them in the inverted graph will always return 1, and the last two will return something depending on the input. 

2. The circuit contains at least one of the first four gate kinds, and having at least one such gate is sufficient for the circuit to meet the condition from the problem. The latter is easy to show: since each of the first four gate kinds always returns 1 in the inverted mode, having it is sufficient to have at least one gate return 1 in the second layer. To show the former, remember that the last two gates return zero in the inverted mode when all three inputs are ones. It means that no matter how many of last two kinds of gates we have, and no matter how they are wired with the inputs, if all the inputs are equal to 1, all such gates will return 0, and at least one gate of the first four kinds will be necessary to have at least one gate to return 1.

From here the solution is trivial: to find the largest subset of the gates in the second layer that would all return 0 in the original circuit, and at least one return 1 in the inverted, we choose the largest set of gates that belong to the abovementioned set, for as long as at least one of them belongs to the first four kinds. If no gate in the second layer belongs to the first four kinds, the desired subset doesn't exist.

Solution for the case when the inverted circuit has all gates in the second layer always return zero and original has at least one that returns one is solved similarly.

