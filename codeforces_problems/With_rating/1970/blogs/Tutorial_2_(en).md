# Tutorial_2_(en)

**A1 - Balanced Shuffle (Easy)**
### [1970A1 - Balanced Shuffle (Easy)](../problems/A1._Balanced_Shuffle_(Easy).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

The problem statement describes exactly what needs to be done, so we just need to implement it carefully, using a O(nlogn) sorting algorithm from the standard library.

If you're using Python for this problem, the time limit can be a bit tight so you might need to optimize a bit. For example, tuples are much faster than custom classes in Python, so the following passes in 0.5s:


```cpp
  
s = input()  
a = []  
b = 0  
for i in range(len(s)):  
  a.append((b, -i, s[i]))  
  if s[i] == '(':  
    b += 1  
  else:  
    b -= 1  
a.sort()  
print(".join(x[2] for x in a))  

```
 **A2 - Balanced Unshuffle (Medium)**
### [1970A2 - Balanced Unshuffle (Medium)](../problems/A2._Balanced_Unshuffle_(Medium).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

In a balanced parentheses sequence each opening parenthesis corresponds (would form a pair enclosing a subexpression in a mathematical expression) to exactly one closing parenthesis and vice versa. In such a pair the balance before the opening parenthesis is always 1 less than the balance before the closing parenthesis. 

After sorting, the parentheses with equal prefix balance go together. Let us consider them in groups of equal prefix balance. The first group, with prefix balance 0, will contain only opening parentheses. The second group, with prefix balance 1, will contain the closing parentheses corresponding to the opening parentheses from the first group, and potentially some more opening parentheses. The third group, with prefix balance 2, will contain the closing parentheses corresponding to the opening parentheses from the second group, and potentially some more opening parentheses, and so on. Moreover, each group except the first one will always start with a closing parenthesis (since we break ties in decreasing order of position).

This observation allows to split the input string into the groups of equal prefix balance: the first group is everything before the first closing parenthesis. The second group is everything after that and before the k+1-th closing parenthesis, where k is the number of opening parentheses in the first group, and so on.

Having done that, we can also construct the original sequence group-by-group. After processing a certain number of groups we will have a string that is a parentheses sequence but not a balanced parentheses sequence yet: some opening parentheses in it will be marked as unmatched (for example, we can use opening square brackets instead of parentheses to denote those). When processing the next group, we put each closing parenthesis and all opening parentheses that follow it after the corresponding unmatched opening parenthesis.

Here is how this process works on the sample testcase:

