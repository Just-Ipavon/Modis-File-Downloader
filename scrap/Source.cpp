#include "Header.h"


void waitForInput() {
    printf("Premi per continuare\n");
    getchar();
};

int main()
{
    string archivio, index, url, path, buffer, token, auth, anno, DB;
    int UrlNI = 0, UrlNF = 0, scelta = 0, SDB = 0;
    token = "cGVwcGU6WjJsMWMyVndjR1V1WVhWc2FXTnBibTlBZFc1cGNHRnlkR2hsYm05d1pTNXBkQT09OjE2NDk3NTQzMjU6MjdiZWMxYzM5YTIyNTcxMTk5ODFjZjRhMDFhNzg1Y2I4YjM0MzBhZA";

    printf("scegliere un anno (YYYY):");
    cin >> anno;
    printf("selezionare un giorno iniziale:");
    cin >> UrlNI;
    printf("selezionare un giorno finale:");
    cin >> UrlNF;
    printf("scegliere un archivio:");
    fflush(stdin);
    cin >> archivio;
    path = "\\\\NAS29F79B\\";
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

        for (int i = UrlNI; i <= UrlNF; i++) {
            if (i > 0 && i <= 9) {
                index = "00";
                index += std::to_string(i);
            }
                
            else if (i >= 10 && i <= 99) {
                index = "0";
                index += std::to_string(i);
            }

            else if (i >= 100 && i <= 365) {
                index = "";
                index += std::to_string(i);
            }
            else
                return 0;
            url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
            url += DB + "/";
            url += anno;
            url += "/" + index + "\"";
            buffer = "wget -e  robots=off -r -l 1 -np -R .html,.tmp -nH --cut-dirs=4 " + url + " --header " + auth + " -P " + path;
            system(buffer.c_str());
            //cout << buffer << endl;
        }

    }
    else {
        return 0;
    }
    return 0;
}