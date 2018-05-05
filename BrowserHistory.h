#pragma once
#include<stdexcept>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();//default constructor
    ~BrowserHistory();//destructor
    void visitSite(Webpage newSite);//add a new website to full history list and navigation list
    string back();//return the URL of the back website
    string forward();//return the URL of the forward website
    void readHistory(string fileName);//reading text file
    string getURL();//return the URL of a website
    size_t getNavSize();//return the size of navigation history list
    void printBackSites();//print all the back websites of the navigation history list
    void printForwardSites();//print all the forward websites of the naviagtion history list
    void printFullHistory();//print all websites int he history list
private:
	list<Webpage> _FullHistoryList;//declare a list of type Webpage to hold full history
	list<Webpage> _NavigationHistoryList;//declare a list of type webpage to hold full navigation history
	list<Webpage>::iterator _currentSite;//declare an iterator to keep track for navigation list
};
