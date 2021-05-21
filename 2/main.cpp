#include "PermutationCipher.h"
#include <locale>
#include <codecvt>
int main()
{
    bool isTrue = true;
    string mode,NeMode,str;
    cout << "Welcome" << endl;
    cout << "For escape from programm write \"exit\"." << endl;
    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Select operating mode:";
        cin >> mode;
        if (mode == "Encode") {
            cout << "Write your line for Encode:";
            cin.get();
            getline(cin, str);
            int key;
            cout << "Write your key:";
            cin >> key;

            PermutationCipher encode(key);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstren = codec.from_bytes(str);
			 cout<<codec.to_bytes(encode.EncodePermutationCipher(encode,wstren))<<endl;
            
        }
        if (mode == "Decode") {
            cout << "Write your line for Decode:";
            cin.get();
            getline(cin, str);
            int key;
            cout << "Write your key:";
            cin >> key;
            PermutationCipher decode(key);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstrdec = codec.from_bytes(str);
			cout<<codec.to_bytes(decode.DecodePermutationCipher(decode,wstrdec))<<endl;
            
        }
        if (mode == "exit") {
            cout << "The program is over." << endl;
            isTrue = false;
            break;
        }
        if (mode != "Encode" && mode != "Decode" && mode != "exit") {
          
            cin >> NeMode;
            

        }

    } while (isTrue != false);
    return 0;
}