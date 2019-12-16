#include <iostream> 
using namespace std; 
class Point 
{ 
    public: int x_cor,y_cor; 
  
    void enterPointCoordinate() 
    { 
       cout<<"\t\tEnter the X-coordinate: ";
       cin>>x_cor;
       cout<<"\t\tEnter the Y-coordinate: ";
       cin>>y_cor;
    } 
    void displayPoint(){
        cout<<"("<<x_cor<<" ,"<<y_cor<<")";
    }
}; 
class Line{
    public: 
    template <class A, class B>
    void line(A& a, B& b){
        cout<<"\tFor Starting Point: "<<endl;
        a.enterPointCoordinate();
        cout<<"\tFor End Point: "<<endl;
        b.enterPointCoordinate();
        cout<<"\n\t\t The line segment is from: ";
        a.displayPoint();
        cout<<" to ";
        b.displayPoint();
    }
};
class PLA{
    public:
    template <class A, class B, class C>
    void pla5D(A& stPt, B& edPt, C& nwPt){
        cout<<"\tFor Starting Point: "<<endl;
        stPt.enterPointCoordinate();
        cout<<"\tFor End Point: "<<endl;
        edPt.enterPointCoordinate();
        cout<<"\tFor New Point: "<<endl;
        nwPt.enterPointCoordinate();
        
        if(nwPt.x_cor==stPt.x_cor && nwPt.y_cor==stPt.y_cor){
            cout<<"\n\t The new point ("<<nwPt.x_cor<<","<<nwPt.y_cor<<")";
            cout<<" is the starting point.";
        }else if(nwPt.x_cor==edPt.x_cor && nwPt.y_cor==edPt.y_cor){
            cout<<"\n\t The new point ("<<nwPt.x_cor<<","<<nwPt.y_cor<<")";
            cout<<" is the terminal point.";
        }
        else if( ((edPt.y_cor-stPt.y_cor)/(edPt.x_cor-stPt.x_cor)) != ((nwPt.y_cor-stPt.y_cor)/(nwPt.x_cor-stPt.x_cor)) ){
            cout<<"\n\n\tThe given three points:";
            cout<<" ("<<stPt.x_cor<<","<<stPt.y_cor<<")";
            cout<<", ("<<edPt.x_cor<<","<<edPt.y_cor<<")";
            cout<<"and ("<<nwPt.x_cor<<","<<nwPt.y_cor<<")";
            cout<<" does not lie in the same line.";
        }else{
            if((nwPt.x_cor>stPt.x_cor || nwPt.y_cor>stPt.y_cor) && (nwPt.x_cor<edPt.x_cor || nwPt.y_cor<edPt.y_cor)){
                cout<<"\n\t The new point ("<<nwPt.x_cor<<","<<nwPt.y_cor<<")";
                cout<<" lies between in the given line segment.";
            }else if(nwPt.x_cor<stPt.x_cor || nwPt.y_cor<stPt.y_cor){
                cout<<"\n\t The new point ("<<nwPt.x_cor<<","<<nwPt.y_cor<<")";
                cout<<" is behind the given line segment.";
            }else {
                cout<<"\n\t The new point ("<<nwPt.x_cor<<","<<nwPt.y_cor<<")";
                cout<<" is beyond the given line segment.";
            }
        }    
    }
};
  
int main() { 
    int choice;
    char cont;
    a:
    cout<<"\n\t\t\t **********************************"<<endl;
    cout<<"\t\t\t     POINT LINE CLASSIFICATION "<<endl;
    cout<<"\t\t\t **********************************"<<endl;
    cout<<"\t\t\t   1. Implementation of Point."<<endl;
    cout<<"\t\t\t   2. Implementation of Line Segment."<<endl;
    cout<<"\t\t\t   3. Test for 5-Dimension of PLA."<<endl;
    cout<<"\n\t\t Enter the choice(1/2/3): ";
    cin>>choice;
    switch(choice){
        case 1: Point p1;
                cout<<"\n\t\t\t **********************************"<<endl;
                cout<<"\t\t\t       IMPLEMENTATION OF POINT"<<endl;
                cout<<"\t\t\t **********************************"<<endl;
                p1.enterPointCoordinate();
                cout<<"\n\t\t The point is: ";
                p1.displayPoint();
            break;
        case 2: Point point1, point2; 
                Line line1;
                cout<<"\n\t\t\t **********************************"<<endl;
                cout<<"\t\t\t   IMPLEMENTATION OF LINE SEGMENT"<<endl;
                cout<<"\t\t\t **********************************"<<endl;
                line1.line<Point, Point>(point1,point2);
            break;
        case 3: Point startPt, endPt, newPt;
                PLA pla;
                cout<<"\n\t\t\t **********************************"<<endl;
                cout<<"\t\t\t         5-DIMENSION OF PLA"<<endl;
                cout<<"\t\t\t **********************************"<<endl;
                pla.pla5D<Point,Point,Point>(startPt,endPt,newPt);
            break;
        default: cout<<"Invalid choice.\n\tEnter the correct choice number(1/2/3): "; 
    }
    cout<<"\n\n\t\tDo u want to continue(Y/N): ";
    cin>>cont;
    if(cont=='y'||cont=='Y')
        goto a;
    return 0; 
}
