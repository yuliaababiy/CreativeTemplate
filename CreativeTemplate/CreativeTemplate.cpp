#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class Bag {
private:
    string brand;
    double price;
public:
    Bag(const string& brand) : brand(brand) {}
    string getBrand() const { return brand; }
    Bag(const double& price) : price(price) {}
    string getPrice() const { return price; }

};

int main() {
    LinkedList<Brand> brandBag;
    LinkedList<Price> priceBag;

    brandBag.insert(Brand("Celine", 30000));
    brandBag.insert(Brand("Coach", 12000));
    brandBag.insert(Brand("Gucci", 20000));

    cout << "brand: ";
    cout << "price: ";
    brandBag.display();
    priceBag.display();

    bool compareByPrice(const Bag & a, const Bag & b) {
        return a.price < b.price;
    }
   
    sort(bags.begin(), bags.end(), compareByPrice);

    cout << "Bags sorted by price:" << endl;
    for (const auto& bag : bags) {
        cout << "Brand: " << bag.brand << ", Price: " << bag.price << endl;
    }

    Bag* findBagByBrand(const vector<Bag>& brand, const string& brand) {
        for (auto& bag: items) {
            if (bag.brand == brand) {
                return &brand; 
            }
        }
        return nullptr; 
    }

   string bagBrand= "Tote Bag";
    Bag* foundbag = findBagByBrand(bags, bagBrand);

    if (foundBag != nullptr) {
        cout << "Bag found: " << foundBag->name << ", Price: " << foundBag->price << endl;
    }
    else {
        cout << "Bag '" << bagBrand << "' not found." << endl;
    }

};
