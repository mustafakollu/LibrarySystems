#include "LibrarySystem.h"

LibrarySystem gec;

LibrarySystem::LibrarySystem() {}
LibrarySystem::~LibrarySystem(){}

struct node
{
    int infoId;
    string infoTitle;
    int infoGenre;
    struct node *next;
    struct node *prev;
}
*start, *last;
int counter = 0;
node* create_node(const int movieId, const string movieTitle, const int year)
{
    counter++;
    struct node *temp;
    temp = new(struct node);
    temp->infoId = movieId;
    temp->infoTitle = movieTitle;
    temp->infoGenre = year;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

struct node1
{
    int infoUserId;
    string infoUserName;
    node1 *nextUser;
    node1 *prevUser;
    struct node *nMoive;
}
*startUser, *lastUser;
int counterUser = 0;
node1 * create_nodeUser(const int userId, const string userName){
    counterUser++;
    struct node1 *tempUser;
    tempUser = new(struct node1);
    tempUser->infoUserId = userId;
    tempUser->infoUserName = userName;
    for (int i=0;i<counter;i++){
        tempUser->nMoive = start;
        start = start->next;
    }
    tempUser->nextUser = NULL;
    tempUser->prevUser = NULL;
    return tempUser;
}


void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {
    ofstream fout("output.txt", ios::app);
    if (start == last && start == NULL){
        struct node *temp;
        temp = create_node(movieId,movieTitle,year);
        fout<<"Movie "<<movieId<<" has been added"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else{
        struct node *temp;
        temp = create_node(movieId,movieTitle,year);
        fout<<"Movie "<<movieId<<" has been added"<<endl;
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;

    }

}

void LibrarySystem::deleteMovie(const int movieId) {
    int i;
    ofstream fout("output.txt", ios::app);
    if (start == last && start == NULL)
    {
        fout<<"The List is empty."<<endl;
        return;
    }
    for (i = 0;i < counter;i++)
    {
        if(movieId==start->next->infoId){
            start->next=start->next->next;
            start=last->next;
            start->prev = last;
            fout<<"Movie "<<movieId<<" has not been checked out\n"
                                    "Movie "<<movieId<<" has been deleted"<<endl;
        }
    }
    counter--;
}

void LibrarySystem::addUser(const int userId, const string userName) {
    ofstream fout("output.txt", ios::app);
    int value=userId;
    struct node1 *tempUser;
    tempUser = create_nodeUser(userId,userName);
    if (startUser == lastUser && startUser == NULL)
    {
        fout<<"User "<<userId<<" has been added"<<endl;
        startUser = lastUser = tempUser;
        startUser->nextUser = lastUser->nextUser = NULL;
        startUser->prevUser = lastUser->prevUser = NULL;
    }
    else
    {
        fout<<"User "<<userId<<" has been added"<<endl;
        lastUser->nextUser = tempUser;
        tempUser->prevUser = lastUser;
        lastUser = tempUser;
        startUser->prevUser = lastUser;
        lastUser->nextUser = startUser;
    }
}

void LibrarySystem::deleteUser(const int userId) {
    ofstream fout("output.txt", ios::app);
    int i;
    if (startUser == lastUser && startUser == NULL)
    {
        fout<<"The List is empty."<<endl;
        return;
    }
    for (i = 0;i < counter;i++)
    {
        if(userId==startUser->nextUser->infoUserId){
            startUser->nextUser=startUser->nextUser->nextUser;
            startUser=lastUser->nextUser;
            startUser->prevUser = lastUser;
            fout<<"User "<<userId<<" has been deleted"<<endl;
        }
    }
    counterUser--;
}

void LibrarySystem::checkOutMovie(const int movieId, const int userId) {

}

void LibrarySystem::returnMovie(const int movieId) {

}

void LibrarySystem::showAllMovies() {
    ofstream fout("output.txt", ios::app);
    int i;
    if (start == last && start == NULL)
    {
        fout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    for (i = 0;i < counter;i++)
    {
        fout<<start->infoId<<"  "<<start->infoTitle<<"  "<<start->infoGenre<<endl;
        start = start->next;
    }
}

void LibrarySystem::showMovie(const int movieId) {
    ofstream fout("output.txt", ios::app);
    int i;
    if (start == last && start == NULL)
    {
        fout<<"The List is empty."<<endl;
        return;
    }
    for (i = 0;i < counter;i++)
    {
        if(movieId==start->infoId){
            fout<<start->infoId<<"  "<<start->infoTitle<<"  "<<start->infoGenre<<endl;
            start = start->next;
        }
        else{
            start = start->next;
        }
    }

}

void LibrarySystem::showUser(const int userId) {
    ofstream fout("output.txt", ios::app);
    int i;
    if (startUser == lastUser && startUser == NULL)
    {
        fout<<"The List is empty."<<endl;
        return;
    }
    for (i = 0;i < counterUser;i++)
    {
        if(userId==startUser->infoUserId){
            fout<<startUser->infoUserId<<"  "<<startUser->infoUserName<<endl;
            startUser = startUser->nextUser;
        }
        else{
            startUser = startUser->nextUser;
        }
    }
}






int LibrarySystem::getIMovieId() const {
    return iMovieId;
}

void LibrarySystem::setIMovieId(int iMovieId) {
    LibrarySystem::iMovieId = iMovieId;
}

const string &LibrarySystem::getSMovieTitle() const {
    return sMovieTitle;
}

void LibrarySystem::setSMovieTitle(const string &sMovieTitle) {
    LibrarySystem::sMovieTitle = sMovieTitle;
}

int LibrarySystem::getIMovieGenre() const {
    return iMovieGenre;
}

void LibrarySystem::setIMovieGenre(int iMovieGenre) {
    LibrarySystem::iMovieGenre = iMovieGenre;
}

int LibrarySystem::getIUserId() const {
    return iUserId;
}

void LibrarySystem::setIUserId(int iUserId) {
    LibrarySystem::iUserId = iUserId;
}

const string &LibrarySystem::getSUserName() const {
    return sUserName;
}

void LibrarySystem::setSUserName(const string &sUserName) {
    LibrarySystem::sUserName = sUserName;
}





