
#ifndef UNTITLED4_LIBRARYSYSTEM_H
#define UNTITLED4_LIBRARYSYSTEM_H


#include <iostream>
#include <fstream>
using namespace std;


class LibrarySystem {
    int iMovieId;
    string sMovieTitle;
    int iMovieGenre;
    int iUserId;
    string sUserName;

public:
    int getIMovieId() const;

    void setIMovieId(int iMovieId);

    const string &getSMovieTitle() const;

    void setSMovieTitle(const string &sMovieTitle);

    int getIMovieGenre() const;

    void setIMovieGenre(int iMovieGenre);

    int getIUserId() const;

    void setIUserId(int iUserId);

    const string &getSUserName() const;

    void setSUserName(const string &sUserName);



    LibrarySystem();
    ~LibrarySystem();



    void addMovie(const int movieId,const string movieTitle,const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId, const string userName);
    void deleteUser(const int userId);

    void checkOutMovie(const int movieId,const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);

};


#endif //UNTITLED4_LIBRARYSYSTEM_H
