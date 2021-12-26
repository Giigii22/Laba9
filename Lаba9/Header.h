
#include <iostream>
using namespace std;

struct Element
{
	int number;
	Element* next;
	Element* prev;
};

class STACK
{
	Element* head;
	Element* tail;
public:
	STACK();
	STACK(const STACK& other);
	STACK(STACK&& other)noexcept;
	~STACK();

	void push(int element);
	int pop();
	int peek();
	int get_size();

	STACK& operator=(const STACK& other);
	STACK& operator=(STACK&& other)noexcept;

	friend ostream& operator<<(ostream& stream, const STACK& that)
	{
		if (that.head == NULL) return stream << "Очередь пуста";
		Element* temp = that.head;
		while (temp != that.tail)
		{
			stream << temp->number << " ";
			temp = temp->prev;
		}
		return stream << temp->number;
	}
};