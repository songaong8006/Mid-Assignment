#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
using namespace bangtal;


void init_game()
{
	auto open = false, locked = true;
	auto open1 = false, locked1 = true;
	auto open2 = false, locked2 = true;

	// ����
	auto start1 = Scene::create(" ", "Images/���1.png");
	auto scene1 = Scene::create(" ", "Images/��1.png");

	auto happen1 = Object::create("Images/��1.png", scene1);
	auto phone1 = Object::create("Images/�ڵ���1.png", scene1, 870, 200);
	auto arrowphone = Object::create("Images/ȭ��ǥ3.png", scene1, 1000, 760);
	auto arrow1 = Object::create("Images/ȭ��ǥ4.png", scene1, 1500, 500, false);
	auto time1 = Object::create("Images/time1.png", scene1, 700, 560, false);
	showMessage("��~ �����! ���� �ڷγ��� ������ ó������ �б����� ���̶� �����㿡 ���ȴµ�... �ٵ� �� �̷��� ���� ����? ������ �����?");

	phone1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		time1->show();
		arrowphone->hide();
		arrow1->show();
		showMessage("�ν� ĥ��? ��! �����̴�!!! 10�оȿ� �������� ���ðھ�! ���� ������!!");
		return true;
		});
	arrow1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		start1->enter();
		return true;
		});

	// ���� ���� ������
	auto scene2 = Scene::create(" ", "Images/������.png");
	auto name1 = Object::create("Images/����1.png", start1, 350, 200);
	name1->setScale(0.6f);
	auto button1 = Object::create("Images/start.png", start1, 850, 235);
	button1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene2->enter();
		return true;
		});

	// ������
	auto scene3 = Scene::create(" ", "Images/�б���.png");
	auto bus = Object::create("Images/������.png", scene2);
	auto phone2 = Object::create("Images/�ڵ���2.png", scene2, 870, 200, false);
	auto timetime = Object::create("Images/�ð�ǥ1.png", scene2, 870, 200, false);
	auto arrow2 = Object::create("Images/ȭ��ǥ4.png", scene2, 1500, 500, false);
	bus->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�� �׷��� ������ �ٷοͼ� �����̾�. ���� �ð�ǥ�� ���?");
		phone2->show();
		return true;
		});
	phone2->setOnKeypadCallback([&](ObjectPtr object)-> bool {
		locked = false;
		showMessage("Ǯ�ȴ�!");
		phone2->hide();
		timetime->show();
		return true;
		});
	phone2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("���긮Ÿ�ӿ� ���� ���� �޴����� �״�. ��й�ȣ�� ������? HINT : �� ������ 97�� 5�� 5���̴�.");
		showKeypad("970505", phone2);
		return true;
		});
	timetime->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("���� ���ÿ� �������� �ְ�.... 310�� 502ȣ.. �� ������ �����߳�����. ������!");
		arrow2->show();
		return true;
		});
	arrow2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene3->enter();
		showMessage("�̰��� ������ �����ϸ� �ٷ� �� �� �ִ°�. 101�� ���Ű�. �� �´� �ӿ��� �ڻ��� �̸��� ���� ������ ������ �����ǹ��̴�.");
		return true;
		});

	//���Ű� ��
	auto scene4 = Scene::create(" ", "Images/������1.png");
	auto school1 = Object::create("Images/�б���.png", scene3);
	auto arrow3 = Object::create("Images/ȭ��ǥ4.png", scene3, 1550, 500, false);
	auto arrow4 = Object::create("Images/ȭ��ǥ2.png", scene3, 400, 500, false);
	school1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�츮�� ���Ű����� ����ó ���� ���� �ذ��� �� �־�! �׷� ���� ���ǽǷ� ����!");
		arrow3->show();
		arrow4->show();
		return true;
		});
	arrow3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�� �ٽ� ���ư����°ž�? ���� ���ǽǷ� ������! ��������!");
		return true;
		});
	arrow4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene4->enter();
		showMessage("�������� ��Ÿ����! ���� ���� �� ������ ������ �� ������?");
		return true;
		});

	// ������1
	auto scene5 = Scene::create(" ", "Images/310��.png");
	auto school2 = Object::create("Images/������1.png", scene4);
	auto puang = Object::create("Images/Ǫ����.png", scene4, 1000, 300, false);
	auto button12 = Object::create("Images/1��.png", scene4, 500, 400, false);
	auto button34 = Object::create("Images/�ٸ���ȣ.png", scene4, 680, 400, false);
	auto arrow5 = Object::create("Images/ȭ��ǥ2.png", scene4, 400, 500, false);
	school2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�ȳ� ���� �߾Ӵ��� ������Ʈ OO�̾�! �� �̸��� ���߸� ���� �������� �˷��ٰ�><");
		puang->show();
		button12->show();
		button34->show();
		return true;
		});
	button12->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		button12->hide();
		button34->hide();
		showMessage("�¾Ҿ�! �׷� �������� �˷��ٰ�! �߰�~~~");
		arrow5->show();
		return true;
		});
	button34->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�ƴϾ�! �ٽ� �����~");
		return true;
		});
	arrow5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene5->enter();
		showMessage("���� 310���� ���̱� �����Ѵ�! ���� �ʾҾ�!");
		return true;
		});

	// 310�� ��
	auto scene6 = Scene::create(" ", "Images/����.png");
	auto school3 = Object::create("Images/310��.png", scene5);
	auto puang1 = Object::create("Images/Ǫ����.png", scene5, 1000, 200, false);
	auto button56 = Object::create("Images/����2.png", scene5, 500, 300, false);
	auto button78 = Object::create("Images/����2��.png", scene5, 870, 300, false);
	auto arrow6 = Object::create("Images/ȭ��ǥ1.png", scene5, 900, 700, false);
	school3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("310���� �߾Ӵ��� 100�ֳ��� ����� ������� ���̾�. �׷��� 100�ֳ� ���� �Ǵ� �������� �Ҹ��⵵��. �츮���� ���� ���ϰǹ� �� ���� ũ�ٰ� �ϴ� �ſ� �ڶ�������!");
		puang1->show();
		return true;
		});
	puang1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("¥��! ���� �� �Ծ�! �� ������ ���߸� 310���� �� �� �ְ� ���ٰ�!");
		button56->show();
		button78->show();
		return true;
		});
	button78->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		button12->hide();
		button34->hide();
		showMessage("�¾Ҿ�! �׷� �����ٰ�! �߰�~~~");
		arrow6->show();
		return true;
		});
	button56->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�ƴϾ�! �ٽ� �����~");
		return true;
		});
	arrow6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene6->enter();
		showMessage("�¾�! ������ �б��� ������ �л��� ī�尡 �ʿ���. ���� �װ� ���ٰ� �״���?");
		return true;
		});

	// ����
	auto scene7 = Scene::create(" ", "Images/�κ�.png");
	auto school4 = Object::create("Images/����.png", scene6);
	auto bag1 = Object::create("Images/����.png", scene6, 200, -100, false);
	auto key = Object::create("Images/�л���.png", scene6, 600, 300, false);
	key->setScale(0.4f);
	auto case1 = Object::create("Images/���̽�.png", scene6, 500, 200, false);
	auto arrow7 = Object::create("Images/ȭ��ǥ1.png", scene6, 700, 650);

	arrow7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		if (open1 == true) {
			scene7->enter();
			showMessage("�̰��� 310���� �κ�� ������ ������? �� �� �Ծ�. ���� ���ǽǷ� ����!");
		}
		else if (key->isHanded()) {
			open1 = true;
			showMessage("���� ���ȴ�! ����.");
		}
		else
		{
			showMessage("�л����� �ʿ���!!");
		}
		return true;
		});
	school4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�¾�! ���濡 �׾��� ������ ������߰ڴ�");
		bag1->show();
		key->show();
		case1->show();
		return true;
		});
	key->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		key->pick();
		bag1->hide();
		case1->hide();
		return true;
		});

	case1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT)
		{
			case1->locate(scene6, 300, 200);
		}
		if (action == MouseAction::MOUSE_DRAG_RIGHT)
		{
			case1->locate(scene6, 700, 200);
		}
		return true;
		});


	// ���������� ����(������!)
	auto scene8 = Scene::create(" ", "Images/���ǽ�.png");
	auto school5 = Object::create("Images/�κ�.png", scene7);
	auto puang2 = Object::create("Images/Ǫ����.png", scene7, 1700, 500, false);
	auto arrow8 = Object::create("Images/ȭ��ǥ2.png", scene7, 850, 800, false);
	school5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�ȳ�! ������� �Ա���. ���� ���� �� �ȳ��Ҿ�. �׷� ������ ������ ����. �� ������ ���߸� ���������͸� �̿��ؼ� �� ������ �� �� �־�.");
		puang2->show();
		return true;
		});
	arrow8->setOnKeypadCallback([&](ObjectPtr object)-> bool {
		locked = false;
		showMessage("��� ������ �� ���豸��! � �߾Ӵ��б��� ���� ������ �˰ԵȰŰ���? �׷� ���� �ߵ��! �� ����");
		arrow8->show();
		return true;
		});
	puang2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�߾Ӵ��б��� ����Ǳ� �� ����������� �����ϱ�?");
		showKeypad("1111", arrow8);
		return true;
		});
	arrow8->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene8->enter();
		showMessage("��! �����ߴ�! �������� �������� ���ñ����̾�.");
		return true;
		});

	// ������ ����.
	auto school6 = Object::create("Images/���ǽ�.png", scene8);
	auto end = Object::create("Images/end.png", scene8, 450, 400, false);
	school6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("�б��� ó���ͼ� ������ ������ ���Ҵ�! �б��� ���� ģ������ �������� ������ �� ���� ��ȸ�� �ְ���.");
		end->show();
		return true;
		});
	end->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		endGame();
		return true;
		});

	startGame(scene1);
}

int main()
{
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto timer = Timer::create(600.f);
	showTimer(timer);
	timer->start();
	init_game();
	return 0;
}