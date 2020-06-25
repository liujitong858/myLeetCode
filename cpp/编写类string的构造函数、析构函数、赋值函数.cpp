#include<string>
#include<cstring>
using namespace std;
//当类中包括指针类成员变量时，一定要重载其拷贝构造函数、赋值函数和析构函数，
//这既是对C++程序员的基本要求，也是《Effective　C++》中特别强调的条款。
class String
{
public:
	String(const char *str=NULL);//普通构造函数
	~String(void);
	String(const String &other);//拷贝构造函数
	String & operator=(const String &other);//赋值构造函数

private:
	char *m_data;//用于保存字符串
};

String::String(const char *str)
{
	if (str == NULL) {              //对m_data加NULL 判断
		this->m_data = new char[1];// 得分点：对空字符串自动申请存放结束标志'\0'的空
		*m_data = '\0';
	}
	else {
		//m_data = new char(*str);//拷贝底层char
		int len = strlen(str);
		m_data = new char[len + 1];
		strcpy_s(m_data, len + 1, str);
	}
}

String::~String()
{
	delete[] m_data;
}

String::String(const String &other) {// 得分点：输入参数为const型
	int len = strlen(other.m_data);
	m_data [len + 1];
	strcpy_s(m_data, len + 1, other.m_data);
}
String & String::operator=(const String &other) {// 得分点：输入参数为const型
	if (this == &other) {//检查自赋值
		return *this;
	}
	delete []m_data;//释放原来内存资源
	//下面这样也可以
	//auto temp = new char(*other.m_data);//拷贝底层char 
	//delete m_data;//释放内存
	//m_data = temp;//从右侧对象拷贝到本对象
	//下面也可以但是如果new的过程中出现excp那
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy_s(m_data, len + 1, other.m_data);
	return *this;
}