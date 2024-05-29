#include<iostream>
#include<string>
using namespace std;

void crossRoad(bool& hasKilledMonster, int& playerHP, int& riversideCount);

void north(bool& hasKilledMonster, int& playerHP, int& riversideCount) {
	char choice = 0;

	if (riversideCount <= 0) {
		cout << "The river has dried up. No water left to drink." << endl;
	}

	else {
		cout << "There is a River\nYou drink water and rest at the riverside." << endl;
		cout << "Your HP is recovered by 2." << endl;
		cout << "------------------------------------------------------------------------" << endl;
		playerHP += 2;
		riversideCount -= 1;
	}

	cout << "Press any key to continue" << endl;
	cout << "PRESS 0 TO EXIT" << endl;

	cin >> choice;
	//cout << choice << endl;

	if (choice == '0')
		exit(0);
	else
		crossRoad(hasKilledMonster, playerHP, riversideCount);
}

void south(bool& hasKilledMonster, int& playerHP, int& riversideCount) {
	int choice = 0;

	do {
		cout << "You are at the gate of the town. A Guard is standing in front of you." << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "1. Talk to the Guard" << endl;
		cout << "2. Attack the Guard" << endl;
		cout << "3. Leave" << endl;
		cout << "PRESS 0 TO EXIT" << endl;

		cin >> choice;

		switch (choice) {
		case 0:
			break;

		case 1:
			if (!hasKilledMonster) {
				cout << "I have never seen you here before. You'll have to kill the Monster to get into the Town!" << endl;
			}
			else {
				cout << "Oh you killed that Goblin!? Thankyou so much. You are a true hero!\nWelcome to our town" << endl;
				//proceed to level2
			}
				
			break;

		case 2:
			cout << "Hey don't be Stupid!" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << "The guard fought back and hit you hard.\nYou received 3 damage" << endl;
			playerHP -= 3;

			if (playerHP <= 0)
				exit(0);

			break;

		case 3:
			crossRoad(hasKilledMonster, playerHP, riversideCount);
			break;

		default:
			cout << "INVALID CHOICE<" << endl;
		}
	} while (choice != 0);
	
	if (!choice)
		exit(0);
}

void crossRoad(bool& hasKilledMonster, int& playerHP, int& riversideCount) {
	int choice = 0;

	cout << "You are at the crossroad. If you go South, you'll be at the town's gate." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "1. Go North" << endl;
	cout << "2. Go East" << endl;
	cout << "3. Go South" << endl;
	cout << "4. Go West" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Enter Your Choice" << endl;
	cout << "PRESS 0 TO EXIT" << endl;

	cin >> choice;

	switch (choice) {
	case 0:
		break;

	case 1:
		cout << "North" << endl;
		north(hasKilledMonster, playerHP, riversideCount);
		break;

	case 2:
		cout << "East" << endl;
		break;

	case 3:
		cout << "South" << endl;
		south(hasKilledMonster, playerHP, riversideCount);
		break;

	case 4:
		cout << "West" << endl;
		break;

	default:
		cout << "INVALID CHOICE" << endl;
	}

	if (!choice)
		exit(0);
}

int main() {
	int playerHP = 15, monsterHP = 20, riversideCount = 3;
	bool hasKilledMonster = false;
	string weapons[5][5] = { {"Knife", "Taken"}, {"Sword", "Not Taken"}, {"Mace", "Not Taken"}, {"Axe", "Not Taken"}, {"Arrow", "Not Taken"} };

	crossRoad(hasKilledMonster, playerHP, riversideCount);
	return 0;
}