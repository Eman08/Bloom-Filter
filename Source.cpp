#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "sha256.h"
#include "md5.h"
#include <CkPrng.h>
#include "uint256_t.h"
#include <stdlib.h>
#include <iomanip>


using namespace std;
SHA256 sha256;

void printVector(vector<bool> vec) {
    int i = 0;
    for (auto it = vec.begin(); it != vec.end(); it++) {

        std::cout << *it << " ";
    }
}

long long hash1(string s, int size) {


    int hash, sum = 0;
    int number = 10;
    for (int i = 0; i < s.length(); i++) {
        sum += (int)s[i] * number;
        number *= pow(number, i);
        number++;
    }
    long long pos = abs(sum % size);
    return pos;

}

int hash2(string s, int size) {

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += pow(3, i) * (int)s[i];
    }
    int pos = abs(sum % size);
    return pos;
}

long long hash3(string s, int size) {

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (int)s[i] * pow(2, i) * pow(3, 2);
    }
    long long pos = abs(sum % size);
    return pos;
}

long long hash4(string s, int size) {

    int sum = 7;
    for (int i = 0; i < s.length(); i++) {
        sum += ((sum * 20) + ((int)s[i])) % size;
    }
    long long pos = abs(sum % size);
    return pos;
}

long long hash5(string s, int size) {

    int sum = 2;
    int p = 3;
    for (int i = 0; i < s.length(); i++) {
        int ch = sum * 2;
        sum += ch + (s[i] * pow(p, 2));
        p++;
    }

    long long pos = abs(sum % size);
    return pos;
}

long long hash6(string s, int size) {

    long sum = 0, mul = 1;
    for (int i = 0; i < s.length(); i++) {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += (int)s[i] * mul;
    }
    long long pos = abs(sum % size);
    return pos;
}


long long hash7(string s, int size) {

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (int)s[i];
    }

    sum = sum * sum * sum;
    long pos = abs(sum % size);
    return pos;
}


long long hash8(string s, int size) {
    long long sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (int)s[i] + ((long long)s[i] * i * pow(i, 3));
    }


    long long pos = abs(sum % size);
    return pos;
}

long long hash9(string s, int size) {
    long long sumeven = 0;
    long long sumodd = 0;
    long long sum = 0;
    int number = 2;
    for (int i = 0; i < s.length(); i++)
        if (i % 2 == 0)
        {
            sumeven += number * (long long)s[i];
            number *= 4;
        }

        else
        {
            sumodd += number * (long long)s[i];
            number *= 5;
        }

    sum = sumeven + sumodd;
    long long pos = abs(sum % size);

    return pos;
}


int hash10(string s, int size) {

    int sum = 0;
    int fact = 1;
    int number = 7;
    for (int i = 0; i < s.length(); i++) {
        sum += (int)s[i] * number * (number + 1);
        number++;
    }

    int pos = abs(sum % size);

    return pos;
}

long long hash11(string s, int size) {

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (sum * 30) + int(s[i]);
    }

    long long pos = abs(sum % size);
    return pos;
}

long long hash12(string s, int size) {

    long long sum = 0;
    int num = 2;
    for (int i = 0; i < s.length(); i++) {
        sum += ((sum * 30) / 2) + int(s[i]);
    }

    long long pos = abs(sum % size);
    return pos;
}

long long hash13(string s, int size) {

    long long sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += pow((15) + long long(s[i]), 2);
    }
    long long pos = (sum % size);
    return pos;
}

long long hash14(string s, int size) {

    long long sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += pow(s[i] * (i + 1), 2);
    }

    long long pos = (sum % size);
    return pos;

}


long long hash15(string s, int size) {

    long long sum = 0;

    for (int i = 0; i < s.length(); i++) {
        sum += long long(s[i]) * pow(long long(s[i]), 3);

    }
    long long pos = (sum % size);
    return pos;

}


//-------------------------------------------------------------------------------------------------



//Generates a 32 byte salt value using an external library
string saltGenerator() {

    CkPrng prng;
    const char* saltHex = prng.genRandom(32, "hex");
    return saltHex;
}


//-------------------------------------------------------------------------------------------------



