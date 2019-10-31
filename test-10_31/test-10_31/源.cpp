#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// new �� delete
class Test
{
public:
	Test(int data = 0)
		: _data(data)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

void TestNew()
{
	// malloc��������ù��캯��---malloc�Ĳ��ܽ����Ϊ����-->������С��һ���ڴ�ռ�
	Test* p1 = (Test*)malloc(sizeof(Test));


	// new��ʵ����ù��캯��--->new���Ľ������һ�������Ķ���
	Test* p2 = new Test;

	// free: ���ͷſռ��ڼ䲻�������������
	free(p1);

	// delete:���ͷſռ��ڼ��������������������е���Դ�����
	delete p2;

	// new[]: ������ռ� + ����N�ι��캯��
	Test* p3 = new Test[10];

	// delete[]�� ���ͷſռ� + ����N������
	delete[] p3;
}

int main()
{
	TestNew();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int data = 0)
		: _data(data)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};


int main()
{
	_CrtMemBlockHeader
		Test* p = new Test[10];
	delete[] p;

	return 0;
}
#endif


#if 0
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};



class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

int main()
{
	List l;
	return 0;
}
#endif

#if 0
void* operator new(size_t size, char* fileName, char* funcName, size_t lineNo)
{
	cout << fileName << "-" << funcName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}


#define  new new(__FILE__, __FUNCDNAME__, __LINE__) 
int main()
{
	int* p = new int;
	delete p;

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int data = 0)
		: _data(data)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

void TestFunc()
{
	int* p = new int[10];
	FILE* pf = fopen("1.txt", "rb");
	if (nullptr == pf)
	{
		return;
	}

	// �ļ�����
	fclose(pf);
}

int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt)Test(10);

	pt->~Test();
	free(pt);
	//delete pt;
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

#if 0
typedef int DataType;

struct SeqList
{
	DataType* _array;
	size_t _capacity;
	size_t _size;
};
#endif

#if 0
// ͨ�õļӷ��������������޹�
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}



int main()
{
	return 0;
}
#endif

#if 0
// class ����typename T
// ���ģ������б����ж�����ͣ��������֮���ö��Ÿ���
// ÿ������ǰ�����class����typename�Ĺؼ���

// �ӷ�����ģ��
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

// watch: ����ģ�岻�������ĺ������Ǳ��������ɴ���Ĺ���

int main()
{
	// �Ժ���ģ�����ʵ����
	// �ڱ����ڼ䣬����ʵ����������ʵ�����ͣ�����ģ�庯����T��ʵ�����ͣ�
	// �������ݵ�ʵ���������ɴ���������͵Ĵ���
	Add(1, 2);  // Add<int>
	Add(1.0, 2.0); // Add<double>
	Add('1', '2'); // Add<char>

	return 0;
}
#endif