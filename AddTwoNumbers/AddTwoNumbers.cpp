/**
 * Carson Gedeus, 10/20/2023
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <ctime>

#define SIZE 5

using namespace std;

class Node
{
	public:
		int data;
		Node* next = NULL;

		Node(int data)
		{
			this->data = data;
		}
};

class AddTwoNumbers
{
	private:
		Node* head = NULL;

	public:
		Node* tailInsert(int data)
		{			
			if (head == NULL)
			{
				head = new Node(data);
				return head;
			}

			Node* move = head;
			while (move->next != NULL)
			{
				move = move->next;
			}
			move->next = new Node(data);

			return head;
		}

		void printList()
		{
			while (head != NULL)
			{
				cout << head->data << " ";
				head = head->next;
			}
			cout << endl;
		}

		int addTwoNumbers(Node* onelist, Node* twolist)
		{
			int sum = 0;
			int sumArray[SIZE];

			for (int i = 0; onelist != NULL && twolist != NULL; i++)
			{
				sumArray[i] = onelist->data + twolist->data;

				if (sumArray[i] > 10)
				{
					sumArray[i] %= 10;
				}

				onelist = onelist->next;
				twolist = twolist->next;
			}

			for (int i = 0; i < SIZE; i++)
			{
				sum += sumArray[i];
			}

			cout << "Sum is " << sum << endl;;

			return sum;
		}
};

int main(void)
{
	AddTwoNumbers sum;
	AddTwoNumbers firstList;
	AddTwoNumbers secondList;

	Node* onelist;
	Node* twolist;

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		onelist = firstList.tailInsert(rand() % 10);
		twolist = secondList.tailInsert(rand() % 10);
	}

	firstList.printList();
	secondList.printList();

	sum.addTwoNumbers(onelist, twolist);

	return 0;
}