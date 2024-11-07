# Tutorial_(en)

[1808A - Lucky Numbers](../problems/A._Lucky_Numbers.md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808A - Lucky Numbers](../problems/A._Lucky_Numbers.md "Codeforces Round 861 (Div. 2)")

Let r−l≥100. Then it is easy to see that there exists a number k such that l≤k≤r, and k \equiv 90 \mod 100. Then the number k is the answer.

If r - l < 100, you can find the answer by trying all the numbers.

Despite the impressive constant, from the theoretical point of view we obtain a solution with asymptotics O(1) for the answer to the query.

[1808B - Playing in a Casino](../problems/B._Playing_in_a_Casino.md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808B - Playing in a Casino](../problems/B._Playing_in_a_Casino.md "Codeforces Round 861 (Div. 2)")

You may notice that the problem can be solved independently for each column of the input matrix. The answer is then the sum \sum\limits_{i = 1}^n \sum\limits_{j = i + 1}^n |a_i - a_j|, where a — array representing a column.

Let's try to calculate this sum for each column. Let's sort all elements of the current column. Let's calculate the answer for some element in the sorted list. The answer for it will be a_i \cdot i - sum, where sum is the sum on the prefix. Why is this so? Because we say that this number is larger than the others and the modulus will then decompose as a_i - a_j, and this is already easy to count.

[1808C - Unlucky Numbers](../problems/C._Unlucky_Numbers.md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808C - Unlucky Numbers](../problems/C._Unlucky_Numbers.md "Codeforces Round 861 (Div. 2)")

Check all pairs (l, r) — the minimum and maximum digits of the number from the answer. Discard the common prefix of l and r. Now we are left with some digits a and b as the leftmost digits of the number, with a < b. If b - a \geq 2, then we can put a + 1 at the beginning of the number, and then put any digit from the interval [l, r].

Otherwise, we try a, and then always put the largest digit of [l, r] that we can. Similarly, then try putting b, and then always put the smallest digit of [l, r] you can.

Of all l and r, for which it is possible to construct a given number, choose such that r - l is minimal, and the number constructed at these l and r.

[1808D - Petya, Petya, Petr, and Palindromes](../problems/D._Petya,_Petya,_Petr,_and_Palindromes.md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808D - Petya, Petya, Petr, and Palindromes](../problems/D._Petya,_Petya,_Petr,_and_Palindromes.md "Codeforces Round 861 (Div. 2)")

Let us see when 1 is added to the palindrome. Let there be some string s of odd length k, consider the index i to the left of the central one. If this character and the corresponding one on the right side of the string are different, we can replace one of the characters with the other and get +1 to the answer. 

Now the problem is as follows: count the number of indices on all substring of length k such that they differ from the corresponding character in that substring. Let's solve the inverse problem: count the number of indices for all substring of length k such that the given symbol and its corresponding one are equal. Then simply subtract from the maximum possible number of differences the required number of matches.

Try some symbol c and count for it the number of matches in all substring. Create a new array a of length n, that a_i=1 when s_i=c, otherwise a_i=0. Now we have to count the number of indices i and j such that i<j, a_i \cdot a_j=1, j-i < k and (j-i) mod 2=0 (i.e. the distance between indices is even). Let's fix some j where a_j=1, then indexes j-2, j-4, etc. fit the parity condition. Then we can calculate prefix sums for each parity of indices. That is, pf_{i,par} means the sum on prefix length i over all indices with parity equal to par. Then pf_{j-2,par}, where par=j mod 2 is subtracted from the answer for some fixed j. Total we get the solution for O(n\cdot maxA), where maxA is the number of different characters of the string.

To solve the problem faster, we will use the work from the previous solution. Write out separately for each character all its occurrences in the string. Let's go through the symbol and write out all positions with even and odd indices. Solve the problem for even ones (odd ones are solved similarly). We will maintain a sliding window, where the difference between right and left elements is no more than k. When we finish iterating after removing the left element, we will subtract the window length -1 from the answer, because for the left element of the window exactly as many elements have the same parity on the right at a distance of no more than k.

P.S. The solution for O(n\cdot maxA) can also be reworked into O(n \sqrt{n}) using the trick with «heavy» and «light» numbers.

[1808E1 - Minibuses on Venus (easy version)](../problems/E1._Minibuses_on_Venus_(easy_version).md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808E1 - Minibuses on Venus (easy version)](../problems/E1._Minibuses_on_Venus_(easy_version).md "Codeforces Round 861 (Div. 2)")

First, let's rephrase the problem condition a bit. A ticket number is lucky if (a_i – the digit that stands at position i in the number) is satisfied:  a_i \equiv (a_1 + a_2 + \ldots + a_{i-1} + a_{i+1} + \ldots + a_{n-1} + a_n) \pmod{k} 

Let S be the sum of all digits of the number. Then we can rewrite the surprise condition:  a_i \equiv S - a_i \pmod{k}   2 \cdot a_i \equiv S \pmod{k} 

Thus, if among the digits of the ticket there is such a digit x that: 2 \cdot x \equiv S \pmod{k}

Then the ticket is lucky.

Also note that there are k^n numbers of tickets in total. Let's count how many nosurprising tickets exist. Then, by subtracting this number from k^n, we will get the answer to the original problem. So now our goal is to count the number of non-surprising tickets.

Given a fixed sum S, there are numbers x that: 2 \cdot x \equiv S \pmod{k}

