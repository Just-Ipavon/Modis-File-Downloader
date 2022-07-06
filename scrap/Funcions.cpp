#include "Header.h"


using namespace std;


void Download(int UrlNI, int UrlNF, string index, string DB, string path, string auth,string anno) {
    string url, buffer, fileName, hourIndex;

    int i, j, annoi;

    for (i = UrlNI; i <= UrlNF; i++) { // cambia il valore dell'indice rendendolo conforme all'url da generare 
        if (i > 0 && i <= 9) {
            index = "00";
            index += to_string(i);
        }

        else if (i >= 10 && i <= 99) {
            index = "0";
            index += to_string(i);
        }

        else if (i >= 100 && i <= 365) {
            index = "";
            index += to_string(i);
        }
        else
            exit;

        for (j = MIN_HOUR; j <= MAX_HOUR-1; j++){ // filtra le ore da scaricare con un intervallo modificabile nel file header

         if (j > 0 && j < 10) {
            hourIndex = "0";
            hourIndex += to_string(j);
        }

        else if (j >= 10 && j <= MAX_HOUR-1) {
             hourIndex = "";
             hourIndex += to_string(j);
         
        }  
        fileName = "\""+DB + ".A" + anno + index + "." + hourIndex + "*" + "\"";  //genera il nome del file con l'ora scelta

        url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
        url += DB + "/";
        url += anno;
        url += "/" + index + "\"";
        buffer = "wget -e  robots=off -r -N -l 1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=3 " + url + " --header " + auth + " -P " + path; //genera il comando per scaricare il file
        
        
    /*    cout << "----------------------------------------------" << endl;
        cout << buffer << endl;
        cout << "----------------------------------------------" << endl;
        
      */
        
        system(buffer.c_str()); 
        //waitForInput();
        }
        fileName = "\"" + DB + ".A" + anno + index + "." + to_string(MAX_HOUR) + "00*" + "\""; //crea il nome dell'ultimo file da scaricare che corrisponde al primo file dell'ultima ora

        url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
        url += DB + "/";
        url += anno;
        url += "/" + index + "\"";
        buffer = "wget -e  robots=off -r -N -l 1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=3 " + url + " --header " + auth + " -P " + path;

        /*
          cout << "----------------------------------------------" << endl;
        cout << buffer << endl;
        cout << "----------------------------------------------" << endl;
        */


        system(buffer.c_str());
       


    }

}

void DownloadM(int UrlNI, int UrlNF, string index, string DB, string path, string auth, string anno, int mese, month* mesi) {
    string url, buffer, fileName, hourIndex, mkdir;

    int i, j, annoi;

    for (i = UrlNI; i <= UrlNF; i++) { // cambia il valore dell'indice rendendolo conforme all'url da generare 
        if (i > 0 && i <= 9) {
            index = "00";
            index += to_string(i);
        }

        else if (i >= 10 && i <= 99) {
            index = "0";
            index += to_string(i);
        }

        else if (i >= 100 && i <= 365) {
            index = "";
            index += to_string(i);
        }
        else
            exit;

        for (j = MIN_HOUR; j <= MAX_HOUR - 1; j++) { // filtra le ore da scaricare con un intervallo modificabile nel file header

            if (j > 0 && j < 10) {
                hourIndex = "0";
                hourIndex += to_string(j);
            }

            else if (j >= 10 && j <= MAX_HOUR - 1) {
                hourIndex = "";
                hourIndex += to_string(j);

            }
            fileName = "\"" + DB + ".A" + anno + index + "." + hourIndex + "*" + "\""; //genera il nome del file con l'ora scelta

            url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
            url += DB + "/";
            url += anno;
            url += "/" + index + "\"";
            mkdir = "if not exist \"" + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\\" " + " mkdir " + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\"; //genera il comando per creare la directory richiesta
            buffer = "wget -e robots=off -r -N -l1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=6 " + url + " --header " + auth + " -P " + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\"; //genera il comando per scaricare il file
        

            /*
            cout << "----------------------------------------------" << endl;
            cout << mkdir << endl;
            cout << buffer << endl;
            cout << "----------------------------------------------" << endl;

            */
            
              
            system(mkdir.c_str());
            system(buffer.c_str());
            //waitForInput();
        }
        fileName = "\"" + DB + ".A" + anno + index + "." + to_string(MAX_HOUR) + "00*" + "\""; //crea il nome dell'ultimo file da scaricare che corrisponde al primo file dell'ultima ora

        url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
        url += DB + "/";
        url += anno;
        url += "/" + index + "\"";
        buffer = "wget -e robots=off -r -N -l1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=6 " + url + " --header " + auth + " -P " + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\";
        cout << buffer << endl;
        cout << "----------------------------------------------" << endl;
        

        system(buffer.c_str());



    }

}

