#include"Header.h"

//===================Player Class======================================================
Player::Player() { checker = true; }
void Player::addPlayerDefault(Team t[], int length) {
	ifstream readme[9];
	srand(time(0));

	readme[0].open("playerNames.txt");
	readme[1].open("shirtNumbers.txt");
	readme[2].open("averageScores.txt");
	readme[3].open("totalRuns.txt");
	readme[4].open("matchesPlayed.txt");
	readme[5].open("totalWickets.txt");
	readme[6].open("testRanking.txt");
	readme[7].open("T20Ranking.txt");
	readme[8].open("ODIRanking.txt");


	string temp;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			getline(readme[0], t[i].p[j].name);
			getline(readme[1], temp);
			t[i].p[j].shirt_no = stoi(temp);
			getline(readme[2], temp);
			t[i].p[j].average = stoi(temp);
			getline(readme[3], temp);
			t[i].p[j].total_runs = stoi(temp);
			getline(readme[4], temp);
			t[i].p[j].matches_played = stoi(temp);
			getline(readme[5], temp);
			t[i].p[j].total_wickets = stoi(temp);
			getline(readme[6], temp);
			t[i].p[j].test_ranking = stoi(temp);
			getline(readme[7], temp);
			t[i].p[j].t20_ranking = stoi(temp);
			getline(readme[8], temp);
			t[i].p[j].ODI_ranking = stoi(temp);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		readme[i].close();
	}
}
//Player* Player::addPlayerCustom(Player *oldAddress, int oldSize) 
//{
//	Player* newArr = new Player[oldSize + 1];
//	for (int i = 0; i < oldSize; i++)
//	{
//		newArr[i].name = oldAddress[i].name;
//		newArr[i].shirt_no = oldAddress[i].shirt_no;
//		newArr[i].average = oldAddress[i].average;
//		newArr[i].t20_ranking = oldAddress[i].t20_ranking;
//		newArr[i].test_ranking = oldAddress[i].test_ranking;
//		newArr[i].ODI_ranking = oldAddress[i].ODI_ranking;
//		newArr[i].total_runs = oldAddress[i].total_runs;
//		newArr[i].matches_played = oldAddress[i].matches_played;
//		newArr[i].total_wickets = oldAddress[i].total_wickets;
//	}
//	delete[]oldAddress;
//	oldAddress = nullptr;
//
//
//	cout << "Enter name: ";
//	cin >> newArr[oldSize].name;
//	cout << "Enter shirt number: ";
//	cin >> newArr[oldSize].shirt_no;
//	cout << "Enter average: ";
//	cin >> newArr[oldSize].average;
//	cout << "Enter T20 ranking: ";
//	cin >> newArr[oldSize].t20_ranking;
//	cout << "Enter Test ranking: ";
//	cin >> newArr[oldSize].test_ranking;
//	cout << "Enter ODI ranking: ";
//	cin >> newArr[oldSize].ODI_ranking;
//	cout << "Enter total runs: ";
//	cin >> newArr[oldSize].total_runs;
//	cout << "Enter matches played: ";
//	cin >> newArr[oldSize].matches_played;
//	cout << "Enter total wickets: ";
//	cin >> newArr[oldSize].total_wickets;
//
//
//	cout << "\nPlayer Added Successfully!\n\n";
//	return newArr;
//}
bool Player::removePlayer(Team t[], string name_for_search, int length)
{
	for (int i = 0; i <= length; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (t[i].p[j].name == name_for_search)
			{
				t[i].p[j].name = "";
				t[i].p[j].shirt_no = NULL;
				t[i].p[j].average = NULL;
				t[i].p[j].t20_ranking = NULL;
				t[i].p[j].test_ranking = NULL;
				t[i].p[j].ODI_ranking = NULL;
				t[i].p[j].total_runs = NULL;
				t[i].p[j].matches_played = NULL;
				t[i].p[j].total_wickets = NULL;


				cout << "\nPlayer Removed Successfully!\n\n";
				checker = false;
			}
		}
	}
	if (checker == true)
	{
		cout << "\nNo Player Found with the Entered Name (for removal)\n";
	}

	return checker;
}
bool Player::searchPlayer(Team t[], string name_for_search, int length)
{
	cout << setw(10) << setfill(' ') << "Name" << setw(10) << "Shirt no." << setfill(' ') << setw(10) << "Average" << setfill(' ') << setw(10) << "T-20" << setfill(' ') << setw(10) << "Test" << setfill(' ') << setw(10) << "ODI" << setfill(' ') << setw(10) << "T-runs" << setfill(' ') << setw(10) << "M-Played" << setfill(' ') << setw(10) << "T-wickets" << setfill(' ') << endl;
	cout << "------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (t[i].p[j].name == name_for_search)
			{
				cout << setw(10) << setfill(' ') << t[i].p[j].name << setw(10) << t[i].p[j].shirt_no << setfill(' ') << setw(10) << t[i].p[j].average << setfill(' ') << setw(10) << t[i].p[j].t20_ranking << setfill(' ') << setw(10) << t[i].p[j].test_ranking << setfill(' ') << setw(10) << t[i].p[j].ODI_ranking << setfill(' ') << setw(10) << t[i].p[j].total_runs << setfill(' ') << setw(10) << t[i].p[j].matches_played << setfill(' ') << setw(10) << t[i].p[j].total_wickets << setfill(' ')  << endl;
				checker = false;
			}
		}
	}
	if (checker == true)
	{
		cout << "\nNo Player Found with the Entered Name (for serach)\n";
	}

	return checker;
}
bool Player::updatePlayer(Team t[], string name_for_search, int length) 
{

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (t[i].p[j].name == name_for_search)
			{
				cout << "Enter New name: ";
				getline(cin >> ws, t[i].p[j].name);
				cout << "Enter shirt number: ";
				cin >> t[i].p[j].shirt_no;
				cout << "Enter average: ";
				cin >> t[i].p[j].average;
				cout << "Enter T20 ranking: ";
				cin >> t[i].p[j].t20_ranking;
				cout << "Enter Test ranking: ";
				cin >> t[i].p[j].test_ranking;
				cout << "Enter ODI ranking: ";
				cin >> t[i].p[j].ODI_ranking;
				cout << "Enter total runs: ";
				cin >> t[i].p[j].total_runs;
				cout << "Enter matches played: ";
				cin >> t[i].p[j].matches_played;
				cout << "Enter total wickets: ";
				cin >> t[i].p[j].total_wickets;

				checker = false;
			}

		}
	}
	if (checker == true)
	{
		cout << "\nNo Player Found with the Entered Name (for updation)\n";
	}

	return checker;
}
Player::~Player() {}


//===================Teams Class======================================================
Team::Team()
{
	checker = true;
	admin_username = "admin";
	admin_password = "admin123";
}

void Team::teamDataDefault(Team t[], int length)
{
	addPlayerDefault(t, 26);
	ifstream readme[6];
	srand(time(0));
	readme[0].open("teamsNames.txt");
	readme[1].open("playerNames.txt");
	readme[2].open("coachesName.txt");
	readme[3].open("T20Ranking.txt");
	readme[4].open("testRanking.txt");
	readme[5].open("ODIRanking.txt");

	string temp;
	for (int i = 0; i <= length; i++)
	{
		getline(readme[0], t[i].team_name);
		t[i].no_of_players = 16;
		t[i].matches_won = 20 + (rand() % 100);
		t[i].matches_lost = 20 + (rand() % 100);

		getline(readme[2], t[i].team_coach);
		getline(readme[3], temp);
		t[i].t20_ranking = stoi(temp);
		getline(readme[4], temp);
		t[i].ODI_ranking = stoi(temp);
		getline(readme[5], temp);
		t[i].test_ranking = stoi(temp);
	}
	int k = 0;
	string garbage;

	for (int i = 0; i < 416; i++)
	{
		if (i % 16 == 0)
		{
			if (k < 26)
			{
				getline(readme[1], t[k].team_captain);
				k++;
			}
		}
		else
		{
			getline(readme[1], garbage);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		readme[i].close();
	}

}
bool Team::accessCheck(string UN, string pass)
{									 //checks username and password
	if (UN == admin_username && pass == admin_password)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Team::updateCaptian(Team t[], string name_for_search, int length)
{
	for (int i = 0; i <= length; i++)
	{
		if (t[i].team_captain == name_for_search)
		{
			cout << "Enter New name: ";
			cin >> t[i].team_captain;


			checker = false;
		}
	}
	if (checker == true)
	{
		cout << "\nNo Captain Found with the Entered Name (for updation)\n";
	}

	return checker;
}

bool Team::updateCoach(Team t[], string name_for_search, int length)
{
	for (int i = 0; i <= length; i++)
	{
		if (t[i].team_coach == name_for_search)
		{
			cout << "Enter New name: ";
			cin >> t[i].team_coach;


			checker = false;
		}
	}
	if (checker == true)
	{
		cout << "\nNo Team Coach Found with the Entered Name (for updation)\n";
	}
	return checker;
}



//=====================Match=========================================================
void Match::conductMatch(Match m[], Team t[], int length)
{
	cout << "\n\n1 Already_Scheduled\n2 Schedule_Match\n";
	char choice = _getch();

	try {
		switch (choice)
		{
		case '1':
			alreadyScheduled(m, t, length);
			break;
		case '2':
			scheduleMatch(m, t, length);
			break;
		default:
			break;
		}
	}

	catch (std::exception err) {
		cerr << err.what() << endl;
	}


}
void Match::alreadyScheduled(Match m[], Team t[], int length)
{
	ifstream reading[4];
	srand(time(0));
	int guess = 0;
	reading[0].open("teamsNames.txt");
	reading[1].open("dates.txt");
	reading[2].open("time.txt");
	reading[3].open("playerNames.txt");

	int j = 0;
	for (int i = 0; i < 6; i++)
	{
		guess = 1 + (rand() % 3);
		m[i].team1 = t[j].team_name;
		m[i].team2 = t[j + 1].team_name;
		j++; j++;
		getline(reading[0], m[i].venue);
		getline(reading[1], m[i].date);
		getline(reading[2], m[i].timee);
		getline(reading[3], m[i].commentator1);
		getline(reading[3], m[i].commentator2);
		getline(reading[3], m[i].umpire1);
		getline(reading[3], m[i].umpire2);
		if (guess == 1 || guess == 2)
		{
			m[i].match_status = "Pending";
		}
		else
		{
			m[i].match_status = "Completed";

		}
		if (guess == 1)
		{
			m[i].match_type = "ODI";
		}
		else if (guess == 2)
		{
			m[i].match_type = "Test";
		}
		else if (guess == 3)
		{
			m[i].match_type = "T20";
		}
	}
	for (int i = 0; i < 4; i++)
	{
		reading[i].close();
	}

	cout << setw(7) << setfill(' ') << "Serial" << setw(25) << "Teams" << setfill(' ') << setw(10) << "Time" << setfill(' ') << setw(10) << "Venue" << setfill(' ') << setw(10) << "Date" << setfill(' ') << setw(10) << "Status" << setfill(' ') << setw(10) << "Type" << setfill(' ') << setw(24) << "  Commentators" << setfill(' ') << setw(23) << "Umpires" << setfill(' ') << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 6; i++)
	{
		cout << setw(7) << setfill(' ') << i + 1 << setw(12) << m[i].team1 << setfill(' ') << setw(4) << "VS" << setfill(' ') << setw(9) << m[i].team2 << setfill(' ') << setw(10) << m[i].timee << setfill(' ') << setw(10) << m[i].venue << setfill(' ') << setw(10) << m[i].date << setfill(' ') << setw(10) << m[i].match_status << setfill(' ') << setw(10) << m[i].match_type << setfill(' ') << setw(12) << m[i].commentator1 << setfill(' ') << setw(3) << "& " << setfill(' ') << setw(9) << m[i].commentator2 << setfill(' ') << setw(12) << m[i].umpire1 << setfill(' ') << setw(3) << "&" << setfill(' ') << setw(8) << m[i].umpire2 << setfill(' ') << endl;
	}
	cout << endl << endl << "Enter Serial Numbers to Conduct Match: ";
	int serialNumber = 10;
	while (serialNumber <= 0 || serialNumber > 6)
	{
		cin >> serialNumber;

		if (serialNumber <= 0 || serialNumber > 6)
		{
			cout << "\n-- INVALID INPUT -- ReEnter --\n";
		}
	}
	
	
	int indexNumber[2];
	indexNumber[1] = serialNumber + (serialNumber - 1);
	indexNumber[0] = indexNumber[1]-1;
	auto a = indexNumber[1];
	auto b = indexNumber[0];
	//m[serialNumber-1].played_status = true;
	conductor(m, t, indexNumber, 2);
}
void Match::conductor(Match m[], Team t[], int indexNumber[], int rounds)
{
	string matchType;
	char choice = '0';
	cout << "\n1 ODI\n2 TEST\n3 T20\n\n";
	while (choice != '1' && choice != '2' && choice != '3')
	{
		choice = _getch();
		if (choice != '1' && choice != '2' && choice != '3')
		{
			cout << "\n-- INVALID CHOICE --\n";
		}
		switch (choice)
		{
		case '1':
			matchType = "ODI";
			break;
		case '2':
			matchType = "TEST";
			break;
		case '3':
			matchType = "T20";
			break;
		}
	}
	cout << "\nTime, Venue and other things will be Chosen by Default\n";
	srand(time(0));
	int winnerIndexGuesser = rand() % rounds;

	/*team1*/
	try {
		Players.push_back(t[indexNumber[0]].team_name);
		Players.push_back(t[indexNumber[1]].team_name);
		Players.push_back(t[indexNumber[winnerIndexGuesser]].team_name);
	}
	catch (std::exception err) {
		cerr << err.what() << endl;
	}


	cout << "\nWinner: " << t[indexNumber[winnerIndexGuesser]].team_name << endl;

	updateTeam_PlayerRanking(t, winnerIndexGuesser, matchType);

}
void Match::updateTeam_PlayerRanking(Team t[], int winnerIndex, string matchType)
{
	t[winnerIndex].matches_won++;
	if (matchType == "TEST")
	{
		if (t[winnerIndex].test_ranking != 1)
		{
			t[winnerIndex].test_ranking--;
		}
	}
	if (matchType == "ODI")
	{
		if (t[winnerIndex].ODI_ranking != 1)
		{
			t[winnerIndex].ODI_ranking--;
		}
	}
	if (matchType == "T20")
	{
		if (t[winnerIndex].t20_ranking != 1)
		{
			t[winnerIndex].t20_ranking--;
		}
	}

	srand(time(0));
	for (int i = 0; i < 16; i++)
	{
		t[winnerIndex].p[i + winnerIndex].total_runs + (50 % rand());
		t[winnerIndex].p[i + winnerIndex].matches_played++;
	}
	updateWorldRecords(t, matchType);
}
void Match::updateWorldRecords(Team t[], string matchType)
{
	cout << "\n------------------------------------\n\tTOP 10 Teams\n";

	Team temp1, temp2, temp3;
	if (matchType == "ODI")
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = i + 1; j < 26; j++)
			{
				if (t[i].ODI_ranking > t[j].ODI_ranking)
				{
					temp1 = t[i];
					t[i] = t[j];
					t[j] = temp1;
				}
			}
		}
	}
	cout << "--------------ODI--------------\n";
	for (int i = 0; i < 10; i++)
	{
		cout << setw(10) << t[i].team_name << setfill(' ') << setw(10) << t[i].ODI_ranking << setfill(' ') << endl;
	}

	if (matchType == "T20")
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = i + 1; j < 26; j++)
			{
				if (t[i].t20_ranking > t[j].t20_ranking)
				{
					temp2 = t[i];
					t[i] = t[j];
					t[j] = temp2;
				}
			}
		}
	}
	cout << "\n--------------T20--------------\n";
	for (int i = 0; i < 10; i++)
	{
		cout << setw(10) << t[i].team_name << setfill(' ') << setw(10) << t[i].t20_ranking << setfill(' ') << endl;
	}
	if (matchType == "TEST")
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = i + 1; j < 26; j++)
			{
				if (t[i].test_ranking > t[j].test_ranking)
				{
					temp3 = t[i];
					t[i] = t[j];
					t[j] = temp3;
				}
			}
		}
	}
	cout << "\n--------------TEST--------------\n";
	for (int i = 0; i < 10; i++)
	{
		cout << setw(10) << t[i].team_name << setfill(' ') << setw(10) << t[i].test_ranking << setfill(' ') << endl;
	}
}
void Match::scheduleMatch(Match m[], Team t[], int length)
{
	ifstream reading;
	reading.open("teamsNames.txt");
	string availableTeams[20];
	string temp;
	int j = 0;

	for (int i = 0; i < 26; i++)
	{
		if (i >= 12)
		{
			getline(reading, availableTeams[j]);
			j++;
		}
		else
		{
			getline(reading, temp);
		}
	}
	reading.close();


	cout << "\nSerial No.\tAvailable Teams\n";
	cout << "---------------------------------------------------\n";
	for (int i = 0; i < j; i++)
	{
		cout << i + 1 << "\t\t" << availableTeams[i] << endl;
	}
	int selectedTeams = 15;
	cout << endl << endl << "How many Teams do want to Select: ";
	while (selectedTeams <= 1 || selectedTeams > 14)
	{
		cin >> selectedTeams;
		if (selectedTeams <= 1 || selectedTeams > 14)
		{
			cout << "\n-- INVALID -- Select within the given Range --\n";
		}
	}

	int st = selectedTeams;
	int i = 0;
	int* serialNumbers = new int[selectedTeams];

	while (selectedTeams > 0)
	{
		cout << "Enter Serial Numbers of Team " << i + 1 << ": ";
		cin >> serialNumbers[i];
		serialNumbers[i] += 11;
		i++; selectedTeams--;
	}
	/*for (int i = 0; i < selectedTeams; i++)
	{
		m[serialNumbers[i]].played_status = true;
	}*/
	conductor(m, t, serialNumbers, st);
}



//=====================Frirends=========================================================
void display(Team t[], int length)
{
	cout << setw(10) << setfill(' ') << "Name" << setw(12) << "Shirt No" << setfill(' ') << setw(10) << "Average" << setfill(' ') << setw(10) << "T-20" << setfill(' ') << setw(10) << "Test" << setfill(' ') << setw(10) << "ODI" << setfill(' ') << setw(10) << "T-runs" << setfill(' ') << setw(10) << "M-Played" << setfill(' ') << setw(10) << "T-wickets" << setfill(' ') << endl;
	cout << "--------------------------------------------------------------------------------------------\n";
	for (int i = 0; i <= length; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << setw(10) << setfill(' ') << t[i].p[j].name << setw(12) << t[i].p[j].shirt_no << setfill(' ') << setw(10) << t[i].p[j].average << setfill(' ') << setw(10) << t[i].p[j].t20_ranking << setfill(' ') << setw(10) << t[i].p[j].test_ranking << setfill(' ') << setw(10) << t[i].p[j].ODI_ranking << setfill(' ') << setw(10) << t[i].p[j].total_runs << setfill(' ') << setw(10) << t[i].p[j].matches_played << setfill(' ') << setw(10) << t[i].p[j].total_wickets << setfill(' ') << endl;
		}
		cout << setw(92) << setfill('_') << "_" << endl;
	}
}
void displayTeam(Team t[], int length)
{
	cout << setw(12) << setfill(' ') << "Name" << setw(12) << "T-Players" << setfill(' ') << setw(10) << "Captain" << setfill(' ') << setw(10) << "T20" << setfill(' ') << setw(10) << "Test" << setfill(' ') << setw(10) << "ODI" << setfill(' ') << setw(10) << "  MatchesWon" << setfill(' ') << setw(10) << "  MatchesLost" << setfill(' ') << setw(8) << "Coach" << setfill(' ') << endl;
	cout << "--------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i <= length; i++)
	{
		cout << setw(12) << setfill(' ') << t[i].team_name << setw(12) << t[i].no_of_players << setfill(' ') << setw(10) << t[i].team_captain << setfill(' ') << setw(10) << t[i].t20_ranking << setfill(' ') << setw(10) << t[i].test_ranking << setfill(' ') << setw(10) << t[i].ODI_ranking << setfill(' ') << setw(10) << t[i].matches_won << setfill(' ') << setw(10) << t[i].matches_lost << setfill(' ') << setw(13) << t[i].team_coach << setfill(' ') << endl;
	}
}

