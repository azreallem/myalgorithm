# 苏格拉底的麦穗问题

苏格拉底的麦穗问题，又称为“最优停止问题”或“秘书问题”，是一个著名的数学问题。问题描述如下：假设有n个麦穗，每个麦穗的大小各不相同，你只能从前往后逐一检查每个麦穗，并且做出是否选择当前麦穗的决定。一旦放弃一个麦穗，就无法再回头选择。目标是选择最大的麦穗。

## 最优策略

对于n个麦穗（或n个候选人、n个选项），最优策略是：
1. 观察阶段：先检查前 (约36.8%) 的麦穗，但不选择任何麦穗。
2. 选择阶段：从第 (约36.8%) 个麦穗开始，选择第一个比观察阶段中所有麦穗都要大的麦穗。

## 算法实现

采用统计的方法计算出最终的近似概率。

### 输入

- 总测试次数(times)
- 样本总容量(total)
- 样本百分比(obv_precent)

### 输出

- sel_average_num: 根据算法结果选出的数，统计后的平均值。
- times: 总测试次数。
- best_times: 根据算法结果选出的数是最大数的次数.
- better_times: 根据算法结果选出的数大于平均数的次数。
- best_prob: best_times概率。
- better_prob: better_times概率。

## 结论

1. 可以选择37%观察样本;
```
please input test times: 10000
please input Total Sample Qty: 10000
please input obversive precent(for example:0.368): 0.37
-------------------------------------------
sel_average_num: 75.18
times: 10000, best_times: 3495, better_times: 7499
best_prob:   34.95%
better_prob: 74.99%
```

2. 可以选择10%观察样本；
```
please input test times: 10000
please input Total Sample Qty: 10000
please input obversive precent(for example:0.368): 0.1
-------------------------------------------
sel_average_num: 92.58
times: 10000, best_times: 2885, better_times: 9270
best_prob:   28.85%
better_prob: 92.70%
```

3. 虽然选择37%观察样本得到最优解的概率最大: 34%；但是选择10%观察样本得到的数学期望值最大: 90（满分100）。
