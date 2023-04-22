#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<map>
#include<string> 
#include<vector>
#include<stack>
using namespace std;
//int main()
//{
//	set<int> s;
//	int arr[] = { 10,2,43,41,5,6,71,8,19 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout<< endl;
//
//	return 0;
//}
//int main()
//{
//	set<int> s;
//	int arr[] = { 10,2,43,41,5,6,71,8,19 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	set<int>::iterator it = s.find(71);
//
//	for (auto& e : s){cout << e << ' ';}cout << endl;
//	
//	s.erase(it);
//
//	for (auto& e : s){cout << e << ' ';}cout << endl;
//
//	s.erase(s.find(41));
//
//	for (auto& e : s) { cout << e << ' '; }cout << endl;
//	cout << s.size() << endl;
//
//
//	return 0;
//}

//
//int main()
//{
//	multiset<int> s;
//	int arr[] = { 10,2,2,2,43,41,41,55,5,5,6,71,8,19 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	
//	for (auto& e : s) { cout << e << ' '; }cout << endl;
//
//	cout << s.count(2) << endl;
//	//ÈÝÆ÷µÄ×î´óÈÝÁ¿
//	cout << s.max_size() << endl;
//
//	return 0;
//}
//

//(*((this->insert(make_pair(k, mapped_type()))).first)).second;
//int main()
//{
//	map<string, string> mymap;
//	mymap.insert(make_pair("string", "×Ö·û´®"));
//	mymap.insert(make_pair("sort", "ÅÅÐò"));
//	mymap.insert(make_pair("int", "ÕûÐÎ"));
//
//	for (auto& e : mymap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	//key/value Ä£ÐÍ
//	cout <<"string·­Òë:" << mymap.find("string")->second << endl;
//	
//	
//
//	return 0;
//}
//
//template<class key_type,class value_type>
//class _map
//{
//	value_type& operator[](key_type key)
//	{
//		pair& tmp = mm.insert(key, value_type());
//		return tmp->second;
//	}
//	map mm;
//};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//¸´ÔÓÁ´±í¸´ÖÆ
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* cur = head;
        Node* copyhead = nullptr;
        Node* copyTail = nullptr;
        map<Node*, Node*> maprandom;
        while (cur)
        {
            if (copyhead == nullptr)
            {
                copyhead = new Node(cur->val);
                copyTail = copyhead;
            }
            else
            {
                copyTail->next = new Node(cur->val);
                copyTail = copyTail->next;
            }
            maprandom[cur] = copyTail;
            cur = cur->next;
        }
        cur = head;
        Node* copycur = copyhead;
        while (cur)
        {
            if (cur->random == nullptr)
            {
                copycur->random = nullptr;
            }
            else
            {
                copycur->random = maprandom[cur->random];
            }
            cur = cur->next;
            copycur = copycur->next;
        }
        return copyhead;
    }
};

//·ÇµÝ¹éºóÐò±éÀú
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode*& root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        TreeNode* prev = nullptr;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* topnode = st.top();
            if (topnode->right == nullptr || topnode->right == prev)
            {
                v.push_back(topnode->val);
                st.pop();
                prev = topnode;
            }
            else
            {
                cur = topnode->right;
            }
        }
        return v;
    }
};

int main()
{
	
	map<string, int> mymap;
	vector<string> v = { "Æ»¹û","Æ»¹û" ,"Æ»¹û","Î÷¹Ï","Ñò½ÇÃÛ","Î÷¹Ï" ,
		"Ñò½ÇÃÛ","Î÷¹Ï" ,"ÀóÖ¦","Ñò½ÇÃÛ","Î÷¹Ï" ,"ÀóÖ¦" ,"²¤ÂÜ"};
	


	for (auto& e : v)
	{
		mymap[e]++;
	}
	mymap["²¤ÂÜ"] = 10;
	for (auto& e : mymap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	return 0;
}
