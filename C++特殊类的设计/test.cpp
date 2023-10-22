#define _CRT_SECURE_NO_WARNINGS 1
#include"Design.hpp"


//int main()
//{
//	//手动释放对象空间
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
//	static StackOnly t1 = move(t);//没办法阻止
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
	//singleton->get_sing_list().push_back("《冰雨》——刘德华");
	//singleton->get_sing_list().push_back("《月光》——胡彦斌");
	//singleton->get_sing_list().push_back("《倒带》——周杰伦");
	//singleton->get_sing_list().push_back("《呓语》——毛不易");
	vector<string> sing = { ",《冰雨》——刘德华",",《月光》——胡彦斌",",《倒带》——周杰伦",",《呓语》——毛不易" };
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