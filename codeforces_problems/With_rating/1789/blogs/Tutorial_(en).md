# Tutorial_(en)


### [1789A - Serval and Mocha's Array](../problems/A._Serval_and_Mocha's_Array.md "Codeforces Round 853 (Div. 2)")

Idea & Preparation: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Tutorial**Considering an array a of n (n≥2) positive integers, the following inequality holds for 2≤i≤n:

 gcd(a1,a2,⋯,ai)≤gcd(a1,a2)≤2Therefore, when the prefix [a1,a2] of a is good, we can show that all the prefixes of a whose length is no less than 2 are good, then a is beautiful. It is obvious that [a1,a2] is good when a is beautiful. So we get the conclusion that a is beautiful if and only if the prefix [a1,a2] is good.

We can check if there exist ai,aj (i≠j) such that gcd(ai,aj)≤2. If so, we can move ai,aj to the front of a to make it beautiful, then the answer is `Yes`. If not, the answer is `No`.

Time complexity: O(n2log106).

### [1789B - Serval and Inversion Magic](../problems/B._Serval_and_Inversion_Magic.md "Codeforces Round 853 (Div. 2)")

Idea & Preparation: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Tutorial**If s is palindromic initially, we can operate on the interval [1,n], the answer is `Yes`.

Let's consider the other case. In a palindrome s, for each i in [1,⌊n/2⌋], si=sn−i+1 must hold. For those i, we may check whether si=sn−i+1 is true in the initial string. For all the illegal positions i, the operation must contain either i or n+1−i, but not both. For the legal positions, the operation must contain neither of i nor n+1−i, or both of them.

If the illegal positions is continuous (which means that they are l,l+1,…,r−1,r for some l and r), we may operate on the interval [l,r] (or [n+1−r,n+1−l]), making the string palindromic. The answer is `Yes`.

Otherwise, there must be some legal positions that lie between the illegal ones. Suppose the illegal positions range between [l,r] (but not continuous), and the operation is [o1,o2]. Without loss of generality, let the operation lies in the left part of the string. Then o1≤l,r≤o2<n+1−r must hold to correct all the illegal positions. This interval covers all the legal positions that lie between the illegal ones but does not cover their symmetrical positions. Thus, such kind of operation will produce new illegal positions. In other words, there are no valid operations in this situation. The answer is `No`.

Time complexity: O(n).

### [1789C - Serval and Toxel's Arrays](../problems/C._Serval_and_Toxel's_Arrays.md "Codeforces Round 853 (Div. 2)")

