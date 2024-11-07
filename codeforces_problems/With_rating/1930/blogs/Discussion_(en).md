# Discussion_(en)

Hi everyone, today I'd like to elaborate something more on the [problem I](../problems/I._Counting_Is_Fun.md) on the recently ended div 1 contest. 

As described in the [official solution](https://codeforces.com/blog/satyam343), a bottleneck of the problem is the following: Given a sequence cj−n≤j≤ncj−n≤j≤n, compute

 gk=∑−k≤j≤k([xj](x+1/x)k)cjgk=∑−k≤j≤k([xj](x+1/x)k)cjfor all 0≤k≤n0≤k≤n.

In the official solution, an O(nlog2n)O(nlog2n) time algorithm is presented, and we also claimed that it is possible to compute gkgk in O(nlogn)O(nlogn) time. In this post, I'd like to elaborate on how to do that.

By the way, another bottleneck of the problem is the relaxed convolution problem, where the usual implementation also takes O(nlog2n)O(nlog2n) time. I mentioned in [comment](https://codeforces.com/blog/entry/111399#comment-996712) that the relaxed convolution has a somehow practical solution that has time complexity

 O(nlog2nloglogn),and there are more intricated optimization that have theoretical complexity O(n(logn)1+o(1)), we have theoretically faster algorithms for problem I.

Well, let's now focus on the previous problem. If you know that methodology called transposition principle (aka. Tellegen's principle), you will immediately see that the problem is equivalent to the following: Given a polynomial A(x) of degree n, compute the coefficients of A(x+1/x).

Well. If you don't know that, hope there will be someone writing a blog post about that. And just forget the previous problem, and focus on the problem of computing the coefficients of A(x+1/x). :)

So here comes our protagonist of this post: the composition problem.

Composition problem
===================

The problem is described as follows. Given a polynomial A(x) of degree n, and a rational function P(x)/Q(x), where P,Q has a constant degree, compute the coefficients of the polynomial A(P(x)/Q(x)). Here we mean that, since Q(x)nA(P(x)/Q(x)) must be a polynomial, the goal is to compute its coefficients.

Another intuitive interpretation is that, A(P(x)/Q(x)) is a rational function, and we want to compute the coefficients of its numerator. This naturally leads to the following general algorithm: Consider a divide-and-conquer algorithm, let A(x)=A0(x)+xn/2A1(x), we compute A0(P/Q) and A1(P/Q) separately, and merge them via

 A(P/Q)=A0(P/Q)+(P/Q)n/2A1(P/Q).The time complexity of this algorithm is given by the recurrence relation T(n)=2T(n/2)+O(nlogn), which has solution O(nlog2n). 

Several years ago I started to think about this problem. Unfortunately, I don't know how to do better than this in general. However, I do discover some special cases that have O(nlogn) algorithms, where indeed handle the case x+1/x=(1+x2)/x.

You might suspect that there is some magic theory behind this, but actually I don't have. The only thing I did was to find some algebraic tricks, and applying them just works.

Building Blocks
===============

We first start with several building blocks that are useful for the composition problem.

The first case is A(x+c). Actually this is almost the only nontrivial tool we can use to speed up the composition problem. I guess most of the audience already knows how to do this in O(nlogn), but for completeness I will still present the idea here. Just look at the expansion

 bk=∑jaj(jk)=1k!∑jajj!⋅cj−k(j−k)!,which is a convolution.

The second case is A(xk). This only requires O(n) time, since it essentially needs no arithmetic operations.

The third case is A(αx), where α is a constant. This can be done by scaling the coefficients of A(x), which also takes O(n) time.

Basic Tricks
============

With the three building blocks above, we can already handle something that seems to be much more.

The first problem is A(x2+ax+b), i.e., the composition of A(x) with a quadratic polynomial. This can be done by an algebraic trick:

 x2+ax+b=(x+a2)2+(b−a24).What does this mean? This means that we can compute A(x2+ax+b) by computing the compositions

 A(x2+ax+b)=A(x)∘(x+(b−a24))∘x2∘(x+a2)in the order from left to right.

The second problem is A((ax+b)/(cx+d)), i.e., the Mobius transformation. Just look at

 ax+bcx+d=ac+bc−adc(cx+d),and we can compute A((ax+b)/(cx+d)) by computing the compositions

 A(ax+bcx+d)=A(x)∘(x+ac)∘bc−adcx−1∘(cx+d).Well, there are some technical details on how to compute the compositions after composing x−1, but these are just tedious and I think you clever readers can figure them out by yourself. :)

