#include <iostream>

class Book
{
public :
    std::string title;
    std::string author;

    void information (void);
    Book (int i, float j);
    void total (void);
protected :
    float price;
    int sum;
};

int main()
{
    class Book b1(20, 12.22);
    b1.author = "Hai mingwei";
    b1.title = "old man and sea";
    b1.information();
    b1.total();
    return 0;
}

void Book::total (void)
{
    int i = price * sum;
    std::cout << "total price :" << i << std::endl;
}

void Book::information(void)
{
    using namespace std;
    {
        cout << "book title :" << title << endl;
        cout << "book author :" << author << endl;
        cout << "book price :" << price << endl;
    }
}

Book::Book (int i,float j)
{
    price = j;
    sum = i;
}