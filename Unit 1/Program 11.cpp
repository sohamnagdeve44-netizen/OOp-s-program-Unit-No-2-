#include <iostream>     // For input and output
#include <string>       // For using string data type
using namespace std;

// Class to represent a product
class Product {
private:
    int productId;              // Stores product ID
    string productName;         // Stores product name
    double price;               // Stores product price
    int stockQuantity;          // Stores available stock

    // Static variable shared by all Product objects
    static int totalProducts;

public:
    // Constructor to initialize product details
    Product(int id, string name, double p, int stock)
        : productId(id), productName(name),
          price(p), stockQuantity(stock) {

        totalProducts++;        // Increase total product count
    }

    // Inline function to return product ID
    inline int getId() const {
        return productId;
    }

    // Inline function to return product name
    inline string getName() const {
        return productName;
    }

    // Inline function to return product price
    inline double getPrice() const {
        return price;
    }

    // Function to update stock quantity
    void updateStock(int quantity) {
        stockQuantity = quantity;
    }

    // Static function to return total number of products
    static int getTotalProducts() {
        return totalProducts;
    }

    // Function to display product details
    void display() const {
        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity << endl;
    }

    // Destructor
    ~Product() {
        totalProducts--;        // Decrease product count when object is
