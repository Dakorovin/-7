#include <iostream>
using namespace std;

// Первый базовый класс

template <class T1, class T2>
class Oven {
protected:
	T1 year, month, day;
	char* name;
public:
	void input();
	void print();
	Oven();
	Oven(const char* n, T2 date_year, T1 date_month, T1 date_day);
	Oven(const Oven<T1, T2>& a);
	~Oven<T1, T2>();
	Oven<T1, T2> operator = (const Oven<T1, T2>& a);
	Oven<T1, T2> operator + (Oven<T1, T2>& a);
	bool operator == (const Oven<T1, T2>& a);
};

template <class T1, class T2>
void Oven<T1, T2>::input() {
	cout << "Введите название вашей печи: ";
	cin >> name;
	cout << "Введите год изобретения вашей печи: ";
	cin >> year;
	cout << "Введите месяц изобретения вашей печи: ";
	cin >> month;
	cout << "Введите день изобретения вашей печи: ";
	cin >> day;
}

template <class T1, class T2>
void Oven<T1, T2>::print() {
	cout << "Название вашей печи - " << name << endl;
	cout << "Год изобретения вашей печи - " << year << endl;
	cout << "Месяц изобретения вашей печи - " << month << endl;
	cout << "День изобретения вашей печи - " << day << endl;
	cout << endl;
}

template <class T1, class T2>
Oven<T1, T2>::Oven() {
	name = new char[11]{ "Неизвестно" };
	year = (T2)0;
	month = (T1)0;
	day = (T1)0;

}

template <class T1, class T2>
Oven<T1, T2>::Oven(const char* n, T2 date_year, T1 date_month, T1 date_day) {
	if (n == "")
		throw "Название печи не может быть пустым"; // Ошибка
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	if (date_year < 0)
		throw "Год не может быть отрицательным"; // Ошибка
	year = date_year;
	if (date_month < 0)
		throw "Месяц не может быть отрицательным"; // Ошибка
	month = date_month;
	if (date_day < 0)
		throw "День не может быть отрицательным"; // Ошибка
	day = date_day;
}

template <class T1, class T2>
Oven<T1, T2>::Oven(const Oven<T1, T2>& a) {
	if (a == NULL)
		throw "Ссылка указывает на несуществующий элемент"; // Ошибка
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
	year = a.year;
	month = a.month;
	day = a.day;
}

template <class T1, class T2>
Oven<T1, T2>::~Oven() {
	delete[]name;
}

template <class T1, class T2>
Oven<T1, T2> Oven<T1, T2> :: operator = (const Oven& a) {
	if (this == &a)
		return *this;
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
	year = a.year;
	month = a.month;
	day = a.day;
	return *this;
}

template<class T1, class T2>
Oven<T1, T2> Oven<T1, T2> :: operator + (Oven& a)
{
	Oven<T1, T2> t;
	t.name = new char[strlen(name) + strlen(a.name) + 1];
	strcpy(t.name, name);
	for (int i = strlen(name); i < strlen(name) + strlen(a.name); i++) {
		t.name[i] = a.name[i - strlen(name)];
	}
	t.name[strlen(name) + strlen(a.name)] = '\0';
	t.year = year + a.year;
	t.month = month + a.month;
	t.day = day + a.day;
	return (t);
}

template<class T1, class T2>
bool Oven<T1, T2> :: operator == (const Oven<T1, T2>& a) {
	return (year + month + day == a.year + a.month + a.day);
}

// Второй базовый класс

template <class T1, class T2>
class TypeOven {
protected:
	char* type;
public:
	TypeOven<T1, T2>();
	TypeOven<T1, T2>(const char* typed);
	void inputType();
	void printType();
};

template<class T1, class T2>
TypeOven<T1, T2>::TypeOven() {
	type = new char[11]{ "Неизвестно" };
}

template<class T1, class T2>
TypeOven<T1, T2>::TypeOven(const char* typed) {
	if (typed == "")
		throw "Название типа печи не может быть пустым"; // Ошибка
	type = new char[strlen(typed) + 1];
	strcpy(type, typed);
}

template<class T1, class T2>
void TypeOven<T1, T2>::inputType() {
	cout << "Введите тип вашей печи:";
	cin >> type;
}

template<class T1, class T2>
void TypeOven<T1, T2>::printType() {
	cout << "Тип вашей печи: " << type << endl;
}

// Класс-наследник

template<class T1, class T2>
class Material : public Oven<T1, T2>, public TypeOven<T1, T2> {
public:
	void input();
	void print();
	Material();
	Material(const char* n, T2 date_year, T1 date_month, T1 date_day, const char* material);
	~Material();
	Material<T1, T2>(const Material& a);
	Material& operator = (const Material<T1, T2>& a);
protected:
	char* material;
};

template<class T1, class T2>
void Material<T1, T2>::input() {
	Oven<T1, T2>::input();
	TypeOven<T1, T2>::inputType();
	cout << "Введите название материала вашей печи : ";
	cin >> material;
}

template<class T1, class T2>
void Material<T1, T2>::print() {
	Oven<T1, T2>::print();
	cout << endl;
	TypeOven<T1, T2>::printType();
	cout << "Материал вашей печи - " << material << endl;
}

template<class T1, class T2>
Material<T1, T2>::Material() : Oven<T1, T2>() {
	material = new char[11]{ "Неизвестно" };
}

template<class T1, class T2>
Material<T1, T2>::Material(const char* n, T2 date_year, T1 date_month, T1 date_day, const char* material) {
	if (material = "")
		throw "Название материала печи не может быть пустым"; // Ошибка
	this->material = material;
}

template<class T1, class T2>
Material<T1, T2>::~Material() {
	Oven<T1, T2>::~Oven();
}

template<class T1, class T2>
Material<T1, T2>::Material<T1, T2>(const Material& a) {
	if (a == NULL)
		throw "Ссылка указывает на несуществующий элемент"; // Ошибка
	material = a.material;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->year = a.year;
	this->month = a.month;
	this->day = a.day;
}

template<class T1, class T2>
Material<T1, T2>& Material<T1, T2> :: operator = (const Material& a) {
	material = a.material;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->year = a.year;
	this->month = a.month;
	this->day = a.day;
	return (*this);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Ошибки в программе:" << endl;

	// Пустое название печи

	try {
		Oven<int, double> a("", 1725, 10, 15);
	}
	catch (const char* e) {
		cout << e << endl;
	}

	// Отрицательная дата года

	try {
		Oven<int, double> b("Russian", -1111, 10, 15);
	}
	catch (const char* e) {
		cout << e << endl;
	}

	// Отрицательная дата месяца

	try {
		Oven<int, double> c("Russian", 1111, -10, 15);
	}
	catch (const char* e) {
		cout << e << endl;
	}

	// Отрицательная дата дня

	try {
		Oven<int, double> d("Russian", 1111, 10, -15);
	}
	catch (const char* e) {
		cout << e << endl;
	}

	// Пустое название типа печи

	try {
		TypeOven<int, double> f("");
	}
	catch (const char* e) {
		cout << e << endl;
	}

	system("pause");
	return 0;
}
