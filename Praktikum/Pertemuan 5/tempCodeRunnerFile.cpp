#include <bits/stdc++.h>
using namespace std;

void errorInput(){
    cout << "Input tidak valid" << endl;
}

struct Data {
    string province;
    string city;
    string nik;
    string name;
    struct Born {
        string place;
        int date;
        int month;
        int year;
    } born;

    bool gender;
    string bloodType;

    struct Address {
        string address;
        int neighborhoodAssociation;
        int communityAssociation;
        string district;
        string subDistrict; 
   } address;
    string religion;
    string isMaried;
    string job; 
    string citizenship; 
    string validUntil;
    struct Created {
        int date;
        int month;
        int year;
    } created;
};

struct Node{
    Data data;
    Node* next;
    Node* prev;
};

class KTP {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:    

    bool validateProvince(string province) {
        return province.length() <= 50;
    }

    bool validateCity(string city) {
        return city.length() <= 50;
    }
    

    bool validateNik(string nik) {
        return nik.length() == 16;
    }
    bool validateName(string name) {
        return name.length() <= 50;
    }
    bool validateBornPlace(string bornPlace) {
        return bornPlace.length() <= 20;
    }
    
    bool validateDate(int date) {
        return date >= 1 && date <= 31;
    }
    
    bool validateMonth(int month) {
        return month >= 1 && month <= 12;
    }
    
    bool validateYear(int year) {
        return year >= 1900 && year <= 2023;
    }

    bool validateGender(int gender) {
        return gender == 0 || gender == 1;
    }

    bool validateBloodType(string bloodType) {
        return bloodType == "A" || bloodType == "B" || bloodType == "AB" || bloodType == "O";
    }
    bool validateAddress(string address) {
        return address.length() <= 100;
    }

    bool validateNeighborhoodAssociation(int neighborhoodAssociation) {
        return neighborhoodAssociation >= 0 && neighborhoodAssociation <= 999;
    }
    
    bool validateCommunityAssociation(int communityAssociation) {
        return communityAssociation >= 0 && communityAssociation <= 999;
    }

    bool validateSubDistrict(string subDistrict) {
        return subDistrict.length() <= 20;
    }
    
    bool validateDistrict(string district) {
        return district.length() <= 20;
    }

    bool validateReligion(string religion) {
        return religion == "Islam" || religion == "Kristen" || religion == "Katolik" || religion == "Hindu" || religion == "Buddha" || religion == "Konghucu";
    }

    bool validateIsMaried(string isMaried) {
        return isMaried == "Kawin" || isMaried == "Belum Kawin";
    }
    bool validateJob(string job) {
        return job.length() <= 30;
    }


