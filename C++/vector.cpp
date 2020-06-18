#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i = 0;
    vector<int> vec;
    for (i = 0; i < 10; i++)
    {
        vec.push_back(i);   //插入数据
    }
    cout << "****************" << endl;

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << "初始化遍历：" << vec[i] << endl;
    }
    //结果为：０，１，２，３，４，５，６，７，８，９
    cout << "****************" << endl;


    vector<int>::iterator it;       //变成一个迭代器
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << "迭代遍历：" << *it << endl;
    }
    //结果为：０，１，２，３，４，５，６，７，８，９
    cout << "****************" << endl;
    
    vec.insert(vec.begin() + 4, 0);     //插入元素
    //结果为:11
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << "插入遍历：" << vec[i] << endl;
    }
    //结果为：０，１，２，３，０，４，５，６，７，８，９
    cout << "****************" << endl;

    vec.erase(vec.begin() + 2);     //删除元素
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << "擦除遍历：" << vec[i] << endl;
    }
    //结果为：０，１，３，０，４，５，６，７，８，９
    cout << "****************" << endl;

    vec.erase(vec.begin() + 3, vec.begin() + 5);    //区间删除元素
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << "迭代遍历：" << *it << endl;
    }
    //结果：0,1,3,5,6,7,8,9
    return 0;
}