The Trick for A(x+1/x)
=======================

Now we are going to solve A(x+1/x), and here is the trick:

 x+1/x=2x+1x−1∘x2∘x+1x−1.Using this special case, we actually can handle general A(P(x)/Q(x)) in O(nlogn) time, where P,Q are quadratic polynomials.

For (ax2+bx+c)/(dx2+ex+f), we can first move out a constant term, then reduce to the cases (b′x+c′)/(dx2+ex+f).

Then substitute by x−c′/b′, we reduce to the case b′x/(d′x2+e′x+f′).

Then take reciprocal, we reduce to the case (d′x2+e′x+f′)/b′x=(d′x2+f′)/b′x+e′/b′.

Seems that d′x/b′+f′x−1/b′ is different with x+x−1, but after scaling, we can again reduce to the case x+x−1.

Well, for some special cases, we cannot do division, but then it can also be reduced to other cases, such as composing a quadratic polynomial, which is also already settled.

(Acknowledgement: [This blog (Chinese)](https://codeforces.com/https://www.luogu.com.cn/blog/Fly37510/FUHE-ERCIFENSHI) reminded me that it's possible to settle all (ax2+bx+c)/(dx2+ex+f)).

The Trick for A(x3+ax2+bx+c)
===============================

Actually, we can also handle A(x3+ax2+bx+c) in O(nlogn) time.

The first two tricks are just applying x+c, then we can figure out that the only thing we need to handle is to compute A(x3+cx). Since we can also do scaling, we only need to solve some specific c.

The game ends with the following trick:

 (x3−3x)∘x+x−12=x3+x−32.This means that

 x3−3x=x+x−12∘x3∘(x+x−12)⟨−1⟩.You may ask, how can I composite (x+x−12)⟨−1⟩? Well, the problem is that it will occur the composition x1/2 when you expand the composition chain of x+x−1, but at that time, it can be proved that all terms of the polynomial have the form x2k, then the composition x1/2 has clear meanings.

Well, there are many technical details that I omitted, for example, it will occur in some essential cases that we need to do scaling with a parameter is a square root of something. This can be handled by introducing a formal element R=√α, and there might be some other technical details that I omitted. 

Whatever, the long chain of composition and the technical details make the O(nlogn) algorithm not so practical according to my experimental test, but I think it is still an interesting result.

Can we go further?
==================

Is it possible to solve the composition problem in O(nlogn) time for general rational functions? At least for the current techniques we have, the answer is no.

Here is an argument. What we have done before is to reduce the composition problem to the composition chain with the Mobius transform (ax+b)/(cx+d), and xk, and x1/k. Note that if we want to solve the equation P(x)=0. Suppose P(x) has such a composition chain, then we can solve the equation P(x)=0 by solving the composition chain step by step, this will result in an expression of the roots of P(x) in radicals. However, by the celebrated Abel–Ruffini theorem, we know that there are polynomials (actually general polynomials of degree ≥5) that cannot be solved by radicals, and this means that these polynomials definitely cannot be represented by the composition chain we want!

So there might be some interesting questions: Try to find some characterization of the polynomials that can be represented by the composition chain. This seems to let me recall the Galois theory, or a characterization of the composition chain of a polynomial by polynomials, known as the "Ritt decomposition theorem". However, they seem to not be directly related to the composition chain we are talking about, I wonder if there might or might not be some well-developed mathematical theory behind this problem.

Another question is, can we find some other building blocks that can be used to solve the composition problem, thus extending our ability to solve the composition problem for more cases? Or more ambitiously, can we find an entirely different algorithm that can solve the composition problem in O(nlogn) time for general rational functions?

I'll be happy to see if any of these questions have positive or negative answers.

Anyway, have a nice day!

