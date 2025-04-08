#include<iostream>
#include<map>
#include<string>
#include<functional>

using namespace std;

int N,X;

void enterX(){
  EnterNumber(X,"Введите число x: ")();
  cout << "X: " << X << endl;
}

void enterN(){

}

void enterfirstX(){

}

void enterNX(){

}
bool UserInput(string input) {
    if (input.empty())
      return false;
    try {
      int number = stoi(input);
    } catch (...) {
      return false;
    }
    return true;
  }
  
  function<void()> EnterNumber(int &varLink, string label) {
    return [&varLink, label]() {
      string raw_input;
      cout << label;
      getline(cin, raw_input);
  
      while (!UserInput(raw_input)) {
        cout << label;
        getline(cin, raw_input);
      }
      varLink = stoi(raw_input);
    };
  }

struct MenuItem{
        string title;
        function<void()>action;
    };

int main(){
    map<int,MenuItem>menu= {
        {1,{"Ввод 1-ой стороны треугольника", EnterNumber(N,"Input side1")}},
        {2,{"Ввод 2-ой стороны треугольника", EnterNumber(X,"Input side2")}},
    };
    int choice = 0;

    while (true) {
        cout<<"Меню:"<<endl;
        for (const auto& item : menu) {
            cout << "Task " <<item.first <<". " << item.second.title <<endl;
        }
        cout << "0. Выход" << endl;
        EnterNumber(choice,"Введите номер пункта: ")();
        if (choice == 0 ){
            cout << "@ 2025 FirstName LastName" <<endl;
            break;
        }
        cout << endl;
        if(menu.find(choice)!= menu.end()){
            menu[choice].action();
        }else{
            cout << "Некорректный ввод.";
        }
        cout << endl;
    }
    return 0;
}