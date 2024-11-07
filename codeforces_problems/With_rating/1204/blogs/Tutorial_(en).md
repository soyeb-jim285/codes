# Tutorial_(en)


### [1204A - BowWow and the Timetable](../problems/A._BowWow_and_the_Timetable.md "Codeforces Round 581 (Div. 2)")

Basically, the problem asks you to count $\lceil \log_4 s \rceil$, which is equal to $\Bigl\lceil \dfrac{\log_2 s}{\log_2 4} \Bigr\rceil = \Bigl\lceil \dfrac{\log_2 s}{2} \Bigr\rceil$. If we denote $l$ as a length of the input number, then $\lceil \log_2 s \rceil$ is either equal to $l-1$ if $s$ is the power of two (it can be checked by checking that there is not more than one $1$ in the input string), or to $l-1$ otherwise, so the answer to the problem is either $\Bigl\lceil \dfrac{l-1}{2} \Bigr\rceil$ or $\Bigl\lceil \dfrac{l}{2} \Bigr\rceil$. Also for $s=0$ the answer is $0$.

 
### [1204B - Mislove Has Lost an Array](../problems/B._Mislove_Has_Lost_an_Array.md "Codeforces Round 581 (Div. 2)")

Any array that satisfies statements' conditions contains only powers of two from $2^0$ to $2^{k-1}$, where $l \leq k \leq r$, so the minimal sum is achieved when we take powers of two from $2^0$ to $2^{l-1}$ and set the other $n-l$ elements equal to $2^0$; the maximal sum is achieved when we take powers of two from $2^0$ to $2^{r-1}$ and set the other $n-r$ elements equal to $2^{r-1}$.

 
### [1204C - Anna, Svyatoslav and Maps](../problems/C._Anna,_Svyatoslav_and_Maps.md "Codeforces Round 581 (Div. 2)")

Firstly, find the matrix of the shortest paths using Floyd-Warshall algortihm or running dfs from all vertexes; then a greedy approach works here: add $p_1$ to the answer and then go along the path; if the distance from the last vertex in the answer to the current vertex $p_i$ is shorter than in given path, add the vertex $p_{i-1}$ to the answer and continue traversing the path. Don't forget to add $p_m$ in the end!

 
### [1204D2 - Kirk and a Binary String (hard version)](../problems/D2._Kirk_and_a_Binary_String_(hard_version).md "Codeforces Round 581 (Div. 2)")

Solution 1: Let's call a string $p$ fixed if there isn't another string $t$ of the same length which satisfies the first condition of the statement (it was about the same lengths of the longest nondecreasing subsequences on substrings). The following statements are obivous:

* string $10$ is fixed;
* if strings $p$ and $q$ are fixed, then their concatenation $pq$ is fixed;
* if a string $p$ is fixed, then the string $1p0$ is fixed;
* each fixed string contains the same number of ones and zeroes;
* the length of the longest nondecreasing subsequence for any fixed string is equal to the half of its length, which can be obtained by taking all zeroes or all ones;

So if we erase all fixed strings from the given string, the remaining parts consists of zeroes at prefix and ones at suffix; it is obvious that we can change all these ones to zeroes and the string still satisfies the condition.

Solution 2: If we change any $1$ to $0$ and the longest nondecreasing sequence of the whole string remains the same, then we are able to change it to $0$. To count the longest nondecreasing sequence of a new string, store and maintain following arrays: $dp^p_i$ — the longest nondecreasing sequence of the substring $s_{1 \ldots i}$; $zero_i$ — number of zeroes in the substring $s_{1 \ldots i}$; $dp^s_i$ — the longest nondecreasing sequence of the substring $s_{i \ldots n}$ and $ones_i$ — number of ones in the substring $s_{i \ldots n}$; now, if we change $1$ to $0$ at a position $i$, then the length of the longest nondecreasing sequence of a new string is $\max(dp^p_{i-1}+ones_{i+1},zero_{i-1}+1+dp^s_{i+1})$.

 
### [1204E - Natasha, Sasha and the Prefix Sums](../problems/E._Natasha,_Sasha_and_the_Prefix_Sums.md "Codeforces Round 581 (Div. 2)")

Let's count a dp $k[x][y]$ — the number of arrays consisting of $x$ ones and $y$ minus ones such that their maximal prefix sum is equal to $0$: if $x=0$ then $k[x][y] = 1$, else if $x>y$ then $k[x][y] = 0$, else $k[x][y] = k[x-1][y] + k[x][y-1]$, because if we consider any array consisting of $x$ ones and $y-1$ minus ones which maximal prefix sum is $0$ then adding a minus one to the end leaves it equal to $0$; also if we consider any array consisting of $x-1$ ones and $y$ minus ones which maximal prefix sum is $0$ then adding a one to the end leaves it equal to $0$, because $x \leq y$.

Now let's count a dp $d[x][y]$ — the answer to the problem for $n=x$ and $m=y$: if $x=0$ then $d[x][y]=0$, else if $y=0$ then $d[x][y]=x$, else $d[x][y] = (\binom{x+y-1}{y}+d[x-1][y]) + (d[x][y-1] - (\binom{x+y-1}{x}-k[x][y-1]))$. That is because if we consider any array of $x-1$ ones and $y$ minus ones (there are $\binom{x+y-1}{y}$ such arrays) then adding a one in its beginning increases its maximal prefix sum by $1$; also if we consider any array of $x$ ones and $y-1$ minus ones then adding a minus one in its beginning either decreases its maximal prefix sum by $1$ if it was greater than $0$ (there are $\binom{x+y-1}{x}-k[x][y-1]$ such arrays) or leaves it equal to $0$. So the answer to the problem is $d[n][m]$.

