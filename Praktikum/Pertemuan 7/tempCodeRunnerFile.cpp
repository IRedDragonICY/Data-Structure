    
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