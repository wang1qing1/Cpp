#define _CRT_SECURE_NO_WARNINGS 1
#include"Design.hpp"


//int main()
//{
//	//�ֶ��ͷŶ���ռ�
//	HeapOnly* t = HeapOnly::CreateObj(100);
//
//	//HeapOnly t2 = (*t); error
//	//t2 = *t; error
//
//	t->Destroy();
//
//	return 0;
//}

//
//int main()
//{
//	StackOnly t = StackOnly::CreateObj(100);
//	//StackOnly* pt = new StackOnly(200); error 
//
//	//static StackOnly t1 = t; //error 
//	static StackOnly t1 = move(t);//û�취��ֹ
//
//	return 0;
//}
mutex mu;
int j = 1;
void func()
{
	Singleton::GetSingleton();

}

int main()
{

	vector<int> arr{ 1,1,1 };
	//Singleton* singleton = Singleton::GetSingleton();
	//singleton->get_sing_list().push_back("�����꡷�������»�");
	//singleton->get_sing_list().push_back("���¹⡷���������");
	//singleton->get_sing_list().push_back("�������������ܽ���");
	//singleton->get_sing_list().push_back("��߽�����ë����");
	vector<string> sing = { ",�����꡷�������»�",",���¹⡷���������",",�������������ܽ���",",��߽�����ë����" };
	vector<thread*> vth;
	for (int i = 0; i < 100000; i++)
	{
		vth.push_back(new thread(func));
	}
	
	for (auto e:vth)
	{
		e->join();
	}

	cout << Singleton::GetSingleton()->i << endl;

	return 0;
}