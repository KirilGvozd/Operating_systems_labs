#include <iostream>

using namespace std;

int main() {

	time_t now = time(0);
	struct tm localTime;
	localtime_s(&localTime, &now);

	char formattedTime[20];
	strftime(formattedTime, sizeof(formattedTime), "%d.%m.%Y %H:%M:%S", &localTime);
	cout << "Current local date & time: " << formattedTime << endl;

	return 0;
}