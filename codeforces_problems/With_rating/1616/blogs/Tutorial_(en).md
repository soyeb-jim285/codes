# Tutorial_(en)


### [1616A - Целочисленное разнообразие](../problems/A._Integer_Diversity.md "Good Bye 2021: 2022 is NEAR")

At first, let's replace ai with |ai|. Let f(x) denote the number of vaues in the array equal to x after the replacement (or, equal to x or −x before).

Then, for the zero we can only get min(1,f(0)) different values.

And for any other number x>0, we can get min(2,f(x)) different numbers in the array.

As different absolute values are independent and bounded, to get the answer we just need to evalue the sum min(1,f(0))+min(2,f(1))+…+min(2,f(100)). It can be easily done using arrays, maintaning the number of occurences for each |x|.

 
### [1616B - Зеркало в строке](../problems/B._Mirror_in_the_String.md "Good Bye 2021: 2022 is NEAR")

Let's compare s1s2…sksksk−1…s1 and s1s2…sk+1sk+1sk…s1. Note that they have a long common prefix s1,s2,…,sk. And the next pair of characters to compare is sk+1 and sk. So, unless s1s2…sksksk−1…s1 is a prefix of s1s2…sk+1sk+1sk…s1, it is optimal to choose k+1 if sk+1≤sk.

Pushing this idea further, we can see that the answer is either s1s1 or s1s2…sksksk−1…s1, for the largest k such that sk≤sk−1.

 
### [1616C - Репрезентативные края](../problems/C._Representative_Edges.md "Good Bye 2021: 2022 is NEAR")

Note that if the array is good ak+2−ak+1=ak+1−ak. In other words, the array form an arithmetic progression. 

We can either fix an arbitrary element and set all other elements equal to it (giving us the lower bound n−1 on the answer). 

Or, to solve the remaining case, we can fix any two elements that are in the answer, derive the formula for an arbitrary element of the arithmetic progression, and check the number of elements that we have to change.

 
### [1616D - Следи за большим средним](../problems/D._Keep_the_Average_High.md "Good Bye 2021: 2022 is NEAR")

Note that al+al+1+…+ar≥x⋅(r−l+1)⇒(al−x)+(al+1−x)+…+(ar−x)≥0.

After subtracting x from all elements, the problem is reduced to choosing the maximum number of elements with only non-negative sum contiguous elements.

Note that there should be a negative-sum subsegment of length 2 or 3, if there is a negative-sum subsegment. It is easy to see as x<0,y<0⇒x+y<0.

Hence, to solve the original problem we can use a simple DP, storing for the last two elements whether they are in the answer or not.

 
### [1616E - Лексикографически достаточно малая](../problems/E._Lexicographically_Small_Enough.md "Good Bye 2021: 2022 is NEAR")

Let's iterate over characters one by one and see the minimum number of operations required to make the string smaller with the fixed common prefix. Every time, we need to update the answer with the minimum number of moves required to make our prefix equal to some other prefix (iterating over characters smaller than the current).

In general, we can easily see that the optimal strategy is to move characters one by one, every time choosing the closest character. You can use data structures like Binary Indexed Tree to maintain the answer along the way.

 
### [1616F - Трехцветные треугольники](../problems/F._Tricolor_Triangles.md "Good Bye 2021: 2022 is NEAR")

c1,c2,c3 form a valid triangle coloring if and only if c1+c2+c3=3k for some k∈Z

Hence we can solve our problem with the simple Gaussian elemeniation. Complexity depends on your implementation, and you can use bitset to optimize it by 64 times. Note that the number of triangles is bounded by m√m, and the number of elements in the basis is m.

 
### [1616G - Просто добавь ребро](../problems/G._Just_Add_an_Edge.md "Good Bye 2021: 2022 is NEAR")

First of all, we have to check whether there is a Hamiltonian path in the original graph. In this case, the number is (n2)

Otherwise, addition of the edge a→b can only add a Hamiltonian path of the form:

1. (1→…→a−1)→…→b
2. b→a
3. a→…→(b→…n)

And these paths should be non-intersecting.

Where (x→…→y) means the default path x→(x+1)→…→y

Using this observation, it is easy to derive a DP with two states: two last vertices on the chain, and we are only interested in the states where x,x+1 are in different chains. 

dpx,x+1,dpx+1,x, we are interested in the number of valid pairs (a−1,a) that you can reach from the valid pair (b,b+1). Pair is valid if there is a hamilton path in the required direction. From here, we can get a solution in O(nm), that could be optimized with bitset to O(nm64).

But to make it linear, let's note that if there is no Hamiltonian path, then there is some edge y→(y+1) not present in the graph, and all the paths connecting the pairs oof vertices we are interested in are going through this edge. So instead of maintaining the set of all valid (a,a+1), we can run DFS in two drections from (y,y+1), and calculate the number of required pairs. 

 
### [1616H - Следи за малостью XOR](../problems/H._Keep_XOR_Low.md "Good Bye 2021: 2022 is NEAR")

First of all, we should divide all elements into groups by the prefix before the leading bit i of x, as elements from different groups will definitely yield invalid answers.

In one group, we either choose elements only from the group with the same bit i, then we can choose an artbirary subset. Or we need to solve the following problem:

* You are given two sequences a,b of lengths n,m and the current bit i.
* Choose any subset of a∪b, such that in each sequence at least one element is chosen, and the bitwise XOR of any pair (ignoring bits above i) is at most x

To solve this problem, we need to look at the bit i in x.

If it is set to zero, we need to recursively divide both arrays into a0,a1,b0,b1 according to the bits, and multiply the answers of (a0,b0,i+1), and (a1,b1,i+1).

Otherwise, let's note that (a0,b1) and (a1,b0) are independent, so we can multiply their answers and also add a bunch of simple combinatorial formulas in case none elements are chosen in one of these pairs.

The total complexity is O(30n), as at each layer there are only n elements in total.

