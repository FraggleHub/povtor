/*
#include "Chat111.h"
#include <iostream>

User::User(std::string password, std::string userName, int newUserID) :password(password), userName(userName), newUserID(newUserID) {}


std::string User::getPassword() 
{
	return password;
}

std::string User::getUserName() 
{
	return userName;
}

int User::getNewUserID()
{
	return newUserID;
}

bool Chatss::registerUser(std::string userName, std::string password)
{
    for (auto& users : userDatabase)
        for ( User& user : users)
            if (user.getUserName() == userName) {
                std::cout << "��� ������������ ��� ���������� " << userName << std::endl;
                return false;
            }
    int newUserID = userDatabase.size() + 1;
    userDatabase.push_back({ User(password, userName, newUserID) });
    std::cout << "������������ ���������������: id " << newUserID << std::endl;
    return true;
}

bool Chatss::login(std::string userName, std::string password, int newUserID)
{
    for (auto& users : userDatabase)
        for (User& user : users)
            if (user.getUserName() == userName && user.getPassword() == password) {
                std::cout << "���� ��������: " << userName << " " << "id: " << user.getNewUserID() << std::endl;
                currentUser = &user;
                return true;
            }
    std::cout << "������������ ������ �����." << std::endl;
    return false;
}

void Chatss::logout()
{
    if (currentUser) {
        currentUser->getUserName();
        currentUser = nullptr;
    }
}

void Chatss::showAllUsers()
{
    std::cout << "��������� ����:" << std::endl;

    for (auto& users : userDatabase)
        for (User& user : users)
            std::cout << user.getUserName() << " (id: " << user.getNewUserID() << ")" << std::endl;
}

void Chatss::sendMessageUser( std::string senderName)
{
    showAllUsers();

    int recipientID;
    std::cout << "������� ID ����������: ";
    std::cin >> recipientID;

    std::string messageText;
    std::cout << "������� ����� ���������: ";
    std::cin.ignore();
    std::getline(std::cin, messageText);
    User* recipient = nullptr;

    // ������� ���������� � �������� ID
    for (auto& users : userDatabase)
        for (User& user : users)
            if (user.getNewUserID() == recipientID) {
                recipient = &user;
                break;
            }
    if (recipient) {
        Message newMessage = { senderName, recipientID, messageText };
        messageHistory.push_back(newMessage);
        std::cout << "��������� ���������� ������������ " << recipient->getUserName() << ": " << messageText << std::endl;
    }
    else
        std::cout << "������������ � ��������� ID �� ������." << std::endl;
}

void Chatss::checkMessage()
{
    for (Message& message : messageHistory)
        std::cout << "����� ��������� �� " << message.sender << ": " << message.text << std::endl;
}
*/
#include "Chat111.h"
#include <iostream>
#include "AccountsConsole.h"

using namespace std;

Messangers mess;

int NewChat::UserId = 0;
Users::Users(int id, string login, string password, string name) :id(id), login(login), password(password), name(name) {}

Users::~Users() { }

string Users::getLogin() {
    return login;
}

string Users::getPassword() {
    return password;
}

string Users::getName() {
    return name;
}

int Users::getId() {
    return id;
}

NewChat::NewChat() {
    usersArray = new Users[number_users];
}

NewChat::~NewChat()
{
    if (usersArray != nullptr) {
        delete[] usersArray;
    }

}

bool NewChat::registerUser(string login, string password, string name)
{
    for (int i = 0; i < usersCount; ++i) {
        if (usersArray[i].getLogin() == login) {
            cout << "����� \"" << login << "\" ��� �����. �������� ������ �����." << endl;
            return false;
        }
    }

    if (usersCount >= number_users)
    {
        resizer();
    }
    int newId = UserId + 1;
    Users newUser(newId, login, password, name);
    usersArray[usersCount] = newUser;
    ++usersCount;
    UserId = newId;

    cout << "����������� ������������ \"" << name << "\" ������� ���������." << endl;
    return true;
}

bool NewChat::Entered(string login, string password)
{
    for (int i = 0; i < usersCount; ++i) {
        if (usersArray[i].getLogin() == login && usersArray[i].getPassword() == password) {
            cout << "���� �������� �������. ����� ����������, " << usersArray[i].getName() << "!" << endl;
            cout << "��� ���������� ID: " << usersArray[i].getId() << endl;
            showAllUsers();
            mess.WhosMessage(usersCount, usersArray[i].getId());
            return true;
        }
    }

    cout << "�������� ����� ��� ������. ���������� �����." << endl;
    return false;
}

void NewChat::dataUser()
{
    string login;
    string password;
    string name;

    cout << "������� �����: ";  
    cin >> login;
    cout << "������� ������: ";
    cin >> password;
    cout << "������� ������ ���: ";
    cin.ignore(); 
    getline(std::cin, name);
    registerUser(login, password, name);
}

void NewChat::showAllUsers()
{
    cout << "������ ������������������ �������������:" << endl;
    for (int i = 0; i < usersCount; ++i) {
        cout << "ID: " << usersArray[i].getId() << " | ���: " << usersArray[i].getName() << endl;
    }
}

void NewChat::resizer()
{
    if (usersCount == number_users) {
        Users* newArray = new Users[number_users * 2];
        for (int i = 0; i < number_users; i++)
        {
            newArray[i] = usersArray[i];
        }
        delete[] usersArray;
        usersArray = newArray;
        number_users *= 2;
    }
}

void NewChat::Prog()
{
    bool  isLoggedIn = true;
    int choice;

    while (true) {
        if (isLoggedIn) {
            std::cout << "����� ���������� � ���!" << std::endl;
            isLoggedIn = false;
        }

        std::cout << "�������� ��������:" << std::endl;
        std::cout << "1. ����������� ������ ������������" << std::endl;
        std::cout << "2. ���� � �������" << std::endl;
        std::cout << "3. ������ ����������" << std::endl;
        std::cout << "0. ����� �� ���������" << std::endl;

        std::cout << "������� ����� ���������� ��������: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            dataUser();
            break;
        }
        case 2: {
            std::string login, password;
            std::cout << "������� �����: ";
            std::cin >> login;
            std::cout << "������� ������: ";
            std::cin >> password;
            Entered(login, password);
            break;
        }
        case 3: {
            showAllUsers();
            break;
        }
        case 0:
            std::cout << "����� �� ���������." << std::endl;
            return;
        default:
            std::cout << "������������ �����." << std::endl;
            break;
        }
    }
}