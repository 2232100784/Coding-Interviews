#include<cstring>
#include<cstdio>
#include <assert.h>
#include <iostream>

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);


private:
	char* m_pData;
};

CMyString::CMyString(char* pData) {
	std::cout << "构造函数" << std::endl;
	if (pData == 0) {
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::~CMyString(void){
	std::cout << "析构函数" << std::endl;
	delete []m_pData;
	m_pData = 0;
}

CMyString::CMyString(const CMyString& str){
	//delete[]m_pData;  //注意！delete空指针会出错
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString& CMyString::operator = (const CMyString& other) {
	if (&other == this){
		return *this;
	}
	else {
		delete[]m_pData;
		m_pData = 0;

		m_pData = new char[strlen(other.m_pData) + 1];
		strcpy(m_pData, other.m_pData);
		return *this;
	}
}

void test() {
	CMyString ms("hello");
	CMyString ms2;
	CMyString ms3;
	ms3= ms2 = ms;
}
int main() {
	test();
	return 0;
}
