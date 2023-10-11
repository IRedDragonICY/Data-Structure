#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#define MAX 100

void errorInput(){
    std::cout << "Input tidak valid" << std::endl;
}

struct Data {
    std::string province;
    std::string city;
    std::string nik;
    std::string name;
    struct Born {
        std::string place;
        int date;
        int month;
        int year;
    } born;

    bool gender;
    std::string bloodType;

    struct Address {
        std::string address;
        int neighborhoodAssociation;
        int communityAssociation;
        std::string district;
        std::string subDistrict; 
   } address;
    std::string religion;
    std::string isMaried;
    std::string job; 
    std::string citizenship; 
    std::string validUntil;
    struct Created {
        int date;
        int month;
        int year;
    } created;
};

class KTP {
private:
    Data data[MAX];
    int count = 0;

public:
    bool validateProvince(std::string province) {
        return province.length() <= 50;
    }

    bool validateCity(std::string city) {
        return city.length() <= 50;
    }
    

    bool validateNik(std::string nik) {
        return nik.length() == 16;
    }
    bool validateName(std::string name) {
        return name.length() <= 50;
    }
    bool validateBornPlace(std::string bornPlace) {
        return bornPlace.length() <= 20;
    }
    
    bool validateDate(int date) {
        return date >= 1 && date <= 31;
    }
    
    bool validateMonth(int month) {
        return month >= 1 && month <= 12;
    }
    
    bool validateYear(int year) {
        return year >= 1900 && year <= 2020;
    }

    bool validateGender(int gender) {
        return gender == 0 || gender == 1;
    }

    bool validateBloodType(std::string bloodType) {
        return bloodType == "A" || bloodType == "B" || bloodType == "AB" || bloodType == "O";
    }
    bool validateAddress(std::string address) {
        return address.length() <= 100;
    }

    bool validateNeighborhoodAssociation(int neighborhoodAssociation) {
        return neighborhoodAssociation >= 0 && neighborhoodAssociation <= 999;
    }
    
    bool validateCommunityAssociation(int communityAssociation) {
        return communityAssociation >= 0 && communityAssociation <= 999;
    }

    bool validateSubDistrict(std::string subDistrict) {
        return subDistrict.length() <= 20;
    }
    
    bool validateDistrict(std::string district) {
        return district.length() <= 20;
    }

    bool validateReligion(std::string religion) {
        return religion == "Islam" || religion == "Kristen" || religion == "Katolik" || religion == "Hindu" || religion == "Buddha" || religion == "Konghucu";
    }

    bool validateIsMaried(std::string isMaried) {
        return isMaried == "Kawin" || isMaried == "Belum Kawin";
    }
    bool validateJob(std::string job) {
        return job.length() <= 30;
    }


