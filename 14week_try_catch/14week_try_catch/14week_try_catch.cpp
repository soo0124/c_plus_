#include <iostream>
using namespace std;

unsigned int fruit_num;
unsigned int x_price;
unsigned int y_num;
unsigned int z_money;
unsigned int custom_money;
unsigned int buy_money;

int Fruit_sellect() {

	cout << " ==================[ 과일 판매 시스템 ]===================" << endl;
	cout << " <구매할 과일을 선택 하시오 !>" << endl;
	cout << " 1)사과  2)희귀사과  3)바나나" << endl;
	cin >> fruit_num;
	try
	{
		if (cin.fail()) throw 'e';
		if (fruit_num > 3 || fruit_num == 0) throw fruit_num;

		cout << "---log1) 과일 선택이 정상적으로 입력되었습니다.---\n" << endl;
		return fruit_num;
	}
	catch (char error)					//문자를 입력할 때 예외 처리
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "  <-- 문자를 입력하셨습니다. 다시 입력하세요" << endl;
		return Fruit_sellect();
	}
	catch (unsigned int exception)		//1~3 이외의 숫자를 입력했을때 예외처리
	{
		cout << exception << " <-- 입력한 숫자는 예외 대상입니다!\n" << endl;
		return Fruit_sellect();
	}
}

int Seller_program()
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
	}

	cout << "(1)..과일 가격을 정하시오 [ *최소 500원 이상* ]" << endl;
	cin >> x_price;

	try
	{
		if (cin.fail()) throw 'e';
		if (x_price < 500) throw x_price;
		cout << "---log2) 과일 가격이 정상적으로 입력되었습니다.---\n" << endl;
	}
	catch (char error)				//문자를 입력할 때 예외 처리
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "  <-- 문자를 입력하셨습니다. 다시 입력하세요" << endl;
		return Seller_program();
	}
	catch (unsigned int exception)	//500원 이하의 숫자를 입력했을때 예외처리
	{
		cout << exception << " <-- 500원 이상의 가격을 입력해야합니다.\n" << endl;
		return Seller_program();
	}

	tryagain_1:	//goto 라벨 설정

	cout << "(2)..과일 개수를 정하시오 [*최소 1개 이상*]" << endl;
	cin >> y_num;

	try
	{
		if (cin.fail()) throw 'e';
		if (y_num < 1) throw y_num;
		cout << "---log3) 과일 개수가 정상적으로 입력되었습니다.---\n" << endl;
	}
	catch (char error)				//문자를 입력할 때 예외 처리
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "  <-- 문자를 입력하셨습니다. 다시 입력하세요" << endl;
		goto tryagain_1;
	}
	catch (unsigned int exception)	//1보다 낮은 숫자를 입력했을때 예외처리
	{
		cout << exception << " <-- 1개 이상의 개수를 입력해야합니다.\n" << endl;
		goto tryagain_1;
	}

	tryagain_2:

	cout << "(3)..과일장수의 자금을 입력하시오" << endl;
	cin >> z_money;
	try
	{
		if (cin.fail()) throw 'e';
		if (z_money < 0) throw z_money;
		cout << "---log4) 과일 장수 자금이 정상적으로 입력되었습니다.---\n" << endl;
	}
	catch (char error)				//문자를 입력할 때 예외처리
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "  <-- 문자를 입력하셨습니다. 다시 입력하세요" << endl;
		goto tryagain_2;
	}
	catch (unsigned int exception)	//갖고있는 자금이 0보다 낮을때 예외처리
	{
		cout << exception << " <-- 가지고 있는 자금이 0보다 커야합니다.\n" << endl;
		goto tryagain_2;
	}
}

int Buyer_program()
{
	tryagain_3:

	cout << " ================ [과일 구매자 프로그램] ================ " << endl;
	cout << " ***** 자신의 자금과 구매할 금액을 정하시오 *****" << endl;
	cin >> custom_money;
	cin >> buy_money;

	try
	{
		if (cin.fail()) throw 'e';
		if (custom_money < x_price || buy_money < x_price) throw buy_money;
		cout << "---log5) 구매자 자금이 정상적으로 입력되었습니다.---\n" << endl;
	}
	catch (char error)				//문자를 입력했을때 예외처리
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << " <-- 문자를 입력하셨습니다. 다시 입력하세요" << endl;
		goto tryagain_3;
	}
	catch (unsigned int exception)	//과일 값보다 금액이 낮을때 예외처리
	{
		cout << exception << "과일을 살수 없는 금액입니다. 과일가격을 확인해주세요!\n" << endl;
		goto tryagain_3;
	}
}

class Person { 
private:
	string name;  

public:
	Person(string p_name) {
		this->name = p_name;
	}

	virtual void Showinfro() = 0;	

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
	AppleSeller(string name, int price, int num, int money)		
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
		cout << " ==================== 사과 판매상인 ====================" << endl << GetName() << endl;
		cout << " 남은 사과 : " << numOfApples << endl;
		cout << " 사과장수 지갑 : " << myMoney << endl;
	}
	~AppleSeller()
	{
	}
};

class _AppleSeller : public AppleSeller
{
private:

public:
	_AppleSeller(string name, int price, int num, int money)    
		: AppleSeller(name, price, num, money) {}

	void Showinfro() {
		cout << " ==================== 희귀사과 판매상인 ====================" << endl << GetName() << endl;
		cout << " 남은 희귀사과 : " << numOfApples << endl;
		cout << " 희귀장수 지갑 : " << myMoney << endl;
	}

};

class BananaSeller : public Person
{
private:
	unsigned int Banana_PRICE;
	unsigned int numOfbanana;
	unsigned int myMoney;
	string myName;

public:
	BananaSeller(string name, int price, int num, int money)	
		:myName(name), Banana_PRICE(price), numOfbanana(num), myMoney(money), Person(name) {}

	int SaleApples(int money)
	{
		int num = money / Banana_PRICE;
		numOfbanana -= num;
		myMoney += money;

		if (numOfbanana < 0) cout << "전체 바나나 값보다 가격이 높음" << endl;
		else return num;
	}
	void Showinfro() {
		cout << " ==================== 바나나 판매상인 ====================" << endl << GetName() << endl;
		cout << " 남은 바나나 : " << numOfbanana << endl;
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
	while (true)
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
		return 0;
	}
}