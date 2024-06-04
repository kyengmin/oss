#include <iostream>
using namespace std;

class CoffeeMachine {
private:
    int coffee;
    int water;
    int sugar;

public:
    CoffeeMachine(int initialCoffee, int initialWater, int initialSugar) {
        coffee = initialCoffee;
        water = initialWater;
        sugar = initialSugar;
        if(coffee > 100) coffee =100; //최대값 설정
        if(coffee < 0) coffee = 0; // 최솟값 설정
        if(water > 100) water = 100;
        if(water < 0) water =0;
        if(sugar > 100) sugar = 100;
        if(sugar < 0) sugar =0;
    }

    void drinkEspresso(){ //에스프레소 만드는 함수
        if(coffee >= 10 && water >= 5) { 
            coffee -= 10;
            water -= 5;
            std::cout << "에스프레소를 만들었습니다." << endl;
            if(coffee < 10 || water < 10 || sugar <10 ) Refill(); //재료가 10 미만으로 떨어지면 Refill() 함수 호출
        } else {
            std::cout << "에스프레소를 만들 수 없습니다." << std::endl; //재료가 떨어진다면 출력후 Refill() 호출해 재료 리필
            Refill();
        }
        
    }

    void drinkAmericano(){ //아메리카노 만들기
        if(coffee >= 5 && water >= 5){
            coffee -=5;
            water -= 5;
            std::cout << "아메리카노를 만들었습니다." << endl;
            if(coffee < 10 || water < 10 || sugar <10 ) Refill(); //10미만 떨어지면 리필
        } else{
            std::cout << "아메리카노를 만들 수 없습니다." << std::endl; // 재료소진시 출력후 리필
            Refill();
        }
    }

    void drinkSugarCoffee(){ //설탕커피 만들기
        if(coffee >= 5 && water >= 5 && sugar >= 5){
            coffee -= 5;
            water -= 5;
            sugar -= 5;
            std::cout << "설탕커피를 만들었습니다." << endl;
            if(coffee < 10 || water < 10 || sugar <10 ) Refill(); //제조후 재료 10미만으로 떨어지면 리필
        }else {
            std::cout << "설탕 커피를 만들 수 없습니다." << std::endl; //재료소진시 출력후 리필
            Refill();
        }
    }
    /*
    void fill(){
        coffee = 10;
        water = 10;
        sugar = 10;
    } */

    void Refill(){ //재료를 100까지 리필하는 함수

        const int maxitem =100;
        
        if(coffee < 10) {
            int refill_amount = maxitem-coffee; //100으로 리셋하지 않고 100까지 채움
            coffee += refill_amount;
            std::cout << refill_amount << "만큼 커피를 채웁니다." <<endl;
            }
        if(water < 10) {
            int refill_amount = maxitem-water;
            water += refill_amount;
            std::cout << refill_amount << "만큼 물을 채웁니다." << endl;
            }
        if(sugar < 10){
            int refill_amount = maxitem-sugar;
            sugar += refill_amount;
            std::cout << refill_amount << "만큼 설탕을 채웁니다." << endl; 
            }

        }

    void show(){
        std::cout << "커피머신 상태, 커피:" << coffee << " 물:" << water << " 설탕:" << sugar << endl;
    }
    };

int main(){
    int num;
    
    CoffeeMachine start(10,10,15);
    cout << "1.에스프레소, 2.아메리카노, 3.설탕 커피 중 선택 (0입력시 종료)" <<endl;
    while(1){

        cin >> num;
        if(num == 1){
            start.drinkEspresso();
            start.show();
        } else if(num == 2) {
            start.drinkAmericano();
            start.show();
        } else if(num == 3) {
            start.drinkSugarCoffee();
            start.show();
        } else if(num == 0) {
            start.Refill();
            start.show();
            break;
        } else
            cout << "다시 입력하세요";
    }


    return 0;
}