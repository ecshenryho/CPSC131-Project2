#include "Webpage.h"
//default constructor
Webpage::Webpage() {
	_webpageURL = "Default URL";//default value 
	_timeVisited = 0;//default vaule
}
//parameter constructor
Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
	_webpageURL = webpageURL;
	_timeVisited = timeVisited;
}
//return the URL of a website
string Webpage::getURL(){
	return _webpageURL;
}
//return the time visted
time_t Webpage::getTime() {
	return _timeVisited;
}
//set the URL of a website
void Webpage::setURL(string webPageURL) {
	_webpageURL = webPageURL;
}
//set the time visited
void Webpage::setTime(time_t timeVisited) {
	_timeVisited = timeVisited;
}
