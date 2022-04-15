#include <iostream>
#include <map>
#include <exception>

class busket
{
private:
    std::map<std::string, int> db;
public:
    busket(){};

    void add(std::string art, int qty)
    {
        if(qty<0)
            throw std::invalid_argument("Quantity can't be negative\n");

        if(db.find(art)==db.end())
            db[art]=qty;
        else
            db[art]=db[art]+qty;
    }

    void remove(std::string art, int qty)
    {
        if(db.find(art)==db.end())
            throw std::invalid_argument("No units with specified code\n");
        if((db[art]-qty)<0)
            throw std::runtime_error("Not sufficient quantity to remove\n");
        else
            db[art]=db[art]-qty;
    }
};

int main()
{
    std::string code_input;
    int qty_input;
    busket db;

    while(true)
    {
        std::cout << "Input command(type 'exit' to leave): ";
        std::cin >> code_input;
        if(code_input=="exit")
            break;
        else if(code_input=="add") {
            std::cout << "Input code and quantity to add: ";
            std::cin >> code_input >> qty_input;
            std::cin.get();
            try {
                db.add(code_input, qty_input);
            }
            catch (const std::exception &x) {
                std::cerr << "Caught exception " << x.what();
            }
        }
        else if(code_input=="remove")
        {
            std::cout << "Input code and quantity to remove: ";
            std::cin >> code_input >> qty_input;
            std::cin.get();
            try {
                db.remove(code_input, qty_input);
            }
            catch (const std::exception &x) {
                std::cerr << "Caught exception " << x.what();
            }
        }
    }

    return 0;
}

