class node {
private:
    int array[];
public:
    node(){
        int basearr[10];
        array = basearr;
    }

    node(int size){
        int basearr[size];
        array = basearr;
    }
};
