#include <iostream>
#include <memory>

template<typename T>
struct list_node
{
	T val_;
	list_node* next_;
	list_node* prev_;

	list_node(T val, list_node* next = nullptr, list_node* prev=nullptr)
		: val_(val)
		, next_(next)
		, prev_(prev)
	{
	}

	void set_conection(list_node* next, list_node* prev)
	{
		next_ = next;
		prev_ = prev;
	}
};

template<typename T>
void josephus(list_node<T>* head, size_t step, size_t size)
{
	list_node<T>* ptr = head;

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < step - 1; ++j)
		{
			ptr = ptr->next_;
		}

		ptr->next_->prev_ = ptr->prev_;
		ptr->prev_->next_ = ptr->next_;

		list_node<T>* tmp = ptr->next_;

		std::cout << ptr->val_ << std::ends;

		delete ptr;
		ptr = tmp;
	}

	std::cout << std::endl;
}

int main()
{
	list_node<int>* head  = new list_node<int>(1);
	list_node<int>* node1 = new list_node<int>(2);
	list_node<int>* node2 = new list_node<int>(3);
	list_node<int>* node3 = new list_node<int>(4);
	list_node<int>* node4 = new list_node<int>(5);
	list_node<int>* node5 = new list_node<int>(6);

	head->set_conection(node1, node5);
	node1->set_conection(node2, head);
	node2->set_conection(node3, node1);
	node3->set_conection(node4, node2);
	node4->set_conection(node5, node3);
	node5->set_conection(head, node4);

	size_t step = 3;
	size_t size = 6;

	josephus<int>(head, step, size);
	
	system("pause");
}