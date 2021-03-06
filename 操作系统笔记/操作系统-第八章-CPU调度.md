# 第八章 CPU调度

## 8.1 CPU调度背景

### 8.1.1 上下文切换

-  切换CPU的当前任务，从一个进程/线程转换到另一个进程/线程；
- 但是切换之前要保护现场，保存当前进程/线程在PCB/TCB中的执行上下文(也就是CPU的状态)；
- 切换任务，当然要读取下一个进程/线程的上下文。 

### 8.1.2 定义

- 从就绪队列中挑选一个进程/线程作为CPU将要运行的下一个进程/线程；
- 需要调度程序(挑选进程/线程的内核函数)；
- 需要考虑的问题是 **调度的时机**。  

### 8.1.3 在进程/线程生命周期调度的时间

- 从一个状态到另一个状态的时候会发生调度

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143303296.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

### 8.1.4 内核运行调度程序的条件（满足其一即可）

- 创建一个新线程之后
- 程序退出时必须做出调度决策
- 当一个进程阻塞在I/O和信号量上或由于其他原因阻塞时
- 在一个I/O中断发生时，必须做出调度决策。如果中断来自I/O设备，而该设备现在完成了工作，某些被阻塞的等待该I/O的进程就成为可运行的就绪进程了。

### 8.1.4 CPU调度方式

- 不可抢占式

  - 调度程序必须等待事件结束(效率低，不采用)；

- 抢占式

  - 调度程序在中断被响应后执行；

  - 当前的进程从运行切换到就绪，或者一个进程从等待切换到就绪；

  - 当前运行的进程可以被换出

## 8.2 调度原则

### 8.2.1 程序执行模型

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143320724.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

-  执行模型：程序在CPU突发和I/O中交替
- 每个调度决定都是关于在下一个CPU突发时将哪个工作交给CPU；
- 在时间分片机制下，线程可能在结束当前CPU突发前被迫放弃CPU；

### 8.2.2 比较调度算法的准则

- CPU使用率：CPU处于忙状态所占时间的百分比；

- 吞吐量：在单位时间内完成的进程数量；

- 周转时间：一个进程从初始化到结束，包括所有等待时间所花费的时间；

  ​                       **周转时间=等待时间+处理时间**

- 等待时间：进程在就绪队列中的总时间；

- 响应时间：从一个请求被提交到第一次响应所花费的时间。 

### 8.2.3  吞吐量vs延迟

- 对快的评价指标：传输文件时的高带宽；玩游戏时的低延迟(这两点相互独立)；
- 减少响应时间：及时处理用户的输出并尽快将输出提供给用户；
- 减少平均响应时间的波动：在交互系统中，可预测性比高差异/低平均更重要；
- **增加吞吐量：减少开支(操作系统开支/上下文切换)；系统资源的高效利用(CPU，I/O设备)；**
- 减少等待时间：减少每个进程的等待时间。
- 低延迟调度增加了交互式表现(个人电脑)：如果移动了鼠标，希望屏幕迅速反馈光标的移动。
- 操作系统保证吞吐量不受影响(服务器)：
- 若想结束长时间的编程，所以操作系统必须不时进行调度，即使存在许多交互任务。
- **吞吐量是操作系统的计算带宽；响应时间是操作系统的计算延迟**。

## 8.3 调度算法

### 8.3.1 先来先服务 FCFS

-  FIFO队列规定，如果进程在执行中阻塞，队列中的下一个会得到CPU。 
-  优点：简单；
- 缺点：平均等待时间波动较大(没有抢占)；
- 花费时间少的任务可能排在花费时间长的任务后面；
- 可能导致I/O和CPU之间的重叠处理(CPU密集型进程会导致I/O设备闲置时，I/O密集型进程也在等待)。 

### 8.3.2 最短作业优先 SJF 最短进程优先 SPF

