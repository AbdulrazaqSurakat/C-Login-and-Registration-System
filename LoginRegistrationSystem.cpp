#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>
#include <sstream>

using namespace std;

template <typename T>
bool printTypeInfo(const T& value) {
	// Use std::is_same to check type at compile time
	if (std::is_same<T, std::string>::value) {
		return true;
	}
	else {
		return false;
	}
}

// Base class for basic operations
class User {
public:
	string username;
	string password;
	string fullname;

	User(string Username, string Password, string Fullname) :username(Username), password(Password), fullname(Fullname) {}

	void getUsername() {
		cout << username << endl;
	}
	void getPassword() {
		cout << password << endl;
	}
	void generateFile()
	{
			 ofstream file_;
			 file_.open("UserRegistrationDatabase.txt");
			 file_ << "Hi " << fullname << ". Here is your log in Info: " << endl;
			 file_ << username << endl;
			 file_ << password  << endl;
			 file_.close();
			 cin.get();
	}
};

int main() {
	string fullname;
	string username;
	string password;
	cout << "Please enter your fullname" << endl;
	getline(std::cin, fullname);
	cout << "Please enter a username" << endl;
	getline(std::cin, username);
	cout << "Please enter a password" << endl;
	getline(std::cin, password);

	User User1(username, password, fullname);
	User1.generateFile();

	return 0;
}
