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

    ~Quote(){
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

class Bulk_quote : public Quote{
private:
    double discount;
public:
    Bulk_quote() = default;
    Bulk_quote(const string &isbn, double &sp,const double &disc)
        :Quote(isbn, sp),discount(disc){
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
    return n*single_price*discount;
}

class Another_quote:protected Quote{
private:
    size_t num;
public:
    Another_quote(const string &isbn, double &sp, const size_t &n)
        :Quote(isbn, sp), num(n){
        cout << "Another_quote" << endl;
    }
    double net_price(size_t n) const{
        if(num < 100 && num >=0){
            return 0.5*Quote::net_price(n);
        }else{
            return Quote::net_price(n);
        }
    }
};

double print_total(ostream &os,
                   const Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.get_isbn()
       <<" # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    string isbn;
    double sp;
    double discount;

    cout << "input isbn:" <<endl;
    cin >> isbn;
    cout << "input single price:" << endl;
    cin >> sp;
    cout << "input discount:" << endl;
    cin >> discount;

    Quote q(isbn,sp);
    Bulk_quote bq(isbn, sp, discount);

    print_total(cout, q, 10);
    print_total(cout, bq, 10);

    q.samename();
    bq.samename();

    Another_quote aq(isbn, sp, 50);
    //print_total(cout, aq, 10);//protected inhirent can't given to father class * or &
    return 0;
}
