
#include <iostream>
#include "task6++Real.h"
using namespace std;

struct Part {
	string name;
    string manufacturer;
	string carModel;
    string answer;
	int cost;
	union {
		struct {
			int amountInStock;
		}str1;
		struct {
			int amountToOrder;
		}str2;
	};
};


Part InpPartInfo() {
	Part scb;
	cout << "Название детали: "; cin >> scb.name;
	cout << "Производитель: "; cin >> scb.manufacturer;
	cout << "Модель автомобиля: "; cin >> scb.carModel;
	cout << "Цена: "; cin >> scb.cost;

	return scb;
}
Part StockInfo(Part& scb) {
    cout << "Есть ли " << scb.name << " в наличии?(Yes или No)";
    cin >> scb.answer;
    if (scb.answer == "Yes") {
        cout << "Введите количество товара " << "\n";
        cin >> scb.str1.amountInStock;
    }
    else {
        cout << "Введите количество необходимое для закупки  " << scb.name << "\n";
        cin >> scb.str2.amountToOrder;
    }
    return scb;
}



void OutPartInfo(Part scb){
	cout << scb.name << " | " << scb.manufacturer << " | "
		<< scb.carModel << " | " << scb.cost << endl;
}

void StockChecker(Part& scb) {
    if (scb.str2.amountToOrder > 0){
        OutPartInfo(scb); cout << "Необходимо дозаказать  " << scb.str2.amountToOrder << " единиц данного товара. " << endl;
}
}


int main(){
	setlocale(LC_ALL, "ru");
	int d;
	cout << "Введите количество товаров: ";
	cin >> d;
	Part* details;
	details = new Part[d];
	int i, j;
    while (1)
    {
        cout << "    Меню СУБД:" << endl
            << "1. Ввод данных." << endl
            << "2. Вывод информации о товаре." << endl
            << "3. Вывод всей информации." << endl
            << "4. Учет наличия." << endl
            << "5. Удаление товаров." << endl
            << "6. Поиск деталей не в наличии." << endl
            << "7. Закончить работу." << endl
            << ">";
        cin >> i;
        switch (i)
        {
        case 1: cout << "Артикул детали: "; cin >> i;
            details[i] = InpPartInfo(); break;
        case 2: cout << "Артикул детали: "; cin >> i;
            OutPartInfo(details[i]); break;
        case 3: for (i = 0; i < d; i++)
            if (details[i].cost) {
                cout << "Товар №" << i+1 << ':' << endl;
                OutPartInfo(details[i]);
            }
              break;
        case 4: cout << "Артикул детали: "; cin >> i;
            StockInfo(details[i]); break;
        case 5: cout << "Артикул удаляемого товара: "; cin >> i;
            details[i] = {}; break;
        case 6: for (i = 0; i < d; i++) {
            StockChecker(details[i]);
        }
            break;
        case 7: return 0;
        default: cout << "Повторите ввод!" << endl;
        }
        
    }
    delete[] details;


}
