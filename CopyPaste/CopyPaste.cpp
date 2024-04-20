#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

int main()
{
    ifstream fin("data.txt");
    string line;
    Sleep(2000);
    int start = clock();
    int kd = 60;
    int typespd = 25;

    while (getline(fin, line)) {
        for (char i : line) {
            bool shift = false;
            UINT key = 9999;
            INPUT modif[1] = {};
            INPUT input[1] = {};
            ZeroMemory(modif, sizeof(modif));
            ZeroMemory(input, sizeof(input));
            input[0].type = INPUT_KEYBOARD;
            modif[0].type = INPUT_KEYBOARD;
            modif[0].ki.wVk = VK_SHIFT;
            
            if (isalpha(i)) {
                if (isupper(i)) shift = true;
                key = int(toupper(i));
            }
            else if (isdigit(i)) {
                key = 0x30 + int(i) - 48;
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
                case '-':
                    key = VK_OEM_MINUS;
                    break;
                case '_':
                    key = VK_OEM_MINUS;
                    shift = true;
                    break;
                case '<':
                    key = VK_OEM_COMMA;
                    shift = true;
                    break;
                case '>':
                    key = VK_OEM_PERIOD;
                    shift = true;
                    break;
                case '+':
                    key = VK_ADD;
                    break;
                case '*':
                    key = VK_MULTIPLY;
                    break;
                case ' ':
                    key = VK_SPACE;
                    break;
                case '(':
                    key = 0x39;
                    shift = true;
                    break;
                case ')':
                    key = 0x30;
                    shift = true;
                    break;
                case '&':
                    key = 0x37;
                    shift = true;
                    break;
                case '=':
                    key = VK_OEM_PLUS;
                    break;
                case '!':
                    key = 0x31;
                    shift = true;
                    break;
                case 92:
                    key = VK_OEM_5;
                    break;
                case '|':
                    key = VK_OEM_5;
                    shift = true;
                    break;
                }
            }
            if (shift) SendInput(1, modif, sizeof(INPUT));
            try {
                if (key == 9999) throw i;
                input[0].ki.wVk = key;
            }
            catch (char i) {
                cout << "Error. Key " << i << '(' << int(i) << ')' << " is not resolved.";
                return 1;
            }
            SendInput(1, input, sizeof(INPUT));
            input[0].ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, input, sizeof(INPUT));
                
            if (shift) {
                modif[0].ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, modif, sizeof(INPUT));
            }
            kd--;
            Sleep(1000 / typespd);
            /*if (kd == 0) {
                Sleep(3000);
                kd = 60;
            }*/
        }
        INPUT enter[1] = {};
        ZeroMemory(enter, sizeof(enter));
        enter[0].type = INPUT_KEYBOARD;
        enter[0].ki.wVk = VK_RETURN;
        SendInput(1, enter, sizeof(INPUT));
        enter[0].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, enter, sizeof(INPUT));
        Sleep(1000 / typespd);
    }

    int end = clock();
    std::cout << end - start;
    fin.close();
    return 0;
}

