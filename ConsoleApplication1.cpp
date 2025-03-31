// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include<Windows.h>//头文件要先包含windows。h再包含mmsystem。h，否则会导致宏定义冲突报错,但为什么这样就不会报错呢?
#include<iostream>
#include"ground_loading.h"
#include<regex>
#include"hero.cpp"
#include"story.h"
#include<thread>
#include<mmsystem.h>

#pragma comment (lib,"winmm.lib")
void music(void) {
      mciSendString(TEXT("open \"D:\\c++learn\\homeworks\\ConsoleApplication1\\ConsoleApplication1\\WindyHill.mp3\" alias song") ,NULL, 0, NULL);
      mciSendString(TEXT(" play song repeat"), NULL, 0, NULL);
      Sleep(20000);
}


int main()
{
    //people m("张三", 120,56,100,"12345");

    //m().information_wrriten(, 18, 100);
    //m.show();
    std::thread t(music);

    story();
    story_1();
    people* animal = new m4a1;
    animal->fight();
    people* people = new ak12;
    people->fight();
    animal->defend();
    out();
    t.join();
}
/*#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 基类：魔法宠物
class MagicPet {
protected:
    string name;
    int hp;
public:
    MagicPet(string n, int h) : name(n), hp(h) {}

    // 虚方法 - 战斗技能
    virtual void specialSkill() {
        cout << name << " 使用了普通撞击！" << endl;
    }

    // 虚析构函数
    virtual ~MagicPet() {
        cout << name << " 回到了魔法球\n";
    }
};

// 派生类：火焰狐狸
class FlameFox : public MagicPet {
public:
    FlameFox() : MagicPet("🔥火焰阿狸", 120) {}

    void specialSkill() override {
        cout << name << " 甩出九条火尾！" << endl;
        cout << "=== 引发持续燃烧效果 ===" << endl;
    }
};

// 派生类：寒冰仓鼠
class IceHamster : public MagicPet {
public:
    IceHamster() : MagicPet("❄️冰镇仓鼠", 150) {}

    void specialSkill() override {
        cout << name << " 发射寒冰瓜子连弹！" << endl;
        cout << "=== 造成冰冻减速效果 ===" << endl;
    }
};

// 派生类：雷电熊猫
class ThunderPanda : public MagicPet {
public:
    ThunderPanda() : MagicPet("⚡霹雳熊猫", 200) {}

    void specialSkill() override {
        cout << name << " 召唤雷云翻滚！" << endl;
        cout << "=== 触发电网麻痹效果 ===" << endl;
    }
};

// 战斗模拟器
class BattleSimulator {
private:
    vector<unique_ptr<MagicPet>> pets;
public:
    void addPet(MagicPet* pet) {
        pets.emplace_back(pet);
    }

    void startBattle() {
        cout << "\n===== 魔法宠物大乱斗 =====" << endl;
        for (auto& pet : pets) {
            pet->specialSkill(); // 多态调用
        }
        cout << "=========================\n" << endl;
    }
};

int main() {
    BattleSimulator arena;

    // 创建宠物
    arena.addPet(new FlameFox());
    arena.addPet(new IceHamster());
    arena.addPet(new ThunderPanda());

    // 特殊隐藏宠物
    arena.addPet(new MagicPet("神秘黑影", 999)); // 使用基类默认技能

    // 开始战斗
    arena.startBattle();

    return 0;
}*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
