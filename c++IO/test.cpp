#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}
//
//
//	return 0;
//}


// C++ IO����ʹ���������+��������صķ�ʽ
// �ܸ��õļ����Զ������ͣ������������ȡ
//int main()
//{
//	Date d;
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//	return 0;
//}

string  str = "I love china";
//int main()
//{
//	string _filename("ttt.txt");
//	ofstream ofs(_filename, ios_base::out | ios_base::binary);
//	ofs.write(str, strlen(str));
//
//
//	//�Զ����ƶ�ȡ�ķ�ʽ����һ��"test"�ļ�������
//	ofstream ofile_b("test", ios_base::out | ios_base::binary);
//	
//	ofile_b.write(str, strlen(str));
//
//	fstream iofile_t("test.txt",ios_base::app);
//	iofile_t << str << endl;
//
//	return 0;
//}

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	operator bool()
	{
		// ����������д�ģ���������_yearΪ0�������
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}
struct ServerInfo
{
	char _address[32];
	int _port;
	Date _date;
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}
	void WriteBin(ServerInfo& info)
	{
		//������������ķ�ʽ����һ���ļ�����
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info,sizeof(info));
		
	}
	void ReadBin(ServerInfo& info)
	{
		//������������ķ�ʽ����һ���ļ�����
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}
	
void WriteText(const ServerInfo& info)
{
	ofstream ofs(_filename);
	ofs << info._address << " " << info._port << " " << info._date;
}
void ReadText(ServerInfo& info)
{
	ifstream ifs(_filename);
	ifs >> info._address >> info._port >> info._date;
}
private:
	string _filename; // �����ļ�
};


//int main()
//{
//
//	ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };
//	// �����ƶ�д
//	ConfigManager cf_bin("test.bin");
//	cf_bin.WriteBin(winfo);
//	ServerInfo rbinfo;
//	cf_bin.ReadBin(rbinfo);
//	cout << rbinfo._address << " " << rbinfo._port << " "
//		<< rbinfo._date << endl;
//	// �ı���д
//	ConfigManager cf_text("test.text");
//	cf_text.WriteText(winfo);
//	ServerInfo rtinfo;
//	cf_text.ReadText(rtinfo);
//	cout << rtinfo._address << " " << rtinfo._port << " " <<
//	rtinfo._date << endl;
//	return 0;
//}


//int main()
//{
//	int n = 123456789;
//	double f = 12345.6789;
//	char s1[32];
//	_itoa(n, s1, 10);
//	char s2[32];
//	sprintf(s2, "%d", n);
//	char s3[32];
//	sprintf(s3, "%f", f);
//	cout << "s3:" << s3 << endl;
//	cout << "s2:" << s2 << endl;
//	cout << "s1:" << s1 << endl;
//	return 0;
//}

#include<sstream>
//int main()
//{
//	int a = 12345678;
//	string sa;
//	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
//	stringstream s;
//	s << a;
//	s >> sa;
//	cout << sa << endl;
//	// clear()
//	// ע����ת��ʱ������ʹ��clear���ϴ�ת��״̬��յ�
//	// stringstreams��ת����βʱ(�����һ��ת����),�Ὣ���ڲ�״̬����Ϊbadbit
//	// �����һ��ת���Ǳ������clear()��״̬����Ϊgoodbit�ſ���ת��
//	// ����clear()���Ὣstringstreams�ײ��ַ�����յ�
//
//	// s.str("");
//	// ��stringstream�ײ����string�������ó�"",
//	// ������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string������
//
//	s.str("");
//	s.clear(); // ���s, ����ջ�ת��ʧ��
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = s.str(); // str()����������stringsteam�й����string����
//	cout << sValue << endl;
//	return 0;
//}


//int main()
//{
//	stringstream s;
//	// ������ַ������� sstream ��
//	s << "first" << " " << "string";
//	s << " second string";
//	cout << "strResult is: " << s.str() << endl;
//	string s1;
//	string s2;
//	s >> s1;
//	s >> s2;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}

struct ChatInfo
{
	string _name;// ����
	int _id; // id
	Date _date; // ʱ��
	string _msg; // ������Ϣ
};
int main()
{
	// �ṹ��Ϣ���л�Ϊ�ַ���
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��"};
	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " "
		<< winfo._msg;
	string str = oss.str();
	cout << str << endl << endl;
	// ����ͨ����������ַ������͸�����ʵ�ʿ����У���Ϣ��Ը����ӣ�
	// һ���ѡ��Json��xml�ȷ�ʽ���и��õ�֧��
	// �ַ��������ɽṹ��Ϣ
	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
	cout << "-------------------------------------------------------"
		<< endl;
	cout << "������" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;
	cout << "-------------------------------------------------------"
		<< endl;
	return 0;
}
