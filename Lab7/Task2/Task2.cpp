#include <iostream>
#include <ctime>

using namespace std;

int main() {
    
    int num_of_iterations = 0;
    time_t start_time = time(nullptr);
    bool flagForFiveSeconds = true;
    bool flagForTenSeconds = true;

    while (true) {
        num_of_iterations++;

        time_t currentTime = time(nullptr);
        int elapsedTime = difftime(currentTime, start_time);


        if (elapsedTime == 5 && flagForFiveSeconds) {
            cout << "Number of iterations after 5 seconds: " << num_of_iterations << endl;
            flagForFiveSeconds = false;
        }

        else if (elapsedTime == 10 && flagForTenSeconds) {
            cout << "Number of iterations after 10 seconds: " << num_of_iterations << endl;
            flagForTenSeconds = false;
        }

        else if (elapsedTime == 15) {
            cout << "Final number of iterations after 15 seconds: " << num_of_iterations << endl;
            break;
        }
    }

    return 0;
}
