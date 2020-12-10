#include <iostream>
using namespace std;

//将零件写为抽象类
//CPU类
class Cpu
{
public:
    //纯虚函数
    virtual void calculete() = 0; //CPU是用于计算的。
};

//显卡类
class Videocard
{
public:
    //纯虚函数
    virtual void display() = 0; //显卡用于显示的。
};

//内存条
class Memory
{
public:
    virtual void storage() = 0; //内存条负责储存的
};

class IntelCpu : public Cpu
{
public:
    virtual void calculete()
    {
        cout << "Intel的cpu正在计算了" << endl;
    }
};

class IntelVideocard : public Videocard
{
public:
    virtual void display()
    {
        cout << "Intel的显卡正在显示了" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel的内存条开始储存了" << endl;
    }
};

class LenovoCpu : public Cpu
{
public:
    virtual void calculete()
    {
        cout << "Lenovo的cpu正在计算了" << endl;
    }
};

class LenovoVideocard : public Videocard
{
public:
    virtual void display()
    {
        cout << "Lenovo的显卡正在显示了" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenovo的内存条开始储存了" << endl;
    }
};

class Computer
{
public:
    Computer(Cpu *cpu, Videocard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    //电脑工作的函数
    void work()
    {
        m_cpu->calculete();
        m_vc->display();
        m_mem->storage();
    }

    ~Computer()
    {
        //释放CPU
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        //释放显卡零件
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }

        //释放内存条
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    Cpu *m_cpu;      //指向CPU零件的指针
    Videocard *m_vc; //指向显卡的零件的指针
    Memory *m_mem;   //指向内存条的零件的指针
};

int main()
{
    cout << "第一台电脑的组装:" << endl;
    Cpu *intelCpu = new IntelCpu;
    Videocard *intelcard = new IntelVideocard;
    Memory *intelMem = new IntelMemory;

    //创建第一台电脑
    Computer *computer1 = new Computer(intelCpu, intelcard, intelMem);
    computer1->work();
    delete computer1;

    cout << "---------------------------------------" << endl;

    cout << "第二台电脑的组装:" << endl;
    //创建第二台电脑
    Computer *computer2 = new Computer(new LenovoCpu, new LenovoVideocard, new LenovoMemory);
    computer2->work();
    delete computer2;
    cout << "---------------------------------------" << endl;

    cout << "第三台电脑的组装:" << endl;
    Computer *computer3 = new Computer(new LenovoCpu, new IntelVideocard, new LenovoMemory);
    computer3->work();
    delete computer3;

    return 0;
}