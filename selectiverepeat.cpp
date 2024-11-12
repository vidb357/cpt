#include <iostream>
using namespace std;

int main() {
    int w, f;
    int frames[50];          // Array to hold frames
    bool acknowledged[50] = {false}; // Array to track acknowledgment status

    cout << "Enter window size: ";
    cin >> w;

    cout << "\nEnter number of frames to transmit: ";
    cin >> f;

    cout << "\nEnter " << f << " frames: ";
    for (int i = 0; i < f; i++) {
        cin >> frames[i];
    }

    int sentFrames = 0;

    cout << "\nSelective Repeat Protocol Simulation:\n";
    while (sentFrames < f) {
        // Send each frame within the window
        for (int i = sentFrames; i < sentFrames + w && i < f; i++) {
            if (!acknowledged[i]) {
                cout << "Sending frame " << frames[i] << endl;

                // Manually input acknowledgment for each frame
                cout << "Acknowledge frame " << frames[i] << "? (1 for Yes, 0 for No): ";
                int ack;
                cin >> ack;

                if (ack == 1) {
                    acknowledged[i] = true;
                    cout << "Frame " << frames[i] << " acknowledged.\n";
                } else {
                    cout << "Frame " << frames[i] << " not acknowledged. Will resend.\n";
                }
            }
        }

        // Move the window forward by skipping acknowledged frames
        while (sentFrames < f && acknowledged[sentFrames]) {
            sentFrames++;
        }

        cout << endl;
    }

    cout << "All frames have been acknowledged.\n";
    return 0;
}
