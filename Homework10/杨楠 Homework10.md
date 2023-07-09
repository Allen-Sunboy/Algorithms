# Homework10

软件13 杨楠

## 1

算法的伪代码如下。

```python
COMPUTE-TRANSITION-FUNCTION(P, Sigma)
    m = P.length
    pi = COMPUTE-PREFIX-FUNCTION(P)
    for q = 0 to m
        for each character a in Sigma
            if q == m or P[q+1] != a
                delta(q, a) = delta(pi[q], a)
            else
                delta(q, a) = q+1
    return delta
```

算法的有效性，即两层循环的正确性。对于不满足 $q = m$ 或者 $P[q+1] \ne a$ 的条件的，那么根据转移函数的要求，转移到的新的转态编号是加一。对于满足上述条件的，根据题干提示，要证明，如果 $q = m$ 或者 $P[q+1] \ne a$ ，则 $\delta(q, a)=\delta(\pi[q], a)$ 。

由转移函数的定义， $\delta(q, a)=\sigma(P_q a), \delta(\pi[q], a)=\sigma(P_{\pi[q]} a)$ 。由前缀函数的定义， $\sigma(P_q)=\pi[q]$ 。即， $P_q$ 长度为 $\pi[q]$ 的后缀，也是 $P_q$ 相同长度的前缀。从而 $\sigma(P_q a) = \sigma(P_{\pi[q]} a)$ 。


计算前缀函数 $\pi$ 的时间为 $\Theta(m)$ ，而两层循环的时间为 $\Omicron(m|\Sigma|)$ ，所以总的时间复杂度为 $\Omicron(m|\Sigma|)$ 。
