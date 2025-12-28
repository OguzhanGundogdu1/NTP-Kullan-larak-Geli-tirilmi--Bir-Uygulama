#ifndef CLASSES
#define CLASSES

#include <iostream>
#include <string>
#define MAX_BORROWED_BOOK 3
#define LIBRARY_CAPACITY 50

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Book;
class ElectronicBook;
class PrintedBook;
class Library;

class Person{
    protected:
        string name;
        int id;
    public:
        Person(string n , int i) : name {n} , id {i} {cout<<"Parametrized Person Constructor."<<endl;}
        virtual void displayInfo() const = 0;
        string getName() {return name;}
        virtual ~Person(); //virtual eklenme sebebi nedir? ~ override edip alt oobjelerin destructorlarına erişmek.
};

class Member : public Person{
    private:
        Book** borrowedBooks;
        int borrowedBookNumber {};
    public:
        Member(string n , int i);
        void displayInfo() const override;
        void borrowBook(Book&);  //const neden sıkıntı çıkarıyor?  ~  const asla eşitliğin sağ tarafında olamaz.
        void returnBook(string);
        ~Member();
};

class Author : public Person{
    private:
        Book** bookswritten;
        int writtenBookNumber = {};
    public:
        Author(string s , int i);
        void displayInfo() const override;
        void addBook(Book&);
        ~Author();
};

class Book{
    protected:
        string title;
        Author* author;
        int type {};
    public:
        Book(string , Author& , int);
        string getTitle() const {return title;}
        virtual void printDetails() const = 0;
        int getType() const {return type;}
        virtual void setAvailability(bool) = 0; 
        virtual bool getAvailability() const = 0;
        virtual ~Book();
};

class ElectronicBook : public Book{
    private:
        int pages {};
    public:
        ElectronicBook(string , Author& , int);
        void printDetails() const override;
        void setAvailability(bool) override {return;}
        bool getAvailability() const override {return true;}
        ~ElectronicBook();
};

class PrintedBook : public Book{
    private:
        int pages;
        bool is_available = true;
    public:
        PrintedBook(string , Author& , int);
        void printDetails() const override;
        void setAvailability(bool) override;
        bool getAvailability() const override {return is_available;}
        ~PrintedBook();
};

class Library{
    private:
        Book** books;
        int book_number {};
    public:
        Library();
        void addBook(Book&);
        void listBooks() const;
        ~Library();
};

#endif