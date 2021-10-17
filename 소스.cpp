#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
using namespace bangtal;


void init_game()
{
	auto open = false, locked = true;
	auto open1 = false, locked1 = true;
	auto open2 = false, locked2 = true;

	// 내방
	auto start1 = Scene::create(" ", "Images/배경1.png");
	auto scene1 = Scene::create(" ", "Images/방1.png");

	auto happen1 = Object::create("Images/방1.png", scene1);
	auto phone1 = Object::create("Images/핸드폰1.png", scene1, 870, 200);
	auto arrowphone = Object::create("Images/화살표3.png", scene1, 1000, 760);
	auto arrow1 = Object::create("Images/화살표4.png", scene1, 1500, 500, false);
	auto time1 = Object::create("Images/time1.png", scene1, 700, 560, false);
	showMessage("아~ 잘잤다! 오늘 코로나가 끝나고 처음으로 학교가는 날이라 어젯밤에 떨렸는데... 근데 왜 이렇게 밖이 밝지? 지금이 몇시지?");

	phone1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		time1->show();
		arrowphone->hide();
		arrow1->show();
		showMessage("두시 칠분? 악! 지각이다!!! 10분안에 교수님이 오시겠어! 당장 가야해!!");
		return true;
		});
	arrow1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		start1->enter();
		return true;
		});

	// 게임 시작 페이지
	auto scene2 = Scene::create(" ", "Images/버스안.png");
	auto name1 = Object::create("Images/제목1.png", start1, 350, 200);
	name1->setScale(0.6f);
	auto button1 = Object::create("Images/start.png", start1, 850, 235);
	button1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene2->enter();
		return true;
		});

	// 버스안
	auto scene3 = Scene::create(" ", "Images/학교앞.png");
	auto bus = Object::create("Images/버스안.png", scene2);
	auto phone2 = Object::create("Images/핸드폰2.png", scene2, 870, 200, false);
	auto timetime = Object::create("Images/시간표1.png", scene2, 870, 200, false);
	auto arrow2 = Object::create("Images/화살표4.png", scene2, 1500, 500, false);
	bus->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("휴 그래도 버스가 바로와서 다행이야. 오늘 시간표가 어떻지?");
		phone2->show();
		return true;
		});
	phone2->setOnKeypadCallback([&](ObjectPtr object)-> bool {
		locked = false;
		showMessage("풀렸다!");
		phone2->hide();
		timetime->show();
		return true;
		});
	phone2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("에브리타임에 들어가기 위해 휴대폰을 켰다. 비밀번호가 뭐였지? HINT : 내 생일은 97년 5월 5일이다.");
		showKeypad("970505", phone2);
		return true;
		});
	timetime->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("오늘 세시에 객지프가 있고.... 310관 502호.. 아 버스가 도착했나보다. 내리자!");
		arrow2->show();
		return true;
		});
	arrow2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene3->enter();
		showMessage("이곳은 정문에 도착하면 바로 볼 수 있는곳. 101관 영신관. 고 승당 임영신 박사의 이름을 따서 세워진 최초의 석조건물이다.");
		return true;
		});

	//영신관 앞
	auto scene4 = Scene::create(" ", "Images/갈림길1.png");
	auto school1 = Object::create("Images/학교앞.png", scene3);
	auto arrow3 = Object::create("Images/화살표4.png", scene3, 1550, 500, false);
	auto arrow4 = Object::create("Images/화살표2.png", scene3, 400, 500, false);
	school1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("우리는 영신관에서 입학처 관련 일을 해결할 수 있어! 그럼 빨리 강의실로 가자!");
		arrow3->show();
		arrow4->show();
		return true;
		});
	arrow3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("왜 다시 돌아가려는거야? 빨리 강의실로 가야해! 정신차려!");
		return true;
		});
	arrow4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene4->enter();
		showMessage("갈림길이 나타났다! 어디로 가야 더 빠르게 도착할 수 있을까?");
		return true;
		});

	// 갈림길1
	auto scene5 = Scene::create(" ", "Images/310관.png");
	auto school2 = Object::create("Images/갈림길1.png", scene4);
	auto puang = Object::create("Images/푸앙이.png", scene4, 1000, 300, false);
	auto button12 = Object::create("Images/1번.png", scene4, 500, 400, false);
	auto button34 = Object::create("Images/다른번호.png", scene4, 680, 400, false);
	auto arrow5 = Object::create("Images/화살표2.png", scene4, 400, 500, false);
	school2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("안녕 나는 중앙대의 마스코트 OO이야! 내 이름을 맞추면 내가 지름길을 알려줄게><");
		puang->show();
		button12->show();
		button34->show();
		return true;
		});
	button12->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		button12->hide();
		button34->hide();
		showMessage("맞았어! 그럼 지름길을 알려줄게! 잘가~~~");
		arrow5->show();
		return true;
		});
	button34->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("아니야! 다시 맞춰봐~");
		return true;
		});
	arrow5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene5->enter();
		showMessage("드디어 310관이 보이기 시작한다! 멀지 않았어!");
		return true;
		});

	// 310관 앞
	auto scene6 = Scene::create(" ", "Images/문앞.png");
	auto school3 = Object::create("Images/310관.png", scene5);
	auto puang1 = Object::create("Images/푸앙이.png", scene5, 1000, 200, false);
	auto button56 = Object::create("Images/문제2.png", scene5, 500, 300, false);
	auto button78 = Object::create("Images/문제2답.png", scene5, 870, 300, false);
	auto arrow6 = Object::create("Images/화살표1.png", scene5, 900, 700, false);
	school3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("310관은 중앙대의 100주년을 기념해 만들어진 곳이야. 그래서 100주년 기념관 또는 경경관으로 불리기도해. 우리나라 대학 단일건물 중 가장 크다고 하니 매우 자랑스러워!");
		puang1->show();
		return true;
		});
	puang1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("짜잔! 내가 또 왔어! 이 문제를 맞추면 310관에 들어갈 수 있게 해줄게!");
		button56->show();
		button78->show();
		return true;
		});
	button78->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		button12->hide();
		button34->hide();
		showMessage("맞았어! 그럼 비켜줄게! 잘가~~~");
		arrow6->show();
		return true;
		});
	button56->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("아니야! 다시 맞춰봐~");
		return true;
		});
	arrow6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene6->enter();
		showMessage("맞아! 이제는 학교에 들어가려면 학생증 카드가 필요해. 내가 그걸 어디다가 뒀더라?");
		return true;
		});

	// 문앞
	auto scene7 = Scene::create(" ", "Images/로비.png");
	auto school4 = Object::create("Images/문앞.png", scene6);
	auto bag1 = Object::create("Images/가방.png", scene6, 200, -100, false);
	auto key = Object::create("Images/학생증.png", scene6, 600, 300, false);
	key->setScale(0.4f);
	auto case1 = Object::create("Images/케이스.png", scene6, 500, 200, false);
	auto arrow7 = Object::create("Images/화살표1.png", scene6, 700, 650);

	arrow7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		if (open1 == true) {
			scene7->enter();
			showMessage("이곳은 310관의 로비야 굉장히 멋지지? 자 다 왔어. 빨리 강의실로 가자!");
		}
		else if (key->isHanded()) {
			open1 = true;
			showMessage("문이 열렸다! 들어가자.");
		}
		else
		{
			showMessage("학생증이 필요해!!");
		}
		return true;
		});
	school4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("맞아! 가방에 뒀었지 가방을 열어봐야겠다");
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


	// 엘리베이터 문제(마지막!)
	auto scene8 = Scene::create(" ", "Images/강의실.png");
	auto school5 = Object::create("Images/로비.png", scene7);
	auto puang2 = Object::create("Images/푸앙이.png", scene7, 1700, 500, false);
	auto arrow8 = Object::create("Images/화살표2.png", scene7, 850, 800, false);
	school5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("안녕! 여기까지 왔구나. 이제 정말 얼마 안남았어. 그럼 마지막 문제를 낼게. 이 문제를 맞추면 엘리베이터를 이용해서 더 빠르게 갈 수 있어.");
		puang2->show();
		return true;
		});
	arrow8->setOnKeypadCallback([&](ObjectPtr object)-> bool {
		locked = false;
		showMessage("모든 문제를 다 맞췄구나! 어때 중앙대학교에 대해 조금은 알게된거같니? 그럼 수업 잘들어! 난 갈게");
		arrow8->show();
		return true;
		});
	puang2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("중앙대학교의 변경되기 전 개교기념일은 언제일까?");
		showKeypad("1111", arrow8);
		return true;
		});
	arrow8->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		scene8->enter();
		showMessage("휴! 도착했다! 다행히도 교수님이 오시기전이야.");
		return true;
		});

	// 수업을 듣자.
	auto school6 = Object::create("Images/강의실.png", scene8);
	auto end = Object::create("Images/end.png", scene8, 450, 400, false);
	school6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		showMessage("학교에 처음와서 수업을 들으니 좋았다! 학교와 아직 친해지지 못했지만 앞으로 더 많은 기회가 있겠지.");
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