#include<unordered_map>
#include<list>
using namespace std;

namespace leetcode146 {
	class LRUCache {
	public:
		//��ϣ����
		//�ؼ��㣺1�������м�Ҫ�洢key��Ҫ�洢value
		//		 2����ϣ��Key��Ӧ��value�ǽ��ĵ�ַ������ͨ��key��ѯ��pairȻ���ƶ���������ǵ�ַ�Ļ���
		//		��Ҫͨ��list.find(make_pair(key,value)),�ҵ���Ȼ����޸�List����valueҲ�޸�hashtable�е�value
		//ɾ�������ҡ�����ĸ��Ӷȶ�O��1��
		LRUCache(int capacity) {
			cap = capacity;
		}
		int get(int key) {
			if (hashtable.count(key) == 0) return -1;
			else//���µ���ͷ
			{
				auto iter = hashtable[key];//�ҵ���Ӧ����ַ
				cache.splice(cache.begin(), cache, iter);//�ƶ�������ͷ
				return cache.begin()->second;//����value
			}
		}

		void put(int key, int value) {
			if (hashtable.count(key) == 0) {
				//����������ˣ�ɾ��β��Ԫ��,�ټ����½��
				if (cache.size() == cap) {
					hashtable.erase(cache.back().first);
					cache.pop_back();
				}//ֱ�����
				cache.push_front(make_pair(key, value));
				hashtable[key] = cache.begin();
			}
			else {//���������ͬkey��Ԫ�أ�����Ҫ�ƶ���valueҲ��Ҫ����
				auto iter = hashtable[key];
				iter->second = value;//���µ�ַvalue
				cache.splice(cache.begin(), cache, iter);//�ƶ�������ͷ
				hashtable[key] = cache.begin();   //����hashtable��value
			}
		}
		private:
			unordered_map<int, list<pair<int, int>>::iterator> hashtable;
			list<pair<int, int>> cache;//key value
			int cap = 0;
	};

	/**
	 * Your LRUCache object will be instantiated and called as such:
	 * LRUCache* obj = new LRUCache(capacity);
	 * int param_1 = obj->get(key);
	 * obj->put(key,value);
	 */
}