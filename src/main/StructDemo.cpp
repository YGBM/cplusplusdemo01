#include <iostream>
#include <cstring>

using namespace std;

double getAverage(int arr[],int size){
    int i,sum = 0;
    double avg;

    for(i = 0; i < size; i++){
        sum +=arr[i];
    }
    avg = double(sum) / size;
    return avg;
}

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void toString(struct Books book){
    cout << "book.title:\t"<< book.title
         << "\nbook.author:\t" << book.author
         << "\nbook.subject:\t" << book.subject
         << "\nbook.book_id:\t" << book.book_id << endl;
}

// Books book1;
// strcpy(book1.author,"fuzusheng");
// strcpy(book1.author,"fuzusheng");
// strcpy(book1.subject,"fuzusheng");
// book1.book_id = 100;
// toString(book1);