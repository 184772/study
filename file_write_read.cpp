
#include"ground_loading.h"
#include<regex>
#include<string>
#include<fstream>
void resign();
using namespace std;

/*�����ַ������棬�����������¹涨�������ͣ�ͷ����+����+��������β������*/
class file_read {//�ļ����࣬���麯������Ҫ��������ݣ�����ֵΪȥ����λ��Ϣ�Ĵ�����
public:
	
	
	virtual void detail(string::const_iterator iterStart, string::const_iterator iterEnd, smatch results) {
		cout << "�������麯��detail����" << endl;
	}
	string read() {
		FILE* file1;
		if (0 == fopen_s(&file1, ".\\information.txt", "r"))
		{
			cout << "�ļ���ȡ�ɹ�" << endl;
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
				string result = results.str();
				result = starts_with_earase(result,"key");
				cout <<"starts_with_earase�ķ���ֵΪ" << result << endl;
				return result;//����ֵ
			}
			else cout << "����ƥ��ʧ��" << endl;

		}
		else cout << "��¼�ļ���ʧ��" << endl;

	}

private:
	string starts_with_earase(const string&result,const string& str) {//ȥ��һ�����ݸ�ʽ��ͷ����Ϣ
		
		if (result.substr(0, str.size()).compare(str)==0)

			return result.substr(str.size());
			else return result;
	}

	/*string end_with_earase(const string& result, const string& str)
	{ 
		if()
	}*/

	
};

class user_design :public file_read {//��ȡ�û���¼����,����
public:
	void detail(string::const_iterator iterStart, string::const_iterator iterEnd, smatch results) override {
		while (regex_search(iterStart, iterEnd, results, regex("key(\\d+)")))
		{
			cout <<"�������麯����ƥ����" << results[0] << endl;
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

class file_write {//�ļ�д��
public:

	void write(string password) {
		ofstream file(".\\information.txt");//���ļ�������д�������ע�⣬����һ�����캯����Ĭ��Ϊ����д��
		if (file.is_open())
		{
			cout << "�ļ�д��ɹ�" << endl;
			file << "key" << password;
			//fprintf_s(file1,"123456781234567812345678");//д���ļ������Ҫ��ȡ�ļ�Ҫ�رպ����´�
			file.close();
		}
		else { cout << "ע����ļ�ʧ��" << endl; }
	}
private:
};






void out(void) //�˺Ź���
{
	
	user_design p;
	file_write z;

	int m = 0;
	cout << "��¼(1)����ע��(2)" << endl;
	cin >> m;
	if (m == 1)
	{
		p.design();
		m = 0;
	}
	else if (m == 2)
	{
		string password;
		cout << "��ע������" << endl;
		cin >> password;
		z.write(password);
		m = 0;
	}

}


	