    void input() {
        do {
            std::cout << "Provinsi: ";
            std::getline(std::cin, data[count].province);
            if (!validateProvince(data[count].province)) {
                errorInput();
            }
        } while (!validateProvince(data[count].province));
        do {
            std::cout << "Kota: ";
            std::getline(std::cin, data[count].city);
            if (!validateCity(data[count].city)) {
                errorInput();
            }
        } while (!validateCity(data[count].city));
        do {
            std::cout << "NIK: ";
            std::getline(std::cin, data[count].nik);
            if (!validateNik(data[count].nik)) {
                errorInput();
            }
        } while (!validateNik(data[count].nik));
        do {
            std::cout << "Nama: ";
            std::getline(std::cin, data[count].name);
            if (!validateName(data[count].name)) {
                errorInput();
            }
        } while (!validateName(data[count].name));
        do {
            std::cout << "Tempat Lahir: ";
            std::getline(std::cin, data[count].born.place);
            if (!validateBornPlace(data[count].born.place)) {
                errorInput();
            }
        } while (!validateBornPlace(data[count].born.place));
        do {
            std::cout << "Tanggal Lahir: ";
            std::cin >> data[count].born.date;
            if (!validateDate(data[count].born.date)) {
                errorInput();
            }
        } while (!validateDate(data[count].born.date));
        do {
            std::cout << "Bulan Lahir: ";
            std::cin >> data[count].born.month;
            if (!validateMonth(data[count].born.month)) {
                errorInput();
            }
        } while (!validateMonth(data[count].born.month));
        do {
            std::cout << "Tahun Lahir: ";
            std::cin >> data[count].born.year;
            if (!validateYear(data[count].born.year)) {
                errorInput();
            }
        } while (!validateYear(data[count].born.year));
        // jenis kelamin
        do {
        std::cout <<"Jenis kelamin (0=laki-laki, 1=perempuan): ";
        std::cin >> data[count].gender;
        if (!validateGender(data[count].gender)) {
            errorInput();
        }
        } while (!validateGender(data[count].gender));
        
        std::cin.ignore();
        
        do {
            std::cout << "Golongan Darah: ";
            getline(std::cin, data[count].bloodType);
            if (!validateBloodType(data[count].bloodType)) {
                errorInput();
            }
        } while (!validateBloodType(data[count].bloodType));
        do {
            std::cout << "Alamat: ";
            getline(std::cin, data[count].address.address);
            if (!validateAddress(data[count].address.address)) {
                errorInput();
            }
        } while (!validateAddress(data[count].address.address));
        do {
            std::cout << "RT: ";
            std::cin >> data[count].address.neighborhoodAssociation;
            if (!validateNeighborhoodAssociation(data[count].address.neighborhoodAssociation)) {
                errorInput();
            }
        } while (!validateNeighborhoodAssociation(data[count].address.neighborhoodAssociation));
        do {
            std::cout << "RW: ";
            std::cin >> data[count].address.communityAssociation;
            if (!validateCommunityAssociation(data[count].address.communityAssociation)) {
                errorInput();
            }
        } while (!validateCommunityAssociation(data[count].address.communityAssociation));
        std::cin.ignore();
        do {
            std::cout << "Kel/Desa: ";
            getline(std::cin, data[count].address.subDistrict);
            if (!validateSubDistrict(data[count].address.subDistrict)) {
                errorInput();
            }
        } while (!validateSubDistrict(data[count].address.subDistrict));
        do {
            std::cout << "Kecamatan: ";
            getline(std::cin, data[count].address.district);
            if (!validateDistrict(data[count].address.district)) {
                errorInput();
            }
        } while (!validateDistrict(data[count].address.district));
        do {
            std::cout << "Agama (Islam, Kristen, Katolik, Hindu, Buddha, Konghucu): ";
            getline(std::cin, data[count].religion);
            if (!validateReligion(data[count].religion)) {
                errorInput();
            }
        } while (!validateReligion(data[count].religion));
        
        do {
            std::cout << "Status Perkawinan (Kawin, Belum Kawin): ";
            getline(std::cin, data[count].isMaried);
            if (!validateIsMaried(data[count].isMaried)) {
                errorInput();
            }
        } while (!validateIsMaried(data[count].isMaried));
        do {
            std::cout << "Pekerjaan: ";
            getline(std::cin, data[count].job);
            if (!validateJob(data[count].job)) {
                errorInput();
            }
        } while (!validateJob(data[count].job));
        data[count].citizenship = "WNI";
        data[count].validUntil = "SEUMUR HIDUP";
        time_t now = time(0);
        tm *ltm = localtime(&now);
        data[count].created.date = ltm->tm_mday;
        data[count].created.month = ltm->tm_mon + 1;
        data[count].created.year = ltm->tm_year + 1900;
        for (int i = 0; i < data[count].religion.length(); i++) {
            data[count].religion[i] = toupper(data[count].religion[i]);
        }
        for (int i = 0; i < data[count].isMaried.length(); i++) {
            data[count].isMaried[i] = toupper(data[count].isMaried[i]);
        }
        std::ofstream file;
        file.open("data.txt", std::ios::app);
        file << std::endl;
        file << "Provinsi          : " << data[count].province << std::endl;
        file << "Kota              : " << data[count].city << std::endl;
        file << "NIK               : " << data[count].nik << std::endl;
        file << "Nama              : " << data[count].name << std::endl;
        file << "Tempat/Tgl Lahir  : " << data[count].born.place << ", " << std::setfill('0') << std::setw(2) << data[count].born.date << "-" << std::setfill('0') << std::setw(2) << data[count].born.month << "-" << data[count].born.year << std::endl;
        file << "Jenis Kelamin     : " << (data[count].gender == 0 ? "LAKI-LAKI" : "PEREMPUAN") << std::endl;
        file << "Gol.Darah         : " << data[count].bloodType << std::endl;
        file << "Alamat            : " << data[count].address.address << std::endl;
        file << "       RT/RW      : " << std::setfill('0') << std::setw(3) << data[count].address.neighborhoodAssociation << "/" << std::setfill('0') << std::setw(3) << data[count].address.communityAssociation << std::endl;
        file << "       Kel/Desa   : " << data[count].address.subDistrict << std::endl;
        file << "       Kecamatan  : " << data[count].address.district << std::endl;
        file << "Agama             : " << data[count].religion << std::endl;
        file << "Status Perkawinan : " << data[count].isMaried << std::endl;
        file << "Pekerjaan         : " << data[count].job << std::endl;
        file << "Kewarganegaraan   : " << data[count].citizenship << std::endl;
        file << "Berlaku Hingga    : " << data[count].validUntil << std::endl;
        file << "Dibuat            : " << std::setfill('0') << std::setw(2) << data[count].created.date << "-" << std::setfill('0') << std::setw(2) << data[count].created.month << "-" << data[count].created.year << std::endl;
        file << "========================================================" << std::endl;
        file.close();
        count++;
    }

