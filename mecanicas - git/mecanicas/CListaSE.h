#pragma once
template <typename T>
class SList
{
	struct Node
	{
		T elem;
		Node* next;

		Node(T elem, Node* next = nullptr)
			: elem(elem), next(next) {}
	};

	int length;  //lon
	Node* first; //ini
	Node* fin;

public:
	SList() : length(0), first(nullptr) {}
	~SList()
	{
		while (first != nullptr)
		{
			Node* aux = first;
			first = first->next;
			delete aux;
		}
	}

	bool isEmpty()
	{
		return first == nullptr;
	}
	T getElem(int pos) {
		if (pos == 0) {
			Node* aux = first;
			return aux->elem;
		}
	}
	int size()
	{
		return length;
	}

	void addFirst(T elem)
	{
		first = new Node(elem, first);
		if (length == 0)
		{
			fin = first;
		}

		length++;
	}

	void insert(T elem, int pos)
	{
		if (pos == 0)
		{
			addFirst(elem);
		}
		else if (pos > 0 && pos < length)
		{
			Node* aux = first;
			for (int i = 1; i < pos; i++) //tambien for (int i = 0; i < pos-1; i++)
			{
				aux = aux->next;
			}
			aux->next = new Node(elem, aux->next);
			length++;
		}
		else if (pos == length)
		{
			insertfin(elem);
		}
	}
	void insertfin(T elem)
	{
		Node* aux = first;
		for (int i = 1; i < length; i++) //tambien for (int i = 0; i < pos-1; i++)
		{
			aux = aux->next;
		}
		aux->next = new Node(elem, aux->next);
		fin = aux->next;
		length++;
	}

	void append(T elem)
	{
		insert(elem, length);
	}

	void deleteFirst()
	{
		if (length > 0)
		{
			Node* aux = first;
			first = first->next;
			delete aux;
			length--;
		}
	}

	void deletePos(int pos)
	{
		if (pos == 0)
		{
			deleteFirst();
		}
		else if (pos > 0 && pos <= length)
		{
			Node* aux = first;
			for (int i = 0; i < pos - 1; i++)
			{
				aux = aux->next;
			}
			Node* aux2 = aux->next;
			aux->next = aux2->next; // 	aux->next = aux->next->next;
			delete aux2;
			length--;
		}
	}
	void deleteLast()
	{
		deletePos(length - 1);
	}
	T getAt(int pos)
	{
		if (pos >= 0 && pos < length)
		{
			Node* aux = first;
			for (int i = 0; i < pos; i++)
			{
				aux = aux->next;
			}
			return aux->elem;
		}
		
	}
};

/*TODO: Hacer los demás funciones de la lista simplente enlazada con puntero al principio y al final
 agregar primer eemento en lsta doble enlazada

void addFirst(T elem)
{
	first = new Nodo(elem, first);
	if (length > 0)
	{
		first->next->prev = first;
	}
	lenght++;
}*/