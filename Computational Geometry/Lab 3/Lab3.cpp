#include<iostream>
#include <cstdlib>
using namespace std;

class Point{
    public: int x_cor,y_cor;
    void enterPointCoordinate(){
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
    void line(Point& a, Point& b){
        cout<<"\tFor Starting Point: "<<endl;
        a.enterPointCoordinate();
        cout<<"\tFor End Point: "<<endl;
        b.enterPointCoordinate();
    }
};

class TurnTest{
    public: int flag=0;
    template <class A, class B, class C>
    int turnTest(A& a, B& b, C& c){
        double area;
        area = 0.5*(a.x_cor*(b.y_cor-c.y_cor)+b.x_cor*(c.y_cor-a.y_cor)+c.x_cor*(a.y_cor-b.y_cor));
        /*if(area>0){
            cout<<"\n\t\t The point ("<<c.x_cor<<","<<c.y_cor<<") is LEFT to ";
            cout<<"the line segment from: ";
            a.displayPoint();
            cout<<" to ";
            b.displayPoint();
        }*/
        if(area<0){
            flag++;
            cout<<"\n\t\t The point ("<<c.x_cor<<","<<c.y_cor<<") is RIGHT to ";
            cout<<"the line segment from: ";
            a.displayPoint();
            cout<<" to ";
            b.displayPoint();
        }
        return flag;
    }
};

class LineIntersection{
    public: int flag;
    