    void input() {
        Node* newNode = new Node;
        do {
            cout << "Provinsi: ";
            getline(cin, newNode->data.province);
            if (!validateProvince(newNode->data.province)) {
                errorInput();
            }
        } while (!validateProvince(newNode->data.province));
        do {
            cout << "Kota: ";
            getline(cin, newNode->data.city);
            if (!validateCity(newNode->data.city)) {
                errorInput();
            }
        } while (!validateCity(newNode->data.city));
        do {
            cout << "NIK: ";
            getline(cin, newNode->data.nik);
            if (!validateNik(newNode->data.nik)) {
                errorInput();
            }
        } while (!validateNik(newNode->data.nik));
        do {
            cout << "Nama: ";
            getline(cin, newNode->data.name);
            if (!validateName(newNode->data.name)) {
                errorInput();
            }
        } while (!validateName(newNode->data.name));
        do {
            cout << "Tempat Lahir: ";
            getline(cin, newNode->data.born.place);
            if (!validateBornPlace(newNode->data.born.place)) {
                errorInput();
            }
        } while (!validateBornPlace(newNode->data.born.place));
        do {
            cout << "Tanggal Lahir: ";
            cin >> newNode->data.born.date;
            if (!validateDate(newNode->data.born.date)) {
                errorInput();
            }
        } while (!validateDate(newNode->data.born.date));
        do {
            cout << "Bulan Lahir: ";
            cin >> newNode->data.born.month;
            if (!validateMonth(newNode->data.born.month)) {
                errorInput();
            }
        } while (!validateMonth(newNode->data.born.month));
        do {
            cout << "Tahun Lahir: ";
            cin >> newNode->data.born.year;
            if (!validateYear(newNode->data.born.year)) {
                errorInput();
            }
        } while (!validateYear(newNode->data.born.year));

        do {
        cout <<"Jenis kelamin (0=laki-laki, 1=perempuan): ";
        cin >> newNode->data.gender;
        if (!validateGender(newNode->data.gender)) {
            errorInput();
        }
        } while (!validateGender(newNode->data.gender));
        
        cin.ignore();
        
        do {
            cout << "Golongan Darah: ";
            getline(cin, newNode->data.bloodType);
            if (!validateBloodType(newNode->data.bloodType)) {
                errorInput();
            }
        } while (!validateBloodType(newNode->data.bloodType));
        do {
            cout << "Alamat: ";
            getline(cin, newNode->data.address.address);
            if (!validateAddress(newNode->data.address.address)) {
                errorInput();
            }
        } while (!validateAddress(newNode->data.address.address));
        do {
            cout << "RT: ";
            cin >> newNode->data.address.neighborhoodAssociation;
            if (!validateNeighborhoodAssociation(newNode->data.address.neighborhoodAssociation)) {
                errorInput();
            }
        } while (!validateNeighborhoodAssociation(newNode->data.address.neighborhoodAssociation));
        do {
            cout << "RW: ";
            cin >> newNode->data.address.communityAssociation;
            if (!validateCommunityAssociation(newNode->data.address.communityAssociation)) {
                errorInput();
            }
        } while (!validateCommunityAssociation(newNode->data.address.communityAssociation));
        cin.ignore();
        do {
            cout << "Kel/Desa: ";
            getline(cin, newNode->data.address.subDistrict);
            if (!validateSubDistrict(newNode->data.address.subDistrict)) {
                errorInput();
            }
        } while (!validateSubDistrict(newNode->data.address.subDistrict));
        do {
            cout << "Kecamatan: ";
            getline(cin, newNode->data.address.district);
            if (!validateDistrict(newNode->data.address.district)) {
                errorInput();
            }
        } while (!validateDistrict(newNode->data.address.district));
        do {
            cout << "Agama (Islam, Kristen, Katolik, Hindu, Buddha, Konghucu): ";
            getline(cin, newNode->data.religion);
            if (!validateReligion(newNode->data.religion)) {
                errorInput();
            }
        } while (!validateReligion(newNode->data.religion));
        
        do {
            cout << "Status Perkawinan (Kawin, Belum Kawin): ";
            getline(cin, newNode->data.isMaried);
            if (!validateIsMaried(newNode->data.isMaried)) {
                errorInput();
            }
        } while (!validateIsMaried(newNode->data.isMaried));
        do {
            cout << "Pekerjaan: ";
            getline(cin, newNode->data.job);
            if (!validateJob(newNode->data.job)) {
                errorInput();
            }
        } while (!validateJob(newNode->data.job));
        newNode->data.citizenship = "WNI";
        newNode->data.validUntil = "SEUMUR HIDUP";
        time_t now = time(0);
        tm *ltm = localtime(&now);
        newNode->data.created.date = ltm->tm_mday;
        newNode->data.created.month = ltm->tm_mon + 1;
        newNode->data.created.year = ltm->tm_year + 1900;
        for (int i = 0; i < newNode->data.religion.length(); i++) {
            newNode->data.religion[i] = toupper(newNode->data.religion[i]);
        }
        for (int i = 0; i < newNode->data.isMaried.length(); i++) {
            newNode->data.isMaried[i] = toupper(newNode->data.isMaried[i]);
        }
        ofstream file;
        file.open("data.txt", ios::app);
        file << "Provinsi          : " << newNode->data.province << endl;
        file << "Kota/Kabupaten    : " << newNode->data.city << endl;
        file << "NIK               : " << newNode->data.nik << endl;
        file << "Nama              : " << newNode->data.name << endl;
        file << "Tempat/Tgl Lahir  : " << newNode->data.born.place << ", " << setfill('0') << setw(2) << newNode->data.born.date << "-" << setfill('0') << setw(2) << newNode->data.born.month << "-" << newNode->data.born.year << endl;
        file << "Jenis Kelamin     : " << (newNode->data.gender == 0 ? "LAKI-LAKI" : "PEREMPUAN") << endl;
        file << "Gol.Darah         : " << newNode->data.bloodType << endl;
        file << "Alamat            : " << newNode->data.address.address << endl;
        file << "       RT/RW      : " << setfill('0') << setw(3) << newNode->data.address.neighborhoodAssociation << "/" << setfill('0') << setw(3) << newNode->data.address.communityAssociation << endl;
        file << "       Kel/Desa   : " << newNode->data.address.subDistrict << endl;
        file << "       Kecamatan  : " << newNode->data.address.district << endl;
        file << "Agama             : " << newNode->data.religion << endl;
        file << "Status Perkawinan : " << newNode->data.isMaried << endl;
        file << "Pekerjaan         : " << newNode->data.job << endl;
        file << "Kewarganegaraan   : " << newNode->data.citizenship << endl;
        file << "Berlaku Hingga    : " << newNode->data.validUntil << endl;
        file << "Dibuat            : " << setfill('0') << setw(2) << newNode->data.created.date << "-" << setfill('0') << setw(2) << newNode->data.created.month << "-" << newNode->data.created.year << endl;
        file << "========================================================" << endl;
        file.close();
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    void output() {
        cout << "===========================================================================================" << endl;
        cout << "                                      KARTU TANDA PENDUDUK" << endl;
        cout << "===========================================================================================" << endl;
        Node* current = head;
        while (current != nullptr) {
            int provinceLength = current->data.province.length();
            int cityLength = current->data.city.length();
            int maxLength = provinceLength > cityLength ? provinceLength : cityLength;
            for (int j = 0; j < (maxLength - provinceLength) / 2; j++) {
                cout << " ";
            }
            cout << "                      " << current->data.province << endl;
            for (int j = 0; j < (maxLength - cityLength) / 2; j++) {
                cout << " ";
            }
            
            cout << "                      " << current->data.city << endl;
            cout << "NIK               : " << current->data.nik << endl;
            cout << "Nama              : " << current->data.name << endl;
            cout << "Tempat/Tgl Lahir  : " << current->data.born.place << ", " << setfill('0') << setw(2) << current->data.born.date << "-" << setfill('0') << setw(2) << current->data.born.month << "-" << current->data.born.year << endl;
            cout << "Jenis Kelamin     : " << (current->data.gender ? "LAKI-LAKI" : "PEREMPUAN");
            cout << setfill(' ') << setw(35 - current->data.bloodType.length()) << "Gol.Darah : " << current->data.bloodType << endl;
            cout << "Alamat            : " << current->data.address.address << endl;
            cout << "RT/RW             : " << setfill('0') << setw(3) << current->data.address.neighborhoodAssociation << "/" << setfill('0') << setw(3) << current->data.address.communityAssociation << endl;
            cout << "Kel/Desa          : " << current->data.address.subDistrict << endl;
            cout << "Kecamatan         : " << current->data.address.district << endl;
            cout << "Agama             : " << current->data.religion << endl;
            cout << "Status Perkawinan : " << current->data.isMaried;
            cout << setfill(' ') << setw(47) << "Foto.jpg" << endl;
            cout << "Pekerjaan         : " << current->data.job << endl;
            cout << "Kewarganegaraan   : " << current->data.citizenship;
            cout << setfill(' ') << setw(45 - to_string(current->data.created.date).length()) << " " << setfill('0') << setw(2) << current->data.created.date << "-" << setfill('0') << setw(2) << current->data.created.month << "-" << current->data.created.year << endl;
            cout << "Berlaku Hingga    : " << current->data.validUntil;
            cout << setfill(' ') << setw(40) << "TTD" << endl;

            cout << "===========================================================================================" << endl;
            current = current->next;
        }
    }

    void initialize() {
        ifstream file;
        file.open("data.txt");

        string line;
        count = 0;
        while (getline(file, line)) {
            if (line.find("NIK") != string::npos) {
                count++;
            }
        }

        cout << "Banyak KTP: " << count << endl;
        file.clear(); file.seekg(0, ios::beg);

        this->head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < count; i++) {
            Data newData;

            while (getline(file, line)) {
                if (line.find("Provinsi") != string::npos) newData.province = line.substr(line.find(":") + 2);
                else if (line.find("Kota/Kabupaten") != string::npos) newData.city = line.substr(line.find(":") + 2);
                else if (line.find("NIK") != string::npos) newData.nik = line.substr(line.find(":") + 2);
                else if (line.find("Nama") != string::npos) newData.name = line.substr(line.find(":") + 2);
                else if (line.find("Tempat/Tgl Lahir") != string::npos) {
                    newData.born.place = line.substr(line.find(":") + 2, line.find(",") - line.find(":") - 2);
                    newData.born.date = stoi(line.substr(line.find(",") + 2, 2));
                    newData.born.month = stoi(line.substr(line.find("-") + 1, 2));
                    newData.born.year = stoi(line.substr(line.find_last_of("-") + 1));
                }
                else if (line.find("Jenis Kelamin") != string::npos) {
                    newData.gender = line.substr(line.find(":") + 2) == "LAKI-LAKI" ? 0 : 1;
                }
                else if (line.find("Gol.Darah") != string::npos) newData.bloodType = line.substr(line.find(":") + 2);
                else if (line.find("Alamat") != string::npos) newData.address.address = line.substr(line.find(":") + 2);
                else if (line.find("RT/RW") != string::npos) {
                    newData.address.neighborhoodAssociation = stoi(line.substr(line.find(":") + 2, 3));
                    newData.address.communityAssociation = stoi(line.substr(line.find_last_of("/") + 1));
                }
                else if (line.find("Kel/Desa") != string::npos) newData.address.subDistrict = line.substr(line.find(":") + 2);
                else if (line.find("Kecamatan") != string::npos) newData.address.district = line.substr(line.find(":") + 2);
                else if (line.find("Agama") != string::npos) newData.religion = line.substr(line.find(":") + 2);
                else if (line.find("Status Perkawinan") != string::npos) newData.isMaried = line.substr(line.find(":") + 2);
                else if (line.find("Pekerjaan") != string::npos) newData.job = line.substr(line.find(":") + 2);
                else if (line.find("Kewarganegaraan") != string::npos) newData.citizenship = line.substr(line.find(":") + 2);
                else if (line.find("Berlaku Hingga") != string::npos) newData.validUntil = line.substr(line.find(":") + 2);
                else if (line.find("Dibuat") != string::npos) {
                    newData.created.date = stoi(line.substr(line.find(":") + 2, 2));
                    newData.created.month = stoi(line.substr(line.find("-") + 1, 2));
                    newData.created.year = stoi(line.substr(line.find_last_of("-") + 1));
                }
                else if (line.find("========================================================") != string::npos) {
                    Node* newNode = new Node{ newData, nullptr, tail };
                    if (head == nullptr) {
                        head = newNode;
                        tail = newNode;
                    }
                    else {
                        tail->next = newNode;
                        tail = newNode;
                    }
                    break;
                }
            }
        }

        file.close();
    }

