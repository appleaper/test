[原地址：https://github.com/ultralytics/yolov3](https://github.com/ultralytics/yolov3)

### 新意点：

每10batch就调整一下图片的大小（adjust (67%% - 150%%) img_size every 10 batches）

缓存图像以进行更快的训练

训练为单类数据集

冻结非输出层

### 检查git是否是最新的

Python3中的subprocess.check_output函数可以执行一条sh命令

```python
def check_git_status():
    '''
    检查git是否是最新的（只有linux，Darwin系统有效）
    '''
    if platform in ['linux', 'darwin']:     #要是是这两种系统其中一种
        # Suggest 'git pull' if repo is out of date
        # Python3中的subprocess.check_output函数可以执行一条sh命令，并返回命令的输出内容
        s = subprocess.check_output('if [ -d .git ]; then git fetch && git status -uno; fi', shell=True).decode('utf-8')
        if 'Your branch is behind' in s:
            print(s[s.find('Your branch is behind'):s.find('\n\n')] + '\n')
```



### glob.glob()

返回所有匹配的文件路径列表。它只有一个参数pathname，定义了文件路径匹配规则，这里可以是绝对路径，也可以是相对路径。

```python
import glob

#获取指定目录下的所有图片
print (glob.glob(r"C:\\Users\\Administrator\\Desktop\\opencv\\*.jpg"),"\n")#加上r让字符串不转义

#获取上级目录的所有.py文件
print (glob.glob(r'../*.py')) #相对路径
```



### 检查是不是有哪些文件

```python
def check_file(file):
    # Searches for file if not found locally
    if os.path.isfile(file):
        return file
    else:
        files = glob.glob('./**/' + file, recursive=True)  # find file
        assert len(files), 'File Not Found: %s' % file  # assert file was found
        return files[0]  # return first file if multiple found
```



自动寻找设备（cpu，gpu）

apex是减速训练，减少训练时间

```python
device = torch_utils.select_device(opt.device, apex=mixed_precision, batch_size=opt.batch_size)
```



round是四舍五入



### math.fmod(y,x)和y%x的区别

y%x和math.fmod(y,x) 公式相同
y%x = y - (y/x)*x
math.fmod(y,x) = y - (y/x)*x
两种运算方法的公式相同，区别在于y/x的取值方法不同：
y%x中的y/x倾向于向下取整（在为负数时候，远离0的方向），而math.fmod中的y/x倾向于向0的方向取整

举例如下：

1. y%x
   -3%2= -3 -（-3/2）*2 =-3 - math.floor(-1.5)*2 =-3 - (-2)*2 =1 //在为负数的时候，向远离0的方向，-1.5即-2

2. math.fmod(y,x)
   math.fmod(-3,2) = -3 -（-3/2）*2= -3 - math.floor( -1.5) *2 = -3 - (-1) *2 = -1

3. y%x
   3%2 = 3 - （3/2）*2 = 3 - （1.5）2 =3 - 12 =1

4. math.fmod(y,x)
   math.fmod(3,2) =3 - （3/2）*2= 3 - （1.5）2 = 3- 12 = 1
   ****解释：****Math.floor() 返回小于或等于一个给定数字的最大整数



### a|b

```
a = 0011 1100
b = 0000 1101
a|b = 0011 1101
```



a//b:	取整除 - 返回商的整数部分（**向下取整**）

9//2  -> 4		-9//2  -> -5



### 解析配置文件

功能：1.加载配置文件 	2.读取文件（切片，去空格）

strip和split的区别

```python
def parse_data_cfg(path):
    # Parses the data configuration file    ＃解析数据配置文件
    if not os.path.exists(path) and os.path.exists('data' + os.sep + path):  # add data/ prefix if omitted  添加数据/前缀（如果省略）
        path = 'data' + os.sep + path

    with open(path, 'r') as f:
        lines = f.readlines()

    options = dict()
    for line in lines:
        line = line.strip()     # strip() 方法用于移除字符串头尾指定的字符（默认为空格或换行符）或字符序列。
        if line == '' or line.startswith('#'):  # 要是为空或者是注解行
            continue
        key, val = line.split('=')      # split() 通过指定分隔符对字符串进行切片，如果参数 num 有指定值，则分隔 num+1 个子字符串
        options[key.strip()] = val.strip()

    return options
```



Python rstrip() 删除 string 字符串末尾的指定字符（默认为空格）.

```python
#!/usr/bin/python

str = "     this is string example....wow!!!     ";
print str.rstrip();
str = "88888888this is string example....wow!!!8888888";
print str.rstrip('8');

结果：
     this is string example....wow!!!
88888888this is string example....wow!!!
```



Python lstrip() 方法用于截掉字符串左边的空格或指定字符。

```python
#!/usr/bin/python

str = "     this is string example....wow!!!     ";
print str.lstrip();
str = "88888888this is string example....wow!!!8888888";
print str.lstrip('8');

结果：
this is string example....wow!!!
this is string example....wow!!!8888888
```



isnumeric( ):检测字符串是否只由数字组成，如果字符串中只包括数字，就返回Ture，否则返回False

```
v='123'
v.isnumeric( )

out:True
```



### 三种激活函数：

```python
if mdef['activation'] == 'leaky':  # activation study https://github.com/ultralytics/yolov3/issues/441  研究激活
    modules.add_module('activation', nn.LeakyReLU(0.1, inplace=True))
elif mdef['activation'] == 'swish':
    modules.add_module('activation', Swish())   # sigmoid
elif mdef['activation'] == 'mish':
    modules.add_module('activation', Mish())
    
    
class Swish(nn.Module):
    def forward(self, x):
        return x * torch.sigmoid(x)
    
    
class Mish(nn.Module):  # https://github.com/digantamisra98/Mish
    def forward(self, x):
        return x * F.softplus(x).tanh()
```

激活函数ReLU、Leaky ReLU

ReLu就是在正值区间就等于原值，负值区间就等于0.Leaky ReLU就是负值区间非零。可以继续负值

sigmoid比较怕梯度消失和爆炸，因为这个原因才有了ReLU

ReLU怕学习率很大，所以又有了Softplus，这个和ReLU很像，ReLU是直来直去，而Softplus是ReLU的平滑版

[激活函数ReLU、Leaky ReLU、PReLU和RReLU](https://blog.csdn.net/qq_23304241/article/details/80300149)

[_sigmoid、softplus与Relu](https://blog.csdn.net/bqw18744018044/article/details/81193241)



### linux解压和压缩命令

zip:

zip all.zip *.jpg 	#将所有.jpg的文件压缩成一个zip包

unzip all.zip 	#将all.zip中的所有文件解压到当前目录中

unzip all.zip -d all #将all.zip 中的所有文件解压到当前目录中的all文件夹中

zip -r hy.zip hy #将当前目录下的hy文件夹压缩为hy.zip

zip -r hy.zip hy 123.txt #将当前目录下的hy文件夹和123.txt压缩为hy.zip

**解压**

tar -xvf file.tar //解压 tar包

tar -xzvf file.tar.gz //解压tar.gz

tar -xjvf file.tar.bz2  //解压 tar.bz2

tar -xZvf file.tar.Z  //解压tar.Z

unrar e file.rar //解压rar

unzip file.zip //解压zip



### AdaBound优化器

[github地址](https://github.com/Luolc/AdaBound)

[原文地址](https://openreview.net/pdf?id=Bkg3g2R9FX)

**SGD的缺点**

SGD现在后期调优时还是经常使用到，但SGD的问题是前期收敛速度慢。**SGD前期收敛慢的原因： SGD在更新参数时对各个维度上梯度的放缩是一致的，并且在训练数据分布极不均很时训练效果很差**。

 **Adam等自适应学习率算法缺点：**

这就是目前很多大牛任然喜欢SGD的原因。这篇文章对于Adam后期的毛病进行了分析，原因出在自适应方法训练后期不稳定的极端学习率。换句话说，就是**自适应学习率训练到后期，学习率出现极端情况，更新参数时有些维度上学习率特别大，有些维度学习率特别小**。

换句话说，Adam和SGD是AdaBound的特殊情况。

在这一设置下，在训练早期由于上下界对学习率的影响很小，算法更加接近于 Adam；而随着时间增长裁减区间越来越收紧，模型的学习率逐渐趋于稳定，在末期更加贴近于 SGD。AMSBound 可以对 AMSGrad 采用类似的裁剪得到。



### 映射：

```
print(list(map(lambda x, y: (x ** y, x+y), [2, 4, 6], [3, 2,1])))
output:[(8, 5), (16, 6), (6, 7)]
```





