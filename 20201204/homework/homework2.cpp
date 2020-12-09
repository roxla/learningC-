#include <iostream>
using namespace std;

class Person
{
private:
    int p_Num;
    int p_Quantity;
    float p_Price;

public:
    Person(int num, int quantity, float price) : p_Num(num), p_Quantity(quantity), p_Price(price)
    {
        // cout << "Person的有参构造函数" << endl;
    }
    int get_num()
    {
        return p_Num;
    }
    int get_quantity()
    {
        return p_Quantity;
    }
    float get_price()
    {
        return p_Price;
    }
    ~Person()
    {
        // cout << "Person的析构函数" << endl;
    }
};

class Shop
{
private:
    static Person s_1;
    static Person s_2;
    static Person s_3;

public:
    static float shop_all_cash()
    {
        float sum = s_1.get_quantity() * s_1.get_price() +
                    s_2.get_quantity() * s_2.get_price() +
                    s_3.get_quantity() * s_3.get_price();
        return sum;
    }
    static float shop_aver_cash()
    {
        int all_num = s_1.get_quantity() + s_2.get_quantity() + s_3.get_quantity();
        float aver = shop_all_cash() / all_num;
        return aver;
    }
};

Person Shop::s_1(101, 5, 23.5);
Person Shop::s_2(102, 12, 24.56);
Person Shop::s_3(103, 100, 21.5);

int main(int argc, char const *argv[])
{
    cout << "当日此商品的总销售款: " << Shop::shop_all_cash() << "元" << endl;
    cout << "每件商品的平均售价: " << Shop::shop_aver_cash() << "元" << endl;
    return 0;
}
