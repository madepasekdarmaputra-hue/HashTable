#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// ==================== LINKED LIST CHAINING ====================
class HashTableChaining {
private:
    static const int SIZE = 10;
    vector<list<string>> table;

public:
    HashTableChaining() {
        table.resize(SIZE);
    }
    
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += (int)c;
        }
        return sum % SIZE;
    }
    
    void insert(string key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted '" << key << "' at index " << index << endl;
    }
    
    void display() {
        cout << "\n=== HASH TABLE CHAINING ===" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            for (string name : table[i]) {
                cout << name << " ";
            }
            cout << endl;
        }
    }
};

// ==================== QUADRATIC PROBING ====================
class HashTableQuadratic {
private:
    static const int SIZE = 10;
    vector<string> table;
    vector<bool> occupied;

public:
    HashTableQuadratic() {
        table.resize(SIZE, "");
        occupied.resize(SIZE, false);
    }
    
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += (int)c;
        }
        return sum % SIZE;
    }
    
    bool insert(string key) {
        int index = hashFunction(key);
        int i = 0;
        
        while (occupied[index]) {
            i++;
            int newIndex = (index + i * i) % SIZE; // Quadratic probing: h(k,i) = (h(k) + i²) % m
            if (newIndex == index) return false; // Full table
            index = newIndex;
        }
        
        table[index] = key;
        occupied[index] = true;
        cout << "Inserted '" << key << "' at index " << index << endl;
        return true;
    }
    
    void display() {
        cout << "\n=== HASH TABLE QUADRATIC PROBING ===" << endl;
        for (int i = 0; i < table.size(); i++) {
            cout << "Index " << i << ": ";
            if (table[i] != "") cout << table[i];
            else cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    HashTableChaining chaining;
    HashTableQuadratic quadratic;
    
    vector<string> names = {"Ando", "Beni", "Citra", "Doni", "Eka", 
                           "Eko", "Gina", "Intan", "Joko", "Kevin"};
    
    cout << "=== HASH TABLE IMPLEMENTASI ===" << endl << endl;
    
    // Insert ke Chaining
    cout << "1. LINKED LIST CHAINING:" << endl;
    for (string name : names) {
        chaining.insert(name);
    }
    chaining.display();
    
    cout << "\n" << string(50, '=') << endl;
    
    // Insert ke Quadratic
    cout << "2. QUADRATIC PROBING:" << endl;
    for (string name : names) {
        quadratic.insert(name);
    }
    quadratic.display();
    
    return 0;
}