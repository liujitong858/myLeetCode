#include<unordered_map>
using namespace std;
namespace LRU {
	struct node
	{
		int key;
		int value;
		node* pre;
		node* next;
		//构造函数初始化
		node(int key,int value):key(key),value(value),pre(nullptr),next(nullptr){}
	};

	class  LRUCache
	{
	private:
		int cap = 0;
		node* head;
		node* tail;
		unordered_map<int, node*> hashmap;
	public:
		LRUCache(int size) {
			cap = size;
			head = nullptr;
			tail = nullptr;
		}
		int get(int key) {
			if (hashmap.count(key) == 0) return -1;
			node* cur = hashmap[key];
			remove(cur);
			sethead(cur);
			return cur->value;
		}
		void put(int key, int value) {
			if (hashmap.count(key) == 0) {
				if (hashmap.size() == cap) {
					node* cur = hashmap[tail->key];//最后那个结点
					remove(cur);
					hashmap.erase(cur->key);
				}
				//容量没到
				node* newNode = new node(key, value);		
				sethead(newNode);
				hashmap[key] = newNode;
			}
			else{//如果结点存在
				node* cur = hashmap[key];
				cur->value = value;//这样更改的话，hashmap中的地址会不会变化？？
				sethead(cur);
			}
		}
		void remove(node* cur) {
			if (cur == head) {
				head = head->next;
			}
			else if(cur==tail){
				tail = cur->pre;
			}
			else {//一般结点
				cur->pre->next = cur->next;
				cur->next->pre = cur->pre;
			}
		}
		void sethead(node* cur) {//万一cur是tail的情况怎么办？？
			cur->next = head;
			if (head != nullptr) {
				head->pre = cur;
			}
			head = cur;
			if (tail == nullptr) {//cur是第一个结点
				tail = head;
			}
		}
	};
}