    void delAtHead(){
        if(head == nullptr){
            cout << "Data kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        cout << "Data berhasil dihapus" << endl;
        count--;
        
        ifstream file;
        file.open("data.txt");
        ofstream tempFile;
        tempFile.open("temp.txt");
        string line;
        int lineCount = 0;
        while (getline(file, line)) {
            if (line.find("NIK") != string::npos) {
                lineCount++;
            }
            if (lineCount != 1) {
                tempFile << line << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }

    void delAtTail(){
        if(head == nullptr){
            cout << "Linked list kosong" << endl;
            return;
        }
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        if(current->prev == nullptr){
            head = nullptr;
        } else {
            current->prev->next = nullptr;
        }
        delete current;
        cout << "Data berhasil dihapus" << endl;
        count--;
        
        ifstream file;
        file.open("data.txt");
        ofstream tempFile;
        tempFile.open("temp.txt");
        string line;
        int lineCount = 0;
        while (getline(file, line)) {
            if (line.find("NIK") != string::npos) {
                lineCount++;
            }
            if (lineCount != count + 1) {
                tempFile << line << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }
};

int main() {
    KTP ktp;
    int choice;
    while(true){
        ktp.initialize();
        cout << "Menu: " << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Delete Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;
        system("cls");
        cin.ignore();
        switch (choice) {
            case 1:
                ktp.input();
                cout << "Data berhasil diinput" << endl;
                break;
            case 2:
                ktp.output();
                break;
            case 3:
                while(true){
                    system("cls");
                cout << "Menu: " << endl;
                cout << "1. Delete data di depan" << endl;
                cout << "2. Delete data di belakang" << endl;
                cout << "3. Kembali" << endl;
                cout << "Pilihan: ";
                cin >> choice;
                    switch(choice){
                        case 1:
                            ktp.delAtHead();
                            break;
                        case 2:
                            ktp.delAtTail();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Pilihan tidak valid" << endl;
                            system("pause");
                            break;
                    }
                    break;
                }
             
                break;
            case 4:
                return EXIT_SUCCESS;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
}