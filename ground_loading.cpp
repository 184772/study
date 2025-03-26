
#include"ground_loading.h"
#include<regex>
#include<string>
#include<fstream>
void resign();


class file_read {//文件读类，用虚函数给出要求读的内容
public:
	virtual void detail(string::const_iterator iterStart, string::const_iterator iterEnd, smatch results) {
		cout << "调用了虚函数detail基类" << endl;
	}
	string read() {
		FILE* file1;
		if (0 == fopen_s(&file1, ".\\information.txt", "r"))
		{
			cout << "读取成功" << endl;
			fseek(file1, 0, SEEK_END);
			int nsize = ftell(file1);
			fseek(file1, 0, SEEK_SET);
			string buf;//内存开辟空间存储文件中的信息//从文件中读取信息的原理是先在内存创建文件流，打开文件用fread函数将文件内容传入文件流，创建开始结束迭代器（理解为文件流开始与结束的指针），用regex_search搜索并存入results(其声明类型类似于结构体)中
			buf.resize(nsize + 1);
			fread((char*)buf.c_str(), sizeof(char), nsize, file1);
			fclose(file1);

			smatch results;//存储匹配的项
			if (regex_search(buf, results, regex("key(\\d+)")))
			{
				string::const_iterator iterStart = buf.begin();
				string::const_iterator iterEnd = buf.end();

				detail(iterStart, iterEnd, results);
				return results.str();
			}
			else cout << "error" << endl;

		}
		else cout << "登录文件打开失败" << endl;

	}

private:
};

class user_design :public file_read {//读取用户登录密码,子类
public:
	void detail(string::const_iterator iterStart, string::const_iterator iterEnd, smatch results) override {
		while (regex_search(iterStart, iterEnd, results, regex("key(\\d+)")))
		{
			cout << results[0] << endl;
			iterStart = results[0].second;//这里的second表示当前匹配位置结束的迭代器

		}

	}
	void design() {//登录
		string password;
		cout << "请输入密码" << endl;
		cin >> password;
		string u = read();
		if (password == u)
		{
			cout << "密码正确" << endl;
		}
		else cout << "密码错误" << endl;
	}
};

class file_write {
public:

	void write(string password) {
		ofstream file(".\\information.txt");//打开文件，可以写入变量，注意，这是一个构造函数；
		if (file.is_open())
		{
			cout << "读取成功" << endl;
			file << "key" << password << endl;
			//fprintf_s(file1,"123456781234567812345678");//写入文件后，如果要读取文件要关闭后重新打开
			file.close();
		}
		else { cout << "注册打开文件失败" << endl; }
	}
private:
};






void k(void) //账号管理
{
	
	user_design p;
	file_write z;

	int m = 0;
	cout << "登录(1)或者注册(2)" << endl;
	cin >> m;
	if (m == 1)
	{
		p.design();
	}
	else if (m == 2)
	{
		string password;
		cout << "请注册密码" << endl;
		cin >> password;
		z.write(password);
	}

}


	

