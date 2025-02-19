#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

// Structure for the linked list of products
struct Product {
    string name;
    int quantity;
};

// Structure for a node in the BST
struct Drug {
    int number; // Unique identifier
    string label; // Label
    float unitPrice; // Unit price
    string category; // Category
    list<Product> productList; // List of products
    Drug* left; // Left child
    Drug* right; // Right child
};

// Function prototypes
Drug* createDrug(int, const string&, float, const string&);
Drug* insertDrug(Drug*, int, const string&, float, const string&);
Drug* searchDrug(Drug*, int);
Drug* deleteDrug(Drug*, int);
Drug* findMin(Drug*);
void addProductsToDrug(Drug*);
void displayDrugs(Drug*);
void displayDrugDetails(Drug*);
void removeProductFromDrug(Drug*, const string&);
void searchDrugsByProduct(Drug*, const string&);
void replaceProductInAllDrugs(Drug*, const string&, const string&);
void displayDrugCategories(Drug* root);
void visualizeTreeByCategory(Drug* root);


// Create a new node
Drug* createDrug(int number, const string& label, float unitPrice, const string& category) {
    Drug* newDrug = new Drug;
    newDrug->number = number;
    newDrug->label = label;
    newDrug->unitPrice = unitPrice;
    newDrug->category = category;
    newDrug->left = nullptr;
    newDrug->right = nullptr;
    return newDrug;
}

// Insert a drug into the BST
Drug* insertDrug(Drug* root, int number, const string& label, float unitPrice, const string& category) {
    if (root == nullptr) {
        return createDrug(number, label, unitPrice, category);
    }

    if (number < root->number) {
        root->left = insertDrug(root->left, number, label, unitPrice, category);
    } else if (number > root->number) {
        root->right = insertDrug(root->right, number, label, unitPrice, category);
    } else {
        cout << "Drug with this number already exists!\n";
    }

    return root;
}

// Search for a drug by its number
Drug* searchDrug(Drug* root, int number) {
    if (root == nullptr || root->number == number) {
        return root;
    }

    if (number < root->number) {
        return searchDrug(root->left, number);
    }

    return searchDrug(root->right, number);
}

// Add products to a drug's product list
void addProductsToDrug(Drug* drug) {
    if (drug == nullptr) {
        cout << "Drug not found!\n";
        return;
    }

    int numProducts;
    cout << "Enter the number of products for the drug: ";
    cin >> numProducts;

    for (int i = 0; i < numProducts; ++i) {
        Product product;
        cout << "Enter product name: ";
        cin >> product.name;
        cout << "Enter product quantity: ";
        cin >> product.quantity;
        drug->productList.push_back(product);
    }
}

// Display all drugs (in-order traversal)
void displayDrugs(Drug* root) {
    if (root == nullptr) {
        return;
    }

    displayDrugs(root->left);
    cout << root->label << endl;
    displayDrugs(root->right);
}

// Display detailed information about a drug
void displayDrugDetails(Drug* drug) {
    if (drug == nullptr) {
        cout << "Drug not found!\n";
        return;
    }

    cout << "Drug Number: " << drug->number << endl;
    cout << "Label: " << drug->label << endl;
    cout << "Unit Price: " << drug->unitPrice << endl;
    cout << "Category: " << drug->category << endl;

    cout << "Products required for manufacture: \n";
    for (const auto& product : drug->productList) {
        cout << "- " << product.name << " (Quantity: " << product.quantity << ")\n";
    }
}

