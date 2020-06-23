#include<unordered_map>
using namespace std;
namespace LRU {
	struct node
	{
		int key;
		int value;
		node* pre;
		node* next;
		//���캯����ʼ��
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
					node* cur = hashmap[tail->key];//����Ǹ����
					remove(cur);
					hashmap.erase(cur->key);
				}
				//����û��
				node* newNode = new node(key, value);		
				sethead(newNode);
				hashmap[key] = newNode;
			}
			else{//���������
				node* cur = hashmap[key];
				cur->value = value;//�������ĵĻ���hashmap�еĵ�ַ�᲻��仯����
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
			else {//һ����
				cur->pre->next = cur->next;
				cur->next->pre = cur->pre;
			}
		}
		void sethead(node* cur) {//��һcur��tail�������ô�죿��
			cur->next = head;
			if (head != nullptr) {
				head->pre = cur;
			}
			head = cur;
			if (tail == nullptr) {//cur�ǵ�һ�����
				tail = head;
			}
		}
	};
}