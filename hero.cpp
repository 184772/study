#include<iostream>

using namespace std;
class people {//新建父类
public:
    string name1;
    int age1, hight1, blood1;
    string id1;

    virtual void fight() {//虚函数
        cout << "发动攻击" << endl;
    }
    virtual void defend() {

    }

private:
};

class m4a1 :public people {//新建子类继承于people
public:
    void fight() override {//重写虚函数
        cout << "m4a1攻击了一次" << endl;
    }
    void defend() override {
        cout << "m4a1防御了一次" << endl;
    }

};
class ak12 :public people {
public:
    void fight() override {
        cout << "ak12攻击了一次" << endl;
    }
    void defend() override {
        cout << "ak12防御了一次" << endl;
    }
};
