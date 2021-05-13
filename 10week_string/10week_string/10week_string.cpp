#include <iostream>
using namespace std;

int fruit_num;

int x_price;
int y_num;
int z_money;

int custom_money;
int buy_money;

int Fruit_sellect() {

	cout << " [ 과일 판매 시스템 ]" << endl;
	cout << " 구매할 과일을 선택 하시오 !" << endl;
	cout << " 1)사과   2)희귀사과   3)바나나" << endl;
	cin >> fruit_num;

	return fruit_num;
}

void Seller_program()
{
	switch (fruit_num)
	{
	case 1:
		cout << " 1. [사과장수 프로그램]" << endl;
		break;
	case 2:
		cout << " 2. [희귀장수 프로그램]" << endl;
		break;
	case 3:
		cout << " 3. [바나나장수 프로그램]" << endl;
		break;
	default:
		cout << "숫자를 잘못입력하였습니다. 프로그램 종료" << endl;
		exit(0);
		break;
	}

	cout << "과일 가격을 정하시오" << endl;
	cin >> x_price;

	cout << "과일 개수를 정하시오" << endl;
	cin >> y_num;
	if (y_num < 0) { //과제 0번, 음수 입력시 프로그램 종료
		cout << "잘못된 값을 입력하셨습니다." << endl;
		exit(0);
	}
	cout << "현재 자금을 정하시오" << endl;
	cin >> z_money;
}

void Buyer_program() //과제 2번, 사과 구매자 정보 입력하는 함수
{
	cout << " [과일 구매자 프로그램] " << endl;
	cout << "현재 잔고와 구매할 금액을 정하시오" << endl;
	cin >> custom_money;
	cin >> buy_money;
}

class Person { //사람 추상클래스
private:
	string name;  //string 타입으로 선언

public:
	Person(string p_name) { 
		this->name = p_name;
	}

	virtual void Showinfro() = 0;	//가상함수

	string GetName() const {
		return name;
	}
};

class AppleSeller : public Person
{
protected:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	string myName;

public:
	AppleSeller(string name, int price, int num, int money)		//string 타입으로 선언
		:myName(name), APPLE_PRICE(price), numOfApples(num), myMoney(money), Person(name) {}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;

		if (numOfApples < 0) cout << "전체 사과 값보다 가격이 높음" << endl;
		else return num;
	}
	void Showinfro() {
		cout << " ===판매상인====" << endl << GetName() << endl;
		cout << " 남은 사과 : " << numOfApples << endl;
		cout << " 사과장수 지갑 : " << myMoney << endl;
	}
	~AppleSeller() //과제 5번, 상태 출력하는 문 소멸자에 추가
	{
		cout << endl;
	}
};

class _AppleSeller : public AppleSeller
{
private:

public:
	_AppleSeller(string name, int price, int num, int money)     //string 타입으로 선언
		: AppleSeller(name, price, num, money) {}

	void Showinfro() {
		cout << " ===판매상인====" << endl << GetName() << endl;
		cout << " 남은 희귀사과 : " << numOfApples << endl;
		cout << " 희귀장수 지갑 : " << myMoney << endl;
	}

};

class BananaSeller : public Person
{
private:
	int Banana_PRICE;
	int numOfApples;
	int myMoney;
	string myName;

public:
	BananaSeller(string name, int price, int num, int money)	//string 타입으로 선언
		:myName(name), Banana_PRICE(price), numOfApples(num), myMoney(money), Person(name) {}

	int SaleApples(int money)
	{
		int num = money / Banana_PRICE;
		numOfApples -= num;
		myMoney += money;

		if (numOfApples < 0) cout << "전체 바나나 값보다 가격이 높음" << endl;
		else return num;
	}
	void Showinfro() {
		cout << " ===판매상인====" << endl << GetName() << endl;
		cout << " 남은 바나나 : " << numOfApples << endl;
		cout << " 바나나장수 지갑 : " << myMoney << endl;
	}
	~BananaSeller() 
	{
		cout << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:

	FruitBuyer(int money) 
		:myMoney(money), numOfApples(0) {}

	void BuyApples(AppleSeller& apple_seller, int money)
	{
		numOfApples += apple_seller.SaleApples(money);
		myMoney -= money;
	}

	void _BuyApples(_AppleSeller& _apple_seller, int money)
	{
		numOfApples += _apple_seller.SaleApples(money);
		myMoney -= money;
	}

	void BuyBanana(BananaSeller& banana_seller, int money)
	{
		numOfApples += banana_seller.SaleApples(money);
		myMoney -= money;
	}

	~FruitBuyer() 
	{
		cout << " [판매자 구매후 잔고 및 사과 개수]" << endl;
		cout << " 현재 잔액: " << myMoney << endl;
		cout << " 과일 개수: " << numOfApples << endl << endl;
	}

};

int main()
{
	Fruit_sellect();	//과일선택함수
	Seller_program();   //과일장수 세팅용 함수
	Buyer_program();    //구매자 세팅용 함수

	FruitBuyer buyer(custom_money);
	AppleSeller apple("*사과장수 A씨", x_price, y_num, z_money);
	_AppleSeller _apple("*희귀사과장수 B씨", x_price, y_num, z_money);
	BananaSeller banana("*바나나장수 C씨", x_price, y_num, z_money);

	switch (fruit_num)
	{
	case 1:
		buyer.BuyApples(apple, buy_money);
		apple.Showinfro();
		break;
	case 2:
		buyer._BuyApples(_apple, buy_money);
		_apple.SaleApples(z_money);
		_apple.Showinfro();
		break;
	case 3:
		buyer.BuyBanana(banana, buy_money);
		banana.Showinfro();
		break;
	default:
		break;
	}

	return 0;
}