// Find the minimum node in a subtree
Drug* findMin(Drug* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a drug from the BST
Drug* deleteDrug(Drug* root, int number) {
    if (root == nullptr) {
        cout << "Drug not found!\n";
        return root;
    }

    if (number < root->number) {
        root->left = deleteDrug(root->left, number);
    } else if (number > root->number) {
        root->right = deleteDrug(root->right, number);
    } else {
        if (root->left == nullptr) {
            Drug* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Drug* temp = root->left;
            delete root;
            return temp;
        } else {
            Drug* temp = findMin(root->right);
            root->number = temp->number;
            root->label = temp->label;
            root->unitPrice = temp->unitPrice;
            root->category = temp->category;
            root->productList = temp->productList;
            root->right = deleteDrug(root->right, temp->number);
        }
    }
    return root;
}
// Remove a product from a drug's product list
void removeProductFromDrug(Drug* drug, const string& productName) {
    if (drug == nullptr) {
        cout << "Drug not found!\n";
        return;
    }

    auto it = drug->productList.begin();
    while (it != drug->productList.end()) {
        if (it->name == productName) {
            it = drug->productList.erase(it);
            cout << "Product removed successfully.\n";
            return;
        } else {
            ++it;
        }
    }
    cout << "Product not found in the drug's product list.\n";
}
// Search for and display all drugs containing a specific product
void searchDrugsByProduct(Drug* root, const string& productName) {
    if (root == nullptr) {
        return;
    }

    searchDrugsByProduct(root->left, productName);

    for (const auto& product : root->productList) {
        if (product.name == productName) {
            cout << "Drug: " << root->label << " (Number: " << root->number << ")\n";
            break;
        }
    }

    searchDrugsByProduct(root->right, productName);
}
// Replace one product with another in all drugs
void replaceProductInAllDrugs(Drug* root, const string& oldProduct, const string& newProduct) {
    if (root == nullptr) {
        return;
    }

    for (auto& product : root->productList) {
        if (product.name == oldProduct) {
            product.name = newProduct;
        }
    }

    replaceProductInAllDrugs(root->left, oldProduct, newProduct);
    replaceProductInAllDrugs(root->right, oldProduct, newProduct);
}
// Function to display all unique categories of drugs
void displayDrugCategories(Drug* root) {
    if (root == nullptr) return;

    // Use a set to store unique categories
    static set<string> categories;

    // Traverse the tree (in-order traversal)
    displayDrugCategories(root->left);
    categories.insert(root->category);
    displayDrugCategories(root->right);

    // Display unique categories (at the end of traversal)
    if (root->number == root->number) { // Dummy condition to trigger display once
        cout << "Drug Categories in the Laboratory: " << endl;
        for (const auto& category : categories) {
            cout << "- " << category << endl;
        }
    }
}
// Function to group drugs by categories
void groupDrugsByCategory(Drug* root, map<string, vector<Drug*>>& categoryMap) {
    if (root == nullptr) return;

    // Traverse the tree and add drugs to their respective categories
    groupDrugsByCategory(root->left, categoryMap);
    categoryMap[root->category].push_back(root);
    groupDrugsByCategory(root->right, categoryMap);
}

// Function to display the drug tree organized by category
void visualizeTreeByCategory(Drug* root) {
    if (root == nullptr) {
        cout << "The drug tree is empty!" << endl;
        return;
    }

    // Map to hold categories and their associated drugs
    map<string, vector<Drug*>> categoryMap;

    // Group drugs by category
    groupDrugsByCategory(root, categoryMap);

    // Display drugs organized by category
    cout << "Drugs Organized by Category: " << endl;
    for (const auto& pair : categoryMap) {
        cout << "\nCategory: " << pair.first << endl;
        for (const auto& drug : pair.second) {
            cout << " - Drug Number: " << drug->number
                 << ", Label: " << drug->label
                 << ", Price: " << drug->unitPrice << endl;
        }
    }
}
// Function to save the drug tree to a file
void saveDrugTreeToFile(Drug* root, const string& filename) {
    if (root == nullptr) {
        return;
    }

    ofstream file(filename, ios::app); // Open the file in append mode
    if (!file) {
        cout << "Error: Could not open file.\n";
        return;
    }

    saveDrugTreeToFile(root->left, filename); // Save left subtree

    // Save current node's data
    file << "Drug Number: " << root->number << endl;
    file << "Label: " << root->label << endl;
    file << "Unit Price: " << root->unitPrice << endl;
    file << "Category: " << root->category << endl;
    file << "Products:\n";
    for (const auto& product : root->productList) {
        file << "- " << product.name << " (Quantity: " << product.quantity << ")\n";
    }
    file << "----------------------\n";

    saveDrugTreeToFile(root->right, filename); // Save right subtree
    file.close();
}
// Function to delete all drugs in a specified category
Drug* deleteDrugsByCategory(Drug* root, const string& category) {
    if (root == nullptr) {
        return nullptr;
    }

    // Recursively process left and right subtrees
    root->left = deleteDrugsByCategory(root->left, category);
    root->right = deleteDrugsByCategory(root->right, category);

    // If the current drug matches the category, delete it
    if (root->category == category) {
        root = deleteDrug(root, root->number); // Use existing deleteDrug function
    }

    return root;
}
// Main function
int main() {
    Drug* root = nullptr;
    int choice;

    do {
        cout << "\n--- Pharmaceutical Laboratory Management ---\n";
        cout << "1. Add a new drug\n";
        cout << "2. Add products to a drug\n";
        cout << "3. Display all drugs\n";
        cout << "4. Search and display a drug\n";
        cout << "5. Delete a drug\n";
        cout << "6. Remove a product from a drug\n";
        cout << "7. Search for drugs by product\n";
        cout << "8. Replace a product in all drugs\n";
        cout << "9. Display drug categories\n";
        cout << "10. Visualize drug tree by category\n";
        cout << "11. Save drug tree to a file\n";
        cout << "12. Delete all drugs in a category\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int number;
            string label;
            float unitPrice;
            string category;

            cout << "Enter drug number: ";
            cin >> number;
            cout << "Enter drug label: ";
            cin.ignore();
            getline(cin, label);
            cout << "Enter unit price: ";
            cin >> unitPrice;
            cout << "Enter drug category: ";
            cin.ignore();
            getline(cin, category);

            root = insertDrug(root, number, label, unitPrice, category);
            break;
        }
        case 2: {
            int number;
            cout << "Enter the drug number to add products: ";
            cin >> number;
            Drug* drug = searchDrug(root, number);
            addProductsToDrug(drug);
            break;
        }
        case 3:
            cout << "Drugs produced by the laboratory:\n";
            displayDrugs(root);
            break;
        case 4: {
            int number;
            cout << "Enter the drug number to search: ";
            cin >> number;
            Drug* drug = searchDrug(root, number);
            displayDrugDetails(drug);
            break;
        }
        case 5: {
            int number;
            cout << "Enter the drug number to delete: ";
            cin >> number;
            root = deleteDrug(root, number);
            break;
        }
        case 6: {
            int number;
            string productName;
            cout << "Enter the drug number to remove a product: ";
            cin >> number;
            Drug* drug = searchDrug(root, number);
            cout << "Enter the product name to remove: ";
            cin >> productName;
            removeProductFromDrug(drug, productName);
            break;
        }
        case 7: {
            string productName;
            cout << "Enter the product name to search for in drugs: ";
            cin >> productName;
            searchDrugsByProduct(root, productName);
            break;
        }
        case 8: {
            string oldProduct, newProduct;
            cout << "Enter the old product name to replace: ";
            cin >> oldProduct;
            cout << "Enter the new product name: ";
            cin >> newProduct;
            replaceProductInAllDrugs(root, oldProduct, newProduct);
            break;
        }
        case 9:
            displayDrugCategories(root);
            break;

        case 10:
            visualizeTreeByCategory(root);
            break;
            
        case 11: {
            string filename;
            cout << "Enter the filename to save the drug tree: ";
            cin >> filename;
            saveDrugTreeToFile(root, filename);
            cout << "Drug tree saved to " << filename << endl;
            break;
        }
        
        case 12: {
            string category;
            cout << "Enter the category to delete all drugs: ";
            cin.ignore();
            getline(cin, category);
            root = deleteDrugsByCategory(root, category);
            cout << "All drugs in the category '" << category << "' have been deleted.\n";
            break;
        }
        case 13:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 13);

    return 0;
}