-  选择下一个最短的进程(短任务优先)，即按照预测的完成时间排序将任务入列； 
-  它可以是抢占的也可以是不抢占的，对于抢占类型的，**是SRT短剩余时间优先** 
- **SRT最短剩余时间优先**：总是选择剩余运行时间最短的那个进程运行；再次提醒：**有关的运行时间必须提前掌握**！当一个新作业到达时候，其整个时间同当前进程的剩余时间做比较，如果新的进程比当前运行进程需要更少的时间，当前进程就被挂起，而运行新的进程。

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143404804.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

-  优点：平均周转时间最少 
-  缺点：可能导致饥饿(连续的短任务流会使长任务饥饿；短任务可用时的的情况下任何长任务的CPU时间都会增加平均等待时间)； 
-  因此就需要预知未来，
  但是怎么预估下一个CPU突发的持续时间是一个问题；(你咋知道下一个进程是长是短呢？？？)
  其中一个简单的解决办法：询问用户；
  如果用户欺骗就杀死进程；
  但是用户不知道怎么办？ 
-  根据历史时间分配预估未来时间的分配(也就是根据之前该进程所花的时间来预测它将要花多少时间)： 

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143509178.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

- 通过当前测量值和先前估计值进行加权平均而得到下一个估计值得技术称为**老化**

### 8.3.3 最高响应比优先 HRRN

-  在SPN调度的基础上改进(考虑了等待时间，改善饥饿现象)；
- 不可抢占；
- 关注进程等待了多长时间；
- 防止无限期推迟；
- R = (w + s) / s (选择R值最高的进程) ，其中w:waiting time等待时间 s:service time执行时间 

### 8.3.4 时间片轮转/轮询算法 Round robin

-  在一个叫做时间片的单元对离散单元中分配处理器；
- 如果时间片结束了，那么就接换到下一个准备好的进程
- 如果该进程在时间片结束前阻塞或结束。则CPU立即进行切换。
-  举一个例子来理解，如下图，先设置一个时间片，例如20，那么就让进程轮流分享这个时间片。先P1执行，用完20后，让出CPU给P2；但是P2只有8，用完直接给P3；同样，P3只用20；以此类推。 

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143648214.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

- 优点：公平；
- 缺点：额外的上下文切换花销；
- 如果时间片太大，则等待时间过长，极限情况下退化成FCFS；
- 如果时间片太小，虽反应迅速，但是开销大；吞吐量由于大量的上下文切换开销而受到影响；
- 目标：选择一个合适的时间片大小；
- 经验规则：维持上下文切换开销处于1%以内。

### 8.3.5 多级反馈队列 Multilevel feedback queues

- 多级队列
  -  就绪队列被划分为独立的队列，比如说前台队列是负责交互的进程，后台队列负责批处理进程；
  - 每个队列可以有自己的调度策略，比如说前台队列可以是RR，后台队列可以是FCFS； 
  - 调度必须在队列间进行，比如说， 例如先处理前台进程，后处理后台，但是可能会造成饥饿； 
  - 固定优先级，例如先处理前台进程，后处理后台，但是可能会造成饥饿；
  - 时间切片，每个队列都得到一个确定的能够调度其进程的CPU总时间，例如，80%给前台，20%给后台。 

-  多级反馈队列 
  - 对于I/O密集型任务，放在高优先级队列，这里的时间片比较短；
  - 对于CPU密集型任务，防止低优先级队列，这里的时间片比较长。
  - (我们希望交互性好，占用资源多的可以放在后面)
  - 一个进程可以在不同的队列中移动。
  - **随着等待时间的增加，优先级增加；随着执行时间的增加，优先级减少，但是保证下次轮到它的时候，时间片是增多的**；
  - **时间片的大小随优先级级别的增加而减少**；如果任务在当前的时间片中没有完成，那么就降到下一个优先级。

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143730188.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

### 8.3.6 公平共享调度 fair share scheduling

- 站在用户的角度实现公平共享CPU资源。因为有的用户可能开的进程多，有的用户进程少。
- 一些用户组比其他用户组更重要；
- 保证不重要的组无法垄断资源；
- 未使用的资源按照每个组所分配的资源的比例来分配；
- 没有达到资源使用目标的组获得更高的优先级。 

### 8.3.7 不同调度模型的评价准则