    //Function to Check Intersection betwwn two lines A & B
    template<class A, class B>
    void checkIntersection(A& a, B& b){
        Point p1,p2,p3,p4;
        double p123, p124, p341, p342; 
        cout<<"\n\t\t           FIRST LINE";
        cout<<"\n\t\tStart Point:"<<endl;
        p1.enterPointCoordinate();
        cout<<"\n\t\tEnd Point:"<<endl;
        p2.enterPointCoordinate();
        cout<<"\n\t\t           SECOND LINE";
        cout<<"\n\t\tStart Point:"<<endl;
        p3.enterPointCoordinate();
        cout<<"\n\t\tEnd Point:"<<endl;
        p4.enterPointCoordinate();
        
        //Computer Area 
        p123 = computeArea(p1,p2,p3);
        p124 = computeArea(p1,p2,p4);
        p341 = computeArea(p3,p4,p1);
        p342 = computeArea(p3,p4,p2);
        
        //Check for Pure Intersection
        if (((p123 > 0 && p124 < 0) && (p341 > 0 && p342 < 0))|| ((p123 > 0 && p124 < 0) && (p341 < 0 && p342 > 0)) || ((p123 < 0 && p124 > 0) && (p341 < 0 && p342 > 0))|| ((p123 < 0 && p124 > 0) && (p341 > 0 && p342 < 0))){
            cout<<"\n\t\t-----> Pure Intersection <-----"<<endl;
        }
        
        //Check for Improper Intersection
        //Check for overlapping when all points are collinear
        else if ((p123 == 0 && p124 == 0 && p341 == 0 && p342 == 0)){
            //Check if one line lie completely inside another line
            //Check if second line lie completely inside first line
            if((((p3.x_cor>=p1.x_cor || p3.y_cor>=p1.y_cor) && (p3.x_cor<=p2.x_cor || p3.y_cor<=p2.y_cor))&&((p4.x_cor>=p1.x_cor || p4.y_cor>=p1.y_cor) && (p4.x_cor<=p2.x_cor || p4.y_cor<=p2.y_cor)))
            ||(((p3.x_cor<=p1.x_cor || p3.y_cor<=p1.y_cor) && (p3.x_cor>=p2.x_cor || p3.y_cor>=p2.y_cor))&&((p4.x_cor<=p1.x_cor || p4.y_cor<=p1.y_cor) && (p4.x_cor>=p2.x_cor || p4.y_cor>=p2.y_cor)))){
                cout<<"\n\tThe second line lie comletely inside the first line";
                cout<<"\n\t\t-----> Improper Intersection <-----"<<endl;
            }
            
            //Check if first line lie completely inside second line
            else if((((p1.x_cor>=p3.x_cor || p1.y_cor>=p3.y_cor) && (p1.x_cor<=p4.x_cor || p1.y_cor<=p4.y_cor))&&((p2.x_cor>=p3.x_cor || p2.y_cor>=p3.y_cor) && (p2.x_cor<=p4.x_cor || p2.y_cor<=p4.y_cor)))
            ||(((p1.x_cor<=p3.x_cor || p1.y_cor<=p3.y_cor) && (p1.x_cor>=p4.x_cor || p1.y_cor>=p4.y_cor))&&((p2.x_cor<=p3.x_cor || p2.y_cor<=p3.y_cor) && (p2.x_cor>=p4.x_cor || p2.y_cor>=p4.y_cor)))){
                cout<<"\n\tThe first line lie comletely inside the second line";
                cout<<"\n\t\t-----> Improper Intersection <-----"<<endl;
            }
            
            //Check if lines are not overlapping and no any touching
            else if((((p3.x_cor<p1.x_cor || p3.y_cor<p1.y_cor) && (p3.x_cor<p2.x_cor || p3.y_cor<p2.y_cor))&&((p4.x_cor<p1.x_cor || p4.y_cor<p1.y_cor) && (p4.x_cor<p2.x_cor || p4.y_cor<p2.y_cor)))||(((p3.x_cor>p1.x_cor || p3.y_cor>p1.y_cor) && (p3.x_cor>p2.x_cor || p3.y_cor>p2.y_cor))&&((p4.x_cor>p1.x_cor || p4.y_cor>p1.y_cor) && (p4.x_cor>p2.x_cor || p4.y_cor>p2.y_cor)))){
                cout<<"\n\tThe points of both lines are collinear but no any intersection.";
                cout<<"\n\t\t-----> Lines do not intersects. <-----"<<endl;
            }
            
            //Check if lines are partially overlapping
            else if((((p3.x_cor>p1.x_cor || p3.y_cor>p1.y_cor) && (p3.x_cor<p2.x_cor || p3.y_cor<p2.y_cor))
                &&
                ((p4.x_cor>p1.x_cor || p4.y_cor>p1.y_cor) && (p4.x_cor>p2.x_cor || p4.y_cor>p2.y_cor))
                ||
                ((p4.x_cor<p1.x_cor || p4.y_cor<p1.y_cor) && (p4.x_cor<p2.x_cor || p4.y_cor<p2.y_cor)))
                ||
                (((p4.x_cor>p1.x_cor || p4.y_cor>p1.y_cor) && (p4.x_cor<p2.x_cor || p4.y_cor<p2.y_cor))
                &&
                ((p3.x_cor>p1.x_cor || p3.y_cor>p1.y_cor) && (p3.x_cor>p2.x_cor || p3.y_cor>p2.y_cor))
                ||
                ((p3.x_cor<p1.x_cor || p3.y_cor<p1.y_cor) && (p3.x_cor<p2.x_cor || p3.y_cor<p2.y_cor))))
                {
                cout<<"\n\tThe lines lie partially inside themselves.";
                cout<<"\n\t\t-----> Improper Intersection <-----"<<endl;
            }
            
            //For all lines are collinear but just touches one another
            else{
                cout<<"\n\tThe lines are collinear and just touches eachother.";
                cout<<"\n\t\t-----> Improper Intersection <-----"<<endl;
            }
            
        }
        
        //Check for improper intersection when only three points are collinear
        else if ((p123 == 0 || p124 == 0 || p341 == 0 || p342 == 0)){
            if(p123==0){
               if((p3.x_cor>=p1.x_cor || p3.y_cor>=p1.y_cor) && (p3.x_cor<=p2.x_cor || p3.y_cor<=p2.y_cor)){
                   flag=1;
               }
            }
            else if(p124==0){
                if((p4.x_cor>=p1.x_cor || p4.y_cor>=p1.y_cor) && (p4.x_cor<=p2.x_cor || p4.y_cor<=p2.y_cor)){
                    flag=1;
                }
            }
            else if(p341==0){
                if((p1.x_cor>=p3.x_cor || p1.y_cor>=p3.y_cor) && (p1.x_cor<=p4.x_cor || p1.y_cor<=p4.y_cor)){
                    flag=1;
                }
            }
            else if(p342==0){
                if((p2.x_cor>=p3.x_cor || p2.y_cor>=p3.y_cor) && (p2.x_cor<=p4.x_cor || p2.y_cor<=p4.y_cor)){
                    flag=1;
                }
            }
            if(flag==1){
                cout<<"\n\t\t-----> Improper Intersection <-----"<<endl;
            }
            else{
                cout<<"\n\t\t-----> Lines do not intersects. <-----"<<endl;
            }
        }
        
        else{
            cout<<"\n\t\t-----> Lines do not intersects. <-----"<<endl;
        }
    }
    
    /*- function to calculate area
    - three points are passed to the function
    - area is calculated using triangle area formulae*/
    template<class A, class B, class C>
    double computeArea(A& a, B& b, C& c){
        return 0.5*(a.x_cor*(b.y_cor-c.y_cor)+b.x_cor*(c.y_cor-a.y_cor)+c.x_cor*(a.y_cor-b.y_cor));    
    }
};

struct vertex {
    Point info;
    struct vertex *n;
    struct vertex *p;
}*start, *last;
int count = 0;

class polygon: public TurnTest {
    public:
    polygon() {
        start = NULL;
        last = NULL;
    }

