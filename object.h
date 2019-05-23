#ifndef OBJECT_H
#define OBJECT_H


class Object{
private:
    static int all_of_objects;
    int varible;
    int id;
    void save();
public:
    Object();
    Object(int init_value);
    virtual ~Object();

    int getVarible();
};

#endif // OBJECT_H
