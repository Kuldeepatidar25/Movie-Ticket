#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	char row_no;
	int seat_no, pin;
	char book;
	struct node *next, *prev;
}node;

class dcll
{
	public:
		node * hn;
	dcll()
	{
		hn = NULL;
	}

	public:
		void create()
		{
			node *n, *cn;
			int j = 1;
			volatile int k = 2;
			char c = 'A';

			do {
				int i = 1;
				do {
					k = (k *k) / 10 + 100 - k / 2;
					n = new node();
					n->next = n->prev = NULL;
					n->row_no = c;
					n->seat_no = i;
					n->pin = k;
					n->book = 'a';
					if (hn == NULL)
					{
						hn = n;
						n->next = n->prev = hn;
					}
					else
					{
						cn = hn;

						while (cn->next != hn)
							cn = cn->next;

						cn->next = n;
						n->prev = cn;
						n->next = hn;
						hn->prev = n;
					}

					i++;
				} while (i <= 7);
				j++;
				c++;
			} while (j <= 10);
		}

	void display()
	{
		node * cn;
		cn = hn;
		cout << "------------------------------------------------------------------\n";
		cout << "|                            Platinum                            |\n";
		while (cn->next != hn)
		{
			if ((cn->prev)->row_no != cn->row_no)
				cout << "| ";
			cout << cn->row_no;
			cout << cn->seat_no;
			if (cn->book == 'a')
				cout << " -> a  ";	//green text with black background
			else
				cout << " -> b  ";	//red text
			if ((cn->next)->row_no != cn->row_no)
				cout << "|\n";
			if (cn->row_no == 'C' && cn->seat_no == 7)
			{
				cout << "------------------------------------------------------------------\n";
				cout << "|                             gold                               |\n";
			}

			if (cn->row_no == 'H' && cn->seat_no == 7)
			{
				cout << "------------------------------------------------------------------\n";
				cout << "|                            Silver                              |\n";
			}

			cn = cn->next;
		}

		cout << cn->row_no;
		cout << cn->seat_no;
		if (cn->book == 'a')
			cout << " -> a  ";	//green text with black background

		else
			cout << " -> b  ";	//red text
		cout << "|\n";

		cout << "------------------------------------------------------------------\n\n";
		cout << "PLATINUM-> 150              GOLD-> 100                  SILVER->60\n";
	}

	void display1(node *tmp[20], int n)
	{
		if (n != 1)
		{
			cout << "------------------------------------------------------------------\n";
			cout << "THANK YOU!\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n";
			for (int i = 1; i < n; i++)

				cout << tmp[i]->row_no << tmp[i]->seat_no << "    PIN : " << tmp[i]->pin << "\n";

			cout << "!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
			cout << "PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n";
			cout << "------------------------------------------------------------------\n";
		}
	}

	void book_seat()
	{
		node *cn, *temp[20];
		int n, z, flag;
		char row;
		int seat;
		char ch;
		do {
			z = 1;
			cout << "\nEnter No Of Tickets u Want To Buy: ";
			cin >> n;

			cout << "\nEnter Seat Number(s): \n";

			for (int i = 1; i <= n; i++)
			{
				cout << "NO " << i << " = ";
				cin >> row >> seat;
				cn = hn;
				if (row >= 'A' && row <= 'E')
				{
					while (cn->next != hn)
					{
						if (cn->row_no == row && cn->seat_no == seat)
						{
							if (cn->book == 'a')
							{
								cn->book = 'b';
								temp[z] = cn;
								z++;
							}
							else
							{
								cout << "INVALID CHOISE!\n";
								cout << cn->row_no << cn->seat_no << " Seat is alredy reserved \n";

							}
						}

						cn = cn->next;
					}

					if (cn->row_no == row && cn->seat_no == seat)
					{
						if (cn->book == 'a')
						{
							cn->book = 'b';
							temp[z] = cn;
							z++;
						}
						else
						{
							cout << "INVALID CHOISE!\n";
							cout << cn->row_no << cn->seat_no << " Seat is alredy reserved\n";
						}
					}
				}
				else	//
				{
					while (cn->prev != hn)
					{
						if (cn->row_no == row && cn->seat_no == seat)
						{
							if (cn->book == 'a')
							{
								cn->book = 'b';
								temp[z] = cn;
								z++;
							}
							else
							{
								cout << "INVALID CHOISE!\n";
								cout << cn->row_no << cn->seat_no << " Seat is alredy reserved \n";

							}
						}

						cn = cn->prev;
					}

					if (cn->row_no == row && cn->seat_no == seat)
					{
						if (cn->book == 'a')
						{
							cn->book = 'b';
							temp[z] = cn;
							z++;
						}
						else
						{
							cout << "INVALID CHOISE!\n";
							cout << cn->row_no << cn->seat_no << " Seat is alredy reserved\n";
						}
					}
				}
			}

			display1(temp, z);
			cout << "\n\nPRESS 1 To check Seat Status\n";
			cout << "PRESS 2 To book other seat\n";
			cout << "PRESS 3 To Exit BOOKING PORTAL\n";
			cout << "\ninput: ";
			cin >> ch;
			if (ch == 1)
				display();
		} while (ch == '2');
	}

