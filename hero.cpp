#include<iostream>

using namespace std;
class people {//�½�����
public:
    string name1;
    int age1, hight1, blood1;
    string id1;

    virtual void fight() {//�麯��
        cout << "��������" << endl;
    }
    virtual void defend() {

    }

private:
};

class m4a1 :public people {//�½�����̳���people
public:
    void fight() override {//��д�麯��
        cout << "m4a1������һ��" << endl;
    }
    void defend() override {
        cout << "m4a1������һ��" << endl;
    }

};
class ak12 :public people {
public:
    void fight() override {
        cout << "ak12������һ��" << endl;
    }
    void defend() override {
        cout << "ak12������һ��" << endl;
    }
};
