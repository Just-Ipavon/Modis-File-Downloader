#include "Header.h"

void Download(int UrlNI, int UrlNF, string index, string DB, string path, string auth, string anno) {
    string url, buffer, fileName, hourIndex;

    int i, j;

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

        for (j = MIN_HOUR; j <= MAX_HOUR; j++){

         if (j > 0 && j < 10) {
            hourIndex = "0";
            hourIndex += to_string(j);
        }

        else if (i >= 10 && i <= 15) {
            hourIndex = "";
            hourIndex += to_string(j);
        }
        fileName = "\""+DB + ".A" + anno + index + "." + hourIndex + "*" + "\"";

        url = "\"https://ladsweb.modaps.eosdis.nasa.gov/archive/allData/61/";
        url += DB + "/";
        url += anno;
        url += "/" + index + "\"";
        buffer = "wget -e  robots=off -r -N -l 1 -np -A " + fileName + " -R .html,.tmp -nH --cut-dirs=4 " + url + " --header " + auth + " -P " + path;
        cout << "----------------------------------------------" << endl;
        cout << buffer << endl;
        cout << "----------------------------------------------" << endl;
        system(buffer.c_str());
        
        waitForInput();
        }
       


    }

}

void waitForInput() {
    cout << "Premi per continuare\n";
    getchar();
};

int FileTime(string FilePath)
{
    string buffer;

    buffer = "dir /T:C " + FilePath;

    system(buffer.c_str());

    return 0;
}

int FileArray(string Fpath)
{
    string FpathC;
    vector<string> fnames; //your filenames will be stored here

    path p("C:\\TEST");   // C:\TEST
    directory_iterator di(p);
    directory_iterator di_end;

    while (di != di_end)
    {
        FpathC = Fpath + di->path().filename().string();
        FileTime(FpathC);
        ++di;
    }
}

int FileArrayRec(string Fpath)
{
    string FpathC;
    path directory = "C:\\TEST";
    for (path p : recursive_directory_iterator(directory))
    {
        FpathC = Fpath + path().filename().string();
        FileTime(FpathC);
    }
}
