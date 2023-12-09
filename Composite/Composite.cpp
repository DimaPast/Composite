#include <iostream>
#include <vector>
#include <Windows.h>


class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};


class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Лист виконує операцію." << std::endl;
    }
};

class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void remove(Component* component) {
       
    }

    void operation() const override {
        std::cout << "Композит виконує операцію." << std::endl;

        
        for (const auto& child : children) {
            child->operation();
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    Leaf* leaf = new Leaf();

  
    Composite* composite = new Composite();
    composite->add(leaf);

    // Виклик операцій
    leaf->operation();      
    composite->operation(); 

  
    delete leaf;
    delete composite;

    return 0;
}
