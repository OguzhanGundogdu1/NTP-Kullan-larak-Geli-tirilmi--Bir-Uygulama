#include "classes.ixx"

Person::~Person(){
    cout<<"Person Destructor."<<endl;
}

Member::~Member(){
    free(borrowedBooks);
    cout<<"Member Destructor."<<endl;
}

Member::Member(string n , int i) : Person(n , i){
    borrowedBooks = (Book**) malloc(sizeof(Book*) * 4);
    for(int i=0 ; i<MAX_BORROWED_BOOK; i++){
        borrowedBooks[i] = nullptr;
    }
    cout<<"Parametrized Member Constructor."<<endl;
}

void Member::displayInfo() const{
    cout<<"NAME ---> "<<name<<" , ID ---> "<<id<<endl;
    if(!borrowedBookNumber){
        cout<<"There is not any borrowed book."<<endl;
        return;
    }
    for(int i = 0; i < borrowedBookNumber; i++){
        cout<<i+1<<" ---> "<<borrowedBooks[i]->getTitle()<<endl;
    }
    return;
}

void Member::borrowBook(Book& new_book){
    if(borrowedBookNumber == MAX_BORROWED_BOOK){
        cout<<"Member cannot borrow another book because of the limitation."<<endl;
        return;
    }
    if(new_book.getType() == 2 && new_book.getAvailability()){
        borrowedBooks[borrowedBookNumber++] = &new_book;
        new_book.setAvailability(false);
    }else if(new_book.getType() == 2 && !new_book.getAvailability()){
        cout<<"\""<<new_book.getTitle()<<"\" has already been borrowed."<<endl;
        return;
    }else if(new_book.getType() == 1){
        borrowedBooks[borrowedBookNumber++] = &new_book;
    }
    cout<<new_book.getTitle()<<" was borrowed by "<<this->name<<endl;
    return;
}

void Member::returnBook(string old_book){
    if(!borrowedBookNumber){
        cout<<"There is not any borrowed book."<<endl;
        return;
    }
    for(int i=0; i<borrowedBookNumber; i++){
        if(borrowedBooks[i]->getTitle() == old_book){
            if(borrowedBooks[i]->getType() == 2){
                borrowedBooks[i]->setAvailability(true);
            }
            borrowedBooks[i] = nullptr;
            for(int a=i; a<borrowedBookNumber-1; a++){
                borrowedBooks[a] = borrowedBooks[a+1];
            }
            break;
        }
    }
    cout<<"\""<<old_book<<"\" was returned by "<<this->name<<endl;
    return;
}

Author::~Author(){
    free(bookswritten);
    cout<<"Author Destructor."<<endl;
}

Author::Author(string s , int i) : Person(s , i){
    bookswritten = (Book**) malloc(sizeof(Book*) * 4);
    for(int i=0; i<4 ;i++){
        bookswritten[i] = nullptr;
    }
    cout<<"Parametrized Author Constructor."<<endl;
}

void Author::displayInfo() const{
    cout<<"NAME ---> "<<name<<" , ID ---> "<<id<<endl;
    if(!writtenBookNumber){
        cout<<"There is not any written book."<<endl;
        return;
    }

    for(int i=0; i<writtenBookNumber; i++){
        cout<<i+1<<" ---> "<<bookswritten[i]->getTitle()<<endl;
    }
    return;
}

void Author::addBook(Book& new_book){
    bookswritten = (Book**) realloc(bookswritten , ++writtenBookNumber * sizeof(Book*));
    bookswritten[writtenBookNumber-1] = &new_book;
    cout<<"Book \""<<new_book.getTitle()<<"\" was added to the written books of Author "<<this->name<<endl;
}

Book::~Book(){
    cout<<"Book Destructor."<<endl;
}

void PrintedBook::setAvailability(bool b){
    is_available = b;
}

Book::Book(string s , Author& a , int i){
    title = s;
    author = &a;
    type = i;
    a.addBook(*this);
    cout<<"Parametrized Book Constructor."<<endl;
}

ElectronicBook::~ElectronicBook(){
    cout<<"EBook Destructor."<<endl;
}

ElectronicBook::ElectronicBook(string s , Author& a , int p) : Book(s , a , 1) , pages {p}{
    cout<<"Parametrized EBook Constructor."<<endl;
}

void ElectronicBook::printDetails() const{
    cout<<"TITLE ---> "<<title<<" , AUTHOR ---> "<<author->getName()<<" , PAGE ---> "<<pages<<endl;
}

PrintedBook::~PrintedBook(){
    cout<<"PrintedBook Destructor."<<endl;
}

PrintedBook::PrintedBook(string s , Author& a , int i) : Book(s , a , 2) , pages(i){
    cout<<"Parametrized PrintedBook Constructor."<<endl;
}

void PrintedBook::printDetails() const{
    cout<<"TITLE ---> "<<title<<" , AUTHOR ---> "<<author->getName()<<" , PAGE ---> "<<pages;
    if(is_available){
        cout<<"AVAILABLE for borrowing."<<endl;
        return;
    }
    cout<<"NOT AVAILABLE for borrowing."<<endl;
    return;
}

Library::~Library(){
    free(books);
    cout<<"Library Destructor."<<endl;
}

Library::Library(){
    books = (Book**) malloc(sizeof(Book*) * LIBRARY_CAPACITY);
    for(int i=0; i<LIBRARY_CAPACITY; i++){
        books[i] = nullptr;
    }
    cout<<"Default Library Constructor."<<endl;
}

void Library::addBook(Book& new_book){
    if(book_number == LIBRARY_CAPACITY){
        cout<<"The Library is FULL , so it cannot accept a new book."<<endl;
        return;
    }
    books[book_number++] = &new_book;
    cout<<"The new book \""<<new_book.getTitle()<<"\" was added to the Library."<<endl;
    return;
}

void Library::listBooks() const{
    if(!book_number){
        cout<<"The library is EMPTY."<<endl;
        return;
    }
    for(int i=0; i<book_number; i++){
        cout<<i+1<<" ---> "<<books[i]->getTitle()<<endl;
    }
    return;
}