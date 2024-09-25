
class myclass
{
	char* name;
	int* marks;
	int* rollno;
	int size;

public:
	myclass()
	{
		name = nullptr;
		marks = nullptr;
	}

	myclass(const char* _name, int* _ptr, int _rollno, int _size)
	{
		size = _size;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);

		marks = new int[size];

		for (int i = 0; i < size; i++)
			marks[i] = _ptr[i];
		rollno = new int(_rollno);
	}

	myclass(const myclass& ref)
	{
		rollno = nullptr;
		cout << "cc called" << endl;
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);

		size = ref.size;

		marks = new int[size];

		for (int i = 0; i < size; i++)
			marks[i] = ref.marks[i];

		rollno = new int(*ref.rollno);
	}

	myclass& operator=(const myclass& ref)
	{
		if (this != &ref) {
			cout << "cpy assignment called" << endl;
			return *this;
		}
	}

	myclass(myclass&& ref)
	{
		cout << "move constructor called" << endl;
		name = ref.name;
		marks = ref.marks;
		rollno = ref.rollno;
		size = ref.size;

		ref.name = nullptr;
		ref.marks = nullptr;
		ref.rollno = nullptr;
		size = 0;
	}

	myclass& operator=(myclass&& ref)
	{
		if (this != &ref)
		{
			cout << "move assign called" << endl;
			delete[]name;
			delete[]marks;
			delete[]rollno;
			size = 0;

			name = ref.name;
			marks = ref.marks;
			rollno = ref.rollno;


		}
	}

	void getDetails()
	{
		cout << name << " " << *rollno << endl << endl;
		for (int i = 0; i < size; i++)
			cout << marks[i] << "  ";
		cout << endl;

	}


	~myclass()
	{
		cout << "dctor called" << endl;
		delete[]marks;
		delete[]rollno;
	}
};
