#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

void crossRoad(bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP);

//input validation being used in fightingMonster function
void inputValidation1(char& giveDamage) {
	cout << "Press x to give damage to the monster" << endl;
	cout << "'PRESS 0 TO EXIT'" << endl;
	cin >> giveDamage;

	if (giveDamage == 'x')
		return;

	else if (giveDamage == '0')
		exit(0);

	cout << "INVALID KEY PRESSED!" << endl;
	inputValidation1(giveDamage);
}

//input validation being used in south
void inputValidation2(char& choice, bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP) {
	cout << "You are at the gate of the town. A Guard is standing in front of you." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "1. Talk to the Guard" << endl;
	cout << "2. Attack the Guard" << endl;
	cout << "3. Leave" << endl;
	cout << "'PRESS 0 TO EXIT'" << endl;

	cin >> choice;

	if (choice == '0')
		exit(0);

	else if (choice == '1') {
		if (!hasKilledMonster) {
			cout << "I have never seen you here before. You'll have to kill the Monster to get into the Town!" << endl;
		}
		else {
			cout << "Oh you killed that Goblin!? Thankyou so much. You are a true hero!\nWelcome to our town" << endl;
			cout << "YOU WON!\nCONGRATULATIONS!!" << endl;
			exit(0);
		}

		inputValidation2(choice, hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
	}

	else if (choice == '2') {
		cout << "Hey don't be Stupid!" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "The guard fought back and hit you hard.\nYou received 3 damages." << endl;
		playerHP -= 3;

		if (playerHP > 0)
			cout << "Your total HP is now: " << playerHP << endl;

		else {
			cout << "\nYOU DIED!" << endl;
			exit(0);
		}

		inputValidation2(choice, hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
	}

	else if (choice == '3') {
		crossRoad(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
	}

	cout << "INVALID CHOICE" << endl;
	inputValidation2(choice, hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
}

void fightingMonster(int& playerHP, int& monsterHP, char& giveDamage, int& weapon, int& previousHP, double& monsterDamageFactor) {
	if (playerHP <= 0 || monsterHP <= 0)
		return;

	srand(time(0));
	cout << "You are now fighting the monster" << endl;
	cout << "The monster's HP is: " << monsterHP << "\nYour HP is: " << playerHP << endl;
	
	//input validation
	inputValidation1(giveDamage);

	if (weapon == 1) {
		monsterHP = monsterHP - (rand() % 5 + 1);

		if (monsterHP > 0) {
			//reducing monster's power after a damage of 5
			if (monsterHP <= (previousHP - 5)) {
				monsterDamageFactor += 0.5;
				previousHP = monsterHP;
			}

			playerHP = (playerHP - (rand() % 9 + 1)) + monsterDamageFactor;
		}
	}
	else if (weapon == 2) {
		monsterHP = monsterHP - (rand() % 6 + 5); //giving monster more damage because of the sword

		if (monsterHP > 0) {
			//reducing monster's power after a damage of 5
			if (monsterHP <= (previousHP - 5)) {
				monsterDamageFactor += 0.5;
				previousHP = monsterHP;
			}
			
			playerHP = (playerHP - (rand() % 5 + 1)) + monsterDamageFactor; //monster giving lesser damage because player is using the sword
		}
	}
	
	fightingMonster(playerHP, monsterHP, giveDamage, weapon, previousHP, monsterDamageFactor);
}

void west(bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP) {
	int choice = -1, weapon = 1, previousHP = monsterHP;
	double monsterDamageFactor = 0.0;
	char giveDamage = 0, option = 0;

	if (hasKilledMonster) {
		cout << "You have already killed the Goblin" << endl;
		cout << "Press any key to continue" << endl;
		cout << "'PRESS 0 TO EXIT'" << endl;

		cin >> option;
		if (option == '0')
			exit(0);
		else
			crossRoad(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
	}

	cout << "You encounter a Goblin!" << endl;
	cout << "1. Fight\n2. Run" << endl;
	cout << "'PRESS 0 TO EXIT'" << endl;

	cin >> choice;

	if (choice == 0)
		exit(0);

	if(choice == 1) {
		if (weapons[1][1] == "Taken") {
			cout << "Choose your Weapon before the Fight." << endl;
			cout << "1. Knife\n2. Sword" << endl;
			cin >> weapon;
		}

		fightingMonster(playerHP, monsterHP, giveDamage, weapon, previousHP, monsterDamageFactor);

		if (playerHP <= 0 && monsterHP <= 0) {
			hasKilledMonster = true;
			cout << "You Killed The Goblin!" << endl;
			cout << "YOU DIED!" << endl;
			exit(0);
		}

		else if (playerHP <= 0) {
			cout << "YOU DIED" << endl;
			exit(0);
		}

		else {
			cout << "You Killed The Goblin!\nYou obtained the monster's silver ring." << endl;
			hasKilledMonster = true;
			playerHP += 5;

			cout << "Your HP is now: " << playerHP << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << "Press any key to continue" << endl;
			cout << "'PRESS 0 TO EXIT'" << endl;
			cin >> option;

			if (option == '0')
				exit(0);
		}
	}

	crossRoad(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
}

void east(bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP) {
	char choice = 0;

	if (weapons[1][1] == "Taken") {
		cout << "You have already obtained the Sword. No more weapons here." << endl;
	}

	else {
		cout << "You walked into a forest and found a Long Sword!\nCONGRATULATIONS!" << endl;
		weapons[1][1] = "Taken";
	}

	cout << "Press any key to continue" << endl;
	cout << "'PRESS 0 TO EXIT'" << endl;

	cin >> choice;
	if (choice == '0')
		exit(0);
	else
		crossRoad(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
}

void north(bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP) {
	char choice = 0;

	if (riversideCount <= 0) {
		cout << "The river has dried up. No water left to drink." << endl;
	}

	else {
		cout << "There is a River\nYou drink water and rest at the riverside." << endl;
		cout << "Your HP is recovered by 2." << endl;
		playerHP += 2;
		riversideCount -= 1;

		cout << "Your total HP is now: " << playerHP << endl;
		cout << "------------------------------------------------------------------------" << endl;
	}

	cout << "Press any key to continue" << endl;
	cout << "'PRESS 0 TO EXIT'" << endl;

	cin >> choice;

	if (choice == '0')
		exit(0);
	else
		crossRoad(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
}

void south(bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP) {
	char choice = 0;

	inputValidation2(choice, hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
}

void crossRoad(bool& hasKilledMonster, int& playerHP, int& riversideCount, string weapons[][2], int& monsterHP) {
	int choice = 0;

	cout << "You are at the crossroad. If you go South, you'll be at the town's gate." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "1. Go North" << endl;
	cout << "2. Go East" << endl;
	cout << "3. Go South" << endl;
	cout << "4. Go West" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Enter Your Choice" << endl;
	cout << "'PRESS 0 TO EXIT'" << endl;

	cin >> choice;

	switch (choice) {
	case 0:
		break;

	case 1:
		cout << "At North" << endl;
		north(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
		break;

	case 2:
		cout << "At East" << endl;
		east(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
		break;

	case 3:
		cout << "At South" << endl;
		south(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
		break;

	case 4:
		cout << "At West" << endl;
		west(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
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
	string weapons[2][2] = { {"Knife", "Taken"}, {"Sword", "Not Taken"}};

	crossRoad(hasKilledMonster, playerHP, riversideCount, weapons, monsterHP);
	return 0;
}