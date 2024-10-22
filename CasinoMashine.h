#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class CasinoMashine 
{
private:
	int Ticket;
	int ReturnMoney;
	string TempCommand;
	int balacneeeeeee;
	int stawka;
public:
	virtual void InvestMoney(int &money) 
	{
		int TempInvwsted;
		cout << "How much money do you want to invest?" << endl;
		cout << "(Your number must be divisible by 5)" << endl;
		cin >> TempInvwsted;
		bool check = true;
		while(check)
		{
			if (((TempInvwsted) % 5))
			{
				cout << "!!!!!Your number must be divisible by 5!!!!!!" << endl;
				cin >> TempInvwsted;
			}
			else if (TempInvwsted > money)
			{
				cout << "You balance: " << money << endl;
				cin >> TempInvwsted;
			}
			else
			{
				check = false;
			}
		}
		
		Ticket = TempInvwsted / 5;
		money = money - TempInvwsted;
		cout << "You have: " << Ticket << " Ticket   " << "and: " << money << "money" << endl;
		balacneeeeeee = money;
	}
	virtual void WithdrawMoney(int &money)
	{
		int TicketsdÂisplayed;
		bool check = true;
		std::cout << "How many tickets do you want to output?" << endl;
		std::cout << "1 ticket = 4 balance" << endl;
		cin >> TicketsdÂisplayed;
		while (check) 
		{
			if (TicketsdÂisplayed > Ticket)
			{
				cout << "Enter the smaller number on your balance: " << Ticket << endl;
				cin >> TicketsdÂisplayed;
			}
			else if (Ticket == 0)
			{
				check = false;
			}
			else
			{
				money = money + (Ticket * 4);
				check = false;
			}
			cout << "you have: " << money << " money" << endl;
			balacneeeeeee = money;
		}


	}
	virtual void StartMachine()
	{
		Stawka();

		cout << "This machine works on the principle of 3 in a row" << endl;
		char cell[5]{ '^' ,'%' ,'#' ,'!' ,'@' };
		char resultSpin[3]{};
		for (int i = 1; i < 3; i++)
		{
			int temp = rand() % 5 + 1;
			resultSpin[i] = cell[temp]; 
		}
		if (resultSpin[1] == resultSpin[2] == resultSpin[3])
		{
			stawka = stawka * 5;
			cout << "you have won the jackpot!" << endl;
			cout << " | " << resultSpin[1] << " | " << resultSpin[2] << " | " << resultSpin[3] << " | " << endl;
			Ticket = Ticket + stawka;
		}
		else if (resultSpin[1] == resultSpin[2] || resultSpin[3] == resultSpin[2] || resultSpin[1] == resultSpin[3])
		{
			stawka = stawka * 2;
			cout << "you have won " << endl;
			cout << " | " << resultSpin[1] << " | " << resultSpin[2] << " | " << resultSpin[3] << " | " << endl;
			Ticket = Ticket + stawka;
		}
		else
		{
			cout << "you lose" << endl;
			cout << " | " << resultSpin[1] << " | " << resultSpin[2] << " | " << resultSpin[3] << " | " << endl;
			stawka = 0;
			Ticket = Ticket + stawka;
		}


		stawka = 0;
		cout << "you have:" << Ticket << " ticket" << endl;
		
	} 
	virtual void ReadInfo()
	{
		bool cheker = true;
		cout << "Enter the command!" << endl;
		cout << "(if you do not know the commands, enter /info)" << endl;

		cin >> TempCommand;
		if (TempCommand == "/info")
		{
			void CommandInfo();
		}
		else if (TempCommand == "/checkTicket")
		{
			cout << "you have:" << Ticket << " Ticket" << endl;
		}
		else if (TempCommand == "/checkBallace")
		{
			cout << "you have: " << balacneeeeeee << "balance" << endl;
		}
		else if (TempCommand == "/leave")
		{
			
		}
		else if (TempCommand == "/Stawka")
		{
			void Stawka();
		}
		else if (TempCommand == "/spin")
		{
			StartMachine();
		}
		else
		{
			cout << "Comand not detected!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}



	}
	virtual void CommandInfo()
	{
		cout << "/info - All commands " << endl;
		cout << "/checkTicket - Check the number of tickets" << endl;
		cout << "/checkBallace - Check the number of money " << endl;
		cout << "/spin - Launch a casino " << endl;
		cout << "/leave - Go to the menu " << endl;
	}
	virtual void Stawka()
	{
		bool cheker = true;
		while (cheker)
		{
			cout << "How much do you want to bet?" << endl;
			cin >> stawka;

			if (stawka <= Ticket)
			{
				cheker = false;
			}
			else
			{
				cout << "You do not have enough tickets!!" << endl;
				cout << "You have only:" << Ticket << " Tickets" << endl;
				cout << "How much do you want to bet?" << endl;
				cin >> stawka;
			}
		}
		Ticket = Ticket - stawka;
	}
	
}; 

class CasinoWheel : public CasinoMashine 
{
private:
	int Ticket;
	int ReturnMoney;
	string TempCommand;
	int balacneeeeeee;
	int stawka;

public:

	virtual void InvestMoney(int& money)
	{
		int TempInvwsted;
		cout << "How much money do you want to invest?" << endl;
		cout << "(Your number must be divisible by 5)" << endl;
		cin >> TempInvwsted;
		bool check = true;
		while (check)
		{
			if (((TempInvwsted) % 5))
			{
				cout << "!!!!!Your number must be divisible by 5!!!!!!" << endl;
				cin >> TempInvwsted;
			}
			else if (TempInvwsted > money)
			{
				cout << "You balance: " << money << endl;
				cin >> TempInvwsted;
			}
			else
			{
				check = false;
			}
		}

		Ticket = TempInvwsted / 5;
		money = money - TempInvwsted;
		cout << "You have: " << Ticket << " Ticket " << "and: " << money << " money" << endl;
		balacneeeeeee = money;
	}
	virtual void WithdrawMoney(int& money)
	{
		int TicketsdÂisplayed;
		bool check = true;
		std::cout << "How many tickets do you want to output?" << endl;
		std::cout << "1 ticket = 4 balance" << endl;
		cin >> TicketsdÂisplayed;
		while (check)
		{
			if (TicketsdÂisplayed > Ticket)
			{
				cout << "Enter the smaller number on your balance: " << Ticket << endl;
				cin >> TicketsdÂisplayed;
			}
			else if (Ticket == 0)
			{
				check = false;
			}
			else
			{
				money = money + (Ticket * 4);
				check = false;
			}
			cout << "you have: " << money << " money" << endl;
			balacneeeeeee = money;
		}


	}
	virtual void StartMachine()
	{
		Stawka();

		cout << "This machine operates on the wheel's rotation." << endl;
		bool cheker = true;

		int YouNumber;
		cout << "Enter your number from 1 to 51" << endl;
		cin >> YouNumber;
		while (cheker)
		{
			if (!(YouNumber >= 1 && YouNumber <= 51))
			{
				cout << "Enter your number from 1 to 51 !!!!!!" << endl;
				cin >> YouNumber;
			}
			else
			{
				cheker = false;
			}
		}

		int Wheel[51]
		{
			1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
			28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51
		};
		int resultWheel = rand() % 50 + 1;

		for (int i = -6; i < 6; i++)
		{
			if (i == 0)
			{
				cout << "|" << Wheel[resultWheel] << "| ";
			}
			else
			{
				cout << Wheel[resultWheel + i] << " ";
			}
		}
		cout << endl;

		if (Wheel[resultWheel] == YouNumber)
		{
			cout << "you have won the jackpot!" << endl;
			stawka = stawka * 50;
			Ticket = Ticket + stawka;
		}
		else
		{
			cout << "you lose" << endl;
			stawka = 0;
			Ticket = Ticket + stawka;
		}

		
		
		stawka = 0;
		cout << "you have:" << Ticket << " ticket" << endl;
	}
	virtual void ReadInfo()
	{
		bool cheker = true;
		cout << "Enter the command!" << endl;
		cout << "(if you do not know the commands, enter /info)" << endl;

		cin >> TempCommand;
		if (TempCommand == "/info")
		{
			void CommandInfo();
		}
		else if (TempCommand == "/checkTicket")
		{
			cout << "you have:" << Ticket << " Ticket" << endl;
		}
		else if (TempCommand == "/Stawka")
		{
			void Stawka();
		}
		else if (TempCommand == "/checkBallace")
		{
			cout << "you have: " << balacneeeeeee << "balance" << endl;
		}
		else if (TempCommand == "/leave")
		{
			
		}
		else if (TempCommand == "/spin")
		{
			StartMachine();
		}
		else
		{
			cout << "Comand not detected!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}



	}
	virtual void CommandInfo()
	{
		cout << "/info - All commands " << endl;
		cout << "/checkTicket - Check the number of tickets" << endl;
		cout << "/checkBallace - Check the number of money " << endl;
		cout << "/spin - Launch a casino " << endl;
		cout << "/leave - Go to the menu " << endl;
	}
	virtual void Stawka() 
	{
		bool cheker = true;
		while (cheker)
		{
			cout << "How much do you want to bet?" << endl;
			cin >> stawka;
			
			if (stawka <= Ticket)
			{
				cheker = false;
			}
			else
			{
				cout << "You do not have enough tickets!!" << endl;
				cout << "You have only:" << Ticket << " Tickets" << endl;
				cout << "How much do you want to bet?" << endl;
				cin >> stawka;
			}
		}
		Ticket = Ticket - stawka ;
	}
};