#include<iostream>
#include<map>
#include<string>
#include<functional>

using namespace std;

int N,X;
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


void enterX(){
  while (true) {
  EnterNumber(X,"Enter number x: ")();
  if (X < 999 && X > 99) {
    cout << "X: " << X << endl;
    break;
  } else{
    cout << "Invalid number.\n";
  }
  }
}

void enterN(){
  while (true) {
  EnterNumber(N,"enter number n (less than X, i.e. 1 to 3): ")();
  if (N >= 1 && N < 3) {
    cout << "N:" << N <<endl;
    break;
  }else{
    cout << "Invalid.\n";
  }
  }
}

void enterfirstX(){
  int first = X / 100;
  cout << "first digit X: " << first << endl;
}

void enterNX(){

}

struct MenuItem{
        string title;
        function<void()>action;
    };

int main(){
    map<int,MenuItem>menu= {
        {1,{"x",enterX}},
        {2,{"n",enterN}},
        {3,{"first digit x",enterfirstX}},
    };
    int choice = 0;

    while (true) {
        cout<<"Menu:"<<endl;
        for (const auto& item : menu) {
            cout << "Task " <<item.first <<". " << item.second.title <<endl;
        }
        cout << "0. Exit" << endl;
        EnterNumber(choice,"Enter Task: ")();
        if (choice == 0 ){
            cout << "@ 2025 FirstName LastName" <<endl;
            break;
        }
        cout << endl;
        if(menu.find(choice)!= menu.end()){
            menu[choice].action();
        }else{
            cout << "Invalid input.";
        }
        cout << endl;
    }
    return 0;
}