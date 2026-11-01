#include <iostream>

class Animal
{
public:
    int age;

    Animal(int a) : age(a) {}

    virtual void speak() = 0;

    virtual int getAge()
    {
        return age;
    }

    virtual ~Animal() {}
};

class Flyable
{
public:
    int speed;

    Flyable(int s) : speed(s) {}

    virtual void fly() = 0;

    virtual ~Flyable() {}
};

class Dog : public Animal, public Flyable
{
public:
    int weight;

    Dog(int a, int s, int w)
        : Animal(a), Flyable(s), weight(w) {}

    void speak() override
    {
        age += 1;
    }

    int getAge() override
    {
        return age;
    }

    void fly() override
    {
        speed += 1;
    }

    ~Dog() override {}
};

int test_cast(Animal *p)
{
    Dog *d = dynamic_cast<Dog *>(p);

    if (d == nullptr)
    {
        return -1;
    }

    return d->weight;
}

int test_virtual(Animal *p)
{
    p->speak();
    return p->getAge();
}

int test_multi()
{
    Dog dog(3, 100, 20);

    Animal *a = &dog;
    Flyable *f = &dog;

    test_virtual(a);
    f->fly();

    return test_cast(a);
}

int main(){
    Dog d(1,2,3);
    Animal* p = &d;

    test_cast(p);
}