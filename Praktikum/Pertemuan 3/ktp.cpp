#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>

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
    Data *data = nullptr;
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
        Data *newData = new Data[count + 1];
        do {
            std::cout << "Provinsi: ";
            std::getline(std::cin, newData[count].province);
            if (!validateProvince(newData[count].province)) {
                errorInput();
            }
        } while (!validateProvince(newData[count].province));
        do {
            std::cout << "Kota: ";
            std::getline(std::cin, newData[count].city);
            if (!validateCity(newData[count].city)) {
                errorInput();
            }
        } while (!validateCity(newData[count].city));
        do {
            std::cout << "NIK: ";
            std::getline(std::cin, newData[count].nik);
            if (!validateNik(newData[count].nik)) {
                errorInput();
            }
        } while (!validateNik(newData[count].nik));
        do {
            std::cout << "Nama: ";
            std::getline(std::cin, newData[count].name);
            if (!validateName(newData[count].name)) {
                errorInput();
            }
        } while (!validateName(newData[count].name));
        do {
            std::cout << "Tempat Lahir: ";
            std::getline(std::cin, newData[count].born.place);
            if (!validateBornPlace(newData[count].born.place)) {
                errorInput();
            }
        } while (!validateBornPlace(newData[count].born.place));
        do {
            std::cout << "Tanggal Lahir: ";
            std::cin >> newData[count].born.date;
            if (!validateDate(newData[count].born.date)) {
                errorInput();
            }
        } while (!validateDate(newData[count].born.date));
        do {
            std::cout << "Bulan Lahir: ";
            std::cin >> newData[count].born.month;
            if (!validateMonth(newData[count].born.month)) {
                errorInput();
            }
        } while (!validateMonth(newData[count].born.month));
        do {
            std::cout << "Tahun Lahir: ";
            std::cin >> newData[count].born.year;
            if (!validateYear(newData[count].born.year)) {
                errorInput();
            }
        } while (!validateYear(newData[count].born.year));

        do {
        std::cout <<"Jenis kelamin (0=laki-laki, 1=perempuan): ";
        std::cin >> newData[count].gender;
        if (!validateGender(newData[count].gender)) {
            errorInput();
        }
        } while (!validateGender(newData[count].gender));
        
        std::cin.ignore();
        
        do {
            std::cout << "Golongan Darah: ";
            getline(std::cin, newData[count].bloodType);
            if (!validateBloodType(newData[count].bloodType)) {
                errorInput();
            }
        } while (!validateBloodType(newData[count].bloodType));
        do {
            std::cout << "Alamat: ";
            getline(std::cin, newData[count].address.address);
            if (!validateAddress(newData[count].address.address)) {
                errorInput();
            }
        } while (!validateAddress(newData[count].address.address));
        do {
            std::cout << "RT: ";
            std::cin >> newData[count].address.neighborhoodAssociation;
            if (!validateNeighborhoodAssociation(newData[count].address.neighborhoodAssociation)) {
                errorInput();
            }
        } while (!validateNeighborhoodAssociation(newData[count].address.neighborhoodAssociation));
        do {
            std::cout << "RW: ";
            std::cin >> newData[count].address.communityAssociation;
            if (!validateCommunityAssociation(newData[count].address.communityAssociation)) {
                errorInput();
            }
        } while (!validateCommunityAssociation(newData[count].address.communityAssociation));
        std::cin.ignore();
        do {
            std::cout << "Kel/Desa: ";
            getline(std::cin, newData[count].address.subDistrict);
            if (!validateSubDistrict(newData[count].address.subDistrict)) {
                errorInput();
            }
        } while (!validateSubDistrict(newData[count].address.subDistrict));
        do {
            std::cout << "Kecamatan: ";
            getline(std::cin, newData[count].address.district);
            if (!validateDistrict(newData[count].address.district)) {
                errorInput();
            }
        } while (!validateDistrict(newData[count].address.district));
        do {
            std::cout << "Agama (Islam, Kristen, Katolik, Hindu, Buddha, Konghucu): ";
            getline(std::cin, newData[count].religion);
            if (!validateReligion(newData[count].religion)) {
                errorInput();
            }
        } while (!validateReligion(newData[count].religion));
        
        do {
            std::cout << "Status Perkawinan (Kawin, Belum Kawin): ";
            getline(std::cin, newData[count].isMaried);
            if (!validateIsMaried(newData[count].isMaried)) {
                errorInput();
            }
        } while (!validateIsMaried(newData[count].isMaried));
        do {
            std::cout << "Pekerjaan: ";
            getline(std::cin, newData[count].job);
            if (!validateJob(newData[count].job)) {
                errorInput();
            }
        } while (!validateJob(newData[count].job));
        newData[count].citizenship = "WNI";
        newData[count].validUntil = "SEUMUR HIDUP";
        time_t now = time(0);
        tm *ltm = localtime(&now);
        newData[count].created.date = ltm->tm_mday;
        newData[count].created.month = ltm->tm_mon + 1;
        newData[count].created.year = ltm->tm_year + 1900;
        for (int i = 0; i < newData[count].religion.length(); i++) {
            newData[count].religion[i] = toupper(newData[count].religion[i]);
        }
        for (int i = 0; i < newData[count].isMaried.length(); i++) {
            newData[count].isMaried[i] = toupper(newData[count].isMaried[i]);
        }
        std::ofstream file;
        file.open("data.txt", std::ios::app);
        file << "Provinsi          : " << newData[count].province << std::endl;
        file << "Kota/Kabupaten    : " << newData[count].city << std::endl;
        file << "NIK               : " << newData[count].nik << std::endl;
        file << "Nama              : " << newData[count].name << std::endl;
        file << "Tempat/Tgl Lahir  : " << newData[count].born.place << ", " << std::setfill('0') << std::setw(2) << newData[count].born.date << "-" << std::setfill('0') << std::setw(2) << newData[count].born.month << "-" << newData[count].born.year << std::endl;
        file << "Jenis Kelamin     : " << (newData[count].gender == 0 ? "LAKI-LAKI" : "PEREMPUAN") << std::endl;
        file << "Gol.Darah         : " << newData[count].bloodType << std::endl;
        file << "Alamat            : " << newData[count].address.address << std::endl;
        file << "       RT/RW      : " << std::setfill('0') << std::setw(3) << newData[count].address.neighborhoodAssociation << "/" << std::setfill('0') << std::setw(3) << newData[count].address.communityAssociation << std::endl;
        file << "       Kel/Desa   : " << newData[count].address.subDistrict << std::endl;
        file << "       Kecamatan  : " << newData[count].address.district << std::endl;
        file << "Agama             : " << newData[count].religion << std::endl;
        file << "Status Perkawinan : " << newData[count].isMaried << std::endl;
        file << "Pekerjaan         : " << newData[count].job << std::endl;
        file << "Kewarganegaraan   : " << newData[count].citizenship << std::endl;
        file << "Berlaku Hingga    : " << newData[count].validUntil << std::endl;
        file << "Dibuat            : " << std::setfill('0') << std::setw(2) << newData[count].created.date << "-" << std::setfill('0') << std::setw(2) << newData[count].created.month << "-" << newData[count].created.year << std::endl;
        file << "========================================================" << std::endl;
        file.close();
        count++;
        delete[] data;
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
        data = new Data[count];
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
    int choice;
    while(true){
        ktp.initialize();
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
                return EXIT_SUCCESS;
            default:
                std::cout << "Pilihan tidak valid" << std::endl;
                break;
        }
        system("pause");
        system("cls");
    }
}