
#include"ground_loading.h"
#include<regex>
#include<string>
#include<fstream>
void resign();


class file_read {//�ļ����࣬���麯������Ҫ���������
public:
	virtual void detail(string::const_iterator iterStart, string::const_iterator iterEnd, smatch results) {
		cout << "�������麯��detail����" << endl;
	}
	string read() {
		FILE* file1;
		if (0 == fopen_s(&file1, ".\\information.txt", "r"))
		{
			cout << "��ȡ�ɹ�" << endl;
			fseek(file1, 0, SEEK_END);
			int nsize = ftell(file1);
			fseek(file1, 0, SEEK_SET);
			string buf;//�ڴ濪�ٿռ�洢�ļ��е���Ϣ//���ļ��ж�ȡ��Ϣ��ԭ���������ڴ洴���ļ��������ļ���fread�������ļ����ݴ����ļ�����������ʼ���������������Ϊ�ļ�����ʼ�������ָ�룩����regex_search����������results(���������������ڽṹ��)��
			buf.resize(nsize + 1);
			fread((char*)buf.c_str(), sizeof(char), nsize, file1);
			fclose(file1);

			smatch results;//�洢ƥ�����
			if (regex_search(buf, results, regex("key(\\d+)")))
			{
				string::const_iterator iterStart = buf.begin();
				string::const_iterator iterEnd = buf.end();

				detail(iterStart, iterEnd, results);
				return results.str();
			}
			else cout << "error" << endl;

		}
		else cout << "��¼�ļ���ʧ��" << endl;

	}

private:
};

class user_design :public file_read {//��ȡ�û���¼����,����
public:
	void detail(string::const_iterator iterStart, string::const_iterator iterEnd, smatch results) override {
		while (regex_search(iterStart, iterEnd, results, regex("key(\\d+)")))
		{
			cout << results[0] << endl;
			iterStart = results[0].second;//�����second��ʾ��ǰƥ��λ�ý����ĵ�����

		}

	}
	void design() {//��¼
		string password;
		cout << "����������" << endl;
		cin >> password;
		string u = read();
		if (password == u)
		{
			cout << "������ȷ" << endl;
		}
		else cout << "�������" << endl;
	}
};

class file_write {
public:

	void write(string password) {
		ofstream file(".\\information.txt");//���ļ�������д�������ע�⣬����һ�����캯����
		if (file.is_open())
		{
			cout << "��ȡ�ɹ�" << endl;
			file << "key" << password << endl;
			//fprintf_s(file1,"123456781234567812345678");//д���ļ������Ҫ��ȡ�ļ�Ҫ�رպ����´�
			file.close();
		}
		else { cout << "ע����ļ�ʧ��" << endl; }
	}
private:
};






void k(void) //�˺Ź���
{
	
	user_design p;
	file_write z;

	int m = 0;
	cout << "��¼(1)����ע��(2)" << endl;
	cin >> m;
	if (m == 1)
	{
		p.design();
	}
	else if (m == 2)
	{
		string password;
		cout << "��ע������" << endl;
		cin >> password;
		z.write(password);
	}

}


	

