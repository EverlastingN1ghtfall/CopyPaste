#include <iostream>
#include <Windows.h>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("data.txt");
    string line;
    Sleep(1000);
    while (getline(fin, line)) {
        for (char i : line) {
            INPUT inputs[1] = {};
            ZeroMemory(inputs, sizeof(inputs));

            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wScan = i;
            inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

            SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        }
        INPUT inputs[1] = {};
        ZeroMemory(inputs, sizeof(inputs));

        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wScan = '\n';
        inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

        SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    }
    string a;
    cin >> a;
    return 0;
}

