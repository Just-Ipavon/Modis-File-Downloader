#include "Header.h"


int main()
{
    string archivio, index, url, path, buffer, token, auth, DB, anno;
    int UrlNI = 0, UrlNF = 0, scelta = 0, SDB = 0;
    token = "cGVwcGU6WjJsMWMyVndjR1V1WVhWc2FXTnBibTlBZFc1cGNHRnlkR2hsYm05d1pTNXBkQT09OjE2NDk3NTQzMjU6MjdiZWMxYzM5YTIyNTcxMTk5ODFjZjRhMDFhNzg1Y2I4YjM0MzBhZA";
    path = "\\\\NAS29F79B\\";

    cout <<"scegliere un anno (YYYY):"<< endl;
    cin >> anno;

    cout<< "selezionare un giorno iniziale:" << endl;
    cin >> UrlNI;

    cout << "selezionare un giorno finale:" << endl;
    cin >> UrlNF;

   cout << "scegliere un archivio:" << endl;
    fflush(stdin);
    cin >> archivio;
    path.append(archivio);  

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
        Download(UrlNI, UrlNF,index, DB, path, auth, anno);
    }
    else {
        return 0;
    }
    return 0;
}