//Checks the password through each hash 
int userCheck(string password, vector<bool> v1, int size) {

    int pos = hash1(password, size);
    if (v1[pos] == 0) {
        return 1;
    }

    pos = hash2(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash3(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash4(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash5(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash6(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash7(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash8(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash9(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash10(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash11(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash12(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash13(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash14(password, size);
    if (v1[pos] == 0) {
        return 1;
    }
    pos = hash15(password, size);
    if (v1[pos] == 0) {
        return 1;
    }

    return 0;
}


//-------------------------------------------------------------------------------------------------




//Adding all the salt values from the file to the vector
void fillSaltVector(vector <string>& saltCheck) {

    fstream inFile;
    inFile.open("pwdFile.txt", ios::in | ios::out);
    int count = 0;
    string a, b, c;
    while (inFile >> a >> b >> c) {
        saltCheck.push_back(c);
    }
}


//-------------------------------------------------------------------------------------------------



//Adding the user to the file
void addUserToFile(string uid, string hashedPwd, string salt) {
    ofstream reg;

    reg.open("pwdFile.txt", fstream::app);
    reg << uid << " " << hashedPwd << " " << salt << "\n";
    reg.close();
}


//-------------------------------------------------------------------------------------------------



//This function reads through the whole file to find the username entered by user for updating the password
int readFile(string uid, string& updateIdHash, string& updateIdSalt) {

    fstream old;
    old.open("pwdFile.txt", ios::in | ios::out);
    string a1, b1, c1;
    int flag = 0;
    while (old >> a1 >> b1 >> c1)
    {
        if (uid.compare(a1) == 0) {
            cout << "\nUser found!\n";
            updateIdHash = b1;
            updateIdSalt = c1;
            flag = 1;
            break;
        }

    }
    if (flag == 1)
        return 1;
    else
        return 0;
}


//-------------------------------------------------------------------------------------------------





//This function is to ensure that the salt value doesnt repeat although, this is highly very unlikely
int readSaltString(string salt) {
    fstream old;
    old.open("pwdFile.txt", ios::in | ios::out);
    string a1, b1, c1;
    int flag = 1;
    while (old >> a1 >> b1 >> c1)
    {
        if (salt == c1) {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}


//-------------------------------------------------------------------------------------------------




//Checking if the username already exists in the password file
int findUserName(string username) {
    fstream old;
    old.open("pwdFile.txt", ios::in | ios::out);
    string a1, b1, c1;
    int flag = 1;
    while (old >> a1 >> b1 >> c1)
    {

        if (username == a1) {
            flag = 0;
            break;
        }

    }
    if (flag == 0)
        return 0;
    else
        return 1;

}


//-------------------------------------------------------------------------------------------------




//converting from hex to decimal, because the value is 256 bits, uint256_t an external library is used.
uint256_t converter(string password) {
    int len = password.length();

    uint256_t base = 1;
    uint256_t decimalNum = 0;

    for (int i = len - 1; i >= 0; i--) {

        if (password[i] >= 48 && password[i] <= 57) {
            decimalNum += (password[i] - 48) * base;
            base = base * 16;
        }

        else if (password[i] >= 65 && password[i] <= 70) {
            decimalNum += (int(password[i]) - 55) * base;
            base = base * 16;
        }

        else if (password[i] >= 97 && password[i] <= 102) {
            decimalNum += (int(password[i]) - 87) * base;
            base = base * 16;
        }

    }

    return decimalNum;

}


//-------------------------------------------------------------------------------------------------



//This function uses SHA256 and MD5 as cryptographic hash functions and hashes the bigrams using these
void func(string password1, vector<int>& vec) {
    SHA256 sha256;
    MD5 md5;

    string password_sha256 = sha256(password1);
    uint256_t decValueSHA256 = converter(password_sha256);

    string password_md5 = md5(password1);

    uint256_t  decValueMD5 = converter(password_md5);

    for (int j = 0; j < 15; j++) {
        uint256_t sum = decValueMD5 + (j * decValueSHA256);
        uint256_t pos = sum % 1000;
        vec[pos] = 1;
        sum = 0;
    }
}



//-------------------------------------------------------------------------------------------------


//This is when a new user is created it is added to the userBloomFilter.txt file for password updates
void firstTimeReg(string uid) {
    vector<int> vec(1000);
    for (int i = 0; i < 1000; i++)
        vec.at(i) = 0;

    ofstream reg;
    string str = "";
    reg.open("usersBloomFilter.txt", fstream::app);
    reg << uid << " ";

    for (int i = 0; i < vec.size(); ++i) {
        reg << vec[i];

    }
    reg << "\n";
    reg.close();
}


//-------------------------------------------------------------------------------------------------


//This function updates the bloom filter 2 each time the password is updated
void updatingBloomFilter(string uid, vector<int> vec) {
    fstream search;
    search.open("usersBloomFilter.txt", fstream::in | fstream::out);
    string uidFile, hugeNumber;
    int fileVec;
    int counter = 0;
    vector<int> v1;

    while (search >> uidFile >> hugeNumber) {
        if (uidFile == uid) {
            for (int i = 0; i < hugeNumber.length(); i++) {
                const char* c = hugeNumber.c_str();
                int temp = c[i] - 48;
                v1.push_back(temp);
            }

            for (int i = 0; i < vec.size(); i++) {
                if (vec.at(i) == 1) {
                    if (v1.at(i) == 0)
                        v1.at(i) = 1;
                }
            }
            counter = v1.size();
        }
    }
    search.close();


    ofstream newwrite;
    fstream s1;

    newwrite.open("rep.txt", ios::in | ios::out);
    s1.open("usersBloomFilter.txt", ios::in | ios::out);
    while (s1 >> uidFile >> hugeNumber) {

        if (uidFile == uid)
        {
            newwrite << uidFile;
            newwrite << " ";
            for (int i = 0; i < v1.size(); i++) {
                newwrite << v1[i];

            }
            newwrite << "\n";
            continue;
        }


        newwrite << uidFile << " " << hugeNumber << "\n";

    }

    newwrite.close();
    s1.close();

    newwrite.open("usersBloomFilter.txt", ios::trunc);
    newwrite.close();
    newwrite.open("usersBloomFilter.txt");
    s1.open("rep.txt", ios::in | ios::out);

    while (s1 >> uidFile >> hugeNumber) {
        newwrite << uidFile << " " << hugeNumber << "\n";
    }

    newwrite.close();
    s1.close();
}

//-------------------------------------------------------------------------------------------------


//This is the bloom filter 1, that reads the rockyou file and creates a vector changing the bits to 1 after hashing the passwords
void BloomFilter1(vector<bool>& f1, int size) {

    fstream file;
    file.open("rockyou-12.txt", ios::in | ios::out);
    int pos = 0;
    string s;
    long long pos1 = 0;

    while (getline(file, s)) {

        pos = hash1(s, size);
        f1[pos] = 1;

        pos = hash2(s, size);
        f1[pos] = 1;

        pos1 = hash3(s, size);
        f1[pos1] = 1;

        pos1 = hash4(s, size);
        f1[pos1] = 1;

        pos1 = hash5(s, size);
        f1[pos1] = 1;

        pos = hash6(s, size);
        f1[pos] = 1;

        pos1 = hash7(s, size);
        f1[pos1] = 1;

        pos1 = hash8(s, size);
        f1[pos1] = 1;

        pos1 = hash9(s, size);
        f1[pos1] = 1;

        pos1 = hash10(s, size);
        f1[pos1] = 1;

        pos1 = hash11(s, size);
        f1[pos1] = 1;

        pos1 = hash12(s, size);
        f1[pos1] = 1;

        pos1 = hash13(s, size);
        f1[pos1] = 1;

        pos1 = hash14(s, size);
        f1[pos1] = 1;

        pos1 = hash15(s, size);
        f1[pos1] = 1;
    }
}

//-------------------------------------------------------------------------------------------------


//This is bloom filter 2 that divides the user entered password into bigrams 
void BloomFilter2(string oldPwd, vector<int>& bf) {

    int len = oldPwd.length();
    string char1 = "_";
    int size4 = 1000;

    string s1, s2;
    int noOfBigrams = 0;

    vector<vector<int>> vec;

    //For loop to traverse the password length and create bigrams
    for (int i = 0; i < oldPwd.length(); i++) {
        if (i == 0) {
            //creating the first bigram with char '_'
            string b1 = char1 + oldPwd[i];
            vector<int> v1(size4);
            for (int i = 0; i < v1.size(); i++) {
                v1.at(i) = 0;
            }
            noOfBigrams++;
            func(b1, v1);
            vec.push_back(v1);
        }

        if (i > 0 && i < len) {
            //creating bigrams using previos positions
            s1 = oldPwd[i - 1];
            s2 = oldPwd[i];
            string s = s1 + s2;
            vector <int> v2(size4);
            for (int i = 0; i < v2.size(); i++) {
                v2.at(i) = 0;
            }
            noOfBigrams++;
            func(s, v2);
            vec.push_back(v2);
        }

        if (i == (len - 1)) {
            //creating the last bigram with char '_' 
            string b1 = (oldPwd[len - 1] + char1);
            vector<int> v3(size4);
            for (int i = 0; i < v3.size(); i++)
            {
                v3.at(i) = 0;
            }
            noOfBigrams++;
            func(b1, v3);
            vec.push_back(v3);
        }
    }
    for (int i = 0; i < noOfBigrams; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == 1) {
                bf[j] = 1;
            }
        }
        cout << endl;
    }
}


//-------------------------------------------------------------------------------------------------


//This function creates a new user in the password file, with their UserID, hashed password and salt
void registerUser(vector<bool>f1, int size) {

    vector <string> saltCheck;
    std::string uid, pwd, pwdConfirm;
    fstream check;
    fstream fileopen;
    int count = 0;
    string a, b, c;
    int val = 0;
    string saltedPwd = "";
    string hashedPwd = "";
    string salt = "";
    fstream file1;
    string a1, b1, c1;
    int flag = 0;

    check.open("pwdFile.txt", ios::in | ios::out);
    fileopen.open("usersBloomFilter.txt", ios::in | ios::out);

    cout << "\nEnter a username:\n";
    cin >> uid;
    while (uid.length() < 6) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Username too short! Username length must be atleast 6 characters\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Enter a new username:\n";
        cin >> uid;
    }

    //This part of code checks if a username already exists in the password file
    int value = 0;
    while (value == 0) {

        value = findUserName(uid);
        if (value == 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "\nUsername taken! Enter another username:\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin >> uid;
        }

    }
    cout << "\nEnter a password:\n";
    cin >> pwd;

    //Checking if user entered password exists in the common password file
    val = userCheck(pwd, f1, size);

    //This part of code checks if the password is in the common password file using the function userCheck
    while (true) {
        if (val == 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "\nToo common. Please enter a strong password:\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin >> pwd;
            val = userCheck(pwd, f1, size);
            continue;
        }
        else
            break;
    }

    cout << "\nConfirm Password:\n";
    cin >> pwdConfirm;
    while (pwdConfirm != pwd) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Password does not match. Enter again:\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cin >> pwdConfirm;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "\nPassword Accepted!\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cout << "\nUser Registered!\n";
    check.close();
    firstTimeReg(uid);

    file1.open("PwdFile.txt", ios::in | ios::out);

    while (flag == 0) {
        salt = saltGenerator();
        flag = readSaltString(salt);
    }

    saltedPwd = pwdConfirm + salt;
    hashedPwd = sha256(saltedPwd);

    //Adding users to Password File
    addUserToFile(uid, hashedPwd, salt);

    //Loading the salt vector with all the salt values from password file
    fillSaltVector(saltCheck);

    vector <int> bf2(1000);
    BloomFilter2(pwdConfirm, bf2);
    updatingBloomFilter(uid, bf2);
}


//-------------------------------------------------------------------------------------------------

//This function calculates the jaccard coefficient, using the two bloom filter's true values
double jaccardCoeff(vector<int> B2, string uid) {

    vector<bool> B1;
    fstream jack;
    jack.open("usersBloomFilter.txt", fstream::in | fstream::out);
    string uidFile, hugeNumber;

    while (jack >> uidFile >> hugeNumber) {

        if (uidFile == uid)
        {
            for (int i = 0; i < hugeNumber.length(); i++)
            {
                const char* c = hugeNumber.c_str();
                int temp = c[i] - 48;

                B1.push_back(temp);
            }

        }
    }

    //Calculating truth values of old passwords from the bloom filter 2
    int KB1 = 0;
    for (int i = 0; i < B1.size(); i++) {
        if (B1.at(i) == 1) {
            KB1++;
        }
    }

    //Calculating truth values from bloom filter 2, of the new password

    int KB2 = 0;
    for (int i = 0; i < B2.size(); i++) {
        if (B2.at(i) == 1) {
            KB2++;
        }
    }

    //Calculating common number of true values in both sets (old passwords and new password)
    int YB1B2 = 0;

    for (int i = 0; i < B1.size(); i++) {
        if (B1.at(i) == 1 && B2.at(i) == 1) {
            YB1B2++;
        }

    }

    double jaccardCoefficient = 0;
    double denominator = (double)(KB1 + KB2) - YB1B2;

    jaccardCoefficient = (double)YB1B2 / denominator;

    return jaccardCoefficient;

}

//-------------------------------------------------------------------------------------------------


//This function updates the password file with the user's latest updated password
void updatePwdFile(string updateId, string newPwd) {

    SHA256 sha256;
    fstream file;
    fstream file1;
    string username, hashedPwd, salt;
    string newHash = "";
    string final1 = "";
    file.open("PwdFile.txt", ios::in | ios::out);

    //A new temporary file is created into which the updated password is enetred
    file1.open("copy.txt", ios::in | ios::out);

    while (file >> username >> hashedPwd >> salt) {
        if (username == updateId) {

            newHash = newPwd + salt;
            final1 = sha256(newHash);

            file1 << username << " " << final1 << " " << salt << "\n";
            continue;
        }
        file1 << username << " " << hashedPwd << " " << salt << "\n";
    }

    file.close();
    file1.close();

    file.open("PwdFile.txt", ios::trunc);
    file.close();

    file.open("PwdFile.txt", ios::in | ios::out);
    file1.open("copy.txt", ios::in | ios::out);

    //From the copy.txt file, the required user's password is selected and updated in the password file

    while (file1 >> username >> hashedPwd >> salt) {
        file << username << " " << hashedPwd << " " << salt << "\n";
    }
    remove("copy.txt");
}


//-------------------------------------------------------------------------------------------------


//This prompts user to enter a new password during updating process, checks through the hashes along with the jaccard coefficient. 
//If the jaccard coefficient gives a value greater than threshold, this function is called again for entering a new password
string enterNewPwd(vector<bool>f1, int size, int counters) {

    string password1;

    cout << "Enter new password:\n";
    cin >> password1;

    //Checking if user entered password exists in the common password file
    int val1 = 0;
    val1 = userCheck(password1, f1, size);
    while (true) {
        if (val1 == 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "\nToo common. Please enter a strong password:\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin >> password1;
            val1 = userCheck(password1, f1, size);
            continue;
        }
        else
            break;
    }
    return password1;
}


//-------------------------------------------------------------------------------------------------

int main() {

    srand(time(NULL));

    int size = 44035;
    vector<bool> f1(size);
    string s;
    fstream file;
    int answer;

    for (int i = 0; i < f1.size(); i++) {
        f1.at(i) = 0;
    }

    BloomFilter1(f1, size);


    cout << "*******************************\n\n";
    cout << "Choose your option below:\n\n";
    cout << "1. New User\n\n";
    cout << "2. Update existing password\n\n";
    cout << "Your input: ";
    cin >> answer;
    cout << "\n*******************************\n\n";


    switch (answer) {
    case 1:
       
        registerUser(f1, size);
        break;
    case 2:

        string oldPwd;
        string updateId;
        string updateIdSalt;
        string updateIdHash;
        string newPwd;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Password Expired! Please update NOW!\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        int flag3 = 0;

        //This while loop will keep asking the user for their username if not found in the existing user file
        while (flag3 == 0) {
            cout << "Enter username: ";
            cin >> updateId;
            flag3 = readFile(updateId, updateIdHash, updateIdSalt);
        }

        //Asks user to enter old password to get the correct hashed password and then prompts to enter new password
        cout << "Enter your old password:\n";
        cin >> oldPwd;
        string hashedOldPwd = sha256(oldPwd + updateIdSalt);


        int flag2 = 0;
        //This code prompts user to enter the password till the enter the correct old password
        while (flag2 == 0) {

            if (hashedOldPwd.compare(updateIdHash) != 0) {
                flag2 = 0;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "Wrong password. Please enter the correct old password:\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cin >> oldPwd;
                hashedOldPwd = sha256(oldPwd + updateIdSalt);
            }
            else {
                flag2 = 1;
                break;
            }
        }

        std::vector <string> f2;
        vector<int> bfNewPassword(1000);

        double JC = 0;
        double threshold = 0.25;
        string password1 = "";
        int counters = 0;

        //This code will ask user to enter a password until a password below threshold is entered
        do {
            password1 = enterNewPwd(f1, size, counters);
            counters++;
            BloomFilter2(password1, bfNewPassword);
            JC = jaccardCoeff(bfNewPassword, updateId);

        } while (JC > threshold);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "Password Accepted\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


        //This calls the function to update the bloom filter 2 with the new password and the user password file with the latest password
        updatingBloomFilter(updateId, bfNewPassword);
        updatePwdFile(updateId, password1);

        break;
    }


}
