#include<iostream>
#include<string>
using namespace std;

void crossRoad() {
	int choice = 0;

	cout << "You are at the crossroad. If you go South, you'll be at the town's gate." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "1. Go North" << endl;
	cout << "2. Go East" << endl;
	cout << "3. Go South" << endl;
	cout << "4. Go West" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Enter Your Choice" << endl;
	
	cin >> choice;

	switch (choice) {
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	default:
		cout << "INVALID CHOICE" << endl;
	}
}

int main() {
	int playerHP = 15, monsterHP = 20, riversideCount = 3;
	bool hasKilledMonster = false;
	string weapons[5][5] = { {"Knife", "Taken"}, {"Sword", "Not Taken"}, {"Mace", "Not Taken"}, {"Axe", "Not Taken"}, {"Arrow", "Not Taken"} };

	crossRoad();
	return 0;
}