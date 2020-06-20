### 使用loguru

#### 安装

```
pip install loguru
```

#### 基本使用

```python
from loguru import logger
logger.debug('this is another debug message')
```

直接引入一个 `logger`，然后调用其 `debug`方法即可。

可以看到其默认的输出格式是上面的内容，有时间、级别、模块名、行号以及日志信息，不需要手动创建 `logger`，直接使用即可，另外其输出还是彩色的，看起来会更加友好。

以上的日志信息是直接输出到控制台的，并没有输出到其他的地方，如果想要输出到其他的位置，比如存为文件，我们只需要使用一行代码声明即可。

例如将结果同时输出到一个 runtime.log 文件里面，可以这么写：

```python
from loguru import logger

trace = logger.add('runtime.log')
logger.debug('this is another debug message')
```

#### 详细使用

**基本参数**

使用`format`、`filter`、`level`来规定输出的格式：

```python
logger.add('runtime.log', format="{time} {level} {message}", filter="my_module", level="INFO")
```

**删除sink**

另外添加 `sink` 之后我们也可以对其进行删除，相当于重新刷新并写入新的内容。

```pyhon
from loguru import logger
 
trace = logger.add('runtime.log')
logger.debug('this is a debug message')
logger.remove(trace)
logger.debug('this is another debug message')
```

看这里，我们首先 `add` 了一个 `sink`，然后获取它的返回值，赋值为 `trace`。随后输出了一条日志，然后将 `trace` 变量传给`remove` 方法，再次输出一条日志，看看结果是怎样的。

可以发现，在调用 `remove` 方法之后，确实将历史 `log` 删除了。

这样我们就可以实现日志的刷新重新写入操作

**rotation 配置**

用了 `loguru` 我们还可以非常方便地使用`rotation` 配置，比如我们想一天输出一个日志文件，或者文件太大了自动分隔日志文件，我们可以直接使用 `add` 方法的 `rotation` 参数进行配置。

```python
logger.add('runtime_{time}.log', rotation="500 MB")
```

通过这样的配置我们就可以实现每 500MB 存储一个文件，每个 log 文件过大就会新创建一个 log 文件。我们在配置 log 名字时加上了一个 `time` 占位符，这样在生成时可以自动将时间替换进去，生成一个文件名包含时间的 log 文件。

另外我们也可以使用 `rotation` 参数实现定时创建 log 文件，例如：

```python
logger.add('runtime_{time}.log', rotation='00:00')
```

这样就可以实现每天 0 点新创建一个 log 文件输出了。

另外我们也可以配置 log 文件的循环时间，比如每隔一周创建一个 log 文件，写法如下：

```python
logger.add('runtime_{time}.log', rotation='1 week')
```

这样我们就可以实现一周创建一个 log 文件了。

**retention 配置**

很多情况下，一些非常久远的 log 对我们来说并没有什么用处了，它白白占据了一些存储空间，不清除掉就会非常浪费。`retention` 这个参数可以配置日志的最长保留时间。

比如我们想要设置日志文件最长保留 10 天，可以这么来配置：

```python
logger.add('runtime.log', retention='10 days')
```

这样 log 文件里面就会保留最新 10 天的 log，妈妈再也不用担心 log 沉积的问题啦。

**compression 配置**

`loguru` 还可以配置文件的压缩格式，比如使用 `zip` 文件格式保存，示例如下：

```python
logger.add('runtime.log', compression='zip')
```

这样可以更加节省存储空间。

**enqueue配置**

`loguru`可以配置在多进程同时往日志文件写日志的时候使用队列达到异步功效。

```python
logger.add("somefile.log", enqueue=True)  # 异步写入
```

**字符串格式化**

`loguru` 在输出 log 的时候还提供了非常友好的字符串格式化功能，像这样：

```python
logger.info('If you are using Python {}, prefer {feature} of course!', 3.6, feature='f-strings')
```

这样在添加参数就非常方便了。

**Traceback 记录**

在很多情况下，如果遇到运行错误，而我们在打印输出 log 的时候万一不小心没有配置好 Traceback 的输出，很有可能我们就没法追踪错误所在了。

但用了 loguru 之后，我们用它提供的装饰器就可以直接进行 Traceback 的记录，类似这样的配置即可：

```python
@logger.catch
def my_function(x, y, z):
    # An error? It's caught anyway!
    return 1 / (x + y + z)
```

我们做个测试，我们在调用时三个参数都传入 0，直接引发除以 0 的错误，看看会出现什么情况：

```
my_function(0, 0, 0)
```

运行完毕之后，可以发现 log 里面就出现了 Traceback 信息，而且给我们输出了当时的变量值，真的是不能再赞了！结果如下：

```python
> File "run.py", line 15, in <module>
    my_function(0, 0, 0)
    └ <function my_function at 0x1171dd510>
 
  File "/private/var/py/logurutest/demo5.py", line 13, in my_function
    return 1 / (x + y + z)
                │   │   └ 0
                │   └ 0
                └ 0
 
ZeroDivisionError: division by zero
```



一段改写后的代码片段

```python
from virtex.config import Config
import argparse
import virtex.utils.distributed as dist
import torch
import random
import numpy as np
from loguru import logger
import os
import sys

def common_setup(_C: Config, _A: argparse.Namespace, job_type: str = "pretrain"):
    # 1.设置随机种子
    torch.manual_seed(0)
    random.seed(0)
    np.random.seed(0)

    # 2.保存配置副本
    os.makedirs('./temp/test', exist_ok=True)    #创建目录
    _C.dump(os.path.join('./temp/test', f"{job_type}_config.yaml"))  # 保存设置文件副本

    # 3.记录日志
    logger.remove(0)    # 删除默认日志
    logger.add(     # 添加日志对象
        './temp/test/runtime.log', format="{time}: {message}", colorize=True,rotation='10 MB',retention='7 day'
    )
    # Print process info, config and args.
    logger.info(f"Rank of current process: 0. World size: 100")   # 记录日志
    logger.info(str(_C))    #记录_C的配置

    logger.info("Command line args:")
    for arg in vars(_A):
        logger.info("{:<20}: {}".format(arg, getattr(_A, arg)))
```

总体上就是这么使用的，要是你不想记录到文件中，可以吧runtime.log这里的地址改为sys.stdout，记得引入sys包.但是要去掉rotation，retention的内容，因为它直接打印到屏幕上了，所以就没有保存上限大小和保存时间这么一说了，不去掉的话，那是会报错的
