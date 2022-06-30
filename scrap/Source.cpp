#include "Header.h"

using namespace std;


int main()
{
    string archivio, index, url, path, buffer, token, auth, DB, anno;
    month mesi[12];
    int UrlNI = 0, UrlNF = 0, scelta = 0, SDB = 0, SM = 0, mese = 0;
    monthInitializer(mesi);

    token = "cGVwcGU6WjJsMWMyVndjR1V1WVhWc2FXTnBibTlBZFc1cGNHRnlkR2hsYm05d1pTNXBkQT09OjE2NDk3NTQzMjU6MjdiZWMxYzM5YTIyNTcxMTk5ODFjZjRhMDFhNzg1Y2I4YjM0MzBhZA";
    path = "\\\\NAS29F79B\\";


    cout << "scegliere una modalita' di download:" << endl
        << "Download singoli mesi (1)" << endl
        << "Download Giorni (2)" << endl
        << "Download Giorni con differenza di mese (3)" << endl
        //TODO: << "Download lista di mesi (4)" << endl
        << "exit (0): " << endl;
    cin >> SM;
    switch (SM) {
    case 1: {
        cout << "scegliere un anno (YYYY):" << endl;
        cin >> anno;

        cout << "scegliere un mese(1-12):" << endl;
        cin >> mese;

        UrlNI = mesi[mese-1].getFirst();
        UrlNF = mesi[mese-1].getLast();

        cout << "scegliere un archivio:" << endl;
        fflush(stdin);
        path = "\\\\NAS29F79B\\" + archivio;

        cout << "Scegliere un database tra: " << endl
            << "MYD03 (1)" << endl
            << "MYD021KM (2)" << endl
            << "MYD35_L2 (3)" << endl
            << "exit (0): " << endl;
        cin >> SDB;
        switch (SDB) {
        case 1: DB = "MYD03"; break;
        case 2: DB = "MYD021KM"; break;
        case 3: DB = "MYD35_L2"; break;
        case 0: return 0;
        }

        path = "C:\\TEST";
        auth = "\"Authorization: Bearer " + token + "\"";

        cout << "Hai inserito questi dati, sono corretti? " << endl
            << "Anno: " << anno << endl
            << "Mese: " << mesi[mese-1].getName() << endl
            << "Archivio: " << archivio << endl
            << "Database: " << DB << endl
            << "Si (1) No(0)" << endl;
        cin >> scelta;
        if (scelta == 1) {
            DownloadM(UrlNI, UrlNF, index, DB, path, auth, anno,mese,mesi);
        }
        else {
            return 0;
        }
    }; break;

    case 2: {

        cout << "scegliere un anno (YYYY):" << endl;
        cin >> anno;

        cout << "selezionare un giorno iniziale:" << endl;
        cin >> UrlNI;

        cout << "selezionare un giorno finale:" << endl;
        cin >> UrlNF;

        cout << "scegliere un archivio:" << endl;
        fflush(stdin);
        cin >> archivio;
        path += archivio;
        path += "\\Modis";

        cout << "Scegliere un database tra: " << endl
            << "MYD03 (1)" << endl
            << "MYD021KM (2)" << endl
            << "MYD35_L2 (3)" << endl
            << "exit (0): " << endl;
        cin >> SDB;
        switch (SDB) {
        case 1: DB = "MYD03"; break;
        case 2: DB = "MYD021KM"; break;
        case 3: DB = "MYD35_L2"; break;
        case 0: return 0;
        }

        // path = "D:\\Test";
        auth = "\"Authorization: Bearer " + token + "\"";

        cout << "Hai inserito questi dati, sono corretti? " << endl
            << "Anno: " << anno << endl
            << "Archivio: " << archivio << endl
            << "Numero Iniziale: " << UrlNI << endl
            << "Numero Finale: " << UrlNF << endl
            << "Database: " << DB << endl
            << "Si (1) No(0)" << endl;
        cin >> scelta;
        if (scelta == 1) {
            Download(UrlNI, UrlNF, index, DB, path, auth, anno);
        }
        else {
            return 0;
        }
    }; break;

    case 3: {

        cout << "scegliere un anno (YYYY):" << endl;
        cin >> anno;

        cout << "selezionare un giorno iniziale:" << endl;
        cin >> UrlNI;

        cout << "selezionare un giorno finale:" << endl;
        cin >> UrlNF;

        cout << "scegliere un archivio:" << endl;
        fflush(stdin);
        path = "\\\\NAS29F79B\\" + archivio + "\\Modis";

        cout << "Scegliere un database tra: " << endl
            << "MYD03 (1)" << endl
            << "MYD021KM (2)" << endl
            << "MYD35_L2 (3)" << endl
            << "exit (0): " << endl;
        cin >> SDB;
        switch (SDB) {
        case 1: DB = "MYD03"; break;
        case 2: DB = "MYD021KM"; break;
        case 3: DB = "MYD35_L2"; break;
        case 0: return 0;
        }

        path = "C:\\TEST";
        auth = "\"Authorization: Bearer " + token + "\"";

        cout << "Hai inserito questi dati, sono corretti? " << endl
            << "Anno: " << anno << endl
            << "Archivio: " << archivio << endl
            << "Numero Iniziale: " << UrlNI << endl
            << "Numero Finale: " << UrlNF << endl
            << "Database: " << DB << endl
            << "Si (1) No(0)" << endl;
        cin >> scelta;
        if (scelta == 1) {
            DownloadGM(UrlNI, UrlNF, index, DB, path, auth, anno, mesi);
        }
        else {
            return 0;
        }
    }; break;

    case 0: return 0;
    }


    return 0;
}