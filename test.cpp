#include <iostream>
using namespace std;

int a = 12;
class Man
{
private:
    string name;
    uint64_t age;

public:
    string getName()
    {
        return name;
    }
    void setName(string names)
    {
        name = names;
    }
};
int main()
{
    string s = "sfsfsfs";
    s.append("年好吗");
    cout << s << endl;
    // system("chcp 65001");
    cout << "sdfsf" << a << endl;
    cout << "Hello, world! " << endl;

    string na = "fsfsf";
    cout << na << endl;
    auto man = new Man();
    man->setName("小明");
    string bb = man->getName();
    cout << bb << endl;
    delete man;
    return 0;
}