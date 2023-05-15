#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
	Product(string name, double price, int id) : product_name(name), product_price(price), product_id(id) {}

	string ProductName() 
	{
		return product_name; 
	}

	double ProductPrice() 
	{
		return product_price;
	}
	int ProductId() 
	{ 
		return product_id; 
	}

private:
	string product_name;
	double product_price;
	int product_id;
};

class Customer {
public:
	Customer(string name, string email, int id) : customer_name(name), customer_email(email), customer_id(id) {}

	string CustomerName() 
	{ 
		return customer_name; 
	}
	string CustomerEmail() 
	{ 
		return customer_email; 
	}
	int CustomerId() 
	{ 
		return customer_id; 
	}

private:
	string customer_name;
	string customer_email;
	int customer_id;
};

class Order {
public:
	Order(Customer customer, vector<Product> products, int id) : order_customer(customer), order_products(products), order_id(id) {}

	void AddProduct(Product product) 
	{
		order_products.push_back(product);
	}

	double TotalCost() {
		double totalCost = 0.0;
		for (auto& product : order_products) {
			totalCost = totalCost + product.ProductPrice();
		}
		return totalCost;
	}

private:
	Customer order_customer;
	vector<Product> order_products;
	int order_id;
};

int main() {
	vector<Product> products;
	Customer customer("Adam Nowak", "adam@gmail.com", 1);
	Product shirt("Shirt", 40.0, 1);
	Product jeans("Jeans", 70.0, 2);
	Product shoes("Shoes", 200.0, 3);
	Product skirt("Skirt", 100.0, 4);
	Product socks("Socks", 10.0, 5);

	Order order(customer, products, 1);
	order.AddProduct(jeans);
	order.AddProduct(shoes);
	order.AddProduct(shirt);
	order.AddProduct(skirt);
	order.AddProduct(socks);

	vector<Product> productstwo;
	Customer customertwo("Julia Ordecka", "julia@gmail.com", 2);
	Order ordertwo(customertwo, productstwo, 2);
	ordertwo.AddProduct(skirt);
	ordertwo.AddProduct(socks);
	double totalcost = order.TotalCost();
	cout << "total cost 1: " << totalcost << endl;
	double totalcosttwo = ordertwo.TotalCost();
	cout << "total cost 2: " << totalcosttwo << endl;

	return 0;
}