# 牛顿法

目标函数为: $f(x) = 0$

算法很简单如下:
$$x_{n+1} = x_{n} - \frac{f(x_n)}{f'(x_n)$$

其实是对f(x)做了泰勒展开, 用前两项来做对于f(x)的近似替代
$$f(x) = f(x_0) + f'(x_0)(x-x_0) + \frac{f''(x_0)}{2!}(x-x_0)+...$$

即, $f(x_0) + f'(x_0)(x-x_0) = 0$

故有, $x_{n+1} = x_{n} - \frac{f(x_n)}{f'(x_n)$


# Newton-Raphson method

Object function: $f(x) = 0$

The simple but useful iteration formula:
$$x_{n+1} = x_{n} - \frac{f(x_n)}{f'(x_n)$$

In fact, the first two terms of the Taylor Expansion of f(x) are ultilized to make an approximately subsitution of f(x)
$$f(x) = f(x_0) + f'(x_0)(x-x_0) + \frac{f''(x_0)}{2!}(x-x_0)+...$$

namely, $f(x_0) + f'(x_0)(x-x_0) = 0$

So, $x_{n+1} = x_{n} - \frac{f(x_n)}{f'(x_n)$