Idea & Preparation: [Toxel](https://codeforces.com/profile/Toxel "International Grandmaster Toxel")

 **Tutorial**Consider the contribution of each value. We only need to count the number of concatenated arrays each value appears in, and sum all those counts up. The answer to this problem only depends on the number of appearances of this value. Notice that the appearance of each value forms some intervals. Each interval starts when it modifies another element (or in the initial array), and ends when it is modified (or in the m-th array). As there are no duplicate elements, the intervals do not intersect, so we can simply sum their lengths up.

Let's use an array appear to track the appearance of each value. We first set the appearance of the initial elements to 0, and other elements to −1, which means the value does not appear. Then, in the i-th modification, suppose we modified some elements from x to y, then we should add i−appearx to countx, and set appearx to −1. We should also set appeary to i. After all operations, for all x, add m+1−appearx to countx if appearx is not −1.

Value x appears in m(m+1)2−(m−countx)(m−countx+1)2 concatenated arrays.

Time complexity: O(n+m).

### [1789D - Serval and Shift-Shift-Shift](../problems/D._Serval_and_Shift-Shift-Shift.md "Codeforces Round 853 (Div. 2)")

Idea & Preparation: [Toxel](https://codeforces.com/profile/Toxel "International Grandmaster Toxel")

 **Tutorial**First of all, it could be proven that the answer exists if and only if a and b are both zero or a and b are both non-zero.

If a is zero, it remains zero after any operations. Therefore it cannot become b if b is non-zero. If a is non-zero, logical left shift it will definitely increase its lowest bit or make it zero, thus changing it into a different number. The same applies to logical right shift. Therefore, the xor result must be non-zero and there are no possible operations if b is zero.

We will show that it is always possible to change a into b in the other cases. We denote lb(a) as the lowest bit of a and hb(a) as the highest bit of a. If a and b are both zero, no operations are needed. If they are both non-zero, the construction consists of four steps:

 1. If hb(a)<lb(b), logical left shift a by lb(b)−hb(a) bits. Then hb(a) must be equal or greater than lb(b).
2. For each bit i of lb(b)−1,lb(b)−2,…,1, if ai=1, we may logical right shift a by hb(a)−i bits to erase it. After that, we have lb(a)≥lb(b).
3. If lb(a)>lb(b), logical right shift a by lb(a)−lb(b) bits. Now it is guaranteed that lb(a)=lb(b).
4. For each bit i of lb(b)+1,lb(b)+2,…,n, if ai≠bi, we may logical left shift a by i−lb(a) bits to erase it. After that, we must have a=b.

Step 2 and step 4 require at most n−1 operations. We may also note that step 1 and step 3 never appear simultaneously. If step 1 is operated, then lb(a)=lb(b) is guaranteed after step 2. Thus, we need not operate step 3 in this case. In conclusion, we may use no more than n operations to change a into b if they are both non-zero.

Time Complexity: O(n2) or O(n2w) by using `std::bitset`.

### [1789E - Serval and Music Game](../problems/E._Serval_and_Music_Game.md "Codeforces Round 853 (Div. 2)")

Idea & Preparation: [Serval](https://codeforces.com/profile/Serval "Grandmaster Serval")

 **Tutorial**Consider the following two cases:

**Case 1**: x is not a factor of sn.

In this case we have ⌊snx⌋+1=⌈snx⌉. Let k=⌊snx⌋. It can be shown that there are at most 2√sn different values of k. The constraint of si can be written in the following form:

 si=pi⋅k+qi⋅(k+1)=(pi+qi)⋅k+qiFor a certain k, such pi and qi do not exist if and only if simodk>⌊sik⌋. To prove it, we show the contradiction that qimodk=simodk>⌊sik⌋≥qi, and we can give a construction of pi and qi when simodk≤⌊sik⌋ that qi=simodk and pi=⌊sik⌋−qi.

By observation, these si are in one of the following k−2 intervals:

 [1,k−1],[k+2,2k−1],…,[(i−1)k+i,ik−1],…,[(k−2)k+(k−1),(k−1)k−1]We can count the number of these si by pre-calculating the prefix sums to calculate f(x).

This case can be solved in O(sn) time, and we will show this fact:

 * When k≤√sn, there are k−2 intervals that need to be considered for a certain k. Since ∑k≤√snk≤sn, this part can be solved in O(sn) time.
* When k>√sn, notice that there are at most ⌈snk⌉≤√sn intervals that need to be considered for a certain k. Recall that there are at most √sn different values of k in this part, so it can be solved in O(sn) time.

**Case 2**: x is a factor of sn.

In this case we have ⌊snx⌋=⌈snx⌉. Let k=snx. The constraint of si becomes:

 si=(pi+qi)⋅kTo calculate f(x), we only need to count the number of multiples of x. To do this, we can first calculate s′i=gcd(si,sn) for all 1≤i≤n in O(nlogsn) time. It is obvious that s′i is a factor of sn. For a certain x, we can enumerate all the factors of sn, find out the multiples of x among them, and sum up the times that they occurred in s′. Recall that sn has at most 2√sn factors, so this takes O(sn) time.

This case can be solved in O(nlogsn+sn) time in total.

Time complexity: O(nlogsn+sn).

O(sn+σ(sn)) solutions can pass all the tests, where σ(n) denotes the sum of all the factors of n. A well-implemented O(snlogsn) solutions may pass the tests, too.

**Bonus**: Solve this problem in O(n+sn) time.

### [1789F - Serval and Brain Power](../problems/F._Serval_and_Brain_Power.md "Codeforces Round 853 (Div. 2)")

Idea & Preparation: [Serval](https://codeforces.com/profile/Serval "Grandmaster Serval")

 **Tutorial**Assume that the longest powerful subsequence of the given string S is T, which can be obtained by concatenating k copies of string T′. Noticing that |S|≤80, we have the observation that k⋅|T′|≤|S|≤80, so it is impossible that both k and |T′| is large.

When k<5, we only need to consider the k=2 case and the k=3 case. The k=4 case is covered by k=2 case, since T=T′+T′+T′+T′=(T′+T′)+(T′+T′).

For the k=2 case, we split S into two parts S=S1+S2, then calculate the maximal length of LCS(S1,S2) by dynamic programming over all the possible splits. This case can be solved in O(w2⋅|S|3) time, where w2 is a small constant.

It is similar to solve the k=3 case. We split S into three parts S=S1+S2+S3, then calculate the maximal length of LCS(S1,S2,S3) over all the possible splits. This case can be solved in O(w3⋅|S|5) time, where w3 is a small constant. We will estimate w3 later.

When k≥5, we have |T′|≤|S|k≤|S|5. It can be shown that, if we split S into 5 parts, T′ will be the subsequence of at least one of them. We can split S into equal lengths, then enumerate all the subsequences of these substrings as the possible T′. For a possible T′, we can find out corresponding k by matching T′ and S greedily. This case can be solved in O(5⋅2|S|/5|S|).

Now let us roughly estimate how small w3 could be. The time that dynamic programming consumed for certain S1,S2,S3 is |S1|⋅|S2|⋅|S3|. Since |S1|+|S2|+|S3|=|S|, we have |S1|⋅|S2|⋅|S3|≤127|S|3. Recall that there are (|S|−12)≤12|S|2 possible splits, then w3≤154 holds.

Time complexity: O(w3⋅|S|5+5⋅2|S|/5|S|).

