#include <unordered_set>
#include <unordered_map>
#include <string>
#include <functional>
#include <list>
#include <stdexcept>
#include <iostream>
#include <random>
#include <stdlib.h>

using namespace std;

extern class EventManager;
static EventManager* mainEventmgr = nullptr;

struct Resource { //�ڿ� ����ü
	int food =  10; //�跮 �ڿ�
	int human = 10;//�η� �ڿ�
	int money = 10;//��   �ڿ�
	int faith = 10;//�ž� �ڿ�
	int milli = 10;//���� �ڿ�
	int diplo = 10;//�ܱ� �ڿ�
};

void ShowResource(const Resource& r) {
	
	cout << "�ķ�:";
	if (r.food < 5) { cout << "����"; }
	else if (r.food < 10) { cout << "����"; }
	else if (r.food < 15) { cout << "����"; }
	else { cout << "ǳ��"; }
	cout << "   ";
	cout << "�η�:";
	if (r.human < 5) { cout << "����"; }
	else if (r.human < 10) { cout << "����"; }
	else if (r.human < 15) { cout << "����"; }
	else { cout << "ǳ��"; }
	cout << "   ";
	cout << "����:";
	if (r.money < 5) { cout << "����"; }
	else if (r.money < 10) { cout << "����"; }
	else if (r.money < 15) { cout << "����"; }
	else { cout << "ǳ��"; }
	cout << "   ";
	cout << "�ܱ�:";
	if (r.diplo < 5) { cout << "����"; }
	else if (r.diplo < 10) { cout << "����"; }
	else if (r.diplo < 15) { cout << "����"; }
	else { cout << "ǳ��"; }
	cout << "   ";
	cout << "����:";
	if (r.milli < 5) { cout << "����"; }
	else if (r.milli < 10) { cout << "����"; }
	else if (r.milli < 15) { cout << "����"; }
	else { cout << "ǳ��"; }
	cout << "   ";
	cout << "�ž�:";
	if (r.faith < 5) { cout << "����"; }
	else if (r.faith < 10) { cout << "����"; }
	else if (r.faith < 15) { cout << "����"; }
	else { cout << "ǳ��"; }
	cout << "   " << endl;
}

class Item {
public:
	const string name; //������ �̸�

	const int cost;
	Resource effect;//������ ȿ��;

	std::vector<string> childItem;

	Item(const string first, const int cost, const Resource effect, const std::vector<string> childItem) : name(first), cost(cost), effect(effect), childItem(childItem) {
		
	}
};

struct Player //�÷��̾� ����ü
{ 
	list<Item> inventory;//������ ���
	Resource res; //�ڿ�
	int rank = 0; //��ũ ����Ʈ
};



struct Gamedata
{
	Player player;
	unordered_map<string, string> dict;
	unordered_map<string, int> delay;
};

static bool AlwaysTrue(Gamedata&) { return true; } //�׻� ��

class EventSelectItem //�̺�Ʈ ������ ����ü
{
public:
	string name = "null";//�̺�Ʈ �������� �̸�
	string content = "null";//�̺�Ʈ �������� ����
	function<bool(Gamedata&)> CanVisible = AlwaysTrue; //ǥ�� �������� �˷��ִ� �Լ�
	function<bool(Gamedata&)> CanRun = AlwaysTrue; //���� �������� �˷��ִ� �Լ�
	function<void(Gamedata&)> Effect; //�����ϸ� ����Ǵ� ȿ�� �Լ�

	EventSelectItem() = delete;
	EventSelectItem(string _name = "���� ����") :name(_name) {

	}
};

enum class EventPriority //�̺�Ʈ �켱����
{
	None,   //����
	Lowest, //�ſ� ����
	Low,    //����
	Normal, //�߰�
	High,   //����
	Highest, //�ſ� ����
};