* After the first group, our string is [.
* After the second group, our string is ([[).
* After the third group, our string is (()([)).
* After the fourth group, our string is (()(())) and we have correctly recovered the original sequence.

The straightforward implementation of this algorithm runs in O(n2), fast enough for the constraints of this subtask.

The transformation described in this problem is called a sweep map in the literature, and searching the Internet using that term will lead to a much deeper dive on the subject if desired.

 **A3 - Balanced Unshuffle (Hard)**
### [1970A3 - Balanced Unshuffle (Hard)](../problems/A3._Balanced_Unshuffle_(Hard).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

Solving this problem requires a more careful implementation of the algorithm described in the previous subtask. Since we only ever insert new parentheses into the current string after an unmatched parenthesis, we can use a linked list of characters instead of a string to represent it, and also store a vector of pointers to unmatched parentheses in it. This way each insertion will be done in O(1) for a total running time of O(n).

Another way to view this solution is that we are constructing a rooted tree corresponding to the original parentheses sequence in a breadth-first manner, layer-by-layer, but then need to traverse it in a depth-first manner to print the original sequence. This runs in O(n) if we store the tree using pointers or indices of children.

In fact, we can notice that the layer-by-layer construction is not really necessary: we just create a queue of tree nodes, each opening parenthesis creates a new child of the node at the front of the queue and puts it at the back of the queue, and each closing parenthesis removes the node at the front of the queue from the queue. This way the implementation becomes very short.

 **B1 - Exact Neighbours (Easy)**
### [1970B1 - Exact Neighbours (Easy)](../problems/B1._Exact_Neighbours_(Easy).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

Place all houses on the diagonal. Notice that for each house i either to the left or to the right, on the diagonal, there will be a house with the desired distance ai

 **B2 - Exact Neighbours (Medium)**
### [1970B2 - Exact Neighbours (Medium)](../problems/B2._Exact_Neighbours_(Medium).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

We don't care about satisfying the condition for the first house, since this house will always be at a distance 0 from itself. There are at least two approaches for constructing the desired placement.

Approach 1: Let's sort all ai in non-increasing order, then we can place houses in the zigzag order the following way: we will start by placing the first house in (1,1), then we will place each new house in the next column, alternating the relative position to the previous house up to down. Since ai is sorted in non-increasing order, we will never get out of the bounds of the field and the i-th house in the sorted order will satisfy the condition for the i−1 house in the sorted order.

Approach 2: Place the first house in (1,1). Then, place each next house in the next column. If ai≥i, you can place the i-th house in such a way that it will be ai away from the first one. If ai<i, you can place the house in the same row as the house with index i−ai and the house with this index will be ai away.

 **B3 - Exact Neighbours (Hard)**Tutorial is loading... **C1 - Game on Tree (Easy)**
### [1970C1 - Game on Tree (Easy)](../problems/C1._Game_on_Tree_(Easy).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

We are given a linked list with an initial coin at index 1≤i≤n. There are i−1 nodes to its left and n−i nodes to its right. Note that after the first move, all the remaining moves are fixed since there will be exactly one inactive neighbor. If one of i−1,n−i is odd, Ron should move to the corresponding node as there will be an even number left thus guaranteeing a victory for Ron. Otherwise, Hermione is guaranteed to win.

 **C2 - Game on Tree (Medium)**
### [1970C2 - Game on Tree (Medium)](../problems/C2._Game_on_Tree_(Medium).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

Let's root the tree at node u1 (the start node). By doing so, we guarantee that if the coin is at node v, the parent of v is already active and thus we can only go down in the tree. This means that each subtree can be seen as its own independent game. So, each node is either a winning or losing position (w.r.t. to the player whose turn is next). We will find recursively whether u1 corresponds to a winning game for Ron. If some child of a node v is a losing position, then the current player should move the coin to that child to guarantee a win. If all children are winning positions, the current player will surely lose. So, v is a winning position iff it has a child that is a losing position. Note that the leaves are losing positions. This is solved in O(n) time.

 **C3 - Game on Tree (Hard)**Tutorial is loading... **D1 - Arithmancy (Easy)**
### [1970D1 - Arithmancy (Easy)](../problems/D1._Arithmancy_(Easy).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

Given that we need to output 3 words only, we can manually (trying a few options on paper until we find a solution) construct 3 words such that all 9 spell powers are different.

 **D2 - Arithmancy (Medium)**
### [1970D2 - Arithmancy (Medium)](../problems/D2._Arithmancy_(Medium).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

Now we need to find 30 words, so manually solving on paper is out of question. However, "just trying" still works: what we can do is to keep generating random words until we find 30 that have all 900 corresponding spell powers different. Depending on how you fast is your computation of the spell power you can either do this during the time limit, or precompute locally and then just submit a solution that prints the precomputed words.

To make sure that we have to precompute only once instead of 30 times (for n=1, n=2, ...), we can find 30 words such that the i-th word has length 30⋅i. This way the first n words from this list give a valid answer to the problem for any n<=30.

To compute the spell power, we can either use the naive approach of taking all substrings, sorting them and finding unique ones, some optimization thereof (for example, if the words are randomly generated, the chances that sufficiently long substrings coincide are vanishingly small and can be ignored), or the asymptotically optimal approach using any of the suffix data structures (the suffix array, or the suffix automaton, or the suffix tree).

 **D3 - Arithmancy (Hard)**
### [1970D3 - Arithmancy (Hard)](../problems/D3._Arithmancy_(Hard).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

The previous approach of just generating random words does not even come close to working for n=1000 (in fact, it is hard to push it beyond roughly n=50). Now we need to add our own insights to the process.

The first idea is: in order to answer the queries, we will likely need to know the spell power for all n2 possible spells. But even if we use a suffix array to compute the spell power, it will be too slow to compute the spell power 106 times for spells of length around 6⋅104. Therefore it is better to choose the magic words in such a way that computing the spell power of a concatenation of two such words can be done in O(1).

One way to achieve this is to choose some family of magic words gi with a regular structure and a single parameter i, and just figure out the function f(i,j) for the spell power for the concatenation of gi and gj on paper, hopefully it will be easy to figure out and quick to compute.

Then, what we can do is to go in increasing order of i, and try to take the next word gi into our set by checking if after adding it to the set, the newly added spells have spell powers that are different from each other and from the existing spell powers. Since we compute the spell power in O(1), the total running time of this process is around O(n⋅k), where k is the number of gi we had to check before we managed to add n of them into the set.

The only remaining difficulty, and of course it is actually the main part of the solution, is to choose the family gi. Here we have two main competing constraints:

* The words have to have simple structure, so that we can compute f(i,j) quickly (in both senses: quickly figure out the formula, and the formula should be simple).
* However, we must have f(i,j)≠f(j,i). It turns out that this rules out many word families with a very simple structure.

We expect that once you realize the two constraints above, after a small amount of experimentation you will stumble upon a family that works. Here are two families that work that we know about, but I expect that there are many many more:

* gi=XOXi−1. So g1=XO, g2=XOX, g3=XOXX, and so on. We found this family in the upsolving solution from one of the teams in the onsite round.
* gi=XOiXOi. So g1=XOXO, g2=XOOXOO, g3=XOOOXOOO and so on. This family actually leads to a string slightly longer than 30000 for n=1000, but it can be fixed by skipping the short strings that lead to too many collisions later (so we actually use gi=XOi+5nXOi+5n). This was the original reference solution.

 As you noticed, our solution does not use the fact that the interactor is guaranteed to be random. The reason the problem was set like this is that we're not aware of a way to find collisions quickly enough that we could use to simply check if the n printed magic words yield n2 distinct spell powers. Therefore to make the problem well-defined and avoid the need for contestants to guess how strong the checker is, we made it weak (just trying 1000 random spells) but well-specified.

 **E1 - Trails (Easy)**
### [1970E1 - Trails (Easy)](../problems/E1._Trails_(Easy).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

Let ti:=si+li. The number of possible paths between cabin i and cabin j is titj−lilj.

Let vk,i be the number of paths that ends in cabin i after walking for k days. We then have v0,1=1,v0,i=0 for i≠1, and vk+1,i=m∑j=1(titj−lilj)vk,j. Thus, we can compute (vk+1,1,…,vk+1,m) from (vk,1,…,vk,m) in O(m2) time using this formula. We do this n times to get (vn,1,…,vn,m). The solution to the problem is now vn,1+⋯+vn,m. The total running complexity is O(nm2).

 **E2 - Trails (Medium)**Tutorial is loading... **E3 - Trails (Hard)**Tutorial is loading... **F - Playing Quidditch (Easy, Medium, Hard)**Tutorial is loading... **G1 - Min-Fund Prison (Easy)**
### [1970G1 - Min-Fund Prison (Easy)](../problems/G1._Min-Fund_Prison_(Easy).md "Helvetic Coding Contest 2024 online mirror (teams allowed, unrated)")

The cells and corridors in this subtask form a tree. No matter how we divide the prison into two complexes, there will be at least one existing corridor connecting them, but we must have at most one such corridor, which means that we do not need to build any more corridors.

For each existing corridor, removing it splits the tree into two parts, and those two parts are the only possibility to have two complexes connected only by this corridor. So we need to compute the sizes of the two parts for every corridor, and then pick the corridor that minimizes the sum of squares of the sizes.

In order to compute the sizes of the two parts for each corridor quickly we can root the tree and then use depth-first search that recursively computes the size of each subtree. The running time of this solution is O(n).

 **G2 - Min-Fund Prison (Medium)**Tutorial is loading... **G3 - Min-Fund Prison (Hard)**Tutorial is loading...