# Horner's Method

which also call as QinJiuSao's Method in China, because QinJiuSao pubulished the method in 1247 while Horner pubilshed in 1819.

Horner's Method is an algorithm for calculating polynomials in a computational efficient way.

$$p(x) = \sum_{i=0}^{n}a_i * x^{n-i}$$

Intuitively, it seams we need $\frac{n(n+1)}{2}$ times Multiplies and $n$ times Additons. But things chanegd if it is transformed to the follow expression.
$$p(x) = (...(a_0x+a_1)x + a_2)...+a_{n-1})x+a_n$$

Obviously, it is just a recursion defination of the previous polynomial which can be present as below.

$$
\begin{equation}
\left\{
             \begin{array}{lr}
             b_0=a_0, &  \\
             b_i = b_{i-1} * x^* + a_i, & i = 1,2,...,n  
             \end{array}
\right.
\end{equation}
$$

Evidently, it just takes $n$ times Multiplies and $n$ times Additions.

# 秦九韶算法

用于计算多项式，将原来的需要$n^2$的运算复杂度降低到了$n$。算法的迭代表达式如上公式。