class Event //�̺�Ʈ ����ü
{
public:
	function<bool(Gamedata&)> CanStart = AlwaysTrue; //���� �������� �˷��ִ� �Լ�
	string name; //�̺�Ʈ�� ����
	string content; //�̺�Ʈ�� ǥ�õ� ����
	vector<EventSelectItem> item;  //�̺�Ʈ�� ������
	EventPriority prio = EventPriority::Normal; //�̺�Ʈ�� �켱����

	Event() = delete;

	Event(string _name = "���� ����", EventPriority _prio = EventPriority::Normal) :name(_name), prio(_prio) {

	}


};

class EventManager
{
	list<Event> event;
public:
	Gamedata gamedata;
	mt19937_64 rand;
	vector<Item> allItem;

	EventManager()
	{
		std::random_device rd;
		rand = mt19937_64(rd());
		mainEventmgr = this;
	}

	bool RandomPercent(const float& percent)
	{
		return ((rand() % 10001) / 100.f) < percent;
	}

	int RandomInt(const int& min, const int& max)
	{
		return rand() % (max - min + 1) + min;
	}

	void AddEvent(const Event e)
	{
		event.push_back(e);
	}

	const Event GetNewEvent()
	{
		EventPriority p = EventPriority::None;

		Event _return("null");
		for (auto& e : event)
		{
			if (e.prio > p && e.CanStart(gamedata))
			{
				p = e.prio;
				_return = e;
			}
		}
		if (p != EventPriority::None)
		{
			return _return;
		}

		throw out_of_range("EventManager Throw: ������ �̺�Ʈ�� �����ϴ�");
	}

	bool RandomAverageTurn(const string name, const int delay)
	{
		if (gamedata.delay.find(name) == gamedata.delay.end())
		{
			gamedata.delay[name] = 5 * delay;
			return false;
		}
		else
		{
			gamedata.delay[name] -= RandomInt(1, 9);
			if (gamedata.delay[name] <= 0)
			{
				gamedata.delay.erase(name);
				return  true;
			}
			else return false;
		}
	}
	