    void output() {
        std::cout << "===========================================================================================" << std::endl;
        std::cout << "                                      KARTU TANDA PENDUDUK" << std::endl;
      std::cout << "===========================================================================================" << std::endl;
        for (int i = 0; i < count; i++) {
            int provinceLength = data[i].province.length();
            int cityLength = data[i].city.length();
            int maxLength = provinceLength > cityLength ? provinceLength : cityLength;
            for (int j = 0; j < (maxLength - provinceLength) / 2; j++) {
                std::cout << " ";
            }
            std::cout << "                      " << data[i].province << std::endl;

            for (int j = 0; j < (maxLength - cityLength) / 2; j++) {
                std::cout << " ";
            }
            std::cout << "                      " << data[i].city << std::endl;
            std::cout << "NIK               : " << data[i].nik << std::endl;
            std::cout << "Nama              : " << data[i].name << std::endl;
            std::cout << "Tempat/Tgl Lahir  : " << data[i].born.place << ", " << std::setfill('0') << std::setw(2) << data[i].born.date << "-" << std::setfill('0') << std::setw(2) << data[i].born.month << "-" << data[i].born.year << std::endl;
            std::cout << "Jenis Kelamin     : " << (data[i].gender ? "LAKI-LAKI" : "PEREMPUAN");
            std::cout << std::setfill(' ') << std::setw(35 - data[i].bloodType.length()) << "Gol.Darah : " << data[i].bloodType << std::endl;
            std::cout << "Alamat            : " << data[i].address.address << std::endl;
            std::cout << "RT/RW             : " << std::setfill('0') << std::setw(3) << data[i].address.neighborhoodAssociation << "/" << std::setfill('0') << std::setw(3) << data[i].address.communityAssociation << std::endl;
            std::cout << "Kel/Desa          : " << data[i].address.subDistrict << std::endl;
            std::cout << "Kecamatan         : " << data[i].address.district << std::endl;
            std::cout << "Agama             : " << data[i].religion << std::endl;
            std::cout << "Status Perkawinan : " << data[i].isMaried;
            std::cout << std::setfill(' ') << std::setw(47) << "Foto.jpg" << std::endl;
            std::cout << "Pekerjaan         : " << data[i].job << std::endl;
            std::cout << "Kewarganegaraan   : " << data[i].citizenship;
            std::cout << std::setfill(' ') << std::setw(45 - std::to_string(data[i].created.date).length()) << " " << std::setfill('0') << std::setw(2) << data[i].created.date << "-" << std::setfill('0') << std::setw(2) << data[i].created.month << "-" << data[i].created.year << std::endl;
            std::cout << "Berlaku Hingga    : " << data[i].validUntil;
            std::cout << std::setfill(' ') << std::setw(40) << "TTD" << std::endl;

            std::cout << "===========================================================================================" << std::endl;
        }
    }
    void initialize(){
    std::ifstream file;
    file.open("data.txt");
    
    std::string line;
    count = 0;
    while (std::getline(file, line)) {
        if (line.find("NIK") != std::string::npos) {
            count++;
        }
    }

    std::cout << "Banyak KTP: " << count << std::endl;
    file.clear();file.seekg(0, std::ios::beg);
    
    int i = 0; 
    while(std::getline(file,line)){
        if (line.find("Provinsi") != std::string::npos) data[i].province = line.substr(line.find(":") + 2);
        else if (line.find("Kota/Kabupaten") != std::string::npos) data[i].city = line.substr(line.find(":") + 2);
        else if (line.find("NIK") != std::string::npos){
            data[i].nik = line.substr(line.find(":") + 2);
        }
        else if (line.find("NIK") != std::string::npos){
            data[i].nik = line.substr(line.find(":") + 2);
        }
        else if (line.find("Nama") != std::string::npos) data[i].name = line.substr(line.find(":") + 2);
        else if (line.find("Tempat/Tgl Lahir") != std::string::npos) {
            data[i].born.place = line.substr(line.find(":") + 2, line.find(",") - line.find(":") - 2);
            data[i].born.date = std::stoi(line.substr(line.find(",") + 2, 2));
            data[i].born.month = std::stoi(line.substr(line.find("-") + 1, 2));
            data[i].born.year = std::stoi(line.substr(line.find_last_of("-") + 1));
        }
        else if (line.find("Jenis Kelamin") != std::string::npos){
            data[i].gender = line.substr(line.find(":") + 2) == "LAKI-LAKI" ? 0 : 1;
        }
        else if (line.find("Gol.Darah") != std::string::npos) data[i].bloodType = line.substr(line.find(":") + 2);
        else if (line.find("Alamat") != std::string::npos) data[i].address.address= line.substr(line.find(":") + 2);
        else if (line.find("RT/RW") != std::string::npos) {
            data[i].address.neighborhoodAssociation = std::stoi(line.substr(line.find(":") + 2, 3));
            data[i].address.communityAssociation = std::stoi(line.substr(line.find_last_of("/") + 1));
        }
        else if (line.find("Kel/Desa") != std::string::npos) data[i].address.subDistrict = line.substr(line.find(":") + 2);
        else if (line.find("Kecamatan") != std::string::npos) data[i].address.district = line.substr(line.find(":") + 2);
        else if (line.find("Agama") != std::string::npos) data[i].religion = line.substr(line.find(":") + 2);
        else if (line.find("Status Perkawinan") != std::string::npos) data[i].isMaried = line.substr(line.find(":") + 2);
        else if (line.find("Pekerjaan") != std::string::npos) data[i].job = line.substr(line.find(":") + 2);
        else if (line.find("Kewarganegaraan") != std::string::npos) data[i].citizenship = line.substr(line.find(":") + 2);
        else if (line.find("Berlaku Hingga") != std::string::npos) data[i].validUntil = line.substr(line.find(":") + 2);
        else if (line.find("Dibuat") != std::string::npos) {
            data[i].created.date = std::stoi(line.substr(line.find(":") + 2, 2));
            data[i].created.month = std::stoi(line.substr(line.find("-") + 1, 2));
            data[i].created.year = std::stoi(line.substr(line.find_last_of("-") + 1));
        }
        else if (line.find("========================================================") != std::string::npos) i++;
    }
    file.close();
}

};



int main() {
    KTP ktp;
    ktp.initialize();
    int choice;
    while(true){
        std::cout << "Menu: " << std::endl;
        std::cout << "1. Input Data" << std::endl;
        std::cout << "2. Tampilkan Data" << std::endl;
        std::cout << "3. Keluar" << std::endl;
        std::cout << "Pilihan: ";
        std::cin >> choice;
        system("cls");
        std::cin.ignore();
        switch (choice) {
            case 1:
                ktp.input();
                std::cout << "Data berhasil diinput" << std::endl;
                break;
            case 2:
                ktp.output();
                break;
            case 3:
                return 0;
            default:
                std::cout << "Pilihan tidak valid" << std::endl;
                break;
        }
        system("pause");
        system("cls");
    }
}