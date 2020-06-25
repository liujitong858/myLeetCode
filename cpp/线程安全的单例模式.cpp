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


//1、单例模式中为什么构造函数为私有private？
//将该类的构造函数私有化，目的是禁止其他程序创建该类的对象，
//同时也是为了提醒查看代码的人我这里是在使用单例模式，防止他人将这里任意修改。
//此时，需要提供一个可访问类自定义对象的类成员方法（对外提供该对象的访问方式）。
//2、为什么指向本身实例的类属性为静态？
//因为指向自己实例的私有引用在被类方法(Getinstance)调用时被初始化，
//只有静态成员变量才能在没有创建对象时进行初始化，并且类的静态成员在第一次使用时不会再被初始化，保证了单例，因此设置为静态。
//3、为什么以自己实例为返回值的类方法为静态？
//通过类方法（GetInstance) 获取instance，类属性instance为静态的(static)，则需要类的静态方法才能调用，因此该类方法应设为静态的。


//饿汉模式的缺点：也是比较明显，不使用却占用资源，不支持向单例构造函数传参；
//优点：就是节省了运行时间（资源提前加载），另外天生自带线程安全属性
//（在多线程环境下肯定是线程安全的，因为不存在多线程实例化的问题）。
//饿汉式
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

// 懒汉式单例模式
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

//线程安全的懒汉式(相对)
//声明一个局部的lock_guard对象，在其构造函数中进行加锁，在其析构函数中进行解锁。
//最终的结果就是：在定义该局部对象的时候加锁（调用构造函数），出了该对象作用域的时候解锁（调用析构函数）。
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
			lock_guard<mutex> lock_(m_cs);//注意到_instance = new T()，是一个写操作，前面有一个无锁的读操作。
			if (!Instance)				 //当真正的写操作进行时，前面的读操作存在脏读情况。
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


//在C++11中提供一种方法，使得函数可以线程安全的只调用一次。
//即使用std::call_once和std::once_flag。std::call_once是一种lazy load的很简单易用的机制。

//线程安全的懒汉式
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
	//向单例构造函数中传参
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

//另外还有一个版本的懒汉模式代码，也是支持线程安全（打开编译器C++11支持）
//这里使用了局部静态变量，C++11机制可以保证它的初始化具有原子性，线程安全。
//这个对象保存在静态数据区，和全局变量是在一起的，而不是在堆中。
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