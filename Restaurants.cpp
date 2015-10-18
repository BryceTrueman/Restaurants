/*
				Test Case 1 - 
Chose option 1
Displayed: 
Restaurant #1 : Chipotle,
Restaurant #2 : Olive Garden,
Restaurant #3 : Round Table,
Restaurant #4 : La Comida,
Restaurant #5 : Panda Express,
Restaurant #6 : Brick Oven,
Restaurant #7 : Taco Bell,
Restaurant #8 : Red Robin

				Test Case 2 - 
Chose option 2
"Which restaurant would you like to add?: In n out
Chose option 3 
"Which restaurant would you like to remove?: Chipotle
Chose option 1 
Restaurant #1 : Olive Garden,
Restaurant #2 : Round Table,
Restaurant #3 : La Comida,
Restaurant #4 : Panda Express,
Restaurant #5 : Brick Oven,
Restaurant #6 : Taco Bell,
Restaurant #7 : Red Robin,
Restaurant #8 : In n out

				Test Case 2 - 
Chose option 5
Chipotle / Olive Garden
Chipotle

Round Table / La Comida
Round Table

Panda Express / Brick Oven
Panda Express

Taco Bell / Red Robin
Taco Bell

Chipotle / Round Table
Round Table

Panda Express / Taco Bell
Panda Express

Round Table / Panda Express
Round Table

The Winner is Restauraunt #1: Round Table
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

string Menu()
{
	string menu_choice;
		cout << endl;
		cout << endl;
		cout << "Please choose one of the following options." << endl;
		cout << "1. Display all restaurants." << endl;
		cout << "2. Add a restaurant." << endl;
		cout << "3. Remove a restaurant." << endl;
		cout << "4. Shuffle the restaurants" << endl;
		cout << "5. Begin the tournament!" << endl;
		cout << "6. Quit." << endl;
		cout << endl;
		cout << "What is your choice?: ";
		getline(cin, menu_choice);
		cout << endl;
	return menu_choice;
}

vector<string> AllRestaurants()
{
	vector<string> Restaurants;
	Restaurants.push_back("Chipotle");
	Restaurants.push_back("Olive Garden");
	Restaurants.push_back("Round Table");
	Restaurants.push_back("La Comida");
	Restaurants.push_back("Panda Express");
	Restaurants.push_back("Brick Oven");
	Restaurants.push_back("Taco Bell");
	Restaurants.push_back("Red Robin");
	return Restaurants;
}

void ShowAllRestaurants(vector<string> Restaurants)
{
	for (int i = 0; i < Restaurants.size(); i++)
	{
		cout << "Restaurant #" << i + 1 << ": " << Restaurants[i];
		if (i != (Restaurants.size() - 1))
		{
			cout << "," << endl;
		}
	}
}

int FindRestaurant(vector<string> Restaurants, string findMe)
{
	for (int i = 0; i < Restaurants.size(); i++)
	{
		if (Restaurants[i] == findMe)
		{
			return i;
		}
	}
	return -1;
}

void AddRestaurant(vector<string>& Restaurants)
{
		string findMe;
		cout << "Please enter the Restaurant you would like to add: ";
		getline(cin, findMe);
		int index = FindRestaurant(Restaurants, findMe);
		if (index == -1)//restaurant DOES exist and you are about to take it out
		{
			Restaurants.push_back(findMe);
			cout << endl;
			cout << "\tYou added the restaurant: " << findMe << endl;
		}
		if (index != -1)//restaurant doesnt exist
		{
			cout << endl;
			cout << "\tSorry that restaurant is already in the game." << endl;
		}
}

void RemoveRestaurant(vector<string>& Restaurants)
{
	string findMe;
	cout << "Please enter the Restaurant you would like to take out: ";
	getline(cin, findMe);
	int index = FindRestaurant(Restaurants, findMe);
	int restaurant_location = FindRestaurant(Restaurants, findMe);
	if (index == -1)//restaurant is found
	{
		cout << "Sorry that restaurant is not in our list." << endl;
	}
	if (index != -1)//restaurant is not found
	{
		cout << "You took out: " << findMe << endl;
		Restaurants.erase(Restaurants.begin() + restaurant_location);
	}
}

void Tournament(vector<string>& Restaurants)
{
	cout << "For each scenario, please choose the restaurant you would prefer." << endl;
	cout << endl;
	vector<string> Winners;
	
	while (Restaurants.size() > 1)
	{
	int a = 0;
	int b = 1;
		for (int i = 0; i < (Restaurants.size() / 2); i++)
		{
			string choice;
			cout << endl;
			cout << Restaurants[a] << " / " << Restaurants[b] << endl;
			cin.sync();
			getline(cin, choice);
			while (choice != Restaurants[a] && choice != Restaurants[b])
			{
				cout << "Please choose one of the above choice: ";
				cin.sync();
				getline(cin, choice);
			}
			if (choice == Restaurants[a])
			{
				Winners.push_back(Restaurants[a]);
			}
			if (choice == Restaurants[b])
			{
				Winners.push_back(Restaurants[b]);
			}
			a = a + 2;
			b = b + 2;
		}
		Restaurants = Winners;
		Winners.clear();
	}
	cout << endl;
	cout << "\tThe Winner is "; 
	ShowAllRestaurants(Restaurants);
}

vector<string> ShuffleRestaurants(vector<string> Restaurants)
{
	int const Times_to_switch = 100;
	for (int i = 0; i < Times_to_switch; i++)
	{

		int randomLoc1 = rand() % Restaurants.size();
		int randomLoc2 = rand() % Restaurants.size();

		string Restaurant1 = Restaurants[randomLoc1];
		string Restaurant2 = Restaurants[randomLoc2];

		Restaurants[randomLoc1] = Restaurant2;
		Restaurants[randomLoc2] = Restaurant1;
	}
	return Restaurants;
}

int main()
{
	srand(time(NULL));
	cout << "\t\t\tWelcome to my program!" << endl;
	cout << "\tI hope this keeps your family from falling apart!" << endl;
	cout << "\t-----------------------------------------------------------" << endl;
	cout << endl;
	vector<string> Restaurants;
	Restaurants = AllRestaurants();
	string menu_choice;
	do
	{
		menu_choice = Menu();
		if (menu_choice == "1")//display restaurants
		{
			cout << "Here are your restaurants." << endl;
			ShowAllRestaurants(Restaurants);
		}
		if (menu_choice == "2")//add a restaurant
		{
			AddRestaurant(Restaurants);
		}
		if (menu_choice == "3")//remove a restaurant
		{
			RemoveRestaurant(Restaurants);
		}
		if (menu_choice == "4")//shuffle restaurants
		{
			Restaurants = ShuffleRestaurants(Restaurants);
			cout << endl;
			ShowAllRestaurants(Restaurants);
		}
		if (menu_choice == "5")//tournament
		{
			bool valid_amount = false;

			for (int n = 0; n < 10; n++)
			{
				if (Restaurants.size() == pow(2, n))//checks if bool is true
				{
					valid_amount = true;
				}
			}
			if (valid_amount == true)//sets bool to true
			{
				Tournament(Restaurants);
			}
			else//boolean is still false
			{
				cout << "Sorry you do not have the correct amount of Restaurants to proceed." << endl;
				cout << "Please have a value that is a power of 2." << endl;
			}
		}
		if (menu_choice == "6")//quit the program
		{
			cout << "\t\tHave a nice day!" << endl;
			cout << "\t  I hope everything works out!" << endl;
			cout << endl;
			return 1;
		}
	} while (menu_choice != "6");//6 is the quit option
	
	
	system("pause");
	return 0;
}


