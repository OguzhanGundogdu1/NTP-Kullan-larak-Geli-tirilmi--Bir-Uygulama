#include "classes.ixx"

int main() {
    Author mahmud("Mahmud" , 76);
    Author george("George" , 10);
    Author ahmed("Ahmed" , 57);



    PrintedBook book1("Tutunamayanlar" , mahmud , 201);
    PrintedBook book2("1984" , george , 184);
    PrintedBook book3("Hayvanciftligi" , george , 315);
    
    

    ElectronicBook book4("Kizilelma" , ahmed , 317);
    ElectronicBook book5("Osmanli" , ahmed , 222);
    ElectronicBook book6("Piyalepasa" , mahmud , 189);

    

    Member oguz("Oguzhan" , 75);
    Member ali("Ali" , 16);

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);
    library.addBook(book6);

    library.listBooks();

    oguz.borrowBook(book1);
    ali.borrowBook(book1);
    ali.borrowBook(book6);
    oguz.borrowBook(book6);
    oguz.borrowBook(book2);
    oguz.borrowBook(book3);
    oguz.borrowBook(book5);
    ali.borrowBook(book5);
    ali.borrowBook(book3);
    oguz.returnBook("Hayvanciftligi");
    ali.borrowBook(book3);

    book2.printDetails();
    book5.printDetails();
    ahmed.displayInfo();
    oguz.displayInfo();

    return 0;
}