#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Player
{
public:
    string m_Name;
    int m_Score;

    Player(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
    ~Player() {}
};

void createPlayer(vector<Player> &v)
{
    string nameSeed = "ABCDE";
    int i, score;
    string name;
    for (i = 0; i < nameSeed.length(); i++)
    {
        name = "选手";
        name += nameSeed[i];
        score = 0;

        Player p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Player> &v)
{
    int i, score;
    for (vector<Player>::iterator it = v.begin(); it != v.end(); ++it)
    {
        deque<int> d;
        for (i = 0; i < 10; i++)
        {
            score = rand() % 41 + 60;
            d.push_back(score);
        }

        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}

void showScore(vector<Player> &v)
{
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名" << (*it).m_Name << " 平均分:" << (*it).m_Score << endl;
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    vector<Player> v;
    createPlayer(v);
    setScore(v);
    showScore(v);

    return 0;
}
