#include <iostream>
using namespace std;
class Point 
{ 
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
  public: 
  template <class A, class B, class C>
  void enterPointForTurnTest(A& a, B& b, C& c){
      cout<<"\tGiven Line Segment: "<<endl;
      cout<<"\t  Starting Point: "<<endl;
      a.enterPointCoordinate();
      cout<<"\t  End Point: "<<endl;
      b.enterPointCoordinate();
      cout<<"\n\tEnter the third point for which turn test is to be done: "<<endl;
      c.enterPointCoordinate();
      turnTest(a,b,c);
  }
  
  //Function to test turn of point C with respect to line AB
  template <class A, class B, class C>
  void turnTest(A& a, B& b, C& c){
      double area;
      area = 0.5*(a.x_cor*(b.y_cor-c.y_cor)+b.x_cor*(c.y_cor-a.y_cor)+c.x_cor*(a.y_cor-b.y_cor));
      if(area>0){
        cout<<"\n\t\t The point ("<<c.x_cor<<","<<c.y_cor<<") is LEFT to "; 
        cout<<"the line segment from: ";
        a.displayPoint();
        cout<<" to ";
        b.displayPoint();
      }
      else if(area<0){
        cout<<"\n\t\t The point ("<<c.x_cor<<","<<c.y_cor<<") is RIGHT to "; 
        cout<<"the line segment from: ";
        a.displayPoint();
        cout<<" to ";
        b.displayPoint();
      }
      else{
        cout<<"\n\t\t The point ("<<c.x_cor<<","<<c.y_cor<<") is COLLINEAR to "; 
        cout<<"the line segment from: ";
        a.displayPoint();
        cout<<" to ";
        b.displayPoint();
      }
  }
};

class LineIntersection{
    public: int flag;
    
    //Function to check betweeness
    template<class A, class B, class C>
    int checkBetweeness(A& a, B& b, C& c){
        if(((a.x_cor == c.x_cor)&&(a.y_cor == c.y_cor)) || ((b.x_cor == c.x_cor)&&(b.y_cor == c.y_cor))){
            return 1;
        }
        else if((((c.x_cor>a.x_cor)||(c.y_cor>a.y_cor))&&((c.x_cor<b.x_cor)||(c.y_cor<b.y_cor)))){
            return 1;
        }
        else
            return 0;
    }
    
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
        
        cout<<"\n\tp123 = "<<p123;
        cout<<"\n\tp124 = "<<p124;
        cout<<"\n\tp341 = "<<p341;
        cout<<"\n\tp342 = "<<p342;
        
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
               flag = checkBetweeness(p1,p2,p3);
            }
            else if(p124==0){
                flag = checkBetweeness(p1,p2,p4);
            }
            else if(p341==0){
                flag = checkBetweeness(p3,p4,p1);
            }
            else if(p342==0){
                flag = checkBetweeness(p3,p4,p2);
            }
            cout<<"\n\t Flag = "<<flag;
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

int main()
{
    int choice;
    char cont;
    a:
    cout<<"\n\t\t\t *********************************************"<<endl;
    cout<<"\t\t\t        TURN TEST AND INTERSECTION TEST      "<<endl;
    cout<<"\t\t\t *********************************************"<<endl;
    cout<<"\t\t\t   1. Turn Test."<<endl;
    cout<<"\t\t\t   2. Check Intersection between two lines."<<endl;
    cout<<"\t\t\t *********************************************"<<endl;
    cout<<"\n\t\t Enter the choice(1/2): ";
    cin>>choice;
    switch(choice){
        case 1: Point point1, point2, point3;
                TurnTest t1;
                cout<<"\n\t\t\t **********************************"<<endl;
                cout<<"\t\t\t            TURN TEST"<<endl;
                cout<<"\t\t\t **********************************"<<endl;
                t1.enterPointForTurnTest(point1, point2, point3);
            break;
        case 2: LineIntersection li;
                Line l1,l2;
                cout<<"\n\t\t\t **********************************"<<endl;
                cout<<"\t\t\t      Check Intersection"<<endl;
                cout<<"\t\t\t **********************************"<<endl;
                li.checkIntersection(l1,l2);
            break;
        default: cout<<"Invalid choice.\n\tEnter the correct choice number(1/2): ";
    }
    cout<<"\n\n\t\tDo u want to continue(Y/N): ";
    cin>>cont;
    if(cont=='y'||cont=='Y')
        goto a;
    return 0;
}