	void cancle()
	{
		char row, ch;
		int seat, pin;
		node * cn;
		cout << "SEAT CANCELATION\n";
		do {
			ch = 'a';
			cn = hn;
			cout << "SEAT NUMBRE :";
			cin >> row >> seat;
			cout << "PIN :";
			cin >> pin;
			if (row >= 'A' && row <= 'E')
			{
				while (cn->next != hn)
				{
					if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
					{
						cout << "Are you sure u want to cancle the Seat (y/n) ";
						char c;
						cin >> c;
						if (c == 'y' || c == 'Y')
						{
							cout << "SEAT CANCELED SUCCESFULLY!\n";
							cn->book = 'a';
						}
					}
					else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
					{
						cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
					}

					cn = cn->next;
				}

				if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
				{
					cout << "Are you sure u want to cancle (y/n) ";
					char c;
					cin >> c;
					if (c == 'y' || c == 'Y')
					{
						cout << "SEAT CANCELED SUCCESFULLY!\n";
						cn->book = 'a';
					}
				}
				else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
				{
					cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
				}
			}
			else
			{
				while (cn->next != hn)
				{
					if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
					{
						cout << "Are you sure u want to cancle the Seat (y/n) ";
						char c;
						cin >> c;
						if (c == 'y' || c == 'Y')
						{
							cout << "SEAT CANCELED SUCCESFULLY!\n";
							cn->book = 'a';
						}
					}
					else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
					{
						cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
					}

					cn = cn->next;
				}

				if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
				{
					cout << "Are you sure u want to cancle (y/n) ";
					char c;
					cin >> c;
					if (c == 'y' || c == 'Y')
					{
						cout << "SEAT CANCELED SUCCESFULLY!\n";
						cn->book = 'a';
					}
				}
				else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
				{
					cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
				}
			}

			cout << "\n\nPRESS 1 To Check Seat Status\n";
			cout << "PRESS 2 To Cancle More Tickets\n";
			cout << "PRESS 3 To Exit CANCELATION PORTAL\n";
			cout << "\ninput: ";
			cin >> ch;
			if (ch == 1)
				display();
		} while (ch == '2');
	}
};

int main()
{
	dcll o;
	int ch;
	char c;
	cout << "\n\n\n";
	cout << "                 @@@@@@   Cinemax  @@@@@@\n";
	cout << "                vvvvvv ARRANGEMENT vvvvvv\n\n";
	o.create();
	o.display();

	do {
		cout << "\n\n\n";
		cout << "PRESS 1-> BOOK TICKETS\n";
		cout << "PRESS 2-> CANCLE TICKETS\n";
		cout << "PRESS 3-> EXIT\n";
		cout << "\ninput: ";
		cin >> ch;
		switch (ch)
		{
			case 1:
				o.book_seat();
				o.display();
				break;
			case 2:
				o.cancle();
				o.display();
				break;
		}

		if (ch != 3)
		{
			cout << "\n\nPRESS 1 To Main Menu\n";
			cout << "PRESS 2 To Exit CINEMAX PORTAL\n";
			cout << "\ninput: ";
			cin >> c;
		}
	} while (c == '1');
	cout << "\n\n\n";
	return 0;

}
