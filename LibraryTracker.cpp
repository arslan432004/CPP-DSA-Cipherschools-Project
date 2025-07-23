#include <bits/stdc++.h>
using namespace std;

class Book{
    private:
    string name;
    string author;
    bool isBorrowed;
    public:
    Book(string name, string author){
        this->name=name;
        this->author=author;
        isBorrowed = false;
    }
    string getBookName(){
        return this->name;
    }
    string getAuthorName(){
        return this->author;
    }
    bool isBorrowed(){
        return this->isBorrowed;
    }
    void setBookStatus(bool f){
        this->isBorrowed = f;
        return;
    }
};

class Library{
    private:
    vector<Book>list;
    public:
    Library(){}
    
    void addBook(string name, string author){
        Book b(name,author);
        list.push_back(b);
    }
    
    void returnBook(int ind){
        if(list.size()==0 || ind<=0 || ind >= list.size()){
            return;
        }
        list[ind].setBookStatus(false);
        return;
        
    }
    void displayBooks(){
        for(int i=0;i<list.size();i++){
            cout<<(i+1)<<"Book name is "<< list[i].getBookName << " which is written by " << list[i].getAuthorName;
        }
    }
    void displayBorrowedBooks(){
        for(int i=0;i<list.size();i++){
            if(List[i].isBorrowed){
                cout<<(i+1)<<"Book name is "<< list[i].getBookName << " which is written by " << list[i].getAuthorName;

            }
        }
    }
    void Borrow(int ind){
        if(list.size()==0 || ind <=0 || ind >= list.size() || list[ind].isBorrowed())return;
        list[ind-1].setBookStatus(true);
        return;
    }
};

int main(){
    Library lb;
    while(true){
        cout<<" LIBRARY MENU "<< endl;
        cout <<"1. Add a book "<<endl;
        cout<<"2. Return a book "<<endl;
        cout<<"3. Borrow a book "<<endl;
        cout<<"4. Display all the books"<<endl;
        cout<<"5. Display all borrowed books"<<endl;
        cout<<"6. Exit"<<endl;

        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            
            lb.addBook("The Mysterious Affair at Styles","Agatha Christie");
            break;

        case 2:
            lb.displayBorrowedBooks();
            int ind;
            cin>>ind;
            lb.returnBook(ind);
            break;

        case 3:
            lb.displayBooks();
            int ind;
            cin >>ind;
            lb.Borrow(ind);
            break;

        case 4:
            lb.displayBooks();
            break;

        case 5:
            lb.displayBorrowedBooks();
            break;

        case 6:
            cout << "EXITING" <<endl;
            return 0;

        default:
            cout << "Invalid Input... Try again" << endl;

        }

    }

    return 0;
}