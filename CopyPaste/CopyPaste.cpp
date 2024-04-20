#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("data.txt");
    string line;
    Sleep(2000);
    int start = clock();
    /*int typespd = 1200;
    while (getline(fin, line)) {
        for (char i : line) {
            INPUT inputs[1] = {};
            ZeroMemory(inputs, sizeof(inputs));

            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wScan = i;
            inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

            SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
            Sleep(1000 / typespd);
        }
        INPUT inputs[1] = {};
        ZeroMemory(inputs, sizeof(inputs));

        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wScan = '\n';
        inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

        SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        Sleep(1000 / typespd);
    }*/

    INPUT inputs[1] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_SHIFT;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

    for (int i = 65; i < 91; i++) {
        INPUT input2[1] = {};
        ZeroMemory(input2, sizeof(input2));

        input2[0].type = INPUT_KEYBOARD;

        SendInput(ARRAYSIZE(input2), input2, sizeof(INPUT));

        input2[0].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(ARRAYSIZE(input2), input2, sizeof(INPUT));

        Sleep(100);
    }

    inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

    while (getline(fin, line)) {
        for (char i : line) {
            bool shift = false;
            UINT key;
            INPUT modif[1] = {};
            INPUT input[1] = {};
            ZeroMemory(modif, sizeof(modif));
            ZeroMemory(input, sizeof(input));
            input[0].type = INPUT_KEYBOARD;
            
            if (isalpha(i)) {
                if (isupper(i)) {
                    shift = true;

                    modif[0].type = INPUT_KEYBOARD;
                    modif[0].ki.wVk = VK_SHIFT;
                    SendInput(1, modif, sizeof(INPUT));
                }

                i = toupper(i);
                input[0].ki.wVk = i;
                SendInput(1, input, sizeof(INPUT));

                input[0].ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, input, sizeof(INPUT));
                if (shift) {
                    modif[0].ki.dwFlags = KEYEVENTF_KEYUP;
                    SendInput(1, modif, sizeof(INPUT));
                }

                continue;
            }
            else if (isdigit(i)) {
                key = 0x60 + int(i);
            }
            else {
                switch (i) {
                case 39:
                    key = VK_OEM_7;
                    break;
                case '"':
                    key = VK_OEM_7;
                    shift = true;
                    break;
                case ';':
                    key = VK_OEM_1;
                    break;
                case ':':
                    key = VK_OEM_1;
                    shift = true;
                    break;
                case '.':
                    key = VK_OEM_PERIOD;
                    break;
                case ',':
                    key = VK_OEM_COMMA;
                    break;
                case '[':
                    key = VK_OEM_4;
                    break;
                case '{':
                    key = VK_OEM_4;
                    shift = true;
                    break;
                case ']':
                    key = VK_OEM_6;
                    break;
                case '}':
                    key = VK_OEM_6;
                    shift = true;
                    break;
                case '/':
                    key = VK_OEM_2;
                    break;
                case '?':
                    key = VK_OEM_2;
                    shift = true;
                    break;
                //case '_':
                case '<':
                    key = VK_OEM_102;
                    break;
                case '>':
                    key = VK_OEM_102;
                    shift = true;
                    break;
                case '+':
                    key = VK_ADD;
                    break;
                case '*':
                    key = VK_MULTIPLY;
                    break;
                }

            }
            
        }
    }

    int end = clock();
    cout << end - start;
    fin.close();
    return 0;
}

