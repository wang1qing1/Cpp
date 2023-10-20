#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//void func(int a,int b)
//{	
//	if (b == 0) throw "b is 0";
//	int c = a / b;
//	
//	cout << c << endl;
//}
//
//void Func(int a,int b)
//{
//	try {
//		func(a, b);
//	}
//	catch (const char* mes)
//	{
//		cout << mes << endl;
//		cout << "void Func(int a,int b)" << endl;
//	}
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	try {
//		Func(a, b);
//	}
//	catch (const char * mes)
//	{
//		cout << mes << endl;
//	}
//	catch (...)
//	{
//	}
//
//	cout << "main end" << endl;
//	return 0;
//}


//void func(int a, int b)
//{
//
//	//if (b == 0); throw "b is 0";
//	//int c = a / b;
//
//	//cout << c << endl;
//}
//
//void Func(int a, int b) 
//{
//	if (b == 0)throw"b========0";
//	func(a, b);
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//	//Func(a, b);
//
//	try {
//		Func(a, b);
//	}
//	catch (const char* mes)
//	{
//		cout << mes << endl;
//	}
//	catch (...)
//	{
//	}
//
//
//	cout << "main end" << endl;
//	return 0;
//}

#include<thread>

class exception_base
{
public:
	exception_base(string msg,int id)
		:_msg(msg),_id(id)
	{
	}

	virtual void what()
	{
		cout << "Exception_id :"<<_id << "Exception_msg :" << _msg << endl;
	}

	string getmsg()
	{
		return _msg;
	}

	int getid()
	{
		return _id;
	}

private:
	string _msg;
	int _id;
};

class SQL_exception : public exception_base
{
public:
	SQL_exception(string msg,int id,string sql)
		:exception_base(msg,id),_sql(sql)
	{
	}
	void what()
	{
		cout << "Exception_id :" << getid() << ",Exception_msg :" << getmsg() <<_sql<<endl;
	}
private:
	string _sql;
};


class INT_exception : public exception_base
{
public:
	INT_exception(string msg, int id, string type)
		:exception_base(msg, id), _type(type)
	{
	}
	void what()
	{
		cout << "Exception_id :" << getid() << ",Exception_msg :" << getmsg() << _type << endl;
	}
private:
	string _type;
};


void server(int num)
{
	if (num % 5 == 0)
	{
		throw SQL_exception("server have a exception", num, ",show data");
	}
	else if (num % 3 == 0)
	{
		throw INT_exception("server have a exception", num, ",https");
	}
	else
	{
		cout << "server successful" << endl;
	}

}

int main()
{
	int num = 0;
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));
		num++;
		try
		{
			server(num);
		}
		catch(exception_base& e)
		{
			//¶àÌ¬
			e.what();
		}
	}

}