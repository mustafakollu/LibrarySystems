

#include "LibrarySystem.h"



int main(int argc, char** argv) {
    ofstream fout(argv[2],ios::app);
    fout<<"===Movie Library System==="<<endl<<endl;
    string line;
    ifstream my_file(argv[1]);
    LibrarySystem gec;
    if (my_file.is_open()){
        string temp="l";
        while (getline(my_file,line)){
            int l =line.length();
            if(line.substr(0,7).compare("addUser")==0){
                if(temp.compare(line)==0){
                    gec.addUser(stoi(line.substr(8,1)),line.substr(10));
                    temp=line;
                }
                else{
                    fout<<"===addUser() method test==="<<endl;
                    gec.addUser(stoi(line.substr(8,1)),line.substr(10));
                    temp=line;
                }
                fout<<endl;
            }
            if(line.substr(0,8).compare("addMovie")==0){
                if(temp.compare(line)==0){
                    gec.addMovie(stoi(line.substr(12,1)),line.substr(11,l-15),stoi(line.substr(l-4,4)));
                    temp=line;
                }
                else{
                    fout<<"===addMovie() method test==="<<endl;
                    gec.addMovie(stoi(line.substr(12,1)),line.substr(11,l-15),stoi(line.substr(l-4,4)));
                    temp=line;
                }
                fout<<endl;
            }
            if(line.substr(0,12).compare("showAllMovie")==0){
                if(temp.compare(line)==0){
                    gec.showAllMovies();
                    temp=line;
                }
                else{
                    fout<<"==showAllMovie() method test==\n"
                          "Movie id - Movie name - Year - Status"<<endl;
                    gec.showAllMovies();
                    temp=line;
                }
                fout<<endl;
            }
            if(line.substr(0,13).compare("checkoutMovie")==0){
                fout<<"==checkoutMovie() method test=="<<endl<<endl;
            }
            if(line.substr(0,9).compare("showMovie")==0){
                if(temp.compare(line)==0){
                    gec.showMovie(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                else{
                    fout<<"==showMovie() method test=="<<endl;
                    gec.showMovie(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                fout<<endl;
            }
            if(line.substr(0,8).compare("showUser")==0){
                if(temp.compare(line)==0){
                    gec.showUser(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                else{
                    fout<<"==showUser() method test=="<<endl;
                    gec.showMovie(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                fout<<endl;
            }
            if(line.substr(0,11).compare("deleteMovie")==0){
                if(temp.compare(line)==0){
                    gec.deleteMovie(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                else{
                    fout<<"==deleteMovie() method test=="<<endl;
                    gec.deleteMovie(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                fout<<endl;
            }
            if(line.substr(0,11).compare("returnMovie")==0){
                fout<<"==returnMovie() method test=="<<endl<<endl;
            }
            if(line.substr(0,10).compare("deleteUser")==0){
                if(temp.compare(line)==0){
                    gec.deleteUser(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                else{
                    fout<<"==deleteMovie() method test=="<<endl;
                    gec.deleteUser(stoi(line.substr(l-1,1)));
                    temp=line;
                }
                fout<<endl;
            }
        }
    }



    return 0;
}
