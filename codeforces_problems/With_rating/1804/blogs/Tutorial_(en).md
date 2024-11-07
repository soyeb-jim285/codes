# Tutorial_(en)


### [1804A - Lame King](../problems/A._Lame_King.md "Nebius Welcome Round (Div. 1 + Div. 2)")

Observation 1. Let |a|=|b||a|=|b|. The king can reach (a,b)(a,b) in 2⋅|a|2⋅|a| moves by alternating moves along rows and moves along columns.

Observation 2. Let |a|≠|b||a|≠|b|, in particular a>b≥0a>b≥0 (without loss of generality due to the board symmetry). The king can reach (a,b)(a,b) in 2a−12a−1 moves. He moves towards aa on turns 1,3,5,…,2a−11,3,5,…,2a−1. The remaining a−1a−1 moves are enough to reach bb. Finally, the remaining slots can be filled with "skip" moves.

Thus, the answer is |a|+|b||a|+|b| if |a|=|b||a|=|b| and 2⋅max(|a|,|b|)−12⋅max(|a|,|b|)−1 otherwise.

 Tutorial is loading... 
### [1804C - Pull Your Luck](../problems/C._Pull_Your_Luck.md "Nebius Welcome Round (Div. 1 + Div. 2)")

Assuming the constraint on the the sum of $n$ over all test cases we might want to simulate the process for each test case. However, we need an $O(n)$ (or other quasilinear complexity) solution.

The key observation is that the sum of all integers from $1$ to $2n$ inclusive is divisible by $n$. Indeed, $\sum_{i = 1}^{2n} i = \frac{(2n + 1) \cdot 2n}{2} = (2n + 1) \cdot n$.

As the remainders of $x$ of modulo $n$ will repeat after $2n$ steps there is no point in trying values of $x$ for more than $\min(2n, p)$.

Question, can you build the test that required Vesper to use $x$ more than $100k$? There is exactly one such test.

 Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading...