#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<fstream>
#include<iomanip>
#include<SFML/Graphics.hpp>

using namespace std;

class Match;
class Team;
class Player {
	string name;
	int shirt_no;
	float average;
	int total_runs;
	int matches_played;
	int total_wickets;
	bool checker;  //checks if at least one player data is entered
	friend void display(Team t[], int length);
	friend void displayTeam(Team t[], int length);
	friend class Match;

protected:
	int t20_ranking;
	int test_ranking;
	int ODI_ranking;

public:
	Player();
	//virtual Team* addPlayerCustom(Team* oldAddress, int oldSize);
	void addPlayerDefault(Team t[], int length);
	virtual bool removePlayer(Team t[], string name_for_search, int length);
	virtual bool searchPlayer(Team t[], string name_for_search, int length);
	virtual bool updatePlayer(Team t[], string name_for_search, int length);
	virtual ~Player();
};

class Team :public Player
{
protected:
	string team_name;
	int no_of_players;
	int matches_won;
	int matches_lost;
	string team_captain;
	string team_coach;
	string admin_username = "admin";
	string admin_password = "admin123";
	string status;
	bool checker;
	friend void displayTeam(Team t[], int length);
	friend class Match;

public:
	Player* p = new Player[16];
	Team();
	void teamDataDefault(Team t[], int length);
	bool accessCheck(string UN, string pass);
	bool updateCaptian(Team t[], string name_for_search, int length);
	bool updateCoach(Team t[], string name_for_search, int length);
};

class Match {
	string team1;
	string team2;
	string date;
	string venue;
	string match_type;
	string tournament_name;
	string commentator1;
	string commentator2;
	string umpire1;
	string umpire2;
	string match_status;
	string timee;

public:
	void conductMatch(Match m[], Team t[], int length);
	void alreadyScheduled(Match m[], Team t[], int length);
	void scheduleMatch(Match m[], Team t[], int length);
	void conductor(Match m[], Team t[], int indexNumbers[], int rounds);
	void updateWorldRecords(Team t[], string matchType);
	void updateTeam_PlayerRanking(Team t[], int winnerIndex, string matchType);
	void displayRecentMatches(Match m[]);
	std::vector<string>Players;


};


//.........................................................................................SFML


enum class GamePages
{
	None,
	StartPage,
	MainPage,
	MainMenuPage
};

enum class TextArea {
	None,
	UserNameArea,
	PassWordArea
};


#define BACKSPACE_KEY 8
#define TAB_KEY 9
#define ENTER_KEY 13
#define ESCAPE_KEY 27


#pragma region BaseClass

class BasePageClass
{

public:

	BasePageClass(sf::RenderWindow* window) {
		this->_window = window;
	}

	virtual void Display() {}
	virtual void HandleEvents(sf::Event*) {}

	std::string _pageID{ " " };
	bool ChangePage{ false };
	GamePages NavTOPage{ GamePages::StartPage };

	sf::RenderWindow* _window;


	bool IsMouseOverButton(const sf::RectangleShape& Btn) {

		float mouseX = sf::Mouse::getPosition(*this->_window).x;
		float mouseY = sf::Mouse::getPosition(*this->_window).y;

		float btnPosX = Btn.getPosition().x;
		float btnPosY = Btn.getPosition().y;

		auto btnPosWidth = btnPosX + Btn.getLocalBounds().width;
		auto btnPosHeight = btnPosY + Btn.getLocalBounds().height;

		if (mouseX < btnPosWidth && mouseX > btnPosX && mouseY <btnPosHeight && mouseY>btnPosY)
			return true;

		return false;
	}

	void AlertWindow(sf::Font cFont, std::string AlertMessage, int Wx, int Wy, sf::Color bgcolor = sf::Color(138, 183, 248), sf::Color messageColor = sf::Color::Black) {

		sf::RenderWindow win(sf::VideoMode(Wx, Wy), "Alert", sf::Style::Close | sf::Style::None);
		sf::Text PlayNameText;

		PlayNameText.setFont(cFont);
		PlayNameText.setFillColor(messageColor);
		PlayNameText.setStyle(sf::Text::Bold);
		PlayNameText.setCharacterSize(15);
		PlayNameText.setString(AlertMessage);
		PlayNameText.setPosition(win.getSize().x / 2 - PlayNameText.getLocalBounds().width / 2, win.getSize().y / 2 - PlayNameText.getLocalBounds().height / 2);

		while (win.isOpen())
		{
			sf::Event evt;
			while (win.pollEvent(evt))
			{
				if (evt.type == sf::Event::Closed)
					win.close();
			}//

			win.clear(bgcolor);
			win.draw(PlayNameText);
			win.display();
		}
	}

};


#pragma endregion


#pragma region StartPage

class StartPage : public BasePageClass
{
public:

	StartPage(sf::RenderWindow* window) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "StartPage";
		this->NavTOPage = GamePages::None;
	}

	void Display() override;
	void HandleEvents(sf::Event*) override;

private:
	void setUp();
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
};

#pragma endregion

#pragma region MainMenu

class MainMenu : public BasePageClass
{
public:

	MainMenu(sf::RenderWindow* window) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "MenuPage";
		this->NavTOPage = GamePages::None;
	}

	void Display() override;
	void HandleEvents(sf::Event*) override;


private:
	Team* t = new Team[26];
	Match* m = new Match[13];
	int k = 12;
	int j = 25;
	static int i;
	void setUp();
	void OnFocusEvent();
	void MouseMoveTigger();
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::Text _mainTitle;
	sf::Font _HeaderFont;
	sf::Font _btnFont;
	sf::RectangleShape _removePlayerButton;
	sf::RectangleShape _searchPlayerButton;
	sf::RectangleShape _updatePlayerButton;
	sf::RectangleShape _updateCaptainButton;
	sf::RectangleShape _updateCoachButton;
	sf::RectangleShape _displayTeamsButton;
	sf::RectangleShape _displayPlayersButton;
	sf::RectangleShape _conductMatchButton;
	sf::RectangleShape _exitButton;
	sf::Text _removePlayer;
	sf::Text _searchPlayer;
	sf::Text _updatePlayer;
	sf::Text _updateCaptain;
	sf::Text _updateCoach;
	sf::Text _displayTeam;
	sf::Text _displayPlayer;
	sf::Text _conductMatch;
	sf::Text _exit;

};
#pragma endregion

#pragma region MainPage

class MainPage : public BasePageClass
{

public:

	MainPage(sf::RenderWindow* window) : BasePageClass(window) {
		this->setUp();
		this->_pageID = "MainPage";
		this->NavTOPage = GamePages::None;
	}

	void Display() override;
	void HandleEvents(sf::Event*) override;

private:

	void setUp();
	void GetTextInput(sf::Event*);
	void OnFocusEvent(bool ManualCtrl = false);
	void MouseMoveTigger();
	sf::Text _mainTitle;
	sf::Font _HeaderFont;
	sf::Font _inputFont;
	sf::Text _username;
	sf::Text _password;
	sf::Text _btnText;
	std::string _pass{};
	std::string _user{};
	bool _isUsernameBlock{ false };
	bool _isPasswordBlock{ false };
	sf::RectangleShape _usernameArea;
	sf::RectangleShape _passwordArea;
	sf::RectangleShape _loginButton;
	TextArea _selectedTextArea{ TextArea::None };

};
#pragma endregion

#pragma region PagesManager

class PagesManager
{

public:

	PagesManager(sf::RenderWindow* window) {

		this->_window = window;
		this->_currentPage = new StartPage(this->_window);
	}

	void HandleEvents(sf::Event*);
	void Display();

private:
	sf::RenderWindow* _window;
	BasePageClass* _currentPage = nullptr;

};

#pragma endregion