//=====================User Interface=========================================================
#pragma region StartPage

void StartPage::setUp() {


	if (!this->_bgTexture.loadFromFile("Images/cricbuzz.png")) {

		cout << "Error Loading Images/cricbuzz.png" << endl;
		cout << "Shutting Down!" << endl;
		this->_window->close();
	}


	auto textureSize = this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);

}

void StartPage::Display() {

	this->_window->clear();
	this->_window->draw(this->_bgSprite);
	this->_window->display();

}

void StartPage::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::KeyPressed)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->ChangePage = true;
			this->NavTOPage = GamePages::MainPage;
		}
}
#pragma endregion

#pragma region MainMenu

void MainMenu::setUp() {

	if (!this->_bgTexture.loadFromFile("Images/stadium.png")) {

		cout << "Error Loading Images/stadium.png" << endl;
		cout << "Shutting Down!" << endl;
		this->_window->close();
	}

	if (this->_HeaderFont.loadFromFile("Fonts/Handlee.ttf")) {
		this->_btnFont = this->_HeaderFont;                     // Temp can change the Font to your spec
	}
	else {
		cout << "Error Loading Fonts" << endl;
		cout << "Shutting Down!" << endl;
		this->_window->close();
	}

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("Main Menu");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Black);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.0f - (9.0f * 45.0f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (150.f / 3.2f);
	auto Posy = this->_window->getSize().y / 4.f;

	const auto height = 35.f;
	this->_removePlayerButton.setSize(sf::Vector2f(150.f, height));
	this->_removePlayerButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_removePlayerButton.setFillColor(sf::Color(15, 18, 105));

	this->_removePlayer.setFillColor(sf::Color::White);
	this->_removePlayer.setFont(this->_btnFont);
	this->_removePlayer.setCharacterSize(20);
	this->_removePlayer.setString("Remove Player");
	auto Framex = Posx + this->_removePlayerButton.getLocalBounds().width / 1.7 - (this->_removePlayerButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_removePlayerButton.getLocalBounds().height / 1.5 - (this->_removePlayerButton.getLocalBounds().height / 2.f);
	this->_removePlayer.setPosition(Framex, Framey);


	Posy += 45;
	this->_searchPlayerButton.setSize(sf::Vector2f(150.f, height));
	this->_searchPlayerButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_searchPlayerButton.setFillColor(sf::Color(15, 18, 105));

	this->_searchPlayer.setFillColor(sf::Color::White);
	this->_searchPlayer.setFont(this->_btnFont);
	this->_searchPlayer.setCharacterSize(20);
	this->_searchPlayer.setString("Search Player");
	Framex = Posx + this->_searchPlayerButton.getLocalBounds().width / 1.7 - (this->_searchPlayerButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_searchPlayerButton.getLocalBounds().height / 1.5 - (this->_searchPlayerButton.getLocalBounds().height / 2.f);
	this->_searchPlayer.setPosition(Framex, Framey);

	Posy += 45;
	this->_updatePlayerButton.setSize(sf::Vector2f(150.f, height));
	this->_updatePlayerButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_updatePlayerButton.setFillColor(sf::Color(15, 18, 105));

	this->_updatePlayer.setFillColor(sf::Color::White);
	this->_updatePlayer.setFont(this->_btnFont);
	this->_updatePlayer.setCharacterSize(20);
	this->_updatePlayer.setString("Update Player");
	Framex = Posx + this->_updatePlayerButton.getLocalBounds().width / 1.7 - (this->_updatePlayerButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_updatePlayerButton.getLocalBounds().height / 1.5 - (this->_updatePlayerButton.getLocalBounds().height / 2.f);
	this->_updatePlayer.setPosition(Framex, Framey);

	Posy += 45;
	this->_updateCaptainButton.setSize(sf::Vector2f(150.f, height));
	this->_updateCaptainButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_updateCaptainButton.setFillColor(sf::Color(15, 18, 105));

	this->_updateCaptain.setFillColor(sf::Color::White);
	this->_updateCaptain.setFont(this->_btnFont);
	this->_updateCaptain.setCharacterSize(20);
	this->_updateCaptain.setString("Update Captain");
	Framex = Posx + this->_updateCaptainButton.getLocalBounds().width / 1.7 - (this->_updateCaptainButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_updateCaptainButton.getLocalBounds().height / 1.5 - (this->_updateCaptainButton.getLocalBounds().height / 2.f);
	this->_updateCaptain.setPosition(Framex, Framey);

	Posy += 45;
	this->_updateCoachButton.setSize(sf::Vector2f(150.f, height));
	this->_updateCoachButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_updateCoachButton.setFillColor(sf::Color(15, 18, 105));

	this->_updateCoach.setFillColor(sf::Color::White);
	this->_updateCoach.setFont(this->_btnFont);
	this->_updateCoach.setCharacterSize(20);
	this->_updateCoach.setString("Update Coach");
	Framex = Posx + this->_updateCoachButton.getLocalBounds().width / 1.7 - (this->_updateCoachButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_updateCoachButton.getLocalBounds().height / 1.5 - (this->_updateCoachButton.getLocalBounds().height / 2.f);
	this->_updateCoach.setPosition(Framex, Framey);

	Posy += 45;
	this->_displayTeamsButton.setSize(sf::Vector2f(150.f, height));
	this->_displayTeamsButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_displayTeamsButton.setFillColor(sf::Color(15, 18, 105));

	this->_displayTeam.setFillColor(sf::Color::White);
	this->_displayTeam.setFont(this->_btnFont);
	this->_displayTeam.setCharacterSize(20);
	this->_displayTeam.setString("Display Teams");
	Framex = Posx + this->_displayTeamsButton.getLocalBounds().width / 1.7 - (this->_displayTeamsButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_displayTeamsButton.getLocalBounds().height / 1.5 - (this->_displayTeamsButton.getLocalBounds().height / 2.f);
	this->_displayTeam.setPosition(Framex, Framey);

	Posy += 45;
	this->_displayPlayersButton.setSize(sf::Vector2f(150.f, height));
	this->_displayPlayersButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_displayPlayersButton.setFillColor(sf::Color(15, 18, 105));

	this->_displayPlayer.setFillColor(sf::Color::White);
	this->_displayPlayer.setFont(this->_btnFont);
	this->_displayPlayer.setCharacterSize(20);
	this->_displayPlayer.setString("Display Players");
	Framex = Posx + this->_displayPlayersButton.getLocalBounds().width / 1.7 - (this->_displayPlayersButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_displayPlayersButton.getLocalBounds().height / 1.5 - (this->_displayPlayersButton.getLocalBounds().height / 2.f);
	this->_displayPlayer.setPosition(Framex, Framey);

	Posy += 45;
	this->_conductMatchButton.setSize(sf::Vector2f(150.f, height));
	this->_conductMatchButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_conductMatchButton.setFillColor(sf::Color(15, 18, 105));

	this->_conductMatch.setFillColor(sf::Color::White);
	this->_conductMatch.setFont(this->_btnFont);
	this->_conductMatch.setCharacterSize(20);
	this->_conductMatch.setString("Conduct Match");
	Framex = Posx + this->_conductMatchButton.getLocalBounds().width / 1.7 - (this->_conductMatchButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_conductMatchButton.getLocalBounds().height / 1.5 - (this->_conductMatchButton.getLocalBounds().height / 2.f);
	this->_conductMatch.setPosition(Framex, Framey);

	Posy += 45;
	this->_exitButton.setSize(sf::Vector2f(150.f, height));
	this->_exitButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_exitButton.setFillColor(sf::Color(15, 18, 105));

	this->_exit.setFillColor(sf::Color::White);
	this->_exit.setFont(this->_btnFont);
	this->_exit.setCharacterSize(20);
	this->_exit.setString("Exit");
	Framex = Posx + this->_exitButton.getLocalBounds().width / 1.1f - (this->_exitButton.getLocalBounds().width / 1.8f);
	Framey = Posy + this->_exitButton.getLocalBounds().height / 1.5 - (this->_exitButton.getLocalBounds().height / 2.f);
	this->_exit.setPosition(Framex, Framey);


	auto textureSize = this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto  ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);
}


void MainMenu::Display() {

	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);

	this->_window->draw(this->_removePlayerButton);
	this->_window->draw(this->_searchPlayerButton);
	this->_window->draw(this->_updatePlayerButton);
	this->_window->draw(this->_updateCaptainButton);
	this->_window->draw(this->_updateCoachButton);
	this->_window->draw(this->_displayTeamsButton);
	this->_window->draw(this->_displayPlayersButton);
	this->_window->draw(this->_conductMatchButton);
	this->_window->draw(this->_exitButton);

	this->_window->draw(this->_removePlayer);
	this->_window->draw(this->_searchPlayer);
	this->_window->draw(this->_updatePlayer);
	this->_window->draw(this->_updateCaptain);
	this->_window->draw(this->_updateCoach);
	this->_window->draw(this->_displayTeam);
	this->_window->draw(this->_displayPlayer);
	this->_window->draw(this->_conductMatch);
	this->_window->draw(this->_exit);


	this->_window->display();
}

int MainMenu::i = 0;
void MainMenu::OnFocusEvent() {

	if (i == 0)
	{
		t->teamDataDefault(t, j);
		i++;
	}

	string name_for_search;

	if (this->IsMouseOverButton(this->_removePlayerButton)) {

		system("cls");
		cout << "\nEnter Players' Name for Removal: " << std::endl;
		getline(cin >> ws, name_for_search);
		auto check = t->p->removePlayer(t, name_for_search, j);
		string Message = (check != true) ? "Successfully Removed Player" : "Operation Failed!";
		this->AlertWindow(this->_btnFont, Message, 300, 100);
	}

	else if (this->IsMouseOverButton(this->_searchPlayerButton)) {

		system("cls");
		cout << "\nEnter Name for Search: " << std::endl;
		getline(cin >> ws, name_for_search);
		auto check = t->p->searchPlayer(t, name_for_search, j);
		string Message = (check != true) ? " Search Successfully" : "Player Not Found";
		this->AlertWindow(this->_btnFont, Message, 300, 100);
	}

	else if (this->IsMouseOverButton(_updatePlayerButton)) {

		system("cls");
		cout << "\nEnter Name for Updation: " << std::endl;
		getline(cin >> ws, name_for_search);
		auto check = t->p->updatePlayer(t, name_for_search, j);
		string Message = (check != true) ? "Update Successful" : "Player Not Found";
		this->AlertWindow(this->_btnFont, Message, 300, 100);
	}

	else if (this->IsMouseOverButton(this->_updateCaptainButton)) {

		system("cls");
		cout << "\nEnter Name for Updation: " << endl;
		getline(cin >> ws, name_for_search);
		auto check = t->updateCaptian(t, name_for_search, j);
		string Message = (check != true) ? "Update Successful" : "Captian Not Found";
		this->AlertWindow(this->_btnFont, Message, 300, 100);
	}

	else if (this->IsMouseOverButton(this->_updateCoachButton)) {

		system("cls");
		cout << "\nEnter Name for Updation: " << endl;
		getline(cin >> ws, name_for_search);
		auto check = t->updateCoach(t, name_for_search, j);
		string Message = (check != true) ? "Update Successful" : "Coach Not Found";
		this->AlertWindow(this->_btnFont, Message, 300, 100);
	}

	else if (this->IsMouseOverButton(this->_displayTeamsButton)) {

		system("cls");
		displayTeam(t, j);
	}

	else if (this->IsMouseOverButton(this->_displayPlayersButton)) {

		system("cls");
		display(t, j);
	}

	else if (this->IsMouseOverButton(this->_conductMatchButton)) {

		system("cls");

		m->Players.clear();
		m->conductMatch(m, t, k);

		if (m->Players.size() <= 0)
		{
			system("cls");
			cout << "Error Occured! Try Again!" << endl;
			return;
		}

#pragma region WinnerWindow

		sf::RenderWindow win(sf::VideoMode(400, 400), "Conduct Match", sf::Style::Close | sf::Style::None);
		sf::Texture VsTexture;
		sf::Sprite VsSprite;

		if (!VsTexture.loadFromFile("Images/vs.png")) {

			cout << "Error Loading Images/vs.png" << endl;
			cout << "Shutting Down!" << endl;
			this->_window->close();
		}

		auto textureSize = VsTexture.getSize();
		auto WindowSize = win.getSize();
		auto ScaleX = (float)WindowSize.x / textureSize.x;
		auto  ScaleY = (float)WindowSize.y / textureSize.y;

		VsSprite.setTexture(VsTexture);
		VsSprite.setScale(ScaleX, ScaleY);

		sf::Text Player1;
		sf::Text Player2;
		sf::Text Winner;

		Player1.setFont(this->_btnFont);
		Player1.setFillColor(sf::Color::White);
		Player1.setStyle(sf::Text::Bold);
		Player1.setCharacterSize(35);
		Player1.setString(m->Players[0]);
		Player1.setPosition(10, win.getSize().y / 1.5 - Player1.getLocalBounds().height / 2);

		Player2.setFont(this->_btnFont);
		Player2.setFillColor(sf::Color::White);
		Player2.setStyle(sf::Text::Bold);
		Player2.setCharacterSize(35);
		Player2.setString(m->Players[1]);
		Player2.setPosition((win.getSize().x - Player2.getLocalBounds().width) - 10, win.getSize().y / 1.5 - Player2.getLocalBounds().height / 2);

		Winner.setFont(this->_btnFont);
		Winner.setFillColor(sf::Color::White);
		Winner.setStyle(sf::Text::Bold);
		Winner.setCharacterSize(35);
		Winner.setString("Winner: " + m->Players[2]);
		Winner.setPosition((win.getSize().x / 2 - Winner.getLocalBounds().width / 2), win.getSize().y / 1.2 - Winner.getLocalBounds().height / 2);

		while (win.isOpen())
		{
			sf::Event evt;
			while (win.pollEvent(evt))
			{
				if (evt.type == sf::Event::Closed)
					win.close();
			}//
			win.clear();
			win.draw(VsSprite);
			win.draw(Player1);
			win.draw(Player2);
			win.draw(Winner);
			win.display();
		}

#pragma endregion

	}

	else if (this->IsMouseOverButton(this->_exitButton)) {

		this->_window->close();
	}

}

void MainMenu::MouseMoveTigger() {

	if (this->IsMouseOverButton(this->_removePlayerButton)) {
		this->_removePlayerButton.setFillColor(sf::Color::White);
		this->_removePlayer.setFillColor(sf::Color(15, 18, 105));
	}                                                                         // removePlayer
	else {
		this->_removePlayerButton.setFillColor(sf::Color(15, 18, 105));
		this->_removePlayer.setFillColor(sf::Color::White);
	}
	//.........

	if (this->IsMouseOverButton(this->_searchPlayerButton)) {
		this->_searchPlayerButton.setFillColor(sf::Color::White);
		this->_searchPlayer.setFillColor(sf::Color(15, 18, 105));
	}                                                                        //searchPlayer
	else {
		this->_searchPlayerButton.setFillColor(sf::Color(15, 18, 105));
		this->_searchPlayer.setFillColor(sf::Color::White);
	}
	//..........

	if (this->IsMouseOverButton(this->_updatePlayerButton)) {
		this->_updatePlayerButton.setFillColor(sf::Color::White);
		this->_updatePlayer.setFillColor(sf::Color(15, 18, 105));
	}                                                                        //updatePlayer
	else {
		this->_updatePlayerButton.setFillColor(sf::Color(15, 18, 105));
		this->_updatePlayer.setFillColor(sf::Color::White);
	}
	//..........

	if (this->IsMouseOverButton(this->_updateCaptainButton)) {
		this->_updateCaptainButton.setFillColor(sf::Color::White);
		this->_updateCaptain.setFillColor(sf::Color(15, 18, 105));
	}                                                                       //updateCaptain
	else {
		this->_updateCaptainButton.setFillColor(sf::Color(15, 18, 105));
		this->_updateCaptain.setFillColor(sf::Color::White);
	}
	//.........

	if (this->IsMouseOverButton(this->_updateCoachButton)) {
		this->_updateCoachButton.setFillColor(sf::Color::White);
		this->_updateCoach.setFillColor(sf::Color(15, 18, 105));
	}                                                                       //updateCoach
	else {
		this->_updateCoachButton.setFillColor(sf::Color(15, 18, 105));
		this->_updateCoach.setFillColor(sf::Color::White);
	}
	//.........

	if (this->IsMouseOverButton(this->_displayTeamsButton)) {
		this->_displayTeamsButton.setFillColor(sf::Color::White);
		this->_displayTeam.setFillColor(sf::Color(15, 18, 105));
	}                                                                       //displayTeam
	else {
		this->_displayTeamsButton.setFillColor(sf::Color(15, 18, 105));
		this->_displayTeam.setFillColor(sf::Color::White);
	}
	//.........

	if (this->IsMouseOverButton(this->_displayPlayersButton)) {
		this->_displayPlayersButton.setFillColor(sf::Color::White);
		this->_displayPlayer.setFillColor(sf::Color(15, 18, 105));
	}                                                                       //displayPlayer
	else {
		this->_displayPlayersButton.setFillColor(sf::Color(15, 18, 105));
		this->_displayPlayer.setFillColor(sf::Color::White);
	}
	//.........


	if (this->IsMouseOverButton(this->_conductMatchButton)) {
		this->_conductMatchButton.setFillColor(sf::Color::White);
		this->_conductMatch.setFillColor(sf::Color(15, 18, 105));
	}                                                                       //conductMatch
	else {
		this->_conductMatchButton.setFillColor(sf::Color(15, 18, 105));
		this->_conductMatch.setFillColor(sf::Color::White);
	}
	//.........

	if (this->IsMouseOverButton(this->_exitButton)) {
		this->_exitButton.setFillColor(sf::Color::White);
		this->_exit.setFillColor(sf::Color(15, 18, 105));
	}                                                                       //exit
	else {
		this->_exitButton.setFillColor(sf::Color(15, 18, 105));
		this->_exit.setFillColor(sf::Color::White);
	}
	//.........

}

void MainMenu::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();

	if (event->type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			this->ChangePage = true;
			this->NavTOPage = GamePages::MainPage;
		}
	}
}

#pragma endregion

#pragma region MainPage

void MainPage::setUp() {


	if (this->_HeaderFont.loadFromFile("Fonts/Handlee.ttf")) {
		this->_inputFont = this->_HeaderFont;                     // Temp can change the Font to your spec
	}
	else {
		cout << "Error Loading Fonts" << endl;
		cout << "Shutting Down!" << endl;
		this->_window->close();
	}

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("WELCOME TO CRICBUZZ");
	this->_mainTitle.setCharacterSize(30);
	this->_mainTitle.setFillColor(sf::Color(15, 18, 105));
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.0f - (19.0f * 30.0f) / 3.0f, this->_window->getSize().y / 6.0f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto UPosx = this->_window->getSize().x / 2.f - 350.0f / 2.f;
	auto UPosy = this->_window->getSize().y / 3.5f;

	this->_usernameArea.setSize(sf::Vector2f(350.f, 25.f));
	this->_usernameArea.setPosition(sf::Vector2f(UPosx, UPosy));
	this->_usernameArea.setOutlineThickness(2.f);
	this->_usernameArea.setOutlineColor(sf::Color(15, 18, 105));
	this->_usernameArea.setFillColor(sf::Color(220, 220, 220));

	auto PPosx = this->_window->getSize().x / 2.f - 350.0f / 2.f;
	auto PPosy = this->_window->getSize().y / 2.8f;

	this->_passwordArea.setSize(sf::Vector2f(350.f, 25.f));
	this->_passwordArea.setPosition(sf::Vector2f(PPosx, PPosy));
	this->_passwordArea.setOutlineThickness(2.f);
	this->_passwordArea.setOutlineColor(sf::Color(15, 18, 105));
	this->_passwordArea.setFillColor(sf::Color(220, 220, 220));

	this->_username.setFillColor(sf::Color::Black);
	this->_username.setFont(this->_inputFont);
	this->_username.setCharacterSize(15);
	auto usernameFramex = UPosx + 5;
	auto usernameFramey = UPosy + this->_usernameArea.getLocalBounds().height / 6 - (this->_username.getLocalBounds().height / 2);
	this->_username.setPosition(usernameFramex, usernameFramey);

	this->_password.setFillColor(sf::Color::Black);
	this->_password.setFont(this->_inputFont);
	this->_password.setCharacterSize(15);
	auto passwordFramex = PPosx + 5;
	auto passwordFramey = PPosy + this->_passwordArea.getLocalBounds().height / 6 - (this->_password.getLocalBounds().height / 2);
	this->_password.setPosition(passwordFramex, passwordFramey);


	auto posx = this->_window->getSize().x / 2.0f - 200.0f / 2.0f;
	auto posy = this->_window->getSize().y / 2.f;

	this->_loginButton.setSize(sf::Vector2f(200.0, 35.0));
	this->_loginButton.setPosition(sf::Vector2f(posx, posy));
	this->_loginButton.setFillColor(sf::Color(138, 183, 248));


	this->_btnText.setFillColor(sf::Color::White);
	this->_btnText.setFont(this->_inputFont);
	this->_btnText.setCharacterSize(20);
	this->_btnText.setString("Login");
	auto btnFramex = posx + this->_loginButton.getLocalBounds().width / 2 - (this->_btnText.getLocalBounds().width / 2);
	auto btnFramey = posy + this->_loginButton.getLocalBounds().height / 2 - (this->_btnText.getLocalBounds().height / 2);
	this->_btnText.setPosition(btnFramex, btnFramey);
}

void MainPage::Display() {

	this->_window->clear(sf::Color(220, 220, 220));
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_usernameArea);
	this->_window->draw(this->_username);
	this->_window->draw(this->_passwordArea);
	this->_window->draw(this->_password);
	this->_window->draw(this->_loginButton);
	this->_window->draw(this->_btnText);
	this->_window->display();
}

void MainPage::MouseMoveTigger() {

	if (this->IsMouseOverButton(this->_loginButton)) {
		this->_loginButton.setFillColor(sf::Color::White);
		this->_btnText.setFillColor(sf::Color(138, 183, 248));
	}

	else {
		this->_loginButton.setFillColor(sf::Color(138, 183, 248));
		this->_btnText.setFillColor(sf::Color::White);
	}

}

void MainPage::OnFocusEvent(bool ManualCtrl) {

	if (!ManualCtrl) {

		if (this->IsMouseOverButton(this->_usernameArea)) {

			this->_selectedTextArea = TextArea::UserNameArea;
			this->_usernameArea.setFillColor(sf::Color::White);
			this->_passwordArea.setFillColor(sf::Color(220, 220, 220));
		}

		else if (this->IsMouseOverButton(this->_passwordArea)) {

			this->_selectedTextArea = TextArea::PassWordArea;
			this->_passwordArea.setFillColor(sf::Color::White);
			this->_usernameArea.setFillColor(sf::Color(220, 220, 220));
		}

		else {
			this->_selectedTextArea = TextArea::None;
			this->_usernameArea.setFillColor(sf::Color(220, 220, 220));
			this->_passwordArea.setFillColor(sf::Color(220, 220, 220));
		}
	}
	if (this->IsMouseOverButton(this->_loginButton) || ManualCtrl) {

		auto emptyCheck = false;
		if (this->_user.length() == 0) {
			this->_usernameArea.setOutlineColor(sf::Color(255, 0, 0));
			emptyCheck = true;
		}

		if (this->_pass.length() == 0) {
			this->_passwordArea.setOutlineColor(sf::Color(255, 0, 0));
			emptyCheck = true;
		}

		if (emptyCheck) {
			this->AlertWindow(this->_inputFont, "Inputs Can't be Empty!", 300, 100, sf::Color(220, 220, 220), sf::Color(135, 47, 23));
			return;
		}

		if (this->_user == "admin" && this->_pass == "admin123") {

			this->ChangePage = true;
			this->NavTOPage = GamePages::MainMenuPage;
		}

		else {
			this->AlertWindow(this->_inputFont, "Invalid Username or Password", 300, 100, sf::Color(220, 220, 220), sf::Color(135, 47, 23));
		}
	}
}

void MainPage::GetTextInput(sf::Event* event) {

	int charTyped = event->text.unicode;

	std::string* refstring = nullptr;
	sf::Text* refText = nullptr;

	if (this->_selectedTextArea == TextArea::UserNameArea) {
		refstring = &this->_user;
		refText = &this->_username;
	}

	else if (this->_selectedTextArea == TextArea::PassWordArea) {
		refstring = &this->_pass;
		refText = &this->_password;
	}

	else
		return;

	if (charTyped < 128) {


		if (charTyped == ENTER_KEY && this->_selectedTextArea == TextArea::PassWordArea) {
			this->OnFocusEvent(true);
		}

		else if (charTyped == TAB_KEY) {

			if (this->_selectedTextArea == TextArea::UserNameArea) {

				this->_selectedTextArea = TextArea::PassWordArea;
				this->_passwordArea.setFillColor(sf::Color::White);
				this->_usernameArea.setFillColor(sf::Color(220, 220, 220));
			}
			return;
		}

		else if (charTyped != BACKSPACE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {

			refstring->push_back((char)charTyped);
			if (this->_selectedTextArea == TextArea::UserNameArea && this->_usernameArea.getOutlineColor() == sf::Color(255, 0, 0))
				this->_usernameArea.setOutlineColor(sf::Color(15, 18, 105));
			else if (this->_selectedTextArea == TextArea::PassWordArea && this->_passwordArea.getOutlineColor() == sf::Color(255, 0, 0))
				this->_passwordArea.setOutlineColor(sf::Color(15, 18, 105));
		}

		else if (charTyped == BACKSPACE_KEY) {
			if (refstring->length() > 0) {

				refstring->pop_back();
			}
		}

		if (this->_selectedTextArea == TextArea::UserNameArea)
			refText->setString(*refstring);
		else
		{
			std::string mask(refstring->length(), '*');
			refText->setString(mask);
		}
	}
}

void MainPage::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && this->_selectedTextArea == TextArea::None) {
			this->ChangePage = true;
			this->NavTOPage = GamePages::StartPage;
		}
	}

	if (event->type == sf::Event::TextEntered)
		this->GetTextInput(event);

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}

#pragma endregion

#pragma region PagesManager

void PagesManager::HandleEvents(sf::Event* event) {

	this->_currentPage->HandleEvents(event);
	//std::cout << this->_currentPage->_pageID << std::endl;
}

void PagesManager::Display() {

	if (this->_currentPage->ChangePage) {

		if (this->_currentPage->NavTOPage == GamePages::MainMenuPage)
			this->_currentPage = new MainMenu(this->_window);

		else if (this->_currentPage->NavTOPage == GamePages::MainPage)
			this->_currentPage = new MainPage(this->_window);

		else if (this->_currentPage->NavTOPage == GamePages::StartPage)
			this->_currentPage = new StartPage(this->_window);

		return;
	}

	this->_currentPage->Display();
}
#pragma endregion