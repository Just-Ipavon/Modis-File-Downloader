#include "Header.h"

void Download(int UrlNI, int UrlNF, string index, string DB, string path, string auth,string anno) {
    string url, buffer, fileName, hourIndex;

    int i, j, annoi;

    for (i = UrlNI; i <= UrlNF; i++) {
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

        for (j = MIN_HOUR; j <= MAX_HOUR-1; j++){

         if (j > 0 && j < 10) {
            hourIndex = "0";
            hourIndex += to_string(j);
        }

        else if (j >= 10 && j <= MAX_HOUR-1) {
             hourIndex = "";
             hourIndex += to_string(j);
         
        }  
        fileName = "\""+DB + ".A" + anno + index + "." + hourIndex + "*" + "\"";

        url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
        url += DB + "/";
        url += anno;
        url += "/" + index + "\"";
        buffer = "wget -e  robots=off -r -N -l 1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=3 " + url + " --header " + auth + " -P " + path;
        
        
    /*    cout << "----------------------------------------------" << endl;
        cout << buffer << endl;
        cout << "----------------------------------------------" << endl;
        
      */
        
        system(buffer.c_str()); 
        //waitForInput();
        }
        fileName = "\"" + DB + ".A" + anno + index + "." + to_string(MAX_HOUR) + "00*" + "\"";

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

void waitForInput() {
    cout << "Premi per continuare\n";
    getchar();
};


bool month::isLeapYear(string anno) {
    if (stoi(anno) % 400 == 0) {
        return true;
    }
    else return false;  
}

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
int month::getId() {
    return this->id;
};
