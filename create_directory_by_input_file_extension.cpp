#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <filesystem>
#include <unistd.h>

using namespace std;

int main(){
    //  get Current working directory 
    filesystem::path currentPath = filesystem::current_path();

    //  list of file name in the folder
    vector<string> files;
    string fileName = "";

    //  check file extension
    string input_extension = "";
    cout << "Enter File Extension ( Example .txt enter: txt): ";
    cin >> input_extension;
    input_extension = "." + input_extension;


    for (const auto & file : filesystem::directory_iterator(currentPath.string())){
        string file_extension = file.path().filename().extension().string();

        if( file_extension == input_extension){
            string destName  = (file.path().string()).substr(0, (file.path().string()).size() - (file_extension.size()) );
            
            //  create directory
            filesystem::create_directory(filesystem::u8path(destName));
            
            //  move the file in the folder
            string tamp = currentPath.string() + "\\" + filesystem::u8path(destName).filename().string() + "\\" + file.path().filename().string();
            
            filesystem::rename(filesystem::u8path(file.path().string()), filesystem::u8path(tamp) );
        }
    }

    return 0;
}