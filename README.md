# 📦 Pharmaceutical Laboratory Management System

A C++ application that manages pharmaceutical drugs and their manufacturing components using a **Binary Search Tree (BST)**. This system allows users to efficiently add, search, update, and delete drug records while managing associated products.

---

## 🚀 Project Overview

This system organizes drug records as nodes in a Binary Search Tree, ensuring fast search, insertion, and deletion based on a unique drug ID. Each drug stores:

- **Unique Number**: Identifies each drug.
- **Label**: The drug's name.
- **Unit Price**: Cost per unit.
- **Category**: Type of drug (e.g., Antibiotic, Analgesic).
- **Product List**: Ingredients (name and quantity) required for manufacturing.

---

## 🟢 Key Features

### 📝 1. Drug Management
- Add new drugs with ID, label, price, and category.
- View all drugs in alphabetical order.
- Search for a drug by its unique ID and display details.
- Delete a drug by its unique ID.

### 📦 2. Product Management
- Add products (ingredients) to a specific drug.
- Remove a product from a drug.
- Search for drugs containing a specific product.
- Replace one product with another across all drugs.

### 🗂️ 3. Category Management
- Display all unique drug categories.
- Visualize drugs grouped by category.
- Delete all drugs within a specified category.

### 💾 4. Data Persistence
- Save the entire drug tree to a text file for backup and reporting.

---

## 🖥️ Installation & Setup

1. **Clone the Repository**
```bash
git clone https://github.com/AbdelkadirSellahi/Binary-Search-Tree-Management-System.git
cd Binary-Search-Tree-Management-System
```

2. **Compile the Program**  
Use a C++ compiler like `g++`:
```bash
g++ Pharmaceutical_Laboratory_Management_System_BST.cpp -o lab_management
```

3. **Run the Program**
```bash
./Pharmaceutical_Laboratory_Management_System_BST
```

---

## 📖 How to Use

After launching the program, you'll see the following menu:

```
--- Pharmaceutical Laboratory Management ---
1. Add a new drug
2. Add products to a drug
3. Display all drugs
4. Search and display a drug
5. Delete a drug
6. Remove a product from a drug
7. Search for drugs by product
8. Replace a product in all drugs
9. Display drug categories
10. Visualize drug tree by category
11. Save drug tree to a file
12. Delete all drugs in a category
13. Exit
```

---

## ⚙️ Example Workflow

### ➕ 1. Add a New Drug
1. Choose option **1**.
2. Enter the drug's number, label, price, and category.
3. Example:
```
Enter drug number: 101
Enter drug label: Paracetamol
Enter unit price: 5.99
Enter drug category: Analgesic
```

### 📦 2. Add Products to a Drug
1. Choose option **2**.
2. Enter the drug number and product details (name and quantity).
3. Example:
```
Enter the drug number to add products: 101
Enter the number of products for the drug: 2
Enter product name: Acetaminophen
Enter product quantity: 100
Enter product name: Starch
Enter product quantity: 50
```

### 🔍 3. Search for a Drug
1. Choose option **4**.
2. Enter the unique drug number.
3. Example:
```
Enter the drug number to search: 101
Output:
Drug Number: 101
Label: Paracetamol
Unit Price: 5.99
Category: Analgesic
Products required for manufacture:
- Acetaminophen (Quantity: 100)
- Starch (Quantity: 50)
```

### 🗂️ 4. Display Drugs by Category
1. Choose option **10**.
2. Example Output:
```
Drugs Organized by Category:

Category: Analgesic
- Drug Number: 101, Label: Paracetamol, Price: 5.99

Category: Antibiotic
- Drug Number: 102, Label: Amoxicillin, Price: 10.50
```

---

## 📚 Project Structure

- **`Drug` Structure:** Represents a BST node with drug details and a linked list of products.
- **`Product` Structure:** Stores product name and quantity for drug manufacturing.
- **Core Functions:**
  - `insertDrug()` – Insert new drugs into the BST.
  - `searchDrug()` – Search for a drug by its unique number.
  - `deleteDrug()` – Remove a drug from the tree.
  - `addProductsToDrug()` – Add ingredients to a specific drug.
  - `replaceProductInAllDrugs()` – Replace one product with another across all drugs.
  - `saveDrugTreeToFile()` – Export drug records to a text file.

---

## 📝 Example Output File (`drugs_output.txt`)
```
Drug Number: 101
Label: Paracetamol
Unit Price: 5.99
Category: Analgesic
Products:
- Acetaminophen (Quantity: 100)
- Starch (Quantity: 50)
----------------------
Drug Number: 102
Label: Amoxicillin
Unit Price: 10.50
Category: Antibiotic
Products:
- Amoxicillin Powder (Quantity: 200)
- Gelatin (Quantity: 30)
----------------------
```

---

## 🤝 Contributing
We welcome contributions! If you have ideas or improvements:
1. Fork the repository.
2. Create a new branch.
3. Submit a pull request.
---

## 💬 **Contact**

Feel free to open an issue or reach out for collaboration!  

**Author**: *Abdelkadir Sellahi*

**Email**: *abdelkadirsellahi@gmail.com* 

**GitHub**: [Abdelkadir Sellahi](https://github.com/AbdelkadirSellahi)

---

## 🙏 Acknowledgments

- Utilizes C++ Standard Template Library (STL): `list`, `map`, `vector`, and `set`.

