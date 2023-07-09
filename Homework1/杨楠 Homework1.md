# Homework1

软件13 杨楠

## 1 证明题

### a
证明：

要证明，对任意的 $f(n) \in \Theta(n^2)$ ，存在某个 $g(n) \in \Theta(n^2)$ ，使得对任意的 $n > n_0$ ，有

$$
2n+f(n)=g(n)
$$

由

$$
\Theta(n^2)=\{f(n): \exists c_1, c_2, n_0 > 0, s.t. \forall n \ge n_0, c_1 n^2 \le f(n) \le c_2 n^2 \}
$$

对于 $f(n)$，其相应的 $c_1, c_2, n_0$ ，要证明存在 $c_1', c_2', n_0'$ 使得

$$
c_1' n^2 \le 2n + f(n) \le c_2' n^2
$$

那么有

$$
c_1' n^2 \le 2n + c_1 n^2
$$

$$
2n + c_2 n^2 \le c_2' n^2
$$

两式分别除以 $n^2$ ，有

$$
c_1' \le \frac 2 n + c_1
$$

$$
\frac 2 n + c_2 \le c_2'
$$

取 $c_1'=c_1, c_2'=\frac{2}{n_0} + c_2, n_0'=n_0$ 即可。


### b
证明：假设原命题不成立，即两者存在交集 $f(n)$ ，那么

$$
\exists c_1, c_2, n_0 > 0, s.t. \forall n \ge n_0, c_1 g(n) \le f(n) \le c_2 g(n) \tag{1}
$$

并且

$$
\forall c > 0,  \exists n_0' > 0, s.t. \forall n \ge n_0, 0 \le f(n) < cg(n) \tag{2}
$$

但对于任何满足条件 $(1)$ 的 $f(n)$ ，其相应的 $c_1$ ，由条件 $(2)$ ，又会有 $f(n) < c_1 g(n)$ ，矛盾，因此不存在这样的交集 $f(n)$ ，即原命题成立

### c
证明：令 $f(n)=g(n)^{\sin n}$ ，由

$$
g(n)^{-1} \le g(n)^{\sin n} \le g(n)
$$

可得

$$
f(n) = \Omicron(g(n))
$$

但是
$$
f(n) \ne \Omega(g(n))
$$

否则， $\exists c, n_0 > 0, s.t. \forall n \ge n_0,  cg(n) \le f(n)$

那么
$$
cg(n) \le g(n)^{-1} \le g(n)^{\sin n}
$$

即
$$
\frac 1 c \ge g(n)^2
$$

显然不恒存在这样的 $c$ 满足条件，比如若 $g(n)\to \infty (n \to \infty)$ 时，$c$ 不存在，所以 $f(n) \ne \Omega(g(n))$ ，从而 $f(n) \ne \Theta(g(n))$

另外，由于并非所有的 $c > 0$ 都满足 $f(n) < cg(n)$ ，所以

$$
f(n) \ne \omicron(g(n))
$$

综上， $f(n) \notin \omicron(g(n)) \cup \Theta(g(n))$ 且 $f(n) \in \Omicron(g(n))$ ，从而原命题成立


### d
证明：

$$
\Theta(f(n)+g(n))=\{h(n): \exists c_1, c_2, n_0 > 0, s.t. \forall n \ge n_0, c_1 (f(n)+g(n)) \le h(n) \le c_2 (f(n)+g(n)) \}
$$

对于 $n \ge n_0$ ，若 $f(n) \ge g(n)$ ，由

$$
c_1 (f(n)+g(n)) \le f(n) \le c_2 (f(n)+g(n))
$$

有

$$
c_1 (f(n)+g(n)) \le 2c_1 f(n) \le f(n) \le c_2 (f(n)+g(n))
$$

取 $c_1 = \frac 1 2, c_2 = 1$ 即可。

若 $f(n) \le g(n)$ ，由

$$
c_1 (f(n)+g(n)) \le g(n) \le c_2 (f(n)+g(n))
$$

有

$$
c_1 (f(n)+g(n)) \le 2c_1 g(n) \le g(n) \le c_2 (f(n)+g(n))
$$

取 $c_1 = \frac 1 2, c_2 = 1$ 即可。

综上， $max\{f(n), g(n)\} \in \Theta(f(n)+g(n))$ ，即 $max\{f(n), g(n)\} = \Theta(f(n)+g(n))$

## 2

a. 是 是 否 否 否

b. 是 是 否 否 否

c. 否 否 否 否 否

d. 否 否 是 是 否

e. 是 否 是 否 是

f. 是 否 是 否 是

## 3

a.

$$
2^{2^{n+1}}, 2^{2^n}, (n+1)! , n!, e^n, n2^n, 2^n, (\frac 3 2)^n, \underline{(\lg n)^{\lg n}, n^{\lg \lg n}}, 
$$

$$
(\lg x)!, n^3, \underline{n^2, 4^{\lg n}}, \underline{\lg(n!), n \lg n}, \underline{n, 2^{\lg n}}, (\sqrt{2})^{\lg n}, 2^{\sqrt{2\lg n}}, 
$$

$$
\lg ^2 n, \ln n, \sqrt{\lg n}, \ln \ln n, 2^{\lg ^* n}, \lg ^* n, \lg (\lg ^* n), \lg ^* (\lg n), \underline{n^{\frac{1}{\lg n}}, 1}
$$

其中，同一条划线部分的函数即在相同类中。

b.

可以取 $f(n) = (2^{2^{n+2}})^{\sin n}$

