// EXP 7: Go-Back-N
#include <iostream>
using namespace std;

int main() {
    int w, f, i, frames[50];

    cout << "Enter window size: ";
    cin >> w;

    cout << "\nEnter number of frames to transmit: ";
    cin >> f;

    cout << "\nEnter " << f << " frames: ";
    for (i = 0; i < f; i++)
        cin >> frames[i];

    cout << "\nWith sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames)\n";
    cout << "After sending " << w << " frames at each stage, the sender waits for acknowledgment from the receiver.\n\n";

    // Sliding window transmission
    for (i = 0; i < f; i++) {
        cout << frames[i] << " ";

        // Check if the window is full
        if ((i + 1) % w == 0) {
            cout << "\nAcknowledgment of above frames received by sender\n\n";
        }
    }

    // Check for remaining frames if any
    if (f % w != 0) {
        cout << "\nAcknowledgment of above frames received by sender\n";
    }

    return 0;
}
