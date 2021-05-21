// Головной модуль

#include <iostream>
#include <cctype>
#include <codecvt>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;

// проверка, чтобы строка состояла только из прописных русских букв
bool isValid(const string& s)
{
locale loc("ru_RU.UTF-8");
wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
wstring ws = codec.from_bytes(s);
for (auto wc: ws)
if (!((wc>= 1040) && (wc <= 1071)) || (wc == 1025))
return false;
return true;
}
int main(int argc, char **argv)
{
string key;
string text;
unsigned op;

m1:
cout<<"Cipher ready. Введите ключ(русские заглавные буквы): ";
cin>>key;
if (!isValid(key)) {
cerr<<"Ключ не принят"<<endl;
goto m1;
//return 1;
}
cout<<"Ключ принят"<< endl;
modAlphaCipher cipher(key);
do {
m2:
cout<<"Cipher ready. Введите операцию (0-выход, 1-зашифровка, 2-расшифровка): ";
cin>>op;
if (op > 2) {
cout<<"номер операции ошибочен"<<endl;
goto m2;
} else if (op >0) {
cout<<"Cipher ready. Введите текст: ";
cin>>text;
if (isValid(text)) {
if (op==1) {
cout<<"Зашифрованный текст:"<<cipher.encrypt(text)<<endl;
} else {
cout<<"Расшифрованный текст:"<<cipher.decrypt(text)<<endl;
}
} else {
cout<<"Операция не выполнена: неверный формат текста(не руссие заглавные буквы)"
<< endl;
}
}
} while (op!=0);
return 0;
}