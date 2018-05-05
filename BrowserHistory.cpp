#include "BrowserHistory.h"

BrowserHistory::BrowserHistory() {
	_currentSite = _NavigationHistoryList.begin();//initialize the iterator to the begining of navigation list
}
BrowserHistory::~BrowserHistory() {
	//we don't need implement anything because the list already have 
	//its own destructor.
}
void BrowserHistory::visitSite(Webpage newSite) {
	_FullHistoryList.push_back(newSite);//add a website to full history list
	if (_NavigationHistoryList.empty())//check if list is empty
	{
		_NavigationHistoryList.push_back(newSite);//add website to the back of navigation list
		_currentSite = _NavigationHistoryList.begin();//set iterator to begining of navigation list
	}
	else//iterator is at somewhere in the navigation
	{
		list<Webpage>::iterator temp = _currentSite;//set iterator temp to currentSite
		if (++temp!=_NavigationHistoryList.end())
		{
			_NavigationHistoryList.erase(temp, _NavigationHistoryList.end());//remove all sites after currents before add new website
		}
		_NavigationHistoryList.push_back(newSite);//add new website into navigation list after removing
		_currentSite++;//increment the current iterator to current position 
	}
}
//return the URL of a website
string BrowserHistory::getURL(){
	return _currentSite->getURL();
}
//return the size of the navigation history
size_t BrowserHistory::getNavSize() {
	return _NavigationHistoryList.size();
}
//return the URL of the back website
string BrowserHistory::back() {
	_currentSite--;
	return _currentSite->getURL();
}
//return the URL of the forward website
string BrowserHistory::forward() {
	_currentSite++;
	return _currentSite->getURL();
}
//read a text find containing user click: new, back, forward
void BrowserHistory::readHistory(string fileName) {
	ifstream myfile(fileName);
	if (myfile.is_open())//check if file open successfully
	{
		string webURL, userClick;//declare variable to hold website URL and action click
		time_t time;//variable holding value of time visited
		while (myfile >> userClick)//read in new, back, forward first
		{
			if (userClick == "new")//check if action click="new"
			{
				myfile >> webURL >> time;//if yes continue read in web URL and time
				Webpage page;//declare a page type webpage to hold webURL and time
				page.setURL(webURL);//call setter function to set the URL 
				page.setTime(time);//call setter function to set the time
				visitSite(page);//call the visitSite to add new website into naviation list
			}
			else if (userClick == "back")
				back();//call function back() to do back() action
			else if (userClick == "forward")
				forward();//call function to do forward() action
		}
		myfile.close();//close the file after using
	}
	else
		throw invalid_argument("Could not open file " + fileName);// throw exception if file could not open
}
//print all the back websites in the navigation list
void BrowserHistory::printBackSites() {
	list<Webpage>::iterator temp = _NavigationHistoryList.begin();//set an iterator to the begining of navigation list
	for (;  temp!=_currentSite;temp++)//loop from the begining to currentSite
	{
		cout<<temp->getURL()<< endl;//print out the website URL
	}
}
//print the all the forward websites in navigation list
void BrowserHistory::printForwardSites() {
	list<Webpage>::iterator temp = _currentSite;//set an iterator to currentSite
	for (; temp != _NavigationHistoryList.end(); temp++)//loop from currentSite to end of list
	{
		cout << temp->getURL() << endl;//print out the website URL
	}
}
//print all the websites in full history list
void BrowserHistory::printFullHistory() {
	list<Webpage>::iterator end = _FullHistoryList.end();//set an iterator to the end of full history list
	for (list<Webpage>::iterator begin = _FullHistoryList.begin();begin!=end;begin++)//loop from the begining to end of list;
	{
		cout << begin->getURL() << endl;//print out the website URL
	}
}
