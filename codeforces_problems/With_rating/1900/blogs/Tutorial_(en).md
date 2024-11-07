# Tutorial_(en)

[1900A - Cover in Water](../problems/A._Cover_in_Water.md "Codeforces Round 911 (Div. 2)") 

Author: [NemanjaSo2005](https://codeforces.com/profile/NemanjaSo2005 "Master NemanjaSo2005")

 **Hint 1**Assume that cells i−1, i, and i+1 are covered in water. What happens if you remove water from cell i?

 **Hint 2**The water at position i is replaced as both cells i−1 and i+1 have water in them. 

 **Solution**Read the hints.

If there are 3 consecutive empty cells i−1, i, i+1, we can place water in cells i−1 and i+1 and then move water from cell i to all other cells. If there are no such cells, we have to place water on every empty cell.

So if we find substring ''...'' in the array, the answer is 2, otherwise the answer is the number of empty cells.

Time and memory complexities are O(N).

 **Bonus**Solve the problem if it is required that each cell is filled with water, or next to at least 1 cell that is filled with water. 

[1900B - Laura and Operations](../problems/B._Laura_and_Operations.md "Codeforces Round 911 (Div. 2)")

Author: [NemanjaSo2005](https://codeforces.com/profile/NemanjaSo2005 "Master NemanjaSo2005")

 **Hint 1**Check if only digits 1 can remain. The situation is similar for checking if only digits 2 or only digits 3 can remain.

 **Hint 2**Try to find something that stays the same after each operation.

 **Hint 3**Look at the parity of the numbers.

 **Hint 4**The parity of each number changes after an operation. That means that if 2 numbers have the same parity, they will always have the same parity. If they had different parity, their parities stay different.

 **Solution**Read the hints.

If the parity of b and c is not the same, then it is impossible for only digits 1 to remain on the board, as it would require b=c=0. Otherwise, the following construction will leave only digits 1 on the board.

First remove digits 2 and 3 and write digit 1 while b>0 and c>0. If b=c, then we are done. Otherwise, without loss of generality assume b>c. That means that after the operations c=0 and b is even (Because b and c are the same parity). Now we perform the following 2 operations b2 times to get only digits 1 left. Remove digits 1 and 2 and add digit 3. After that remove digits 2 and 3 and add digit 1. An effective change of these 2 operations is the reduction of b by 2.

Time and memory complexities are O(1).

 **Bonus**Come up with a problem that uses a similar idea and try to solve it. A lot of beginner problems use a similar idea.

[1900C - Anji's Binary Tree](../problems/C._Anji's_Binary_Tree.md "Codeforces Round 911 (Div. 2)")

Author: [Riblji_Keksic](https://codeforces.com/profile/Riblji_Keksic "Master Riblji_Keksic")

 **Hint 1**Solve the problem if all of the characters on vertices are 'U'.

 **Hint 2**We can run DFS from the root. Using it we can calculate the number of edges that we have to traverse to get to every edge. Just output the smallest value among all the leaves.

 **Hint 3**Modify the DFS such that it takes into account that traversing some edges does not require an operation.

 **Hint 4**Add weights to the edges.

 **Solution**Read the hints.

We will make edges from a vertex to its children. The weight of that edge will be 1 unless one of the following holds:

 * The weight of an edge between a vertex and its left child will be 0 if the letter written on that vertex is 'L'.
* The weight of an edge between a vertex and its right child will be 0 if the letter written on that vertex is 'R'.

Now we run a modified DFS to find the distance of each vertex from the root, but with weighted edges. We output the minimal value among all the leaves. 

Time and memory complexities are O(N).

 **Bonus**Solve the problem if after reaching a leaf, Keksic can teleport to any other leaf that he chooses and then needs to get back to the root, or report that it is impossible for him to complete such a travel.

[1900D - Small GCD](../problems/D._Small_GCD.md "Codeforces Round 911 (Div. 2)")

Author:[NemanjaSo2005](https://codeforces.com/profile/NemanjaSo2005 "Master NemanjaSo2005")

 **Hint 1**Let m be the biggest value in the array. Calculate array x such that xi (1≤i≤m) is the number of triples which have gcd of i. Then the answer is the sum of i \cdot x_i over all i (1 \le i \le m). 

 **Hint 2**Value of \lfloor \frac{m}{1} \rfloor + \lfloor \frac{m}{2} \rfloor + \lfloor \frac{m}{3} \rfloor + \ldots + \lfloor \frac{m}{m} \rfloor is around m log m.

 **Solution part 1**We calculate x_i from x_m to x_1. For some i, we can first calculate the number of triples that have a value of function f that is an integer multiple of i, and then from it subtract x_{2i}, x_{3i}, x_{4i} \ldots. Because of the previous hint, the subtractions will be quite fast.

Now the question is how to calculate the number of triples that have a value of function f that is an integer multiple of i.

 **Hint 3**Numbers up to 100\,000 can have at most 128 divisors.

 **The rest of the solution**As the order in which numbers are given does not matter, we can sort the array. Now for each number d (1 \le d \le M) store indices of all numbers that are divisible by d in an array of vectors. Now we will for each number d (1 \le d \le m) count the number of triples.

To find the number of triples that have a gcd value that is an integer multiple of d, we can do the following. We go over the index of the number that will be value b in the function. We can utilize the vectors we calculated in the previous step for that. Say that the current index is i. Then for value c we can pick any number with an index larger than i as the array is sorted. For value a, we can pick any of the numbers divisible by d with an index less than i, the number of which we can get from the vector. By multiplying those 2 numbers we get the number of triples that have a_i as their middle value.

As numbers can have up to 128 divisors, the step above is quite fast.

Total time complexity is O(m log m + n log n + 128 \cdot n). Total memory complexity is O(m + 128 \cdot n).

 **Bonus**Solve the problem if f(a,b,c) = \gcd (a,c).

[1900E - Transitive Graph](../problems/E._Transitive_Graph.md "Codeforces Round 911 (Div. 2)")

Author:[NemanjaSo2005](https://codeforces.com/profile/NemanjaSo2005 "Master NemanjaSo2005")

 **Hint 1**Try to simplify graph H.

 **Hint 2**Look at strongly connected components of G, and what happens with them.

 **Hint 3**Use dp to find the answer.

 **Solution**The main observation is what H looks like. All the strongly connected components (SCC) in G will become fully connected subgraphs in H. Secondly, take any two vertices a and b such that a and b are not in the same SCC. We can let S_a be a set of vertices that are in the same SCC as a (a included). Similarly, S_b is a set of vertices that are in the same SCC as b. If there is an edge going from a to b, then for any two vertices x and y such that x belongs to S_a and y belongs to S_b, there is an edge going from x to y. Both of the previously stated facts about the graph can be proven by induction.

Now, let's say that there is the longest path that goes through at least one vertex of an SCC. Then that path goes through all the vertices in the SCC, due to all vertices in SCC being connected to the same vertices outside the SCC and due to the fact that SCC is a complete subgraph.

Now we can construct the graph H'. Each of the SCCs from H will be a vertex in H'. The number on the vertex will be equal to the sum of all numbers on the vertices of the SCC that it was constructed from. Edges between two new vertexes will be added if there is an edge between their original SCCs. The edge will have a weight equal to the size of the SCC that it is going into. An additional vertex will be added at index 0 and an edge will be made between it and all other vertices with 0 ingoing edges. Weight will be determined based on the size of the SCC of the vertex that the edge is going into.

Due to the previous observations, the answer for the H' will be the same as the answer for the H. However, notice that H' is a DAG. That means that the answer for it can be computed using DP after topological ordering.

Total time and memory complexity is O(n).

 **Bonus**We will define the value of the path as the biggest value of a vertex on the path. Among the values of all the longest paths, find the median one. It is guaranteed that there are at most 10^{18} longest paths starting from each node. (So basically, you can ignore overflow in the number of paths) The rest of the constraints are the same. 

[1900F - Local Deletions](../problems/F._Local_Deletions.md "Codeforces Round 911 (Div. 2)")

Author: [NemanjaSo2005](https://codeforces.com/profile/NemanjaSo2005 "Master NemanjaSo2005")

 **Hint 1**Solve the problem for q=1.

 **Hint 2**We can just simulate the process. Each operation removes at least half of the elements, meaning that we will perform at most log n operations.

 **Hint 3**Solve the problem if each l_i = 1. So basically, solve the problem for each prefix.

 **Hint 4**Keep values that are in the array after 1, 2, 3, \cdots, log n operations. Let's call those array's layers. Layer 0 is an array after 0 operations, layer 1 after 1 operation, and so on. When we add a value to the end of the layer, only 1 number that was previously local extreme (local minimum or maximum, depending on layer) might unbecome local extreme if the new value becomes local extreme. So we can just propagate this update to all layers.

 **Hint 5**Try to simulate the process of updating described in hint 4. Also, notice that if the array is longer than 3, we can handle prefix and suffix updates separately.

 **Solution**Read the hints.

Now we will precompute and store the array after each operation on the entire permutation. We will call those array layers. 

We can now solve queries in O(log n).

If a query involves a small number of elements, we can just brute force it. Otherwise, we do the following:

Now let's define our queries a bit differently. We are given some array x, which will be a subarray of some layer, and 2 values, a and b. We will get array y by appending a to the start of x and appending b to the end of x. We are interested in the value of f(y). It is easy to see that all queries involving 3 or more elements can be converted into the modified query.

If |y| is small, we can just brute force it. Otherwise, we can transform it into a query on the next layer in constant time, or in O(log n).

Now, the first thing to notice is that all elements in x that are neither first nor last will be deleted only if they were deleted when we performed operations on the whole permutation. That means that they will represent some interval on the next layer, let's call it z. (That interval can be found either with binary search or in O(1) with precomputation) It holds that  |z|  is around half of |x|. Now, notice that among a and the first element of x, there has to be at least one deletion. The same goes for the last element of x and b. 

So now we have transformed the query onto the next level in O(1), or O(log n). As we will do at most O(log n) such transformations, the complexity of a single query is either O(log n) or O(log^2 n) depending on the way we find the next interval, both of which should be fast enough to pass.

Total time complexity: O(n + q log n) or O(n + q log^2 n). Total memory complexity: O(n+q)

 **Bonus**Imagine that you already decided for each layer which indices will be on it. Come up with a generator that will uniformly randomly pick one permutation that satisfies those conditions.

