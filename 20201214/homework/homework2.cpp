#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
1、案例描述：
1）公司今天招聘了10个员工(ABCDEFGHIJ),10名员工进入公司后，需要指派员工在哪个部门工作。
2）员工信息有：姓名 工资组成; 部门分为：策划、美术、研发
3）随机给10名员工分配部门和工资
4）通过multimap进行信息的插入 key(部门编号) value(员工)
5）分部门显示员工信息

2、实现步骤
1、创建10名员工，放到vector中。
2、遍历vector容器，取出每一个员工，进行随机分组。
3、分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
4、分部门显示员工信息。
*/

#define CHEHUA 0
#define MEISHU 1
#define YANFA 2

//设计员工类
class Worker
{
public:
    string m_Name;
    int m_Wage;
};

void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    Worker worker;
    int i;

    for (i = 0; i < 10; i++)
    {
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Wage = rand() % 10000 + 10000; //10000~19999

        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    int deptid;
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号。
        deptid = rand() % 3; //012

        //将员工插入到分组中。
        //key作为部门编号，value就是具体的员工。
        m.insert(make_pair(deptid, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
    //0: ABC  1: DE  2 FG
    cout << "策划部门:" << endl;
    multimap<int, Worker>::iterator pos = m.find(CHEHUA); //找到策划部门的第一个人的迭代器
    int count = m.count(CHEHUA);                          //统计策划部门的人数

    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << "  工资:" << pos->second.m_Wage << endl;
    }

    cout << "------------------------------------" << endl;
    cout << "美术部门:" << endl;
    pos = m.find(MEISHU);    //找到美术部门的第一个人的迭代器
    count = m.count(MEISHU); //统计美术部门的人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << "  工资:" << pos->second.m_Wage << endl;
    }

    cout << "------------------------------------" << endl;
    cout << "研发部门:" << endl;
    pos = m.find(YANFA);    //找到研发部门的第一个人的迭代器
    count = m.count(YANFA); //统计研发部门的人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << "  工资:" << pos->second.m_Wage << endl;
    }
}

int main()
{
    //0. 添加随机数种子
    srand((unsigned int)time(NULL));

    //1. 创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    //测试
    /*
	for(vector<Worker>::iterator it = vWorker.begin() ; it!=vWorker.end() ; it++)
	{
		cout << "姓名: " << it->m_Name << "  工资:" << it->m_Wage << endl;
	}
	*/

    //2. 员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    //3. 分组显示员工的信息
    showWorkerByGroup(mWorker);

    return 0;
}