Therefore, in order for a number with sum S to be unlucky, it must not contain these digits.

Let us fix what S modulo k will equal. 

Now, let's make a DP f[i][sum], where: 

* i – index of the digit to be processed in the ticket
* sum – the current sum of digits of the ticket, modulo k

The basis of DP – f[0][0] = 1. We will build transitions from the state f[i][sum] by going through the digit y, which we will put at position i. Keep in mind that we cannot use such y that: 2 \cdot y \equiv S \pmod{k} 

Depending on y we recalculate sum. The number of unlucky ticket numbers, with sum S modulo k will be stored in f[n][S].

[1808E2 - Minibuses on Venus (medium version)](../problems/E2._Minibuses_on_Venus_(medium_version).md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808E2 - Minibuses on Venus (medium version)](../problems/E2._Minibuses_on_Venus_(medium_version).md "Codeforces Round 861 (Div. 2)")

First, read the editorial of problem E1. This section is a continuation and improvement of ideas from the previous section.

Let us improve the solution for O(nk^3). To do this, note that the transitions from i to i + 1 can be given by a matrix g of size k \times k. Then by multiplying f[i] (i.e., multiplying exactly 1 \times k matrix of the form [f[i][0], f[i][1], \ldots, f[i][k - 1]]) by this g matrix, we get f[i + 1].

Now note that for a fixed sum S modulo k, the matrix g will be the same for any i. Then let us take g to the power of n. Then f[n] can be obtained by calculating f[0] \cdot g^n. We can use multiplication algorithm for O(k^3 \log n) to get the matrix powered n.

[1808E3 - Minibuses on Venus (hard version)](../problems/E3._Minibuses_on_Venus_(hard_version).md "Codeforces Round 861 (Div. 2)")

 **Solution**
### [1808E3 - Minibuses on Venus (hard version)](../problems/E3._Minibuses_on_Venus_(hard_version).md "Codeforces Round 861 (Div. 2)")

First read the editorial for problems E1 and E2. This section is a continuation and improvement of ideas from previous sections.

Let's calculate how many such digits x can exist in total for a fixed S modulo k that: 2 \cdot x \equiv S \pmod{k}. To do this we need to consider two cases: 

* k is odd. Then there can exist exactly one such digit x from 0 to k - 1, provided that S – is odd (and it will equal exactly \frac{S + k}{2}).
* k is even. Then there can be two such digits x_1, x_2 from 0 to k - 1, provided that S – is even (with x_1 = \frac{k}{2}, x_2 = \frac{S + k}{2}).

Let's solve the problem when k is odd. Calculate how many different S exist that for them there exists a digit x (denote the set of such S as cnt_1), and calculate how many different S exist that for them there is no such digit x (denote the set of such S as cnt_0). 

If S enters cnt_0, then the number of unsurprising ticket numbers will be k^{n-1} (Since the total numbers k^n are exactly \frac{1}{k} of them will have some S from 0 to k - 1 modulo k). So it is sufficient to add |cnt_0| \cdot k^{n-1} to the number of unsurprising tickets.

If S enters cnt_1, let's use the following trick: subtract from each digit in the number x. Now we have reduced the original problem to the case where x = 0.

Now let's count the DP f[i][flag] – the number of unlucky numbers, where: 

* i – how many digits of the ticket we've already looked at
* flag = 1 if the current sum of digits is greater than zero, and flag = 0 otherwise.

This DP can be counted in O(\log n), again using the binary exponentiation of the matrix 2 \times 2 (the content of the matrix is justified by the fact that the numbers must not contain x = 0): \begin{pmatrix} 0 & k - 1\\\ 1 & k - 2 \end{pmatrix}

After calculating the DP, it is necessary to enumerate all possible variants of x and variants of S'. If the condition is satisfied: 2 \cdot x \equiv (S' + x \cdot n) \pmod{k}.

Then we can add to the number of unsurprising numbers: 

* f[n][0] if S' = 0
* \frac{f[n][1]}{k - 1} if S' \neq 0 (note that division must be done modulo m). The reason for division is that f[n][1] is the number of all numbers with S' \neq 0, and we need the number of numbers with some particular sum of S'.

The approach to solving for even k will be almost identical to the approach for odd k. The difference will be that we can now have either two x_1, x_2 when S is fixed, or none. When there are no x-ones, the solution is the same as the solution for cnt_0 of odd k. When there is x_1, x_2, we can see that they differ by \frac{k}{2}. So let's again subtract x_1 from each digit in the number and then double each digit after that. That is, we now work with the numbers 0, 2, \ldots, 2\cdot (k - 2), 0, 2, \ldots (k - 2). The matrix for DP transitions will now have the form: \begin{pmatrix} 0 & k - 2\\\ 2 & k - 4 \end{pmatrix}

After calculating the DP, it is necessary to enumerate all matching pairs x_1, x_2 and variants of S'. If the condition is satisfied: 2 \cdot x_1 \equiv (S' + x_1 \cdot n) \pmod{k}

Then we can add to the number of unsurprising numbers: 

* \frac{f[n][0]}{2} if S' = 0 (note that division must be done modulo m). The division is justified by the fact that f[n][0] is the number of all numbers with S' = 0, but now we have two different "zero" sums (since we have dominated all numbers by 2).
* \frac{f[n][1]}{k - 2} if S' \neq 0 (note that division must be done modulo m). The reason for division is that f[n][1] is the number of all numbers with S' \neq 0, and we need the number of numbers with some particular sum of S'.
