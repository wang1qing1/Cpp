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


// C++ IO流，使用面向对象+运算符重载的方式
// 能更好的兼容自定义类型，流插入和流提取
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
//	//以二进制读取的方式创建一个"test"文件流对象
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
		// 这里是随意写的，假设输入_year为0，则结束
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
		//二进制流输出的方式创建一个文件对象
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info,sizeof(info));
		
	}
	void ReadBin(ServerInfo& info)
	{
		//二进制流输入的方式创建一个文件对象
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
	string _filename; // 配置文件
};


//int main()
//{
//
//	ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };
//	// 二进制读写
//	ConfigManager cf_bin("test.bin");
//	cf_bin.WriteBin(winfo);
//	ServerInfo rbinfo;
//	cf_bin.ReadBin(rbinfo);
//	cout << rbinfo._address << " " << rbinfo._port << " "
//		<< rbinfo._date << endl;
//	// 文本读写
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
//	// 将一个整形变量转化为字符串，存储到string类对象中
//	stringstream s;
//	s << a;
//	s >> sa;
//	cout << sa << endl;
//	// clear()
//	// 注意多次转换时，必须使用clear将上次转换状态清空掉
//	// stringstreams在转换结尾时(即最后一个转换后),会将其内部状态设置为badbit
//	// 因此下一次转换是必须调用clear()将状态重置为goodbit才可以转换
//	// 但是clear()不会将stringstreams底层字符串清空掉
//
//	// s.str("");
//	// 将stringstream底层管理string对象设置成"",
//	// 否则多次转换时，会将结果全部累积在底层string对象中
//
//	s.str("");
//	s.clear(); // 清空s, 不清空会转化失败
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = s.str(); // str()方法：返回stringsteam中管理的string类型
//	cout << sValue << endl;
//	return 0;
//}


//int main()
//{
//	stringstream s;
//	// 将多个字符串放入 sstream 中
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
	string _name;// 名字
	int _id; // id
	Date _date; // 时间
	string _msg; // 聊天信息
};
int main()
{
	// 结构信息序列化为字符串
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧"};
	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " "
		<< winfo._msg;
	string str = oss.str();
	cout << str << endl << endl;
	// 我们通过网络这个字符串发送给对象，实际开发中，信息相对更复杂，
	// 一般会选用Json、xml等方式进行更好的支持
	// 字符串解析成结构信息
	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
	cout << "-------------------------------------------------------"
		<< endl;
	cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;
	cout << "-------------------------------------------------------"
		<< endl;
	return 0;
}
