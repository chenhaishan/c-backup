#include <iostream>
#include <string>
using namespace std;

class Quote{
private:
    string isbn;
protected:
    double single_price;
public:
    Quote() = default;
    Quote(const string &isbn, double &sp):
        isbn(isbn), single_price(sp){
        cout << "Quote(...)" << endl;
    }

    virtual ~Quote(){
        cout << "~Quote" << endl;
    }

    void samename(){
        cout << "Quote.samename" << endl;
    }

    string get_isbn() const;
    virtual double net_price(size_t n) const;
};
string Quote::get_isbn() const{
    return isbn;
}

double Quote::net_price(size_t n) const{
    cout << "Quote::net_price" << endl;
    return n*single_price;
}

class Disc_quote:public Quote{
public:
    int m_i;
protected:
    size_t quantity = 0;
    double discount = 0.0;
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price,
               size_t qty, double disc, int i):
        Quote(book, price), quantity(qty),discount(disc),m_i(i){
        cout << "Disc_quote(...)" << endl;
    }
    virtual ~Disc_quote(){
        cout << "~ Disc_quote" << endl;
    }

    double net_price(size_t) const = 0;
};

class Bulk_quote : public Disc_quote{
    friend void friend_func(Bulk_quote&);
public:
    Bulk_quote() = default;
    Bulk_quote(const string &isbn, double sp,
               size_t qty, const double disc, int i)
        :Disc_quote(isbn, sp, qty, disc, i){
        cout << "Bulk_quote(...)" << endl;
    }
    ~Bulk_quote(){
        cout << "~Bulk_quote" << endl;
    }

    void samename(){
        Quote::samename();
        cout << "Bulk_quote.samename" << endl;
    }

    double net_price(size_t) const override;
};
double Bulk_quote::net_price(size_t n) const{
    cout << "Bulk_quote::net_price" << endl;
    //return Quote::net_price(n)*discount;
    if(quantity > 100)
        return n*single_price*discount;
    else
        return n*single_price;
}

void friend_func(Bulk_quote & bq){
    cout << "bq.m_i = "<< bq.m_i << endl;
}

int main()
{
    Bulk_quote bq("isbn1234", 1.2, 120, 0.6,12345);
    cout << "net price: "<< bq.net_price(120) << endl;
    friend_func(bq);
    return 0;
}
