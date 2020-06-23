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


