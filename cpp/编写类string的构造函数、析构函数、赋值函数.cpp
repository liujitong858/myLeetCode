#include<string>
#include<cstring>
using namespace std;
//�����а���ָ�����Ա����ʱ��һ��Ҫ�����俽�����캯������ֵ����������������
//����Ƕ�C++����Ա�Ļ���Ҫ��Ҳ�ǡ�Effective��C++�����ر�ǿ�������
class String
{
public:
	String(const char *str=NULL);//��ͨ���캯��
	~String(void);
	String(const String &other);//�������캯��
	String & operator=(const String &other);//��ֵ���캯��

private:
	char *m_data;//���ڱ����ַ���
};

String::String(const char *str)
{
	if (str == NULL) {              //��m_data��NULL �ж�
		this->m_data = new char[1];// �÷ֵ㣺�Կ��ַ����Զ������Ž�����־'\0'�Ŀ�
		*m_data = '\0';
	}
	else {
		//m_data = new char(*str);//�����ײ�char
		int len = strlen(str);
		m_data = new char[len + 1];
		strcpy_s(m_data, len + 1, str);
	}
}

String::~String()
{
	delete[] m_data;
}

String::String(const String &other) {// �÷ֵ㣺�������Ϊconst��
	int len = strlen(other.m_data);
	m_data [len + 1];
	strcpy_s(m_data, len + 1, other.m_data);
}
String & String::operator=(const String &other) {// �÷ֵ㣺�������Ϊconst��
	if (this == &other) {//����Ը�ֵ
		return *this;
	}
	delete []m_data;//�ͷ�ԭ���ڴ���Դ
	//��������Ҳ����
	//auto temp = new char(*other.m_data);//�����ײ�char 
	//delete m_data;//�ͷ��ڴ�
	//m_data = temp;//���Ҳ���󿽱���������
	//����Ҳ���Ե������new�Ĺ����г���excp��
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy_s(m_data, len + 1, other.m_data);
	return *this;
}