    vertex *create_vertex(Point p){
        count++;
        struct vertex *t;
        t = new(struct vertex);
        t->info = p;
        t->n = NULL;
        t->p = NULL;
        return t;
    };

    void insert(){
        Point p;
        p.enterPointCoordinate();
        struct vertex *t;
        t = create_vertex(p);
        if (start == last && start == NULL) {
            start = last = t;
            start->n= last->n = NULL;
            start->p = last->p= NULL;
        } else {
            last->n= t;
            t->p= last;
            last = t;
            start->p = last;
            last->n= start;
        }
    };

    int checkConvex(){
        int i, flag;
        TurnTest t1;
        struct vertex *s, *p, *n;
        s = start;
        n = s->n;
        p = n->n;
        for (i = 0;i < count;i++) {
            flag = t1.turnTest(s->info, n->info, p->info);
            p = p->n;
            s = s->n;
            n = n->n;
        }
        return flag;
    }

    template <class A>
    int checkConvex(A& a){
        int i, flag;
        Point point1;
        point1.x_cor = a.x_cor;
        point1.y_cor = a.y_cor;
        TurnTest t1;
        struct vertex *s, *p, *n;
        s = start;
        n = s->n;
        p = n->n;
        for (i = 0;i < count;i++) {
            flag = t1.turnTest(point1, s->info, n->info);
            p = p->n;
            s = s->n;
            n = n->n;
        }
        return flag;
    }

    void display(){
        int i;
        struct vertex *s;
        s = start;
        cout<<"\n\t The vertices  of given polygon are: ";
        for (i = 0;i < count-1;i++) {
            s->info.displayPoint();
            cout<<",";
            s = s->n;
        }
        s->info.displayPoint();
    };
};

void enterPolygonDetail(){
    int vertexNo;
    polygon pol;
    aa:
    cout<<"\n\t Enter the number of vertex of a polygon: ";
    cin>>vertexNo;
    if(vertexNo<4){
        cout<<"\n\t\t************************************";
        cout<<"\n\t\t* The vertices number must be >= 4 *";
        cout<<"\n\t\t************************************"<<endl;
        goto aa;
    }
    cout<<endl<<"Enter the vertices of the polygon: "<<endl;
    for(int i=0;i<vertexNo;i++){
        cout<<"\tVertex V"<<i<<": "<<endl;
        pol.insert();
    }
    cout<<"\t***************************************"<<endl;
    cout<<"\t*        Vertices  inserted !         *"<<endl;
    cout<<"\t***************************************"<<endl;
};

int main() {
    int choice, convexFlag;
    char cont;
    polygon pol;
    cout<<"\n\t\t\t *************************************************"<<endl;
    cout<<"\t\t\t                    LAB 3            "<<endl;
    cout<<"\t\t\t *************************************************"<<endl;
    cout<<"\t\t\t   1. To check if polygon is convex or not."<<endl;
    cout<<"\t\t\t   2. For Point Inclusion Test in convex polygon."<<endl;
    cout<<"\t\t\t   3. For Implementation of Ray Casting."<<endl;
    cout<<"\t\t\t ************************************************"<<endl;
    cout<<"\n\t\t Enter the choice(1/2/3): ";
    cin>>choice;
    sw:
    switch(choice) {
        case 1:
            enterPolygonDetail();
            pol.display();
            convexFlag = pol.checkConvex();
            if(convexFlag > 0){
                cout<<"\n\t The polygon is non-convex.";
            }else{
                cout<<"\n\t The polygon is convex.";
            }
        break;
        case 2:
        Point p1;
            enterPolygonDetail();
            cout<<"\n\t Enter the point for which point inclusion is to be tested: "<<endl;
            p1.enterPointCoordinate();
            pol.display();
            convexFlag = pol.checkConvex(p1);
            if(convexFlag > 0){
                cout<<"\n\n\t****************************************************************";
                cout<<"\n\t\t ===> The query point lies outside the polygon.";
                cout<<"\n\t****************************************************************";

            }else{
                cout<<"\n\n\t****************************************************************";
                cout<<"\n\t\t ===> The query point lies inside the polygon.";
                cout<<"\n\t****************************************************************";
            }
        break;
        case 3:
            cout<<"Ray Casting"<<endl;
            break;
        default:
            cout<<"\t\t\t\t ***   Wrong choice   ***"<<endl;
            cout<<"\n\t\t Enter the choice(1/2/3): ";
            cin>>choice;
            goto sw;
    }
    return 0;
}