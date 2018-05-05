#pragma once

#include <string>
using namespace std;

class Webpage {
public:
    Webpage();//constructor
    Webpage(const string& webpageURL, const time_t& timeVisited);//parameter constructor
    string getURL();//return the URL of a website
    time_t getTime();//return the time visited
	void setURL(string webPageURL);//set the URL of a website
	void setTime(time_t timeVisited);//set the URL of a website
private:
	string _webpageURL;//variable holding a URL of a website
	time_t _timeVisited;// variable holding time visited 
};
