#include <iostream>
using namespace std;

unsigned int fruit_num;

unsigned int x_price;
unsigned int y_num;
unsigned int z_money;

unsigned custom_money;
unsigned int buy_money;

int Fruit_sellect() {

	cout << " ========[ 과일 판매 시스템 ]=========" << endl;
	cout << " <구매할 과일을 선택 하시오 !>" << endl;
	cout << " 1)사과  2)희귀사과  3)바나나" << endl;
	cin >> fruit_num;

	return fruit_num;
}

void Seller_program()
{
	switch (fruit_num)
	{
	case 1:
		cout << "*** 1. [사과장수 프로그램] ***" << endl;
		break;
	case 2:
		cout << "*** 2. [희귀장수 프로그램] ***" << endl;
		break;
	case 3:
		cout << "*** 3. [바나나장수 프로그램] ***" << endl;
		break;
	default:
		cout << "숫자를 잘못입력하였습니다. 프로그램 종료" << endl;
		exit(0);
		break;
	}

	cout << "과일 가격을 정하시오 [ *최소 10원 이상* ]" << endl;
	cin >> x_price;
	if (x_price < 10) { 
		cout << "10원 이상의 가격을 입력해야합니다" << endl;
		exit(0);
	}

	cout << "과일 개수를 정하시오" << endl;
	cin >> y_num;
	if (y_num < 1) {
		cout << "잘못된 값을 입력하셨습니다." << endl;
		exit(0);
	}
	cout << "현재 자금을 정하시오" << endl;
	cin >> z_money;
}

void Buyer_program() 
{
	cout << " ====== [과일 구매자 프로그램] ====== " << endl;
	cout << " *** 현재 잔고와 구매할 금액을 정하시오" << endl;
	cin >> custom_money;
	cin >> buy_money;
	if (buy_money < x_price)
	{
		cout << " <Error> 과일을 살수 없는 가격입니다. 과일가격을 확인해주세요! " << endl;
		exit(0);
	}
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
	unsigned int APPLE_PRICE;
	unsigned int numOfApples;
	unsigned int myMoney;
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
		cout << " ========== 사과 판매상인 ==========" << endl << GetName() << endl;
		cout << " 남은 사과 : " << numOfApples << endl;
		cout << " 사과장수 지갑 : " << myMoney << endl;
	}
	~AppleSeller() 
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
		cout << " ========== 희귀사과 판매상인 ==========" << endl << GetName() << endl;
		cout << " 남은 희귀사과 : " << numOfApples << endl;
		cout << " 희귀장수 지갑 : " << myMoney << endl;
	}

};

class BananaSeller : public Person
{
private:
	unsigned int Banana_PRICE;
	unsigned int numOfApples;
	unsigned int myMoney;
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
		cout << " ========== 바나나 판매상인 ==========" << endl << GetName() << endl;
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
	unsigned int myMoney;
	unsigned int numOfFruit = 0;


public:

	FruitBuyer(unsigned int money)
		:myMoney(money), numOfFruit(0) {}  

	//11주차 과제, Template 사용한 함수 선언
	template <class  T>	void BuyFruit(T& seller, unsigned int money)
	{
		numOfFruit += seller.SaleApples(money);
		myMoney -= money;
	}

	/*void BuyApples(AppleSeller& apple_seller, int money)
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
	}*/

	~FruitBuyer()
	{
		cout << " [판매자 구매후 잔고 및 과일 개수]" << endl;
		cout << " 현재 잔액: " << myMoney << endl;
		cout << " 과일 개수: " << numOfFruit << endl;
		cout << " ~~~~~~~~~~프로그램이 종료 되었습니다~~~~~~~~~~~ " << endl << endl;
	}

};

int main()
{
	while(true)
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
			buyer.BuyFruit(apple, buy_money);
			apple.Showinfro();
			break;
		case 2:
			buyer.BuyFruit(_apple, buy_money);
			_apple.SaleApples(z_money);
			_apple.Showinfro();
			break;
		case 3:
			buyer.BuyFruit(banana, buy_money);
			banana.Showinfro();
			break;
		default:
			break;
		}
	}
	return 0;
}