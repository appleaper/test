torch，opencv一起使用.md



填充：

```c++
#include <torch/torch.h>
#include "torch/script.h"

using namespace std;
int main() {   
    torch::Tensor a1 = torch::rand({2,3});	//随机函数
    torch::Tensor a2 = torch::full_like(tmp_1,1);	//填充函数
    torch::Tensor a3 = torch::ones({2, 4});		//ones函数
    torch::Tensor a4 = torch::full({ 2,3 }, -2, torch::dtype(torch::kLong));
	torch::Tensor a5 = torch::ones({3,2}).fill_(-8);
    cout<<a1<<endl;
    cout<<a2<<endl;
    cout<<a3<<endl;
    cout<<a4<<endl;
    cout<<a5<<endl;
}
```



拼接

```c++
int main() {   
    torch::Tensor a = torch::rand({2,3});
    torch::Tensor b = torch::rand({2,1});
    torch::Tensor cat_1 = torch::cat({a,b},1);//按列拼接--》》前提是行数需要一样
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<cat_1<<std::endl;

}
```



取指定的某一行或某一列

```c++
int main() {  
	torch::Tensor a = torch::rand({2,3});
    std::cout<<a<<std::endl;
    torch::Tensor b = a.select(0,1);//按行取 0是按行取，1是第2行
    std::cout<<b<<std::endl;
}
```

select是一种浅拷贝



squeeze维度压缩

```
    torch::Tensor a = torch::rand({1,1,3});
    std::cout<<a<<std::endl;
    
    torch::Tensor b = a.squeeze();
    std::cout<<b<<std::endl;
    
    torch::Tensor c = a.squeeze(0);
    std::cout<<c<<std::endl;
    
    torch::Tensor d = a.squeeze(1);
    std::cout<<d<<std::endl;
    
    torch::Tensor e = a.squeeze(2);
    std::cout<<e<<std::endl;
```



输出非0的坐标

```
int main() {  
torch::Tensor a = torch::rand({2,3});
    a[0][1] = 0;
    a[1][2] = 0;
    std::cout<<a<<std::endl;
    torch::Tensor b = torch::nonzero(a);
    std::cout<<b<<std::endl;
}
```





