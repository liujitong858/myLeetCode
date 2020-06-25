#include<mutex>
using namespace std;

//#include <pthread.h>
//class Singleton
//{
//public:
//	Singleton() {}
//	~Singleton() {}
//	static Singleton* getInstance() {
//		if (instance == nullptr) {
//			pthread_mutex_lock(mtx);
//			if (instance == nullptr) {
//				instance = new Singleton();
//			}
//			pthread_mutex_unlock(mtx);
//		}
//		return instance;
//	}
//private:
//	static pthread_mutex_t mtx;
//	static	Singleton* instance;
//};
//pthread_mutex_t Singleton::mtx = PTHREAD_MUTEX_INITIALIZER;
//Singleton Singleton::instance = nullptr;


//1������ģʽ��Ϊʲô���캯��Ϊ˽��private��
//������Ĺ��캯��˽�л���Ŀ���ǽ�ֹ�������򴴽�����Ķ���
//ͬʱҲ��Ϊ�����Ѳ鿴�����������������ʹ�õ���ģʽ����ֹ���˽����������޸ġ�
//��ʱ����Ҫ�ṩһ���ɷ������Զ����������Ա�����������ṩ�ö���ķ��ʷ�ʽ����
//2��Ϊʲôָ����ʵ����������Ϊ��̬��
//��Ϊָ���Լ�ʵ����˽�������ڱ��෽��(Getinstance)����ʱ����ʼ����
//ֻ�о�̬��Ա����������û�д�������ʱ���г�ʼ����������ľ�̬��Ա�ڵ�һ��ʹ��ʱ�����ٱ���ʼ������֤�˵������������Ϊ��̬��
//3��Ϊʲô���Լ�ʵ��Ϊ����ֵ���෽��Ϊ��̬��
//ͨ���෽����GetInstance) ��ȡinstance��������instanceΪ��̬��(static)������Ҫ��ľ�̬�������ܵ��ã���˸��෽��Ӧ��Ϊ��̬�ġ�


//����ģʽ��ȱ�㣺Ҳ�ǱȽ����ԣ���ʹ��ȴռ����Դ����֧���������캯�����Σ�
//�ŵ㣺���ǽ�ʡ������ʱ�䣨��Դ��ǰ���أ������������Դ��̰߳�ȫ����
//���ڶ��̻߳����¿϶����̰߳�ȫ�ģ���Ϊ�����ڶ��߳�ʵ���������⣩��
//����ʽ
template<class T>
class Singleton
{
private:
	Singleton() = default;
	~Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static	T * Instance;
public:
	static T* GetInstance() {
		return Instance;
	}
};

template <class T>
T* Singleton<T>::Instance = new T();

// ����ʽ����ģʽ
template<class T>
class Singleton3
{
private:
	Singleton3() = default;
	~Singleton3() = default;
	Singleton3(const Singleton3&) = delete;
	Singleton3& operator=(const Singleton3&) = delete;
	static	T * Instance;
public:
	static T* GetInstance() {
		if (Instance == nullptr) {
			Instance = new T();
		}
		return Instance;
	}
};

template <class T>
T* Singleton3<T>::Instance = NULL;

//�̰߳�ȫ������ʽ(���)
//����һ���ֲ���lock_guard�������乹�캯���н��м������������������н��н�����
//���յĽ�����ǣ��ڶ���þֲ������ʱ����������ù��캯���������˸ö����������ʱ�����������������������
template <class T>
class Singleton1
{
private:
	Singleton1() = default;
	~Singleton1() = default;
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;

public:
	static T* instance()
	{
		if (!Instance)
		{
			lock_guard<mutex> lock_(m_cs);//ע�⵽_instance = new T()����һ��д������ǰ����һ�������Ķ�������
			if (!Instance)				 //��������д��������ʱ��ǰ��Ķ�����������������
			{
				Instance = new T();
			}
		}
		return Instance;
	}

private:
	static T* Instance;
	static std::mutex m_cs;
};

template <class T>
T* Singleton1<T>::Instance = NULL;

template <class T>
mutex Singleton1<T> ::m_cs;


//��C++11���ṩһ�ַ�����ʹ�ú��������̰߳�ȫ��ֻ����һ�Ρ�
//��ʹ��std::call_once��std::once_flag��std::call_once��һ��lazy load�ĺܼ����õĻ��ơ�

//�̰߳�ȫ������ʽ
template <class T>
class Singleton2
{
private:
	Singleton2() = default;
	~Singleton2() = default;
	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;

public:
	static T* instance()
	{
		call_once(_flag, [&]() {
			_instance = new T();
		});
		return _instance;
	}
	//�������캯���д���
	/*template <typename... Args>
	static T* instance(Args&&... args)
	{
		std::call_once(_flag, &](){
			_instance = new T(std::forward<Args>(args)...);
		});
		return _instance;
	}*/
private:
	static T* _instance;
	static once_flag _flag;
};

template <class T>
T* Singleton2<T>::_instance = NULL;

template <class T>
once_flag Singleton2<T>::_flag;

//���⻹��һ���汾������ģʽ���룬Ҳ��֧���̰߳�ȫ���򿪱�����C++11֧�֣�
//����ʹ���˾ֲ���̬������C++11���ƿ��Ա�֤���ĳ�ʼ������ԭ���ԣ��̰߳�ȫ��
//������󱣴��ھ�̬����������ȫ�ֱ�������һ��ģ��������ڶ��С�
//class Singleton3
//{
//public:
//	static Singleton3* instance()
//	{
//		static Singleton3 _instance;
//		return &_instance;
//	}
//private:
//	Singleton3() {}
//};