- 确定性建模：确定一个工作量，然后计算每个算法的表现；
- 队列模型：用来处理随机工作负载的数学方法；
- 实现/模拟：建立一个允许算法运行实际数据的系统。 

## 8.5 实时调度

### 8.5.1 实时系统 

- 定义：正确性依赖于其时间和功能两方面的一种操作系统；
- 性能指标：**时间约束的及时性**(deadlines);**速度和平均性能相对不重要；**
- 主要特性：时间约束的可预测性；
- 强实时系统：需要在保证的时间内完成重要的任务，必须完成；
- 弱实时系统：要求重要的进程的优先级更高，尽量完成，并非必须；

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143814693.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

-  硬时限：
  - 如果错过了最后期限，可能会发生灾难性或非常严重的后果；
  - 必须验证：在最坏的情况下也能够满足时限吗？
  - 保证确定性；

- 软时限：
  - 理想情况下，时限应该被最大满足。如果有时限没有被满足，那么就相应地降低要求；
  - 尽最大努力去保证； 

### 8.5.2 可调度性

- 静态优先级调度：运行之前优先级就是确定的；
- 动态优先级调度：优先级在运行中是动态变化的； 
- RM(Rate Monotonic)速率单调调度
  - 最佳静态优先级调度
  - 通过周期安排优先级
  - 周期越短，优先级越高
  - 先执行周期最短的任务

- EDbF(Earliest Deadline First)最早期限调度
  - 最佳的动态优先级调度
  - Deadline越早，或者说纪录DeadLine越近优先级越高
  - 先执行Deadline最早的任务

## 8.6 多处理器调度与优先级反转

### 8.6.1 多处理器调度的原因

-  多处理器的CPU调度更加复杂(多个相同的单处理器组成一个多处理器；它的优点是负载共享)；还有对称多处理器(SMP)(每个处理器运行自己的调度程序；需要在调度程序中同步)； 

### 8.6.2 优先级反转

-  优先级反转可以发生在任何基于优先级的可抢占的调度机制；
- **当系统内的环境强制使高优先级任务等待低优先级任务时发生。**；
- 发生在NASA火星探测机器人上面的操作系统
- 优先级反转的持续时间取决于其它不相关任务的不可预测的行为
  在这种情况下，高优先级可能比低优先级任务晚完成。例如下图，优先级T1>T2>T3。 

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200109143911935.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2l3YW5kZXJ1,size_16,color_FFFFFF,t_70) 

- 首先时间轴上，只有T3有任务，所以在t1-t3是T3在执行；
  到t2的时候，T3访问了一个蓝色的贡献资源(T1在t4时也要用)；
  到了t3时，T1出现了，它的优先级更高，所以T3中断，T1执行；直到t4时刻，T1需要使用T3占用的蓝色资源释放后才能继续执行，所以把CPU让给T3；
  t4-t5是T3执行，t5时，此时T2出现，优先级比T3高，所以T3终止，执行T2；
  T2执行完后，T3在时间t6-t7中释放了蓝色共享资源，T1才能继续执行。
  这里出现了个奇怪的现象，**也就是优先级更高的T1，需要等T2运行完才能执行。**
- 还有一种优先级反转的可能性：在课本P72页说过，就是说T3占用了共享资源，然后T1就绪，切换到T1，然后运行到临界区进不去，进入忙等待，但由于T1就绪时，T3不会被调度，T3也就无法离开临界区，T1将永远地忙等待下去。
- 优先级继承： 低优先级任务即成高优先级任务的优先级，这个依赖于他们共享的资源。此时T3的优先级会动态的得到提升，取得和T1一样的优先级，所以T3执行完才能T2，此时T2无法抢占T3。 
- 优先级天花板：
- “拥有资源”的优先级和“所有可以锁定该资源任务中优先级最高的那个任务”的优先级相同(T3拥有T1的资源，所以它的优先级提升到T1)；
- 除非当前进程的优先级高于系统中所有被锁定的资源的优先级的上线，否则任务尝试执行临界区的时候会被阻塞；
- 持有最高优先级上限信号量锁的任务，会继承被该锁所阻塞的任务的优先级。
  