void DownloadGM(int UrlNI, int UrlNF, string index, string DB, string path, string auth, string anno, month* mesi) {
    string url, buffer, fileName, hourIndex, mkdir;

    int i, j, annoi, mese;

    for (i = UrlNI; i <= UrlNF; i++) { // cambia il valore dell'indice rendendolo conforme all'url da generare 
        if (i > 0 && i <= 9) {
            index = "00";
            index += to_string(i);
        }

        else if (i >= 10 && i <= 99) {
            index = "0";
            index += to_string(i);
        }

        else if (i >= 100 && i <= 365) {
            index = "";
            index += to_string(i);
        }
        else
            exit;
        mese = whatMonth(anno, i, mesi);
        for (j = MIN_HOUR; j <= MAX_HOUR - 1; j++) { // filtra le ore da scaricare con un intervallo modificabile nel file header

            if (j > 0 && j < 10) {
                hourIndex = "0";
                hourIndex += to_string(j);
            }

            else if (j >= 10 && j <= MAX_HOUR - 1) {
                hourIndex = "";
                hourIndex += to_string(j);

            }
            fileName = "\"" + DB + ".A" + anno + index + "." + hourIndex + "*" + "\""; //genera il nome del file con l'ora scelta

            url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
            url += DB + "/";
            url += anno;
            url += "/" + index + "\"";
            mkdir = "if not exist \"" + path + "\\" + mesi[mese - 1].getName() + "_" + anno +  "\\\" " + " mkdir " + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\"; //genera il comando per creare la directory richiesta
            buffer = "wget -e robots=off -r -N -l1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=6 " + url + " --header " + auth + " -P " + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\";  //genera il comando per scaricare il file

            /*
            cout << "----------------------------------------------" << endl;
            cout << mkdir << endl;
            cout << buffer << endl;
            cout << "----------------------------------------------" << endl;
            */

            system(mkdir.c_str());
            system(buffer.c_str());
            //waitForInput();
        }
        fileName = "\"" + DB + ".A" + anno + index + "." + to_string(MAX_HOUR) + "00*" + "\"";  //crea il nome dell'ultimo file da scaricare che corrisponde al primo file dell'ultima ora

        url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
        url += DB + "/";
        url += anno;
        url += "/" + index + "\"";
        buffer = "wget -e robots=off -r -N -l1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=6 " + url + " --header " + auth + " -P " + path + "\\" + mesi[mese - 1].getName() + "_" + anno + "\\";
        cout << buffer << endl;
        cout << "----------------------------------------------" << endl;

        system(buffer.c_str());

    }

}

void waitForInput() {
    cout << "Premi per continuare\n";
    getchar();
};

int whatMonth(string anno, int day, month* mesi) { //prendendo in input anno, l'array di mesi e il giorno restituisce il mese del giorno scelto
    if (month::isLeapYear(anno)) {
        for (int i = 0; i <= sizeof(mesi); i++) {
            if (day <= mesi[i].getLastLeap() && day >= mesi[i].getFirstLeap()) {
                return i + 1;
            }
        }
    }
    else {
        for (int i = 0; i <= MONTH; i++) {
            if (day >= mesi[i].getFirst() && day <= mesi[i].getLast()) {
                return i + 1;
            }
        }
    }
}

bool month::isLeapYear(string anno) { //controlla se l'anno scelto � bisestile
    if (stoi(anno) % 400 == 0) {
        return true;
    }
    else return false;  
}

void month::setName(string Name) {
    this->name = Name;
};
void month::setFirst(int First) {
    this->first = First;
};
void month::setLast(int Last) {
    this->last = Last;
};
void month::setFirstLeap(int firstleap) {
    this -> firstLeap = firstleap;
};
void month::setLastLeap(int lastleap) {
    this->lastLEap = lastleap;
};

string month::getName() {
    return this->name;
};
int month::getFirst() {
    return this->first;
};
int month::getLast() {
    return this->last;
};
int month::getFirstLeap() {
    return this->firstLeap;
};
int month::getLastLeap() {
    return this->lastLEap;
};

void monthInitializer(month* mesi) {

    mesi[0].setName("Gennaio");
    mesi[0].setFirst(1);
    mesi[0].setLast(31);
    mesi[0].setFirstLeap(1);
    mesi[0].setLastLeap(31);

    mesi[1].setName("Febbraio");
    mesi[1].setFirst(32);
    mesi[1].setLast(59);
    mesi[1].setFirstLeap(32);
    mesi[1].setLastLeap(60);


    mesi[2].setName("Marzo");
    mesi[2].setFirst(60);
    mesi[2].setLast(90);
    mesi[2].setFirstLeap(61);
    mesi[2].setLastLeap(91);


    mesi[3].setName("Aprile");
    mesi[3].setFirst(91);
    mesi[3].setLast(120);
    mesi[3].setFirstLeap(92);
    mesi[3].setLastLeap(121);


    mesi[4].setName("Maggio");
    mesi[4].setFirst(121);
    mesi[4].setLast(151);
    mesi[4].setFirstLeap(122);
    mesi[4].setLastLeap(152);


    mesi[5].setName("Giugno");
    mesi[5].setFirst(152);
    mesi[5].setLast(181);
    mesi[5].setFirstLeap(153);
    mesi[5].setLastLeap(182);


    mesi[6].setName("Luglio");
    mesi[6].setFirst(182);
    mesi[6].setLast(212);
    mesi[6].setFirstLeap(183);
    mesi[6].setLastLeap(213);


    mesi[7].setName("Agosto");
    mesi[7].setFirst(213);
    mesi[7].setLast(243);
    mesi[7].setFirstLeap(214);
    mesi[7].setLastLeap(244);


    mesi[8].setName("Settembre");
    mesi[8].setFirst(244);
    mesi[8].setLast(273);
    mesi[8].setFirstLeap(245);
    mesi[8].setLastLeap(274);


    mesi[9].setName("Ottobre");
    mesi[9].setFirst(274);
    mesi[9].setLast(304);
    mesi[9].setFirstLeap(275);
    mesi[9].setLastLeap(305);


    mesi[10].setName("Novembre");
    mesi[10].setFirst(305);
    mesi[10].setLast(334);
    mesi[10].setFirstLeap(306);
    mesi[10].setLastLeap(335);


    mesi[11].setName("Dicembre");
    mesi[11].setFirst(335);
    mesi[11].setLast(365);
    mesi[11].setFirstLeap(336);
    mesi[11].setLastLeap(366);


}