	void DefaultRun()
	{
		try
		{
			bool Loop = true;
			while (Loop)
			{
				system("cls");
				auto& e = GetNewEvent();
				cout << "\n=== " << e.name << " ===" << endl << e.content << endl << endl;

				while (true)
				{
					cout << "[" << gamedata.dict["�÷��̾�"] << "]";
					ShowResource(gamedata.player.res);
					size_t i = 1;
					for (const auto& s : e.item)
					{
						if (s.CanVisible(gamedata))
						{
							cout << i << ". " << s.name;
							cout << endl;
						}
						++i;
					}

					if (i == 1)
					{
						cin.ignore();
					}
					else
					{
						cout << endl << "���ڸ� ���� �������ּ��� : ";
						cin >> i;

						auto& sec = e.item.at(i - 1);

						cout << endl << sec.content << endl;

						//if (sec.CanRun(gamedata))
						{
							cout << "�̰����� �����ϰڽ��ϱ�? (y/n) : ";
							char c;
							while (true)
							{
								cin >> c;
								if (c == 'y' || c == 'n') break;
							}
							if (c == 'y')
							{
								sec.Effect(gamedata);
								if (gamedata.player.res.diplo < 0)
								{
									if (-gamedata.player.res.diplo <= gamedata.player.res.faith)
									{
										gamedata.player.res.faith += gamedata.player.res.diplo;
										gamedata.player.res.diplo = 0;
									}
									else
									{
										cout << "����� ������ ����߽��ϴ�.\n�� ������ ����� ��ħ�� ������ ���� �ʽ��ϴ�. �ܱ����� ����� �������� ���� ����Դϴ�...";
										Loop = false;
										break;
									}
								}
								if (gamedata.player.res.milli < 0)
								{
									if (-gamedata.player.res.milli <= gamedata.player.res.faith)
									{
										gamedata.player.res.faith += gamedata.player.res.milli;
										gamedata.player.res.milli = 0;
									}
									else
									{
										cout << "����� ������ ����߽��ϴ�.\n����� ����� �ο�� ���� �ʰ� ���� ���� �ŵ��� ���� ����� �ü��� �����߽��ϴ�.\n������ ����� �������� ���� ����Դϴ�...";
										Loop = false;
										break;
									}
								}
								if (gamedata.player.res.food < 0)
								{
									if (-gamedata.player.res.food <= gamedata.player.res.faith)
									{
										gamedata.player.res.faith += gamedata.player.res.food;
										gamedata.player.res.food = 0;
									}
									else
									{
										cout << "����� ������ ����߽��ϴ�.\n����� �ķ�â���� �� �� ���� �ҵ� ���� �ʾ����� �ü��� �������� ���� ���� �ƽ��ϴ�.\n�ķ��� ���̴� � ������ ������ �� �����ϴ�.";
										Loop = false;
										break;
									}
								}
								if (gamedata.player.res.human < 0)
								{
									if (-gamedata.player.res.human <= gamedata.player.res.faith)
									{
										gamedata.player.res.faith += gamedata.player.res.human;
										gamedata.player.res.human = 0;
									}
									else
									{
										cout << "����� ������ ����߽��ϴ�.\n�ƹ��� ���� ���� ���� �ʽ��ϴ�. �� �̻� �����̶�� �β����� �����Դϴ�. \n ����� �־�� ������ �ִ¹��Դϴ�.";
										Loop = false;
										break;
									}
								}
								if (gamedata.player.res.money < 0)
								{
									if (-gamedata.player.res.money <= gamedata.player.res.faith)
									{
										gamedata.player.res.faith += gamedata.player.res.money;
										gamedata.player.res.money = 0;
									}
									else
							                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            		{
										cout << "����� ������ ����߽��ϴ�.\n�� �̻� �������� �������� ���� ���� ������ �̿� ���� ��� �ü��� �������ϴ�.\n���� ���ٸ� �ƹ��͵� �� �� �����ϴ�.";
										Loop = false;
										break;
									}
								}
								if (gamedata.player.res.faith < 0)
								{
									cout << "����� ������ ����߽��ϴ�.\n����� ������ ��ġ�������� �� ������ ����� ������ �ŷ������� �ʰ� ������ �ʽ��ϴ�.\n�ž��� ���ٸ� �츮�� ��ġ�� ��а� �ٸ� �����ϴ�.";
									Loop = false;
									break;
								}
								break;
							}
						}
						cout << endl;

						cin.ignore();
					}
				}
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}
	}
};




class EventMaker {
	Event e;
public:

	EventMaker(string first, EventPriority second) : e(first, second)  {
		
	}

	[[nodiscard]] Event* operator-> () {
		return &e;
	}

	Event* _Ptr() {
		return &e;
	}
	
	~EventMaker()
	{
		mainEventmgr->AddEvent(e);
	}
};

class EventSelectItemMaker {
	EventSelectItem s;
	Event* e;
public:

	EventSelectItemMaker(EventMaker& first, string second) : s(second) {
		e = first._Ptr();
	}

	[[nodiscard]] EventSelectItem* operator-> () {
		return &s;
	}

	~EventSelectItemMaker()
	{
		e->item.push_back(s);
	}
};

void PlayerGive(int food, int human, int money, int diplo, int milli, int faith)
{
	mainEventmgr->gamedata.player.res.food += food;
	mainEventmgr->gamedata.player.res.human += human;
	mainEventmgr->gamedata.player.res.money += money;
	mainEventmgr->gamedata.player.res.diplo += diplo;
	mainEventmgr->gamedata.player.res.milli += milli;
	mainEventmgr->gamedata.player.res.faith += faith;
}

void PlayerUse(int food, int human, int money, int diplo, int milli, int faith)
{
	mainEventmgr->gamedata.player.res.food -= food;
	mainEventmgr->gamedata.player.res.human -= human;
	mainEventmgr->gamedata.player.res.money -= money;
	mainEventmgr->gamedata.player.res.diplo -= diplo;
	mainEventmgr->gamedata.player.res.milli -= milli;
	mainEventmgr->gamedata.player.res.faith -= faith;
}
